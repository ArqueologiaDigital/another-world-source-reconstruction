LABEL_5D0A:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video type=0, offset=COMMON_VIDEO_206, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_213, x=[0x07], y=[0x08], zoom=0x40
	je [0x0D], 0x00, LABEL_5D29
	call LABEL_5BA2
	jmp LABEL_5D2E

LABEL_5D29:
	video type=0, offset=COMMON_VIDEO_208, x=[0x07], y=[0x08], zoom=0x40

LABEL_5D2E:
	ret

LABEL_5D2F:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x08], 0x0001
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video type=0, offset=COMMON_VIDEO_203, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_214, x=[0x07], y=[0x08], zoom=0x40
	je [0x0D], 0x00, LABEL_5D52
	call LABEL_5BD1
	jmp DEDUP_CAVES_5B_007__PRISON_INLINE_SETTERS_AND_INIT_002

LABEL_5D52:
	video type=0, offset=COMMON_VIDEO_215, x=[0x07], y=[0x08], zoom=0x40
