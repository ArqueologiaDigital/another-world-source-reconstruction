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

LABEL_20D5:
	sub [0x01], 0x0014
	add [0x02], 0x0014
	video type=1, offset=CINEMATIC_126, x=160, y=[0x01], zoom=0x40
	video type=1, offset=CINEMATIC_127, x=160, y=[0x02], zoom=0x40
	video type=1, offset=CINEMATIC_128, x=160, y=111, zoom=[0x04]
	je [MUS_MARK], 0x10, LABEL_20F3

LABEL_20F3:
	break
	djnz [0x03], LABEL_20D5
	video type=1, offset=CINEMATIC_128, x=160, y=111, zoom=[0x04]
	setup channel=0x08, address=DRAW_CIN_128_521_ZOOM_VAR04
	setup channel=0x09, address=DRAW_CIN_126_127_AT_VAR01_02
	setup channel=0x05, address=CH_05_INIT_VARS_06_07_08
	mov [0x03], 0x0007

LABEL_210E:
	sub [0x04], 0x0003
	je [MUS_MARK], 0x10, LABEL_2118

LABEL_2118:
	break
	djnz [0x03], LABEL_210E
	play id=0x000C, freq=0x0A, vol=0x32, channel=0x02
	mov [0x03], 0x0003

LABEL_2127:
	add [0x01], 0x0014
	sub [0x02], 0x0014
	add [0x04], 0x0000
	je [MUS_MARK], 0x10, LABEL_2139

LABEL_2139:
	break
	djnz [0x03], LABEL_2127
	setup channel=0x08, address=KILL_CHANNEL_ROUTINE
	add [0x01], 0x0014
	sub [0x02], 0x0014
	break
	mov [0x03], 0x0005

LABEL_214F:
	add [0x01], 0x0014
	sub [0x02], 0x0014
	video type=1, offset=CINEMATIC_129, x=160, y=111, zoom=[0x04]
	je [MUS_MARK], 0x10, LABEL_216E
	break
	djnz [0x03], LABEL_214F
	play id=0x0036, freq=0x0F, vol=0x3F, channel=0x02

LABEL_216E:
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

LABEL_2197:
	mov [0x09], 0x0003

LABEL_219B:
	video type=1, offset=CINEMATIC_130, x=[0x06], y=16, zoom=0x40
	video type=1, offset=CINEMATIC_130, x=[0x07], y=18, zoom=0x40
	break
	djnz [0x09], LABEL_219B
	add [0x06], 0x0002
	sub [0x07], 0x0002
	djnz [0x08], LABEL_2197
	jmp CH_05_INIT_VARS_06_07_08
LABEL_21B9:
	killChannel

INTRO_DRAW_CIN_528_AT_96_131:
	break
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_528, x=96, y=131
	selectVideoPage 0xFF
	mov [0x05], 0x0003

LABEL_21C7:
	break
	djnz [0x05], LABEL_21C7
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_130, x=96, y=131
	selectVideoPage 0xFF
	mov [0x05], 0x0004

LABEL_21D8:
	break
	djnz [0x05], LABEL_21D8
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

