LABEL_9783:
	mov [0x63], 0x0064
	play id=0x0057, freq=0x1C, vol=0x40, channel=0x00
	je [SCREEN_NUM], 0x8E, LABEL_97B8
	je [SCREEN_NUM], 0x8A, LABEL_98B6
	je [SCREEN_NUM], 0xAA, LABEL_97B8
	mov [HERO_Y], [0x52]
	sub [HERO_Y], 0x001E
	call LABEL_99E2
	break
	mov [HERO_Y], [0x52]
	call LABEL_99E2
	setup channel=0x1A, address=LABEL_9774
	jmp CAPSULE_HERO_WALK_DECIDE_BY_VAR04_BIT_4
LABEL_97B7:
	db 0x11

LABEL_97B8:
	mov [0x63], 0x0064
	sub [HERO_Y], 0x0050
	mov [0x32], 0x0001
	jne [SCREEN_NUM], 0xAA, LABEL_97D6
	video offset=CINEMATIC_089, x=[HERO_X], y=160
	break
	video offset=CINEMATIC_089, x=[HERO_X], y=200
	break

LABEL_97D6:
	video offset=CINEMATIC_089, x=[HERO_X], y=240
	mov [HERO_Y], 0x012C
	setup channel=0x17, address=KILL_CHANNEL_LANDING
	break
	mov [0x0F], 0x0000
	mov [0x32], 0x0001
	break
	mov [0x32], 0x0001
	mov [HERO_Y], [0x52]
	break
	je [SCREEN_NUM], 0xCE, INIT_VARS_03_32_02
	mov [0x32], 0x0001
	video offset=CINEMATIC_089, x=[HERO_X], y=77
	mov [HERO_Y], [0x52]
	break
	mov [0x32], 0x0001
	video offset=CINEMATIC_089, x=[HERO_X], y=146
	break
	video offset=CINEMATIC_089, x=[HERO_X], y=189
	mov [HERO_Y], [0x52]
	setup channel=0x1A, address=LABEL_9774
	jmp CAPSULE_HERO_WALK_DECIDE_BY_VAR04_BIT_4

LABEL_9821:
	mov [0x63], 0x0064
	play id=0x0057, freq=0x1C, vol=0x40, channel=0x00
	je [SCREEN_NUM], 0xEE, LABEL_9856
	je [SCREEN_NUM], 0xAA, LABEL_9905
	je [SCREEN_NUM], 0xC8, LABEL_9856
	mov [HERO_Y], [0x51]
	add [HERO_Y], 0x001E
	call LABEL_99C8
	break
	mov [HERO_Y], [0x51]
	call LABEL_99C8
	setup channel=0x1A, address=CAPSULE_SHELVE_BACKDROP_TO_PAGE3_L1
	jmp CAPSULE_HERO_WALK_DECIDE_BY_VAR04_BIT_4
LABEL_9855:
	db 0x11

LABEL_9856:
	mov [0x63], 0x0064
	sub [HERO_Y], 0x0064
	je [SCREEN_NUM], 0xAA, LABEL_986E
	mov [0x32], 0x0001
	video offset=CINEMATIC_091, x=[HERO_X], y=115
	break

LABEL_986E:
	mov [0x32], 0x0001
	video offset=CINEMATIC_091, x=[HERO_X], y=60
	setup channel=0x17, address=KILL_CHANNEL_LANDING
	break
	mov [0x0F], 0x0000
	mov [0x32], 0x0001
	video offset=CINEMATIC_091, x=[HERO_X], y=65529
	break
	mov [HERO_Y], [0x51]
	break
	je [SCREEN_NUM], 0xCE, INIT_VARS_03_32_02_1
	video offset=CINEMATIC_091, x=[HERO_X], y=180
	jne [SCREEN_NUM], 0xAA, LABEL_98AC
	break
	video offset=CINEMATIC_091, x=[HERO_X], y=130
	break
	video offset=CINEMATIC_091, x=[HERO_X], y=70

LABEL_98AC:
	mov [HERO_Y], [0x51]
	setup channel=0x1A, address=CAPSULE_SHELVE_BACKDROP_TO_PAGE3_L1
	jmp CAPSULE_HERO_WALK_DECIDE_BY_VAR04_BIT_4

LABEL_98B6:
	mov [0x63], 0x0064
	sub [HERO_Y], 0x001E
	mov [0x32], 0x0001
	video offset=CINEMATIC_089, x=[HERO_X], y=240
	mov [HERO_Y], 0x012C
	break
	setup channel=0x17, address=KILL_CHANNEL_LANDING
	mov [0x32], 0x0001
	break
	mov [0x0F], 0x0000
	mov [0x32], 0x0001
	mov [HERO_Y], [0x52]
	break
	mov [HERO_X], 0x0036
	mov [0x32], 0x0009
	video offset=CINEMATIC_089, x=[HERO_X], y=40
	mov [HERO_Y], [0x52]
	break
	mov [0x32], 0x0009
	video offset=CINEMATIC_089, x=[HERO_X], y=80
	mov [HERO_Y], [0x52]
	setup channel=0x1A, address=LABEL_9774
	jmp CAPSULE_HERO_WALK_DECIDE_BY_VAR04_BIT_4

LABEL_9905:
	mov [0x63], 0x0064
	sub [HERO_Y], 0x0064
	mov [0x32], 0x0001
	video offset=CINEMATIC_091, x=[HERO_X], y=40
	break
	mov [0x32], 0x0001
	video offset=CINEMATIC_091, x=[HERO_X], y=65524
	break
	mov [HERO_Y], [0x51]
	break
	mov [0x32], 0x0009
	mov [HERO_X], 0x0029
	video offset=CINEMATIC_091, x=[HERO_X], y=180
	mov [HERO_Y], [0x51]
	setup channel=0x1A, address=CAPSULE_SHELVE_BACKDROP_TO_PAGE3_L1
	jmp CAPSULE_HERO_WALK_DECIDE_BY_VAR04_BIT_4
