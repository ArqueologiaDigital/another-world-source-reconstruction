LABEL_B9FD:
	je [HACK_VAR_67], 0x25, LABEL_BA37
	video type=0, offset=COMMON_VIDEO_141, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0003
	break
	video type=0, offset=COMMON_VIDEO_137, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0001
	break
	video type=0, offset=COMMON_VIDEO_135, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0006
	break
	video type=0, offset=COMMON_VIDEO_134, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_133, x=[HERO_X], y=[HERO_Y], zoom=0x40
	mov [0x2A], 0x000F
	call SET_VAR04_TO_0000
	jmp LABEL_C543
LABEL_BA36:
	db 0x11

LABEL_BA37:
	video type=0, offset=COMMON_VIDEO_141, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	je [HERO_ACTION_POS_MASK], 0x05, LABEL_B8E1
	je [HERO_ACTION_POS_MASK], 0x06, LABEL_BA4D
	jmp LABEL_BA37
LABEL_BA4C:
	db 0x11

LABEL_BA4D:
	video type=0, offset=COMMON_VIDEO_139, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	je [HERO_POS_MASK], 0x05, LABEL_B8B9

LABEL_BA59:
	jne [HERO_ACTION_POS_MASK], 0x06, LABEL_B9FD
	video type=0, offset=COMMON_VIDEO_163, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0002
	break
	je [HERO_POS_MASK], 0x05, LABEL_B8A9

LABEL_BA6F:
	jne [HERO_ACTION_POS_MASK], 0x06, LABEL_B9FD
	video type=0, offset=COMMON_VIDEO_140, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0002
	break
	je [HERO_POS_MASK], 0x05, LABEL_B97B

LABEL_BA85:
	video type=0, offset=COMMON_VIDEO_147, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x06, WALK_LEFT_DRAW_CV140_MULTISTEP
	sub [HERO_X], 0x0003
	break
	je [HERO_POS_MASK], 0x05, LABEL_B965

LABEL_BA9B:
	video type=0, offset=COMMON_VIDEO_148, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x06, WALK_LEFT_DRAW_CV140_MULTISTEP
	sub [HERO_X], 0x0002
	break
	je [HERO_POS_MASK], 0x05, LABEL_B94F

LABEL_BAB1:
	video type=0, offset=COMMON_VIDEO_146, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x06, WALK_LEFT_DRAW_CV140_MULTISTEP
	sub [HERO_X], 0x0001
	break
	je [HERO_POS_MASK], 0x05, LABEL_B939

LABEL_BAC7:
	video type=0, offset=COMMON_VIDEO_145, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x06, LABEL_B9D4
	sub [HERO_X], 0x0002
	break
	je [HERO_POS_MASK], 0x05, LABEL_B923

LABEL_BADD:
	video type=0, offset=COMMON_VIDEO_144, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x06, LABEL_B9D4
	sub [HERO_X], 0x0003
	break
	je [HERO_POS_MASK], 0x05, LABEL_B90D

LABEL_BAF3:
	video type=0, offset=COMMON_VIDEO_143, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x06, LABEL_B9D4
	sub [HERO_X], 0x0004
	break
	je [HERO_POS_MASK], 0x05, LABEL_B8F7

LABEL_BB09:
	jne [HERO_ACTION_POS_MASK], 0x06, LABEL_B9FD
	video type=0, offset=COMMON_VIDEO_142, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0002
	break
	je [HERO_POS_MASK], 0x05, LABEL_B8E1

LABEL_BB1F:
	jne [HERO_ACTION_POS_MASK], 0x06, LABEL_B9FD
	video type=0, offset=COMMON_VIDEO_141, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0001
	break
	je [HERO_POS_MASK], 0x05, LABEL_B8CB
	jne [HERO_ACTION_POS_MASK], 0x06, LABEL_B9FD
	jmp LABEL_BA4D
	killChannel
	break
	add [HERO_X], 0x0002
	call LABEL_94C4

LABEL_BB47:
	break
	add [HERO_X], 0x0002
	call LABEL_94AD

LABEL_BB4F:
	break
	add [HERO_X], 0x0002
	call LABEL_9496

LABEL_BB57:
	add [HERO_X], 0x0001
	jmp HERO_WALK_LEFT_LOOP
	break
	add [HERO_X], 0x0002
	call LABEL_9423

LABEL_BB66:
	break
	add [HERO_X], 0x0002
	call LABEL_9414

LABEL_BB6E:
	break
	add [HERO_X], 0x0002
	call LABEL_953F

LABEL_BB76:
	add [HERO_X], 0x0001
	jmp LABEL_BC16
LABEL_BB7D:
	db 0x11
