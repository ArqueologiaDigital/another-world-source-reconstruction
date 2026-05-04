LABEL_3CFE:
	jne [0x13], 0x81, LABEL_3D10
	play id=0x005A, freq=0x14, vol=0x40, channel=0x01
	video type=1, offset=CINEMATIC_472, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_3D10:
	jne [0x13], 0x82, LABEL_3D1C
	video type=1, offset=CINEMATIC_471, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_3D1C:
	jne [0x13], 0x83, LABEL_3D28
	video type=1, offset=CINEMATIC_470, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_3D28:
	jne [0x13], 0x84, LABEL_3D34
	video type=1, offset=CINEMATIC_469, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_3D34:
	jne [0x13], 0x85, LABEL_3D40
	video type=1, offset=CINEMATIC_468, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_3D40:
	jne [0x13], 0x86, LABEL_3D4C
	video type=1, offset=CINEMATIC_467, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_3D4C:
	jne [0x13], 0x87, LABEL_3D58
	video type=1, offset=CINEMATIC_466, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_3D58:
	jne [0x13], 0x88, LABEL_3D64
	video type=1, offset=CINEMATIC_465, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_3D64:
	jne [0x13], 0x89, LABEL_3D70
	video type=1, offset=CINEMATIC_464, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_3D70:
	ret
LABEL_3D71:
	db 0x11

LABEL_3D72:
	jge [0x13], 0x64, LABEL_3DBE
	jle [0x13], 0x03, LABEL_3DA0
	jle [0x13], 0x05, LABEL_3D8E
	video type=1, offset=CINEMATIC_504, x=[0x21], y=[0x27], zoom=0x40
	mov [0x13], 0xFFFE
	ret

LABEL_3D8E:
	jle [0x13], 0x04, DRAW_CIN_502
	video type=1, offset=CINEMATIC_503, x=[0x21], y=[0x27], zoom=0x40
	ret
