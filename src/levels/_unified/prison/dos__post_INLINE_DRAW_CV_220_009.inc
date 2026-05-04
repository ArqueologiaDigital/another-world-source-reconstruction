LABEL_561F:
	call DRAW_SPRITE_CIN_236_239_BY_VAR09
	video type=0, offset=COMMON_VIDEO_233, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_240_IF_VAR09_EQ_1
	call LABEL_53F3
	ret

LABEL_562E:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	play id=0x0055, freq=0x14, vol=0x14, channel=0x01
	je [0x0D], 0x00, 0x5646
	call LABEL_52C8
	jmp LABEL_564B
