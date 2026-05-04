ANIM_CIN_423_LOOP_VAREF:
	video type=1, offset=CINEMATIC_423, x=103, y=100
	break
	djnz [0xEF], ANIM_CIN_423_LOOP_VAREF
	mov [0xEF], 0x0005

LABEL_17A2:
	video type=1, offset=CINEMATIC_423, x=103, y=100
	video type=1, offset=CINEMATIC_424, x=105, y=174
	break
	djnz [0xEF], LABEL_17A2
	jmp INLINE_SET_VAREF_TO_5
LABEL_17B2:
	db 0x11

LABEL_17B3:
	mov [0x01], 0x013B
	or [0x04], 0x4000
	mov [0xB7], 0x0001
	play id=0x005E, freq=0x14, vol=0x40, channel=0x01
	play id=0x005E, freq=0x1C, vol=0x40, channel=0x02
	video type=1, offset=CINEMATIC_426, x=[0x01], y=[0x02], zoom=0x40
	video type=1, offset=CINEMATIC_427, x=330, y=[0x02], zoom=0x40
	break
	sub [0x01], 0x000A
	video type=1, offset=CINEMATIC_426, x=[0x01], y=[0x02], zoom=0x40
	video type=1, offset=CINEMATIC_427, x=340, y=[0x02], zoom=0x40
	break
	sub [0x01], 0x000A
	video type=1, offset=CINEMATIC_428, x=[0x01], y=[0x02], zoom=0x40
	break
	sub [0x01], 0x000A
	video type=1, offset=CINEMATIC_429, x=[0x01], y=[0x02], zoom=0x40
	setup channel=0x02, address=INIT_VARS_EE_EF
	mov [0x0A], 0x0000
	break
	sub [0x01], 0x000A
	video type=1, offset=CINEMATIC_430, x=[0x01], y=[0x02], zoom=0x40
	call LABEL_42CD
	break
	sub [0x01], 0x000E
	video type=1, offset=CINEMATIC_431, x=[0x01], y=[0x02], zoom=0x40
	play id=0x0060, freq=0x14, vol=0x40, channel=0x01
	break
	sub [0x01], 0x0005
	video type=1, offset=CINEMATIC_431, x=[0x01], y=[0x02], zoom=0x40
	break
	sub [0x01], 0x0004
	video type=1, offset=CINEMATIC_431, x=[0x01], y=[0x02], zoom=0x40
	break
	sub [0x01], 0x0003
	video type=1, offset=CINEMATIC_431, x=[0x01], y=[0x02], zoom=0x40
	break
	sub [0x01], 0x0003
	video type=1, offset=CINEMATIC_431, x=[0x01], y=[0x02], zoom=0x40
	break
	sub [0x01], 0x0003
	video type=1, offset=CINEMATIC_431, x=[0x01], y=[0x02], zoom=0x40
	break
	sub [0x01], 0x0002
	video type=1, offset=CINEMATIC_431, x=[0x01], y=[0x02], zoom=0x40
	break
	sub [0x01], 0x0001
	video type=1, offset=CINEMATIC_431, x=[0x01], y=[0x02], zoom=0x40
	break
	sub [0x01], 0x0001
	video type=1, offset=CINEMATIC_431, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_431, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0001

LABEL_1877:
	break
	video type=1, offset=CINEMATIC_431, x=[0x01], y=[0x02], zoom=0x40
	jmp LABEL_1877
LABEL_1880:
	db 0x11

LABEL_1881:
	je [0xB6], 0x00, KILL_CHAN_AT_0161
	jne [HACK_VAR_67], [0xB6], KILL_CHAN_AT_0161
	jl [0x01], 0x0148, LABEL_18A1
	mov [0x01], 0x0148
	deleteChannels first=0x14, last=0x16
	setup channel=0x14, address=LABEL_17B3
	killChannel

LABEL_18A1:
	break
	jmp LABEL_1881
LABEL_18A5:
	db 0x11

LABEL_18A6:
	break
	je [0xB5], 0x00, LABEL_18BB
	jne [0x72], 0x6D, LABEL_18BB
	mov [0x72], 0x006C
	mov [0xB5], 0x006C

LABEL_18BB:
	jl [0x01], 0x78, LABEL_18A6
	jg [0x01], 0xF0, LABEL_18A6
	mov [0xF8], [0xB2]
	and [0xF8], 0x0100
	jne [0xF8], 0x00, KILL_CHAN_AT_0161
	or [0xB2], 0x0100
	mov [0xAA], 0xFFFF
	mov [0xAD], 0xFFFF
	call LABEL_434E
	setup channel=0x34, address=LABEL_70E3
	setup channel=0x33, address=LABEL_70AF
	break
	break
	break
	break
	break
	break
	call LABEL_4372

LABEL_18F4:
	break
	je [0x7A], 0x6E, KILL_CHAN_AT_0161
	jl [0x01], 0xFA, LABEL_18F4
	mov [0x78], 0x0000
	killChannel

LABEL_1906:
	jl [HACK_VAR_67], 0x45, LABEL_191D
	jg [HACK_VAR_67], 0x48, LABEL_191D
	jne [0x1D], 0x29, LABEL_191D
	or [0xB2], 0x0020
	ret

LABEL_191D:
	jl [HACK_VAR_67], 0x4A, LABEL_193F
	jg [HACK_VAR_67], 0x50, LABEL_193F
	jne [0x1D], 0x2A, LABEL_1934
	or [0xB2], 0x0001
	ret

LABEL_1934:
	jne [0x1D], 0x29, SHARED_RET
	mov [0xB3], 0x0000
	ret

LABEL_193F:
	jl [HACK_VAR_67], 0x6A, SHARED_RET
	jg [HACK_VAR_67], 0x70, SHARED_RET
	jne [HACK_VAR_67], 0x70, LABEL_1956
	or [0xB2], 0x0002
	ret

LABEL_1956:
	jne [0x1D], 0x2A, LABEL_1972
	je [0xB6], 0x00, LABEL_1967
	mov [0xB6], 0x0000
	ret

LABEL_1967:
	je [0xB4], 0x00, LABEL_1972
	mov [0xB4], 0x0000
	ret

LABEL_1972:
	jne [0x1D], 0x29, SHARED_RET
	je [0xB5], 0x00, SHARED_RET
	mov [0xB5], 0x0000
	ret

LABEL_1983:
	break
	jne [HACK_VAR_67], 0x95, LABEL_1983
	jl [0x73], 0x4000, LABEL_1994
	call LABEL_4396

LABEL_1994:
	jl [0x7B], 0x4000, LABEL_1983
	call LABEL_43BE
	jmp LABEL_1983
LABEL_19A1:
	db 0x11

LABEL_19A2:
	mov [0xF8], [0xB2]
	and [0xF8], 0x0004
	je [HACK_VAR_67], 0x4C, LABEL_19B5
	jne [HACK_VAR_67], 0x6B, LABEL_19DD

LABEL_19B5:
	jne [0xF8], 0x00, LABEL_19DD
	jl [0x01], 0x96, LABEL_19DD
	jge [0x73], 0x4000, LABEL_19DD
	mov [0xF8], [0x72]
	sub [0xF8], 0x0001
	jne [HACK_VAR_67], [0xF8], LABEL_19DD
	or [0xB2], 0x0004
	setup channel=0x00, address=LABEL_12CF

LABEL_19DD:
	call LABEL_5BE7
	je [0x21], 0x00, LABEL_19F4
	jge [HACK_VAR_67], 0x91, LABEL_19F4
	mov [0x74], 0x0010
	or [0x74], 0x4000

LABEL_19F4:
	break
	jmp LABEL_19A2
LABEL_19F8:
	db 0x11
