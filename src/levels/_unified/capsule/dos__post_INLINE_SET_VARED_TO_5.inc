DELAY_LOOP_VARED_AT_1D5C:
	break
	djnz [0xED], DELAY_LOOP_VARED_AT_1D5C
	break
	break
	break
	setup channel=0x36, address=LABEL_1E40
	mov [0xED], 0x0005

DELAY_LOOP_VARED_AT_1D6C:
	break
	djnz [0xED], DELAY_LOOP_VARED_AT_1D6C
	setup channel=0x36, address=LABEL_1E40
	setup channel=0x37, address=LABEL_1EA0
	setup channel=0x04, address=LABEL_1D9B
	setup channel=0x05, address=LABEL_3D4F
	mov [0xED], 0x0006

DELAY_LOOP_VARED_AT_1D85:
	break
	djnz [0xED], DELAY_LOOP_VARED_AT_1D85
	mov [0xED], 0x0005

DELAY_LOOP_VARED_AT_1D8E:
	break
	djnz [0xED], DELAY_LOOP_VARED_AT_1D8E
	setup channel=0x36, address=LABEL_1E40
	jmp INLINE_SET_VARED_TO_5
LABEL_1D9A:
	db 0x11

LABEL_1D9B:
	video offset=CINEMATIC_375, x=216, y=149
	play id=0x0057, freq=0x14, vol=0x10, channel=0x00
	break
	video offset=CINEMATIC_375, x=218, y=149
	break
	video offset=CINEMATIC_376, x=220, y=149
	break
	video offset=CINEMATIC_376, x=222, y=149
	video offset=CINEMATIC_377, x=223, y=149
	selectVideoPage 0x00
	video offset=CINEMATIC_377, x=223, y=148
	selectVideoPage 0xFF
	killChannel

LABEL_1DC1:
	video offset=CINEMATIC_375, x=72, y=143
	play id=0x0057, freq=0x14, vol=0x10, channel=0x00
	video offset=CINEMATIC_372, x=93, y=90
	break
	video offset=CINEMATIC_375, x=75, y=143
	video offset=CINEMATIC_372, x=94, y=90
	break
	video offset=CINEMATIC_376, x=77, y=143
	break
	video offset=CINEMATIC_377, x=79, y=143
	selectVideoPage 0x00
	video offset=CINEMATIC_377, x=80, y=144
	selectVideoPage 0xFF
	killChannel

LABEL_1DEB:
	video offset=CINEMATIC_375, x=213, y=149
	play id=0x0075, freq=0x12, vol=0x18, channel=0x03
	break
	video offset=CINEMATIC_375, x=231, y=150
	break
	video offset=CINEMATIC_375, x=233, y=150
	break
	video offset=CINEMATIC_376, x=235, y=150
	break
	video offset=CINEMATIC_376, x=236, y=150
	break
	video offset=CINEMATIC_377, x=238, y=149
	selectVideoPage 0x00
	video offset=CINEMATIC_377, x=239, y=149
	selectVideoPage 0xFF
	killChannel
	video offset=CINEMATIC_375, x=80, y=148
	selectVideoPage 0x00
	video offset=CINEMATIC_378, x=89, y=149
	selectVideoPage 0xFF
	killChannel

LABEL_1E24:
	video offset=CINEMATIC_379, x=160, y=100, zoom=[0x50]	;@enc=alt
	play id=0x0075, freq=0x0C, vol=0x10, channel=0x03
	break
	video offset=CINEMATIC_379, x=160, y=100, zoom=[0x46]	;@enc=alt
	break

HANG_DRAW_CIN_379:
	video offset=CINEMATIC_379, x=160, y=100
	break
	jmp HANG_DRAW_CIN_379

LABEL_1E40:
	video offset=CINEMATIC_394, x=160, y=100
	video offset=CINEMATIC_379, x=160, y=100, zoom=[0x43]	;@enc=alt
	play id=0x0052, freq=0x1E, vol=0x40, channel=0x03
	setup channel=0x06, address=LABEL_1E7E
	break
	video offset=CINEMATIC_395, x=160, y=100
	video offset=CINEMATIC_379, x=160, y=100
	jmp HANG_DRAW_CIN_379
	killChannel
	video offset=CINEMATIC_394, x=190, y=100
	video offset=CINEMATIC_379, x=160, y=100, zoom=[0x43]	;@enc=alt
	play id=0x0052, freq=0x1E, vol=0x40, channel=0x03
	break
	video offset=CINEMATIC_395, x=210, y=100
	video offset=CINEMATIC_379, x=160, y=100
	jmp HANG_DRAW_CIN_379
LABEL_1E7D:
	db 0x11

LABEL_1E7E:
	video offset=CINEMATIC_382, x=160, y=100
	break
	video offset=CINEMATIC_396, x=160, y=100
	selectVideoPage 0x00
	video offset=CINEMATIC_383, x=188, y=100, zoom=[0xe8]
	add [0xE8], 0x000A
	selectVideoPage 0xFF
	jl [0xE8], 0xA0, KILL_CHAN_AT_1471
	mov [0xE8], 0x0022
	killChannel

LABEL_1EA0:
	video offset=CINEMATIC_380, x=160, y=100
	break
	video offset=CINEMATIC_381, x=160, y=100
	break
	video offset=CINEMATIC_382, x=78, y=84
	selectVideoPage 0x00
	video offset=CINEMATIC_383, x=107, y=84
	selectVideoPage 0xFF
	break
	video offset=CINEMATIC_384, x=160, y=100
	break
	video offset=CINEMATIC_385, x=160, y=100
	break
	video offset=CINEMATIC_386, x=160, y=100
	break
	killChannel
	video offset=CINEMATIC_387, x=160, y=100
	break
	video offset=CINEMATIC_388, x=160, y=100
	killChannel
	video offset=CINEMATIC_389, x=160, y=100
	break
	video offset=CINEMATIC_390, x=160, y=100
	setup channel=0x38, address=LABEL_1EDF
	killChannel

LABEL_1EDF:
	video offset=CINEMATIC_391, x=160, y=100
	break
	video offset=CINEMATIC_392, x=160, y=100
	killChannel

HANG_DRAW_CIN_393:
	video offset=CINEMATIC_393, x=160, y=100
	break
	jmp HANG_DRAW_CIN_393
LABEL_1EF1:
	db 0x11

HANG_DRAW_CIN_456:
	video offset=CINEMATIC_456, x=160, y=100
	break
	jmp HANG_DRAW_CIN_456
LABEL_1EFA:
	db 0x11

LABEL_1EFB:
	video offset=CINEMATIC_557, x=0, y=137
	jl [HERO_X], 0xA0, LABEL_1F09
	video offset=CINEMATIC_558, x=160, y=100

LABEL_1F09:
	break
	jmp LABEL_1EFB
LABEL_1F0D:
	db 0x11

LABEL_1F0E:
	break
	jg [HERO_X], 0x28, LABEL_1F0E
	video offset=CINEMATIC_561, x=23, y=62
	jmp LABEL_1F0E
LABEL_1F1C:
	db 0x11

LABEL_1F1D:
	break
	jg [HERO_Y], 0xA6, LABEL_1F1D
	video offset=CINEMATIC_499, x=65, y=131
	video offset=CINEMATIC_499, x=1, y=67
	video offset=CINEMATIC_498, x=24, y=129
	jg [HERO_X], 0x3C, LABEL_1F1D
	jl [HERO_X], 0x14, LABEL_1F1D
	jmp LABEL_1F1D
LABEL_1F3F:
	db 0x11

LABEL_1F40:
	break
	jl [HERO_Y], 0xB1, LABEL_1F40
	video offset=CINEMATIC_498, x=270, y=210
	video offset=CINEMATIC_499, x=178, y=203, zoom=0x40
	jmp LABEL_1F40
LABEL_1F54:
	db 0x11

LABEL_1F55:
	break
	jg [HERO_X], 0x73, LABEL_1F55
	video offset=CINEMATIC_498, x=42, y=184
	jmp LABEL_1F55
LABEL_1F63:
	db 0x11

LABEL_1F64:
	break
	jg [HERO_X], 0xBE, LABEL_1F64
	video offset=CINEMATIC_561, x=174, y=199
	video offset=CINEMATIC_346, x=160, y=184
	jmp LABEL_1F64
LABEL_1F76:
	db 0x11

HANG_DRAW_CIN_491:
	video offset=CINEMATIC_491, x=160, y=100
	break
	jmp HANG_DRAW_CIN_491
LABEL_1F7F:
	db 0x11

HANG_DRAW_CIN_494:
	video offset=CINEMATIC_494, x=160, y=100
	break
	jmp HANG_DRAW_CIN_494
LABEL_1F88:
	db 0x11

LABEL_1F89:
	video offset=CINEMATIC_335, x=280, y=101
	video offset=CINEMATIC_336, x=226, y=140
	jg [HERO_X], 0x82, LABEL_1FA8
	jl [HERO_Y], 0x7C, LABEL_1FA4
	jg [HERO_X], 0x4B, LABEL_1FA8

LABEL_1FA4:
	video offset=CINEMATIC_338, x=160, y=100

LABEL_1FA8:
	jl [HERO_X], 0xC8, LABEL_1FB9
	jg [HERO_Y], 0xA0, LABEL_1FB9
	video offset=CINEMATIC_337, x=300, y=101

LABEL_1FB9:
	break
	jmp LABEL_1F89
LABEL_1FBD:
	db 0x11

HANG_DRAW_CIN_335:
	video offset=CINEMATIC_335, x=76, y=177
	break
	jmp HANG_DRAW_CIN_335
LABEL_1FC6:
	db 0x11

LABEL_1FC7:
	video offset=CINEMATIC_335, x=65498, y=30
	jg [HERO_Y], 0x5A, LABEL_1FD9
	video offset=CINEMATIC_337, x=65534, y=31

LABEL_1FD9:
	break
	jmp LABEL_1FC7
LABEL_1FDD:
	db 0x11

LABEL_1FDE:
	jl [HERO_X], 0xC8, LABEL_1FE8
	video offset=CINEMATIC_347, x=231, y=111

LABEL_1FE8:
	jg [HERO_X], 0x64, LABEL_1FFC
	video offset=CINEMATIC_346, x=64, y=160
	video offset=CINEMATIC_347, x=66, y=105
	video offset=CINEMATIC_335, x=65513, y=83

LABEL_1FFC:
	break
	jmp LABEL_1FDE
	video offset=CINEMATIC_336, x=226, y=140
	killChannel

LABEL_2005:
	break
	video offset=CINEMATIC_347, x=56, y=60
	jmp LABEL_2005

LABEL_200D:
	jl [HERO_X], 0x14, LABEL_201D
	jg [HERO_X], 0x93, LABEL_201D
	video offset=CINEMATIC_337, x=61, y=100

LABEL_201D:
	jl [HERO_X], 0xE6, LABEL_202F
	jg [HERO_X], 0x0138, LABEL_202F
	video offset=CINEMATIC_337, x=270, y=100

LABEL_202F:
	jl [HERO_X], 0x2A, LABEL_203F
	jg [HERO_X], 0xA2, LABEL_203F
	video offset=CINEMATIC_343, x=160, y=100

LABEL_203F:
	jl [HERO_X], 0x4E, LABEL_204F
	jg [HERO_X], 0xA5, LABEL_204F
	video offset=CINEMATIC_342, x=160, y=100

LABEL_204F:
	jl [HERO_X], 0x5E, LABEL_205F
	jg [HERO_X], 0xB2, LABEL_205F
	video offset=CINEMATIC_341, x=160, y=100

LABEL_205F:
	jl [HERO_X], 0x8F, LABEL_206F
	jg [HERO_X], 0xF0, LABEL_206F
	video offset=CINEMATIC_343, x=251, y=101

LABEL_206F:
	jl [HERO_X], 0xAC, LABEL_2080
	jg [HERO_X], 0x0114, LABEL_2080
	video offset=CINEMATIC_342, x=251, y=101

LABEL_2080:
	jl [HERO_X], 0xC0, LABEL_2091
	jg [HERO_X], 0x0122, LABEL_2091
	video offset=CINEMATIC_341, x=251, y=101

LABEL_2091:
	break
	jmp LABEL_200D
LABEL_2095:
	db 0x11

LABEL_2096:
	jg [HERO_X], 0x32, LABEL_20A8
	mov [HERO_X], 0xFFE2
	mov [HERO_Y], 0x005A
	mov [0x32], 0x0001

LABEL_20A8:
	jl [HERO_X], 0x010E, LABEL_20B3
	mov [HERO_X], 0x015E

LABEL_20B3:
	break
	jmp LABEL_2096

LABEL_20B7:
	video offset=CINEMATIC_448, x=160, y=100
	play id=0x0052, freq=0x22, vol=0x40, channel=0x02
	setPalette 0x02
	break
	setPalette 0x01
	video offset=CINEMATIC_449, x=160, y=100
	video offset=CINEMATIC_450, x=72, y=56
	break
	selectVideoPage 0x00
	video offset=CINEMATIC_451, x=72, y=56
	selectVideoPage 0xFF
	killChannel

LABEL_20DA:
	mov [0xE8], 0x008C
	play id=0x0052, freq=0x1B, vol=0x40, channel=0x02
	mov [0xE9], 0x0032
	call DERIVE_HASH_BUCKETS_FROM_VAR38
	add [0xE8], [0x3D]
	call DERIVE_HASH_BUCKETS_FROM_VAR38
	add [0xE9], [0x3D]
	setPalette 0x02
	video offset=CINEMATIC_452, x=[0xe8], y=[0xe9]
	break
	setPalette 0x01
	video offset=CINEMATIC_453, x=[0xe8], y=[0xe9]
	break
	sub [0xE8], 0x005F
	sub [0xE9], 0x0018
	call DERIVE_HASH_BUCKETS_FROM_VAR38
	add [RANDOM_SEED], 0x0020
	video offset=CINEMATIC_450, x=[0xe8], y=[0xe9], zoom=[0x3c]
	selectVideoPage 0x00
	video offset=CINEMATIC_451, x=[0xe8], y=[0xe9], zoom=[0x3c]
	selectVideoPage 0xFF
	killChannel

LABEL_2126:
	mov [0xEA], 0x0064
	mov [0xEB], 0x0032
	play id=0x0052, freq=0x1E, vol=0x40, channel=0x02
	call DERIVE_HASH_BUCKETS_FROM_VAR38
	add [0xEA], [0x3E]
	call DERIVE_HASH_BUCKETS_FROM_VAR38
	add [0xEB], [0x3D]
	setPalette 0x02
	video offset=CINEMATIC_454, x=[0xea], y=[0xeb]
	break
	setPalette 0x01
	video offset=CINEMATIC_455, x=[0xea], y=[0xeb]
	break
	add [0xEA], 0x0014
	sub [0xEB], 0x0018
	call DERIVE_HASH_BUCKETS_FROM_VAR38
	add [RANDOM_SEED], 0x0020
	video offset=CINEMATIC_450, x=[0xea], y=[0xeb], zoom=[0x3c]
	selectVideoPage 0x00
	video offset=CINEMATIC_451, x=[0xea], y=[0xeb], zoom=[0x3c]
	selectVideoPage 0xFF
	killChannel
