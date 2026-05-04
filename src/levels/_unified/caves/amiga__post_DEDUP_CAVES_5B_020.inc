LABEL_8931:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_200, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_201, x=[0x07], y=[0x08], zoom=0x40
	je [0x0D], 0x00, LABEL_8950
	call LABEL_88A6
	jmp LABEL_8955

LABEL_8950:
	video type=0, offset=COMMON_VIDEO_202, x=[0x07], y=[0x08], zoom=0x40

LABEL_8955:
	ret

LABEL_8956:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x08], 0x0001
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_203, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_204, x=[0x07], y=[0x08], zoom=0x40
	je [0x0D], 0x00, LABEL_8979
	call LABEL_8883
	jmp DEDUP_CAVES_5B_007__HELPER_DEDUP_CAVES_5B_007

LABEL_8979:
	video type=0, offset=COMMON_VIDEO_205, x=[0x07], y=[0x08], zoom=0x40
