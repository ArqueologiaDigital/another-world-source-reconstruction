# PRISON: a cloaked figure in nineteen frames, and a person seen from behind

`PRISON_FILL_AND_DRAW_CIN_24_28_L0` is installed on channel 0x23 by two
different `setup`s. It draws twenty-eight pictures at `[BUDDY_X],[BUDDY_Y]`,
one or two per `break` -- an actor slot, so per **#0138** these names come
from the art.

The run splits in two, and the split is visible in the path counts alone.

## 596 to 614: one to five paths each

```
  596  21.0x61.0  1 path      606  28.5x49.5  4 paths
  601  28.0x59.0  3 paths     611  34.5x60.0  4 paths
```

Nineteen frames of a human-proportioned mass carrying no interior detail at
all: a single dark fill, one to five paths, about 60 tall throughout. No limb
and no feature resolves until **F15**, where a pale head with an orange mark
appears and then stays.

The bottom edge is the measurement that moves. It sits on y +0.5 for the first
four frames, lifts to **y -11.0** by F10 while the top stays at y -60, and is
back on the floor from F12. A shape that shortens from below while its top
holds still is a hem coming off the ground.

## 615 to 623: pairs, and the odd one is drawn first

```
	video offset=CINEMATIC_615      1 path,  17.0x25.0
	video offset=CINEMATIC_616     13 paths, 33.0x59.0
	break
	video offset=CINEMATIC_617      1 path,  13.0x28.0
	video offset=CINEMATIC_618     13 paths, 33.0x59.0
	...
```

The four even ones share **identical extents**, 33.0x59.0 and y[-58.0, 1.0],
and four distinct `canonical_md5`s: one figure in four poses. Rendered, it is
a person seen from behind -- dark tunic, bare arms and legs, boots.

The five odd ones are **one path each**, 6 to 17 wide, at the figure's
screen-left side, and each is drawn *before* its body, so it is behind the
torso. Rendered alone they are one limb in five positions, swung out at F0 and
hanging straight by F4.

The last pair reuses `CINEMATIC_622`, so the body cycle has four members and
the arm five. The two families are indexed separately for that reason.

| constant | proposed name | confidence | evidence |
| --- | --- | --- | --- |
| CINEMATIC_596 | CINEMATIC_PRISON_CLOAKED_FIGURE_F0 | medium | 21.0x61.0, 1 path(s), bottom edge y +0.5. **One path**: the whole figure is a single filled outline |
| CINEMATIC_597 | CINEMATIC_PRISON_CLOAKED_FIGURE_F1 | medium | 26.5x61.0, 2 path(s), bottom edge y +0.5 |
| CINEMATIC_598 | CINEMATIC_PRISON_CLOAKED_FIGURE_F2 | medium | 26.0x61.0, 2 path(s), bottom edge y +0.5 |
| CINEMATIC_599 | CINEMATIC_PRISON_CLOAKED_FIGURE_F3 | medium | 25.0x61.0, 2 path(s), bottom edge y +0.5 |
| CINEMATIC_600 | CINEMATIC_PRISON_CLOAKED_FIGURE_F4 | medium | 26.0x60.0, 3 path(s), bottom edge y +0.0 |
| CINEMATIC_601 | CINEMATIC_PRISON_CLOAKED_FIGURE_F5 | medium | 28.0x59.0, 3 path(s), bottom edge y -1.5 |
| CINEMATIC_602 | CINEMATIC_PRISON_CLOAKED_FIGURE_F6 | medium | 23.0x56.0, 2 path(s), bottom edge y -4.0 |
| CINEMATIC_603 | CINEMATIC_PRISON_CLOAKED_FIGURE_F7 | medium | 25.0x53.5, 3 path(s), bottom edge y -7.0 |
| CINEMATIC_604 | CINEMATIC_PRISON_CLOAKED_FIGURE_F8 | medium | 26.5x51.5, 4 path(s), bottom edge y -9.0 |
| CINEMATIC_605 | CINEMATIC_PRISON_CLOAKED_FIGURE_F9 | medium | 26.5x50.5, 4 path(s), bottom edge y -10.0 |
| CINEMATIC_606 | CINEMATIC_PRISON_CLOAKED_FIGURE_F10 | medium | 28.5x49.5, 4 path(s), bottom edge y -11.0. The bottom edge is at **y -11.0**, its highest: the garment's hem is clear of the floor here, and from F12 on it is back on it |
| CINEMATIC_607 | CINEMATIC_PRISON_CLOAKED_FIGURE_F11 | medium | 24.0x49.0, 2 path(s), bottom edge y -10.0 |
| CINEMATIC_608 | CINEMATIC_PRISON_CLOAKED_FIGURE_F12 | medium | 24.0x59.0, 2 path(s), bottom edge y -0.5 |
| CINEMATIC_609 | CINEMATIC_PRISON_CLOAKED_FIGURE_F13 | medium | 24.0x59.0, 2 path(s), bottom edge y -0.5 |
| CINEMATIC_610 | CINEMATIC_PRISON_CLOAKED_FIGURE_F14 | medium | 24.0x58.0, 2 path(s), bottom edge y -0.5 |
| CINEMATIC_611 | CINEMATIC_PRISON_CLOAKED_FIGURE_F15 | medium | 34.5x60.0, 4 path(s), bottom edge y +0.0. A pale head with an orange mark appears at the top for the first time and stays for the rest of the run |
| CINEMATIC_612 | CINEMATIC_PRISON_CLOAKED_FIGURE_F16 | medium | 32.5x55.0, 5 path(s), bottom edge y -0.5 |
| CINEMATIC_613 | CINEMATIC_PRISON_CLOAKED_FIGURE_F17 | medium | 32.5x52.5, 4 path(s), bottom edge y +0.0 |
| CINEMATIC_614 | CINEMATIC_PRISON_CLOAKED_FIGURE_F18 | medium | 25.5x51.0, 4 path(s), bottom edge y -0.5 |
| CINEMATIC_616 | CINEMATIC_PRISON_STANDING_FIGURE_F0 | high | 33.0x59.0, 13 paths, y[-58.0, 1.0] -- identical extents to the other three and a distinct `canonical_md5`. A person seen from behind: dark tunic, bare arms and legs, boots on the ground, pale head. Drawn second of its pair, over the arm |
| CINEMATIC_618 | CINEMATIC_PRISON_STANDING_FIGURE_F1 | high | 33.0x59.0, 13 paths, y[-58.0, 1.0] -- identical extents to the other three and a distinct `canonical_md5`. A person seen from behind: dark tunic, bare arms and legs, boots on the ground, pale head. Drawn second of its pair, over the arm |
| CINEMATIC_620 | CINEMATIC_PRISON_STANDING_FIGURE_F2 | high | 33.0x59.0, 13 paths, y[-58.0, 1.0] -- identical extents to the other three and a distinct `canonical_md5`. A person seen from behind: dark tunic, bare arms and legs, boots on the ground, pale head. Drawn second of its pair, over the arm |
| CINEMATIC_622 | CINEMATIC_PRISON_STANDING_FIGURE_F3 | high | 33.0x59.0, 13 paths, y[-58.0, 1.0] -- identical extents to the other three and a distinct `canonical_md5`. A person seen from behind: dark tunic, bare arms and legs, boots on the ground, pale head. Drawn second of its pair, over the arm |
| CINEMATIC_615 | CINEMATIC_PRISON_STANDING_FIGURE_ARM_F0 | high | 17.0x25.0, **one path**, at the figure's screen-left side. Drawn first of its pair, so it sits behind the torso. The five narrow from 17.0 wide and swung out to 6.0 and hanging straight |
| CINEMATIC_617 | CINEMATIC_PRISON_STANDING_FIGURE_ARM_F1 | high | 13.0x28.0, **one path**, at the figure's screen-left side. Drawn first of its pair, so it sits behind the torso. The five narrow from 17.0 wide and swung out to 6.0 and hanging straight |
| CINEMATIC_619 | CINEMATIC_PRISON_STANDING_FIGURE_ARM_F2 | high | 12.0x27.0, **one path**, at the figure's screen-left side. Drawn first of its pair, so it sits behind the torso. The five narrow from 17.0 wide and swung out to 6.0 and hanging straight |
| CINEMATIC_621 | CINEMATIC_PRISON_STANDING_FIGURE_ARM_F3 | high | 7.0x24.0, **one path**, at the figure's screen-left side. Drawn first of its pair, so it sits behind the torso. The five narrow from 17.0 wide and swung out to 6.0 and hanging straight |
| CINEMATIC_623 | CINEMATIC_PRISON_STANDING_FIGURE_ARM_F4 | high | 6.0x20.0, **one path**, at the figure's screen-left side. Drawn first of its pair, so it sits behind the torso. The five narrow from 17.0 wide and swung out to 6.0 and hanging straight |

## What these names do not claim

`CLOAKED` describes the silhouette that is measured: one to five paths, a
single fill, human proportions, and a hem that leaves the floor and returns.
It does not say what the figure is wearing, or that it is wearing anything.

Neither family says **who**. Both run at the buddy slot and #0138 is why that
is not taken as the answer.

`STANDING_FIGURE_ARM` is one path. That it is an arm rests on its shape, its
place at the figure's side, and its five positions; nothing inside the picture
says so, because there is nothing inside it.
