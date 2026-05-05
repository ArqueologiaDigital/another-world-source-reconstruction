DRAW_INTRO_DECOR_318:
	break
	video offset=CINEMATIC_318, x=176, y=157
	break
	video offset=CINEMATIC_319, x=176, y=157
	break
	video offset=CINEMATIC_320, x=175, y=159
	break
	video offset=CINEMATIC_321, x=175, y=156
	break
	video offset=CINEMATIC_320, x=176, y=159
	break
	video offset=CINEMATIC_319, x=175, y=157
	break
	video offset=CINEMATIC_318, x=176, y=157
	mov [0x0E], 0x0007

DELAY_7_BEFORE_CIN_322:
	break
	djnz [0x0E], DELAY_7_BEFORE_CIN_322
	video offset=CINEMATIC_322, x=149, y=158
	break
	video offset=CINEMATIC_323, x=150, y=159
	break
	video offset=CINEMATIC_324, x=150, y=160
	break
	video offset=CINEMATIC_323, x=151, y=160
	mov [0x0E], 0x0005

DELAY_5_BEFORE_CIN_325:
	break
	djnz [0x0E], DELAY_5_BEFORE_CIN_325
	video offset=CINEMATIC_325, x=134, y=166
	break
	video offset=CINEMATIC_326, x=134, y=170
	break
	video offset=CINEMATIC_327, x=134, y=169
	break
	video offset=CINEMATIC_328, x=134, y=169
	jmp DRAW_INTRO_DECOR_318
LABEL_0BDE:
	killChannel

INIT_VAR_0D_THEN_LOOP:
	break
	mov [0x0D], 0x0014

DELAY_20_BEFORE_PLAY_2C_CIN_309:
	break
	djnz [0x0D], DELAY_20_BEFORE_PLAY_2C_CIN_309
	play id=0x002C, freq=0x08, vol=0x20, channel=0x01
	video offset=CINEMATIC_309, x=198, y=136
	break
	video offset=CINEMATIC_310, x=198, y=136
	break
	video offset=CINEMATIC_311, x=198, y=135
	break
	video offset=CINEMATIC_312, x=199, y=138
	break
	video offset=CINEMATIC_313, x=197, y=139
	break
	video offset=CINEMATIC_314, x=205, y=144
	break
	video offset=CINEMATIC_315, x=249, y=149
	break
	video offset=CINEMATIC_316, x=252, y=150
	break
	video offset=CINEMATIC_317, x=254, y=145
	killChannel

DRAW_INTRO_DECOR_305:
	break
	video offset=CINEMATIC_305, x=229, y=40
	break
	video offset=CINEMATIC_306, x=229, y=40
	break
	video offset=CINEMATIC_307, x=229, y=40
	break
	video offset=CINEMATIC_308, x=229, y=40
	break
	play id=0x002C, freq=0x19, vol=0x0A, channel=0x01
	video offset=CINEMATIC_307, x=229, y=40
	break
	video offset=CINEMATIC_306, x=229, y=40
	break
	video offset=CINEMATIC_305, x=229, y=40
	mov [0x0F], 0x0016

DELAY_22_BEFORE_DECOR_305:
	break
	djnz [0x0F], DELAY_22_BEFORE_DECOR_305
	jmp DRAW_INTRO_DECOR_305
LABEL_0C51:
	killChannel

DRAW_INTRO_DECOR_301:
	break
	video offset=CINEMATIC_301, x=194, y=29
	break
	video offset=CINEMATIC_302, x=196, y=29
	break
	video offset=CINEMATIC_303, x=197, y=29
	break
	video offset=CINEMATIC_304, x=197, y=29
	play id=0x000E, freq=0x1B, vol=0x0F, channel=0x00
	break
	video offset=CINEMATIC_303, x=197, y=29
	break
	video offset=CINEMATIC_302, x=196, y=29
	break
	video offset=CINEMATIC_301, x=194, y=29
	mov [0x10], 0x0019

DELAY_25_BEFORE_DECOR_301:
	break
	djnz [0x10], DELAY_25_BEFORE_DECOR_301
	jmp DRAW_INTRO_DECOR_301
LABEL_0C87:
	killChannel

SET_PALETTE_18:
	setPalette 0x18
	break
	break
	break
	setPalette 0x1A
	break
	jmp SET_PALETTE_18
LABEL_0C95:
	killChannel

SET_PALETTE_17_INIT_VAR_14:
	setPalette 0x17
	mov [0x14], 0x001E

DELAY_30_THEN_SET_PAL_18:
	break
	djnz [0x14], DELAY_30_THEN_SET_PAL_18
	setPalette 0x18
	break
	setPalette 0x1A
	break
	setPalette 0x18
	break
	setPalette 0x17
	break
	break
	break
	break
	setPalette 0x18
	break
	jmp SET_PALETTE_17_INIT_VAR_14
LABEL_0CBC:
	killChannel

PHASE_PAGE3_DRAW_CIN_172_175:
	break
	selectVideoPage 0x03
	fill page=0x03, color=0x02
	call DRAW_CINEMATICS_172_TO_175
	video offset=CINEMATIC_248, x=160, y=101
	video offset=CINEMATIC_182, x=187, y=101
	selectVideoPage 0xFF
	fill page=0xFF, color=0x02
	video offset=CINEMATIC_249, x=160, y=100
	video offset=CINEMATIC_250, x=160, y=100
	video offset=CINEMATIC_251, x=160, y=100
	copyVideoPage src=0xFF, dst=0x00
	setPalette 0x16
	break
	video offset=CINEMATIC_252, x=160, y=100
	play id=0x002C, freq=0x14, vol=0x3F, channel=0x03
	break
	video offset=CINEMATIC_253, x=160, y=100
	play id=0x000A, freq=0x14, vol=0x3F, channel=0x03
	break
	video offset=CINEMATIC_254, x=160, y=100
	play id=0x002C, freq=0x14, vol=0x3F, channel=0x03
	break
	video offset=CINEMATIC_255, x=160, y=100
	play id=0x000A, freq=0x14, vol=0x3F, channel=0x03
	break
	video offset=CINEMATIC_256, x=160, y=100
	play id=0x002C, freq=0x14, vol=0x3F, channel=0x03
	break
	video offset=CINEMATIC_257, x=160, y=100
	play id=0x000A, freq=0x14, vol=0x3F, channel=0x03
	break
	video offset=CINEMATIC_258, x=160, y=100
	play id=0x002C, freq=0x14, vol=0x3F, channel=0x03
	break
	video offset=CINEMATIC_259, x=160, y=100
	play id=0x002C, freq=0x0A, vol=0x3F, channel=0x03
	break
	video offset=CINEMATIC_260, x=160, y=100
	break
	video offset=CINEMATIC_261, x=160, y=100
	break
	video offset=CINEMATIC_262, x=160, y=100
	break
	play id=0x000A, freq=0x14, vol=0x3F, channel=0x03
	video offset=CINEMATIC_263, x=160, y=100
	break
	video offset=CINEMATIC_264, x=160, y=100
	break
	video offset=CINEMATIC_265, x=160, y=100
	break
	video offset=CINEMATIC_266, x=160, y=100
	break
	play id=0x000E, freq=0x02, vol=0x3F, channel=0x03
	mov [0x01], 0x0012

DELAY_18_THEN_PAL_15_CIN_267:
	break
	djnz [0x01], DELAY_18_THEN_PAL_15_CIN_267
	setPalette 0x15
	video offset=CINEMATIC_267, x=160, y=100
	play id=0x000E, freq=0x14, vol=0x3F, channel=0x03
	break
	video offset=CINEMATIC_268, x=160, y=100
	play id=0x000E, freq=0x14, vol=0x3F, channel=0x03
	break
	video offset=CINEMATIC_269, x=160, y=100
	play id=0x000A, freq=0x14, vol=0x3F, channel=0x03
	break
	video offset=CINEMATIC_270, x=160, y=100
	play id=0x000E, freq=0x14, vol=0x3F, channel=0x03
	break
	video offset=CINEMATIC_271, x=160, y=100
	play id=0x000E, freq=0x14, vol=0x3F, channel=0x03
	break
	video offset=CINEMATIC_272, x=160, y=100
	play id=0x000A, freq=0x14, vol=0x3F, channel=0x03
	break
	video offset=CINEMATIC_273, x=160, y=100
	play id=0x000E, freq=0x14, vol=0x3F, channel=0x03
	break
	video offset=CINEMATIC_273, x=160, y=100, zoom=[0x50]	;@enc=alt
	play id=0x000A, freq=0x0A, vol=0x3F, channel=0x03
	break
	jmp TRANSITION_TO_BLITTER_LOOP
LABEL_0DD6:
	killChannel

