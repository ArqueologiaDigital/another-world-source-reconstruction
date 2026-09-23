# PRISON: the cage coming down, read from a render at palette 2

Five pictures, one per `break`, drawn at `[0x03],[0x04]` -- an actor slot, so
per **#0138** these names come from the art and not from the scene the
pictures appear in. What the scene contributes is the anchor, and that is a
measurement in its own right:

```
	add [0x04], 0x0020
	play id=0x0063, freq=0x14, vol=0x40, channel=0x01
	video offset=CINEMATIC_080, x=[0x03], y=[0x04]
	break
	add [0x04], 0x0016
	setPalette 0x02
	video offset=CINEMATIC_081, x=[0x03], y=[0x04]
	break
	play id=0x0064, freq=0x14, vol=0x40, channel=0x02
	video offset=CINEMATIC_082, x=[0x03], y=[0x04]
	...
	video offset=CINEMATIC_083, x=[0x03], y=[0x04]
	break
	video offset=CINEMATIC_084, x=[0x1a], y=[0x1b]      ; = [0x03],[0x04]
```

The anchor drops 0x20 then 0x16 and then **stops**. 080 is drawn 32 lower than
what came before, 081 another 22 lower, and 082, 083 and 084 are all at 081's
height. Two impacts are played at full volume, one before 080 and one before
082.

## What the pictures show

Rendered at the palette this routine itself sets, all five are a barred cage,
and the arc is the anchor's:

* **080** a cage tilted, two figures inside, a third below it reaching up.
  Its extent reaches y +61.0 -- 18 lower than any of the others.
* **081** the cage lower and tilted further, shapes beneath it.
* **082** the cage upright and level, resting on a mass beneath.
* **083** the same, with a bar sprung loose and curving away to the right,
  which is why this frame is 96.0 wide against the others' 69 to 74.
* **084** upright, settled.

```
  080  69.5x90.0  38 paths  y[-29.0, 61.0]
  081  69.0x75.0  48 paths  y[-32.0, 43.0]
  082  69.5x70.0  34 paths  y[-27.0, 43.0]
  083  96.0x80.5  50 paths  y[-37.5, 43.0]
  084  74.0x70.0  47 paths  y[-27.0, 43.0]
```

Five distinct `canonical_md5`s. From 081 on, every bottom edge is y +43.0
exactly -- the cage has reached its floor and stays on it.

`CINEMATIC_082` has a **second draw site**: `LABEL_8155` paints it at the
literal 181,146 on the screen-repaint path, which is the cage standing in the
room afterwards. That is independent of this routine and it agrees: 082 is the
frame where the cage is down.

| constant | proposed name | confidence | evidence |
| --- | --- | --- | --- |
| CINEMATIC_080 | CINEMATIC_PRISON_CAGE_LANDING_F0 | high | 69.5x90.0, 38 paths: a barred cage tilted, figures inside, another figure below it. Drawn first, 0x20 lower than the frame before, with an impact played at vol 0x40. Its extent reaches y +61.0, the lowest of the five, because of the figure beneath |
| CINEMATIC_081 | CINEMATIC_PRISON_CAGE_LANDING_F1 | high | 69.0x75.0, 48 paths: the cage lower and tilted further. Drawn 0x16 lower again, and the last frame the anchor moves for |
| CINEMATIC_082 | CINEMATIC_PRISON_CAGE_LANDING_F2 | high | 69.5x70.0, 34 paths: the cage upright and level on the mass beneath it, and the second impact plays just before. Also drawn once at the literal 181,146 by `LABEL_8155` on the screen-repaint path, which is this cage at rest in the room -- an independent site that agrees this is the landed frame |
| CINEMATIC_083 | CINEMATIC_PRISON_CAGE_LANDING_F3 | high | **96.0** wide against the others' 69 to 74, and the extra 26 is a single curved bar sprung loose and thrown to the right. 50 paths, the most of the five. Bottom edge still y +43.0 |
| CINEMATIC_084 | CINEMATIC_PRISON_CAGE_LANDING_F4 | high | 74.0x70.0, 47 paths: upright and settled, bottom edge y +43.0. Drawn at `[0x1a],[0x1b]`, which the two lines above set from `[0x03],[0x04]` -- the same place |

## What these names do not claim

Every frame contains figures, inside the cage and beneath it, and none of
these names identifies any of them. `CAGE` is what the bars in all five
pictures support; `LANDING` is the anchor dropping 0x20 then 0x16 and then
holding, plus the two impacts, plus the bottom edge settling at y +43.0 from
F1 on.
