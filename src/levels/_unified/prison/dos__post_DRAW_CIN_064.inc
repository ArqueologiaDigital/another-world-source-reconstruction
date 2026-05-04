LABEL_751F:
	jne [0x06], 0x06, LABEL_753E
	jg [0x14], 0x00, DRAW_CIN060_AT_X03_Y04
	video type=1, offset=CINEMATIC_062, x=[0x03], y=[0x04], zoom=0x40
	jmp DRAW_CIN_061
