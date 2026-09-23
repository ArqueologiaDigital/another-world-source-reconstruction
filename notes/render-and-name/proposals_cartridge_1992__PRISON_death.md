# PRISON (cartridge): the same four, by slot

Argument in `hero_death_four_ways.md`. Cartridge's ROM is not extracted
(#0106), so nothing was measured: the claim is the slot. Cartridge PRISON holds
all four runs under the **same constant numbers** as amiga and msdos, in
routines with the same shape and the same `sub`/`add [HERO_X]` markers --
`PRISON_HERO_DEATH_FLASH`, `DRAW_CIN_146_TO_147_4F_AT_8AA18039`,
`DRAW_CIN_280_TO_281_2F_AT_75ED3E60` and `LABEL_0F58` -- each `F0, F1, F2, F1`
into `DRAW_CIN_137_138_BLOCK`.

Without this the stage would carry an undirected `CINEMATIC_HERO_DEATH_F*` in
one branch and `..._STANDING_LEFT_F*` in the other two, which is the sort of
split `../cross-port-art/name_art_agreement.py` exists to catch.

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_HERO_DEATH_F0 | CINEMATIC_HERO_DEATH_STANDING_LEFT_F0 | high | `PRISON_HERO_DEATH_FLASH`, the same routine amiga and msdos rename; the facing is theirs, not a cartridge reading |
| CINEMATIC_HERO_DEATH_F1 | CINEMATIC_HERO_DEATH_STANDING_LEFT_F1 | high | `PRISON_HERO_DEATH_FLASH`, the same routine amiga and msdos rename; the facing is theirs, not a cartridge reading |
| CINEMATIC_HERO_DEATH_F2 | CINEMATIC_HERO_DEATH_STANDING_LEFT_F2 | high | `PRISON_HERO_DEATH_FLASH`, the same routine amiga and msdos rename; the facing is theirs, not a cartridge reading |
| CINEMATIC_146 | CINEMATIC_HERO_DEATH_STANDING_RIGHT_F0 | medium | `DRAW_CIN_146_TO_147_4F_AT_8AA18039`, no x motion; frame 0 of the `F0, F1, F2, F1` run, same constant number as amiga's and msdos'. Art not compared (#0106) |
| CINEMATIC_147 | CINEMATIC_HERO_DEATH_STANDING_RIGHT_F1 | medium | `DRAW_CIN_146_TO_147_4F_AT_8AA18039`, no x motion; frame 1 of the `F0, F1, F2, F1` run, same constant number as amiga's and msdos'. Art not compared (#0106) |
| CINEMATIC_148 | CINEMATIC_HERO_DEATH_STANDING_RIGHT_F2 | medium | `DRAW_CIN_146_TO_147_4F_AT_8AA18039`, no x motion; frame 2 of the `F0, F1, F2, F1` run, same constant number as amiga's and msdos'. Art not compared (#0106) |
| CINEMATIC_280 | CINEMATIC_HERO_DEATH_KNEELING_RIGHT_F0 | medium | `DRAW_CIN_280_TO_281_2F_AT_75ED3E60`, `sub [HERO_X]` between frames; frame 0 of the `F0, F1, F2, F1` run, same constant number as amiga's and msdos'. Art not compared (#0106) |
| CINEMATIC_281 | CINEMATIC_HERO_DEATH_KNEELING_RIGHT_F1 | medium | `DRAW_CIN_280_TO_281_2F_AT_75ED3E60`, `sub [HERO_X]` between frames; frame 1 of the `F0, F1, F2, F1` run, same constant number as amiga's and msdos'. Art not compared (#0106) |
| CINEMATIC_282 | CINEMATIC_HERO_DEATH_KNEELING_RIGHT_F2 | medium | `DRAW_CIN_280_TO_281_2F_AT_75ED3E60`, `sub [HERO_X]` between frames; frame 2 of the `F0, F1, F2, F1` run, same constant number as amiga's and msdos'. Art not compared (#0106) |
| CINEMATIC_134 | CINEMATIC_HERO_DEATH_KNEELING_LEFT_F0 | medium | `LABEL_0F58`, `add [HERO_X]` between frames; frame 0 of the `F0, F1, F2, F1` run, same constant number as amiga's and msdos'. Art not compared (#0106) |
| CINEMATIC_135 | CINEMATIC_HERO_DEATH_KNEELING_LEFT_F1 | medium | `LABEL_0F58`, `add [HERO_X]` between frames; frame 1 of the `F0, F1, F2, F1` run, same constant number as amiga's and msdos'. Art not compared (#0106) |
| CINEMATIC_136 | CINEMATIC_HERO_DEATH_KNEELING_LEFT_F2 | medium | `LABEL_0F58`, `add [HERO_X]` between frames; frame 2 of the `F0, F1, F2, F1` run, same constant number as amiga's and msdos'. Art not compared (#0106) |
