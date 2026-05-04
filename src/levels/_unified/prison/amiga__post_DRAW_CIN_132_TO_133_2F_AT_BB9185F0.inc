LABEL_0EF0:
	add [0x01], 0x0003
	video type=1, offset=CINEMATIC_134, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0002
	break
	video type=1, offset=CINEMATIC_135, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0001
	break
	video type=1, offset=CINEMATIC_136, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_135, x=[0x01], y=[0x02], zoom=0x40
	jmp DRAW_CIN_137_138_BLOCK
LABEL_0F16:
	db 0x11
