LABEL_8D56:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_255C, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=CV_FIGURE_RUN_RIGHT_BODY_F09, x=[0x07], y=[0x08], zoom=0x40
	sub [0x07], 0x0001
	je [0x0D], 0x00, INLINE_DRAW_CV_243_012
	call CAVES_DRAW_CV_355_L9
	jmp INCREMENT_VAR07_BY_1
