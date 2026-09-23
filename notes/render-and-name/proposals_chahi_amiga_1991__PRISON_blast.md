# PRISON: a second debris fall, at the hero's slot, with the page selection
# doing the sorting

`DRAW_CIN_137_138_BLOCK` runs at `[HERO_X],[HERO_Y]` -- an actor slot, so
**#0138** applies and these names come from the art. What sorts them into two
families is not the art at all; it is which page each draw goes to.

```
	selectVideoPage 0x00
	video offset=CINEMATIC_137        <- page 0, BEFORE the sound
	selectVideoPage 0xFF
	play id=0x005A, freq=0x14, vol=0x40, channel=0x00
	break
	video offset=CINEMATIC_138        \
	break                              |
	video offset=CINEMATIC_139         |  front buffer:
	break                              |  gone with the frame
	video offset=CINEMATIC_140        /
	selectVideoPage 0x00
	video offset=CINEMATIC_141        <- page 0, same frame as 140
	selectVideoPage 0xFF
	break
	video offset=CINEMATIC_142
	break
	video offset=CINEMATIC_143
	break
	video offset=CINEMATIC_144
	selectVideoPage 0x00
	video offset=CINEMATIC_145        <- page 0, same frame as 144
	selectVideoPage 0xFF
	killChannel
```

Six go to the front buffer and vanish with it. Three -- 137, 141, 145 -- go to
page 0, the page the room keeps. 141 and 145 are drawn in the *same frame* as
140 and 144, so they are not steps of the animation; they are what it leaves
behind.

## The measurements

```
        extent      paths   page   what it is
  137   22.0x 9.5     4      0     two crossing strokes low at the anchor
  138   41.0x60.0    38     FF     the cloud, tallest, top at y -65.5
  139   48.0x60.0    34     FF     wider
  140   59.0x56.5    29     FF     wider still, falling
  142   53.0x54.0    14     FF     only 14 pieces left
  143   49.0x57.0    20     FF
  144   50.0x 5.0    15     FF     flat: y[-4.5, 0.5]
  141   63.0x 3.5     9      0     flat, the widest deposit
  145   25.0x 3.0     7      0     flat, the last deposit
```

Every one of the nine has its bottom edge between y -2.5 and y +1.0. The three
page-0 pictures are 3.0 to 9.5 tall; the six front-buffer ones run 5.0 to 60.0.
Height alone separates the two families, and the page selection says the same
thing independently.

Nine distinct `canonical_md5`s.

| constant | proposed name | confidence | evidence |
| --- | --- | --- | --- |
| CINEMATIC_137 | CINEMATIC_PRISON_BLAST_MARK | medium | 22.0x9.5, four paths: two dark strokes crossing, low at the anchor. Drawn to **page 0 before the sound plays** and before any other frame, so it is what the room gets first and keeps. `MARK` is the shape and the placement; it does not say what made it |
| CINEMATIC_138 | CINEMATIC_PRISON_BLAST_DEBRIS_F0 | high | 41.0x60.0, 38 paths: a cloud of small bright and dark fragments, the tallest of the six and the first after `play id=0x005A` at vol 0x40 |
| CINEMATIC_139 | CINEMATIC_PRISON_BLAST_DEBRIS_F1 | high | 48.0x60.0, 34 paths: seven wider, same height |
| CINEMATIC_140 | CINEMATIC_PRISON_BLAST_DEBRIS_F2 | high | 59.0x56.5, 29 paths: widest of the cloud frames, and falling -- top edge up from -65.5 to -55.5 |
| CINEMATIC_142 | CINEMATIC_PRISON_BLAST_DEBRIS_F3 | high | 53.0x54.0, **14 paths**: less than half of F0's pieces are still in the air |
| CINEMATIC_143 | CINEMATIC_PRISON_BLAST_DEBRIS_F4 | high | 49.0x57.0, 20 paths, gathered into a knot near the ground |
| CINEMATIC_144 | CINEMATIC_PRISON_BLAST_DEBRIS_F5 | high | 50.0x**5.0**, 15 paths, y[-4.5, 0.5]: flat on the floor. The last frame drawn to the front buffer, and the end of the motion |
| CINEMATIC_141 | CINEMATIC_PRISON_BLAST_DEBRIS_SETTLED_0 | high | 63.0x**3.5**, 9 paths, y[-2.5, 1.0]. Drawn to page 0 in the same frame as F2, so it is not a step of the animation -- it is the first band of fragments the floor keeps while the rest are still in the air. The widest of the three page-0 pictures |
| CINEMATIC_145 | CINEMATIC_PRISON_BLAST_DEBRIS_SETTLED_1 | high | 25.0x**3.0**, 7 paths. Drawn to page 0 in the same frame as F5, the last thing the routine does before `killChannel` |

## Two things this batch does not do

**146, 147 and 148 are left numbered.** They sit after the `killChannel` that
ends this routine, and `LABEL_103E`, the only label among them, is reached by
nothing but its own `jmp`. They are unreachable bytes and **#0126** forbids a
role name on them.

**One fragment is not a fragment.** F0 through F3 each contain a single dark
tapered shape, much larger than the specks around it, that falls with them. No
name here claims what it is.
