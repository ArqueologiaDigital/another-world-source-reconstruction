LABEL_E017:
	jne [HERO_ACTION_POS_MASK], 0x81, LABEL_E035
	je [0x63], 0x06, LABEL_E035
	setup channel=0x14, address=LABEL_E794
	jne [0x63], 0x01, INLINE_SET_VAR63_TO_6
	setup channel=0x14, address=LABEL_E774
