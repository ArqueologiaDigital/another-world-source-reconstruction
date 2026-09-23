# CAPSULE: nine frames in which one figure throws another

`INIT_VARS_07_08_29` seeds `[BUDDY_X],[BUDDY_Y]` to 0x9D,0x9D and `[0x29]` to
10; `ANIM_CIN_433_LOOP_VAR29` holds `CINEMATIC_433` for those ten frames and
then plays nine more, one per `break`, at that anchor -- an actor slot, so
**#0138** applies and the names come from the art. Read at palette 0x0C, the
palette the scene sets.

## The width is the throw

```
  434  31.5x94.5  28 paths   x[-11.5,  20.0]
  435  31.5x93.0  27 paths
  436  32.0x91.0  27 paths
  437  31.0x92.5  27 paths
  438  27.0x92.5  27 paths   x[-13.5,  13.5]
  439  44.5x74.5  23 paths   x[-23.0,  21.5]
  440 118.5x59.5  26 paths   x[-16.0, 102.5]
  441 114.5x60.5  22 paths   x[-11.0, 103.5]
  442  44.0x60.5  11 paths   x[-11.0,  33.0]
```

Five frames at 27 to 32 wide and 91 to 94.5 tall, then 44.5, then **118.5**,
with the right edge going from +13.5 to +102.5 in two steps. The height falls
the other way, 94.5 down to 59.5. And the path count ends at **11**, less than
half the 27 it held for five frames.

Rendered: a tall figure stands with a small orange-haired one in front of it;
it bends and takes hold; it swings; the small figure is flung out to the right
with straight strokes trailing it; and the last frame is the tall figure alone
with one arm extended, which is why 16 paths have gone.

| constant | proposed name | confidence | evidence |
| --- | --- | --- | --- |
| CINEMATIC_434 | CINEMATIC_CAPSULE_FIGURE_THROW_F0 | medium | 31.5x94.5, 28 paths, the most of the nine: a tall figure with a small orange-haired one in front of it. First after the ten-frame hold on `CINEMATIC_433` |
| CINEMATIC_435 | CINEMATIC_CAPSULE_FIGURE_THROW_F1 | medium | 31.5x93.0, 27 paths |
| CINEMATIC_436 | CINEMATIC_CAPSULE_FIGURE_THROW_F2 | medium | 32.0x91.0, 27 paths |
| CINEMATIC_437 | CINEMATIC_CAPSULE_FIGURE_THROW_F3 | medium | 31.0x92.5, 27 paths |
| CINEMATIC_438 | CINEMATIC_CAPSULE_FIGURE_THROW_F4 | medium | 27.0x92.5, 27 paths, the narrowest of the five tall frames: the figure has closed on the small one |
| CINEMATIC_439 | CINEMATIC_CAPSULE_FIGURE_THROW_F5 | medium | 44.5x74.5, 23 paths: **20 shorter and 17 wider** than F4 -- the tall figure bent over, the small one swung low |
| CINEMATIC_440 | CINEMATIC_CAPSULE_FIGURE_THROW_F6 | medium | 118.5x59.5, 26 paths, right edge at **+102.5** against F5's +21.5: the small figure is out at arm's length and beyond, with straight strokes behind it |
| CINEMATIC_441 | CINEMATIC_CAPSULE_FIGURE_THROW_F7 | medium | 114.5x60.5, 22 paths, right edge +103.5 -- four fewer paths at the same reach, so some of the strokes have gone |
| CINEMATIC_442 | CINEMATIC_CAPSULE_FIGURE_THROW_F8 | medium | 44.0x60.5, **11 paths**: the tall figure alone with one arm out. Sixteen paths fewer than F4, which is the small figure and its strokes no longer being drawn |

## What these names do not claim

`THROW` is the width going 27.0 to 118.5 in two steps while the height falls
and the path count ends at 11. It does not say why, and it does not name
either figure. The small one has the orange hair this tree elsewhere calls
Lester, and **this batch does not make that claim**: the slot is an actor
slot and #0138 is the reason.

`CINEMATIC_433`, held for ten frames before the run, is **left numbered**. It
was not rendered for this batch.
