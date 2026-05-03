INTRO_RESET_PAGES_AND_PAL_0:
	fill page=0x00, color=0x00
	fill page=0xFF, color=0x00
	fill page=0x03, color=0x00
	setPalette 0x00	;@raw=0x0B,0x00,0x00
	blitFramebuffer 0xFF
	load id=0x3E82

PLAY_FX_2C_AND_DRAW_CIN_000:
	break
	play id=0x002C, freq=0x14, vol=0x3F, channel=0x00
	video type=1, offset=CINEMATIC_000, x=160, y=100
	break
	video type=1, offset=CINEMATIC_001, x=160, y=100
	break
	video type=1, offset=CINEMATIC_002, x=160, y=100
	break
	video type=1, offset=CINEMATIC_003, x=160, y=100
	break
	video type=1, offset=CINEMATIC_004, x=160, y=100
	mov [0x02], 0x005A

LABEL_09FE:
	break
	djnz [0x02], LABEL_09FE
	jmp PLAY_FX_2C_AND_DRAW_CIN_000
LABEL_0A06:
	killChannel

DRAW_INTRO_DECOR_340:
	video type=1, offset=CINEMATIC_340, x=160, y=100
	break
	video type=1, offset=CINEMATIC_341, x=160, y=100
	break
	video type=1, offset=CINEMATIC_342, x=160, y=100
	break
	video type=1, offset=CINEMATIC_343, x=160, y=100
	break
	play id=0x002C, freq=0x0A, vol=0x20, channel=0x01
	video type=1, offset=CINEMATIC_344, x=160, y=100
	break
	video type=1, offset=CINEMATIC_345, x=160, y=100
	break
	video type=1, offset=CINEMATIC_346, x=160, y=100
	break
	video type=1, offset=CINEMATIC_347, x=160, y=100
	break
	video type=1, offset=CINEMATIC_348, x=160, y=100
	mov [0x04], 0x0024

LABEL_0A3D:
	break
	djnz [0x04], LABEL_0A3D
	jmp DRAW_INTRO_DECOR_340
LABEL_0A45:
	killChannel

DRAW_INTRO_DECOR_337:
	break
	video type=1, offset=CINEMATIC_337, x=160, y=100
	break
	video type=1, offset=CINEMATIC_338, x=160, y=100
	break
	video type=1, offset=CINEMATIC_339, x=160, y=100
	mov [0x06], 0x003C

LABEL_0A59:
	break
	djnz [0x06], LABEL_0A59
	jmp DRAW_INTRO_DECOR_337
LABEL_0A61:
	killChannel

DRAW_INTRO_DECOR_333:
	break
	video type=1, offset=CINEMATIC_333, x=160, y=100
	break
	video type=1, offset=CINEMATIC_334, x=160, y=100
	break
	video type=1, offset=CINEMATIC_335, x=160, y=100
	break
	play id=0x002C, freq=0x0F, vol=0x3F, channel=0x02
	video type=1, offset=CINEMATIC_336, x=160, y=100
	mov [0x08], 0x0032

LABEL_0A80:
	break
	djnz [0x08], LABEL_0A80
	jmp DRAW_INTRO_DECOR_333
LABEL_0A88:
	killChannel

DRAW_INTRO_DECOR_331:
	break
	video type=1, offset=CINEMATIC_331, x=112, y=127
	break
	video type=1, offset=CINEMATIC_331, x=113, y=129
	break
	video type=1, offset=CINEMATIC_331, x=115, y=131
	break
	video type=1, offset=CINEMATIC_331, x=116, y=133
	break
	video type=1, offset=CINEMATIC_331, x=117, y=136
	break
	video type=1, offset=CINEMATIC_331, x=118, y=138
	break
	video type=1, offset=CINEMATIC_331, x=120, y=140
	break
	video type=1, offset=CINEMATIC_331, x=122, y=142
	break
	video type=1, offset=CINEMATIC_331, x=123, y=144
	break
	video type=1, offset=CINEMATIC_332, x=125, y=147
	break
	video type=1, offset=CINEMATIC_332, x=127, y=149
	break
	video type=1, offset=CINEMATIC_332, x=128, y=151
	break
	video type=1, offset=CINEMATIC_331, x=130, y=153
	break
	video type=1, offset=CINEMATIC_331, x=132, y=155
	break
	video type=1, offset=CINEMATIC_331, x=133, y=158
	break
	video type=1, offset=CINEMATIC_331, x=133, y=160
	break
	video type=1, offset=CINEMATIC_331, x=133, y=162
	mov [0x0A], 0x001E

LABEL_0AE2:
	break
	djnz [0x0A], LABEL_0AE2
	jmp DRAW_INTRO_DECOR_331
LABEL_0AEA:
	killChannel

DRAW_INTRO_DECOR_329:
	break
	video type=1, offset=CINEMATIC_329, x=254, y=142
	break
	video type=1, offset=CINEMATIC_329, x=254, y=144
	break
	video type=1, offset=CINEMATIC_329, x=254, y=146
	break
	video type=1, offset=CINEMATIC_329, x=253, y=148
	break
	video type=1, offset=CINEMATIC_329, x=253, y=150
	break
	video type=1, offset=CINEMATIC_329, x=253, y=151
	break
	video type=1, offset=CINEMATIC_329, x=253, y=154
	break
	video type=1, offset=CINEMATIC_329, x=253, y=156
	break
	video type=1, offset=CINEMATIC_329, x=253, y=158
	break
	video type=1, offset=CINEMATIC_329, x=252, y=159
	break
	video type=1, offset=CINEMATIC_329, x=252, y=160
	break
	video type=1, offset=CINEMATIC_330, x=250, y=162
	break
	video type=1, offset=CINEMATIC_330, x=250, y=163
	break
	play id=0x000E, freq=0x08, vol=0x20, channel=0x02
	video type=1, offset=CINEMATIC_330, x=248, y=167
	break
	video type=1, offset=CINEMATIC_330, x=247, y=169
	break
	video type=1, offset=CINEMATIC_330, x=246, y=172
	break
	video type=1, offset=CINEMATIC_330, x=245, y=174
	break
	video type=1, offset=CINEMATIC_330, x=243, y=176
	break
	video type=1, offset=CINEMATIC_330, x=242, y=178
	break
	video type=1, offset=CINEMATIC_325, x=144, y=158
	break
	video type=1, offset=CINEMATIC_326, x=144, y=160
	break
	video type=1, offset=CINEMATIC_327, x=145, y=162
	break
	video type=1, offset=CINEMATIC_328, x=145, y=163
	break
	video type=1, offset=CINEMATIC_327, x=145, y=167
	break
	video type=1, offset=CINEMATIC_326, x=145, y=169
	break
	video type=1, offset=CINEMATIC_325, x=145, y=171
	mov [0x0C], 0x000A

LABEL_0B77:
	break
	djnz [0x0C], LABEL_0B77
	jmp DRAW_INTRO_DECOR_329
LABEL_0B7F:
	killChannel

DRAW_INTRO_DECOR_318:
	break
	video type=1, offset=CINEMATIC_318, x=176, y=157
	break
	video type=1, offset=CINEMATIC_319, x=176, y=157
	break
	video type=1, offset=CINEMATIC_320, x=175, y=159
	break
	video type=1, offset=CINEMATIC_321, x=175, y=156
	break
	video type=1, offset=CINEMATIC_320, x=176, y=159
	break
	video type=1, offset=CINEMATIC_319, x=175, y=157
	break
	video type=1, offset=CINEMATIC_318, x=176, y=157
	mov [0x0E], 0x0007

LABEL_0BA7:
	break
	djnz [0x0E], LABEL_0BA7
	video type=1, offset=CINEMATIC_322, x=149, y=158
	break
	video type=1, offset=CINEMATIC_323, x=150, y=159
	break
	video type=1, offset=CINEMATIC_324, x=150, y=160
	break
	video type=1, offset=CINEMATIC_323, x=151, y=160
	mov [0x0E], 0x0005

LABEL_0BC3:
	break
	djnz [0x0E], LABEL_0BC3
	video type=1, offset=CINEMATIC_325, x=134, y=166
	break
	video type=1, offset=CINEMATIC_326, x=134, y=170
	break
	video type=1, offset=CINEMATIC_327, x=134, y=169
	break
	video type=1, offset=CINEMATIC_328, x=134, y=169
	jmp DRAW_INTRO_DECOR_318
LABEL_0BDE:
	killChannel

INIT_VAR_0D_THEN_LOOP:
	break
	mov [0x0D], 0x0014

LABEL_0BE4:
	break
	djnz [0x0D], LABEL_0BE4
	play id=0x002C, freq=0x08, vol=0x20, channel=0x01
	video type=1, offset=CINEMATIC_309, x=198, y=136
	break
	video type=1, offset=CINEMATIC_310, x=198, y=136
	break
	video type=1, offset=CINEMATIC_311, x=198, y=135
	break
	video type=1, offset=CINEMATIC_312, x=199, y=138
	break
	video type=1, offset=CINEMATIC_313, x=197, y=139
	break
	video type=1, offset=CINEMATIC_314, x=205, y=144
	break
	video type=1, offset=CINEMATIC_315, x=249, y=149
	break
	video type=1, offset=CINEMATIC_316, x=252, y=150
	break
	video type=1, offset=CINEMATIC_317, x=254, y=145
	killChannel

DRAW_INTRO_DECOR_305:
	break
	video type=1, offset=CINEMATIC_305, x=229, y=40
	break
	video type=1, offset=CINEMATIC_306, x=229, y=40
	break
	video type=1, offset=CINEMATIC_307, x=229, y=40
	break
	video type=1, offset=CINEMATIC_308, x=229, y=40
	break
	play id=0x002C, freq=0x19, vol=0x0A, channel=0x01
	video type=1, offset=CINEMATIC_307, x=229, y=40
	break
	video type=1, offset=CINEMATIC_306, x=229, y=40
	break
	video type=1, offset=CINEMATIC_305, x=229, y=40
	mov [0x0F], 0x0016

LABEL_0C49:
	break
	djnz [0x0F], LABEL_0C49
	jmp DRAW_INTRO_DECOR_305
LABEL_0C51:
	killChannel

DRAW_INTRO_DECOR_301:
	break
	video type=1, offset=CINEMATIC_301, x=194, y=29
	break
	video type=1, offset=CINEMATIC_302, x=196, y=29
	break
	video type=1, offset=CINEMATIC_303, x=197, y=29
	break
	video type=1, offset=CINEMATIC_304, x=197, y=29
	play id=0x000E, freq=0x1B, vol=0x0F, channel=0x00
	break
	video type=1, offset=CINEMATIC_303, x=197, y=29
	break
	video type=1, offset=CINEMATIC_302, x=196, y=29
	break
	video type=1, offset=CINEMATIC_301, x=194, y=29
	mov [0x10], 0x0019

LABEL_0C7F:
	break
	djnz [0x10], LABEL_0C7F
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

LABEL_0C9D:
	break
	djnz [0x14], LABEL_0C9D
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

LABEL_0CBD:
	break
	selectVideoPage 0x03
	fill page=0x03, color=0x02
	call DRAW_CINEMATICS_172_TO_175
	video type=1, offset=CINEMATIC_248, x=160, y=101
	video type=1, offset=CINEMATIC_182, x=187, y=101
	selectVideoPage 0xFF
	fill page=0xFF, color=0x02
	video type=1, offset=CINEMATIC_249, x=160, y=100
	video type=1, offset=CINEMATIC_250, x=160, y=100
	video type=1, offset=CINEMATIC_251, x=160, y=100
	copyVideoPage src=0xFF, dst=0x00
	setPalette 0x16
	break
	video type=1, offset=CINEMATIC_252, x=160, y=100
	play id=0x002C, freq=0x14, vol=0x3F, channel=0x03
	break
	video type=1, offset=CINEMATIC_253, x=160, y=100
	play id=0x000A, freq=0x14, vol=0x3F, channel=0x03
	break
	video type=1, offset=CINEMATIC_254, x=160, y=100
	play id=0x002C, freq=0x14, vol=0x3F, channel=0x03
	break
	video type=1, offset=CINEMATIC_255, x=160, y=100
	play id=0x000A, freq=0x14, vol=0x3F, channel=0x03
	break
	video type=1, offset=CINEMATIC_256, x=160, y=100
	play id=0x002C, freq=0x14, vol=0x3F, channel=0x03
	break
	video type=1, offset=CINEMATIC_257, x=160, y=100
	play id=0x000A, freq=0x14, vol=0x3F, channel=0x03
	break
	video type=1, offset=CINEMATIC_258, x=160, y=100
	play id=0x002C, freq=0x14, vol=0x3F, channel=0x03
	break
	video type=1, offset=CINEMATIC_259, x=160, y=100
	play id=0x002C, freq=0x0A, vol=0x3F, channel=0x03
	break
	video type=1, offset=CINEMATIC_260, x=160, y=100
	break
	video type=1, offset=CINEMATIC_261, x=160, y=100
	break
	video type=1, offset=CINEMATIC_262, x=160, y=100
	break
	play id=0x000A, freq=0x14, vol=0x3F, channel=0x03
	video type=1, offset=CINEMATIC_263, x=160, y=100
	break
	video type=1, offset=CINEMATIC_264, x=160, y=100
	break
	video type=1, offset=CINEMATIC_265, x=160, y=100
	break
	video type=1, offset=CINEMATIC_266, x=160, y=100
	break
	play id=0x000E, freq=0x02, vol=0x3F, channel=0x03
	mov [0x01], 0x0012

LABEL_0D71:
	break
	djnz [0x01], LABEL_0D71
	setPalette 0x15
	video type=1, offset=CINEMATIC_267, x=160, y=100
	play id=0x000E, freq=0x14, vol=0x3F, channel=0x03
	break
	video type=1, offset=CINEMATIC_268, x=160, y=100
	play id=0x000E, freq=0x14, vol=0x3F, channel=0x03
	break
	video type=1, offset=CINEMATIC_269, x=160, y=100
	play id=0x000A, freq=0x14, vol=0x3F, channel=0x03
	break
	video type=1, offset=CINEMATIC_270, x=160, y=100
	play id=0x000E, freq=0x14, vol=0x3F, channel=0x03
	break
	video type=1, offset=CINEMATIC_271, x=160, y=100
	play id=0x000E, freq=0x14, vol=0x3F, channel=0x03
	break
	video type=1, offset=CINEMATIC_272, x=160, y=100
	play id=0x000A, freq=0x14, vol=0x3F, channel=0x03
	break
	video type=1, offset=CINEMATIC_273, x=160, y=100
	play id=0x000E, freq=0x14, vol=0x3F, channel=0x03
	break
	video type=1, offset=CINEMATIC_273, x=160, y=100, zoom=[0x50]	;@raw=0x6A,0x4A,0x61,0xA0,0x64,0x50
	play id=0x000A, freq=0x0A, vol=0x3F, channel=0x03
	break
	jmp LABEL_0776
LABEL_0DD6:
	killChannel

