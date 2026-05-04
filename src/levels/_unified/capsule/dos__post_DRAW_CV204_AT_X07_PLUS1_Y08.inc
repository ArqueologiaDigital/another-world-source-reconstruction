LABEL_7AB1:
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_208, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_030_031_032_VAR09
	call LABEL_791F
	ret

LABEL_7AC0:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, LABEL_7ACF
	call DRAW_CV_304_THEN_305

LABEL_7ACF:
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_209, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_030_031_032_VAR09
	call LABEL_793C
	ret

LABEL_7ADE:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	play id=0x0055, freq=0x0F, vol=0x14, channel=0x00
	je [0x0D], 0x00, LABEL_7AF3
	call DRAW_CV_304_THEN_305

LABEL_7AF3:
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_210, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_030_031_032_VAR09
	call LABEL_795D
	play id=0x0055, freq=0x0F, vol=0x14, channel=0x00
	ret

LABEL_7B08:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, LABEL_7B17
	call DRAW_CV_304_THEN_305

LABEL_7B17:
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_213, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_030_031_032_VAR09
	call LABEL_797A
	ret

LABEL_7B26:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, LABEL_7B38
	call LABEL_786D
	jmp LABEL_7B3D

LABEL_7B38:
	video type=0, offset=COMMON_VIDEO_216, x=[0x07], y=[0x08], zoom=0x40

LABEL_7B3D:
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_217, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_030_031_032_VAR09
	call LABEL_799B
	ret

LABEL_7B4C:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, LABEL_7B5E
	call LABEL_7861
	jmp LABEL_7B63

LABEL_7B5E:
	video type=0, offset=COMMON_VIDEO_220, x=[0x07], y=[0x08], zoom=0x40

LABEL_7B63:
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_221, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_030_031_032_VAR09
	call LABEL_79BC
	ret

LABEL_7B72:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, DRAW_CV224_AT_X07_Y08
	call LABEL_7843
	jmp LABEL_7B89
