# INTRO (msdos): the same twelve leftovers, matched by art

Evidence, renders and reasoning in
`proposals_chahi_amiga_1991__INTRO_collision_leftovers.md`. Each row below is
the msdos constant whose `canonical_md5` equals the amiga one's -- never the
same index, which for two of them is a different picture entirely (#0107).

Two amiga rows have no msdos row here, for opposite reasons.

**The lift shaft bands are amiga-only.** msdos defines none of 0x4158, 0x410C
or 0x40CE, has no `LIFT_SHAFT_SCROLL_LOOP`, and draws the one picture it does
share -- 0x4082, which it calls `CINEMATIC_466` -- at a **fixed** `x=153,
y=114` from `INIT_PAGE0_PAUSE2_FILL1`. Giving that one constant
`..._SCROLL_BAND_F3` would claim a scroll msdos does not perform and a family
of one whose index starts at 3. It keeps its number.

**The lamp is matched by its draw site, not by its hash**, for the reason given
in its row.

## Proposals

| old | new | confidence | evidence |
|---|---|---|---|
| CINEMATIC_LESTER_HANDS_OPENING_SODA_CAN_F2_AMIGA_EXTRA | CINEMATIC_LESTER_HANDS_OPENING_SODA_CAN_F3 | high | 0x5950, `7a7bfe3397a5` -- identical art to amiga's `CINEMATIC_LESTER_HANDS_OPENING_SODA_CAN_F2_AMIGA_EXTRA` |
| CINEMATIC_LESTER_HANDS_OPENING_SODA_CAN_F6_AMIGA_EXTRA | CINEMATIC_LESTER_HANDS_OPENING_SODA_CAN_F7 | high | 0x5980, `510d2306ed67` -- identical art to amiga's `CINEMATIC_LESTER_HANDS_OPENING_SODA_CAN_F6_AMIGA_EXTRA` |
| CINEMATIC_LESTER_HEAD_SIDEWAYS_AMIGA_EXTRA | CINEMATIC_HOLO_SCREEN_PANEL_FRAME_F0 | high | 0xE8E6, `91023dce60dc` -- identical art to amiga's `CINEMATIC_LESTER_HEAD_SIDEWAYS_AMIGA_EXTRA` |
| CINEMATIC_LESTER_SEATED_AT_HOLO_CONSOLE_F0_AMIGA_EXTRA | CINEMATIC_HOLO_CONSOLE_WIREFRAME_CUBE_CORNER_BOTTOM_RIGHT | high | 0xF228, `e843eb2c0435` -- identical art to amiga's `CINEMATIC_LESTER_SEATED_AT_HOLO_CONSOLE_F0_AMIGA_EXTRA` |
| CINEMATIC_LESTER_HAND_PRESSING_KEYPAD_F3_AMIGA_EXTRA | CINEMATIC_LESTER_STANDING_BACK_TO_CAMERA | medium | 0x4230, `69b043b9dbde` -- identical art to amiga's `CINEMATIC_LESTER_HAND_PRESSING_KEYPAD_F3_AMIGA_EXTRA` |
| CINEMATIC_LESTER_HAND_PRESSING_KEYPAD_F5_AMIGA_EXTRA | CINEMATIC_LAB_AUTH_CRT_OVERLAY_STAMP | high | 0xF578, `0835b7133ad6` -- identical art to amiga's `CINEMATIC_LESTER_HAND_PRESSING_KEYPAD_F5_AMIGA_EXTRA` |
| CINEMATIC_LESTER_WALKING_AWAY_FROM_CAMERA_F3_AMIGA_EXTRA | CINEMATIC_BIOMETRIC_SCANNER_CONSOLE_DETAIL | medium | 0xB000, `6d39f3b1d9ba` -- identical art to amiga's `CINEMATIC_LESTER_WALKING_AWAY_FROM_CAMERA_F3_AMIGA_EXTRA` |
| CINEMATIC_LESTER_HANDS_OPENING_SODA_CAN_F11_AMIGA_EXTRA | CINEMATIC_SODA_SCENE_BACKDROP | medium | 0xEA88, `92fc563a4e25` -- identical art to amiga's `CINEMATIC_LESTER_HANDS_OPENING_SODA_CAN_F11_AMIGA_EXTRA` |
| CINEMATIC_LESTER_DRINKING_HAND_F6_AMIGA_EXTRA | CINEMATIC_HOLO_CONSOLE_ROOM_BACKDROP | medium | 0x4EE2, `4e6704d00d9b` -- identical art to amiga's `CINEMATIC_LESTER_DRINKING_HAND_F6_AMIGA_EXTRA` |
| CINEMATIC_LESTER_WALKING_AWAY_FROM_CAMERA_F6_AMIGA_EXTRA | CINEMATIC_LAB_DOOR_SCENE_LAMP | high | 0x06CC -- **not matched by hash**: at 2.0x1.0 in one path its `canonical_md5` is shared with ten other dos constants, so a hash match would prove nothing. Matched instead by the three things that are unique: same constant name, same offset 0x06CC as amiga, and the same single draw `x=96, y=131` in the same lamp-blink loop |
