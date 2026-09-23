; composes BG_F0 + BG_F1
; into the cave's first
; room — fill page0,
; draw both BG frames,
; setPage3 backdrop
DRAW_CAVES_FIRST_ROOM_BG:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_CAVES_FIRST_ROOM_BG_F0, x=160, y=100
	video offset=CINEMATIC_CAVES_FIRST_ROOM_BG_F1, x=160, y=100
	selectVideoPage 0x03
	fill page=0x03, color=0x09
	mov [SCROLL_Y], 0x0096
	copyVideoPage src=0x80, dst=0x03
	selectVideoPage 0x00
	ret


CAVES_SCREEN_68_BACKDROP_DRAW:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_CAVES_SCREEN_6B_BACKDROP_LAYER_14, x=160, y=100
	video offset=CINEMATIC_397, x=160, y=100
	copyVideoPage src=0x00, dst=0x03
	video offset=CINEMATIC_398, x=160, y=100
	ret


CAVES_SCREEN_69_BACKDROP_DRAW:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_408, x=160, y=100
	video offset=CINEMATIC_409, x=160, y=100
	ret


DRAW_CIN_415_416_FRAGMENTS:
	fill page=0x00, color=0x08
	video offset=CINEMATIC_CAVES_SCREEN_6D_BACKDROP_2, x=160, y=100
	video offset=CINEMATIC_416, x=202, y=65
	video offset=CINEMATIC_416, x=293, y=4
	video offset=CINEMATIC_416, x=298, y=117
	video offset=CINEMATIC_416, x=125, y=59, zoom=0x2e
	video offset=CINEMATIC_416, x=212, y=101, zoom=0x2e
	video offset=CINEMATIC_416, x=121, y=91, zoom=0x20
	video offset=CINEMATIC_416, x=201, y=132, zoom=0x20
	video offset=CINEMATIC_416, x=86, y=82
	video offset=CINEMATIC_416, x=257, y=78
	video offset=CINEMATIC_416, x=249, y=151
	video offset=CINEMATIC_416, x=159, y=16
	video offset=CINEMATIC_416, x=250, y=155, zoom=0x20
	video offset=CINEMATIC_416, x=89, y=86, zoom=0x20
	copyVideoPage src=0x00, dst=0x03
	video offset=CINEMATIC_417, x=169, y=94
	ret


LABEL_D2F3:
	fill page=0x00, color=0x08
	video offset=CINEMATIC_356, x=134, y=103
	video offset=CINEMATIC_416, x=6, y=90
	video offset=CINEMATIC_416, x=315, y=147, zoom=0x26
	video offset=CINEMATIC_427, x=14, y=166
	video offset=CINEMATIC_416, x=44, y=133, zoom=0x20
	video offset=CINEMATIC_357, x=19, y=73
	video offset=CINEMATIC_357, x=16, y=76
	video offset=CINEMATIC_357, x=136, y=165
	video offset=CINEMATIC_357, x=82, y=139
	video offset=CINEMATIC_357, x=38, y=167
	video offset=CINEMATIC_357, x=245, y=150
	video offset=CINEMATIC_357, x=252, y=83
	video offset=CINEMATIC_357, x=310, y=138
	video offset=CINEMATIC_357, x=303, y=169
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
	video offset=CINEMATIC_431, x=293, y=165
	video offset=CINEMATIC_CAVES_BUDDY_CRAWLING_BG_0, x=91, y=153
	video offset=CINEMATIC_CAVES_BUDDY_CRAWLING_BG_0, x=28, y=153
	video offset=CINEMATIC_CAVES_BUDDY_CRAWLING_BG_0, x=59, y=153
	video offset=CINEMATIC_CAVES_BUDDY_CRAWLING_BG_0, x=124, y=153
	video offset=CINEMATIC_CAVES_BUDDY_CRAWLING_BG_0, x=320, y=153
	video offset=CINEMATIC_CAVES_BUDDY_CRAWLING_BG_0, x=269, y=153
	video offset=CINEMATIC_CAVES_BUDDY_CRAWLING_BG_0, x=132, y=153
	video offset=CINEMATIC_CAVES_BUDDY_CRAWLING_BG_0, x=203, y=153
	video offset=CINEMATIC_CAVES_BUDDY_CRAWLING_BG_0, x=170, y=153
	video offset=CINEMATIC_432, x=230, y=172
	ret


CAVES_SCREEN_6D_BACKDROP_DRAW:
	fill page=0x00, color=0x08
	video offset=CINEMATIC_CAVES_SCREEN_6F_BACKDROP_LAYER_1, x=160, y=100
	video offset=CINEMATIC_CAVES_SCREEN_6F_BACKDROP_LAYER_2, x=160, y=100
	video offset=CINEMATIC_436, x=160, y=100
	ret


CAVES_SCREEN_6E_BACKDROP_DRAW:
	fill page=0x00, color=0x08
	video offset=CINEMATIC_453, x=160, y=100
	ret


CAVES_SCREEN_87_BACKDROP_DRAW:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_590, x=160, y=100
	video offset=CINEMATIC_591, x=160, y=100
	jne [0xAF], 0x58, SHARED_RET
	video offset=CINEMATIC_592, x=160, y=100
	video offset=CINEMATIC_CAVES_HERO_IDLE_DOWN_4, x=199, y=200, zoom=0x40
	video offset=CINEMATIC_CAVES_HERO_IDLE_DOWN_4, x=250, y=189
	ret


CAVES_SCREEN_88_BACKDROP_DRAW:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_602, x=160, y=100
	video offset=CINEMATIC_603, x=160, y=100
	video offset=CINEMATIC_604, x=160, y=100
	ret


CAVES_SCREEN_89_BACKDROP_DRAW:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_606, x=160, y=100
	video offset=CINEMATIC_607, x=160, y=100
	ret


LABEL_D3E3:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_610, x=161, y=100
	video offset=CINEMATIC_611, x=161, y=99
	selectVideoPage 0x03
	fill page=0x03, color=0x00
	video offset=CINEMATIC_610, x=160, y=100
	video offset=CINEMATIC_611, x=160, y=100
	ret


LABEL_D3FC:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_643, x=160, y=100
	video offset=CINEMATIC_644, x=160, y=100
	video offset=CINEMATIC_645, x=256, y=167, zoom=0x20
	video offset=CINEMATIC_646, x=244, y=170, zoom=0x20
	video offset=CINEMATIC_647, x=135, y=202, zoom=0x40
	copyVideoPage src=0x00, dst=0x03
	mov [0xF8], [0xB1]
	and [0xF8], 0x0008
	jne [0xF8], 0x00, DRAW_CIN_648
	video offset=CINEMATIC_649, x=160, y=100
	ret


DRAW_CIN_648:
	video offset=CINEMATIC_648, x=160, y=100
	ret


CAVES_SCREEN_A8_BACKDROP_DRAW:
	fill page=0x00, color=0x09
	video offset=CINEMATIC_655, x=155, y=100
	video offset=CINEMATIC_656, x=155, y=100
	ret


LABEL_D43E:
	fill page=0x00, color=0x09
	video offset=CINEMATIC_656, x=25, y=100
	ret


CAVES_SCREEN_C8_BACKDROP_DRAW:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_659, x=160, y=100
	video offset=CINEMATIC_660, x=160, y=100
	video offset=CINEMATIC_CAVES_FIGURE_DISINTEGRATION_F0, x=160, y=100
	video offset=CINEMATIC_CAVES_FIGURE_DISINTEGRATION_F1, x=160, y=100
	ret


CAVES_SCREEN_C9_BACKDROP_DRAW:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_CAVES_COLLAPSE_SEGMENTED_BAR_F2, x=160, y=100
	video offset=CINEMATIC_CAVES_HERO_COLLAPSE_F2, x=160, y=100
	video offset=CINEMATIC_CAVES_COLLAPSE_SEGMENTED_BAR_F3, x=160, y=100
	video offset=CINEMATIC_645, x=130, y=57
	video offset=CINEMATIC_646, x=39, y=51, zoom=0x20
	video offset=CINEMATIC_CAVES_HERO_COLLAPSE_F3, x=27, y=47, zoom=0x20
	ret


CAVES_SCREEN_CA_BACKDROP_DRAW:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_735, x=160, y=100
	video offset=CINEMATIC_CAVES_SCREEN_CD_BACKDROP_LAYER_4, x=160, y=100
	video offset=CINEMATIC_737, x=160, y=100
	ret


CAVES_SCREEN_CB_BACKDROP_DRAW:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_CAVES_SCREEN_ED_BACKDROP_LAYER_1, x=160, y=100
	video offset=CINEMATIC_CAVES_SCREEN_ED_BACKDROP_LAYER_2, x=160, y=100
	video offset=CINEMATIC_CAVES_SCREEN_ED_BACKDROP_LAYER_3, x=160, y=100
	video offset=CINEMATIC_CAVES_SCREEN_ED_BACKDROP_LAYER_4, x=160, y=100
	ret


LABEL_D49E:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_CAVES_SCREEN_ED_BACKDROP_LAYER_2, x=160, y=100
	video offset=CINEMATIC_CAVES_SCREEN_ED_BACKDROP_LAYER_1, x=160, y=100
	video offset=CINEMATIC_CAVES_LASER_BLAST_7, x=160, y=100
	video offset=CINEMATIC_CAVES_LASER_BLAST_6, x=160, y=100
	jne [0xB0], 0x03, SHARED_RET
	setPalette 0x10
	video offset=CINEMATIC_646, x=49, y=115
	video offset=CINEMATIC_645, x=8, y=96
	video offset=CINEMATIC_CAVES_HERO_COLLAPSE_F3, x=28, y=110
	video offset=CINEMATIC_645, x=68, y=115
	video offset=CINEMATIC_646, x=9, y=80
	video offset=CINEMATIC_646, x=6, y=99
	video offset=CINEMATIC_645, x=15, y=120, zoom=0x2a
	video offset=CINEMATIC_CAVES_HERO_COLLAPSE_F3, x=65526, y=66
	ret


LABEL_D4DF:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_CAVES_SCREEN_ED_BACKDROP_LAYER_2, x=160, y=100
	video offset=CINEMATIC_CAVES_SCREEN_ED_BACKDROP_LAYER_1, x=160, y=100
	video offset=CINEMATIC_CAVES_LASER_BLAST_7, x=160, y=100
	video offset=CINEMATIC_CAVES_LASER_BLAST_6, x=160, y=100
	ret


LABEL_D4F3:
	jne [0xB0], 0x03, SHARED_RET
	video offset=CINEMATIC_CAVES_HERO_IDLE_DOWN_4, x=70, y=97
	video offset=CINEMATIC_CAVES_HERO_IDLE_DOWN_4, x=260, y=97
	ret


CAVES_SCREEN_AD_BACKDROP_DRAW:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_657, x=160, y=100
	video offset=CINEMATIC_CAVES_SCREEN_92_BACKDROP_LAYER_1, x=327, y=146
	video offset=CINEMATIC_647, x=239, y=137
	video offset=CINEMATIC_647, x=243, y=180
	jne [0xB0], 0x03, SHARED_RET
	video offset=CINEMATIC_CAVES_HERO_IDLE_DOWN_4, x=131, y=217, zoom=0x40
	ret


DRAW_STALACTITE_CAVERN_BG:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_CAVES_SCREEN_ED_BACKDROP_LAYER_2, x=160, y=100
	video offset=CINEMATIC_CAVES_SCREEN_ED_BACKDROP_LAYER_1, x=160, y=100
	video offset=CINEMATIC_CAVES_LASER_BLAST_7, x=160, y=100
	video offset=CINEMATIC_CAVES_LASER_BLAST_6, x=160, y=100
	video offset=CINEMATIC_CAVES_LASER_BLAST_5, x=160, y=100
	ret


LABEL_D53B:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_CAVES_LASER_BLAST_3, x=160, y=100
	video offset=CINEMATIC_CAVES_LASER_BLAST_2, x=160, y=100
	video offset=CINEMATIC_CAVES_LASER_BLAST_1, x=160, y=100
	video offset=CINEMATIC_CAVES_LASER_BLAST_0, x=160, y=100
	video offset=CINEMATIC_763, x=296, y=23
	video offset=CINEMATIC_CAVES_LASER_IMPACT_RIGHT_7, x=298, y=66
	video offset=CINEMATIC_CAVES_LASER_IMPACT_RIGHT_6, x=260, y=88
	video offset=CINEMATIC_CAVES_LASER_IMPACT_RIGHT_6, x=326, y=82
	video offset=CINEMATIC_CAVES_LASER_IMPACT_RIGHT_5, x=160, y=100
	jne [0xB0], 0x03, SHARED_RET
	video offset=CINEMATIC_CAVES_HERO_IDLE_DOWN_4, x=65508, y=90
	video offset=CINEMATIC_CAVES_HERO_IDLE_DOWN_4, x=156, y=184
	ret


CAVES_SCREEN_EE_BACKDROP_DRAW:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_CAVES_SCREEN_ED_BACKDROP_LAYER_2, x=160, y=70
	video offset=CINEMATIC_CAVES_SCREEN_ED_BACKDROP_LAYER_1, x=160, y=70
	video offset=CINEMATIC_CAVES_LASER_BLAST_7, x=160, y=80
	video offset=CINEMATIC_CAVES_LASER_BLAST_6, x=160, y=80
	video offset=CINEMATIC_CAVES_LASER_IMPACT_RIGHT_1, x=91, y=44
	video offset=CINEMATIC_CAVES_LASER_IMPACT_RIGHT_0, x=86, y=70
	video offset=CINEMATIC_CAVES_SCREEN_EE_BACKDROP_LAYER_6, x=217, y=71
	video offset=CINEMATIC_CAVES_SCREEN_EE_BACKDROP_LAYER_7, x=160, y=100
	ret


LABEL_D59B:
	db 0x11

; composes BG_F0 + BG_F1
; into the cave's first
; room — fill page0,
; draw both BG frames,
; setPage3 backdrop
DRAW_WATERFALL_LEFT_STAIRS_BG:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_WATERFALL_LEFT_STAIRS_BG, x=160, y=100
	video offset=CINEMATIC_CAVES_BUDDY_CRAWLING_BG_0, x=165, y=111
	video offset=CINEMATIC_CAVES_BUDDY_CRAWLING_BG_0, x=220, y=110
	video offset=CINEMATIC_CAVES_BUDDY_CRAWLING_BG_0, x=257, y=111
	video offset=CINEMATIC_CAVES_BUDDY_CRAWLING_BG_0, x=301, y=111
	video offset=CINEMATIC_CAVES_BUDDY_CRAWLING_BG_0, x=33, y=112
	video offset=CINEMATIC_CAVES_BUDDY_CRAWLING_BG_0, x=70, y=110
	ret


LABEL_D5BE:
	db 0x11

CAVES_BUDDY_CRAWLING_SCENE_SETUP:
	fill page=0x00, color=0x00
	fill page=0x03, color=0x00
	load id=0x0043
	copyVideoPage src=0x00, dst=0x03
	mov [SCROLL_Y], 0x0002
	copyVideoPage src=0x83, dst=0x00
	selectVideoPage 0x00
	video offset=CINEMATIC_CAVES_BUDDY_CRAWLING_BG_3, x=163, y=99
	video offset=CINEMATIC_CAVES_WATERFALL_BG, x=162, y=99
	selectVideoPage 0x03
	video offset=CINEMATIC_CAVES_BUDDY_CRAWLING_BG_3, x=160, y=100
	video offset=CINEMATIC_CAVES_WATERFALL_BG, x=160, y=100
	selectVideoPage 0xFF
	ret


; composes BG_F0 + BG_F1
; into the cave's first
; room — fill page0,
; draw both BG frames,
; setPage3 backdrop
DRAW_WATERFALL_BG_FOUR_PASS:
	fill page=0x00, color=0x00
	fill page=0x03, color=0x00
	load id=0x0043
	copyVideoPage src=0x00, dst=0x03
	mov [SCROLL_Y], 0xFFDA
	copyVideoPage src=0x80, dst=0x03
	mov [SCROLL_Y], 0x0002
	copyVideoPage src=0x83, dst=0x00
	selectVideoPage 0x00
	video offset=CINEMATIC_CAVES_WATERFALL_BG, x=161, y=61
	video offset=CINEMATIC_CAVES_WATERFALL_BG, x=161, y=62
	selectVideoPage 0x03
	video offset=CINEMATIC_CAVES_WATERFALL_BG, x=161, y=60
	video offset=CINEMATIC_CAVES_WATERFALL_BG, x=160, y=62
	selectVideoPage 0xFF
	ret


; composes BG_F0 + BG_F1
; into the cave's first
; room — fill page0,
; draw both BG frames,
; setPage3 backdrop
DRAW_BUDDY_CRAWLING_BG:
	fill page=0x00, color=0x08
	video offset=CINEMATIC_BUDDY_CRAWLING_STUCK_AT_RING, x=160, y=100
	video offset=CINEMATIC_318, x=160, y=100
	video offset=CINEMATIC_319, x=160, y=100
	video offset=CINEMATIC_320, x=160, y=100
	ret


LABEL_D62E:
	fill page=0x00, color=0x08
	video offset=CINEMATIC_353, x=160, y=100
	video offset=CINEMATIC_354, x=160, y=100
	video offset=CINEMATIC_355, x=160, y=100
	video offset=CINEMATIC_356, x=31, y=74
	video offset=CINEMATIC_356, x=293, y=150
	video offset=CINEMATIC_357, x=97, y=110
	video offset=CINEMATIC_357, x=29, y=103
	video offset=CINEMATIC_357, x=37, y=15
	video offset=CINEMATIC_357, x=43, y=12
	video offset=CINEMATIC_357, x=86, y=72
	video offset=CINEMATIC_357, x=35, y=103
	video offset=CINEMATIC_357, x=218, y=152
	video offset=CINEMATIC_357, x=93, y=77
	video offset=CINEMATIC_358, x=161, y=96
	video offset=CINEMATIC_CAVES_BUDDY_CRAWLING_BG_0, x=59, y=96
	ret


LABEL_D66F:
	fill page=0x00, color=0x08
	video offset=CINEMATIC_361, x=160, y=100
	video offset=CINEMATIC_362, x=160, y=100
	video offset=CINEMATIC_CAVES_BUDDY_CRAWLING_BG_0, x=214, y=153
	video offset=CINEMATIC_CAVES_BUDDY_CRAWLING_BG_0, x=248, y=153
	video offset=CINEMATIC_CAVES_BUDDY_CRAWLING_BG_0, x=310, y=153
	video offset=CINEMATIC_356, x=24, y=62
	video offset=CINEMATIC_356, x=32, y=71
	video offset=CINEMATIC_356, x=24, y=69
	video offset=CINEMATIC_356, x=38, y=136
	video offset=CINEMATIC_356, x=0, y=64
	video offset=CINEMATIC_356, x=25, y=71
	video offset=CINEMATIC_356, x=4, y=158
	video offset=CINEMATIC_356, x=112, y=82
	video offset=CINEMATIC_356, x=297, y=109
	video offset=CINEMATIC_356, x=317, y=87
	video offset=CINEMATIC_356, x=203, y=157
	video offset=CINEMATIC_357, x=27, y=65
	video offset=CINEMATIC_357, x=34, y=80
	video offset=CINEMATIC_357, x=54, y=140
	video offset=CINEMATIC_357, x=43, y=167
	video offset=CINEMATIC_357, x=4, y=170
	video offset=CINEMATIC_357, x=203, y=163
	video offset=CINEMATIC_357, x=308, y=104
	video offset=CINEMATIC_357, x=309, y=152
	video offset=CINEMATIC_357, x=121, y=84
	video offset=CINEMATIC_357, x=93, y=107
	video offset=CINEMATIC_357, x=2, y=116
	video offset=CINEMATIC_357, x=123, y=173
	video offset=CINEMATIC_357, x=137, y=187
	video offset=CINEMATIC_357, x=124, y=192
	video offset=CINEMATIC_363, x=197, y=154
	video offset=CINEMATIC_358, x=302, y=141
	video offset=CINEMATIC_358, x=209, y=129
	video offset=CINEMATIC_358, x=6, y=57
	ret


CAVES_SCREEN_4E_BACKDROP_DRAW:
	fill page=0x00, color=0x08
	video offset=CINEMATIC_364, x=160, y=100
	video offset=CINEMATIC_CAVES_BUDDY_CRAWLING_BG_0, x=47, y=153
	video offset=CINEMATIC_CAVES_BUDDY_CRAWLING_BG_0, x=68, y=153
	video offset=CINEMATIC_CAVES_BUDDY_CRAWLING_BG_0, x=104, y=153
	video offset=CINEMATIC_CAVES_BUDDY_CRAWLING_BG_0, x=141, y=152
	video offset=CINEMATIC_CAVES_BUDDY_CRAWLING_BG_0, x=11, y=153
	video offset=CINEMATIC_CAVES_BUDDY_CRAWLING_BG_0, x=157, y=155
	video offset=CINEMATIC_CAVES_BUDDY_CRAWLING_BG_0, x=188, y=154
	video offset=CINEMATIC_CAVES_BUDDY_CRAWLING_BG_0, x=219, y=154
	video offset=CINEMATIC_CAVES_BUDDY_CRAWLING_BG_0, x=302, y=153
	video offset=CINEMATIC_CAVES_BUDDY_CRAWLING_BG_0, x=177, y=153
	video offset=CINEMATIC_CAVES_BUDDY_CRAWLING_BG_0, x=262, y=153
	ret


CAVES_SCREEN_4F_BACKDROP_DRAW:
	fill page=0x00, color=0x02
	video offset=CINEMATIC_365, x=160, y=100
	video offset=CINEMATIC_366, x=160, y=100
	video offset=CINEMATIC_367, x=95, y=150
	video offset=CINEMATIC_367, x=191, y=40, zoom=0x3b
	video offset=CINEMATIC_367, x=191, y=40, zoom=0x2f
	video offset=CINEMATIC_367, x=192, y=42, zoom=0x20
	video offset=CINEMATIC_367, x=232, y=41, zoom=0x29
	video offset=CINEMATIC_368, x=196, y=90
	video offset=CINEMATIC_368, x=197, y=96
	video offset=CINEMATIC_368, x=196, y=99
	video offset=CINEMATIC_368, x=196, y=102
	video offset=CINEMATIC_368, x=220, y=94
	video offset=CINEMATIC_368, x=220, y=97
	video offset=CINEMATIC_368, x=219, y=101
	video offset=CINEMATIC_368, x=196, y=94
	video offset=CINEMATIC_368, x=220, y=90
	ret


LABEL_D783:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_369, x=160, y=100
	video offset=CINEMATIC_370, x=160, y=100
	video offset=CINEMATIC_371, x=160, y=100
	video offset=CINEMATIC_CAVES_SCREEN_67_BACKDROP_LAYER_0, x=[0xec], y=130, zoom=0x20
	video offset=CINEMATIC_CAVES_SCREEN_67_BACKDROP_LAYER_0, x=[0xed], y=150, zoom=0x30
	video offset=CINEMATIC_CAVES_SCREEN_67_BACKDROP_LAYER_1, x=154, y=159
	video offset=CINEMATIC_CAVES_SCREEN_67_BACKDROP_LAYER_1, x=145, y=173
	video offset=CINEMATIC_CAVES_SCREEN_67_BACKDROP_LAYER_1, x=56, y=108
	video offset=CINEMATIC_356, x=300, y=130
	ret


CAVES_SCREEN_6F_BACKDROP_DRAW:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_454, x=160, y=100
	video offset=CINEMATIC_CAVES_HERO_IDLE_DOWN_2, x=160, y=100
	video offset=CINEMATIC_456, x=160, y=100
	jne [0xB0], 0x03, SHARED_RET
	video offset=CINEMATIC_CAVES_HERO_IDLE_DOWN_4, x=160, y=230, zoom=0x40
	ret


LABEL_D7CB:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_614, x=160, y=100
	video offset=CINEMATIC_615, x=160, y=100
	video offset=CINEMATIC_616, x=160, y=100
	video offset=CINEMATIC_618, x=160, y=100
	jl [0xB0], 0x02, LABEL_D7E8
	video offset=CINEMATIC_CAVES_SCREEN_93_BACKDROP_LAYER_1, x=160, y=100

LABEL_D7E8:
	mov [0xF8], [0xB0]
	and [0xF8], 0x0001
	je [0xF8], 0x00, SHARED_RET
	video offset=CINEMATIC_CAVES_HERO_IDLE_DOWN_4, x=65466, y=97
	jl [0xB0], 0x02, SHARED_RET
	video offset=CINEMATIC_CAVES_HERO_IDLE_DOWN_4, x=160, y=97
	video offset=CINEMATIC_CAVES_HERO_IDLE_DOWN_4, x=100, y=97
	setPalette 0x10
	ret


CAVES_SCREEN_8F_BACKDROP_DRAW:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_614, x=160, y=100
	video offset=CINEMATIC_615, x=160, y=100
	video offset=CINEMATIC_616, x=160, y=100
	video offset=CINEMATIC_CAVES_SCREEN_92_BACKDROP_LAYER_1, x=65527, y=98
	jne [0xB0], 0x03, SHARED_RET
	video offset=CINEMATIC_CAVES_HERO_IDLE_DOWN_4, x=160, y=50
	video offset=CINEMATIC_CAVES_HERO_IDLE_DOWN_4, x=160, y=130
	setPalette 0x10
	ret


CAVES_SCREEN_70_BACKDROP_DRAW:
	fill page=0x00, color=0x03
	video offset=CINEMATIC_CAVES_SCREEN_95_BACKDROP_LAYER_5, x=160, y=100
	video offset=CINEMATIC_356, x=180, y=70
	video offset=CINEMATIC_CAVES_SCREEN_67_BACKDROP_LAYER_0, x=178, y=73
	ret


LABEL_D844:
	fill page=0x00, color=0x03
	video offset=CINEMATIC_561, x=160, y=100
	ret


LABEL_D84C:
	fill page=0x00, color=0x02
	video offset=CINEMATIC_627, x=161, y=106
	video offset=CINEMATIC_369, x=150, y=65522
	video offset=CINEMATIC_628, x=32, y=102
	video offset=CINEMATIC_628, x=287, y=102
	video offset=CINEMATIC_628, x=125, y=101
	video offset=CINEMATIC_628, x=193, y=101
	video offset=CINEMATIC_367, x=161, y=143
	video offset=CINEMATIC_629, x=394, y=100
	video offset=CINEMATIC_630, x=99, y=100
	video offset=CINEMATIC_630, x=271, y=100
	video offset=CINEMATIC_631, x=10, y=100
	video offset=CINEMATIC_355, x=481, y=65456
	mov [0xF8], [0xB1]
	and [0xF8], 0x0004
	jne [0xF8], 0x00, SHARED_RET
	video offset=CINEMATIC_632, x=3, y=123
	ret


	video offset=CINEMATIC_632, x=332, y=123
	killChannel

LABEL_D89E:
	fill page=0x00, color=0x02
	video offset=CINEMATIC_627, x=160, y=100
	video offset=CINEMATIC_CAVES_SCREEN_C8_BACKDROP_LAYER_0, x=160, y=100
	video offset=CINEMATIC_CAVES_SCREEN_C8_BACKDROP_LAYER_1, x=160, y=100
	ret


CAVES_SCREEN_93_BACKDROP_DRAW:
	fill page=0x00, color=0x02
	video offset=CINEMATIC_627, x=160, y=100
	video offset=CINEMATIC_CAVES_SCREEN_C8_BACKDROP_LAYER_2, x=160, y=100
	video offset=CINEMATIC_CAVES_SCREEN_C8_BACKDROP_LAYER_1, x=160, y=100
	ret


LABEL_D8BE:
	fill page=0x00, color=0x02
	video offset=CINEMATIC_627, x=160, y=100
	video offset=CINEMATIC_CAVES_SCREEN_C8_BACKDROP_LAYER_1, x=160, y=100
	ret


CAVES_SCREEN_95_BACKDROP_DRAW:
	fill page=0x00, color=0x02
	video offset=CINEMATIC_627, x=160, y=100
	video offset=CINEMATIC_627, x=390, y=100
	video offset=CINEMATIC_CAVES_SCREEN_C8_BACKDROP_LAYER_3, x=364, y=107
	video offset=CINEMATIC_642, x=160, y=100
	video offset=CINEMATIC_577, x=160, y=100
	video offset=CINEMATIC_579, x=160, y=100
	ret


LABEL_D8E8:
	db 0x11

CAVES_SCREEN_75_BACKDROP_DRAW:
	fill page=0x00, color=0x08
	video offset=CINEMATIC_563, x=160, y=100
	video offset=CINEMATIC_564, x=160, y=100
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
