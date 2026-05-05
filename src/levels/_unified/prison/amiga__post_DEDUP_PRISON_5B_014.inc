LABEL_5C85:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [BUDDY_Y], 0x0001
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video type=0, offset=COMMON_VIDEO_206, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	video type=0, offset=COMMON_VIDEO_207, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	je [0x0D], 0x00, LABEL_5CA8
	call LABEL_5B73
	jmp DEDUP_CAVES_5B_007_001

LABEL_5CA8:
	video type=0, offset=COMMON_VIDEO_208, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
