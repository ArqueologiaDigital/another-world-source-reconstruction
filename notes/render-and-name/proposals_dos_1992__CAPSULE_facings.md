# CAPSULE (msdos): the facing that was missing, and the left-facing sheet

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
| CINEMATIC_CAPSULE_FIGURE_POSE_0_0 | CINEMATIC_CAPSULE_FIGURE_POSE_RIGHT_0_0 | high | correction: adds the facing, right-facing dispatcher |
| CINEMATIC_CAPSULE_FIGURE_POSE_0_1 | CINEMATIC_CAPSULE_FIGURE_POSE_RIGHT_0_1 | high | correction: adds the facing, right-facing dispatcher |
| CINEMATIC_CAPSULE_FIGURE_POSE_0_2 | CINEMATIC_CAPSULE_FIGURE_POSE_RIGHT_0_2 | high | correction: adds the facing, right-facing dispatcher |
| CINEMATIC_CAPSULE_FIGURE_POSE_0_3 | CINEMATIC_CAPSULE_FIGURE_POSE_RIGHT_0_3 | high | correction: adds the facing, right-facing dispatcher |
| CINEMATIC_CAPSULE_FIGURE_POSE_0_4 | CINEMATIC_CAPSULE_FIGURE_POSE_RIGHT_0_4 | high | correction: adds the facing, right-facing dispatcher |
| CINEMATIC_CAPSULE_FIGURE_POSE_0_5 | CINEMATIC_CAPSULE_FIGURE_POSE_RIGHT_0_5 | high | correction: adds the facing, right-facing dispatcher |
| CINEMATIC_CAPSULE_FIGURE_POSE_0_6 | CINEMATIC_CAPSULE_FIGURE_POSE_RIGHT_0_6 | high | correction: adds the facing, right-facing dispatcher |
| CINEMATIC_CAPSULE_FIGURE_POSE_0_7 | CINEMATIC_CAPSULE_FIGURE_POSE_RIGHT_0_7 | high | correction: adds the facing, right-facing dispatcher |
| CINEMATIC_CAPSULE_FIGURE_POSE_4_3 | CINEMATIC_CAPSULE_FIGURE_POSE_RIGHT_4_3 | high | correction: adds the facing, right-facing dispatcher |
| CINEMATIC_CAPSULE_FIGURE_POSE_7_0 | CINEMATIC_CAPSULE_FIGURE_POSE_RIGHT_7_0 | high | correction: adds the facing, right-facing dispatcher |
| CINEMATIC_CAPSULE_FIGURE_POSE_7_1 | CINEMATIC_CAPSULE_FIGURE_POSE_RIGHT_7_1 | high | correction: adds the facing, right-facing dispatcher |

## Left numbered, with the reason

- `CINEMATIC_015` is dispatched at group 3 index 3, group 5 index 3 -- no single index.
