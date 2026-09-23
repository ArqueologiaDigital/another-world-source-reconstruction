# ENDING: eleven pictures, all with an earned routine beside them

ENDING is one of the best-labelled stages already -- `PTERANODON_WING_LEFT_F0..F10`,
`..._LEG_DANGLE_F0..F6`, `ENDING_ALIEN_WALK_F0..F5`, `ENDING_LESTER_PRONE_F0..F5`
-- so every one of these eleven has named siblings to be placed against.
Read with `compose_run.py --routine` / `--under-routine`, at the palettes
`palette_in_force.py` reports (0x0B for the terrace shot, 0x0A for the rest).

## The terrace shot

`ENDING_DRAW_STARS_BG_PLAY_SOUND_08` calls both cloud-sky backdrops, installs
`PTERANODON_HEAD_LOWERED_HOLD_LOOP`, and then draws exactly three pictures on
page 0:

```
  008  0x1238  306.0x 95.0  16 paths  x[  3.5, 309.5] y[123.5, 218.5]
  009  0x1318   72.0x  3.0   8 paths  x[ 52.5, 124.5] y[148.5, 151.5]
  010  0x4498   70.5x117.5  17 paths  x[177.0, 247.5] y[ 26.0, 143.5]
```

Over the clouds: 008 is a dark mass spanning the full width along the bottom,
with a small finial at its left end -- the surface everything else in the shot
stands on. 009 is a 3-pixel-tall row of small red and blue marks lying on it.
010 is a dark body with spread wings standing on it at the right, which is what
the head-loop this routine installs belongs to.

## The arrival

`LESTER_PRONE_ARRIVAL_DELAY` draws `011`, then `012`, then
`CINEMATIC_ENDING_LESTER_PRONE_F0`, all at the same `[0x01], [0x02]`. The path
counts run **18, 11, 9** and the finished prone frames are 9 apiece: a figure
in pieces, then fewer pieces, then whole. `ARRIVAL` is the routine's own word.

`019` is drawn once at the same anchor after the whole prone cycle has played
F0..F5 and come back, immediately before `ALIEN_ARRIVAL_POSITION_INIT`. It is
9 paths and the same size band as the rest of that family, and by order of
appearance it is the last of them.

## The alien's head

`ALIEN_STAND_HOLD_THEN_WALK_START` draws `024` and then
`CINEMATIC_ENDING_ALIEN_STANDING`, both at `[BUDDY_X], [BUDDY_Y]`. 024 is
**12.0x10.0 in 3 paths** and lands at x[155.0, 167.0] y[41.0, 51.0]; the
standing body is 30.5x57.0 at x[143.0, 173.5] y[44.0, 101.0]. It sits on top of
the body. The stage animates a head separately in three other routines
(`ALIEN_WALK_HEAD_LOOP`, `PTERANODON_HEAD_RAISE_ANIM`, `..._HEAD_RAISED_HOLD_LOOP`).

## The clouds

`DRAW_STARS_CIN_38_39_40_5_6` interleaves `038`, `039`, `040`, `041` with
`CINEMATIC_ENDING_CLOUD_SKY_PAGE3_F1` and `_F2` at a dozen positions. The first
three match their named siblings in every measure -- 72.0x66.5 / 7 paths,
66.0x68.5 / 6, 68.0x72.0 / 7, against F1's 66.0x68.5 / 7 and F2's 69.5x75.0 / 7
-- and render as the same chunky cloud lumps. `041` does not: **159.0x119.5 in
38 paths**, twice as wide and five times as many paths, and it puts down
several lumps at once.

## Proposals

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_008 | CINEMATIC_ENDING_TERRACE | medium | 0x1238, 16 paths, 306.0x95.0 spanning x[3.5, 309.5] along the bottom, drawn first of the three over the cloud sky: the surface the rest of the shot stands on, with a small finial at its left end |
| CINEMATIC_009 | CINEMATIC_ENDING_TERRACE_LIGHTS | medium | 0x1318, 8 paths in a band **3.0 pixels tall** at y[148.5, 151.5], lying on the terrace: a row of small red and blue marks |
| CINEMATIC_010 | CINEMATIC_ENDING_PTERANODON_PERCHED | medium | 0x4498, 17 paths, 70.5x117.5 standing on the terrace at x[177.0, 247.5]: a dark body with spread wings. The routine that draws it installs `PTERANODON_HEAD_LOWERED_HOLD_LOOP` |
| CINEMATIC_011 | CINEMATIC_ENDING_LESTER_ARRIVAL_F0 | high | 0x179A, **18 paths** in 52.5x13.0, the first thing `LESTER_PRONE_ARRIVAL_DELAY` draws: the prone figure in pieces |
| CINEMATIC_012 | CINEMATIC_ENDING_LESTER_ARRIVAL_F1 | high | 0x1730, **11 paths**, drawn next at the same anchor: fewer pieces. `..._LESTER_PRONE_F0` follows at 9 |
| CINEMATIC_019 | CINEMATIC_ENDING_LESTER_PRONE_F6 | high | 0x1800, 9 paths, 55.5x8.5 -- the same construction and band as `..._PRONE_F0..F5` -- drawn once at the same anchor after the whole cycle has run, so last by order of appearance |
| CINEMATIC_024 | CINEMATIC_ENDING_ALIEN_HEAD | high | 0x16C4, **3 paths**, 12.0x10.0 at x[155.0, 167.0] y[41.0, 51.0], drawn at `[BUDDY_X], [BUDDY_Y]` immediately before `..._ALIEN_STANDING`, whose body occupies x[143.0, 173.5] y[44.0, 101.0]. It sits on top of it |
| CINEMATIC_038 | CINEMATIC_ENDING_CLOUD_SKY_PAGE3_F4 | high | 0x2758, 7 paths, 72.0x66.5 -- the same construction as `..._PAGE3_F1` (7 paths, 66.0x68.5) and `_F2` (7, 69.5x75.0), interleaved with them by the same routine. First of the three by order of appearance |
| CINEMATIC_039 | CINEMATIC_ENDING_CLOUD_SKY_PAGE3_F5 | high | 0x290A, 6 paths, 66.0x68.5 |
| CINEMATIC_040 | CINEMATIC_ENDING_CLOUD_SKY_PAGE3_F6 | high | 0x267E, 7 paths, 68.0x72.0 |
| CINEMATIC_041 | CINEMATIC_ENDING_CLOUD_BANK | medium | 0x29C8, **38 paths**, 159.0x119.5 -- twice the width and five times the paths of any single cloud in the family, and it lays down several lumps at once. Kept out of the `_PAGE3_F*` run for that reason |

## What these names do not claim

`TERRACE` says a surface spanning the frame that everything in the shot stands
on; whether it is a balcony, a parapet or a roof is not claimed, and
`TERRACE_LIGHTS` says a row of small coloured marks lying on it and not what
they are for.

`PTERANODON_PERCHED` uses the stage's own word for the creature -- twelve
routines and forty constants already carry it -- and claims only that this is
one body with spread wings standing on the terrace.

`ARRIVAL` is `LESTER_PRONE_ARRIVAL_DELAY`'s word. The two frames are graded
`high` on the path counts, 18 then 11 then the family's 9, not on a reading of
what the pieces are.
