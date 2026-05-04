LABEL_8983:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x08], 0x0001
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_206, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_207, x=[0x07], y=[0x08], zoom=0x40
	je [0x0D], 0x00, LABEL_89A6
	call LABEL_8877
	jmp DEDUP_CAVES_5B_007__CAVES_INLINE_SETTERS_AND_INIT_001

LABEL_89A6:
	video type=0, offset=COMMON_VIDEO_208, x=[0x07], y=[0x08], zoom=0x40
