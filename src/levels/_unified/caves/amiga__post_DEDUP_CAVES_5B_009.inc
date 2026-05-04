LABEL_8A54:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x08], 0x0001
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_203, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_216, x=[0x07], y=[0x08], zoom=0x40
	je [0x0D], 0x00, LABEL_8A77
	call LABEL_88F8
	jmp DEDUP_CAVES_5B_007	;@raw=0x07,0x8A,0x7C

LABEL_8A77:
	video type=0, offset=COMMON_VIDEO_217, x=[0x07], y=[0x08], zoom=0x40
