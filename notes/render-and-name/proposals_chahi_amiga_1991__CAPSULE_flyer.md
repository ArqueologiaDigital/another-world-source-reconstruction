# CAPSULE: eight frames where only the trailing part changes

`LABEL_116D` draws eight pictures one per `break` at `[0xE6],[0xE7]`, opening
with `play id=0x006C` at vol 0x18 -- the quietest sound in this stage's
routines. Read at palette 0x0C.

```
  016  60.0x13.0   9 paths  x[-21.0, 39.0]  y[-4.5, 8.5]
  017  55.5x13.0  11 paths  x[-18.0, 37.5]  y[-4.5, 8.5]
  018  50.5x13.0  11 paths  x[-17.5, 33.0]  y[-4.5, 8.5]
  019  52.0x13.0  11 paths  x[-17.5, 34.5]  y[-4.5, 8.5]
  020  51.0x13.0  11 paths  x[-17.5, 33.5]  y[-4.5, 8.5]
  021  48.0x12.0   9 paths  x[-17.5, 30.5]  y[-4.5, 7.5]
  022  50.5x 9.5   8 paths  x[-17.5, 33.0]  y[-4.5, 5.0]
  023  63.0x10.0  12 paths  x[-26.0, 37.0]  y[-4.5, 5.5]
```

Seven of the eight share a **left edge at -17.5 or -18.0** and all eight share
a top edge at -4.5. What moves is the right edge, 30.5 to 39.0, and the path
count, 8 to 12.

Rendered, the reason is plain: the large pale shape on the left -- a long
tapered body with a dark patch on it -- is **the same in every frame**, and
the small dark-blue shape behind it is different in every one: a
parallelogram, a tent, a diagonal, a V, an X, absent, a sliver, three slivers.

| constant | proposed name | confidence | evidence |
| --- | --- | --- | --- |
| CINEMATIC_016 | CINEMATIC_CAPSULE_FLYER_F0 | medium | 60.0x13.0, 9 paths: the tapered body plus one flat parallelogram behind it. First of the run, and the `play` follows it |
| CINEMATIC_017 | CINEMATIC_CAPSULE_FLYER_F1 | medium | 55.5x13.0, 11 paths: two more paths and the trailing shape is a tent |
| CINEMATIC_018 | CINEMATIC_CAPSULE_FLYER_F2 | medium | 50.5x13.0, 11 paths, the narrowest but one; the trailing shape is a single diagonal |
| CINEMATIC_019 | CINEMATIC_CAPSULE_FLYER_F3 | medium | 52.0x13.0, 11 paths; the trailing shape is a V |
| CINEMATIC_020 | CINEMATIC_CAPSULE_FLYER_F4 | medium | 51.0x13.0, 11 paths; the trailing shape crosses itself |
| CINEMATIC_021 | CINEMATIC_CAPSULE_FLYER_F5 | medium | 48.0x12.0, **9 paths**, the narrowest of the eight: the trailing shape is gone and only a stub is left |
| CINEMATIC_022 | CINEMATIC_CAPSULE_FLYER_F6 | medium | 50.5x**9.5**, 8 paths, the fewest and the shortest |
| CINEMATIC_023 | CINEMATIC_CAPSULE_FLYER_F7 | medium | 63.0x10.0, **12 paths**, the widest and the most: three slivers behind the body, and the left edge reaches -26.0 where every other frame stops at -17.5 |

## What these names do not claim

`FLYER` is a long tapered body, 48 to 63 by 9.5 to 13, at a variable anchor,
with a trailing element that changes every frame and vanishes in one. It does
**not** decide between a machine and an animal: the body has a pointed end and
a dark patch, and at 13 pixels tall neither reading is settled by the picture.

The trailing shapes are **not named separately**. They are paths inside these
eight, not constants of their own, and the run's whole variation is in them.
