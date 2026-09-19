.if BRANCH == "chahi_amiga_1991"
CINEMATIC_BIOMETRIC_SCANNER_BEAM_LINE		EQU 0x4BCA
CINEMATIC_129		EQU 0xAF5E
.else
CINEMATIC_LESTER_HAND_PRESSING_KEYPAD_F3_AMIGA_EXTRA		EQU 0x4230
CINEMATIC_129		EQU 0x4290
.endif
.if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
CINEMATIC_LESTER_WALKING_TOWARDS_CAMERA_F0		EQU 0x18F6
.endif
.if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
CINEMATIC_LESTER_WALKING_TOWARDS_CAMERA_F1		EQU 0x1972
.endif
CINEMATIC_LESTER_WALKING_TOWARDS_CAMERA_F2		EQU 0x19F2
CINEMATIC_LESTER_WALKING_TOWARDS_CAMERA_F3		EQU 0x1A72
CINEMATIC_LESTER_WALKING_TOWARDS_CAMERA_F4		EQU 0x1AF2
CINEMATIC_LESTER_WALKING_TOWARDS_CAMERA_F5		EQU 0x1B72
CINEMATIC_LESTER_WALKING_TOWARDS_CAMERA_F6		EQU 0x1BF2
CINEMATIC_LESTER_WALKING_TOWARDS_CAMERA_F7		EQU 0x180A
.if BRANCH == "chahi_amiga_1991"
CINEMATIC_LESTER_WALKING_AWAY_FROM_CAMERA_F0		EQU 0x42D6
CINEMATIC_LESTER_WALKING_AWAY_FROM_CAMERA_F1		EQU 0x42EE
CINEMATIC_LESTER_WALKING_AWAY_FROM_CAMERA_F2		EQU 0xAFC2
CINEMATIC_LESTER_WALKING_AWAY_FROM_CAMERA_F3		EQU 0x4336
CINEMATIC_LESTER_WALKING_AWAY_FROM_CAMERA_F4		EQU 0x434E
CINEMATIC_LESTER_WALKING_AWAY_FROM_CAMERA_F5		EQU 0x4366
CINEMATIC_LESTER_WALKING_AWAY_FROM_CAMERA_F6		EQU 0x42A6
.else
CINEMATIC_LESTER_WALKING_AWAY_FROM_CAMERA_F0		EQU 0x4248
CINEMATIC_LESTER_WALKING_AWAY_FROM_CAMERA_F1		EQU 0x4260
CINEMATIC_LESTER_WALKING_AWAY_FROM_CAMERA_F2		EQU 0x4278
CINEMATIC_LESTER_WALKING_AWAY_FROM_CAMERA_F3		EQU 0x42A8
CINEMATIC_LESTER_WALKING_AWAY_FROM_CAMERA_F4		EQU 0x42C0
CINEMATIC_LESTER_WALKING_AWAY_FROM_CAMERA_F5		EQU 0x42D8
CINEMATIC_LESTER_WALKING_AWAY_FROM_CAMERA_F6		EQU 0x4218
.endif
CINEMATIC_LESTER_WALKING_AWAY_FROM_CAMERA_F6_AMIGA_EXTRA		EQU 0x06CC

LAB_DOOR_OPENING_INIT:
	mov [0x04], 0x005E
	setPalette 0x0E
	mov [0x01], 0x0064
	mov [0x02], 0x0064
	mov [0x03], 0x0009
	setup channel=0x04, address=LAB_DOOR_SCENE_LAMP_BLINK_LOOP
	copyVideoPage src=0x03, dst=0x00
	copyVideoPage src=0x00, dst=0xFF
	play id=0x000C, freq=0x0F, vol=0x3F, channel=0x02

LAB_DOOR_LEAVES_PARTING_LOOP:
	sub [0x01], 0x0014
	add [0x02], 0x0014
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_121, x=160, y=[0x01]
	video offset=CINEMATIC_122, x=160, y=[0x02]
	video offset=CINEMATIC_LESTER_HAND_PRESSING_KEYPAD_F3_AMIGA_EXTRA, x=160, y=111, zoom=[0x04]
	je [MUS_MARK], 0x10, MUS_10_FORCE_KILL_CHANNELS
.else
	video offset=CINEMATIC_126, x=160, y=[0x01]
	video offset=CINEMATIC_127, x=160, y=[0x02]
	video offset=CINEMATIC_LESTER_HAND_PRESSING_KEYPAD_F3_AMIGA_EXTRA, x=160, y=111, zoom=[0x04]
	je [MUS_MARK], 0x10, PARALLAX_LOOP_BREAK_AND_DJNZ
.endif

.if BRANCH != "chahi_amiga_1991"
PARALLAX_LOOP_BREAK_AND_DJNZ:
.endif
	break
	djnz [0x03], LAB_DOOR_LEAVES_PARTING_LOOP
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_LESTER_HAND_PRESSING_KEYPAD_F3_AMIGA_EXTRA, x=160, y=111, zoom=[0x04]
.else
	video offset=CINEMATIC_LESTER_HAND_PRESSING_KEYPAD_F3_AMIGA_EXTRA, x=160, y=111, zoom=[0x04]
.endif
	setup channel=0x08, address=LESTER_WALKING_AWAY_FROM_CAMERA_FRAME_CYCLE
	setup channel=0x09, address=LAB_DOOR_LEAVES_REDRAW_LOOP
	setup channel=0x05, address=INTRO_DOT_PAIR_CROSSING_SWEEP_CYCLE_INIT
	mov [0x03], 0x0007

ZOOM_OUT_VAR4_M3_LOOP:
	sub [0x04], 0x0003
.if BRANCH == "chahi_amiga_1991"
	je [MUS_MARK], 0x10, MUS_10_FORCE_KILL_CHANNELS
.else
	je [MUS_MARK], 0x10, ZOOM_OUT_BREAK_AND_DJNZ
.endif

.if BRANCH != "chahi_amiga_1991"
ZOOM_OUT_BREAK_AND_DJNZ:
.endif
	break
	djnz [0x03], ZOOM_OUT_VAR4_M3_LOOP
	play id=0x000C, freq=0x0A, vol=0x32, channel=0x02
	mov [0x03], 0x0003

PARALLAX_REVERSE_3X:
	add [0x01], 0x0014
	sub [0x02], 0x0014
	add [0x04], 0x0000
.if BRANCH == "chahi_amiga_1991"
	je [MUS_MARK], 0x10, MUS_10_FORCE_KILL_CHANNELS
.else
	je [MUS_MARK], 0x10, PARALLAX_REV_BREAK_AND_DJNZ
.endif

.if BRANCH != "chahi_amiga_1991"
PARALLAX_REV_BREAK_AND_DJNZ:
.endif
	break
	djnz [0x03], PARALLAX_REVERSE_3X
	setup channel=0x08, address=KILL_CHANNEL_ROUTINE
	add [0x01], 0x0014
	sub [0x02], 0x0014
	break
	mov [0x03], 0x0005

LAB_DOOR_LEAVES_SHUT_LOOP:
	add [0x01], 0x0014
	sub [0x02], 0x0014
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_518, x=160, y=111, zoom=[0x04]
.else
	video offset=CINEMATIC_129, x=160, y=111, zoom=[0x04]
.endif
.if BRANCH != "chahi_amiga_1991"
	je [MUS_MARK], 0x10, MUS_10_FORCE_KILL_CHANNELS
.endif
	break
	djnz [0x03], LAB_DOOR_LEAVES_SHUT_LOOP
	play id=0x0036, freq=0x0F, vol=0x3F, channel=0x02

MUS_10_FORCE_KILL_CHANNELS:
	setup channel=0x05, address=KILL_CHANNEL_ROUTINE
	setup channel=0x04, address=KILL_CHANNEL_ROUTINE
	setup channel=0x08, address=KILL_CHANNEL_ROUTINE
	setup channel=0x09, address=KILL_CHANNEL_ROUTINE
	setup channel=0x01, address=DRAW_BIOMETRIC_SCANNER_BG_COMPOSITE
	setup channel=0x02, address=INTRO_PAUSE_3_PLAY_SONG_INIT
.if BRANCH != "chahi_amiga_1991"
	setup channel=0x3C, address=BLIT_AND_COPY_PAGE_FF_LOOP
.endif
	killChannel

INTRO_DOT_PAIR_CROSSING_SWEEP_CYCLE_INIT:
	mov [0x06], 0x007A
	mov [0x07], 0x0082
	mov [0x08], 0x0005

INTRO_DOT_PAIR_CROSSING_SWEEP_STEP_LOOP:
	mov [0x09], 0x0003

INTRO_DOT_PAIR_CROSSING_SWEEP_HOLD_LOOP:
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_124, x=[0x06], y=16
	video offset=CINEMATIC_124, x=[0x07], y=18
.else
	video offset=CINEMATIC_130, x=[0x06], y=16
	video offset=CINEMATIC_130, x=[0x07], y=18
.endif
	break
	djnz [0x09], INTRO_DOT_PAIR_CROSSING_SWEEP_HOLD_LOOP
	add [0x06], 0x0002
	sub [0x07], 0x0002
	djnz [0x08], INTRO_DOT_PAIR_CROSSING_SWEEP_STEP_LOOP
	jmp INTRO_DOT_PAIR_CROSSING_SWEEP_CYCLE_INIT
LABEL_21B9:
.if BRANCH == "dos_1992"
	db 0x11
.else
.if BRANCH == "chahi_amiga_1991"
	db 0x11
.else
	killChannel
.endif
.endif

LAB_DOOR_SCENE_LAMP_BLINK_LOOP:
	break
	selectVideoPage 0x00
	video offset=CINEMATIC_LESTER_WALKING_AWAY_FROM_CAMERA_F6_AMIGA_EXTRA, x=96, y=131
	selectVideoPage 0xFF
	mov [0x05], 0x0003

LAB_DOOR_SCENE_LAMP_SWAP_HOLD:
	break
	djnz [0x05], LAB_DOOR_SCENE_LAMP_SWAP_HOLD
	selectVideoPage 0x00
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_124, x=96, y=131
.else
	video offset=CINEMATIC_130, x=96, y=131
.endif
	selectVideoPage 0xFF
	mov [0x05], 0x0004

LESTER_WALKING_AWAY_FROM_CAMERA_ANIMATION:
	break
	djnz [0x05], LESTER_WALKING_AWAY_FROM_CAMERA_ANIMATION
	jmp LAB_DOOR_SCENE_LAMP_BLINK_LOOP
LABEL_21E0:
.if BRANCH == "dos_1992"
	db 0x11
.else
.if BRANCH == "chahi_amiga_1991"
	db 0x11
.else
	killChannel
.endif
.endif

LAB_DOOR_LEAVES_REDRAW_LOOP:
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_121, x=160, y=[0x01]
	video offset=CINEMATIC_122, x=160, y=[0x02]
.else
	video offset=CINEMATIC_126, x=160, y=[0x01]
	video offset=CINEMATIC_127, x=160, y=[0x02]
.endif
	break
	jmp LAB_DOOR_LEAVES_REDRAW_LOOP
LABEL_21EF:
.if BRANCH == "dos_1992"
	db 0x11
.else
.if BRANCH == "chahi_amiga_1991"
	db 0x11
.else
	killChannel
.endif
.endif

LESTER_WALKING_AWAY_FROM_CAMERA_FRAME_CYCLE:
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_LESTER_HAND_PRESSING_KEYPAD_F3_AMIGA_EXTRA, x=160, y=111, zoom=[0x04]
.else
	video offset=CINEMATIC_LESTER_HAND_PRESSING_KEYPAD_F3_AMIGA_EXTRA, x=160, y=111, zoom=[0x04]
.endif
	break
	video offset=CINEMATIC_LESTER_WALKING_AWAY_FROM_CAMERA_F0, x=160, y=111, zoom=[0x04]
	break
	video offset=CINEMATIC_LESTER_WALKING_AWAY_FROM_CAMERA_F1, x=160, y=111, zoom=[0x04]
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_517, x=160, y=111, zoom=[0x04]
.else
	video offset=CINEMATIC_LESTER_WALKING_AWAY_FROM_CAMERA_F2, x=160, y=111, zoom=[0x04]
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_518, x=160, y=111, zoom=[0x04]
.else
	video offset=CINEMATIC_129, x=160, y=111, zoom=[0x04]
.endif
	break
	video offset=CINEMATIC_LESTER_WALKING_AWAY_FROM_CAMERA_F3, x=160, y=111, zoom=[0x04]
	break
	video offset=CINEMATIC_LESTER_WALKING_AWAY_FROM_CAMERA_F4, x=160, y=111, zoom=[0x04]
	break
	video offset=CINEMATIC_LESTER_WALKING_AWAY_FROM_CAMERA_F5, x=160, y=111, zoom=[0x04]
	break
	video offset=CINEMATIC_LESTER_WALKING_AWAY_FROM_CAMERA_F4, x=160, y=111, zoom=[0x04]
	break
	video offset=CINEMATIC_LESTER_WALKING_AWAY_FROM_CAMERA_F3, x=160, y=111, zoom=[0x04]
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_518, x=160, y=111, zoom=[0x04]
.else
	video offset=CINEMATIC_129, x=160, y=111, zoom=[0x04]
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_517, x=160, y=111, zoom=[0x04]
.else
	video offset=CINEMATIC_LESTER_WALKING_AWAY_FROM_CAMERA_F2, x=160, y=111, zoom=[0x04]
.endif
	break
	video offset=CINEMATIC_LESTER_WALKING_AWAY_FROM_CAMERA_F1, x=160, y=111, zoom=[0x04]
	break
	video offset=CINEMATIC_LESTER_WALKING_AWAY_FROM_CAMERA_F0, x=160, y=111, zoom=[0x04]
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_LESTER_HAND_PRESSING_KEYPAD_F3_AMIGA_EXTRA, x=160, y=111, zoom=[0x04]
.else
	video offset=CINEMATIC_LESTER_HAND_PRESSING_KEYPAD_F3_AMIGA_EXTRA, x=160, y=111, zoom=[0x04]
.endif
	break
	video offset=CINEMATIC_LESTER_WALKING_AWAY_FROM_CAMERA_F6, x=160, y=111, zoom=[0x04]
	break
	jmp LESTER_WALKING_AWAY_FROM_CAMERA_FRAME_CYCLE
LABEL_2263:
.if BRANCH == "dos_1992"
	db 0x11
.else
.if BRANCH == "chahi_amiga_1991"
	db 0x11
.else
	killChannel
.endif
.endif

LESTER_WALKING_TOWARDS_CAMERA_ANIMATION:
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_466, x=160, y=111, zoom=[0x04]
.else
	video offset=CINEMATIC_468, x=160, y=111, zoom=[0x04]
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_LESTER_WALKING_TOWARDS_CAMERA_F0, x=160, y=111, zoom=[0x04]
.else
	video offset=CINEMATIC_LESTER_WALKING_TOWARDS_CAMERA_F0, x=160, y=111, zoom=[0x04]
.endif
	break
	play id=0x003C, freq=0x0A, vol=0x0F, channel=0x02
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_LESTER_WALKING_TOWARDS_CAMERA_F1, x=160, y=111, zoom=[0x04]
.else
	video offset=CINEMATIC_LESTER_WALKING_TOWARDS_CAMERA_F1, x=160, y=111, zoom=[0x04]
.endif
	break
	video offset=CINEMATIC_LESTER_WALKING_TOWARDS_CAMERA_F2, x=160, y=111, zoom=[0x04]
	break
	video offset=CINEMATIC_LESTER_WALKING_TOWARDS_CAMERA_F3, x=160, y=111, zoom=[0x04]
	break
	video offset=CINEMATIC_LESTER_WALKING_TOWARDS_CAMERA_F4, x=160, y=111, zoom=[0x04]
	break
	video offset=CINEMATIC_LESTER_WALKING_TOWARDS_CAMERA_F5, x=160, y=111, zoom=[0x04]
	break
	video offset=CINEMATIC_LESTER_WALKING_TOWARDS_CAMERA_F6, x=160, y=111, zoom=[0x04]
	break
	video offset=CINEMATIC_LESTER_WALKING_TOWARDS_CAMERA_F5, x=160, y=111, zoom=[0x04]
	play id=0x003C, freq=0x0B, vol=0x14, channel=0x02
	break
	video offset=CINEMATIC_LESTER_WALKING_TOWARDS_CAMERA_F4, x=160, y=111, zoom=[0x04]
	break
	video offset=CINEMATIC_LESTER_WALKING_TOWARDS_CAMERA_F3, x=160, y=111, zoom=[0x04]
	break
	video offset=CINEMATIC_LESTER_WALKING_TOWARDS_CAMERA_F2, x=160, y=111, zoom=[0x04]
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_LESTER_WALKING_TOWARDS_CAMERA_F1, x=160, y=111, zoom=[0x04]
.else
	video offset=CINEMATIC_LESTER_WALKING_TOWARDS_CAMERA_F1, x=160, y=111, zoom=[0x04]
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_LESTER_WALKING_TOWARDS_CAMERA_F0, x=160, y=111, zoom=[0x04]
.else
	video offset=CINEMATIC_LESTER_WALKING_TOWARDS_CAMERA_F0, x=160, y=111, zoom=[0x04]
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_466, x=160, y=111, zoom=[0x04]
.else
	video offset=CINEMATIC_468, x=160, y=111, zoom=[0x04]
.endif
	break
	video offset=CINEMATIC_LESTER_WALKING_TOWARDS_CAMERA_F7, x=160, y=111, zoom=[0x04]
	break
	jmp LESTER_WALKING_TOWARDS_CAMERA_ANIMATION
LABEL_22E3:
.if BRANCH == "dos_1992"
	db 0x11
.else
.if BRANCH == "chahi_amiga_1991"
	db 0x11
.else
	killChannel
.endif
.endif

