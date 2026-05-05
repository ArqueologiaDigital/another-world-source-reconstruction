LABEL_74B0:
	jne [0x06], 0xFFFF, LABEL_74D0
	jl [0x14], 0x00, DRAW_CIN054_AT_X03_Y04
	video offset=CINEMATIC_056, x=[0x03], y=[0x04], zoom=0x40
	jmp DRAW_CIN_055
