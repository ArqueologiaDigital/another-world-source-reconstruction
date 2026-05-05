LABEL_8F64:
	jne [0xB6], 0x00, LABEL_8F9E
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
	jmp LABEL_9B1E
LABEL_8F9D:
	db 0x11

LABEL_8F9E:
	video type=0, offset=COMMON_VIDEO_141, x=[HERO_X], y=[HERO_Y], zoom=0x40
	mov [0x04], 0x0010
	break
	je [HERO_ACTION_POS_MASK], 0x05, LABEL_8E48
	je [HERO_ACTION_POS_MASK], 0x06, LABEL_8FB8
	jmp LABEL_8F9E
LABEL_8FB7:
	db 0x11

LABEL_8FB8:
	video type=0, offset=COMMON_VIDEO_139, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	je [HERO_POS_MASK], 0x05, LABEL_8E20

LABEL_8FC4:
	jne [HERO_ACTION_POS_MASK], 0x06, LABEL_8F64
	video type=0, offset=COMMON_VIDEO_163, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0002
	break
	je [HERO_POS_MASK], 0x05, LABEL_8E10

LABEL_8FDA:
	jne [HERO_ACTION_POS_MASK], 0x06, LABEL_8F64
	video type=0, offset=COMMON_VIDEO_140, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0002
	break
	je [HERO_POS_MASK], 0x05, LABEL_8EE2

LABEL_8FF0:
	video type=0, offset=COMMON_VIDEO_147, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x06, WALK_LEFT_DRAW_CV140_MULTISTEP
	sub [HERO_X], 0x0003
	break
	je [HERO_POS_MASK], 0x05, LABEL_8ECC

LABEL_9006:
	video type=0, offset=COMMON_VIDEO_148, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x06, WALK_LEFT_DRAW_CV140_MULTISTEP
	sub [HERO_X], 0x0002
	break
	je [HERO_POS_MASK], 0x05, LABEL_8EB6

LABEL_901C:
	video type=0, offset=COMMON_VIDEO_146, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x06, WALK_LEFT_DRAW_CV140_MULTISTEP
	sub [HERO_X], 0x0001
	break
	je [HERO_POS_MASK], 0x05, LABEL_8EA0

LABEL_9032:
	video type=0, offset=COMMON_VIDEO_145, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x06, LABEL_8F3B
	sub [HERO_X], 0x0002
	break
	je [HERO_POS_MASK], 0x05, LABEL_8E8A

LABEL_9048:
	video type=0, offset=COMMON_VIDEO_144, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x06, LABEL_8F3B
	sub [HERO_X], 0x0003
	break
	je [HERO_POS_MASK], 0x05, LABEL_8E74

LABEL_905E:
	video type=0, offset=COMMON_VIDEO_143, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x06, LABEL_8F3B
	sub [HERO_X], 0x0004
	break
	je [HERO_POS_MASK], 0x05, LABEL_8E5E

LABEL_9074:
	jne [HERO_ACTION_POS_MASK], 0x06, LABEL_8F64
	video type=0, offset=COMMON_VIDEO_142, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0002
	break
	je [HERO_POS_MASK], 0x05, LABEL_8E48

LABEL_908A:
	jne [HERO_ACTION_POS_MASK], 0x06, LABEL_8F64
	video type=0, offset=COMMON_VIDEO_141, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0001
	break
	je [HERO_POS_MASK], 0x05, LABEL_8E32
	jne [HERO_ACTION_POS_MASK], 0x06, LABEL_8F64
	jmp LABEL_8FB8
	killChannel
	break
	add [HERO_X], 0x0002
	call LABEL_6FA9

LABEL_90B2:
	break
	add [HERO_X], 0x0002
	call LABEL_6F92

LABEL_90BA:
	break
	add [HERO_X], 0x0002
	call LABEL_6F7B

LABEL_90C2:
	add [HERO_X], 0x0001
	jmp HERO_WALK_LEFT_LOOP
	break
	add [HERO_X], 0x0002
	call LABEL_6F0E

LABEL_90D1:
	break
	add [HERO_X], 0x0002
	call LABEL_6EFF

LABEL_90D9:
	break
	add [HERO_X], 0x0002
	call LABEL_701E

LABEL_90E1:
	add [HERO_X], 0x0001
	jmp LABEL_9187
LABEL_90E8:
	db 0x11
