# CAPSULE (msdos) — the same three heavy beam tiles

msdos keeps them as plain indices rather than under the wrong name: its tile
routines draw `CINEMATIC_614/615/616`, measured 15, 47 and 111 px by 5, all at
x=64, with the same 0x10/0x30/0x70 steps. Same set, same evidence.

| constant | proposed name | confidence | evidence |
|---|---|---|---|
| CINEMATIC_614 | CINEMATIC_CAPSULE_SUPERBLAST_BEAM_TILE_0 | high | 15x5 at x=64, SHORT tiler, step 0x10; measured |
| CINEMATIC_615 | CINEMATIC_CAPSULE_SUPERBLAST_BEAM_TILE_1 | high | 47x5, MEDIUM tiler, step 0x30; measured |
| CINEMATIC_616 | CINEMATIC_CAPSULE_SUPERBLAST_BEAM_TILE_2 | high | 111x5, LONG tiler, step 0x70; measured |
