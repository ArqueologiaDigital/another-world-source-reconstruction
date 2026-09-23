# CAVES: eleven pictures shared across ten backdrop routines

Ten of the stage's `CAVES_SCREEN_*_BACKDROP_DRAW` routines still had numbered
layers, but only **eleven distinct pictures** between them -- most are drawn by
several screens. Scoping first is what made this one batch instead of ten.

```
  624, 625, 708  screens C9, CC, and three CAVES_FALLING_ROCK_*_DRAW routines
  436            screens 6F, 87, 8F, AD, ED
  596            screens 8F, AD          337   screens 4C, 4D
  634            screens A8, A9          636   screen AD only
  589, 590       screen 8A only          342   screen 4D only
```

## Three that name themselves

`CINEMATIC_625`, `624` and `708` are each drawn by a routine that already says
what it is -- `CAVES_FALLING_ROCK_SMALL_DRAW`, `..._MEDIUM_DRAW`,
`..._LARGE_DRAW` -- and the measurements agree independently:

```
  625  0xCED4  21.0x19.5   5 paths     small
  624  0xCF2C  38.5x24.5   5 paths     medium
  708  0xCF8C  57.5x28.5   7 paths     large
```

21.0 < 38.5 < 57.5, in the order the three routine words claim. Two independent
sources agreeing is why these are `high` and the rest are `medium`.

## The rest

```
  436  0x8D74  198.0x209.0   1 path     drawn by five screens, once with zoom=0x40
  596  0x9AA4  148.0x114.0   1 path     screens 8F and AD
  636  0x9AB0   44.0x 44.0   1 path     screen AD, drawn twice
  589  0x5084  388.5x230.0  70 paths    screen 8A, drawn twice one pixel apart
  590  0x52B8  367.0x205.0  55 paths    screen 8A, drawn twice one pixel apart
  634  0xAE40   62.0x117.0  69 paths    screens A8/A9, drawn twice, x=155 and x=25
  337  0xABF8   14.0x 19.0   3 paths    screens 4C and 4D
  342  0xAC40   12.5x 11.5   4 paths    screen 4D
```

436, 596 and 636 are **single paths** -- plain filled rectangles of three
sizes, used as the base a screen is built on. 589 and 590 are the two detailed
layers of screen 8A, each drawn twice a pixel apart, which is how this stage
puts an outline under a shape. 634 is a tall narrow piece with jagged edges and
spikes at its foot, drawn twice side by side at x=155 and x=25.

## Proposals

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_625 | CINEMATIC_CAVES_FALLING_ROCK_SMALL | high | 0xCED4, 21.0x19.5 in 5 paths -- the smallest of the three -- and the only picture `CAVES_FALLING_ROCK_SMALL_DRAW` draws |
| CINEMATIC_624 | CINEMATIC_CAVES_FALLING_ROCK_MEDIUM | high | 0xCF2C, 38.5x24.5 in 5 paths, and `CAVES_FALLING_ROCK_MEDIUM_DRAW`'s only picture |
| CINEMATIC_708 | CINEMATIC_CAVES_FALLING_ROCK_LARGE | high | 0xCF8C, 57.5x28.5 in 7 paths -- the largest -- and `CAVES_FALLING_ROCK_LARGE_DRAW`'s only picture |
| CINEMATIC_436 | CINEMATIC_CAVES_BACKDROP_FIELD_LARGE | medium | 0x8D74, **1 path**, 198.0x209.0: a plain filled rectangle, drawn by five screens and once at `zoom=0x40` |
| CINEMATIC_596 | CINEMATIC_CAVES_BACKDROP_FIELD_MEDIUM | medium | 0x9AA4, **1 path**, 148.0x114.0, the same kind of plain fill, on screens 8F and AD |
| CINEMATIC_636 | CINEMATIC_CAVES_SCREEN_AD_BACKDROP_FIELD_SMALL | medium | 0x9AB0, **1 path**, 44.0x44.0, drawn twice on screen AD alone |
| CINEMATIC_589 | CINEMATIC_CAVES_SCREEN_8A_CAVERN_WALL | medium | 0x5084, **70 paths**, 388.5x230.0 -- wider than the page -- the first layer screen 8A draws, and drawn twice one pixel apart |
| CINEMATIC_590 | CINEMATIC_CAVES_SCREEN_8A_CAVERN_RIDGE | medium | 0x52B8, 55 paths, 367.0x205.0, drawn immediately after it and also doubled: a ridge silhouette over the wall |
| CINEMATIC_634 | CINEMATIC_CAVES_SHAFT_COLUMN | medium | 0xAE40, **69 paths**, 62.0x117.0: a tall narrow piece with jagged edges and spikes at its foot, drawn twice side by side at x=155 and x=25 on screens A8 and A9 |
| CINEMATIC_337 | CINEMATIC_CAVES_GLOW_STONE | medium | 0xABF8, 3 paths, 14.0x19.0: a rounded shape with a bright core inside a darker rim. Screens 4C and 4D |
| CINEMATIC_342 | CINEMATIC_CAVES_SCREEN_4D_ROCK_CORNER | medium | 0xAC40, 4 paths, 12.5x11.5: dark angular strokes meeting at a corner. Screen 4D alone |

## What these names do not claim

The three rocks are `high` because two independent sources agree -- the routine
words and the size order. Nothing else here has that, and the rest are
`medium`.

`BACKDROP_FIELD` says a single-path filled rectangle used as a base, and
nothing about what it represents. `CAVERN_WALL` and `CAVERN_RIDGE` say which of
screen 8A's two layers is drawn first and that the second is a silhouette over
the first; neither claims a distance. `GLOW_STONE` says a bright core in a
darker rim at 14x19 and does not claim it emits anything.
