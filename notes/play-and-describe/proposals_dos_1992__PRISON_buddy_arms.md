# PRISON: Buddy's two gestures, completed

The first pass named two of these from two sentences and left the middle of both
runs numbered. Five more sentences from the second play session close them:

- `ann:a18725eb7b33` on `CINEMATIC_442` (f1152): "buddy's right arm tapping at lester's right
  shoulder"
- on `CINEMATIC_443` (f1153): "buddy's right arm at lester's shoulder"
- on `CINEMATIC_444` (f1154): "buddy's arm on lester's shoulder"
- on `CINEMATIC_445` (f1170): "first frame of the movement that buddy makes with
  the right arm to point forward (indicating lester...)"
- on `CINEMATIC_446` (f1172): "second frame of the movement that buddy makes
  with the right arm to point forward"

## Two contiguous runs, two gestures

    tap     0x8BAE  0x8BEA  0x8C32  0x8C7E          441 442 443 444
    point   0x87A2  0x87DE  0x882A                  445 446 447

Two separate contiguous blocks in the bank, and the extents say what each is:

    441  24.0 x 21.0   4 leaves   x reaches 17.5   y[-53.5,-32.5]
    442  29.0 x 14.5   5 leaves   x reaches 24.0   y[-53.0,-38.5]
    443  30.0 x 17.5   5 leaves   x reaches 24.5   y[-53.5,-36.0]
    444  31.0 x 18.5   5 leaves   x reaches 25.5   y[-53.5,-35.0]

    445  15.0 x 19.5   3 leaves   x reaches  9.0   y[-56.5,-37.0]
    446  23.5 x 11.5   5 leaves   x reaches 17.5   y[-52.5,-41.0]
    447  35.0 x 11.5   6 leaves   x reaches 29.0   y[-52.0,-40.5]

The tap run holds at y[-53.5, -35] -- **shoulder height** on a figure whose head
family sits at y[-60,-48] -- and reaches out 17.5 -> 25.5. The point run
straightens: reach 9.0 -> 17.5 -> 29.0 while the height collapses 19.5 -> 11.5
-> 11.5. An arm extending to horizontal.

Both are drawn over `PRISON_BUDDY_SIMPLE_DRAW_CIN164_167_CV291`, which lays the
body, and `play id=0x0073` fires on the tap.

The index is each run's own offset order. The two already-named members become
`_F0` and `_F2` of their runs, which is what they were; the names simply did not
say it while the middles were numbered.

BUDDY is admissible in this scene and not in the guard scene: the body under
these arms is drawn by a routine the tree already calls BUDDY, the person says
Buddy throughout, and `../actor-anchors/` places the changeover at the cage
collapse, which is 3000 frames earlier.

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_PRISON_BUDDY_ARM_TAP | CINEMATIC_PRISON_BUDDY_ARM_TAP_F0 | high | 0x8BAE, first of the contiguous run 0x8BAE 0x8BEA 0x8C32 0x8C7E; 24.0x21.0 in 4 leaves reaching x=17.5 at y[-53.5,-32.5], shoulder height; `play id=0x0073` fires on it. Gains its index now that the rest of the run is named |
| CINEMATIC_442 | CINEMATIC_PRISON_BUDDY_ARM_TAP_F1 | high | 0x8BEA, second of the run; 29.0x14.5 in 5 leaves reaching x=24.0; annot:a18725eb7b33 frame 1152, "buddy's right arm tapping at lester's right shoulder" |
| CINEMATIC_443 | CINEMATIC_PRISON_BUDDY_ARM_TAP_F2 | high | 0x8C32, third; 30.0x17.5 in 5 leaves reaching x=24.5; annot:d5c9c497f7e6 frame 1153, "buddy's right arm at lester's shoulder" |
| CINEMATIC_444 | CINEMATIC_PRISON_BUDDY_ARM_TAP_F3 | high | 0x8C7E, last of the run; 31.0x18.5 in 5 leaves reaching x=25.5, the furthest of the four; annot:f4770174c965 frame 1154, "buddy's arm on lester's shoulder" |
| CINEMATIC_445 | CINEMATIC_PRISON_BUDDY_ARM_POINT_RIGHT_F0 | high | 0x87A2, first of the contiguous run 0x87A2 0x87DE 0x882A; 15.0x19.5 in 3 leaves reaching only x=9.0 -- the arm still folded; annot:5703ca73019d frame 1170, "first frame of the movement that buddy makes with the right arm to point forward" |
| CINEMATIC_446 | CINEMATIC_PRISON_BUDDY_ARM_POINT_RIGHT_F1 | high | 0x87DE, second; 23.5x11.5 in 5 leaves reaching x=17.5, the height already collapsed from 19.5 to 11.5 as the arm straightens; annot:99dcb895d576 frame 1172, "second frame of the movement" |
| CINEMATIC_PRISON_BUDDY_ARM_POINT_RIGHT | CINEMATIC_PRISON_BUDDY_ARM_POINT_RIGHT_F2 | high | 0x882A, last of the run; 35.0x11.5 in 6 leaves reaching x=29.0, three times wider than tall -- fully extended. Gains its index now that the run is named |
