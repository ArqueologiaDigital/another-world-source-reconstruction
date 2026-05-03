INIT_PAGE0_PAUSE2_FILL1:
	selectVideoPage 0x00
	mov [PAUSE_SLICES], 0x0002
	fill page=0x00, color=0x01
	video type=1, offset=CINEMATIC_466, x=153, y=114
	selectVideoPage 0xFF
	fill page=0xFF, color=0x01
	video type=1, offset=CINEMATIC_466, x=153, y=114
	setup channel=0x3C, address=BLIT_DISPATCH_HERO_ACTION_ALT
	setPalette 0x0D
	mov [0x01], 0xFC45
	mov [0x03], 0x0073

DRIFT_VAR1_PLUS_5_FOR_115X:
	break
	add [0x01], 0x0005
	djnz [0x03], DRIFT_VAR1_PLUS_5_FOR_115X
	mov [0x03], 0x0019

DRIFT_VAR1_PLUS_4_FOR_25X:
	break
	add [0x01], 0x0004
	djnz [0x03], DRIFT_VAR1_PLUS_4_FOR_25X
	mov [0x03], 0x0064

DRIFT_VAR1_PLUS_3_FOR_100X:
	break
	add [0x01], 0x0003
	djnz [0x03], DRIFT_VAR1_PLUS_3_FOR_100X
	mov [0x03], 0x001E

DRIFT_VAR1_PLUS_2_FOR_30X:
	break
	add [0x01], 0x0002
	djnz [0x03], DRIFT_VAR1_PLUS_2_FOR_30X
	mov [0x03], 0x0010

DRIFT_VAR1_PLUS_1_FOR_16X:
	break
	add [0x01], 0x0001
	djnz [0x03], DRIFT_VAR1_PLUS_1_FOR_16X
	copyVideoPage src=0xFE, dst=0x00
	setup channel=0x03, address=KILL_CHANNEL_ROUTINE
	setup channel=0x3C, address=BLIT_AND_COPY_PAGE_FF_LOOP
	break
	setPalette 0x0C
	copyVideoPage src=0xFE, dst=0x00
	copyVideoPage src=0xFE, dst=0xFF
	fill page=0x00, color=0x07
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_467, x=150, y=100
	video type=1, offset=CINEMATIC_468, x=160, y=111
	fill page=0x03, color=0x02
	selectVideoPage 0x03
	video type=1, offset=CINEMATIC_469, x=160, y=100
	selectVideoPage 0xFF
	break
	mov [PAUSE_SLICES], 0x0004
	setPalette 0x06
	video type=1, offset=CINEMATIC_470, x=160, y=100
	break
	video type=1, offset=CINEMATIC_471, x=160, y=100
	break
	video type=1, offset=CINEMATIC_472, x=160, y=100
	break
	video type=1, offset=CINEMATIC_473, x=160, y=100
	break
	video type=1, offset=CINEMATIC_474, x=160, y=100
	break
	video type=1, offset=CINEMATIC_475, x=160, y=100
	break
	video type=1, offset=CINEMATIC_476, x=160, y=100
	break
	video type=1, offset=CINEMATIC_477, x=160, y=100
	break
	video type=1, offset=CINEMATIC_478, x=160, y=100
	break
	video type=1, offset=CINEMATIC_479, x=160, y=100
	break
	video type=1, offset=CINEMATIC_480, x=160, y=100
	break
	video type=1, offset=CINEMATIC_481, x=160, y=100
	break
	video type=1, offset=CINEMATIC_482, x=160, y=100
	break
	video type=1, offset=CINEMATIC_483, x=160, y=100
	break
	video type=1, offset=CINEMATIC_484, x=160, y=100
	break
	video type=1, offset=CINEMATIC_485, x=160, y=100
	break
	video type=1, offset=CINEMATIC_486, x=160, y=100
	break
	video type=1, offset=CINEMATIC_487, x=160, y=100
	break
	video type=1, offset=CINEMATIC_488, x=160, y=100
	break
	video type=1, offset=CINEMATIC_489, x=160, y=100
	break
	video type=1, offset=CINEMATIC_490, x=160, y=100
	break
	video type=1, offset=CINEMATIC_491, x=160, y=100
	break
	video type=1, offset=CINEMATIC_492, x=160, y=100
	break
	video type=1, offset=CINEMATIC_493, x=160, y=100
	break
	video type=1, offset=CINEMATIC_494, x=160, y=100
	break
	video type=1, offset=CINEMATIC_495, x=160, y=100
	break
	video type=1, offset=CINEMATIC_496, x=160, y=100
	break
	video type=1, offset=CINEMATIC_497, x=160, y=100
	break
	video type=1, offset=CINEMATIC_498, x=160, y=100
	break
	video type=1, offset=CINEMATIC_499, x=160, y=100
	break
	video type=1, offset=CINEMATIC_500, x=160, y=100
	break
	video type=1, offset=CINEMATIC_501, x=160, y=100
	break
	setup channel=0x3C, address=BLIT_AND_COPY_PAGE_FF_LOOP
	break
	play id=0x0036, freq=0x16, vol=0x3F, channel=0x03
	setup channel=0x01, address=CH_01_INIT_VAR_04_06
	setup channel=0x03, address=DRAW_CIN_468_509_ZOOM_VAR04
	fill page=0x00, color=0x07
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_467, x=150, y=100
	selectVideoPage 0xFF
	mov [0x05], 0x0019

DELAY_25F_BEFORE_VAR1_4E:
	break
	djnz [0x05], DELAY_25F_BEFORE_VAR1_4E
	mov [0x01], 0x004E
	mov [0x02], 0x00E8
	mov [0x05], 0x000A

LABEL_1B94:
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_502, x=[0x01], y=100, zoom=0x40
	video type=1, offset=CINEMATIC_503, x=[0x02], y=100, zoom=0x40
	add [0x01], 0x0002
	sub [0x02], 0x0002
	selectVideoPage 0xFF
	break
	djnz [0x05], LABEL_1B94
	mov [0x05], 0x001A

LABEL_1BB3:
	break
	djnz [0x05], LABEL_1BB3
	play id=0x0036, freq=0x0F, vol=0x30, channel=0x03
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_504, x=165, y=100
	selectVideoPage 0xFF
	killChannel

DRAW_CIN_505_LOOP_VAR_02:
	mov [0x02], [0x01]
	video type=1, offset=CINEMATIC_505, x=153, y=[0x02], zoom=0x40
	add [0x02], 0x0186
	video type=1, offset=CINEMATIC_506, x=153, y=[0x02], zoom=0x40
	add [0x02], 0x0124
	video type=1, offset=CINEMATIC_507, x=153, y=[0x02], zoom=0x40
	add [0x02], 0x0183
	video type=1, offset=CINEMATIC_508, x=153, y=[0x02], zoom=0x40
	break
	jmp DRAW_CIN_505_LOOP_VAR_02
LABEL_1BEE:
	killChannel
	db 0x06, 0x11
LABEL_1BF1:
	break
	video type=1, offset=CINEMATIC_182, x=187, y=101
	jmp LABEL_1BF1
	db 0x11

