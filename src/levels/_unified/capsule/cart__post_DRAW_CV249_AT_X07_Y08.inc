LABEL_837C:
	sub [0x08], 0x0001
	ret

LABEL_8381:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x08], 0x0001
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_250, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_251, x=[0x07], y=[0x08], zoom=0x40
	je [0x0D], 0x00, LABEL_83A4
	call LABEL_826F
	jmp LABEL_83A9

LABEL_83A4:
	video type=0, offset=COMMON_VIDEO_252, x=[0x07], y=[0x08], zoom=0x40

LABEL_83A9:
	sub [0x08], 0x0001
	ret

LABEL_83AE:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_253, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_254, x=[0x07], y=[0x08], zoom=0x40
	je [0x0D], 0x00, LABEL_83CD
	call LABEL_827B
	jmp LABEL_83D2

LABEL_83CD:
	video type=0, offset=COMMON_VIDEO_255, x=[0x07], y=[0x08], zoom=0x40

LABEL_83D2:
	ret

LABEL_83D3:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	sub [0x08], 0x0001
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_250, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_256, x=[0x07], y=[0x08], zoom=0x40
	je [0x0D], 0x00, LABEL_83F6
	call LABEL_829E
	jmp LABEL_83FB

LABEL_83F6:
	video type=0, offset=COMMON_VIDEO_255, x=[0x07], y=[0x08], zoom=0x40

LABEL_83FB:
	add [0x08], 0x0001
	ret

LABEL_8400:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_250, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_257, x=[0x07], y=[0x08], zoom=0x40
	je [0x0D], 0x00, LABEL_841F
	call LABEL_829E
	jmp LABEL_8424

LABEL_841F:
	video type=0, offset=COMMON_VIDEO_252, x=[0x07], y=[0x08], zoom=0x40

LABEL_8424:
	ret

LABEL_8425:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	play id=0x0055, freq=0x14, vol=0x14, channel=0x00
	add [0x08], 0x0001
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_247, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_258, x=[0x07], y=[0x08], zoom=0x40
	je [0x0D], 0x00, DRAW_CV259_AT_X07_Y08
	call LABEL_82CD
	jmp LABEL_8453
