LABEL_397E:
	jne [HACK_VAR_67], 0x8D, LABEL_3989
	video offset=CINEMATIC_119, x=277, y=35

LABEL_3989:
	break
	djnz [0x29], LABEL_397E
	mov [0x29], 0x0014

LABEL_3992:
	jne [HACK_VAR_67], 0x8D, LABEL_399D
	video offset=CINEMATIC_119, x=277, y=34

LABEL_399D:
	break
	djnz [0x29], LABEL_3992
	jmp INLINE_SET_VAR29_TO_8
LABEL_39A5:
	db 0x11

LABEL_39A6:
	video offset=CINEMATIC_286, x=191, y=73
	break
	video offset=CINEMATIC_287, x=219, y=70
	break
	video offset=CINEMATIC_287, x=235, y=82
	break
	video offset=CINEMATIC_079, x=253, y=112
	setup channel=0x04, address=KILL_CHANNEL_LANDING
	break
	play id=0x0060, freq=0x14, vol=0x40, channel=0x02
	video offset=CINEMATIC_279, x=283, y=98
	video offset=CINEMATIC_074, x=260, y=120
	break
	video offset=CINEMATIC_277, x=283, y=98
	video offset=CINEMATIC_073, x=261, y=121
	break
	setup channel=0x04, address=HANG_DRAW_CIN_288
	play id=0x0060, freq=0x18, vol=0x20, channel=0x02
	video offset=CINEMATIC_279, x=283, y=98
	video offset=CINEMATIC_079, x=267, y=113
	break
	video offset=CINEMATIC_079, x=276, y=82
	break
	video offset=CINEMATIC_079, x=280, y=73
	break
	video offset=CINEMATIC_079, x=285, y=71
	break
	video offset=CINEMATIC_079, x=291, y=86
	break
	play id=0x0060, freq=0x14, vol=0x20, channel=0x02
	video offset=CINEMATIC_073, x=297, y=98
	mov [PAUSE_SLICES], 0x0004
	mov [0x03], 0x0003

LABEL_3A1A:
	break
	video type=0, offset=COMMON_VIDEO_335, x=297, y=98, zoom=0x40
	djnz [0x03], LABEL_3A1A
	break
	setup channel=0x16, address=LABEL_B74A
	mov [0x63], 0x0002
	call SET_VAR04_TO_0020
	mov [0x01], 0x012A
	video offset=CINEMATIC_073, x=[0x01], y=[0x02]
	break
	video offset=CINEMATIC_074, x=[0x01], y=[0x02]
	jmp HERO_WALK_RIGHT_LOOP
LABEL_3A42:
	db 0x11

HANG_DRAW_CIN_288:
	video offset=CINEMATIC_288, x=283, y=98
	break
	jmp HANG_DRAW_CIN_288

HANG_DRAW_CIN_521:
	video offset=CINEMATIC_521, x=188, y=126
	break
	jmp HANG_DRAW_CIN_521
LABEL_3A54:
	db 0x11

LABEL_3A55:
	break
	jg [0x02], 0x7F, LABEL_3A55
	jl [0x02], 0x64, LABEL_3A55
	jl [0x01], 0xC8, LABEL_3AF1
	jg [0x01], 0xDC, LABEL_3A55
	mov [0xF8], [0xB9]
	and [0xF8], 0x0020
	je [0xF8], 0x00, LABEL_3AF1
	or [0xB9], 0x0008
	setup channel=0x04, address=KILL_CHANNEL_LANDING
	setup channel=0x14, address=KILL_CHANNEL_LANDING
	break
	mov [PAUSE_SLICES], 0x0006
	video offset=CINEMATIC_513, x=188, y=126
	video offset=CINEMATIC_081, x=203, y=144
	break
	video offset=CINEMATIC_514, x=188, y=126
	video offset=CINEMATIC_519, x=111, y=149
	break
	video offset=CINEMATIC_515, x=188, y=126
	video offset=CINEMATIC_520, x=64, y=144
	break
	video offset=CINEMATIC_515, x=188, y=126
	video offset=CINEMATIC_519, x=67, y=153
	break
	video offset=CINEMATIC_516, x=188, y=126
	video offset=CINEMATIC_076, x=99, y=168
	or [0xB9], 0x0008
	setup channel=0x14, address=INIT_VARS_03_01_02
	mov [PAUSE_SLICES], 0x0004
	break

LABEL_3AC5:
	video offset=CINEMATIC_517, x=188, y=126
	break
	video offset=CINEMATIC_518, x=188, y=126
	break
	video offset=CINEMATIC_518, x=188, y=126
	break
	video offset=CINEMATIC_517, x=188, y=126
	break
	video offset=CINEMATIC_516, x=188, y=126
	break
	video offset=CINEMATIC_516, x=188, y=126
	break
	video offset=CINEMATIC_517, x=188, y=126
	break

HANG_DRAW_CIN_518:
	video offset=CINEMATIC_518, x=187, y=126
	break
	jmp HANG_DRAW_CIN_518
LABEL_3AF0:
	db 0x11

LABEL_3AF1:
	setup channel=0x04, address=KILL_CHANNEL_LANDING
	break
	video offset=CINEMATIC_513, x=188, y=126
	break
	video offset=CINEMATIC_514, x=188, y=126
	break
	video offset=CINEMATIC_515, x=188, y=126
	break
	video offset=CINEMATIC_516, x=188, y=126
	break
	jmp LABEL_3AC5
