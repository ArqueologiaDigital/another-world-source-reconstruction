# CAPSULE: five bodies under a named upper pose

`STATE_VAR12_BIG_DISPATCH_CASE_38` and `..._CASE_28` both draw these five, and
every one is drawn **immediately before a constant that is already named**, at
the same anchor:

```
	video offset=CINEMATIC_334, x=[BUDDY_X], y=[BUDDY_Y]
	video type=0, offset=CV_FIGURE_WALK_RIGHT_UPPER_POSE_00, ... zoom=0x40
	break
	video offset=CINEMATIC_335, ...
	video type=0, offset=CV_FIGURE_WALK_RIGHT_UPPER_POSE_01, ...
	...
	add [BUDDY_X], 0x0002
	video offset=CINEMATIC_336, ...
	video type=0, offset=CV_FIGURE_WALK_RIGHT_UPPER_POSE_03, ...
```

The pairing is one to one and exhaustive: 334→00, 335→01, 336→03, 337→04,
338→06. Nothing else in this stage pairs a numbered constant with a
`CV_FIGURE_WALK_*` pose.

## Which of the pair is the body

```
  CINEMATIC_334                        27.5x59.5  10 paths  y[-58.5,   1.0]
  CV_FIGURE_WALK_RIGHT_UPPER_POSE_00   18.0x30.0   2 paths  y[-53.0, -23.0]
```

The numbered one is 59.5 tall with its lowest point at y +1.0 -- the floor --
and ten paths. The named one is 30 tall, two paths, and sits entirely in the
band y -53 to -23. So the numbered constant is the **whole figure** and the
named one is a small overlay on its upper half, drawn after it. Rendered, the
numbered five are a figure in boots, striding, with `add [BUDDY_X], 0x0002`
between two of the frames.

## The index is draw order, and it has to be

The upper family runs `_00` to `_08`, nine poses; only five are paired here,
at 00, 01, 03, 04 and 06. Numbering the bodies to match would give a family
`{0, 1, 3, 4, 6}` -- holes at 2 and 5 -- which `docs/NAMING.md` §2 bars and
`apply_cinematic_renames.py` rejects. So the index is this run's own order and
each row names its partner instead.

| constant | proposed name | confidence | evidence |
| --- | --- | --- | --- |
| CINEMATIC_334 | CINEMATIC_CAPSULE_FIGURE_WALK_RIGHT_BODY_F0 | high | 27.5x59.5, 10 paths, y[-58.5, 1.0]: a full figure standing on y +1.0. Drawn immediately before `CV_FIGURE_WALK_RIGHT_UPPER_POSE_00` at the same anchor |
| CINEMATIC_335 | CINEMATIC_CAPSULE_FIGURE_WALK_RIGHT_BODY_F1 | high | 18.0x60.5, 10 paths, the narrowest of the five -- legs together. Paired with `..._UPPER_POSE_01` |
| CINEMATIC_336 | CINEMATIC_CAPSULE_FIGURE_WALK_RIGHT_BODY_F2 | high | 41.0x60.5, **15 paths**, the widest and most-pathed: the leading leg is out and five extra paths trail behind its boot. Paired with `..._UPPER_POSE_03`, and the `add [BUDDY_X], 0x0002` is on the line before |
| CINEMATIC_337 | CINEMATIC_CAPSULE_FIGURE_WALK_RIGHT_BODY_F3 | high | 39.5x60.5, 11 paths: the leg still out, one extra path rather than five. Paired with `..._UPPER_POSE_04` |
| CINEMATIC_338 | CINEMATIC_CAPSULE_FIGURE_WALK_RIGHT_BODY_F4 | high | 26.0x60.5, 10 paths, back to the base path count. Paired with `..._UPPER_POSE_06` |

## What these names do not claim

`WALK_RIGHT` is taken from the constant each frame is paired with, which is
already named that, plus the `add [BUDDY_X], 0x0002` between frames. The
bodies themselves do not state a direction -- their signed boxes run both ways
across the cycle, which is what legs do.

**The extra paths in F2 and F3 are not named.** Five of them trail the leading
boot in F2 and one in F3; they are strokes behind a foot and this batch does
not say whether they are motion, dust or something the boot emits.
