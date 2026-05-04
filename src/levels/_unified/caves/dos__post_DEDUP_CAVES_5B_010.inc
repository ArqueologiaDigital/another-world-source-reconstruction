LABEL_8DDF:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_244, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_262, x=[0x07], y=[0x08], zoom=0x40
	sub [0x07], 0x0001
	je [0x0D], 0x00, INLINE_DRAW_CV_243_012
	call LABEL_8C33
	jmp INCREMENT_VAR07_BY_1
