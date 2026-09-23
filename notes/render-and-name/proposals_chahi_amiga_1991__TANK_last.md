# TANK: the last three in amiga

All three are small, all three have a routine that says what they are for, and
all three are at the **same offsets in msdos** with identical `canonical_md5`.

```
  100  0x548A   6.0x12.0   2 paths   e6ed01ed7a79   a thin pale diagonal streak
  152  0x27CA   8.0x 8.0   2 paths   0b33b655fdb2   a small angular mark
  155  0x27F6   7.0x 5.5   3 paths   0a9341a571c1   a smaller, darker mark
```

**100** is drawn by one tight loop and nothing else, three times per pass at
`(81,131)`, `(96,121)` and `(86,127)` -- three positions within 15 pixels of
each other -- then `jmp` back. msdos calls the same routine
`TANK_DRAW_CIN_087_THREE_VARYING_POSITIONS`, which is where "three varying
positions" is confirmed rather than assumed.

**152** and **155** belong to `TANK_AMBIENT_RANDOM_DELAY_PLAY_SOUND_8C`, which
hashes the random seed into `[0x3D]`, masks it to `0x1F` and adds `0x5A`, plays
sound `0x8C`, and draws 152 at `[0x3c], [0x3d]`. It then hashes again, masks to
`0x03`, and branches to `TANK_AMBIENT_IMPACT_SCAR_CASE_01`, whose arm draws 155
at the same `[0x3c], [0x3d]`. So: a randomly placed mark with an impact sound,
and then a second mark at the same place, one time in four.

`AMBIENT` and `IMPACT_SCAR` are the two routines' own words.

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_100 | CINEMATIC_TANK_FALLING_STREAK | medium | 0x548A, **2 paths**, 6.0x12.0 -- a thin pale diagonal, taller than it is wide. Drawn three times a pass at (81,131), (96,121), (86,127) by a loop that does nothing else |
| CINEMATIC_152 | CINEMATIC_TANK_AMBIENT_IMPACT_FLASH | high | 0x27CA, 2 paths, 8.0x8.0, drawn at a y the routine randomises into 0x5A..0x79 together with `play id=0x008C` |
| CINEMATIC_155 | CINEMATIC_TANK_AMBIENT_IMPACT_SCAR | high | 0x27F6, 3 paths, 7.0x5.5, drawn at the **same** `[0x3c], [0x3d]` as the flash, one pass in four, by `TANK_AMBIENT_IMPACT_SCAR_CASE_01` |

## What these names do not claim

`FALLING_STREAK` is graded `medium`: what is measured is a two-path diagonal
twice as tall as it is wide, redrawn at three nearby positions forever. That it
falls rather than rises is read from the shape, not from the loop, which does
not move it in one direction.
