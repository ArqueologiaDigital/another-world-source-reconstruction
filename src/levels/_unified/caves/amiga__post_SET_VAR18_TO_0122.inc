LABEL_DD8D:
	deleteChannels first=0x15, last=0x16
	break
	jne [HACK_VAR_67], 0x6F, LABEL_DDA6
	call LABEL_12DE
	call LABEL_12FB
	mov [HERO_X], 0x00E6
	mov [HERO_Y], 0x007D

LABEL_DDA6:
	jne [HACK_VAR_67], 0xED, LABEL_DDB4
	mov [HERO_X], 0x00C8
	mov [HERO_Y], 0x0050

LABEL_DDB4:
	add [HERO_X], 0x000A
	video offset=CINEMATIC_451, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_494, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_495, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_496, x=[HERO_X], y=[HERO_Y]
	play id=0x006C, freq=0x14, vol=0x40, channel=0x01
	break
	video offset=CINEMATIC_497, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_498, x=[HERO_X], y=[HERO_Y]
	mov [0x63], 0x0002
	mov [0x05], 0x0000
	mov [PAUSE_SLICES], 0x0004
	mov [0x32], 0x0000
	setup channel=0x16, address=LABEL_DF3B
	setup channel=0x14, address=LABEL_E54E
	setup channel=0x3E, address=LABEL_C742
	mov [HERO_X], 0x00D9
	jne [HACK_VAR_67], 0x6F, KILL_CHAN_AT_DE0F
	setup channel=0x3E, address=LABEL_C70E
	mov [HERO_X], 0x010E

KILL_CHAN_AT_DE0F:
	killChannel

LABEL_DE10:
	deleteChannels first=0x15, last=0x16
	call LABEL_12DE
	call LABEL_12FB
	break
	mov [HERO_X], 0x005A
	mov [HERO_Y], 0x007D
	sub [HERO_X], 0x000A
	video offset=CINEMATIC_469, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_499, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_500, x=[HERO_X], y=[HERO_Y]
	break
	play id=0x006C, freq=0x14, vol=0x40, channel=0x01
	video offset=CINEMATIC_501, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_502, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_503, x=[HERO_X], y=[HERO_Y]
	mov [0x05], 0x0000
	mov [0x63], 0x0001
	mov [PAUSE_SLICES], 0x0004
	mov [0x32], 0x0000
	setup channel=0x16, address=LABEL_DF3B
	setup channel=0x14, address=LABEL_E41E
	setup channel=0x3E, address=LABEL_C70E
	mov [HERO_X], 0x003C
	killChannel

LABEL_DE71:
	jne [HACK_VAR_67], 0x6F, LABEL_DE82
	jg [HERO_Y], 0x8C, SHARED_RET
	mov [0x22], 0x03E8
	ret

LABEL_DE82:
	jne [HACK_VAR_67], 0xED, SHARED_RET
	jg [HERO_Y], 0x5A, SHARED_RET
	mov [0x22], 0x03E8
	ret

LABEL_DE93:
	je [0x63], 0x03, SHARED_RET
	je [0x63], 0x64, SHARED_RET
	jne [HACK_VAR_67], 0x6F, LABEL_DED9
	jg [HERO_Y], 0x85, SHARED_RET
	mov [0xF8], [HERO_X]
	add [0xF8], [0x2A]
	jl [0xF8], 0xFF, LABEL_DEC2
	je [0x63], 0x01, SHARED_RET
	mov [0x22], 0x03E8
	ret

LABEL_DEC2:
	mov [0xF8], [HERO_X]
	sub [0xF8], [0x2A]
	jg [0xF8], 0x4B, SHARED_RET
	je [0x63], 0x02, SHARED_RET
	mov [0x22], 0x03E9
	ret

LABEL_DED9:
	jne [HACK_VAR_67], 0xED, SHARED_RET
	jg [HERO_Y], 0x55, SHARED_RET
	mov [0xF8], [HERO_X]
	add [0xF8], [0x2A]
	jl [0xF8], 0xD2, SHARED_RET
	je [0x63], 0x01, SHARED_RET
	mov [0x22], 0x03E8
	ret

LABEL_DEFC:
	add [0x22], [0x21]
	add [0x22], [0x21]
	jle [0x22], 0x06, LABEL_DF0C
	mov [0x22], 0x0006

LABEL_DF0C:
	jge [0x22], 0xFFFA, LABEL_DF17
	mov [0x22], 0xFFFA

LABEL_DF17:
	jle [0x22], 0x00, LABEL_DF2C
	sub [0x22], 0x0001
	jg [0x22], 0x00, SHARED_RET
	mov [0x22], 0x0000
	ret

LABEL_DF2C:
	add [0x22], 0x0001
	jl [0x22], 0x00, SHARED_RET
	mov [0x22], 0x0000
	ret

LABEL_DF3B:
	je [0x63], 0x64, LABEL_E07E
	jge [HERO_ACTION_POS_MASK], 0x80, LABEL_DFD4
	jne [HERO_POS_LEFT_RIGHT], 0xFFFF, LABEL_DF66
	je [0x63], 0x01, LABEL_DF66
	setup channel=0x14, address=LABEL_E41E
	je [0x63], 0x05, INLINE_SET_VAR63_TO_1
	setup channel=0x14, address=STEP_DRAW_CV352_LEFT4_RIGHT1
