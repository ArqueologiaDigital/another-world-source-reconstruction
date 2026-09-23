# CAVES: someone picks up a burning torch, and the field that follows a burst

## The torch

`LABEL_03A4` and the `LABEL_03C7` it falls into draw eight constants at one
fixed spot, `x=123, y=172`, with a `break` between each -- a cutscene played in
place.

    545 -> 547 -> 548 -> 549 -> 550 -> 551 -> 552 -> 553 (held four frames)

Rendered at palette 29 and cropped to each frame's own extent
(`crop_to_extent.py`), it reads straight through: a figure bent double, then
reaching down to a **long pole with a magenta-and-yellow tip** lying at its
feet, then standing with the pole upright beside it, then lifting it, then
holding it, then reaching it out. The tip is the only part of any of the eight
that is not in the silhouette colour, and it is two colours -- which is what a
flame is drawn as.

The heights follow the action and are the check on the reading:

```
  545  41.5x36.0    5 leaf   bent double, no pole
  547  44.5x92.5   22 leaf   reaching down, pole on the ground
  548  37.5x77.5   19 leaf   standing, pole upright
  549  41.5x95.0   24 leaf   lifting -- the tallest of the eight
  550  41.5x64.0   20 leaf   holding
  551  46.5x59.0   23 leaf   reaching out
  552  54.0x59.0   24 leaf   reaching further -- the widest
  553  49.5x59.0   14 leaf   held, and repeated four times
```

36 tall while bent, 92 to 95 while the pole is up, 59 once it is held out in
front: the figure's own height never changes, so what grows and shrinks is the
pole's angle.

## The field after the burst

`LABEL_10ED` is set up on **four channels at once** -- 0x05, 0x06, 0x07, 0x08 --
immediately after `CAVES_BURST_CHUNKS_F0..F6` and `CAVES_BURST_STREAKS_F0..F6`
have played out. It cycles four constants across four x positions:

```
  249@160  250@164  251@168  252@172
  250@160  251@164  252@168  249@172
  251@160  252@164  249@168  250@172
  252@160  249@164  250@168  251@172
```

Each of the four is a **vertical run of short horizontal dashes** -- 0.0 wide
(one pixel, which the rasteriser draws as two), 54 to 69 tall, 9 to 15 leaves,
in two or three colours. Four columns, four phases, four channels: the same
strip of dashes marching down the screen everywhere at once.

The name says what they are and not what they mean. A burst has just happened
and something is raining or flickering; which of those it is would take the
scene, and the scene is not in this routine.

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_545 | CINEMATIC_CAVES_TORCH_BEARER_F0 | medium | 0x4D20, 41.5x36.0 in 5 leaves, bent double and the only frame without the pole; first in `LABEL_03A4` |
| CINEMATIC_547 | CINEMATIC_CAVES_TORCH_BEARER_F1 | medium | 0xF96E, 44.5x92.5 in 22 leaves, reaching down to the pole where it lies |
| CINEMATIC_548 | CINEMATIC_CAVES_TORCH_BEARER_F2 | medium | 0xF99A, 37.5x77.5 in 19 leaves, upright with the pole beside |
| CINEMATIC_549 | CINEMATIC_CAVES_TORCH_BEARER_F3 | medium | 0xF9C6, **41.5x95.0** in 24 leaves, the tallest of the eight -- the pole at its highest |
| CINEMATIC_550 | CINEMATIC_CAVES_TORCH_BEARER_F4 | medium | 0xF9FA, 41.5x64.0 in 20 leaves; first of `LABEL_03C7` |
| CINEMATIC_551 | CINEMATIC_CAVES_TORCH_BEARER_F5 | medium | 0xFA2A, 46.5x59.0 in 23 leaves, the pole coming down in front |
| CINEMATIC_552 | CINEMATIC_CAVES_TORCH_BEARER_F6 | medium | 0xFA56, **54.0x59.0** in 24 leaves, the widest -- the pole furthest out |
| CINEMATIC_553 | CINEMATIC_CAVES_TORCH_BEARER_F7 | medium | 0xFA82, 49.5x59.0 in 14 leaves, drawn four times in a row: the pose the sequence rests on |
| CINEMATIC_249 | CINEMATIC_CAVES_DASH_COLUMN_0 | medium | 0xD008, 0.0x69.0 in 14 leaves, a vertical run of one-pixel dashes; phase 0 of the four-channel cycle that follows the burst |
| CINEMATIC_250 | CINEMATIC_CAVES_DASH_COLUMN_1 | medium | 0xD06C, 0.0x64.0 in 11 leaves; phase 1 |
| CINEMATIC_251 | CINEMATIC_CAVES_DASH_COLUMN_2 | medium | 0xD09C, 0.0x54.0 in 9 leaves, the shortest; phase 2 |
| CINEMATIC_252 | CINEMATIC_CAVES_DASH_COLUMN_3 | medium | 0xD0C4, 0.0x69.0 in 15 leaves; phase 3 |

The phase index is the routine's own: each frame draws `249, 250, 251, 252` at
`160, 164, 168, 172` and then rotates which constant starts, so `_0` is the one
that opens at x=160.

## Left numbered

`CINEMATIC_546` (7.0x33.0), drawn at `x=97, y=138` beside the torch sequence and
twice more elsewhere, and `CINEMATIC_044` (13.0x10.0 in 4 leaves) at
`x=113, y=194`. Neither is part of the eight-frame run and neither is legible at
palette 29.
