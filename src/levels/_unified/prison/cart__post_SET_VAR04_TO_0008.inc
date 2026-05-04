LABEL_8BC4:
	db 0x11

LABEL_8BC5:
	je [0x63], 0x64, LABEL_8D4F
	jne [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_8C0E
	jne [0x63], 0x05, LABEL_8BE3
	setup channel=0x14, address=LABEL_9716
	mov [0x63], 0x0064
	jmp LABEL_8D4F

LABEL_8BE3:
	jne [0x63], 0x06, LABEL_8BF4
	setup channel=0x14, address=LABEL_983B
	mov [0x63], 0x0064
	jmp LABEL_8D4F

LABEL_8BF4:
	jne [0x63], 0x01, LABEL_8C01
	setup channel=0x14, address=LABEL_967F
	jmp LABEL_8D4F

LABEL_8C01:
	jne [0x63], 0x02, LABEL_8C0E
	setup channel=0x14, address=LABEL_97A4
	jmp LABEL_8D4F

LABEL_8C0E:
	jge [HERO_ACTION_POS_MASK], 0x80, LABEL_8CA1
	jne [HERO_POS_LEFT_RIGHT], 0xFFFF, LABEL_8C33
	je [0x63], 0x01, LABEL_8C33
	setup channel=0x14, address=LABEL_90F7
	je [0x63], 0x05, INLINE_SET_VAR63_TO_1
	setup channel=0x14, address=STEP_DRAW_CIN555_LEFT4_RIGHT1
