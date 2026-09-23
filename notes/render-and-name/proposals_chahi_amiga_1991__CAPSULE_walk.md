# CAPSULE: a walk cycle, measured off the two edges

`[0xE8],[0xE9]` are seeded to 0x00B4, 0x0064 -- 180,100 -- and a later
`add [0xE8], 0x000D` steps the anchor 13 to the right. Between those, one
block draws `CINEMATIC_356` four times and `CINEMATIC_357` twice, and
`LABEL_070A` draws `CINEMATIC_358` to `365` twice each.

## The two edges alternate, and that is the whole argument

Every one of the ten is 16 to 21 tall and sits in the same y band. Only x
moves:

```
  356   7.0 wide  x[-123.5, -116.5]   1 path
  357  31.0       x[-123.5,  -92.5]   2 paths
  358  29.0       x[-123.5,  -94.5]   2 paths
  359  27.0       x[-121.5,  -94.5]
  360  22.0       x[-116.5,  -94.5]
  361  18.0       x[-112.5,  -94.5]
  362  16.0       x[-110.5,  -94.5]   <- narrowest
  363  18.0       x[-110.5,  -92.5]
  364  22.0       x[-110.5,  -88.5]
  365  27.0       x[-110.5,  -83.5]
```

From F2 to F6 the **left** edge marches right, -123.5 to -110.5, while the
right edge does not move at all. From F6 to F9 the **left** edge does not move
and the **right** edge marches right, -94.5 to -83.5. One end catches up while
the other waits, then that end goes ahead: the pair passes through itself and
keeps going, and the anchor then steps 13 further right.

`CINEMATIC_356` is **one path** where every other frame is two, and its left
edge is the same -123.5 the pair starts from. One shape becoming two, at the
same place.

| constant | proposed name | confidence | evidence |
| --- | --- | --- | --- |
| CINEMATIC_356 | CINEMATIC_CAPSULE_DISTANT_WALK_F0 | high | 7.0x16.0, **one path**, x[-123.5, -116.5]: the only frame of the ten that is a single shape, at the left edge the pair later starts from. Drawn four times |
| CINEMATIC_357 | CINEMATIC_CAPSULE_DISTANT_WALK_F1 | high | 31.0x19.5, two paths, x[-123.5, -92.5]: the widest of the ten, and the same left edge as F0. Drawn twice |
| CINEMATIC_358 | CINEMATIC_CAPSULE_DISTANT_WALK_F2 | high | 29.0x17.5, two paths, x[-123.5, -94.5] |
| CINEMATIC_359 | CINEMATIC_CAPSULE_DISTANT_WALK_F3 | high | 27.0x18.0, x[-121.5, -94.5]: left edge +2, right edge unmoved |
| CINEMATIC_360 | CINEMATIC_CAPSULE_DISTANT_WALK_F4 | high | 22.0x20.5, x[-116.5, -94.5]: left edge +5, right edge unmoved |
| CINEMATIC_361 | CINEMATIC_CAPSULE_DISTANT_WALK_F5 | high | 18.0x21.0, x[-112.5, -94.5], the tallest of the ten |
| CINEMATIC_362 | CINEMATIC_CAPSULE_DISTANT_WALK_F6 | high | 16.0x18.0, x[-110.5, -94.5]: **the narrowest**, and the frame the two edges swap roles at |
| CINEMATIC_363 | CINEMATIC_CAPSULE_DISTANT_WALK_F7 | high | 18.0x20.5, x[-110.5, -92.5]: left edge now unmoved, right edge +2 |
| CINEMATIC_364 | CINEMATIC_CAPSULE_DISTANT_WALK_F8 | high | 22.0x19.5, x[-110.5, -88.5]: right edge +4 |
| CINEMATIC_365 | CINEMATIC_CAPSULE_DISTANT_WALK_F9 | high | 27.0x19.0, x[-110.5, -83.5]: right edge +5, and the cycle ends 13 right of where it began -- the same 13 the anchor is then stepped by |

## What these names do not claim

`WALK` is the edge measurement above and nothing else: one end holds while the
other closes, then they swap, and the net displacement matches the `add
[0xE8], 0x000D` the routine applies afterwards. `DISTANT` is the scale -- 16
to 21 pixels tall, against a standing hero's 47 elsewhere in this stage.

**Nothing here says what is walking.** At 21 pixels tall and two paths there is
no silhouette to read, and the anchor is a variable pair, so the scene cannot
answer it either.
