LABEL_5DE3:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video type=0, offset=COMMON_VIDEO_244, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	video type=0, offset=COMMON_VIDEO_245, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	je [0x0D], 0x00, DRAW_CV246_AT_X07_Y08
	call LABEL_5D52
	jmp LABEL_5E07
