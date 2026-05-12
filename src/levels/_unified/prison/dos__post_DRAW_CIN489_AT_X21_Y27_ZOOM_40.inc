PRISON_DRAW_CIN_499_L3:
	jne [0x13], 0x81, LABEL_3E6D
	play id=0x005A, freq=0x14, vol=0x40, channel=0x01
	video offset=CINEMATIC_472, x=[0x21], y=[0x27]
	ret


LABEL_3E6D:
	jne [0x13], 0x82, LABEL_3E79
	video offset=CINEMATIC_471, x=[0x21], y=[0x27]
	ret


LABEL_3E79:
	jne [0x13], 0x83, LABEL_3E85
	video offset=CINEMATIC_470, x=[0x21], y=[0x27]
	ret


LABEL_3E85:
	jne [0x13], 0x84, LABEL_3E91
	video offset=CINEMATIC_469, x=[0x21], y=[0x27]
	ret


LABEL_3E91:
	jne [0x13], 0x85, LABEL_3E9D
	video offset=CINEMATIC_468, x=[0x21], y=[0x27]
	ret


LABEL_3E9D:
	jne [0x13], 0x86, LABEL_3EA9
	video offset=CINEMATIC_467, x=[0x21], y=[0x27]
	ret


LABEL_3EA9:
	jne [0x13], 0x87, LABEL_3EB5
	video offset=CINEMATIC_466, x=[0x21], y=[0x27]
	ret


LABEL_3EB5:
	jne [0x13], 0x88, LABEL_3EC1
	video offset=CINEMATIC_465, x=[0x21], y=[0x27]
	ret


LABEL_3EC1:
	jne [0x13], 0x89, PRISON_DRAW_CIN_499_L0
	video offset=CINEMATIC_464, x=[0x21], y=[0x27]
	ret


PRISON_DRAW_CIN_499_L0:
	ret


LABEL_3ECE:
	db 0x11

PRISON_DRAW_CIN_499_L1:
	mov [0x22], [0x21]
	sub [0x22], 0x0064
	mov [0x09], [0x22]
	call PRISON_DEDUP_PRISON_5B_032_L0
	call LABEL_401D
	mov [0x2C], 0x0001
	jne [0x1D], 0x00, LABEL_3F3F
	video offset=CINEMATIC_463, x=[0x22], y=[0x27]
	ret


PRISON_DRAW_CIN_499_L2:
	mov [0x22], [0x21]
	sub [0x22], 0x0140
	mov [0x09], [0x22]
	call PRISON_DEDUP_PRISON_5B_032_L0
	call LABEL_401D
	mov [0x2C], 0x0001
	jmp LABEL_3F3F
LABEL_3F06:
	db 0x11

PRISON_DRAW_CIN_483_L1:
	mov [0x22], [0x21]
	add [0x22], 0x0064
	mov [0x09], [0x22]
	call PRISON_DEDUP_PRISON_5B_032_L0
	call LABEL_401D
	mov [0x2C], 0x0000
	jne [0x1D], 0x00, LABEL_3F3F
	video offset=CINEMATIC_463, x=[0x22], y=[0x27]
	ret


PRISON_DRAW_CIN_483_L2:
	mov [0x22], [0x21]
	add [0x22], 0x0140
	mov [0x09], [0x22]
	call PRISON_DEDUP_PRISON_5B_032_L0
	call LABEL_401D
	mov [0x2C], 0x0000
	jmp LABEL_3F3F
LABEL_3F3E:
	db 0x11

LABEL_3F3F:
	mov [0x13], 0x0080
	mov [0x21], [0x22]
	jl [0x1D], 0x0A, CALL_LABEL_407D_AND_RET
	jl [0x1D], 0x14, LABEL_3F9D
	jl [0x1D], 0x1E, LABEL_3F73
	jge [0x1D], 0x28, LABEL_3F62

CALL_LABEL_407D_AND_RET:
	call PRISON_INLINE_ADD_VAR2C_BY_1_L5
	ret


LABEL_3F62:
	call PRISON_COPY_VAR22_TO_VAR07_L11
	mov [0x13], 0xFFFE
	je [0x2C], 0x01, PRISON_DRAW_CIN_499_L2
	jmp PRISON_DRAW_CIN_483_L2
LABEL_3F72:
	db 0x05

LABEL_3F73:
	call PRISON_INLINE_ADD_VAR2C_BY_1_L5
	call PRISON_COPY_VAR40_TO_VAR27_L1
	mov [0x11], 0xFFFF
	call PRISON_COPY_VARAD_TO_VAR11_L1
	ret


LABEL_3F81:
	db 0x11

LABEL_3F82:
	and [0xF8], 0x0080
	jne [0xF8], 0x00, MASK_VAR11_NOSIGN_INCR_VAR21_BY_14
	mov [0xF8], [0x11]
	and [0xF8], 0x0100
	jne [0xF8], 0x00, LABEL_3FCC
	jmp LABEL_3FBE
LABEL_3F9C:
	db 0x11

LABEL_3F9D:
	call LABEL_40E6
	call PRISON_INLINE_ADD_VAR2C_BY_1_L5
	mov [0x21], [0x10]
	mov [0x13], 0x006E
	mov [0xF8], [0x11]
	je [0x2C], 0x01, LABEL_3F82
	and [0xF8], 0x03FF
	jl [0xF8], 0x0200, LABEL_3FC5

LABEL_3FBE:
	and [0x11], 0xFDFF
	jmp LABEL_3FDF

LABEL_3FC5:
	jl [0xF8], 0x0100, MASK_VAR11_NOSIGN_INCR_VAR21_BY_14

LABEL_3FCC:
	and [0x11], 0xFEFF
	add [0x21], 0x000A
	jmp LABEL_3FDF
