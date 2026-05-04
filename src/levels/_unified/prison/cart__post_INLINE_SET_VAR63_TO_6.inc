LABEL_8D02:
	jne [0x0A], 0x00, LABEL_8D4F
	je [0x63], 0x01, LABEL_8D33
	je [0x63], 0x05, LABEL_8D33
	jne [HERO_ACTION_POS_MASK], 0x88, LABEL_8D22
	mov [0x63], 0x0064
	setup channel=0x14, address=LABEL_9964

LABEL_8D22:
	jne [HERO_ACTION_POS_MASK], 0x84, JUMP_TO_LABEL_8D4F_AT_8D30
	mov [0x63], 0x0064
	setup channel=0x14, address=LABEL_99F6

JUMP_TO_LABEL_8D4F_AT_8D30:
	jmp LABEL_8D4F

LABEL_8D33:
	jne [HERO_ACTION_POS_MASK], 0x88, LABEL_8D41
	mov [0x63], 0x0064
	setup channel=0x14, address=LABEL_9636

LABEL_8D41:
	jne [HERO_ACTION_POS_MASK], 0x84, LABEL_8D4F
	mov [0x63], 0x0064
	setup channel=0x14, address=LABEL_99AD

LABEL_8D4F:
	break
	jmp LABEL_8BC5
LABEL_8D53:
	db 0x11

LABEL_8D54:
	video type=0, offset=COMMON_VIDEO_152, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_151, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0006
	break
	video type=0, offset=COMMON_VIDEO_150, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0001
	call SET_VAR04_TO_0008
	break
	video type=0, offset=COMMON_VIDEO_161, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=0, offset=COMMON_VIDEO_149, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0003
	break
	video type=0, offset=COMMON_VIDEO_162, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0005
	break
	mov [0x2A], 0x000F
	jmp LABEL_8E10
LABEL_8D92:
	db 0x11

LABEL_8D93:
	break
	video type=0, offset=COMMON_VIDEO_147, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0003
	break
	jmp LABEL_8DBC
