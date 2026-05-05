LABEL_B93D:
	je [HACK_VAR_67], 0x25, LABEL_B977
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
	jmp LABEL_C6C7
LABEL_B976:
	db 0x11

LABEL_B977:
	video type=0, offset=COMMON_VIDEO_140, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	je [HERO_ACTION_POS_MASK], 0x05, LABEL_B98D
	je [HERO_ACTION_POS_MASK], 0x06, LABEL_BB53
	jmp LABEL_B977
LABEL_B98C:
	db 0x11

LABEL_B98D:
	video type=0, offset=COMMON_VIDEO_140, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0002
	break
	je [HERO_POS_MASK], 0x06, LABEL_BB3D

LABEL_B99D:
	jne [HERO_ACTION_POS_MASK], 0x05, LABEL_B93D
	video type=0, offset=COMMON_VIDEO_163, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	je [HERO_POS_MASK], 0x06, LABEL_BB31

LABEL_B9AF:
	jne [HERO_ACTION_POS_MASK], 0x05, LABEL_B93D
	video type=0, offset=COMMON_VIDEO_139, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0001
	break
	je [HERO_POS_MASK], 0x06, LABEL_BC03

LABEL_B9C5:
	jne [HERO_ACTION_POS_MASK], 0x05, LABEL_B93D
	video type=0, offset=COMMON_VIDEO_141, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0002
	break
	je [HERO_POS_MASK], 0x06, LABEL_BBED

LABEL_B9DB:
	jne [HERO_ACTION_POS_MASK], 0x05, LABEL_B93D
	video type=0, offset=COMMON_VIDEO_142, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0004
	break
	je [HERO_POS_MASK], 0x06, LABEL_BBD7

LABEL_B9F1:
	video type=0, offset=COMMON_VIDEO_143, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x05, WALK_RIGHT_DRAW_CV142_MULTISTEP
	add [HERO_X], 0x0003
	break
	je [HERO_POS_MASK], 0x06, LABEL_BBC1

LABEL_BA07:
	video type=0, offset=COMMON_VIDEO_144, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x05, WALK_RIGHT_DRAW_CV142_MULTISTEP
	add [HERO_X], 0x0002
	break
	je [HERO_POS_MASK], 0x06, LABEL_BBAB

LABEL_BA1D:
	video type=0, offset=COMMON_VIDEO_145, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x05, WALK_RIGHT_DRAW_CV142_MULTISTEP
	add [HERO_X], 0x0001
	break
	je [HERO_POS_MASK], 0x06, LABEL_BB95

LABEL_BA33:
	video type=0, offset=COMMON_VIDEO_146, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x05, LABEL_B914
	add [HERO_X], 0x0002
	break
	je [HERO_POS_MASK], 0x06, LABEL_BB7F

LABEL_BA49:
	video type=0, offset=COMMON_VIDEO_148, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x05, LABEL_B914
	add [HERO_X], 0x0003
	break
	je [HERO_POS_MASK], 0x06, LABEL_BB69

LABEL_BA5F:
	video type=0, offset=COMMON_VIDEO_147, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0002
	break
	je [HERO_POS_MASK], 0x06, LABEL_BB53
	jne [HERO_ACTION_POS_MASK], 0x05, LABEL_B93D
	jmp LABEL_B98D
	killChannel
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
	jmp LABEL_BB31
LABEL_BAB7:
	db 0x11

LABEL_BAB8:
	break
	video type=0, offset=COMMON_VIDEO_143, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0003
	break
	jmp LABEL_BAE1
