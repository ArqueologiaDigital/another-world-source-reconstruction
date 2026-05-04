DELAY_LOOP_VARE6:
	break
	djnz [0xE6], DELAY_LOOP_VARE6
	call LABEL_3496
	mov [0xE6], 0x000D

DELAY_LOOP_VARE6_AT_0842:
	break
	djnz [0xE6], DELAY_LOOP_VARE6_AT_0842
	call LABEL_3472
	setup channel=0x38, address=LABEL_2EBF
	mov [0xE6], 0x0014

DELAY_LOOP_VARE6_AT_0852:
	break
	djnz [0xE6], DELAY_LOOP_VARE6_AT_0852
	setup channel=0x01, address=LABEL_3BCA
	killChannel

LABEL_085C:
	je [0xBA], 0x01, INLINE_SET_VARE6_TO_28
	jg [0x01], 0x64, INLINE_SET_VARE6_TO_28
	mov [0xBA], 0x0001
	setup channel=0x37, address=LABEL_21EE
