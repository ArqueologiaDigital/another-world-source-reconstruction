# CAPSULE (msdos): the same dispatcher, this port's own pictures

Argument in `proposals_chahi_amiga_1991__CAPSULE_poses.md`. msdos's
`DRAW_HERO_SPRITE_BY_VAR09_0E` has the identical prologue and dispatch shape,
and `notes/pose-dispatch/pose_index.py` reads its mapping the same way.

The pictures are **not** the same as amiga's. Of the eight slots the two ports
share, only group 0 index 5 has the same `canonical_md5` (`ded0af914f4c`); the
other seven differ. A pose index is therefore a per-port dispatch fact, and
these names describe what **this** port draws for each slot -- which is exactly
what a branch-scoped constant is for.

`CINEMATIC_015` is reached at both `(3, 3)` and `(5, 3)` and so has no unique
index; it is left numbered.

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_022 | CINEMATIC_CAPSULE_FIGURE_POSE_0_0 | high | `DRAW_HERO_POSE_0_0`, `je [0xF8], 0x00` in the `[0x0E] == 0` arm |
| CINEMATIC_023 | CINEMATIC_CAPSULE_FIGURE_POSE_0_1 | high | `DRAW_HERO_POSE_0_1`, `je [0xF8], 0x01` |
| CINEMATIC_024 | CINEMATIC_CAPSULE_FIGURE_POSE_0_2 | high | `DRAW_HERO_POSE_0_2`, `je [0xF8], 0x02` |
| CINEMATIC_025 | CINEMATIC_CAPSULE_FIGURE_POSE_0_3 | high | `DRAW_HERO_POSE_0_3`, `je [0xF8], 0x03` |
| CINEMATIC_026 | CINEMATIC_CAPSULE_FIGURE_POSE_0_4 | high | `DRAW_HERO_POSE_0_4`, `je [0xF8], 0x04` |
| CINEMATIC_027 | CINEMATIC_CAPSULE_FIGURE_POSE_0_5 | high | `DRAW_ALIEN_POSE_0_5`, `je [0xF8], 0x05`. `ded0af914f4c` -- the one slot whose art amiga shares exactly. Its routine says ALIEN where amiga's says HERO, which is why neither word is used |
| CINEMATIC_028 | CINEMATIC_CAPSULE_FIGURE_POSE_0_6 | high | `DRAW_HERO_POSE_0_6`, `je [0xF8], 0x06` |
| CINEMATIC_029 | CINEMATIC_CAPSULE_FIGURE_POSE_0_7 | high | `DRAW_HERO_POSE_0_7`, `je [0xF8], 0x07` |
| CINEMATIC_017 | CINEMATIC_CAPSULE_FIGURE_POSE_4_3 | high | `je [0xF8], 0x03` inside the `[0x0E] == 4` arm |
| CINEMATIC_012 | CINEMATIC_CAPSULE_FIGURE_POSE_7_0 | high | `je [0xF8], 0x00` inside the `[0x0E] == 7` arm |
| CINEMATIC_013 | CINEMATIC_CAPSULE_FIGURE_POSE_7_1 | high | `je [0xF8], 0x01` inside the `[0x0E] == 7` arm |
