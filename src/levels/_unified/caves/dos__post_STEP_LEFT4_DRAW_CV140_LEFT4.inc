LABEL_E816:
	je [HACK_VAR_67], 0x25, LABEL_E850
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
	jmp LABEL_F386
LABEL_E84F:
	db 0x11

LABEL_E850:
	video type=0, offset=COMMON_VIDEO_141, x=[0x01], y=[0x02], zoom=0x40
	break
	je [HERO_ACTION_POS_MASK], 0x05, LABEL_E706
	je [HERO_ACTION_POS_MASK], 0x06, LABEL_E866
	jmp LABEL_E850
LABEL_E865:
	db 0x11

LABEL_E866:
	video type=0, offset=COMMON_VIDEO_139, x=[0x01], y=[0x02], zoom=0x40
	break
	je [HERO_POS_MASK], 0x05, LABEL_E6DE

LABEL_E872:
	jne [HERO_ACTION_POS_MASK], 0x06, LABEL_E816
	video type=0, offset=COMMON_VIDEO_163, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0002
	break
	je [HERO_POS_MASK], 0x05, LABEL_E6CE

LABEL_E888:
	jne [HERO_ACTION_POS_MASK], 0x06, LABEL_E816
	video type=0, offset=COMMON_VIDEO_140, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0002
	break
	je [HERO_POS_MASK], 0x05, LABEL_E7A0

LABEL_E89E:
	video type=0, offset=COMMON_VIDEO_147, x=[0x01], y=[0x02], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x06, STEP_LEFT4_DRAW_CV140_LEFT4
	sub [0x01], 0x0003
	break
	je [HERO_POS_MASK], 0x05, LABEL_E78A

LABEL_E8B4:
	video type=0, offset=COMMON_VIDEO_148, x=[0x01], y=[0x02], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x06, STEP_LEFT4_DRAW_CV140_LEFT4
	sub [0x01], 0x0002
	break
	je [HERO_POS_MASK], 0x05, LABEL_E774

LABEL_E8CA:
	video type=0, offset=COMMON_VIDEO_146, x=[0x01], y=[0x02], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x06, STEP_LEFT4_DRAW_CV140_LEFT4
	sub [0x01], 0x0001
	break
	je [HERO_POS_MASK], 0x05, LABEL_E75E

LABEL_E8E0:
	video type=0, offset=COMMON_VIDEO_145, x=[0x01], y=[0x02], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x06, LABEL_E7F9
	sub [0x01], 0x0002
	break
	je [HERO_POS_MASK], 0x05, LABEL_E748

LABEL_E8F6:
	video type=0, offset=COMMON_VIDEO_144, x=[0x01], y=[0x02], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x06, LABEL_E7F9
	sub [0x01], 0x0003
	break
	je [HERO_POS_MASK], 0x05, LABEL_E732

LABEL_E90C:
	video type=0, offset=COMMON_VIDEO_143, x=[0x01], y=[0x02], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x06, LABEL_E7F9
	sub [0x01], 0x0004
	break
	je [HERO_POS_MASK], 0x05, LABEL_E71C

LABEL_E922:
	jne [HERO_ACTION_POS_MASK], 0x06, LABEL_E816
	video type=0, offset=COMMON_VIDEO_142, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0002
	break
	je [HERO_POS_MASK], 0x05, LABEL_E706

LABEL_E938:
	jne [HERO_ACTION_POS_MASK], 0x06, LABEL_E816
	video type=0, offset=COMMON_VIDEO_141, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0001
	break
	je [HERO_POS_MASK], 0x05, LABEL_E6F0
	jne [HERO_ACTION_POS_MASK], 0x06, LABEL_E816
	jmp LABEL_E866
	killChannel
	break
	add [0x01], 0x0002
	call LABEL_9EB7

LABEL_E960:
	break
	add [0x01], 0x0002
	call LABEL_9EA0

LABEL_E968:
	break
	add [0x01], 0x0002
	call LABEL_9E89

LABEL_E970:
	add [0x01], 0x0001
	jmp HERO_WALK_LEFT_LOOP
	break
	add [0x01], 0x0002
	call LABEL_9E16

LABEL_E97F:
	break
	add [0x01], 0x0002
	call LABEL_9E07

LABEL_E987:
	break
	add [0x01], 0x0002
	call LABEL_9F32

LABEL_E98F:
	add [0x01], 0x0001
	jmp LABEL_EA2F
LABEL_E996:
	db 0x11
