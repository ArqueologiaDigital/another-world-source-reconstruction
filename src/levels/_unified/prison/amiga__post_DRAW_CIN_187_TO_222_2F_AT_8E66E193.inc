LABEL_968A:
	break
	video offset=CINEMATIC_222, x=[HERO_X], y=[HERO_Y]
	je [HERO_ACTION_POS_MASK], 0x84, LABEL_968A
	add [HERO_X], 0x0002
	break
	video offset=CINEMATIC_223, x=[HERO_X], y=[HERO_Y]
	add [HERO_X], 0x0002
	je [HERO_POS_JUMP_DOWN], 0x01, LABEL_97A0
	mov [0x63], 0x0001
	jmp HERO_WALK_LEFT_LOOP
