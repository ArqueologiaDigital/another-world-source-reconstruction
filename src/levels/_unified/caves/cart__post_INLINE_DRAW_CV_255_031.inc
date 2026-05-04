LABEL_8CA9:
	ret

LABEL_8CAA:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	sub [0x08], 0x0001
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_250, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_256, x=[0x07], y=[0x08], zoom=0x40
	je [0x0D], 0x00, 0x8CCD
	call LABEL_8B7B
	jmp 0x8CD2
