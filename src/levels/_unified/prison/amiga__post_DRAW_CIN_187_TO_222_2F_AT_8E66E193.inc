LABEL_968A:
	break
	video type=1, offset=CINEMATIC_222, x=[0x01], y=[0x02], zoom=0x40
	je [HERO_ACTION_POS_MASK], 0x84, LABEL_968A
	add [0x01], 0x0002
	break
	video type=1, offset=CINEMATIC_223, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0002
	je [HERO_POS_JUMP_DOWN], 0x01, LABEL_97A0
	mov [0x63], 0x0001
	jmp HERO_WALK_LEFT_LOOP
