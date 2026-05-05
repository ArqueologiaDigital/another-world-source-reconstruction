LABEL_739F:
	jne [0x06], 0x00, LABEL_73AB
	video offset=CINEMATIC_595, x=[0x03], y=[0x04], zoom=0x40
	ret

LABEL_73AB:
	jne [0x06], 0x01, LABEL_73B7
	video offset=CINEMATIC_594, x=[0x03], y=[0x04], zoom=0x40
	ret

LABEL_73B7:
	jne [0x06], 0x02, LABEL_73C3
	video offset=CINEMATIC_593, x=[0x03], y=[0x04], zoom=0x40
	ret

LABEL_73C3:
	jne [0x06], 0x03, LABEL_73CF
	video offset=CINEMATIC_592, x=[0x03], y=[0x04], zoom=0x40
	ret

LABEL_73CF:
	jne [0x06], 0x04, LABEL_73DB
	video offset=CINEMATIC_591, x=[0x03], y=[0x04], zoom=0x40
	ret

LABEL_73DB:
	jne [0x06], 0x05, LABEL_73E7
	video offset=CINEMATIC_590, x=[0x03], y=[0x04], zoom=0x40
	ret

LABEL_73E7:
	jne [0x06], 0x06, LABEL_73F3
	video offset=CINEMATIC_589, x=[0x03], y=[0x04], zoom=0x40
	ret

LABEL_73F3:
	jl [0x06], 0x07, LABEL_73FF
	video offset=CINEMATIC_588, x=[0x03], y=[0x04], zoom=0x40
	ret

LABEL_73FF:
	jne [0x06], 0xFFFF, LABEL_740C
	video offset=CINEMATIC_587, x=[0x03], y=[0x04], zoom=0x40
	ret

LABEL_740C:
	jne [0x06], 0xFFFE, LABEL_7419
	video offset=CINEMATIC_586, x=[0x03], y=[0x04], zoom=0x40
	ret

LABEL_7419:
	jne [0x06], 0xFFFD, LABEL_7426
	video offset=CINEMATIC_585, x=[0x03], y=[0x04], zoom=0x40
	ret

LABEL_7426:
	jne [0x06], 0xFFFC, LABEL_7433
	video offset=CINEMATIC_584, x=[0x03], y=[0x04], zoom=0x40
	ret

LABEL_7433:
	jne [0x06], 0xFFFB, LABEL_7440
	video offset=CINEMATIC_583, x=[0x03], y=[0x04], zoom=0x40
	ret

LABEL_7440:
	jne [0x06], 0xFFFA, DRAW_CIN_581
	video offset=CINEMATIC_582, x=[0x03], y=[0x04], zoom=0x40
	ret

DRAW_CIN_581:
	video offset=CINEMATIC_581, x=[0x03], y=[0x04], zoom=0x40
	ret
	killChannel
	jne [0x06], 0x00, LABEL_7460
	video offset=CINEMATIC_079, x=[0x03], y=[0x04], zoom=0x40
	ret

LABEL_7460:
	jne [0x06], 0x01, DRAW_CIN_055_AT_746C
	video offset=CINEMATIC_076, x=[0x03], y=[0x04], zoom=0x40
	ret

DRAW_CIN_055_AT_746C:
	video offset=CINEMATIC_055, x=[0x03], y=[0x04], zoom=0x40
	ret
LABEL_7472:
	db 0x11

LABEL_7473:
	jne [0x06], 0x00, LABEL_7484
	video offset=CINEMATIC_078, x=[0x03], y=[0x04], zoom=0x40
	video offset=CINEMATIC_079, x=[0x03], y=[0x04], zoom=0x40
	ret

LABEL_7484:
	jne [0x06], 0x01, LABEL_74A3
	jg [0x14], 0x00, DRAW_CIN075_AT_X03_Y04
	video offset=CINEMATIC_077, x=[0x03], y=[0x04], zoom=0x40
	jmp DRAW_CIN_076
