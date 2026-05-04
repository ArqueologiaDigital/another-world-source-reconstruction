LABEL_3C9C:
	jne [0x13], 0x81, LABEL_3CAE
	play id=0x005A, freq=0x14, vol=0x40, channel=0x01
	video type=1, offset=CINEMATIC_472, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_3CAE:
	jne [0x13], 0x82, LABEL_3CBA
	video type=1, offset=CINEMATIC_471, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_3CBA:
	jne [0x13], 0x83, LABEL_3CC6
	video type=1, offset=CINEMATIC_470, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_3CC6:
	jne [0x13], 0x84, LABEL_3CD2
	video type=1, offset=CINEMATIC_469, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_3CD2:
	jne [0x13], 0x85, LABEL_3CDE
	video type=1, offset=CINEMATIC_468, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_3CDE:
	jne [0x13], 0x86, LABEL_3CEA
	video type=1, offset=CINEMATIC_467, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_3CEA:
	jne [0x13], 0x87, LABEL_3CF6
	video type=1, offset=CINEMATIC_466, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_3CF6:
	jne [0x13], 0x88, LABEL_3D02
	video type=1, offset=CINEMATIC_465, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_3D02:
	jne [0x13], 0x89, LABEL_3D0E
	video type=1, offset=CINEMATIC_464, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_3D0E:
	ret
LABEL_3D0F:
	db 0x11

LABEL_3D10:
	jge [0x13], 0x64, LABEL_3D5C
	jle [0x13], 0x03, LABEL_3D3E
	jle [0x13], 0x05, LABEL_3D2C
	video type=1, offset=CINEMATIC_504, x=[0x21], y=[0x27], zoom=0x40
	mov [0x13], 0xFFFE
	ret

LABEL_3D2C:
	jle [0x13], 0x04, DRAW_CIN_502
	video type=1, offset=CINEMATIC_503, x=[0x21], y=[0x27], zoom=0x40
	ret
