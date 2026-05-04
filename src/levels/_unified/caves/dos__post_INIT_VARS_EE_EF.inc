LABEL_18BC:
	video type=1, offset=CINEMATIC_444, x=[0xee], y=98, zoom=0x40
	sub [0xEE], 0x000A
	break
	djnz [0xEF], LABEL_18BC
	mov [0xEF], 0x0004

LABEL_18CE:
	video type=1, offset=CINEMATIC_444, x=[0xee], y=99, zoom=0x40
	sub [0xEE], 0x0008
	break
	djnz [0xEF], LABEL_18CE
	mov [0xEF], 0x0004

LABEL_18E0:
	video type=1, offset=CINEMATIC_444, x=[0xee], y=100, zoom=0x40
	sub [0xEE], 0x0006
	break
	djnz [0xEF], LABEL_18E0
	mov [0xEF], 0x0004

LABEL_18F2:
	video type=1, offset=CINEMATIC_444, x=[0xee], y=100, zoom=0x40
	sub [0xEE], 0x0004
	break
	djnz [0xEF], LABEL_18F2
	mov [0xEF], 0x0004

LABEL_1904:
	video type=1, offset=CINEMATIC_444, x=[0xee], y=100, zoom=0x40
	sub [0xEE], 0x0003
	break
	djnz [0xEF], LABEL_1904
	mov [0xEF], 0x0004

LABEL_1916:
	video type=1, offset=CINEMATIC_444, x=[0xee], y=100, zoom=0x40
	sub [0xEE], 0x0002
	break
	djnz [0xEF], LABEL_1916
	mov [0xEF], 0x0004

LABEL_1928:
	video type=1, offset=CINEMATIC_444, x=[0xee], y=100, zoom=0x40
	sub [0xEE], 0x0001
	break
	djnz [0xEF], LABEL_1928
	mov [0xEF], 0x0002

LABEL_193A:
	video type=1, offset=CINEMATIC_444, x=[0xee], y=100, zoom=0x40
	sub [0xEE], 0x0001
	break
	video type=1, offset=CINEMATIC_444, x=[0xee], y=100, zoom=0x40
	break
	djnz [0xEF], LABEL_193A
	jmp INLINE_SET_VAREF_TO_5
