# INTRO: five pictures their own loops already describe

## Two marks, and why the hash is not used for them

`CINEMATIC_124` (0x06A8) and `CINEMATIC_131` (0xB17E) are both **2.0 x 1.0 in a
single path**, so `canonical_md5` merges them with eight other marks in the
stage (`notes/cross-port-art/colour_blind_hashes.py`). Both render `#ebcb00`.
They are separated, and carried to msdos, by their draw sites alone:

```
  HOLO_CONSOLE_DOT_RISE_SLOW_LOOP:            LAB_AUTH_DOT_PAIR_STEP_HOLD_LOOP:
      video 124, x=204, y=[0x08]                  video 131, x=280, y=[0x08]
      sub [0x08], 0x0001                          video 131, x=283, y=[0x0b]
```

124 rises -- its y is decremented every pass -- at the same `x=204` where
`CINEMATIC_HOLO_CONSOLE_DOT_RISE_FAST` is drawn on another variable. The
existing name supplies everything but the speed, and the loop supplies that.

131 is drawn **twice a pass**, at x=280 and x=283, on two variables the outer
loop moves by +3 and -3 -- one picture used for both members of the pair the
routine calls a `DOT_PAIR`.

## Three pictures on two screens

```
  447  0xDDA8   45.0x10.5   3 paths   x[166.5, 211.5] y[113.0, 123.5]
  126  0xF56E   30.0x28.0  12 paths   x[211.5, 241.5] y[ 28.5,  56.5]
  127  0xF5CA   21.0x28.0   2 paths   x[217.5, 238.5] y[ 32.0,  60.0]
```

447 is a shallow black wedge 45 wide and 10.5 tall with two small red marks
below its right end (`#000000`, `#fb0000`, `#db7454`).
`HOLO_CONSOLE_BAR_RISE_STAMP_LOOP` draws it at `x=160` on a y it decrements
every pass, over `LESTER_SEATED_AT_HOLO_CONSOLE_F2`, and then installs
`HOLO_CONSOLE_PANEL_LIGHTS_CYCLE_LOOP`.

126 and 127 are both drawn at `x=160, y=100` but land at x[211.5, 241.5] and
x[217.5, 238.5] -- the auth CRT's own column, where
`CINEMATIC_LAB_AUTH_CRT_OVERLAY_STAMP` goes at x=228. 126 is 12 paths: four
green horizontal bars with small markers at their left ends, stacked -- rows of
readout. 127 is **2 paths**: one filled rounded shape, taller than wide, with a
brighter rim. `..._PHASE_1` draws the first, `..._PHASE_2` the second.

## Proposals

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_124 | CINEMATIC_HOLO_CONSOLE_DOT_RISE_SLOW | high | 0x06A8, 2.0x1.0 in 1 path, `#ebcb00`. Drawn by `HOLO_CONSOLE_DOT_RISE_SLOW_LOOP` at the same `x=204` as `..._DOT_RISE_FAST`, on a y the loop decrements by 1 |
| CINEMATIC_131 | CINEMATIC_LAB_AUTH_DOT | high | 0xB17E, 2.0x1.0 in 1 path, `#ebcb00`. The single picture `LAB_AUTH_DOT_PAIR_STEP_HOLD_LOOP` draws twice a pass, at x=280 and x=283, on variables moved +3 and -3 |
| CINEMATIC_447 | CINEMATIC_HOLO_CONSOLE_RISING_BAR | high | 0xDDA8, 45.0x10.5 in 3 paths: a shallow black wedge with two small red marks under its right end. Drawn by `HOLO_CONSOLE_BAR_RISE_STAMP_LOOP` on a y it decrements each pass |
| CINEMATIC_126 | CINEMATIC_LAB_AUTH_CRT_READOUT_ROWS | medium | 0xF56E, **12 paths** in 30.0x28.0 landing at x[211.5, 241.5], the auth CRT's column: four green horizontal bars with a small marker at each left end |
| CINEMATIC_127 | CINEMATIC_LAB_AUTH_CRT_SOLID_ICON | medium | 0xF5CA, **2 paths** in 21.0x28.0 on the same CRT: one filled rounded shape, taller than wide, inside a brighter rim. Drawn by phase 2 where 126 is drawn by phase 1 |

## What these names do not claim

`READOUT_ROWS` says four bars in a row and nothing about what they spell.
`SOLID_ICON` says a filled shape with a rim and nothing about what it depicts;
this is a biometric-authorisation scene and it would be easy to read a
thumbprint or a face into 21x28 pixels in two paths, which is exactly why the
name does not.

`RISING_BAR`, `DOT_RISE_SLOW`, `LAB_AUTH_DOT` and `DOT_PAIR` are all their
loops' own words.

Note for whoever reconciles branch vocabularies: amiga calls the fast dot
`CINEMATIC_HOLO_CONSOLE_DOT_RISE_FAST` and msdos calls the same draw site
`CINEMATIC_HOLO_SCENE_PULSED_RISE`. Both are earned names for one picture and
#0120 says not to pick between them here, so this batch does not.
