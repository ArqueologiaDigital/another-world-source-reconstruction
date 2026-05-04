LABEL_3DBE:
	jge [0x13], 0xC8, LABEL_3ECD
	je [0x13], 0x64, LABEL_3ECF
	je [0x13], 0x65, LABEL_3EEF
	jge [0x13], 0x81, LABEL_3E5B
	jne [0x13], 0x6E, LABEL_3DF1
	play id=0x0056, freq=0x14, vol=0x40, channel=0x00
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_452, x=[0x21], y=[0x27], zoom=0x40
	selectVideoPage 0xFF
	video type=1, offset=CINEMATIC_498, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_3DF1:
	jne [0x13], 0x6F, LABEL_3DFD
	video type=1, offset=CINEMATIC_497, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_3DFD:
	jne [0x13], 0x70, LABEL_3E09
	video type=1, offset=CINEMATIC_496, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_3E09:
	jne [0x13], 0x71, LABEL_3E15
	video type=1, offset=CINEMATIC_495, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_3E15:
	jne [0x13], 0x72, LABEL_3E21
	video type=1, offset=CINEMATIC_494, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_3E21:
	jne [0x13], 0x73, LABEL_3E2D
	video type=1, offset=CINEMATIC_493, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_3E2D:
	jne [0x13], 0x74, LABEL_3E39
	video type=1, offset=CINEMATIC_492, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_3E39:
	jne [0x13], 0x75, LABEL_3E45
	video type=1, offset=CINEMATIC_491, x=[0x21], y=[0x27], zoom=0x40
	ret

LABEL_3E45:
	jne [0x13], 0x76, DRAW_CIN489_AT_X21_Y27_ZOOM_40
	video type=1, offset=CINEMATIC_490, x=[0x21], y=[0x27], zoom=0x40
	ret
