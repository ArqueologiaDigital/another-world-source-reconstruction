LABEL_3C61:
	jge [0x13], 0xC8, LABEL_3D70
	je [0x13], 0x64, LABEL_3F07
	je [0x13], 0x65, LABEL_3F27
	jge [0x13], 0x81, LABEL_3CFE
	jne [0x13], 0x6E, LABEL_3C94
	play id=0x0056, freq=0x14, vol=0x40, channel=0x00
	selectVideoPage 0x00
	video offset=CINEMATIC_452, x=[0x21], y=[0x27]
	selectVideoPage 0xFF
	video offset=CINEMATIC_482, x=[0x21], y=[0x27]
	ret

LABEL_3C94:
	jne [0x13], 0x6F, LABEL_3CA0
	video offset=CINEMATIC_481, x=[0x21], y=[0x27]
	ret

LABEL_3CA0:
	jne [0x13], 0x70, LABEL_3CAC
	video offset=CINEMATIC_480, x=[0x21], y=[0x27]
	ret

LABEL_3CAC:
	jne [0x13], 0x71, LABEL_3CB8
	video offset=CINEMATIC_479, x=[0x21], y=[0x27]
	ret

LABEL_3CB8:
	jne [0x13], 0x72, LABEL_3CC4
	video offset=CINEMATIC_478, x=[0x21], y=[0x27]
	ret

LABEL_3CC4:
	jne [0x13], 0x73, LABEL_3CD0
	video offset=CINEMATIC_477, x=[0x21], y=[0x27]
	ret

LABEL_3CD0:
	jne [0x13], 0x74, LABEL_3CDC
	video offset=CINEMATIC_476, x=[0x21], y=[0x27]
	ret

LABEL_3CDC:
	jne [0x13], 0x75, LABEL_3CE8
	video offset=CINEMATIC_475, x=[0x21], y=[0x27]
	ret

LABEL_3CE8:
	jne [0x13], 0x76, DRAW_CIN473_AT_X21_Y27_ZOOM_40
	video offset=CINEMATIC_474, x=[0x21], y=[0x27]
	ret
