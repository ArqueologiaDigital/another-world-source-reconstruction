LABEL_98E4:
	break
	video offset=CINEMATIC_222, x=[0x01], y=[0x02]
	je [HERO_ACTION_POS_MASK], 0x84, LABEL_98E4
	add [0x01], 0x0002
	break
	video offset=CINEMATIC_223, x=[0x01], y=[0x02]
	add [0x01], 0x0002
	je [HERO_POS_JUMP_DOWN], 0x01, LABEL_99FA
	mov [0x63], 0x0001
	jmp HERO_WALK_LEFT_LOOP
