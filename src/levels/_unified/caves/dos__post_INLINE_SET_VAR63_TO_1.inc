LABEL_E4F9:
	jne [HERO_POS_LEFT_RIGHT], 0x01, LABEL_E517
	je [0x63], 0x02, LABEL_E517
	setup channel=0x14, address=LABEL_EB39
	je [0x63], 0x06, INLINE_SET_VAR63_TO_2
	setup channel=0x14, address=DRAW_CV352_STEP_RIGHT3
