LABEL_3652:
	db 0x11

PRISON_DRAW_CIN505_AT_X21_Y27_L29:
	mov [0x26], [0x21]
	mov [0x21], [0x22]
	mov [0x22], [0x26]
	call PRISON_DRAW_CIN505_AT_X21_Y27_L35
	mov [0x26], [0x21]
	mov [0x21], [0x22]
	mov [0x22], [0x26]
	ret


LABEL_3669:
	db 0x11

PRISON_DRAW_CIN505_AT_X21_Y27_L35:
	mov [0x26], [0x22]
	sub [0x26], [0x21]
	jl [0x26], 0x7E, LABEL_3697
	jge [0x12], 0x2000, LABEL_368A
	video offset=CINEMATIC_520, x=[0x21], y=[0x27]
	video offset=CINEMATIC_521, x=[0x22], y=[0x27]
	jmp PRISON_DRAW_CIN505_AT_X21_Y27_L0

LABEL_368A:
	video offset=CINEMATIC_518, x=[0x21], y=[0x27]
	video offset=CINEMATIC_519, x=[0x22], y=[0x27]
	jmp PRISON_DRAW_CIN505_AT_X21_Y27_L0

LABEL_3697:
	jl [0x26], 0x64, LABEL_36BE
	jge [0x12], 0x2000, LABEL_36B1
	video offset=CINEMATIC_514, x=[0x21], y=[0x27]
	video offset=CINEMATIC_515, x=[0x22], y=[0x27]
	jmp PRISON_DRAW_CIN505_AT_X21_Y27_L0

LABEL_36B1:
	video offset=CINEMATIC_516, x=[0x21], y=[0x27]
	video offset=CINEMATIC_517, x=[0x22], y=[0x27]
	jmp PRISON_DRAW_CIN505_AT_X21_Y27_L0

LABEL_36BE:
	jl [0x26], 0x3E, LABEL_36D1
	video offset=CINEMATIC_514, x=[0x21], y=[0x27]
	video offset=CINEMATIC_515, x=[0x22], y=[0x27]
	jmp PRISON_DRAW_CIN505_AT_X21_Y27_L0

LABEL_36D1:
	jl [0x26], 0x1E, LABEL_36E4
	video offset=CINEMATIC_512, x=[0x21], y=[0x27]
	video offset=CINEMATIC_513, x=[0x22], y=[0x27]
	jmp PRISON_DRAW_CIN505_AT_X21_Y27_L0

LABEL_36E4:
	jl [0x26], 0x0E, LABEL_36F7
	video offset=CINEMATIC_510, x=[0x21], y=[0x27]
	video offset=CINEMATIC_511, x=[0x22], y=[0x27]
	jmp PRISON_DRAW_CIN505_AT_X21_Y27_L0

LABEL_36F7:
	jl [0x26], 0x06, LABEL_370A
	video offset=CINEMATIC_508, x=[0x21], y=[0x27]
	video offset=CINEMATIC_509, x=[0x22], y=[0x27]
	jmp PRISON_DRAW_CIN505_AT_X21_Y27_L0

LABEL_370A:
	jl [0x26], 0x02, DRAW_CIN505_AT_X21_Y27
	video offset=CINEMATIC_506, x=[0x21], y=[0x27]
	video offset=CINEMATIC_507, x=[0x22], y=[0x27]
	jmp PRISON_DRAW_CIN505_AT_X21_Y27_L0
