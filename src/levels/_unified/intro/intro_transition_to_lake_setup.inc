CINEMATIC_222		EQU 0x831A
CINEMATIC_223		EQU 0x833A
CINEMATIC_224		EQU 0x8446
CINEMATIC_225		EQU 0x850E
CINEMATIC_226		EQU 0x85D6
CINEMATIC_227		EQU 0x8686
CINEMATIC_228		EQU 0x871A
CINEMATIC_229		EQU 0x8796
CINEMATIC_230		EQU 0x87D2
CINEMATIC_231		EQU 0x7532
CINEMATIC_232		EQU 0x757E
CINEMATIC_233		EQU 0x766E
CINEMATIC_234		EQU 0x7756
CINEMATIC_235		EQU 0x7866
CINEMATIC_236		EQU 0x7A32
CINEMATIC_237		EQU 0x7BEA
CINEMATIC_238		EQU 0x7D2A
CINEMATIC_239		EQU 0x7E4E
CINEMATIC_240		EQU 0x7F56
CINEMATIC_241		EQU 0x801E
CINEMATIC_242		EQU 0x80E6
CINEMATIC_243		EQU 0x818A
CINEMATIC_244		EQU 0x81EE
CINEMATIC_245		EQU 0x8246
CINEMATIC_246		EQU 0x8296
CINEMATIC_247		EQU 0x82D6
CINEMATIC_379		EQU 0x2BF2
CINEMATIC_380		EQU 0xCB2E
CINEMATIC_381		EQU 0xCB3E
CINEMATIC_385		EQU 0xEA04
CINEMATIC_386		EQU 0x592C
CINEMATIC_387		EQU 0x5938
CINEMATIC_388		EQU 0x5944
CINEMATIC_389		EQU 0x5950
CINEMATIC_390		EQU 0x595C
CINEMATIC_391		EQU 0x5968
CINEMATIC_392		EQU 0x5974
CINEMATIC_393		EQU 0x5980
CINEMATIC_394		EQU 0x598C
CINEMATIC_395		EQU 0x5998
CINEMATIC_396		EQU 0x59A4
CINEMATIC_397		EQU 0x59B0
CINEMATIC_398		EQU 0xEA88
CINEMATIC_399		EQU 0x6B76
CINEMATIC_400		EQU 0x6580
CINEMATIC_401		EQU 0x6CDA
CINEMATIC_402		EQU 0x6462
CINEMATIC_403		EQU 0x6E4A
CINEMATIC_404		EQU 0x6316
CINEMATIC_405		EQU 0x6FBA
CINEMATIC_406		EQU 0x65E4
CINEMATIC_407		EQU 0x712A
CINEMATIC_408		EQU 0x6738
CINEMATIC_409		EQU 0x7282
CINEMATIC_410		EQU 0x689E
CINEMATIC_411		EQU 0x73DA
CINEMATIC_412		EQU 0x69F6
CINEMATIC_418		EQU 0xBA7C

INTRO_TRANSITION_TO_LAKE_SETUP:
	selectVideoPage 0x03
	fill page=0x03, color=0x01
	video offset=CINEMATIC_379, x=160, y=100
	video offset=CINEMATIC_380, x=160, y=100
	video offset=CINEMATIC_381, x=160, y=100
	selectVideoPage 0xFF
	killChannel

PHASE_PAGE3_TO_0_PAL_16:
	copyVideoPage src=0x03, dst=0x00
	break
	setPalette 0x16
	mov [0x01], 0x0009

DELAY_9_BEFORE_CIN_222:
	break
	djnz [0x01], DELAY_9_BEFORE_CIN_222
	video offset=CINEMATIC_222, x=160, y=100
	play id=0x002C, freq=0x1E, vol=0x3F, channel=0x03
	break
	video offset=CINEMATIC_223, x=160, y=100
	break
	video offset=CINEMATIC_224, x=160, y=100
	play id=0x002C, freq=0x1B, vol=0x39, channel=0x03
	break
	video offset=CINEMATIC_225, x=160, y=100
	play id=0x002C, freq=0x19, vol=0x32, channel=0x03
	break
	video offset=CINEMATIC_226, x=160, y=100
	play id=0x000A, freq=0x14, vol=0x28, channel=0x03
	break
	video offset=CINEMATIC_227, x=160, y=100
	play id=0x000A, freq=0x0F, vol=0x1E, channel=0x03
	break
	video offset=CINEMATIC_228, x=160, y=100
	play id=0x002C, freq=0x0A, vol=0x1C, channel=0x03
	break
	video offset=CINEMATIC_229, x=160, y=100
	play id=0x000A, freq=0x1E, vol=0x3F, channel=0x03
	break
	video offset=CINEMATIC_230, x=160, y=100
	play id=0x000A, freq=0x1E, vol=0x3F, channel=0x03
	break
	mov [0x01], 0x0007

DELAY_7_THEN_PAL_15_CIN_231:
	break
	djnz [0x01], DELAY_7_THEN_PAL_15_CIN_231
	setPalette 0x15
	video offset=CINEMATIC_231, x=160, y=100
	play id=0x000A, freq=0x1E, vol=0x3F, channel=0x03
	break
	video offset=CINEMATIC_232, x=160, y=100
	play id=0x000A, freq=0x1E, vol=0x3F, channel=0x03
	break
	fill page=0xFF, color=0x0F
	play id=0x000A, freq=0x1E, vol=0x3F, channel=0x02
	play id=0x000A, freq=0x0A, vol=0x3F, channel=0x03
	break
	video offset=CINEMATIC_233, x=160, y=100
	play id=0x000A, freq=0x1E, vol=0x3F, channel=0x03
	break
	video offset=CINEMATIC_234, x=160, y=100
	play id=0x000A, freq=0x1E, vol=0x3F, channel=0x03
	break
	video offset=CINEMATIC_235, x=160, y=100
	play id=0x000A, freq=0x05, vol=0x3F, channel=0x02
	break
	video offset=CINEMATIC_236, x=160, y=100
	play id=0x000F, freq=0x14, vol=0x3F, channel=0x03
	break
	video offset=CINEMATIC_237, x=160, y=100
	play id=0x000A, freq=0x14, vol=0x32, channel=0x02
	play id=0x000A, freq=0x1E, vol=0x3F, channel=0x03
	break
	video offset=CINEMATIC_238, x=160, y=100
	play id=0x002C, freq=0x02, vol=0x3F, channel=0x03
	break
	video offset=CINEMATIC_239, x=160, y=100
	play id=0x002C, freq=0x02, vol=0x3F, channel=0x03
	break
	video offset=CINEMATIC_240, x=160, y=100
	play id=0x000A, freq=0x14, vol=0x3F, channel=0x03
	break
	video offset=CINEMATIC_241, x=160, y=100
	play id=0x000A, freq=0x02, vol=0x32, channel=0x03
	break
	video offset=CINEMATIC_242, x=160, y=100
	play id=0x002C, freq=0x0A, vol=0x3F, channel=0x03
	play id=0x002C, freq=0x02, vol=0x3F, channel=0x02
	break
	video offset=CINEMATIC_243, x=160, y=100
	play id=0x000A, freq=0x02, vol=0x28, channel=0x03
	break
	video offset=CINEMATIC_244, x=160, y=100
	play id=0x002C, freq=0x02, vol=0x3F, channel=0x03
	break
	video offset=CINEMATIC_245, x=160, y=100
	play id=0x000A, freq=0x14, vol=0x32, channel=0x03
	break
	video offset=CINEMATIC_246, x=160, y=100
	play id=0x002C, freq=0x02, vol=0x32, channel=0x03
	break
	video offset=CINEMATIC_247, x=160, y=100
	break
	setup channel=0x3C, address=BLIT_AND_COPY_PAGE_FF_LOOP
	play id=0x000E, freq=0x05, vol=0x3F, channel=0x03
	play id=0x000E, freq=0x01, vol=0x3F, channel=0x02
	jmp PHASE_PAGE3_DRAW_CIN_172_175
LABEL_0F48:
	killChannel

INTRO_FILL_AND_DRAW_CIN_385:
	fill page=0xFF, color=0x04
	video offset=CINEMATIC_385, x=160, y=100
	copyVideoPage src=0xFF, dst=0x00
	setPalette 0x13
	mov [PAUSE_SLICES], 0x0006
	video offset=CINEMATIC_386, x=160, y=100
	break
	video offset=CINEMATIC_387, x=160, y=100
	break
	video offset=CINEMATIC_388, x=160, y=100
	break
	video offset=CINEMATIC_389, x=160, y=100
	break
	video offset=CINEMATIC_390, x=160, y=100
	break
	video offset=CINEMATIC_391, x=160, y=100
	break
	video offset=CINEMATIC_392, x=160, y=100
	break
	video offset=CINEMATIC_393, x=160, y=100
	break
	video offset=CINEMATIC_394, x=160, y=100
	break
	video offset=CINEMATIC_395, x=160, y=100
	play id=0x003F, freq=0x14, vol=0x3F, channel=0x03
	break
	mov [PAUSE_SLICES], 0x0004
	video offset=CINEMATIC_396, x=160, y=100
	break
	video offset=CINEMATIC_397, x=158, y=96
	break
	video offset=CINEMATIC_397, x=185, y=114
	break
	video offset=CINEMATIC_397, x=196, y=123
	break
	video offset=CINEMATIC_397, x=207, y=125
	break
	video offset=CINEMATIC_397, x=212, y=132
	break
	video offset=CINEMATIC_397, x=212, y=135
	setup channel=0x3C, address=BLIT_AND_COPY_PAGE_FF_LOOP
	break
	setPalette 0x14
	mov [PAUSE_SLICES], 0x0009
	fill page=0xFF, color=0x04
	video offset=CINEMATIC_398, x=160, y=100
	copyVideoPage src=0xFF, dst=0x00
	video offset=CINEMATIC_399, x=154, y=123
	video offset=CINEMATIC_400, x=180, y=100
	break
	video offset=CINEMATIC_401, x=154, y=123
	video offset=CINEMATIC_402, x=180, y=100
	break
	video offset=CINEMATIC_403, x=154, y=123
	video offset=CINEMATIC_404, x=180, y=100
	break
	video offset=CINEMATIC_405, x=154, y=123
	video offset=CINEMATIC_406, x=180, y=100
	break
	video offset=CINEMATIC_407, x=154, y=123
	video offset=CINEMATIC_408, x=180, y=100
	play id=0x0040, freq=0x14, vol=0x28, channel=0x03
	break
	video offset=CINEMATIC_409, x=154, y=123
	video offset=CINEMATIC_410, x=180, y=100
	mov [0x02], 0x0003

CITY_OUTER_3X_LOOP:
	mov [0x01], 0x0002

CITY_DRAW_411_412_LOOP:
	break
	video offset=CINEMATIC_411, x=154, y=123
	video offset=CINEMATIC_412, x=180, y=100
	je [MUS_MARK], 0x2B, WAIT_MUS_MARK_2B_THEN_TEXT
	djnz [0x01], CITY_DRAW_411_412_LOOP
	mov [0x01], 0x0004
	play id=0x0041, freq=0x14, vol=0x3F, channel=0x03

CITY_DRAW_418_412_LOOP:
	break
	video offset=CINEMATIC_418, x=154, y=123
	video offset=CINEMATIC_412, x=181, y=100
	je [MUS_MARK], 0x2B, WAIT_MUS_MARK_2B_THEN_TEXT
	djnz [0x01], CITY_DRAW_418_412_LOOP
	djnz [0x02], CITY_OUTER_3X_LOOP

