LABEL_972B:
	call LABEL_6C9D
	je [HERO_ACTION_POS_MASK], 0x84, INLINE_BREAK_035
	jmp LABEL_9752
LABEL_9737:
	db 0x11

LABEL_9738:
	mov [0x2A], 0x0021
	sub [0x01], 0x0001
	call HANDLE_HORIZ_VAR01_VS_VAR28
	add [0x01], 0x0003
	video type=1, offset=CINEMATIC_187, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_188, x=[0x01], y=[0x02], zoom=0x40

LABEL_9752:
	break
	jne [HACK_VAR_67], 0x23, LABEL_975F
	je [HERO_ACTION_POS_MASK], 0x06, LABEL_8C34

LABEL_975F:
	je [HERO_ACTION_POS_MASK], 0x84, LABEL_96EF
	je [HERO_ACTION_POS_MASK], 0x86, LABEL_96EF
	call LABEL_6C9D
	je [HERO_ACTION_POS_MASK], 0x04, LABEL_9752
	break
	sub [0x01], 0x0002
	video type=1, offset=CINEMATIC_205, x=[0x01], y=[0x02], zoom=0x40
	mov [0x63], 0x0001
	mov [0x0A], 0x0003
	jmp HERO_WALK_LEFT_LOOP
LABEL_9789:
	db 0x11

LABEL_978A:
	mov [0x63], 0x0064
	call SET_VAR04_TO_0000
	jne [0x0A], 0x00, LABEL_9738
	add [0x01], 0x0002
	video type=1, offset=CINEMATIC_187, x=[0x01], y=[0x02], zoom=0x40

LABEL_97A0:
	break
	je [HERO_ACTION_POS_MASK], 0x84, DRAW_CIN_187_TO_222_2F_AT_8E66E193
	video type=1, offset=CINEMATIC_224, x=[0x01], y=[0x02], zoom=0x40
	je [HERO_ACTION_POS_MASK], 0x04, LABEL_97A0
	break
	video type=1, offset=CINEMATIC_187, x=[0x01], y=[0x02], zoom=0x40
	break
	sub [0x01], 0x0002
	video type=1, offset=CINEMATIC_205, x=[0x01], y=[0x02], zoom=0x40
	mov [0x63], 0x0001
	add [0x01], 0x0002
	jmp HERO_WALK_LEFT_LOOP
LABEL_97CD:
	db 0x11

LABEL_97CE:
	jne [0x0F], 0x00, LABEL_980A
	add [0x01], 0x0003
	call HANDLE_HORIZ_VAR01_VS_VAR28
	video type=1, offset=CINEMATIC_208, x=[0x01], y=[0x02], zoom=0x40
	mov [0x21], [0x01]
	mov [0x27], [0x02]
	add [0x21], 0x001E
	sub [0x27], 0x0016
	call LABEL_379F
	break
	sub [0x01], 0x0002
	video type=1, offset=CINEMATIC_209, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0001
	jne [HERO_ACTION_POS_MASK], 0x84, LABEL_982D
	setup channel=0x17, address=LABEL_449B
