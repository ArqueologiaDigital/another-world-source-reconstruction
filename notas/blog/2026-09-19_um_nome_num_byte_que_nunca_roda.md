# Um nome num byte que nunca roda

*Quatro vezes numa sessão só, uma ferramenta copiou um nome **correto** para um
byte que não pode executar. O portão de verificação passou 29/29 o tempo
inteiro, e passaria de qualquer jeito: um nome de rótulo não é um byte.*

---

O projeto mantém o mesmo jogo em quatro versões — Amiga 1991, MS-DOS 1992,
cartucho 1992, GBA 2004 — e duas árvores de fonte: uma por versão, e uma
unificada com blocos condicionais. Tudo é conferido montando e comparando byte
a byte com o original: 29 combinações de porte e fase, duas vezes.

Nomes não entram nessa conta. Renomear um rótulo não move um byte. É por isso
que o portão nunca vai reclamar de um nome errado, e é por isso que o erro
abaixo sobreviveu.

## O que aconteceu

Depois de nomear rotinas numa versão, o fluxo do projeto é propagar: casar as
versões pelo fluxo de instruções e levar o nome para quem ainda não tem. Quatro
vezes, isso pôs um nome descritivo em cima de um bloco de bytes que nenhum
caminho de execução alcança.

| versão / fase | nome que chegou | onde foi parar |
|---|---|---|
| Amiga / TANK | `CAPSULE_DOME_CLOSED_REDRAW_LOOP` | um bloco `db` de 100 bytes |
| cartucho / INTRO | `BLIT_DISPATCH_VAR3_LOOP` | `LABEL_00E4` |
| GBA / INTRO | `BLIT_DISPATCH_VAR3_LOOP` | `LABEL_00EA` |
| MS-DOS / TANK | `TANK_BACKDROP_SWAY_ANIM_LOOP` | `LABEL_16D4` |

O detalhe que torna isso difícil de ver: **o nome está certo de onde veio.** Na
MS-DOS, `BLIT_DISPATCH_VAR3_LOOP` é uma rotina de verdade, que faz
`add [0xC7], 0x0001` e manda o quadro para a tela. Na MS-DOS,
`CAPSULE_DOME_CLOSED_REDRAW_LOOP` realmente segura um quadro da cúpula
fechando, para sempre. Ninguém inventou nada.

O que acontece é que **as versões discordam sobre quais endereços são vivos**.
Uma rotina que roda numa é enchimento de fim de bloco na outra, na posição
equivalente do alinhamento, e a árvore unificada guarda um nome só para o par.
Levar esse nome para baixo faz com que ele descreva algo que nunca executa.

## Por que só uma ferramenta tinha a defesa

Havia duas ferramentas de propagação. A que casa duas versões entre si já
recusava isso, com um comentário citando o caso que a motivou:

```python
# Never move a meaningful name onto a byte nothing can reach. […]
if tgt in tgt_dead or ref in ref_dead:
    continue
```

A que leva nomes da árvore unificada para a de uma versão fazia o mesmo
trabalho e **não tinha a guarda**. O defeito estava fechado num caminho e
aberto no outro, e por isso ninguém notou que continuava aberto.

Agora tem, e ela diz o que recusou em vez de ficar calada:

```
      keeping the address name on 1 unreachable byte(s) (#0126):
        LABEL_16D4 stays, not TANK_BACKDROP_SWAY_ANIM_LOOP
```

## O conserto que eu errei primeiro

Achados os dois primeiros casos, renomeei os rótulos de volta para a forma de
endereço — em todas as versões de uma vez.

Errado. Nas outras versões aqueles mesmos nomes estão sobre rotinas **vivas** e
são exatos: a MS-DOS realmente faz um teste de faixa de ±10 pixels em
`CAVES_CHECK_HERO_Y_E7_WITHIN_20PX_BAND`. Eu tinha acabado de destruir dois
nomes bons para consertar dois nomes ruins.

Quem pegou foi uma terceira verificação, que confere se todo rótulo do formato
`LABEL_<hex>` afirma o endereço em que de fato está:

```
genesis_europe/CAVES: LABEL_1296 is at 0x13AC -> LABEL_13AC
msdos/CAVES:          LABEL_1296 is at 0x1411 -> LABEL_1411
```

Os espaços de endereçamento das versões são diferentes, então um nome de
endereço honesto numa é mentira na outra — e foi essa mentira, não o nome
perdido, que me avisou.

## O que fica disso

**Numa árvore de fontes com vários alvos, "a mesma rotina" é um alinhamento,
não uma identidade.** Duas posições que casam no fluxo de instruções podem ser
código numa versão e lixo de preenchimento na outra, e qualquer coisa que
propague um atributo ao longo desse casamento precisa perguntar se o atributo
continua verdadeiro do outro lado.

E: **uma afirmação que o portão não consegue conferir precisa do portão dela.**
O portão de bytes é excelente e é cego para nomes. A verificação que enxerga
esta classe é outra, roda em segundos, e passou a ser obrigatória depois de
cada propagação — foi ela que achou os quatro casos, um deles de meses atrás
que ninguém tinha visto.

---

Conferível: a ferramenta de blocos inalcançáveis relata hoje zero nomes
semânticos sobre bytes inalcançáveis, em 3.066 bytes rotulados desse tipo nas
quatro versões; a de endereços relata que todo `LABEL_<hex>` afirma o endereço
em que está; e `make test` segue 29/29 e 29/29 — como seguia durante todo o
período em que os quatro nomes estavam errados.
