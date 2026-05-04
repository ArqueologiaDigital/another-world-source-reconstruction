DELAY_LOOP_VARED_AT_1E70:
	break
	djnz [0xED], DELAY_LOOP_VARED_AT_1E70
	break
	break
	break
	setup channel=0x36, address=LABEL_1F54
	mov [0xED], 0x0005

DELAY_LOOP_VARED_AT_1E80:
	break
	djnz [0xED], DELAY_LOOP_VARED_AT_1E80
	setup channel=0x36, address=LABEL_1F54
	setup channel=0x37, address=LABEL_1FB4
	setup channel=0x04, address=LABEL_1EAF
	setup channel=0x05, address=LABEL_3D17
	mov [0xED], 0x0006

DELAY_LOOP_VARED_AT_1E99:
	break
	djnz [0xED], DELAY_LOOP_VARED_AT_1E99
	mov [0xED], 0x0005

DELAY_LOOP_VARED_AT_1EA2:
	break
	djnz [0xED], DELAY_LOOP_VARED_AT_1EA2
	setup channel=0x36, address=LABEL_1F54
	jmp INLINE_SET_VARED_TO_5
LABEL_1EAE:
	db 0x11

LABEL_1EAF:
	video type=1, offset=CINEMATIC_378, x=216, y=149
	play id=0x0057, freq=0x14, vol=0x10, channel=0x00
	break
	video type=1, offset=CINEMATIC_378, x=218, y=149
	break
	video type=1, offset=CINEMATIC_379, x=220, y=149
	break
	video type=1, offset=CINEMATIC_379, x=222, y=149
	video type=1, offset=CINEMATIC_380, x=223, y=149
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_380, x=223, y=148
	selectVideoPage 0xFF
	killChannel

LABEL_1ED5:
	video type=1, offset=CINEMATIC_378, x=72, y=143
	play id=0x0057, freq=0x14, vol=0x10, channel=0x00
	video type=1, offset=CINEMATIC_375, x=93, y=90
	break
	video type=1, offset=CINEMATIC_378, x=75, y=143
	video type=1, offset=CINEMATIC_375, x=94, y=90
	break
	video type=1, offset=CINEMATIC_379, x=77, y=143
	break
	video type=1, offset=CINEMATIC_380, x=79, y=143
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_380, x=80, y=144
	selectVideoPage 0xFF
	killChannel

LABEL_1EFF:
	video type=1, offset=CINEMATIC_378, x=213, y=149
	play id=0x0075, freq=0x12, vol=0x18, channel=0x03
	break
	video type=1, offset=CINEMATIC_378, x=231, y=150
	break
	video type=1, offset=CINEMATIC_378, x=233, y=150
	break
	video type=1, offset=CINEMATIC_379, x=235, y=150
	break
	video type=1, offset=CINEMATIC_379, x=236, y=150
	break
	video type=1, offset=CINEMATIC_380, x=238, y=149
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_380, x=239, y=149
	selectVideoPage 0xFF
	killChannel
	video type=1, offset=CINEMATIC_378, x=80, y=148
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_381, x=89, y=149
	selectVideoPage 0xFF
	killChannel

LABEL_1F38:
	video type=1, offset=CINEMATIC_382, x=160, y=100, zoom=[0x50]	;@raw=0x6A,0x36,0xEF,0xA0,0x64,0x50
	play id=0x0075, freq=0x0C, vol=0x10, channel=0x03
	break
	video type=1, offset=CINEMATIC_382, x=160, y=100, zoom=[0x46]	;@raw=0x6A,0x36,0xEF,0xA0,0x64,0x46
	break

HANG_DRAW_CIN_382:
	video type=1, offset=CINEMATIC_382, x=160, y=100
	break
	jmp HANG_DRAW_CIN_382

LABEL_1F54:
	video type=1, offset=CINEMATIC_397, x=160, y=100
	video type=1, offset=CINEMATIC_382, x=160, y=100, zoom=[0x43]	;@raw=0x6A,0x36,0xEF,0xA0,0x64,0x43
	play id=0x0052, freq=0x1E, vol=0x40, channel=0x03
	setup channel=0x06, address=LABEL_1F92
	break
	video type=1, offset=CINEMATIC_398, x=160, y=100
	video type=1, offset=CINEMATIC_382, x=160, y=100
	jmp HANG_DRAW_CIN_382
	killChannel
	video type=1, offset=CINEMATIC_397, x=190, y=100
	video type=1, offset=CINEMATIC_382, x=160, y=100, zoom=[0x43]	;@raw=0x6A,0x36,0xEF,0xA0,0x64,0x43
	play id=0x0052, freq=0x1E, vol=0x40, channel=0x03
	break
	video type=1, offset=CINEMATIC_398, x=210, y=100
	video type=1, offset=CINEMATIC_382, x=160, y=100
	jmp HANG_DRAW_CIN_382
LABEL_1F91:
	db 0x11

LABEL_1F92:
	video type=1, offset=CINEMATIC_385, x=160, y=100
	break
	video type=1, offset=CINEMATIC_399, x=160, y=100
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_386, x=188, y=100, zoom=[0xe8]
	add [0xE8], 0x000A
	selectVideoPage 0xFF
	jl [0xE8], 0xA0, KILL_CHAN_AT_157F
	mov [0xE8], 0x0022
	killChannel

LABEL_1FB4:
	video type=1, offset=CINEMATIC_383, x=160, y=100
	break
	video type=1, offset=CINEMATIC_384, x=160, y=100
	break
	video type=1, offset=CINEMATIC_385, x=78, y=84
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_386, x=107, y=84
	selectVideoPage 0xFF
	break
	video type=1, offset=CINEMATIC_387, x=160, y=100
	break
	video type=1, offset=CINEMATIC_388, x=160, y=100
	break
	video type=1, offset=CINEMATIC_389, x=160, y=100
	break
	killChannel
	video type=1, offset=CINEMATIC_390, x=160, y=100
	break
	video type=1, offset=CINEMATIC_391, x=160, y=100
	killChannel
	video type=1, offset=CINEMATIC_392, x=160, y=100
	break
	video type=1, offset=CINEMATIC_393, x=160, y=100
	setup channel=0x38, address=LABEL_1FF3
	killChannel

LABEL_1FF3:
	video type=1, offset=CINEMATIC_394, x=160, y=100
	break
	video type=1, offset=CINEMATIC_395, x=160, y=100
	killChannel

HANG_DRAW_CIN_396:
	video type=1, offset=CINEMATIC_396, x=160, y=100
	break
	jmp HANG_DRAW_CIN_396
LABEL_2005:
	db 0x11

HANG_DRAW_CIN_460:
	video type=1, offset=CINEMATIC_460, x=160, y=100
	break
	jmp HANG_DRAW_CIN_460
LABEL_200E:
	db 0x11

LABEL_200F:
	video type=1, offset=CINEMATIC_563, x=0, y=137
	jl [0x01], 0xA0, LABEL_201D
	video type=1, offset=CINEMATIC_564, x=160, y=100

LABEL_201D:
	break
	jmp LABEL_200F
LABEL_2021:
	db 0x11

LABEL_2022:
	break
	jg [0x01], 0x28, LABEL_2022
	video type=1, offset=CINEMATIC_570, x=23, y=62
	jmp LABEL_2022
LABEL_2030:
	db 0x11

LABEL_2031:
	break
	jg [0x02], 0xA6, LABEL_2031
	video type=1, offset=CINEMATIC_502, x=65, y=131
	video type=1, offset=CINEMATIC_502, x=1, y=67
	video type=1, offset=CINEMATIC_501, x=24, y=129
	jg [0x01], 0x3C, LABEL_2031
	jl [0x01], 0x14, LABEL_2031
	jmp LABEL_2031
LABEL_2053:
	db 0x11

LABEL_2054:
	break
	jl [0x02], 0xB1, LABEL_2054
	video type=1, offset=CINEMATIC_501, x=270, y=210, zoom=0x40
	video type=1, offset=CINEMATIC_502, x=178, y=203, zoom=0x40
	jmp LABEL_2054
LABEL_2068:
	db 0x11

LABEL_2069:
	break
	jg [0x01], 0x73, LABEL_2069
	video type=1, offset=CINEMATIC_501, x=42, y=184
	jmp LABEL_2069
LABEL_2077:
	db 0x11

LABEL_2078:
	break
	jg [0x01], 0xBE, LABEL_2078
	video type=1, offset=CINEMATIC_570, x=174, y=199
	video type=1, offset=CINEMATIC_347, x=160, y=184
	jmp LABEL_2078
LABEL_208A:
	db 0x11

HANG_DRAW_CIN_494:
	video type=1, offset=CINEMATIC_494, x=160, y=100
	break
	jmp HANG_DRAW_CIN_494
LABEL_2093:
	db 0x11

HANG_DRAW_CIN_497:
	video type=1, offset=CINEMATIC_497, x=160, y=100
	break
	jmp HANG_DRAW_CIN_497
LABEL_209C:
	db 0x11

LABEL_209D:
	video type=1, offset=CINEMATIC_336, x=280, y=101, zoom=0x40
	video type=1, offset=CINEMATIC_337, x=226, y=140
	jg [0x01], 0x82, LABEL_20BC
	jl [0x02], 0x7C, LABEL_20B8
	jg [0x01], 0x4B, LABEL_20BC

LABEL_20B8:
	video type=1, offset=CINEMATIC_339, x=160, y=100

LABEL_20BC:
	jl [0x01], 0xC8, LABEL_20CD
	jg [0x02], 0xA0, LABEL_20CD
	video type=1, offset=CINEMATIC_338, x=300, y=101, zoom=0x40

LABEL_20CD:
	break
	jmp LABEL_209D
LABEL_20D1:
	db 0x11

HANG_DRAW_CIN_336:
	video type=1, offset=CINEMATIC_336, x=76, y=177
	break
	jmp HANG_DRAW_CIN_336
LABEL_20DA:
	db 0x11

LABEL_20DB:
	video type=1, offset=CINEMATIC_336, x=65498, y=30, zoom=0x40
	jg [0x02], 0x5A, LABEL_20ED
	video type=1, offset=CINEMATIC_338, x=65534, y=31, zoom=0x40

LABEL_20ED:
	break
	jmp LABEL_20DB
LABEL_20F1:
	db 0x11

LABEL_20F2:
	jl [0x01], 0xC8, LABEL_20FC
	video type=1, offset=CINEMATIC_348, x=231, y=111

LABEL_20FC:
	jg [0x01], 0x64, LABEL_2110
	video type=1, offset=CINEMATIC_347, x=64, y=160
	video type=1, offset=CINEMATIC_348, x=66, y=105
	video type=1, offset=CINEMATIC_336, x=65513, y=83, zoom=0x40

LABEL_2110:
	break
	jmp LABEL_20F2
	video type=1, offset=CINEMATIC_337, x=226, y=140
	killChannel

LABEL_2119:
	break
	video type=1, offset=CINEMATIC_348, x=56, y=60
	jmp LABEL_2119

LABEL_2121:
	jl [0x01], 0x14, LABEL_2131
	jg [0x01], 0x93, LABEL_2131
	video type=1, offset=CINEMATIC_338, x=61, y=100

LABEL_2131:
	jl [0x01], 0xE6, LABEL_2143
	jg [0x01], 0x0138, LABEL_2143
	video type=1, offset=CINEMATIC_338, x=270, y=100, zoom=0x40

LABEL_2143:
	jl [0x01], 0x2A, LABEL_2153
	jg [0x01], 0xA2, LABEL_2153
	video type=1, offset=CINEMATIC_344, x=160, y=100

LABEL_2153:
	jl [0x01], 0x4E, LABEL_2163
	jg [0x01], 0xA5, LABEL_2163
	video type=1, offset=CINEMATIC_343, x=160, y=100

LABEL_2163:
	jl [0x01], 0x5E, LABEL_2173
	jg [0x01], 0xBE, LABEL_2173
	video type=1, offset=CINEMATIC_342, x=160, y=100

LABEL_2173:
	jl [0x01], 0x82, LABEL_2183
	jg [0x01], 0xF0, LABEL_2183
	video type=1, offset=CINEMATIC_344, x=251, y=101

LABEL_2183:
	jl [0x01], 0xA2, LABEL_2194
	jg [0x01], 0x0118, LABEL_2194
	video type=1, offset=CINEMATIC_343, x=251, y=101

LABEL_2194:
	jl [0x01], 0xB6, LABEL_21A5
	jg [0x01], 0x0122, LABEL_21A5
	video type=1, offset=CINEMATIC_342, x=251, y=101

LABEL_21A5:
	break
	jmp LABEL_2121
LABEL_21A9:
	db 0x11

LABEL_21AA:
	jg [0x01], 0x32, LABEL_21BC
	mov [0x01], 0xFFE2
	mov [0x02], 0x005A
	mov [0x32], 0x0001

LABEL_21BC:
	jl [0x01], 0x010E, LABEL_21C7
	mov [0x01], 0x015E

LABEL_21C7:
	break
	jmp LABEL_21AA

LABEL_21CB:
	video type=1, offset=CINEMATIC_452, x=160, y=100
	play id=0x0052, freq=0x22, vol=0x40, channel=0x02
	setPalette 0x02
	break
	setPalette 0x01
	video type=1, offset=CINEMATIC_453, x=160, y=100
	video type=1, offset=CINEMATIC_454, x=72, y=56
	break
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_455, x=72, y=56
	selectVideoPage 0xFF
	killChannel

LABEL_21EE:
	mov [0xE8], 0x008C
	play id=0x0052, freq=0x1B, vol=0x40, channel=0x02
	mov [0xE9], 0x0032
	call DERIVE_HASH_BUCKETS_FROM_VAR38
	add [0xE8], [0x3D]
	call DERIVE_HASH_BUCKETS_FROM_VAR38
	add [0xE9], [0x3D]
	setPalette 0x02
	video type=1, offset=CINEMATIC_456, x=[0xe8], y=[0xe9], zoom=0x40
	break
	setPalette 0x01
	video type=1, offset=CINEMATIC_457, x=[0xe8], y=[0xe9], zoom=0x40
	break
	sub [0xE8], 0x005F
	sub [0xE9], 0x0018
	call DERIVE_HASH_BUCKETS_FROM_VAR38
	add [RANDOM_SEED], 0x0020
	video type=1, offset=CINEMATIC_454, x=[0xe8], y=[0xe9], zoom=[0x3c]
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_455, x=[0xe8], y=[0xe9], zoom=[0x3c]
	selectVideoPage 0xFF
	killChannel

LABEL_223A:
	mov [0xEA], 0x0064
	mov [0xEB], 0x0032
	play id=0x0052, freq=0x1E, vol=0x40, channel=0x02
	call DERIVE_HASH_BUCKETS_FROM_VAR38
	add [0xEA], [0x3E]
	call DERIVE_HASH_BUCKETS_FROM_VAR38
	add [0xEB], [0x3D]
	setPalette 0x02
	video type=1, offset=CINEMATIC_458, x=[0xea], y=[0xeb], zoom=0x40
	break
	setPalette 0x01
	video type=1, offset=CINEMATIC_459, x=[0xea], y=[0xeb], zoom=0x40
	break
	add [0xEA], 0x0014
	sub [0xEB], 0x0018
	call DERIVE_HASH_BUCKETS_FROM_VAR38
	add [RANDOM_SEED], 0x0020
	video type=1, offset=CINEMATIC_454, x=[0xea], y=[0xeb], zoom=[0x3c]
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_455, x=[0xea], y=[0xeb], zoom=[0x3c]
	selectVideoPage 0xFF
	killChannel
