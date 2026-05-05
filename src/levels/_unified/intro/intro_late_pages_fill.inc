CINEMATIC_468		EQU 0x187E

CINEMATIC_466		EQU 0x4082
CINEMATIC_467		EQU 0x40FE
CINEMATIC_469		EQU 0xCC2C
CINEMATIC_470		EQU 0xFB44
CINEMATIC_471		EQU 0xFB64
CINEMATIC_472		EQU 0xFB78
CINEMATIC_473		EQU 0xFB8C
CINEMATIC_474		EQU 0xFBA0
CINEMATIC_475		EQU 0xFBB4
CINEMATIC_476		EQU 0xFBC8
CINEMATIC_477		EQU 0xFBE8
CINEMATIC_478		EQU 0xFBFC
CINEMATIC_479		EQU 0xFC10
CINEMATIC_480		EQU 0xFC24
CINEMATIC_481		EQU 0xFC38
CINEMATIC_482		EQU 0xFC4C
CINEMATIC_483		EQU 0xFC60
CINEMATIC_484		EQU 0xFC80
CINEMATIC_485		EQU 0xFC94
CINEMATIC_486		EQU 0xFCA8
CINEMATIC_487		EQU 0xFCBC
CINEMATIC_488		EQU 0xFCD0
CINEMATIC_489		EQU 0xFCE4
CINEMATIC_490		EQU 0xFD04
CINEMATIC_491		EQU 0xFD18
CINEMATIC_492		EQU 0xFD2C
CINEMATIC_493		EQU 0xFD40
CINEMATIC_494		EQU 0xFD54
CINEMATIC_495		EQU 0xFD68
CINEMATIC_496		EQU 0xFD7C
CINEMATIC_497		EQU 0xFD90
CINEMATIC_498		EQU 0xFDAC
CINEMATIC_499		EQU 0xFDBC
CINEMATIC_500		EQU 0xFDCC
CINEMATIC_501		EQU 0xFDDC
CINEMATIC_502		EQU 0x41C4
CINEMATIC_503		EQU 0x41D0
CINEMATIC_504		EQU 0x41B8
CINEMATIC_505		EQU 0xFEAC
CINEMATIC_506		EQU 0xFE60
CINEMATIC_507		EQU 0xFE32
CINEMATIC_508		EQU 0xFDEC

INIT_PAGE0_PAUSE2_FILL1:
	selectVideoPage 0x00
	mov [PAUSE_SLICES], 0x0002
	fill page=0x00, color=0x01
	video offset=CINEMATIC_466, x=153, y=114
	selectVideoPage 0xFF
	fill page=0xFF, color=0x01
	video offset=CINEMATIC_466, x=153, y=114
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
	video offset=CINEMATIC_467, x=150, y=100
	video offset=CINEMATIC_468, x=160, y=111
	fill page=0x03, color=0x02
	selectVideoPage 0x03
	video offset=CINEMATIC_469, x=160, y=100
	selectVideoPage 0xFF
	break
	mov [PAUSE_SLICES], 0x0004
	setPalette 0x06
	video offset=CINEMATIC_470, x=160, y=100
	break
	video offset=CINEMATIC_471, x=160, y=100
	break
	video offset=CINEMATIC_472, x=160, y=100
	break
	video offset=CINEMATIC_473, x=160, y=100
	break
	video offset=CINEMATIC_474, x=160, y=100
	break
	video offset=CINEMATIC_475, x=160, y=100
	break
	video offset=CINEMATIC_476, x=160, y=100
	break
	video offset=CINEMATIC_477, x=160, y=100
	break
	video offset=CINEMATIC_478, x=160, y=100
	break
	video offset=CINEMATIC_479, x=160, y=100
	break
	video offset=CINEMATIC_480, x=160, y=100
	break
	video offset=CINEMATIC_481, x=160, y=100
	break
	video offset=CINEMATIC_482, x=160, y=100
	break
	video offset=CINEMATIC_483, x=160, y=100
	break
	video offset=CINEMATIC_484, x=160, y=100
	break
	video offset=CINEMATIC_485, x=160, y=100
	break
	video offset=CINEMATIC_486, x=160, y=100
	break
	video offset=CINEMATIC_487, x=160, y=100
	break
	video offset=CINEMATIC_488, x=160, y=100
	break
	video offset=CINEMATIC_489, x=160, y=100
	break
	video offset=CINEMATIC_490, x=160, y=100
	break
	video offset=CINEMATIC_491, x=160, y=100
	break
	video offset=CINEMATIC_492, x=160, y=100
	break
	video offset=CINEMATIC_493, x=160, y=100
	break
	video offset=CINEMATIC_494, x=160, y=100
	break
	video offset=CINEMATIC_495, x=160, y=100
	break
	video offset=CINEMATIC_496, x=160, y=100
	break
	video offset=CINEMATIC_497, x=160, y=100
	break
	video offset=CINEMATIC_498, x=160, y=100
	break
	video offset=CINEMATIC_499, x=160, y=100
	break
	video offset=CINEMATIC_500, x=160, y=100
	break
	video offset=CINEMATIC_501, x=160, y=100
	break
	setup channel=0x3C, address=BLIT_AND_COPY_PAGE_FF_LOOP
	break
	play id=0x0036, freq=0x16, vol=0x3F, channel=0x03
	setup channel=0x01, address=CH_01_INIT_VAR_04_06
	setup channel=0x03, address=DRAW_CIN_468_509_ZOOM_VAR04
	fill page=0x00, color=0x07
	selectVideoPage 0x00
	video offset=CINEMATIC_467, x=150, y=100
	selectVideoPage 0xFF
	mov [0x05], 0x0019

DELAY_25F_BEFORE_VAR1_4E:
	break
	djnz [0x05], DELAY_25F_BEFORE_VAR1_4E
	mov [0x01], 0x004E
	mov [0x02], 0x00E8
	mov [0x05], 0x000A

DRIFT_CIN_502_503_BY_2_10X:
	selectVideoPage 0x00
	video offset=CINEMATIC_502, x=[0x01], y=100
	video offset=CINEMATIC_503, x=[0x02], y=100
	add [0x01], 0x0002
	sub [0x02], 0x0002
	selectVideoPage 0xFF
	break
	djnz [0x05], DRIFT_CIN_502_503_BY_2_10X
	mov [0x05], 0x001A

DELAY_26F_THEN_PLAY_FX_36:
	break
	djnz [0x05], DELAY_26F_THEN_PLAY_FX_36
	play id=0x0036, freq=0x0F, vol=0x30, channel=0x03
	selectVideoPage 0x00
	video offset=CINEMATIC_504, x=165, y=100
	selectVideoPage 0xFF
	killChannel

DRAW_CIN_505_LOOP_VAR_02:
	mov [0x02], [0x01]
	video offset=CINEMATIC_505, x=153, y=[0x02]
	add [0x02], 0x0186
	video offset=CINEMATIC_506, x=153, y=[0x02]
	add [0x02], 0x0124
	video offset=CINEMATIC_507, x=153, y=[0x02]
	add [0x02], 0x0183
	video offset=CINEMATIC_508, x=153, y=[0x02]
	break
	jmp DRAW_CIN_505_LOOP_VAR_02
LABEL_1BEE:
	killChannel
	db 0x06, 0x11
DRAW_CIN_182_AT_187_101_LOOP:
	break
	video offset=CINEMATIC_182, x=187, y=101
	jmp DRAW_CIN_182_AT_187_101_LOOP
	db 0x11

