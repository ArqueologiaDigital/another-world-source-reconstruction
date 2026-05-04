LABEL_5E36:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video type=0, offset=COMMON_VIDEO_244, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_262, x=[0x07], y=[0x08], zoom=0x40
	sub [0x07], 0x0001
	je [0x0D], 0x00, 0x5E59
	call LABEL_5C7E
	jmp INCREMENT_VAR07_BY_1
