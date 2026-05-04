LABEL_9BE8:
	jg [0x01], [0x50], LABEL_9C25
	jne [0x02], [0x52], LABEL_9C07
	jne [HERO_POS_UP_DOWN], 0xFFFF, LABEL_9C25
	mov [0x32], 0x0001
	setup channel=0x17, address=DRAW_CIN_052_THEN_053_PAIR
	setup channel=0x14, address=LABEL_988A

LABEL_9C07:
	jne [0x02], [0x51], LABEL_9C25
	je [0x32], 0x01, LABEL_9C25
	jne [HERO_POS_UP_DOWN], 0x01, LABEL_9C25
	mov [0x32], 0x0001
	setup channel=0x14, address=LABEL_97EC
	setup channel=0x17, address=DRAW_CIN_052_THEN_053_PAIR

LABEL_9C25:
	sub [0x50], 0x0014
	je [HACK_VAR_67], 0xEE, INLINE_SUB_VAR50_BY_C
	jne [HACK_VAR_67], 0x8E, LABEL_9C39
