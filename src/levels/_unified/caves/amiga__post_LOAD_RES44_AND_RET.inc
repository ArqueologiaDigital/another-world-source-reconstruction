LABEL_CDA8:
	load id=0x0046
	copyVideoPage src=0x00, dst=0x03
	load id=0x0045
	ret

LABEL_CDB2:
	fill page=0x00, color=0x00
	video type=1, offset=CINEMATIC_372, x=160, y=100
	video type=1, offset=CINEMATIC_373, x=160, y=100
	selectVideoPage 0x03
	fill page=0x03, color=0x09
	mov [SCROLL_Y], 0x0096
	copyVideoPage src=0x80, dst=0x03
	selectVideoPage 0x00
	ret

LABEL_CDCC:
	fill page=0x00, color=0x00
	video type=1, offset=CINEMATIC_375, x=160, y=100
	video type=1, offset=CINEMATIC_376, x=160, y=100
	copyVideoPage src=0x00, dst=0x03
	video type=1, offset=CINEMATIC_377, x=160, y=100
	ret

LABEL_CDDF:
	fill page=0x00, color=0x00
	video type=1, offset=CINEMATIC_387, x=160, y=100
	video type=1, offset=CINEMATIC_388, x=160, y=100
	ret

DRAW_CIN_415_416_FRAGMENTS:
	fill page=0x00, color=0x08
	video type=1, offset=CINEMATIC_394, x=160, y=100
	video type=1, offset=CINEMATIC_395, x=202, y=65
	video type=1, offset=CINEMATIC_395, x=293, y=4, zoom=0x40
	video type=1, offset=CINEMATIC_395, x=298, y=117, zoom=0x40
	video type=1, offset=CINEMATIC_395, x=125, y=59, zoom=[0x2e]	;@raw=0x6A,0x73,0x7E,0x7D,0x3B,0x2E
	video type=1, offset=CINEMATIC_395, x=212, y=101, zoom=[0x2e]	;@raw=0x6A,0x73,0x7E,0xD4,0x65,0x2E
	video type=1, offset=CINEMATIC_395, x=121, y=91, zoom=[0x20]	;@raw=0x6A,0x73,0x7E,0x79,0x5B,0x20
	video type=1, offset=CINEMATIC_395, x=201, y=132, zoom=[0x20]	;@raw=0x6A,0x73,0x7E,0xC9,0x84,0x20
	video type=1, offset=CINEMATIC_395, x=86, y=82
	video type=1, offset=CINEMATIC_395, x=257, y=78, zoom=0x40
	video type=1, offset=CINEMATIC_395, x=249, y=151
	video type=1, offset=CINEMATIC_395, x=159, y=16
	video type=1, offset=CINEMATIC_395, x=250, y=155, zoom=[0x20]	;@raw=0x6A,0x73,0x7E,0xFA,0x9B,0x20
	video type=1, offset=CINEMATIC_395, x=89, y=86, zoom=[0x20]	;@raw=0x6A,0x73,0x7E,0x59,0x56,0x20
	copyVideoPage src=0x00, dst=0x03
	video type=1, offset=CINEMATIC_396, x=169, y=94
	ret

LABEL_CE3D:
	fill page=0x00, color=0x08
	video type=1, offset=CINEMATIC_335, x=134, y=103
	video type=1, offset=CINEMATIC_395, x=6, y=90
	video type=1, offset=CINEMATIC_395, x=315, y=147, zoom=[0x26]	;@raw=0x7A,0x73,0x7E,0x3B,0x93,0x26
	video type=1, offset=CINEMATIC_406, x=14, y=166
	video type=1, offset=CINEMATIC_395, x=44, y=133, zoom=[0x20]	;@raw=0x6A,0x73,0x7E,0x2C,0x85,0x20
	video type=1, offset=CINEMATIC_336, x=19, y=73
	video type=1, offset=CINEMATIC_336, x=16, y=76
	video type=1, offset=CINEMATIC_336, x=136, y=165
	video type=1, offset=CINEMATIC_336, x=82, y=139
	video type=1, offset=CINEMATIC_336, x=38, y=167
	video type=1, offset=CINEMATIC_336, x=245, y=150
	video type=1, offset=CINEMATIC_336, x=252, y=83
	video type=1, offset=CINEMATIC_336, x=310, y=138, zoom=0x40
	video type=1, offset=CINEMATIC_336, x=303, y=169, zoom=0x40
	video type=1, offset=CINEMATIC_336, x=191, y=169
	video type=1, offset=CINEMATIC_336, x=150, y=156
	video type=1, offset=CINEMATIC_407, x=96, y=124
	video type=1, offset=CINEMATIC_407, x=107, y=108
	video type=1, offset=CINEMATIC_407, x=150, y=169
	video type=1, offset=CINEMATIC_407, x=130, y=142
	video type=1, offset=CINEMATIC_408, x=160, y=100
	video type=1, offset=CINEMATIC_409, x=160, y=100
	video type=1, offset=CINEMATIC_410, x=83, y=165
	video type=1, offset=CINEMATIC_410, x=136, y=165
	video type=1, offset=CINEMATIC_410, x=233, y=165
	video type=1, offset=CINEMATIC_410, x=293, y=165, zoom=0x40
	video type=1, offset=CINEMATIC_275, x=91, y=153
	video type=1, offset=CINEMATIC_275, x=28, y=153
	video type=1, offset=CINEMATIC_275, x=59, y=153
	video type=1, offset=CINEMATIC_275, x=124, y=153
	video type=1, offset=CINEMATIC_275, x=320, y=153, zoom=0x40
	video type=1, offset=CINEMATIC_275, x=269, y=153, zoom=0x40
	video type=1, offset=CINEMATIC_275, x=132, y=153
	video type=1, offset=CINEMATIC_275, x=203, y=153
	video type=1, offset=CINEMATIC_275, x=170, y=153
	video type=1, offset=CINEMATIC_411, x=230, y=172
	ret

LABEL_CEDA:
	fill page=0x00, color=0x08
	video type=1, offset=CINEMATIC_413, x=160, y=100
	video type=1, offset=CINEMATIC_414, x=160, y=100
	video type=1, offset=CINEMATIC_415, x=160, y=100
	ret

LABEL_CEEA:
	fill page=0x00, color=0x08
	video type=1, offset=CINEMATIC_432, x=160, y=100
	ret

LABEL_CEF2:
	fill page=0x00, color=0x00
	video type=1, offset=CINEMATIC_569, x=160, y=100
	video type=1, offset=CINEMATIC_570, x=160, y=100
	jne [0xAF], 0x58, SHARED_RET
	video type=1, offset=CINEMATIC_571, x=160, y=100
	video type=1, offset=CINEMATIC_436, x=199, y=200, zoom=0x40
	video type=1, offset=CINEMATIC_436, x=250, y=189
	ret

LABEL_CF11:
	fill page=0x00, color=0x00
	video type=1, offset=CINEMATIC_581, x=160, y=100
	video type=1, offset=CINEMATIC_582, x=160, y=100
	video type=1, offset=CINEMATIC_583, x=160, y=100
	ret

LABEL_CF21:
	fill page=0x00, color=0x00
	video type=1, offset=CINEMATIC_585, x=160, y=100
	video type=1, offset=CINEMATIC_586, x=160, y=100
	ret

LABEL_CF2D:
	fill page=0x00, color=0x00
	video type=1, offset=CINEMATIC_589, x=161, y=100
	video type=1, offset=CINEMATIC_590, x=161, y=99
	selectVideoPage 0x03
	fill page=0x03, color=0x00
	video type=1, offset=CINEMATIC_589, x=160, y=100
	video type=1, offset=CINEMATIC_590, x=160, y=100
	ret

LABEL_CF46:
	fill page=0x00, color=0x00
	video type=1, offset=CINEMATIC_622, x=160, y=100
	video type=1, offset=CINEMATIC_623, x=160, y=100
	video type=1, offset=CINEMATIC_624, x=256, y=167, zoom=[0x20]	;@raw=0x7A,0x67,0x96,0x00,0xA7,0x20
	video type=1, offset=CINEMATIC_625, x=244, y=170, zoom=[0x20]	;@raw=0x6A,0x67,0x6A,0xF4,0xAA,0x20
	copyVideoPage src=0x00, dst=0x03
	mov [0xF8], [0xB1]
	and [0xF8], 0x0008
	jne [0xF8], 0x00, DRAW_CIN_626
	video type=1, offset=CINEMATIC_627, x=160, y=100
	ret

DRAW_CIN_626:
	video type=1, offset=CINEMATIC_626, x=160, y=100
	ret

LABEL_CF77:
	fill page=0x00, color=0x09
	video type=1, offset=CINEMATIC_633, x=155, y=100
	video type=1, offset=CINEMATIC_634, x=155, y=100
	ret

LABEL_CF83:
	fill page=0x00, color=0x09
	video type=1, offset=CINEMATIC_634, x=25, y=100
	ret

LABEL_CF8B:
	fill page=0x00, color=0x00
	video type=1, offset=CINEMATIC_638, x=160, y=100
	video type=1, offset=CINEMATIC_639, x=160, y=100
	video type=1, offset=CINEMATIC_640, x=160, y=100
	video type=1, offset=CINEMATIC_641, x=160, y=100
	ret

LABEL_CF9F:
	fill page=0x00, color=0x00
	video type=1, offset=CINEMATIC_705, x=160, y=100
	video type=1, offset=CINEMATIC_706, x=160, y=100
	video type=1, offset=CINEMATIC_707, x=160, y=100
	video type=1, offset=CINEMATIC_624, x=130, y=57
	video type=1, offset=CINEMATIC_625, x=39, y=51, zoom=[0x20]	;@raw=0x6A,0x67,0x6A,0x27,0x33,0x20
	video type=1, offset=CINEMATIC_708, x=27, y=47, zoom=[0x20]	;@raw=0x6A,0x67,0xC6,0x1B,0x2F,0x20
	ret

LABEL_CFBF:
	fill page=0x00, color=0x00
	video type=1, offset=CINEMATIC_714, x=160, y=100
	video type=1, offset=CINEMATIC_715, x=160, y=100
	video type=1, offset=CINEMATIC_716, x=160, y=100
	ret

LABEL_CFCF:
	fill page=0x00, color=0x00
	video type=1, offset=CINEMATIC_718, x=160, y=100
	video type=1, offset=CINEMATIC_719, x=160, y=100
	video type=1, offset=CINEMATIC_720, x=160, y=100
	video type=1, offset=CINEMATIC_721, x=160, y=100
	ret

LABEL_CFE3:
	fill page=0x00, color=0x00
	video type=1, offset=CINEMATIC_719, x=160, y=100
	video type=1, offset=CINEMATIC_718, x=160, y=100
	video type=1, offset=CINEMATIC_734, x=160, y=100
	video type=1, offset=CINEMATIC_735, x=160, y=100
	jne [0xB0], 0x03, SHARED_RET
	setPalette 0x10
	video type=1, offset=CINEMATIC_625, x=49, y=115
	video type=1, offset=CINEMATIC_624, x=8, y=96
	video type=1, offset=CINEMATIC_708, x=28, y=110
	video type=1, offset=CINEMATIC_624, x=68, y=115
	video type=1, offset=CINEMATIC_625, x=9, y=80
	video type=1, offset=CINEMATIC_625, x=6, y=99
	video type=1, offset=CINEMATIC_624, x=15, y=120, zoom=[0x2a]	;@raw=0x6A,0x67,0x96,0x0F,0x78,0x2A
	video type=1, offset=CINEMATIC_708, x=65526, y=66, zoom=0x40
	ret

LABEL_D024:
	fill page=0x00, color=0x00
	video type=1, offset=CINEMATIC_719, x=160, y=100
	video type=1, offset=CINEMATIC_718, x=160, y=100
	video type=1, offset=CINEMATIC_734, x=160, y=100
	video type=1, offset=CINEMATIC_735, x=160, y=100
	ret

LABEL_D038:
	jne [0xB0], 0x03, SHARED_RET
	video type=1, offset=CINEMATIC_436, x=70, y=97
	video type=1, offset=CINEMATIC_436, x=260, y=97, zoom=0x40
	ret

LABEL_D048:
	fill page=0x00, color=0x00
	video type=1, offset=CINEMATIC_635, x=160, y=100
	video type=1, offset=CINEMATIC_596, x=327, y=146, zoom=0x40
	video type=1, offset=CINEMATIC_636, x=239, y=137
	video type=1, offset=CINEMATIC_636, x=243, y=180
	jne [0xB0], 0x03, SHARED_RET
	video type=1, offset=CINEMATIC_436, x=131, y=217, zoom=0x40
	ret

LABEL_D068:
	fill page=0x00, color=0x00
	video type=1, offset=CINEMATIC_719, x=160, y=100
	video type=1, offset=CINEMATIC_718, x=160, y=100
	video type=1, offset=CINEMATIC_734, x=160, y=100
	video type=1, offset=CINEMATIC_735, x=160, y=100
	video type=1, offset=CINEMATIC_736, x=160, y=100
	ret

LABEL_D080:
	fill page=0x00, color=0x00
	video type=1, offset=CINEMATIC_738, x=160, y=100
	video type=1, offset=CINEMATIC_739, x=160, y=100
	video type=1, offset=CINEMATIC_740, x=160, y=100
	video type=1, offset=CINEMATIC_741, x=160, y=100
	video type=1, offset=CINEMATIC_742, x=160, y=100
	video type=1, offset=CINEMATIC_743, x=309, y=42, zoom=0x40
	video type=1, offset=CINEMATIC_744, x=308, y=57, zoom=0x40
	video type=1, offset=CINEMATIC_745, x=303, y=72, zoom=0x40
	video type=1, offset=CINEMATIC_746, x=296, y=23, zoom=0x40
	jne [0xB0], 0x03, SHARED_RET
	video type=1, offset=CINEMATIC_436, x=65508, y=90, zoom=0x40
	video type=1, offset=CINEMATIC_436, x=156, y=184
	ret

LABEL_D0BC:
	fill page=0x00, color=0x00
	video type=1, offset=CINEMATIC_274, x=160, y=100
	video type=1, offset=CINEMATIC_275, x=165, y=111
	video type=1, offset=CINEMATIC_275, x=220, y=110
	video type=1, offset=CINEMATIC_275, x=257, y=111, zoom=0x40
	video type=1, offset=CINEMATIC_275, x=301, y=111, zoom=0x40
	video type=1, offset=CINEMATIC_275, x=33, y=112
	video type=1, offset=CINEMATIC_275, x=70, y=110
	ret
LABEL_D0DE:
	db 0x11

LABEL_D0DF:
	fill page=0x00, color=0x00
	fill page=0x03, color=0x00
	load id=0x0043
	copyVideoPage src=0x00, dst=0x03
	mov [SCROLL_Y], 0x0002
	copyVideoPage src=0x83, dst=0x00
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_278, x=163, y=99
	video type=1, offset=CINEMATIC_279, x=162, y=99
	selectVideoPage 0x03
	video type=1, offset=CINEMATIC_278, x=160, y=100
	video type=1, offset=CINEMATIC_279, x=160, y=100
	selectVideoPage 0xFF
	ret

LABEL_D109:
	fill page=0x00, color=0x00
	fill page=0x03, color=0x00
	load id=0x0043
	copyVideoPage src=0x00, dst=0x03
	mov [SCROLL_Y], 0xFFDA
	copyVideoPage src=0x80, dst=0x03
	mov [SCROLL_Y], 0x0002
	copyVideoPage src=0x83, dst=0x00
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_279, x=161, y=61
	video type=1, offset=CINEMATIC_279, x=161, y=62
	selectVideoPage 0x03
	video type=1, offset=CINEMATIC_279, x=161, y=60
	video type=1, offset=CINEMATIC_279, x=160, y=62
	selectVideoPage 0xFF
	ret

LABEL_D13A:
	fill page=0x00, color=0x08
	video type=1, offset=CINEMATIC_296, x=160, y=100
	video type=1, offset=CINEMATIC_297, x=160, y=100
	video type=1, offset=CINEMATIC_298, x=160, y=100
	video type=1, offset=CINEMATIC_299, x=160, y=100
	ret

LABEL_D14E:
	fill page=0x00, color=0x08
	video type=1, offset=CINEMATIC_332, x=160, y=100
	video type=1, offset=CINEMATIC_333, x=160, y=100
	video type=1, offset=CINEMATIC_334, x=160, y=100
	video type=1, offset=CINEMATIC_335, x=31, y=74
	video type=1, offset=CINEMATIC_335, x=293, y=150, zoom=0x40
	video type=1, offset=CINEMATIC_336, x=97, y=110
	video type=1, offset=CINEMATIC_336, x=29, y=103
	video type=1, offset=CINEMATIC_336, x=37, y=15
	video type=1, offset=CINEMATIC_336, x=43, y=12
	video type=1, offset=CINEMATIC_336, x=86, y=72
	video type=1, offset=CINEMATIC_336, x=35, y=103
	video type=1, offset=CINEMATIC_336, x=218, y=152
	video type=1, offset=CINEMATIC_336, x=93, y=77
	video type=1, offset=CINEMATIC_337, x=161, y=96
	video type=1, offset=CINEMATIC_275, x=59, y=96
	ret

LABEL_D18F:
	fill page=0x00, color=0x08
	video type=1, offset=CINEMATIC_340, x=160, y=100
	video type=1, offset=CINEMATIC_341, x=160, y=100
	video type=1, offset=CINEMATIC_275, x=214, y=153
	video type=1, offset=CINEMATIC_275, x=248, y=153
	video type=1, offset=CINEMATIC_275, x=310, y=153, zoom=0x40
	video type=1, offset=CINEMATIC_335, x=24, y=62
	video type=1, offset=CINEMATIC_335, x=32, y=71
	video type=1, offset=CINEMATIC_335, x=24, y=69
	video type=1, offset=CINEMATIC_335, x=38, y=136
	video type=1, offset=CINEMATIC_335, x=0, y=64
	video type=1, offset=CINEMATIC_335, x=25, y=71
	video type=1, offset=CINEMATIC_335, x=4, y=158
	video type=1, offset=CINEMATIC_335, x=112, y=82
	video type=1, offset=CINEMATIC_335, x=297, y=109, zoom=0x40
	video type=1, offset=CINEMATIC_335, x=317, y=87, zoom=0x40
	video type=1, offset=CINEMATIC_335, x=203, y=157
	video type=1, offset=CINEMATIC_336, x=27, y=65
	video type=1, offset=CINEMATIC_336, x=34, y=80
	video type=1, offset=CINEMATIC_336, x=54, y=140
	video type=1, offset=CINEMATIC_336, x=43, y=167
	video type=1, offset=CINEMATIC_336, x=4, y=170
	video type=1, offset=CINEMATIC_336, x=203, y=163
	video type=1, offset=CINEMATIC_336, x=308, y=104, zoom=0x40
	video type=1, offset=CINEMATIC_336, x=309, y=152, zoom=0x40
	video type=1, offset=CINEMATIC_336, x=121, y=84
	video type=1, offset=CINEMATIC_336, x=93, y=107
	video type=1, offset=CINEMATIC_336, x=2, y=116
	video type=1, offset=CINEMATIC_336, x=123, y=173
	video type=1, offset=CINEMATIC_336, x=137, y=187
	video type=1, offset=CINEMATIC_336, x=124, y=192
	video type=1, offset=CINEMATIC_342, x=197, y=154
	video type=1, offset=CINEMATIC_337, x=302, y=141, zoom=0x40
	video type=1, offset=CINEMATIC_337, x=209, y=129
	video type=1, offset=CINEMATIC_337, x=6, y=57
	ret

LABEL_D221:
	fill page=0x00, color=0x08
	video type=1, offset=CINEMATIC_343, x=160, y=100
	video type=1, offset=CINEMATIC_275, x=47, y=153
	video type=1, offset=CINEMATIC_275, x=68, y=153
	video type=1, offset=CINEMATIC_275, x=104, y=153
	video type=1, offset=CINEMATIC_275, x=141, y=152
	video type=1, offset=CINEMATIC_275, x=11, y=153
	video type=1, offset=CINEMATIC_275, x=157, y=155
	video type=1, offset=CINEMATIC_275, x=188, y=154
	video type=1, offset=CINEMATIC_275, x=219, y=154
	video type=1, offset=CINEMATIC_275, x=302, y=153, zoom=0x40
	video type=1, offset=CINEMATIC_275, x=177, y=153
	video type=1, offset=CINEMATIC_275, x=262, y=153, zoom=0x40
	ret

LABEL_D257:
	fill page=0x00, color=0x02
	video type=1, offset=CINEMATIC_344, x=160, y=100
	video type=1, offset=CINEMATIC_345, x=160, y=100
	video type=1, offset=CINEMATIC_346, x=95, y=150
	video type=1, offset=CINEMATIC_346, x=191, y=40, zoom=[0x3b]	;@raw=0x6A,0x74,0x56,0xBF,0x28,0x3B
	video type=1, offset=CINEMATIC_346, x=191, y=40, zoom=[0x2f]	;@raw=0x6A,0x74,0x56,0xBF,0x28,0x2F
	video type=1, offset=CINEMATIC_346, x=192, y=42, zoom=[0x20]	;@raw=0x6A,0x74,0x56,0xC0,0x2A,0x20
	video type=1, offset=CINEMATIC_346, x=232, y=41, zoom=[0x29]	;@raw=0x6A,0x74,0x56,0xE8,0x29,0x29
	video type=1, offset=CINEMATIC_347, x=196, y=90
	video type=1, offset=CINEMATIC_347, x=197, y=96
	video type=1, offset=CINEMATIC_347, x=196, y=99
	video type=1, offset=CINEMATIC_347, x=196, y=102
	video type=1, offset=CINEMATIC_347, x=220, y=94
	video type=1, offset=CINEMATIC_347, x=220, y=97
	video type=1, offset=CINEMATIC_347, x=219, y=101
	video type=1, offset=CINEMATIC_347, x=196, y=94
	video type=1, offset=CINEMATIC_347, x=220, y=90
	ret

LABEL_D2A3:
	fill page=0x00, color=0x00
	video type=1, offset=CINEMATIC_348, x=160, y=100
	video type=1, offset=CINEMATIC_349, x=160, y=100
	video type=1, offset=CINEMATIC_350, x=160, y=100
	video type=1, offset=CINEMATIC_351, x=[0xec], y=130, zoom=[0x20]	;@raw=0x5A,0x3C,0xCC,0xEC,0x82,0x20
	video type=1, offset=CINEMATIC_351, x=[0xed], y=150, zoom=[0x30]	;@raw=0x5A,0x3C,0xCC,0xED,0x96,0x30
	video type=1, offset=CINEMATIC_352, x=154, y=159
	video type=1, offset=CINEMATIC_352, x=145, y=173
	video type=1, offset=CINEMATIC_352, x=56, y=108
	video type=1, offset=CINEMATIC_335, x=300, y=130, zoom=0x40
	ret

LABEL_D2D0:
	fill page=0x00, color=0x00
	video type=1, offset=CINEMATIC_433, x=160, y=100
	video type=1, offset=CINEMATIC_434, x=160, y=100
	video type=1, offset=CINEMATIC_435, x=160, y=100
	jne [0xB0], 0x03, SHARED_RET
	video type=1, offset=CINEMATIC_436, x=160, y=230, zoom=0x40
	ret

LABEL_D2EB:
	fill page=0x00, color=0x00
	video type=1, offset=CINEMATIC_593, x=160, y=100
	video type=1, offset=CINEMATIC_594, x=160, y=100
	video type=1, offset=CINEMATIC_595, x=160, y=100
	video type=1, offset=CINEMATIC_597, x=160, y=100
	jl [0xB0], 0x02, LABEL_D308
	video type=1, offset=CINEMATIC_598, x=160, y=100

LABEL_D308:
	mov [0xF8], [0xB0]
	and [0xF8], 0x0001
	je [0xF8], 0x00, SHARED_RET
	video type=1, offset=CINEMATIC_436, x=65466, y=97, zoom=0x40
	jl [0xB0], 0x02, SHARED_RET
	video type=1, offset=CINEMATIC_436, x=160, y=97
	video type=1, offset=CINEMATIC_436, x=100, y=97
	setPalette 0x10
	ret

LABEL_D32D:
	fill page=0x00, color=0x00
	video type=1, offset=CINEMATIC_593, x=160, y=100
	video type=1, offset=CINEMATIC_594, x=160, y=100
	video type=1, offset=CINEMATIC_595, x=160, y=100
	video type=1, offset=CINEMATIC_596, x=65527, y=98, zoom=0x40
	jne [0xB0], 0x03, SHARED_RET
	video type=1, offset=CINEMATIC_436, x=160, y=50
	video type=1, offset=CINEMATIC_436, x=160, y=130
	setPalette 0x10
	ret

LABEL_D354:
	fill page=0x00, color=0x03
	video type=1, offset=CINEMATIC_537, x=160, y=100
	video type=1, offset=CINEMATIC_335, x=180, y=70
	video type=1, offset=CINEMATIC_351, x=178, y=73
	ret

LABEL_D364:
	fill page=0x00, color=0x03
	video type=1, offset=CINEMATIC_540, x=160, y=100
	ret

LABEL_D36C:
	fill page=0x00, color=0x02
	video type=1, offset=CINEMATIC_606, x=161, y=106
	video type=1, offset=CINEMATIC_348, x=150, y=65522, zoom=0x40
	video type=1, offset=CINEMATIC_607, x=32, y=102
	video type=1, offset=CINEMATIC_607, x=287, y=102, zoom=0x40
	video type=1, offset=CINEMATIC_607, x=125, y=101
	video type=1, offset=CINEMATIC_607, x=193, y=101
	video type=1, offset=CINEMATIC_346, x=161, y=143
	video type=1, offset=CINEMATIC_608, x=394, y=100, zoom=0x40
	video type=1, offset=CINEMATIC_609, x=99, y=100
	video type=1, offset=CINEMATIC_609, x=271, y=100, zoom=0x40
	video type=1, offset=CINEMATIC_610, x=10, y=100
	video type=1, offset=CINEMATIC_334, x=481, y=65456, zoom=0x40
	mov [0xF8], [0xB1]
	and [0xF8], 0x0004
	jne [0xF8], 0x00, SHARED_RET
	video type=1, offset=CINEMATIC_611, x=3, y=123
	ret
LABEL_D3B8:
	db 0x78, 0x7A, 0x94, 0x4C, 0x7B, 0x11

LABEL_D3BE:
	fill page=0x00, color=0x02
	video type=1, offset=CINEMATIC_606, x=160, y=100
	video type=1, offset=CINEMATIC_617, x=160, y=100
	video type=1, offset=CINEMATIC_618, x=160, y=100
	ret

LABEL_D3CE:
	fill page=0x00, color=0x02
	video type=1, offset=CINEMATIC_606, x=160, y=100
	video type=1, offset=CINEMATIC_619, x=160, y=100
	video type=1, offset=CINEMATIC_618, x=160, y=100
	ret

LABEL_D3DE:
	fill page=0x00, color=0x02
	video type=1, offset=CINEMATIC_606, x=160, y=100
	video type=1, offset=CINEMATIC_618, x=160, y=100
	ret

LABEL_D3EA:
	fill page=0x00, color=0x02
	video type=1, offset=CINEMATIC_606, x=160, y=100
	video type=1, offset=CINEMATIC_606, x=390, y=100, zoom=0x40
	video type=1, offset=CINEMATIC_620, x=364, y=107, zoom=0x40
	video type=1, offset=CINEMATIC_621, x=160, y=100
	video type=1, offset=CINEMATIC_556, x=160, y=100
	video type=1, offset=CINEMATIC_558, x=160, y=100
	ret
LABEL_D408:
	db 0x11

LABEL_D409:
	fill page=0x00, color=0x08
	video type=1, offset=CINEMATIC_542, x=160, y=100
	video type=1, offset=CINEMATIC_543, x=160, y=100
	ret
LABEL_D415:
	db 0x0A, 0x01, 0x27, 0x01, 0xD4, 0x24, 0x00, 0x22
	db 0x00, 0x5A, 0x00, 0x21, 0x00, 0xB6, 0x05, 0x0A
	db 0x02, 0x27, 0x04, 0xD4, 0x33, 0x00, 0x22, 0x00
	db 0x50, 0x00, 0x21, 0x00, 0xB6, 0x05, 0x0A, 0x01
	db 0x27, 0x05, 0xD4, 0x46, 0x00, 0x22, 0x00, 0x14
	db 0x00, 0x21, 0x00, 0x81, 0x00, 0x23, 0x00, 0x00
	db 0x05, 0x0A, 0x01, 0x27, 0x25, 0xD4, 0x59, 0x00
	db 0x22, 0x00, 0x81, 0x00, 0x21, 0x00, 0xB4, 0x00
	db 0x23, 0x00, 0x01, 0x05, 0x0A, 0x01, 0x27, 0x24
	db 0xD4, 0x68, 0x00, 0x22, 0x00, 0x5D, 0x00, 0x21
	db 0x00, 0xB6, 0x05, 0x0A, 0x01, 0x27, 0x23, 0xD4
	db 0x77, 0x00, 0x22, 0x00, 0x5C, 0x00, 0x21, 0x00
	db 0xB6, 0x05, 0x0A, 0x01, 0x27, 0x45, 0xD4, 0x8A
	db 0x00, 0x22, 0x00, 0x14, 0x00, 0x21, 0x00, 0x81
	db 0x00, 0x23, 0x00, 0x00, 0x05, 0x0A, 0x01, 0x27
	db 0x44, 0xD4, 0x99, 0x00, 0x22, 0x00, 0x46, 0x00
	db 0x21, 0x00, 0x8B, 0x05, 0x05, 0x11
