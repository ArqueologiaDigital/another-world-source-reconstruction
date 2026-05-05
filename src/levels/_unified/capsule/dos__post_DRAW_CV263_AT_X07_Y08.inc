LABEL_7F3B:
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_264, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	call LABEL_7A61
	add [BUDDY_Y], 0x0001
	ret

LABEL_7F4B:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, LABEL_7F5D
	call LABEL_7861
	jmp LABEL_7F62

LABEL_7F5D:
	video type=0, offset=COMMON_VIDEO_266, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40

LABEL_7F62:
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_267, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	call LABEL_7A1F
	ret

LABEL_7F6E:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [BUDDY_Y], 0x0001
	je [0x0D], 0x00, LABEL_7F84
	call DRAW_CV_304_THEN_305
	jmp LABEL_7F89

LABEL_7F84:
	video type=0, offset=COMMON_VIDEO_269, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40

LABEL_7F89:
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_270, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	call LABEL_7A2A
	sub [BUDDY_Y], 0x0001
	ret

LABEL_7F99:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	play id=0x0055, freq=0x14, vol=0x14, channel=0x00
	add [BUDDY_Y], 0x0001
	je [0x0D], 0x00, LABEL_7FB5
	call DRAW_CV_304_THEN_305
	jmp LABEL_7FBA

LABEL_7FB5:
	video type=0, offset=COMMON_VIDEO_272, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40

LABEL_7FBA:
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_273, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	call LABEL_7A35
	sub [BUDDY_Y], 0x0001
	ret

LABEL_7FCA:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, DRAW_CV275_AT_X07_Y08
	call DRAW_CV_304_THEN_305
	jmp LABEL_7FE1
