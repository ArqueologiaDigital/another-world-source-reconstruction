# PRISON (amiga): the cage coming apart, and what is left of it

Two sentences, at frames 3072 and 3073:

- `ann:f23e8265f6a3` on `CINEMATIC_549`: "the bottom part of the broken cage
  resting on the floor after having fallen"
- `ann:59b2673a0940` on `CINEMATIC_542`: "a large chunk of the cage flying away
  and going out of frame while passing closer to the camera, coming roughtly in
  the direction of the camera"

**The debris frames grow, which is what coming at the camera means.**
`DRAW_CIN_540_543_WITH_SFX_57` (PRISON.asm:13515-13527) alternates three
single-polygon constants with the already-named
`CINEMATIC_PRISON_FLEXING_BAND_F0..F5`, all at the one anchor `[0x1a],[0x1b]`:

    CINEMATIC_540    16.0 x  32.0   1 leaf      area    512
    CINEMATIC_542   138.0 x  81.0   1 leaf      area 11,178
    CINEMATIC_544    66.0 x 140.0   1 leaf      area  9,240

in that draw order. A single flat polygon that goes from 512 to 11,178 square
pixels in two frames is something arriving at the lens, and `play id=0x0057,
freq=0x1C, vol=0x40` fires on the frame the person annotated. The existing
`FLEXING_BAND` family is the other half of the same event and is left alone.

`CINEMATIC_549` is different in kind: `HANG_DRAW_CIN_549` (PRISON.asm:13537)
draws it at the literal (181,146) inside `jmp` to itself forever. A hang loop is
the scene's settled state, and 69.0x62.0 in 9 leaves is a wreck sitting still,
not a frame of anything.

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_540 | CINEMATIC_PRISON_CAGE_DEBRIS_NEAR_F0 | high | 0x2820, first of the three drawn by DRAW_CIN_540_543_WITH_SFX_57 at [0x1a],[0x1b]; 16.0x32.0, one polygon, the smallest of the run; no annotation of its own -- it is the frame before the one annotated, in the same routine and the same anchor |
| CINEMATIC_542 | CINEMATIC_PRISON_CAGE_DEBRIS_NEAR_F1 | high | 0x2870, second of the three, drawn immediately after `play id=0x0057, freq=0x1C, vol=0x40`; 138.0x81.0, one polygon, 22x the area of F0 one frame later; annot:59b2673a0940 frame 3073, "a large chunk of the cage flying away ... coming roughtly in the direction of the camera" |
| CINEMATIC_544 | CINEMATIC_PRISON_CAGE_DEBRIS_NEAR_F2 | high | 0x2850, third of the three; 66.0x140.0, one polygon, taller than it is wide where F1 was wider than tall -- the chunk turning as it passes; no annotation of its own, same routine and anchor as F0 and F1 |
| CINEMATIC_549 | CINEMATIC_PRISON_CAGE_WRECK_AT_REST | high | 0x5770, drawn at the literal (181,146) by HANG_DRAW_CIN_549, an infinite `jmp` to itself -- the stage's settled state and not a frame of an animation; 69.0x62.0 in 9 leaves; annot:f23e8265f6a3 frame 3072, "the bottom part of the broken cage resting on the floor after having fallen" |
