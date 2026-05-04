LABEL_9598:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_HERO_Y_PLUS_E
	video type=0, offset=COMMON_VIDEO_288, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_820A
	ret

LABEL_95AA:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	sub [0x07], 0x0001
	call DRAW_HERO_Y_PLUS_E
	video type=0, offset=COMMON_VIDEO_289, x=[0x07], y=[0x08], zoom=0x40
	sub [0x08], 0x0001
	call LABEL_8238
	add [0x08], 0x0001
	add [0x07], 0x0001
	ret

LABEL_95CC:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_HERO_Y_PLUS_E
	video type=0, offset=COMMON_VIDEO_288, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_826A
	ret

LABEL_95DE:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_HERO_Y_PLUS_E
	video type=0, offset=COMMON_VIDEO_288, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_8238
	ret

LABEL_95F0:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_HERO_Y_PLUS_E
	video type=0, offset=COMMON_VIDEO_288, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	je [0x0D], 0x00, LABEL_960E
	call LABEL_8C33
	jmp DECREMENT_VAR08_BY_D

LABEL_960E:
	call LABEL_8F24
