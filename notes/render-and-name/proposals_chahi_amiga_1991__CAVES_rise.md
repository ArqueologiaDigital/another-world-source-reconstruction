# CAVES: getting up off the ground, both facings, and no stage word

Two routines, `LABEL_DDB4` and `LABEL_DE10`, each draw six pictures one per
`break` at `[HERO_X],[HERO_Y]`. Read at palette 0x05 the figure has orange
hair, a dark top and pale limbs -- the same figure `CINEMATIC_HERO_LEAP_*`,
`CINEMATIC_HERO_LAND_*` and `CINEMATIC_HERO_DEATH_*` already name in this
tree, which is what carries `HERO_` here rather than the slot.

## An exact mirror pair

```
  451  50.0x26.0  9 paths  x[-26.5,  23.5]   469  50.0x26.0  9 paths  x[-23.5,  26.5]
  494  33.5x34.5  8 paths  x[-12.5,  21.0]   499  33.5x35.0  8 paths  x[-21.0,  12.5]
  495  24.0x41.0  8 paths  x[ -2.5,  21.5]   500  25.0x41.5  8 paths  x[-23.5,   1.5]
  496  24.5x35.5  8 paths  x[ -0.5,  24.0]   501  23.5x36.0  8 paths  x[-25.0,  -1.5]
  497  23.5x32.0  8 paths  x[  2.5,  26.0]   502  21.5x34.5  8 paths  x[-25.0,  -3.5]
  498  19.5x33.0  8 paths  x[  7.5,  27.0]   503  18.5x33.5  8 paths  x[-27.0,  -8.5]
```

The first two rows are exact: 451 and 469 are both 50.0x26.0 with nine paths
and their x ranges sum to zero both ways; 494 and 499 likewise at 33.5 and
eight paths. The rest are within 2.0 of a mirror, one path count apart from
nobody.

## What the six frames do

Width falls 50.0 to 19.5 and height rises 26.0 to 41.0 and then settles near
33. The first frame is 50 wide and 26 tall, the widest and shortest of the
six; the last is 19.5 wide and 33 tall. Rendered, F0 is a figure **lying
flat** with a small object at the far end of its arm, and F1 through F5 are
that figure pushing up onto its legs -- the extents are the silhouette going
from horizontal to vertical.

## The scope is settled before the name is written

`frame_runs.py --stages` reports **CAPSULE 6/6** for both runs: every one of
the twelve has a byte-identical twin there, still numbered. Three stages is
not required to *withhold* a stage word -- two are enough to show the art is
not CAVES'. So these take none, the way `CINEMATIC_TUMBLING_CHUNK_*` did.

| constant | proposed name | confidence | evidence |
| --- | --- | --- | --- |
| CINEMATIC_451 | CINEMATIC_HERO_RISE_FROM_PRONE_RIGHT_0 | high | 50.0x26.0, 9 paths: lying flat, the widest and shortest of the six, with a small separate shape at the end of the outstretched arm. Exact mirror of the LEFT `_0` |
| CINEMATIC_494 | CINEMATIC_HERO_RISE_FROM_PRONE_RIGHT_1 | high | 33.5x34.5, 8 paths, x[-12.5, 21.0]: up on the arms, and the first frame taller than it is wide |
| CINEMATIC_495 | CINEMATIC_HERO_RISE_FROM_PRONE_RIGHT_2 | high | 24.0x41.0, 8 paths: the **tallest** of the six and 26 narrower than F0 |
| CINEMATIC_496 | CINEMATIC_HERO_RISE_FROM_PRONE_RIGHT_3 | high | 24.5x35.5, 8 paths, x[-0.5, 24.0] -- the whole figure is now on the positive side of the anchor |
| CINEMATIC_497 | CINEMATIC_HERO_RISE_FROM_PRONE_RIGHT_4 | high | 23.5x32.0, 8 paths, x[2.5, 26.0] |
| CINEMATIC_498 | CINEMATIC_HERO_RISE_FROM_PRONE_RIGHT_5 | high | 19.5x33.0, 8 paths, x[7.5, 27.0]: the narrowest, upright |
| CINEMATIC_469 | CINEMATIC_HERO_RISE_FROM_PRONE_LEFT_0 | high | 50.0x26.0, 9 paths, x[-23.5, 26.5]: the exact mirror of the RIGHT `_0`, same size and same path count |
| CINEMATIC_499 | CINEMATIC_HERO_RISE_FROM_PRONE_LEFT_1 | high | 33.5x35.0, 8 paths, x[-21.0, 12.5]: exact mirror of RIGHT `_1` |
| CINEMATIC_500 | CINEMATIC_HERO_RISE_FROM_PRONE_LEFT_2 | high | 25.0x41.5, 8 paths, the tallest of its run |
| CINEMATIC_501 | CINEMATIC_HERO_RISE_FROM_PRONE_LEFT_3 | high | 23.5x36.0, 8 paths, x[-25.0, -1.5] -- wholly on the negative side |
| CINEMATIC_502 | CINEMATIC_HERO_RISE_FROM_PRONE_LEFT_4 | high | 21.5x34.5, 8 paths, x[-25.0, -3.5] |
| CINEMATIC_503 | CINEMATIC_HERO_RISE_FROM_PRONE_LEFT_5 | high | 18.5x33.5, 8 paths, the narrowest of its run |

## What these names do not claim

The small separate shape at the end of the arm in `_0`, present in both
facings and gone from every later frame, is **not named**. It is why `_0` has
nine paths where the others have eight, and that is all this batch says about
it.

`RISE_FROM_PRONE` is the extents: 50.0 wide by 26.0 tall at the start, 19.5 by
33.0 at the end, monotone in width. It does not say what put the figure on the
ground.
