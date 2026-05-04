LABEL_7500:
	jne [0x06], 0x05, LABEL_751F
	jg [0x14], 0x00, DRAW_CIN063_AT_X03_Y04
	video type=1, offset=CINEMATIC_065, x=[0x03], y=[0x04], zoom=0x40
	jmp DRAW_CIN_064
