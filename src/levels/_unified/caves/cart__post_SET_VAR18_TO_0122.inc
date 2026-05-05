LABEL_E366:
	deleteChannels first=0x15, last=0x16
	break
	jne [HACK_VAR_67], 0x6F, LABEL_E37F
	call LABEL_1439
	call LABEL_1456
	mov [HERO_X], 0x00E6
	mov [HERO_Y], 0x007D

LABEL_E37F:
	jne [HACK_VAR_67], 0xED, LABEL_E38D
	mov [HERO_X], 0x00BE
	mov [HERO_Y], 0x0050

LABEL_E38D:
	add [HERO_X], 0x000A
	video offset=CINEMATIC_473, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_516, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_517, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_518, x=[HERO_X], y=[HERO_Y]
	play id=0x006C, freq=0x14, vol=0x40, channel=0x01
	break
	video offset=CINEMATIC_519, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_520, x=[HERO_X], y=[HERO_Y]
	mov [0x63], 0x0002
	mov [0x05], 0x0000
	mov [PAUSE_SLICES], 0x0004
	mov [0x32], 0x0000
	setup channel=0x16, address=SETUP_CHAN_14_BY_VAR63
	setup channel=0x14, address=LABEL_EBC2
	setup channel=0x3E, address=LABEL_CBCD
	mov [HERO_X], 0x00D9
	jne [HACK_VAR_67], 0x6F, KILL_CHAN_AT_E3E8
	setup channel=0x3E, address=LABEL_CB8C
	mov [HERO_X], 0x010E

KILL_CHAN_AT_E3E8:
	killChannel

LABEL_E3E9:
	deleteChannels first=0x15, last=0x16
	call LABEL_1439
	call LABEL_1456
	break
	mov [HERO_X], 0x005A
	mov [HERO_Y], 0x007D
	sub [HERO_X], 0x000A
	video offset=CINEMATIC_491, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_521, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_522, x=[HERO_X], y=[HERO_Y]
	break
	play id=0x006C, freq=0x14, vol=0x40, channel=0x01
	video offset=CINEMATIC_523, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_524, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_525, x=[HERO_X], y=[HERO_Y]
	mov [0x05], 0x0000
	mov [0x63], 0x0001
	mov [PAUSE_SLICES], 0x0004
	mov [0x32], 0x0000
	setup channel=0x16, address=SETUP_CHAN_14_BY_VAR63
	setup channel=0x14, address=LABEL_EA2E
	setup channel=0x3E, address=LABEL_CB8C
	mov [HERO_X], 0x003C
	killChannel

LABEL_E44A:
	jne [HACK_VAR_67], 0x6F, LABEL_E45B
	jg [HERO_Y], 0x8C, SHARED_RET
	mov [0x22], 0x03E8
	ret

LABEL_E45B:
	jne [HACK_VAR_67], 0xED, SHARED_RET
	jg [HERO_Y], 0x5A, SHARED_RET
	mov [0x22], 0x03E8
	ret

LABEL_E46C:
	je [0x63], 0x03, SHARED_RET
	je [0x63], 0x64, SHARED_RET
	jne [HACK_VAR_67], 0x6F, LABEL_E4B2
	jg [HERO_Y], 0x85, SHARED_RET
	mov [0xF8], [HERO_X]
	add [0xF8], [0x2A]
	jl [0xF8], 0xFF, LABEL_E49B
	je [0x63], 0x01, SHARED_RET
	mov [0x22], 0x03E8
	ret

LABEL_E49B:
	mov [0xF8], [HERO_X]
	sub [0xF8], [0x2A]
	jg [0xF8], 0x4B, SHARED_RET
	je [0x63], 0x02, SHARED_RET
	mov [0x22], 0x03E9
	ret

LABEL_E4B2:
	jne [HACK_VAR_67], 0xED, SHARED_RET
	jg [HERO_Y], 0x55, SHARED_RET
	mov [0xF8], [HERO_X]
	add [0xF8], [0x2A]
	jl [0xF8], 0xD2, SHARED_RET
	je [0x63], 0x01, SHARED_RET
	mov [0x22], 0x03E8
	ret

LABEL_E4D5:
	add [0x22], [0x21]
	add [0x22], [0x21]
	jle [0x22], 0x06, LABEL_E4E5
	mov [0x22], 0x0006

LABEL_E4E5:
	jge [0x22], 0xFFFA, LABEL_E4F0
	mov [0x22], 0xFFFA

LABEL_E4F0:
	jle [0x22], 0x00, LABEL_E505
	sub [0x22], 0x0001
	jg [0x22], 0x00, SHARED_RET
	mov [0x22], 0x0000
	ret

LABEL_E505:
	add [0x22], 0x0001
	jl [0x22], 0x00, SHARED_RET
	mov [0x22], 0x0000
	ret

SETUP_CHAN_14_BY_VAR63:
	je [0x63], 0x64, LABEL_E69A
	jne [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_E55D
	jne [0x63], 0x05, LABEL_E532
	setup channel=0x14, address=LABEL_F0AA
	mov [0x63], 0x0064
	jmp LABEL_E69A

LABEL_E532:
	jne [0x63], 0x06, LABEL_E543
	setup channel=0x14, address=LABEL_F21E
	mov [0x63], 0x0064
	jmp LABEL_E69A

LABEL_E543:
	jne [0x63], 0x01, LABEL_E550
	setup channel=0x14, address=LABEL_EFE3
	jmp LABEL_E69A

LABEL_E550:
	jne [0x63], 0x02, LABEL_E55D
	setup channel=0x14, address=LABEL_F157
	jmp LABEL_E69A

LABEL_E55D:
	jge [HERO_ACTION_POS_MASK], 0x80, LABEL_E5F0
	jne [HERO_POS_LEFT_RIGHT], 0xFFFF, LABEL_E582
	je [0x63], 0x01, LABEL_E582
	setup channel=0x14, address=LABEL_EA2E
	je [0x63], 0x05, INLINE_SET_VAR63_TO_1
	setup channel=0x14, address=STEP_DRAW_CV352_LEFT4_RIGHT1
