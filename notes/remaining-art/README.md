# The shape of the art that is still numbered

| file | question it answers | command |
| --- | --- | --- |
| `by_anchor.py` | How is the remaining `CINEMATIC_<index>` art drawn, and which method does each class need? | `python3 notes/remaining-art/by_anchor.py` |
| | Which routines are `fill` + full-screen layers, i.e. backdrops? | `... --backdrops` |

`../sole-named-drawer/README.md` ends with a ledger showing every drawer-side
seam is now worth 0 and that **1,655** pictures are numbered in *both*
priority ports with identical art. Nothing in the call graph separates them,
so the next question is not who draws a picture but **how**, because the draw
operands sort the backlog into classes that need different evidence.

Measured 2026-09-23 over PRISON, CAVES and CAPSULE in both priority ports:

| anchor | draws | distinct pictures |
| --- | --- | --- |
| fixed literal `x,y` | 2978 | 1152 |
| variable pair (actor/prop slot) | 2647 | 1534 |
| hero slot | 1256 | 788 |
| one literal, one variable | 474 | 228 |

A "distinct picture" is a `(port, stage, constant)` triple, so a constant
numbered in both ports counts twice.

The methods already exist, one per class:

- **hero slot** — `../shared-bank-geometry/`: pose and height measured against
  the named walk frames, gait phase from the drawers.
- **actor/prop slot** — `../actor-sprite-sheet/`, under the `#0138` rule that
  a picture at the actor slot is not named from the scene drawing it.
- **fixed literal** — scenery, and the one with no method yet. It cannot be
  named from its coordinates: `docs/NAMING.md` §1 forbids it and
  `../lake-shooting/` is the cautionary tale of a whole scene hidden inside a
  coordinate-grouped name.

## The backdrops, and the two guesses that failed

42 routines are structurally unmistakable: `fill`, then N pictures at one
anchor of which at least one is full-screen, then `ret`.

```
DRAW_CIN_305_TO_309_5F_AT_AACB4DF5:
        fill page=0x00, color=0x03
        video offset=CINEMATIC_305, x=160, y=100
        ... 306, 307, 308, 309 ...
        ret
```

and the caller frames it as a render: `selectVideoPage 0x00`, the call,
`selectVideoPage 0xFF`. These are backdrops drawn in layers.

What is missing is **which screen**, and that is the whole reason they are
still numbered. Two hypotheses were tested and both failed:

1. *The two-hex token in the generated label is the screen.* Of the 54
   `DRAW_CIN_..._<XX>_AT_<hash>` labels, **0** are reached under a
   `[SCREEN_NUM]` guard equal to their token.
2. *It is the draw count.* 42 of 74 match the number of draws in the body and
   32 do not.

Nor is it at the call site: `DRAW_CIN_305_TO_309_5F` is called from
`LABEL_815E`, itself unnamed, with no guard. And there is no single screen
dispatcher to read — `[SCREEN_NUM]` is compared **182 times across 52 distinct
values in CAVES alone**, scattered as guards through the stage.

So attaching a screen to a backdrop is a multi-hop reachability problem
through unnamed labels. That is the next piece of real work, and it unlocks
the largest class that has no method yet.

## Where a composite already carries its screen

Six of the 42 have the screen in the label already — `CAVES_SCREEN_92_
BACKDROP_DRAW` and kin. Where that is so, the layers are that screen's
backdrop in the order the machine draws them, and `--proposals` names them
`CINEMATIC_<STAGE>_SCREEN_<NN>_BACKDROP_LAYER_<i>`.

Only a layer drawn by that composite **and nothing else** may take the name,
and that restriction does most of the work here. Screens 0x92 and 0x93 in
CAVES are three layers each and share two of them:

```
CAVES_SCREEN_92_BACKDROP_DRAW   606  617  618
CAVES_SCREEN_93_BACKDROP_DRAW   606  619  618
```

`606` (438x248, the full-screen base) and `618` (391x29, a strip across the
top) belong to both screens and to neither name; `606` is drawn by three more
routines besides. Only the middle layer distinguishes the two screens —
`617` at 306x14 for 0x92 and `619` at 314x63 for 0x93, each drawn by its own
composite and by nothing else in the stage.

So four names, applied branch-scoped because the symbols differ per port
(amiga `617`/`619`, msdos `638`/`640`) while the art is identical in both,
`canonical_md5` agreeing on all four pairs. `make test` 29/29 and 29/29,
`undefined_symbols.py` clean, and `--proposals` now prints nothing.

Four is a small number, and it is the honest size of what this rule can reach
until more composites carry their screen. The rule is worth having written
down because it scales the moment the reachability work above lands: every
composite that gains a screen name hands its exclusive layers over for free.
