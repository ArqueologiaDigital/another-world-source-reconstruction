LABEL_8A66:
	db 0x11

LABEL_8A67:
	je [0x63], 0x64, LABEL_8BF1
	jne [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_8AB0
	jne [0x63], 0x05, LABEL_8A85
	setup channel=0x14, address=LABEL_9599
	mov [0x63], 0x0064
	jmp LABEL_8BF1

LABEL_8A85:
	jne [0x63], 0x06, LABEL_8A96
	setup channel=0x14, address=LABEL_96B8
	mov [0x63], 0x0064
	jmp LABEL_8BF1

LABEL_8A96:
	jne [0x63], 0x01, LABEL_8AA3
	setup channel=0x14, address=LABEL_9519
	jmp LABEL_8BF1

LABEL_8AA3:
	jne [0x63], 0x02, LABEL_8AB0
	setup channel=0x14, address=LABEL_9638
	jmp LABEL_8BF1

LABEL_8AB0:
	jge [HERO_ACTION_POS_MASK], 0x80, LABEL_8B43
	jne [HERO_POS_LEFT_RIGHT], 0xFFFF, LABEL_8AD5
	je [0x63], 0x01, LABEL_8AD5
	setup channel=0x14, address=LABEL_8F91
	je [0x63], 0x05, INLINE_SET_VAR63_TO_1
	setup channel=0x14, address=STEP_DRAW_CIN555_LEFT4_RIGHT1
