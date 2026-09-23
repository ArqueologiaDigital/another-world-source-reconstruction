# O nome estava a um salto de distância

Quatrocentas e noventa e nove figuras neste projeto já se chamam
`CINEMATIC_CAVES_SCREEN_67_BACKDROP_LAYER_0` e coisas assim: camada tal do
fundo da tela tal. São nomes que alguém ganhou olhando a arte, tela por tela,
e escrevendo o que via.

Dez rotinas se chamavam `CAVES_SCREEN_92_BACKDROP_DRAW`.

Dez. As outras continuavam `LABEL_CDB2`, `JUNK__9DD7`,
`DRAW_CIN_305_TO_309_5F_AT_AACB4DF5` — e essa última, além de não dizer nada,
carrega uma cauda hexadecimal crua que a própria norma do projeto proíbe. Só
que o corpo de cada uma dessas rotinas já era uma pilha de camadas cujos nomes
diziam, um por um, de qual tela era aquele fundo.

O nome estava dentro da rotina. Faltava subir um nível.

## Duas fontes que não se conhecem

A regra é a mesma que uma sonda anterior já tinha estabelecido no sentido
contrário — um rótulo cujo corpo é um único desenho herda o nome da figura que
desenha. Aqui o corpo é uma pilha, e a pilha concorda consigo mesma.

Mas concordar consigo mesma não basta. Se eu batizo a rotina com o número que
as camadas dizem, a única coisa que provei é que as camadas dizem o que dizem.
Então a proposta só sai quando **duas** fontes dão a mesma tela:

1. **As camadas da própria rotina.** Toda figura já batizada que ela desenha é
   `CINEMATIC_<FASE>_SCREEN_<NN>_BACKDROP...` para um único `NN`.
2. **A análise de fluxo sobre `[SCREEN_NUM]`**, escrita numa sessão anterior
   para outro fim: a rotina pertence à tela `NN` quando **todo** caminho que
   chega até ela já testou a guarda e encontrou `NN`.

As duas não compartilham entrada. A primeira lê nomes que uma pessoa escreveu
a partir da arte; a segunda lê `je` e `jne` no bytecode e nunca foi informada
de que esses nomes existem. Quando uma dirige a renomeação, a outra é a
conferência.

O controle roda sobre as rotinas que já tinham nome antes de tudo isso:
**139 concordam, 0 discordam** — e essa contagem inclui as versões de cartucho
e de GBA, que não são alvo de batismo aqui (os romsets delas não trazem banco
de figuras extraído, então nada neste módulo consegue medir a arte delas) mas
carregam 33 nomes de pintor que a ferramenta de alinhamento empurrou das
versões prioritárias. Depois do caso 0x4C/0x6C mais abaixo, cada um desses 33
teve de ser reconferido contra as guardas da própria versão. Os 33 passam.

Resultado: **85 pintores de fundo batizados**, em três passadas — batizar um
pintor dá uma tela àquela rotina, o que deixa a passada seguinte casar um par
entre versões que antes não resolvia, então rodei até parar de render. Eram
**20 rótulos de pintor no começo do dia, são 106 agora**, em 64 telas
distintas.

## O guarda que só apareceu depois de eu errar

A primeira versão da sonda propôs 76 nomes. Treze deles eram lixo, e o lixo
era instrutivo.

```
LABEL_136B:
        video offset=CINEMATIC_452, x=[BUDDY_X], y=[BUDDY_Y]
        jne [0x10], 0x01, LABEL_137B
        video offset=CINEMATIC_453, x=[BUDDY_X], y=[BUDDY_Y]
```

Isso são dois quadros do companheiro andando. A análise de fluxo diz,
corretamente, que essa rotina só roda na tela 0x24 — e a sonda concluiu, de
forma completamente absurda, que ela é *o fundo* da tela 0x24.

É o mesmo erro que o projeto já tinha catalogado com outra roupa: a cena em
que uma figura é desenhada não nomeia a figura, e a figura não nomeia a cena.
Estar dentro de uma tela não faz de você o cenário dela.

O conserto é medir o que um fundo é, e não onde ele roda: **toda camada numa
coordenada literal** — cenário não é desenhado em `[BUDDY_X]` nem na ficha do
herói — **e ou uma limpeza de página (`fill`, `copyVideoPage`) ou uma camada
que cobre os 240x160 inteiros.** Com esse teste, os treze somem.

Um segundo guarda veio junto: quatro rótulos de PRISON derivavam todos a tela
0x24. Onde vários derivam a mesma tela, nenhum deles é *o* pintor dela, então
todos caem.

## Três correções que a conferência obrigou

### Um nome de fundo numa rotina que não desenha nada

A versão Amiga de CAVES chamava isto de `DRAW_CAVES_FIRST_ROOM_BG`:

```
DRAW_CAVES_FIRST_ROOM_BG:
        break
        jmp CAVES_DRAW_CRAWLING_BG_AND_PICK_BY_HERO_X
```

Não desenha nada. É o ponto de junção de uma atribuição de dois braços a
`[0x42]` — chega-se ali caindo de cima, ou pelo `jl [HERO_X], 0x35` que pula o
braço do `else` — seguido do `break` e da volta ao topo. É a cauda de laço de
uma linha de animação.

Na versão MS-DOS, a mesma posição é o anônimo `LABEL_D1E3`. E o pintor de
verdade, nas duas versões, é a rotina de `fill` mais duas camadas, mais
abaixo. O nome estava simplesmente pregado no lugar errado.

Pior: como a sonda tinha batizado o pintor Amiga de
`CAVES_SCREEN_67_BACKDROP_DRAW` antes disso, a versão que **tinha** o nome
descritivo não podia mais cedê-lo. A sonda agora recusa qualquer rotina cuja
contraparte na outra versão já carregue um nome ganho — contraparte
identificada pelo md5 da arte que ela pinta, nunca por índice, porque as
versões indexam o banco de figuras de maneiras diferentes.

### Um número de tela é propriedade da versão

A ferramenta que casa rotinas entre versões faz isso pelo fluxo de instruções
alinhado e leva o nome junto. Isso está certo para um nome de rotina e está
**errado para um nome que contém um número de tela**. Ela levou
`CAPSULE_SCREEN_6C_BACKDROP_DRAW` do MS-DOS para a rotina Amiga alinhada, e o
controle pegou:

```
amiga CAPSULE  CAPSULE_SCREEN_6C_BACKDROP_DRAW   nome 0x6C  camadas -  fluxo 0x4C  **
```

A medida que decide: **a fase CAPSULE do Amiga compara `[SCREEN_NUM]` com 0x4C
quatro vezes e com 0x6C nenhuma**; a do MS-DOS compara com as duas. As duas
versões numeram essa tela de formas diferentes. A rotina Amiga agora é
`CAPSULE_SCREEN_4C_BACKDROP_DRAW`, o valor que a própria versão usa.

Qualquer nome dessa forma precisa ser reconferido depois de uma fusão entre
versões. Isso ficou escrito no README da sonda, porque é o tipo de coisa que
volta a morder.

### Quatro rotinas cujas camadas afirmam uma tela que o fluxo nega

Ficaram como estão, e estão registradas porque são o próximo trabalho, não
ruído:

```
amiga CAVES    LABEL_D2EB   camadas dizem 0x8F, fluxo diz 0xAF
msdos CAVES    LABEL_D7CB   camadas dizem 0x8F, fluxo diz 0xAF
msdos CAPSULE  LABEL_9CCB   camadas dizem 0xAB, fluxo diz 0xEC
msdos CAPSULE  LABEL_9CFF   camadas dizem 0xAB, fluxo diz 0xCB
```

Em CAVES, `LABEL_D2EB` e a rotina agora chamada `CAVES_SCREEN_8F_BACKDROP_DRAW`
pintam **as mesmas três camadas nas mesmas âncoras** e só então divergem. Ou
seja: aquelas três são uma base compartilhada por duas telas, e
`CINEMATIC_CAVES_SCREEN_8F_BACKDROP_LAYER_{0,1,2}` reivindica uma
exclusividade que não tem — exatamente a regra que o projeto já escreveu para
as telas 0x92 e 0x93.

Em CAPSULE é pior. `CINEMATIC_CAPSULE_SCREEN_AB_BACKDROP_LAYER_0` é pintada
por três rotinas em três âncoras `y` diferentes (198, 151, 187), **nenhuma**
rotina em nenhuma das versões é fixada em 0xAB pelo fluxo, e a fase CAPSULE do
Amiga nunca compara `[SCREEN_NUM]` com 0xAB. Esses nomes provavelmente estão
errados.

Rebaixá-los é uma mudança com evidência própria, não um efeito colateral
desta. Fica anotado.

## O que sobrou dizendo por que sobrou

A sonda recusa e conta o motivo:

| retidos | por quê |
|---|---|
| 2468 | o nome já foi ganho — um nome descritivo derivado da arte nunca é deslocado |
| 2170 | não é um pintor de fundo |
| 23 | só o fluxo fixa; nada confirma |
| 4 | as figuras batizadas não apontam todas para uma tela |
| 4 | as camadas e o fluxo discordam |
| 1 | o fluxo não consegue fixar |

Os 6 restantes são o resto aproveitável: rotinas onde o fluxo sabe a tela, as
camadas ainda são numeradas e a outra versão não confirma. Uma fonte só não
basta, e não basta mesmo — este texto tem três correções que provam isso.

## Mais dois defeitos meus, achados porque a saída era pequena demais

O nível cruzado entre versões casava **zero** pares, e "0 pares" tinha cara de
achado sobre o jogo. Era defeito: a impressão digital da arte eram 512 bytes
crus lidos a partir do offset, mas um polígono é mais curto que isso, então a
maior parte do hash era a arte que por acaso vinha depois no banco — que
difere entre versões por construção. Usando o md5 canônico da árvore
analisada, que é o que o resto do projeto usa exatamente para isso, 0 pares
viram 6.

E um corpo de rotina passava do próprio `ret`. Eu terminava o corpo no rótulo
seguinte, e a fase CAPSULE do MS-DOS tem dois desenhos depois de um `ret` sem
rótulo nenhum na frente:

```
LABEL_9C52:
        fill page=0x00, color=0x08
        video offset=CINEMATIC_522, ...
        video offset=CINEMATIC_BUDDY_SMASHING_WINDOW_F1, ...
        ...
        ret
                                          <- nenhum rótulo aqui
        video offset=CINEMATIC_CAPSULE_SCREEN_92_BACKDROP_LAYER_5, ...
        video offset=CINEMATIC_CAPSULE_SCREEN_92_BACKDROP_LAYER_6, ...
```

Essas duas camadas eram a **única** ligação daquela rotina com uma tela, e ela
não consegue alcançá-las. O corpo agora termina no primeiro `ret`, `jmp` ou
`db 0x11` — os três opcodes que o desmontador já lista como terminadores.

## A auditoria dos nomes de camada que já existiam

A mesma evidência, virada para os 312 nomes de camada já na árvore, sob a
pergunta mais fraca que ainda afirma alguma coisa: **pelo menos uma rotina que
desenha a figura tem de estar na tela que o nome reivindica**. Uma rotina que
o fluxo não consegue fixar não conta nem a favor nem contra.

Isso é de propósito mais fraco que a regra dos nomes novos, que também exige
exclusividade. Uma figura compartilhada por duas telas é defensável nesta
auditoria e indefensável naquela regra, e a diferença é o ponto: **rebaixar um
nome precisa de prova de que ele está errado, não de ausência de prova de que
está certo.**

**2 de 312 falharam**, e falharam de forma categórica:
`CINEMATIC_CAVES_SCREEN_ED_BACKDROP_LAYER_1` e `_2` são pintadas por cinco
rotinas nas telas 0xCB, 0xEE, 0xCD, 0xCC e 0xCE, nenhuma delas 0xED — enquanto
`CAVES_SCREEN_ED_BACKDROP_DRAW`, que existe, não pinta nenhuma das duas.
Voltaram a ser `CINEMATIC_739` e `CINEMATIC_740`, as posições delas na tabela
de EQU. Essa convenção foi conferida em vez de suposta: das 908 linhas
CINEMATIC EQU do CAVES em MS-DOS, **0** das que ainda carregam número
discordam da própria posição. A auditoria agora fecha em 0 de 312.
