ANIM_CIN_444_LOOP_VAREF:
	video offset=CINEMATIC_444, x=103, y=100
	break
	djnz [0xEF], ANIM_CIN_444_LOOP_VAREF
	mov [0xEF], 0x0005

LABEL_1915:
	video offset=CINEMATIC_444, x=103, y=100
	video offset=CINEMATIC_445, x=105, y=174
	break
	djnz [0xEF], LABEL_1915
	jmp INLINE_SET_VAREF_TO_5
LABEL_1925:
	db 0x11

LABEL_1926:
	mov [0x01], 0x013B
	or [0x04], 0x4000
	mov [0xB7], 0x0001
	mov [0x50], 0x0FA0
	play id=0x005E, freq=0x14, vol=0x40, channel=0x01
	play id=0x005E, freq=0x1C, vol=0x40, channel=0x02
	song id=0x0BCC, delay=0x0000, pos=0x00
	video offset=CINEMATIC_448, x=[0x01], y=[0x02], zoom=0x40
	video offset=CINEMATIC_449, x=330, y=[0x02], zoom=0x40
	break
	sub [0x01], 0x000A
	video offset=CINEMATIC_448, x=[0x01], y=[0x02], zoom=0x40
	video offset=CINEMATIC_449, x=340, y=[0x02], zoom=0x40
	break
	sub [0x01], 0x000A
	video offset=CINEMATIC_450, x=[0x01], y=[0x02], zoom=0x40
	break
	sub [0x01], 0x000A
	video offset=CINEMATIC_451, x=[0x01], y=[0x02], zoom=0x40
	je [0x0A], 0x00, LABEL_1983
	setup channel=0x02, address=INIT_VARS_EE_EF
	mov [0x0A], 0x0000

LABEL_1983:
	break
	sub [0x01], 0x000A
	video offset=CINEMATIC_452, x=[0x01], y=[0x02], zoom=0x40
	call LABEL_45DE
	break
	sub [0x01], 0x000E
	video offset=CINEMATIC_453, x=[0x01], y=[0x02], zoom=0x40
	play id=0x0060, freq=0x14, vol=0x40, channel=0x01
	break
	sub [0x01], 0x0005
	video offset=CINEMATIC_453, x=[0x01], y=[0x02], zoom=0x40
	break
	sub [0x01], 0x0004
	video offset=CINEMATIC_453, x=[0x01], y=[0x02], zoom=0x40
	break
	sub [0x01], 0x0003
	video offset=CINEMATIC_453, x=[0x01], y=[0x02], zoom=0x40
	break
	sub [0x01], 0x0003
	video offset=CINEMATIC_453, x=[0x01], y=[0x02], zoom=0x40
	break
	sub [0x01], 0x0003
	video offset=CINEMATIC_453, x=[0x01], y=[0x02], zoom=0x40
	break
	sub [0x01], 0x0002
	video offset=CINEMATIC_453, x=[0x01], y=[0x02], zoom=0x40
	break
	sub [0x01], 0x0001
	video offset=CINEMATIC_453, x=[0x01], y=[0x02], zoom=0x40
	break
	sub [0x01], 0x0001
	video offset=CINEMATIC_453, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_453, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0001

LABEL_19FA:
	break
	video offset=CINEMATIC_453, x=[0x01], y=[0x02], zoom=0x40
	jmp LABEL_19FA
LABEL_1A03:
	db 0x11

LABEL_1A04:
	je [0xB6], 0x00, KILL_CHAN_AT_01FB
	jne [HACK_VAR_67], [0xB6], KILL_CHAN_AT_01FB
	jl [0x01], 0x0148, LABEL_1A24
	mov [0x01], 0x0148
	deleteChannels first=0x14, last=0x16
	setup channel=0x14, address=LABEL_1926
	killChannel

LABEL_1A24:
	break
	jmp LABEL_1A04
LABEL_1A28:
	db 0x11

LABEL_1A29:
	break
	je [0xB5], 0x00, LABEL_1A3E
	jne [0x72], 0x6D, LABEL_1A3E
	mov [0x72], 0x006C
	mov [0xB5], 0x006C

LABEL_1A3E:
	jl [0x01], 0x78, LABEL_1A29
	jg [0x01], 0xF0, LABEL_1A29
	mov [0xF8], [0xB2]
	and [0xF8], 0x0100
	jne [0xF8], 0x00, KILL_CHAN_AT_01FB
	or [0xB2], 0x0100
	mov [0xAA], 0xFFFF
	mov [0xAD], 0xFFFF
	call LABEL_465F
	setup channel=0x34, address=LABEL_732D
	setup channel=0x33, address=LABEL_72F6
	break
	break
	break
	break
	break
	break
	call LABEL_4683

LABEL_1A77:
	break
	je [0x7A], 0x6E, KILL_CHAN_AT_01FB
	jl [0x01], 0xFA, LABEL_1A77
	mov [0x78], 0x0000
	killChannel

LABEL_1A89:
	jl [HACK_VAR_67], 0x45, LABEL_1AA0
	jg [HACK_VAR_67], 0x48, LABEL_1AA0
	jne [0x1D], 0x29, LABEL_1AA0
	or [0xB2], 0x0020
	ret

LABEL_1AA0:
	jl [HACK_VAR_67], 0x4A, LABEL_1AC2
	jg [HACK_VAR_67], 0x50, LABEL_1AC2
	jne [0x1D], 0x2A, LABEL_1AB7
	or [0xB2], 0x0001
	ret

LABEL_1AB7:
	jne [0x1D], 0x29, SHARED_RET
	mov [0xB3], 0x0000
	ret

LABEL_1AC2:
	jl [HACK_VAR_67], 0x6A, SHARED_RET
	jg [HACK_VAR_67], 0x70, SHARED_RET
	jne [HACK_VAR_67], 0x70, LABEL_1AD9
	or [0xB2], 0x0002
	ret

LABEL_1AD9:
	jne [0x1D], 0x2A, LABEL_1AF5
	je [0xB6], 0x00, LABEL_1AEA
	mov [0xB6], 0x0000
	ret

LABEL_1AEA:
	je [0xB4], 0x00, LABEL_1AF5
	mov [0xB4], 0x0000
	ret

LABEL_1AF5:
	jne [0x1D], 0x29, SHARED_RET
	je [0xB5], 0x00, SHARED_RET
	mov [0xB5], 0x0000
	ret

LABEL_1B06:
	break
	jne [HACK_VAR_67], 0x95, LABEL_1B06
	jl [0x73], 0x4000, LABEL_1B17
	call LABEL_46A7

LABEL_1B17:
	jl [0x7B], 0x4000, LABEL_1B06
	call LABEL_46CF
	jmp LABEL_1B06
LABEL_1B24:
	db 0x11

LABEL_1B25:
	mov [0xF8], [0xB2]
	and [0xF8], 0x0004
	je [HACK_VAR_67], 0x4C, LABEL_1B38
	jne [HACK_VAR_67], 0x6B, LABEL_1B60

LABEL_1B38:
	jne [0xF8], 0x00, LABEL_1B60
	jl [0x01], 0x96, LABEL_1B60
	jge [0x73], 0x4000, LABEL_1B60
	mov [0xF8], [0x72]
	sub [0xF8], 0x0001
	jne [HACK_VAR_67], [0xF8], LABEL_1B60
	or [0xB2], 0x0004
	setup channel=0x00, address=LABEL_142A

LABEL_1B60:
	call LABEL_5E1F
	je [0x21], 0x00, LABEL_1B7D
	jge [HACK_VAR_67], 0x91, LABEL_1B7D
	jl [HACK_VAR_67], 0x48, LABEL_1B7D
	mov [0x74], 0x0010
	or [0x74], 0x4000

LABEL_1B7D:
	break
	jmp LABEL_1B25
LABEL_1B81:
	db 0x11
