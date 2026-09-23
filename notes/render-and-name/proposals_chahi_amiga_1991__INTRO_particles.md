# INTRO: four marks that differ only in brightness

## They are one sheet

Four constants on a **12-byte stride** -- 0x0630, 0x063C, 0x0648, 0x0654 --
each **2.0 x 1.0 in a single path**. Two pixels. There is nothing in the shape
to tell them apart and `canonical_md5` says so: all four hash to
`afafd0dda5fb`, along with six other one-path marks in the stage
(`notes/cross-port-art/colour_blind_hashes.py`).

What separates them is the renderer's fill, and it is a clean ramp in bank
order:

```
  0x0630  #102044   darkest
  0x063C  #103054
  0x0648  #204464
  0x0654  #305474   lightest
```

The same four fills come out at palette 0x01 and at palette 0x19, so the ramp
is in the art, not in one palette's accident.

## What draws them

```
CH_11_DRAW_PARTICLES_LOOP:              CH_12_DRAW_PARTICLES_LOOP:
    video 351, x=[0x0a], y=50               video 348, x=[0x0c], y=140
    video 349, x=[0x0a], y=20               video 349, x=[0x0c], y=100
    video 350, x=[0x0a], y=110              video 349, x=[0x0c], y=80
    video 349, x=[0x0a], y=180              video 350, x=[0x0c], y=10
    add [0x0A], 0x000A                      add [0x0C], 0x0009
    break                                   break
```

One x per channel, advanced by 10 and by 9 each pass, with the marks pinned to
fixed rows. So they drift horizontally across the frame at a rate the channel
sets, and the brightness ramp is what distinguishes near from far. `PARTICLE`
is the two loops' own word, and `SETUP_INTRO_PARTICLE_CHANNELS` installs them.

The index is the bank stride, which is also the brightness order, darkest
first. This follows the convention already in the stage for sets that are not
animation frames -- `CINEMATIC_CITY_GANTRY_BRACE_0..3`,
`CINEMATIC_CITY_WINDOW_LIGHTS_0..2`,
`CINEMATIC_PARTICLE_LAB_HOLO_CONSOLE_LED_0..4` -- a bare numeric suffix rather
than `_F<n>`.

## Cross-port: by offset, not by hash

msdos holds the same four at the **same four offsets** and its two loops draw
them at the **same eight y values** in the same order. The hash cannot carry
these names -- it merges all ten one-path marks in the stage -- so the match is
the offset and the draw site, which are unambiguous:

```
  0x0630  amiga CINEMATIC_351   msdos CINEMATIC_352
  0x063C  amiga CINEMATIC_349   msdos CINEMATIC_350
  0x0648  amiga CINEMATIC_348   msdos CINEMATIC_349
  0x0654  amiga CINEMATIC_350   msdos CINEMATIC_351
```

## Proposals

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_351 | CINEMATIC_DRIFTING_PARTICLE_0 | high | 0x0630, 2.0x1.0 in 1 path, `#102044` -- the darkest of the four and first on the 12-byte stride |
| CINEMATIC_349 | CINEMATIC_DRIFTING_PARTICLE_1 | high | 0x063C, `#103054`. Drawn three times a pass, more than any other |
| CINEMATIC_348 | CINEMATIC_DRIFTING_PARTICLE_2 | high | 0x0648, `#204464` |
| CINEMATIC_350 | CINEMATIC_DRIFTING_PARTICLE_3 | high | 0x0654, `#305474` -- the lightest and last on the stride |

## What these names do not claim

Nothing about what the marks represent: rain, sparks, dust, stars. They are
two-pixel marks in four brightnesses drifting sideways at a fixed rate, and
`DRIFTING` is `add [0x0A], 0x000A` and `PARTICLE` is the routine's word.

The index is brightness order because that is the only property that separates
them, and it coincides with bank order. It is **not** a frame index: all four
are on screen at once, on different rows.
