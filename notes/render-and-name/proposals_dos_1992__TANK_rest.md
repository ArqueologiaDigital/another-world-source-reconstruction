# TANK (msdos): the rest of the runs with earned routine names

All msdos-only art -- none of these has a `canonical_md5` twin in amiga/TANK.
Read at palette 0x0C.

## `TANK_DESTROYED_CUTSCENE_BLAST_ENTRY`: five small readouts and one big scatter

```
  120  11.0x 4.5   4 paths  y[45.5, 50.0]
  121  11.0x 3.5   5 paths  y[47.0, 50.5]
  122  10.0x 5.0   6 paths  y[45.5, 50.5]
  123  10.0x 4.0   5 paths  y[45.5, 49.5]
  124   8.0x 3.0   3 paths  y[45.5, 48.5]
  125 205.0x138.0  8 paths  y[-80.0, 58.0]
```

Five frames 8 to 11 wide and 3 to 5 tall, in the same 5-pixel y band, made of
red and blue bars; then one picture **eighteen times wider and thirty times
taller** than any of them. The scale gap is the whole argument for treating
125 separately: it is not a sixth frame of the same thing.

## `TANK_STAGE_EXIT_CAPSULE_LAUNCH_TO_BATHS`: a cloud rising over a fixed bar

Its draw order is `129 130 131 130 132 130 133 130 134 130 131 130` -- **130
between every other frame**, and 130 is the only one of the six that is not a
cloud:

```
  129  45.0x24.0  2 paths  y[54.0, 78.0]      130  31.0x5.0  2 paths  y[77.5, 82.5]
  131  38.0x29.0  2 paths  y[47.5, 76.5]
  132  36.0x33.0  2 paths  y[40.5, 73.5]
  133  38.0x29.0  2 paths  y[38.5, 67.5]
  134  38.0x31.0  2 paths  y[40.5, 71.5]
```

The five clouds' y bands **climb**: top edge 54.0, 47.5, 40.5, 38.5, 40.5.
130 sits at y[77.5, 82.5], below every one of them and never moving, and is
green where they are a dark core in a pale ring.

## `DRAW_CIN_6_27_28_AND_RET`: three unrelated pictures

```
  006  436.0x119.0  14 paths   a red band above a dark teal band, wider than the screen
  027  257.0x 42.5  25 paths   a row of arches
  028   67.0x 28.0  25 paths   a jumble of angular blue shapes
```

| constant | proposed name | confidence | evidence |
| --- | --- | --- | --- |
| CINEMATIC_120 | CINEMATIC_TANK_DESTROYED_READOUT_F0 | medium | 11.0x4.5, 4 paths of red and blue bars in the band y[45.5, 50.0] |
| CINEMATIC_121 | CINEMATIC_TANK_DESTROYED_READOUT_F1 | medium | 11.0x3.5, 5 paths |
| CINEMATIC_122 | CINEMATIC_TANK_DESTROYED_READOUT_F2 | medium | 10.0x5.0, **6 paths**, the most of the five |
| CINEMATIC_123 | CINEMATIC_TANK_DESTROYED_READOUT_F3 | medium | 10.0x4.0, 5 paths |
| CINEMATIC_124 | CINEMATIC_TANK_DESTROYED_READOUT_F4 | medium | 8.0x3.0, **3 paths**, the smallest and the fewest |
| CINEMATIC_125 | CINEMATIC_TANK_DESTROYED_SHARDS | medium | 205.0x138.0, 8 paths: long pale slivers scattered across the frame, eighteen times wider than any READOUT frame. No index -- one picture, drawn once |
| CINEMATIC_129 | CINEMATIC_TANK_LAUNCH_PLUME_F0 | medium | 45.0x24.0, 2 paths, y[54.0, 78.0]: the lowest and widest cloud of the five, a dark core in a pale ring |
| CINEMATIC_131 | CINEMATIC_TANK_LAUNCH_PLUME_F1 | medium | 38.0x29.0, 2 paths, y[47.5, 76.5] -- 6.5 higher than F0 |
| CINEMATIC_132 | CINEMATIC_TANK_LAUNCH_PLUME_F2 | medium | 36.0x33.0, 2 paths, y[40.5, 73.5], the tallest |
| CINEMATIC_133 | CINEMATIC_TANK_LAUNCH_PLUME_F3 | medium | 38.0x29.0, 2 paths, y[38.5, 67.5], the highest top edge of the five |
| CINEMATIC_134 | CINEMATIC_TANK_LAUNCH_PLUME_F4 | medium | 38.0x31.0, 2 paths, y[40.5, 71.5] |
| CINEMATIC_130 | CINEMATIC_TANK_LAUNCH_BASE_BAR | medium | 31.0x**5.0**, 2 paths, y[77.5, 82.5]: below every PLUME frame and never moving, green where they are pale-ringed. Drawn **between every other frame** of the run, six times to their one each. No index -- one picture |
| CINEMATIC_006 | CINEMATIC_TANK_TWO_BAND_BACKDROP | medium | 436.0x119.0, 14 paths: a red band above a dark teal band, wider than the 320-pixel screen and running off both edges. Drawn once |
| CINEMATIC_027 | CINEMATIC_TANK_ARCH_ROW | medium | 257.0x42.5, 25 paths: a row of arches, each a pale outline over a darker one. Drawn once, after the backdrop |
| CINEMATIC_028 | CINEMATIC_TANK_WRECKAGE | medium | 67.0x28.0, **25 paths** in a fifth of the width of `_ARCH_ROW`'s: a dense jumble of angular blue shapes at no two of the same size. Drawn once, last |

## What these names do not claim

`DESTROYED` and `LAUNCH` come from the routines, which are
`TANK_DESTROYED_CUTSCENE_BLAST_ENTRY` and
`TANK_STAGE_EXIT_CAPSULE_LAUNCH_TO_BATHS` and are the only routines that draw
any of these. `READOUT`, `SHARDS`, `PLUME`, `BASE_BAR`, `ARCH_ROW` and
`WRECKAGE` come from the pictures.

`TWO_BAND_BACKDROP` names a red band over a teal band and nothing else -- at
14 paths across 436 pixels there is no detail in it to name.

`DRAW_CIN_6_27_28_AND_RET` contributes nothing: it is a generated name and its
three pictures share no size, no path density and no position, so they are
named separately.
