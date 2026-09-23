# CAVES: five more kit pieces, found by counting placements

`notes/scenery-kit/kit_pieces.py` lists still-numbered pictures that are placed
only at fixed literal coordinates, many times, by several routines -- the test
that told the stalactites apart from a backdrop layer. Lowering it to three
placements in two routines returns 26 in amiga, of which ten are CAVES
one-leaf shapes. Five of those ten are unambiguous once rendered at palette 9
and cropped to their own extents.

```
  389   75.0x67.0   1 leaf    a stepped profile: five descending steps, left to right
  276   84.0x67.0   1 leaf    the same profile, nine pixels wider
  277  127.0x66.0   1 leaf    a plain parallelogram, slanting down to the right
  437   24.0x31.0   1 leaf    a plain rectangle
  212   26.0x36.0   1 leaf    a plain rectangle, slightly larger
```

**437 tiles.** Three of its eleven placements are `x=179, y=31`, `y=62`, `y=93`
-- a column at intervals of exactly 31, which is its own height. That is a wall
being built out of one block, and it is the only one of the five that does it.

The other four are scattered as terrain: 277 at `(37,31), (76,76), (149,11),
(192,168), (203,208)`, 389 at `(59,15), (112,69), (150,27), (226,87)`, 276 at
`(46,139), (91,146), (99,160), (121,203)`. Two of those y values are past the
bottom of a 200-pixel screen, which is what a piece placed to fill a corner off
the visible edge looks like.

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_389 | CINEMATIC_CAVES_STEPPED_SLOPE_0 | medium | 0xF2FA, 75.0x67.0 in one leaf; a staircase profile, five steps descending left to right; 4 placements in 2 routines |
| CINEMATIC_276 | CINEMATIC_CAVES_STEPPED_SLOPE_1 | medium | 0xFBBC, 84.0x67.0 in one leaf, the same profile nine pixels wider; 4 placements in 4 routines |
| CINEMATIC_277 | CINEMATIC_CAVES_SLANTED_SLAB | medium | 0xF304, **127.0x66.0** in one leaf, a plain parallelogram with no steps, the widest of the five; 5 placements in 3 routines |
| CINEMATIC_437 | CINEMATIC_CAVES_WALL_TILE | medium | 0xE032, 24.0x31.0 in one leaf, a plain rectangle **tiled vertically at intervals of 31 -- its own height** -- at x=179; 11 placements in 5 routines |
| CINEMATIC_212 | CINEMATIC_CAVES_PLAIN_BLOCK | medium | 0xD7A6, 26.0x36.0 in one leaf, a plain rectangle placed at `(16,184)`, `(320,184)` and `(160,19)`, never tiled; 3 placements in 2 routines |

## The five left numbered

`554` (0.0x53.0), `546` (7.0x33.0), `338` (14.0x65.0), `384` (39.0x15.0) and
`412` (61.0x88.0). 338 and 412 render in the background colour at palette 9, so
whatever they are is invisible in the one palette that has been looked at; 554
is a bare vertical line and 546 a seven-pixel sliver. Each wants its own
palette found before it is worth a name.
