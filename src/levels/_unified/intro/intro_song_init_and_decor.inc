CINEMATIC_131		EQU 0xF578
CINEMATIC_132		EQU 0xF4E0
CINEMATIC_133		EQU 0xF53C
CINEMATIC_134		EQU 0x4B3C
CINEMATIC_135		EQU 0xAED0
CINEMATIC_136		EQU 0xAEDC
CINEMATIC_137		EQU 0xB0F0
CINEMATIC_457		EQU 0x4B54
CINEMATIC_458		EQU 0x4BD4
CINEMATIC_459		EQU 0x4B6C
CINEMATIC_460		EQU 0x4BA0
CINEMATIC_461		EQU 0x4C08
CINEMATIC_462		EQU 0x4C3C
CINEMATIC_463		EQU 0x4C70
CINEMATIC_464		EQU 0x4CA4
CINEMATIC_465		EQU 0x4CD8

INTRO_PAUSE_3_PLAY_SONG_INIT:
	mov [PAUSE_SLICES], 0x0003
	song id=0x0000, delay=0x3E1C, pos=0x00
	setup channel=0x03, address=CH_03_INIT_VAR_01_02_FFF6
	setup channel=0x04, address=CH_04_INIT_VAR_04_05
	setup channel=0x05, address=CH_05_INIT_VAR_06_07
	setup channel=0x06, address=CH_06_DRAW_CIN_457_PARTICLES
	setup channel=0x07, address=CH_07_INIT_VAR_08_09
	setup channel=0x0A, address=SHOW_PAGE_0_LOOP_INTRO
	setup channel=0x10, address=SHOW_PAGE_FF_LOOP_INTRO
	setup channel=0x08, address=INIT_VARS_10_11_AND_SELECT_PAGE0
	setup channel=0x09, address=DRAW_CIN_170_171_AT_VAR10_VAR11
	mov [0x03], 0x0032

DELAY_50F_THEN_DRAW_CIN_454:
	break
	djnz [0x03], DELAY_50F_THEN_DRAW_CIN_454
	setup channel=0x09, address=KILL_CHANNEL_ROUTINE
	setup channel=0x11, address=DRAW_CIN_453_454_SEQ
	mov [0x03], 0x0009

DELAY_9F_THEN_DRAW_CIN_132:
	break
	djnz [0x03], DELAY_9F_THEN_DRAW_CIN_132
	setup channel=0x3C, address=BLIT_AND_COPY_PAGE_FF_LOOP
	break
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_131, x=228, y=44
	video type=1, offset=CINEMATIC_132, x=160, y=100
	selectVideoPage 0xFF
	setup channel=0x11, address=DRAW_CIN_453_454_SEQ
	mov [0x03], 0x0009

DELAY_9F_THEN_DRAW_CIN_133:
	break
	djnz [0x03], DELAY_9F_THEN_DRAW_CIN_133
	setup channel=0x3C, address=BLIT_AND_COPY_PAGE_FF_LOOP
	break
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_131, x=228, y=44
	video type=1, offset=CINEMATIC_133, x=160, y=100
	selectVideoPage 0xFF
	setup channel=0x11, address=DRAW_CIN_453_454_SEQ
	mov [0x03], 0x000A

DELAY_10F_BEFORE_KILL_CHANNELS:
	break
	djnz [0x03], DELAY_10F_BEFORE_KILL_CHANNELS
	setup channel=0x11, address=KILL_CHANNEL_ROUTINE
	setup channel=0x03, address=KILL_CHANNEL_ROUTINE
	setup channel=0x04, address=KILL_CHANNEL_ROUTINE
	setup channel=0x05, address=KILL_CHANNEL_ROUTINE
	setup channel=0x06, address=KILL_CHANNEL_ROUTINE
	setup channel=0x07, address=KILL_CHANNEL_ROUTINE
	setup channel=0x0A, address=KILL_CHANNEL_ROUTINE
	setup channel=0x10, address=KILL_CHANNEL_ROUTINE
	setup channel=0x02, address=INTRO_PAUSE_3_AND_DRAW_CIN_138
	setup channel=0x3C, address=BLIT_AND_COPY_PAGE_FF_LOOP
	killChannel

CH_03_INIT_VAR_01_02_FFF6:
	mov [0x01], 0xFFF6
	mov [0x02], 0x0017

DROP_CIN_134_DOWN_BY_10_23X:
	video type=1, offset=CINEMATIC_134, x=110, y=[0x01], zoom=0x40
	add [0x01], 0x000A
	break
	djnz [0x02], DROP_CIN_134_DOWN_BY_10_23X
	killChannel

CH_04_INIT_VAR_04_05:
	mov [0x04], 0x0032
	mov [0x05], 0x0050

DRIFT_CIN_135_RIGHT_BY_2_80X:
	video type=1, offset=CINEMATIC_135, x=[0x04], y=100, zoom=0x40
	add [0x04], 0x0002
	break
	djnz [0x05], DRIFT_CIN_135_RIGHT_BY_2_80X
	killChannel

CH_05_INIT_VAR_06_07:
	mov [0x06], 0x00DC
	mov [0x07], 0x0017

RISE_CIN_136_BY_10_FOR_23X:
	break
	video type=1, offset=CINEMATIC_136, x=110, y=[0x06], zoom=0x40
	sub [0x06], 0x000A
	djnz [0x07], RISE_CIN_136_BY_10_FOR_23X
	killChannel

CH_07_INIT_VAR_08_09:
	break
	mov [0x08], 0x007F
	mov [0x09], 0x0006
	mov [0x0B], 0x008E

DRAW_CIN_137_DOUBLE_OUTER:
	mov [0x0A], 0x0002

DRAW_CIN_137_AT_280_283_TWICE:
	break
	video type=1, offset=CINEMATIC_137, x=280, y=[0x08], zoom=0x40
	video type=1, offset=CINEMATIC_137, x=283, y=[0x0b], zoom=0x40
	djnz [0x0A], DRAW_CIN_137_AT_280_283_TWICE
	add [0x08], 0x0003
	sub [0x0B], 0x0003
	djnz [0x09], DRAW_CIN_137_DOUBLE_OUTER
	jmp CH_07_INIT_VAR_08_09
LABEL_19C5:
	killChannel

CH_06_DRAW_CIN_457_PARTICLES:
	break
	video type=1, offset=CINEMATIC_457, x=318, y=139, zoom=0x40
	video type=1, offset=CINEMATIC_457, x=298, y=139, zoom=0x40
	break
	video type=1, offset=CINEMATIC_457, x=278, y=139, zoom=0x40
	video type=1, offset=CINEMATIC_457, x=258, y=139, zoom=0x40
	break
	video type=1, offset=CINEMATIC_457, x=238, y=139
	video type=1, offset=CINEMATIC_457, x=218, y=139
	break
	video type=1, offset=CINEMATIC_457, x=198, y=139
	video type=1, offset=CINEMATIC_457, x=178, y=139
	break
	video type=1, offset=CINEMATIC_457, x=158, y=139
	break
	break
	break
	video type=1, offset=CINEMATIC_458, x=59, y=140
	video type=1, offset=CINEMATIC_459, x=39, y=140
	break
	video type=1, offset=CINEMATIC_460, x=19, y=144
	break
	video type=1, offset=CINEMATIC_461, x=65532, y=152, zoom=0x40
	break
	video type=1, offset=CINEMATIC_462, x=25, y=167
	break
	video type=1, offset=CINEMATIC_463, x=26, y=183
	break
	video type=1, offset=CINEMATIC_464, x=70, y=193
	break
	video type=1, offset=CINEMATIC_465, x=132, y=181
	break
	video type=1, offset=CINEMATIC_465, x=219, y=181
	break
	video type=1, offset=CINEMATIC_465, x=307, y=181, zoom=0x40
	killChannel

