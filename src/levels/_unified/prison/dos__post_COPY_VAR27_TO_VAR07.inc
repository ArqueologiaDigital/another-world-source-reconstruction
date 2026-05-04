LABEL_36B4:
	db 0x11

LABEL_36B5:
	mov [0x26], [0x21]
	mov [0x21], [0x22]
	mov [0x22], [0x26]
	call LABEL_36CC
	mov [0x26], [0x21]
	mov [0x21], [0x22]
	mov [0x22], [0x26]
	ret
LABEL_36CB:
	db 0x11

LABEL_36CC:
	mov [0x26], [0x22]
	sub [0x26], [0x21]
	jl [0x26], 0x7E, LABEL_36F9
	jge [0x12], 0x2000, LABEL_36EC
	video type=1, offset=CINEMATIC_520, x=[0x21], y=[0x27], zoom=0x40
	video type=1, offset=CINEMATIC_521, x=[0x22], y=[0x27], zoom=0x40
	jmp LABEL_3784

LABEL_36EC:
	video type=1, offset=CINEMATIC_518, x=[0x21], y=[0x27], zoom=0x40
	video type=1, offset=CINEMATIC_519, x=[0x22], y=[0x27], zoom=0x40
	jmp LABEL_3784

LABEL_36F9:
	jl [0x26], 0x64, LABEL_3720
	jge [0x12], 0x2000, LABEL_3713
	video type=1, offset=CINEMATIC_514, x=[0x21], y=[0x27], zoom=0x40
	video type=1, offset=CINEMATIC_515, x=[0x22], y=[0x27], zoom=0x40
	jmp LABEL_3784

LABEL_3713:
	video type=1, offset=CINEMATIC_516, x=[0x21], y=[0x27], zoom=0x40
	video type=1, offset=CINEMATIC_517, x=[0x22], y=[0x27], zoom=0x40
	jmp LABEL_3784

LABEL_3720:
	jl [0x26], 0x3E, LABEL_3733
	video type=1, offset=CINEMATIC_514, x=[0x21], y=[0x27], zoom=0x40
	video type=1, offset=CINEMATIC_515, x=[0x22], y=[0x27], zoom=0x40
	jmp LABEL_3784

LABEL_3733:
	jl [0x26], 0x1E, LABEL_3746
	video type=1, offset=CINEMATIC_512, x=[0x21], y=[0x27], zoom=0x40
	video type=1, offset=CINEMATIC_513, x=[0x22], y=[0x27], zoom=0x40
	jmp LABEL_3784

LABEL_3746:
	jl [0x26], 0x0E, LABEL_3759
	video type=1, offset=CINEMATIC_510, x=[0x21], y=[0x27], zoom=0x40
	video type=1, offset=CINEMATIC_511, x=[0x22], y=[0x27], zoom=0x40
	jmp LABEL_3784

LABEL_3759:
	jl [0x26], 0x06, LABEL_376C
	video type=1, offset=CINEMATIC_508, x=[0x21], y=[0x27], zoom=0x40
	video type=1, offset=CINEMATIC_509, x=[0x22], y=[0x27], zoom=0x40
	jmp LABEL_3784

LABEL_376C:
	jl [0x26], 0x02, DRAW_CIN505_AT_X21_Y27
	video type=1, offset=CINEMATIC_506, x=[0x21], y=[0x27], zoom=0x40
	video type=1, offset=CINEMATIC_507, x=[0x22], y=[0x27], zoom=0x40
	jmp LABEL_3784
