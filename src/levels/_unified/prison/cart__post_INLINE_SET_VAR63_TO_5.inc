LABEL_8CE4:
	jne [HERO_ACTION_POS_MASK], 0x81, LABEL_8D02
	je [0x63], 0x06, LABEL_8D02
	setup channel=0x14, address=LABEL_9507
	jne [0x63], 0x01, INLINE_SET_VAR63_TO_6
	setup channel=0x14, address=LABEL_94E7
