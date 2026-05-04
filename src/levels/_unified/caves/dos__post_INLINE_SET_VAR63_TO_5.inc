LABEL_E5AA:
	jne [HERO_ACTION_POS_MASK], 0x81, LABEL_E5C8
	je [0x63], 0x06, LABEL_E5C8
	setup channel=0x14, address=LABEL_EDED
	jne [0x63], 0x01, INLINE_SET_VAR63_TO_6
	setup channel=0x14, address=LABEL_EDCD
