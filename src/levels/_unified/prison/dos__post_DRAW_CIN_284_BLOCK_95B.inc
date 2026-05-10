LABEL_0F91:
	break
	video offset=CINEMATIC_CAVES_WATERFALL_LEFT_STAIRS_BG, x=[HERO_X], y=[HERO_Y]
	jmp LABEL_0F91
LABEL_0F9A:
	db 0x11

LABEL_0F9B:
	video offset=CINEMATIC_298, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_299, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_CAVES_WATERFALL_BG, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_299, x=[HERO_X], y=[HERO_Y]
	jmp DRAW_CIN_137_138_BLOCK
LABEL_0FB5:
	db 0x11
