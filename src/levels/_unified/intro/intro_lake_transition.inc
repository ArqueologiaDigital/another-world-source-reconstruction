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

LABEL_1D04:
	break
	djnz [0x09], LABEL_1D04
	video type=1, offset=CINEMATIC_444, x=221, y=123
	video type=1, offset=CINEMATIC_443, x=217, y=127
	video type=1, offset=CINEMATIC_442, x=219, y=125
	video type=1, offset=CINEMATIC_446, x=138, y=107
	video type=1, offset=CINEMATIC_445, x=134, y=107
	mov [0x09], 0x000A

LABEL_1D21:
	break
	djnz [0x09], LABEL_1D21
	video type=1, offset=CINEMATIC_442, x=217, y=127
	video type=1, offset=CINEMATIC_443, x=221, y=123
	video type=1, offset=CINEMATIC_444, x=219, y=125
	video type=1, offset=CINEMATIC_445, x=138, y=107
	video type=1, offset=CINEMATIC_446, x=135, y=109
	mov [0x09], 0x000A

LABEL_1D3E:
	break
	djnz [0x09], LABEL_1D3E
	video type=1, offset=CINEMATIC_446, x=131, y=109
	video type=1, offset=CINEMATIC_445, x=135, y=109
	mov [0x09], 0x000A

LABEL_1D4F:
	break
	djnz [0x09], LABEL_1D4F
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

LABEL_1DC3:
	break
	add [0x02], 0x0001
	sub [0x03], 0x0001
	video type=1, offset=CINEMATIC_113, x=[0x02], y=94, zoom=0x40
	video type=1, offset=CINEMATIC_114, x=[0x03], y=94, zoom=0x40
	djnz [0x01], LABEL_1DC3
	mov [PAUSE_SLICES], 0x0002
	video type=1, offset=CINEMATIC_112, x=143, y=94
	setup channel=0x03, address=KILL_CHANNEL_ROUTINE
	copyVideoPage src=0xFF, dst=0x00
	mov [0x01], 0x0019
	setPalette 0x0A

LABEL_1DF0:
	break
	djnz [0x01], LABEL_1DF0
	mov [PAUSE_SLICES], 0x0001
	mov [0x01], 0x0050
	mov [0x02], 0x0004
	mov [0x03], 0x001A
	setup channel=0x3C, address=BLIT_DISPATCH_HERO_ACTION_ALT

LABEL_1E09:
	jne [0x02], 0x01, LABEL_1E13
	mov [0x02], 0x0002

LABEL_1E13:
	mov [0x04], [0x02]
	sub [0x02], 0x0001

LABEL_1E1A:
	break
	video type=1, offset=CINEMATIC_115, x=121, y=[0x03], zoom=0x40
	video type=1, offset=CINEMATIC_116, x=121, y=187
	djnz [0x04], LABEL_1E1A
	add [0x03], 0x0002
	djnz [0x01], LABEL_1E09
	setup channel=0x3C, address=BLIT_AND_COPY_PAGE_FF_LOOP
	break
	mov [PAUSE_SLICES], 0x0001
	copyVideoPage src=0xFE, dst=0x00
	setPalette 0x10
	mov [0x01], 0x001E

LABEL_1E43:
	video type=1, offset=CINEMATIC_117, x=193, y=65527, zoom=0x40
	break
	djnz [0x01], LABEL_1E43
	mov [0x01], 0x001E

LABEL_1E52:
	video type=1, offset=CINEMATIC_117, x=196, y=65530, zoom=0x40
	break
	djnz [0x01], LABEL_1E52
	mov [0x01], 0x001E

LABEL_1E61:
	video type=1, offset=CINEMATIC_117, x=189, y=65529, zoom=0x40
	break
	djnz [0x01], LABEL_1E61
	mov [0x01], 0x001E

LABEL_1E70:
	video type=1, offset=CINEMATIC_117, x=193, y=65531, zoom=0x40
	break
	djnz [0x01], LABEL_1E70
	mov [0x01], 0x001E

LABEL_1E7F:
	video type=1, offset=CINEMATIC_117, x=196, y=65534, zoom=0x40
	break
	djnz [0x01], LABEL_1E7F
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

LABEL_1EC4:
	break
	djnz [0x04], LABEL_1EC4
	add [0x01], 0x000E
	break
	add [0x01], 0x000E
	break
	mov [0x03], 0x0000
	mov [0x1E], 0x0001
	mov [0x04], 0x0004

LABEL_1EDF:
	break
	djnz [0x04], LABEL_1EDF
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

LABEL_1F0B:
	break
	djnz [0x04], LABEL_1F0B
	mov [0x04], 0x0004
	mov [0x1E], 0x0002
	mov [0x03], 0x0000

LABEL_1F1C:
	break
	djnz [0x04], LABEL_1F1C
	mov [0x04], 0x0003

LABEL_1F25:
	add [0x01], 0x000F
	sub [0x02], 0x000F
	break
	djnz [0x04], LABEL_1F25
	add [0x01], 0x000B
	sub [0x02], 0x0009
	break
	mov [0x03], 0x0000
	mov [0x1E], 0x0003
	mov [0x04], 0x0004

LABEL_1F47:
	break
	djnz [0x04], LABEL_1F47
	mov [0x04], 0x0003

LABEL_1F50:
	add [0x02], 0x0012
	break
	djnz [0x04], LABEL_1F50
	mov [0x03], 0x0000
	mov [0x1E], 0x0004
	mov [0x04], 0x0003

LABEL_1F65:
	break
	djnz [0x04], LABEL_1F65
	mov [0x04], 0x0002
	add [0x02], 0x0001

LABEL_1F72:
	sub [0x01], 0x000E
	add [0x02], 0x0000
	break
	djnz [0x04], LABEL_1F72
	mov [0x1E], 0x0005
	mov [0x03], 0x0000
	mov [0x04], 0x0006

LABEL_1F8B:
	break
	djnz [0x04], LABEL_1F8B
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
	call LABEL_1FD2
	break
	video type=1, offset=CINEMATIC_124, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_125, x=[0x01], y=[0x02], zoom=0x40
	break
	jmp DRAW_CIN_120_LOOP_VAR03
LABEL_1FD1:
	killChannel

LABEL_1FD2:
	jne [0x1E], 0x00, LABEL_1FDE
	play id=0x000B, freq=0x14, vol=0x3F, channel=0x02

LABEL_1FDE:
	jne [0x1E], 0x01, LABEL_1FEA
	play id=0x000B, freq=0x16, vol=0x3F, channel=0x02

LABEL_1FEA:
	jne [0x1E], 0x02, LABEL_1FF6
	play id=0x000B, freq=0x12, vol=0x3F, channel=0x02

LABEL_1FF6:
	jne [0x1E], 0x03, LABEL_2002
	play id=0x000B, freq=0x12, vol=0x3F, channel=0x02

LABEL_2002:
	jne [0x1E], 0x04, LABEL_200E
	play id=0x000B, freq=0x14, vol=0x3F, channel=0x02

LABEL_200E:
	jne [0x1E], 0x05, LABEL_201A
	play id=0x000B, freq=0x14, vol=0x3F, channel=0x02

LABEL_201A:
	ret

CH_01_INIT_VAR_04_06:
	mov [0x04], 0x0040
	mov [0x06], 0x000F

LABEL_2023:
	add [0x04], 0x0003
	break
	djnz [0x06], LABEL_2023
	mov [0x06], 0x000A

LABEL_2030:
	add [0x04], 0x0005
	break
	djnz [0x06], LABEL_2030
	mov [0x06], 0x0014

LABEL_203D:
	add [0x04], 0x0009
	break
	djnz [0x06], LABEL_203D
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

LABEL_207A:
	sub [0x04], 0x0009
	break
	djnz [0x06], LABEL_207A
	mov [0x06], 0x000A

LABEL_2087:
	sub [0x04], 0x0005
	break
	djnz [0x06], LABEL_2087
	mov [0x06], 0x0005

LABEL_2094:
	sub [0x04], 0x0003
	break
	djnz [0x06], LABEL_2094
	setup channel=0x01, address=KILL_CHANNEL_ROUTINE
	setup channel=0x02, address=INTRO_FILL_PAGE0_DRAW_CIN_118
	setup channel=0x03, address=DRAW_CIN_120_LOOP_VAR03
	setup channel=0x3C, address=BLIT_AND_COPY_PAGE_FF_LOOP
	setup channel=0x04, address=KILL_CHANNEL_ROUTINE
	killChannel

