LABEL_0ED0:
	add [HERO_X], 0x0003
	video offset=CINEMATIC_134, x=[HERO_X], y=[HERO_Y]
	add [HERO_X], 0x0002
	break
	video offset=CINEMATIC_135, x=[HERO_X], y=[HERO_Y]
	add [HERO_X], 0x0001
	break
	video offset=CINEMATIC_136, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_135, x=[HERO_X], y=[HERO_Y]
	jmp DRAW_CIN_137_138_BLOCK
LABEL_0EF6:
	db 0x11
