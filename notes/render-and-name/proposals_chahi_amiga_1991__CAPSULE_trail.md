# CAPSULE: a trail retracting to a point, and a wide flash at a chosen height

## 407 to 410: two paths, one end pinned

`LABEL_0771` and `LABEL_078F` each draw these four at `[0xEA],157` and
`[0xEB],157` -- the same four, at two anchors.

```
  407  178.0x175.0  2 paths  x[-210.0, -32.0]  y[-209.5, -34.5]
  408  177.0x176.0  2 paths  x[-175.0,   2.0]  y[-175.5,   0.5]
  409   71.0x 70.0  2 paths  x[ -70.0,   1.0]  y[ -69.5,   0.5]
  410    4.5x  7.0  2 paths  x[  -3.0,   1.5]  y[  -6.5,   0.5]
```

From F1 on the **lower-right end does not move**: x ends at +2.0, +1.0, +1.5
and y at +0.5 in all three. The upper-left end comes in from 175 away to 3
away. Width and height stay within a pixel of each other in every frame, so
the thing is at 45 degrees throughout.

Rendered, it is a single diagonal stroke -- two paths because a thick line in
this engine is two triangles -- shortening from behind while its leading end
stays put.

## 125 to 128: a band wider than the screen

`LABEL_181B` and `LABEL_1833` each draw these four one per `break` and then
`killChannel`, at `160,[0xE7]` and `160,[0xE8]`: one effect, played at a
height the caller picks.

```
  125  261.0x16.0  3 paths
  126  475.0x22.0  4 paths     <- wider than the 320-pixel screen
  127  403.0x15.0  5 paths
  128  201.0x 6.0  2 paths
```

Width goes 261 out to **475** and back to 201; height 16, 22, 15, 6. Rendered,
each is a horizontal bar and nothing else.

`frame_runs.py --stages` reports **CAVES 4/4** for this family: byte-identical
twins there, still numbered. Not CAPSULE art, so no stage word.

| constant | proposed name | confidence | evidence |
| --- | --- | --- | --- |
| CINEMATIC_407 | CINEMATIC_CAPSULE_DIAGONAL_TRAIL_F0 | medium | 178.0x175.0, two paths, x[-210.0, -32.0]: one diagonal stroke at 45 degrees, the longest of the four and the only one whose leading end is not yet at the anchor |
| CINEMATIC_408 | CINEMATIC_CAPSULE_DIAGONAL_TRAIL_F1 | medium | 177.0x176.0, two paths, x[-175.0, 2.0] y[-175.5, 0.5]: the leading end has reached the anchor and stays there for the rest of the run |
| CINEMATIC_409 | CINEMATIC_CAPSULE_DIAGONAL_TRAIL_F2 | medium | 71.0x70.0, two paths: 106 shorter than F1 with the leading end unmoved -- the stroke is being eaten from behind |
| CINEMATIC_410 | CINEMATIC_CAPSULE_DIAGONAL_TRAIL_F3 | medium | 4.5x7.0, two paths, x[-3.0, 1.5]: what is left, at the anchor |
| CINEMATIC_125 | CINEMATIC_WIDE_FLASH_F0 | medium | 261.0x16.0, 3 paths: a horizontal bar and nothing else, drawn at a y the caller chooses. First of four, then `killChannel` |
| CINEMATIC_126 | CINEMATIC_WIDE_FLASH_F1 | medium | 475.0x22.0, 4 paths: the widest and the tallest, and **wider than the 320-pixel screen** -- it runs off both edges |
| CINEMATIC_127 | CINEMATIC_WIDE_FLASH_F2 | medium | 403.0x15.0, 5 paths: still wider than the screen, 7 shorter than F1 |
| CINEMATIC_128 | CINEMATIC_WIDE_FLASH_F3 | medium | 201.0x**6.0**, 2 paths: a quarter of F1's width and a third its height -- the last |

## What these names do not claim

`DIAGONAL_TRAIL` is a 45-degree stroke whose leading end is pinned at the
anchor from F1 while the other end closes 175 to 3. It does not say what made
it or what is at the pinned end; no frame contains anything but the stroke.

`WIDE_FLASH` is a bar that goes from 261 to 475 wide and back to 201 while
getting thinner, at a height the caller sets. `FLASH` is the shape's brief
flare, not a claim about light. The name carries no stage word because the
same four are byte-identical in CAVES.
