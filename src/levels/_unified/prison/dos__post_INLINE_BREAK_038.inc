LABEL_9A64:
	call LABEL_6B3A
	je [HERO_ACTION_POS_MASK], 0x84, INLINE_BREAK_035
	jmp LABEL_9A87
LABEL_9A70:
	db 0x11

LABEL_9A71:
	mov [0x2A], 0x0021
	call HANDLE_HORIZ_VAR01_VS_VAR28
	sub [0x01], 0x0002
	video offset=CINEMATIC_212, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_209, x=[0x01], y=[0x02], zoom=0x40

LABEL_9A87:
	break
	jne [HACK_VAR_67], 0x23, LABEL_9A94
	je [HERO_ACTION_POS_MASK], 0x05, LABEL_8BF6

LABEL_9A94:
	je [HERO_ACTION_POS_MASK], 0x84, LABEL_9A28
	je [HERO_ACTION_POS_MASK], 0x85, LABEL_9A28
	call LABEL_6B3A
	je [HERO_POS_JUMP_DOWN], 0x01, LABEL_9A87
	break
	add [0x01], 0x0002
	video offset=CINEMATIC_211, x=[0x01], y=[0x02], zoom=0x40
	mov [0x63], 0x0002
	mov [0x0A], 0x0003
	jmp HERO_WALK_RIGHT_LOOP
LABEL_9ABE:
	db 0x11

LABEL_9ABF:
	mov [0x63], 0x0064
	call SET_VAR04_TO_0010
	jne [0x0A], 0x00, LABEL_9A71
	sub [0x01], 0x0002
	video offset=CINEMATIC_212, x=[0x01], y=[0x02], zoom=0x40

LABEL_9AD5:
	break
	je [HERO_ACTION_POS_MASK], 0x84, DRAW_CIN_212_TO_213_2F_AT_6B0D0A47
	video offset=CINEMATIC_215, x=[0x01], y=[0x02], zoom=0x40
	je [HERO_ACTION_POS_MASK], 0x04, LABEL_9AD5
	break
	video offset=CINEMATIC_212, x=[0x01], y=[0x02], zoom=0x40
	break
	add [0x01], 0x0002
	video offset=CINEMATIC_211, x=[0x01], y=[0x02], zoom=0x40
	mov [0x63], 0x0002
	sub [0x01], 0x0002
	jmp HERO_WALK_RIGHT_LOOP
LABEL_9B02:
	db 0x11, 0x54, 0x01, 0xC0, 0x01, 0x02, 0x11, 0x54
	db 0x02, 0xB4, 0x01, 0x02, 0x11, 0xFF, 0xFF, 0xFF
	FILL(25838, 0xFF)
