LABEL_9949:
	video offset=CINEMATIC_091, x=[HERO_X], y=[HERO_Y]
	add [SCROLL_Y], 0x0000
	sub [HERO_Y], 0x0028
	break
	djnz [0x03], LABEL_9949
	video offset=CINEMATIC_091, x=[HERO_X], y=65516
	break
	mov [HERO_Y], [0x51]
	break
	video offset=CINEMATIC_091, x=[HERO_X], y=180
	mov [HERO_Y], [0x51]
	setup channel=0x1A, address=CAPSULE_COPY_PAGE0_TO_3_AND_VAR66_TO_VAR65_L1
	jmp CAPSULE_HERO_WALK_DECIDE_BY_VAR04_BIT_4
LABEL_9975:
	db 0x11
