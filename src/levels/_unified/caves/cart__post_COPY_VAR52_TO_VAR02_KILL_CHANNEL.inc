LABEL_A0F3:
	mov [0x63], 0x0064
	mov [HERO_Y], [0x52]
	sub [HERO_Y], 0x001E
	call LABEL_A153
	play id=0x0057, freq=0x1C, vol=0x40, channel=0x00
	break
	mov [HERO_Y], [0x52]
	call LABEL_A153
	setup channel=0x1A, address=LABEL_A0E1
	jmp LABEL_A16C
LABEL_A115:
	db 0x11

LABEL_A116:
	mov [0x63], 0x0064
	mov [HERO_Y], [0x51]
	add [HERO_Y], 0x001E
	call LABEL_A139
	play id=0x0057, freq=0x1C, vol=0x40, channel=0x00
	break
	mov [HERO_Y], [0x51]
	call LABEL_A139
	setup channel=0x1A, address=LABEL_A0CF
	jmp LABEL_A16C
LABEL_A138:
	db 0x11

LABEL_A139:
	mov [0xF8], [0x04]
	and [0xF8], 0x0010
	jne [0xF8], 0x00, DRAW_CIN_868
	video offset=CINEMATIC_869, x=[HERO_X], y=[HERO_Y]
	ret

DRAW_CIN_868:
	video offset=CINEMATIC_868, x=[HERO_X], y=[HERO_Y]
	ret
LABEL_A152:
	db 0x11

LABEL_A153:
	mov [0xF8], [0x04]
	and [0xF8], 0x0010
	jne [0xF8], 0x00, DRAW_CIN_866
	video offset=CINEMATIC_867, x=[HERO_X], y=[HERO_Y]
	ret

DRAW_CIN_866:
	video offset=CINEMATIC_866, x=[HERO_X], y=[HERO_Y]
	ret

LABEL_A16C:
	mov [0xF8], [0x04]
	and [0xF8], 0x0010
	mov [0x32], 0x0000
	mov [0x63], 0x0002
	jne [0xF8], 0x00, HERO_WALK_RIGHT_LOOP
	mov [0x63], 0x0001
	jmp HERO_WALK_LEFT_LOOP
LABEL_A188:
	db 0x11
