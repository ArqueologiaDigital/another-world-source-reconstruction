LABEL_7415:
	jne [0x06], 0x03, LABEL_7434
	jg [0x14], 0x00, DRAW_CIN069_AT_X03_Y04
	video offset=CINEMATIC_071, x=[0x03], y=[0x04], zoom=0x40
	jmp DRAW_CIN_070
