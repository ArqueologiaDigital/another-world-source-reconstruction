LABEL_89B0:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_209, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_210, x=[0x07], y=[0x08], zoom=0x40
	je [0x0D], 0x00, LABEL_89CF
	call LABEL_8883
	jmp LABEL_89D4

LABEL_89CF:
	video type=0, offset=COMMON_VIDEO_211, x=[0x07], y=[0x08], zoom=0x40

LABEL_89D4:
	ret

LABEL_89D5:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	sub [0x08], 0x0001
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_206, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_212, x=[0x07], y=[0x08], zoom=0x40
	je [0x0D], 0x00, LABEL_89F8
	call LABEL_88A6
	jmp DEDUP_CAVES_5B_020	;@raw=0x07,0x89,0xFD

LABEL_89F8:
	video type=0, offset=COMMON_VIDEO_211, x=[0x07], y=[0x08], zoom=0x40
