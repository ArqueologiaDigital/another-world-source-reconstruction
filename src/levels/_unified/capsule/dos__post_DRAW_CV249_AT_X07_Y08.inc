LABEL_8313:
	sub [BUDDY_Y], 0x0001
	ret

LABEL_8318:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [BUDDY_Y], 0x0001
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_250, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	video type=0, offset=COMMON_VIDEO_251, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	je [0x0D], 0x00, LABEL_833B
	call LABEL_8206
	jmp LABEL_8340

LABEL_833B:
	video type=0, offset=COMMON_VIDEO_252, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40

LABEL_8340:
	sub [BUDDY_Y], 0x0001
	ret

LABEL_8345:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_253, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	video type=0, offset=COMMON_VIDEO_254, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	je [0x0D], 0x00, LABEL_8364
	call LABEL_8212
	jmp LABEL_8369

LABEL_8364:
	video type=0, offset=COMMON_VIDEO_255, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40

LABEL_8369:
	ret

LABEL_836A:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	sub [BUDDY_Y], 0x0001
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_250, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	video type=0, offset=COMMON_VIDEO_256, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	je [0x0D], 0x00, LABEL_838D
	call LABEL_8235
	jmp LABEL_8392

LABEL_838D:
	video type=0, offset=COMMON_VIDEO_255, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40

LABEL_8392:
	add [BUDDY_Y], 0x0001
	ret

LABEL_8397:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_250, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	video type=0, offset=COMMON_VIDEO_257, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	je [0x0D], 0x00, LABEL_83B6
	call LABEL_8235
	jmp LABEL_83BB

LABEL_83B6:
	video type=0, offset=COMMON_VIDEO_252, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40

LABEL_83BB:
	ret

LABEL_83BC:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	play id=0x0055, freq=0x14, vol=0x14, channel=0x00
	add [BUDDY_Y], 0x0001
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_247, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	video type=0, offset=COMMON_VIDEO_258, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	je [0x0D], 0x00, DRAW_CV259_AT_X07_Y08
	call LABEL_8264
	jmp LABEL_83EA
