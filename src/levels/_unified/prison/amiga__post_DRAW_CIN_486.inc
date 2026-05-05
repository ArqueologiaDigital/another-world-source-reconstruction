LABEL_3BE1:
	jle [0x13], 0x02, LABEL_3BED
	video offset=CINEMATIC_485, x=[0x21], y=[0x27]
	ret

LABEL_3BED:
	jle [0x13], 0x01, DRAW_CIN_483
	video offset=CINEMATIC_484, x=[0x21], y=[0x27]
	ret
