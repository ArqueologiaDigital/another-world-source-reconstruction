# INTRO: the two halves of the lab door

`LAB_DOOR_LEAVES_PARTING_LOOP` is an earned name and its body says which half
is which:

```
  sub [0x01], 0x0014                       <- one y goes down each pass
  add [0x02], 0x0014                       <- the other goes up
  video offset=CINEMATIC_121, x=160, y=[0x01]
  video offset=CINEMATIC_122, x=160, y=[0x02]
```

Rendered at palette 0x0E the two are the halves of one rectangle:

```
  0x446C  153.0x137.0  4 paths  x[73.5, 226.5]  y[ -1.0, 136.0]
  0x44B0  153.0x 87.0  4 paths  x[73.5, 226.5]  y[135.5, 222.5]
```

Same width, same x to the half-pixel, and their y ranges meet at 135.5/136.0
with no overlap and no gap. `CINEMATIC_121` takes the variable that **shrinks**
and holds the range above the seam; `CINEMATIC_122` takes the one that grows
and holds the range below it.

`LAB_DOOR_LEAVES_REDRAW_LOOP` redraws the same pair at the same two variables,
and `DRIFT_VAR4_PLUS_9_FOR_20X` draws both at a fixed `y=100` -- the shut
position, before the parting begins.

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_121 | CINEMATIC_LAB_DOOR_LEAF_UPPER | high | 0x446C, 153.0x137.0 in 4 paths at y[-1.0, 136.0], everything above the seam. Drawn at `y=[0x01]`, the variable `LAB_DOOR_LEAVES_PARTING_LOOP` decrements by 0x14 a pass |
| CINEMATIC_122 | CINEMATIC_LAB_DOOR_LEAF_LOWER | high | 0x44B0, 153.0x87.0 in 4 paths at y[135.5, 222.5], everything below it. Drawn at `y=[0x02]`, the variable the same loop increments by 0x14 |

## What these names do not claim

`LAB_DOOR_LEAVES` is the routines' own word, in three of them. The only thing
added here is which leaf is which, and that comes from the two y ranges and
the two opposite-signed variables, not from the picture's content.
