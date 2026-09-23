# CAVES: the seven still-numbered layers of screen 6C

`CAVES_SCREEN_6C_BACKDROP_DRAW` is the densest backdrop left in the stage: 7 of
its 36 draws are still numbers. Read with `compose_run.py --progressive
--routine` at palette 0x09, the screen is a cavern of tall columns under a dark
ceiling, with a drift of small dark specks crossing the middle. Its named
layers are already `..._SCREEN_6C_CAVERN_COLUMNS`, `..._CAVERN_COLUMN_LARGE`
and `..._SCREEN_6C_STALAGMITE`.

## Scope first

Four of the seven are drawn by other screens too and take no screen word:

```
  335  screens 4C, 4D, 6C, 70 (+ one generated label)
  336  screens 4C, 4D, 6C
  275  screens 4C, 4D, 4E, 6C, and DRAW_WATERFALL_LEFT_STAIRS...
  395  screen 6C and DRAW_CIN_415_416_FRAGMENTS
  406, 407, 411  screen 6C only
```

## What each is

```
  335  0xAC84   6.5x 5.5   2 paths   two dark slivers meeting at an angle
  336  0xACB0   4.0x 2.0   2 paths   drawn TEN times, scattered across the frame
  407  0xE760  26.0x21.0  38 paths   about twenty of those same marks in one picture
  395  0xE6FC  36.5x38.0   2 paths   two curved strokes, a broken ring; drawn three
                                     times at zooms 0x26, 0x20 and none
  406  0xE6D0  17.5x20.0   2 paths   the same two-stroke arc, narrower
  275  0x7442  37.0x 4.5   8 paths   a thin horizontal bar with blocks along it,
                                     drawn NINE times at one y (153) across the width
  411  0xE7B0  17.0x 4.0   2 paths   two flat slivers
```

The relationship between 336 and 407 is the clearest thing here: 407 is 38
paths and about twenty copies of the two-path mark 336 is one of, and in the
composite both land in the same diagonal drift across the middle of the cavern.
395 and 406 are the same two-stroke construction at two sizes, and in the
composite they sit on the cavern walls at the left and right edges.

## Proposals

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_336 | CINEMATIC_CAVES_DRIFT_MOTE | medium | 0xACB0, **2 paths**, 4.0x2.0, drawn ten times at scattered positions across the middle of the screen. Shared with screens 4C and 4D |
| CINEMATIC_407 | CINEMATIC_CAVES_SCREEN_6C_DRIFT_MOTE_CLUSTER | medium | 0xE760, **38 paths** in 26.0x21.0 -- about twenty marks of the same shape as `..._DRIFT_MOTE`, in one picture, landing in the same drift |
| CINEMATIC_395 | CINEMATIC_CAVES_ROCK_ARC_LARGE | medium | 0xE6FC, **2 paths**, 36.5x38.0: two curved strokes forming a broken ring. Drawn three times on this screen, twice with a zoom (0x26, 0x20), on the cavern walls |
| CINEMATIC_406 | CINEMATIC_CAVES_SCREEN_6C_ROCK_ARC_SMALL | medium | 0xE6D0, **2 paths**, 17.5x20.0 -- the same two-stroke arc, about half the size |
| CINEMATIC_335 | CINEMATIC_CAVES_ROCK_FLECK | medium | 0xAC84, **2 paths**, 6.5x5.5: two dark slivers meeting at an angle. Shared with screens 4C, 4D and 70 |
| CINEMATIC_275 | CINEMATIC_CAVES_LEDGE_SEGMENT | medium | 0x7442, 8 paths, 37.0x4.5, drawn **nine times at a single y=153** across the width -- a repeated horizontal unit. Also drawn by `DRAW_WATERFALL_LEFT_STAIRS...` and by screens 4C, 4D and 4E |
| CINEMATIC_411 | CINEMATIC_CAVES_SCREEN_6C_FLAT_SLIVER | medium | 0xE7B0, **2 paths**, 17.0x4.0, drawn once near the foot of the columns |

## What these names do not claim

Every row is `medium`. `DRIFT_MOTE` says a two-path mark repeated across the
middle of the screen and `..._CLUSTER` says twenty of them in one picture; what
they are -- dust, spores, insects, falling grit -- is not claimed.

`ROCK_ARC` says two curved strokes on the cavern wall, at two sizes. It does not
claim a crack rather than an edge or a shadow.

`LEDGE_SEGMENT` rests on the nine draws at one y and on `..._STAIRS` being
among its other callers, not on the picture, which at 37.0x4.5 is a bar with
blocks on it and could be a step, a rail or a pipe.

`FLAT_SLIVER` is the weakest and says only its shape; it is one picture drawn
once and nothing else in the routine is like it.
