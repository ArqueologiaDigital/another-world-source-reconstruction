LABEL_958B:
	call LABEL_6AAB
	je [HERO_ACTION_POS_MASK], 0x80, INLINE_BREAK_035
	jmp LABEL_951A
LABEL_9597:
	db 0x11

LABEL_9598:
	call SET_VAR04_TO_0030
	mov [0x2A], 0x0020
	call HANDLE_HORIZ_VAR01_VS_VAR28
	jne [0x0A], 0x00, LABEL_9552
	add [0x01], 0x0004
	video type=1, offset=CINEMATIC_567, x=[0x01], y=[0x02], zoom=0x40
	break
	sub [0x01], 0x0001
	video type=1, offset=CINEMATIC_567, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0001

LABEL_95BF:
	break
	video type=1, offset=CINEMATIC_567, x=[0x01], y=[0x02], zoom=0x40
	je [HERO_ACTION_POS_MASK], 0x88, LABEL_95BF
	break
	sub [0x01], 0x0002
	video type=1, offset=CINEMATIC_562, x=[0x01], y=[0x02], zoom=0x40
	mov [0x63], 0x0002
	sub [0x01], 0x0002
	jmp HERO_WALK_LOOP
LABEL_95E0:
	db 0x11

LABEL_95E1:
	call SET_VAR04_TO_0000
	mov [0x2A], 0x0020
	jne [0x0A], 0x00, LABEL_96EF
	sub [0x01], 0x0004
	call HANDLE_HORIZ_VAR01_VS_VAR28
	video type=1, offset=CINEMATIC_556, x=[0x01], y=[0x02], zoom=0x40
	break
	add [0x01], 0x0001
	video type=1, offset=CINEMATIC_556, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0001

LABEL_9608:
	break
	video type=1, offset=CINEMATIC_556, x=[0x01], y=[0x02], zoom=0x40
	je [HERO_ACTION_POS_MASK], 0x84, LABEL_9608
	break
	add [0x01], 0x0002
	video type=1, offset=CINEMATIC_557, x=[0x01], y=[0x02], zoom=0x40
	add [0x01], 0x0001
	mov [0x63], 0x0001
	jmp HERO_WALK_LEFT_LOOP
LABEL_9629:
	db 0x11

LABEL_962A:
	call SET_VAR04_TO_0010
	mov [0x2A], 0x0020
	jne [0x0A], 0x00, LABEL_97CE
	call HANDLE_HORIZ_VAR01_VS_VAR28
	add [0x01], 0x0004
	video type=1, offset=CINEMATIC_561, x=[0x01], y=[0x02], zoom=0x40
	break
	sub [0x01], 0x0001
	video type=1, offset=CINEMATIC_561, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0001

LABEL_9651:
	break
	video type=1, offset=CINEMATIC_561, x=[0x01], y=[0x02], zoom=0x40
	je [HERO_ACTION_POS_MASK], 0x84, LABEL_9651
	break
	sub [0x01], 0x0002
	video type=1, offset=CINEMATIC_562, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0001
	mov [0x63], 0x0002
	jmp HERO_WALK_LOOP
LABEL_9672:
	db 0x11
