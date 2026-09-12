PRISON_HERO_CRAWL_RIGHT_STOP:
	jne [0xB6], 0x00, LABEL_8C98
	video type=0, offset=COMMON_VIDEO_140, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0003
	break
	video type=0, offset=COMMON_VIDEO_149, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0001
	break
	video type=0, offset=COMMON_VIDEO_150, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0006
	break
	video type=0, offset=COMMON_VIDEO_151, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_152, x=[HERO_X], y=[HERO_Y], zoom=0x40
	mov [0x2A], 0x000F
	call SET_VAR04_TO_0010
	jmp LABEL_9A87
LABEL_8C97:
	db 0x11

LABEL_8C98:
	video type=0, offset=COMMON_VIDEO_140, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	je [HERO_ACTION_POS_MASK], 0x05, LABEL_8CAE
	je [HERO_ACTION_POS_MASK], 0x06, LABEL_8E74
	jmp LABEL_8C98
LABEL_8CAD:
	db 0x11

LABEL_8CAE:
	video type=0, offset=COMMON_VIDEO_140, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0002
	break
	je [HERO_POS_MASK], 0x06, LABEL_8E5E

PRISON_HERO_ACTION_POS_5_DRAW_CV163_THEN_HERO_POS_6:
	jne [HERO_ACTION_POS_MASK], 0x05, PRISON_HERO_CRAWL_RIGHT_STOP
	video type=0, offset=COMMON_VIDEO_163, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	je [HERO_POS_MASK], 0x06, LABEL_8E52

LABEL_8CD0:
	jne [HERO_ACTION_POS_MASK], 0x05, PRISON_HERO_CRAWL_RIGHT_STOP
	video type=0, offset=COMMON_VIDEO_139, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0001
	break
	je [HERO_POS_MASK], 0x06, LABEL_8F24

LABEL_8CE6:
	jne [HERO_ACTION_POS_MASK], 0x05, PRISON_HERO_CRAWL_RIGHT_STOP
	video type=0, offset=COMMON_VIDEO_141, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0002
	break
	je [HERO_POS_MASK], 0x06, LABEL_8F0E

LABEL_8CFC:
	jne [HERO_ACTION_POS_MASK], 0x05, PRISON_HERO_CRAWL_RIGHT_STOP
	video type=0, offset=COMMON_VIDEO_142, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0004
	break
	je [HERO_POS_MASK], 0x06, LABEL_8EF8

PRISON_HERO_WALK_RIGHT_PHASE_05:
	video type=0, offset=COMMON_VIDEO_143, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x05, WALK_RIGHT_DRAW_CV142_MULTISTEP
	add [HERO_X], 0x0003
	break
	je [HERO_POS_MASK], 0x06, LABEL_8EE2

PRISON_HERO_WALK_RIGHT_PHASE_06:
	video type=0, offset=COMMON_VIDEO_144, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x05, WALK_RIGHT_DRAW_CV142_MULTISTEP
	add [HERO_X], 0x0002
	break
	je [HERO_POS_MASK], 0x06, LABEL_8ECC

PRISON_HERO_WALK_RIGHT_PHASE_07:
	video type=0, offset=COMMON_VIDEO_145, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x05, WALK_RIGHT_DRAW_CV142_MULTISTEP
	add [HERO_X], 0x0001
	break
	je [HERO_POS_MASK], 0x06, LABEL_8EB6

PRISON_HERO_WALK_RIGHT_PHASE_08:
	video type=0, offset=COMMON_VIDEO_146, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x05, LABEL_8C35
	add [HERO_X], 0x0002
	break
	je [HERO_POS_MASK], 0x06, LABEL_8EA0

PRISON_HERO_WALK_RIGHT_PHASE_09:
	video type=0, offset=COMMON_VIDEO_148, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x05, LABEL_8C35
	add [HERO_X], 0x0003
	break
	je [HERO_POS_MASK], 0x06, LABEL_8E8A

LABEL_8D80:
	video type=0, offset=COMMON_VIDEO_147, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0002
	break
	je [HERO_POS_MASK], 0x06, LABEL_8E74
	jne [HERO_ACTION_POS_MASK], 0x05, PRISON_HERO_CRAWL_RIGHT_STOP
	jmp LABEL_8CAE
LABEL_8D99:
	db 0x11

LABEL_8D9A:
	video type=0, offset=COMMON_VIDEO_133, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_134, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0006
	break
	video type=0, offset=COMMON_VIDEO_135, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0001
	call SET_VAR04_TO_0008
	break
	video type=0, offset=COMMON_VIDEO_136, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_137, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0003
	break
	video type=0, offset=COMMON_VIDEO_138, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0005
	break
	mov [0x2A], 0x000F
	jmp LABEL_8E52
LABEL_8DD8:
	db 0x11

LABEL_8DD9:
	break
	video type=0, offset=COMMON_VIDEO_143, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0003
	break
	jmp PRISON_HERO_CRAWL_LEFT_STOP
