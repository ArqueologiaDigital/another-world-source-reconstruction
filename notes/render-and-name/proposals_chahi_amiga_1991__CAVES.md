# CAVES art named from a render -- chahi_amiga_1991

**These names have no independent check behind them.** They were read off a
render, at the confidence stated per row, with the measured extent and the
draw position quoted as the corrective. A rename moves no bytes, so `make
test` cannot catch one of these being wrong. They are listed here as a group
so they can be audited or reverted together.

Produced by `notes/render-and-name/sheet.py`; see that module's docstring for
the render recipe and for the three earlier wrong readings in this project
that its tile labels are designed to prevent.

| constant | proposed name | confidence | evidence |
| --- | --- | --- | --- |
| CINEMATIC_410 | CINEMATIC_CAVES_SCREEN_6C_STALAGMITE | high | 12x30, one path, a spike wide at the base and tapering to a point at the top. Drawn **four times at y=165** by `CAVES_SCREEN_6C_BACKDROP_DRAW` and by nothing else, at x=83, 136, 233 and 293 -- spread along the floor of a 200-tall screen. Floor position and upward taper agree; a shape of this silhouette drawn near y=20 would be the opposite reading, and it is not drawn there |
| CINEMATIC_408 | CINEMATIC_CAVES_SCREEN_6C_CAVERN_COLUMNS | medium | 463x284, 980 paths: a dark band across the top with four columns descending from it, each flaring where it meets the band. Drawn once at x=160, y=100 by `CAVES_SCREEN_6C_BACKDROP_DRAW` and by nothing else, and 463 wide against a 320-wide screen, so it is the scrolling backdrop rather than a prop |
| CINEMATIC_341 | CINEMATIC_CAVES_SCREEN_4D_CAVERN_COLUMNS | medium | 431x361, 327 paths, the same motif as CINEMATIC_408 -- ceiling band, columns flaring into it -- with two broad columns and a narrower pillar between. Drawn once at x=160, y=100 by `CAVES_SCREEN_4D_BACKDROP_DRAW` and by nothing else |
| CINEMATIC_332 | CINEMATIC_CAVES_SCREEN_4C_CAVERN_COLUMNS | medium | 388x242, 562 paths, the same motif again, with a stepped blocky mass at the lower left. Drawn once at x=160, y=100 by `CAVES_SCREEN_4C_BACKDROP_DRAW` and by nothing else |
# CAVES batch 2 -- read from a render

| constant | proposed name | confidence | evidence |
| --- | --- | --- | --- |
| CINEMATIC_340 | CINEMATIC_CAVES_SCREEN_4D_ARCHES | medium | 424x161, 512 paths: two arch silhouettes side by side, each springing from a pillar, with stepped blocks between and below them. Drawn once at x=160, y=100 by `CAVES_SCREEN_4D_BACKDROP_DRAW` and by nothing else. The arch outline is the one shape in this stage's backdrops that is not a column or a rock edge |
| CINEMATIC_409 | CINEMATIC_CAVES_SCREEN_6C_CAVERN_COLUMN_LARGE | medium | 367x339, 95 paths: a single column whose top flares very wide and whose stem is narrow, under a ceiling slab. Drawn once at x=160, y=100 by `CAVES_SCREEN_6C_BACKDROP_DRAW`, immediately after `CINEMATIC_CAVES_SCREEN_6C_CAVERN_COLUMNS`, which is the same motif repeated four times at smaller scale |
| CINEMATIC_333 | CINEMATIC_CAVES_SCREEN_4C_CAVERN_ARCH | medium | 327x249, 362 paths: a broad flared column left of centre with an arch springing to its right and two short pillars below. Drawn once at x=160, y=100 by `CAVES_SCREEN_4C_BACKDROP_DRAW`, alongside `CINEMATIC_CAVES_SCREEN_4C_CAVERN_COLUMNS`; the arch is what distinguishes it from that one |
# CAVES batch 3 -- read from a render

| constant | proposed name | confidence | evidence |
| --- | --- | --- | --- |
| CINEMATIC_279 | CINEMATIC_CAVES_WATERFALL | high | 198x200, 818 paths: dense vertical streaks hanging in horizontal bands, the silhouette of falling water. Two sources agree with the picture. `DRAW_WATERFALL_BG_FOUR_PASS` draws **this constant and nothing else**, four times at x=161 y=61, x=161 y=62, x=161 y=60 and x=160 y=62 across two video pages -- the one-pixel offsets that give the routine its `FOUR_PASS` name. Its other drawer, `CAVES_BUDDY_CRAWLING_SCENE_SETUP`, paints it full-screen at x=160, y=100 as that scene's background. `../sole-named-drawer/` cannot reach it because rule 3 refuses a picture two routines draw; here both routines agree |
# CAVES batch 4 -- a walk cycle read from a render

| constant | proposed name | confidence | evidence |
| --- | --- | --- | --- |
| CINEMATIC_323 | CINEMATIC_CAVES_CREATURE_WALK_RIGHT_F0 | high | rendered together in phase order, the six are a four-legged creature in profile facing right, the head high at the right and the body sloping down to the left, differing frame to frame in leg position. Six **distinct** `canonical_md5`s, so six real frames and not three alternating -- the bounding boxes pair up (51x30, 56x30, 67x30, twice each) but the art does not. This one is the sole picture of `CAVES_CREATURE_WALK_RIGHT_PHASE_1`, whose body is one `video` and a `ret`. Drawn at `x=[0x07], y=[0x08]`, the actor slot, so per #0138 the name is read from the art and not inferred from any scene |
| CINEMATIC_325 | CINEMATIC_CAVES_CREATURE_WALK_RIGHT_F1 | high | as above; the sole picture of `CAVES_CREATURE_WALK_RIGHT_PHASE_2` |
| CINEMATIC_326 | CINEMATIC_CAVES_CREATURE_WALK_RIGHT_F2 | high | as above; the sole picture of `CAVES_CREATURE_WALK_RIGHT_PHASE_3` |
| CINEMATIC_327 | CINEMATIC_CAVES_CREATURE_WALK_RIGHT_F3 | high | as above; the sole picture of `CAVES_CREATURE_WALK_RIGHT_PHASE_4` |
| CINEMATIC_328 | CINEMATIC_CAVES_CREATURE_WALK_RIGHT_F4 | high | as above; the sole picture of `CAVES_CREATURE_WALK_RIGHT_PHASE_5` |
| CINEMATIC_329 | CINEMATIC_CAVES_CREATURE_WALK_RIGHT_F5 | high | as above; the sole picture of `CAVES_CREATURE_WALK_RIGHT_PHASE_6` |
