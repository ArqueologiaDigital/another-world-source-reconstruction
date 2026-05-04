LABEL_75FD:
	jne [0x06], 0xFFFA, LABEL_761D
	jl [0x14], 0x00, DRAW_CIN039_AT_X03_Y04
	video type=1, offset=CINEMATIC_041, x=[0x03], y=[0x04], zoom=0x40
	jmp DRAW_CIN_040
