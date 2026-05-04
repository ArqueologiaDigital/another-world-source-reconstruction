LABEL_E2DD:
	deleteChannels first=0x15, last=0x16
	break
	jne [HACK_VAR_67], 0x6F, LABEL_E2F6
	call LABEL_149E
	call LABEL_14BB
	mov [0x01], 0x00E6
	mov [0x02], 0x007D

LABEL_E2F6:
	jne [HACK_VAR_67], 0xED, LABEL_E304
	mov [0x01], 0x00BE
	mov [0x02], 0x0050

LABEL_E304:
	add [0x01], 0x000A
	video type=1, offset=CINEMATIC_472, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_515, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_516, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_517, x=[0x01], y=[0x02], zoom=0x40
	play id=0x006C, freq=0x14, vol=0x40, channel=0x01
	break
	video type=1, offset=CINEMATIC_518, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_519, x=[0x01], y=[0x02], zoom=0x40
	mov [0x63], 0x0002
	mov [0x05], 0x0000
	mov [PAUSE_SLICES], 0x0004
	mov [0x32], 0x0000
	setup channel=0x16, address=SETUP_CHAN_14_BY_VAR63
	setup channel=0x14, address=LABEL_EB39
	setup channel=0x3E, address=LABEL_CBE2
	mov [0x01], 0x00D9
	jne [HACK_VAR_67], 0x6F, KILL_CHAN_AT_E35F
	setup channel=0x3E, address=LABEL_CBA1
	mov [0x01], 0x010E

KILL_CHAN_AT_E35F:
	killChannel

LABEL_E360:
	deleteChannels first=0x15, last=0x16
	call LABEL_149E
	call LABEL_14BB
	break
	mov [0x01], 0x005A
	mov [0x02], 0x007D
	sub [0x01], 0x000A
	video type=1, offset=CINEMATIC_490, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_520, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_521, x=[0x01], y=[0x02], zoom=0x40
	break
	play id=0x006C, freq=0x14, vol=0x40, channel=0x01
	video type=1, offset=CINEMATIC_522, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_523, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_524, x=[0x01], y=[0x02], zoom=0x40
	mov [0x05], 0x0000
	mov [0x63], 0x0001
	mov [PAUSE_SLICES], 0x0004
	mov [0x32], 0x0000
	setup channel=0x16, address=SETUP_CHAN_14_BY_VAR63
	setup channel=0x14, address=LABEL_E9A5
	setup channel=0x3E, address=LABEL_CBA1
	mov [0x01], 0x003C
	killChannel

LABEL_E3C1:
	jne [HACK_VAR_67], 0x6F, LABEL_E3D2
	jg [0x02], 0x8C, SHARED_RET
	mov [0x22], 0x03E8
	ret

LABEL_E3D2:
	jne [HACK_VAR_67], 0xED, SHARED_RET
	jg [0x02], 0x5A, SHARED_RET
	mov [0x22], 0x03E8
	ret

LABEL_E3E3:
	je [0x63], 0x03, SHARED_RET
	je [0x63], 0x64, SHARED_RET
	jne [HACK_VAR_67], 0x6F, LABEL_E429
	jg [0x02], 0x85, SHARED_RET
	mov [0xF8], [0x01]
	add [0xF8], [0x2A]
	jl [0xF8], 0xFF, LABEL_E412
	je [0x63], 0x01, SHARED_RET
	mov [0x22], 0x03E8
	ret

LABEL_E412:
	mov [0xF8], [0x01]
	sub [0xF8], [0x2A]
	jg [0xF8], 0x4B, SHARED_RET
	je [0x63], 0x02, SHARED_RET
	mov [0x22], 0x03E9
	ret

LABEL_E429:
	jne [HACK_VAR_67], 0xED, SHARED_RET
	jg [0x02], 0x55, SHARED_RET
	mov [0xF8], [0x01]
	add [0xF8], [0x2A]
	jl [0xF8], 0xD2, SHARED_RET
	je [0x63], 0x01, SHARED_RET
	mov [0x22], 0x03E8
	ret

LABEL_E44C:
	add [0x22], [0x21]
	add [0x22], [0x21]
	jle [0x22], 0x06, LABEL_E45C
	mov [0x22], 0x0006

LABEL_E45C:
	jge [0x22], 0xFFFA, LABEL_E467
	mov [0x22], 0xFFFA

LABEL_E467:
	jle [0x22], 0x00, LABEL_E47C
	sub [0x22], 0x0001
	jg [0x22], 0x00, SHARED_RET
	mov [0x22], 0x0000
	ret

LABEL_E47C:
	add [0x22], 0x0001
	jl [0x22], 0x00, SHARED_RET
	mov [0x22], 0x0000
	ret

SETUP_CHAN_14_BY_VAR63:
	je [0x63], 0x64, LABEL_E611
	jne [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_E4D4
	jne [0x63], 0x05, LABEL_E4A9
	setup channel=0x14, address=LABEL_F021
	mov [0x63], 0x0064
	jmp LABEL_E611

LABEL_E4A9:
	jne [0x63], 0x06, LABEL_E4BA
	setup channel=0x14, address=LABEL_F195
	mov [0x63], 0x0064
	jmp LABEL_E611

LABEL_E4BA:
	jne [0x63], 0x01, LABEL_E4C7
	setup channel=0x14, address=LABEL_EF5A
	jmp LABEL_E611

LABEL_E4C7:
	jne [0x63], 0x02, LABEL_E4D4
	setup channel=0x14, address=LABEL_F0CE
	jmp LABEL_E611

LABEL_E4D4:
	jge [HERO_ACTION_POS_MASK], 0x80, LABEL_E567
	jne [HERO_POS_LEFT_RIGHT], 0xFFFF, LABEL_E4F9
	je [0x63], 0x01, LABEL_E4F9
	setup channel=0x14, address=LABEL_E9A5
	je [0x63], 0x05, INLINE_SET_VAR63_TO_1
	setup channel=0x14, address=STEP_DRAW_CV352_LEFT4_RIGHT1
