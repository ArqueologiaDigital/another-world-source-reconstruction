# CAVES: one spinning shape, two instances, indexed by pose not by play order

Two routines, each set up as one screen's own channel and each looping
forever, draw the same seven-pose cycle at `x=160, y=100`:

```
LABEL_07FD                    screen 0x4F, after `setPalette 0x05` and
                              `call CAVES_SCREEN_4F_BACKDROP_DRAW`
    239 240 241 242 243 244 245 244 243 242 241 240 239   `jmp LABEL_07FD`

DRAW_CIN_437_439_BLOCK        screen 0x6D, set up by `CAVES_SCREEN_6D_ENTRY`
    416 417 418 419 420 421 420 418 422 417 416
```

## The poses, and why they are the index

```
  instance 0                           instance 1
  239   1.0x15.0  x[34.5, 35.5]        416   1.0x15.0  x[123.5, 124.5]
  240   3.0x15.0  x[34.5, 37.5]        417   3.0x15.0  x[122.5, 125.5]
  241  22.0x15.0  x[34.0, 56.0]        422  22.0x15.0  x[123.0, 145.0]
  242  26.0x 3.0  x[36.0, 62.0]        418  26.0x 3.0  x[120.0, 146.0]
  243  18.0x15.0  x[43.0, 61.0]        419  18.0x15.0  x[125.0, 143.0]
  244   4.0x15.0  x[57.0, 61.0]        420   4.0x15.0  x[139.0, 143.0]
  245   1.0x15.0  x[58.5, 59.5]        421   1.0x15.0  x[140.5, 141.5]
```

Seven widths -- 1, 3, 22, 26, 18, 4, 1 -- and two heights, 15 except at the
26-wide pose where it is 3. The two instances reproduce that list **exactly**,
one path each, so the same object is drawn twice at two places.

The index is the pose, not the play order, because the two play orders differ:
instance 0 runs the poses 0..6 and back, instance 1 skips pose 2 on the way
out and takes it on the way back (`... 421 420 418 422 417 416`). Indexing by
appearance would put the same silhouette at 2 in one family and at 6 in the
other.

Rendered, the poses are a tapered point with a thicker base: edge-on, then
opening out to the right, then flat, then closing to the left, then edge-on
again -- it turns over. And its **centre drifts one way** the whole time, 35,
36, 45, 49, 52, 59, 59 for instance 0, so it is not pivoting on a fixed point.

| constant | proposed name | confidence | evidence |
| --- | --- | --- | --- |
| CINEMATIC_239 | CINEMATIC_CAVES_SPINNING_SPIKE_0_F0 | medium | 1.0x15.0, one path, x[34.5, 35.5]: edge-on, the narrowest pose. Instance 0 is `LABEL_07FD` on screen 0x4F |
| CINEMATIC_240 | CINEMATIC_CAVES_SPINNING_SPIKE_0_F1 | medium | 3.0x15.0, x[34.5, 37.5] |
| CINEMATIC_241 | CINEMATIC_CAVES_SPINNING_SPIKE_0_F2 | medium | 22.0x15.0, x[34.0, 56.0]: a thick base at the left tapering to a point at the right |
| CINEMATIC_242 | CINEMATIC_CAVES_SPINNING_SPIKE_0_F3 | medium | 26.0x**3.0**, x[36.0, 62.0]: the only pose that is not 15 tall -- flat, seen along its own length |
| CINEMATIC_243 | CINEMATIC_CAVES_SPINNING_SPIKE_0_F4 | medium | 18.0x15.0, x[43.0, 61.0]: the base is now at the **right** and the point at the left. The mirror of F2's arrangement, which is what turning over looks like |
| CINEMATIC_244 | CINEMATIC_CAVES_SPINNING_SPIKE_0_F5 | medium | 4.0x15.0, x[57.0, 61.0] |
| CINEMATIC_245 | CINEMATIC_CAVES_SPINNING_SPIKE_0_F6 | medium | 1.0x15.0, x[58.5, 59.5]: edge-on again, 24 to the right of where F0 was |
| CINEMATIC_416 | CINEMATIC_CAVES_SPINNING_SPIKE_1_F0 | medium | 1.0x15.0, x[123.5, 124.5]. Instance 1 is `DRAW_CIN_437_439_BLOCK` on screen 0x6D, and its seven widths reproduce instance 0's list exactly |
| CINEMATIC_417 | CINEMATIC_CAVES_SPINNING_SPIKE_1_F1 | medium | 3.0x15.0, x[122.5, 125.5] |
| CINEMATIC_422 | CINEMATIC_CAVES_SPINNING_SPIKE_1_F2 | medium | 22.0x15.0, x[123.0, 145.0]. Its routine draws it **only on the way back**, which is why the index is the pose and not the order |
| CINEMATIC_418 | CINEMATIC_CAVES_SPINNING_SPIKE_1_F3 | medium | 26.0x**3.0**, x[120.0, 146.0]: the flat pose |
| CINEMATIC_419 | CINEMATIC_CAVES_SPINNING_SPIKE_1_F4 | medium | 18.0x15.0, x[125.0, 143.0] |
| CINEMATIC_420 | CINEMATIC_CAVES_SPINNING_SPIKE_1_F5 | medium | 4.0x15.0, x[139.0, 143.0] |
| CINEMATIC_421 | CINEMATIC_CAVES_SPINNING_SPIKE_1_F6 | medium | 1.0x15.0, x[140.5, 141.5] |

## What these names do not claim

`SPIKE` is the silhouette: one path, a thick base tapering to a point, 22 long
at its widest and 15 across. It does not say the thing is sharp, or a weapon,
or a hazard.

`SPINNING` is the width sequence 1, 3, 22, 26, 18, 4, 1 with the thick end
swapping sides between F2 and F4. The centre drifts 35 to 59 across the cycle,
so whatever it is, it is **not** pivoting about a fixed attachment.

The instance index `_0` and `_1` is bank order. Each instance is one routine
on one screen; the screens are named in the evidence rather than in the name,
because a screen number is per stage **and** per port.
