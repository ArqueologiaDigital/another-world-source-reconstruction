CH_03_INIT_VAR_03_04:
	mov [0x03], 0x0064
	mov [0x04], 0x0013

SLIDE_CIN_448_BY_VAR3_19X:
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_448, x=160, y=[0x03], zoom=0x40
	video type=1, offset=CINEMATIC_449, x=160, y=101
	sub [0x03], 0x0001
	selectVideoPage 0xFF
	break
	djnz [0x04], SLIDE_CIN_448_BY_VAR3_19X
	setup channel=0x06, address=DRAW_CIN_450_451_SEQ
	killChannel

INTRO_TRANSITION_TO_LAKE_SCENE:
	mov [PAUSE_SLICES], 0x0003
	mov [0x01], 0x002E
	mov [0x02], 0x00FF
	fill page=0xFF, color=0x02
	call DRAW_CINEMATICS_172_TO_175
	setPalette 0x08
	video type=1, offset=CINEMATIC_181, x=160, y=101
	video type=1, offset=CINEMATIC_182, x=187, y=101
	copyVideoPage src=0xFF, dst=0x00
	break
	setup channel=0x03, address=CH_03_INIT_VAR_03_04
	setup channel=0x04, address=CH_04_INIT_VAR_05
	setup channel=0x05, address=CH_05_INIT_VAR_07_08
	setup channel=0x0A, address=SELECT_PAGE0_AND_DISPATCH_BLIT
	setup channel=0x0B, address=DRAW_CIN_442_443_444_DESC_Y
	setup channel=0x0E, address=SELECT_PAGE_FF_LOOP
	mov [0x01], 0x0032

DELAY_50F_THEN_SETUP_CITY_SEQ:
	break
	djnz [0x01], DELAY_50F_THEN_SETUP_CITY_SEQ
	setup channel=0x01, address=INTRO_FILL_AND_DRAW_413_414
	setup channel=0x02, address=SETUP_CITY_SEQ_CHANNELS
	setup channel=0x3C, address=BLIT_AND_COPY_PAGE_FF_LOOP
	setup channel=0x04, address=KILL_CHANNEL_ROUTINE
	setup channel=0x05, address=KILL_CHANNEL_ROUTINE
	setup channel=0x0A, address=KILL_CHANNEL_ROUTINE
	setup channel=0x0B, address=KILL_CHANNEL_ROUTINE
	setup channel=0x0E, address=KILL_CHANNEL_ROUTINE
	setup channel=0x06, address=KILL_CHANNEL_ROUTINE
	killChannel

SELECT_PAGE0_AND_DISPATCH_BLIT:
	selectVideoPage 0x00
	setup channel=0x3C, address=BLIT_AND_COPY_PAGE_FF_LOOP
	break
	jmp SELECT_PAGE0_AND_DISPATCH_BLIT
LABEL_1C8E:
	killChannel

SELECT_PAGE_FF_LOOP:
	selectVideoPage 0xFF
	break
	jmp SELECT_PAGE_FF_LOOP
LABEL_1C95:
	killChannel

CH_04_INIT_VAR_05:
	mov [0x05], 0x0009

DELAY_9F_THEN_PLAY_FX_34:
	break
	djnz [0x05], DELAY_9F_THEN_PLAY_FX_34
	play id=0x0034, freq=0x14, vol=0x3F, channel=0x02
	mov [0x05], 0x0007
	mov [0x06], 0x007B

RISE_CIN_447_BY_2_FOR_7X:
	video type=1, offset=CINEMATIC_447, x=204, y=[0x06], zoom=0x40
	sub [0x06], 0x0002
	break
	djnz [0x05], RISE_CIN_447_BY_2_FOR_7X
	jmp CH_04_INIT_VAR_05
LABEL_1CBE:
	killChannel

CH_05_INIT_VAR_07_08:
	mov [0x07], 0x0014
	mov [0x08], 0x007B

RISE_CIN_130_BY_1_FOR_20X:
	video type=1, offset=CINEMATIC_130, x=204, y=[0x08], zoom=0x40
	sub [0x08], 0x0001
	break
	djnz [0x07], RISE_CIN_130_BY_1_FOR_20X
	jmp CH_05_INIT_VAR_07_08
LABEL_1CD8:
	killChannel

DRAW_CIN_450_451_SEQ:
	video type=1, offset=CINEMATIC_450, x=160, y=100
	break
	video type=1, offset=CINEMATIC_451, x=160, y=100
	break
	video type=1, offset=CINEMATIC_452, x=160, y=100
	break
	jmp DRAW_CIN_450_451_SEQ
LABEL_1CEB:
	killChannel

DRAW_CIN_442_443_444_DESC_Y:
	video type=1, offset=CINEMATIC_442, x=221, y=123
	video type=1, offset=CINEMATIC_443, x=219, y=125
	video type=1, offset=CINEMATIC_444, x=217, y=127
	video type=1, offset=CINEMATIC_445, x=131, y=109
	video type=1, offset=CINEMATIC_446, x=134, y=107
	mov [0x09], 0x000A

DELAY_10F_BEFORE_CIN_444_443:
	break
	djnz [0x09], DELAY_10F_BEFORE_CIN_444_443
	video type=1, offset=CINEMATIC_444, x=221, y=123
	video type=1, offset=CINEMATIC_443, x=217, y=127
	video type=1, offset=CINEMATIC_442, x=219, y=125
	video type=1, offset=CINEMATIC_446, x=138, y=107
	video type=1, offset=CINEMATIC_445, x=134, y=107
	mov [0x09], 0x000A

DELAY_10F_BEFORE_CIN_442_443:
	break
	djnz [0x09], DELAY_10F_BEFORE_CIN_442_443
	video type=1, offset=CINEMATIC_442, x=217, y=127
	video type=1, offset=CINEMATIC_443, x=221, y=123
	video type=1, offset=CINEMATIC_444, x=219, y=125
	video type=1, offset=CINEMATIC_445, x=138, y=107
	video type=1, offset=CINEMATIC_446, x=135, y=109
	mov [0x09], 0x000A

DELAY_10F_BEFORE_CIN_446_445:
	break
	djnz [0x09], DELAY_10F_BEFORE_CIN_446_445
	video type=1, offset=CINEMATIC_446, x=131, y=109
	video type=1, offset=CINEMATIC_445, x=135, y=109
	mov [0x09], 0x000A

DELAY_10F_BEFORE_RESTART_443:
	break
	djnz [0x09], DELAY_10F_BEFORE_RESTART_443
	jmp DRAW_CIN_442_443_444_DESC_Y
LABEL_1D57:
	killChannel

DRAW_CINEMATICS_172_TO_175:
	video type=1, offset=CINEMATIC_172, x=156, y=94
	video type=1, offset=CINEMATIC_173, x=160, y=100
	video type=1, offset=CINEMATIC_174, x=161, y=99
	video type=1, offset=CINEMATIC_175, x=205, y=101
	video type=1, offset=CINEMATIC_176, x=90, y=79
	video type=1, offset=CINEMATIC_177, x=191, y=99
	video type=1, offset=CINEMATIC_178, x=187, y=101
	video type=1, offset=CINEMATIC_179, x=191, y=99
	video type=1, offset=CINEMATIC_180, x=160, y=100
	ret

INTRO_SET_PAL_7_FILL_PAGE0_5:
	setPalette 0x07
	selectVideoPage 0x00
	fill page=0x00, color=0x05
	video type=1, offset=CINEMATIC_529, x=133, y=90
	video type=1, offset=CINEMATIC_530, x=245, y=86
	video type=1, offset=CINEMATIC_531, x=287, y=118, zoom=0x40
	video type=1, offset=CINEMATIC_532, x=287, y=101, zoom=0x40
	video type=1, offset=CINEMATIC_533, x=248, y=100
	video type=1, offset=CINEMATIC_534, x=288, y=158, zoom=0x40
	copyVideoPage src=0x00, dst=0xFF
	setup channel=0x3C, address=BLIT_AND_COPY_PAGE_FF_LOOP
	selectVideoPage 0xFF
	killChannel

DRAW_CIN_112_AT_143_94_LOOP:
	video type=1, offset=CINEMATIC_112, x=143, y=94
	break
	jmp DRAW_CIN_112_AT_143_94_LOOP
LABEL_1DB2:
	killChannel

CH_02_INIT_VARS_01_02_03:
	mov [0x01], 0x0008
	mov [0x02], 0x008F
	mov [0x03], 0x0090
	mov [PAUSE_SLICES], 0x0002

DRIFT_CIN_113_X_PLUS_Y_MINUS_8X:
	break
	add [0x02], 0x0001
	sub [0x03], 0x0001
	video type=1, offset=CINEMATIC_113, x=[0x02], y=94, zoom=0x40
	video type=1, offset=CINEMATIC_114, x=[0x03], y=94, zoom=0x40
	djnz [0x01], DRIFT_CIN_113_X_PLUS_Y_MINUS_8X
	mov [PAUSE_SLICES], 0x0002
	video type=1, offset=CINEMATIC_112, x=143, y=94
	setup channel=0x03, address=KILL_CHANNEL_ROUTINE
	copyVideoPage src=0xFF, dst=0x00
	mov [0x01], 0x0019
	setPalette 0x0A

DELAY_25F_AFTER_SET_PAL_A:
	break
	djnz [0x01], DELAY_25F_AFTER_SET_PAL_A
	mov [PAUSE_SLICES], 0x0001
	mov [0x01], 0x0050
	mov [0x02], 0x0004
	mov [0x03], 0x001A
	setup channel=0x3C, address=BLIT_DISPATCH_HERO_ACTION_ALT

BLITTER_CYCLE_VAR2_80X_LOOP:
	jne [0x02], 0x01, COPY_VAR2_TO_VAR4_DEC
	mov [0x02], 0x0002

COPY_VAR2_TO_VAR4_DEC:
	mov [0x04], [0x02]
	sub [0x02], 0x0001

DRAW_CIN_115_116_VAR4_LOOP:
	break
	video type=1, offset=CINEMATIC_115, x=121, y=[0x03], zoom=0x40
	video type=1, offset=CINEMATIC_116, x=121, y=187
	djnz [0x04], DRAW_CIN_115_116_VAR4_LOOP
	add [0x03], 0x0002
	djnz [0x01], BLITTER_CYCLE_VAR2_80X_LOOP
	setup channel=0x3C, address=BLIT_AND_COPY_PAGE_FF_LOOP
	break
	mov [PAUSE_SLICES], 0x0001
	copyVideoPage src=0xFE, dst=0x00
	setPalette 0x10
	mov [0x01], 0x001E

DRIFT_CIN_117_AT_193_NEG9_30X:
	video type=1, offset=CINEMATIC_117, x=193, y=65527, zoom=0x40
	break
	djnz [0x01], DRIFT_CIN_117_AT_193_NEG9_30X
	mov [0x01], 0x001E

DRIFT_CIN_117_AT_196_NEG6_30X:
	video type=1, offset=CINEMATIC_117, x=196, y=65530, zoom=0x40
	break
	djnz [0x01], DRIFT_CIN_117_AT_196_NEG6_30X
	mov [0x01], 0x001E

DRIFT_CIN_117_AT_189_NEG7_30X:
	video type=1, offset=CINEMATIC_117, x=189, y=65529, zoom=0x40
	break
	djnz [0x01], DRIFT_CIN_117_AT_189_NEG7_30X
	mov [0x01], 0x001E

DRIFT_CIN_117_AT_193_NEG5_30X:
	video type=1, offset=CINEMATIC_117, x=193, y=65531, zoom=0x40
	break
	djnz [0x01], DRIFT_CIN_117_AT_193_NEG5_30X
	mov [0x01], 0x001E

DRIFT_CIN_117_AT_196_NEG2_30X:
	video type=1, offset=CINEMATIC_117, x=196, y=65534, zoom=0x40
	break
	djnz [0x01], DRIFT_CIN_117_AT_196_NEG2_30X
	setup channel=0x02, address=INIT_PAGE0_PAUSE2_FILL1
	setup channel=0x03, address=DRAW_CIN_505_LOOP_VAR_02
	setup channel=0x3C, address=BLIT_AND_COPY_PAGE_FF_LOOP
	killChannel

INTRO_FILL_PAGE0_DRAW_CIN_118:
	fill page=0x00, color=0x06
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_118, x=130, y=58
	video type=1, offset=CINEMATIC_119, x=160, y=100
	selectVideoPage 0xFF
	copyVideoPage src=0x00, dst=0xFF
	setPalette 0x0F
	mov [0x01], 0x0098
	mov [0x02], 0x005C
	mov [0x03], 0x0000
	mov [0x1E], 0x0000
	mov [0x04], 0x0005
	mov [PAUSE_SLICES], 0x0004

DELAY_VAR4_BEFORE_VAR1_PLUS_E:
	break
	djnz [0x04], DELAY_VAR4_BEFORE_VAR1_PLUS_E
	add [0x01], 0x000E
	break
	add [0x01], 0x000E
	break
	mov [0x03], 0x0000
	mov [0x1E], 0x0001
	mov [0x04], 0x0004

DELAY_4F_BEFORE_VAR_SHIFT_9:
	break
	djnz [0x04], DELAY_4F_BEFORE_VAR_SHIFT_9
	sub [0x01], 0x0009
	add [0x02], 0x0009
	break
	sub [0x01], 0x0009
	add [0x02], 0x0009
	break
	sub [0x01], 0x000A
	add [0x02], 0x0009
	break
	mov [0x03], 0x0000
	mov [0x1E], 0x0002
	mov [0x04], 0x0004

DELAY_4F_BEFORE_PHASE_2_INIT:
	break
	djnz [0x04], DELAY_4F_BEFORE_PHASE_2_INIT
	mov [0x04], 0x0004
	mov [0x1E], 0x0002
	mov [0x03], 0x0000

DELAY_4F_BEFORE_DRIFT_15_M15:
	break
	djnz [0x04], DELAY_4F_BEFORE_DRIFT_15_M15
	mov [0x04], 0x0003

DRIFT_VAR1_PLUS_F_VAR2_M_F_3X:
	add [0x01], 0x000F
	sub [0x02], 0x000F
	break
	djnz [0x04], DRIFT_VAR1_PLUS_F_VAR2_M_F_3X
	add [0x01], 0x000B
	sub [0x02], 0x0009
	break
	mov [0x03], 0x0000
	mov [0x1E], 0x0003
	mov [0x04], 0x0004

DELAY_4F_BEFORE_DRIFT_VAR2_18:
	break
	djnz [0x04], DELAY_4F_BEFORE_DRIFT_VAR2_18
	mov [0x04], 0x0003

DRIFT_VAR2_PLUS_18_3X:
	add [0x02], 0x0012
	break
	djnz [0x04], DRIFT_VAR2_PLUS_18_3X
	mov [0x03], 0x0000
	mov [0x1E], 0x0004
	mov [0x04], 0x0003

DELAY_3F_BEFORE_VAR2_PLUS_1:
	break
	djnz [0x04], DELAY_3F_BEFORE_VAR2_PLUS_1
	mov [0x04], 0x0002
	add [0x02], 0x0001

DRIFT_VAR1_MINUS_E_2X:
	sub [0x01], 0x000E
	add [0x02], 0x0000
	break
	djnz [0x04], DRIFT_VAR1_MINUS_E_2X
	mov [0x1E], 0x0005
	mov [0x03], 0x0000
	mov [0x04], 0x0006

DELAY_6F_BEFORE_PAL_E_INIT:
	break
	djnz [0x04], DELAY_6F_BEFORE_PAL_E_INIT
	setup channel=0x02, address=INIT_VAR_04_PAL_E_VAR_01
	setup channel=0x3C, address=BLIT_AND_COPY_PAGE_FF_LOOP
	setup channel=0x03, address=KILL_CHANNEL_ROUTINE
	killChannel

DRAW_CIN_120_LOOP_VAR03:
	video type=1, offset=CINEMATIC_120, x=[0x01], y=[0x02], zoom=0x40
	break
	jne [0x03], 0x00, DRAW_CIN_120_LOOP_VAR03
	mov [0x03], 0x00FF
	video type=1, offset=CINEMATIC_121, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_122, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_123, x=[0x01], y=[0x02], zoom=0x40
	call PLAY_FX_BY_PHASE_VAR1E
	break
	video type=1, offset=CINEMATIC_124, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_125, x=[0x01], y=[0x02], zoom=0x40
	break
	jmp DRAW_CIN_120_LOOP_VAR03
LABEL_1FD1:
	killChannel

PLAY_FX_BY_PHASE_VAR1E:
	jne [0x1E], 0x00, PLAY_FX_PHASE_1_FREQ_22
	play id=0x000B, freq=0x14, vol=0x3F, channel=0x02

PLAY_FX_PHASE_1_FREQ_22:
	jne [0x1E], 0x01, PLAY_FX_PHASE_2_FREQ_18
	play id=0x000B, freq=0x16, vol=0x3F, channel=0x02

PLAY_FX_PHASE_2_FREQ_18:
	jne [0x1E], 0x02, PLAY_FX_PHASE_3_FREQ_18
	play id=0x000B, freq=0x12, vol=0x3F, channel=0x02

PLAY_FX_PHASE_3_FREQ_18:
	jne [0x1E], 0x03, PLAY_FX_PHASE_4_FREQ_20
	play id=0x000B, freq=0x12, vol=0x3F, channel=0x02

PLAY_FX_PHASE_4_FREQ_20:
	jne [0x1E], 0x04, PLAY_FX_PHASE_5_FREQ_20
	play id=0x000B, freq=0x14, vol=0x3F, channel=0x02

PLAY_FX_PHASE_5_FREQ_20:
	jne [0x1E], 0x05, PLAY_FX_DISPATCH_RET
	play id=0x000B, freq=0x14, vol=0x3F, channel=0x02

PLAY_FX_DISPATCH_RET:
	ret

CH_01_INIT_VAR_04_06:
	mov [0x04], 0x0040
	mov [0x06], 0x000F

DRIFT_VAR4_PLUS_3_FOR_15X:
	add [0x04], 0x0003
	break
	djnz [0x06], DRIFT_VAR4_PLUS_3_FOR_15X
	mov [0x06], 0x000A

DRIFT_VAR4_PLUS_5_FOR_10X:
	add [0x04], 0x0005
	break
	djnz [0x06], DRIFT_VAR4_PLUS_5_FOR_10X
	mov [0x06], 0x0014

DRIFT_VAR4_PLUS_9_FOR_20X:
	add [0x04], 0x0009
	break
	djnz [0x06], DRIFT_VAR4_PLUS_9_FOR_20X
	setup channel=0x02, address=KILL_CHANNEL_ROUTINE
	fill page=0xFF, color=0x09
	setup channel=0x3C, address=BLIT_AND_COPY_PAGE_FF_LOOP
	break
	setPalette 0x0E
	copyVideoPage src=0x03, dst=0x00
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_126, x=160, y=100
	video type=1, offset=CINEMATIC_127, x=160, y=100
	selectVideoPage 0xFF
	fill page=0xFF, color=0x09
	break
	setup channel=0x03, address=DRAW_CIN_128_521_ZOOM_VAR04
	play id=0x0036, freq=0x14, vol=0x3F, channel=0x03
	mov [0x04], 0x0153
	mov [0x06], 0x0014

DRIFT_VAR4_MINUS_9_FOR_20X:
	sub [0x04], 0x0009
	break
	djnz [0x06], DRIFT_VAR4_MINUS_9_FOR_20X
	mov [0x06], 0x000A

DRIFT_VAR4_MINUS_5_FOR_10X:
	sub [0x04], 0x0005
	break
	djnz [0x06], DRIFT_VAR4_MINUS_5_FOR_10X
	mov [0x06], 0x0005

DRIFT_VAR4_MINUS_3_FOR_5X:
	sub [0x04], 0x0003
	break
	djnz [0x06], DRIFT_VAR4_MINUS_3_FOR_5X
	setup channel=0x01, address=KILL_CHANNEL_ROUTINE
	setup channel=0x02, address=INTRO_FILL_PAGE0_DRAW_CIN_118
	setup channel=0x03, address=DRAW_CIN_120_LOOP_VAR03
	setup channel=0x3C, address=BLIT_AND_COPY_PAGE_FF_LOOP
	setup channel=0x04, address=KILL_CHANNEL_ROUTINE
	killChannel

