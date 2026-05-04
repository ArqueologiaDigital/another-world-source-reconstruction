LABEL_3C43:
	jle [0x13], 0x02, LABEL_3C4F
	video type=1, offset=CINEMATIC_485, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_3C4F:
	jle [0x13], 0x01, DRAW_CIN_483
	video type=1, offset=CINEMATIC_484, x=[0x21], y=[0x27], zoom=0x40
	ret
