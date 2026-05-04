LABEL_980A:
	call LABEL_6A8D
	je [HERO_ACTION_POS_MASK], 0x84, INLINE_BREAK_035
	jmp LABEL_982D
LABEL_9816:
	db 0x11

LABEL_9817:
	mov [0x2A], 0x0021
	call HANDLE_HORIZ_VAR01_VS_VAR28
	sub [0x01], 0x0002
	video type=1, offset=CINEMATIC_212, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_209, x=[0x01], y=[0x02], zoom=0x40

LABEL_982D:
	break
	jne [HACK_VAR_67], 0x23, LABEL_983A
	je [HERO_ACTION_POS_MASK], 0x05, LABEL_8A90

LABEL_983A:
	je [HERO_ACTION_POS_MASK], 0x84, LABEL_97CE
	je [HERO_ACTION_POS_MASK], 0x85, LABEL_97CE
	call LABEL_6A8D
	je [HERO_POS_JUMP_DOWN], 0x01, LABEL_982D
	break
	add [0x01], 0x0002
	video type=1, offset=CINEMATIC_211, x=[0x01], y=[0x02], zoom=0x40
	mov [0x63], 0x0002
	mov [0x0A], 0x0003
	jmp HERO_WALK_LOOP
LABEL_9864:
	db 0x11

LABEL_9865:
	mov [0x63], 0x0064
	call SET_VAR04_TO_0010
	jne [0x0A], 0x00, LABEL_9817
	sub [0x01], 0x0002
	video type=1, offset=CINEMATIC_212, x=[0x01], y=[0x02], zoom=0x40

LABEL_987B:
	break
	je [HERO_ACTION_POS_MASK], 0x84, DRAW_CIN_212_TO_213_2F_AT_6B0D0A47
	video type=1, offset=CINEMATIC_215, x=[0x01], y=[0x02], zoom=0x40
	je [HERO_ACTION_POS_MASK], 0x04, LABEL_987B
	break
	video type=1, offset=CINEMATIC_212, x=[0x01], y=[0x02], zoom=0x40
	break
	add [0x01], 0x0002
	video type=1, offset=CINEMATIC_211, x=[0x01], y=[0x02], zoom=0x40
	mov [0x63], 0x0002
	sub [0x01], 0x0002
	jmp HERO_WALK_LOOP
LABEL_98A8:
	db 0x11, 0x54, 0x01, 0xC0, 0x01, 0x02, 0x11, 0x54
	db 0x02, 0xB4, 0x01, 0x02, 0x11, 0x00, 0xFF, 0xFF
	FILL(26440, 0xFF)
