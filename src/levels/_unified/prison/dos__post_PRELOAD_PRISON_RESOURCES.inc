JUNK__016F:
	video offset=CINEMATIC_705, x=259, y=103, zoom=0x40
	break
	video offset=CINEMATIC_706, x=259, y=103, zoom=0x40
	break
	video offset=CINEMATIC_707, x=259, y=103, zoom=0x40
	break
	video offset=CINEMATIC_708, x=259, y=103, zoom=0x40
	break
	video offset=CINEMATIC_709, x=259, y=103, zoom=0x40
	break
	jmp JUNK__016F
	killChannel
	mov [0x01], 0x03E8

LABEL_0195:
	video offset=CINEMATIC_704, x=160, y=100
	djnz [0x01], LABEL_0195
	break
	setPalette 0x0C
