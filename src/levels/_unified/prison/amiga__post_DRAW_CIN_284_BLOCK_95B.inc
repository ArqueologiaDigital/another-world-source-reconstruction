LABEL_0FB1:
	break
	video offset=CINEMATIC_295, x=[HERO_X], y=[HERO_Y]
	jmp LABEL_0FB1
LABEL_0FBA:
	db 0x11

LABEL_0FBB:
	video offset=CINEMATIC_298, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_299, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_300, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_299, x=[HERO_X], y=[HERO_Y]
	jmp DRAW_CIN_137_138_BLOCK
LABEL_0FD5:
	db 0x11
