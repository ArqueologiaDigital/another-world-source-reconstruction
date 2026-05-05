DELAY_LOOP_VARF1:
	break
	djnz [0xF1], DELAY_LOOP_VARF1
	and [0x49], 0x7F9F
	killChannel
