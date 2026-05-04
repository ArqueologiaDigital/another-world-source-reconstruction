LABEL_38B4:
	break
	je [HACK_VAR_67], 0x8D, INLINE_SET_VAR29_TO_8
	jne [HACK_VAR_67], [0x6A], LABEL_38CB
	video type=1, offset=CINEMATIC_269, x=283, y=98, zoom=0x40
	video type=1, offset=CINEMATIC_118, x=284, y=225, zoom=0x40

LABEL_38CB:
	djnz [0x29], LABEL_38B4
	mov [0x29], 0x0008

LABEL_38D3:
	break
	je [HACK_VAR_67], 0x8D, INLINE_SET_VAR29_TO_8
	jne [HACK_VAR_67], [0x6A], LABEL_38EA
	video type=1, offset=CINEMATIC_270, x=283, y=98, zoom=0x40
	video type=1, offset=CINEMATIC_118, x=283, y=224, zoom=0x40

LABEL_38EA:
	djnz [0x29], LABEL_38D3
	mov [0x29], 0x000C

LABEL_38F2:
	break
	je [HACK_VAR_67], 0x8D, INLINE_SET_VAR29_TO_8
	jne [HACK_VAR_67], [0x6A], LABEL_3909
	video type=1, offset=CINEMATIC_269, x=283, y=98, zoom=0x40
	video type=1, offset=CINEMATIC_118, x=284, y=224, zoom=0x40

LABEL_3909:
	djnz [0x29], LABEL_38F2
	jmp INLINE_SET_VAR29_TO_6
LABEL_3910:
	db 0x11
