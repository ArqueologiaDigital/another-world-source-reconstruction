LABEL_5722:
	call DRAW_SPRITE_CIN_236_239_BY_VAR09
	video type=0, offset=COMMON_VIDEO_233, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_240_IF_VAR09_EQ_1
	call LABEL_54F6
	ret

LABEL_5731:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	play id=0x0055, freq=0x14, vol=0x14, channel=0x01
	je [0x0D], 0x00, INLINE_DRAW_CV_216_027	;@raw=0x0A,0x00,0x0D,0x00,0x57,0x49
	call LABEL_53CB
	jmp LABEL_574E
