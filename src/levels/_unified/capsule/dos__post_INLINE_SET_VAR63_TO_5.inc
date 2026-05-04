LABEL_B785:
	jne [HERO_ACTION_POS_MASK], 0x81, LABEL_B7A3
	je [0x63], 0x06, LABEL_B7A3
	setup channel=0x14, address=LABEL_BFCE
	jne [0x63], 0x01, INLINE_SET_VAR63_TO_6
	setup channel=0x14, address=LABEL_BFAE
