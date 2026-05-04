LABEL_1A27:
	call GUARDED_DRAW_CIN_242_243
	break
	djnz [0x29], LABEL_1A27
	killChannel
