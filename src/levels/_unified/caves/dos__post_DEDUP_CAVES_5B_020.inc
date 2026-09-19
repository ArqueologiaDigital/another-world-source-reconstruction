LABEL_8C8F:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_255C, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=CV_1FE4, x=[0x07], y=[0x08], zoom=0x40
	je [0x0D], 0x00, DRAW_CV246_AT_X07_Y08
	call CAVES_INLINE_DRAW_CV_255_031_L2
	jmp CAVES_DRAW_CV246_AT_X07_Y08_L0
