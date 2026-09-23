# INTRO: the lamp, renamed everywhere rather than per branch

`..._collision_leftovers.md` renamed `CINEMATIC_LESTER_WALKING_AWAY_FROM_CAMERA_F6_AMIGA_EXTRA`
in amiga and msdos only, and `apply_branch_scoped_names.py` then reported two
shared draw lines it had left alone. It was right to leave them: the EQU and
the draw both sit **outside any `.if BRANCH` arm** in
`src/levels/_unified/intro/intro_scene_late_phase.inc`, because this one is not
divergent art at all.

All four branches define it at the **same offset 0x06CC**, and amiga, msdos and
gba agree on `canonical_md5` `afafd0dda5fb` (cartridge has no romset, #0106, so
it contributes the offset and not the art). `LAB_DOOR_SCENE_LAMP_BLINK_LOOP`
draws it once at `x=96, y=131` in every branch.

So it takes one shared name. This also removes the last `_AMIGA_EXTRA` constant
from the tree outside cartridge.

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_LESTER_WALKING_AWAY_FROM_CAMERA_F6_AMIGA_EXTRA | CINEMATIC_LAB_DOOR_SCENE_LAMP | high | 0x06CC in all four branches, `afafd0dda5fb` in the three with a romset. 2.0x1.0 in one path -- two pixels -- and the only picture `LAB_DOOR_SCENE_LAMP_BLINK_LOOP` draws, at `x=96, y=131` |
