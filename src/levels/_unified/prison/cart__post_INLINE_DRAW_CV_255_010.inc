LABEL_5E86:
	ret

LABEL_5E87:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	play id=0x0055, freq=0x1C, vol=0x0A, channel=0x01
	sub [0x08], 0x0001
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video type=0, offset=COMMON_VIDEO_250, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_256, x=[0x07], y=[0x08], zoom=0x40
	je [0x0D], 0x00, 0x5EB0
	call LABEL_5D52
	jmp 0x5EB5
