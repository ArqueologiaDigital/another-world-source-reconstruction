# CAVES: the swimmer's arm stroke, eleven frames, both facings

These twenty-two were **held** in the handoff: rendered at palette 0 they are
unreadable slivers, and the two routines' setup sites did not name a palette.
What unlocked them was the swim correction -- once
`CINEMATIC_CAVES_HERO_IDLE_RIGHT_0` was known to be a horizontal swimmer, the
right thing to do was render these **on top of it**, at palette 0x05, rather
than alone.

`LABEL_3CD9` and `LABEL_3813` are set up on channel 0x16 by the hero-direction
routines, alongside the idle pose on another channel, and each plays eleven
frames one per `break` at `[HERO_X],[HERO_Y]` before looping.

## What the eleven do

The right-facing run, per frame:

```
  F0    16.0x2.0  1p  x[  18.0,  34.0] y[  2.0,  4.0]
  F1    10.0x2.0  1p  x[  18.0,  28.0] y[  2.0,  4.0]
  F2     4.0x3.0  1p  x[  16.0,  20.0] y[  0.5,  3.5]
  F3    10.0x2.0  1p  x[   7.0,  17.0] y[  2.0,  4.0]
  F4    16.0x2.0  1p  x[   0.0,  16.0] y[  2.0,  4.0]
  F5    12.0x4.0  2p  x[   4.5,  16.5] y[  1.5,  5.5]
  F6    10.5x6.0  2p  x[   7.0,  17.5] y[  1.5,  7.5]
  F7     7.0x6.0  2p  x[  11.5,  18.5] y[  1.5,  7.5]
  F8     9.0x5.0  2p  x[  13.5,  22.5] y[  2.0,  7.0]
  F9     8.5x5.0  2p  x[  17.0,  25.5] y[  1.5,  6.5]
  F10   15.0x3.0  2p  x[  16.5,  31.5] y[  1.5,  4.5]
```

One path in every frame. The right edge goes **+34.0** at F0, back to +20.0 at
F2, out to only +16.0 at F4 -- the whole shape has moved behind the shoulder --
and then forward again to +31.5 by F10. The y band is 0.5 to 4.0 for the first
five frames and 1.5 to 7.5 for the next five: the shape drops while it is
behind.

Composited over the idle pose, that is an arm: extended ahead of the head at
F0, drawn in, swept back and down under the body, and recovered forward.

`857..867` is the mirror. `514` spans x[18.0, 34.0] and `857` spans
x[-33.0, -17.0]; `516` spans x[16.0, 20.0] and `859` x[-19.0, -15.0]; `518`
spans x[0.0, 16.0] and `861` x[-16.0, 0.0] -- the same widths, reflected, in
every frame.

| constant | proposed name | confidence | evidence |
| --- | --- | --- | --- |
| CINEMATIC_514 | CINEMATIC_CAVES_HERO_SWIM_ARM_RIGHT_F0 | high | 16.0x2.0, 1 path(s), x[18.0, 34.0] y[2.0, 4.0] |
| CINEMATIC_515 | CINEMATIC_CAVES_HERO_SWIM_ARM_RIGHT_F1 | high | 10.0x2.0, 1 path(s), x[18.0, 28.0] y[2.0, 4.0] |
| CINEMATIC_516 | CINEMATIC_CAVES_HERO_SWIM_ARM_RIGHT_F2 | high | 4.0x3.0, 1 path(s), x[16.0, 20.0] y[0.5, 3.5] |
| CINEMATIC_517 | CINEMATIC_CAVES_HERO_SWIM_ARM_RIGHT_F3 | high | 10.0x2.0, 1 path(s), x[7.0, 17.0] y[2.0, 4.0] |
| CINEMATIC_518 | CINEMATIC_CAVES_HERO_SWIM_ARM_RIGHT_F4 | high | 16.0x2.0, 1 path(s), x[0.0, 16.0] y[2.0, 4.0] |
| CINEMATIC_519 | CINEMATIC_CAVES_HERO_SWIM_ARM_RIGHT_F5 | high | 12.0x4.0, 2 path(s), x[4.5, 16.5] y[1.5, 5.5] |
| CINEMATIC_520 | CINEMATIC_CAVES_HERO_SWIM_ARM_RIGHT_F6 | high | 10.5x6.0, 2 path(s), x[7.0, 17.5] y[1.5, 7.5] |
| CINEMATIC_521 | CINEMATIC_CAVES_HERO_SWIM_ARM_RIGHT_F7 | high | 7.0x6.0, 2 path(s), x[11.5, 18.5] y[1.5, 7.5] |
| CINEMATIC_522 | CINEMATIC_CAVES_HERO_SWIM_ARM_RIGHT_F8 | high | 9.0x5.0, 2 path(s), x[13.5, 22.5] y[2.0, 7.0] |
| CINEMATIC_523 | CINEMATIC_CAVES_HERO_SWIM_ARM_RIGHT_F9 | high | 8.5x5.0, 2 path(s), x[17.0, 25.5] y[1.5, 6.5] |
| CINEMATIC_524 | CINEMATIC_CAVES_HERO_SWIM_ARM_RIGHT_F10 | high | 15.0x3.0, 2 path(s), x[16.5, 31.5] y[1.5, 4.5] |
| CINEMATIC_857 | CINEMATIC_CAVES_HERO_SWIM_ARM_LEFT_F0 | high | 16.0x2.0, 1 path(s), x[-33.0, -17.0] y[2.0, 4.0] |
| CINEMATIC_858 | CINEMATIC_CAVES_HERO_SWIM_ARM_LEFT_F1 | high | 10.0x2.5, 2 path(s), x[-27.0, -17.0] y[2.0, 4.5] |
| CINEMATIC_859 | CINEMATIC_CAVES_HERO_SWIM_ARM_LEFT_F2 | high | 4.0x3.0, 1 path(s), x[-19.0, -15.0] y[0.5, 3.5] |
| CINEMATIC_860 | CINEMATIC_CAVES_HERO_SWIM_ARM_LEFT_F3 | high | 10.0x3.5, 2 path(s), x[-17.0, -7.0] y[0.5, 4.0] |
| CINEMATIC_861 | CINEMATIC_CAVES_HERO_SWIM_ARM_LEFT_F4 | high | 16.0x2.0, 1 path(s), x[-16.0, 0.0] y[2.0, 4.0] |
| CINEMATIC_862 | CINEMATIC_CAVES_HERO_SWIM_ARM_LEFT_F5 | high | 12.0x4.0, 2 path(s), x[-17.5, -5.5] y[1.5, 5.5] |
| CINEMATIC_863 | CINEMATIC_CAVES_HERO_SWIM_ARM_LEFT_F6 | high | 11.5x6.0, 2 path(s), x[-18.5, -7.0] y[1.5, 7.5] |
| CINEMATIC_864 | CINEMATIC_CAVES_HERO_SWIM_ARM_LEFT_F7 | high | 7.0x6.0, 2 path(s), x[-19.5, -12.5] y[1.5, 7.5] |
| CINEMATIC_865 | CINEMATIC_CAVES_HERO_SWIM_ARM_LEFT_F8 | high | 9.5x5.0, 2 path(s), x[-23.5, -14.0] y[2.0, 7.0] |
| CINEMATIC_866 | CINEMATIC_CAVES_HERO_SWIM_ARM_LEFT_F9 | high | 9.5x5.0, 2 path(s), x[-26.5, -17.0] y[1.5, 6.5] |
| CINEMATIC_867 | CINEMATIC_CAVES_HERO_SWIM_ARM_LEFT_F10 | high | 15.0x3.0, 2 path(s), x[-31.5, -16.5] y[1.5, 4.5] |

## What these names do not claim

`ARM` is one path per frame whose reach goes +34.0 to +16.0 and back while it
drops from the body line, drawn on its own channel over a horizontal figure.
It does not claim which arm, and nothing in a single untextured path could.

The index is the routine's own play order, which loops; it is not a claim
about where a stroke begins.
