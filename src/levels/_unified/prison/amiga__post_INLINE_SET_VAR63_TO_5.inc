LABEL_8A20:
	jne [HERO_ACTION_POS_MASK], 0x81, LABEL_8A3E
	je [0x63], 0x06, LABEL_8A3E
	setup channel=0x14, address=LABEL_9173
	jne [0x63], 0x01, INLINE_SET_VAR63_TO_6
	setup channel=0x14, address=LABEL_9153
