LABEL_74C2:
	jne [0x06], 0x03, LABEL_74E1
	jg [0x14], 0x00, DRAW_CIN069_AT_X03_Y04
	video type=1, offset=CINEMATIC_071, x=[0x03], y=[0x04], zoom=0x40
	jmp DRAW_CIN_070
