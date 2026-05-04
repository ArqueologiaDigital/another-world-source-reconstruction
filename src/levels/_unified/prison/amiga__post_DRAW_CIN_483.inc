LABEL_3BFF:
	jge [0x13], 0xC8, LABEL_3D0E
	je [0x13], 0x64, LABEL_3EA5
	je [0x13], 0x65, LABEL_3EC5
	jge [0x13], 0x81, LABEL_3C9C
	jne [0x13], 0x6E, LABEL_3C32
	play id=0x0056, freq=0x14, vol=0x40, channel=0x00
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_452, x=[0x21], y=[0x27], zoom=0x40
	selectVideoPage 0xFF
	video type=1, offset=CINEMATIC_482, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_3C32:
	jne [0x13], 0x6F, LABEL_3C3E
	video type=1, offset=CINEMATIC_481, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_3C3E:
	jne [0x13], 0x70, LABEL_3C4A
	video type=1, offset=CINEMATIC_480, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_3C4A:
	jne [0x13], 0x71, LABEL_3C56
	video type=1, offset=CINEMATIC_479, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_3C56:
	jne [0x13], 0x72, LABEL_3C62
	video type=1, offset=CINEMATIC_478, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_3C62:
	jne [0x13], 0x73, LABEL_3C6E
	video type=1, offset=CINEMATIC_477, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_3C6E:
	jne [0x13], 0x74, LABEL_3C7A
	video type=1, offset=CINEMATIC_476, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_3C7A:
	jne [0x13], 0x75, LABEL_3C86
	video type=1, offset=CINEMATIC_475, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_3C86:
	jne [0x13], 0x76, DRAW_CIN473_AT_X21_Y27_ZOOM_40
	video type=1, offset=CINEMATIC_474, x=[0x21], y=[0x27], zoom=0x40
	ret
