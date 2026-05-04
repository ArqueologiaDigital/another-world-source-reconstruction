LABEL_247A:
	break
	sub [0xE6], 0x0004
	jg [0xE6], 0xFFEC, LABEL_247A
	setup channel=0x2C, address=KILL_CHANNEL_LANDING
	killChannel

LABEL_248B:
	video type=1, offset=CINEMATIC_361, x=239, y=102
	mov [0xEB], 0x00C8
	mov [0xEC], 0x0061
	mov [0xE9], 0x00EF
	mov [0xEA], 0x0066
	video type=1, offset=CINEMATIC_362, x=2, y=103
	video type=1, offset=CINEMATIC_361, x=200, y=97
	video type=1, offset=CINEMATIC_362, x=171, y=100
	je [0xDB], 0x01, LABEL_24C1
	video type=1, offset=CINEMATIC_363, x=239, y=102
	video type=1, offset=CINEMATIC_364, x=2, y=103
	video type=1, offset=CINEMATIC_363, x=200, y=97
	video type=1, offset=CINEMATIC_364, x=171, y=100

LABEL_24C1:
	break
	jmp LABEL_248B
	killChannel

HANG_DRAW_CIN_352_AT_24C6:
	video type=1, offset=CINEMATIC_352, x=[0xe9], y=[0xea], zoom=0x40
	break
	jmp HANG_DRAW_CIN_352_AT_24C6

HANG_DRAW_CIN_350_AT_24CF:
	video type=1, offset=CINEMATIC_350, x=[0xeb], y=[0xec], zoom=0x40
	break
	jmp HANG_DRAW_CIN_350_AT_24CF

LABEL_24D8:
	video type=1, offset=CINEMATIC_435, x=[0xeb], y=[0xec], zoom=0x40
	break

HANG_DRAW_CIN_352_AT_24DE:
	video type=1, offset=CINEMATIC_352, x=[0xeb], y=[0xec], zoom=0x40
	break
	jmp HANG_DRAW_CIN_352_AT_24DE

LABEL_24E7:
	video type=1, offset=CINEMATIC_352, x=[0xe9], y=[0xea], zoom=0x40
	break
	video type=1, offset=CINEMATIC_353, x=[0xe9], y=[0xea], zoom=0x40
	break
	play id=0x0070, freq=0x1E, vol=0x0A, channel=0x01
	video type=1, offset=CINEMATIC_354, x=[0xe9], y=[0xea], zoom=0x40
	break
	video type=1, offset=CINEMATIC_355, x=[0xe9], y=[0xea], zoom=0x40
	break

HANG_DRAW_CIN_350_AT_2505:
	video type=1, offset=CINEMATIC_350, x=[0xe9], y=[0xea], zoom=0x40
	break
	jmp HANG_DRAW_CIN_350_AT_2505

LABEL_250E:
	video type=1, offset=CINEMATIC_435, x=[0xe9], y=[0xea], zoom=0x40
	break

HANG_DRAW_CIN_352_AT_2514:
	video type=1, offset=CINEMATIC_352, x=[0xe9], y=[0xea], zoom=0x40
	break
	jmp HANG_DRAW_CIN_352_AT_2514

LABEL_251D:
	video type=1, offset=CINEMATIC_352, x=[0xeb], y=[0xec], zoom=0x40
	break
	video type=1, offset=CINEMATIC_353, x=[0xeb], y=[0xec], zoom=0x40
	break
	video type=1, offset=CINEMATIC_354, x=[0xeb], y=[0xec], zoom=0x40
	break
	video type=1, offset=CINEMATIC_355, x=[0xeb], y=[0xec], zoom=0x40
	break

HANG_DRAW_CIN_350_AT_2535:
	video type=1, offset=CINEMATIC_350, x=[0xeb], y=[0xec], zoom=0x40
	break
	jmp HANG_DRAW_CIN_350_AT_2535

HANG_DRAW_CIN_351:
	video type=1, offset=CINEMATIC_351, x=[0xeb], y=[0xec], zoom=0x40
	break
	jmp HANG_DRAW_CIN_351

LABEL_2547:
	video type=1, offset=CINEMATIC_359, x=[0xe9], y=[0xea], zoom=0x40
	break

HANG_DRAW_CIN_358:
	video type=1, offset=CINEMATIC_358, x=[0xe9], y=[0xea], zoom=0x40
	break
	jmp HANG_DRAW_CIN_358

LABEL_2556:
	video type=1, offset=CINEMATIC_356, x=[0xe9], y=[0xea], zoom=0x40
	break
	video type=1, offset=CINEMATIC_357, x=[0xe9], y=[0xea], zoom=0x40
	break
	play id=0x008D, freq=0x1E, vol=0x0A, channel=0x02
	video type=1, offset=CINEMATIC_358, x=[0xe9], y=[0xea], zoom=0x40
	break
	video type=1, offset=CINEMATIC_359, x=[0xe9], y=[0xea], zoom=0x40
	break

HANG_DRAW_CIN_360:
	video type=1, offset=CINEMATIC_360, x=[0xe9], y=[0xea], zoom=0x40
	break
	jmp HANG_DRAW_CIN_360
