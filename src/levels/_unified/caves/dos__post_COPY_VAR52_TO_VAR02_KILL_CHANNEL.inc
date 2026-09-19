CAVES_TELEPORT_DOWN_ENTRY:
	mov [0x63], 0x0064
	mov [HERO_Y], [0x52]
	sub [HERO_Y], 0x001E
	call CAVES_TELEPORT_DOWN_BEAM_DRAW
	play id=0x0057, freq=0x1C, vol=0x40, channel=0x00
	break
	mov [HERO_Y], [0x52]
	call CAVES_TELEPORT_DOWN_BEAM_DRAW
	setup channel=0x1A, address=CAVES_TELEPORT_DOWN_SETTLE_LOOP
	jmp LABEL_A1F5
LABEL_A19E:
	db 0x11

CAVES_TELEPORT_UP_ENTRY:
	mov [0x63], 0x0064
	mov [HERO_Y], [0x51]
	add [HERO_Y], 0x001E
	call CAVES_TELEPORT_UP_BEAM_DRAW
	play id=0x0057, freq=0x1C, vol=0x40, channel=0x00
	break
	mov [HERO_Y], [0x51]
	call CAVES_TELEPORT_UP_BEAM_DRAW
	setup channel=0x1A, address=CAVES_SHELVE_BACKDROP_TO_PAGE3_L1
	jmp LABEL_A1F5
LABEL_A1C1:
	db 0x11

CAVES_TELEPORT_UP_BEAM_DRAW:
	mov [0xF8], [0x04]
	and [0xF8], 0x0010
	jne [0xF8], 0x00, DRAW_CIN_878
	video offset=CINEMATIC_879, x=[HERO_X], y=[HERO_Y]
	ret


DRAW_CIN_878:
	video offset=CINEMATIC_878, x=[HERO_X], y=[HERO_Y]
	ret


LABEL_A1DB:
	db 0x11

CAVES_TELEPORT_DOWN_BEAM_DRAW:
	mov [0xF8], [0x04]
	and [0xF8], 0x0010
	jne [0xF8], 0x00, DRAW_CIN_876
	video offset=CINEMATIC_877, x=[HERO_X], y=[HERO_Y]
	ret


DRAW_CIN_876:
	video offset=CINEMATIC_876, x=[HERO_X], y=[HERO_Y]
	ret


LABEL_A1F5:
	mov [0xF8], [0x04]
	and [0xF8], 0x0010
	mov [0x32], 0x0000
	mov [0x63], 0x0002
	jne [0xF8], 0x00, HERO_WALK_RIGHT_LOOP
	mov [0x63], 0x0001
	jmp HERO_WALK_LEFT_LOOP
LABEL_A211:
	db 0x11
