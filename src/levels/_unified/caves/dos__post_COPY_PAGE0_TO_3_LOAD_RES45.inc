LABEL_D268:
	fill page=0x00, color=0x00
	video type=1, offset=CINEMATIC_393, x=160, y=100
	video type=1, offset=CINEMATIC_394, x=160, y=100
	selectVideoPage 0x03
	fill page=0x03, color=0x09
	mov [SCROLL_Y], 0x0096
	copyVideoPage src=0x80, dst=0x03
	selectVideoPage 0x00
	ret

LABEL_D282:
	fill page=0x00, color=0x00
	video type=1, offset=CINEMATIC_396, x=160, y=100
	video type=1, offset=CINEMATIC_397, x=160, y=100
	copyVideoPage src=0x00, dst=0x03
	video type=1, offset=CINEMATIC_398, x=160, y=100
	ret

LABEL_D295:
	fill page=0x00, color=0x00
	video type=1, offset=CINEMATIC_408, x=160, y=100
	video type=1, offset=CINEMATIC_409, x=160, y=100
	ret

DRAW_CIN_415_416_FRAGMENTS:
	fill page=0x00, color=0x08
	video type=1, offset=CINEMATIC_415, x=160, y=100
	video type=1, offset=CINEMATIC_416, x=202, y=65
	video type=1, offset=CINEMATIC_416, x=293, y=4, zoom=0x40
	video type=1, offset=CINEMATIC_416, x=298, y=117, zoom=0x40
	video type=1, offset=CINEMATIC_416, x=125, y=59, zoom=[0x2e]	;@raw=0x6A,0x72,0xAB,0x7D,0x3B,0x2E
	video type=1, offset=CINEMATIC_416, x=212, y=101, zoom=[0x2e]	;@raw=0x6A,0x72,0xAB,0xD4,0x65,0x2E
	video type=1, offset=CINEMATIC_416, x=121, y=91, zoom=[0x20]	;@raw=0x6A,0x72,0xAB,0x79,0x5B,0x20
	video type=1, offset=CINEMATIC_416, x=201, y=132, zoom=[0x20]	;@raw=0x6A,0x72,0xAB,0xC9,0x84,0x20
	video type=1, offset=CINEMATIC_416, x=86, y=82
	video type=1, offset=CINEMATIC_416, x=257, y=78, zoom=0x40
	video type=1, offset=CINEMATIC_416, x=249, y=151
	video type=1, offset=CINEMATIC_416, x=159, y=16
	video type=1, offset=CINEMATIC_416, x=250, y=155, zoom=[0x20]	;@raw=0x6A,0x72,0xAB,0xFA,0x9B,0x20
	video type=1, offset=CINEMATIC_416, x=89, y=86, zoom=[0x20]	;@raw=0x6A,0x72,0xAB,0x59,0x56,0x20
	copyVideoPage src=0x00, dst=0x03
	video type=1, offset=CINEMATIC_417, x=169, y=94
	ret

LABEL_D2F3:
	fill page=0x00, color=0x08
	video type=1, offset=CINEMATIC_356, x=134, y=103
	video type=1, offset=CINEMATIC_416, x=6, y=90
	video type=1, offset=CINEMATIC_416, x=315, y=147, zoom=[0x26]	;@raw=0x7A,0x72,0xAB,0x3B,0x93,0x26
	video type=1, offset=CINEMATIC_427, x=14, y=166
	video type=1, offset=CINEMATIC_416, x=44, y=133, zoom=[0x20]	;@raw=0x6A,0x72,0xAB,0x2C,0x85,0x20
	video type=1, offset=CINEMATIC_357, x=19, y=73
	video type=1, offset=CINEMATIC_357, x=16, y=76
	video type=1, offset=CINEMATIC_357, x=136, y=165
	video type=1, offset=CINEMATIC_357, x=82, y=139
	video type=1, offset=CINEMATIC_357, x=38, y=167
	video type=1, offset=CINEMATIC_357, x=245, y=150
	video type=1, offset=CINEMATIC_357, x=252, y=83
	video type=1, offset=CINEMATIC_357, x=310, y=138, zoom=0x40
	video type=1, offset=CINEMATIC_357, x=303, y=169, zoom=0x40
	video type=1, offset=CINEMATIC_357, x=191, y=169
	video type=1, offset=CINEMATIC_357, x=150, y=156
	video type=1, offset=CINEMATIC_428, x=96, y=124
	video type=1, offset=CINEMATIC_428, x=107, y=108
	video type=1, offset=CINEMATIC_428, x=150, y=169
	video type=1, offset=CINEMATIC_428, x=130, y=142
	video type=1, offset=CINEMATIC_429, x=160, y=100
	video type=1, offset=CINEMATIC_430, x=160, y=100
	video type=1, offset=CINEMATIC_431, x=83, y=165
	video type=1, offset=CINEMATIC_431, x=136, y=165
	video type=1, offset=CINEMATIC_431, x=233, y=165
	video type=1, offset=CINEMATIC_431, x=293, y=165, zoom=0x40
	video type=1, offset=CINEMATIC_296, x=91, y=153
	video type=1, offset=CINEMATIC_296, x=28, y=153
	video type=1, offset=CINEMATIC_296, x=59, y=153
	video type=1, offset=CINEMATIC_296, x=124, y=153
	video type=1, offset=CINEMATIC_296, x=320, y=153, zoom=0x40
	video type=1, offset=CINEMATIC_296, x=269, y=153, zoom=0x40
	video type=1, offset=CINEMATIC_296, x=132, y=153
	video type=1, offset=CINEMATIC_296, x=203, y=153
	video type=1, offset=CINEMATIC_296, x=170, y=153
	video type=1, offset=CINEMATIC_432, x=230, y=172
	ret

LABEL_D390:
	fill page=0x00, color=0x08
	video type=1, offset=CINEMATIC_434, x=160, y=100
	video type=1, offset=CINEMATIC_435, x=160, y=100
	video type=1, offset=CINEMATIC_436, x=160, y=100
	ret

LABEL_D3A0:
	fill page=0x00, color=0x08
	video type=1, offset=CINEMATIC_453, x=160, y=100
	ret

LABEL_D3A8:
	fill page=0x00, color=0x00
	video type=1, offset=CINEMATIC_590, x=160, y=100
	video type=1, offset=CINEMATIC_591, x=160, y=100
	jne [0xAF], 0x58, SHARED_RET
	video type=1, offset=CINEMATIC_592, x=160, y=100
	video type=1, offset=CINEMATIC_457, x=199, y=200, zoom=0x40
	video type=1, offset=CINEMATIC_457, x=250, y=189
	ret

LABEL_D3C7:
	fill page=0x00, color=0x00
	video type=1, offset=CINEMATIC_602, x=160, y=100
	video type=1, offset=CINEMATIC_603, x=160, y=100
	video type=1, offset=CINEMATIC_604, x=160, y=100
	ret

LABEL_D3D7:
	fill page=0x00, color=0x00
	video type=1, offset=CINEMATIC_606, x=160, y=100
	video type=1, offset=CINEMATIC_607, x=160, y=100
	ret

LABEL_D3E3:
	fill page=0x00, color=0x00
	video type=1, offset=CINEMATIC_610, x=161, y=100
	video type=1, offset=CINEMATIC_611, x=161, y=99
	selectVideoPage 0x03
	fill page=0x03, color=0x00
	video type=1, offset=CINEMATIC_610, x=160, y=100
	video type=1, offset=CINEMATIC_611, x=160, y=100
	ret

LABEL_D3FC:
	fill page=0x00, color=0x00
	video type=1, offset=CINEMATIC_643, x=160, y=100
	video type=1, offset=CINEMATIC_644, x=160, y=100
	video type=1, offset=CINEMATIC_645, x=256, y=167, zoom=[0x20]	;@raw=0x7A,0x66,0xC3,0x00,0xA7,0x20
	video type=1, offset=CINEMATIC_646, x=244, y=170, zoom=[0x20]	;@raw=0x6A,0x66,0x97,0xF4,0xAA,0x20
	video type=1, offset=CINEMATIC_647, x=135, y=202, zoom=0x40
	copyVideoPage src=0x00, dst=0x03
	mov [0xF8], [0xB1]
	and [0xF8], 0x0008
	jne [0xF8], 0x00, DRAW_CIN_648
	video type=1, offset=CINEMATIC_649, x=160, y=100
	ret

DRAW_CIN_648:
	video type=1, offset=CINEMATIC_648, x=160, y=100
	ret

LABEL_D432:
	fill page=0x00, color=0x09
	video type=1, offset=CINEMATIC_655, x=155, y=100
	video type=1, offset=CINEMATIC_656, x=155, y=100
	ret

LABEL_D43E:
	fill page=0x00, color=0x09
	video type=1, offset=CINEMATIC_656, x=25, y=100
	ret

LABEL_D446:
	fill page=0x00, color=0x00
	video type=1, offset=CINEMATIC_659, x=160, y=100
	video type=1, offset=CINEMATIC_660, x=160, y=100
	video type=1, offset=CINEMATIC_661, x=160, y=100
	video type=1, offset=CINEMATIC_662, x=160, y=100
	ret

LABEL_D45A:
	fill page=0x00, color=0x00
	video type=1, offset=CINEMATIC_726, x=160, y=100
	video type=1, offset=CINEMATIC_727, x=160, y=100
	video type=1, offset=CINEMATIC_728, x=160, y=100
	video type=1, offset=CINEMATIC_645, x=130, y=57
	video type=1, offset=CINEMATIC_646, x=39, y=51, zoom=[0x20]	;@raw=0x6A,0x66,0x97,0x27,0x33,0x20
	video type=1, offset=CINEMATIC_729, x=27, y=47, zoom=[0x20]	;@raw=0x6A,0x66,0xF3,0x1B,0x2F,0x20
	ret

LABEL_D47A:
	fill page=0x00, color=0x00
	video type=1, offset=CINEMATIC_735, x=160, y=100
	video type=1, offset=CINEMATIC_736, x=160, y=100
	video type=1, offset=CINEMATIC_737, x=160, y=100
	ret

LABEL_D48A:
	fill page=0x00, color=0x00
	video type=1, offset=CINEMATIC_739, x=160, y=100
	video type=1, offset=CINEMATIC_740, x=160, y=100
	video type=1, offset=CINEMATIC_741, x=160, y=100
	video type=1, offset=CINEMATIC_742, x=160, y=100
	ret

LABEL_D49E:
	fill page=0x00, color=0x00
	video type=1, offset=CINEMATIC_740, x=160, y=100
	video type=1, offset=CINEMATIC_739, x=160, y=100
	video type=1, offset=CINEMATIC_755, x=160, y=100
	video type=1, offset=CINEMATIC_756, x=160, y=100
	jne [0xB0], 0x03, SHARED_RET
	setPalette 0x10
	video type=1, offset=CINEMATIC_646, x=49, y=115
	video type=1, offset=CINEMATIC_645, x=8, y=96
	video type=1, offset=CINEMATIC_729, x=28, y=110
	video type=1, offset=CINEMATIC_645, x=68, y=115
	video type=1, offset=CINEMATIC_646, x=9, y=80
	video type=1, offset=CINEMATIC_646, x=6, y=99
	video type=1, offset=CINEMATIC_645, x=15, y=120, zoom=[0x2a]	;@raw=0x6A,0x66,0xC3,0x0F,0x78,0x2A
	video type=1, offset=CINEMATIC_729, x=65526, y=66, zoom=0x40
	ret

LABEL_D4DF:
	fill page=0x00, color=0x00
	video type=1, offset=CINEMATIC_740, x=160, y=100
	video type=1, offset=CINEMATIC_739, x=160, y=100
	video type=1, offset=CINEMATIC_755, x=160, y=100
	video type=1, offset=CINEMATIC_756, x=160, y=100
	ret

LABEL_D4F3:
	jne [0xB0], 0x03, SHARED_RET
	video type=1, offset=CINEMATIC_457, x=70, y=97
	video type=1, offset=CINEMATIC_457, x=260, y=97, zoom=0x40
	ret

LABEL_D503:
	fill page=0x00, color=0x00
	video type=1, offset=CINEMATIC_657, x=160, y=100
	video type=1, offset=CINEMATIC_617, x=327, y=146, zoom=0x40
	video type=1, offset=CINEMATIC_647, x=239, y=137
	video type=1, offset=CINEMATIC_647, x=243, y=180
	jne [0xB0], 0x03, SHARED_RET
	video type=1, offset=CINEMATIC_457, x=131, y=217, zoom=0x40
	ret

LABEL_D523:
	fill page=0x00, color=0x00
	video type=1, offset=CINEMATIC_740, x=160, y=100
	video type=1, offset=CINEMATIC_739, x=160, y=100
	video type=1, offset=CINEMATIC_755, x=160, y=100
	video type=1, offset=CINEMATIC_756, x=160, y=100
	video type=1, offset=CINEMATIC_757, x=160, y=100
	ret

LABEL_D53B:
	fill page=0x00, color=0x00
	video type=1, offset=CINEMATIC_759, x=160, y=100
	video type=1, offset=CINEMATIC_760, x=160, y=100
	video type=1, offset=CINEMATIC_761, x=160, y=100
	video type=1, offset=CINEMATIC_762, x=160, y=100
	video type=1, offset=CINEMATIC_763, x=296, y=23, zoom=0x40
	video type=1, offset=CINEMATIC_764, x=298, y=66, zoom=0x40
	video type=1, offset=CINEMATIC_765, x=260, y=88, zoom=0x40
	video type=1, offset=CINEMATIC_765, x=326, y=82, zoom=0x40
	video type=1, offset=CINEMATIC_766, x=160, y=100
	jne [0xB0], 0x03, SHARED_RET
	video type=1, offset=CINEMATIC_457, x=65508, y=90, zoom=0x40
	video type=1, offset=CINEMATIC_457, x=156, y=184
	ret

LABEL_D577:
	fill page=0x00, color=0x00
	video type=1, offset=CINEMATIC_740, x=160, y=70
	video type=1, offset=CINEMATIC_739, x=160, y=70
	video type=1, offset=CINEMATIC_755, x=160, y=80
	video type=1, offset=CINEMATIC_756, x=160, y=80
	video type=1, offset=CINEMATIC_770, x=91, y=44
	video type=1, offset=CINEMATIC_771, x=86, y=70
	video type=1, offset=CINEMATIC_772, x=217, y=71
	video type=1, offset=CINEMATIC_773, x=160, y=100
	ret
LABEL_D59B:
	db 0x11

LABEL_D59C:
	fill page=0x00, color=0x00
	video type=1, offset=CINEMATIC_295, x=160, y=100
	video type=1, offset=CINEMATIC_296, x=165, y=111
	video type=1, offset=CINEMATIC_296, x=220, y=110
	video type=1, offset=CINEMATIC_296, x=257, y=111, zoom=0x40
	video type=1, offset=CINEMATIC_296, x=301, y=111, zoom=0x40
	video type=1, offset=CINEMATIC_296, x=33, y=112
	video type=1, offset=CINEMATIC_296, x=70, y=110
	ret
LABEL_D5BE:
	db 0x11

LABEL_D5BF:
	fill page=0x00, color=0x00
	fill page=0x03, color=0x00
	load id=0x0043
	copyVideoPage src=0x00, dst=0x03
	mov [SCROLL_Y], 0x0002
	copyVideoPage src=0x83, dst=0x00
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_299, x=163, y=99
	video type=1, offset=CINEMATIC_300, x=162, y=99
	selectVideoPage 0x03
	video type=1, offset=CINEMATIC_299, x=160, y=100
	video type=1, offset=CINEMATIC_300, x=160, y=100
	selectVideoPage 0xFF
	ret

LABEL_D5E9:
	fill page=0x00, color=0x00
	fill page=0x03, color=0x00
	load id=0x0043
	copyVideoPage src=0x00, dst=0x03
	mov [SCROLL_Y], 0xFFDA
	copyVideoPage src=0x80, dst=0x03
	mov [SCROLL_Y], 0x0002
	copyVideoPage src=0x83, dst=0x00
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_300, x=161, y=61
	video type=1, offset=CINEMATIC_300, x=161, y=62
	selectVideoPage 0x03
	video type=1, offset=CINEMATIC_300, x=161, y=60
	video type=1, offset=CINEMATIC_300, x=160, y=62
	selectVideoPage 0xFF
	ret

LABEL_D61A:
	fill page=0x00, color=0x08
	video type=1, offset=CINEMATIC_317, x=160, y=100
	video type=1, offset=CINEMATIC_318, x=160, y=100
	video type=1, offset=CINEMATIC_319, x=160, y=100
	video type=1, offset=CINEMATIC_320, x=160, y=100
	ret

LABEL_D62E:
	fill page=0x00, color=0x08
	video type=1, offset=CINEMATIC_353, x=160, y=100
	video type=1, offset=CINEMATIC_354, x=160, y=100
	video type=1, offset=CINEMATIC_355, x=160, y=100
	video type=1, offset=CINEMATIC_356, x=31, y=74
	video type=1, offset=CINEMATIC_356, x=293, y=150, zoom=0x40
	video type=1, offset=CINEMATIC_357, x=97, y=110
	video type=1, offset=CINEMATIC_357, x=29, y=103
	video type=1, offset=CINEMATIC_357, x=37, y=15
	video type=1, offset=CINEMATIC_357, x=43, y=12
	video type=1, offset=CINEMATIC_357, x=86, y=72
	video type=1, offset=CINEMATIC_357, x=35, y=103
	video type=1, offset=CINEMATIC_357, x=218, y=152
	video type=1, offset=CINEMATIC_357, x=93, y=77
	video type=1, offset=CINEMATIC_358, x=161, y=96
	video type=1, offset=CINEMATIC_296, x=59, y=96
	ret

LABEL_D66F:
	fill page=0x00, color=0x08
	video type=1, offset=CINEMATIC_361, x=160, y=100
	video type=1, offset=CINEMATIC_362, x=160, y=100
	video type=1, offset=CINEMATIC_296, x=214, y=153
	video type=1, offset=CINEMATIC_296, x=248, y=153
	video type=1, offset=CINEMATIC_296, x=310, y=153, zoom=0x40
	video type=1, offset=CINEMATIC_356, x=24, y=62
	video type=1, offset=CINEMATIC_356, x=32, y=71
	video type=1, offset=CINEMATIC_356, x=24, y=69
	video type=1, offset=CINEMATIC_356, x=38, y=136
	video type=1, offset=CINEMATIC_356, x=0, y=64
	video type=1, offset=CINEMATIC_356, x=25, y=71
	video type=1, offset=CINEMATIC_356, x=4, y=158
	video type=1, offset=CINEMATIC_356, x=112, y=82
	video type=1, offset=CINEMATIC_356, x=297, y=109, zoom=0x40
	video type=1, offset=CINEMATIC_356, x=317, y=87, zoom=0x40
	video type=1, offset=CINEMATIC_356, x=203, y=157
	video type=1, offset=CINEMATIC_357, x=27, y=65
	video type=1, offset=CINEMATIC_357, x=34, y=80
	video type=1, offset=CINEMATIC_357, x=54, y=140
	video type=1, offset=CINEMATIC_357, x=43, y=167
	video type=1, offset=CINEMATIC_357, x=4, y=170
	video type=1, offset=CINEMATIC_357, x=203, y=163
	video type=1, offset=CINEMATIC_357, x=308, y=104, zoom=0x40
	video type=1, offset=CINEMATIC_357, x=309, y=152, zoom=0x40
	video type=1, offset=CINEMATIC_357, x=121, y=84
	video type=1, offset=CINEMATIC_357, x=93, y=107
	video type=1, offset=CINEMATIC_357, x=2, y=116
	video type=1, offset=CINEMATIC_357, x=123, y=173
	video type=1, offset=CINEMATIC_357, x=137, y=187
	video type=1, offset=CINEMATIC_357, x=124, y=192
	video type=1, offset=CINEMATIC_363, x=197, y=154
	video type=1, offset=CINEMATIC_358, x=302, y=141, zoom=0x40
	video type=1, offset=CINEMATIC_358, x=209, y=129
	video type=1, offset=CINEMATIC_358, x=6, y=57
	ret

LABEL_D701:
	fill page=0x00, color=0x08
	video type=1, offset=CINEMATIC_364, x=160, y=100
	video type=1, offset=CINEMATIC_296, x=47, y=153
	video type=1, offset=CINEMATIC_296, x=68, y=153
	video type=1, offset=CINEMATIC_296, x=104, y=153
	video type=1, offset=CINEMATIC_296, x=141, y=152
	video type=1, offset=CINEMATIC_296, x=11, y=153
	video type=1, offset=CINEMATIC_296, x=157, y=155
	video type=1, offset=CINEMATIC_296, x=188, y=154
	video type=1, offset=CINEMATIC_296, x=219, y=154
	video type=1, offset=CINEMATIC_296, x=302, y=153, zoom=0x40
	video type=1, offset=CINEMATIC_296, x=177, y=153
	video type=1, offset=CINEMATIC_296, x=262, y=153, zoom=0x40
	ret

LABEL_D737:
	fill page=0x00, color=0x02
	video type=1, offset=CINEMATIC_365, x=160, y=100
	video type=1, offset=CINEMATIC_366, x=160, y=100
	video type=1, offset=CINEMATIC_367, x=95, y=150
	video type=1, offset=CINEMATIC_367, x=191, y=40, zoom=[0x3b]	;@raw=0x6A,0x73,0x83,0xBF,0x28,0x3B
	video type=1, offset=CINEMATIC_367, x=191, y=40, zoom=[0x2f]	;@raw=0x6A,0x73,0x83,0xBF,0x28,0x2F
	video type=1, offset=CINEMATIC_367, x=192, y=42, zoom=[0x20]	;@raw=0x6A,0x73,0x83,0xC0,0x2A,0x20
	video type=1, offset=CINEMATIC_367, x=232, y=41, zoom=[0x29]	;@raw=0x6A,0x73,0x83,0xE8,0x29,0x29
	video type=1, offset=CINEMATIC_368, x=196, y=90
	video type=1, offset=CINEMATIC_368, x=197, y=96
	video type=1, offset=CINEMATIC_368, x=196, y=99
	video type=1, offset=CINEMATIC_368, x=196, y=102
	video type=1, offset=CINEMATIC_368, x=220, y=94
	video type=1, offset=CINEMATIC_368, x=220, y=97
	video type=1, offset=CINEMATIC_368, x=219, y=101
	video type=1, offset=CINEMATIC_368, x=196, y=94
	video type=1, offset=CINEMATIC_368, x=220, y=90
	ret

LABEL_D783:
	fill page=0x00, color=0x00
	video type=1, offset=CINEMATIC_369, x=160, y=100
	video type=1, offset=CINEMATIC_370, x=160, y=100
	video type=1, offset=CINEMATIC_371, x=160, y=100
	video type=1, offset=CINEMATIC_372, x=[0xec], y=130, zoom=[0x20]	;@raw=0x5A,0x3B,0xF6,0xEC,0x82,0x20
	video type=1, offset=CINEMATIC_372, x=[0xed], y=150, zoom=[0x30]	;@raw=0x5A,0x3B,0xF6,0xED,0x96,0x30
	video type=1, offset=CINEMATIC_373, x=154, y=159
	video type=1, offset=CINEMATIC_373, x=145, y=173
	video type=1, offset=CINEMATIC_373, x=56, y=108
	video type=1, offset=CINEMATIC_356, x=300, y=130, zoom=0x40
	ret

LABEL_D7B0:
	fill page=0x00, color=0x00
	video type=1, offset=CINEMATIC_454, x=160, y=100
	video type=1, offset=CINEMATIC_455, x=160, y=100
	video type=1, offset=CINEMATIC_456, x=160, y=100
	jne [0xB0], 0x03, SHARED_RET
	video type=1, offset=CINEMATIC_457, x=160, y=230, zoom=0x40
	ret

LABEL_D7CB:
	fill page=0x00, color=0x00
	video type=1, offset=CINEMATIC_614, x=160, y=100
	video type=1, offset=CINEMATIC_615, x=160, y=100
	video type=1, offset=CINEMATIC_616, x=160, y=100
	video type=1, offset=CINEMATIC_618, x=160, y=100
	jl [0xB0], 0x02, LABEL_D7E8
	video type=1, offset=CINEMATIC_619, x=160, y=100

LABEL_D7E8:
	mov [0xF8], [0xB0]
	and [0xF8], 0x0001
	je [0xF8], 0x00, SHARED_RET
	video type=1, offset=CINEMATIC_457, x=65466, y=97, zoom=0x40
	jl [0xB0], 0x02, SHARED_RET
	video type=1, offset=CINEMATIC_457, x=160, y=97
	video type=1, offset=CINEMATIC_457, x=100, y=97
	setPalette 0x10
	ret

LABEL_D80D:
	fill page=0x00, color=0x00
	video type=1, offset=CINEMATIC_614, x=160, y=100
	video type=1, offset=CINEMATIC_615, x=160, y=100
	video type=1, offset=CINEMATIC_616, x=160, y=100
	video type=1, offset=CINEMATIC_617, x=65527, y=98, zoom=0x40
	jne [0xB0], 0x03, SHARED_RET
	video type=1, offset=CINEMATIC_457, x=160, y=50
	video type=1, offset=CINEMATIC_457, x=160, y=130
	setPalette 0x10
	ret

LABEL_D834:
	fill page=0x00, color=0x03
	video type=1, offset=CINEMATIC_558, x=160, y=100
	video type=1, offset=CINEMATIC_356, x=180, y=70
	video type=1, offset=CINEMATIC_372, x=178, y=73
	ret

LABEL_D844:
	fill page=0x00, color=0x03
	video type=1, offset=CINEMATIC_561, x=160, y=100
	ret

LABEL_D84C:
	fill page=0x00, color=0x02
	video type=1, offset=CINEMATIC_627, x=161, y=106
	video type=1, offset=CINEMATIC_369, x=150, y=65522, zoom=0x40
	video type=1, offset=CINEMATIC_628, x=32, y=102
	video type=1, offset=CINEMATIC_628, x=287, y=102, zoom=0x40
	video type=1, offset=CINEMATIC_628, x=125, y=101
	video type=1, offset=CINEMATIC_628, x=193, y=101
	video type=1, offset=CINEMATIC_367, x=161, y=143
	video type=1, offset=CINEMATIC_629, x=394, y=100, zoom=0x40
	video type=1, offset=CINEMATIC_630, x=99, y=100
	video type=1, offset=CINEMATIC_630, x=271, y=100, zoom=0x40
	video type=1, offset=CINEMATIC_631, x=10, y=100
	video type=1, offset=CINEMATIC_355, x=481, y=65456, zoom=0x40
	mov [0xF8], [0xB1]
	and [0xF8], 0x0004
	jne [0xF8], 0x00, SHARED_RET
	video type=1, offset=CINEMATIC_632, x=3, y=123
	ret
	video type=1, offset=CINEMATIC_632, x=332, y=123, zoom=0x40
	killChannel

LABEL_D89E:
	fill page=0x00, color=0x02
	video type=1, offset=CINEMATIC_627, x=160, y=100
	video type=1, offset=CINEMATIC_638, x=160, y=100
	video type=1, offset=CINEMATIC_639, x=160, y=100
	ret

LABEL_D8AE:
	fill page=0x00, color=0x02
	video type=1, offset=CINEMATIC_627, x=160, y=100
	video type=1, offset=CINEMATIC_640, x=160, y=100
	video type=1, offset=CINEMATIC_639, x=160, y=100
	ret

LABEL_D8BE:
	fill page=0x00, color=0x02
	video type=1, offset=CINEMATIC_627, x=160, y=100
	video type=1, offset=CINEMATIC_639, x=160, y=100
	ret

LABEL_D8CA:
	fill page=0x00, color=0x02
	video type=1, offset=CINEMATIC_627, x=160, y=100
	video type=1, offset=CINEMATIC_627, x=390, y=100, zoom=0x40
	video type=1, offset=CINEMATIC_641, x=364, y=107, zoom=0x40
	video type=1, offset=CINEMATIC_642, x=160, y=100
	video type=1, offset=CINEMATIC_577, x=160, y=100
	video type=1, offset=CINEMATIC_579, x=160, y=100
	ret
LABEL_D8E8:
	db 0x11

LABEL_D8E9:
	fill page=0x00, color=0x08
	video type=1, offset=CINEMATIC_563, x=160, y=100
	video type=1, offset=CINEMATIC_564, x=160, y=100
	ret
	jne [0x27], 0x01, LABEL_D904
	mov [0x22], 0x005A
	mov [0x21], 0x00B6
	ret

LABEL_D904:
	jg [0x27], 0x04, LABEL_D913
	mov [0x22], 0x0050
	mov [0x21], 0x00B6
	ret

LABEL_D913:
	jne [0x27], 0x05, LABEL_D926
	mov [0x22], 0x0014
	mov [0x21], 0x0081
	mov [0x23], 0x0000
	ret

LABEL_D926:
	jne [0x27], 0x25, LABEL_D939
	mov [0x22], 0x0081
	mov [0x21], 0x00B4
	mov [0x23], 0x0001
	ret

LABEL_D939:
	jne [0x27], 0x24, LABEL_D948
	mov [0x22], 0x005D
	mov [0x21], 0x00B6
	ret

LABEL_D948:
	jne [0x27], 0x23, LABEL_D957
	mov [0x22], 0x005C
	mov [0x21], 0x00B6
	ret

LABEL_D957:
	jne [0x27], 0x45, LABEL_D96A
	mov [0x22], 0x0014
	mov [0x21], 0x0081
	mov [0x23], 0x0000
	ret

LABEL_D96A:
	jne [0x27], 0x44, LABEL_D979
	mov [0x22], 0x0046
	mov [0x21], 0x008B
	ret

LABEL_D979:
	ret
LABEL_D97A:
	db 0x11
