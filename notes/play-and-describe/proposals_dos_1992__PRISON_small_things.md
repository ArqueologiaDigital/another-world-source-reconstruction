# PRISON: four small things the second session pointed at

Four sentences, four constants whose whole nature is in one measurement each.

- `ann:ff430470da80` on `CINEMATIC_310`: "This looks like a grid. It passes in front of the camera at the bottom of the screen."
- `ann:5ccc4c58358f` on `CINEMATIC_318`: "red indicator light near the outside of a prison cell"
- `ann:3cf3bf4725a6` on `CINEMATIC_186`: "something very small close to the gun in the floor"
- `ann:9e13a2ce0980` on `CINEMATIC_275`: "something at the floor near the dead body of the guard or near the fallen cage or near buddy's feet"

Two of them are literally one pixel, and the difference between them is how they
are used, not what they are: `CINEMATIC_318` is placed twice at fixed points and
baked into the backdrop page, `CINEMATIC_186` is scattered across seven
positions that form no run.

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_310 | CINEMATIC_PRISON_FOREGROUND_GRID | high | 0xC37E, 61.0x50.0 in 7 leaves, its whole extent BELOW its anchor at y[56.0,106.0] -- so drawn at y=100 it occupies screen rows 156-206, the bottom. Its one draw site is inside LABEL_0881, a loop that does `add [0xE8], 0x000C` then draws and repeats while `[0xE8] < 0x0190`: it sweeps horizontally in 12-pixel steps from its start position past 400, well off a 320-wide screen. A large near shape panning across the bottom and out; annot:ff430470da80 |
| CINEMATIC_318 | CINEMATIC_PRISON_CELL_INDICATOR_LAMP | high | 0xA77C, 0.0x1.0 in ONE leaf -- a single pixel. Drawn twice by DRAW_CIN_318_TO_318_2F_AT_93A8CE70 at the literals (225,50) and (278,50), the same height and 53 apart, between `selectVideoPage 0x00` and `0xFF` so both are baked into the backdrop page rather than redrawn per frame. A pair of fixed one-pixel points is a pair of lamps; annot:5ccc4c58358f |
| CINEMATIC_186 | CINEMATIC_PRISON_PIXEL_GLINT | high | 0x0068, 0.0x1.0 in ONE leaf -- a single pixel, like CINEMATIC_318 but used differently: seven draw sites at seven scattered literals (101,158) (103,156) (105,154) (110,166) (108,167) (145,100) (258,181), no two of them a run. A one-pixel mark reused wherever a glint is wanted, which is why the sentence could only say 'something very small'; annot:3cf3bf4725a6 |
| CINEMATIC_275 | CINEMATIC_PRISON_CAGE_WRECK_FLOOR_PIECE | high | 0x9A20, 23.0x11.0 in ONE leaf -- a flat slab -- drawn by HANG_DRAW_CIN_275 at the literal (181,146) inside a `jmp` to itself. That is the SAME literal position and the same infinite-loop shape as HANG_PRISON_CAGE_WRECK_AT_REST, so it is a second layer of the settled wreck, held for as long as the scene lasts; annot:9e13a2ce0980 |
