LABEL_5D5C:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x08], 0x0001
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video type=0, offset=COMMON_VIDEO_203, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_216, x=[0x07], y=[0x08], zoom=0x40
	je [0x0D], 0x00, LABEL_5D7F
	call LABEL_5BF4
	jmp DEDUP_CAVES_5B_007__PRISON_INLINE_SETTERS_AND_INIT_003

LABEL_5D7F:
	video type=0, offset=COMMON_VIDEO_217, x=[0x07], y=[0x08], zoom=0x40
