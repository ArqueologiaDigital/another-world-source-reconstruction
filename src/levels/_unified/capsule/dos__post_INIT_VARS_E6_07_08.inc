LABEL_0385:
	video offset=CINEMATIC_003, x=123, y=172
	video offset=CINEMATIC_004, x=114, y=160
	break
	djnz [0xE6], LABEL_0385
	video offset=CINEMATIC_005, x=[0x07], y=[0x08], zoom=0x40
	break
	video offset=CINEMATIC_006, x=[0x07], y=[0x08], zoom=0x40
	break
	video offset=CINEMATIC_007, x=[0x07], y=[0x08], zoom=0x40
	break
	video offset=CINEMATIC_008, x=[0x07], y=[0x08], zoom=0x40
	break
	video offset=CINEMATIC_008, x=[0x07], y=[0x08], zoom=0x40
	break
	video offset=CINEMATIC_009, x=[0x07], y=[0x08], zoom=0x40
	break
	video offset=CINEMATIC_010, x=[0x07], y=[0x08], zoom=0x40
	mov [0x01], 0x005C
	mov [0x02], [0x40]
	mov [0x63], 0x0002
	setup channel=0x14, address=LABEL_9A35
	setup channel=0x14, address=LABEL_BD20
	setup channel=0x16, address=LABEL_9A21
	setup channel=0x16, address=LABEL_B666
	setup channel=0x03, address=LABEL_0429
	mov [0x32], 0x0000
	mov [0x29], 0x0004

LABEL_03E2:
	break
	video offset=CINEMATIC_011, x=[0x07], y=[0x08], zoom=0x40
	djnz [0x29], LABEL_03E2
	break
	jmp INIT_VARS_0E_29
LABEL_03F0:
	db 0x11
