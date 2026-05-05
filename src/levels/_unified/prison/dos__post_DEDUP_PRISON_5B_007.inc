LABEL_5DB7:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video type=0, offset=COMMON_VIDEO_250, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	video type=0, offset=COMMON_VIDEO_257, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	je [0x0D], 0x00, INLINE_DRAW_CV_252_018
	call LABEL_5C4F
	jmp LABEL_5DDB
