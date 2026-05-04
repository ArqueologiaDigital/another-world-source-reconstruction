LABEL_198B:
	call GUARDED_DRAW_CIN_242_243
	break
	djnz [0x29], LABEL_198B
	killChannel
