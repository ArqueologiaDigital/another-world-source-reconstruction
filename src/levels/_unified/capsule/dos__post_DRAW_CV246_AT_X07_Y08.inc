LABEL_82E4:
	ret

LABEL_82E5:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	play id=0x0055, freq=0x0F, vol=0x14, channel=0x00
	add [BUDDY_Y], 0x0001
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_247, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	video type=0, offset=COMMON_VIDEO_248, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	je [0x0D], 0x00, DRAW_CV249_AT_X07_Y08
	call LABEL_8212
	jmp LABEL_8313
