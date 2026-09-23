# INTRO: the lift doors, and the two marks in the shaft

Five pictures, three routines, and in every case the routine's own body says
which is which before the render is consulted.

## The two door leaves close toward each other

```
LIFT_DOORS_CLOSING_LOOP:
    break
    add [0x02], 0x0001          <- one x grows
    sub [0x03], 0x0001          <- the other shrinks
    video offset=CINEMATIC_108, x=[0x02], y=94
    video offset=CINEMATIC_109, x=[0x03], y=94
    djnz [0x01], LIFT_DOORS_CLOSING_LOOP
```

Both are a **single path**, 14.0x167.0 and 15.0x161.0 -- tall narrow slabs, the
same height to within six pixels, nothing else in them. The leaf on the growing
x travels right, so it enters from the left; the leaf on the shrinking x
travels left, so it enters from the right. That is the whole basis for
`_LEFT` and `_RIGHT` and it comes from the two opposite-signed variables, not
from the picture, which is a plain rectangle either way.

This is a different mechanism from `CINEMATIC_LIFT_DOORS_OPENING_F0..F31`,
which animates by frame. Here two slabs are animated by position.

## What is left standing when they shut

The same loop, once the count runs out, draws `CINEMATIC_107` at a **fixed**
`x=143, y=94`, and `LIFT_SCENE_FIXED_OVERLAY_REDRAW_LOOP` then redraws that one
picture and nothing else, forever, one per `break`. It is 71.0x186.0 in 4
paths: two small squares high in the frame and a wedge at the foot -- sparse,
wider than either leaf, and never moved.

## Two marks in the shaft, one descending and one not

```
LIFT_SHAFT_MARKER_DESCENT_HOLD:
    break
    video offset=CINEMATIC_110, x=121, y=[0x03]
    video offset=CINEMATIC_111, x=121, y=187
    djnz [0x04], LIFT_SHAFT_MARKER_DESCENT_HOLD
    add [0x03], 0x0002
```

Both are **2.0x4.0** -- four pixels tall, two wide -- and both are drawn at the
same `x=121`. One takes a y the outer loop advances by 2 a pass; the other is
nailed to `y=187`. `MARKER` is the routine's own word.

## Proposals

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_108 | CINEMATIC_LIFT_DOOR_LEAF_LEFT | high | 0x403C, 14.0x167.0 in **1 path**. Drawn at `x=[0x02]`, the variable `LIFT_DOORS_CLOSING_LOOP` increments, so it travels right and enters from the left |
| CINEMATIC_109 | CINEMATIC_LIFT_DOOR_LEAF_RIGHT | high | 0x4046, 15.0x161.0 in **1 path**. Drawn at `x=[0x03]`, the variable the same loop decrements |
| CINEMATIC_107 | CINEMATIC_LIFT_SCENE_FIXED_OVERLAY | medium | 0x4010, 71.0x186.0 in 4 paths: two small squares and a wedge at the foot. Drawn at a fixed `x=143, y=94` when the doors finish shutting, and it is the **only** picture `LIFT_SCENE_FIXED_OVERLAY_REDRAW_LOOP` draws |
| CINEMATIC_110 | CINEMATIC_LIFT_SHAFT_MARKER_MOVING | high | 0x4074, **2.0x4.0** in 2 paths, drawn at `x=121, y=[0x03]`, the variable `LIFT_SHAFT_MARKER_DESCENT_HOLD` advances by 2 each outer pass |
| CINEMATIC_111 | CINEMATIC_LIFT_SHAFT_MARKER_FIXED | high | 0x4068, **2.0x4.0** in 1 path, the same size and the same `x=121` as the other, at a `y=187` that never changes |

## What these names do not claim

`LIFT`, `DOOR`, `SHAFT`, `MARKER` and `FIXED_OVERLAY` are all the routines'
words. Nothing here says what the marks stand for -- a car position, a floor
number, a lamp. They are four-pixel-tall marks at one x, one of which moves and
one of which does not, and the names say exactly that.

`_LEFT` and `_RIGHT` are about where each leaf comes from, which the sign of
its variable fixes. The two pictures themselves are indistinguishable plain
slabs and could not have settled it.
