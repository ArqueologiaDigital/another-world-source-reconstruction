LABEL_75DD:
	jne [0x06], 0xFFFB, LABEL_75FD
	jl [0x14], 0x00, DRAW_CIN042_AT_X03_Y04
	video type=1, offset=CINEMATIC_044, x=[0x03], y=[0x04], zoom=0x40
	jmp DRAW_CIN_043
