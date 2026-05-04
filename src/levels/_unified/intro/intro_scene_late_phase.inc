CINEMATIC_128		EQU 0x4230
CINEMATIC_129		EQU 0x4290
CINEMATIC_509		EQU 0x18F6
CINEMATIC_510		EQU 0x1972
CINEMATIC_511		EQU 0x19F2
CINEMATIC_512		EQU 0x1A72
CINEMATIC_513		EQU 0x1AF2
CINEMATIC_514		EQU 0x1B72
CINEMATIC_515		EQU 0x1BF2
CINEMATIC_516		EQU 0x180A
CINEMATIC_521		EQU 0x4248
CINEMATIC_522		EQU 0x4260
CINEMATIC_523		EQU 0x4278
CINEMATIC_524		EQU 0x42A8
CINEMATIC_525		EQU 0x42C0
CINEMATIC_526		EQU 0x42D8
CINEMATIC_527		EQU 0x4218
CINEMATIC_528		EQU 0x06CC

INIT_VAR_04_PAL_E_VAR_01:
	mov [0x04], 0x005E
	setPalette 0x0E
	mov [0x01], 0x0064
	mov [0x02], 0x0064
	mov [0x03], 0x0009
	setup channel=0x04, address=INTRO_DRAW_CIN_528_AT_96_131
	copyVideoPage src=0x03, dst=0x00
	copyVideoPage src=0x00, dst=0xFF
	play id=0x000C, freq=0x0F, vol=0x3F, channel=0x02

PARALLAX_CIN_126_127_LOOP:
	sub [0x01], 0x0014
	add [0x02], 0x0014
	video type=1, offset=CINEMATIC_126, x=160, y=[0x01], zoom=0x40
	video type=1, offset=CINEMATIC_127, x=160, y=[0x02], zoom=0x40
	video type=1, offset=CINEMATIC_128, x=160, y=111, zoom=[0x04]
	je [MUS_MARK], 0x10, PARALLAX_LOOP_BREAK_AND_DJNZ

PARALLAX_LOOP_BREAK_AND_DJNZ:
	break
	djnz [0x03], PARALLAX_CIN_126_127_LOOP
	video type=1, offset=CINEMATIC_128, x=160, y=111, zoom=[0x04]
	setup channel=0x08, address=DRAW_CIN_128_521_ZOOM_VAR04
	setup channel=0x09, address=DRAW_CIN_126_127_AT_VAR01_02
	setup channel=0x05, address=CH_05_INIT_VARS_06_07_08
	mov [0x03], 0x0007

ZOOM_OUT_VAR4_M3_LOOP:
	sub [0x04], 0x0003
	je [MUS_MARK], 0x10, ZOOM_OUT_BREAK_AND_DJNZ

ZOOM_OUT_BREAK_AND_DJNZ:
	break
	djnz [0x03], ZOOM_OUT_VAR4_M3_LOOP
	play id=0x000C, freq=0x0A, vol=0x32, channel=0x02
	mov [0x03], 0x0003

PARALLAX_REVERSE_3X:
	add [0x01], 0x0014
	sub [0x02], 0x0014
	add [0x04], 0x0000
	je [MUS_MARK], 0x10, PARALLAX_REV_BREAK_AND_DJNZ

PARALLAX_REV_BREAK_AND_DJNZ:
	break
	djnz [0x03], PARALLAX_REVERSE_3X
	setup channel=0x08, address=KILL_CHANNEL_ROUTINE
	add [0x01], 0x0014
	sub [0x02], 0x0014
	break
	mov [0x03], 0x0005

DRIFT_CIN_129_PARALLAX_5X:
	add [0x01], 0x0014
	sub [0x02], 0x0014
	video type=1, offset=CINEMATIC_129, x=160, y=111, zoom=[0x04]
	je [MUS_MARK], 0x10, MUS_10_FORCE_KILL_CHANNELS
	break
	djnz [0x03], DRIFT_CIN_129_PARALLAX_5X
	play id=0x0036, freq=0x0F, vol=0x3F, channel=0x02

MUS_10_FORCE_KILL_CHANNELS:
	setup channel=0x05, address=KILL_CHANNEL_ROUTINE
	setup channel=0x04, address=KILL_CHANNEL_ROUTINE
	setup channel=0x08, address=KILL_CHANNEL_ROUTINE
	setup channel=0x09, address=KILL_CHANNEL_ROUTINE
	setup channel=0x01, address=FILL_FF_8_AND_DRAW_CIN_517_518
	setup channel=0x02, address=INTRO_PAUSE_3_PLAY_SONG_INIT
	setup channel=0x3C, address=BLIT_AND_COPY_PAGE_FF_LOOP
	killChannel

CH_05_INIT_VARS_06_07_08:
	mov [0x06], 0x007A
	mov [0x07], 0x0082
	mov [0x08], 0x0005

DRAW_CIN_130_NESTED_OUTER:
	mov [0x09], 0x0003

DRAW_CIN_130_AT_VAR67_INNER:
	video type=1, offset=CINEMATIC_130, x=[0x06], y=16, zoom=0x40
	video type=1, offset=CINEMATIC_130, x=[0x07], y=18, zoom=0x40
	break
	djnz [0x09], DRAW_CIN_130_AT_VAR67_INNER
	add [0x06], 0x0002
	sub [0x07], 0x0002
	djnz [0x08], DRAW_CIN_130_NESTED_OUTER
	jmp CH_05_INIT_VARS_06_07_08
LABEL_21B9:
	killChannel

INTRO_DRAW_CIN_528_AT_96_131:
	break
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_528, x=96, y=131
	selectVideoPage 0xFF
	mov [0x05], 0x0003

DELAY_3F_BEFORE_CIN_130_DRAW:
	break
	djnz [0x05], DELAY_3F_BEFORE_CIN_130_DRAW
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_130, x=96, y=131
	selectVideoPage 0xFF
	mov [0x05], 0x0004

DELAY_4F_BEFORE_CIN_528_RESTART:
	break
	djnz [0x05], DELAY_4F_BEFORE_CIN_528_RESTART
	jmp INTRO_DRAW_CIN_528_AT_96_131
LABEL_21E0:
	killChannel

DRAW_CIN_126_127_AT_VAR01_02:
	video type=1, offset=CINEMATIC_126, x=160, y=[0x01], zoom=0x40
	video type=1, offset=CINEMATIC_127, x=160, y=[0x02], zoom=0x40
	break
	jmp DRAW_CIN_126_127_AT_VAR01_02
LABEL_21EF:
	killChannel

DRAW_CIN_128_521_ZOOM_VAR04:
	video type=1, offset=CINEMATIC_128, x=160, y=111, zoom=[0x04]
	break
	video type=1, offset=CINEMATIC_521, x=160, y=111, zoom=[0x04]
	break
	video type=1, offset=CINEMATIC_522, x=160, y=111, zoom=[0x04]
	break
	video type=1, offset=CINEMATIC_523, x=160, y=111, zoom=[0x04]
	break
	video type=1, offset=CINEMATIC_129, x=160, y=111, zoom=[0x04]
	break
	video type=1, offset=CINEMATIC_524, x=160, y=111, zoom=[0x04]
	break
	video type=1, offset=CINEMATIC_525, x=160, y=111, zoom=[0x04]
	break
	video type=1, offset=CINEMATIC_526, x=160, y=111, zoom=[0x04]
	break
	video type=1, offset=CINEMATIC_525, x=160, y=111, zoom=[0x04]
	break
	video type=1, offset=CINEMATIC_524, x=160, y=111, zoom=[0x04]
	break
	video type=1, offset=CINEMATIC_129, x=160, y=111, zoom=[0x04]
	break
	video type=1, offset=CINEMATIC_523, x=160, y=111, zoom=[0x04]
	break
	video type=1, offset=CINEMATIC_522, x=160, y=111, zoom=[0x04]
	break
	video type=1, offset=CINEMATIC_521, x=160, y=111, zoom=[0x04]
	break
	video type=1, offset=CINEMATIC_128, x=160, y=111, zoom=[0x04]
	break
	video type=1, offset=CINEMATIC_527, x=160, y=111, zoom=[0x04]
	break
	jmp DRAW_CIN_128_521_ZOOM_VAR04
LABEL_2263:
	killChannel

DRAW_CIN_468_509_ZOOM_VAR04:
	video type=1, offset=CINEMATIC_468, x=160, y=111, zoom=[0x04]
	break
	video type=1, offset=CINEMATIC_509, x=160, y=111, zoom=[0x04]
	break
	play id=0x003C, freq=0x0A, vol=0x0F, channel=0x02
	video type=1, offset=CINEMATIC_510, x=160, y=111, zoom=[0x04]
	break
	video type=1, offset=CINEMATIC_511, x=160, y=111, zoom=[0x04]
	break
	video type=1, offset=CINEMATIC_512, x=160, y=111, zoom=[0x04]
	break
	video type=1, offset=CINEMATIC_513, x=160, y=111, zoom=[0x04]
	break
	video type=1, offset=CINEMATIC_514, x=160, y=111, zoom=[0x04]
	break
	video type=1, offset=CINEMATIC_515, x=160, y=111, zoom=[0x04]
	break
	video type=1, offset=CINEMATIC_514, x=160, y=111, zoom=[0x04]
	play id=0x003C, freq=0x0B, vol=0x14, channel=0x02
	break
	video type=1, offset=CINEMATIC_513, x=160, y=111, zoom=[0x04]
	break
	video type=1, offset=CINEMATIC_512, x=160, y=111, zoom=[0x04]
	break
	video type=1, offset=CINEMATIC_511, x=160, y=111, zoom=[0x04]
	break
	video type=1, offset=CINEMATIC_510, x=160, y=111, zoom=[0x04]
	break
	video type=1, offset=CINEMATIC_509, x=160, y=111, zoom=[0x04]
	break
	video type=1, offset=CINEMATIC_468, x=160, y=111, zoom=[0x04]
	break
	video type=1, offset=CINEMATIC_516, x=160, y=111, zoom=[0x04]
	break
	jmp DRAW_CIN_468_509_ZOOM_VAR04
LABEL_22E3:
	killChannel

