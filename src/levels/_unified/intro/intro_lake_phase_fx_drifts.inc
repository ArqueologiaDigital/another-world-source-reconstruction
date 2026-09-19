LESTER_HAND_PRESSING_KEYPAD_ANIMATION:
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_LESTER_HAND_PRESSING_KEYPAD_F0, x=[0x01], y=[0x02]
.else
	video offset=CINEMATIC_LESTER_HAND_PRESSING_KEYPAD_F0, x=[0x01], y=[0x02]
.endif
	break
	jne [0x03], 0x00, LESTER_HAND_PRESSING_KEYPAD_ANIMATION
	mov [0x03], 0x00FF
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_LESTER_HAND_PRESSING_KEYPAD_F1, x=[0x01], y=[0x02]
.else
	video offset=CINEMATIC_LESTER_HAND_PRESSING_KEYPAD_F1, x=[0x01], y=[0x02]
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_LESTER_HAND_PRESSING_KEYPAD_F2, x=[0x01], y=[0x02]
.else
	video offset=CINEMATIC_LESTER_HAND_PRESSING_KEYPAD_F2, x=[0x01], y=[0x02]
.endif
	break
	video offset=CINEMATIC_LESTER_HAND_PRESSING_KEYPAD_F3, x=[0x01], y=[0x02]
	call KEYPAD_KEYPRESS_TONE_CASE_00
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_LESTER_HAND_PRESSING_KEYPAD_F4, x=[0x01], y=[0x02]
.else
	video offset=CINEMATIC_LESTER_HAND_PRESSING_KEYPAD_F4, x=[0x01], y=[0x02]
.endif
	break
	video offset=CINEMATIC_LESTER_HAND_PRESSING_KEYPAD_F5, x=[0x01], y=[0x02]
	break
	jmp LESTER_HAND_PRESSING_KEYPAD_ANIMATION
LABEL_1FD1:
.if BRANCH == "dos_1992"
	db 0x11
.else
.if BRANCH == "chahi_amiga_1991"
	db 0x11
.else
	killChannel
.endif
.endif

KEYPAD_KEYPRESS_TONE_CASE_00:
	jne [0x1E], 0x00, PLAY_FX_PHASE_1_FREQ_22
	play id=0x000B, freq=0x14, vol=0x3F, channel=0x02

PLAY_FX_PHASE_1_FREQ_22:
	jne [0x1E], 0x01, PLAY_FX_PHASE_2_FREQ_18
	play id=0x000B, freq=0x16, vol=0x3F, channel=0x02

PLAY_FX_PHASE_2_FREQ_18:
	jne [0x1E], 0x02, PLAY_FX_PHASE_3_FREQ_18
	play id=0x000B, freq=0x12, vol=0x3F, channel=0x02

PLAY_FX_PHASE_3_FREQ_18:
	jne [0x1E], 0x03, PLAY_FX_PHASE_4_FREQ_20
	play id=0x000B, freq=0x12, vol=0x3F, channel=0x02

PLAY_FX_PHASE_4_FREQ_20:
	jne [0x1E], 0x04, PLAY_FX_PHASE_5_FREQ_20
	play id=0x000B, freq=0x14, vol=0x3F, channel=0x02

PLAY_FX_PHASE_5_FREQ_20:
	jne [0x1E], 0x05, PLAY_FX_DISPATCH_RET
	play id=0x000B, freq=0x14, vol=0x3F, channel=0x02

PLAY_FX_DISPATCH_RET:
	ret


LESTER_APPROACH_ZOOM_RAMP_INIT:
	mov [0x04], 0x0040
	mov [0x06], 0x000F

DRIFT_VAR4_PLUS_3_FOR_15X:
	add [0x04], 0x0003
	break
	djnz [0x06], DRIFT_VAR4_PLUS_3_FOR_15X
	mov [0x06], 0x000A

DRIFT_VAR4_PLUS_5_FOR_10X:
	add [0x04], 0x0005
	break
	djnz [0x06], DRIFT_VAR4_PLUS_5_FOR_10X
	mov [0x06], 0x0014

DRIFT_VAR4_PLUS_9_FOR_20X:
	add [0x04], 0x0009
	break
	djnz [0x06], DRIFT_VAR4_PLUS_9_FOR_20X
	setup channel=0x02, address=KILL_CHANNEL_ROUTINE
	fill page=0xFF, color=0x09
.if BRANCH != "chahi_amiga_1991"
	setup channel=0x3C, address=BLIT_AND_COPY_PAGE_FF_LOOP
.endif
	break
	setPalette 0x0E
	copyVideoPage src=0x03, dst=0x00
	selectVideoPage 0x00
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_121, x=160, y=100
	video offset=CINEMATIC_122, x=160, y=100
.else
	video offset=CINEMATIC_126, x=160, y=100
	video offset=CINEMATIC_127, x=160, y=100
.endif
	selectVideoPage 0xFF
	fill page=0xFF, color=0x09
	break
	setup channel=0x03, address=LESTER_WALKING_AWAY_FROM_CAMERA_FRAME_CYCLE
	play id=0x0036, freq=0x14, vol=0x3F, channel=0x03
	mov [0x04], 0x0153
	mov [0x06], 0x0014

DRIFT_VAR4_MINUS_9_FOR_20X:
	sub [0x04], 0x0009
	break
	djnz [0x06], DRIFT_VAR4_MINUS_9_FOR_20X
	mov [0x06], 0x000A

DRIFT_VAR4_MINUS_5_FOR_10X:
	sub [0x04], 0x0005
	break
	djnz [0x06], DRIFT_VAR4_MINUS_5_FOR_10X
	mov [0x06], 0x0005

DRIFT_VAR4_MINUS_3_FOR_5X:
	sub [0x04], 0x0003
	break
	djnz [0x06], DRIFT_VAR4_MINUS_3_FOR_5X
	setup channel=0x01, address=KILL_CHANNEL_ROUTINE
	setup channel=0x02, address=LAB_KEYPAD_SCENE_INIT
	setup channel=0x03, address=LESTER_HAND_PRESSING_KEYPAD_ANIMATION
.if BRANCH != "chahi_amiga_1991"
	setup channel=0x3C, address=BLIT_AND_COPY_PAGE_FF_LOOP
.endif
	setup channel=0x04, address=KILL_CHANNEL_ROUTINE
	killChannel

