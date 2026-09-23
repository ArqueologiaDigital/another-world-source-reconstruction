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
