# A coordenada no nome escondia um tiro

*A norma do projeto proíbe pôr coordenada de tela num nome, e o exemplo que ela
usa para dizer "não faça isso" é `CINEMATIC_DECOR_AT_305_155_F0`. Esse nome
existia de verdade, num grupo de dezenove. O grupo não era uma coisa: era um
herói, um atirador, um feixe e três juncos à deriva, reunidos só porque uma
chamada de desenho os pôs perto uns dos outros. Levou duas passadas para
desmontar, e **as duas primeiras erraram olhando para a renderização** — de
dois jeitos opostos.*

---

## Um grupo formado pelo lugar, não pelo assunto

Um nome com coordenada é proibido por duas razões: vaza um número mágico e
quebra a leitura do índice de quadro — `CINEMATIC_LAKE_DECOR_AT_327_164` lê-se
como família `…AT_327`, quadro 164. Mas o defeito pior é anterior ao nome. A
coordenada só entra porque alguém agrupou por **onde aquilo é desenhado**, e o
lugar não é o assunto. Dezenove quadros com o mesmo prefixo, em offsets
espalhados pelo banco, sem nada em comum além de um par de números.

A passada de ontem dividiu o grupo por renderização e nomeou sete. Sobre quatro
dos que restaram, escreveu:

    F01..F04  ~40x16/12  decoração à deriva (DECOR_F1_DRIFT_LOOP, F2_DRIFT_LOOP)

Está errado. Não é decoração e nada vai à deriva. São os quatro últimos quadros
do herói sendo baleado.

## Por que a renderização não salvou — a primeira vez

O erro é instrutivo porque não foi falta de cuidado. A passada renderizou os
dezenove quadros, olhou, e agrupou pelo tamanho e pelo nome da rotina que
desenha. Os dois concordaram: formas baixas e largas, rotinas chamadas
`DRIFT_LOOP`. Concordância é evidência, certo?

Não, porque **os nomes das rotinas tinham sido inventados na mesma passada, a
partir do mesmo olhar, para as mesmas figuras**. Confirmar uma suposição com
outra suposição derivada dela não é conferir nada. Uma tabela de tamanhos não
distingue decoração de um corpo caído; o que distingue está no operando:

    video offset=CINEMATIC_DECOR_AT_305_155_F1, x=[HERO_X], y=[HERO_Y]

Decoração não é desenhada nas coordenadas do herói. Os quatro quadros dividem a
fatia com os quatro `CINEMATIC_LAKE_LESTER_*` logo acima e são contínuos com
eles numa linha reta de código.

## O que a cena é

Medindo âncora mais caixa delimitadora com sinal — cada peça ganha uma faixa na
tela em vez de um tamanho solto — as peças se encaixam numa coisa só:

| peça | faixa na tela |
|---|---|
| a figura em 327,164 | x 282..345, y 126..184, cinco folhas |
| cabeça do feixe | x 232..454, y 148..164 |
| vão do feixe | x 100..314, depois −40..174, depois −166..46 |
| feixe na boca da arma | x 282..328, y 154..156 |

A tela tem 320 de largura. A figura está encostada na borda direita, metade
fora, com um braço esticado para a **esquerda** segurando um cano. O feixe
começa colado na borda esquerda dela, na altura do cano, e caminha para fora da
tela um vão por quadro. O primeiro desenho toca `play id=0x0052`.

Depois o herói. O passo aplicado à âncora antes de cada quadro, lido dos `sub` e
`add`: −3, −12, −12, −10, −10, −3, −3, −3, −3, −2, −1. Sessenta e dois pixels
para a esquerda, desacelerando de forma monótona, descendo. Os corpos medem
65x25, 41x19, 29x23, 39x16, 43x13 — contra 48 de altura em pé. Horizontais, e
achatando. O último fica num laço para sempre, enquanto o canal que ele libera
vai para `LAKE_PALETTE_FADE_IN`.

Dois nomes que já estavam no repositório eram falsos, e a medida os desmentiu:

- `CINEMATIC_LAKE_LESTER_RECOVER` não é uma pose. É um grupo com um sólido de
  17x26 e **três barras de 213x1** — a mesma primitiva do vão do feixe — 216 de
  largura, desenhado na fatia do herói no quadro em que o tiro chega. Nada ali
  se recupera.
- `CINEMATIC_LAKE_LESTER_RISE` é o primeiro quadro no ar do arremesso, indo para
  a esquerda e para **baixo**.

## Por que a renderização não salvou — a segunda vez, ao contrário

Sobraram sete quadros, F07..F13, desenhados em `[0x32],[0x33]`, uma fatia
diferente. Renderizados um SVG por offset, F09..F13 são "uma forma angular ao
lado de uma linha vertical", e foi exatamente isso que a nota de ontem
registrou como não identificável.

O problema agora é o oposto do primeiro. Lá, duas suposições concordaram. Aqui,
a ferramenta estava certa e a pergunta é que estava errada: o bytecode desenha
duas figuras **na mesma âncora**, e cada SVG vem recortado na própria arte.

    REED_SWAY_F0_TO_BACKGROUND:
        video offset=CINEMATIC_LAKE_REED,          x=[0x32], y=[0x33]
        video offset=CINEMATIC_LAKE_REED_SWAY_F0,  x=[0x32], y=[0x33]

Desenhadas na âncora que compartilham, são uma haste com duas frondes em pé
sobre o tronco do junco. Uma planta, balançando.

E `[0x32],[0x33]` não é uma posição: é uma posição *compartilhada* que três
rotinas `MULTIPLEX_ANIM_RING3_SLOT_0..2` giram entre três registros a cada
quadro. Intercaladas por número de canal com três laços de junco, dois de
salpico e um de balanço, elas deixam um só conjunto de rotinas de desenho servir
**três juncos em três posições**, cada um caminhando um pixel para a esquerda
por desenho. Um multiplexador cooperativo escrito no script.

## Dois resultados negativos que ficaram registrados

Nem toda medida responde. Duas não responderam, e isso também é resultado:

**A inclinação não ordena os quadros.** Medindo x do topo menos x da base por
quadro: 18,5 / 18,5 / 19,5 / 20,0 / 23,5 — com dois empatados exatamente. A
figura tem duas hastes e a métrica não as separa. Então o índice veio da ordem
em que o ciclo toca os quadros (9,10,11,10,9,12,13,12 e repete: F0 é o quadro de
repouso), com a ordem dos offsets servindo de **conferência**, não de fonte.

**F07 e F08 são a mesma figura.** Dois registros de dez bytes:

    F8 @0xDC0A: 02 80 80 00 ec 35 72 56 04 80
    F7 @0xDC14: 02 80 80 00 ec 35 72 56 04 6e

Cabeçalho de grupo, pivô 0x80,0x80, um filho em 0xD86A com sobreposição de cor.
O byte de cor é `04` nos dois; o byte seguinte é o que a VM busca e **descarta**.
Mesmo `canonical_md5`, mesma caixa. Ou seja: `DECOR_F7_BLINK_3X_LOOP` alternava
duas constantes que desenham a mesma coisa. A piscada que dá nome à rotina não
existe.

Resultado: nomes com coordenada embutida no repositório, de 22 para **zero**.

## O erro que eu cometi, e que só um teste pegou

No fim, testei as sondas que eu mesmo tinha acabado de commitar. A que produz
toda a evidência acima foi escrita **antes** das renomeações que ela justifica,
e ninguém reapontou as tabelas de nomes dentro dela. Depois que as renomeações
entraram, treze das dezesseis linhas imprimiam `NOT DEFINED`, e o número que eu
tinha publicado na nota e na mensagem de commit — "16 de 16 idênticos byte a
byte" — voltava como "3 de 3".

A geometria nunca esteve errada. O que quebrou foi a capacidade de reproduzi-la,
que é justamente a parte que importa: uma medida cujo produtor não roda mais é
a afirmação não verificável que commitar o produtor deveria impedir. Reapontada,
volta a 16 de 16. E ganhou uma guarda: a sonda agora sai com erro se qualquer
nome das suas tabelas deixar de existir, em vez de relatar um total menor em
silêncio.

A mesma varredura pegou outra: `2468 de 10144 polígonos mudam de extensão`,
publicado quando a correção do pivô de grupo entrou, hoje reproduz como
`2195 de 9397`. A proporção segue em ~24%, mas a população mudou em 747 nomes ao
longo de um dia de renomeações. As duas notas agora trazem os dois números com
data e a instrução de re-executar antes de citar qualquer um — e dizem
explicitamente que **a causa da queda não foi investigada**, porque foi notada
numa varredura de obsolescência e não perseguida. É pior dar uma causa que a
medida não sustenta do que registrar a pergunta em aberto.

## O que fica

Três coisas, e nenhuma delas é sobre este jogo:

1. **Duas suposições que concordam não são uma conferência** se a segunda veio
   da primeira. O nome da rotina e a leitura da figura tinham a mesma origem.
2. **A pergunta que a ferramenta responde não é sempre a que você tem.** Um SVG
   por offset é o padrão certo e foi o que escondeu a planta; o conserto é uma
   ferramenta de dez linhas que desenha camadas na âncora que elas dividem.
3. **Uma medida publicada precisa continuar rodando.** Não basta commitar o
   produtor no dia; ele apodrece contra as próprias mudanças que justificou, e
   só um teste o pega.
