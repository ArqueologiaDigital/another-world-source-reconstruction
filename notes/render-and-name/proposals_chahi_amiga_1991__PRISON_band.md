# PRISON: a band that only bends, and a panel that loses its bars

## `DRAW_CIN_540_543_WITH_SFX_57`: two layers, one of which stops

The routine's first three frames are **pairs**, its last five singles:

```
	540 541  break   |  542 543  break (+ sound)  |  544 545  break
	546  break   547  break   548  break   547  break   548
```

So `{540, 542, 544}` appear only in the first three frames and
`{541, 543, 545, 546, 547, 548}` run the whole way. The second set is one
shape:

```
  541  12.0x50.0  1 path  x[15.0, 27.0]  y[-25.0, 25.0]
  543  18.0x49.0  1 path  x[15.0, 33.0]  y[-23.5, 25.5]
  545  13.0x49.0  1 path  x[14.5, 27.5]  y[-23.5, 25.5]
  546  17.0x49.0  1 path  x[14.5, 31.5]  y[-23.5, 25.5]
  547  14.0x49.0  1 path  x[15.0, 29.0]  y[-23.5, 25.5]
  548  15.0x49.0  1 path  x[14.5, 29.5]  y[-23.5, 25.5]
```

**One path, 49 or 50 tall, and the same y band in all six**; the left edge
never leaves 14.5..15.0. Only the width moves, 12 to 18. Rendered, each is a
narrow band running up the frame with a bend in it, and the six differ only in
how far the bend throws the top.

## `DRAW_CIN_624_TO_628_*`: a panel losing its bars

```
  624  16.0x18.0  8 paths      627  16.0x18.5  5 paths
  625  16.0x18.0  7 paths      628  16.0x18.0  2 paths
  626  16.0x18.5  6 paths
```

Identical extents -- 16.0 wide, 18.0 or 18.5 tall, at x[109.0, 125.0] in every
frame -- and the path count falls **8, 7, 6, 5, 2**. Rendered, they are
vertical bars inside a frame, one fewer each step, until only the frame's two
uprights are left. `DRAW_CIN_624_TO_628_5F_AT_499AFE0A` plays them in that
order and `DRAW_CIN_628_TO_625_4F_AT_2F47D6D0` plays them back.

| constant | proposed name | confidence | evidence |
| --- | --- | --- | --- |
| CINEMATIC_541 | CINEMATIC_PRISON_FLEXING_BAND_F0 | medium | 12.0x50.0, one path, the narrowest and the only one 50 tall. Drawn in the routine's first frame |
| CINEMATIC_543 | CINEMATIC_PRISON_FLEXING_BAND_F1 | medium | 18.0x49.0, one path, the **widest** of the six -- the bend at its furthest. The sound plays on this frame |
| CINEMATIC_545 | CINEMATIC_PRISON_FLEXING_BAND_F2 | medium | 13.0x49.0, one path |
| CINEMATIC_546 | CINEMATIC_PRISON_FLEXING_BAND_F3 | medium | 17.0x49.0, one path. The first frame with no partner in the other layer |
| CINEMATIC_547 | CINEMATIC_PRISON_FLEXING_BAND_F4 | medium | 14.0x49.0, one path. Drawn twice, as is F5 -- the routine ends by alternating the two |
| CINEMATIC_548 | CINEMATIC_PRISON_FLEXING_BAND_F5 | medium | 15.0x49.0, one path, and the last thing the routine draws before `killChannel` |
| CINEMATIC_624 | CINEMATIC_PRISON_BAR_PANEL_F0 | medium | 16.0x18.0, **8 paths**, the most: a frame with its full set of vertical bars |
| CINEMATIC_625 | CINEMATIC_PRISON_BAR_PANEL_F1 | medium | 16.0x18.0, 7 paths -- one bar fewer at exactly the same extent |
| CINEMATIC_626 | CINEMATIC_PRISON_BAR_PANEL_F2 | medium | 16.0x18.5, 6 paths |
| CINEMATIC_627 | CINEMATIC_PRISON_BAR_PANEL_F3 | medium | 16.0x18.5, 5 paths |
| CINEMATIC_628 | CINEMATIC_PRISON_BAR_PANEL_F4 | medium | 16.0x18.0, **2 paths**: the frame's two uprights and nothing between them |

## What these names do not claim

`FLEXING_BAND` is one path, 49 tall, pinned at its left edge, whose only
variation is width. It does not say what the band is or what bends it.

`BAR_PANEL` is a path count falling 8 to 2 at a fixed 16x18. It does not say
whether the bars are retracting, being cut, or being hidden -- and because
both orders are played, it does not claim which way is "opening".

`CINEMATIC_540`, `542` and `544` -- the layer that stops after three frames --
are **left numbered**. They are one path each at 16x32, 138x81 and 66x140, all
up and to the right of the anchor and progressively higher, and three frames
is not enough to say what they are.
