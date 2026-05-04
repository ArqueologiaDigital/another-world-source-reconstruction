LABEL_0F91:
	break
	video type=1, offset=CINEMATIC_295, x=[0x01], y=[0x02], zoom=0x40
	jmp LABEL_0F91
LABEL_0F9A:
	db 0x11

LABEL_0F9B:
	video type=1, offset=CINEMATIC_298, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_299, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_300, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_299, x=[0x01], y=[0x02], zoom=0x40
	jmp DRAW_CIN_137_138_BLOCK
LABEL_0FB5:
	db 0x11
