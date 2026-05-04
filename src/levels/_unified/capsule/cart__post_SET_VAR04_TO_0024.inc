LABEL_B749:
	db 0x11

LABEL_B74A:
	je [0x63], 0x64, LABEL_B8D0
	jne [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_B793
	jne [0x63], 0x05, LABEL_B768
	setup channel=0x14, address=LABEL_C2D4
	mov [0x63], 0x0064
	jmp LABEL_B8D0

LABEL_B768:
	jne [0x63], 0x06, LABEL_B779
	setup channel=0x14, address=LABEL_C448
	mov [0x63], 0x0064
	jmp LABEL_B8D0

LABEL_B779:
	jne [0x63], 0x01, LABEL_B786
	setup channel=0x14, address=LABEL_C20D
	jmp LABEL_B8D0

LABEL_B786:
	jne [0x63], 0x02, LABEL_B793
	setup channel=0x14, address=LABEL_C381
	jmp LABEL_B8D0

LABEL_B793:
	jge [HERO_ACTION_POS_MASK], 0x80, LABEL_B826
	jne [HERO_POS_LEFT_RIGHT], 0xFFFF, LABEL_B7B8
	je [0x63], 0x01, LABEL_B7B8
	setup channel=0x14, address=LABEL_BC70
	je [0x63], 0x05, INLINE_SET_VAR63_TO_1
	setup channel=0x14, address=STEP_DRAW_CV352_LEFT4_RIGHT1
