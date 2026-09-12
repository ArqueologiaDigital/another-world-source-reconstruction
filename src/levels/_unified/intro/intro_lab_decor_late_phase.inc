DRAW_INTRO_DECOR_318:
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_EXPERIMENT_SPARK_LONG_F0, x=176, y=157
.else
	video offset=CINEMATIC_318, x=176, y=157
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_EXPERIMENT_SPARK_LONG_F1, x=176, y=157
.else
	video offset=CINEMATIC_319, x=176, y=157
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_EXPERIMENT_SPARK_LONG_F2, x=175, y=159
.else
	video offset=CINEMATIC_320, x=175, y=159
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_EXPERIMENT_SPARK_LONG_F3, x=175, y=156
.else
	video offset=CINEMATIC_321, x=175, y=156
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_EXPERIMENT_SPARK_LONG_F2, x=176, y=159
.else
	video offset=CINEMATIC_320, x=176, y=159
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_EXPERIMENT_SPARK_LONG_F1, x=175, y=157
.else
	video offset=CINEMATIC_319, x=175, y=157
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_EXPERIMENT_SPARK_LONG_F0, x=176, y=157
.else
	video offset=CINEMATIC_318, x=176, y=157
.endif
	mov [0x0E], 0x0007

DELAY_7_BEFORE_CIN_322:
	break
	djnz [0x0E], DELAY_7_BEFORE_CIN_322
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_EXPERIMENT_SPARK_CURVED_F0, x=149, y=158
.else
	video offset=CINEMATIC_322, x=149, y=158
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_EXPERIMENT_SPARK_CURVED_F1, x=150, y=159
.else
	video offset=CINEMATIC_323, x=150, y=159
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_EXPERIMENT_SPARK_CURVED_F2, x=150, y=160
.else
	video offset=CINEMATIC_324, x=150, y=160
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_EXPERIMENT_SPARK_CURVED_F1, x=151, y=160
.else
	video offset=CINEMATIC_323, x=151, y=160
.endif
	mov [0x0E], 0x0005

DELAY_5_BEFORE_CIN_325:
	break
	djnz [0x0E], DELAY_5_BEFORE_CIN_325
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_EXPERIMENT_SPARK_SHORT_F0, x=134, y=166
.else
	video offset=CINEMATIC_325, x=134, y=166
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_EXPERIMENT_SPARK_SHORT_F1, x=134, y=170
.else
	video offset=CINEMATIC_326, x=134, y=170
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_EXPERIMENT_SPARK_SHORT_F2, x=134, y=169
.else
	video offset=CINEMATIC_327, x=134, y=169
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_EXPERIMENT_SPARK_SHORT_F3, x=134, y=169
.else
	video offset=CINEMATIC_328, x=134, y=169
.endif
	jmp DRAW_INTRO_DECOR_318
LABEL_0BDE:
.if BRANCH == "dos_1992"
	db 0x11
.else
.if BRANCH == "chahi_amiga_1991"
	db 0x11
.else
	killChannel
.endif
.endif

DRAW_INTRO_LIGHTNING_BOLT_STRIKE:
	break
	mov [0x0D], 0x0014

DELAY_20_BEFORE_PLAY_2C_CIN_309:
	break
	djnz [0x0D], DELAY_20_BEFORE_PLAY_2C_CIN_309
	play id=0x002C, freq=0x08, vol=0x20, channel=0x01
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_EXPERIMENT_LIGHTNING_STRIKE_F0, x=198, y=136
.else
	video offset=CINEMATIC_309, x=198, y=136
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_EXPERIMENT_LIGHTNING_STRIKE_F1, x=198, y=136
.else
	video offset=CINEMATIC_310, x=198, y=136
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_EXPERIMENT_LIGHTNING_STRIKE_F2, x=198, y=135
.else
	video offset=CINEMATIC_311, x=198, y=135
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_EXPERIMENT_LIGHTNING_STRIKE_F3, x=199, y=138
.else
	video offset=CINEMATIC_312, x=199, y=138
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_EXPERIMENT_LIGHTNING_STRIKE_F4, x=197, y=139
.else
	video offset=CINEMATIC_313, x=197, y=139
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_EXPERIMENT_LIGHTNING_STRIKE_F5, x=205, y=144
.else
	video offset=CINEMATIC_314, x=205, y=144
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_EXPERIMENT_LIGHTNING_STRIKE_F6, x=249, y=149
.else
	video offset=CINEMATIC_315, x=249, y=149
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_EXPERIMENT_LIGHTNING_STRIKE_F7, x=252, y=150
.else
	video offset=CINEMATIC_316, x=252, y=150
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_EXPERIMENT_LIGHTNING_STRIKE_F8, x=254, y=145
.else
	video offset=CINEMATIC_317, x=254, y=145
.endif
	killChannel

DRAW_INTRO_LIGHTNING_FLICKER_RIGHT:
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_EXPERIMENT_LIGHTNING_FLICKER_RIGHT_F0, x=229, y=40
.else
	video offset=CINEMATIC_305, x=229, y=40
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_EXPERIMENT_LIGHTNING_FLICKER_RIGHT_F1, x=229, y=40
.else
	video offset=CINEMATIC_306, x=229, y=40
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_EXPERIMENT_LIGHTNING_FLICKER_RIGHT_F2, x=229, y=40
.else
	video offset=CINEMATIC_307, x=229, y=40
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_EXPERIMENT_LIGHTNING_FLICKER_RIGHT_F3, x=229, y=40
.else
	video offset=CINEMATIC_308, x=229, y=40
.endif
	break
	play id=0x002C, freq=0x19, vol=0x0A, channel=0x01
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_EXPERIMENT_LIGHTNING_FLICKER_RIGHT_F2, x=229, y=40
.else
	video offset=CINEMATIC_307, x=229, y=40
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_EXPERIMENT_LIGHTNING_FLICKER_RIGHT_F1, x=229, y=40
.else
	video offset=CINEMATIC_306, x=229, y=40
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_EXPERIMENT_LIGHTNING_FLICKER_RIGHT_F0, x=229, y=40
.else
	video offset=CINEMATIC_305, x=229, y=40
.endif
	mov [0x0F], 0x0016

DELAY_22_BEFORE_DECOR_305:
	break
	djnz [0x0F], DELAY_22_BEFORE_DECOR_305
	jmp DRAW_INTRO_LIGHTNING_FLICKER_RIGHT
LABEL_0C51:
.if BRANCH == "dos_1992"
	db 0x11
.else
.if BRANCH == "chahi_amiga_1991"
	db 0x11
.else
	killChannel
.endif
.endif

DRAW_INTRO_LIGHTNING_FLICKER_CENTER:
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_EXPERIMENT_LIGHTNING_FLICKER_CENTER_F0, x=194, y=29
.else
	video offset=CINEMATIC_301, x=194, y=29
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_EXPERIMENT_LIGHTNING_FLICKER_CENTER_F1, x=196, y=29
.else
	video offset=CINEMATIC_302, x=196, y=29
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_EXPERIMENT_LIGHTNING_FLICKER_CENTER_F2, x=197, y=29
.else
	video offset=CINEMATIC_303, x=197, y=29
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_EXPERIMENT_LIGHTNING_FLICKER_CENTER_F3, x=197, y=29
.else
	video offset=CINEMATIC_304, x=197, y=29
.endif
	play id=0x000E, freq=0x1B, vol=0x0F, channel=0x00
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_EXPERIMENT_LIGHTNING_FLICKER_CENTER_F2, x=197, y=29
.else
	video offset=CINEMATIC_303, x=197, y=29
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_EXPERIMENT_LIGHTNING_FLICKER_CENTER_F1, x=196, y=29
.else
	video offset=CINEMATIC_302, x=196, y=29
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_EXPERIMENT_LIGHTNING_FLICKER_CENTER_F0, x=194, y=29
.else
	video offset=CINEMATIC_301, x=194, y=29
.endif
	mov [0x10], 0x0019

DELAY_25_BEFORE_DECOR_301:
	break
	djnz [0x10], DELAY_25_BEFORE_DECOR_301
	jmp DRAW_INTRO_LIGHTNING_FLICKER_CENTER
LABEL_0C87:
.if BRANCH == "dos_1992"
	db 0x11
.else
.if BRANCH == "chahi_amiga_1991"
	db 0x11
.else
	killChannel
.endif
.endif

SET_PALETTE_18:
	setPalette 0x18
	break
	break
	break
	setPalette 0x1A
	break
	jmp SET_PALETTE_18
LABEL_0C95:
.if BRANCH == "dos_1992"
	db 0x11
.else
.if BRANCH == "chahi_amiga_1991"
	db 0x11
.else
	killChannel
.endif
.endif

INTRO_PALETTE_FLICKER_LOOP:
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
	jmp INTRO_PALETTE_FLICKER_LOOP
LABEL_0CBC:
.if BRANCH == "dos_1992"
	db 0x11
.else
.if BRANCH == "chahi_amiga_1991"
	db 0x11
.else
	killChannel
.endif
.endif

PHASE_PAGE3_DRAW_CIN_172_175:
	break
	selectVideoPage 0x03
	fill page=0x03, color=0x02
	call DRAW_PARTICLE_LAB_BG_COMPOSITE
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_LESTER_SEATED_AT_HOLO_CONSOLE_F1_AMIGA_EXTRA, x=160, y=101
	video offset=CINEMATIC_PARTICLE_LAB_BG_F3, x=187, y=101
.else
	video offset=CINEMATIC_LESTER_SEATED_AT_HOLO_CONSOLE_F1, x=160, y=101
	video offset=CINEMATIC_182, x=187, y=101
.endif
	selectVideoPage 0xFF
	fill page=0xFF, color=0x02
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_243, x=160, y=100
	video offset=CINEMATIC_ACCELERATOR_TUNNEL_FLOOR_DETAIL, x=160, y=100
	video offset=CINEMATIC_ACCELERATOR_TUNNEL_WALL_DETAIL, x=160, y=100
.else
	video offset=CINEMATIC_ACCELERATOR_TUNNEL_VIEW_NEAR, x=160, y=100
	video offset=CINEMATIC_250, x=160, y=100
	video offset=CINEMATIC_251, x=160, y=100
.endif
	copyVideoPage src=0xFF, dst=0x00
	setPalette 0x16
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_246, x=160, y=100
.else
	video offset=CINEMATIC_252, x=160, y=100
.endif
	play id=0x002C, freq=0x14, vol=0x3F, channel=0x03
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_247, x=160, y=100
.else
	video offset=CINEMATIC_253, x=160, y=100
.endif
	play id=0x000A, freq=0x14, vol=0x3F, channel=0x03
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_LESTER_SEATED_AT_HOLO_CONSOLE_F1, x=160, y=100
.else
	video offset=CINEMATIC_254, x=160, y=100
.endif
	play id=0x002C, freq=0x14, vol=0x3F, channel=0x03
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_ACCELERATOR_TUNNEL_VIEW_NEAR, x=160, y=100
.else
	video offset=CINEMATIC_255, x=160, y=100
.endif
	play id=0x000A, freq=0x14, vol=0x3F, channel=0x03
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_250, x=160, y=100
.else
	video offset=CINEMATIC_256, x=160, y=100
.endif
	play id=0x002C, freq=0x14, vol=0x3F, channel=0x03
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_251, x=160, y=100
.else
	video offset=CINEMATIC_257, x=160, y=100
.endif
	play id=0x000A, freq=0x14, vol=0x3F, channel=0x03
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_252, x=160, y=100
.else
	video offset=CINEMATIC_258, x=160, y=100
.endif
	play id=0x002C, freq=0x14, vol=0x3F, channel=0x03
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_253, x=160, y=100
.else
	video offset=CINEMATIC_259, x=160, y=100
.endif
	play id=0x002C, freq=0x0A, vol=0x3F, channel=0x03
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_254, x=160, y=100
.else
	video offset=CINEMATIC_260, x=160, y=100
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_255, x=160, y=100
.else
	video offset=CINEMATIC_261, x=160, y=100
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_256, x=160, y=100
.else
	video offset=CINEMATIC_262, x=160, y=100
.endif
	break
	play id=0x000A, freq=0x14, vol=0x3F, channel=0x03
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_257, x=160, y=100
.else
	video offset=CINEMATIC_263, x=160, y=100
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_258, x=160, y=100
.else
	video offset=CINEMATIC_264, x=160, y=100
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_259, x=160, y=100
.else
	video offset=CINEMATIC_265, x=160, y=100
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_260, x=160, y=100
.else
	video offset=CINEMATIC_266, x=160, y=100
.endif
	break
	play id=0x000E, freq=0x02, vol=0x3F, channel=0x03
	mov [0x01], 0x0012

DELAY_18_THEN_PAL_15_CIN_267:
	break
	djnz [0x01], DELAY_18_THEN_PAL_15_CIN_267
	setPalette 0x15
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_261, x=160, y=100
.else
	video offset=CINEMATIC_267, x=160, y=100
.endif
	play id=0x000E, freq=0x14, vol=0x3F, channel=0x03
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_262, x=160, y=100
.else
	video offset=CINEMATIC_268, x=160, y=100
.endif
	play id=0x000E, freq=0x14, vol=0x3F, channel=0x03
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_263, x=160, y=100
.else
	video offset=CINEMATIC_269, x=160, y=100
.endif
	play id=0x000A, freq=0x14, vol=0x3F, channel=0x03
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_264, x=160, y=100
.else
	video offset=CINEMATIC_270, x=160, y=100
.endif
	play id=0x000E, freq=0x14, vol=0x3F, channel=0x03
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_265, x=160, y=100
.else
	video offset=CINEMATIC_271, x=160, y=100
.endif
	play id=0x000E, freq=0x14, vol=0x3F, channel=0x03
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_266, x=160, y=100
.else
	video offset=CINEMATIC_272, x=160, y=100
.endif
	play id=0x000A, freq=0x14, vol=0x3F, channel=0x03
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_267, x=160, y=100
.else
	video offset=CINEMATIC_273, x=160, y=100
.endif
	play id=0x000E, freq=0x14, vol=0x3F, channel=0x03
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_267, x=160, y=100, zoom=[0x50]	;@enc=alt
.else
	video offset=CINEMATIC_273, x=160, y=100, zoom=[0x50]	;@enc=alt
.endif
	play id=0x000A, freq=0x0A, vol=0x3F, channel=0x03
	break
	jmp TRANSITION_TO_BLITTER_LOOP
LABEL_0DD6:
.if BRANCH == "dos_1992"
	db 0x11
.else
.if BRANCH == "chahi_amiga_1991"
	db 0x11
.else
	killChannel
.endif
.endif

