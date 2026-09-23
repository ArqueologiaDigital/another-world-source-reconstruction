# O mesmo argumento, certo numa vez e errado na seguinte

*Um argumento que tinha derrubado um nome errado no projeto — "esta rotina
nunca mexe na vertical, logo não é uma queda" — foi aplicado a outro caso e
estava errado. A diferença não está no código nem na medida, que são iguais
nos dois: está em **o que a âncora significa**. E o mesmo dia produziu uma
sonda que engolia duplicatas em silêncio, e um vocabulário que, ao ser
corrigido, fez o número de acertos **cair** — honestamente.*

---

## O argumento que funcionou

Numa sessão anterior o projeto tinha descoberto que `HERO_FALL_LEFT_LOOP` —
"o herói caindo para a esquerda" — nunca move o herói na vertical. As quatro
escritas em `HERO_Y` são `add [HERO_Y], 0x0000`: nada. Um `grep` por "mexe na
vertical?" responde "sim" e mente. Não era uma queda; era a caminhada, e o
laço vizinho é que era a corrida.

Bom argumento, bem medido, nome corrigido.

## O mesmo argumento, no caso seguinte

As folhas de salto estavam retidas havia semanas, com esta anotação no
documento de passagem:

    CAVES diz JUMP, LAKE/CAPSULE dizem WALK/RUN para os mesmos passos em X,
    e nenhuma das duas escreve HERO_Y.

A última cláusula é verdadeira. A conclusão tirada dela não é. E eu a tirei de
novo, em voz alta, antes de medir: *um salto que nunca escreve `HERO_Y` não é
um salto.*

A diferença é que **a âncora é a referência do chão**. O `x,y` passado ao
`video` não é o centro da figura: é o ponto onde os pés tocam o solo. Uma
folha de sprites pode levantar o boneco **dentro do próprio quadro**, e esta
levanta. Medindo a borda inferior de cada quadro contra o nível de chão modal
(+0,5):

    quadro 05   +0,5   no chão
    quadro 06   -7,0   NO AR   (7,5 acima do chão)
    quadro 07   -3,5   NO AR
    quadro 08   +0,5   no chão

Dois quadros no ar na versão que parte parado; quatro na que parte correndo,
que é a que também escreve `HERO_Y` três vezes — as duas coisas somadas, o
salto maior. Controle: os 15 quadros de `HERO_WALK_LEFT_BODY` já nomeados não
têm **nenhum** quadro no ar.

Então o JUMP estava certo o tempo todo, nas duas fases. E havia muito menos
desacordo do que a anotação dizia: CAVES e PRISON desenham **os mesmos doze
offsets na mesma ordem**, com o mesmo deslocamento líquido em X (±57), e os
dois nomes dizem JUMP. Diferem só em como descrevem a aproximação.

O resultado prático: 26 quadros nomeados, uma folha de treze por direção — a
entrada parado toca doze, a entrada correndo entra no quinto e segura o
sétimo, que é a parte funda do arco que um pulo parado nunca alcança.

**A lição não é "meça mais".** É que um argumento válido carrega consigo a
suposição sobre a qual foi construído, e essa suposição não viaja. "Não mexe
em `HERO_Y`" prova "não se desloca verticalmente **como entidade**"; não prova
"não sai do chão", porque o desenho também pode fazer isso.

## Uma sonda que dizia "tudo certo" corretamente e inutilmente

No mesmo dia, o item 5 da lista de pendências dizia que a verificação de
símbolos não cobria um dos alvos de compilação, e citava um bug real: uma
renomeação que passou pela sonda e mexeu em bytes.

Conferir antes de consertar mostrou que a afirmação está errada — aquele alvo
e o seu irmão são construídos do mesmo diretório e montam texto idêntico, então
os quatro que a sonda percorre já cobrem os cinco alvos. Não havia nada a
acrescentar.

O buraco era outro, e mais interessante. A sonda guardava as definições num
`set`. Um símbolo definido **duas vezes** fica indistinguível de um definido
uma vez. Quando a renomeação deixou dois `EQU` com o mesmo nome no mesmo
arquivo, os bytes do alvo mudaram, a verificação caiu para 28/29, e a sonda
respondeu "todos os símbolos estão definidos" — **com toda a razão, e sem
nenhuma utilidade**. Uma redefinição é a falha oposta de uma definição
ausente e precisava do próprio sinal.

Agora tem, com gravidade graduada: valores diferentes são erro (é o caso que
mexe em bytes), valor igual é aviso. Porque a verificação encontrou de
imediato **30 duplicatas já existentes na árvore**, todas com o mesmo valor —
nenhuma move um byte hoje, e todas são o estado a partir do qual aquele bug
começa: renomeie um gêmeo, esqueça o outro, e os valores divergem.

## Quando corrigir o vocabulário faz o número piorar

A sonda de consenso nomeia arte do banco compartilhado quando duas fases
independentes concordam sobre o movimento. Ela exigia que a palavra de
movimento e a de direção fossem **adjacentes**, então
`PRISON_HERO_WALK_JUMP_LEFT` simplesmente não era lida. Corrigido — a ação é a
palavra de movimento imediatamente antes da direção, e as anteriores são a
aproximação — o consenso subiu de 5 para 7.

Depois faltavam ainda `AIM`, `FIRE` e `SHOT` no vocabulário. `FIRE` e `SHOT`
são a mesma ação: as rotinas que contêm uma e as que contêm a outra desenham
**exatamente os mesmos quatro offsets**. Acrescentados, o consenso caiu de 7
para **5**.

Isso é a sonda ficando mais honesta, não pior. Dois offsets estavam sendo
batizados CROUCH com base em duas rotinas da **mesma** fase, enquanto a outra
fase dizia AIM numa rotina que não era lida. Fazer a rotina ser lida
transformou uma unanimidade falsa num conflito registrado. O número que caiu
era um número inflado.

## E o conflito se resolve medindo, sem escolher vencedor

A norma do projeto (#0120) proíbe uma ferramenta escolher entre dois nomes
ganhos honestamente. Mas "agachado ou em pé" não é questão de preferência — é
altura, e a arte responde. Contra os 15 quadros de caminhada já nomeados
(mediana 49,0), os offsets em disputa são bimodais, com **11 unidades de vão e
nada no meio**:

    CV_1664  44,5   -4,5   em pé      → o CROUCH de CAVES está errado aqui
    CV_17CC  45,0   -4,0   em pé
    CV_3764  33,0  -16,0   agachado
    CV_39A2  33,5  -15,5   agachado
    CV_1784  33,0  -16,0   agachado   ← o controle

`CV_1784` é o controle: é o único do grupo em que as duas fontes já
concordavam em CROUCH, sem nenhuma reivindicação de AIM contra. Ele cai no
modo agachado, o que confirma o teste antes de ele ser usado nos casos em
disputa. E a largura separa do mesmo jeito, por outro caminho: 16 a 18
unidades com os braços junto ao corpo, 35 a 45 com o braço da arma estendido.

A altura decide o corpo e não diz nada sobre os braços. Então, para os
agachados, **os dois nomes estão parcialmente certos** — e é isso que vai para
o nome, em vez de um vencedor.

## Onde isso deixa a contagem

Chaves do banco compartilhado sem nome: 189 → **152**. Arte das fases
prioritárias nomeada: 50,8% → **53,0%**. Dois itens da lista de pendências
fechados, ambos porque a própria lista estava errada.

E um erro meu que não tem desculpa e já é o terceiro da sessão: escrevi
"53,1% (5.391)" na tabela do documento de passagem **no mesmo comando** que
calculava o valor real, que é 53,0% (5.382). O número saiu da contagem de
nomes aplicados, não da sonda — que conta por **uso**, de modo que um nome
aplicado a um offset desenhado em vários lugares move o numerador mais de uma
vez. Rodar primeiro, escrever depois.
