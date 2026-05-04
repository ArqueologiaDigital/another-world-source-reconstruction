LABEL_B665:
	db 0x11

LABEL_B666:
	je [0x63], 0x64, LABEL_B7EC
	jne [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_B6AF
	jne [0x63], 0x05, LABEL_B684
	setup channel=0x14, address=LABEL_C1F0
	mov [0x63], 0x0064
	jmp LABEL_B7EC

LABEL_B684:
	jne [0x63], 0x06, LABEL_B695
	setup channel=0x14, address=LABEL_C364
	mov [0x63], 0x0064
	jmp LABEL_B7EC

LABEL_B695:
	jne [0x63], 0x01, LABEL_B6A2
	setup channel=0x14, address=LABEL_C129
	jmp LABEL_B7EC

LABEL_B6A2:
	jne [0x63], 0x02, LABEL_B6AF
	setup channel=0x14, address=LABEL_C29D
	jmp LABEL_B7EC

LABEL_B6AF:
	jge [HERO_ACTION_POS_MASK], 0x80, LABEL_B742
	jne [HERO_POS_LEFT_RIGHT], 0xFFFF, LABEL_B6D4
	je [0x63], 0x01, LABEL_B6D4
	setup channel=0x14, address=LABEL_BB8C
	je [0x63], 0x05, INLINE_SET_VAR63_TO_1
	setup channel=0x14, address=STEP_DRAW_CV352_LEFT4_RIGHT1
