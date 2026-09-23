# O olho que abre, e três nomes que estavam nos degraus errados

A cena em que o herói acorda na prisão tem um close-up de um rosto. A árvore
já sabia disso: três polígonos chamavam-se
`CINEMATIC_PRISON_WAKE_CLOSEUP_PUPIL_0`, `_1` e `_2`. Alguém renderizou,
olhou, viu uma pupila e escreveu o nome. Estava certo sobre o assunto.

Estava errado sobre o número.

## A escada

O que desenha a pupila não é uma animação. É uma **escada**: uma corrente de
`jg [0x16], N` que escolhe *uma* figura para o valor atual de uma variável,
e a variável sobe e desce.

```
	jg [0x16], 0x01, PRISON_WAKE_CLOSEUP_PUPIL_UPTO_02
	video offset=CINEMATIC_682, x=[0x1a], y=[0x1b]
	jmp LABEL_4D8F

PRISON_WAKE_CLOSEUP_PUPIL_UPTO_02:
	jg [0x16], 0x02, LABEL_4D52
	video offset=CINEMATIC_PRISON_WAKE_CLOSEUP_PUPIL_0, x=[0x1a], y=[0x1b]
```

A escada tem **sete degraus**. Os três nomes estavam nos degraus 2, 6 e 7, e
numerados 0, 1 e 2 — porque quando foram escritos só três dos sete eram
conhecidos. A norma do projeto proíbe buraco na numeração de uma família, e
preencher os quatro degraus que faltavam não tinha como deixar a numeração
antiga de pé. As opções eram renumerar tudo ou não nomear nada.

Medida por olho, por olho:

```
  <=1   6x7     <=3  10x11    <=5  14x15    else  18x19
  <=2   8x9     <=4  12x13    <=6  16x17
```

Mais dois de largura e mais dois de altura a cada degrau, os sete concêntricos
no mesmo ponto. E os offsets no banco — 0x3B62, 6E, 7A, 86, 92, 9E — são uma
corrida de doze em doze bytes **na ordem da escada**. A arte concorda com o
bytecode em cada degrau.

## A caixa delimitadora mentiu sobre tudo

Todas as figuras dessa cena têm dois caminhos: um por olho, a uns 165 pixels
de distância. A caixa delimitadora é a união dos dois, então ela atravessa o
vão entre os olhos e mede o rosto inteiro.

`CINEMATIC_658` mede **170x7**. São dois quadrados de **5x5**.

Quem só lê a extensão vê uma faixa fina e larga e pode escrever "linha do
cílio". São dois brilhos especulares, um em cada pupila. Toda medida do
trabalho de hoje é por caminho, não por figura, e essa é a razão.

## A pálpebra

A segunda escada, em `[0x15]`, tem dezoito degraus. Todos com a borda de cima
em y = 92,0 e a borda de baixo exatamente 2,0 acima da anterior: 134,0 no
primeiro, 100,0 no último. O olho ocupa y 108,5..127,5 — então o degrau 0
cobre o olho inteiro e o degrau 17 está acima dele. `mov [0x15], 0x0000`
começa a cena com a pálpebra fechada.

Dezoito degraus, uma progressão aritmética perfeita, nenhuma exceção.

E `CINEMATIC_656`, a placa escura sob a pupila, tem extensão vertical
108,5..127,5 — **exatamente a da pupila mais larga**. A pupila dilata até
encher a placa e nunca passa dela. É por isso que o nome dela é `PUPIL_BASE` e
não "íris": ela é a base sobre a qual a pupila é composta, e a íris estriada
de verdade, 56 cunhas radiais, está no fundo fixo.

## Um nome que passaria a significar duas coisas

O renumeramento valia para a Amiga e para a MS-DOS, medidas. Só que a versão
de cartucho carrega os mesmos três nomes.

Renumerar duas versões e deixar a terceira: `PUPIL_0` passa a ser o degrau 1
em duas e o degrau 2 na outra. Renumerar só os três dela: a família fica
{1, 5, 6}, com buraco. Os dois estados consistentes eram "todos os sete" ou
"nenhum", e "nenhum" joga fora três nomes que acertam o assunto.

A arte de cartucho **não pode ser medida**. A questão #0106 do projeto —
localizar os offsets dos polígonos no ROM de SNES — está aberta, o
`snes.toml` ainda carrega `["cinematic.rom", "?"]`, e não existe renderização
nenhuma para olhar. Então os sete nomes lá não se apoiam na arte. Apoiam-se no
degrau, que está no bytecode que dá para ler, e o arquivo de proposta diz isso
no primeiro parágrafo e diz o que esses sete nomes **não** afirmam.

A sonda que verifica isso compara duas versões degrau a degrau e julga pela
contagem e pelo limiar — nunca pela grafia da constante, que passa a diferir
por construção assim que uma das versões é renomeada. Ela também reprova um
degrau em que as duas versões carregam nomes semânticos diferentes, que é um
nome significando duas coisas. Reprovou 3 enquanto a cartucho estava para
trás, e aprovou 0 depois.

## A ferramenta que teria comido o lote

O renumeramento é um lote em que uma linha **libera** um nome que outra linha
**toma**: `CINEMATIC_682` fica com `PUPIL_0` no mesmo lote em que `PUPIL_0`
vira `PUPIL_1` e `PUPIL_1` vira `PUPIL_5`. Aplicado linha a linha, os três
terminam escritos `PUPIL_5`.

A ferramenta que carrega os nomes para a árvore unificada fazia exatamente
isso, uma regra de cada vez. A solução em vigor era ordenar as linhas da
tabela defensivamente — primeiro os deslocamentos, em ordem decrescente, os
nomes novos por último.

Isso põe o defeito de uma ferramenta na ordem de leitura de um documento, e
depende de todo autor futuro lembrar da página que explica. Trocado por uma
passada só, com uma alternância sobre todos os nomes antigos, mais longos
primeiro. O controle está no próprio arquivo e reproduz a falha:

```
python3 notes/unified-scoping/sync_equ_rename.py --self-test
```

Ele imprime o que a ferramenta produz e o que linha a linha teria produzido.

E aí veio a lição pior, na mesma tarde. Uma tabela de renomeação **não é
idempotente, e não dá para fazer ser**. Depois que `682 -> PUPIL_0` e
`PUPIL_0 -> PUPIL_1` foram aplicados, a árvore fica idêntica ao que estaria
antes de uma segunda passada das mesmas linhas: `PUPIL_0` definido,
`PUPIL_1` definido. Nenhum teste sobre o estado final distingue "novo" de
"já feito" — os estados finais são iguais, só a história difere.

O arquivo de propostas ganhou uma seção nova, reexecutar era o natural, e a
escada da Amiga saiu `_1, _5, _6, _3, _4, _5`. As duas redes pegaram: a
verificação de símbolos acusou dois símbolos definidos duas vezes com valores
diferentes, e o portão de bytes foi para **28/29 na metade unificada com a
metade canônica ainda em 29/29** — a assinatura exata que a documentação já
descrevia.

Agora a história é registrada: um arquivo com uma linha por
`(versão, fase, antigo, novo)` já escrito, e uma linha já registrada é pulada.
E uma tabela por lote, daqui em diante.

## O que dá para ver

A composição, camada por camada, num olho:

1. o fundo fixo: a esclera e uma íris estriada em 56 cunhas radiais;
2. `PUPIL_BASE`: um hexágono escuro sobre o centro dela;
3. um dos sete degraus de pupila, dilatando;
4. `EYE_GLINT`: o quadradinho claro de 5x5;
5. um dos dezoito degraus de pálpebra, descendo por cima de tudo.

Trinta constantes, uma cena, e o único jeito de saber que era isso foi
renderizar na paleta que a própria cena carrega — `setPalette 0x0B`, duas
linhas antes do primeiro desenho. Na paleta padrão o mesmo hexágono sai azul
brilhante e a leitura muda.
