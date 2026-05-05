LABEL_99B2:
	video offset=CINEMATIC_092, x=[HERO_X], y=[HERO_Y]
	add [SCROLL_Y], 0x0000
	sub [HERO_Y], 0x0028
	break
	djnz [0x03], LABEL_99B2
	video offset=CINEMATIC_092, x=[HERO_X], y=65516
	break
	mov [HERO_Y], [0x51]
	break
	video offset=CINEMATIC_092, x=[HERO_X], y=180
	mov [HERO_Y], [0x51]
	setup channel=0x1A, address=LABEL_97CE
	jmp LABEL_9A64
LABEL_99DE:
	db 0x11
