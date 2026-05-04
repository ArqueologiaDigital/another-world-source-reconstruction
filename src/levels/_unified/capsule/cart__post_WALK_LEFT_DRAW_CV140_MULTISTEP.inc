LABEL_BAE1:
	je [HACK_VAR_67], 0x25, LABEL_BB1B
	video type=0, offset=COMMON_VIDEO_141, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0003
	break
	video type=0, offset=COMMON_VIDEO_137, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0001
	break
	video type=0, offset=COMMON_VIDEO_135, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0006
	break
	video type=0, offset=COMMON_VIDEO_134, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_133, x=[0x01], y=[0x02], zoom=0x40
	mov [0x2A], 0x000F
	call SET_VAR04_TO_0000
	jmp LABEL_C627
LABEL_BB1A:
	db 0x11

LABEL_BB1B:
	video type=0, offset=COMMON_VIDEO_141, x=[0x01], y=[0x02], zoom=0x40
	break
	je [HERO_ACTION_POS_MASK], 0x05, LABEL_B9C5
	je [HERO_ACTION_POS_MASK], 0x06, LABEL_BB31
	jmp LABEL_BB1B
LABEL_BB30:
	db 0x11

LABEL_BB31:
	video type=0, offset=COMMON_VIDEO_139, x=[0x01], y=[0x02], zoom=0x40
	break
	je [HERO_POS_MASK], 0x05, LABEL_B99D

LABEL_BB3D:
	jne [HERO_ACTION_POS_MASK], 0x06, LABEL_BAE1
	video type=0, offset=COMMON_VIDEO_163, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0002
	break
	je [HERO_POS_MASK], 0x05, LABEL_B98D

LABEL_BB53:
	jne [HERO_ACTION_POS_MASK], 0x06, LABEL_BAE1
	video type=0, offset=COMMON_VIDEO_140, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0002
	break
	je [HERO_POS_MASK], 0x05, LABEL_BA5F

LABEL_BB69:
	video type=0, offset=COMMON_VIDEO_147, x=[0x01], y=[0x02], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x06, WALK_LEFT_DRAW_CV140_MULTISTEP
	sub [0x01], 0x0003
	break
	je [HERO_POS_MASK], 0x05, LABEL_BA49

LABEL_BB7F:
	video type=0, offset=COMMON_VIDEO_148, x=[0x01], y=[0x02], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x06, WALK_LEFT_DRAW_CV140_MULTISTEP
	sub [0x01], 0x0002
	break
	je [HERO_POS_MASK], 0x05, LABEL_BA33

LABEL_BB95:
	video type=0, offset=COMMON_VIDEO_146, x=[0x01], y=[0x02], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x06, WALK_LEFT_DRAW_CV140_MULTISTEP
	sub [0x01], 0x0001
	break
	je [HERO_POS_MASK], 0x05, LABEL_BA1D

LABEL_BBAB:
	video type=0, offset=COMMON_VIDEO_145, x=[0x01], y=[0x02], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x06, LABEL_BAB8
	sub [0x01], 0x0002
	break
	je [HERO_POS_MASK], 0x05, LABEL_BA07

LABEL_BBC1:
	video type=0, offset=COMMON_VIDEO_144, x=[0x01], y=[0x02], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x06, LABEL_BAB8
	sub [0x01], 0x0003
	break
	je [HERO_POS_MASK], 0x05, LABEL_B9F1

LABEL_BBD7:
	video type=0, offset=COMMON_VIDEO_143, x=[0x01], y=[0x02], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x06, LABEL_BAB8
	sub [0x01], 0x0004
	break
	je [HERO_POS_MASK], 0x05, LABEL_B9DB

LABEL_BBED:
	jne [HERO_ACTION_POS_MASK], 0x06, LABEL_BAE1
	video type=0, offset=COMMON_VIDEO_142, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0002
	break
	je [HERO_POS_MASK], 0x05, LABEL_B9C5

LABEL_BC03:
	jne [HERO_ACTION_POS_MASK], 0x06, LABEL_BAE1
	video type=0, offset=COMMON_VIDEO_141, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0001
	break
	je [HERO_POS_MASK], 0x05, LABEL_B9AF
	jne [HERO_ACTION_POS_MASK], 0x06, LABEL_BAE1
	jmp LABEL_BB31
	killChannel
	break
	add [0x01], 0x0002
	call LABEL_952D

LABEL_BC2B:
	break
	add [0x01], 0x0002
	call LABEL_9516

LABEL_BC33:
	break
	add [0x01], 0x0002
	call LABEL_94FF

LABEL_BC3B:
	add [0x01], 0x0001
	jmp HERO_WALK_LEFT_LOOP
	break
	add [0x01], 0x0002
	call LABEL_948C

LABEL_BC4A:
	break
	add [0x01], 0x0002
	call LABEL_947D

LABEL_BC52:
	break
	add [0x01], 0x0002
	call LABEL_95A8

LABEL_BC5A:
	add [0x01], 0x0001
	jmp LABEL_BCFA
LABEL_BC61:
	db 0x11
