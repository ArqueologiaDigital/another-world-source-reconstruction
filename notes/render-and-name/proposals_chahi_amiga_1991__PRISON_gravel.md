# PRISON: a gravel field tiled down the screen, and the shards over it

`PRISON_BACKDROP_TILE_REPEAT_DOWN` builds a whole screen out of one small
tile. It paints the tile into page 3, then copies that page onto page 0 four
times with `[SCROLL_Y]` stepping by 0x20 each time, and finally lays three
pictures over the result:

```
	selectVideoPage 0x03
	call DRAW_CIN_SEQ_085_085_086
	mov [SCROLL_Y], 0x0000
	copyVideoPage src=0x83, dst=0x00        \  four copies,
	add [SCROLL_Y], 0x0020                   \ SCROLL_Y +0x20 apart
	...
	video offset=CINEMATIC_087, x=160, y=100
	video offset=CINEMATIC_088, x=160, y=100
	video offset=CINEMATIC_089, x=160, y=100
	video offset=CINEMATIC_089, x=0,   y=100
```

and `DRAW_CIN_SEQ_085_085_086` is four draws, two pictures at two anchors:

```
	video offset=CINEMATIC_085, x=132, y=39
	video offset=CINEMATIC_085, x=297, y=39
	video offset=CINEMATIC_086, x=132, y=39
	video offset=CINEMATIC_086, x=297, y=39
```

## The path sizes name these, not the silhouettes

```
            paths    median      largest path
  085        325     4.0 x 3.0    8.0 x  6.0
  086         81     4.0 x 3.0    8.0 x  6.0
  087         58    22.0 x 6.0   29.0 x 30.0
  088         59    22.0 x 9.0   29.0 x 30.0
  089         41    18.0 x 9.0   25.0 x 30.0
```

085 and 086 are **hundreds of pieces none of which exceeds 8x6** -- there is
no object in either, only a texture, and the routine's job is to repeat it
until it fills a screen. 087, 088 and 089 are made of pieces three to five
times longer, median 22 wide by 6 to 9 tall: slivers, scattered and crossing,
with a few blocks among them.

| constant | proposed name | confidence | evidence |
| --- | --- | --- | --- |
| CINEMATIC_085 | CINEMATIC_PRISON_GRAVEL_TILE_0 | high | 178x54 and **325 paths**, median 4.0x3.0, largest 8.0x6.0: a dense field of small angular stones and nothing else. Drawn at 132,39 and again at 297,39, into a page the routine then copies down the screen four times at 0x20 intervals. A texture, by construction |
| CINEMATIC_086 | CINEMATIC_PRISON_GRAVEL_TILE_1 | high | 156x44, 81 paths, same median 4.0x3.0 and same largest 8.0x6.0 as `_0`: the same stones, sparser, laid over `_0` at the same two anchors to fill its gaps. Rendered alone it is a thinner version of the same field |
| CINEMATIC_087 | CINEMATIC_PRISON_DEBRIS_SHARDS_0 | medium | 190x220, 58 paths, median 22.0x6.0: long thin slivers lying across each other over the gravel, with a handful of small blocks. Three to five times longer than any gravel piece, which is what separates this layer from the tile beneath it. First of the three laid over the tiled page |
| CINEMATIC_088 | CINEMATIC_PRISON_DEBRIS_SHARDS_1 | medium | 184x203, 59 paths, median 22.0x9.0: the same kind of slivers, second of the three |
| CINEMATIC_089 | CINEMATIC_PRISON_DEBRIS_SHARDS_2 | medium | 134x190, 41 paths, median 18.0x9.0. Drawn **twice**, at 160,100 and again at 0,100, so the same scatter appears at two places across the screen -- which is also why its own extent is the narrowest of the three |

## What these names do not claim

`GRAVEL_TILE_0` and `_1` are two passes of one texture at one pair of anchors,
not two frames. The index is draw order.

`SHARDS` says the pieces are long and thin relative to the gravel, which is
measured. It does not say what they are shards of.
