LABEL_3D3E:
	jle [0x13], 0x02, LABEL_3D4A
	video type=1, offset=CINEMATIC_501, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_3D4A:
	jle [0x13], 0x01, DRAW_CIN_499
	video type=1, offset=CINEMATIC_500, x=[0x21], y=[0x27], zoom=0x40
	ret
