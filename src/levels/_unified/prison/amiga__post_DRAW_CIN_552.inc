LABEL_7E4E:
	db 0x11

LABEL_7E4F:
	mov [0xF8], [0x04]
	and [0xF8], 0x0010
	jne [0xF8], 0x00, DRAW_CIN_550
	video offset=CINEMATIC_551, x=[HERO_X], y=[HERO_Y]
	ret
