LABEL_D2ED:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_392, x=160, y=100
	video offset=CINEMATIC_393, x=160, y=100
	selectVideoPage 0x03
	fill page=0x03, color=0x09
	mov [SCROLL_Y], 0x0096
	copyVideoPage src=0x80, dst=0x03
	selectVideoPage 0x00
	ret

LABEL_D307:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_395, x=160, y=100
	video offset=CINEMATIC_396, x=160, y=100
	copyVideoPage src=0x00, dst=0x03
	video offset=CINEMATIC_397, x=160, y=100
	ret

LABEL_D31A:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_408, x=160, y=100
	video offset=CINEMATIC_409, x=160, y=100
	ret

DRAW_CIN_415_416_FRAGMENTS:
	fill page=0x00, color=0x08
	video offset=CINEMATIC_415, x=160, y=100
	video offset=CINEMATIC_416, x=202, y=65
	video offset=CINEMATIC_416, x=293, y=4, zoom=0x40
	video offset=CINEMATIC_416, x=298, y=117, zoom=0x40
	video offset=CINEMATIC_416, x=125, y=59, zoom=[0x2e]	;@enc=alt
	video offset=CINEMATIC_416, x=212, y=101, zoom=[0x2e]	;@enc=alt
	video offset=CINEMATIC_416, x=121, y=91, zoom=[0x20]	;@enc=alt
	video offset=CINEMATIC_416, x=201, y=132, zoom=[0x20]	;@enc=alt
	video offset=CINEMATIC_416, x=86, y=82
	video offset=CINEMATIC_416, x=257, y=78, zoom=0x40
	video offset=CINEMATIC_416, x=249, y=151
	video offset=CINEMATIC_416, x=159, y=16
	video offset=CINEMATIC_416, x=250, y=155, zoom=[0x20]	;@enc=alt
	video offset=CINEMATIC_416, x=89, y=86, zoom=[0x20]	;@enc=alt
	copyVideoPage src=0x00, dst=0x03
	video offset=CINEMATIC_417, x=169, y=94
	ret

LABEL_D378:
	fill page=0x00, color=0x08
	video offset=CINEMATIC_356, x=134, y=103
	video offset=CINEMATIC_416, x=6, y=90
	video offset=CINEMATIC_416, x=315, y=147, zoom=[0x26]	;@enc=alt
	video offset=CINEMATIC_427, x=14, y=166
	video offset=CINEMATIC_416, x=44, y=133, zoom=[0x20]	;@enc=alt
	video offset=CINEMATIC_357, x=19, y=73
	video offset=CINEMATIC_357, x=16, y=76
	video offset=CINEMATIC_357, x=136, y=165
	video offset=CINEMATIC_357, x=82, y=139
	video offset=CINEMATIC_357, x=38, y=167
	video offset=CINEMATIC_357, x=245, y=150
	video offset=CINEMATIC_357, x=252, y=83
	video offset=CINEMATIC_357, x=310, y=138, zoom=0x40
	video offset=CINEMATIC_357, x=303, y=169, zoom=0x40
	video offset=CINEMATIC_357, x=191, y=169
	video offset=CINEMATIC_357, x=150, y=156
	video offset=CINEMATIC_428, x=96, y=124
	video offset=CINEMATIC_428, x=107, y=108
	video offset=CINEMATIC_428, x=150, y=169
	video offset=CINEMATIC_428, x=130, y=142
	video offset=CINEMATIC_429, x=160, y=100
	video offset=CINEMATIC_430, x=160, y=100
	video offset=CINEMATIC_431, x=83, y=165
	video offset=CINEMATIC_431, x=136, y=165
	video offset=CINEMATIC_431, x=233, y=165
	video offset=CINEMATIC_431, x=293, y=165, zoom=0x40
	video offset=CINEMATIC_295, x=91, y=153
	video offset=CINEMATIC_295, x=28, y=153
	video offset=CINEMATIC_295, x=59, y=153
	video offset=CINEMATIC_295, x=124, y=153
	video offset=CINEMATIC_295, x=320, y=153, zoom=0x40
	video offset=CINEMATIC_295, x=269, y=153, zoom=0x40
	video offset=CINEMATIC_295, x=132, y=153
	video offset=CINEMATIC_295, x=203, y=153
	video offset=CINEMATIC_295, x=170, y=153
	video offset=CINEMATIC_432, x=230, y=172
	ret

LABEL_D415:
	fill page=0x00, color=0x08
	video offset=CINEMATIC_434, x=160, y=100
	video offset=CINEMATIC_435, x=160, y=100
	video offset=CINEMATIC_436, x=160, y=100
	ret

LABEL_D425:
	fill page=0x00, color=0x08
	video offset=CINEMATIC_454, x=160, y=100
	ret

LABEL_D42D:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_579, x=160, y=100
	video offset=CINEMATIC_580, x=160, y=100
	jne [0xAF], 0x58, SHARED_RET
	video offset=CINEMATIC_581, x=160, y=100
	video offset=CINEMATIC_458, x=199, y=200, zoom=0x40
	video offset=CINEMATIC_458, x=250, y=189
	ret

LABEL_D44C:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_591, x=160, y=100
	video offset=CINEMATIC_592, x=160, y=100
	video offset=CINEMATIC_593, x=160, y=100
	ret

LABEL_D45C:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_595, x=160, y=100
	video offset=CINEMATIC_596, x=160, y=100
	video offset=CINEMATIC_597, x=65510, y=198, zoom=0x40
	ret

LABEL_D46E:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_600, x=161, y=100
	video offset=CINEMATIC_601, x=161, y=99
	selectVideoPage 0x03
	fill page=0x03, color=0x00
	video offset=CINEMATIC_600, x=160, y=100
	video offset=CINEMATIC_601, x=160, y=100
	ret

LABEL_D487:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_634, x=160, y=100
	video offset=CINEMATIC_635, x=160, y=100
	video offset=CINEMATIC_636, x=256, y=167, zoom=[0x20]	;@enc=alt
	video offset=CINEMATIC_637, x=244, y=170, zoom=[0x20]	;@enc=alt
	video offset=CINEMATIC_638, x=135, y=202, zoom=0x40
	copyVideoPage src=0x00, dst=0x03
	mov [0xF8], [0xB1]
	and [0xF8], 0x0008
	jne [0xF8], 0x00, DRAW_CIN_639
	video offset=CINEMATIC_640, x=160, y=100
	ret

DRAW_CIN_639:
	video offset=CINEMATIC_639, x=160, y=100
	ret

LABEL_D4BD:
	fill page=0x00, color=0x09
	video offset=CINEMATIC_645, x=155, y=100
	video offset=CINEMATIC_646, x=155, y=100
	ret

LABEL_D4C9:
	fill page=0x00, color=0x09
	video offset=CINEMATIC_646, x=25, y=100
	ret

LABEL_D4D1:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_649, x=160, y=100
	video offset=CINEMATIC_650, x=160, y=100
	video offset=CINEMATIC_651, x=160, y=100
	video offset=CINEMATIC_652, x=160, y=100
	ret

LABEL_D4E5:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_717, x=160, y=100
	video offset=CINEMATIC_718, x=160, y=100
	video offset=CINEMATIC_719, x=160, y=100
	video offset=CINEMATIC_636, x=130, y=57
	video offset=CINEMATIC_637, x=39, y=51, zoom=[0x20]	;@enc=alt
	video offset=CINEMATIC_720, x=27, y=47, zoom=[0x20]	;@enc=alt
	ret

LABEL_D505:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_726, x=160, y=100
	video offset=CINEMATIC_727, x=160, y=100
	video offset=CINEMATIC_728, x=160, y=100
	ret

LABEL_D515:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_730, x=160, y=100
	video offset=CINEMATIC_731, x=160, y=100
	video offset=CINEMATIC_732, x=160, y=100
	video offset=CINEMATIC_733, x=160, y=100
	ret

LABEL_D529:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_731, x=160, y=100
	video offset=CINEMATIC_730, x=160, y=100
	video offset=CINEMATIC_746, x=160, y=100
	video offset=CINEMATIC_747, x=160, y=100
	jne [0xB0], 0x03, SHARED_RET
	setPalette 0x10
	video offset=CINEMATIC_637, x=49, y=115
	video offset=CINEMATIC_636, x=8, y=96
	video offset=CINEMATIC_720, x=28, y=110
	video offset=CINEMATIC_636, x=68, y=115
	video offset=CINEMATIC_637, x=9, y=80
	video offset=CINEMATIC_637, x=6, y=99
	video offset=CINEMATIC_636, x=15, y=120, zoom=[0x2a]	;@enc=alt
	video offset=CINEMATIC_720, x=65526, y=66, zoom=0x40
	ret

LABEL_D56A:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_731, x=160, y=100
	video offset=CINEMATIC_730, x=160, y=100
	video offset=CINEMATIC_746, x=160, y=100
	video offset=CINEMATIC_747, x=160, y=100
	ret

LABEL_D57E:
	jne [0xB0], 0x03, SHARED_RET
	video offset=CINEMATIC_458, x=70, y=97
	video offset=CINEMATIC_458, x=260, y=97, zoom=0x40
	ret

LABEL_D58E:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_647, x=160, y=100
	video offset=CINEMATIC_607, x=327, y=146, zoom=0x40
	video offset=CINEMATIC_638, x=239, y=137
	video offset=CINEMATIC_638, x=243, y=180
	jne [0xB0], 0x03, SHARED_RET
	video offset=CINEMATIC_458, x=131, y=217, zoom=0x40
	ret

LABEL_D5AE:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_731, x=160, y=100
	video offset=CINEMATIC_730, x=160, y=100
	video offset=CINEMATIC_746, x=160, y=100
	video offset=CINEMATIC_747, x=160, y=100
	video offset=CINEMATIC_748, x=160, y=100
	ret

LABEL_D5C6:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_750, x=160, y=100
	video offset=CINEMATIC_751, x=160, y=100
	video offset=CINEMATIC_752, x=160, y=100
	video offset=CINEMATIC_753, x=160, y=100
	video offset=CINEMATIC_754, x=296, y=23, zoom=0x40
	video offset=CINEMATIC_755, x=298, y=66, zoom=0x40
	video offset=CINEMATIC_756, x=260, y=88, zoom=0x40
	video offset=CINEMATIC_756, x=326, y=82, zoom=0x40
	video offset=CINEMATIC_757, x=160, y=100
	jne [0xB0], 0x03, SHARED_RET
	video offset=CINEMATIC_458, x=65508, y=90, zoom=0x40
	video offset=CINEMATIC_458, x=156, y=184
	ret

LABEL_D602:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_731, x=160, y=70
	video offset=CINEMATIC_730, x=160, y=70
	video offset=CINEMATIC_746, x=160, y=80
	video offset=CINEMATIC_747, x=160, y=80
	video offset=CINEMATIC_761, x=91, y=44
	video offset=CINEMATIC_762, x=86, y=70
	video offset=CINEMATIC_763, x=217, y=71
	video offset=CINEMATIC_764, x=160, y=100
	ret
LABEL_D626:
	db 0x11

LABEL_D627:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_294, x=160, y=100
	video offset=CINEMATIC_295, x=165, y=111
	video offset=CINEMATIC_295, x=220, y=110
	video offset=CINEMATIC_295, x=257, y=111, zoom=0x40
	video offset=CINEMATIC_295, x=301, y=111, zoom=0x40
	video offset=CINEMATIC_295, x=33, y=112
	video offset=CINEMATIC_295, x=70, y=110
	ret
LABEL_D649:
	db 0x11

LABEL_D64A:
	fill page=0x00, color=0x00
	fill page=0x03, color=0x00
	load id=0x0043
	copyVideoPage src=0x00, dst=0x03
	mov [SCROLL_Y], 0x0002
	copyVideoPage src=0x83, dst=0x00
	selectVideoPage 0x00
	video offset=CINEMATIC_298, x=163, y=99
	video offset=CINEMATIC_299, x=162, y=99
	selectVideoPage 0x03
	video offset=CINEMATIC_298, x=160, y=100
	video offset=CINEMATIC_299, x=160, y=100
	selectVideoPage 0xFF
	ret

LABEL_D674:
	fill page=0x00, color=0x00
	fill page=0x03, color=0x00
	load id=0x0043
	copyVideoPage src=0x00, dst=0x03
	mov [SCROLL_Y], 0xFFDA
	copyVideoPage src=0x80, dst=0x03
	mov [SCROLL_Y], 0x0002
	copyVideoPage src=0x83, dst=0x00
	selectVideoPage 0x00
	video offset=CINEMATIC_299, x=161, y=61
	video offset=CINEMATIC_299, x=161, y=62
	selectVideoPage 0x03
	video offset=CINEMATIC_299, x=161, y=60
	video offset=CINEMATIC_299, x=160, y=62
	selectVideoPage 0xFF
	ret

LABEL_D6A5:
	fill page=0x00, color=0x08
	video offset=CINEMATIC_316, x=160, y=100
	video offset=CINEMATIC_317, x=160, y=100
	video offset=CINEMATIC_318, x=160, y=100
	video offset=CINEMATIC_319, x=160, y=100
	ret

LABEL_D6B9:
	fill page=0x00, color=0x08
	video offset=CINEMATIC_353, x=160, y=100
	video offset=CINEMATIC_354, x=160, y=100
	video offset=CINEMATIC_355, x=160, y=100
	video offset=CINEMATIC_356, x=31, y=74
	video offset=CINEMATIC_356, x=293, y=150, zoom=0x40
	video offset=CINEMATIC_357, x=97, y=110
	video offset=CINEMATIC_357, x=29, y=103
	video offset=CINEMATIC_357, x=37, y=15
	video offset=CINEMATIC_357, x=43, y=12
	video offset=CINEMATIC_357, x=86, y=72
	video offset=CINEMATIC_357, x=35, y=103
	video offset=CINEMATIC_357, x=218, y=152
	video offset=CINEMATIC_357, x=93, y=77
	video offset=CINEMATIC_358, x=161, y=96
	video offset=CINEMATIC_295, x=59, y=96
	ret

LABEL_D6FA:
	fill page=0x00, color=0x08
	video offset=CINEMATIC_360, x=160, y=100
	video offset=CINEMATIC_361, x=160, y=100
	video offset=CINEMATIC_295, x=214, y=153
	video offset=CINEMATIC_295, x=248, y=153
	video offset=CINEMATIC_295, x=310, y=153, zoom=0x40
	video offset=CINEMATIC_356, x=24, y=62
	video offset=CINEMATIC_356, x=32, y=71
	video offset=CINEMATIC_356, x=24, y=69
	video offset=CINEMATIC_356, x=38, y=136
	video offset=CINEMATIC_356, x=0, y=64
	video offset=CINEMATIC_356, x=25, y=71
	video offset=CINEMATIC_356, x=4, y=158
	video offset=CINEMATIC_356, x=112, y=82
	video offset=CINEMATIC_356, x=297, y=109, zoom=0x40
	video offset=CINEMATIC_356, x=317, y=87, zoom=0x40
	video offset=CINEMATIC_356, x=203, y=157
	video offset=CINEMATIC_357, x=27, y=65
	video offset=CINEMATIC_357, x=34, y=80
	video offset=CINEMATIC_357, x=54, y=140
	video offset=CINEMATIC_357, x=43, y=167
	video offset=CINEMATIC_357, x=4, y=170
	video offset=CINEMATIC_357, x=203, y=163
	video offset=CINEMATIC_357, x=308, y=104, zoom=0x40
	video offset=CINEMATIC_357, x=309, y=152, zoom=0x40
	video offset=CINEMATIC_357, x=121, y=84
	video offset=CINEMATIC_357, x=93, y=107
	video offset=CINEMATIC_357, x=2, y=116
	video offset=CINEMATIC_357, x=123, y=173
	video offset=CINEMATIC_357, x=137, y=187
	video offset=CINEMATIC_357, x=124, y=192
	video offset=CINEMATIC_362, x=197, y=154
	video offset=CINEMATIC_358, x=302, y=141, zoom=0x40
	video offset=CINEMATIC_358, x=209, y=129
	video offset=CINEMATIC_358, x=6, y=57
	ret

LABEL_D78C:
	fill page=0x00, color=0x08
	video offset=CINEMATIC_363, x=160, y=100
	video offset=CINEMATIC_295, x=47, y=153
	video offset=CINEMATIC_295, x=68, y=153
	video offset=CINEMATIC_295, x=104, y=153
	video offset=CINEMATIC_295, x=141, y=152
	video offset=CINEMATIC_295, x=11, y=153
	video offset=CINEMATIC_295, x=157, y=155
	video offset=CINEMATIC_295, x=188, y=154
	video offset=CINEMATIC_295, x=219, y=154
	video offset=CINEMATIC_295, x=302, y=153, zoom=0x40
	video offset=CINEMATIC_295, x=177, y=153
	video offset=CINEMATIC_295, x=262, y=153, zoom=0x40
	ret

LABEL_D7C2:
	fill page=0x00, color=0x02
	video offset=CINEMATIC_364, x=160, y=100
	video offset=CINEMATIC_365, x=160, y=100
	video offset=CINEMATIC_366, x=95, y=150
	video offset=CINEMATIC_366, x=191, y=40, zoom=[0x3b]	;@enc=alt
	video offset=CINEMATIC_366, x=191, y=40, zoom=[0x2f]	;@enc=alt
	video offset=CINEMATIC_366, x=192, y=42, zoom=[0x20]	;@enc=alt
	video offset=CINEMATIC_366, x=232, y=41, zoom=[0x29]	;@enc=alt
	video offset=CINEMATIC_367, x=196, y=90
	video offset=CINEMATIC_367, x=197, y=96
	video offset=CINEMATIC_367, x=196, y=99
	video offset=CINEMATIC_367, x=196, y=102
	video offset=CINEMATIC_367, x=220, y=94
	video offset=CINEMATIC_367, x=220, y=97
	video offset=CINEMATIC_367, x=219, y=101
	video offset=CINEMATIC_367, x=196, y=94
	video offset=CINEMATIC_367, x=220, y=90
	ret

LABEL_D80E:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_368, x=160, y=100
	video offset=CINEMATIC_369, x=160, y=100
	video offset=CINEMATIC_370, x=160, y=100
	video offset=CINEMATIC_371, x=[0xec], y=130, zoom=[0x20]	;@enc=alt
	video offset=CINEMATIC_371, x=[0xed], y=150, zoom=[0x30]	;@enc=alt
	video offset=CINEMATIC_372, x=154, y=159
	video offset=CINEMATIC_372, x=145, y=173
	video offset=CINEMATIC_372, x=56, y=108
	video offset=CINEMATIC_356, x=300, y=130, zoom=0x40
	ret

LABEL_D83B:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_455, x=160, y=100
	video offset=CINEMATIC_456, x=160, y=100
	video offset=CINEMATIC_457, x=160, y=100
	jne [0xB0], 0x03, SHARED_RET
	video offset=CINEMATIC_458, x=160, y=230, zoom=0x40
	ret

LABEL_D856:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_604, x=160, y=100
	video offset=CINEMATIC_605, x=160, y=100
	video offset=CINEMATIC_606, x=160, y=100
	video offset=CINEMATIC_608, x=160, y=100
	jl [0xB0], 0x02, LABEL_D873
	video offset=CINEMATIC_609, x=160, y=100

LABEL_D873:
	mov [0xF8], [0xB0]
	and [0xF8], 0x0001
	je [0xF8], 0x00, SHARED_RET
	video offset=CINEMATIC_458, x=65486, y=97, zoom=0x40
	jl [0xB0], 0x02, SHARED_RET
	video offset=CINEMATIC_458, x=160, y=97
	video offset=CINEMATIC_458, x=100, y=97
	setPalette 0x10
	ret

LABEL_D898:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_604, x=160, y=100
	video offset=CINEMATIC_605, x=160, y=100
	video offset=CINEMATIC_606, x=160, y=100
	video offset=CINEMATIC_607, x=65527, y=98, zoom=0x40
	jne [0xB0], 0x03, SHARED_RET
	call LABEL_0080
	video offset=CINEMATIC_458, x=160, y=50
	video offset=CINEMATIC_458, x=160, y=130
	setPalette 0x10
	ret

LABEL_D8C2:
	fill page=0x00, color=0x03
	video offset=CINEMATIC_559, x=160, y=100
	video offset=CINEMATIC_356, x=180, y=70
	video offset=CINEMATIC_371, x=178, y=73
	ret

LABEL_D8D2:
	fill page=0x00, color=0x03
	video offset=CINEMATIC_563, x=160, y=100
	ret

LABEL_D8DA:
	fill page=0x00, color=0x02
	video offset=CINEMATIC_618, x=161, y=106
	video offset=CINEMATIC_368, x=150, y=65522, zoom=0x40
	video offset=CINEMATIC_619, x=32, y=102
	video offset=CINEMATIC_619, x=287, y=102, zoom=0x40
	video offset=CINEMATIC_619, x=125, y=101
	video offset=CINEMATIC_619, x=193, y=101
	video offset=CINEMATIC_366, x=161, y=143
	video offset=CINEMATIC_620, x=394, y=100, zoom=0x40
	video offset=CINEMATIC_621, x=99, y=100
	video offset=CINEMATIC_621, x=271, y=100, zoom=0x40
	video offset=CINEMATIC_622, x=10, y=100
	video offset=CINEMATIC_355, x=481, y=65456, zoom=0x40
	mov [0xF8], [0xB1]
	and [0xF8], 0x0004
	jne [0xF8], 0x00, SHARED_RET
	video offset=CINEMATIC_623, x=3, y=123
	ret
	video offset=CINEMATIC_623, x=332, y=123, zoom=0x40
	killChannel

LABEL_D92C:
	fill page=0x00, color=0x02
	video offset=CINEMATIC_618, x=160, y=100
	video offset=CINEMATIC_629, x=160, y=100
	video offset=CINEMATIC_630, x=160, y=100
	ret

LABEL_D93C:
	fill page=0x00, color=0x02
	video offset=CINEMATIC_618, x=160, y=100
	video offset=CINEMATIC_631, x=160, y=100
	video offset=CINEMATIC_630, x=160, y=100
	ret

LABEL_D94C:
	fill page=0x00, color=0x02
	video offset=CINEMATIC_618, x=160, y=100
	video offset=CINEMATIC_630, x=160, y=100
	ret

LABEL_D958:
	fill page=0x00, color=0x02
	video offset=CINEMATIC_618, x=160, y=100
	video offset=CINEMATIC_618, x=390, y=100, zoom=0x40
	video offset=CINEMATIC_632, x=364, y=107, zoom=0x40
	video offset=CINEMATIC_633, x=160, y=100
	video offset=CINEMATIC_565, x=160, y=100
	video offset=CINEMATIC_567, x=160, y=100
	ret
LABEL_D976:
	db 0x11

FILL_PAGE_00_COLOR_08:
	fill page=0x00, color=0x08
	ret
	jne [0x27], 0x01, LABEL_D98A
	mov [0x22], 0x005A
	mov [0x21], 0x00B6
	ret

LABEL_D98A:
	jg [0x27], 0x04, LABEL_D999
	mov [0x22], 0x0050
	mov [0x21], 0x00B6
	ret

LABEL_D999:
	jne [0x27], 0x05, LABEL_D9AC
	mov [0x22], 0x0014
	mov [0x21], 0x0081
	mov [0x23], 0x0000
	ret

LABEL_D9AC:
	jne [0x27], 0x25, LABEL_D9BF
	mov [0x22], 0x0081
	mov [0x21], 0x00B4
	mov [0x23], 0x0001
	ret

LABEL_D9BF:
	jne [0x27], 0x24, LABEL_D9CE
	mov [0x22], 0x005D
	mov [0x21], 0x00B6
	ret

LABEL_D9CE:
	jne [0x27], 0x23, LABEL_D9DD
	mov [0x22], 0x005C
	mov [0x21], 0x00B6
	ret

LABEL_D9DD:
	jne [0x27], 0x45, LABEL_D9F0
	mov [0x22], 0x0014
	mov [0x21], 0x0081
	mov [0x23], 0x0000
	ret

LABEL_D9F0:
	jne [0x27], 0x44, LABEL_D9FF
	mov [0x22], 0x0046
	mov [0x21], 0x008B
	ret

LABEL_D9FF:
	ret
LABEL_DA00:
	db 0x11
