# CAVES: four short runs, read at palette 0x05

## `LABEL_14A1`, 143 to 147: the top edge never moves

```
  143   9.0x25.5  2 paths  x[-25.5, -16.5]  y[-38.0, -12.5]
  144  10.0x23.5  2 paths  x[-26.0, -16.0]  y[-38.0, -14.5]
  145  13.0x21.5  2 paths  x[-27.5, -14.5]  y[-38.0, -16.5]
  146  14.0x19.5  2 paths  x[-26.0, -12.0]  y[-38.0, -18.5]
  147  26.0x12.0  1 path   x[-25.0,   1.0]  y[-38.0, -26.0]
```

**y starts at -38.0 in all five** while the bottom edge climbs -12.5 to -26.0
and the width grows 9.0 to 26.0. A shape pinned at one end and swinging out
from it. Rendered, the two paths are a limb with a pale wedge at the free end,
bent in F0 and straight by F4, where the wedge is gone and only one path is
left.

## `LABEL_2F29` / `LABEL_2F51` / `LABEL_2F73`, 534 to 536

Three routines draw the same three pictures, each twice, at `140,[0xE6]`,
`157,54` and `160,[0xE6]`.

```
  534  195.0x4.0   9 paths   y[27.0, 31.0]
  535  208.0x4.5  11 paths   y[27.0, 31.5]
  536  194.0x4.5  11 paths   y[26.5, 31.0]
```

**Wider than half the screen and four pixels tall**, nine to eleven paths, all
in the same four-pixel y band. Rendered, each is a long undulating line, and
the three differ only in where the crests sit.

## `LABEL_30E6` / `LABEL_310C` / `LABEL_3128`, 283 to 285

```
  283  39.0x38.5  7 paths  y[ -94.0, -55.5]
  284  43.0x40.0  7 paths  y[ -89.5, -49.5]
  285  27.0x34.0  7 paths  y[-100.5, -66.5]
```

Seven paths in all three, all well above the anchor. Rendered, each is a small
group of bright vertical bars with pale segments in them, the three differing
in how the bars are spread.

## `LABEL_CAB0`, 403 to 405

```
  403  40.0x14.5  14 paths  x[-28.5, 11.5]  y[-16.0, -1.5]
  404  40.0x14.5  14 paths  x[-28.5, 11.5]  y[-16.0, -1.5]
  405  40.0x13.5  14 paths  x[-28.5, 11.5]  y[-15.0, -1.5]
```

**Identical extents and identical path counts**, three distinct
`canonical_md5`s. Rendered, a dark bracket with a bright rounded lamp at each
end, and what differs between the three is the lamps.

| constant | proposed name | confidence | evidence |
| --- | --- | --- | --- |
| CINEMATIC_143 | CINEMATIC_CAVES_SWINGING_LIMB_F0 | medium | 9.0x25.5, 2 paths, the narrowest and tallest: bent, with a pale wedge at the free end. Top edge y -38.0 |
| CINEMATIC_144 | CINEMATIC_CAVES_SWINGING_LIMB_F1 | medium | 10.0x23.5, 2 paths, same top edge |
| CINEMATIC_145 | CINEMATIC_CAVES_SWINGING_LIMB_F2 | medium | 13.0x21.5, 2 paths |
| CINEMATIC_146 | CINEMATIC_CAVES_SWINGING_LIMB_F3 | medium | 14.0x19.5, 2 paths |
| CINEMATIC_147 | CINEMATIC_CAVES_SWINGING_LIMB_F4 | medium | 26.0x12.0, **1 path**: straight, and the pale wedge is gone. Still pinned at y -38.0 |
| CINEMATIC_534 | CINEMATIC_CAVES_RIPPLE_LINE_F0 | medium | 195.0x**4.0**, 9 paths, y[27.0, 31.0]: an undulating line wider than half the screen. Three routines draw it, at three different anchors, twice each |
| CINEMATIC_535 | CINEMATIC_CAVES_RIPPLE_LINE_F1 | medium | 208.0x4.5, 11 paths, the widest of the three |
| CINEMATIC_536 | CINEMATIC_CAVES_RIPPLE_LINE_F2 | medium | 194.0x4.5, 11 paths, the narrowest |
| CINEMATIC_283 | CINEMATIC_CAVES_BAR_CLUSTER_F0 | medium | 39.0x38.5, 7 paths, y[-94.0, -55.5]: bright vertical bars with pale segments, well above the anchor |
| CINEMATIC_284 | CINEMATIC_CAVES_BAR_CLUSTER_F1 | medium | 43.0x40.0, 7 paths, the widest and the lowest of the three |
| CINEMATIC_285 | CINEMATIC_CAVES_BAR_CLUSTER_F2 | medium | 27.0x34.0, 7 paths, the narrowest and the highest |
| CINEMATIC_403 | CINEMATIC_CAVES_TWIN_LAMP_BRACKET_F0 | medium | 40.0x14.5, 14 paths: a dark bracket with a bright rounded lamp at each end |
| CINEMATIC_404 | CINEMATIC_CAVES_TWIN_LAMP_BRACKET_F1 | medium | 40.0x14.5, 14 paths -- the same extent as F0 to the pixel and the same path count, with a distinct `canonical_md5` |
| CINEMATIC_405 | CINEMATIC_CAVES_TWIN_LAMP_BRACKET_F2 | medium | 40.0x13.5, 14 paths: one pixel shorter, everything else unchanged |

## What these names do not claim

`SWINGING_LIMB` is a shape pinned at y -38.0 in all five frames that widens as
its free end rises. It does not say whose limb, and the tree's other CAVES
limb families are the swimmer's, drawn at `[HERO_X],[HERO_Y]`; this one is
drawn at `[0x78],[0x79]`.

`RIPPLE_LINE` is 194 to 208 wide by 4 tall, undulating. It does not claim
water; what it claims is a long thin line whose crests move between three
variants.

`BAR_CLUSTER` and `TWIN_LAMP_BRACKET` describe what the paths draw. Neither
says what the thing is for, and `TWIN_LAMP_BRACKET`'s three frames differ only
inside an outline that never changes, which is what a light does and not what
a moving object does.
