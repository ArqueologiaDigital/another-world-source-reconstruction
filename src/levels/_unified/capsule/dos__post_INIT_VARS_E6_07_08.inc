LABEL_0385:
	video offset=CINEMATIC_003, x=123, y=172
	video offset=CINEMATIC_004, x=114, y=160
	break
	djnz [0xE6], LABEL_0385
	video offset=CINEMATIC_BUDDY_PULLS_LESTER_0, x=[0x07], y=[0x08]
	break
	video offset=CINEMATIC_BUDDY_PULLS_LESTER_1, x=[0x07], y=[0x08]
	break
	video offset=CINEMATIC_BUDDY_PULLS_LESTER_2, x=[0x07], y=[0x08]
	break
	video offset=CINEMATIC_BUDDY_PULLS_LESTER_3, x=[0x07], y=[0x08]
	break
	video offset=CINEMATIC_BUDDY_PULLS_LESTER_3, x=[0x07], y=[0x08]
	break
	video offset=CINEMATIC_BUDDY_PULLS_LESTER_4, x=[0x07], y=[0x08]
	break
	video offset=CINEMATIC_BUDDY_PULLS_LESTER_5, x=[0x07], y=[0x08]
	mov [HERO_X], 0x005C
	mov [HERO_Y], [0x40]
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
	video offset=CINEMATIC_BUDDY_PULLS_LESTER_6, x=[0x07], y=[0x08]
	djnz [0x29], LABEL_03E2
	break
	jmp INIT_VARS_0E_29
LABEL_03F0:
	db 0x11
