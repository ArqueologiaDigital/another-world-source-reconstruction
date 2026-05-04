LABEL_8C21:
	jne [HERO_ACTION_POS_MASK], 0x81, LABEL_8C3F
	je [0x63], 0x06, LABEL_8C3F
	setup channel=0x14, address=LABEL_939E
	jne [0x63], 0x01, INLINE_SET_VAR63_TO_6
	setup channel=0x14, address=LABEL_937E
