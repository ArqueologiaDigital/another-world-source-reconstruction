LABEL_5AB2:
	call DRAW_SPRITE_CIN_236_239_BY_VAR09
	video type=0, offset=COMMON_VIDEO_270, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_554F
	sub [0x08], 0x0001
	ret

LABEL_5AC2:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x08], 0x0001
	je [0x0D], 0x00, 0x5AD8
	call DRAW_CIN_242_THEN_243
	jmp LABEL_5ADD
