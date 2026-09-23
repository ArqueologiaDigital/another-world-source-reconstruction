# CAPSULE: the hero crawl cycle, read from a render

Rendered together the eight are a prone figure in profile, 54-56 long and
8-12 tall, nine paths each, the body rising and falling frame to frame --
11.5, 12.5, 11.5, 10.5, 9.5, 8.5, 9.5, 11.5. Eight distinct `canonical_md5`s,
so eight real frames.

**One cycle, not two.** `HERO_CRAWL_LEFT_LOOP` does `sub [HERO_X]` and plays
370, 379, 380, 381, 382, 383; `HERO_CRAWL_RIGHT_LOOP` does `add [HERO_X]` and
plays 370, 385, 384, 383, 382, 381. The same pictures, read forwards and
backwards, so the name carries **no direction** -- the direction of travel is
in the routine's arithmetic, not in the art.

Nor is it read from the signed bounding box, which is the same for all eight
(x -44.5..+11.0, mass to the left). That test was established for **standing**
figures, where the draw anchor is the point the feet touch the ground; a prone
figure's anchor is not that, and the assumption does not travel. The project
has one recorded case of exactly that mistake, in
`notas/blog/2026-09-23_o_mesmo_argumento_certo_e_depois_errado.md`.

Indexed by descending bank offset, the convention
`../actor-sprite-sheet/subpiece_poses.py --control` reproduces 12 times out of
12. Drawn at `[HERO_X],[HERO_Y]`, so **#0138**: read from the art.

| constant | proposed name | confidence | evidence |
| --- | --- | --- | --- |
| CINEMATIC_379 | CINEMATIC_CAPSULE_HERO_CRAWL_F0 | high | 0xD8DC, highest offset in the block, 54.0x11.5/9; first frame the left-moving loop plays after the entry frame |
| CINEMATIC_380 | CINEMATIC_CAPSULE_HERO_CRAWL_F1 | high | 0xD8A8, 54.5x9.5/9 |
| CINEMATIC_381 | CINEMATIC_CAPSULE_HERO_CRAWL_F2 | high | 0xD864, 53.5x8.5/9 -- the flattest of the eight, the bottom of the body's rise and fall |
| CINEMATIC_382 | CINEMATIC_CAPSULE_HERO_CRAWL_F3 | high | 0xD824, 54.5x9.5/9 |
| CINEMATIC_383 | CINEMATIC_CAPSULE_HERO_CRAWL_F4 | high | 0xD7F8, 55.5x10.5/9 |
| CINEMATIC_384 | CINEMATIC_CAPSULE_HERO_CRAWL_F5 | high | 0xD7CC, 55.5x11.5/9 |
| CINEMATIC_385 | CINEMATIC_CAPSULE_HERO_CRAWL_F6 | high | 0xD7A0, 55.5x12.5/9 -- the tallest, the top of the rise |
| CINEMATIC_370 | CINEMATIC_CAPSULE_HERO_CRAWL_F7 | high | 0xD6DC, lowest offset in the block, 55.5x11.5/9. Drawn first by **both** loops, so it is the frame the cycle is entered on |
# CAPSULE: the prone figure raising an arm

Nine frames, nine distinct `canonical_md5`s. All share the left edge **-44.5**
-- the same prone body as `CINEMATIC_CAPSULE_HERO_CRAWL_*`, whose left edge is
also -44.5, and the routine ends by drawing two crawl frames, so it is the
same figure.

What moves is the arm. Height and right edge across the run:

    F0  12.5 / +11.0    F3  13.0 / +18.5    F6  23.5 / +13.5
    F1  12.5 / +12.5    F4  14.5 / +17.0    F7  21.5 / +12.5
    F2  13.0 / +15.5    F5  19.0 / +16.5    F8  17.0 / +13.0

The arm reaches out to +18.5 first, then lifts to 23.5 tall while drawing back
in, then settles. That is the measurement; the frames also render as a prone
figure whose arm rises and falls.

Order is the routine's own play order, which here is also ascending bank
offset -- 0xE35A, 0xE386, 0xE3B2, 0xE47E, 0xE4AA, 0xE4D6, 0xE502, 0xE52E,
0xE56A. Drawn at `[HERO_X],[HERO_Y]`, so **#0138**: read from the art.

There is a blocky shape at the end of the arm in F6 through F8 that looks like
a held object, and no name here claims one. `ARM_RAISE` is what the extents
support.

| constant | proposed name | confidence | evidence |
| --- | --- | --- | --- |
| CINEMATIC_371 | CINEMATIC_CAPSULE_HERO_PRONE_ARM_RAISE_F0 | high | 55.5x12.5/10, right edge +11.0 -- flattest and shortest reach, first frame the routine plays |
| CINEMATIC_369 | CINEMATIC_CAPSULE_HERO_PRONE_ARM_RAISE_F1 | high | 57.0x12.5/10, right edge +12.5 |
| CINEMATIC_368 | CINEMATIC_CAPSULE_HERO_PRONE_ARM_RAISE_F2 | high | 60.0x13.0/10, right edge +15.5 |
| CINEMATIC_367 | CINEMATIC_CAPSULE_HERO_PRONE_ARM_RAISE_F3 | high | 63.0x13.0/10, right edge **+18.5**, the furthest reach of the run |
| CINEMATIC_366 | CINEMATIC_CAPSULE_HERO_PRONE_ARM_RAISE_F4 | high | 61.5x14.5/10, right edge +17.0 -- reach shortening as height starts to grow |
| CINEMATIC_372 | CINEMATIC_CAPSULE_HERO_PRONE_ARM_RAISE_F5 | high | 61.0x19.0/10, right edge +16.5 |
| CINEMATIC_374 | CINEMATIC_CAPSULE_HERO_PRONE_ARM_RAISE_F6 | high | 58.0x23.5/10, **tallest** of the run at 23.5 |
| CINEMATIC_376 | CINEMATIC_CAPSULE_HERO_PRONE_ARM_RAISE_F7 | high | 57.0x21.5/11 -- the one frame with eleven paths, coming back down |
| CINEMATIC_378 | CINEMATIC_CAPSULE_HERO_PRONE_ARM_RAISE_F8 | high | 57.5x17.0/10, settling; the routine then plays two crawl frames |
