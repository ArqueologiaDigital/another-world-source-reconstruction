# PRISON -- the actor charge glow, read from a render

Numbered densely from 0 in ascending routine-frame order, because
`PRISON_ACTOR_CHARGE_GLOW_FRAME_02` **does not exist** -- the gap is in the
routine family, and copying it into the art family would be an interior hole
that `docs/NAMING.md` §2 bars. The mapping is
`FRAME_01,03,04,05,06,07,08 -> F0..F6`.

| constant | proposed name | confidence | evidence |
| --- | --- | --- | --- |
| CINEMATIC_203 | CINEMATIC_PRISON_ACTOR_CHARGE_GLOW_F0 | medium | rendered in frame order the seven are a small, vertically symmetric blob that **grows monotonically**: 5x6, 6x8, 12x8, 12x12, 12x14, then 12x12 and 12x14 again, every one of them two paths. Growth then alternation is what a charge and its flicker look like, and it is what orders the family. Each is the sole picture of one `PRISON_ACTOR_CHARGE_GLOW_FRAME_<n>` routine; seven separately written names agree on the subject. The word `GLOW` is supported by the shape, `CHARGE` comes from those routines |
| CINEMATIC_190 | CINEMATIC_PRISON_ACTOR_CHARGE_GLOW_F1 | medium | 6x8, sole picture of `PRISON_ACTOR_CHARGE_GLOW_FRAME_03` |
| CINEMATIC_191 | CINEMATIC_PRISON_ACTOR_CHARGE_GLOW_F2 | medium | 12x8, sole picture of `PRISON_ACTOR_CHARGE_GLOW_FRAME_04` |
| CINEMATIC_192 | CINEMATIC_PRISON_ACTOR_CHARGE_GLOW_F3 | medium | 12x12, sole picture of `PRISON_ACTOR_CHARGE_GLOW_FRAME_05` |
| CINEMATIC_193 | CINEMATIC_PRISON_ACTOR_CHARGE_GLOW_F4 | medium | 12x14, sole picture of `PRISON_ACTOR_CHARGE_GLOW_FRAME_06` |
| CINEMATIC_194 | CINEMATIC_PRISON_ACTOR_CHARGE_GLOW_F5 | medium | 12x12, sole picture of `PRISON_ACTOR_CHARGE_GLOW_FRAME_07` |
| CINEMATIC_195 | CINEMATIC_PRISON_ACTOR_CHARGE_GLOW_F6 | medium | 12x14, sole picture of `PRISON_ACTOR_CHARGE_GLOW_FRAME_08` |
# PRISON batch -- the cell scene, read from a render

| constant | proposed name | confidence | evidence |
| --- | --- | --- | --- |
| CINEMATIC_634 | CINEMATIC_PRISON_PRISONER_BEHIND_BARS | high | 278x360, 49 paths: a human figure in profile -- rounded head with hair, neck, sloping shoulders, a bent arm -- seen through **five vertical bars** that run the full height. The clearest silhouette in this stage, and the only one here that resolves as a person rather than a mass. Drawn by `LABEL_4EE9` at `x=[0x14], y=100`, twenty times under a `djnz [0x15]` seeded to 0x14, alongside CINEMATIC_635 and CINEMATIC_636 at a second variable x -- a panning shot across a row of cells |
| CINEMATIC_636 | CINEMATIC_PRISON_CELL_BARS | high | 158x205, **three paths**: three tall vertical bars and nothing else. The path count and the extent say the same thing the picture does. Drawn by `LABEL_4EE9` at `x=[0x17], y=100`, the second of the two anchors that routine pans, and it is the bar layer for that cell as CINEMATIC_634 carries its own |
# PRISON: the buddy typing, read from a render

`BUDDY_HACK_SECOND_TYPING_LOOP` draws one right arm and one left arm over a
body base on each `break`, five frames in all, at `[BUDDY_X],[BUDDY_Y]` --
the actor slot, so per **#0138** these names come from the art and not from
the scene the pictures appear in.

The signed bounding box separates the two arms without reference to draw
order: four span positive x, four negative, and all four left arms share the
same left edge at **-17.5** -- one shoulder with the forearm at four angles.
Indices are order of first appearance in that routine, the convention
`../placeholder-census/ --frames` reproduces 159 times out of 159 for a
complete family drawn by one routine.

| constant | proposed name | confidence | evidence |
| --- | --- | --- | --- |
| CINEMATIC_393 | CINEMATIC_PRISON_BUDDY_FIGURE_BASE | high | 22x29, one path: a torso, wider at the shoulders and hips than at the waist. It is the sole picture of `DRAW_BUDDY_FIGURE_BASE`, which the typing loop `call`s once per frame after laying both arms down, so it is the body the arms are composited onto |
| CINEMATIC_391 | CINEMATIC_PRISON_BUDDY_TYPING_ARM_RIGHT_F0 | high | 6x25, one path, spans x +3.0..+9.0 -- right of the anchor. First right arm drawn in the loop |
| CINEMATIC_394 | CINEMATIC_PRISON_BUDDY_TYPING_ARM_RIGHT_F1 | high | 8x22, one path, spans +2.0..+10.0. Second right arm |
| CINEMATIC_395 | CINEMATIC_PRISON_BUDDY_TYPING_ARM_RIGHT_F2 | high | 6x16, one path, spans +4.0..+10.0. Third right arm |
| CINEMATIC_397 | CINEMATIC_PRISON_BUDDY_TYPING_ARM_RIGHT_F3 | high | 7x16, one path, spans +2.5..+9.5. Fourth right arm, and the one held for the last two frames |
| CINEMATIC_392 | CINEMATIC_PRISON_BUDDY_TYPING_ARM_LEFT_F0 | high | 9x25, one path, spans -17.5..-8.5 -- left of the anchor, sharing the -17.5 shoulder edge with the other three. First left arm, held across the first two frames |
| CINEMATIC_396 | CINEMATIC_PRISON_BUDDY_TYPING_ARM_LEFT_F1 | high | 13x21, one path, spans -17.5..-4.5. Second left arm, the one reaching furthest in |
| CINEMATIC_398 | CINEMATIC_PRISON_BUDDY_TYPING_ARM_LEFT_F2 | high | 7x17, one path, spans -17.5..-10.5. Third left arm |
| CINEMATIC_399 | CINEMATIC_PRISON_BUDDY_TYPING_ARM_LEFT_F3 | high | 9x14, one path, spans -17.5..-8.5. Fourth left arm |
# PRISON: the eye opening, read from a render at the scene's own palette

`DRAW_CIN_683_TO_685_3F_AT_1EB7324B` does `setPalette 0x0B`, paints three
pictures at 160,100, copies the page and then hands off to `LABEL_4D31`,
which redraws four layers on every `break`:

```
  video offset=CINEMATIC_656, x=[0x1a], y=[0x1b]     the plate
  <ladder on [0x16], 7 ways>                          the pupil
  video offset=CINEMATIC_658, x=[0x1a], y=[0x1b]     the glint
  <ladder on [0x15], 18 ways>   at x=160, y=100       the lid
```

`[0x1A]` and `[0x1B]` are set once, to 0x00A0 and 0x0064 -- 160 and 100. The
whole closeup is static; the two variables are constants the shared draw path
reads.

**These are ladders, not frame sequences.** Neither picture list is played in
order: `[0x15]` is seeded to 0 and then moved up and down (`add [0x15],
0x0002` five times, `sub [0x15], 0x0001` ten times, `add [0x15], 0x0004`,
`sub [0x15], 0x0008` ...) -- the eye flutters. So the index is the **ladder
step**, ascending in the selector variable, which is also the order the
pictures sit at in the bank. Both families start at the state the scene starts
in: lid down, pupil small.

## Why the extents lied and the paths did not

Every picture here is two paths, one per eye, ~165px apart, so the union
bounding box spans the gap and reports nonsense. `CINEMATIC_658` measures
170x7 and is in fact **two 5x5 squares**. The numbers below are per path.

## The pupil ladder -- and a renumber

Measured per eye, left eye, in ladder order:

```
  [0x16] <=1   682       6 x  7   at x[80.0,86.0] y[114.5,121.5]
  [0x16] <=2   PUPIL_0   8 x  9   at x[79.0,87.0] y[113.5,122.5]
  [0x16] <=3   680      10 x 11   at x[78.0,88.0] y[112.5,123.5]
  [0x16] <=4   679      12 x 13   at x[77.0,89.0] y[111.5,124.5]
  [0x16] <=5   678      14 x 15   at x[76.0,90.0] y[110.5,125.5]
  [0x16] <=6   PUPIL_1  16 x 17   at x[75.0,91.0] y[109.5,126.5]
  else         PUPIL_2  18 x 19   at x[74.0,92.0] y[108.5,127.5]
```

Width +2 and height +2 at every step, all seven concentric on (83, 118). Bank
offsets 0x3B62, 6E, 7A, 86, 92, 9E are a **12-byte stride run in ladder
order**; only the first rung, 0x3A92, sits outside it.

The three names already in the tree are rungs **2, 6 and 7 of seven** but are
numbered 0, 1 and 2. That is a family whose index run does not match the
ladder it indexes, and filling the four holes cannot leave it standing.
`docs/NAMING.md` §2 forbids the gap either way, so this batch renumbers the
whole family 0..6 in one simultaneous pass -- the case
`apply_cinematic_renames.py`'s `collides()` docstring describes.

## The lid ladder

Every one of the eighteen has its top edge at y=92.0 and its bottom edge
exactly 2.0 lower than its successor:

```
  _0  bottom 134.0   ...   _12 bottom 110.0   _17 bottom 100.0
```

The eye occupies y 108.5..127.5. At `_0` the lid reaches 134.0, past the
bottom of the eye -- covered. At `_17` it stops at 100.0, above the top of the
eye -- clear. It first touches the eye between `_13` (108.0) and `_12`
(110.0). The lid also widens as it descends (its inner edge runs x 31.0 down
to -3.0), which is what a lid on a curved eyeball does.

| constant | proposed name | confidence | evidence |
| --- | --- | --- | --- |
| CINEMATIC_683 | CINEMATIC_PRISON_WAKE_CLOSEUP_FACE_HALF_0 | high | 176x212, 8 paths: the screen-left half of the closeup -- brow, the socket around the left eye, cheek, and a red band above. `HALF` is a composition word, not a facing direction: 683 occupies x 0..150 and 684 x 150..320, and the two together are one face. Drawn once, by `DRAW_CIN_683_TO_685_3F_AT_1EB7324B`, into the page that is then copied and held |
| CINEMATIC_684 | CINEMATIC_PRISON_WAKE_CLOSEUP_FACE_HALF_1 | high | 198x210, 6 paths: the screen-right half -- the nose bridge (a thin vertical spike at x~150), the right socket, cheek. Second of the same three draws |
| CINEMATIC_685 | CINEMATIC_PRISON_WAKE_CLOSEUP_IRIS_STRIATIONS | high | 202x34 but **56 paths**: two discs of radial spokes, one centred in each socket, and nothing else. The path count is the evidence -- 56 narrow wedges is how this engine draws a striated iris, and they land exactly where the pupil plate is laid down next. Third of the same three draws, so the irises are painted into the held backdrop while everything above animates |
| CINEMATIC_656 | CINEMATIC_PRISON_WAKE_CLOSEUP_PUPIL_BASE | high | 22x19 per eye at x[72,94] y[108.5,127.5]: a flat hexagon laid over the centre of each striated iris, redrawn first on every frame. Its **y extent is exactly the widest pupil's** (108.5..127.5), so the pupil dilates to fill it and never past it. It is the plate the pupil is composited onto, the same relation `CINEMATIC_PRISON_BUDDY_FIGURE_BASE` names. No index: one picture, not a family |
| CINEMATIC_658 | CINEMATIC_PRISON_WAKE_CLOSEUP_EYE_GLINT | high | two 5x5 squares, one per eye, at the upper-right of the pupil plate (x[89.5,94.5] y[109.5,114.5] and x[254.5,259.5] y[111.5,116.5]), pale against the dark plate, drawn last of the three eye layers so it sits on top of the pupil at every dilation. A small bright square at a fixed spot on a dark eye is a specular highlight |
| CINEMATIC_682 | CINEMATIC_PRISON_WAKE_CLOSEUP_PUPIL_0 | high | 6x7 per eye, the ladder's first rung, `[0x16] <= 1`. The smallest of the seven and the only one outside the 12-byte stride run |
| CINEMATIC_PRISON_WAKE_CLOSEUP_PUPIL_0 | CINEMATIC_PRISON_WAKE_CLOSEUP_PUPIL_1 | high | **renumber**, not a new name: 8x9, rung 2 of 7. Was numbered 0 when only three of the seven were known |
| CINEMATIC_680 | CINEMATIC_PRISON_WAKE_CLOSEUP_PUPIL_2 | high | 10x11, rung 3 of 7, bank 0x3B6E |
| CINEMATIC_679 | CINEMATIC_PRISON_WAKE_CLOSEUP_PUPIL_3 | high | 12x13, rung 4 of 7, bank 0x3B7A |
| CINEMATIC_678 | CINEMATIC_PRISON_WAKE_CLOSEUP_PUPIL_4 | high | 14x15, rung 5 of 7, bank 0x3B86 |
| CINEMATIC_PRISON_WAKE_CLOSEUP_PUPIL_1 | CINEMATIC_PRISON_WAKE_CLOSEUP_PUPIL_5 | high | **renumber**: 16x17, rung 6 of 7 |
| CINEMATIC_PRISON_WAKE_CLOSEUP_PUPIL_2 | CINEMATIC_PRISON_WAKE_CLOSEUP_PUPIL_6 | high | **renumber**: 18x19, rung 7 of 7, widest, exactly filling the plate's height |
| CINEMATIC_676 | CINEMATIC_PRISON_WAKE_CLOSEUP_EYELID_0 | high | lid bottom 134.0, below the eye's own bottom at 127.5 -- fully closed, and the state `mov [0x15], 0x0000` starts the scene in |
| CINEMATIC_675 | CINEMATIC_PRISON_WAKE_CLOSEUP_EYELID_1 | high | lid bottom 132.0 |
| CINEMATIC_674 | CINEMATIC_PRISON_WAKE_CLOSEUP_EYELID_2 | high | lid bottom 130.0 |
| CINEMATIC_673 | CINEMATIC_PRISON_WAKE_CLOSEUP_EYELID_3 | high | lid bottom 128.0 |
| CINEMATIC_672 | CINEMATIC_PRISON_WAKE_CLOSEUP_EYELID_4 | high | lid bottom 126.0 |
| CINEMATIC_671 | CINEMATIC_PRISON_WAKE_CLOSEUP_EYELID_5 | high | lid bottom 124.0 |
| CINEMATIC_670 | CINEMATIC_PRISON_WAKE_CLOSEUP_EYELID_6 | high | lid bottom 122.0 |
| CINEMATIC_669 | CINEMATIC_PRISON_WAKE_CLOSEUP_EYELID_7 | high | lid bottom 120.0 |
| CINEMATIC_668 | CINEMATIC_PRISON_WAKE_CLOSEUP_EYELID_8 | high | lid bottom 118.0 |
| CINEMATIC_667 | CINEMATIC_PRISON_WAKE_CLOSEUP_EYELID_9 | high | lid bottom 116.0 |
| CINEMATIC_666 | CINEMATIC_PRISON_WAKE_CLOSEUP_EYELID_10 | high | lid bottom 114.0 |
| CINEMATIC_665 | CINEMATIC_PRISON_WAKE_CLOSEUP_EYELID_11 | high | lid bottom 112.0 |
| CINEMATIC_664 | CINEMATIC_PRISON_WAKE_CLOSEUP_EYELID_12 | high | lid bottom 110.0, just clear of the eye's top at 108.5 |
| CINEMATIC_663 | CINEMATIC_PRISON_WAKE_CLOSEUP_EYELID_13 | high | lid bottom 108.0 |
| CINEMATIC_662 | CINEMATIC_PRISON_WAKE_CLOSEUP_EYELID_14 | high | lid bottom 106.0 |
| CINEMATIC_661 | CINEMATIC_PRISON_WAKE_CLOSEUP_EYELID_15 | high | lid bottom 104.0 |
| CINEMATIC_660 | CINEMATIC_PRISON_WAKE_CLOSEUP_EYELID_16 | high | lid bottom 102.0 |
| CINEMATIC_659 | CINEMATIC_PRISON_WAKE_CLOSEUP_EYELID_17 | high | lid bottom 100.0, the highest rung, `[0x16] > 0x20` -- eye fully clear |

## What these names do not claim

Nothing here says **whose** face it is. `PRISON_WAKE_CLOSEUP` was already the
tree's word for this scene and these names inherit it; the pictures settle
that it is a face waking up, and not who.

`FACE_HALF_0` and `FACE_HALF_1` are the screen-left and screen-right halves of
the composition. They are not a facing direction, and the trailing index is
draw order, not a frame.
