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
	add [0x01], 0x0004
	video type=1, offset=CINEMATIC_567, x=[0x01], y=[0x02], zoom=0x40
	break
	sub [0x01], 0x0001
	video type=1, offset=CINEMATIC_567, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0001

LABEL_998B:
	break
	video type=1, offset=CINEMATIC_567, x=[0x01], y=[0x02], zoom=0x40
	je [HERO_ACTION_POS_MASK], 0x88, LABEL_998B
	break
	sub [0x01], 0x0002
	video type=1, offset=CINEMATIC_562, x=[0x01], y=[0x02], zoom=0x40
	mov [0x63], 0x0002
	sub [0x01], 0x0002
	jmp HERO_WALK_RIGHT_LOOP
LABEL_99AC:
	db 0x11

LABEL_99AD:
	call SET_VAR04_TO_0000
	mov [0x2A], 0x0020
	jne [0x0A], 0x00, LABEL_9ABB
	sub [0x01], 0x0004
	call HANDLE_HORIZ_VAR01_VS_VAR28
	video type=1, offset=CINEMATIC_556, x=[0x01], y=[0x02], zoom=0x40
	break
	add [0x01], 0x0001
	video type=1, offset=CINEMATIC_556, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0001

LABEL_99D4:
	break
	video type=1, offset=CINEMATIC_556, x=[0x01], y=[0x02], zoom=0x40
	je [HERO_ACTION_POS_MASK], 0x84, LABEL_99D4
	break
	add [0x01], 0x0002
	video type=1, offset=CINEMATIC_557, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0001
	mov [0x63], 0x0001
	jmp HERO_WALK_LEFT_LOOP
LABEL_99F5:
	db 0x11

LABEL_99F6:
	call SET_VAR04_TO_0010
	mov [0x2A], 0x0020
	jne [0x0A], 0x00, LABEL_9BA6
	call HANDLE_HORIZ_VAR01_VS_VAR28
	add [0x01], 0x0004
	video type=1, offset=CINEMATIC_561, x=[0x01], y=[0x02], zoom=0x40
	break
	sub [0x01], 0x0001
	video type=1, offset=CINEMATIC_561, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0001

LABEL_9A1D:
	break
	video type=1, offset=CINEMATIC_561, x=[0x01], y=[0x02], zoom=0x40
	je [HERO_ACTION_POS_MASK], 0x84, LABEL_9A1D
	break
	sub [0x01], 0x0002
	video type=1, offset=CINEMATIC_562, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0001
	mov [0x63], 0x0002
	jmp HERO_WALK_RIGHT_LOOP
LABEL_9A3E:
	db 0x11

LABEL_9A3F:
	sub [0x01], 0x0004
	video type=1, offset=CINEMATIC_187, x=[0x01], y=[0x02], zoom=0x40
	break
	add [0x01], 0x0001
	video type=1, offset=CINEMATIC_222, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0001

LABEL_9A56:
	break
	video type=1, offset=CINEMATIC_222, x=[0x01], y=[0x02], zoom=0x40
	je [HERO_ACTION_POS_MASK], 0x84, LABEL_9A56
	add [0x01], 0x0002
	break
	video type=1, offset=CINEMATIC_223, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0002
	je [HERO_POS_JUMP_DOWN], 0x01, LABEL_9B78
	mov [0x63], 0x0001
	jmp HERO_WALK_LEFT_LOOP

LABEL_9A7D:
	add [0x01], 0x0004
	video type=1, offset=CINEMATIC_212, x=[0x01], y=[0x02], zoom=0x40
	break
	sub [0x01], 0x0001
	video type=1, offset=CINEMATIC_213, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0001

LABEL_9A94:
	break
	video type=1, offset=CINEMATIC_213, x=[0x01], y=[0x02], zoom=0x40
	je [HERO_ACTION_POS_MASK], 0x84, LABEL_9A94
	sub [0x01], 0x0002
	break
	video type=1, offset=CINEMATIC_214, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0002
	je [HERO_POS_JUMP_DOWN], 0x01, LABEL_9C5F
	mov [0x63], 0x0002
	jmp HERO_WALK_RIGHT_LOOP

LABEL_9ABB:
	jne [0x0F], 0x00, LABEL_9AF7
	sub [0x01], 0x0003
	call HANDLE_HORIZ_VAR01_VS_VAR28
	video type=1, offset=CINEMATIC_189, x=[0x01], y=[0x02], zoom=0x40
	mov [0x21], [0x01]
	mov [0x27], [0x02]
	sub [0x21], 0x001E
	sub [0x27], 0x0016
	call LABEL_3889
	break
	add [0x01], 0x0002
	video type=1, offset=CINEMATIC_188, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0001
	jne [HERO_ACTION_POS_MASK], 0x84, LABEL_9B1E
	setup channel=0x17, address=LABEL_45A9
