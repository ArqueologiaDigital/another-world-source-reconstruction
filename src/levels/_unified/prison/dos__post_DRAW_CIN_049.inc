LABEL_75BD:
	jne [0x06], 0xFFFC, LABEL_75DD
	jl [0x14], 0x00, DRAW_CIN045_AT_X03_Y04
	video type=1, offset=CINEMATIC_047, x=[0x03], y=[0x04], zoom=0x40
	jmp DRAW_CIN_046
