# INTRO: the lift interior, and the panel drawn twice in two shades

`INTRO_SET_PAL_7_FILL_PAGE0_5` sets **palette 0x07**, fills page 0 with colour
5 and then lays six pictures down in order. Read with
`compose_run.py --progressive`:

```
  f   offset   whole picture                                  paths
  528 0x22BC   257.0x235.5  x[ -6.0, 251.0] y[  1.5, 237.0]    65
  VIEW 0x2346    9.0x195.5  x[145.5, 154.5] y[ 21.0, 216.5]     6   (already named)
  530 0x23EC    80.0x218.0  x[120.0, 200.0] y[ -9.0, 209.0]     1
  531 0x2542    80.0x218.0  x[120.0, 200.0] y[ -9.0, 209.0]     1
  532 0x2536     6.0x198.0  x[157.0, 163.0] y[  1.0, 199.0]     1
  533 0x2562   137.0x238.5  x[118.5, 255.5] y[-89.0, 149.5]    25
```

**528 is the room.** 65 paths and the first thing drawn: walls, a doorway
recess and a floor, with everything else laid inside it.

**`CINEMATIC_LIFT_SCENE_VIEW` is the gap**, 9 pixels wide and bright, standing
in the doorway.

**530 and 531 are one shape drawn twice.** Identical boxes to the half-pixel,
identical `canonical_md5` `b68d53dff594`, one path each -- and different
colours: `#204464` and `#103054`. They are drawn at the same `x=287`, 17 apart
in y (118 then 101), and between them they cover the bright gap. The hash
cannot separate them (`notes/cross-port-art/colour_blind_hashes.py`); the fill
and the draw order can.

**532 is the seam**: 6.0 x 198.0 in a single path, a vertical sliver nearly the
full height of the page, drawn over where the two panels meet.

**533 is the structure beyond**: 25 paths across 137.0x238.5, reaching to
y=-89 -- well above the page -- a lattice with diagonal bracing.

## Proposals

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_528 | CINEMATIC_LIFT_INTERIOR | high | 0x22BC, **65 paths**, 257.0x235.5, drawn first after the page fill: walls, a doorway recess and a floor. Everything else in the scene sits inside it |
| CINEMATIC_530 | CINEMATIC_LIFT_DOORWAY_PANEL_LIT | medium | 0x23EC, 1 path, 80.0x218.0, fill `#204464`, drawn at `x=287, y=118`. The lighter of the identical pair |
| CINEMATIC_531 | CINEMATIC_LIFT_DOORWAY_PANEL_SHADE | medium | 0x2542, 1 path, the **same** 80.0x218.0 box and the same `canonical_md5` as 530, fill `#103054`, drawn at the same `x=287` 17 higher. The darker of the pair |
| CINEMATIC_532 | CINEMATIC_LIFT_DOORWAY_SEAM | high | 0x2536, **1 path**, 6.0x198.0 -- six pixels wide and nearly the full height of the page -- drawn after both panels, where they meet |
| CINEMATIC_533 | CINEMATIC_LIFT_SHAFT_LATTICE | medium | 0x2562, 25 paths across 137.0x238.5 reaching y=-89, above the page: a lattice with diagonal bracing, drawn last |

## What these names do not claim

`_LIT` and `_SHADE` rest on nothing but the two fills, `#204464` against
`#103054`, and follow the convention the carpark pillar already uses
(`..._PILLAR_LIT_FACE`, `..._PILLAR_OUTER_SHADE`). Which of the two is nearer
the light is not claimed; only which is brighter.

`SHAFT_LATTICE` for 533 is a reading of 25 paths of crossed members; that it
belongs to the shaft comes from the scene, not from the picture, and it is
graded `medium` for that reason.

These panels are not `CINEMATIC_LIFT_DOOR_LEAF_LEFT/RIGHT`, which are 14-15
pixels wide and animated by position in a different routine. `DOORWAY` rather
than `DOOR` keeps them apart.
