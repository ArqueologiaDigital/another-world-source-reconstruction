LABEL_97E5:
	call LABEL_6B58
	je [HERO_ACTION_POS_MASK], 0x80, INLINE_BREAK_035
	jmp LABEL_9774
LABEL_97F1:
	db 0x11

LABEL_97F2:
	call SET_VAR04_TO_0030
	mov [0x2A], 0x0020
	call HANDLE_HORIZ_VAR01_VS_VAR28
	jne [0x0A], 0x00, LABEL_97AC
	add [HERO_X], 0x0004
	video offset=CINEMATIC_567, x=[HERO_X], y=[HERO_Y]
	break
	sub [HERO_X], 0x0001
	video offset=CINEMATIC_567, x=[HERO_X], y=[HERO_Y]
	sub [HERO_X], 0x0001

LABEL_9819:
	break
	video offset=CINEMATIC_567, x=[HERO_X], y=[HERO_Y]
	je [HERO_ACTION_POS_MASK], 0x88, LABEL_9819
	break
	sub [HERO_X], 0x0002
	video offset=CINEMATIC_562, x=[HERO_X], y=[HERO_Y]
	mov [0x63], 0x0002
	sub [HERO_X], 0x0002
	jmp HERO_WALK_RIGHT_LOOP
LABEL_983A:
	db 0x11

LABEL_983B:
	call SET_VAR04_TO_0000
	mov [0x2A], 0x0020
	jne [0x0A], 0x00, LABEL_9949
	sub [HERO_X], 0x0004
	call HANDLE_HORIZ_VAR01_VS_VAR28
	video offset=CINEMATIC_556, x=[HERO_X], y=[HERO_Y]
	break
	add [HERO_X], 0x0001
	video offset=CINEMATIC_556, x=[HERO_X], y=[HERO_Y]
	add [HERO_X], 0x0001

LABEL_9862:
	break
	video offset=CINEMATIC_556, x=[HERO_X], y=[HERO_Y]
	je [HERO_ACTION_POS_MASK], 0x84, LABEL_9862
	break
	add [HERO_X], 0x0002
	video offset=CINEMATIC_557, x=[HERO_X], y=[HERO_Y]
	add [HERO_X], 0x0001
	mov [0x63], 0x0001
	jmp HERO_WALK_LEFT_LOOP
LABEL_9883:
	db 0x11

LABEL_9884:
	call SET_VAR04_TO_0010
	mov [0x2A], 0x0020
	jne [0x0A], 0x00, LABEL_9A28
	call HANDLE_HORIZ_VAR01_VS_VAR28
	add [HERO_X], 0x0004
	video offset=CINEMATIC_561, x=[HERO_X], y=[HERO_Y]
	break
	sub [HERO_X], 0x0001
	video offset=CINEMATIC_561, x=[HERO_X], y=[HERO_Y]
	sub [HERO_X], 0x0001

LABEL_98AB:
	break
	video offset=CINEMATIC_561, x=[HERO_X], y=[HERO_Y]
	je [HERO_ACTION_POS_MASK], 0x84, LABEL_98AB
	break
	sub [HERO_X], 0x0002
	video offset=CINEMATIC_562, x=[HERO_X], y=[HERO_Y]
	sub [HERO_X], 0x0001
	mov [0x63], 0x0002
	jmp HERO_WALK_RIGHT_LOOP
LABEL_98CC:
	db 0x11
