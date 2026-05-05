LABEL_233C:
	break
	sub [0xE6], 0x0004
	jg [0xE6], 0xFFEC, LABEL_233C
	setup channel=0x2C, address=KILL_CHANNEL_LANDING
	killChannel

LABEL_234D:
	video offset=CINEMATIC_360, x=239, y=102
	mov [0xEB], 0x00C8
	mov [0xEC], 0x0061
	mov [0xE9], 0x00EF
	mov [0xEA], 0x0066
	video offset=CINEMATIC_361, x=2, y=103
	video offset=CINEMATIC_360, x=200, y=97
	video offset=CINEMATIC_361, x=171, y=100
	break
	jmp LABEL_234D
	killChannel

HANG_DRAW_CIN_351_AT_2372:
	video offset=CINEMATIC_351, x=[0xe9], y=[0xea], zoom=0x40
	break
	jmp HANG_DRAW_CIN_351_AT_2372

HANG_DRAW_CIN_349_AT_237B:
	video offset=CINEMATIC_349, x=[0xeb], y=[0xec], zoom=0x40
	break
	jmp HANG_DRAW_CIN_349_AT_237B

LABEL_2384:
	video offset=CINEMATIC_431, x=[0xeb], y=[0xec], zoom=0x40
	break

HANG_DRAW_CIN_351_AT_238A:
	video offset=CINEMATIC_351, x=[0xeb], y=[0xec], zoom=0x40
	break
	jmp HANG_DRAW_CIN_351_AT_238A

LABEL_2393:
	video offset=CINEMATIC_351, x=[0xe9], y=[0xea], zoom=0x40
	break
	video offset=CINEMATIC_352, x=[0xe9], y=[0xea], zoom=0x40
	break
	play id=0x0070, freq=0x1E, vol=0x0A, channel=0x01
	video offset=CINEMATIC_353, x=[0xe9], y=[0xea], zoom=0x40
	break
	video offset=CINEMATIC_354, x=[0xe9], y=[0xea], zoom=0x40
	break

HANG_DRAW_CIN_349_AT_23B1:
	video offset=CINEMATIC_349, x=[0xe9], y=[0xea], zoom=0x40
	break
	jmp HANG_DRAW_CIN_349_AT_23B1

LABEL_23BA:
	video offset=CINEMATIC_431, x=[0xe9], y=[0xea], zoom=0x40
	break

HANG_DRAW_CIN_351_AT_23C0:
	video offset=CINEMATIC_351, x=[0xe9], y=[0xea], zoom=0x40
	break
	jmp HANG_DRAW_CIN_351_AT_23C0

LABEL_23C9:
	video offset=CINEMATIC_351, x=[0xeb], y=[0xec], zoom=0x40
	break
	video offset=CINEMATIC_352, x=[0xeb], y=[0xec], zoom=0x40
	break
	video offset=CINEMATIC_353, x=[0xeb], y=[0xec], zoom=0x40
	break
	video offset=CINEMATIC_354, x=[0xeb], y=[0xec], zoom=0x40
	break

HANG_DRAW_CIN_349_AT_23E1:
	video offset=CINEMATIC_349, x=[0xeb], y=[0xec], zoom=0x40
	break
	jmp HANG_DRAW_CIN_349_AT_23E1

HANG_DRAW_CIN_350:
	video offset=CINEMATIC_350, x=[0xeb], y=[0xec], zoom=0x40
	break
	jmp HANG_DRAW_CIN_350

LABEL_23F3:
	video offset=CINEMATIC_358, x=[0xe9], y=[0xea], zoom=0x40
	break

HANG_DRAW_CIN_357:
	video offset=CINEMATIC_357, x=[0xe9], y=[0xea], zoom=0x40
	break
	jmp HANG_DRAW_CIN_357

LABEL_2402:
	video offset=CINEMATIC_355, x=[0xe9], y=[0xea], zoom=0x40
	break
	video offset=CINEMATIC_356, x=[0xe9], y=[0xea], zoom=0x40
	break
	play id=0x008D, freq=0x1E, vol=0x0A, channel=0x02
	video offset=CINEMATIC_357, x=[0xe9], y=[0xea], zoom=0x40
	break
	video offset=CINEMATIC_358, x=[0xe9], y=[0xea], zoom=0x40
	break

HANG_DRAW_CIN_359:
	video offset=CINEMATIC_359, x=[0xe9], y=[0xea], zoom=0x40
	break
	jmp HANG_DRAW_CIN_359
