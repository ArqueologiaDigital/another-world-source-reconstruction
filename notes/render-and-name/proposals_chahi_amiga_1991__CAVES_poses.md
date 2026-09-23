# CAVES (amiga): pictures named by the slot their dispatcher selects

Two dispatchers with identical prologues -- `mov [0xF8], [0x09]; shr [0xF8], 4`
-- pick a picture by an `[0x0E]` group and `[0x09]`'s high nibble, and each
target is a one-line routine drawing exactly one constant. The index is out of
the bytecode; nothing here was rendered.

**Their callers say which sheet is which.** One is reached only from
`CAVES_ACTOR_*_LEFT_*` routines, the other only from `CAVES_ACTOR_*_RIGHT_*`.
So the two sheets are two **facings**, not two actors -- which matters, because
their own labels say BUDDY and HERO (and BEAST, in CAVES) for what the callers
show to be one actor turned around. `../actor-anchors/` measures why no actor
word may be used: 72 conflicts between a name's actor word and its anchor, and
CAVES draws 194 times at the `BUDDY_X` slot in a stage with no companion in it.

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_048 | CINEMATIC_CAVES_FIGURE_POSE_LEFT_0_0 | high | `DRAW_BEAST_POSE_0_0`, reached by `je [0xF8], 0x00` inside the `[0x0E] == 0` arm of the left-facing dispatcher |
| CINEMATIC_049 | CINEMATIC_CAVES_FIGURE_POSE_LEFT_0_1 | high | `DRAW_BEAST_POSE_0_1`, reached by `je [0xF8], 0x01` inside the `[0x0E] == 0` arm of the left-facing dispatcher |
| CINEMATIC_050 | CINEMATIC_CAVES_FIGURE_POSE_LEFT_0_2 | high | `DRAW_BEAST_POSE_0_2`, reached by `je [0xF8], 0x02` inside the `[0x0E] == 0` arm of the left-facing dispatcher |
| CINEMATIC_051 | CINEMATIC_CAVES_FIGURE_POSE_LEFT_0_3 | high | `DRAW_BEAST_POSE_0_3`, reached by `je [0xF8], 0x03` inside the `[0x0E] == 0` arm of the left-facing dispatcher |
| CINEMATIC_052 | CINEMATIC_CAVES_FIGURE_POSE_LEFT_0_4 | high | `DRAW_BEAST_POSE_0_4`, reached by `je [0xF8], 0x04` inside the `[0x0E] == 0` arm of the left-facing dispatcher |
| CINEMATIC_026 | CINEMATIC_CAVES_FIGURE_POSE_LEFT_0_5 | high | `DRAW_BEAST_POSE_0_5`, reached by `je [0xF8], 0x05` inside the `[0x0E] == 0` arm of the left-facing dispatcher |
| CINEMATIC_053 | CINEMATIC_CAVES_FIGURE_POSE_LEFT_0_6 | high | `DRAW_BEAST_POSE_0_6`, reached by `je [0xF8], 0x06` inside the `[0x0E] == 0` arm of the left-facing dispatcher |
| CINEMATIC_043 | CINEMATIC_CAVES_FIGURE_POSE_LEFT_4_3 | high | `DRAW_CIN_043`, reached by `je [0xF8], 0x03` inside the `[0x0E] == 4` arm of the left-facing dispatcher |
| CINEMATIC_038 | CINEMATIC_CAVES_FIGURE_POSE_LEFT_7_0 | high | `DRAW_CIN_038`, reached by `je [0xF8], 0x00` inside the `[0x0E] == 7` arm of the left-facing dispatcher |
| CINEMATIC_039 | CINEMATIC_CAVES_FIGURE_POSE_LEFT_7_1 | high | `DRAW_CIN_039`, reached by `je [0xF8], 0x01` inside the `[0x0E] == 7` arm of the left-facing dispatcher |
| CINEMATIC_017 | CINEMATIC_CAVES_FIGURE_POSE_RIGHT_4_1 | high | `DRAW_CIN_017`, reached by `je [0xF8], 0x01` inside the `[0x0E] == 4` arm of the right-facing dispatcher |
| CINEMATIC_015 | CINEMATIC_CAVES_FIGURE_POSE_RIGHT_7_1 | high | `DRAW_CIN_015`, reached by `je [0xF8], 0x01` inside the `[0x0E] == 7` arm of the right-facing dispatcher |

## Notes and what is left numbered

- `CINEMATIC_026` is dispatched at group 0 index 5 by **both** facings (LEFT, RIGHT). One picture serves both, so it takes the left name and the right-facing run has no member of its own at that index.
- `CINEMATIC_041` is dispatched at group 3 index 3, group 5 index 3, so no single index names it. Left numbered.
- `CINEMATIC_022` would be `CINEMATIC_CAVES_FIGURE_POSE_RIGHT_0_1`, but that run is missing an index because the shared picture above took the other facing's name, and a family may not gain a gap. Left numbered.
- `CINEMATIC_023` would be `CINEMATIC_CAVES_FIGURE_POSE_RIGHT_0_2`, but that run is missing an index because the shared picture above took the other facing's name, and a family may not gain a gap. Left numbered.
- `CINEMATIC_024` would be `CINEMATIC_CAVES_FIGURE_POSE_RIGHT_0_3`, but that run is missing an index because the shared picture above took the other facing's name, and a family may not gain a gap. Left numbered.
- `CINEMATIC_025` would be `CINEMATIC_CAVES_FIGURE_POSE_RIGHT_0_4`, but that run is missing an index because the shared picture above took the other facing's name, and a family may not gain a gap. Left numbered.
- `CINEMATIC_027` would be `CINEMATIC_CAVES_FIGURE_POSE_RIGHT_0_6`, but that run is missing an index because the shared picture above took the other facing's name, and a family may not gain a gap. Left numbered.
