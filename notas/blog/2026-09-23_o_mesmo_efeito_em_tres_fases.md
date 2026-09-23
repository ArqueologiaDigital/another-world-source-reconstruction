# O mesmo efeito em três fases

Uma sonda deste projeto carrega nomes de arte entre **fases** quando os bytes
são idênticos, e ela retém deliberadamente um caso: quando o nome de origem
carrega o prefixo de outra fase. O texto dela diz por quê, e está certo:

> tirar `CAVES_` e recolocar outro prefixo inventaria um nome que ninguém
> ganhou.

São 36 candidatos retidos na versão Amiga, 34 na MS-DOS. Eu fui olhar por quê
e encontrei uma terceira saída que o texto não considera.

## Se a arte está em três fases, a palavra de fase está errada

Não é que ela não possa ser transportada. É que ela **não devia estar ali**.

Sete quadros de um brilho de carga são byte a byte idênticos em PRISON, CAVES
e CAPSULE, nas duas versões prioritárias: 42 constantes, exatamente uma por
quadro por fase por versão, com tamanhos 5x6, 6x8, 12x8, 12x12, 12x14, 12x12,
12x14 e duas folhas cada. Um efeito que aparece em três fases não é
específico de fase nenhuma.

Então o nome perdeu a palavra: `CINEMATIC_ACTOR_CHARGE_GLOW_F0..F6`, em todas
as três. **Remover um escopo não inventa nada** — ao contrário de recolocá-lo.

E o prefixo `PRISON_` que eles carregavam também não era ganho: fui eu que o
pus, uma hora antes, na mesma sessão, antes de as cópias de CAVES e CAPSULE
aparecerem. Abrir mão do próprio escopo é mais barato do que discutir o dos
outros.

O achado veio de seguir uma animação de seis tiques dentro de uma rotina de
decaimento de escudo em CAVES — `CINEMATIC_068` a `073` — cujas extensões
batiam exatamente com a família de PRISON. E então **conferi o md5 canônico em
vez de confiar na coincidência de tamanho**, que é o passo que separa isto de
um palpite.

## E então a regra que eu escrevi quase fez estrago

Escrevi no README, em uma linha: "arte em três fases, então tire a palavra de
fase". Rodada sobre a árvore inteira, essa regra oferece treze nomes e **só um
é seguro**.

A condição que faltava, e que teria feito estrago de verdade: **o nome não
pode carregar um número de tela.** A regra ofereceu

```
PRISON  CINEMATIC_384  ->  CINEMATIC_SCREEN_6A_BACKDROP_LAYER_0
CAVES   CINEMATIC_134  ->  CINEMATIC_SCREEN_6A_BACKDROP_LAYER_0
```

a partir de `CINEMATIC_CAPSULE_SCREEN_6A_BACKDROP_LAYER_0`. Um número de tela
é por fase **e** por versão — nesta mesma sessão eu já tinha tido de consertar
`CAPSULE_SCREEN_6C_BACKDROP_DRAW` porque a versão Amiga numera aquela tela
como 0x4C e **nunca** compara `[SCREEN_NUM]` com 0x6C. `SCREEN_6A` sem fase é
um número sem nada para indexar. Três dos treze tinham essa forma.

A terceira condição: **o prefixo que se remove não pode ser um nome ganho por
outra pessoa.** O brilho de carga passou porque o `PRISON_` era meu.
`CINEMATIC_PRISON_SUPERBLAST_BEAM_TILE_0` não é, e re-escopá-lo é uma
discussão separada de batizar as cópias sem nome.

O único sobrevivente das três condições a própria sonda já retém, pela regra
dela de "a arte casa com dois nomes diferentes", que está certa.

**Efeito líquido além do brilho de carga: zero nomes.** O valor do commit é
que a regra não pode mais ser reaplicada a partir da versão de uma linha.

## Duas vezes no mesmo dia

É a segunda vez nesta sessão que uma regra minha pareceu geral e não era. A
primeira foi um interpretador de nomes que eu alarguei, commitei, e tive de
reverter porque a arte o contradizia seis vezes em seis. Esta eu peguei antes
de aplicar.

A diferença entre as duas não foi sorte: foi ter rodado a regra sobre a árvore
inteira antes de acreditar nela. Treze propostas, uma segura — isso é uma
medida, e uma linha de README não é.
