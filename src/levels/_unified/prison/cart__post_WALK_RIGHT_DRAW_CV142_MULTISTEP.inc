PRISON_HERO_CRAWL_RIGHT_STOP:
	jne [0xB6], 0x00, LABEL_8DF6
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
	jmp LABEL_9C05
LABEL_8DF5:
	db 0x11

LABEL_8DF6:
	video type=0, offset=COMMON_VIDEO_140, x=[HERO_X], y=[HERO_Y], zoom=0x40
	mov [0x04], 0x0010
	break
	je [HERO_ACTION_POS_MASK], 0x05, LABEL_8E10
	je [HERO_ACTION_POS_MASK], 0x06, LABEL_8FDA
	jmp LABEL_8DF6
LABEL_8E0F:
	db 0x11

LABEL_8E10:
	video type=0, offset=COMMON_VIDEO_140, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0002
	break
	je [HERO_POS_MASK], 0x06, LABEL_8FC4

LABEL_8E20:
	jne [HERO_ACTION_POS_MASK], 0x05, PRISON_HERO_CRAWL_RIGHT_STOP
	video type=0, offset=COMMON_VIDEO_163, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	je [HERO_POS_MASK], 0x06, LABEL_8FB8

LABEL_8E32:
	jne [HERO_ACTION_POS_MASK], 0x05, PRISON_HERO_CRAWL_RIGHT_STOP
	video type=0, offset=COMMON_VIDEO_139, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0001
	break
	je [HERO_POS_MASK], 0x06, LABEL_908A

LABEL_8E48:
	jne [HERO_ACTION_POS_MASK], 0x05, PRISON_HERO_CRAWL_RIGHT_STOP
	video type=0, offset=COMMON_VIDEO_141, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0002
	break
	je [HERO_POS_MASK], 0x06, LABEL_9074

PRISON_HERO_CRAWL_LEFT_PHASE_01:
	jne [HERO_ACTION_POS_MASK], 0x05, PRISON_HERO_CRAWL_RIGHT_STOP
	video type=0, offset=COMMON_VIDEO_142, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0004
	break
	je [HERO_POS_MASK], 0x06, LABEL_905E

PRISON_HERO_CRAWL_LEFT_PHASE_00:
	video type=0, offset=COMMON_VIDEO_143, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x05, WALK_RIGHT_DRAW_CV142_MULTISTEP
	add [HERO_X], 0x0003
	break
	je [HERO_POS_MASK], 0x06, LABEL_9048

PRISON_HERO_CRAWL_LEFT_PHASE_10:
	video type=0, offset=COMMON_VIDEO_144, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x05, WALK_RIGHT_DRAW_CV142_MULTISTEP
	add [HERO_X], 0x0002
	break
	je [HERO_POS_MASK], 0x06, LABEL_9032

PRISON_HERO_CRAWL_LEFT_PHASE_09:
	video type=0, offset=COMMON_VIDEO_145, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x05, WALK_RIGHT_DRAW_CV142_MULTISTEP
	add [HERO_X], 0x0001
	break
	je [HERO_POS_MASK], 0x06, LABEL_901C

PRISON_HERO_CRAWL_LEFT_PHASE_08:
	video type=0, offset=COMMON_VIDEO_146, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x05, LABEL_8D93
	add [HERO_X], 0x0002
	break
	je [HERO_POS_MASK], 0x06, LABEL_9006

PRISON_HERO_CRAWL_LEFT_PHASE_07:
	video type=0, offset=COMMON_VIDEO_148, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x05, LABEL_8D93
	add [HERO_X], 0x0003
	break
	je [HERO_POS_MASK], 0x06, LABEL_8FF0

PRISON_HERO_CRAWL_LEFT_PHASE_06:
	video type=0, offset=COMMON_VIDEO_147, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0002
	break
	je [HERO_POS_MASK], 0x06, LABEL_8FDA
	jne [HERO_ACTION_POS_MASK], 0x05, PRISON_HERO_CRAWL_RIGHT_STOP
	jmp LABEL_8E10
LABEL_8EFB:
	db 0x11

PRISON_HERO_CRAWL_LEFT_START:
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
	jmp LABEL_8FB8
LABEL_8F3A:
	db 0x11

LABEL_8F3B:
	break
	video type=0, offset=COMMON_VIDEO_143, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0003
	break
	jmp PRISON_HERO_CRAWL_LEFT_STOP
