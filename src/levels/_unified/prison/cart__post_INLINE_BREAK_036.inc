LABEL_9957:
	call LABEL_6C5B
	je [HERO_ACTION_POS_MASK], 0x80, INLINE_BREAK_035
	jmp LABEL_98E6
LABEL_9963:
	db 0x11

LABEL_9964:
	call SET_VAR04_TO_0030
	mov [0x2A], 0x0020
	call HANDLE_HORIZ_VAR01_VS_VAR28
	jne [0x0A], 0x00, LABEL_991E
	add [HERO_X], 0x0004
	video offset=CINEMATIC_567, x=[HERO_X], y=[HERO_Y]
	break
	sub [HERO_X], 0x0001
	video offset=CINEMATIC_567, x=[HERO_X], y=[HERO_Y]
	sub [HERO_X], 0x0001

LABEL_998B:
	break
	video offset=CINEMATIC_567, x=[HERO_X], y=[HERO_Y]
	je [HERO_ACTION_POS_MASK], 0x88, LABEL_998B
	break
	sub [HERO_X], 0x0002
	video offset=CINEMATIC_562, x=[HERO_X], y=[HERO_Y]
	mov [0x63], 0x0002
	sub [HERO_X], 0x0002
	jmp HERO_WALK_RIGHT_LOOP
LABEL_99AC:
	db 0x11

LABEL_99AD:
	call SET_VAR04_TO_0000
	mov [0x2A], 0x0020
	jne [0x0A], 0x00, LABEL_9ABB
	sub [HERO_X], 0x0004
	call HANDLE_HORIZ_VAR01_VS_VAR28
	video offset=CINEMATIC_556, x=[HERO_X], y=[HERO_Y]
	break
	add [HERO_X], 0x0001
	video offset=CINEMATIC_556, x=[HERO_X], y=[HERO_Y]
	add [HERO_X], 0x0001

LABEL_99D4:
	break
	video offset=CINEMATIC_556, x=[HERO_X], y=[HERO_Y]
	je [HERO_ACTION_POS_MASK], 0x84, LABEL_99D4
	break
	add [HERO_X], 0x0002
	video offset=CINEMATIC_557, x=[HERO_X], y=[HERO_Y]
	add [HERO_X], 0x0001
	mov [0x63], 0x0001
	jmp HERO_WALK_LEFT_LOOP
LABEL_99F5:
	db 0x11

LABEL_99F6:
	call SET_VAR04_TO_0010
	mov [0x2A], 0x0020
	jne [0x0A], 0x00, LABEL_9BA6
	call HANDLE_HORIZ_VAR01_VS_VAR28
	add [HERO_X], 0x0004
	video offset=CINEMATIC_561, x=[HERO_X], y=[HERO_Y]
	break
	sub [HERO_X], 0x0001
	video offset=CINEMATIC_561, x=[HERO_X], y=[HERO_Y]
	sub [HERO_X], 0x0001

LABEL_9A1D:
	break
	video offset=CINEMATIC_561, x=[HERO_X], y=[HERO_Y]
	je [HERO_ACTION_POS_MASK], 0x84, LABEL_9A1D
	break
	sub [HERO_X], 0x0002
	video offset=CINEMATIC_562, x=[HERO_X], y=[HERO_Y]
	sub [HERO_X], 0x0001
	mov [0x63], 0x0002
	jmp HERO_WALK_RIGHT_LOOP
LABEL_9A3E:
	db 0x11

LABEL_9A3F:
	sub [HERO_X], 0x0004
	video offset=CINEMATIC_187, x=[HERO_X], y=[HERO_Y]
	break
	add [HERO_X], 0x0001
	video offset=CINEMATIC_222, x=[HERO_X], y=[HERO_Y]
	add [HERO_X], 0x0001

LABEL_9A56:
	break
	video offset=CINEMATIC_222, x=[HERO_X], y=[HERO_Y]
	je [HERO_ACTION_POS_MASK], 0x84, LABEL_9A56
	add [HERO_X], 0x0002
	break
	video offset=CINEMATIC_223, x=[HERO_X], y=[HERO_Y]
	add [HERO_X], 0x0002
	je [HERO_POS_JUMP_DOWN], 0x01, LABEL_9B78
	mov [0x63], 0x0001
	jmp HERO_WALK_LEFT_LOOP

LABEL_9A7D:
	add [HERO_X], 0x0004
	video offset=CINEMATIC_212, x=[HERO_X], y=[HERO_Y]
	break
	sub [HERO_X], 0x0001
	video offset=CINEMATIC_213, x=[HERO_X], y=[HERO_Y]
	sub [HERO_X], 0x0001

LABEL_9A94:
	break
	video offset=CINEMATIC_213, x=[HERO_X], y=[HERO_Y]
	je [HERO_ACTION_POS_MASK], 0x84, LABEL_9A94
	sub [HERO_X], 0x0002
	break
	video offset=CINEMATIC_214, x=[HERO_X], y=[HERO_Y]
	sub [HERO_X], 0x0002
	je [HERO_POS_JUMP_DOWN], 0x01, LABEL_9C5F
	mov [0x63], 0x0002
	jmp HERO_WALK_RIGHT_LOOP

LABEL_9ABB:
	jne [0x0F], 0x00, LABEL_9AF7
	sub [HERO_X], 0x0003
	call HANDLE_HORIZ_VAR01_VS_VAR28
	video offset=CINEMATIC_189, x=[HERO_X], y=[HERO_Y]
	mov [0x21], [HERO_X]
	mov [0x27], [HERO_Y]
	sub [0x21], 0x001E
	sub [0x27], 0x0016
	call LABEL_3889
	break
	add [HERO_X], 0x0002
	video offset=CINEMATIC_188, x=[HERO_X], y=[HERO_Y]
	add [HERO_X], 0x0001
	jne [HERO_ACTION_POS_MASK], 0x84, LABEL_9B1E
	setup channel=0x17, address=LABEL_45A9
