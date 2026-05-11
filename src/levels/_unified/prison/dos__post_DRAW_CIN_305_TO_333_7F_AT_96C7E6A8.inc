LABEL_4ACC:
	mov [0x65], 0x0000
	call PRISON_SCENE_INIT_DRAW_CIN_085_086_TO_PAGE_3
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

LABEL_4AF5:
	call PRISON_SCENE_INIT_DRAW_CIN_085_086_TO_PAGE_3
	selectVideoPage 0x00
	copyVideoPage src=0x03, dst=0x00
	video offset=CINEMATIC_448, x=160, y=100
	video offset=CINEMATIC_449, x=160, y=100
	video offset=CINEMATIC_450, x=160, y=100
	video offset=CINEMATIC_451, x=160, y=100
	ret

LABEL_4B0E:
	mov [0x65], 0x0000
	call PRISON_SCENE_INIT_DRAW_CIN_085_086_TO_PAGE_3
	selectVideoPage 0x00
	copyVideoPage src=0x03, dst=0x00
	video offset=CINEMATIC_434, x=160, y=100
	video offset=CINEMATIC_435, x=160, y=100
	video offset=CINEMATIC_436, x=160, y=100
	video offset=CINEMATIC_437, x=160, y=100
	ret

; Single-shot draw helper that copies page 0x03 onto page 0
; (FG), then draws CINEMATIC_ENERGY_TRANSMISSION_LINE
; (renamed in 2d4db26) at (160, 100). Used during the
; sequence where Lester must shoot the energy line to power
; down the upstairs security doors.
DRAW_ENERGY_TRANSMISSION_LINE_FG:
	call PRISON_SCENE_INIT_DRAW_CIN_085_086_TO_PAGE_3
	selectVideoPage 0x00
	copyVideoPage src=0x03, dst=0x00
	video offset=CINEMATIC_ENERGY_TRANSMISSION_LINE, x=160, y=100
	ret
