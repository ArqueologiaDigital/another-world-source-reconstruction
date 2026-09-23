# CAVES: the swimmer's tilt ladder, indexed by where the hair is

The eight `HERO_DIRECTION_<A>_TO_<B>_TURN` routines draw ten frames this batch
names. They were held in the handoff because those routines assert an UP/DOWN
that the renders appeared to contradict. **The frames can be named without
settling that**, because the pose is a measurement and the direction word is
the routine's claim.

## The measurement

`#742000` is the hair: in `CINEMATIC_HERO_SWIM_PITCH_RIGHT_0` -- the
horizontal frame, whose orientation is not in doubt -- it is the topmost
colour in the picture. `#004497` is the fin at the other end. Both, per frame,
as mid-y against the anchor's y = 100:

```
              hair    fin            hair    fin
  453 / 471    94.0  130.0    472 / 491  106.0   91.5
  452 / 470    95.0  122.0    473 / 492  120.0   94.5
  451 / 469    97.0  114.0    474 / 493  124.0   85.0
              ^ the horizontal frame, already named
```

The hair is monotone across all six steps -- 94, 95, 97, 106, 120, 124 -- and
the fin moves the other way on the near side, 130, 122, 114. The body is one
shape rotating about a point, and the hair's y is the angle.

The hair's **x** confirms the facing and the pivot: 451 at 175 against the
anchor's 160, 452 at 163, 453 at 160; the left-hand mirrors run 146, 156, 160.
Both converge on the anchor as the body comes vertical, which is what a
rotation about a fixed point does.

`452`/`470` and `453`/`471` are exact mirrors -- x[-15.0, 12.5] against
x[-12.5, 15.0], and x[-8.0, 7.5] against x[-7.5, 8.0] -- at the same sizes and
path counts.

| constant | proposed name | confidence | evidence |
| --- | --- | --- | --- |
| CINEMATIC_452 | CINEMATIC_CAVES_HERO_SWIM_HEAD_UP_RIGHT_0 | high | 27.5x34.5, 7 paths, hair at y 95.0 and fin at 122.0 -- one step from the horizontal frame's 97.0 and 114.0. Exact mirror of the LEFT `_0` |
| CINEMATIC_453 | CINEMATIC_CAVES_HERO_SWIM_HEAD_UP_RIGHT_1 | high | 15.5x46.0, 7 paths, hair at 94.0 and fin at 130.0: the extreme of this side, and the narrowest and tallest frame of the ten. Hair x is 160.0, on the anchor |
| CINEMATIC_470 | CINEMATIC_CAVES_HERO_SWIM_HEAD_UP_LEFT_0 | high | 27.5x34.5, 7 paths, x[-12.5, 15.0] -- the exact mirror of `_RIGHT_0`'s x[-15.0, 12.5] -- with the same hair and fin heights |
| CINEMATIC_471 | CINEMATIC_CAVES_HERO_SWIM_HEAD_UP_LEFT_1 | high | 15.5x46.0, 7 paths, x[-7.5, 8.0]: the exact mirror of `_RIGHT_1` |
| CINEMATIC_472 | CINEMATIC_CAVES_HERO_SWIM_HEAD_DOWN_RIGHT_0 | high | 47.0x27.0, 10 paths, hair at 106.0 -- **below** the horizontal frame's 97.0 -- and fin at 91.5, above it. The widest and shortest of the ten |
| CINEMATIC_473 | CINEMATIC_CAVES_HERO_SWIM_HEAD_DOWN_RIGHT_1 | high | 26.0x32.0, 8 paths, hair at 120.0 |
| CINEMATIC_474 | CINEMATIC_CAVES_HERO_SWIM_HEAD_DOWN_RIGHT_2 | high | 11.0x45.0, 7 paths, hair at 124.0 and fin at 85.0: fully inverted, and the narrowest frame of the ten alongside its mirror |
| CINEMATIC_491 | CINEMATIC_CAVES_HERO_SWIM_HEAD_DOWN_LEFT_0 | high | 43.5x25.5, 8 paths, hair at 106.0, hair x 139.0 against `_RIGHT_0`'s 178.0 -- 21 either side of the anchor's 160 |
| CINEMATIC_492 | CINEMATIC_CAVES_HERO_SWIM_HEAD_DOWN_LEFT_1 | high | 26.0x32.0, 6 paths, hair at 120.0: the same extent as `_RIGHT_1` and two paths fewer |
| CINEMATIC_493 | CINEMATIC_CAVES_HERO_SWIM_HEAD_DOWN_LEFT_2 | high | 11.0x43.0, 5 paths, hair at 124.0 |

## What these names do not claim

`HEAD_UP` and `HEAD_DOWN` are the hair's y against the horizontal frame's
97.0. **They are not a direction of travel**, and this batch deliberately does
not say which of them is the game's "up".

That question is still open and is why these were held. The eight routines
name it the other way round: `HERO_DIRECTION_UP_TO_RIGHT_TURN` draws `474`
first, and `474` is the frame with the hair at 124.0 -- the lowest of the ten.
Either those earned names are inverted or the swimmer travels feet-first one
way, and choosing between them is #0120.

`[0x19]` and `[0x2A]`, which all eight routines write, turned out **not** to
settle it: `[0x19]` offsets a copy of `[HERO_Y]` and `[0x2A]` offsets
`[HERO_X]`, so they are the vertical and horizontal extents -- but both
vertical poses are reached with `[0x2A] = 0x05` and left with `[0x19] = 0x00`,
symmetrically. The handoff entry is updated to say so, so the next reader does
not spend the same hour.

The index counts **away from the horizontal frame**, so neither family has a
gap and neither claims a frame rate or a play order; the routines play these
in both directions.
