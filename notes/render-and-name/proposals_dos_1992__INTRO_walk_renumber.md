# INTRO (msdos): the walk renumber, this branch's own part

Steps and evidence in `proposals_all__INTRO_walk_shift.md` (global, first) and
`proposals_chahi_amiga_1991__INTRO_walk_renumber.md` (the argument).

msdos, like amiga, had `..._F2` on the room outline rather than on the sheet's
own fourth slot; cartridge and gba had it right. The global step has already
filled F3 here from `CINEMATIC_129`, so only F2 moves.
| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_LESTER_WALKING_AWAY_FROM_CAMERA_F2 | CINEMATIC_BIOMETRIC_SCANNER_ROOM_OUTLINE | high | 0xAF34, `144a3f4a258d`, identical to amiga's 0xAFC2 and gba's 0xAF34 |
| CINEMATIC_523 | CINEMATIC_LESTER_WALKING_AWAY_FROM_CAMERA_F2 | high | 0x4278, `daee1ba7c85b` -- the slot cartridge and gba already call `..._F2` |
