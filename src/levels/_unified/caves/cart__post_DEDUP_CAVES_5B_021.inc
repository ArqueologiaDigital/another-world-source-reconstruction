LABEL_8CD7:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_2548, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=CV_232C, x=[0x07], y=[0x08], zoom=0x40
	je [0x0D], 0x00, INLINE_DRAW_CV_252_018
	call CAVES_INLINE_DRAW_CV_255_031_L2
	jmp CAVES_INLINE_DRAW_CV_252_023_L0
