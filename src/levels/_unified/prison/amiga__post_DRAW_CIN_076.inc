LABEL_73F6:
	jne [0x06], 0x02, LABEL_7415
	jg [0x14], 0x00, DRAW_CIN072_AT_X03_Y04
	video type=1, offset=CINEMATIC_074, x=[0x03], y=[0x04], zoom=0x40
	jmp DRAW_CIN_073
