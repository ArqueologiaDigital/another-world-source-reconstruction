# Vinte nomes a um `setup` de distância

*A fase CAVES guarda a orientação do herói numa máquina de quatro estados. Os
**dez pontos de entrada** dessa máquina já estavam batizados, nas duas versões
prioritárias, desde alguma passada anterior. As rotinas que eles instalam, não:
oito das dez continuavam `LABEL_<hex>`. O nome estava a uma instrução de
distância do lugar onde faria falta.*

---

## A máquina

Um `[0x63]` guarda o estado. Um despachante lê o teclado e escreve nele:

```
[0x63] = 0
se  entrada horizontal == -1 : [0x63] = 1     (esquerda)
se  entrada horizontal == +1 : [0x63] = 2     (direita)
se  entrada vertical   == -1 : [0x63] = 3     (cima)
se  entrada vertical   == +1 : [0x63] = 4     (baixo)
```

E dez rotinas `START_HERO_DIRECTION_<A>_TO_<B>_TURN`, uma para cada par
ordenado de LEFT/RIGHT/UP/DOWN, cada uma instalando um corpo no canal 0x15.
Duas delas instalam corpos já batizados no mesmo formato
(`HERO_DIRECTION_LEFT_TO_RIGHT_TURN`); as outras oito instalavam um
`LABEL_<hex>`.

O sinal do `-1` **não foi suposto**. Está corroborado no mesmo arquivo:
`je [HERO_POS_JUMP_DOWN], 0xFFFF, HERO_JUMP_LEFT_RUN_PRELUDE` — um nome ganho
antes, em que `-1` é a tecla de pulo.

O que torna a passada segura não é a tabela, é uma contagem: a sonda conta
**todos** os `setup` da fase que instalam cada corpo. Um corpo alcançado por
dois pontos de entrada não poderia receber o nome de nenhum dos dois (é o
#0118 chegando pelo outro lado), e a sonda sai com erro se isso acontecer. Dez
corpos, dez instaladores, nenhum compartilhado.

### O erro que cometi no meio

Li os estados da Amiga pela renderização antes de conferir quem os chama, e
concluí que as duas versões numeravam os estados de forma diferente. **Não
numeram.** As duas concordam em 1=LEFT 2=RIGHT 3=UP 4=DOWN. A diferença real
entre elas é outra, e menor: a Amiga testa `HERO_POS_JUMP_DOWN` (0xFB) onde a
MS-DOS testa `HERO_POS_UP_DOWN` (0xE5).

## Duas camadas, e só uma batizada

Seguindo a máquina até a arte, apareceu uma coisa que não estava no plano:
**cada estado desenha em duas camadas**. O despachante desenha o corpo; um
segundo laço, instalado no canal 0x16, desenha outra coisa no mesmo ponto — e
cicla 11 quadros contra os 2 a 5 do corpo. Dois períodos independentes são duas
coisas.

A medição que separa as camadas lê a cor **direto do ROM**, não de uma
renderização: o byte de cabeçalho de um polígono sólido é `>= 0xC0` e os seis
bits baixos são o índice de cor. É independente de paleta.

- todo quadro do canal 0x16, nos quatro estados, é o índice 6 e **mais nada**;
- os quatro corpos compartilham os índices {0, 2, 3, 4, 10, 14} — o que já vale
  alguma coisa: são quatro estados de **uma** figura, não quatro figuras;
- LEFT e RIGHT acrescentam o 6; UP e DOWN **nunca** o usam, então ali a segunda
  camada é a única coisa na tela naquela cor;
- as segundas camadas de LEFT e RIGHT são uma animação só, espelhada: mesmas
  extensões quadro a quadro e **dez de dez** passos do centro em x indo em
  direções opostas, ida e volta.

A sonda achou um defeito nela mesma no caminho, e o registro ficou na
docstring: a primeira versão passava direto pelo byte de *override* de cor de
um filho de grupo e lia a cor do cabeçalho de cada folha. LEFT e RIGHT usam
override, UP e DOWN não — então o defeito apareceu como os dois pares
discordando sem motivo visível.

E as quatro rotinas do canal 0x16 **continuam `LABEL_<hex>`**. Uma cor e uma ou
duas folhas comportam mais de uma leitura, e a norma quer que a renderização
resolva o assunto antes de o nome afirmar um. Aqui ela não resolve.

## O que a arte devolveu de graça

Duas coisas erradas nas mesmas quatro animações.

**A família começava dois quadros tarde.** Cada laço de espera é um palíndromo
de cinco quadros — a entrada desenha dois, o laço interno desenha três e volta.
Os nomes existentes `..._IDLE_LEFT_0..2` cobriam só o laço interno, então os
dois primeiros quadros seguiam com número e o índice 0 estava no terceiro
quadro.

**Seis nomes da MS-DOS estavam em arte alheia.** Estão nos **mesmos índices**
da Amiga — 797/798/799 e 511/512/513, as mesmas linhas, porque as tabelas de
EQU são alinhadas por índice — e foram copiados por índice. Medidos:

| nome | aponta para | deveria ser |
|---|---|---|
| `CAVES_HERO_IDLE_LEFT_0` | 12x70, 3 folhas | 66x70, 11 folhas |
| `CAVES_HERO_IDLE_LEFT_1` | **2x5, 6 folhas** | 66x70, 11 folhas |
| `CAVES_HERO_IDLE_RIGHT_1` | 74x90, 8 folhas | 116x70, 11 folhas |

Um borrão de 2x5 com seis folhas não é quadro de coisa nenhuma. Os laços da
MS-DOS desenham, de fato, 819..823 e 530..534 — contíguos, e batendo com os da
Amiga cinco para cinco, inclusive nos cantos.

## Duas ferramentas que não sabiam dizer isto

Nenhuma das duas correções passou pelo validador, e os dois motivos eram
defeitos de expressão, não recusas legítimas:

- o validador julgava **linha por linha**, então uma renumeração era sempre
  recusada: `CINEMATIC_795` assumindo o `_0` parece uma fusão com o `_0` que
  existe, mesmo que o mesmo lote renomeie aquele para `_2`. Como as
  renomeações são aplicadas simultaneamente, um nome que o lote aposenta não é
  colisão. E a saída óbvia — renomear em ordem decrescente — é recusada pela
  regra de buracos de família, **com razão**: cada estado intermediário tem um
  buraco de verdade. Uma renumeração só pode ser dita como um lote só.
- e um **rebaixamento** não tinha como ser dito, porque o alvo é um número e
  número não é nome. Agora tem, e é conferido em vez de aceito: o índice
  precisa ser o que a posição do constante na tabela de EQU dá. Ele recalculou
  797/798/799 e 511/512/513 sozinho e só aceitou porque bateram com o que eu
  tinha derivado à mão.

## O saldo

20 rotinas e 46 constantes, nas duas versões prioritárias. Arte nomeada de
33,9% para 34,2% (3.467 de 10.145); amiga/CAVES de 26,3% para 26,6%.

---

Conferível: `make test` 29/29 e 29/29 o tempo todo — um nome de rótulo não é um
byte. As sondas estão em
`notes/hero-direction-machine/` (`derive_state_map.py`, que sai com erro se
algum corpo ganhar um segundo instalador, e `layer_colour_census.py`), e as
tabelas com a evidência por símbolo em
`another-world-archaeology/docs/content/research/2026-09-19-caves-hero-direction-machine/`.
