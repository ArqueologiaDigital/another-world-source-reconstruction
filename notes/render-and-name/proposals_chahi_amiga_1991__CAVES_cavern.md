# CAVES: the stalactite cavern's four layers

`DRAW_STALACTITE_CAVERN_BG` is an **earned name** and it draws five pictures,
four of them still numbered:

```
DRAW_STALACTITE_CAVERN_BG:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_719, x=160, y=100
	video offset=CINEMATIC_718, x=160, y=100
	video offset=CINEMATIC_734, x=160, y=100
	video offset=CINEMATIC_735, x=160, y=100
	video offset=CINEMATIC_CAVES_SCREEN_CD_BACKDROP_LAYER_4, x=160, y=100
	ret
```

Its caller sets `setPalette 0x10` on the line before, and read at that palette
the composite is a cavern: a floor with small stalagmites along the bottom and
a ceiling with long stalactites hanging from the top, a dark gap between them.
The routine's name is not being taken on trust -- the picture shows what it
says.

## The extents split the four cleanly, with no overlap in y

```
  719  252.0x178.5  42 paths  x[-167.0,  85.0]  y[  15.0, 193.5]
  718  265.5x168.0  42 paths  x[ -60.0, 205.5]  y[  10.5, 178.5]
  734  311.5x179.5  52 paths  x[-191.0, 120.5]  y[-213.5, -34.0]
  735  148.0x128.0   9 paths  x[  85.0, 233.0]  y[-166.0, -38.0]
```

Two are **entirely below** the anchor (y from +10.5 and +15.0 down) and two
are **entirely above** it (y to -34.0 and -38.0). Nothing crosses y = 0, so
floor and ceiling are a measurement and not a reading. Within each pair the x
centres separate them: -41 against +73 below, -35 against +159 above.

| constant | proposed name | confidence | evidence |
| --- | --- | --- | --- |
| CINEMATIC_719 | CINEMATIC_CAVES_STALACTITE_CAVERN_FLOOR_LEFT | high | 252.0x178.5, 42 paths, y[15.0, 193.5] -- wholly below the anchor -- centred at x -41. Drawn first by a routine whose own name states the subject |
| CINEMATIC_718 | CINEMATIC_CAVES_STALACTITE_CAVERN_FLOOR_RIGHT | high | 265.5x168.0, 42 paths, y[10.5, 178.5], centred at x +73: the same number of paths as `_LEFT` and the other half of the floor |
| CINEMATIC_734 | CINEMATIC_CAVES_STALACTITE_CAVERN_CEILING_LEFT | high | 311.5x179.5, **52 paths**, the most of the four, y[-213.5, -34.0] -- wholly above the anchor -- centred at x -35. Rendered, the extra paths are the long tapered forms hanging from it, which is what the routine is named for |
| CINEMATIC_735 | CINEMATIC_CAVES_STALACTITE_CAVERN_CEILING_RIGHT | high | 148.0x128.0, **9 paths**, y[-166.0, -38.0], centred at x +159: the plainest of the four and the right-hand end of the ceiling |

## What these names do not claim

`LEFT` and `RIGHT` are the x centres, not a partition: the two floor pieces
overlap between x -60 and +85, and so do the two ceiling pieces between +85
and +120.5. Neither pair is cut at a seam.

These four are also drawn by `CAVES_SCREEN_CC_BACKDROP_DRAW` and
`CAVES_SCREEN_CE_BACKDROP_DRAW`. Those two name a **place**, not a subject,
so the name comes from the third drawer, the only one of the three that names
what is in the picture.

This resolves `CINEMATIC_718`, `719` and `734` from the handoff's held list.
