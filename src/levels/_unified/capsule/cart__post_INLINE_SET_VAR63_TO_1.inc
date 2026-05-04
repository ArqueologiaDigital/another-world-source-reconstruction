LABEL_B7B8:
	jne [HERO_POS_LEFT_RIGHT], 0x01, LABEL_B7D6
	je [0x63], 0x02, LABEL_B7D6
	setup channel=0x14, address=LABEL_BE04
	je [0x63], 0x06, INLINE_SET_VAR63_TO_2
	setup channel=0x14, address=DRAW_CV352_STEP_RIGHT3
