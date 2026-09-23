# PRISON: a figure lifting a bar, and one crouched over something

`DRAW_CIN_406_408_BLOCK` plays at `[BUDDY_X],[BUDDY_Y]` -- an actor slot, so
per **#0138** these names come from the art:

```
	406  break  407  break  408  break  409  break
	409  break  408  break  409
	<410 to page 0, at 160,100>
	break  411
LABEL_18FA:
	break  412 ... 411 ... 409 ... 408 ... <413 at 160,36> ... 407
```

Six distinct pictures, indexed by **order of first appearance in the
routine** -- the convention `../placeholder-census/ --frames` reproduces 159
times out of 159 for a complete family drawn by one routine. The repeats
(409, 408, 409 again, and the whole descending tail after `LABEL_18FA`) are
the animation playing back and forth, not more frames.

## What the frames show, and what the extents say

```
        extent      paths   top edge
  406  42.0x47.0     11      -46.0
  407  49.5x39.0     11      -38.0
  408  52.5x39.5     12      -37.0
  409  52.5x40.5     12      -38.0
  411  47.5x46.0     12      -45.0
  412  40.0x46.0     12      -45.0
```

The top edge drops from -46.0 to -37.0 and comes back to -45.0: the figure
bends and straightens. The width does the opposite, 42.0 out to 52.5 and back
to 40.0, which is a reach.

Rendered, F0 and F1 are a figure bending forward with nothing in front of it.
From F2 a thin purple quadrilateral lies **flat on the ground** at its feet;
by F4 the same shape is **diagonal** and by F5 **steeper still**, while the
figure straightens. Four frames, one object, going from horizontal to raised.

| constant | proposed name | confidence | evidence |
| --- | --- | --- | --- |
| CINEMATIC_406 | CINEMATIC_PRISON_FIGURE_LIFTING_BAR_F0 | medium | 42.0x47.0, 11 paths, top edge -46.0: a figure bending forward, arms down, nothing in front of it yet. First appearance in the routine |
| CINEMATIC_407 | CINEMATIC_PRISON_FIGURE_LIFTING_BAR_F1 | medium | 49.5x39.0, 11 paths, top -38.0: bent further and reaching, 7.5 wider than F0 |
| CINEMATIC_408 | CINEMATIC_PRISON_FIGURE_LIFTING_BAR_F2 | medium | 52.5x39.5, 12 paths, top -37.0, the lowest the head goes. The twelfth path is a thin purple quadrilateral lying **flat** at the figure's feet, and it is the frame the object first appears in |
| CINEMATIC_409 | CINEMATIC_PRISON_FIGURE_LIFTING_BAR_F3 | medium | 52.5x40.5, 12 paths, top -38.0: the same pose with the bar still flat. Drawn three times by this routine, more than any other frame |
| CINEMATIC_411 | CINEMATIC_PRISON_FIGURE_LIFTING_BAR_F4 | medium | 47.5x46.0, 12 paths, top back up to -45.0: the figure straightening, and the bar now **diagonal** rather than flat |
| CINEMATIC_412 | CINEMATIC_PRISON_FIGURE_LIFTING_BAR_F5 | medium | 40.0x46.0, 12 paths, top -45.0 and the narrowest of the six: upright, the bar steeper again |
| CINEMATIC_426 | CINEMATIC_PRISON_FIGURE_CROUCHED_F0 | medium | 56.0x39.0, **21 paths** -- nearly twice any frame above -- a figure crouched low over a round orange shape and a grey angular one at its lower left. A different pose set from the lifting run, and the only PRISON frames at this slot with an orange mass in them |
| CINEMATIC_427 | CINEMATIC_PRISON_FIGURE_CROUCHED_F1 | medium | 58.0x39.0, 22 paths: the same crouch, one path more, drawn twice where F0 is drawn once |

## What these names do not claim

`BAR` is a thin purple quadrilateral that is flat on the ground in F2 and F3
and raised in F4 and F5. That is its shape and its motion. Nothing here says
what it is made of or what it is for.

`CROUCHED` is the pose. The round orange mass and the grey angular shape under
the figure in F0 and F1 are **not named**: at 56x39 with 21 paths the picture
does not settle what they are, and the slot is an actor slot, so the scene
cannot answer it either.

`CINEMATIC_410`, the 16.5x157.5 column this routine paints into page 0 at
160,100, is **left numbered**. It runs 49 pixels off the bottom of the screen
and nothing in it resolves.
