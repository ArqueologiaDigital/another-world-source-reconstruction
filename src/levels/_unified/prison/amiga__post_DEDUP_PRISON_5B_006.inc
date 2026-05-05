LABEL_5C33:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video type=0, offset=COMMON_VIDEO_200, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_201, x=[0x07], y=[0x08], zoom=0x40
	je [0x0D], 0x00, LABEL_5C52
	call LABEL_5BA2
	jmp LABEL_5C57

LABEL_5C52:
	video type=0, offset=COMMON_VIDEO_202, x=[0x07], y=[0x08], zoom=0x40

LABEL_5C57:
	ret

LABEL_5C58:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x08], 0x0001
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video type=0, offset=COMMON_VIDEO_203, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_204, x=[0x07], y=[0x08], zoom=0x40
	je [0x0D], 0x00, LABEL_5C7B
	call LABEL_5B7F
	jmp DEDUP_CAVES_5B_007__HELPER

LABEL_5C7B:
	video type=0, offset=COMMON_VIDEO_205, x=[0x07], y=[0x08], zoom=0x40
