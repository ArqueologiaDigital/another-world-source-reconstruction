# INTRO: the walk family's tail, shifted once for every branch

Step 1 of the renumber argued in
`proposals_chahi_amiga_1991__INTRO_walk_renumber.md`. It is **global** -- no
`--branch` -- and that is the whole point of it.

`LESTER_WALKING_AWAY_FROM_CAMERA_FRAME_CYCLE`'s draws of F3, F4 and F5 are
shared lines in `src/levels/_unified/intro/intro_scene_late_phase.inc`, outside
any `.if BRANCH` arm, and dos, cartridge and gba share one `.else` arm for the
EQU block. Two attempts established what that means:

- renaming in amiga and msdos only left the shared draw lines pointing at a
  name whose value had moved in two branches and not the other two.
  `verify_unified.py` 29/29 -> **25/29**.
- renaming branch by branch for all four applied the **chained** shift
  (F3->F4->F5->F6->F7) once per branch to the one arm they share, so 0x42A8
  came out as F5 and two constants ended up both called F7.
  `undefined_symbols.py`: 6 problems, three of them "defined 2 times, 2
  DIFFERENT values".

A uniform shift across every branch is one global rename, applied once.
`CINEMATIC_129` rides along in the same batch because it is the same offset
0x4290 in each of the three branches that define it, and because splitting it
out would leave the family with a gap at F3 and the validator would reject
that -- correctly.

amiga has no `CINEMATIC_129`, so it leaves this batch with F3 unfilled; step 2
(`proposals_chahi_amiga_1991__INTRO_walk_renumber.md`) fills it from amiga's
own `CINEMATIC_518`. Run the two together.

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_LESTER_WALKING_AWAY_FROM_CAMERA_F3 | CINEMATIC_LESTER_WALKING_AWAY_FROM_CAMERA_F4 | high | amiga 0x4336, others 0x42A8, `1fa4211454a6` in all three renderable ports |
| CINEMATIC_LESTER_WALKING_AWAY_FROM_CAMERA_F4 | CINEMATIC_LESTER_WALKING_AWAY_FROM_CAMERA_F5 | high | amiga 0x434E, others 0x42C0 |
| CINEMATIC_LESTER_WALKING_AWAY_FROM_CAMERA_F5 | CINEMATIC_LESTER_WALKING_AWAY_FROM_CAMERA_F6 | high | amiga 0x4366, others 0x42D8, the turn of the palindrome |
| CINEMATIC_LESTER_WALKING_AWAY_FROM_CAMERA_F6 | CINEMATIC_LESTER_WALKING_AWAY_FROM_CAMERA_F7 | high | amiga 0x42A6, others 0x4218, `adc38d8c70ed`; played once at the end of each pass, so last by order of appearance |
| CINEMATIC_129 | CINEMATIC_LESTER_WALKING_AWAY_FROM_CAMERA_F3 | high | 0x4290 in dos, cartridge and gba alike, `3cdfb5d79185` where it can be rendered. The sheet slot between F2 (0x4278) and the old F3 (0x42A8) |
