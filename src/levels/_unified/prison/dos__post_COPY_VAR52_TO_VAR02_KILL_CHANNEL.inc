LABEL_7EBA:
	mov [0x63], 0x0064
	mov [HERO_Y], [0x52]
	sub [HERO_Y], 0x001E
	play id=0x0057, freq=0x1C, vol=0x40, channel=0x00
	call PRISON_DRAW_CIN_552_L1
	break
	mov [HERO_Y], [0x52]
	call PRISON_DRAW_CIN_552_L1
	setup channel=0x1A, address=PRISON_COPY_VAR51_TO_VAR02_KILL_CHANNEL_L0
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
	setup channel=0x1A, address=PRISON_COPY_PAGE0_TO_3_AND_VAR66_TO_VAR65_L1
	jmp LABEL_7F33
LABEL_7EFF:
	db 0x11

LABEL_7F00:
	mov [0xF8], [0x04]
	and [0xF8], 0x0010
	jne [0xF8], 0x00, DRAW_CIN_552
	video offset=CINEMATIC_553, x=[HERO_X], y=[HERO_Y]
	ret
