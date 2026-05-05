LABEL_186F:
	video offset=CINEMATIC_444, x=[0xee], y=98, zoom=0x40
	sub [0xEE], 0x000A
	break
	djnz [0xEF], LABEL_186F
	mov [0xEF], 0x0004

LABEL_1881:
	video offset=CINEMATIC_444, x=[0xee], y=99, zoom=0x40
	sub [0xEE], 0x0008
	break
	djnz [0xEF], LABEL_1881
	mov [0xEF], 0x0004

LABEL_1893:
	video offset=CINEMATIC_444, x=[0xee], y=100, zoom=0x40
	sub [0xEE], 0x0006
	break
	djnz [0xEF], LABEL_1893
	mov [0xEF], 0x0004

LABEL_18A5:
	video offset=CINEMATIC_444, x=[0xee], y=100, zoom=0x40
	sub [0xEE], 0x0004
	break
	djnz [0xEF], LABEL_18A5
	mov [0xEF], 0x0004

LABEL_18B7:
	video offset=CINEMATIC_444, x=[0xee], y=100, zoom=0x40
	sub [0xEE], 0x0003
	break
	djnz [0xEF], LABEL_18B7
	mov [0xEF], 0x0004

LABEL_18C9:
	video offset=CINEMATIC_444, x=[0xee], y=100, zoom=0x40
	sub [0xEE], 0x0002
	break
	djnz [0xEF], LABEL_18C9
	mov [0xEF], 0x0004

LABEL_18DB:
	video offset=CINEMATIC_444, x=[0xee], y=100, zoom=0x40
	sub [0xEE], 0x0001
	break
	djnz [0xEF], LABEL_18DB
	mov [0xEF], 0x0002

LABEL_18ED:
	video offset=CINEMATIC_444, x=[0xee], y=100, zoom=0x40
	sub [0xEE], 0x0001
	break
	video offset=CINEMATIC_444, x=[0xee], y=100, zoom=0x40
	break
	djnz [0xEF], LABEL_18ED
	jmp INLINE_SET_VAREF_TO_5
