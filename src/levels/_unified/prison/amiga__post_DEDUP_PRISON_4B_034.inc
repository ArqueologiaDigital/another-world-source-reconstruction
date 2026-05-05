LABEL_7AAE:
	db 0x11

LABEL_7AAF:
	call LABEL_7D42
	call LABEL_7AD5
	mov [0x21], 0x00A0
	mov [0x22], [0x18]
	mov [0x2B], 0x0006

LABEL_7AC0:
	call LABEL_78E3
	add [0x22], 0x0032
	djnz [0x2B], LABEL_7AC0
	video offset=CINEMATIC_102, x=[HERO_X], y=[HERO_Y]
	video offset=CINEMATIC_103, x=160, y=129
	ret

LABEL_7AD5:
	mov [0x21], 0x0064
	jg [0x14], 0x22A0, DRAW_CIN_092
	mov [0x21], [0x14]
	sub [0x21], 0x22A0
	add [0x21], 0x0064
