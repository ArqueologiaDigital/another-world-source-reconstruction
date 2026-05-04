LABEL_4ACC:
	mov [0x65], 0x0000
	call LABEL_8189
	selectVideoPage 0x00
	copyVideoPage src=0x03, dst=0x00
	video type=1, offset=CINEMATIC_428, x=160, y=100
	video type=1, offset=CINEMATIC_429, x=160, y=100
	video type=1, offset=CINEMATIC_430, x=160, y=100
	video type=1, offset=CINEMATIC_305, x=160, y=100
	video type=1, offset=CINEMATIC_431, x=160, y=100
	video type=1, offset=CINEMATIC_432, x=160, y=100
	video type=1, offset=CINEMATIC_433, x=160, y=100
	ret

LABEL_4AF5:
	call LABEL_8189
	selectVideoPage 0x00
	copyVideoPage src=0x03, dst=0x00
	video type=1, offset=CINEMATIC_448, x=160, y=100
	video type=1, offset=CINEMATIC_449, x=160, y=100
	video type=1, offset=CINEMATIC_450, x=160, y=100
	video type=1, offset=CINEMATIC_451, x=160, y=100
	ret

LABEL_4B0E:
	mov [0x65], 0x0000
	call LABEL_8189
	selectVideoPage 0x00
	copyVideoPage src=0x03, dst=0x00
	video type=1, offset=CINEMATIC_434, x=160, y=100
	video type=1, offset=CINEMATIC_435, x=160, y=100
	video type=1, offset=CINEMATIC_436, x=160, y=100
	video type=1, offset=CINEMATIC_437, x=160, y=100
	ret

LABEL_4B2B:
	call LABEL_8189
	selectVideoPage 0x00
	copyVideoPage src=0x03, dst=0x00
	video type=1, offset=CINEMATIC_458, x=160, y=100
	ret
