LABEL_9985:
	call LABEL_6D4A
	je [HERO_ACTION_POS_MASK], 0x84, INLINE_BREAK_035
	jmp LABEL_99AC
LABEL_9991:
	db 0x11

LABEL_9992:
	mov [0x2A], 0x0021
	sub [0x01], 0x0001
	call HANDLE_HORIZ_VAR01_VS_VAR28
	add [0x01], 0x0003
	video offset=CINEMATIC_187, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_188, x=[0x01], y=[0x02], zoom=0x40

LABEL_99AC:
	break
	jne [HACK_VAR_67], 0x23, LABEL_99B9
	je [HERO_ACTION_POS_MASK], 0x06, LABEL_8D9A

LABEL_99B9:
	je [HERO_ACTION_POS_MASK], 0x84, LABEL_9949
	je [HERO_ACTION_POS_MASK], 0x86, LABEL_9949
	call LABEL_6D4A
	je [HERO_ACTION_POS_MASK], 0x04, LABEL_99AC
	break
	sub [0x01], 0x0002
	video offset=CINEMATIC_205, x=[0x01], y=[0x02], zoom=0x40
	mov [0x63], 0x0001
	mov [0x0A], 0x0003
	jmp HERO_WALK_LEFT_LOOP
LABEL_99E3:
	db 0x11

LABEL_99E4:
	mov [0x63], 0x0064
	call SET_VAR04_TO_0000
	jne [0x0A], 0x00, LABEL_9992
	add [0x01], 0x0002
	video offset=CINEMATIC_187, x=[0x01], y=[0x02], zoom=0x40

LABEL_99FA:
	break
	je [HERO_ACTION_POS_MASK], 0x84, DRAW_CIN_187_TO_222_2F_AT_8E66E193
	video offset=CINEMATIC_224, x=[0x01], y=[0x02], zoom=0x40
	je [HERO_ACTION_POS_MASK], 0x04, LABEL_99FA
	break
	video offset=CINEMATIC_187, x=[0x01], y=[0x02], zoom=0x40
	break
	sub [0x01], 0x0002
	video offset=CINEMATIC_205, x=[0x01], y=[0x02], zoom=0x40
	mov [0x63], 0x0001
	add [0x01], 0x0002
	jmp HERO_WALK_LEFT_LOOP
LABEL_9A27:
	db 0x11

LABEL_9A28:
	jne [0x0F], 0x00, LABEL_9A64
	add [0x01], 0x0003
	call HANDLE_HORIZ_VAR01_VS_VAR28
	video offset=CINEMATIC_208, x=[0x01], y=[0x02], zoom=0x40
	mov [0x21], [0x01]
	mov [0x27], [0x02]
	add [0x21], 0x001E
	sub [0x27], 0x0016
	call LABEL_3801
	break
	sub [0x01], 0x0002
	video offset=CINEMATIC_209, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0001
	jne [HERO_ACTION_POS_MASK], 0x84, LABEL_9A87
	setup channel=0x17, address=LABEL_450B
