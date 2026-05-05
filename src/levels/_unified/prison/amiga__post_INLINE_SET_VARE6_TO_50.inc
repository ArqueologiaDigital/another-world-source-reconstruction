LABEL_0B6C:
	selectVideoPage 0x00
	video offset=CINEMATIC_457, x=84, y=[0xe6]
	video offset=CINEMATIC_186, x=82, y=[0xe6]
	selectVideoPage 0xFF
	add [0xE6], 0x0002
	break
	break
	jne [0xE6], 0x56, LABEL_0B6C
	mov [0xE6], 0x0050

LABEL_0B8A:
	selectVideoPage 0x00
	video offset=CINEMATIC_186, x=84, y=[0xe6]
	video offset=CINEMATIC_457, x=82, y=[0xe6]
	selectVideoPage 0xFF
	add [0xE6], 0x0002
	break
	break
	jne [0xE6], 0x56, LABEL_0B8A
	jmp INLINE_SET_VARE6_TO_50
LABEL_0BA7:
	db 0x11

LABEL_0BA8:
	video offset=CINEMATIC_457, x=27, y=153
	break
	video offset=CINEMATIC_457, x=25, y=158
	break
	video offset=CINEMATIC_457, x=31, y=157
	break
	video offset=CINEMATIC_457, x=35, y=153
	break
	video offset=CINEMATIC_457, x=32, y=149
	break
	video offset=CINEMATIC_457, x=26, y=148
	break
	video offset=CINEMATIC_457, x=27, y=153
	break
	video offset=CINEMATIC_457, x=22, y=146
	break
	video offset=CINEMATIC_457, x=21, y=150
	break
	video offset=CINEMATIC_457, x=20, y=153
	break
	jmp LABEL_0BA8
LABEL_0BDD:
	db 0x11
