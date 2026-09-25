# PRISON: the pose dispatcher's leaves and arms

Every leaf of `DRAW_PRISON_BUDDY_SPRITE_BY_VAR09_0E` now draws exactly one
named constant, so each routine's name follows from its one line. The three
dispatch arms are named for the case they test.

Two changes of word, both deliberate. `DRAW_CIN_<n>` placeholders name a
constant number that no longer exists, so keeping them would point at nothing.
And the two `DRAW_PRISON_BUDDY_POSE_*` routines carry an actor word that
`../actor-anchors/` records as not admissible from this anchor -- the same
word this session removed from the variable itself -- so they take FIGURE like
the constants they draw. Their `_0_0`..`_0_3` siblings keep BUDDY for now;
changing those is a separate table.

| old | new | confidence | evidence |
|---|---|---|---|
| DRAW_CIN_235 | DRAW_PRISON_FIGURE_POSE_LEFT_1_OTHER | high | one line, `video offset=CINEMATIC_PRISON_FIGURE_POSE_LEFT_1_OTHER, x=[ACTOR_X], y=[ACTOR_Y]`; the `jmp` fall-through of case 1's variant test |
| DRAW_CIN_234 | DRAW_PRISON_FIGURE_POSE_LEFT_1_1 | high | one line drawing CINEMATIC_PRISON_FIGURE_POSE_LEFT_1_1; case 1, `je [0xF8], 0x01` |
| DRAW_CIN_233 | DRAW_PRISON_FIGURE_POSE_LEFT_2_OTHER | high | one line drawing CINEMATIC_PRISON_FIGURE_POSE_LEFT_2_OTHER; case 2 fall-through |
| DRAW_CIN_232 | DRAW_PRISON_FIGURE_POSE_LEFT_2_1 | high | one line drawing CINEMATIC_PRISON_FIGURE_POSE_LEFT_2_1; case 2, `je [0xF8], 0x01` |
| DRAW_PRISON_BUDDY_POSE_3 | DRAW_PRISON_FIGURE_POSE_LEFT_3_ANY | high | one line drawing CINEMATIC_PRISON_FIGURE_POSE_LEFT_3_ANY; case 3 has no variant test, hence ANY. BUDDY dropped per ../actor-anchors/ |
| DRAW_CIN_230 | DRAW_PRISON_FIGURE_POSE_LEFT_4_OTHER | high | one line drawing CINEMATIC_PRISON_FIGURE_POSE_LEFT_4_OTHER; case 4 fall-through |
| DRAW_CIN_229 | DRAW_PRISON_FIGURE_POSE_LEFT_4_1 | high | one line drawing CINEMATIC_PRISON_FIGURE_POSE_LEFT_4_1; case 4, `je [0xF8], 0x01` |
| DRAW_PRISON_BUDDY_POSE_5 | DRAW_PRISON_FIGURE_POSE_LEFT_5_ANY | high | one line drawing CINEMATIC_PRISON_FIGURE_POSE_LEFT_5_ANY; case 5 has no variant test. BUDDY dropped |
| DRAW_CIN_225 | DRAW_PRISON_FIGURE_POSE_LEFT_7_0 | high | one line drawing CINEMATIC_PRISON_FIGURE_POSE_LEFT_7_0; case 7, `je [0xF8], 0x00` |
| DRAW_CIN_226 | DRAW_PRISON_FIGURE_POSE_LEFT_7_1 | high | one line drawing CINEMATIC_PRISON_FIGURE_POSE_LEFT_7_1; case 7, `je [0xF8], 0x01` |
| LABEL_5166 | PRISON_FIGURE_POSE_DISPATCH_CASE_03 | high | `jne [0x0E], 0x03` arm of the pose switch, matching the sibling arms already named PRISON_BUDDY_POSE_DISPATCH_CASE_04 and _06 in shape |
| LABEL_517E | PRISON_FIGURE_POSE_DISPATCH_CASE_05 | high | `jne [0x0E], 0x05` arm of the same switch |
| LABEL_5193 | PRISON_FIGURE_POSE_DISPATCH_CASE_07 | high | `jne [0x0E], 0x07` arm, whose two `je [0xF8]` leaves are the 7_0 and 7_1 pair |
