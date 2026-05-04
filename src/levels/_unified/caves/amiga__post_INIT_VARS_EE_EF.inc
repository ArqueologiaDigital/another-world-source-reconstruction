LABEL_16FC:
	video type=1, offset=CINEMATIC_423, x=[0xee], y=98, zoom=0x40
	sub [0xEE], 0x000A
	break
	djnz [0xEF], LABEL_16FC
	mov [0xEF], 0x0004

LABEL_170E:
	video type=1, offset=CINEMATIC_423, x=[0xee], y=99, zoom=0x40
	sub [0xEE], 0x0008
	break
	djnz [0xEF], LABEL_170E
	mov [0xEF], 0x0004

LABEL_1720:
	video type=1, offset=CINEMATIC_423, x=[0xee], y=100, zoom=0x40
	sub [0xEE], 0x0006
	break
	djnz [0xEF], LABEL_1720
	mov [0xEF], 0x0004

LABEL_1732:
	video type=1, offset=CINEMATIC_423, x=[0xee], y=100, zoom=0x40
	sub [0xEE], 0x0004
	break
	djnz [0xEF], LABEL_1732
	mov [0xEF], 0x0004

LABEL_1744:
	video type=1, offset=CINEMATIC_423, x=[0xee], y=100, zoom=0x40
	sub [0xEE], 0x0003
	break
	djnz [0xEF], LABEL_1744
	mov [0xEF], 0x0004

LABEL_1756:
	video type=1, offset=CINEMATIC_423, x=[0xee], y=100, zoom=0x40
	sub [0xEE], 0x0002
	break
	djnz [0xEF], LABEL_1756
	mov [0xEF], 0x0004

LABEL_1768:
	video type=1, offset=CINEMATIC_423, x=[0xee], y=100, zoom=0x40
	sub [0xEE], 0x0001
	break
	djnz [0xEF], LABEL_1768
	mov [0xEF], 0x0002

LABEL_177A:
	video type=1, offset=CINEMATIC_423, x=[0xee], y=100, zoom=0x40
	sub [0xEE], 0x0001
	break
	video type=1, offset=CINEMATIC_423, x=[0xee], y=100, zoom=0x40
	break
	djnz [0xEF], LABEL_177A
	jmp INLINE_SET_VAREF_TO_5
