LABEL_5A76:
	call DRAW_SPRITE_CIN_236_239_BY_VAR09
	video type=0, offset=COMMON_VIDEO_280, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_546D
	sub [0x08], 0x0001
	ret

LABEL_5A86:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x08], 0x0001
	je [0x0D], 0x00, 0x5A9C
	call LABEL_52BC
	jmp LABEL_5AA1
