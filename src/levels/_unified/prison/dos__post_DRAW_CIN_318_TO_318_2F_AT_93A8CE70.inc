LABEL_0ABF:
	break
	mov [0xF8], [0x31]
	and [0xF8], 0x0007
	jne [0xF8], 0x00, LABEL_0ABF
	selectVideoPage 0x00
	video offset=CINEMATIC_319, x=225, y=50
	video offset=CINEMATIC_319, x=278, y=50
	selectVideoPage 0xFF

LABEL_0ADA:
	break
	mov [0xF8], [0x31]
	and [0xF8], 0x0003
	jne [0xF8], 0x00, LABEL_0ADA
	jmp DRAW_CIN_318_TO_318_2F_AT_93A8CE70
	killChannel

LABEL_0AEC:
	break
	selectVideoPage 0x00
	video offset=CINEMATIC_186, x=101, y=158
	video offset=CINEMATIC_457, x=105, y=154
	selectVideoPage 0xFF
	break
	break
	selectVideoPage 0x00
	video offset=CINEMATIC_186, x=103, y=156
	video offset=CINEMATIC_457, x=101, y=158
	selectVideoPage 0xFF
	break
	break
	selectVideoPage 0x00
	video offset=CINEMATIC_186, x=105, y=154
	video offset=CINEMATIC_457, x=103, y=156
	selectVideoPage 0xFF
	break
	jmp LABEL_0AEC
	killChannel

LABEL_0B1A:
	selectVideoPage 0x00
	video offset=CINEMATIC_457, x=109, y=167
	video offset=CINEMATIC_703, x=108, y=167
	selectVideoPage 0xFF
	break
	break
	selectVideoPage 0x00
	video offset=CINEMATIC_186, x=110, y=166
	video offset=CINEMATIC_703, x=109, y=167
	selectVideoPage 0xFF
	break
	break
	selectVideoPage 0x00
	video offset=CINEMATIC_186, x=108, y=167
	video offset=CINEMATIC_703, x=110, y=166
	selectVideoPage 0xFF
	break
	break
	jmp LABEL_0B1A
LABEL_0B47:
	db 0x11
