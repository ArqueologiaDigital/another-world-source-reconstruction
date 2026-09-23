# INTRO: a second pulse, down the far tunnel, wearing a lightning name

`notes/amiga-extra-suffix/` measured that `_AMIGA_EXTRA` is a collision record
and that its 35 `KEPT` rows are pictures which never earned their base word.
These six are the first batch worked from that list, and the base word does not
survive the render.

## They are not lightning

`CINEMATIC_EXPERIMENT_LIGHTNING_F23..F28_AMIGA_EXTRA` are drawn by
`EXPERIMENT_LIGHTNING_FADE_THEN_TUNNEL_TUMBLE` at **palette 0x16**, which
`PHASE_PAGE3_TO_0_PAL_16` sets on the line that copies their backdrop into
place. Composited over that backdrop -- `CINEMATIC_378` +
`CINEMATIC_ACCELERATOR_TUNNEL_VIEW_FAR` + `CINEMATIC_ACCELERATOR_TUNNEL_DEBRIS`,
the three pictures `INTRO_TRANSITION_TO_LAKE_SETUP` draws to page 3 -- they are
the accelerator-tunnel pulse again:

```
  f   offset   whole picture                                 paths  salmon core
  F0  0x83A8   398.0x227.0  x[-16.5, 381.5] y[-15.5, 211.5]    4    125.0x84.0
  F1  0x83C8   214.0x140.0  x[ 76.5, 290.5] y[  4.0, 144.0]    8     34.0x20.0
  F2  0x84D4    92.5x 78.0  x[140.0, 232.5] y[ 28.5, 106.5]    8     21.0x13.0
  F3  0x859C    57.0x 56.5  x[175.5, 232.5] y[ 43.5, 100.0]    8     11.0x 7.0
  F4  0x8664    41.0x 35.0  x[197.5, 238.5] y[ 53.0,  88.0]    8      8.0x 5.0
  F5  0x8714    31.5x 25.0  x[210.0, 241.5] y[ 63.5,  88.5]    8      5.0x 3.0
```

Every marker of the pulse run is here and none of the lightning run's. F0 is a
**398.0x227.0 four-path blackout with a salmon-over-cream core**, the same
construction as `..._PULSE_F0`; F1..F5 are **eight-path** frames whose salmon
core shrinks 34x20, 21x13, 11x7, 8x5, 5x3. The plain
`CINEMATIC_EXPERIMENT_LIGHTNING_F23..F28`, drawn by
`EXPERIMENT_LIGHTNING_WAIT_AND_TRIGGER` at palette 0x19, look nothing like it:
12, 7, 6, 6, 4, 4 paths, boxes 138.0x81.0, 97.0x74.0, 130.0x69.5, 135.5x69.0,
125.5x70.5, 118.0x72.0 -- **roughly constant size** in a fixed band at
x[149, 290] y[23.5, 104.5], which is a flicker, not a collapse.

## The two F0s are the same drawing moved, and the two runs then diverge

`0x83A8` and `0x887C` (the pulse run's F0) measure identically on every number
-- 398.0x227.0, 4 paths, salmon 125.0x84.0, cream 93.0x57.0 -- and have
**different `canonical_md5`**: `0cdfa2e06dd5` against `41ea1c15e4a6`. Diffing
the two renders' path data, every point of `0x887C` is exactly `(+31, +3)` from
`0x83A8`. Same shape, moved; and the bounding box could never have told them
apart, which is the reason to keep reading `canonical_md5` and not extents.

What separates the runs is what happens next. Whole-picture box centres:

| | first frame after the blackout | last frame | x travel |
|---|---|---|---|
| over `VIEW_NEAR` | (165.25, 93.25) | (167.0, 84.0) | **1.75** while the box goes 251.5 -> 2.0 |
| over `VIEW_FAR` | (183.5, 74.0) | (225.75, 76.0) | **42.25** while the box goes 214.0 -> 31.5 |

The near pulse shrinks in place onto the bore's vanishing point. The far pulse
travels right across the frame as it shrinks, which is what a pulse going away
down a tunnel seen off its axis does -- and `..._TUNNEL_VIEW_FAR` is exactly
that view. It also never reaches a point: it stops at 31.5x25.0 and
`LESTER_TUMBLING_DOWN_TUNNEL_FAR_F6..F8` take over.

## Which is why the first family gets a qualifier too

With two pulses in one stage, `CINEMATIC_ACCELERATOR_TUNNEL_PULSE_F7` and a
new `..._PULSE_FAR_F3` would read as one family and a variant of it. They are
two runs over two backdrops, so both take the qualifier their own routine's
backdrop supplies: `_NEAR_` for the fifteen composited over
`..._TUNNEL_VIEW_NEAR`, `_FAR_` for the six over `..._TUNNEL_VIEW_FAR`. No
picture changes hands; the fifteen are the same fifteen named one commit ago.

## Proposals

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_ACCELERATOR_TUNNEL_PULSE_F0 | CINEMATIC_ACCELERATOR_TUNNEL_PULSE_NEAR_F0 | high | 0x887C. Qualifier only; the run is composited over `..._TUNNEL_VIEW_NEAR` and shrinks in place, centre moving 1.75 px |
| CINEMATIC_ACCELERATOR_TUNNEL_PULSE_F1 | CINEMATIC_ACCELERATOR_TUNNEL_PULSE_NEAR_F1 | high | 0x8890 |
| CINEMATIC_ACCELERATOR_TUNNEL_PULSE_F2 | CINEMATIC_ACCELERATOR_TUNNEL_PULSE_NEAR_F2 | high | 0x8958 |
| CINEMATIC_ACCELERATOR_TUNNEL_PULSE_F3 | CINEMATIC_ACCELERATOR_TUNNEL_PULSE_NEAR_F3 | high | 0x8A24 |
| CINEMATIC_ACCELERATOR_TUNNEL_PULSE_F4 | CINEMATIC_ACCELERATOR_TUNNEL_PULSE_NEAR_F4 | high | 0x8AE0 |
| CINEMATIC_ACCELERATOR_TUNNEL_PULSE_F5 | CINEMATIC_ACCELERATOR_TUNNEL_PULSE_NEAR_F5 | high | 0x8B90 |
| CINEMATIC_ACCELERATOR_TUNNEL_PULSE_F6 | CINEMATIC_ACCELERATOR_TUNNEL_PULSE_NEAR_F6 | high | 0x8C04 |
| CINEMATIC_ACCELERATOR_TUNNEL_PULSE_F7 | CINEMATIC_ACCELERATOR_TUNNEL_PULSE_NEAR_F7 | high | 0x8C68 |
| CINEMATIC_ACCELERATOR_TUNNEL_PULSE_F8 | CINEMATIC_ACCELERATOR_TUNNEL_PULSE_NEAR_F8 | high | 0x8CD8 |
| CINEMATIC_ACCELERATOR_TUNNEL_PULSE_F9 | CINEMATIC_ACCELERATOR_TUNNEL_PULSE_NEAR_F9 | high | 0x8D4A |
| CINEMATIC_ACCELERATOR_TUNNEL_PULSE_F10 | CINEMATIC_ACCELERATOR_TUNNEL_PULSE_NEAR_F10 | high | 0x8DA0 |
| CINEMATIC_ACCELERATOR_TUNNEL_PULSE_F11 | CINEMATIC_ACCELERATOR_TUNNEL_PULSE_NEAR_F11 | high | 0x8DF0 |
| CINEMATIC_ACCELERATOR_TUNNEL_PULSE_F12 | CINEMATIC_ACCELERATOR_TUNNEL_PULSE_NEAR_F12 | high | 0x8E10 |
| CINEMATIC_ACCELERATOR_TUNNEL_PULSE_F13 | CINEMATIC_ACCELERATOR_TUNNEL_PULSE_NEAR_F13 | high | 0x8E30 |
| CINEMATIC_ACCELERATOR_TUNNEL_PULSE_F14 | CINEMATIC_ACCELERATOR_TUNNEL_PULSE_NEAR_F14 | high | 0x8E3E |
| CINEMATIC_EXPERIMENT_LIGHTNING_F23_AMIGA_EXTRA | CINEMATIC_ACCELERATOR_TUNNEL_PULSE_FAR_F0 | high | 0x83A8, 398.0x227.0 in **4 paths**, salmon core 125.0x84.0 over cream 93.0x57.0 -- the pulse blackout, not a flicker. Same drawing as `..._PULSE_NEAR_F0` moved by (+31, +3), different `canonical_md5` |
| CINEMATIC_EXPERIMENT_LIGHTNING_F24_AMIGA_EXTRA | CINEMATIC_ACCELERATOR_TUNNEL_PULSE_FAR_F1 | high | 0x83C8, 8 paths, 214.0x140.0, core 34.0x20.0: shards around the core, over `..._TUNNEL_VIEW_FAR` |
| CINEMATIC_EXPERIMENT_LIGHTNING_F25_AMIGA_EXTRA | CINEMATIC_ACCELERATOR_TUNNEL_PULSE_FAR_F2 | high | 0x84D4, 8 paths, 92.5x78.0, core 21.0x13.0 |
| CINEMATIC_EXPERIMENT_LIGHTNING_F26_AMIGA_EXTRA | CINEMATIC_ACCELERATOR_TUNNEL_PULSE_FAR_F3 | high | 0x859C, 8 paths, 57.0x56.5, core 11.0x7.0; the box centre has moved 20 px right of F1's |
| CINEMATIC_EXPERIMENT_LIGHTNING_F27_AMIGA_EXTRA | CINEMATIC_ACCELERATOR_TUNNEL_PULSE_FAR_F4 | high | 0x8664, 8 paths, 41.0x35.0, core 8.0x5.0 |
| CINEMATIC_EXPERIMENT_LIGHTNING_F28_AMIGA_EXTRA | CINEMATIC_ACCELERATOR_TUNNEL_PULSE_FAR_F5 | high | 0x8714, 8 paths, 31.5x25.0, core 5.0x3.0, centre 42.25 px right of F1's. The run stops here; it does not reach a point |

## What these names do not claim

They do not claim the six were never lightning in some earlier reading. They
claim what the render shows: a four-path blackout with a two-tone core,
followed by five eight-path frames whose core shrinks monotonically, over the
far tunnel view -- the construction of the pulse run and not of the six plain
`EXPERIMENT_LIGHTNING_F23..F28`, which are 4-to-12-path flickers of roughly
constant size in a fixed band and keep their name.

`NEAR` and `FAR` come from `..._TUNNEL_VIEW_NEAR` and `..._TUNNEL_VIEW_FAR`,
which are the backdrops the two routines actually composite over, not from a
judgement about distance.
