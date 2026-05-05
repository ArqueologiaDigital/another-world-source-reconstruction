LABEL_3D5C:
	jge [0x13], 0xC8, LABEL_3E6B
	je [0x13], 0x64, LABEL_3E6D
	je [0x13], 0x65, LABEL_3E8D
	jge [0x13], 0x81, LABEL_3DF9
	jne [0x13], 0x6E, LABEL_3D8F
	play id=0x0056, freq=0x14, vol=0x40, channel=0x00
	selectVideoPage 0x00
	video offset=CINEMATIC_452, x=[0x21], y=[0x27]
	selectVideoPage 0xFF
	video offset=CINEMATIC_498, x=[0x21], y=[0x27]
	ret

LABEL_3D8F:
	jne [0x13], 0x6F, LABEL_3D9B
	video offset=CINEMATIC_497, x=[0x21], y=[0x27]
	ret

LABEL_3D9B:
	jne [0x13], 0x70, LABEL_3DA7
	video offset=CINEMATIC_496, x=[0x21], y=[0x27]
	ret

LABEL_3DA7:
	jne [0x13], 0x71, LABEL_3DB3
	video offset=CINEMATIC_495, x=[0x21], y=[0x27]
	ret

LABEL_3DB3:
	jne [0x13], 0x72, LABEL_3DBF
	video offset=CINEMATIC_494, x=[0x21], y=[0x27]
	ret

LABEL_3DBF:
	jne [0x13], 0x73, LABEL_3DCB
	video offset=CINEMATIC_493, x=[0x21], y=[0x27]
	ret

LABEL_3DCB:
	jne [0x13], 0x74, LABEL_3DD7
	video offset=CINEMATIC_492, x=[0x21], y=[0x27]
	ret

LABEL_3DD7:
	jne [0x13], 0x75, LABEL_3DE3
	video offset=CINEMATIC_491, x=[0x21], y=[0x27]
	ret

LABEL_3DE3:
	jne [0x13], 0x76, DRAW_CIN489_AT_X21_Y27_ZOOM_40
	video offset=CINEMATIC_490, x=[0x21], y=[0x27]
	ret
