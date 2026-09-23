# Correction: the figure is swimming, not getting up off a floor

`CINEMATIC_HERO_RISE_FROM_PRONE_{RIGHT,LEFT}_0..5` was applied earlier today
from a render at palette 0x05 of `LABEL_DDB4` and `LABEL_DE10` alone. The
extents in that batch are all still right -- the mirror pair is exact, the
width falls 50.0 to 19.5 while the height rises 26.0 to 41.0 -- and so is the
scope, which is why the names carry no stage word. **The subject word is
wrong.**

## What changed the reading

`CINEMATIC_451`, the frame named `_RIGHT_0`, is also drawn by
`HERO_DIRECTION_RIGHT_TO_DOWN_TURN`, one of eight routines in CAVES named
`HERO_DIRECTION_<A>_TO_<B>_TURN` over A and B in {UP, DOWN, LEFT, RIGHT}.
Rendering that whole set at palette 0x05 shows the same figure in six
orientations:

```
  451 / 469   horizontal, arms forward, legs trailing
  452 / 470   diagonal
  453 / 471   vertical, head at the top
  472 / 491   diagonal, the other way
  473 / 492   steeper
  474 / 493   vertical, head at the BOTTOM -- fully inverted
```

A figure that appears **fully inverted** is not standing on anything, and a
control scheme with four directions including two vertical ones is not a
walking one. The small blue shape at the far end of `451`, which the earlier
batch declined to name and used to explain its ninth path, is a fin.

`LABEL_DDB4`'s six frames rotate that horizontal figure to vertical. That is a
swimmer pitching, not a body getting off a floor.

| constant | proposed name | confidence | evidence |
| --- | --- | --- | --- |
| CINEMATIC_HERO_RISE_FROM_PRONE_RIGHT_0 | CINEMATIC_HERO_SWIM_PITCH_RIGHT_0 | high | **correction**, same art, same index, same facing -- only the subject word changes |
| CINEMATIC_HERO_RISE_FROM_PRONE_RIGHT_1 | CINEMATIC_HERO_SWIM_PITCH_RIGHT_1 | high | **correction**, same art, same index, same facing -- only the subject word changes |
| CINEMATIC_HERO_RISE_FROM_PRONE_RIGHT_2 | CINEMATIC_HERO_SWIM_PITCH_RIGHT_2 | high | **correction**, same art, same index, same facing -- only the subject word changes |
| CINEMATIC_HERO_RISE_FROM_PRONE_RIGHT_3 | CINEMATIC_HERO_SWIM_PITCH_RIGHT_3 | high | **correction**, same art, same index, same facing -- only the subject word changes |
| CINEMATIC_HERO_RISE_FROM_PRONE_RIGHT_4 | CINEMATIC_HERO_SWIM_PITCH_RIGHT_4 | high | **correction**, same art, same index, same facing -- only the subject word changes |
| CINEMATIC_HERO_RISE_FROM_PRONE_RIGHT_5 | CINEMATIC_HERO_SWIM_PITCH_RIGHT_5 | high | **correction**, same art, same index, same facing -- only the subject word changes |
| CINEMATIC_HERO_RISE_FROM_PRONE_LEFT_0 | CINEMATIC_HERO_SWIM_PITCH_LEFT_0 | high | **correction**, same art, same index, same facing -- only the subject word changes |
| CINEMATIC_HERO_RISE_FROM_PRONE_LEFT_1 | CINEMATIC_HERO_SWIM_PITCH_LEFT_1 | high | **correction**, same art, same index, same facing -- only the subject word changes |
| CINEMATIC_HERO_RISE_FROM_PRONE_LEFT_2 | CINEMATIC_HERO_SWIM_PITCH_LEFT_2 | high | **correction**, same art, same index, same facing -- only the subject word changes |
| CINEMATIC_HERO_RISE_FROM_PRONE_LEFT_3 | CINEMATIC_HERO_SWIM_PITCH_LEFT_3 | high | **correction**, same art, same index, same facing -- only the subject word changes |
| CINEMATIC_HERO_RISE_FROM_PRONE_LEFT_4 | CINEMATIC_HERO_SWIM_PITCH_LEFT_4 | high | **correction**, same art, same index, same facing -- only the subject word changes |
| CINEMATIC_HERO_RISE_FROM_PRONE_LEFT_5 | CINEMATIC_HERO_SWIM_PITCH_LEFT_5 | high | **correction**, same art, same index, same facing -- only the subject word changes |

## What is *not* being renamed, and why

The ten frames of the `HERO_DIRECTION_*_TURN` set -- 452, 453, 470, 471, 472,
473, 474, 491, 492, 493 -- are **held**. Their poses are legible and their
mirror pairs are exact (452 x[-15.0, 12.5] against 470 x[-12.5, 15.0], 453
x[-8.0, 7.5] against 471 x[-7.5, 8.0]), but the routines that draw them assert
an UP/DOWN that the renders do not obviously agree with:
`HERO_DIRECTION_UP_TO_RIGHT_TURN` draws `474` first, and `474` is the frame
with the head at the **bottom**.

Either those routine names are inverted or the reading is, and choosing
between them is #0120. What would settle it: whether `[0x19]` and `[0x2A]`,
which every one of these routines writes, are the vertical and horizontal
speed components -- and if so, their sign.
