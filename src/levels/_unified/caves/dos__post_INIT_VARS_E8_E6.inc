LABEL_2265:
	add [0xE6], 0x0004
	mov [0xF8], [0xE6]
	shr [0xF8], 0x0004
	add [0xF8], [0xE7]
	video offset=CINEMATIC_904, x=[0xe6], y=[0xf8]
	djnz [0xE8], LABEL_2265
	add [0xE7], 0x0004
	djnz [0xE9], INIT_VARS_E8_E6
	ret
LABEL_2285:
	db 0x11

HANG_DRAW_CIN_351:
	video offset=CINEMATIC_351, x=160, y=100
	break
	jmp HANG_DRAW_CIN_351
LABEL_228E:
	db 0x11

HANG_DRAW_CIN_352:
	video offset=CINEMATIC_352, x=160, y=100
	break
	jmp HANG_DRAW_CIN_352
LABEL_2297:
	db 0x11

LABEL_2298:
	break
	break
	break
	break
	video offset=CINEMATIC_360, x=65522, y=182
	break
	video offset=CINEMATIC_360, x=65530, y=188
	break
	video offset=CINEMATIC_360, x=2, y=194
	break
	video offset=CINEMATIC_360, x=6, y=198
	break
	video offset=CINEMATIC_360, x=13, y=203, zoom=0x40
	break
	video offset=CINEMATIC_360, x=18, y=206, zoom=0x40
	killChannel

LABEL_22C0:
	mov [0xE6], 0x000A
	mov [0xF8], [0xB2]
	and [0xF8], 0x0040
	jne [0xF8], 0x00, INIT_VARS_E6_68_69_6B
	or [0xB2], 0x0040

DELAY_LOOP_VARE6_AT_22D5:
	break
	djnz [0xE6], DELAY_LOOP_VARE6_AT_22D5
	video offset=CINEMATIC_338, x=15, y=178
	break
	video offset=CINEMATIC_338, x=30, y=185
	break
	play id=0x0060, freq=0x05, vol=0x40, channel=0x03
	mov [0x6B], 0x0200
	mov [0x68], 0x002A
	video offset=CINEMATIC_339, x=[0x68], y=184
	break
	add [0x68], 0x000B
	video offset=CINEMATIC_339, x=[0x68], y=184
	break
	add [0x68], 0x0008
	video offset=CINEMATIC_339, x=[0x68], y=184
	break
	add [0x68], 0x0006
	video offset=CINEMATIC_339, x=[0x68], y=184
	break
	add [0x68], 0x0004
	video offset=CINEMATIC_340, x=[0x68], y=184
	break
	add [0x68], 0x0003
	video offset=CINEMATIC_340, x=[0x68], y=184
	break
	add [0x68], 0x0003
	video offset=CINEMATIC_340, x=[0x68], y=184
	break
	add [0x68], 0x0002
	video offset=CINEMATIC_341, x=[0x68], y=184
	break
	add [0x68], 0x0002
	video offset=CINEMATIC_341, x=[0x68], y=184
	break
	video offset=CINEMATIC_341, x=[0x68], y=184
	add [0x68], 0x0001
	mov [0xE6], 0x0014

LABEL_2355:
	break
	video offset=CINEMATIC_341, x=[0x68], y=184
	djnz [0xE6], LABEL_2355
	break
	video offset=CINEMATIC_342, x=[0x68], y=184
	break
	video offset=CINEMATIC_342, x=[0x68], y=184
	break
	video offset=CINEMATIC_343, x=[0x68], y=184
	break
	video offset=CINEMATIC_343, x=[0x68], y=184
	mov [0x69], 0x00BA
	mov [0xE6], 0x0001

LABEL_237F:
	break
	video offset=CINEMATIC_344, x=[0x68], y=[0x69]
	djnz [0xE6], LABEL_237F
	break
	video offset=CINEMATIC_345, x=[0x68], y=[0x69]
	break
	video offset=CINEMATIC_345, x=[0x68], y=[0x69]
	break
	video offset=CINEMATIC_331, x=[0x68], y=[0x69]
	mov [0xE6], 0x0005

LABEL_239F:
	break
	video offset=CINEMATIC_335, x=[0x68], y=[0x69]
	djnz [0xE6], LABEL_239F
	mov [0xE6], 0x0005

LABEL_23AD:
	break
	video offset=CINEMATIC_344, x=[0x68], y=[0x69]
	djnz [0xE6], LABEL_23AD
	mov [0xE6], 0x0008

LABEL_23BB:
	break
	video offset=CINEMATIC_344, x=[0x68], y=[0x69]
	break
	video offset=CINEMATIC_344, x=[0x68], y=[0x69]
	add [0x68], 0x0003
	break
	video offset=CINEMATIC_346, x=[0x68], y=[0x69]
	break
	video offset=CINEMATIC_346, x=[0x68], y=[0x69]
	add [0x68], 0x0003
	break
	video offset=CINEMATIC_347, x=[0x68], y=[0x69]
	break
	video offset=CINEMATIC_347, x=[0x68], y=[0x69]
	add [0x68], 0x0002
	break
	video offset=CINEMATIC_348, x=[0x68], y=[0x69]
	break
	video offset=CINEMATIC_348, x=[0x68], y=[0x69]
	add [0x68], 0x0003
	break
	video offset=CINEMATIC_349, x=[0x68], y=[0x69]
	break
	video offset=CINEMATIC_349, x=[0x68], y=[0x69]
	add [0x68], 0x0003
	break
	video offset=CINEMATIC_350, x=[0x68], y=[0x69]
	break
	video offset=CINEMATIC_350, x=[0x68], y=[0x69]
	add [0x68], 0x0003
	djnz [0xE6], LABEL_23BB
