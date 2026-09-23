# CAPSULE: a full-height column widening, in two families

Two runs at `160,100`, both spanning the **whole screen height** and both
widening frame by frame. `LABEL_0636` sets `setPalette 0x0C` before its run;
`LABEL_0600` is reached by `jmp` and ends by writing its last frame to page 0.

```
  LABEL_0636, 3 paths each          LABEL_0600, 5 paths each
  388  28.0x158.5  y[-100.0, 58.5]  400  19.0x160.5  y[-102.0, 58.5]
  389  28.0x159.0  y[-100.0, 59.0]  401  42.0x158.0  y[-100.5, 57.5]
  390  33.5x159.0                   402  47.0x158.0
  391  43.0x159.5                   403  61.0x158.5
  392  49.0x159.5                   404  61.0x158.5
  393  52.0x158.0                   405  62.0x158.5
                                    406  62.0x161.0  y[-102.5, 58.5]
```

Every frame of both is 158 to 161 tall and every one spans y -100 to +58, so
nothing here grows or moves vertically: the **only** thing that changes is the
width, 28 to 52 in one family and 19 to 62 in the other.

The path counts separate them and the render says what the difference is.
`LABEL_0636`'s three paths are a flat lens at the top of the span and another
at the bottom, with **nothing between them**. `LABEL_0600`'s five are those
two plus a tapered shaft joining them, wider at the top than the bottom.

| constant | proposed name | confidence | evidence |
| --- | --- | --- | --- |
| CINEMATIC_388 | CINEMATIC_CAPSULE_BEAM_ENDS_F0 | medium | 28.0x158.5, **3 paths**, y[-100.0, 58.5]: a flat lens at the top of the span and another at the bottom, and nothing between them. The narrowest of its family |
| CINEMATIC_389 | CINEMATIC_CAPSULE_BEAM_ENDS_F1 | medium | 28.0x159.0, 3 paths: the same width as F0, half a pixel taller |
| CINEMATIC_390 | CINEMATIC_CAPSULE_BEAM_ENDS_F2 | medium | 33.5x159.0, 3 paths |
| CINEMATIC_391 | CINEMATIC_CAPSULE_BEAM_ENDS_F3 | medium | 43.0x159.5, 3 paths: the largest single step, 9.5 wider than F2 |
| CINEMATIC_392 | CINEMATIC_CAPSULE_BEAM_ENDS_F4 | medium | 49.0x159.5, 3 paths |
| CINEMATIC_393 | CINEMATIC_CAPSULE_BEAM_ENDS_F5 | medium | 52.0x158.0, 3 paths, the widest. Its routine draws it once more into **page 0**, so it is the state the room keeps |
| CINEMATIC_400 | CINEMATIC_CAPSULE_BEAM_COLUMN_F0 | medium | 19.0x160.5, **5 paths**: the two lenses plus a shaft joining them, here barely wider than a line. The narrowest thing in either family |
| CINEMATIC_401 | CINEMATIC_CAPSULE_BEAM_COLUMN_F1 | medium | 42.0x158.0, 5 paths: **23 wider than F0**, the largest step in either family |
| CINEMATIC_402 | CINEMATIC_CAPSULE_BEAM_COLUMN_F2 | medium | 47.0x158.0, 5 paths |
| CINEMATIC_403 | CINEMATIC_CAPSULE_BEAM_COLUMN_F3 | medium | 61.0x158.5, 5 paths |
| CINEMATIC_404 | CINEMATIC_CAPSULE_BEAM_COLUMN_F4 | medium | 61.0x158.5, 5 paths -- the same extent as F3 and a distinct `canonical_md5`, so the shaft changes inside its own outline |
| CINEMATIC_405 | CINEMATIC_CAPSULE_BEAM_COLUMN_F5 | medium | 62.0x158.5, 5 paths |
| CINEMATIC_406 | CINEMATIC_CAPSULE_BEAM_COLUMN_F6 | medium | 62.0x161.0, 5 paths, the widest and the tallest. Its routine draws it once more into **page 0** |

## What these names do not claim

`BEAM` is a shape that spans the screen from top to bottom in every frame and
only ever changes width. It does not claim light, energy or a transport, and
nothing in the pictures says which way it points.

`ENDS` and `COLUMN` are the path counts, three against five, and what that
difference renders as. **The two families are not claimed to be phases of one
thing.** `LABEL_0636` runs first and its widest frame is 52.0; `LABEL_0600`
starts again at 19.0, which does not continue it, and this batch does not
explain that.

`CINEMATIC_386`, `387` and `399` are drawn by the same two routines and are
**left numbered**: 386 is 86.0x9.0 at the very top of the span, 387 is
45.0x22.0 drawn four times at y 100, 98, 96 and 94 -- rising -- and 399 is
175.0x173.0 with 13 paths. None of the three was rendered for this batch.
