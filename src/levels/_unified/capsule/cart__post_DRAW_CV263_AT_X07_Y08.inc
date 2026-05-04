LABEL_7FA4:
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_264, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_7ACA
	add [0x08], 0x0001
	ret

LABEL_7FB4:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, LABEL_7FC6
	call LABEL_78CA
	jmp LABEL_7FCB

LABEL_7FC6:
	video type=0, offset=COMMON_VIDEO_266, x=[0x07], y=[0x08], zoom=0x40

LABEL_7FCB:
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_267, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_7A88
	ret

LABEL_7FD7:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x08], 0x0001
	je [0x0D], 0x00, LABEL_7FED
	call DRAW_CV_304_THEN_305
	jmp LABEL_7FF2

LABEL_7FED:
	video type=0, offset=COMMON_VIDEO_269, x=[0x07], y=[0x08], zoom=0x40

LABEL_7FF2:
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_270, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_7A93
	sub [0x08], 0x0001
	ret

LABEL_8002:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	play id=0x0055, freq=0x14, vol=0x14, channel=0x00
	add [0x08], 0x0001
	je [0x0D], 0x00, LABEL_801E
	call DRAW_CV_304_THEN_305
	jmp LABEL_8023

LABEL_801E:
	video type=0, offset=COMMON_VIDEO_272, x=[0x07], y=[0x08], zoom=0x40

LABEL_8023:
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_273, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_7A9E
	sub [0x08], 0x0001
	ret

LABEL_8033:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, DRAW_CV275_AT_X07_Y08
	call DRAW_CV_304_THEN_305
	jmp LABEL_804A
