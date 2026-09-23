# PRISON (amiga): pictures named by the slot their dispatcher selects

Two dispatchers with identical prologues -- `mov [0xF8], [0x09]; shr [0xF8], 4`
-- pick a picture by an `[0x0E]` group and `[0x09]`'s high nibble, and each
target is a one-line routine drawing exactly one constant. The index is out of
the bytecode; nothing here was rendered.

**Their callers say which sheet is which.** One is reached only from
`PRISON_ACTOR_*_LEFT_*` routines, the other only from `PRISON_ACTOR_*_RIGHT_*`.
So the two sheets are two **facings**, not two actors -- which matters, because
their own labels say BUDDY and HERO (and BEAST, in CAVES) for what the callers
show to be one actor turned around. `../actor-anchors/` measures why no actor
word may be used: 72 conflicts between a name's actor word and its anchor, and
CAVES draws 194 times at the `BUDDY_X` slot in a stage with no companion in it.

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_236 | CINEMATIC_PRISON_FIGURE_POSE_LEFT_0_0 | high | `DRAW_PRISON_BUDDY_POSE_0_0`, reached by `je [0xF8], 0x00` inside the `[0x0E] == 0` arm of the left-facing dispatcher |
| CINEMATIC_237 | CINEMATIC_PRISON_FIGURE_POSE_LEFT_0_1 | high | `DRAW_PRISON_BUDDY_POSE_0_1`, reached by `je [0xF8], 0x01` inside the `[0x0E] == 0` arm of the left-facing dispatcher |
| CINEMATIC_238 | CINEMATIC_PRISON_FIGURE_POSE_LEFT_0_2 | high | `DRAW_PRISON_BUDDY_POSE_0_2`, reached by `je [0xF8], 0x02` inside the `[0x0E] == 0` arm of the left-facing dispatcher |
| CINEMATIC_239 | CINEMATIC_PRISON_FIGURE_POSE_LEFT_0_3 | high | `DRAW_PRISON_BUDDY_POSE_0_3`, reached by `je [0xF8], 0x03` inside the `[0x0E] == 0` arm of the left-facing dispatcher |
| CINEMATIC_234 | CINEMATIC_PRISON_FIGURE_POSE_LEFT_1_1 | high | `DRAW_CIN_234`, reached by `je [0xF8], 0x01` inside the `[0x0E] == 1` arm of the left-facing dispatcher |
| CINEMATIC_232 | CINEMATIC_PRISON_FIGURE_POSE_LEFT_2_1 | high | `DRAW_CIN_232`, reached by `je [0xF8], 0x01` inside the `[0x0E] == 2` arm of the left-facing dispatcher |
| CINEMATIC_229 | CINEMATIC_PRISON_FIGURE_POSE_LEFT_4_1 | high | `DRAW_CIN_229`, reached by `je [0xF8], 0x01` inside the `[0x0E] == 4` arm of the left-facing dispatcher |
| CINEMATIC_225 | CINEMATIC_PRISON_FIGURE_POSE_LEFT_7_0 | high | `DRAW_CIN_225`, reached by `je [0xF8], 0x00` inside the `[0x0E] == 7` arm of the left-facing dispatcher |
| CINEMATIC_226 | CINEMATIC_PRISON_FIGURE_POSE_LEFT_7_1 | high | `DRAW_CIN_226`, reached by `je [0xF8], 0x01` inside the `[0x0E] == 7` arm of the left-facing dispatcher |
| CINEMATIC_164 | CINEMATIC_PRISON_FIGURE_POSE_RIGHT_0_0 | high | `DRAW_PRISON_HERO_POSE_0_0`, reached by `je [0xF8], 0x00` inside the `[0x0E] == 0` arm of the right-facing dispatcher |
| CINEMATIC_165 | CINEMATIC_PRISON_FIGURE_POSE_RIGHT_0_1 | high | `DRAW_PRISON_HERO_POSE_0_1`, reached by `je [0xF8], 0x01` inside the `[0x0E] == 0` arm of the right-facing dispatcher |
| CINEMATIC_166 | CINEMATIC_PRISON_FIGURE_POSE_RIGHT_0_2 | high | `DRAW_PRISON_HERO_POSE_0_2`, reached by `je [0xF8], 0x02` inside the `[0x0E] == 0` arm of the right-facing dispatcher |
| CINEMATIC_167 | CINEMATIC_PRISON_FIGURE_POSE_RIGHT_0_3 | high | `DRAW_PRISON_HERO_POSE_0_3`, reached by `je [0xF8], 0x03` inside the `[0x0E] == 0` arm of the right-facing dispatcher |
| CINEMATIC_159 | CINEMATIC_PRISON_FIGURE_POSE_RIGHT_4_1 | high | `DRAW_CIN_159`, reached by `je [0xF8], 0x01` inside the `[0x0E] == 4` arm of the right-facing dispatcher |
| CINEMATIC_157 | CINEMATIC_PRISON_FIGURE_POSE_RIGHT_7_1 | high | `DRAW_CIN_157`, reached by `je [0xF8], 0x01` inside the `[0x0E] == 7` arm of the right-facing dispatcher |
