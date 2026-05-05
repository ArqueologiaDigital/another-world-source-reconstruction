DRAW_CIN_055:
	video offset=CINEMATIC_055, x=[0x03], y=[0x04], zoom=0x40
	ret

LABEL_74D0:
	jne [0x06], 0xFFFE, LABEL_74F0
	jl [0x14], 0x00, DRAW_CIN051_AT_X03_Y04
	video offset=CINEMATIC_053, x=[0x03], y=[0x04], zoom=0x40
	jmp DRAW_CIN_052
