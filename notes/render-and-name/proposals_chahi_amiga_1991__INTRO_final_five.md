# INTRO: the last five, all read from placed composites

Every one of these was held at some point in this session, and every hold was
caused by the same thing: looking at a picture at the renderer's anchor instead
of where the routine puts it. With `compose_run.py --routine` /
`--under-routine` and `on_screen_box.py`, all five resolve.

## The three that build one object

`BLINK_PAGE_FF_3X_LOOP` draws `292`, `293`, `294` one per `break` at
`x=160, y=100`, each **onto page 0 without clearing it**, over what
`FILL_PAGE_FF_COLOR_8_ONCE` has already accumulated there. So they are not
three states of one thing; they are three layers of one picture:

```
  292  0xD9EE  217.5x 99.5   22 paths   y[ 84.5, 184.0]
  293  0xDA7E  161.0x 73.5   29 paths   y[127.5, 201.0]   <- lower than 292
  294  0xDC20   63.0x 93.5   17 paths   y[ 85.0, 178.5]
```

Composited in place, 292 is a broad body with a raised block on top of it;
293 adds angular members splaying **below** it, which is why its band sits
lower; 294 adds more of them through the middle. The result is one object with
a hull, a superstructure and struts.

**This corrects an earlier reading.** `notes/HANDOFF.md` recorded these as "a
mass that comes apart", from areas 21,641 -> 11,833 -> 5,890 and a path count
that rises then collapses. Those numbers are right and the inference was wrong:
they are three layers of different sizes, not one object shrinking, and nothing
in the routine clears the page between them.

## The other two

**`CINEMATIC_026`** renders at x[33.0, 287.0] y[93.0, 107.0] and is drawn at
`x=42, y=120`, so it lands at **x[-85.0, 169.0] y[113.0, 127.0]** -- a single
path running off the left edge and tapering to a point at x=169, at road level.
Its scene is the one that draws `CAR_DRIVING_AWAY_FROM_CAMERA_F*`,
`CAR_TAIL_LIGHT_PAIR` and `CAR_SHADOW_F0`; the car's tail lights sit at
y[97.5, 143.5], the same band.

**`CINEMATIC_112`** is where the coordinate question mattered. Its five draws
read `y=65527, 65530, 65529, 65531, 65534`, which
`../coordinate-signedness/` establishes are **-9, -6, -7, -5, -2**. Placed:

```
  x=193 y=-9   ->  x[122.0, 125.0] y[11.0, 17.0]
  x=196 y=-6   ->  x[125.0, 128.0] y[14.0, 20.0]
  x=189 y=-7   ->  x[118.0, 121.0] y[13.0, 19.0]
  x=193 y=-5   ->  x[122.0, 125.0] y[15.0, 21.0]
  x=196 y=-2   ->  x[125.0, 128.0] y[18.0, 24.0]
```

All five land on the page, high up, and over the lift scene they sit
**immediately above the top corner of the lit doorway**. It is 3.0x6.0 in five
paths, every one a shade of red, and each of the five hold-loops holds it for
0x1E ticks.

## Proposals

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_292 | CINEMATIC_MACHINE_HULL | medium | 0xD9EE, 22 paths, 217.5x99.5: a broad body with a raised block on its top, the first of three layers drawn onto an uncleared page |
| CINEMATIC_293 | CINEMATIC_MACHINE_STRUTS | medium | 0xDA7E, **29 paths** in a band at y[127.5, 201.0], **below** the hull's: angular members splaying beneath it |
| CINEMATIC_294 | CINEMATIC_MACHINE_STRUT_DETAIL | medium | 0xDC20, 17 paths at y[85.0, 178.5], more of the same members through the middle. Drawn last of the three |
| CINEMATIC_026 | CINEMATIC_STREET_ROAD_EDGE | medium | 0x0900, **1 path**, 254.0x14.0, landing at x[-85.0, 169.0] y[113.0, 127.0]: runs off the left edge and tapers to a point, at the same height as the car's tail lights |
| CINEMATIC_112 | CINEMATIC_LIFT_DOOR_INDICATOR | medium | 0xC3E0, 3.0x6.0 in **5 paths, all shades of red**, drawn five times at y -9, -6, -7, -5, -2 (signed) and landing at x[118.0, 128.0] y[11.0, 24.0] -- just above the top corner of the lift's lit doorway, held 0x1E ticks each |

## What these names do not claim

`MACHINE` is the weakest word here and is graded `medium`: what is measured is
a broad body, a raised block on it, and angular members splaying below, built
in three layers on an uncleared page. It is not claimed to be a vehicle, to
have landed, or to belong to anyone.

`ROAD_EDGE` claims a line at road level that tapers to a point; whether it is a
kerb, a verge or the far side of the road is not claimed, and `CAR_SHADOW_F0`
already has the shadow.

`LIFT_DOOR_INDICATOR` claims a small red mark above the lift's doorway that
moves between five held positions. What it indicates is not claimed.
