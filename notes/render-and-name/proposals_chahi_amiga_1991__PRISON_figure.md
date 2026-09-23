# PRISON: the figure that comes into focus, read from a render at palette 7

The scene the eye closeup hands off to. `LABEL_4CDD`, which drives `[0x15]`
and `[0x16]` for the closeup, ends with

```
	deleteChannels first=0x01, last=0x03
	setup channel=0x01, address=SET_PAL_07_FILL_TWO_PAGES_86243111
	setup channel=0x02, address=LABEL_4F23
```

so this is the same beat, one shot later: what the eyes that just opened see.

## Fifteen constants, five pictures

`canonical_md5` says the three copies of each shape are **byte-identical**:

```
  (172,110)  637 641 645   IDENTICAL   92b1ee04
  (183,40)   638 642 646   IDENTICAL   2d66cda0
  (88,146)   639 643 647   IDENTICAL   714132b8
  (289,147)  640 644 648   IDENTICAL   942be322
  (272,133)  649 650       IDENTICAL   b340f3de
```

They are not frames. All fifteen are drawn in **one** pass of `LABEL_4F23`,
each with `zoom=[0x14]`, and `[0x14]` is recomputed between them:

```
	mov [0x14], 0x0042 ; +[0x15] x3   -> 637      then -[0x15]  -> 638,639,640
	mov [0x14], 0x0040 ; +[0x15] x2   -> 641      then -[0x15]  -> 642,643,644
	mov [0x14], 0x0040 ; -[0x15]      -> 645,646,647,648
	mov [0x14], 0x0040 ; +[0x15]      -> 649      then -[0x15] x5 -> 650
```

So the index is the **zoom pass**, in draw order, which is descending scale.
At `[0x15] = 0` every pass lands on 0x40 or 0x42 and the copies coincide: one
sharp figure. At `[0x15] = 5` they spread to 1.27, 1.19, 1.16, 1.08 and 0.92
of full size: one smeared figure. `[0x15]` is the blur.

And the `jne [0x15], N` ladder at the end of the routine draws the facial
detail, most at `[0x15] = 0` and none at `[0x15] >= 5`:

```
  == 0  CINEMATIC_655   77.5x178.0  19 paths
  == 1  CINEMATIC_654   77.5x177.5  24 paths
  == 2  CINEMATIC_653   72.5x176.5  10 paths
  == 3  CINEMATIC_652   69.5x130.5   7 paths
  == 4  CINEMATIC_651   36.0x  4.0   2 paths
  >= 5  nothing
```

`SET_PAL_07_FILL_TWO_PAGES_86243111` seeds `[0x15]` to 5 and walks it
5 -> 2 -> 6 -> 0. The blur and the detail move together, in that order:
**the picture resolves.**

| constant | proposed name | confidence | evidence |
| --- | --- | --- | --- |
| CINEMATIC_638 | CINEMATIC_PRISON_WAKE_FIGURE_HEAD_0 | high | 101x76, one path: a head seen from below -- a rounded crown with a highlight, a heavy brow, and the sockets the detail ladder fills in. Zoom pass 0 of 3, the largest scale, drawn first |
| CINEMATIC_642 | CINEMATIC_PRISON_WAKE_FIGURE_HEAD_1 | high | byte-identical to `_0` (`canonical_md5` 2d66cda0); zoom pass 1 of 3 |
| CINEMATIC_646 | CINEMATIC_PRISON_WAKE_FIGURE_HEAD_2 | high | byte-identical to `_0`; zoom pass 2 of 3, the smallest scale |
| CINEMATIC_655 | CINEMATIC_PRISON_WAKE_FIGURE_FACE_DETAIL_0 | high | 19 paths over the head: two eyes with lids, nostrils, a mouth line, cheek shading. `jne [0x15], 0x00` -- drawn only when the blur is fully closed, which is the sharpest the scene ever gets |
| CINEMATIC_654 | CINEMATIC_PRISON_WAKE_FIGURE_FACE_DETAIL_1 | high | 24 paths, `[0x15] == 1`. The path count is not monotonic across this family and the name does not claim it is; what is monotonic is the `[0x15]` rung, which is what the index is |
| CINEMATIC_653 | CINEMATIC_PRISON_WAKE_FIGURE_FACE_DETAIL_2 | high | 10 paths, `[0x15] == 2` |
| CINEMATIC_652 | CINEMATIC_PRISON_WAKE_FIGURE_FACE_DETAIL_3 | high | 7 paths and 130 tall against the others' 176, `[0x15] == 3`: the lower face is gone and only the upper marks survive |
| CINEMATIC_651 | CINEMATIC_PRISON_WAKE_FIGURE_FACE_DETAIL_4 | high | **2 paths, 36x4** -- two specks where the eyes are and nothing else, `[0x15] == 4`. The last thing to disappear as the blur opens, and the first to appear as it closes |
| CINEMATIC_637 | CINEMATIC_PRISON_WAKE_FIGURE_NECK_0 | medium | 54x65, one path: a wide horizontal bar at the top narrowing to a column that runs 65 down, drawn directly below the head. Read as the jaw underside and the throat, in the same from-below perspective as the head. Zoom pass 0 of 3 |
| CINEMATIC_641 | CINEMATIC_PRISON_WAKE_FIGURE_NECK_1 | medium | byte-identical to `_0` (92b1ee04); zoom pass 1 of 3 |
| CINEMATIC_645 | CINEMATIC_PRISON_WAKE_FIGURE_NECK_2 | medium | byte-identical to `_0`; zoom pass 2 of 3 |
| CINEMATIC_639 | CINEMATIC_PRISON_WAKE_FIGURE_ARM_LEFT_0 | medium | 45x110, one path: a tall column with a single bend, bowed outward, at the left edge of the frame. The bend is what makes it a limb rather than a post. Zoom pass 0 of 3 |
| CINEMATIC_643 | CINEMATIC_PRISON_WAKE_FIGURE_ARM_LEFT_1 | medium | byte-identical to `_0` (714132b8); zoom pass 1 of 3 |
| CINEMATIC_647 | CINEMATIC_PRISON_WAKE_FIGURE_ARM_LEFT_2 | medium | byte-identical to `_0`; zoom pass 2 of 3 |
| CINEMATIC_640 | CINEMATIC_PRISON_WAKE_FIGURE_ARM_RIGHT_0 | medium | 56x109, one path: a wider mass at the right edge, a rounded top narrowing at the middle and squaring off below -- shoulder into upper arm. Zoom pass 0 of 3 |
| CINEMATIC_644 | CINEMATIC_PRISON_WAKE_FIGURE_ARM_RIGHT_1 | medium | byte-identical to `_0` (942be322); zoom pass 1 of 3 |
| CINEMATIC_648 | CINEMATIC_PRISON_WAKE_FIGURE_ARM_RIGHT_2 | medium | byte-identical to `_0`; zoom pass 2 of 3 |
| CINEMATIC_649 | CINEMATIC_PRISON_WAKE_FIGURE_ARM_RIGHT_EDGE_0 | medium | 24x49, one path: a thin curved wedge, pale, drawn over the narrow part of `ARM_RIGHT` -- the lit edge where the mass turns. Zoom pass 0 of 2 |
| CINEMATIC_650 | CINEMATIC_PRISON_WAKE_FIGURE_ARM_RIGHT_EDGE_1 | medium | byte-identical to `_0` (b340f3de); zoom pass 1 of 2, and the one whose zoom runs away fastest -- `0x40 - 5*[0x15]`, the widest spread in the scene |

## What these names do not claim

**`LEFT` and `RIGHT` are sides of the frame, not of the figure.** `ARM_LEFT`
is drawn at x=88 and `ARM_RIGHT` at x=289. The figure faces the camera, so if
it is a person these are its right and left arms respectively. The names
follow the frame because that is what the pictures show.

**`NECK` and the two `ARM`s are `medium`.** Each is a single untextured path
and the reading comes from its outline and its position under a head, not
from anything inside it. `HEAD` and the five `FACE_DETAIL` frames are `high`
because they carry eyes, a mouth and nostrils.

**The index is a zoom pass, not a frame.** Three byte-identical copies exist
so that one pass of the routine can draw the same shape at three scales; there
is no animation in the family and the name asserts none. The order is draw
order, which is also descending scale.
