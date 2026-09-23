# PRISON: the last three layers of the wall backdrop, at palette 2

`FILL_AND_DRAW_CIN_24_28` is one screen's backdrop, composed once:

```
	fill page=0x00, color=0x00
	video offset=CINEMATIC_PRISON_WALL_RUBBLE_0 .. _4
	video offset=CINEMATIC_029, x=160, y=400        <- y=400, off screen
	video offset=CINEMATIC_PRISON_WALL_PILLAR
	video offset=CINEMATIC_PRISON_GRATING_STRIP
	video offset=CINEMATIC_032
	video offset=CINEMATIC_033
	video offset=CINEMATIC_034
	ret
```

Seven of its ten draws already carry names, so the subject -- a wall with a
burst of rubble, a pillar and a grating -- is settled. `LABEL_1CB8` calls it
under `setPalette 0x02`, and that is the palette every colour below is read
at.

Each of the three is drawn **once**, by this routine only, so the index is
draw order within the family and is not ambiguous the way a repeated layer's
would be.

## What is actually in them

Per path, not per picture:

```
  032   45 paths, NONE larger than 200 px^2
          2.0x80.0   at (244,0)    #0097fb
          1.0x123.0  at (228,0)    #5474db
        ... and 43 specks

  033   19 paths, 3 larger than 200 px^2, every one of them narrow and tall
          9.0x100.0  at (310,0)    #443087
          6.0x144.0  at (236,-1)   #302064
          3.0x170.0  at (224,1)    #302064

  034   14 paths, 2 larger than 200 px^2
         35.0x65.0   at (0,0)      #302064
         12.0x30.0   at (-5,184)   #302064
```

032's two largest paths are one and two pixels wide and light; 033's three are
three to nine pixels wide and dark; 034's largest sits in the screen's
top-left corner. None of the three contains a shape big enough to be a
subject of its own.

| constant | proposed name | confidence | evidence |
| --- | --- | --- | --- |
| CINEMATIC_032 | CINEMATIC_PRISON_WALL_HIGHLIGHTS | medium | 128x211 overall but **no path larger than 200 px^2**: two bright hairlines, 2x80 at x=244 in `#0097fb` and 1x123 at x=228 in `#5474db`, running down the pillar's edges, plus 43 specks. The only one of the three whose fills are light at palette 0x02. Drawn once, eighth of ten, by a routine that draws nothing else |
| CINEMATIC_033 | CINEMATIC_PRISON_WALL_SHADOW_BANDS | medium | 19 paths, and its three largest are all narrow verticals in the dark fills `#302064` and `#443087`: 9x100 at the right margin, 6x144 and 3x170 beside the pillar. Bands, not objects. Drawn once, ninth of ten |
| CINEMATIC_034 | CINEMATIC_PRISON_WALL_CORNER_SHADOW | medium | 14 paths; the dominant one is 35x65 in `#302064` at (0,0), the screen's top-left corner, with a curved inner edge that cuts across the rubble already painted there. A 12x30 block at (-5,184) anchors the bottom-left. Drawn last of ten |

## What these names do not claim

`HIGHLIGHTS` and `SHADOW` are read from the fills **at palette 0x02**, the one
`LABEL_1CB8` sets before calling this routine. The polygon data stores colour
indices, not colours; at another palette the same indices could read the other
way, and the evidence cites the palette for that reason.

The index is draw order within each family. `CINEMATIC_PRISON_WALL_RUBBLE_0..4`
in the same routine numbers its own five the same way, and the two families do
not share an index space.
