LABEL_8DB2:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x08], 0x0001
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_247, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_260, x=[0x07], y=[0x08], zoom=0x40
	je [0x0D], 0x00, DRAW_CV261_AT_X07_Y08
	call LABEL_8C56
	jmp DEDUP_CAVES_5B_007	;@raw=0x07,0x8D,0xDA
