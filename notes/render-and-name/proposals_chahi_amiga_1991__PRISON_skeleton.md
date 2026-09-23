# PRISON: the x-ray flash, both facings, and the hero's aim pose

## Two sequences with the same shape

`LABEL_10D5` and `LABEL_1128` are the same three instructions with different
constants:

```
LABEL_10D5:           376   break   377   mov [0x29], 0x0014
LABEL_10F0: break     378   jge/djnz [0x29] -> LABEL_10F0
LABEL_1107: break     377

LABEL_1128:           365   break   366   mov [0x29], 0x0014
LABEL_1137: break     367   jge/djnz [0x29] -> LABEL_1137
LABEL_1148: break     366
```

One picture, then a pair **alternating twenty times**, then back to the first
of the pair. Both at `[BUDDY_X],[BUDDY_Y]` -- an actor slot, so **#0138**
applies and these come from the art.

## The pairs are one picture in two colours

Comparing the path data, not the extents:

```
  366 vs 367   16 paths each, geometry IDENTICAL coordinate for coordinate
  377 vs 378   15 paths each, geometry IDENTICAL coordinate for coordinate
```

and the fills are the whole difference:

```
  366   16 x #fbfbfb   (white)        377   15 x #fbfbfb
  367   16 x #202044   (dark navy)    378   15 x #202044
```

So neither pair is two frames of anything. Each is **one picture strobed**,
which is what a `djnz [0x29]` seeded to 0x14 around exactly two draws does.

Rendered, those sixteen and fifteen paths are a skull, a ribcage and limbs.
`CINEMATIC_365` and `CINEMATIC_376` are the frame before the strobe: four
paths, three `#fbfbfb` and one `#0097fb`, a solid white body inside a bright
blue edge.

## The facings

```
  365   x[-29.5,   7.5]        376   x[ -8.5,  28.5]
  366   x[-24.5,   9.5]        377   x[ -6.5,  23.5]
```

`365` and `376` are an **exact mirror**: -29.5 + 28.5 = -1 and 7.5 + -8.5 =
-1, the same axis both ways, at the same 37.0x50.0 and four paths. The
skeletons are not mirrors of each other -- 34.0 wide against 30.0, sixteen
paths against fifteen -- but each sits on the same side of the anchor as the
silhouette it follows, so the two signals agree about which sequence is which.

| constant | proposed name | confidence | evidence |
| --- | --- | --- | --- |
| CINEMATIC_365 | CINEMATIC_PRISON_XRAY_FLASH_LEFT | high | 37.0x50.0, four paths: a solid `#fbfbfb` body inside one `#0097fb` edge. x[-29.5, 7.5], the negative-dominant half of an exact mirror pair with `_RIGHT`. The single frame before the strobe begins |
| CINEMATIC_366 | CINEMATIC_PRISON_XRAY_SKELETON_LEFT_LIT | high | 34.0x46.0, **16 paths all `#fbfbfb`**: a skull, a ribcage and limbs. Identical in geometry to `_DARK` coordinate for coordinate. Drawn first of the strobed pair and again as its last frame |
| CINEMATIC_367 | CINEMATIC_PRISON_XRAY_SKELETON_LEFT_DARK | high | the same 16 paths as `_LIT`, filled `#202044`. Drawn inside the `djnz [0x29]` loop seeded to 0x14 |
| CINEMATIC_376 | CINEMATIC_PRISON_XRAY_FLASH_RIGHT | high | 37.0x50.0, four paths, the same three white and one blue. x[-8.5, 28.5] -- the mirror of `_LEFT` about x = -0.5, exact on both edges |
| CINEMATIC_377 | CINEMATIC_PRISON_XRAY_SKELETON_RIGHT_LIT | high | 30.0x46.0, **15 paths all `#fbfbfb`**, geometry identical to `_DARK`. Not a mirror of the left skeleton -- four narrower and one path fewer -- but on the positive side of the anchor, like the flash that precedes it |
| CINEMATIC_378 | CINEMATIC_PRISON_XRAY_SKELETON_RIGHT_DARK | high | the same 15 paths, filled `#202044` |
| CINEMATIC_563 | CINEMATIC_PRISON_HERO_STAND_AIM_RIGHT | high | 39.5x48.5, 12 paths at `[HERO_X],[HERO_Y]`: a standing figure with orange hair, a dark top and a pistol held out to the right. x[-9.5, 30.0], positive-dominant. `LABEL_6AAB` draws it and then, on a condition, `CINEMATIC_PRISON_HERO_STAND_AIM_RIGHT_CHARGE_DOT` -- a one-path dot at x = 20.0, inside this picture's own x range and at the end of the gun. The name is the one that charge dot already carries, minus its suffix |

## What these names do not claim

`XRAY` is the white-then-dark strobe of a skeleton over a figure's position.
Nothing here says who is inside it, and the two sequences are identified as
left and right by the signed bounding box, not by which scene calls them.

`_LIT` and `_DARK` are the fills, `#fbfbfb` and `#202044`. They are not frame
indices, because there is no motion between them -- the geometry is the same
coordinate for coordinate.
