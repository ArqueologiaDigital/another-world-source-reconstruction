# CAVES: an object breaking up, and a figure with one arm out

Both runs come from `frame_runs.py --stage CAVES --min 5 --stages`, and both
report **this stage only**, so both take a `CAVES_` word.

## 194 to 199: the path count is the whole story

`LABEL_11B7` draws the six in order at `[0xE6],[0xE7]`. `LABEL_121D` draws the
same six overlapped in pairs -- `194 199 195 194 196 195 197 196 198 197 198
199` -- which is a cross-fade, not six more frames.

```
  194   9.0x17.0   2 paths
  195  14.5x17.0   7 paths
  196  14.5x16.0   7 paths
  197  13.5x10.5   5 paths
  198  14.5x11.5   5 paths
  199  12.0x10.0   5 paths
```

One picture with **two** paths becomes one with **seven**, and then settles at
five while the height falls from 17.0 to 10.0. Rendered at palette 0x05, F0 is
a single dark blue mass with a narrow spike above it; from F1 the mass is
gone and separate angular pieces stand where it was; by F5 the pieces are
smaller, fewer and further apart, and the spike is gone too.

## 643, 651 to 656: one path's worth of arm

`LABEL_24CF` draws seven at `[HERO_X],[HERO_Y]` -- an actor slot, **#0138**.

```
  643  14.5x37.0   9 paths  x[ -7.5,  7.0]
  651  18.5x36.5   9 paths  x[-11.0,  7.5]
  652  35.0x40.0  10 paths  x[-21.5, 13.5]
  653  32.5x42.5  11 paths  x[-20.5, 12.0]
  654  23.0x43.0  11 paths  x[-15.5,  7.5]
  655  19.0x39.0  10 paths  x[-11.5,  7.5]
  656  12.5x38.0   9 paths  x[ -8.5,  4.0]
```

Height barely moves -- 37.0 to 43.0 and back -- while width goes 14.5 out to
35.0 and back to 12.5, and the path count goes 9, 9, 10, 11, 11, 10, 9. The
extra width and the extra paths arrive and leave together, and they arrive on
the **negative** side: x reaches -21.5 at F2 against F0's -7.5.

Rendered, the figure is the one `CINEMATIC_HERO_*` already names here -- orange
hair, pale limbs -- and the extra path is a long pale bar running up and to the
left from the shoulder.

| constant | proposed name | confidence | evidence |
| --- | --- | --- | --- |
| CINEMATIC_194 | CINEMATIC_CAVES_SHATTER_F0 | medium | 9.0x17.0, **two paths**: one dark blue mass with a narrow spike above it. The only frame of the six that is a single object |
| CINEMATIC_195 | CINEMATIC_CAVES_SHATTER_F1 | medium | 14.5x17.0, **seven paths**: five more than F0 at the same height, spread 5.5 wider. The mass is gone and separate angular pieces are in its place |
| CINEMATIC_196 | CINEMATIC_CAVES_SHATTER_F2 | medium | 14.5x16.0, seven paths |
| CINEMATIC_197 | CINEMATIC_CAVES_SHATTER_F3 | medium | 13.5x10.5, five paths -- the height drops by 5.5 here, the largest step in the run, and two pieces are gone |
| CINEMATIC_198 | CINEMATIC_CAVES_SHATTER_F4 | medium | 14.5x11.5, five paths |
| CINEMATIC_199 | CINEMATIC_CAVES_SHATTER_F5 | medium | 12.0x10.0, five paths: the shortest and the last |
| CINEMATIC_643 | CINEMATIC_CAVES_HERO_ARM_OUT_LEFT_F0 | medium | 14.5x37.0, 9 paths, x[-7.5, 7.0]: the figure with nothing extended, and the narrowest of the seven |
| CINEMATIC_651 | CINEMATIC_CAVES_HERO_ARM_OUT_LEFT_F1 | medium | 18.5x36.5, 9 paths, x[-11.0, 7.5] |
| CINEMATIC_652 | CINEMATIC_CAVES_HERO_ARM_OUT_LEFT_F2 | medium | 35.0x40.0, **10 paths**, x[-21.5, 13.5]: the widest, and the tenth path is a long pale bar reaching up and left from the shoulder |
| CINEMATIC_653 | CINEMATIC_CAVES_HERO_ARM_OUT_LEFT_F3 | medium | 32.5x42.5, **11 paths**, the tallest of the seven |
| CINEMATIC_654 | CINEMATIC_CAVES_HERO_ARM_OUT_LEFT_F4 | medium | 23.0x43.0, 11 paths: 12 narrower than F2 with the same path count -- the bar is drawing back in |
| CINEMATIC_655 | CINEMATIC_CAVES_HERO_ARM_OUT_LEFT_F5 | medium | 19.0x39.0, 10 paths |
| CINEMATIC_656 | CINEMATIC_CAVES_HERO_ARM_OUT_LEFT_F6 | medium | 12.5x38.0, 9 paths, x[-8.5, 4.0]: back to the path count and roughly the width of F0 |

## What these names do not claim

`SHATTER` is two paths becoming seven and then five, at a falling height. It
does not say what the object was: at 9.0x17.0 with two paths there is nothing
in F0 to identify, and the run says only that it stopped being one thing.

`ARM_OUT_LEFT` is the extra path and the extra width arriving and leaving
together on the negative side of the anchor. It does not say what the figure
is reaching for, or whether it is reaching at all rather than being pulled.

`CINEMATIC_458` to `CINEMATIC_464` from `LABEL_3C0E` are **left numbered**.
They are two thin curved strokes that spread apart, flatten and close again
while the pair moves from above the anchor (y[-16.5, 0.5]) to below it
(y[2.5, 19.5]). Two paths is not enough to say what a pair of curves is, and
nothing else in the routine narrows it.
