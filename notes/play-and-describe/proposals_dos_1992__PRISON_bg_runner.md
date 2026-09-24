# PRISON: the guard who runs in from the background to look

Three sentences, at frames 2805, 2806 and 3075:

- `ann:69b7dc99ab7a` on `CINEMATIC_574`: "a guard in the background runs to take
  a look and chack what's going on after he heard the sounds of shots. his body
  is represented with horizontal lines that denote quick movement."
- `ann:438cd839e6b0` on `CINEMATIC_570`: "another frame of the guard in the
  background quickly entering the scene to see what's going on"
- `ann:3c445c5992df` on `CINEMATIC_573`: "guard quickly going away, also with
  the horizontal lines to denote speed"

**Two passes, one figure, one run cycle.** Two routines draw these at the same
floor line y=175, moving in opposite directions:

    DRAW_CIN_570_574_BLOCK            574(239) 570(230)+574(230) 570(228)
                                      575(227) 575(226)              -> LEFT
    DRAW_CIN_569_TO_572_6F_AT_F8680E45  570(228) 571(232) 573(245)   -> RIGHT

`CINEMATIC_570` appears in both, which settles that these are frames of one
cycle rather than two characters: an arrival and a departure sharing a walk.
That also matches the sentences, which call 574 and 570 entering and 573 going
away.

The five figure frames measure as one figure at one scale -- 20.0 to 23.5 wide,
32.5 to 34.5 tall, 8 to 14 leaves. Two constants in the same block are **not**
figures and are named for what they are instead:

    CINEMATIC_572   11.0 x 37.0   1 leaf    re-drawn at (160,100) every frame
    CINEMATIC_569   25.5 x 35.0   6 leaves  drawn once onto page 0 at (160,100)

**The index is bank order, and says so.** The five frames sit at 0x5414, 0x54A4,
0x54E4, 0x5562, 0x55F2; nothing here establishes the cycle's phase order, so the
index is the offset run's and is not a claim about which foot falls first.

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_570 | CINEMATIC_PRISON_BACKGROUND_GUARD_RUN_F0 | high | 0x5414, first of the five figure frames by offset; 22.0x34.5 in 8 leaves; drawn in BOTH passes -- at (230,175) and (228,175) running left, and at (228,175) running right -- which is what makes the two passes one cycle; annot:438cd839e6b0 frame 2806, "the guard in the background quickly entering the scene" |
| CINEMATIC_575 | CINEMATIC_PRISON_BACKGROUND_GUARD_RUN_F1 | medium | 0x54A4, second by offset; 23.5x34.5 in 8 leaves, the same figure at the same scale; drawn at (227,175) and twice at (226,175), the end of the leftward pass. No annotation of its own; it is named from the run it belongs to |
| CINEMATIC_574 | CINEMATIC_PRISON_BACKGROUND_GUARD_RUN_F2 | high | 0x54E4, third by offset; 22.5x32.5 in 13 leaves; drawn at (239,175) then (230,175) on the leftward pass, the first frame of the arrival; annot:69b7dc99ab7a frame 2805, "a guard in the background runs to take a look ... horizontal lines that denote quick movement" |
| CINEMATIC_571 | CINEMATIC_PRISON_BACKGROUND_GUARD_RUN_F3 | medium | 0x5562, fourth by offset; 20.0x34.5 in 8 leaves; drawn at (232,175) between 570 and 573 on the rightward pass. No annotation of its own; named from the run |
| CINEMATIC_573 | CINEMATIC_PRISON_BACKGROUND_GUARD_RUN_F4 | high | 0x55F2, fifth by offset; 22.5x33.5 in 14 leaves; drawn at (245,175), the far end of the rightward pass; annot:3c445c5992df frame 3075, "guard quickly going away, also with the horizontal lines to denote speed" |
| CINEMATIC_572 | CINEMATIC_PRISON_BACKGROUND_DOORWAY_POST | medium | 0x554E, inside the same bank block and NOT a figure: 11.0x37.0 in ONE leaf, a solid vertical bar, re-drawn at the literal (160,100) after every frame of both passes. A one-polygon upright re-blitted each frame over a figure that runs past it is something the figure passes behind |
| CINEMATIC_569 | CINEMATIC_PRISON_BACKGROUND_DOORWAY_BACKDROP | medium | 0x9902, drawn ONCE at (160,100) with `selectVideoPage 0x00` around it, before either pass begins -- a backdrop laid into page 0, not an animation frame; 25.5x35.0 in 6 leaves |
