LABEL_9629:
	call LABEL_6E6B
	je [HERO_ACTION_POS_MASK], 0x80, INLINE_BREAK_035
	jmp LABEL_95B5
LABEL_9635:
	db 0x11

LABEL_9636:
	call SET_VAR04_TO_0020
	mov [0x2A], 0x0020
	jne [0x0A], 0x00, LABEL_95ED
	sub [HERO_X], 0x0004
	call HANDLE_HORIZ_VAR01_VS_VAR28
	video offset=CINEMATIC_560, x=[HERO_X], y=[HERO_Y]
	break
	add [HERO_X], 0x0001
	video offset=CINEMATIC_560, x=[HERO_X], y=[HERO_Y]
	add [HERO_X], 0x0001

LABEL_965D:
	break
	video offset=CINEMATIC_560, x=[HERO_X], y=[HERO_Y]
	je [HERO_ACTION_POS_MASK], 0x88, LABEL_965D
	break
	add [HERO_X], 0x0002
	video offset=CINEMATIC_557, x=[HERO_X], y=[HERO_Y]
	mov [0x63], 0x0001
	add [HERO_X], 0x0002
	jmp HERO_WALK_LEFT_LOOP
LABEL_967E:
	db 0x11

LABEL_967F:
	je [HERO_POS_MASK], 0x09, LABEL_97A4
	mov [0x63], 0x0064
	video type=0, offset=COMMON_VIDEO_048, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_049, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_050, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_051, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0005
	break
	video type=0, offset=COMMON_VIDEO_052, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0007
	break
	video type=0, offset=COMMON_VIDEO_053, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x000D
	break
	video type=0, offset=COMMON_VIDEO_054, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x000C
	break
	video type=0, offset=COMMON_VIDEO_055, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0002
	break
	video type=0, offset=COMMON_VIDEO_056, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0007
	break
	video type=0, offset=COMMON_VIDEO_057, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0004
	break
	play id=0x0060, freq=0x14, vol=0x40, channel=0x00
	video type=0, offset=COMMON_VIDEO_058, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0007
	break
	video type=0, offset=COMMON_VIDEO_059, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	mov [0x63], 0x0001
	jmp LABEL_922C
LABEL_96FE:
	db 0x11

LABEL_96FF:
	je [HERO_POS_MASK], 0x09, LABEL_9824
	sub [HERO_X], 0x0005
	sub [HERO_X], 0x0007
	setup channel=0x15, address=KILL_CHANNEL_LANDING
	mov [0x63], 0x0064
	break

LABEL_9716:
	je [HERO_POS_MASK], 0x09, LABEL_983B
	video type=0, offset=COMMON_VIDEO_053, x=[HERO_X], y=[HERO_Y], zoom=0x40
	setup channel=0x15, address=KILL_CHANNEL_LANDING
	sub [HERO_X], 0x000D
	sub [HERO_Y], 0x0002
	break
	video type=0, offset=COMMON_VIDEO_054, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x000C
	break
	video type=0, offset=COMMON_VIDEO_096, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x000C
	add [HERO_Y], 0x0001
	break
	video type=0, offset=COMMON_VIDEO_096, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x000C
	add [HERO_Y], 0x0001
	call LABEL_882F
	call LABEL_883E
	break
	video type=0, offset=COMMON_VIDEO_055, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0002
	break
	video type=0, offset=COMMON_VIDEO_056, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0007
	break
	sub [HERO_X], 0x0005
	je [HERO_ACTION], 0x01, LABEL_9471
	add [HERO_X], 0x0005
	video type=0, offset=COMMON_VIDEO_057, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0004
	break
	play id=0x0060, freq=0x14, vol=0x40, channel=0x00
	video type=0, offset=COMMON_VIDEO_058, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0007
	break
	video type=0, offset=COMMON_VIDEO_059, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	mov [0x63], 0x0001
	jmp LABEL_922C
LABEL_97A3:
	db 0x11

LABEL_97A4:
	je [HERO_POS_MASK], 0x0A, LABEL_967F
	mov [0x63], 0x0064
	video type=0, offset=COMMON_VIDEO_003, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_004, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_005, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_006, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0005
	break
	video type=0, offset=COMMON_VIDEO_007, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0007
	break
	video type=0, offset=COMMON_VIDEO_008, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x000D
	break
	video type=0, offset=COMMON_VIDEO_009, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x000C
	break
	video type=0, offset=COMMON_VIDEO_010, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0002
	break
	video type=0, offset=COMMON_VIDEO_011, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0007
	break
	video type=0, offset=COMMON_VIDEO_012, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0004
	break
	play id=0x0060, freq=0x14, vol=0x40, channel=0x00
	video type=0, offset=COMMON_VIDEO_013, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0007
	break
	video type=0, offset=COMMON_VIDEO_014, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	mov [0x63], 0x0002
	jmp LABEL_93BB
LABEL_9823:
	db 0x11

LABEL_9824:
	je [HERO_POS_MASK], 0x0A, LABEL_96FF
	add [HERO_X], 0x0005
	add [HERO_X], 0x0007
	setup channel=0x15, address=KILL_CHANNEL_LANDING
	mov [0x63], 0x0064
	break

LABEL_983B:
	je [HERO_POS_MASK], 0x0A, LABEL_9716
	setup channel=0x15, address=KILL_CHANNEL_LANDING
	video type=0, offset=COMMON_VIDEO_008, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x000D
	sub [HERO_Y], 0x0002
	break
	video type=0, offset=COMMON_VIDEO_009, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x000C
	break
	video type=0, offset=COMMON_VIDEO_085, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x000C
	add [HERO_Y], 0x0001
	break
	video type=0, offset=COMMON_VIDEO_085, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x000C
	add [HERO_Y], 0x0001
	call LABEL_882F
	call LABEL_883E
	break
	video type=0, offset=COMMON_VIDEO_010, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0002
	break
	video type=0, offset=COMMON_VIDEO_011, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0007
	break
	add [HERO_X], 0x0005
	je [HERO_ACTION], 0x01, LABEL_954B
	sub [HERO_X], 0x0005
	video type=0, offset=COMMON_VIDEO_012, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0004
	break
	play id=0x0060, freq=0x14, vol=0x40, channel=0x00
	video type=0, offset=COMMON_VIDEO_013, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0007
	break
	video type=0, offset=COMMON_VIDEO_014, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	mov [0x63], 0x0002
	jmp LABEL_93BB
LABEL_98C8:
	db 0x11

LABEL_98C9:
	call SET_VAR04_TO_0030
	je [0x0A], 0x00, LABEL_9916
	mov [0x2A], 0x0021
	call HANDLE_HORIZ_VAR01_VS_VAR28
	add [HERO_X], 0x0004
	video offset=CINEMATIC_565, x=[HERO_X], y=[HERO_Y]
	add [HERO_X], 0x0001

LABEL_98E6:
	break
	je [HERO_ACTION_POS_MASK], 0x80, LABEL_991E
	call LABEL_6C5B
	je [HERO_ACTION_POS_MASK], 0x00, LABEL_98E6
	break
	sub [HERO_X], 0x0002
	video offset=CINEMATIC_565, x=[HERO_X], y=[HERO_Y]
	sub [HERO_X], 0x0002
	break
	video offset=CINEMATIC_562, x=[HERO_X], y=[HERO_Y]
	mov [0x63], 0x0002
	mov [0x0A], 0x0004
	jmp HERO_WALK_RIGHT_LOOP
LABEL_9915:
	db 0x11

LABEL_9916:
	mov [0x63], 0x0002
	jmp LABEL_93BB
LABEL_991D:
	db 0x11

LABEL_991E:
	jne [0x0F], 0x00, LABEL_9957
	add [HERO_X], 0x0002
	video offset=CINEMATIC_566, x=[HERO_X], y=[HERO_Y]
	mov [0x21], [HERO_X]
	mov [0x27], [HERO_Y]
	add [0x21], 0x001E
	sub [0x27], 0x0027
	call LABEL_38F5
	break
	sub [HERO_X], 0x0001
	video offset=CINEMATIC_565, x=[HERO_X], y=[HERO_Y]
	sub [HERO_X], 0x0001
	jne [HERO_ACTION_POS_MASK], 0x80, LABEL_98E6
	setup channel=0x17, address=LABEL_4605
