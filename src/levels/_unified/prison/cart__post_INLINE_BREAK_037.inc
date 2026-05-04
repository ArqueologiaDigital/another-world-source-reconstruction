LABEL_9AF7:
	call LABEL_6E4D
	je [HERO_ACTION_POS_MASK], 0x84, INLINE_BREAK_035
	jmp LABEL_9B1E
LABEL_9B03:
	db 0x11

LABEL_9B04:
	mov [0x2A], 0x0021
	sub [0x01], 0x0001
	call HANDLE_HORIZ_VAR01_VS_VAR28
	add [0x01], 0x0003
	video type=1, offset=CINEMATIC_187, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_188, x=[0x01], y=[0x02], zoom=0x40

LABEL_9B1E:
	break
	jne [HACK_VAR_67], 0x23, LABEL_9B37
	jg [0x01], 0xC8, LABEL_9B37
	jl [0x02], 0x64, LABEL_9B37
	je [HERO_ACTION_POS_MASK], 0x06, LABEL_8EFC

LABEL_9B37:
	je [HERO_ACTION_POS_MASK], 0x84, LABEL_9ABB
	je [HERO_ACTION_POS_MASK], 0x86, LABEL_9ABB
	call LABEL_6E4D
	je [HERO_ACTION_POS_MASK], 0x04, LABEL_9B1E
	break
	sub [0x01], 0x0002
	video type=1, offset=CINEMATIC_205, x=[0x01], y=[0x02], zoom=0x40
	mov [0x63], 0x0001
	mov [0x0A], 0x0003
	jmp HERO_WALK_LEFT_LOOP
LABEL_9B61:
	db 0x11

LABEL_9B62:
	mov [0x63], 0x0064
	call SET_VAR04_TO_0000
	jne [0x0A], 0x00, LABEL_9B04
	add [0x01], 0x0002
	video type=1, offset=CINEMATIC_187, x=[0x01], y=[0x02], zoom=0x40

LABEL_9B78:
	break
	je [HERO_ACTION_POS_MASK], 0x84, LABEL_9A3F
	video type=1, offset=CINEMATIC_224, x=[0x01], y=[0x02], zoom=0x40
	je [HERO_ACTION_POS_MASK], 0x04, LABEL_9B78
	break
	video type=1, offset=CINEMATIC_187, x=[0x01], y=[0x02], zoom=0x40
	break
	sub [0x01], 0x0002
	video type=1, offset=CINEMATIC_205, x=[0x01], y=[0x02], zoom=0x40
	mov [0x63], 0x0001
	add [0x01], 0x0002
	jmp HERO_WALK_LEFT_LOOP
LABEL_9BA5:
	db 0x11

LABEL_9BA6:
	jne [0x0F], 0x00, LABEL_9BE2
	add [0x01], 0x0003
	call HANDLE_HORIZ_VAR01_VS_VAR28
	video type=1, offset=CINEMATIC_208, x=[0x01], y=[0x02], zoom=0x40
	mov [0x21], [0x01]
	mov [0x27], [0x02]
	add [0x21], 0x001E
	sub [0x27], 0x0016
	call LABEL_38F5
	break
	sub [0x01], 0x0002
	video type=1, offset=CINEMATIC_209, x=[0x01], y=[0x02], zoom=0x40
	sub [0x01], 0x0001
	jne [HERO_ACTION_POS_MASK], 0x84, LABEL_9C05
	setup channel=0x17, address=LABEL_4605
