LABEL_8A02:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_206, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_213, x=[0x07], y=[0x08], zoom=0x40
	je [0x0D], 0x00, LABEL_8A21
	call LABEL_88A6
	jmp LABEL_8A26

LABEL_8A21:
	video type=0, offset=COMMON_VIDEO_208, x=[0x07], y=[0x08], zoom=0x40

LABEL_8A26:
	ret

LABEL_8A27:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x08], 0x0001
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_203, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_214, x=[0x07], y=[0x08], zoom=0x40
	je [0x0D], 0x00, LABEL_8A4A
	call LABEL_88D5
	jmp 0x8A4F

LABEL_8A4A:
	video type=0, offset=COMMON_VIDEO_215, x=[0x07], y=[0x08], zoom=0x40
