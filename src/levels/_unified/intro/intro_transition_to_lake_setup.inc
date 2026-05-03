INTRO_TRANSITION_TO_LAKE_SETUP:
	selectVideoPage 0x03
	fill page=0x03, color=0x01
	video type=1, offset=CINEMATIC_379, x=160, y=100
	video type=1, offset=CINEMATIC_380, x=160, y=100
	video type=1, offset=CINEMATIC_381, x=160, y=100
	selectVideoPage 0xFF
	killChannel

LABEL_0DEB:
	copyVideoPage src=0x03, dst=0x00
	break
	setPalette 0x16
	mov [0x01], 0x0009

LABEL_0DF6:
	break
	djnz [0x01], LABEL_0DF6
	video type=1, offset=CINEMATIC_222, x=160, y=100
	play id=0x002C, freq=0x1E, vol=0x3F, channel=0x03
	break
	video type=1, offset=CINEMATIC_223, x=160, y=100
	break
	video type=1, offset=CINEMATIC_224, x=160, y=100
	play id=0x002C, freq=0x1B, vol=0x39, channel=0x03
	break
	video type=1, offset=CINEMATIC_225, x=160, y=100
	play id=0x002C, freq=0x19, vol=0x32, channel=0x03
	break
	video type=1, offset=CINEMATIC_226, x=160, y=100
	play id=0x000A, freq=0x14, vol=0x28, channel=0x03
	break
	video type=1, offset=CINEMATIC_227, x=160, y=100
	play id=0x000A, freq=0x0F, vol=0x1E, channel=0x03
	break
	video type=1, offset=CINEMATIC_228, x=160, y=100
	play id=0x002C, freq=0x0A, vol=0x1C, channel=0x03
	break
	video type=1, offset=CINEMATIC_229, x=160, y=100
	play id=0x000A, freq=0x1E, vol=0x3F, channel=0x03
	break
	video type=1, offset=CINEMATIC_230, x=160, y=100
	play id=0x000A, freq=0x1E, vol=0x3F, channel=0x03
	break
	mov [0x01], 0x0007

LABEL_0E5C:
	break
	djnz [0x01], LABEL_0E5C
	setPalette 0x15
	video type=1, offset=CINEMATIC_231, x=160, y=100
	play id=0x000A, freq=0x1E, vol=0x3F, channel=0x03
	break
	video type=1, offset=CINEMATIC_232, x=160, y=100
	play id=0x000A, freq=0x1E, vol=0x3F, channel=0x03
	break
	fill page=0xFF, color=0x0F
	play id=0x000A, freq=0x1E, vol=0x3F, channel=0x02
	play id=0x000A, freq=0x0A, vol=0x3F, channel=0x03
	break
	video type=1, offset=CINEMATIC_233, x=160, y=100
	play id=0x000A, freq=0x1E, vol=0x3F, channel=0x03
	break
	video type=1, offset=CINEMATIC_234, x=160, y=100
	play id=0x000A, freq=0x1E, vol=0x3F, channel=0x03
	break
	video type=1, offset=CINEMATIC_235, x=160, y=100
	play id=0x000A, freq=0x05, vol=0x3F, channel=0x02
	break
	video type=1, offset=CINEMATIC_236, x=160, y=100
	play id=0x000F, freq=0x14, vol=0x3F, channel=0x03
	break
	video type=1, offset=CINEMATIC_237, x=160, y=100
	play id=0x000A, freq=0x14, vol=0x32, channel=0x02
	play id=0x000A, freq=0x1E, vol=0x3F, channel=0x03
	break
	video type=1, offset=CINEMATIC_238, x=160, y=100
	play id=0x002C, freq=0x02, vol=0x3F, channel=0x03
	break
	video type=1, offset=CINEMATIC_239, x=160, y=100
	play id=0x002C, freq=0x02, vol=0x3F, channel=0x03
	break
	video type=1, offset=CINEMATIC_240, x=160, y=100
	play id=0x000A, freq=0x14, vol=0x3F, channel=0x03
	break
	video type=1, offset=CINEMATIC_241, x=160, y=100
	play id=0x000A, freq=0x02, vol=0x32, channel=0x03
	break
	video type=1, offset=CINEMATIC_242, x=160, y=100
	play id=0x002C, freq=0x0A, vol=0x3F, channel=0x03
	play id=0x002C, freq=0x02, vol=0x3F, channel=0x02
	break
	video type=1, offset=CINEMATIC_243, x=160, y=100
	play id=0x000A, freq=0x02, vol=0x28, channel=0x03
	break
	video type=1, offset=CINEMATIC_244, x=160, y=100
	play id=0x002C, freq=0x02, vol=0x3F, channel=0x03
	break
	video type=1, offset=CINEMATIC_245, x=160, y=100
	play id=0x000A, freq=0x14, vol=0x32, channel=0x03
	break
	video type=1, offset=CINEMATIC_246, x=160, y=100
	play id=0x002C, freq=0x02, vol=0x32, channel=0x03
	break
	video type=1, offset=CINEMATIC_247, x=160, y=100
	break
	setup channel=0x3C, address=BLIT_AND_COPY_PAGE_FF_LOOP
	play id=0x000E, freq=0x05, vol=0x3F, channel=0x03
	play id=0x000E, freq=0x01, vol=0x3F, channel=0x02
	jmp LABEL_0CBD
LABEL_0F48:
	killChannel

INTRO_FILL_AND_DRAW_CIN_385:
	fill page=0xFF, color=0x04
	video type=1, offset=CINEMATIC_385, x=160, y=100
	copyVideoPage src=0xFF, dst=0x00
	setPalette 0x13
	mov [PAUSE_SLICES], 0x0006
	video type=1, offset=CINEMATIC_386, x=160, y=100
	break
	video type=1, offset=CINEMATIC_387, x=160, y=100
	break
	video type=1, offset=CINEMATIC_388, x=160, y=100
	break
	video type=1, offset=CINEMATIC_389, x=160, y=100
	break
	video type=1, offset=CINEMATIC_390, x=160, y=100
	break
	video type=1, offset=CINEMATIC_391, x=160, y=100
	break
	video type=1, offset=CINEMATIC_392, x=160, y=100
	break
	video type=1, offset=CINEMATIC_393, x=160, y=100
	break
	video type=1, offset=CINEMATIC_394, x=160, y=100
	break
	video type=1, offset=CINEMATIC_395, x=160, y=100
	play id=0x003F, freq=0x14, vol=0x3F, channel=0x03
	break
	mov [PAUSE_SLICES], 0x0004
	video type=1, offset=CINEMATIC_396, x=160, y=100
	break
	video type=1, offset=CINEMATIC_397, x=158, y=96
	break
	video type=1, offset=CINEMATIC_397, x=185, y=114
	break
	video type=1, offset=CINEMATIC_397, x=196, y=123
	break
	video type=1, offset=CINEMATIC_397, x=207, y=125
	break
	video type=1, offset=CINEMATIC_397, x=212, y=132
	break
	video type=1, offset=CINEMATIC_397, x=212, y=135
	setup channel=0x3C, address=BLIT_AND_COPY_PAGE_FF_LOOP
	break
	setPalette 0x14
	mov [PAUSE_SLICES], 0x0009
	fill page=0xFF, color=0x04
	video type=1, offset=CINEMATIC_398, x=160, y=100
	copyVideoPage src=0xFF, dst=0x00
	video type=1, offset=CINEMATIC_399, x=154, y=123
	video type=1, offset=CINEMATIC_400, x=180, y=100
	break
	video type=1, offset=CINEMATIC_401, x=154, y=123
	video type=1, offset=CINEMATIC_402, x=180, y=100
	break
	video type=1, offset=CINEMATIC_403, x=154, y=123
	video type=1, offset=CINEMATIC_404, x=180, y=100
	break
	video type=1, offset=CINEMATIC_405, x=154, y=123
	video type=1, offset=CINEMATIC_406, x=180, y=100
	break
	video type=1, offset=CINEMATIC_407, x=154, y=123
	video type=1, offset=CINEMATIC_408, x=180, y=100
	play id=0x0040, freq=0x14, vol=0x28, channel=0x03
	break
	video type=1, offset=CINEMATIC_409, x=154, y=123
	video type=1, offset=CINEMATIC_410, x=180, y=100
	mov [0x02], 0x0003

LABEL_100D:
	mov [0x01], 0x0002

LABEL_1011:
	break
	video type=1, offset=CINEMATIC_411, x=154, y=123
	video type=1, offset=CINEMATIC_412, x=180, y=100
	je [MUS_MARK], 0x2B, WAIT_MUS_MARK_2B_THEN_TEXT
	djnz [0x01], LABEL_1011
	mov [0x01], 0x0004
	play id=0x0041, freq=0x14, vol=0x3F, channel=0x03

LABEL_102E:
	break
	video type=1, offset=CINEMATIC_418, x=154, y=123
	video type=1, offset=CINEMATIC_412, x=181, y=100
	je [MUS_MARK], 0x2B, WAIT_MUS_MARK_2B_THEN_TEXT
	djnz [0x01], LABEL_102E
	djnz [0x02], LABEL_100D

