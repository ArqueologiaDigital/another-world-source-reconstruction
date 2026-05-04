LABEL_8C8F:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_244, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_245, x=[0x07], y=[0x08], zoom=0x40
	je [0x0D], 0x00, DRAW_CV246_AT_X07_Y08
	call LABEL_8C04
	jmp LABEL_8CB3
