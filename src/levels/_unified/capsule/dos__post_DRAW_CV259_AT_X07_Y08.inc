LABEL_83EA:
	sub [BUDDY_Y], 0x0001
	ret

LABEL_83EF:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [BUDDY_Y], 0x0001
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_247, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	video type=0, offset=COMMON_VIDEO_260, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	je [0x0D], 0x00, DRAW_CV261_AT_X07_Y08
	call LABEL_8287
	jmp LABEL_8417
