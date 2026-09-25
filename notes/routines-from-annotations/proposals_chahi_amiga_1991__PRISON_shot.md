# PRISON (chahi_amiga_1991): the two routines of the upward shot

Both draw only constants named in `../play-and-describe/proposals_chahi_amiga_1991__PRISON_shot_up.md`.

| old | new | confidence | evidence |
|---|---|---|---|
| LABEL_567F | PRISON_DRAW_FIGURE_WITH_GUN_UP | high | gated on `jne [SCREEN_NUM], [0x10]`, then draws CINEMATIC_PRISON_FIGURE_ARM_GUN_UP, calls the head dispatcher and lays CV_FIGURE_PROFILE_STRIDE as the body -- the whole routine is one figure holding a gun up |
| LABEL_2158 | PRISON_FIRE_SHOT_UP_AND_SUMMON_GUARD | high | the complete event: two calls to the figure draw, `jl [0x15], 0x1E` on the cage-swing counter, `setPalette 0x0F` and `play id=0x0052` for the flash and report, the three SHOT_UP_BEAM draws climbing y 110 -> 80 -> -20, then `setup channel=0x11, address=PRISON_BACKGROUND_GUARD_RUN_IN` |
