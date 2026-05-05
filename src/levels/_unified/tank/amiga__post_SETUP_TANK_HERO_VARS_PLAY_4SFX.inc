LABEL_00D2:
	break
	call DRAW_CIN_093_TO_097_VAR
	mov [0xF8], [0x2B]
	add [0xF8], 0x0003
	add [0x01], [0xF8]
	djnz [0x2B], LABEL_00D2
	jmp LABEL_001B

RESET_PAGES_AND_SETUP_CH_0A:
	killChannel
	copyVideoPage src=0x03, dst=0x00
	killChannel
	setup channel=0x0A, address=LABEL_0101

HANG_DRAW_CIN_035:
	video offset=CINEMATIC_035, x=160, y=100
	break
	jmp HANG_DRAW_CIN_035

HANG_DRAW_CIN_034:
	video offset=CINEMATIC_034, x=160, y=100
	break
	jmp HANG_DRAW_CIN_034
LABEL_0100:
	db 0x11

LABEL_0101:
	video offset=CINEMATIC_100, x=81, y=131
	break
	video offset=CINEMATIC_100, x=96, y=121
	break
	video offset=CINEMATIC_100, x=86, y=127
	break
	jmp LABEL_0101
LABEL_0113:
	db 0x11

LABEL_0114:
	video offset=CINEMATIC_223, x=152, y=101
	break
	video offset=CINEMATIC_223, x=143, y=136
	break
	video offset=CINEMATIC_223, x=148, y=124
	break
	video offset=CINEMATIC_223, x=151, y=112
	break
	video offset=CINEMATIC_223, x=206, y=52
	break
	video offset=CINEMATIC_223, x=205, y=166
	break
	video offset=CINEMATIC_223, x=196, y=50
	break
	video offset=CINEMATIC_223, x=188, y=49
	break
	video offset=CINEMATIC_223, x=179, y=49
	break
	video offset=CINEMATIC_223, x=179, y=78
	break
	video offset=CINEMATIC_223, x=205, y=81
	break
	video offset=CINEMATIC_223, x=103, y=89
	break
	video offset=CINEMATIC_223, x=51, y=130
	break
	video offset=CINEMATIC_223, x=104, y=46
	break
	video offset=CINEMATIC_223, x=101, y=46
	break
	video offset=CINEMATIC_223, x=99, y=48
	break
	video offset=CINEMATIC_223, x=95, y=50
	break
	video offset=CINEMATIC_223, x=96, y=60
	break
	video offset=CINEMATIC_223, x=98, y=69
	break
	video offset=CINEMATIC_223, x=95, y=72
	break
	video offset=CINEMATIC_223, x=92, y=75
	break
	video offset=CINEMATIC_223, x=49, y=69
	break
	video offset=CINEMATIC_223, x=51, y=76
	break
	video offset=CINEMATIC_223, x=54, y=83
	break
	video offset=CINEMATIC_223, x=56, y=92
	break
	video offset=CINEMATIC_223, x=62, y=88
	break
	video offset=CINEMATIC_223, x=66, y=85
	break
	video offset=CINEMATIC_223, x=71, y=82
	break
	video offset=CINEMATIC_223, x=70, y=75
	break
	video offset=CINEMATIC_223, x=66, y=76
	break
	video offset=CINEMATIC_223, x=63, y=79
	break
	video offset=CINEMATIC_223, x=60, y=80
	break
	video offset=CINEMATIC_223, x=59, y=74
	break
	video offset=CINEMATIC_223, x=62, y=72
	break
	video offset=CINEMATIC_223, x=65, y=70
	break
	video offset=CINEMATIC_223, x=69, y=68
	break
	video offset=CINEMATIC_223, x=228, y=107
	break
	video offset=CINEMATIC_223, x=227, y=112
	break
	video offset=CINEMATIC_223, x=225, y=117
	break
	video offset=CINEMATIC_223, x=265, y=70
	break
	video offset=CINEMATIC_223, x=268, y=73
	break
	video offset=CINEMATIC_223, x=271, y=78
	break
	video offset=CINEMATIC_223, x=273, y=82
	break
	video offset=CINEMATIC_223, x=275, y=87
	break
	video offset=CINEMATIC_223, x=225, y=50
	break
	video offset=CINEMATIC_223, x=225, y=58
	break
	video offset=CINEMATIC_223, x=153, y=36
	break
	video offset=CINEMATIC_223, x=111, y=125
	break
	video offset=CINEMATIC_223, x=120, y=37
	break
	video offset=CINEMATIC_223, x=23, y=110
	break
	video offset=CINEMATIC_223, x=27, y=95
	break
	jmp LABEL_0114
LABEL_021B:
	db 0x11

LABEL_021C:
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
	jmp LABEL_021C

LABEL_024B:
	setup channel=0x3C, address=HANG_BLITTING_PAGE_FF
	setup channel=0x0A, address=LABEL_0114
	selectVideoPage 0x00
	fill page=0x00, color=0x00
	video offset=CINEMATIC_174, x=160, y=100
	video offset=CINEMATIC_175, x=160, y=100
	video offset=CINEMATIC_176, x=160, y=100
	video offset=CINEMATIC_177, x=160, y=100
	selectVideoPage 0xFF
	break
	setPalette 0x0B
	setup channel=0x3B, address=HANG_DRAW_CIN_222
	mov [0x02], 0x00FA
	mov [0x03], 0x0014

LABEL_027A:
	break
	play id=0x0058, freq=0x07, vol=0x10, channel=0x00
	video offset=CINEMATIC_178, x=160, y=[0x02]
	sub [0x02], 0x0005
	djnz [0x03], LABEL_027A
	setup channel=0x09, address=LABEL_021C
	setup channel=0x0B, address=LABEL_0114
	break
	video offset=CINEMATIC_179, x=160, y=[0x02]
	setPalette 0x0B
	mov [0x03], 0x000F

LABEL_02A3:
	break
	video offset=CINEMATIC_179, x=160, y=[0x02]
	sub [0x02], 0x0005
	djnz [0x03], LABEL_02A3
	add [0x02], 0x0002
	selectVideoPage 0x00
	video offset=CINEMATIC_179, x=160, y=[0x02]
	selectVideoPage 0xFF
	setPalette 0x0A
	play id=0x0057, freq=0x02, vol=0x20, channel=0x00
	setup channel=0x37, address=LABEL_0454
	deleteChannels first=0x09, last=0x0B
	mov [0x03], 0x0014

DELAY_LOOP_VAR03:
	break
	djnz [0x03], DELAY_LOOP_VAR03
	setup channel=0x37, address=RESET_PAGES_AND_SETUP_CH_0A
	break
	jmp LABEL_02E1
LABEL_02E0:
	db 0x11

LABEL_02E1:
	setup channel=0x3C, address=HANG_BLITTING_PAGE_FF
	setup channel=0x3B, address=HANG_DRAW_CIN_222
	setup channel=0x37, address=LABEL_0328
	play id=0x008B, freq=0x14, vol=0x40, channel=0x00
	deleteChannels first=0x09, last=0x0B
	selectVideoPage 0x00
	fill page=0x00, color=0x00
	video offset=CINEMATIC_180, x=160, y=100
	video offset=CINEMATIC_176, x=160, y=100
	video offset=CINEMATIC_181, x=160, y=100
	video offset=CINEMATIC_182, x=160, y=100
	selectVideoPage 0xFF
	copyVideoPage src=0x00, dst=0xFF
	video offset=CINEMATIC_183, x=160, y=[0x02]
	setPalette 0x13
	mov [0x03], 0x0032

ANIM_CIN_183_LOOP_VAR03:
	video offset=CINEMATIC_183, x=160, y=[0x02]
	break
	djnz [0x03], ANIM_CIN_183_LOOP_VAR03
	killChannel

LABEL_0328:
	video offset=CINEMATIC_184, x=160, y=100
	break
	video offset=CINEMATIC_185, x=160, y=100
	break
	video offset=CINEMATIC_186, x=160, y=100
	break
	play id=0x008B, freq=0x1C, vol=0x40, channel=0x01
	video offset=CINEMATIC_187, x=160, y=100
	break
	video offset=CINEMATIC_188, x=160, y=100
	break
	video offset=CINEMATIC_189, x=160, y=100
	break
	video offset=CINEMATIC_190, x=160, y=100
	play id=0x008B, freq=0x12, vol=0x20, channel=0x01
	mov [0xE6], 0x00A0
	mov [0xE7], 0x00A0
	mov [0xE8], 0x0003

LABEL_0362:
	break
	sub [0xE6], 0x0002
	add [0xE7], 0x0002
	video offset=CINEMATIC_190, x=[0xe6], y=100
	video offset=CINEMATIC_190, x=[0xe7], y=100
	djnz [0xE8], LABEL_0362
	play id=0x008B, freq=0x1C, vol=0x40, channel=0x00
	mov [0xE6], 0x00A0
	mov [0xE7], 0x00A0
	mov [0xE8], 0x0006

LABEL_038B:
	break
	sub [0xE6], 0x0002
	add [0xE7], 0x0002
	video offset=CINEMATIC_191, x=[0xe6], y=100
	video offset=CINEMATIC_191, x=[0xe7], y=100
	djnz [0xE8], LABEL_038B
	play id=0x008B, freq=0x0A, vol=0x10, channel=0x00
	mov [0xE6], 0x00A0
	mov [0xE7], 0x00A0
	mov [0xE9], 0x0040
	mov [0xE8], 0x0018

LABEL_03B8:
	break
	play id=0x008B, freq=0x22, vol=0x40, channel=0x01
	sub [0xE6], 0x0001
	add [0xE7], 0x0001
	video offset=CINEMATIC_192, x=[0xe6], y=100, zoom=[0xe9]
	video offset=CINEMATIC_192, x=[0xe7], y=100, zoom=[0xe9]
	djnz [0xE8], LABEL_03B8
	play id=0x008B, freq=0x0A, vol=0x10, channel=0x01
	deleteChannels first=0x00, last=0x36
	deleteChannels first=0x38, last=0x3B
	deleteChannels first=0x3D, last=0x3F
	jmp LABEL_0072
LABEL_03EC:
	db 0x11

LABEL_03ED:
	call LABEL_1786
	jmp LABEL_024B
LABEL_03F3:
	db 0x08, 0x3C, 0x1A, 0xB0, 0x0D, 0x00, 0x0E, 0x00
	db 0x00, 0xA1, 0x1B, 0xA0, 0x64, 0xA1, 0xCE, 0xA0
	db 0x64, 0xA1, 0xD8, 0xA0, 0x64, 0xA2, 0x1A, 0xA0
	db 0x64, 0x0D, 0xFF, 0x06, 0x0B, 0x0C, 0xFF, 0x08
	db 0x3B, 0x04, 0x4B, 0x00, 0x02, 0x00, 0xFA, 0x00
	db 0x03, 0x00, 0x23, 0x06, 0x64, 0x27, 0xC3, 0xA0
	db 0x02, 0x03, 0x02, 0xFF, 0xFB, 0x09, 0x03, 0x04
	db 0x1E, 0x00, 0x03, 0x00, 0x0F, 0x06, 0x64, 0x27
	db 0xC3, 0xA0, 0x02, 0x09, 0x03, 0x04, 0x30, 0x03
	db 0x02, 0x00, 0x02, 0x0D, 0x00, 0x64, 0x20, 0x7D
	db 0xA0, 0x02, 0x0D, 0xFF, 0x07, 0x02, 0x4B, 0x11

HANG_DRAW_CIN_222:
	video offset=CINEMATIC_222, x=160, y=100
	break
	jmp HANG_DRAW_CIN_222
LABEL_0453:
	db 0x11

LABEL_0454:
	video offset=CINEMATIC_193, x=160, y=100
	video offset=CINEMATIC_194, x=160, y=100
	break
	video offset=CINEMATIC_195, x=160, y=100
	video offset=CINEMATIC_196, x=160, y=100
	break
	video offset=CINEMATIC_197, x=160, y=100
	video offset=CINEMATIC_198, x=160, y=100
	break
	video offset=CINEMATIC_199, x=160, y=100
	video offset=CINEMATIC_200, x=160, y=100
	break
	video offset=CINEMATIC_201, x=160, y=100
	video offset=CINEMATIC_202, x=160, y=100
	break
	video offset=CINEMATIC_203, x=160, y=100
	video offset=CINEMATIC_204, x=160, y=100
	break
	video offset=CINEMATIC_205, x=160, y=100
	video offset=CINEMATIC_206, x=160, y=100
	break
	video offset=CINEMATIC_207, x=160, y=100
	video offset=CINEMATIC_208, x=160, y=100
	break
	video offset=CINEMATIC_209, x=160, y=100
	video offset=CINEMATIC_210, x=160, y=100
	break
	video offset=CINEMATIC_211, x=160, y=100
	video offset=CINEMATIC_212, x=160, y=100
	break
	video offset=CINEMATIC_213, x=160, y=100
	video offset=CINEMATIC_214, x=160, y=100
	break
	video offset=CINEMATIC_215, x=160, y=100
	video offset=CINEMATIC_216, x=160, y=100
	break
	video offset=CINEMATIC_217, x=160, y=100
	video offset=CINEMATIC_218, x=160, y=100
	break
	video offset=CINEMATIC_219, x=160, y=100
	video offset=CINEMATIC_220, x=160, y=100
	break
	video offset=CINEMATIC_219, x=160, y=100
	video offset=CINEMATIC_220, x=160, y=100
	video offset=CINEMATIC_221, x=132, y=115
	video offset=CINEMATIC_221, x=162, y=115
	break
	video offset=CINEMATIC_219, x=160, y=100
	video offset=CINEMATIC_220, x=160, y=100
	video offset=CINEMATIC_221, x=159, y=102
	video offset=CINEMATIC_221, x=135, y=102
	play id=0x0057, freq=0x18, vol=0x40, channel=0x00

LABEL_04F9:
	break
	video offset=CINEMATIC_219, x=160, y=100
	video offset=CINEMATIC_220, x=160, y=100
	video offset=CINEMATIC_221, x=158, y=102
	video offset=CINEMATIC_221, x=141, y=100
	jmp LABEL_04F9
LABEL_050D:
	db 0x11

LABEL_050E:
	break
	je [0x63], 0x00, LABEL_050E
	setup channel=0x35, address=RESET_PAGES_AND_SETUP_CH_0A
	setup channel=0x01, address=RESET_PAGES_AND_SETUP_CH_0A
	unfreezeChannels first=0x00, last=0x22
	deleteChannels first=0x39, last=0x3B
	selectVideoPage 0x00
	video offset=CINEMATIC_085, x=160, y=100
	selectVideoPage 0xFF
	break
	play id=0x008E, freq=0x18, vol=0x40, channel=0x01
	video offset=CINEMATIC_086, x=160, y=100
	break
	play id=0x008E, freq=0x14, vol=0x40, channel=0x00
	video offset=CINEMATIC_087, x=160, y=100
	break
	video offset=CINEMATIC_088, x=160, y=100
	break
	video offset=CINEMATIC_089, x=160, y=100
	break
	video offset=CINEMATIC_090, x=160, y=100
	break
	video offset=CINEMATIC_091, x=160, y=100
	break
	video offset=CINEMATIC_092, x=160, y=100
	break
	video offset=CINEMATIC_093, x=160, y=100
	break
	video offset=CINEMATIC_094, x=160, y=100
	break
	video offset=CINEMATIC_095, x=160, y=100
	freezeChannels first=0x00, last=0x27
	deleteChannels first=0x00, last=0x27
	deleteChannels first=0x29, last=0x3B
	fill page=0x03, color=0x01
	break
	play id=0x0057, freq=0x14, vol=0x40, channel=0x02
	video offset=CINEMATIC_096, x=77, y=201, zoom=0x40
	video offset=CINEMATIC_097, x=137, y=220, zoom=0x40
	break
	play id=0x0057, freq=0x14, vol=0x40, channel=0x03
	mov [PAUSE_SLICES], 0x0008
	video offset=CINEMATIC_098, x=97, y=146
	video offset=CINEMATIC_099, x=185, y=172
	break
	video offset=CINEMATIC_096, x=117, y=85
	video offset=CINEMATIC_097, x=237, y=126
	break
	video offset=CINEMATIC_098, x=138, y=24
	video offset=CINEMATIC_099, x=287, y=79
	break
	video offset=CINEMATIC_096, x=148, y=65533
	video offset=CINEMATIC_097, x=336, y=32
	break
	break
	bankSwitch 6;  Capsule Lands at the Bath
	killChannel

LABEL_05C3:
	je [HACK_VAR_67], 0x00, LABEL_0642
	jl [0x5F], 0x00, COPY_VAR62_TO_VAR5F
	jg [HACK_VAR_67], 0x02, LABEL_05E1
	jl [0x5F], 0x02, LABEL_0661
	je [0x5F], 0x03, LABEL_0661

LABEL_05E1:
	je [0x5F], 0x1E, SET_VAR5F_TO_0016
	je [0x5F], 0x20, LABEL_0651
	je [0x5F], 0x21, SET_VAR5F_TO_0018
	je [0x5F], 0x23, LABEL_0651
	jg [0x5F], 0x22, COPY_VAR62_TO_VAR5F
	je [0x5F], 0x0F, SET_VAR5F_14_OR_COPY_VAR62
	je [0x5F], 0x17, SET_VAR5F_14_OR_COPY_VAR62
	je [0x5F], 0x03, COPY_VAR62_TO_VAR5F
	je [0x5F], 0x04, COPY_VAR62_TO_VAR5F
	je [0x5F], 0x05, COPY_VAR62_TO_VAR5F
	je [0x5F], 0x06, COPY_VAR62_TO_VAR5F
	je [0x5F], 0x07, COPY_VAR62_TO_VAR5F
	je [0x5F], 0x0A, LABEL_0691
	je [0x5F], 0x12, LABEL_0691
	je [0x5F], 0x0D, LABEL_0681
	je [0x5F], 0x19, LABEL_0691
	ret

LABEL_0642:
	je [0x5F], 0x0B, SHARED_RET
	je [0x5F], 0x13, SHARED_RET
	jmp COPY_VAR62_TO_VAR5F

LABEL_0651:
	je [0x62], 0x22, SET_VAR5F_TO_001B
	mov [0x5F], 0x0022
	ret

SET_VAR5F_TO_001B:
	mov [0x5F], 0x001B
	ret

LABEL_0661:
	je [0x62], 0x02, INCREMENT_VAR5F_BY_8
	mov [0x5F], 0x0002
	ret
