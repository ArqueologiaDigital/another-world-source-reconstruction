# PRISON (amiga): routines whose draw list is now fully named

Every row here draws only constants named in `../play-and-describe/` this
session. Line numbers are `src/levels/chahi_amiga_1991/PRISON.asm` after those renames.

| old | new | confidence | evidence |
|---|---|---|---|
| DRAW_CIN_576_578_BLOCK | PRISON_GUARD_GUN_KNOCKED_ARC | high | PRISON.asm:4202-4226; draws CINEMATIC_PRISON_GUARD_GUN_KNOCKED_F0..F5 and nothing else, at ten literal positions tracing x 215->251 and y 131->175 then flat, with `play id=0x0060` twice as it reaches the floor line. The whole routine is that one arc |
| DRAW_CIN_570_574_BLOCK | PRISON_BACKGROUND_GUARD_RUN_IN | high | PRISON.asm:4183-4199; draws CINEMATIC_PRISON_BACKGROUND_GUARD_RUN_F2, F0 and F1 at x descending 239, 230, 228, 227, 226 on the floor line y=175, re-blitting CINEMATIC_PRISON_BACKGROUND_DOORWAY_POST between frames. One figure, one direction: in |
| DRAW_CIN_569_TO_572_6F_AT_F8680E45 | PRISON_BACKGROUND_GUARD_RUN_OUT | high | PRISON.asm:4170-4181; lays CINEMATIC_PRISON_BACKGROUND_DOORWAY_BACKDROP into page 0, then draws RUN_F0, F3 and F4 at x ascending 228, 232, 245 on the same floor line. The opposite direction of the routine above, sharing RUN_F0 |
| DRAW_CIN_540_543_WITH_SFX_57 | PRISON_CAGE_DEBRIS_NEAR_PASS | high | PRISON.asm:13515-13527; alternates CINEMATIC_PRISON_CAGE_DEBRIS_NEAR_F0..F2 with CINEMATIC_PRISON_FLEXING_BAND_F0..F5 at one anchor, with `play id=0x0057` on the second. The debris areas go 512 -> 11,178 -> 9,240 square pixels: the near pass is the whole routine, and the old name's `WITH_SFX_57` is kept in spirit by the sound staying in the evidence |
| HANG_DRAW_CIN_549 | HANG_PRISON_CAGE_WRECK_AT_REST | high | PRISON.asm:13537-13540; draws CINEMATIC_PRISON_CAGE_WRECK_AT_REST at the literal (181,146) inside a `jmp` to itself. The HANG_ prefix stays: it is an infinite draw loop with no exit, which ../on-screen-priority/ reads to mark a row STUCK |
| LABEL_7A1D | PRISON_LIFT_CAR_BODY_TO_PAGE_3 | high | PRISON.asm:13398-13405; sets SCROLL_Y and [0x17]/[0x18] to zero, selects page 3, draws CINEMATIC_PRISON_LIFT_CAR_BODY at the literal (160,100), restores the page, then calls PRISON_LIFT_MOVE_STEP. Its whole body is putting the car into page 3 |
| LABEL_7AC0 | PRISON_LIFT_SHAFT_AND_HERO_DRAW | high | PRISON.asm:13478-13483; loops PRISON_LIFT_SHAFT_STRIP_TILT_UPTO_16 over [0x2B] adding 0x32 to [0x22] each pass, then draws CINEMATIC_PRISON_LIFT_HERO_SILHOUETTE at the hero anchor and CINEMATIC_PRISON_LIFT_CAR_FLOOR at (160,129) |
