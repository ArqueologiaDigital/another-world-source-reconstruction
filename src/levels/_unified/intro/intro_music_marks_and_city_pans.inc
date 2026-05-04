CINEMATIC_191		EQU 0xE51C
CINEMATIC_192		EQU 0xE6F0

CINEMATIC_183		EQU 0xF1BE
CINEMATIC_184		EQU 0xF1EE
CINEMATIC_185		EQU 0xF26A
CINEMATIC_186		EQU 0xF212
CINEMATIC_187		EQU 0xF228
CINEMATIC_188		EQU 0xF23E
CINEMATIC_189		EQU 0xF254
CINEMATIC_190		EQU 0xF192
CINEMATIC_413		EQU 0x4EE2
CINEMATIC_414		EQU 0xC41A
CINEMATIC_415		EQU 0x4E96
CINEMATIC_416		EQU 0xC3A8
CINEMATIC_417		EQU 0x4CFC
CINEMATIC_429		EQU 0xE356
CINEMATIC_430		EQU 0xE8FC
CINEMATIC_431		EQU 0xFB28
CINEMATIC_432		EQU 0xE214
CINEMATIC_433		EQU 0xE278
CINEMATIC_434		EQU 0xE2E0
CINEMATIC_435		EQU 0xDF46
CINEMATIC_436		EQU 0xDFFE
CINEMATIC_437		EQU 0xE0B0
CINEMATIC_438		EQU 0xE162
CINEMATIC_439		EQU 0xDDB2
CINEMATIC_440		EQU 0xDE4E
CINEMATIC_441		EQU 0xDEBE

WAIT_MUS_MARK_2B_THEN_TEXT:
	setup channel=0x02, address=COPY_BG_PAGE_AND_DISPLAY_TEXT_23
	setup channel=0x3C, address=BLIT_AND_COPY_PAGE_FF_LOOP
	killChannel

INTRO_FILL_AND_DRAW_413_414:
	fill page=0xFF, color=0x02
	video type=1, offset=CINEMATIC_413, x=145, y=117
	video type=1, offset=CINEMATIC_414, x=160, y=100
	video type=1, offset=CINEMATIC_415, x=145, y=108
	video type=1, offset=CINEMATIC_416, x=145, y=108
	video type=1, offset=CINEMATIC_417, x=95, y=100
	copyVideoPage src=0xFF, dst=0x00
	setPalette 0x12
	killChannel

SETUP_CITY_SEQ_CHANNELS:
	setup channel=0x06, address=DRAW_CITY_SEQ_439_440
	setup channel=0x07, address=DRAW_CITY_SEQ_435_436
	setup channel=0x03, address=DRAW_CITY_SEQ_432_433
	setup channel=0x01, address=DRAW_CIN_190_LOOP
	mov [0x03], 0x00C3
	mov [0x04], 0x0064
	mov [0x01], 0x0006

DELAY_6_BEFORE_BLITTER_SETUP:
	break
	djnz [0x01], DELAY_6_BEFORE_BLITTER_SETUP
	setup channel=0x3C, address=BLIT_AND_COPY_PAGE_FF_LOOP
	break
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_183, x=200, y=102
	video type=1, offset=CINEMATIC_184, x=125, y=99
	selectVideoPage 0xFF
	break
	mov [0x01], 0x0007

DELAY_7_BEFORE_BLITTER_SETUP:
	break
	djnz [0x01], DELAY_7_BEFORE_BLITTER_SETUP
	setup channel=0x3C, address=BLIT_AND_COPY_PAGE_FF_LOOP
	break
	setup channel=0x3C, address=BLIT_DISPATCH_HERO_ACTION_ALT
	setup channel=0x03, address=KILL_CHANNEL_ROUTINE
	setup channel=0x06, address=KILL_CHANNEL_ROUTINE
	setup channel=0x07, address=KILL_CHANNEL_ROUTINE
	selectVideoPage 0x00
	mov [PAUSE_SLICES], 0x0001
	mov [0x01], 0x0006

CITY_PAN_X_M2_Y_P1_6X:
	break
	sub [0x03], 0x0002
	add [0x04], 0x0001
	djnz [0x01], CITY_PAN_X_M2_Y_P1_6X
	mov [0x01], 0x0004

CITY_PAN_X_M3_Y_0_4X:
	break
	sub [0x03], 0x0003
	add [0x04], 0x0000
	djnz [0x01], CITY_PAN_X_M3_Y_0_4X
	mov [0x01], 0x000A

CITY_PAN_X_M3_Y_M1_10X:
	break
	sub [0x03], 0x0003
	sub [0x04], 0x0001
	djnz [0x01], CITY_PAN_X_M3_Y_M1_10X
	mov [0x01], 0x0004

CITY_PAN_X_M2_Y_M1_4X:
	break
	sub [0x03], 0x0002
	sub [0x04], 0x0001
	djnz [0x01], CITY_PAN_X_M2_Y_M1_4X
	setup channel=0x3C, address=BLIT_AND_DISPATCH_HERO_ACTION
	break
	setup channel=0x01, address=DRAW_CIN_431_LOOP
	sub [0x03], 0x0001
	sub [0x04], 0x0001
	mov [0x01], 0x0005

CITY_PAN_X_M1_Y_M1_5X:
	break
	sub [0x03], 0x0001
	sub [0x04], 0x0001
	djnz [0x01], CITY_PAN_X_M1_Y_M1_5X
	mov [0x01], 0x0009

DELAY_9_BEFORE_BLITTER_SETUP:
	break
	djnz [0x01], DELAY_9_BEFORE_BLITTER_SETUP
	setup channel=0x3C, address=BLIT_AND_COPY_PAGE_FF_LOOP
	break
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_185, x=131, y=48
	selectVideoPage 0xFF
	play id=0x0005, freq=0x1E, vol=0x3F, channel=0x02
	break
	video type=1, offset=CINEMATIC_186, x=117, y=39
	video type=1, offset=CINEMATIC_187, x=137, y=64
	video type=1, offset=CINEMATIC_188, x=143, y=40
	video type=1, offset=CINEMATIC_189, x=129, y=56
	break
	video type=1, offset=CINEMATIC_189, x=121, y=64
	video type=1, offset=CINEMATIC_188, x=153, y=33
	video type=1, offset=CINEMATIC_187, x=143, y=73
	video type=1, offset=CINEMATIC_186, x=107, y=31
	break
	video type=1, offset=CINEMATIC_186, x=96, y=20
	video type=1, offset=CINEMATIC_187, x=149, y=83
	video type=1, offset=CINEMATIC_188, x=168, y=21
	video type=1, offset=CINEMATIC_189, x=114, y=71
	setup channel=0x06, address=KILL_CHANNEL_ROUTINE
	setup channel=0x07, address=KILL_CHANNEL_ROUTINE
	setup channel=0x03, address=KILL_CHANNEL_ROUTINE
	setup channel=0x01, address=INTRO_FILL_AND_DRAW_CIN_429_430
	setup channel=0x02, address=SETUP_INTRO_CITY_CHANNELS
	setup channel=0x3C, address=BLIT_AND_COPY_PAGE_FF_LOOP
	setup channel=0x05, address=KILL_CHANNEL_ROUTINE
	killChannel

