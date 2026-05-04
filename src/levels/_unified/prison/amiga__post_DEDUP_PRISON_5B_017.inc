LABEL_5D89:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video type=0, offset=COMMON_VIDEO_200, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_218, x=[0x07], y=[0x08], zoom=0x40
	sub [0x07], 0x0001
	je [0x0D], 0x00, LABEL_5DAC
	call LABEL_5BD1
	jmp INCREMENT_VAR07_BY_1

LABEL_5DAC:
	video type=0, offset=COMMON_VIDEO_199, x=[0x07], y=[0x08], zoom=0x40
