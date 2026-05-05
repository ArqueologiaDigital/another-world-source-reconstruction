LABEL_7DEF:
	mov [0x63], 0x0064
	mov [HERO_Y], [0x52]
	sub [HERO_Y], 0x001E
	play id=0x0057, freq=0x1C, vol=0x40, channel=0x00
	call LABEL_7E4F
	break
	mov [HERO_Y], [0x52]
	call LABEL_7E4F
	setup channel=0x1A, address=LABEL_7DDD
	jmp LABEL_7E68
LABEL_7E11:
	db 0x11

LABEL_7E12:
	mov [0x63], 0x0064
	mov [HERO_Y], [0x51]
	add [HERO_Y], 0x001E
	play id=0x0057, freq=0x1C, vol=0x40, channel=0x00
	call LABEL_7E35
	break
	mov [HERO_Y], [0x51]
	call LABEL_7E35
	setup channel=0x1A, address=LABEL_7DCB
	jmp LABEL_7E68
LABEL_7E34:
	db 0x11

LABEL_7E35:
	mov [0xF8], [0x04]
	and [0xF8], 0x0010
	jne [0xF8], 0x00, DRAW_CIN_552
	video offset=CINEMATIC_553, x=[HERO_X], y=[HERO_Y]
	ret
