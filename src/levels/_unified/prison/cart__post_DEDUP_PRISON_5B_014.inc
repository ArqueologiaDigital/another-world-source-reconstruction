LABEL_5E35:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x08], 0x0001
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video type=0, offset=COMMON_VIDEO_250, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_251, x=[0x07], y=[0x08], zoom=0x40
	je [0x0D], 0x00, 0x5E58
	call LABEL_5D23
	jmp 0x5E5D
