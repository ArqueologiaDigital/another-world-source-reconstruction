LABEL_0BD4:
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_457, x=84, y=[0xe6], zoom=0x40
	video type=1, offset=CINEMATIC_186, x=82, y=[0xe6], zoom=0x40
	selectVideoPage 0xFF
	add [0xE6], 0x0002
	break
	break
	jne [0xE6], 0x56, LABEL_0BD4
	mov [0xE6], 0x0050

LABEL_0BF2:
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_186, x=84, y=[0xe6], zoom=0x40
	video type=1, offset=CINEMATIC_457, x=82, y=[0xe6], zoom=0x40
	selectVideoPage 0xFF
	add [0xE6], 0x0002
	break
	break
	jne [0xE6], 0x56, LABEL_0BF2
	jmp INLINE_SET_VARE6_TO_50
LABEL_0C0F:
	db 0x11

LABEL_0C10:
	video type=1, offset=CINEMATIC_457, x=27, y=153
	break
	video type=1, offset=CINEMATIC_457, x=25, y=158
	break
	video type=1, offset=CINEMATIC_457, x=31, y=157
	break
	video type=1, offset=CINEMATIC_457, x=35, y=153
	break
	video type=1, offset=CINEMATIC_457, x=32, y=149
	break
	video type=1, offset=CINEMATIC_457, x=26, y=148
	break
	video type=1, offset=CINEMATIC_457, x=27, y=153
	break
	video type=1, offset=CINEMATIC_457, x=22, y=146
	break
	video type=1, offset=CINEMATIC_457, x=21, y=150
	break
	video type=1, offset=CINEMATIC_457, x=20, y=153
	break
	jmp LABEL_0C10
LABEL_0C45:
	db 0x11
