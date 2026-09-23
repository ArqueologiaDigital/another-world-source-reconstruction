# INTRO: seven layers of two background composites

Both routines build a scene by laying one picture over another, and only the
finished state is ever displayed, so a layer rendered alone says very little.
These were read with `compose_run.py --progressive`, which draws each layer
**over the ones before it**, and then again alone to confirm what had appeared.

## `DRAW_PARTICLE_LAB_BG_COMPOSITE` -- five numbered layers among four named ones

Draw order is `166, PARTICLE_LAB_BG_F0..F3, 171, 172, 173, 174`, and the
composite is displayed at **palette 0x08**: `INTRO_TRANSITION_TO_LAKE_SCENE`
calls the routine and sets that palette on the next line. (The other caller,
`INTRO_COMPOSE_PAGE3_THEN_RECEDE_DOWN_ACCELERATOR_TUNNEL`, builds it on page 3
for later use.)

```
  166  0x3A70  321.0x151.5    3 paths   drawn FIRST, before anything
  171  0x3830  182.0x 79.5   61 paths   y[104.5, 184.0]
  172  0x39D6   39.5x 49.0   10 paths   x[130.5, 170.0] y[129.5, 178.5]
  173  0xC80C  191.5x 26.0   41 paths   y[165.5, 191.5]
  174  0xC78E  280.0x154.0   67 paths   drawn LAST, over everything
```

166 is three paths and the first thing drawn: two wall planes meeting at a
vertical corner above a floor, and nothing else. Everything in the room is laid
on top of it.

171 is the console: 61 paths in a 182x79.5 band low in the frame, an angled
desk with a green inset and rows of small coloured controls. 172 is 10 paths in
39.5x49.0 directly in front of it -- a seat on a pedestal. 173 is 41 paths
confined to a 26-pixel-high band at y[165.5, 191.5], small dark specks strewn
along the floor. 174 is 67 paths scattered across the **whole** 280x154 scene
and drawn after everything: small pale and cyan slivers sitting on the
machinery.

## `DRAW_CARPARK_ENTRANCE_COMPOSITE` -- two layers on the pillar

This routine sets its own palette, `setPalette 0x04`, four lines in. Its
pillar is built from progressively narrower single-path shapes, each over the
last:

```
  CARPARK_WALL_DOORWAY_RECESS   65.0 wide
  CARPARK_PILLAR_OUTER_SHADE    67.0
  CARPARK_PILLAR_MID_SHADE      59.0
  CARPARK_PILLAR_LIT_FACE       47.0
  CINEMATIC_104                 37.0      <- narrower still, 1 path
  CINEMATIC_105                  1.0      <- one pixel wide, 145.0 tall
```

104 continues that narrowing: a curved pale highlight down one side of the lit
face. 105 is not a face at all -- **1.0 x 145.0 in a single path**, a vertical
line at x[159.5, 160.5], which is the middle of the pillar's own x[126.5,
193.5].

## Proposals

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_166 | CINEMATIC_PARTICLE_LAB_WALLS_AND_FLOOR | high | 0x3A70, **3 paths**, 321.0x151.5, the first thing `DRAW_PARTICLE_LAB_BG_COMPOSITE` draws: two wall planes meeting at a vertical corner over a floor. Every other layer sits on it |
| CINEMATIC_171 | CINEMATIC_PARTICLE_LAB_CONSOLE_DESK | high | 0x3830, 61 paths, 182.0x79.5 at y[104.5, 184.0]: an angled desk with a green inset panel and rows of small coloured controls |
| CINEMATIC_172 | CINEMATIC_PARTICLE_LAB_CHAIR | high | 0x39D6, 10 paths, 39.5x49.0 at x[130.5, 170.0], standing directly in front of the desk: a seat on a pedestal |
| CINEMATIC_173 | CINEMATIC_PARTICLE_LAB_FLOOR_LITTER | high | 0xC80C, 41 paths confined to a 26-pixel band at y[165.5, 191.5] -- small dark specks strewn along the floor, and nothing above it |
| CINEMATIC_174 | CINEMATIC_PARTICLE_LAB_HIGHLIGHTS | medium | 0xC78E, 67 paths spread over the full 280.0x154.0 of the scene and drawn **last**, after every other layer: small pale and cyan slivers on the machinery |
| CINEMATIC_104 | CINEMATIC_CARPARK_PILLAR_HIGHLIGHT | medium | 0x17D6, **1 path**, 37.0x113.0 -- narrower than `..._PILLAR_LIT_FACE`'s 47.0 and drawn straight after it, continuing the same run of narrowing single-path shades. A curved pale band down one side |
| CINEMATIC_105 | CINEMATIC_CARPARK_PILLAR_SEAM | high | 0x17F2, **1 path, 1.0 x 145.0** -- one pixel wide and three-quarters of the screen tall, at x[159.5, 160.5], the middle of the pillar's x[126.5, 193.5] |

## What these names do not claim

`PARTICLE_LAB` and `CARPARK` are the two routines' own words, and `PILLAR` is
already in four sibling names.

`HIGHLIGHTS` for 174 is the weakest of the seven and is graded `medium`: what
is measured is 67 small pale paths spread over the whole scene and drawn after
everything else. That it is specular rather than, say, dust is a reading.
`FLOOR_LITTER` is firmer because the 26-pixel band pins it to the floor.

Nothing here claims 172 is a chair anyone sits in during this scene. It is a
seat-shaped object in front of the desk; who uses it is elsewhere.
