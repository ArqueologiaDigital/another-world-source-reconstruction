LABEL_4A2B:
	mov [0x65], 0x0000
	call LABEL_80AA
	selectVideoPage 0x00
	copyVideoPage src=0x03, dst=0x00
	video offset=CINEMATIC_428, x=160, y=100
	video offset=CINEMATIC_429, x=160, y=100
	video offset=CINEMATIC_430, x=160, y=100
	video offset=CINEMATIC_305, x=160, y=100
	video offset=CINEMATIC_431, x=160, y=100
	video offset=CINEMATIC_432, x=160, y=100
	video offset=CINEMATIC_433, x=160, y=100
	ret

LABEL_4A54:
	call LABEL_80AA
	selectVideoPage 0x00
	copyVideoPage src=0x03, dst=0x00
	video offset=CINEMATIC_448, x=160, y=100
	video offset=CINEMATIC_449, x=160, y=100
	video offset=CINEMATIC_450, x=160, y=100
	video offset=CINEMATIC_451, x=160, y=100
	ret

LABEL_4A6D:
	mov [0x65], 0x0000
	call LABEL_80AA
	selectVideoPage 0x00
	copyVideoPage src=0x03, dst=0x00
	video offset=CINEMATIC_434, x=160, y=100
	video offset=CINEMATIC_435, x=160, y=100
	video offset=CINEMATIC_436, x=160, y=100
	video offset=CINEMATIC_437, x=160, y=100
	ret

LABEL_4A8A:
	call LABEL_80AA
	selectVideoPage 0x00
	copyVideoPage src=0x03, dst=0x00
	video offset=CINEMATIC_458, x=160, y=100
	ret
