# PRISON (amiga): two background miners, one ten-frame pick swing, mirrored

Three annotations, and the bytecode gives the other seventeen names:

- `ann:4a7cae1fdd83` on `CINEMATIC_006` (f118): "This is part of the body of one
  of the people who's mining at the background. Not sure but maybe those are
  prisoners doing force work..."
- `ann:8458404ed1c9` on `CINEMATIC_008` (f120): "another frame of the person
  mining in the background - this one seems to convey part of the arm movement
  while holding a pickaxe"
- `ann:ccb56f798965` on `CINEMATIC_018` (f121): "body of another background miner"

**"Another" is the finding.** There are two, and they are the same animation
mirrored.

## Ten frames twice, and the pairing is exact

`CINEMATIC_004..013` and `CINEMATIC_014..023` are drawn at the same anchor
`[0x24],[0x25]` by two structurally identical chains of routines, each stepping
through `INCREMENT_VAR27_AND_DISPATCH` between frames -- lines 4091-4163 and
4010-4082 of `dos_1992/PRISON.asm`. Frame for frame:

    k   004..013            014..023            leaves
    0   5.5 x  8.0          6.5 x  8.0          2 = 2
    1  10.0 x 14.5          9.0 x 14.5          4 = 4
    2   5.5 x 12.0          6.5 x 12.0          3 = 3
    3  10.0 x 10.5         10.0 x 10.5          5 = 5
    4  11.0 x 16.0         11.0 x 16.0          5 = 5
    5  11.0 x 21.0         10.0 x 21.0          5 = 5
    6  13.0 x 20.0         13.0 x 20.0          5 = 5
    7  20.0 x  8.5         20.0 x  8.5          5 = 5
    8  17.5 x 11.5         17.5 x 11.5          5 = 5
    9  13.0 x 13.0         14.0 x 13.0          5 = 5

**Identical height and identical leaf count on all ten pairs.** And they are
mirrors: fitting one reflection axis across all twenty x-ranges lands on
x = 4.5 with an average endpoint error of **0.35 px**, every pair inside 1.0 --

    k=7   004..013 spans x[-12.0, 8.0]   mirrored -> [1.0, 21.0]   014..023 x[1.0, 21.0]

## The swing is in the heights, and the direction in the widths

Heights across the run: 8.0, 14.5, 12.0, 10.5, 16.0, **21.0**, 20.0, **8.5**,
11.5, 13.0. Tallest at frame 5, then the flattest and widest at frame 7 --
20.0 x 8.5. Something raised overhead and then driven down and out. That is the
"arm movement while holding a pickaxe" the annotation describes, arrived at from
the extents.

The direction follows from where the tool goes in those frames: `004..013`
reaches to x = -12 (left of the anchor) and `014..023` to x = +21 (right). So
`004..013` swings left and `014..023` swings right.

MINER is the subject word from the annotations and is a role, not a character
identity, so `../actor-anchors/` does not bear on it -- unlike GUARD, nothing
here claims *which* individual. The annotator's own hedge, "maybe those are
prisoners doing force work", is deliberately not in any name.

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_004 | CINEMATIC_PRISON_BACKGROUND_MINER_SWING_LEFT_F0 | high | 0x9896, frame 0 of the ten-frame swing; 5.5x8.0 in 2 leaves, the same height and leaf count as its RIGHT twin at frame 0; no annotation of its own -- named from the run it belongs to |
| CINEMATIC_005 | CINEMATIC_PRISON_BACKGROUND_MINER_SWING_LEFT_F1 | high | 0x96AA, frame 1 of the ten-frame swing; 10.0x14.5 in 4 leaves, the same height and leaf count as its RIGHT twin at frame 1; no annotation of its own -- named from the run it belongs to |
| CINEMATIC_006 | CINEMATIC_PRISON_BACKGROUND_MINER_SWING_LEFT_F2 | high | 0x96FA, frame 2 of the ten-frame swing; 5.5x12.0 in 3 leaves, the same height and leaf count as its RIGHT twin at frame 2; annot:4a7cae1fdd83 frame 118, "part of the body of one of the people who's mining at the background" |
| CINEMATIC_007 | CINEMATIC_PRISON_BACKGROUND_MINER_SWING_LEFT_F3 | high | 0x970A, frame 3 of the ten-frame swing; 10.0x10.5 in 5 leaves, the same height and leaf count as its RIGHT twin at frame 3; no annotation of its own -- named from the run it belongs to |
| CINEMATIC_008 | CINEMATIC_PRISON_BACKGROUND_MINER_SWING_LEFT_F4 | high | 0x9722, frame 4 of the ten-frame swing; 11.0x16.0 in 5 leaves, the same height and leaf count as its RIGHT twin at frame 4; annot:8458404ed1c9 frame 120, "another frame of the person mining in the background - this one seems to convey part of the arm movement while holding a pickaxe" |
| CINEMATIC_009 | CINEMATIC_PRISON_BACKGROUND_MINER_SWING_LEFT_F5 | high | 0x973A, frame 5 of the ten-frame swing; 11.0x21.0 in 5 leaves, the same height and leaf count as its RIGHT twin at frame 5; no annotation of its own -- named from the run it belongs to |
| CINEMATIC_010 | CINEMATIC_PRISON_BACKGROUND_MINER_SWING_LEFT_F6 | high | 0x9752, frame 6 of the ten-frame swing; 13.0x20.0 in 5 leaves, the same height and leaf count as its RIGHT twin at frame 6; no annotation of its own -- named from the run it belongs to |
| CINEMATIC_011 | CINEMATIC_PRISON_BACKGROUND_MINER_SWING_LEFT_F7 | high | 0x976A, frame 7 of the ten-frame swing; 20.0x8.5 in 5 leaves, the same height and leaf count as its RIGHT twin at frame 7; no annotation of its own -- named from the run it belongs to |
| CINEMATIC_012 | CINEMATIC_PRISON_BACKGROUND_MINER_SWING_LEFT_F8 | high | 0x9782, frame 8 of the ten-frame swing; 17.5x11.5 in 5 leaves, the same height and leaf count as its RIGHT twin at frame 8; no annotation of its own -- named from the run it belongs to |
| CINEMATIC_013 | CINEMATIC_PRISON_BACKGROUND_MINER_SWING_LEFT_F9 | high | 0x979A, frame 9 of the ten-frame swing; 13.0x13.0 in 5 leaves, the same height and leaf count as its RIGHT twin at frame 9; no annotation of its own -- named from the run it belongs to |
| CINEMATIC_014 | CINEMATIC_PRISON_BACKGROUND_MINER_SWING_RIGHT_F0 | high | 0x98A2, frame 0 of the ten-frame swing; 6.5x8.0 in 2 leaves, the same height and leaf count as its LEFT twin at frame 0; no annotation of its own -- named from the run it belongs to |
| CINEMATIC_015 | CINEMATIC_PRISON_BACKGROUND_MINER_SWING_RIGHT_F1 | high | 0x94CA, frame 1 of the ten-frame swing; 9.0x14.5 in 4 leaves, the same height and leaf count as its LEFT twin at frame 1; no annotation of its own -- named from the run it belongs to |
| CINEMATIC_016 | CINEMATIC_PRISON_BACKGROUND_MINER_SWING_RIGHT_F2 | high | 0x950E, frame 2 of the ten-frame swing; 6.5x12.0 in 3 leaves, the same height and leaf count as its LEFT twin at frame 2; no annotation of its own -- named from the run it belongs to |
| CINEMATIC_017 | CINEMATIC_PRISON_BACKGROUND_MINER_SWING_RIGHT_F3 | high | 0x952A, frame 3 of the ten-frame swing; 10.0x10.5 in 5 leaves, the same height and leaf count as its LEFT twin at frame 3; no annotation of its own -- named from the run it belongs to |
| CINEMATIC_018 | CINEMATIC_PRISON_BACKGROUND_MINER_SWING_RIGHT_F4 | high | 0x955A, frame 4 of the ten-frame swing; 11.0x16.0 in 5 leaves, the same height and leaf count as its LEFT twin at frame 4; annot:ccb56f798965 frame 121, "body of another background miner" |
| CINEMATIC_019 | CINEMATIC_PRISON_BACKGROUND_MINER_SWING_RIGHT_F5 | high | 0x9596, frame 5 of the ten-frame swing; 10.0x21.0 in 5 leaves, the same height and leaf count as its LEFT twin at frame 5; no annotation of its own -- named from the run it belongs to |
| CINEMATIC_020 | CINEMATIC_PRISON_BACKGROUND_MINER_SWING_RIGHT_F6 | high | 0x95C6, frame 6 of the ten-frame swing; 13.0x20.0 in 5 leaves, the same height and leaf count as its LEFT twin at frame 6; no annotation of its own -- named from the run it belongs to |
| CINEMATIC_021 | CINEMATIC_PRISON_BACKGROUND_MINER_SWING_RIGHT_F7 | high | 0x9602, frame 7 of the ten-frame swing; 20.0x8.5 in 5 leaves, the same height and leaf count as its LEFT twin at frame 7; no annotation of its own -- named from the run it belongs to |
| CINEMATIC_022 | CINEMATIC_PRISON_BACKGROUND_MINER_SWING_RIGHT_F8 | high | 0x963E, frame 8 of the ten-frame swing; 17.5x11.5 in 5 leaves, the same height and leaf count as its LEFT twin at frame 8; no annotation of its own -- named from the run it belongs to |
| CINEMATIC_023 | CINEMATIC_PRISON_BACKGROUND_MINER_SWING_RIGHT_F9 | high | 0x967A, frame 9 of the ten-frame swing; 14.0x13.0 in 5 leaves, the same height and leaf count as its LEFT twin at frame 9; no annotation of its own -- named from the run it belongs to |
