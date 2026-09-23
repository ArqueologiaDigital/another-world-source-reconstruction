# CAVES: the cave-dressing kit -- five spikes reused across nine routines

## What the census pointed at

`by_anchor.py`'s "fixed literal x,y" class is the biggest unworked one, and its
densest routine in CAVES is `LABEL_C433`: twenty-one draws, no `break` between
them, then one `break` and `jmp` back to the top -- the whole thing repainted
every frame.

```
  video 580, x=85,  y=105
  video 382, x=102, y=99      ... and at 94,88  107,102  116,95  151,86  178,115  272,39
  video 385, x=53,  y=131     ... and at 137,135  141,135  135,133  195,143
  video 383, x=104, y=138     ... and at 206,145  213,144
  video 380, x=261, y=41
  video 382, x=246, y=27      ... and at 239,24  233,27
  video 747, x=160, y=100
```

Six constants, twenty-one placements. Composited at palette 9 the screen fills
with **tapering spikes hanging from above**, a few standing from below, and one
large pillared mass behind them.

## Why they are a kit and not a screen

The five spikes are drawn by nine different routines between them --
`LABEL_C391, C3AD, C3C1, C3DF, C3F4, C405, C433, C497, C4D5, C50C, C532, C550,
C557, C560, C581, C5A0, C5B1, C5CF` -- 61 placements in all. Nothing about them
belongs to one screen, so none of them takes a screen word. What separates them
is size, which is measured:

```
  382   9.0x35.0    383  11.0x32.0    385  11.0x42.0    380  15.0x43.0    580  19.0x44.0
```

Each is **one leaf**: a single polygon that pinches to nothing partway down, so
it draws as a spike from above with a small foot beneath it. That is what a
stalactite over its stalagmite looks like, and the stage already carries
`CINEMATIC_CAVES_SCREEN_6C_STALAGMITE` for the floor-only kind.

The two large ones are drawn once each, at `160, 100`, by one routine each --
747 by `LABEL_C433` and 737 by `LABEL_C497` -- which is the backdrop slot, and
they are told apart by width, 73.5 against 200.5.

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_382 | CINEMATIC_CAVES_STALACTITE_0 | medium | 0xF39C, **9.0x35.0** in one leaf, the narrowest of the five; 21 placements across eight routines |
| CINEMATIC_383 | CINEMATIC_CAVES_STALACTITE_1 | medium | 0xF36C, 11.0x32.0 in one leaf; 11 placements across eight routines |
| CINEMATIC_385 | CINEMATIC_CAVES_STALACTITE_2 | medium | 0xF37C, 11.0x42.0 in one leaf -- the same width as the last and ten pixels longer; 10 placements |
| CINEMATIC_380 | CINEMATIC_CAVES_STALACTITE_3 | medium | 0x4DB4, 15.0x43.0 in one leaf; 13 placements across nine routines |
| CINEMATIC_580 | CINEMATIC_CAVES_STALACTITE_4 | medium | 0xF35C, **19.0x44.0** in one leaf, the widest and longest; 6 placements |
| CINEMATIC_381 | CINEMATIC_CAVES_STALAGMITE_STUB | medium | 0xF38C, 14.0x13.0 in one leaf -- wider than it is tall, the only one of the six that is; 6 placements across five routines |
| CINEMATIC_747 | CINEMATIC_CAVES_CAVERN_PILLARS_NARROW | medium | 0xFB62, 73.5x185.0 in 4 leaves, drawn once at `160, 100` by `LABEL_C433` and nowhere else |
| CINEMATIC_737 | CINEMATIC_CAVES_CAVERN_PILLARS_WIDE | medium | 0xFB46, **200.5x236.0** in 6 leaves, drawn once at `160, 100` by `LABEL_C497` and nowhere else |

The index runs on increasing width, ties broken on height, which is the same
rule `CINEMATIC_CAVES_FALLING_ROCK_{SMALL,MEDIUM,LARGE}` was named under. The
`medium` is on the word, not the ordering: a one-leaf polygon that pinches and
tapers, hung in scattered clusters over a cave scene, is a stalactite on any
reading, but nothing here proves the stage means it as one.
