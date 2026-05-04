LABEL_8417:
	sub [0x08], 0x0001
	ret

LABEL_841C:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_244, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_262, x=[0x07], y=[0x08], zoom=0x40
	sub [0x07], 0x0001
	je [0x0D], 0x00, LABEL_843F
	call LABEL_8264
	jmp INCREMENT_VAR07_BY_1

LABEL_843F:
	video type=0, offset=COMMON_VIDEO_243, x=[0x07], y=[0x08], zoom=0x40
