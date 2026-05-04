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
	sub [0x01], 0x0004
	call HANDLE_HORIZ_VAR01_VS_VAR28
	video type=1, offset=CINEMATIC_560, x=[0x01], y=[0x02], zoom=0x40
	break
	add [0x01], 0x0001
	video type=1, offset=CINEMATIC_560, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0001

LABEL_965D:
	break
	video type=1, offset=CINEMATIC_560, x=[0x01], y=[0x02], zoom=0x40
	je [HERO_ACTION_POS_MASK], 0x88, LABEL_965D
	break
	add [0x01], 0x0002
	video type=1, offset=CINEMATIC_557, x=[0x01], y=[0x02], zoom=0x40
	mov [0x63], 0x0001
	add [0x01], 0x0002
	jmp HERO_WALK_LEFT_LOOP
LABEL_967E:
	db 0x11

LABEL_967F:
	je [HERO_POS_MASK], 0x09, LABEL_97A4
	mov [0x63], 0x0064
	video type=0, offset=COMMON_VIDEO_048, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_049, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_050, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_051, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0005
	break
	video type=0, offset=COMMON_VIDEO_052, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0007
	break
	video type=0, offset=COMMON_VIDEO_053, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x000D
	break
	video type=0, offset=COMMON_VIDEO_054, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x000C
	break
	video type=0, offset=COMMON_VIDEO_055, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0002
	break
	video type=0, offset=COMMON_VIDEO_056, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0007
	break
	video type=0, offset=COMMON_VIDEO_057, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0004
	break
	play id=0x0060, freq=0x14, vol=0x40, channel=0x00
	video type=0, offset=COMMON_VIDEO_058, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0007
	break
	video type=0, offset=COMMON_VIDEO_059, x=[0x01], y=[0x02], zoom=0x40
	break
	mov [0x63], 0x0001
	jmp LABEL_922C
LABEL_96FE:
	db 0x11

LABEL_96FF:
	je [HERO_POS_MASK], 0x09, LABEL_9824
	sub [0x01], 0x0005
	sub [0x01], 0x0007
	setup channel=0x15, address=KILL_CHANNEL_LANDING
	mov [0x63], 0x0064
	break

LABEL_9716:
	je [HERO_POS_MASK], 0x09, LABEL_983B
	video type=0, offset=COMMON_VIDEO_053, x=[0x01], y=[0x02], zoom=0x40
	setup channel=0x15, address=KILL_CHANNEL_LANDING
	sub [0x01], 0x000D
	sub [0x02], 0x0002
	break
	video type=0, offset=COMMON_VIDEO_054, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x000C
	break
	video type=0, offset=COMMON_VIDEO_096, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x000C
	add [0x02], 0x0001
	break
	video type=0, offset=COMMON_VIDEO_096, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x000C
	add [0x02], 0x0001
	call LABEL_882F
	call LABEL_883E
	break
	video type=0, offset=COMMON_VIDEO_055, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0002
	break
	video type=0, offset=COMMON_VIDEO_056, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0007
	break
	sub [0x01], 0x0005
	je [HERO_ACTION], 0x01, LABEL_9471
	add [0x01], 0x0005
	video type=0, offset=COMMON_VIDEO_057, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0004
	break
	play id=0x0060, freq=0x14, vol=0x40, channel=0x00
	video type=0, offset=COMMON_VIDEO_058, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0007
	break
	video type=0, offset=COMMON_VIDEO_059, x=[0x01], y=[0x02], zoom=0x40
	break
	mov [0x63], 0x0001
	jmp LABEL_922C
LABEL_97A3:
	db 0x11

LABEL_97A4:
	je [HERO_POS_MASK], 0x0A, LABEL_967F
	mov [0x63], 0x0064
	video type=0, offset=COMMON_VIDEO_003, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_004, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_005, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_006, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0005
	break
	video type=0, offset=COMMON_VIDEO_007, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0007
	break
	video type=0, offset=COMMON_VIDEO_008, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x000D
	break
	video type=0, offset=COMMON_VIDEO_009, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x000C
	break
	video type=0, offset=COMMON_VIDEO_010, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0002
	break
	video type=0, offset=COMMON_VIDEO_011, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0007
	break
	video type=0, offset=COMMON_VIDEO_012, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0004
	break
	play id=0x0060, freq=0x14, vol=0x40, channel=0x00
	video type=0, offset=COMMON_VIDEO_013, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0007
	break
	video type=0, offset=COMMON_VIDEO_014, x=[0x01], y=[0x02], zoom=0x40
	break
	mov [0x63], 0x0002
	jmp LABEL_93BB
LABEL_9823:
	db 0x11

LABEL_9824:
	je [HERO_POS_MASK], 0x0A, LABEL_96FF
	add [0x01], 0x0005
	add [0x01], 0x0007
	setup channel=0x15, address=KILL_CHANNEL_LANDING
	mov [0x63], 0x0064
	break

LABEL_983B:
	je [HERO_POS_MASK], 0x0A, LABEL_9716
	setup channel=0x15, address=KILL_CHANNEL_LANDING
	video type=0, offset=COMMON_VIDEO_008, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x000D
	sub [0x02], 0x0002
	break
	video type=0, offset=COMMON_VIDEO_009, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x000C
	break
	video type=0, offset=COMMON_VIDEO_085, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x000C
	add [0x02], 0x0001
	break
	video type=0, offset=COMMON_VIDEO_085, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x000C
	add [0x02], 0x0001
	call LABEL_882F
	call LABEL_883E
	break
	video type=0, offset=COMMON_VIDEO_010, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0002
	break
	video type=0, offset=COMMON_VIDEO_011, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0007
	break
	add [0x01], 0x0005
	je [HERO_ACTION], 0x01, LABEL_954B
	sub [0x01], 0x0005
	video type=0, offset=COMMON_VIDEO_012, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0004
	break
	play id=0x0060, freq=0x14, vol=0x40, channel=0x00
	video type=0, offset=COMMON_VIDEO_013, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0007
	break
	video type=0, offset=COMMON_VIDEO_014, x=[0x01], y=[0x02], zoom=0x40
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
	add [0x01], 0x0004
	video type=1, offset=CINEMATIC_565, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0001

LABEL_98E6:
	break
	je [HERO_ACTION_POS_MASK], 0x80, LABEL_991E
	call LABEL_6C5B
	je [HERO_ACTION_POS_MASK], 0x00, LABEL_98E6
	break
	sub [0x01], 0x0002
	video type=1, offset=CINEMATIC_565, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0002
	break
	video type=1, offset=CINEMATIC_562, x=[0x01], y=[0x02], zoom=0x40
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
	add [0x01], 0x0002
	video type=1, offset=CINEMATIC_566, x=[0x01], y=[0x02], zoom=0x40
	mov [0x21], [0x01]
	mov [0x27], [0x02]
	add [0x21], 0x001E
	sub [0x27], 0x0027
	call LABEL_38F5
	break
	sub [0x01], 0x0001
	video type=1, offset=CINEMATIC_565, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0001
	jne [HERO_ACTION_POS_MASK], 0x80, LABEL_98E6
	setup channel=0x17, address=LABEL_4605
