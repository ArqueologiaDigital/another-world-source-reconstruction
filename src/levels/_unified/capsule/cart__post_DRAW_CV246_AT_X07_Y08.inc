LABEL_834D:
	ret

LABEL_834E:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	play id=0x0055, freq=0x0F, vol=0x14, channel=0x00
	add [0x08], 0x0001
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_247, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_248, x=[0x07], y=[0x08], zoom=0x40
	je [0x0D], 0x00, DRAW_CV249_AT_X07_Y08
	call LABEL_827B
	jmp LABEL_837C
