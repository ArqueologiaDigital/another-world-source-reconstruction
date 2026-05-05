LABEL_99EB:
	video offset=CINEMATIC_090, x=[HERO_X], y=[HERO_Y]
	add [HERO_Y], 0x0028
	break
	djnz [0x03], LABEL_99EB
	video offset=CINEMATIC_090, x=[HERO_X], y=240
	break
	mov [0x32], 0x0001
	video offset=CINEMATIC_090, x=[HERO_X], y=280
	break
	mov [HERO_Y], [0x52]
	break
	mov [0x32], 0x0001
	video offset=CINEMATIC_090, x=[HERO_X], y=77
	break
	mov [0x32], 0x0001
	video offset=CINEMATIC_090, x=[HERO_X], y=146
	break
	video offset=CINEMATIC_090, x=[HERO_X], y=189
	mov [HERO_Y], [0x52]
	setup channel=0x1A, address=LABEL_97DD
	jmp LABEL_9A64

LABEL_9A31:
	mov [0xF8], [0x04]
	and [0xF8], 0x0010
	jne [0xF8], 0x00, DRAW_CIN_092
	video offset=CINEMATIC_093, x=[HERO_X], y=[HERO_Y]
	ret

DRAW_CIN_092:
	video offset=CINEMATIC_092, x=[HERO_X], y=[HERO_Y]
	ret
LABEL_9A4A:
	db 0x11

LABEL_9A4B:
	mov [0xF8], [0x04]
	and [0xF8], 0x0010
	jne [0xF8], 0x00, DRAW_CIN_090
	video offset=CINEMATIC_091, x=[HERO_X], y=[HERO_Y]
	ret

DRAW_CIN_090:
	video offset=CINEMATIC_090, x=[HERO_X], y=[HERO_Y]
	ret

LABEL_9A64:
	mov [0xF8], [0x04]
	and [0xF8], 0x0010
	mov [0x32], 0x0000
	mov [0x63], 0x0002
	jne [0xF8], 0x00, HERO_WALK_RIGHT_LOOP
	mov [0x63], 0x0001
	jmp HERO_WALK_LEFT_LOOP
LABEL_9A80:
	db 0x11
