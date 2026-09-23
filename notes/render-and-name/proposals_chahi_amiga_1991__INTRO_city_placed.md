# INTRO: the city scene, composited where the engine actually puts it

## Why this is a correction as well as a batch

`compose_run.py` draws every layer at the renderer's own anchor, (160, 100). A
background composite does not: each `video` carries its own `x, y`. Read
without placement, `INTRO_SCENE_INIT_PARTICLES`'s 51 layers piled on top of one
another, the scene did not resolve into anything, and its six numbered layers
were filed in `notes/HANDOFF.md` as unreadable. That was a fault in how they
were looked at, not in the art.

`compose_run.py --routine` now reads the draw list from the branch's `.asm`,
resolves each `EQU` and translates every layer by `(draw_x - 160, draw_y - 100)`,
with coordinates read as signed (`../coordinate-signedness/`). Composited that
way the scene is a night cityscape: towers, a pale pyramid tower, a gantry with
lattice bracing at the right, a ground line, and a foreground girder frame.

Two carpark names from an earlier batch were read off the same mistake and are
corrected below.

## The six, each seen against the layer before it

```
  543  0x0B8E   49.0x14.0   12 paths   ->  x[284.0, 333.0] y[111.5, 125.5]
  555  0x0A54    6.0x 6.0    1 path    ->  four draws along y[120.0, 126.0]
  559  0x0B36  249.0x22.0    1 path    ->  x[-16.5, 232.5] y[127.0, 149.0]
  560  0x0CE4  102.0x 7.5   15 paths   ->  x[186.0, 288.0] y[171.0, 178.5]
  563  0x0DCA   72.0x22.0    1 path    ->  x[215.0, 287.0] y[105.0, 127.0]
  564  0x0E02  120.0x12.0    1 path    ->  x[198.0, 318.0] y[125.0, 137.0]
```

- **543** lands on top of the gantry, whose `..._CROSS_BRACING` occupies
  x[253.0, 340.0]. Against the frame before it, what appears is a spray of thin
  angular spars radiating from the head of the mast.
- **555** is one 6x6 path drawn **four times** at x 86, 102, 177 and 178, all
  at the same y band. What appears each time is a small pointed triangle
  standing on the skyline base.
- **559** is a single path 249 wide: a long dark band tapering away to the
  right, just under the skyline and above the ground.
- **560** is 15 paths in a band 7.5 pixels tall, the lowest thing in the scene:
  a flat dark lens with small specks scattered either side of it.
- **563** is one path: a dark pointed peak standing in front of the pale
  pyramid tower, whose own `..._LIT_EDGE` and `..._FAR_EDGE` are already named.
- **564** is one path 120 wide and 12 tall: a long thin diagonal rising to the
  right and meeting the gantry post.

## Proposals

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_543 | CINEMATIC_CITY_GANTRY_AERIALS | medium | 0x0B8E, **12 paths** in 49.0x14.0, landing at x[284.0, 333.0] inside the gantry's own x[253.0, 340.0]: thin angular spars radiating from the head of the mast |
| CINEMATIC_555 | CINEMATIC_CITY_ROOFTOP_PEAK | medium | 0x0A54, **1 path**, 6.0x6.0, drawn four times at x 86, 102, 177, 178 in one y band on the skyline base. A small pointed triangle, repeated |
| CINEMATIC_559 | CINEMATIC_CITY_DISTANT_RIDGE | medium | 0x0B36, **1 path**, 249.0x22.0 at y[127.0, 149.0]: a long dark band tapering to the right, below the skyline and above the ground |
| CINEMATIC_560 | CINEMATIC_CITY_GROUND_PATCH | medium | 0x0CE4, 15 paths in a band **7.5 pixels tall** at y[171.0, 178.5], the lowest layer in the scene: a flat dark lens with specks around it |
| CINEMATIC_563 | CINEMATIC_CITY_DARK_PEAK | medium | 0x0DCA, **1 path**, 72.0x22.0 at x[215.0, 287.0]: a dark pointed peak standing in front of the pale pyramid tower |
| CINEMATIC_564 | CINEMATIC_CITY_GANTRY_CABLE | medium | 0x0E02, **1 path**, 120.0x12.0 at x[198.0, 318.0] y[125.0, 137.0]: a long thin diagonal rising to the right and meeting the gantry post |
| CINEMATIC_CARPARK_PILLAR_HIGHLIGHT | CINEMATIC_CARPARK_WALL_SHADOW | high | 0x17D6, 1 path. **Correction.** Drawn at `x=117, y=86` it lands at x[98.5, 135.5] -- on the wall, immediately right of `..._WALL_DOORWAY_RECESS` at x[31.5, 96.5], and nowhere near the pillar group at x[210.5, 277.5]. Against the frame before it, a curved darker band appears on the wall beside the doorway |
| CINEMATIC_CARPARK_PILLAR_SEAM | CINEMATIC_CARPARK_DOORWAY_DIVIDER | high | 0x17F2, 1 path, 1.0x145.0. **Correction.** Drawn at `x=61, y=69` it lands at x[60.5, 61.5] -- **inside** the doorway recess at x[31.5, 96.5] and inside `..._ENTRANCE_DOOR_CLOSED` at x[30.0, 65.0]. It splits the dark recess in two; it is not on the pillar |

## What the corrections retract

The earlier batch said 104 was "narrower than `..._PILLAR_LIT_FACE`'s 47.0 and
drawn straight after it, continuing the same run of narrowing single-path
shades", and that 105 sat "down the middle of the pillar's x[126.5, 193.5]".
Both sentences describe an untranslated composite. `..._PILLAR_LIT_FACE` is at
x[223.5, 270.5] once placed, 104 is at x[98.5, 135.5], and the two are 88
pixels apart with a doorway between them. The widths really do narrow -- 65,
67, 59, 47, 37 -- which is what made the wrong reading look convincing; they
are simply not narrowing around the same object.

## What these names do not claim

All six city names are `medium`. They rest on a placed composite and on
neighbours that were already named `CITY_*`, not on anything structural.
`GANTRY_AERIALS` and `GANTRY_CABLE` claim only that those two layers land on
the gantry and meet its mast. `GROUND_PATCH` claims a flat dark shape low in
the frame and not what it is a patch of.
