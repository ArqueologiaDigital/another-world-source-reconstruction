LABEL_9922:
	break
	video type=1, offset=CINEMATIC_213, x=[0x01], y=[0x02], zoom=0x40
	je [HERO_ACTION_POS_MASK], 0x84, LABEL_9922
	sub [0x01], 0x0002
	break
	video type=1, offset=CINEMATIC_214, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0002
	je [HERO_POS_JUMP_DOWN], 0x01, LABEL_9AD5
	mov [0x63], 0x0002
	jmp HERO_WALK_RIGHT_LOOP

LABEL_9949:
	jne [0x0F], 0x00, LABEL_9985
	sub [0x01], 0x0003
	call HANDLE_HORIZ_VAR01_VS_VAR28
	video type=1, offset=CINEMATIC_189, x=[0x01], y=[0x02], zoom=0x40
	mov [0x21], [0x01]
	mov [0x27], [0x02]
	sub [0x21], 0x001E
	sub [0x27], 0x0016
	call LABEL_3795
	break
	add [0x01], 0x0002
	video type=1, offset=CINEMATIC_188, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0001
	jne [HERO_ACTION_POS_MASK], 0x84, LABEL_99AC
	setup channel=0x17, address=LABEL_44AF
