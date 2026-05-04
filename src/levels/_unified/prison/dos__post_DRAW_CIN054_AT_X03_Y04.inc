DRAW_CIN_055_AT_7577:
	video type=1, offset=CINEMATIC_055, x=[0x03], y=[0x04], zoom=0x40
	ret

LABEL_757D:
	jne [0x06], 0xFFFE, LABEL_759D
	jl [0x14], 0x00, DRAW_CIN051_AT_X03_Y04
	video type=1, offset=CINEMATIC_053, x=[0x03], y=[0x04], zoom=0x40
	jmp DRAW_CIN_052
