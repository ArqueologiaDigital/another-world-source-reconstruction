LABEL_8C58:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	add [0x08], 0x0001
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_2548, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=CV_FIGURE_RUN_RIGHT_BODY_F03, x=[0x07], y=[0x08], zoom=0x40
	je [0x0D], 0x00, INLINE_DRAW_CV_252_018__HELPER
	call LABEL_8B4C
	jmp DEDUP_CAVES_5B_007_001
