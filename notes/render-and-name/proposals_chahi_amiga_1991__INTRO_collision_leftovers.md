# INTRO: the twelve pictures the collision handler left holding someone else's name

`notes/amiga-extra-suffix/` established what `_AMIGA_EXTRA` means -- the loser
of a name collision, renamed without either picture being looked at -- and that
`asset_naming_share.py` counts every one of them as named. This is the rest of
amiga/INTRO's list worked one render at a time, at the palette
`palette_in_force.py` reports for each drawing routine.

Two keep their base word, ten do not, and four of the ten turn out to complete
families that were already in the tree with a slot missing.

## The four that complete something

**A twelve-frame sheet with two gaps, and the two suffixed constants sit in
them.** `CINEMATIC_LESTER_HANDS_OPENING_SODA_CAN_*` runs on a perfectly regular
**12-byte stride** from 0x59BA, and the indices map straight onto it:

```
  0x59BA F0   0x59C6 F1   0x59D2 F2   0x59DE ???  0x59EA F4   0x59F6 F5
  0x5A02 F6   0x5A0E ???  0x5A1A F8   0x5A26 F9   0x5A32 F10  0x5A3E F11
```

The two `???` are `_F2_AMIGA_EXTRA` and `_F6_AMIGA_EXTRA`, and the family's
only two gaps are F3 and F7. Rendered at palette 0x13 both are a hand on a can,
the same subject as their neighbours, and they fit the size run:
F3 266.0x131.0 / 23 paths between F2's 269.5x138.5 / 32 and F4's 264.0x131.0 /
24; F7 267.5x120.5 / 21 between F6's 270.0x138.0 / 22 and F8's 279.5x128.5 /
19. Restoring them closes both gaps and renumbers nothing.

**A panel that draws itself in, whose first frame was filed as a head.**
`DRAW_CITY_SEQ_419_420` draws `..._HEAD_SIDEWAYS_AMIGA_EXTRA` and then
`CINEMATIC_HOLO_SCREEN_PANEL_FRAME_F1` and `_F2`. All three have the **same
bounding box to the half-pixel** -- 114.0x185.0 at x[24.0, 138.0] y[5.5, 190.5]
-- with 4, 7 and 9 paths: the top and bottom edges, then the sides and the
middle rule, then the right-hand thickness. It is that panel's F0, and the
family currently starts at F1, which 0-based indexing says it should not.

**A wireframe cube missing one corner.** The cube's corners sit at a 22-byte
stride -- 0xF2A0, 0xF2B6, 0xF2CC, 0xF2E2 -- and three of the four are named
`..._CORNER_TOP_LEFT`, `_TOP_RIGHT`, `_BOTTOM_LEFT`. 0xF2B6 is the fourth, and
it wears `LESTER_SEATED_AT_HOLO_CONSOLE_F0_AMIGA_EXTRA`. All four are **3
paths**, 15-22 wide, 14-17 tall, in the same y band [144.5, 162.0], and each is
a vertical edge, a horizontal edge and a receding diagonal meeting at one point.
0xF2B6's horizontal runs **left** from the foot of its vertical and its
diagonal falls to the **right**: the bottom-right corner, the one name not yet
used. `DELAY_9_BEFORE_BLITTER_SETUP` draws it three times interleaved with the
other three as the corners fly apart.

**A scroll loop whose four bands are two wrong names and two numbers.**
`LIFT_SHAFT_SCROLL_LOOP` draws four pictures at `x=153` with `y` stepping by
0x186, 0x124 and 0x183 -- a vertical tiling. All four are **exactly 4.0 wide**
and 264.5, 277.5, 386.5 and 437.5 tall, taller than the 200-pixel page, which
is what a strip that scrolls through the frame has to be. Two of them are
called `LIFT_DOORS_OPENING_F33/F34_AMIGA_EXTRA` and two are still
`CINEMATIC_505/506`. The real lift doors, `..._F0..F31`, live at 0xFBD2..0xFE6A
and measure 166.0x201.5; these four live at 0x4082..0x4158. Different region,
different shape, different job.

## The rest

| constant | drawn by | what the render shows |
|---|---|---|
| `..._SODA_CAN_F11_AMIGA_EXTRA` 0xEB16 | `LESTER_OPENS_AND_DRINKS_SODA_ANIMATION`, onto a `fill color=0x04` page that is then copied to page 0 | 255.0x144.5 in **2 paths**, one flat field. A backdrop wash, not a hand |
| `..._DRINKING_HAND_F6_AMIGA_EXTRA` 0x4F70 | `INTRO_FILL_AND_DRAW_413_414`, first of five, before `HOLO_CONSOLE_PANEL_DETAIL` and `..._DISPLAY_SCREEN` | 343.0x114.0 in **2 paths**, wider than the screen, occupying y[112.0, 226.0]. The base the console composite is built on |
| `..._HAND_PRESSING_KEYPAD_F3_AMIGA_EXTRA` 0x42BE | `LAB_DOOR_LEAVES_PARTING_LOOP`, four times at `x=160, y=111, zoom=[0x04]` while the two door leaves part | 98.0x184.5 in 14 paths: a standing figure seen from behind, dark shirt over black trousers with red hair -- the same build as `..._WALKING_AWAY_FROM_CAMERA_F5/F6`. No other constant in the stage holds this art |
| `..._HAND_PRESSING_KEYPAD_F5_AMIGA_EXTRA` 0xF606 | `LAB_AUTH_CRT_OVERLAY_STAMP_PHASE_1`, at `x=228, y=44` | 30.0x38.0 in **1 path**, one rectangle. x=228 is the auth CRT's own column -- `..._CRT_SHOWING_BIOMETRICS` is drawn at x=228 too |
| `..._WALKING_AWAY_FROM_CAMERA_F3_AMIGA_EXTRA` 0xB08E | `DRAW_BIOMETRIC_SCANNER_BG_COMPOSITE`, second of four | 79.0x62.0 in **35 paths** at x[211.0, 290.0] y[105.5, 167.5] -- a dense panel of detail under the CRT, not a figure |
| `..._WALKING_AWAY_FROM_CAMERA_F6_AMIGA_EXTRA` 0x06CC | `LAB_DOOR_SCENE_LAMP_BLINK_LOOP`, at `x=96, y=131` | **2.0x1.0 in 1 path**. Two pixels. The thing the loop blinks |

## Proposals

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_LESTER_HANDS_OPENING_SODA_CAN_F2_AMIGA_EXTRA | CINEMATIC_LESTER_HANDS_OPENING_SODA_CAN_F3 | high | 0x59DE, the F3 slot of a 12-byte stride whose only gaps are F3 and F7. 266.0x131.0, 23 paths, a hand on a can, between F2's 269.5x138.5 and F4's 264.0x131.0 |
| CINEMATIC_LESTER_HANDS_OPENING_SODA_CAN_F6_AMIGA_EXTRA | CINEMATIC_LESTER_HANDS_OPENING_SODA_CAN_F7 | high | 0x5A0E, the F7 slot of the same stride. 267.5x120.5, 21 paths, between F6's 22 and F8's 19 |
| CINEMATIC_LESTER_HEAD_SIDEWAYS_AMIGA_EXTRA | CINEMATIC_HOLO_SCREEN_PANEL_FRAME_F0 | high | 0xE974, 4 paths. Same bounding box to the half-pixel as `..._FRAME_F1` (7 paths) and `_F2` (9 paths): 114.0x185.0 at x[24.0, 138.0] y[5.5, 190.5]. Drawn immediately before them by the same routine |
| CINEMATIC_LESTER_SEATED_AT_HOLO_CONSOLE_F0_AMIGA_EXTRA | CINEMATIC_HOLO_CONSOLE_WIREFRAME_CUBE_CORNER_BOTTOM_RIGHT | high | 0xF2B6, 3 paths, 22.5x15.5. Fourth of four corners on a 22-byte stride with `_TOP_LEFT` 0xF2A0, `_TOP_RIGHT` 0xF2CC, `_BOTTOM_LEFT` 0xF2E2; its horizontal edge runs left from the foot of its vertical and its diagonal falls right |
| CINEMATIC_LIFT_DOORS_OPENING_F33_AMIGA_EXTRA | CINEMATIC_LIFT_SHAFT_SCROLL_BAND_F0 | high | 0x4158, 4.0x264.5 in 4 paths, first of the four `LIFT_SHAFT_SCROLL_LOOP` tiles at x=153 |
| CINEMATIC_LIFT_DOORS_OPENING_F34_AMIGA_EXTRA | CINEMATIC_LIFT_SHAFT_SCROLL_BAND_F1 | high | 0x410C, 4.0x277.5 in 8 paths, second tile |
| CINEMATIC_505 | CINEMATIC_LIFT_SHAFT_SCROLL_BAND_F2 | high | 0x40CE, 4.0x386.5 in 7 paths, third tile |
| CINEMATIC_506 | CINEMATIC_LIFT_SHAFT_SCROLL_BAND_F3 | high | 0x4082, 4.0x437.5 in 5 paths, fourth tile. All four are exactly 4.0 wide and taller than the 200-pixel page |
| CINEMATIC_LESTER_HAND_PRESSING_KEYPAD_F3_AMIGA_EXTRA | CINEMATIC_LESTER_STANDING_BACK_TO_CAMERA | medium | 0x42BE, 98.0x184.5 in 14 paths: a standing figure from behind. Drawn four times at a varying `zoom=[0x04]` while the lab door leaves part, and the loop then installs `LESTER_WALKING_AWAY_FROM_CAMERA_FRAME_CYCLE` |
| CINEMATIC_LESTER_HAND_PRESSING_KEYPAD_F5_AMIGA_EXTRA | CINEMATIC_LAB_AUTH_CRT_OVERLAY_STAMP | high | 0xF606, **one path**, 30.0x38.0, drawn at x=228 y=44 by `LAB_AUTH_CRT_OVERLAY_STAMP_PHASE_1`. The routine names it and the column matches the CRT's |
| CINEMATIC_LESTER_WALKING_AWAY_FROM_CAMERA_F6_AMIGA_EXTRA | CINEMATIC_LAB_DOOR_SCENE_LAMP | high | 0x06CC, **2.0x1.0 in one path**, the only picture `LAB_DOOR_SCENE_LAMP_BLINK_LOOP` draws |
| CINEMATIC_LESTER_WALKING_AWAY_FROM_CAMERA_F3_AMIGA_EXTRA | CINEMATIC_BIOMETRIC_SCANNER_CONSOLE_DETAIL | medium | 0xB08E, 79.0x62.0 in **35 paths** at x[211.0, 290.0] y[105.5, 167.5], drawn into the scanner composite just below where `..._CRT_SHOWING_BIOMETRICS` goes (x=228, y=85) |
| CINEMATIC_LESTER_HANDS_OPENING_SODA_CAN_F11_AMIGA_EXTRA | CINEMATIC_SODA_SCENE_BACKDROP | medium | 0xEB16, 255.0x144.5 in **2 paths**, drawn onto a filled page that is then copied to page 0 before any figure. A flat field |
| CINEMATIC_LESTER_DRINKING_HAND_F6_AMIGA_EXTRA | CINEMATIC_HOLO_CONSOLE_ROOM_BACKDROP | medium | 0x4F70, 343.0x114.0 in **2 paths**, wider than the screen at y[112.0, 226.0], first picture of `INTRO_FILL_AND_DRAW_413_414`'s five-picture composite |

## What these names do not claim

The four completions are the strong ones: a 12-byte stride with gaps exactly
where the suffixed constants sit, three pictures sharing a bounding box to the
half-pixel, a 22-byte stride of four corners with one name unused, and four
tiles of identical width in one scroll loop. None of those rests on reading a
silhouette.

The six graded `medium` do rest on reading a picture, and each says only what
is visible: a standing figure from behind (not which frame of which walk), a
rectangle on a CRT (not what it displays), a two-pixel mark a loop blinks (not
what it is meant to be), a dense panel beside the scanner's CRT, and two flat
fields laid down before anything else in their composites.

`SODA_SCENE` and `HOLO_CONSOLE_ROOM` come from the routines that draw them,
`LESTER_OPENS_AND_DRINKS_SODA_ANIMATION` and `INTRO_FILL_AND_DRAW_413_414`'s
own `HOLO_CONSOLE_*` neighbours. `LIFT_SHAFT_SCROLL` is `LIFT_SHAFT_SCROLL_LOOP`
verbatim.
