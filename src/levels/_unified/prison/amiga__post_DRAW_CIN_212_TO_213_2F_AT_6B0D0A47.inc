LABEL_96C8:
	break
	video offset=CINEMATIC_213, x=[HERO_X], y=[HERO_Y]
	je [HERO_ACTION_POS_MASK], 0x84, LABEL_96C8
	sub [HERO_X], 0x0002
	break
	video offset=CINEMATIC_214, x=[HERO_X], y=[HERO_Y]
	sub [HERO_X], 0x0002
	je [HERO_POS_JUMP_DOWN], 0x01, LABEL_987B
	mov [0x63], 0x0002
	jmp HERO_WALK_LOOP

LABEL_96EF:
	jne [0x0F], 0x00, LABEL_972B
	sub [HERO_X], 0x0003
	call HANDLE_HORIZ_VAR01_VS_VAR28
	video offset=CINEMATIC_189, x=[HERO_X], y=[HERO_Y]
	mov [0x21], [HERO_X]
	mov [0x27], [HERO_Y]
	sub [0x21], 0x001E
	sub [0x27], 0x0016
	call LABEL_3733
	break
	add [HERO_X], 0x0002
	video offset=CINEMATIC_188, x=[HERO_X], y=[HERO_Y]
	add [HERO_X], 0x0001
	jne [HERO_ACTION_POS_MASK], 0x84, LABEL_9752
	setup channel=0x17, address=LABEL_444D
