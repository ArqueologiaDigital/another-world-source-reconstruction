LABEL_B869:
	jne [HERO_ACTION_POS_MASK], 0x81, LABEL_B887
	je [0x63], 0x06, LABEL_B887
	setup channel=0x14, address=LABEL_C0B2
	jne [0x63], 0x01, INLINE_SET_VAR63_TO_6
	setup channel=0x14, address=LABEL_C092
