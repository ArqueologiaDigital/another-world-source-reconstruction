LABEL_0FB1:
	break
	video offset=CINEMATIC_295, x=[0x01], y=[0x02], zoom=0x40
	jmp LABEL_0FB1
LABEL_0FBA:
	db 0x11

LABEL_0FBB:
	video offset=CINEMATIC_298, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_299, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_300, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_299, x=[0x01], y=[0x02], zoom=0x40
	jmp DRAW_CIN_137_138_BLOCK
LABEL_0FD5:
	db 0x11
