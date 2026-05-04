DRAW_CIN_190_LOOP:
	video type=1, offset=CINEMATIC_190, x=[0x03], y=[0x04], zoom=0x40
	break
	jmp DRAW_CIN_190_LOOP
LABEL_119E:
	killChannel

DRAW_CIN_431_LOOP:
	video type=1, offset=CINEMATIC_431, x=[0x03], y=[0x04], zoom=0x40
	break
	jmp DRAW_CIN_431_LOOP
LABEL_11A8:
	killChannel

DRAW_CITY_SEQ_432_433:
	video type=1, offset=CINEMATIC_432, x=160, y=100
	break
	video type=1, offset=CINEMATIC_433, x=160, y=100
	break
	video type=1, offset=CINEMATIC_434, x=160, y=100
	break
	jmp DRAW_CITY_SEQ_432_433
LABEL_11BB:
	killChannel

DRAW_CITY_SEQ_439_440:
	video type=1, offset=CINEMATIC_439, x=160, y=100
	break
	video type=1, offset=CINEMATIC_440, x=160, y=100
	break
	video type=1, offset=CINEMATIC_441, x=160, y=100
	break
	jmp DRAW_CITY_SEQ_439_440
LABEL_11CE:
	killChannel

DRAW_CITY_SEQ_435_436:
	video type=1, offset=CINEMATIC_435, x=160, y=100
	break
	video type=1, offset=CINEMATIC_436, x=160, y=100
	break
	video type=1, offset=CINEMATIC_437, x=160, y=100
	break
	video type=1, offset=CINEMATIC_438, x=160, y=100
	break
	jmp DRAW_CITY_SEQ_435_436
LABEL_11E6:
	killChannel

INTRO_FILL_AND_DRAW_CIN_429_430:
	fill page=0xFF, color=0x02
	video type=1, offset=CINEMATIC_429, x=160, y=100
	video type=1, offset=CINEMATIC_430, x=160, y=100
	setPalette 0x09
	copyVideoPage src=0xFF, dst=0x00
	killChannel

SETUP_INTRO_CITY_CHANNELS:
	setup channel=0x01, address=DRAW_CIN_426_427_TWICE
	setup channel=0x0A, address=SHOW_PAGE_0_LOOP_INTRO
	setup channel=0x10, address=SHOW_PAGE_FF_LOOP_INTRO
	mov [PAUSE_SLICES], 0x0004
	mov [0x01], 0x0001

WAIT_1_BEFORE_COPY_PAGE_03:
	break
	djnz [0x01], WAIT_1_BEFORE_COPY_PAGE_03
	copyVideoPage src=0x00, dst=0x03
	mov [0x01], 0x000E

DELAY_14_BEFORE_BLIT_DISPATCH:
	break
	djnz [0x01], DELAY_14_BEFORE_BLIT_DISPATCH
	setup channel=0x3C, address=BLIT_AND_DISPATCH_VAR3
	break
	selectVideoPage 0x00
	text id=0x0002, x=1, y=24, color=0x06
	selectVideoPage 0xFF
	mov [0x01], 0x0009

DELAY_9_BEFORE_BLIT_DISPATCH:
	break
	djnz [0x01], DELAY_9_BEFORE_BLIT_DISPATCH
	setup channel=0x3C, address=BLIT_AND_DISPATCH_VAR3
	break
	mov [0x01], 0x0014
	selectVideoPage 0x00
	text id=0x0007, x=1, y=150, color=0x06
	selectVideoPage 0xFF

SHOW_TEXT_21_AT_3_150_20X:
	break
	text id=0x0021, x=3, y=150, color=0x06
	djnz [0x01], SHOW_TEXT_21_AT_3_150_20X
	setup channel=0x0C, address=DISPLAY_TEXT_0A_0B_PLAY_FX
	setup channel=0x05, address=DISPLAY_TEXT_21
	mov [0x01], 0x0031

DELAY_49_BEFORE_COPY_PAGE_3_0:
	break
	djnz [0x01], DELAY_49_BEFORE_COPY_PAGE_3_0
	break
	copyVideoPage src=0x03, dst=0x00
	setup channel=0x0B, address=DRAW_CITY_SEQ_419_420
	mov [0x01], 0x0013

DELAY_19_BEFORE_BLITTER_SETUP:
	break
	djnz [0x01], DELAY_19_BEFORE_BLITTER_SETUP
	setup channel=0x3C, address=BLIT_AND_COPY_PAGE_FF_LOOP
	break
	copyVideoPage src=0x00, dst=0x03
	selectVideoPage 0x00
	text id=0x001A, x=20, y=60, color=0x06
	text id=0x0038, x=5, y=20, color=0x05
	selectVideoPage 0xFF
	mov [0x01], 0x000A

SHOW_TEXT_21_AT_26_60_10X:
	break
	text id=0x0021, x=26, y=60, color=0x06
	djnz [0x01], SHOW_TEXT_21_AT_26_60_10X
	mov [0x01], 0x000F

SHOW_TEXT_21_AT_27_68_15X:
	break
	text id=0x0021, x=27, y=68, color=0x06
	djnz [0x01], SHOW_TEXT_21_AT_27_68_15X
	break
	text id=0x0021, x=29, y=84, color=0x06
	mov [0x01], 0x0009

SHOW_TEXT_21_AT_27_100_9X:
	break
	text id=0x0021, x=27, y=100, color=0x06
	djnz [0x01], SHOW_TEXT_21_AT_27_100_9X
	setup channel=0x3C, address=BLIT_AND_COPY_PAGE_FF_LOOP
	break
	selectVideoPage 0x00
	text id=0x0021, x=26, y=100, color=0x02
	selectVideoPage 0xFF
	setup channel=0x3C, address=BLIT_AND_COPY_PAGE_FF_LOOP
	break
	selectVideoPage 0x00
	text id=0x001C, x=26, y=100, color=0x06
	selectVideoPage 0xFF
	text id=0x0021, x=26, y=100, color=0x06
	mov [0x01], 0x000A

SHOW_TEXT_21_AT_27_100_10X:
	break
	text id=0x0021, x=27, y=100, color=0x06
	djnz [0x01], SHOW_TEXT_21_AT_27_100_10X
	mov [0x01], 0x0012

SHOW_TEXT_21_AT_26_124_18X:
	break
	text id=0x0021, x=26, y=124, color=0x06
	djnz [0x01], SHOW_TEXT_21_AT_26_124_18X
	break
	text id=0x0021, x=25, y=132, color=0x06
	mov [0x01], 0x0012

SHOW_TEXT_21_AT_25_156_18X:
	break
	text id=0x0021, x=25, y=156, color=0x06
	djnz [0x01], SHOW_TEXT_21_AT_25_156_18X
	setup channel=0x07, address=INIT_VAR_03_AND_LOOP
	mov [0x01], 0x0024

DELAY_36_BEFORE_BLITTER_SETUP:
	break
	djnz [0x01], DELAY_36_BEFORE_BLITTER_SETUP
	setup channel=0x3C, address=BLIT_AND_COPY_PAGE_FF_LOOP
	break
	selectVideoPage 0x00
	text id=0x0194, x=36, y=170, color=0x06
	selectVideoPage 0xFF
	mov [0x01], 0x000E

DELAY_14_BEFORE_BLITTER_SETUP:
	break
	djnz [0x01], DELAY_14_BEFORE_BLITTER_SETUP
	setup channel=0x3C, address=BLIT_AND_COPY_PAGE_FF_LOOP
	break
	selectVideoPage 0x03
	video type=1, offset=CINEMATIC_191, x=162, y=100
	video type=1, offset=CINEMATIC_192, x=234, y=163
	selectVideoPage 0xFF
	copyVideoPage src=0x03, dst=0x00
	setup channel=0x3C, address=BLIT_AND_COPY_PAGE_FF_LOOP
	break
	selectVideoPage 0x00
	text id=0x0022, x=8, y=2, color=0x06
	selectVideoPage 0xFF
	setup channel=0x07, address=DRAW_CIN_382_TWICE_AT_DIFF_Y
	mov [0x01], 0x0005

SHOW_TEXT_31_AT_2_150_5X:
	break
	text id=0x0031, x=2, y=150, color=0x06
	djnz [0x01], SHOW_TEXT_31_AT_2_150_5X
	mov [0x01], 0x0040

SHOW_TEXT_32_AT_2_156_64X:
	break
	text id=0x0032, x=2, y=156, color=0x06
	djnz [0x01], SHOW_TEXT_32_AT_2_156_64X
	mov [PAUSE_SLICES], 0x0005
	mov [0x01], 0x0013

SHOW_TEXT_33_AT_2_150_19X:
	break
	text id=0x0033, x=2, y=150, color=0x06
	djnz [0x01], SHOW_TEXT_33_AT_2_150_19X
	mov [PAUSE_SLICES], 0x0004
	mov [0x01], 0x0013

SHOW_TEXT_34_AT_8_152_19X:
	break
	text id=0x0034, x=8, y=152, color=0x06
	djnz [0x01], SHOW_TEXT_34_AT_8_152_19X
	mov [0x01], 0x0019

SHOW_TEXT_35_AT_2_140_25X:
	break
	text id=0x0035, x=2, y=140, color=0x06
	jg [MUS_MARK], 0x20, WAIT_MUS_MARK_20_THEN_TEXT_23
	djnz [0x01], SHOW_TEXT_35_AT_2_140_25X
	mov [0x01], 0x000A

SHOW_TEXT_36_UNTIL_MUS_20:
	break
	text id=0x0036, x=2, y=80, color=0x06
	jg [MUS_MARK], 0x20, WAIT_MUS_MARK_20_THEN_TEXT_23
	djnz [0x01], SHOW_TEXT_36_UNTIL_MUS_20

WAIT_MUS_MARK_20_THEN_TEXT_23:
	setup channel=0x3C, address=BLIT_AND_COPY_PAGE_FF_LOOP
	copyVideoPage src=0x03, dst=0x00
	selectVideoPage 0x00
	text id=0x0023, x=0, y=80, color=0x06
	selectVideoPage 0xFF
	mov [PAUSE_SLICES], 0x0005
	mov [0x01], 0x000A
	break

SHOW_TEXT_24_UNTIL_MUS_22:
	je [MUS_MARK], 0x22, SHOW_TEXT_25_PHASE_INIT
	text id=0x0024, x=28, y=80, color=0x06
	break
	djnz [0x01], SHOW_TEXT_24_UNTIL_MUS_22

SHOW_TEXT_25_PHASE_INIT:
	mov [0x01], 0x000A

SHOW_TEXT_25_UNTIL_MUS_23:
	je [MUS_MARK], 0x23, SHOW_TEXT_26_PHASE_INIT
	text id=0x0025, x=28, y=80, color=0x06
	break
	djnz [0x01], SHOW_TEXT_25_UNTIL_MUS_23

SHOW_TEXT_26_PHASE_INIT:
	mov [0x01], 0x000A

SHOW_TEXT_26_AT_28_80_10X:
	text id=0x0026, x=28, y=80, color=0x06
	break
	djnz [0x01], SHOW_TEXT_26_AT_28_80_10X
	text id=0x004C, x=28, y=80, color=0x06
	setup channel=0x10, address=KILL_CHANNEL_ROUTINE
	setup channel=0x0A, address=KILL_CHANNEL_ROUTINE
	setup channel=0x02, address=INTRO_FILL_AND_DRAW_CIN_385
	setup channel=0x01, address=KILL_CHANNEL_ROUTINE
	setup channel=0x3C, address=BLIT_AND_COPY_PAGE_FF_LOOP
	killChannel

COPY_BG_PAGE_AND_DISPLAY_TEXT_23:
	copyVideoPage src=0x03, dst=0xFF
	text id=0x0023, x=0, y=80, color=0x06
	copyVideoPage src=0xFF, dst=0x00
	mov [PAUSE_SLICES], 0x0005
	setup channel=0x03, address=INIT_VAR_02_AND_BREAK_LOOP
	setup channel=0x04, address=KILL_CHANNEL_ROUTINE
	setup channel=0x05, address=KILL_CHANNEL_ROUTINE
	setup channel=0x06, address=KILL_CHANNEL_ROUTINE
	setup channel=0x01, address=DRAW_CIN_426_427_TWICE
	setPalette 0x09
	mov [0x01], 0x000B

SHOW_TEXT_4B_UNTIL_MUS_2C:
	je [MUS_MARK], 0x2C, SHOW_TEXT_27_PHASE_INIT
	text id=0x004B, x=28, y=80, color=0x06
	break
	djnz [0x01], SHOW_TEXT_4B_UNTIL_MUS_2C

SHOW_TEXT_27_PHASE_INIT:
	mov [0x01], 0x000B

SHOW_TEXT_27_UNTIL_MUS_2D:
	je [MUS_MARK], 0x2D, SHOW_TEXT_28_PHASE_INIT
	text id=0x0027, x=28, y=80, color=0x06
	break
	djnz [0x01], SHOW_TEXT_27_UNTIL_MUS_2D

SHOW_TEXT_28_PHASE_INIT:
	mov [0x01], 0x000B

SHOW_TEXT_28_UNTIL_MUS_2E:
	je [MUS_MARK], 0x2E, SHOW_TEXT_29_PHASE_INIT
	text id=0x0028, x=28, y=80, color=0x06
	break
	djnz [0x01], SHOW_TEXT_28_UNTIL_MUS_2E

SHOW_TEXT_29_PHASE_INIT:
	mov [0x01], 0x000B

SHOW_TEXT_29_UNTIL_MUS_2F:
	je [MUS_MARK], 0x2F, SHOW_TEXT_2A_PHASE_INIT
	text id=0x0029, x=28, y=80, color=0x0D
	break
	djnz [0x01], SHOW_TEXT_29_UNTIL_MUS_2F

SHOW_TEXT_2A_PHASE_INIT:
	mov [0x01], 0x000B

SHOW_TEXT_2A_UNTIL_MUS_30:
	je [MUS_MARK], 0x30, SHOW_TEXT_2B_FINAL_PHASE
	text id=0x002A, x=28, y=80, color=0x0D
	break
	djnz [0x01], SHOW_TEXT_2A_UNTIL_MUS_30

SHOW_TEXT_2B_FINAL_PHASE:
	text id=0x002B, x=28, y=80, color=0x0F
	setup channel=0x3C, address=BLIT_AND_COPY_PAGE_FF_LOOP
	copyVideoPage src=0x03, dst=0x00
	mov [PAUSE_SLICES], 0x0004
	setup channel=0x07, address=DRAW_CIN_382_TWICE_AT_DIFF_Y
	setup channel=0x04, address=KILL_CHANNEL_ROUTINE
	setup channel=0x05, address=KILL_CHANNEL_ROUTINE
	setup channel=0x06, address=KILL_CHANNEL_ROUTINE
	mov [0x01], 0x0027

SONG_REPEAT_OR_NEXT_PHASE_LOOP:
	break
	jne [MUS_MARK], 0x31, SONG_LOOP_END_THEN_BLIT_SETUP
	jne [0xDB], 0x00, SONG_RESTART_RESET_MARK
	song id=0x0000, delay=0x0000, pos=0x00

SONG_RESTART_RESET_MARK:
	mov [MUS_MARK], 0x0000

SONG_LOOP_END_THEN_BLIT_SETUP:
	djnz [0x01], SONG_REPEAT_OR_NEXT_PHASE_LOOP
	setup channel=0x3C, address=BLIT_AND_COPY_PAGE_FF_LOOP
	break
	setup channel=0x03, address=KILL_CHANNEL_ROUTINE
	setup channel=0x02, address=SETUP_INTRO_PARTICLE_CHANNELS
	setup channel=0x01, address=KILL_CHANNEL_ROUTINE
	setup channel=0x07, address=KILL_CHANNEL_ROUTINE
	setup channel=0x3C, address=BLIT_AND_COPY_PAGE_FF_LOOP
	fill page=0xFF, color=0x00
	fill page=0x00, color=0x00
	killChannel

BLINK_TEXTS_44_45_AT_2_20:
	text id=0x0044, x=2, y=20, color=0x05
	break
	text id=0x0045, x=2, y=20, color=0x05
	break
	jmp BLINK_TEXTS_44_45_AT_2_20
LABEL_153F:
	killChannel
BLINK_TEXTS_3E_3F_AT_10_120:
	text id=0x003E, x=10, y=120, color=0x04
	break
	text id=0x003F, x=10, y=120, color=0x04
	break
	text id=0x0046, x=11, y=120, color=0x04
	break
	text id=0x0047, x=11, y=120, color=0x04
	break
	text id=0x0040, x=10, y=120, color=0x04
	break
	jmp BLINK_TEXTS_3E_3F_AT_10_120
BLINK_TEXTS_3F_41_AT_11_132:
	text id=0x003F, x=11, y=132, color=0x04
	break
	text id=0x0041, x=11, y=132, color=0x04
	break
	text id=0x0042, x=11, y=132, color=0x04
	break
	text id=0x0043, x=11, y=132, color=0x04
	break
	jmp BLINK_TEXTS_3F_41_AT_11_132
	db 0x11

