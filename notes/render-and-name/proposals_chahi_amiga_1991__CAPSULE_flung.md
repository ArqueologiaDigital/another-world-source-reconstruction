# CAPSULE: a figure in flight, and a figure pushing its upper body up

Both at `[HERO_X],[HERO_Y]` -- an actor slot, so **#0138** applies -- read at
palette 0x0C.

## `LABEL_098B`, 454 to 458: it leaves

```
  454  35.5x31.0  10 paths  x[  2.0,  37.5]  y[-29.0,   2.0]
  455  45.5x36.5  10 paths  x[ 24.5,  70.0]  y[-36.5,   0.0]
  456  54.0x20.0  10 paths  x[ 39.0,  93.0]  y[-30.5, -10.5]
  457  53.0x15.0  10 paths  x[ 59.0, 112.0]  y[-21.0,  -6.0]
  458  35.5x14.0   3 paths  x[ 89.5, 125.0]  y[-17.5,  -3.5]
```

The x range **never overlaps its own start**: left edge +2.0 to +89.5, right
edge +37.5 to +125.0, monotone in both. Height falls 31.0 to 14.0 after one
frame of rising to 36.5. Path count holds at 10 for four frames and then drops
to **3**.

Rendered, the orange-haired figure is tumbling away to the right and getting
smaller, and by F4 only a few strokes are left.

## `LABEL_0930`, 448 to 452: it rises without moving

```
  448  58.5x 7.5  11 paths  x[-15.0, 43.5]  y[ -6.5, 1.0]
  449  55.5x 8.5   9 paths  x[-12.0, 43.5]  y[ -7.5, 1.0]
  450  56.0x 9.5   9 paths  x[-11.5, 44.5]  y[ -8.5, 1.0]
  451  55.5x11.0   9 paths  x[-11.0, 44.5]  y[-10.0, 1.0]
  452  52.5x13.5  10 paths  x[ -9.0, 43.5]  y[-12.5, 1.0]
```

The **bottom edge is +1.0 in all five** and the right edge stays within a
pixel of +44. Only the top edge moves, -6.5 to -12.5, and only the left edge
follows it in, -15.0 to -9.0. Rendered, a figure lying flat with its head to
the left, lifting its upper body while the rest of it does not move.

| constant | proposed name | confidence | evidence |
| --- | --- | --- | --- |
| CINEMATIC_454 | CINEMATIC_CAPSULE_FIGURE_FLUNG_F0 | medium | 35.5x31.0, 10 paths, x[2.0, 37.5]: the orange-haired figure, nearest the anchor of the five |
| CINEMATIC_455 | CINEMATIC_CAPSULE_FIGURE_FLUNG_F1 | medium | 45.5x36.5, 10 paths, x[24.5, 70.0]: the tallest and the only frame taller than F0 |
| CINEMATIC_456 | CINEMATIC_CAPSULE_FIGURE_FLUNG_F2 | medium | 54.0x20.0, 10 paths, x[39.0, 93.0]: the widest, and the height has halved |
| CINEMATIC_457 | CINEMATIC_CAPSULE_FIGURE_FLUNG_F3 | medium | 53.0x15.0, 10 paths, x[59.0, 112.0] -- past the right of where F0's whole extent was |
| CINEMATIC_458 | CINEMATIC_CAPSULE_FIGURE_FLUNG_F4 | medium | 35.5x14.0, **3 paths** against the previous four frames' 10: almost nothing is left |
| CINEMATIC_448 | CINEMATIC_CAPSULE_FIGURE_PROP_UP_F0 | medium | 58.5x**7.5**, 11 paths, y[-6.5, 1.0]: the flattest of the five, a figure lying with its head to the left |
| CINEMATIC_449 | CINEMATIC_CAPSULE_FIGURE_PROP_UP_F1 | medium | 55.5x8.5, 9 paths, bottom edge still +1.0 |
| CINEMATIC_450 | CINEMATIC_CAPSULE_FIGURE_PROP_UP_F2 | medium | 56.0x9.5, 9 paths |
| CINEMATIC_451 | CINEMATIC_CAPSULE_FIGURE_PROP_UP_F3 | medium | 55.5x11.0, 9 paths |
| CINEMATIC_452 | CINEMATIC_CAPSULE_FIGURE_PROP_UP_F4 | medium | 52.5x**13.5**, 10 paths, y[-12.5, 1.0]: 6 taller than F0 with the bottom edge and the right edge unmoved |

## What these names do not claim

`FLUNG` is the x range moving so far that F3 no longer overlaps F0, with the
height falling and the path count collapsing to 3. It does **not** claim this
is the figure thrown by `CINEMATIC_CAPSULE_FIGURE_THROW_F0..F8`, even though
that run also ends with a small figure going right: the two are in different
routines and nothing here connects them.

`PROP_UP` is one edge moving and three staying put. It does not say what the
figure is on or why it is down.

`CINEMATIC_078` to `082`, drawn by `LABEL_144F` at `141,127`, are **left
numbered**: five near-identical dark masses in a corner, 9 paths for four of
them and 2 for the last, and at that size the render does not settle what they
are.
