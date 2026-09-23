# CAPSULE (amiga): the facing that was missing, and the left-facing sheet

`proposals_*__CAPSULE_poses.md` named this stage's right-facing slots
`CINEMATIC_CAPSULE_FIGURE_POSE_<g>_<i>` and said the other dispatcher's word was
'not established enough to use yet'. The caller test that settled PRISON and
CAVES settles it here too:

```
  LABEL_5DE8                    24 callers named ..._LEFT_...,  0 named ..._RIGHT_...
  DRAW_HERO_SPRITE_BY_VAR09_0E   0                             22
  e.g. CAPSULE_ACTOR_RUN_LEFT_DRAW_0_DONE / CAPSULE_ACTOR_RUN_RIGHT_DRAW_0
```

So the two sheets are two facings, the already-named ones are the **right**-facing
sheet and should say so, and `LABEL_5DE8`'s are the left-facing sheet.

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_195 | CINEMATIC_CAPSULE_FIGURE_POSE_LEFT_0_0 | high | `DRAW_CIN_195`, `je [0xF8], 0x00` in the `[0x0E] == 0` arm, left-facing dispatcher |
| CINEMATIC_196 | CINEMATIC_CAPSULE_FIGURE_POSE_LEFT_0_1 | high | `DRAW_CIN_196`, `je [0xF8], 0x01` in the `[0x0E] == 0` arm, left-facing dispatcher |
| CINEMATIC_197 | CINEMATIC_CAPSULE_FIGURE_POSE_LEFT_0_2 | high | `DRAW_CIN_197`, `je [0xF8], 0x02` in the `[0x0E] == 0` arm, left-facing dispatcher |
| CINEMATIC_198 | CINEMATIC_CAPSULE_FIGURE_POSE_LEFT_0_3 | high | `DRAW_CIN_198`, `je [0xF8], 0x03` in the `[0x0E] == 0` arm, left-facing dispatcher |
| CINEMATIC_199 | CINEMATIC_CAPSULE_FIGURE_POSE_LEFT_0_4 | high | `DRAW_CIN_199`, `je [0xF8], 0x04` in the `[0x0E] == 0` arm, left-facing dispatcher |
| CINEMATIC_CAPSULE_FIGURE_POSE_0_5 | CINEMATIC_CAPSULE_FIGURE_POSE_LEFT_0_5 | high | correction: adds the facing, left-facing dispatcher |
| CINEMATIC_200 | CINEMATIC_CAPSULE_FIGURE_POSE_LEFT_0_6 | high | `DRAW_CIN_200`, `je [0xF8], 0x06` in the `[0x0E] == 0` arm, left-facing dispatcher |
| CINEMATIC_190 | CINEMATIC_CAPSULE_FIGURE_POSE_LEFT_4_3 | high | `DRAW_CIN_190`, `je [0xF8], 0x03` in the `[0x0E] == 4` arm, left-facing dispatcher |
| CINEMATIC_185 | CINEMATIC_CAPSULE_FIGURE_POSE_LEFT_7_0 | high | `DRAW_CIN_185`, `je [0xF8], 0x00` in the `[0x0E] == 7` arm, left-facing dispatcher |
| CINEMATIC_186 | CINEMATIC_CAPSULE_FIGURE_POSE_LEFT_7_1 | high | `DRAW_CIN_186`, `je [0xF8], 0x01` in the `[0x0E] == 7` arm, left-facing dispatcher |
| CINEMATIC_CAPSULE_FIGURE_POSE_4_1 | CINEMATIC_CAPSULE_FIGURE_POSE_RIGHT_4_1 | high | correction: adds the facing, right-facing dispatcher |
| CINEMATIC_CAPSULE_FIGURE_POSE_7_1 | CINEMATIC_CAPSULE_FIGURE_POSE_RIGHT_7_1 | high | correction: adds the facing, right-facing dispatcher |

## Left numbered, with the reason

- `CINEMATIC_CAPSULE_FIGURE_POSE_0_5` is dispatched at group 0 index 5 by both facings; it takes the left name.
- `CINEMATIC_188` is dispatched at group 3 index 3, group 5 index 3 -- no single index.
- `CINEMATIC_CAPSULE_FIGURE_POSE_0_1` would be `CINEMATIC_CAPSULE_FIGURE_POSE_RIGHT_0_1`, but that run would gain a gap.
- `CINEMATIC_CAPSULE_FIGURE_POSE_0_2` would be `CINEMATIC_CAPSULE_FIGURE_POSE_RIGHT_0_2`, but that run would gain a gap.
- `CINEMATIC_CAPSULE_FIGURE_POSE_0_3` would be `CINEMATIC_CAPSULE_FIGURE_POSE_RIGHT_0_3`, but that run would gain a gap.
- `CINEMATIC_CAPSULE_FIGURE_POSE_0_4` would be `CINEMATIC_CAPSULE_FIGURE_POSE_RIGHT_0_4`, but that run would gain a gap.
- `CINEMATIC_CAPSULE_FIGURE_POSE_0_6` would be `CINEMATIC_CAPSULE_FIGURE_POSE_RIGHT_0_6`, but that run would gain a gap.
