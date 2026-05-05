LABEL_5D83:
	ret

LABEL_5D84:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	play id=0x0055, freq=0x1C, vol=0x0A, channel=0x01
	sub [BUDDY_Y], 0x0001
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video type=0, offset=COMMON_VIDEO_250, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	video type=0, offset=COMMON_VIDEO_256, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	je [0x0D], 0x00, INLINE_DRAW_CV_255_010
	call LABEL_5C4F
	jmp DEDUP_CAVES_5B_020
