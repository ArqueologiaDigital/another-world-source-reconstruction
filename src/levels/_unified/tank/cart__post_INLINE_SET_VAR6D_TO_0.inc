LABEL_0004:
	call CLEAR_PAGES_1_2_AND_BLIT
	mov [0xE3], 0x0000
	mov [PAUSE_SLICES], 0x0002
	setup channel=0x3C, address=HANG_BLITTING_PAGE_FF
	setup channel=0x14, address=LABEL_042F
	call LABEL_00A4
	call LABEL_00C9
	killChannel
	setup channel=0x09, address=LABEL_0E32
	killChannel
	jmp LABEL_042F

LABEL_0026:
	setup channel=0x3C, address=BLITTER_LOOP_COPY_PAGE_03
	setup channel=0x02, address=DRAW_CIN_224_MULTI_FRAME
	setup channel=0x04, address=LABEL_14F7
	setup channel=0x0A, address=LABEL_1838
	setup channel=0x0B, address=WAIT_VAR3E_DEC_AND_RANDOMIZE
	setup channel=0x0E, address=WAIT_VAR4E_PLAY_8C_DRAW_CIN_201
	setup channel=0x1C, address=LABEL_1282
	setup channel=0x1F, address=LABEL_0FDB
	setup channel=0x20, address=LABEL_0F71
	setup channel=0x21, address=LABEL_1133
	setup channel=0x22, address=WAIT_VAR56_PLAY_8E_DRAW_CIN_020
	setup channel=0x23, address=INIT_VAR1_NEG50_PLAY_8B_TWICE
	setup channel=0x24, address=LABEL_16BF
	setup channel=0x25, address=LABEL_1335
	setup channel=0x28, address=LABEL_085A
	setup channel=0x2A, address=INLINE_SET_VAR6B_TO_50
	setup channel=0x2F, address=LABEL_071B
	setup channel=0x30, address=WAIT_VAR45_PLAY_8C_DRAW_CIN_011
	setup channel=0x31, address=WAIT_VAR46_PLAY_8E_DRAW_CIN_056
	setup channel=0x35, address=INLINE_SET_VAR66_TO_32
	setup channel=0x37, address=LABEL_1237
	call INIT_TANK_DRIVE_VARS
	call LABEL_1BCA
	setup channel=0x00, address=INIT_VARS_A_B_PAL_1
	killChannel

LABEL_0085:
	setup channel=0x3C, address=BLITTER_LOOP_COPY_PAGE_03
	setup channel=0x02, address=DRAW_CIN_224_MULTI_FRAME
	setup channel=0x00, address=LABEL_1C05
	setup channel=0x20, address=HANG_DRAW_CIN_223
	setup channel=0x28, address=HANG_DRAW_CIN_222
	setup channel=0x23, address=LABEL_00DD
	call INIT_TANK_DRIVE_VARS
	killChannel
	call BLACKHOLE_FRAME_DRAW

LABEL_00A4:
	jne [0xDB], 0x00, SHARED_RET
	load id=0x0052
	load id=0x0084
	load id=0x008B
	load id=0x008C
	load id=0x008E
	load id=0x005C
	load id=0x0058
	load id=0x0057
	load id=0x0059
	load id=0x005B
	ret

LABEL_00C9:
	je [0xDB], 0x00, SHARED_RET
	load id=0x07DC
	ret

LABEL_00D3:
	je [0xDB], 0x00, SHARED_RET
	load id=0x07DD
	ret

LABEL_00DD:
	mov [0x01], 0x00AA
	call LABEL_00D3
	song id=0x0BD7, delay=0x0000, pos=0x00
	mov [0x02], 0x0064
	mov [0x03], 0x0040
	mov [0x2B], 0x0014
	play id=0x0084, freq=0x0F, vol=0x20, channel=0x03
	play id=0x0084, freq=0x11, vol=0x40, channel=0x02
	play id=0x008B, freq=0x0A, vol=0x40, channel=0x01
	play id=0x008B, freq=0x14, vol=0x40, channel=0x00

LABEL_010E:
	break
	call DRAW_CIN_093_TO_097_VAR
	mov [0xF8], [0x2B]
	add [0xF8], 0x0003
	add [0x01], [0xF8]
	djnz [0x2B], LABEL_010E
	jmp LABEL_0026

RESET_PAGES_AND_SETUP_CH_0A:
	killChannel
	copyVideoPage src=0x03, dst=0x00
	killChannel
	setup channel=0x0A, address=LABEL_013D

HANG_DRAW_CIN_223:
	video type=1, offset=CINEMATIC_223, x=160, y=100
	break
	jmp HANG_DRAW_CIN_223

HANG_DRAW_CIN_222:
	video type=1, offset=CINEMATIC_222, x=160, y=100
	break
	jmp HANG_DRAW_CIN_222
LABEL_013C:
	db 0x11

LABEL_013D:
	video type=1, offset=CINEMATIC_229, x=81, y=131
	break
	video type=1, offset=CINEMATIC_229, x=96, y=121
	break
	video type=1, offset=CINEMATIC_229, x=86, y=127
	break
	jmp LABEL_013D
LABEL_014F:
	db 0x11

DRAW_CIN_260_AT_3_POSITIONS:
	video type=1, offset=CINEMATIC_260, x=152, y=101
	break
	video type=1, offset=CINEMATIC_260, x=143, y=136
	break
	video type=1, offset=CINEMATIC_260, x=148, y=124
	break
	video type=1, offset=CINEMATIC_260, x=151, y=112
	break
	video type=1, offset=CINEMATIC_260, x=206, y=52
	break
	video type=1, offset=CINEMATIC_260, x=205, y=166
	break
	video type=1, offset=CINEMATIC_260, x=196, y=50
	break
	video type=1, offset=CINEMATIC_260, x=188, y=49
	break
	video type=1, offset=CINEMATIC_260, x=179, y=49
	break
	video type=1, offset=CINEMATIC_260, x=179, y=78
	break
	video type=1, offset=CINEMATIC_260, x=205, y=81
	break
	video type=1, offset=CINEMATIC_260, x=103, y=89
	break
	video type=1, offset=CINEMATIC_260, x=51, y=130
	break
	video type=1, offset=CINEMATIC_260, x=104, y=46
	break
	video type=1, offset=CINEMATIC_260, x=101, y=46
	break
	video type=1, offset=CINEMATIC_260, x=99, y=48
	break
	video type=1, offset=CINEMATIC_260, x=95, y=50
	break
	video type=1, offset=CINEMATIC_260, x=96, y=60
	break
	video type=1, offset=CINEMATIC_260, x=98, y=69
	break
	video type=1, offset=CINEMATIC_260, x=95, y=72
	break
	video type=1, offset=CINEMATIC_260, x=92, y=75
	break
	video type=1, offset=CINEMATIC_260, x=49, y=69
	break
	video type=1, offset=CINEMATIC_260, x=51, y=76
	break
	video type=1, offset=CINEMATIC_260, x=54, y=83
	break
	video type=1, offset=CINEMATIC_260, x=56, y=92
	break
	video type=1, offset=CINEMATIC_260, x=62, y=88
	break
	video type=1, offset=CINEMATIC_260, x=66, y=85
	break
	video type=1, offset=CINEMATIC_260, x=71, y=82
	break
	video type=1, offset=CINEMATIC_260, x=70, y=75
	break
	video type=1, offset=CINEMATIC_260, x=66, y=76
	break
	video type=1, offset=CINEMATIC_260, x=63, y=79
	break
	video type=1, offset=CINEMATIC_260, x=60, y=80
	break
	video type=1, offset=CINEMATIC_260, x=59, y=74
	break
	video type=1, offset=CINEMATIC_260, x=62, y=72
	break
	video type=1, offset=CINEMATIC_260, x=65, y=70
	break
	video type=1, offset=CINEMATIC_260, x=69, y=68
	break
	video type=1, offset=CINEMATIC_260, x=228, y=107
	break
	video type=1, offset=CINEMATIC_260, x=227, y=112
	break
	video type=1, offset=CINEMATIC_260, x=225, y=117
	break
	video type=1, offset=CINEMATIC_260, x=265, y=70, zoom=0x40
	break
	video type=1, offset=CINEMATIC_260, x=268, y=73, zoom=0x40
	break
	video type=1, offset=CINEMATIC_260, x=271, y=78, zoom=0x40
	break
	video type=1, offset=CINEMATIC_260, x=273, y=82, zoom=0x40
	break
	video type=1, offset=CINEMATIC_260, x=275, y=87, zoom=0x40
	break
	video type=1, offset=CINEMATIC_260, x=225, y=50
	break
	video type=1, offset=CINEMATIC_260, x=225, y=58
	break
	video type=1, offset=CINEMATIC_260, x=153, y=36
	break
	video type=1, offset=CINEMATIC_260, x=111, y=125
	break
	video type=1, offset=CINEMATIC_260, x=120, y=37
	break
	video type=1, offset=CINEMATIC_260, x=23, y=110
	break
	video type=1, offset=CINEMATIC_260, x=27, y=95
	break
	jmp DRAW_CIN_260_AT_3_POSITIONS
LABEL_0257:
	db 0x11

LABEL_0258:
	setPalette 0x0A
	break
	setPalette 0x0D
	break
	setPalette 0x0E
	break
	setPalette 0x0F
	break
	setPalette 0x10
	break
	setPalette 0x10
	break
	setPalette 0x0F
	break
	setPalette 0x0E
	break
	setPalette 0x0D
	break
	setPalette 0x0A
	break
	setPalette 0x0A
	break
	jmp LABEL_0258

LABEL_0287:
	setup channel=0x3C, address=HANG_BLITTING_PAGE_FF
	song id=0x0BD6, delay=0x0000, pos=0x00
	setup channel=0x0A, address=DRAW_CIN_260_AT_3_POSITIONS
	selectVideoPage 0x00
	fill page=0x00, color=0x00
	video type=1, offset=CINEMATIC_070, x=160, y=100
	video type=1, offset=CINEMATIC_071, x=160, y=100
	video type=1, offset=CINEMATIC_072, x=160, y=100
	video type=1, offset=CINEMATIC_073, x=160, y=100
	selectVideoPage 0xFF
	break
	setPalette 0x0B
	setup channel=0x3B, address=HANG_DRAW_CIN_259
	mov [0x02], 0x00FA
	mov [0x03], 0x0014

LABEL_02BC:
	break
	play id=0x0058, freq=0x07, vol=0x10, channel=0x00
	video type=1, offset=CINEMATIC_074, x=160, y=[0x02], zoom=0x40
	sub [0x02], 0x0005
	djnz [0x03], LABEL_02BC
	setup channel=0x09, address=LABEL_0258
	setup channel=0x0B, address=DRAW_CIN_260_AT_3_POSITIONS
	break
	video type=1, offset=CINEMATIC_075, x=160, y=[0x02], zoom=0x40
	setPalette 0x0B
	mov [0x03], 0x000F

LABEL_02E5:
	break
	video type=1, offset=CINEMATIC_075, x=160, y=[0x02], zoom=0x40
	sub [0x02], 0x0005
	djnz [0x03], LABEL_02E5
	add [0x02], 0x0002
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_075, x=160, y=[0x02], zoom=0x40
	selectVideoPage 0xFF
	setPalette 0x0A
	play id=0x0057, freq=0x02, vol=0x20, channel=0x00
	setup channel=0x37, address=LABEL_043E
	deleteChannels first=0x09, last=0x0B
	mov [0x03], 0x0014

DELAY_LOOP_VAR03:
	break
	djnz [0x03], DELAY_LOOP_VAR03
	setup channel=0x37, address=RESET_PAGES_AND_SETUP_CH_0A
	break
	jmp LABEL_0323
LABEL_0322:
	db 0x11

LABEL_0323:
	setup channel=0x3C, address=HANG_BLITTING_PAGE_FF
	setup channel=0x3B, address=HANG_DRAW_CIN_259
	setup channel=0x37, address=LABEL_036A
	play id=0x008B, freq=0x14, vol=0x40, channel=0x00
	deleteChannels first=0x09, last=0x0B
	selectVideoPage 0x00
	fill page=0x00, color=0x00
	video type=1, offset=CINEMATIC_076, x=160, y=100
	video type=1, offset=CINEMATIC_072, x=160, y=100
	video type=1, offset=CINEMATIC_077, x=160, y=100
	video type=1, offset=CINEMATIC_078, x=160, y=100
	selectVideoPage 0xFF
	copyVideoPage src=0x00, dst=0xFF
	video type=1, offset=CINEMATIC_079, x=160, y=[0x02], zoom=0x40
	setPalette 0x13
	mov [0x03], 0x0032

ANIM_CIN_079_LOOP_VAR03:
	video type=1, offset=CINEMATIC_079, x=160, y=[0x02], zoom=0x40
	break
	djnz [0x03], ANIM_CIN_079_LOOP_VAR03
	killChannel

LABEL_036A:
	video type=1, offset=CINEMATIC_080, x=160, y=100
	break
	video type=1, offset=CINEMATIC_081, x=160, y=100
	break
	video type=1, offset=CINEMATIC_082, x=160, y=100
	break
	play id=0x008B, freq=0x1C, vol=0x40, channel=0x01
	video type=1, offset=CINEMATIC_083, x=160, y=100
	break
	video type=1, offset=CINEMATIC_084, x=160, y=100
	break
	video type=1, offset=CINEMATIC_085, x=160, y=100
	break
	video type=1, offset=CINEMATIC_086, x=160, y=100
	play id=0x008B, freq=0x12, vol=0x20, channel=0x01
	mov [0xE6], 0x00A0
	mov [0xE7], 0x00A0
	mov [0xE8], 0x0003

LABEL_03A4:
	break
	sub [0xE6], 0x0002
	add [0xE7], 0x0002
	video type=1, offset=CINEMATIC_086, x=[0xe6], y=100, zoom=0x40
	video type=1, offset=CINEMATIC_086, x=[0xe7], y=100, zoom=0x40
	djnz [0xE8], LABEL_03A4
	play id=0x008B, freq=0x1C, vol=0x40, channel=0x00
	mov [0xE6], 0x00A0
	mov [0xE7], 0x00A0
	mov [0xE8], 0x0006

LABEL_03CD:
	break
	sub [0xE6], 0x0002
	add [0xE7], 0x0002
	video type=1, offset=CINEMATIC_087, x=[0xe6], y=100, zoom=0x40
	video type=1, offset=CINEMATIC_087, x=[0xe7], y=100, zoom=0x40
	djnz [0xE8], LABEL_03CD
	play id=0x008B, freq=0x0A, vol=0x10, channel=0x00
	mov [0xE6], 0x00A0
	mov [0xE7], 0x00A0
	mov [0xE9], 0x0040
	mov [0xE8], 0x0018

LABEL_03FA:
	break
	play id=0x008B, freq=0x22, vol=0x40, channel=0x01
	sub [0xE6], 0x0001
	add [0xE7], 0x0001
	video type=1, offset=CINEMATIC_088, x=[0xe6], y=100, zoom=[0xe9]
	video type=1, offset=CINEMATIC_088, x=[0xe7], y=100, zoom=[0xe9]
	djnz [0xE8], LABEL_03FA
	play id=0x008B, freq=0x0A, vol=0x10, channel=0x01
	deleteChannels first=0x00, last=0x36
	deleteChannels first=0x38, last=0x3B
	deleteChannels first=0x3D, last=0x3F
	jmp LABEL_0085
LABEL_042E:
	db 0x11

LABEL_042F:
	call LABEL_1BAF
	jmp LABEL_0287

HANG_DRAW_CIN_259:
	video type=1, offset=CINEMATIC_259, x=160, y=100
	break
	jmp HANG_DRAW_CIN_259
LABEL_043D:
	db 0x11

LABEL_043E:
	video type=1, offset=CINEMATIC_230, x=160, y=100
	video type=1, offset=CINEMATIC_231, x=160, y=100
	break
	video type=1, offset=CINEMATIC_232, x=160, y=100
	video type=1, offset=CINEMATIC_233, x=160, y=100
	break
	video type=1, offset=CINEMATIC_234, x=160, y=100
	video type=1, offset=CINEMATIC_235, x=160, y=100
	break
	video type=1, offset=CINEMATIC_236, x=160, y=100
	video type=1, offset=CINEMATIC_237, x=160, y=100
	break
	video type=1, offset=CINEMATIC_238, x=160, y=100
	video type=1, offset=CINEMATIC_239, x=160, y=100
	break
	video type=1, offset=CINEMATIC_240, x=160, y=100
	video type=1, offset=CINEMATIC_241, x=160, y=100
	break
	video type=1, offset=CINEMATIC_242, x=160, y=100
	video type=1, offset=CINEMATIC_243, x=160, y=100
	break
	video type=1, offset=CINEMATIC_244, x=160, y=100
	video type=1, offset=CINEMATIC_245, x=160, y=100
	break
	video type=1, offset=CINEMATIC_246, x=160, y=100
	video type=1, offset=CINEMATIC_247, x=160, y=100
	break
	video type=1, offset=CINEMATIC_248, x=160, y=100
	video type=1, offset=CINEMATIC_249, x=160, y=100
	break
	video type=1, offset=CINEMATIC_250, x=160, y=100
	video type=1, offset=CINEMATIC_251, x=160, y=100
	break
	video type=1, offset=CINEMATIC_252, x=160, y=100
	video type=1, offset=CINEMATIC_253, x=160, y=100
	break
	video type=1, offset=CINEMATIC_254, x=160, y=100
	video type=1, offset=CINEMATIC_255, x=160, y=100
	break
	video type=1, offset=CINEMATIC_256, x=160, y=100
	video type=1, offset=CINEMATIC_257, x=160, y=100
	break
	video type=1, offset=CINEMATIC_256, x=160, y=100
	video type=1, offset=CINEMATIC_257, x=160, y=100
	video type=1, offset=CINEMATIC_258, x=132, y=115
	video type=1, offset=CINEMATIC_258, x=162, y=115
	break
	video type=1, offset=CINEMATIC_256, x=160, y=100
	video type=1, offset=CINEMATIC_257, x=160, y=100
	video type=1, offset=CINEMATIC_258, x=159, y=102
	video type=1, offset=CINEMATIC_258, x=135, y=102
	play id=0x0057, freq=0x18, vol=0x40, channel=0x00

LABEL_04E3:
	break
	video type=1, offset=CINEMATIC_256, x=160, y=100
	video type=1, offset=CINEMATIC_257, x=160, y=100
	video type=1, offset=CINEMATIC_258, x=158, y=102
	video type=1, offset=CINEMATIC_258, x=141, y=100
	jmp LABEL_04E3
LABEL_04F7:
	db 0x11

LABEL_04F8:
	video type=1, offset=CINEMATIC_153, x=[0x6f], y=[0x6c], zoom=[0x6a]
	video type=1, offset=CINEMATIC_154, x=[0x6f], y=[0x6c], zoom=[0x6a]
	break
	video type=1, offset=CINEMATIC_155, x=[0x6f], y=[0x6c], zoom=[0x6a]
	video type=1, offset=CINEMATIC_154, x=[0x6f], y=[0x6c], zoom=[0x6a]
	break
	video type=1, offset=CINEMATIC_156, x=[0x6f], y=[0x6c], zoom=[0x6a]
	video type=1, offset=CINEMATIC_154, x=[0x6f], y=[0x6c], zoom=[0x6a]
	break
	video type=1, offset=CINEMATIC_157, x=[0x6f], y=[0x6c], zoom=[0x6a]
	video type=1, offset=CINEMATIC_154, x=[0x6f], y=[0x6c], zoom=[0x6a]
	break
	video type=1, offset=CINEMATIC_158, x=[0x6f], y=[0x6c], zoom=[0x6a]
	video type=1, offset=CINEMATIC_154, x=[0x6f], y=[0x6c], zoom=[0x6a]
	break
	video type=1, offset=CINEMATIC_155, x=[0x6f], y=[0x6c], zoom=[0x6a]
	video type=1, offset=CINEMATIC_154, x=[0x6f], y=[0x6c], zoom=[0x6a]
	break
	jmp LABEL_04F8
LABEL_0549:
	db 0x11
