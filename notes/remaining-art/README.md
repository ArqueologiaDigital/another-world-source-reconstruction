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
