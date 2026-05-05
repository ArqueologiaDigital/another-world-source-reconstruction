LABEL_E8DF:
	call LABEL_99EB
	je [HERO_ACTION_POS_MASK], 0x80, INLINE_BREAK_035
	jmp LABEL_E87C
LABEL_E8EB:
	db 0x11, 0x04, 0xD8, 0x71, 0x00, 0x2A, 0x00, 0x20
	db 0x0A, 0x01, 0x0A, 0x00, 0xE8, 0xAA, 0x00, 0x63
	db 0x00, 0x01, 0x07, 0xE4, 0xDF, 0x11

LABEL_E901:
	mov [0x63], 0x0064
	video type=0, offset=COMMON_VIDEO_087, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_088, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_089, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	call SET_VAR04_TO_0024
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
	mov [0x34], 0xFFFE
	sub [HERO_X], 0x000F
	call LABEL_770D
	break
	add [HERO_X], 0x000F
	video type=0, offset=COMMON_VIDEO_094, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0002
	sub [HERO_X], 0x000F
	break
	add [HERO_X], 0x000F
	video type=0, offset=COMMON_VIDEO_095, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0007
	call SET_VAR04_TO_0020
	sub [HERO_X], 0x000C
	break
	add [HERO_X], 0x000C
	video type=0, offset=COMMON_VIDEO_096, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0004
	sub [HERO_X], 0x0007
	play id=0x0060, freq=0x14, vol=0x40, channel=0x01
	break
	add [HERO_X], 0x0007
	video type=0, offset=COMMON_VIDEO_097, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0007
	break
	video type=0, offset=COMMON_VIDEO_098, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	mov [0x63], 0x0001
	jmp LABEL_E4EC
LABEL_E9A7:
	db 0x11

LABEL_E9A8:
	sub [HERO_X], 0x0005
	sub [HERO_X], 0x0007
	call SET_VAR04_TO_0024
	setup channel=0x15, address=KILL_CHANNEL_LANDING
	mov [0x63], 0x0064
	break

LABEL_E9BC:
	call SET_VAR04_TO_0024
	setup channel=0x15, address=KILL_CHANNEL_LANDING
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
	mov [0x34], 0xFFFB
	sub [HERO_X], 0x000F
	call LABEL_770D
	sub [HERO_X], 0x0002
	break
	add [HERO_X], 0x000F
	video type=0, offset=COMMON_VIDEO_095, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0007
	call SET_VAR04_TO_0020
	sub [HERO_X], 0x000C
	break
	play id=0x0060, freq=0x14, vol=0x40, channel=0x01
	add [HERO_X], 0x000C
	sub [HERO_X], 0x0005
	je [HERO_ACTION], 0x01, LABEL_E6FE
	add [HERO_X], 0x0005
	video type=0, offset=COMMON_VIDEO_096, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0004
	sub [HERO_X], 0x0007
	break
	add [HERO_X], 0x0007
	video type=0, offset=COMMON_VIDEO_097, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0007
	break
	video type=0, offset=COMMON_VIDEO_098, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	mov [0x63], 0x0001
	jmp LABEL_E4EC
LABEL_EA62:
	db 0x11

LABEL_EA63:
	mov [0x63], 0x0064
	video type=0, offset=COMMON_VIDEO_034, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_035, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_036, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	call SET_VAR04_TO_0034
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
	mov [0x34], 0x0002
	add [HERO_X], 0x000F
	call LABEL_770D
	break
	sub [HERO_X], 0x000F
	video type=0, offset=COMMON_VIDEO_041, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0002
	add [HERO_X], 0x000F
	break
	sub [HERO_X], 0x000F
	video type=0, offset=COMMON_VIDEO_042, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0007
	call SET_VAR04_TO_0030
	add [HERO_X], 0x000C
	break
	sub [HERO_X], 0x000C
	video type=0, offset=COMMON_VIDEO_043, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0004
	add [HERO_X], 0x0007
	play id=0x0060, freq=0x14, vol=0x40, channel=0x01
	break
	sub [HERO_X], 0x0007
	video type=0, offset=COMMON_VIDEO_044, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0007
	break
	video type=0, offset=COMMON_VIDEO_045, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	mov [0x63], 0x0002
	jmp LABEL_E644
LABEL_EB09:
	db 0x11

LABEL_EB0A:
	add [HERO_X], 0x0005
	add [HERO_X], 0x0007
	call SET_VAR04_TO_0034
	setup channel=0x15, address=KILL_CHANNEL_LANDING
	mov [0x63], 0x0064
	break

LABEL_EB1E:
	call SET_VAR04_TO_0034
	setup channel=0x15, address=KILL_CHANNEL_LANDING
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
	mov [0x34], 0x0005
	add [HERO_X], 0x000F
	call LABEL_770D
	add [HERO_X], 0x0002
	break
	sub [HERO_X], 0x000F
	video type=0, offset=COMMON_VIDEO_042, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0007
	call SET_VAR04_TO_0030
	add [HERO_X], 0x000C
	break
	play id=0x0060, freq=0x14, vol=0x40, channel=0x01
	sub [HERO_X], 0x000C
	add [HERO_X], 0x0005
	je [HERO_ACTION], 0x01, LABEL_E7EC
	sub [HERO_X], 0x0005
	video type=0, offset=COMMON_VIDEO_043, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0004
	add [HERO_X], 0x0007
	break
	sub [HERO_X], 0x0007
	video type=0, offset=COMMON_VIDEO_044, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0007
	break
	video type=0, offset=COMMON_VIDEO_045, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	mov [0x63], 0x0002
	jmp LABEL_E644
LABEL_EBC4:
	db 0x11

LABEL_EBC5:
	call LABEL_98D5
	break
	je [HERO_ACTION_POS_MASK], 0x80, LABEL_EBC5
	call LABEL_98D5
	mov [0x63], 0x0002
	jmp HERO_WALK_RIGHT_LOOP

LABEL_EBD9:
	call SET_VAR04_TO_0030
	je [0x0A], 0x00, LABEL_EBC5
	mov [0x2A], 0x0020
	call LABEL_7B5E
	add [HERO_X], 0x0004
	call LABEL_9751
	add [HERO_X], 0x0001

LABEL_EBF4:
	break
	je [HERO_ACTION_POS_MASK], 0x80, LABEL_EC22
	call LABEL_9763
	je [HERO_ACTION_POS_MASK], 0x00, LABEL_EBF4
	break
	sub [HERO_X], 0x0002
	call LABEL_9751
	sub [HERO_X], 0x0002
	break
	video type=0, offset=COMMON_VIDEO_351, x=[HERO_X], y=[HERO_Y], zoom=0x40
	mov [0x63], 0x0002
	mov [0x0A], 0x0004
	jmp HERO_WALK_RIGHT_LOOP
LABEL_EC21:
	db 0x11

LABEL_EC22:
	jne [0x0F], 0x00, LABEL_EC57
	add [HERO_X], 0x0002
	call LABEL_978D
	mov [0x21], [HERO_X]
	mov [0x27], [HERO_Y]
	add [0x21], 0x001E
	sub [0x27], 0x0027
	call LABEL_62DD
	break
	sub [HERO_X], 0x0001
	call LABEL_9751
	sub [HERO_X], 0x0001
	jne [HERO_ACTION_POS_MASK], 0x80, LABEL_EBF4
	setup channel=0x17, address=LABEL_71FB
