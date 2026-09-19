LABEL_8A81:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_255C, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=CV_2380, x=[0x07], y=[0x08], zoom=0x40
	sub [0x07], 0x0001
	je [0x0D], 0x00, LABEL_8AA4
	call LABEL_88D5
	jmp INCREMENT_VAR07_BY_1

LABEL_8AA4:
	video type=0, offset=CV_6108, x=[0x07], y=[0x08], zoom=0x40
