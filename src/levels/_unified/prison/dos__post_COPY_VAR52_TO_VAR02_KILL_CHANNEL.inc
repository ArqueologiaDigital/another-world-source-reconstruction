LABEL_7EBA:
	mov [0x63], 0x0064
	mov [HERO_Y], [0x52]
	sub [HERO_Y], 0x001E
	play id=0x0057, freq=0x1C, vol=0x40, channel=0x00
	call LABEL_7F1A
	break
	mov [HERO_Y], [0x52]
	call LABEL_7F1A
	setup channel=0x1A, address=LABEL_7EA8
	jmp LABEL_7F33
LABEL_7EDC:
	db 0x11

LABEL_7EDD:
	mov [0x63], 0x0064
	mov [HERO_Y], [0x51]
	add [HERO_Y], 0x001E
	play id=0x0057, freq=0x1C, vol=0x40, channel=0x00
	call LABEL_7F00
	break
	mov [HERO_Y], [0x51]
	call LABEL_7F00
	setup channel=0x1A, address=LABEL_7E96
	jmp LABEL_7F33
LABEL_7EFF:
	db 0x11

LABEL_7F00:
	mov [0xF8], [0x04]
	and [0xF8], 0x0010
	jne [0xF8], 0x00, DRAW_CIN_552
	video offset=CINEMATIC_553, x=[HERO_X], y=[HERO_Y]
	ret
