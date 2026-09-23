# INTRO: the walk sheet, whose two unnamed slots sit in the middle of the run

## The sheet

Nine pictures on a perfectly regular **0x18 stride**, every one 14 paths and
about 100x185, every one the same figure seen from behind:

```
  0x42A6  101.0x184.5  14 paths   x[101.5, 202.5]      was ..._F6
  0x42BE   98.0x184.5  14 paths   x[105.0, 203.0]      LESTER_STANDING_BACK_TO_CAMERA
  0x42D6   99.0x184.5  14 paths   x[104.5, 203.5]      ..._F0
  0x42EE  100.0x185.5  14 paths   x[107.0, 207.0]      ..._F1
  0x4306  101.0x185.5  14 paths   x[106.5, 207.5]      CINEMATIC_517
  0x431E  102.0x185.5  14 paths   x[107.0, 209.0]      CINEMATIC_518
  0x4336  103.0x184.5  14 paths   x[106.5, 209.5]      was ..._F3
  0x434E  102.0x184.5  14 paths   x[108.0, 210.0]      was ..._F4
  0x4366  102.0x184.5  14 paths   x[109.0, 211.0]      was ..._F5
```

## The cycle is a palindrome, and only one numbering makes it one

`LESTER_WALKING_AWAY_FROM_CAMERA_FRAME_CYCLE` plays, one per `break`, all at
`x=160, y=111, zoom=[0x04]`:

```
  STANDING  F0  F1  517  518  F3  F4  F5  F4  F3  518  517  F1  F0  STANDING  F6
```

Read with 517 and 518 as the two frames between F1 and F3, that is a clean
out-and-back over eight consecutive sheet slots, plus one more picture played
once at the end. Read with the current names it is a palindrome with `F6`
dangling outside it and two numbers in the middle of an otherwise complete
`F0..F6`. The sheet order and the play order are the same order, which is what
makes the first reading the one to keep.

So the two numbers are the family's F2 and F3, and everything above them
shifts by one. `notes/HANDOFF.md` records the convention this follows --
complete `_F` families are indexed by **order of first appearance**, 159 of 159
-- and appearance order among the family's own members is exactly sheet order
here: 0x42D6, 0x42EE, 0x4306, 0x431E, 0x4336, 0x434E, 0x4366, then 0x42A6 last.

`LESTER_STANDING_BACK_TO_CAMERA` (0x42BE) keeps its name. It is on the sheet,
but it is also what `LAB_DOOR_LEAVES_PARTING_LOOP` holds on screen for four
passes before the cycle is installed at all, and it is the frame the palindrome
turns on at both ends. Nothing here contradicts that, so it is left alone.

## The index this frees was on the wrong picture anyway

`CINEMATIC_LESTER_WALKING_AWAY_FROM_CAMERA_F2` is at **0xAFC2**, nowhere near
the sheet, and the walk cycle never draws it. Its only draw is the first line
of `DRAW_BIOMETRIC_SCANNER_BG_COMPOSITE`. Rendered there it is **362.0x226.5 in
10 paths**: long thin teal lines -- two horizontal runs across the full width,
a vertical at the left, and two parallel diagonals. A room's edges, not a
person. It has to move before F2 can be filled, and it should have moved
anyway.

Its neighbours in that composite confirm the reading: `..._CONSOLE_DETAIL`
(0xB08E) is a scatter of small readout marks at x[211.0, 290.0], and
`LESTER_IN_BIOMETRIC_SCANNER` (0x4982) is the only figure in the scene.

## Proposals

**This renumber has to touch all four branches**, and the first attempt at it
did not. `LESTER_WALKING_AWAY_FROM_CAMERA_FRAME_CYCLE`'s draws of F3, F4 and F5
are shared lines in `src/levels/_unified/intro/intro_scene_late_phase.inc`,
outside any `.if BRANCH` arm, because every branch draws the same frame there.
Renaming in amiga and msdos alone left those lines pointing at a name whose
value had moved in two branches and not the other two, and `verify_unified.py`
went 29/29 to **25/29**. The companion tables
`proposals_{cartridge_1992,gba_2004}__INTRO_walk_renumber.md` carry the tail,
and `sync_equ_rename.py --shared` rewrites the shared lines once all four agree.

cartridge and gba need no F2 row: they already call **0x4278** `..._F2`, which
is the sheet's own slot. On this they were right and amiga and msdos were not,
which is a second, independent reading of the same sheet.

**Step 2 of two.** `proposals_all__INTRO_walk_shift.md` runs first and
globally: it shifts F3..F6 up by one in every branch at once and fills F3 from
`CINEMATIC_129` for the three branches that have it. This file then does what
is true of amiga alone -- move the wrong `..._F2` out and fill F2 and F3 from
amiga's own two numbers. Companion files do the same for dos and for
cartridge/gba.

A renumber is one batch and one file, and it is not idempotent: a rename table
describes a transition, not a state, so re-running it after it has been applied
will not leave the tree as it found it. See the journal in
`notes/unified-scoping/sync_equ_rename.py`.

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_LESTER_WALKING_AWAY_FROM_CAMERA_F2 | CINEMATIC_BIOMETRIC_SCANNER_ROOM_OUTLINE | high | 0xAFC2, off the sheet and never drawn by the walk cycle. 362.0x226.5 in 10 paths of long thin lines, drawn first in `DRAW_BIOMETRIC_SCANNER_BG_COMPOSITE`. `144a3f4a258d`, the same art msdos and gba hold at 0xAF34 |
| CINEMATIC_517 | CINEMATIC_LESTER_WALKING_AWAY_FROM_CAMERA_F2 | high | 0x4306, `daee1ba7c85b` -- the sheet slot cartridge and gba already call `..._F2` at their own 0x4278. 101.0x185.5 in 14 paths, played fourth in the cycle and fourth from the end |
| CINEMATIC_518 | CINEMATIC_LESTER_WALKING_AWAY_FROM_CAMERA_F3 | high | 0x431E, `3cdfb5d79185` -- the slot the other three branches call `CINEMATIC_129` at 0x4290, filled for them by the global step. 102.0x185.5 in 14 paths, played fifth and fifth from the end, and once more by `LAB_DOOR_LEAVES_SHUT_LOOP` |

## What this does not claim

It does not claim which foot is forward in any frame. The figure is seen from
behind in black trousers at this palette, so the legs carry no readable
contrast and the frames differ visibly only in the arms and shoulders. The
order comes from the sheet stride and the play order, both of which are in the
bytecode, not from reading a gait.

It does not renumber `LESTER_STANDING_BACK_TO_CAMERA` into the run even though
it sits on the same stride, because two things point the other way and nothing
points at a frame index for it.
