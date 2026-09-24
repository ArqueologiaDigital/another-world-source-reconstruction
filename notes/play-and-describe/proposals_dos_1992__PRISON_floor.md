# PRISON: the cell block floor, shared by three screens

`ann:c2ec5d4f2063` on `CINEMATIC_305`, frame 3430: "the floor".

It is drawn at the literal (160,100) as the **first** thing after
`fill page=0x00, color=0x03` in three separate screen routines --
`PRISON_SCREEN_02_BACKDROP_DRAW` (PRISON.asm:8721),
`PRISON_SCREEN_03_BACKDROP_DRAW` (8731) and
`PRISON_SCREEN_04_BACKDROP_DRAW` (8749) -- with each screen's own
`..._SCREEN_<NN>_BACKDROP_LAYER_1..3` drawn on top of it afterwards.

So it is layer 0 for three screens at once, which is why it takes no
`_SCREEN_<NN>_` component: `notes/screen-scope/` reserves that for art one
screen owns, and this is the opposite case. 130 polygons.

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_305 | CINEMATIC_PRISON_CELLBLOCK_FLOOR | high | 0x4D12, drawn at the literal (160,100) as the first layer after `fill page=0x00, color=0x03` in PRISON_SCREEN_02/03/04_BACKDROP_DRAW, with each screen's own numbered layers over it; shared by three screens, so deliberately not `_SCREEN_<NN>_` scoped; 130 polygons; annot:c2ec5d4f2063 frame 3430, "the floor" |
