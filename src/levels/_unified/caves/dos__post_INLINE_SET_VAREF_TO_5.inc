ANIM_CIN_444_LOOP_VAREF__DOS__POST_INLINE_SET_VAREF_TO_5:
	video type=1, offset=CINEMATIC_444, x=103, y=100
	break
	djnz [0xEF], ANIM_CIN_444_LOOP_VAREF__DOS__POST_INLINE_SET_VAREF_TO_5
	mov [0xEF], 0x0005

LABEL_1962:
	video type=1, offset=CINEMATIC_444, x=103, y=100
	video type=1, offset=CINEMATIC_445, x=105, y=174
	break
	djnz [0xEF], LABEL_1962
	jmp INLINE_SET_VAREF_TO_5
LABEL_1972:
	db 0x11

LABEL_1973:
	mov [0x01], 0x013B
	or [0x04], 0x4000
	mov [0xB7], 0x0001
	mov [0x50], 0x0FA0
	play id=0x005E, freq=0x14, vol=0x40, channel=0x01
	play id=0x005E, freq=0x1C, vol=0x40, channel=0x02
	video type=1, offset=CINEMATIC_447, x=[0x01], y=[0x02], zoom=0x40
	video type=1, offset=CINEMATIC_448, x=330, y=[0x02], zoom=0x40
	break
	sub [0x01], 0x000A
	video type=1, offset=CINEMATIC_447, x=[0x01], y=[0x02], zoom=0x40
	video type=1, offset=CINEMATIC_448, x=340, y=[0x02], zoom=0x40
	break
	sub [0x01], 0x000A
	video type=1, offset=CINEMATIC_449, x=[0x01], y=[0x02], zoom=0x40
	break
	sub [0x01], 0x000A
	video type=1, offset=CINEMATIC_450, x=[0x01], y=[0x02], zoom=0x40
	setup channel=0x02, address=INIT_VARS_EE_EF
	mov [0x0A], 0x0000
	break
	sub [0x01], 0x000A
	video type=1, offset=CINEMATIC_451, x=[0x01], y=[0x02], zoom=0x40
	call LABEL_45DE
	break
	sub [0x01], 0x000E
	video type=1, offset=CINEMATIC_452, x=[0x01], y=[0x02], zoom=0x40
	play id=0x0060, freq=0x14, vol=0x40, channel=0x01
	break
	sub [0x01], 0x0005
	video type=1, offset=CINEMATIC_452, x=[0x01], y=[0x02], zoom=0x40
	break
	sub [0x01], 0x0004
	video type=1, offset=CINEMATIC_452, x=[0x01], y=[0x02], zoom=0x40
	break
	sub [0x01], 0x0003
	video type=1, offset=CINEMATIC_452, x=[0x01], y=[0x02], zoom=0x40
	break
	sub [0x01], 0x0003
	video type=1, offset=CINEMATIC_452, x=[0x01], y=[0x02], zoom=0x40
	break
	sub [0x01], 0x0003
	video type=1, offset=CINEMATIC_452, x=[0x01], y=[0x02], zoom=0x40
	break
	sub [0x01], 0x0002
	video type=1, offset=CINEMATIC_452, x=[0x01], y=[0x02], zoom=0x40
	break
	sub [0x01], 0x0001
	video type=1, offset=CINEMATIC_452, x=[0x01], y=[0x02], zoom=0x40
	break
	sub [0x01], 0x0001
	video type=1, offset=CINEMATIC_452, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_452, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0001

LABEL_1A3B:
	break
	video type=1, offset=CINEMATIC_452, x=[0x01], y=[0x02], zoom=0x40
	jmp LABEL_1A3B
LABEL_1A44:
	db 0x11

LABEL_1A45:
	je [0xB6], 0x00, KILL_CHAN_AT_016E
	jne [HACK_VAR_67], [0xB6], KILL_CHAN_AT_016E
	jl [0x01], 0x0148, LABEL_1A65
	mov [0x01], 0x0148
	deleteChannels first=0x14, last=0x16
	setup channel=0x14, address=LABEL_1973
	killChannel

LABEL_1A65:
	break
	jmp LABEL_1A45
LABEL_1A69:
	db 0x11

LABEL_1A6A:
	break
	je [0xB5], 0x00, LABEL_1A7F
	jne [0x72], 0x6D, LABEL_1A7F
	mov [0x72], 0x006C
	mov [0xB5], 0x006C

LABEL_1A7F:
	jl [0x01], 0x78, LABEL_1A6A
	jg [0x01], 0xF0, LABEL_1A6A
	mov [0xF8], [0xB2]
	and [0xF8], 0x0100
	jne [0xF8], 0x00, KILL_CHAN_AT_016E
	or [0xB2], 0x0100
	mov [0xAA], 0xFFFF
	mov [0xAD], 0xFFFF
	call LABEL_465F
	setup channel=0x34, address=LABEL_73FD
	setup channel=0x33, address=LABEL_73C9
	break
	break
	break
	break
	break
	break
	call LABEL_4683

LABEL_1AB8:
	break
	je [0x7A], 0x6E, KILL_CHAN_AT_016E
	jl [0x01], 0xFA, LABEL_1AB8
	mov [0x78], 0x0000
	killChannel

LABEL_1ACA:
	jl [HACK_VAR_67], 0x45, LABEL_1AE1
	jg [HACK_VAR_67], 0x48, LABEL_1AE1
	jne [0x1D], 0x29, LABEL_1AE1
	or [0xB2], 0x0020
	ret

LABEL_1AE1:
	jl [HACK_VAR_67], 0x4A, LABEL_1B03
	jg [HACK_VAR_67], 0x50, LABEL_1B03
	jne [0x1D], 0x2A, LABEL_1AF8
	or [0xB2], 0x0001
	ret

LABEL_1AF8:
	jne [0x1D], 0x29, SHARED_RET
	mov [0xB3], 0x0000
	ret

LABEL_1B03:
	jl [HACK_VAR_67], 0x6A, SHARED_RET
	jg [HACK_VAR_67], 0x70, SHARED_RET
	jne [HACK_VAR_67], 0x70, LABEL_1B1A
	or [0xB2], 0x0002
	ret

LABEL_1B1A:
	jne [0x1D], 0x2A, LABEL_1B36
	je [0xB6], 0x00, LABEL_1B2B
	mov [0xB6], 0x0000
	ret

LABEL_1B2B:
	je [0xB4], 0x00, LABEL_1B36
	mov [0xB4], 0x0000
	ret

LABEL_1B36:
	jne [0x1D], 0x29, SHARED_RET
	je [0xB5], 0x00, SHARED_RET
	mov [0xB5], 0x0000
	ret

LABEL_1B47:
	break
	jne [HACK_VAR_67], 0x95, LABEL_1B47
	jl [0x73], 0x4000, LABEL_1B58
	call LABEL_46A7

LABEL_1B58:
	jl [0x7B], 0x4000, LABEL_1B47
	call LABEL_46CF
	jmp LABEL_1B47
LABEL_1B65:
	db 0x11

LABEL_1B66:
	mov [0xF8], [0xB2]
	and [0xF8], 0x0004
	je [HACK_VAR_67], 0x4C, LABEL_1B79
	jne [HACK_VAR_67], 0x6B, LABEL_1BA1

LABEL_1B79:
	jne [0xF8], 0x00, LABEL_1BA1
	jl [0x01], 0x96, LABEL_1BA1
	jge [0x73], 0x4000, LABEL_1BA1
	mov [0xF8], [0x72]
	sub [0xF8], 0x0001
	jne [HACK_VAR_67], [0xF8], LABEL_1BA1
	or [0xB2], 0x0004
	setup channel=0x00, address=LABEL_148F

LABEL_1BA1:
	call LABEL_5F0A
	je [0x21], 0x00, LABEL_1BBE
	jge [HACK_VAR_67], 0x91, LABEL_1BBE
	jl [HACK_VAR_67], 0x48, LABEL_1BBE
	mov [0x74], 0x0010
	or [0x74], 0x4000

LABEL_1BBE:
	break
	jmp LABEL_1B66
LABEL_1BC2:
	db 0x11
