LABEL_8C5E:
	jne [0xB6], 0x00, LABEL_8C98
	video type=0, offset=COMMON_VIDEO_140, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0003
	break
	video type=0, offset=COMMON_VIDEO_149, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0001
	break
	video type=0, offset=COMMON_VIDEO_150, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0006
	break
	video type=0, offset=COMMON_VIDEO_151, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_152, x=[0x01], y=[0x02], zoom=0x40
	mov [0x2A], 0x000F
	call SET_VAR04_TO_0010
	jmp LABEL_9A87
LABEL_8C97:
	db 0x11

LABEL_8C98:
	video type=0, offset=COMMON_VIDEO_140, x=[0x01], y=[0x02], zoom=0x40
	break
	je [HERO_ACTION_POS_MASK], 0x05, LABEL_8CAE
	je [HERO_ACTION_POS_MASK], 0x06, LABEL_8E74
	jmp LABEL_8C98
LABEL_8CAD:
	db 0x11

LABEL_8CAE:
	video type=0, offset=COMMON_VIDEO_140, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0002
	break
	je [HERO_POS_MASK], 0x06, LABEL_8E5E

LABEL_8CBE:
	jne [HERO_ACTION_POS_MASK], 0x05, LABEL_8C5E
	video type=0, offset=COMMON_VIDEO_163, x=[0x01], y=[0x02], zoom=0x40
	break
	je [HERO_POS_MASK], 0x06, LABEL_8E52

LABEL_8CD0:
	jne [HERO_ACTION_POS_MASK], 0x05, LABEL_8C5E
	video type=0, offset=COMMON_VIDEO_139, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0001
	break
	je [HERO_POS_MASK], 0x06, LABEL_8F24

LABEL_8CE6:
	jne [HERO_ACTION_POS_MASK], 0x05, LABEL_8C5E
	video type=0, offset=COMMON_VIDEO_141, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0002
	break
	je [HERO_POS_MASK], 0x06, LABEL_8F0E

LABEL_8CFC:
	jne [HERO_ACTION_POS_MASK], 0x05, LABEL_8C5E
	video type=0, offset=COMMON_VIDEO_142, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0004
	break
	je [HERO_POS_MASK], 0x06, LABEL_8EF8

LABEL_8D12:
	video type=0, offset=COMMON_VIDEO_143, x=[0x01], y=[0x02], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x05, WALK_RIGHT_DRAW_CV142_MULTISTEP
	add [0x01], 0x0003
	break
	je [HERO_POS_MASK], 0x06, LABEL_8EE2

LABEL_8D28:
	video type=0, offset=COMMON_VIDEO_144, x=[0x01], y=[0x02], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x05, WALK_RIGHT_DRAW_CV142_MULTISTEP
	add [0x01], 0x0002
	break
	je [HERO_POS_MASK], 0x06, LABEL_8ECC

LABEL_8D3E:
	video type=0, offset=COMMON_VIDEO_145, x=[0x01], y=[0x02], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x05, WALK_RIGHT_DRAW_CV142_MULTISTEP
	add [0x01], 0x0001
	break
	je [HERO_POS_MASK], 0x06, LABEL_8EB6

LABEL_8D54:
	video type=0, offset=COMMON_VIDEO_146, x=[0x01], y=[0x02], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x05, LABEL_8C35
	add [0x01], 0x0002
	break
	je [HERO_POS_MASK], 0x06, LABEL_8EA0

LABEL_8D6A:
	video type=0, offset=COMMON_VIDEO_148, x=[0x01], y=[0x02], zoom=0x40
	jne [HERO_ACTION_POS_MASK], 0x05, LABEL_8C35
	add [0x01], 0x0003
	break
	je [HERO_POS_MASK], 0x06, LABEL_8E8A

LABEL_8D80:
	video type=0, offset=COMMON_VIDEO_147, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0002
	break
	je [HERO_POS_MASK], 0x06, LABEL_8E74
	jne [HERO_ACTION_POS_MASK], 0x05, LABEL_8C5E
	jmp LABEL_8CAE
LABEL_8D99:
	db 0x11

LABEL_8D9A:
	video type=0, offset=COMMON_VIDEO_133, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_134, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0006
	break
	video type=0, offset=COMMON_VIDEO_135, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0001
	call SET_VAR04_TO_0008
	break
	video type=0, offset=COMMON_VIDEO_136, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_137, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0003
	break
	video type=0, offset=COMMON_VIDEO_138, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0005
	break
	mov [0x2A], 0x000F
	jmp LABEL_8E52
LABEL_8DD8:
	db 0x11

LABEL_8DD9:
	break
	video type=0, offset=COMMON_VIDEO_143, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0003
	break
	jmp LABEL_8E02
