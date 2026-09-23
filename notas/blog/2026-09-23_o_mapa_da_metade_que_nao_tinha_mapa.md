# O mapa da metade que não tinha mapa

Este projeto tem duas metades. A dos **dados** — as figuras poligonais — tem
mapa há tempos: uma sonda separa a arte ainda numerada por *como* ela é
desenhada, porque o operando de posição decide que evidência poderia batizá-la.

A metade dos **rótulos** não tinha mapa nenhum. Tinha uma porcentagem: a fase
CAVES da versão Amiga está 32,6% semântica, a CAPSULE do MS-DOS 24,0%. Isso
diz que falta muito e não diz nada sobre o que falta.

Então fiz o mapa. Todos os rótulos ainda marcados como provisórios em PRISON,
CAVES e CAPSULE, nas duas versões prioritárias, classificados por **como o
controle chega até eles** — porque é isso que decide que evidência poderia
algum dia nomeá-los.

```
  14503  rótulos
   7594  provisórios
     2360    quem salta para ele também é provisório
     2253    ninguém referencia (byte morto, ou junção só por queda)
     1690    alcançado por call/setup: é um ponto de entrada
      828    INTERNO a uma única rotina já batizada
      463    saltado de duas ou mais rotinas
```

Os 828 são os tratáveis. Um rótulo provisório para o qual só se salta de
dentro de uma rotina que já tem nome é uma **posição** dentro dela, e uma
posição pode ser nomeada sem saber o que a arte representa.

## E mesmo assim não os batizei

Eles se separam bem por papel: 629 alvos de salto para a frente com corpo de
verdade, 127 alvos para trás (cabeças de laço), 44 caudas de duas instruções,
28 `ret` puros. E 549 das 649 rotinas donas têm exatamente um, então
`<DONA>_<PAPEL>` não precisaria nem de índice.

O problema é o **vocabulário de papel**: ele teria de ser inventado. Medido
sobre os rótulos que já têm nome em cada uma dessas posições, o último termo é
uma palavra de conteúdo ou um número de fase muito mais vezes do que uma
palavra posicional. De 3.384 alvos de salto condicional para a frente já
batizados, 67 terminam em `DONE` e 58 em `RET`. De 433 alvos para trás, 38
terminam em `LOOP`.

Um sufixo posicional é *permitido* pela árvore. Não é o que a árvore
majoritariamente faz — e renomear 828 rótulos assim faria disso o que a árvore
majoritariamente faz. Isso é uma decisão sobre o nomear do projeto, não uma
medição. Fica escrito e fica parado.

## Duas regras tiradas da própria árvore, medidas, e recusadas

### Quadros pela ordem de primeira aparição — exata e inutilizável

Uma rotina que desenha uma família `CINEMATIC_<CAULE>_F*` **completa** numera
os membros pela ordem em que aparecem pela primeira vez no corpo dela. Isso é
exato: **159 de 159**.

Os 19 que pareciam contraexemplos são, todos eles, famílias que a rotina
desenha só em parte — o ordinal ali é tomado sobre uma visão parcial e não tem
como bater. Separação limpa, não um limiar.

O que **não** se deriva é o caule. Dos 159, **82** têm um caule que não tem
relação com o nome da rotina:

```
ENDING_CLOSEUP_SIDE_SILHOUETTE_RISE_FALL_LOOP  desenha  CINEMATIC_ENDING_CLOSEUP_SILHOUETTE_F*
PTERANODON_HEAD_BEAK_OPEN_ANIM                 desenha  CINEMATIC_PTERANODON_BEAK_OPEN_F*
```

Usar o nome da rotina mesmo assim rende 10 famílias, e ler o resultado mata
quase todas: uma delas seria
`CINEMATIC_PRISON_DRAW_CIN505_AT_X21_Y27_L35_F0` — um nome carregando um
índice cru **e** duas coordenadas de tela, as duas coisas proibidas pela
norma. Não vale um módulo.

### `<CAULE>_DONE` nomeia sua cabeça de laço `<CAULE>_LOOP` — 9 de 16

Na escada de zoom da cutscene de PRISON a forma se repete exatamente, e nas
fases 04 e 05 os dois lados já estão batizados assim. Na árvore inteira o par
vale 9 vezes em 16, o que não é regra. Então a sonda **reporta e não propõe**.

Ainda assim rende dois nomes certos dentro daquela escada, onde a convenção
está provada doze linhas acima no mesmo arquivo. Esses dois foram tomados à
mão, com isso dito como evidência.

## A fatia que rendeu

```
LABEL_6B98:
        video type=0, offset=HERO_WALK_RIGHT_BODY_F10, x=[HERO_X], y=[HERO_Y], zoom=0x40
        jne [0x0A], 0x00, HERO_GUN_ARM_POSE_CASE_01
        video offset=CINEMATIC_PRISON_HERO_WALK_RIGHT_ARM_F10, x=[HERO_X], y=[HERO_Y]
        ret
```

As duas figuras dizem `F10`. Doze linhas abaixo,
`PRISON_HERO_WALK_RIGHT_POSE_11` tem o corpo idêntico com `F11`, e o mesmo
vale para POSE_12, 13, 14, 00..06 e 08.

O nome aqui **não é um juízo sobre o que a arte representa** — a arte já está
batizada. É a convenção dos irmãos aplicada no índice que a própria arte
declara. O modelo é derivado dos irmãos, nunca escolhido: se eles não
concordarem num prefixo e numa largura de zero à esquerda, não há convenção a
seguir e nada é proposto.

O controle esconde cada irmão já batizado, deriva o modelo do resto, e confere
se reproduz o nome que uma pessoa escreveu: **127 de 127**.

**4 nomes** — as poses 09 e 10, os dois buracos de uma sequência de quinze
quadros, nas duas versões prioritárias.

## Os dois ajustes, e por que um deles foi recusado por medição

A primeira rodada propôs **zero**, inclusive o caso acima. O braço em
`LABEL_6B98` é `CINEMATIC_PRISON_HERO_WALK_RIGHT_ARM_F10` — uma cópia com
escopo de fase no banco de cinemáticas — enquanto os irmãos desenham
`HERO_WALK_RIGHT_ARM_F11`, do banco compartilhado. Agrupar pela string crua da
família colocou o mesmo membro em dois grupos. Tirar o prefixo de banco e o
token de fase resolve, sem mexer no controle.

A tentação oposta era tirar a **forma do corpo** da chave de agrupamento, que
parece rigorosa demais. Testei em vez de opinar: o controle cai de 127/127
para **21 de 27**, porque PRISON carrega ao mesmo tempo
`DRAW_HERO_WALK_RIGHT_F07` e o estilo `PRISON_HERO_WALK_RIGHT_POSE_07` em
corpos de formas diferentes, e juntar os dois faz cada convenção contradizer a
outra. E não rende proposta nenhuma a mais. A forma fica.

Juntar irmãos entre versões — mesma fase e mesma família em Amiga, MS-DOS,
cartucho e GBA — também foi testado, na teoria de que uma versão pudesse ter
batizado o que outra deixou numerada. O controle sobrevive (124 reproduzidos,
0 falhas) e rende **0** propostas novas: essas famílias não têm desenhador
batizado em versão nenhuma. Não adotado — um conjunto maior sem rendimento é
só uma superfície maior para errar.

## O que fica

Das três classes que não são os 828, cada uma está travada em algo real:

- **2.253 sem referência.** Alguns são bytes mortos, que por norma devem
  manter nome de endereço. O resto são junções alcançadas só por queda, e
  nenhum salto aponta para elas — alcançabilidade não diz nada a respeito.
- **2.360 cujo único saltador também é provisório.** Destravam em cadeia
  conforme quem salta para elas ganha nome. Não falta mais nada.
- **1.690 pontos de entrada.** Um alvo de `call` ou `setup` é uma rotina por
  direito próprio, e batizá-la exige saber o que ela **faz** — o mesmo
  problema que a metade da arte tem.
