# CAVES: the swimmer's legs, two runs, composited to be read

Both were unreadable alone and both came out at once when composited over
`CINEMATIC_CAVES_HERO_IDLE_RIGHT_0` at palette 0x05 -- the same move that
turned `LABEL_3CD9`'s slivers into an arm.

Each run is **two paths per frame**, flesh-coloured, below or across a
horizontal figure: a pair of limbs.

## `LABEL_3C0E`, 458 to 464: the pair crosses the body

```
  F0    11.0x17.0  2p  y[ -16.5,   0.5]
  F1    32.0x12.0  2p  y[ -11.0,   1.0]
  F2    43.0x4.0   2p  y[  -1.0,   3.0]
  F3    37.0x11.0  2p  y[   2.5,  13.5]
  F4    14.0x17.0  2p  y[   2.5,  19.5]
  F5    12.0x15.0  2p  y[   2.5,  17.5]
  F6    12.0x10.0  2p  y[   4.0,  14.0]
```

The y band starts **above** the anchor at -16.5 and finishes **below** it at
+14.0, passing through it at F2 (y[-1.0, 3.0]). The width goes 11.0 out to
43.0 at F2 -- the pair at its widest exactly as it crosses -- and back to 12.0.

## `LABEL_3BA3`, 480 to 490: the pair stays under it

```
  F0    14.0x18.0  2p  y[  17.5,  35.5]
  F1    34.0x12.0  2p  y[  19.0,  31.0]
  F2    42.0x4.0   2p  y[  19.0,  23.0]
  F3    35.0x11.0  2p  y[   7.5,  18.5]
  F4    13.0x17.0  2p  y[   1.5,  18.5]
  F5    12.0x15.0  2p  y[   3.5,  18.5]
  F6    13.0x10.0  2p  y[   8.0,  18.0]
  F7    15.0x6.0   2p  y[  12.0,  18.0]
  F8    13.0x9.5   4p  y[  12.5,  22.0]
  F9    10.0x6.0   2p  y[  20.0,  26.0]
  F10   10.0x14.0  2p  y[  20.0,  34.0]
```

Every frame is below the anchor: the y band never goes above +1.5. It rises
from +17.5..+35.5 to +1.5..+18.5 at F4 and falls back to +20.0..+34.0 by F10,
so this run is a full cycle that returns where it started. Its widest frame,
42.0 at F2, is again the frame where the pair is most open.

| constant | proposed name | confidence | evidence |
| --- | --- | --- | --- |
| CINEMATIC_458 | CINEMATIC_CAVES_HERO_SWIM_LEGS_DOWNSWEEP_F0 | high | 11.0x17.0, 2 paths, y[-16.5, 0.5] |
| CINEMATIC_459 | CINEMATIC_CAVES_HERO_SWIM_LEGS_DOWNSWEEP_F1 | high | 32.0x12.0, 2 paths, y[-11.0, 1.0] |
| CINEMATIC_460 | CINEMATIC_CAVES_HERO_SWIM_LEGS_DOWNSWEEP_F2 | high | 43.0x4.0, 2 paths, y[-1.0, 3.0] |
| CINEMATIC_461 | CINEMATIC_CAVES_HERO_SWIM_LEGS_DOWNSWEEP_F3 | high | 37.0x11.0, 2 paths, y[2.5, 13.5] |
| CINEMATIC_462 | CINEMATIC_CAVES_HERO_SWIM_LEGS_DOWNSWEEP_F4 | high | 14.0x17.0, 2 paths, y[2.5, 19.5] |
| CINEMATIC_463 | CINEMATIC_CAVES_HERO_SWIM_LEGS_DOWNSWEEP_F5 | high | 12.0x15.0, 2 paths, y[2.5, 17.5] |
| CINEMATIC_464 | CINEMATIC_CAVES_HERO_SWIM_LEGS_DOWNSWEEP_F6 | high | 12.0x10.0, 2 paths, y[4.0, 14.0] |
| CINEMATIC_480 | CINEMATIC_CAVES_HERO_SWIM_LEGS_CYCLE_F0 | high | 14.0x18.0, 2 paths, y[17.5, 35.5] |
| CINEMATIC_481 | CINEMATIC_CAVES_HERO_SWIM_LEGS_CYCLE_F1 | high | 34.0x12.0, 2 paths, y[19.0, 31.0] |
| CINEMATIC_482 | CINEMATIC_CAVES_HERO_SWIM_LEGS_CYCLE_F2 | high | 42.0x4.0, 2 paths, y[19.0, 23.0] |
| CINEMATIC_483 | CINEMATIC_CAVES_HERO_SWIM_LEGS_CYCLE_F3 | high | 35.0x11.0, 2 paths, y[7.5, 18.5] |
| CINEMATIC_484 | CINEMATIC_CAVES_HERO_SWIM_LEGS_CYCLE_F4 | high | 13.0x17.0, 2 paths, y[1.5, 18.5] |
| CINEMATIC_485 | CINEMATIC_CAVES_HERO_SWIM_LEGS_CYCLE_F5 | high | 12.0x15.0, 2 paths, y[3.5, 18.5] |
| CINEMATIC_486 | CINEMATIC_CAVES_HERO_SWIM_LEGS_CYCLE_F6 | high | 13.0x10.0, 2 paths, y[8.0, 18.0] |
| CINEMATIC_487 | CINEMATIC_CAVES_HERO_SWIM_LEGS_CYCLE_F7 | high | 15.0x6.0, 2 paths, y[12.0, 18.0] |
| CINEMATIC_488 | CINEMATIC_CAVES_HERO_SWIM_LEGS_CYCLE_F8 | high | 13.0x9.5, 4 paths, y[12.5, 22.0] |
| CINEMATIC_489 | CINEMATIC_CAVES_HERO_SWIM_LEGS_CYCLE_F9 | high | 10.0x6.0, 2 paths, y[20.0, 26.0] |
| CINEMATIC_490 | CINEMATIC_CAVES_HERO_SWIM_LEGS_CYCLE_F10 | high | 10.0x14.0, 2 paths, y[20.0, 34.0] |

## What these names do not claim

`LEGS` is two flesh-coloured paths per frame, below a horizontal figure,
opening and closing together. Nothing in two untextured paths says they are
legs rather than fins or a tail; what carries the name is the pair count, the
position under the body, and the figure they are drawn over.

`DOWNSWEEP` and `CYCLE` are the y bands: one run crosses the anchor from
-16.5 to +14.0 and does not come back within its seven frames, the other never
leaves the space below it and returns to where it began. Neither is a claim
about swimming technique.

**No direction word.** Both runs are roughly centred on the anchor -- 480
spans x[-10.5, 3.5] and 482 x[-24.5, 17.5] -- so the signed box does not
separate a left from a right version, and no mirror run was found for either.
