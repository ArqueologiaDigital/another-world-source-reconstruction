LABEL_0F12:
	break
	video offset=CINEMATIC_282, x=[HERO_X], y=[HERO_Y]
	djnz [0x03], LABEL_0F12
	setup channel=0x15, address=DRAW_CIN_284_BLOCK_95B
	mov [0x03], 0x0003

LABEL_0F24:
	break
	video offset=CINEMATIC_283, x=[HERO_X], y=[HERO_Y]
	djnz [0x03], LABEL_0F24
	jmp DRAW_CIN_137_138_BLOCK
LABEL_0F31:
	db 0x11
