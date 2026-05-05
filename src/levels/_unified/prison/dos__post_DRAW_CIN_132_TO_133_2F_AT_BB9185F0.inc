LABEL_0ED0:
	add [0x01], 0x0003
	video offset=CINEMATIC_134, x=[0x01], y=[0x02]
	add [0x01], 0x0002
	break
	video offset=CINEMATIC_135, x=[0x01], y=[0x02]
	add [0x01], 0x0001
	break
	video offset=CINEMATIC_136, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_135, x=[0x01], y=[0x02]
	jmp DRAW_CIN_137_138_BLOCK
LABEL_0EF6:
	db 0x11
