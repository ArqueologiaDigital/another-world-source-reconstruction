LABEL_03F2:
	video offset=CINEMATIC_003, x=123, y=172
	video offset=CINEMATIC_004, x=114, y=160
	break
	djnz [0xE6], LABEL_03F2
	video offset=CINEMATIC_BUDDY_PULLS_LESTER_0, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_BUDDY_PULLS_LESTER_1, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_BUDDY_PULLS_LESTER_2, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_BUDDY_PULLS_LESTER_3, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_BUDDY_PULLS_LESTER_3, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_BUDDY_PULLS_LESTER_4, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_BUDDY_PULLS_LESTER_5, x=[BUDDY_X], y=[BUDDY_Y]
	mov [HERO_X], 0x005C
	mov [HERO_Y], [0x40]
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
	video offset=CINEMATIC_BUDDY_PULLS_LESTER_6, x=[BUDDY_X], y=[BUDDY_Y]
	djnz [0x29], LABEL_044F
	break
	jmp INIT_VARS_0E_29
LABEL_045D:
	db 0x11
