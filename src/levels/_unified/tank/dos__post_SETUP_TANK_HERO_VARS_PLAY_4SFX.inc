LABEL_00E4:
	break
	call DRAW_CIN_093_TO_097_VAR
	mov [0xF8], [0x2B]
	add [0xF8], 0x0003
	add [0x01], [0xF8]
	djnz [0x2B], LABEL_00E4
	jmp LABEL_001F

RESET_PAGES_AND_SETUP_CH_0A:
	killChannel
	copyVideoPage src=0x03, dst=0x00
	killChannel
	setup channel=0x0A, address=LABEL_0113

HANG_DRAW_CIN_037:
	video type=1, offset=CINEMATIC_037, x=160, y=100
	break
	jmp HANG_DRAW_CIN_037

HANG_DRAW_CIN_036:
	video type=1, offset=CINEMATIC_036, x=160, y=100
	break
	jmp HANG_DRAW_CIN_036
LABEL_0112:
	db 0x11

LABEL_0113:
	video type=1, offset=CINEMATIC_087, x=81, y=131
	break
	video type=1, offset=CINEMATIC_087, x=96, y=121
	break
	video type=1, offset=CINEMATIC_087, x=86, y=127
	break
	jmp LABEL_0113
LABEL_0125:
	db 0x11

LABEL_0126:
	video type=1, offset=CINEMATIC_275, x=152, y=101
	break
	video type=1, offset=CINEMATIC_275, x=143, y=136
	break
	video type=1, offset=CINEMATIC_275, x=148, y=124
	break
	video type=1, offset=CINEMATIC_275, x=151, y=112
	break
	video type=1, offset=CINEMATIC_275, x=206, y=52
	break
	video type=1, offset=CINEMATIC_275, x=205, y=166
	break
	video type=1, offset=CINEMATIC_275, x=196, y=50
	break
	video type=1, offset=CINEMATIC_275, x=188, y=49
	break
	video type=1, offset=CINEMATIC_275, x=179, y=49
	break
	video type=1, offset=CINEMATIC_275, x=179, y=78
	break
	video type=1, offset=CINEMATIC_275, x=205, y=81
	break
	video type=1, offset=CINEMATIC_275, x=103, y=89
	break
	video type=1, offset=CINEMATIC_275, x=51, y=130
	break
	video type=1, offset=CINEMATIC_275, x=104, y=46
	break
	video type=1, offset=CINEMATIC_275, x=101, y=46
	break
	video type=1, offset=CINEMATIC_275, x=99, y=48
	break
	video type=1, offset=CINEMATIC_275, x=95, y=50
	break
	video type=1, offset=CINEMATIC_275, x=96, y=60
	break
	video type=1, offset=CINEMATIC_275, x=98, y=69
	break
	video type=1, offset=CINEMATIC_275, x=95, y=72
	break
	video type=1, offset=CINEMATIC_275, x=92, y=75
	break
	video type=1, offset=CINEMATIC_275, x=49, y=69
	break
	video type=1, offset=CINEMATIC_275, x=51, y=76
	break
	video type=1, offset=CINEMATIC_275, x=54, y=83
	break
	video type=1, offset=CINEMATIC_275, x=56, y=92
	break
	video type=1, offset=CINEMATIC_275, x=62, y=88
	break
	video type=1, offset=CINEMATIC_275, x=66, y=85
	break
	video type=1, offset=CINEMATIC_275, x=71, y=82
	break
	video type=1, offset=CINEMATIC_275, x=70, y=75
	break
	video type=1, offset=CINEMATIC_275, x=66, y=76
	break
	video type=1, offset=CINEMATIC_275, x=63, y=79
	break
	video type=1, offset=CINEMATIC_275, x=60, y=80
	break
	video type=1, offset=CINEMATIC_275, x=59, y=74
	break
	video type=1, offset=CINEMATIC_275, x=62, y=72
	break
	video type=1, offset=CINEMATIC_275, x=65, y=70
	break
	video type=1, offset=CINEMATIC_275, x=69, y=68
	break
	video type=1, offset=CINEMATIC_275, x=228, y=107
	break
	video type=1, offset=CINEMATIC_275, x=227, y=112
	break
	video type=1, offset=CINEMATIC_275, x=225, y=117
	break
	video type=1, offset=CINEMATIC_275, x=265, y=70, zoom=0x40
	break
	video type=1, offset=CINEMATIC_275, x=268, y=73, zoom=0x40
	break
	video type=1, offset=CINEMATIC_275, x=271, y=78, zoom=0x40
	break
	video type=1, offset=CINEMATIC_275, x=273, y=82, zoom=0x40
	break
	video type=1, offset=CINEMATIC_275, x=275, y=87, zoom=0x40
	break
	video type=1, offset=CINEMATIC_275, x=225, y=50
	break
	video type=1, offset=CINEMATIC_275, x=225, y=58
	break
	video type=1, offset=CINEMATIC_275, x=153, y=36
	break
	video type=1, offset=CINEMATIC_275, x=111, y=125
	break
	video type=1, offset=CINEMATIC_275, x=120, y=37
	break
	video type=1, offset=CINEMATIC_275, x=23, y=110
	break
	video type=1, offset=CINEMATIC_275, x=27, y=95
	break
	jmp LABEL_0126
LABEL_022D:
	db 0x11

LABEL_022E:
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
	jmp LABEL_022E

LABEL_025D:
	setup channel=0x3C, address=HANG_BLITTING_PAGE_FF
	setup channel=0x0A, address=LABEL_0126
	selectVideoPage 0x00
	fill page=0x00, color=0x00
	video type=1, offset=CINEMATIC_226, x=160, y=100
	video type=1, offset=CINEMATIC_227, x=160, y=100
	video type=1, offset=CINEMATIC_228, x=160, y=100
	video type=1, offset=CINEMATIC_229, x=160, y=100
	selectVideoPage 0xFF
	break
	setPalette 0x0B
	setup channel=0x3B, address=HANG_DRAW_CIN_274
	mov [0x02], 0x00FA
	mov [0x03], 0x0014

LABEL_028C:
	break
	play id=0x0058, freq=0x07, vol=0x10, channel=0x00
	video type=1, offset=CINEMATIC_230, x=160, y=[0x02], zoom=0x40
	sub [0x02], 0x0005
	djnz [0x03], LABEL_028C
	setup channel=0x09, address=LABEL_022E
	setup channel=0x0B, address=LABEL_0126
	break
	video type=1, offset=CINEMATIC_231, x=160, y=[0x02], zoom=0x40
	setPalette 0x0B
	mov [0x03], 0x000F

LABEL_02B5:
	break
	video type=1, offset=CINEMATIC_231, x=160, y=[0x02], zoom=0x40
	sub [0x02], 0x0005
	djnz [0x03], LABEL_02B5
	add [0x02], 0x0002
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_231, x=160, y=[0x02], zoom=0x40
	selectVideoPage 0xFF
	setPalette 0x0A
	play id=0x0057, freq=0x02, vol=0x20, channel=0x00
	setup channel=0x37, address=LABEL_0466
	deleteChannels first=0x09, last=0x0B
	mov [0x03], 0x0014

DELAY_LOOP_VAR03:
	break
	djnz [0x03], DELAY_LOOP_VAR03
	setup channel=0x37, address=RESET_PAGES_AND_SETUP_CH_0A
	break
	jmp LABEL_02F3
LABEL_02F2:
	db 0x11

LABEL_02F3:
	setup channel=0x3C, address=HANG_BLITTING_PAGE_FF
	setup channel=0x3B, address=HANG_DRAW_CIN_274
	setup channel=0x37, address=LABEL_033A
	play id=0x008B, freq=0x14, vol=0x40, channel=0x00
	deleteChannels first=0x09, last=0x0B
	selectVideoPage 0x00
	fill page=0x00, color=0x00
	video type=1, offset=CINEMATIC_232, x=160, y=100
	video type=1, offset=CINEMATIC_228, x=160, y=100
	video type=1, offset=CINEMATIC_233, x=160, y=100
	video type=1, offset=CINEMATIC_234, x=160, y=100
	selectVideoPage 0xFF
	copyVideoPage src=0x00, dst=0xFF
	video type=1, offset=CINEMATIC_235, x=160, y=[0x02], zoom=0x40
	setPalette 0x13
	mov [0x03], 0x0032

ANIM_CIN_235_LOOP_VAR03:
	video type=1, offset=CINEMATIC_235, x=160, y=[0x02], zoom=0x40
	break
	djnz [0x03], ANIM_CIN_235_LOOP_VAR03
	killChannel

LABEL_033A:
	video type=1, offset=CINEMATIC_236, x=160, y=100
	break
	video type=1, offset=CINEMATIC_237, x=160, y=100
	break
	video type=1, offset=CINEMATIC_238, x=160, y=100
	break
	play id=0x008B, freq=0x1C, vol=0x40, channel=0x01
	video type=1, offset=CINEMATIC_239, x=160, y=100
	break
	video type=1, offset=CINEMATIC_240, x=160, y=100
	break
	video type=1, offset=CINEMATIC_241, x=160, y=100
	break
	video type=1, offset=CINEMATIC_242, x=160, y=100
	play id=0x008B, freq=0x12, vol=0x20, channel=0x01
	mov [0xE6], 0x00A0
	mov [0xE7], 0x00A0
	mov [0xE8], 0x0003

LABEL_0374:
	break
	sub [0xE6], 0x0002
	add [0xE7], 0x0002
	video type=1, offset=CINEMATIC_242, x=[0xe6], y=100, zoom=0x40
	video type=1, offset=CINEMATIC_242, x=[0xe7], y=100, zoom=0x40
	djnz [0xE8], LABEL_0374
	play id=0x008B, freq=0x1C, vol=0x40, channel=0x00
	mov [0xE6], 0x00A0
	mov [0xE7], 0x00A0
	mov [0xE8], 0x0006

LABEL_039D:
	break
	sub [0xE6], 0x0002
	add [0xE7], 0x0002
	video type=1, offset=CINEMATIC_243, x=[0xe6], y=100, zoom=0x40
	video type=1, offset=CINEMATIC_243, x=[0xe7], y=100, zoom=0x40
	djnz [0xE8], LABEL_039D
	play id=0x008B, freq=0x0A, vol=0x10, channel=0x00
	mov [0xE6], 0x00A0
	mov [0xE7], 0x00A0
	mov [0xE9], 0x0040
	mov [0xE8], 0x0018

LABEL_03CA:
	break
	play id=0x008B, freq=0x22, vol=0x40, channel=0x01
	sub [0xE6], 0x0001
	add [0xE7], 0x0001
	video type=1, offset=CINEMATIC_244, x=[0xe6], y=100, zoom=[0xe9]
	video type=1, offset=CINEMATIC_244, x=[0xe7], y=100, zoom=[0xe9]
	djnz [0xE8], LABEL_03CA
	play id=0x008B, freq=0x0A, vol=0x10, channel=0x01
	deleteChannels first=0x00, last=0x36
	deleteChannels first=0x38, last=0x3B
	deleteChannels first=0x3D, last=0x3F
	jmp LABEL_007E
LABEL_03FE:
	db 0x11

LABEL_03FF:
	call LABEL_1C8C
	jmp LABEL_025D
	setup channel=0x3C, address=HANG_BLITTING_PAGE_FF
	selectVideoPage 0x00
	fill page=0x00, color=0x00
	video type=1, offset=CINEMATIC_226, x=160, y=100
	video type=1, offset=CINEMATIC_227, x=160, y=100
	video type=1, offset=CINEMATIC_228, x=160, y=100
	video type=1, offset=CINEMATIC_229, x=160, y=100
	selectVideoPage 0xFF
	break
	setPalette 0x0C
	setup channel=0x3B, address=HANG_DRAW_CIN_274
	mov [0x02], 0x00FA
	mov [0x03], 0x0023

LABEL_0430:
	break
	video type=1, offset=CINEMATIC_278, x=160, y=[0x02], zoom=0x40
	sub [0x02], 0x0005
	djnz [0x03], LABEL_0430
	mov [0x03], 0x000F

LABEL_0442:
	break
	video type=1, offset=CINEMATIC_278, x=160, y=[0x02], zoom=0x40
	djnz [0x03], LABEL_0442
	add [0x02], 0x0002
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_231, x=160, y=[0x02], zoom=0x40
	selectVideoPage 0xFF
	jmp LABEL_025D
LABEL_045C:
	db 0x11

HANG_DRAW_CIN_274:
	video type=1, offset=CINEMATIC_274, x=160, y=100
	break
	jmp HANG_DRAW_CIN_274
LABEL_0465:
	db 0x11

LABEL_0466:
	video type=1, offset=CINEMATIC_245, x=160, y=100
	video type=1, offset=CINEMATIC_246, x=160, y=100
	break
	video type=1, offset=CINEMATIC_247, x=160, y=100
	video type=1, offset=CINEMATIC_248, x=160, y=100
	break
	video type=1, offset=CINEMATIC_249, x=160, y=100
	video type=1, offset=CINEMATIC_250, x=160, y=100
	break
	video type=1, offset=CINEMATIC_251, x=160, y=100
	video type=1, offset=CINEMATIC_252, x=160, y=100
	break
	video type=1, offset=CINEMATIC_253, x=160, y=100
	video type=1, offset=CINEMATIC_254, x=160, y=100
	break
	video type=1, offset=CINEMATIC_255, x=160, y=100
	video type=1, offset=CINEMATIC_256, x=160, y=100
	break
	video type=1, offset=CINEMATIC_257, x=160, y=100
	video type=1, offset=CINEMATIC_258, x=160, y=100
	break
	video type=1, offset=CINEMATIC_259, x=160, y=100
	video type=1, offset=CINEMATIC_260, x=160, y=100
	break
	video type=1, offset=CINEMATIC_261, x=160, y=100
	video type=1, offset=CINEMATIC_262, x=160, y=100
	break
	video type=1, offset=CINEMATIC_263, x=160, y=100
	video type=1, offset=CINEMATIC_264, x=160, y=100
	break
	video type=1, offset=CINEMATIC_265, x=160, y=100
	video type=1, offset=CINEMATIC_266, x=160, y=100
	break
	video type=1, offset=CINEMATIC_267, x=160, y=100
	video type=1, offset=CINEMATIC_268, x=160, y=100
	break
	video type=1, offset=CINEMATIC_269, x=160, y=100
	video type=1, offset=CINEMATIC_270, x=160, y=100
	break
	video type=1, offset=CINEMATIC_271, x=160, y=100
	video type=1, offset=CINEMATIC_272, x=160, y=100
	break
	video type=1, offset=CINEMATIC_271, x=160, y=100
	video type=1, offset=CINEMATIC_272, x=160, y=100
	video type=1, offset=CINEMATIC_273, x=132, y=115
	video type=1, offset=CINEMATIC_273, x=162, y=115
	break
	video type=1, offset=CINEMATIC_271, x=160, y=100
	video type=1, offset=CINEMATIC_272, x=160, y=100
	video type=1, offset=CINEMATIC_273, x=159, y=102
	video type=1, offset=CINEMATIC_273, x=135, y=102
	play id=0x0057, freq=0x18, vol=0x40, channel=0x00

LABEL_050B:
	break
	video type=1, offset=CINEMATIC_271, x=160, y=100
	video type=1, offset=CINEMATIC_272, x=160, y=100
	video type=1, offset=CINEMATIC_273, x=158, y=102
	video type=1, offset=CINEMATIC_273, x=141, y=100
	jmp LABEL_050B
LABEL_051F:
	db 0x11

LABEL_0520:
	video type=1, offset=CINEMATIC_129, x=[0x6f], y=[0x6c], zoom=[0x6a]
	video type=1, offset=CINEMATIC_130, x=[0x6f], y=[0x6c], zoom=[0x6a]
	break
	video type=1, offset=CINEMATIC_131, x=[0x6f], y=[0x6c], zoom=[0x6a]
	video type=1, offset=CINEMATIC_130, x=[0x6f], y=[0x6c], zoom=[0x6a]
	break
	video type=1, offset=CINEMATIC_132, x=[0x6f], y=[0x6c], zoom=[0x6a]
	video type=1, offset=CINEMATIC_130, x=[0x6f], y=[0x6c], zoom=[0x6a]
	break
	video type=1, offset=CINEMATIC_133, x=[0x6f], y=[0x6c], zoom=[0x6a]
	video type=1, offset=CINEMATIC_130, x=[0x6f], y=[0x6c], zoom=[0x6a]
	break
	video type=1, offset=CINEMATIC_134, x=[0x6f], y=[0x6c], zoom=[0x6a]
	video type=1, offset=CINEMATIC_130, x=[0x6f], y=[0x6c], zoom=[0x6a]
	break
	video type=1, offset=CINEMATIC_131, x=[0x6f], y=[0x6c], zoom=[0x6a]
	video type=1, offset=CINEMATIC_130, x=[0x6f], y=[0x6c], zoom=[0x6a]
	break
	jmp LABEL_0520
LABEL_0571:
	db 0x11
