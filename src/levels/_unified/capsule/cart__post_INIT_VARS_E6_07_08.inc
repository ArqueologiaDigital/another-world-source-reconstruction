LABEL_03F2:
	video type=1, offset=CINEMATIC_003, x=123, y=172
	video type=1, offset=CINEMATIC_004, x=114, y=160
	break
	djnz [0xE6], LABEL_03F2
	video type=1, offset=CINEMATIC_005, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=1, offset=CINEMATIC_006, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=1, offset=CINEMATIC_007, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=1, offset=CINEMATIC_008, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=1, offset=CINEMATIC_008, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=1, offset=CINEMATIC_009, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=1, offset=CINEMATIC_010, x=[0x07], y=[0x08], zoom=0x40
	mov [0x01], 0x005C
	mov [0x02], [0x40]
	mov [0x63], 0x0002
	setup channel=0x14, address=LABEL_9A9E
	setup channel=0x14, address=LABEL_BE04
	setup channel=0x16, address=LABEL_9A8A
	setup channel=0x16, address=LABEL_B74A
	setup channel=0x03, address=LABEL_0496
	mov [0x32], 0x0000
	mov [0x29], 0x0004

LABEL_044F:
	break
	video type=1, offset=CINEMATIC_011, x=[0x07], y=[0x08], zoom=0x40
	djnz [0x29], LABEL_044F
	break
	jmp INIT_VARS_0E_29
LABEL_045D:
	db 0x11
