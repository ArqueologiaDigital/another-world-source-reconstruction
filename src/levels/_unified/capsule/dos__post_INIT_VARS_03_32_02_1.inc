LABEL_9949:
	video offset=CINEMATIC_091, x=[HERO_X], y=[HERO_Y]
	add [SCROLL_Y], 0x0000
	sub [HERO_Y], 0x0028
	break
	djnz [0x03], LABEL_9949
	video offset=CINEMATIC_091, x=[HERO_X], y=65516
	break
	mov [HERO_Y], [0x51]
	break
	video offset=CINEMATIC_091, x=[HERO_X], y=180
	mov [HERO_Y], [0x51]
	setup channel=0x1A, address=LABEL_9765
	jmp LABEL_99FB
LABEL_9975:
	db 0x11
