LABEL_753E:
	jl [0x06], 0x07, LABEL_755D
	jg [0x14], 0x00, DRAW_CIN057_AT_X03_Y04
	video type=1, offset=CINEMATIC_059, x=[0x03], y=[0x04], zoom=0x40
	jmp DRAW_CIN_058
