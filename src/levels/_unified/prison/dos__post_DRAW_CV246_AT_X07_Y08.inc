LABEL_5D04:
	ret

LABEL_5D05:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x08], 0x0001
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video type=0, offset=COMMON_VIDEO_247, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_248, x=[0x07], y=[0x08], zoom=0x40
	je [0x0D], 0x00, DRAW_CV249_AT_X07_Y08
	call LABEL_5C2C
	jmp DEDUP_CAVES_5B_007__HELPER
