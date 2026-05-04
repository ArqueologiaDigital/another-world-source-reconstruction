LABEL_5961:
	call DRAW_SPRITE_CIN_236_239_BY_VAR09
	video type=0, offset=COMMON_VIDEO_264, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_5483
	add [0x08], 0x0001
	ret

LABEL_5971:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, 0x5983
	call LABEL_52E6
	jmp LABEL_5988
