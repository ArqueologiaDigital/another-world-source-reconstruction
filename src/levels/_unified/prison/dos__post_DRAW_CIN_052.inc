LABEL_759D:
	jne [0x06], 0xFFFD, LABEL_75BD
	jl [0x14], 0x00, DRAW_CIN048_AT_X03_Y04
	video offset=CINEMATIC_050, x=[0x03], y=[0x04], zoom=0x40
	jmp DRAW_CIN_049
