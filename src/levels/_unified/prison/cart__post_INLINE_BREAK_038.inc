LABEL_9BE2:
	call LABEL_6C3D
	je [HERO_ACTION_POS_MASK], 0x84, INLINE_BREAK_035
	jmp LABEL_9C05
LABEL_9BEE:
	db 0x11

LABEL_9BEF:
	mov [0x2A], 0x0021
	call HANDLE_HORIZ_VAR01_VS_VAR28
	sub [0x01], 0x0002
	video offset=CINEMATIC_212, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_209, x=[0x01], y=[0x02], zoom=0x40

LABEL_9C05:
	break
	jne [HACK_VAR_67], 0x23, LABEL_9C1E
	jg [0x01], 0xC8, LABEL_9C1E
	jl [0x02], 0x64, LABEL_9C1E
	je [HERO_ACTION_POS_MASK], 0x05, LABEL_8D54

LABEL_9C1E:
	je [HERO_ACTION_POS_MASK], 0x84, LABEL_9BA6
	je [HERO_ACTION_POS_MASK], 0x85, LABEL_9BA6
	call LABEL_6C3D
	je [HERO_POS_JUMP_DOWN], 0x01, LABEL_9C05
	break
	add [0x01], 0x0002
	video offset=CINEMATIC_211, x=[0x01], y=[0x02], zoom=0x40
	mov [0x63], 0x0002
	mov [0x0A], 0x0003
	jmp HERO_WALK_RIGHT_LOOP
LABEL_9C48:
	db 0x11

LABEL_9C49:
	mov [0x63], 0x0064
	call SET_VAR04_TO_0010
	jne [0x0A], 0x00, LABEL_9BEF
	sub [0x01], 0x0002
	video offset=CINEMATIC_212, x=[0x01], y=[0x02], zoom=0x40

LABEL_9C5F:
	break
	je [HERO_ACTION_POS_MASK], 0x84, LABEL_9A7D
	video offset=CINEMATIC_215, x=[0x01], y=[0x02], zoom=0x40
	je [HERO_ACTION_POS_MASK], 0x04, LABEL_9C5F
	break
	video offset=CINEMATIC_212, x=[0x01], y=[0x02], zoom=0x40
	break
	add [0x01], 0x0002
	video offset=CINEMATIC_211, x=[0x01], y=[0x02], zoom=0x40
	mov [0x63], 0x0002
	sub [0x01], 0x0002
	jmp HERO_WALK_RIGHT_LOOP
LABEL_9C8C:
	db 0x11, 0x54, 0x01, 0xC0, 0x01, 0x02, 0x11, 0x54
	db 0x02, 0x9E, 0x01, 0x02, 0x11, 0x0A, 0xFF, 0xFF
	FILL(25444, 0xFF)
