LABEL_9295:
	call LABEL_6CBB
	je [HERO_ACTION_POS_MASK], 0x80, INLINE_BREAK_035
	jmp LABEL_9221
LABEL_92A1:
	db 0x11

LABEL_92A2:
	call SET_VAR04_TO_0020
	mov [0x2A], 0x0020
	jne [0x0A], 0x00, LABEL_9259
	sub [HERO_X], 0x0004
	call HANDLE_HORIZ_VAR01_VS_VAR28
	video offset=CINEMATIC_560, x=[HERO_X], y=[HERO_Y]
	break
	add [HERO_X], 0x0001
	video offset=CINEMATIC_560, x=[HERO_X], y=[HERO_Y]
	add [HERO_X], 0x0001

LABEL_92C9:
	break
	video offset=CINEMATIC_560, x=[HERO_X], y=[HERO_Y]
	je [HERO_ACTION_POS_MASK], 0x88, LABEL_92C9
	break
	add [HERO_X], 0x0002
	video offset=CINEMATIC_557, x=[HERO_X], y=[HERO_Y]
	mov [0x63], 0x0001
	add [HERO_X], 0x0002
	jmp HERO_WALK_LEFT_LOOP
LABEL_92EA:
	db 0x11

LABEL_92EB:
	mov [0x63], 0x0064
	video type=0, offset=COMMON_VIDEO_087, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_088, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_089, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_090, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0005
	break
	video type=0, offset=COMMON_VIDEO_091, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0007
	break
	video type=0, offset=COMMON_VIDEO_092, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x000D
	break
	video type=0, offset=COMMON_VIDEO_093, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x000C
	break
	video type=0, offset=COMMON_VIDEO_094, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0002
	break
	video type=0, offset=COMMON_VIDEO_095, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0007
	break
	video type=0, offset=COMMON_VIDEO_096, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0004
	break
	play id=0x0060, freq=0x14, vol=0x40, channel=0x00
	video type=0, offset=COMMON_VIDEO_097, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0007
	break
	video type=0, offset=COMMON_VIDEO_098, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	mov [0x63], 0x0001
	jmp LABEL_8F00
LABEL_9364:
	db 0x11

LABEL_9365:
	sub [HERO_X], 0x0005
	sub [HERO_X], 0x0007
	setup channel=0x15, address=KILL_CHANNEL_LANDING
	mov [0x63], 0x0064
	break
	video type=0, offset=COMMON_VIDEO_092, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x000D
	sub [HERO_Y], 0x0002
	break
	video type=0, offset=COMMON_VIDEO_093, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x000C
	break
	video type=0, offset=COMMON_VIDEO_282, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x000C
	add [HERO_Y], 0x0001
	break
	video type=0, offset=COMMON_VIDEO_282, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x000C
	add [HERO_Y], 0x0001
	break
	video type=0, offset=COMMON_VIDEO_094, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0002
	break
	video type=0, offset=COMMON_VIDEO_095, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0007
	break
	sub [HERO_X], 0x0005
	je [HERO_ACTION], 0x01, LABEL_90DD
	add [HERO_X], 0x0005
	video type=0, offset=COMMON_VIDEO_096, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0004
	break
	play id=0x0060, freq=0x14, vol=0x40, channel=0x00
	video type=0, offset=COMMON_VIDEO_097, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0007
	break
	video type=0, offset=COMMON_VIDEO_098, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	mov [0x63], 0x0002
	jmp LABEL_9027
LABEL_93F3:
	db 0x11

LABEL_93F4:
	mov [0x63], 0x0064
	video type=0, offset=COMMON_VIDEO_034, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_035, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_036, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_037, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0005
	break
	video type=0, offset=COMMON_VIDEO_038, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0007
	break
	video type=0, offset=COMMON_VIDEO_039, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x000D
	break
	video type=0, offset=COMMON_VIDEO_040, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x000C
	break
	video type=0, offset=COMMON_VIDEO_041, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0002
	break
	video type=0, offset=COMMON_VIDEO_042, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0007
	break
	video type=0, offset=COMMON_VIDEO_043, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0004
	break
	play id=0x0060, freq=0x14, vol=0x40, channel=0x00
	video type=0, offset=COMMON_VIDEO_044, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0007
	break
	video type=0, offset=COMMON_VIDEO_045, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	mov [0x63], 0x0002
	jmp LABEL_9027
LABEL_946D:
	db 0x11

LABEL_946E:
	add [HERO_X], 0x0005
	add [HERO_X], 0x0007
	setup channel=0x15, address=KILL_CHANNEL_LANDING
	mov [0x63], 0x0064
	break
	video type=0, offset=COMMON_VIDEO_039, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x000D
	sub [HERO_Y], 0x0002
	break
	video type=0, offset=COMMON_VIDEO_040, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x000C
	break
	video type=0, offset=COMMON_VIDEO_257, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x000C
	add [HERO_Y], 0x0001
	break
	video type=0, offset=COMMON_VIDEO_257, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x000C
	add [HERO_Y], 0x0001
	break
	video type=0, offset=COMMON_VIDEO_041, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0002
	break
	video type=0, offset=COMMON_VIDEO_042, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0007
	break
	add [HERO_X], 0x0005
	je [HERO_ACTION], 0x01, LABEL_91B7
	sub [HERO_X], 0x0005
	video type=0, offset=COMMON_VIDEO_043, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0004
	break
	play id=0x0060, freq=0x14, vol=0x40, channel=0x00
	video type=0, offset=COMMON_VIDEO_044, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0007
	break
	video type=0, offset=COMMON_VIDEO_045, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	mov [0x63], 0x0002
	jmp LABEL_9027
LABEL_94FC:
	db 0x11

LABEL_94FD:
	call SET_VAR04_TO_0030
	je [0x0A], 0x00, LABEL_954A
	mov [0x2A], 0x0021
	call HANDLE_HORIZ_VAR01_VS_VAR28
	add [HERO_X], 0x0004
	video offset=CINEMATIC_565, x=[HERO_X], y=[HERO_Y]
	add [HERO_X], 0x0001

LABEL_951A:
	break
	je [HERO_ACTION_POS_MASK], 0x80, LABEL_9552
	call LABEL_6AAB
	je [HERO_ACTION_POS_MASK], 0x00, LABEL_951A
	break
	sub [HERO_X], 0x0002
	video offset=CINEMATIC_565, x=[HERO_X], y=[HERO_Y]
	sub [HERO_X], 0x0002
	break
	video offset=CINEMATIC_562, x=[HERO_X], y=[HERO_Y]
	mov [0x63], 0x0002
	mov [0x0A], 0x0004
	jmp HERO_WALK_LOOP
LABEL_9549:
	db 0x11

LABEL_954A:
	mov [0x63], 0x0002
	jmp LABEL_9027
LABEL_9551:
	db 0x11

LABEL_9552:
	jne [0x0F], 0x00, LABEL_958B
	add [HERO_X], 0x0002
	video offset=CINEMATIC_566, x=[HERO_X], y=[HERO_Y]
	mov [0x21], [HERO_X]
	mov [0x27], [HERO_Y]
	add [0x21], 0x001E
	sub [0x27], 0x0027
	call LABEL_379F
	break
	sub [HERO_X], 0x0001
	video offset=CINEMATIC_565, x=[HERO_X], y=[HERO_Y]
	sub [HERO_X], 0x0001
	jne [HERO_ACTION_POS_MASK], 0x80, LABEL_951A
	setup channel=0x17, address=LABEL_449B
