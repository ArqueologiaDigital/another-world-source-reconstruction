LABEL_8C85:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_253, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_254, x=[0x07], y=[0x08], zoom=0x40
	je [0x0D], 0x00, INLINE_DRAW_CV_255_010	;@raw=0x0A,0x00,0x0D,0x00,0x8C,0xA4
	call LABEL_8B58
	jmp LABEL_8CA9
