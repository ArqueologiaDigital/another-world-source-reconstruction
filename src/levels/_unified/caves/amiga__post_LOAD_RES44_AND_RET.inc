LABEL_CDA8:
	load id=0x0046
	copyVideoPage src=0x00, dst=0x03
	load id=0x0045
	ret


LABEL_CDB2:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_CAVES_SCREEN_67_BACKDROP_LAYER_0, x=160, y=100
	video offset=CINEMATIC_CAVES_SCREEN_67_BACKDROP_LAYER_1, x=160, y=100
	selectVideoPage 0x03
	fill page=0x03, color=0x09
	mov [SCROLL_Y], 0x0096
	copyVideoPage src=0x80, dst=0x03
	selectVideoPage 0x00
	ret


CAVES_SCREEN_68_BACKDROP_DRAW:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_CAVES_SCREEN_68_BACKDROP_LAYER_0, x=160, y=100
	video offset=CINEMATIC_CAVES_SCREEN_68_BACKDROP_LAYER_1, x=160, y=100
	copyVideoPage src=0x00, dst=0x03
	video offset=CINEMATIC_CAVES_SCREEN_68_BACKDROP_LAYER_2, x=160, y=100
	ret


CAVES_SCREEN_69_BACKDROP_DRAW:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_CAVES_SCREEN_69_BACKDROP_LAYER_0, x=160, y=100
	video offset=CINEMATIC_CAVES_SCREEN_69_BACKDROP_LAYER_1, x=160, y=100
	ret


DRAW_CIN_415_416_FRAGMENTS:
	fill page=0x00, color=0x08
	video offset=CINEMATIC_CAVES_FIRST_ROOM_BG_F1, x=160, y=100
	video offset=CINEMATIC_395, x=202, y=65
	video offset=CINEMATIC_395, x=293, y=4
	video offset=CINEMATIC_395, x=298, y=117
	video offset=CINEMATIC_395, x=125, y=59, zoom=0x2e
	video offset=CINEMATIC_395, x=212, y=101, zoom=0x2e
	video offset=CINEMATIC_395, x=121, y=91, zoom=0x20
	video offset=CINEMATIC_395, x=201, y=132, zoom=0x20
	video offset=CINEMATIC_395, x=86, y=82
	video offset=CINEMATIC_395, x=257, y=78
	video offset=CINEMATIC_395, x=249, y=151
	video offset=CINEMATIC_395, x=159, y=16
	video offset=CINEMATIC_395, x=250, y=155, zoom=0x20
	video offset=CINEMATIC_395, x=89, y=86, zoom=0x20
	copyVideoPage src=0x00, dst=0x03
	video offset=CINEMATIC_CAVES_SCREEN_6B_BACKDROP_LAYER_14, x=169, y=94
	ret


CAVES_SCREEN_6C_BACKDROP_DRAW:
	fill page=0x00, color=0x08
	video offset=CINEMATIC_335, x=134, y=103
	video offset=CINEMATIC_395, x=6, y=90
	video offset=CINEMATIC_395, x=315, y=147, zoom=0x26
	video offset=CINEMATIC_406, x=14, y=166
	video offset=CINEMATIC_395, x=44, y=133, zoom=0x20
	video offset=CINEMATIC_336, x=19, y=73
	video offset=CINEMATIC_336, x=16, y=76
	video offset=CINEMATIC_336, x=136, y=165
	video offset=CINEMATIC_336, x=82, y=139
	video offset=CINEMATIC_336, x=38, y=167
	video offset=CINEMATIC_336, x=245, y=150
	video offset=CINEMATIC_336, x=252, y=83
	video offset=CINEMATIC_336, x=310, y=138
	video offset=CINEMATIC_336, x=303, y=169
	video offset=CINEMATIC_336, x=191, y=169
	video offset=CINEMATIC_336, x=150, y=156
	video offset=CINEMATIC_407, x=96, y=124
	video offset=CINEMATIC_407, x=107, y=108
	video offset=CINEMATIC_407, x=150, y=169
	video offset=CINEMATIC_407, x=130, y=142
	video offset=CINEMATIC_CAVES_SCREEN_6C_CAVERN_COLUMNS, x=160, y=100
	video offset=CINEMATIC_CAVES_SCREEN_6C_CAVERN_COLUMN_LARGE, x=160, y=100
	video offset=CINEMATIC_CAVES_SCREEN_6C_STALAGMITE, x=83, y=165
	video offset=CINEMATIC_CAVES_SCREEN_6C_STALAGMITE, x=136, y=165
	video offset=CINEMATIC_CAVES_SCREEN_6C_STALAGMITE, x=233, y=165
	video offset=CINEMATIC_CAVES_SCREEN_6C_STALAGMITE, x=293, y=165
	video offset=CINEMATIC_275, x=91, y=153
	video offset=CINEMATIC_275, x=28, y=153
	video offset=CINEMATIC_275, x=59, y=153
	video offset=CINEMATIC_275, x=124, y=153
	video offset=CINEMATIC_275, x=320, y=153
	video offset=CINEMATIC_275, x=269, y=153
	video offset=CINEMATIC_275, x=132, y=153
	video offset=CINEMATIC_275, x=203, y=153
	video offset=CINEMATIC_275, x=170, y=153
	video offset=CINEMATIC_411, x=230, y=172
	ret


CAVES_SCREEN_6D_BACKDROP_DRAW:
	fill page=0x00, color=0x08
	video offset=CINEMATIC_CAVES_SCREEN_6D_BACKDROP_0, x=160, y=100
	video offset=CINEMATIC_CAVES_SCREEN_6D_BACKDROP_1, x=160, y=100
	video offset=CINEMATIC_CAVES_SCREEN_6D_BACKDROP_2, x=160, y=100
	ret


CAVES_SCREEN_6E_BACKDROP_DRAW:
	fill page=0x00, color=0x08
	video offset=CINEMATIC_432, x=160, y=100
	ret


CAVES_SCREEN_87_BACKDROP_DRAW:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_CAVES_SCREEN_87_BACKDROP_LAYER_0, x=160, y=100
	video offset=CINEMATIC_CAVES_SCREEN_87_BACKDROP_LAYER_1, x=160, y=100
	jne [0xAF], 0x58, SHARED_RET
	video offset=CINEMATIC_CAVES_SCREEN_87_BACKDROP_LAYER_2, x=160, y=100
	video offset=CINEMATIC_436, x=199, y=200, zoom=0x40
	video offset=CINEMATIC_436, x=250, y=189
	ret


CAVES_SCREEN_88_BACKDROP_DRAW:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_CAVES_SCREEN_88_BACKDROP_0, x=160, y=100
	video offset=CINEMATIC_CAVES_SCREEN_88_BACKDROP_1, x=160, y=100
	video offset=CINEMATIC_CAVES_SCREEN_88_BACKDROP_2, x=160, y=100
	ret


CAVES_SCREEN_89_BACKDROP_DRAW:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_CAVES_SCREEN_89_BACKDROP_LAYER_0, x=160, y=100
	video offset=CINEMATIC_CAVES_SCREEN_89_BACKDROP_LAYER_1, x=160, y=100
	ret


CAVES_SCREEN_8A_BACKDROP_DRAW:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_589, x=161, y=100
	video offset=CINEMATIC_590, x=161, y=99
	selectVideoPage 0x03
	fill page=0x03, color=0x00
	video offset=CINEMATIC_589, x=160, y=100
	video offset=CINEMATIC_590, x=160, y=100
	ret


LABEL_CF46:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_622, x=160, y=100
	video offset=CINEMATIC_623, x=160, y=100
	video offset=CINEMATIC_624, x=256, y=167, zoom=0x20
	video offset=CINEMATIC_625, x=244, y=170, zoom=0x20
	copyVideoPage src=0x00, dst=0x03
	mov [0xF8], [0xB1]
	and [0xF8], 0x0008
	jne [0xF8], 0x00, DRAW_CIN_626
	video offset=CINEMATIC_627, x=160, y=100
	ret


DRAW_CIN_626:
	video offset=CINEMATIC_626, x=160, y=100
	ret


CAVES_SCREEN_A8_BACKDROP_DRAW:
	fill page=0x00, color=0x09
	video offset=CINEMATIC_CAVES_SCREEN_A8_BACKDROP_LAYER_0, x=155, y=100
	video offset=CINEMATIC_634, x=155, y=100
	ret


CAVES_SCREEN_A9_BACKDROP_DRAW:
	fill page=0x00, color=0x09
	video offset=CINEMATIC_634, x=25, y=100
	ret


CAVES_SCREEN_C8_BACKDROP_DRAW:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_CAVES_SCREEN_C8_BACKDROP_LAYER_0, x=160, y=100
	video offset=CINEMATIC_CAVES_SCREEN_C8_BACKDROP_LAYER_1, x=160, y=100
	video offset=CINEMATIC_CAVES_SCREEN_C8_BACKDROP_LAYER_2, x=160, y=100
	video offset=CINEMATIC_CAVES_SCREEN_C8_BACKDROP_LAYER_3, x=160, y=100
	ret


CAVES_SCREEN_C9_BACKDROP_DRAW:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_CAVES_SCREEN_C9_BACKDROP_LAYER_0, x=160, y=100
	video offset=CINEMATIC_CAVES_SCREEN_C9_BACKDROP_LAYER_1, x=160, y=100
	video offset=CINEMATIC_CAVES_SCREEN_C9_BACKDROP_LAYER_2, x=160, y=100
	video offset=CINEMATIC_624, x=130, y=57
	video offset=CINEMATIC_625, x=39, y=51, zoom=0x20
	video offset=CINEMATIC_708, x=27, y=47, zoom=0x20
	ret


CAVES_SCREEN_CA_BACKDROP_DRAW:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_CAVES_SCREEN_CA_BACKDROP_0, x=160, y=100
	video offset=CINEMATIC_CAVES_SCREEN_CA_BACKDROP_1, x=160, y=100
	video offset=CINEMATIC_CAVES_SCREEN_CA_BACKDROP_2, x=160, y=100
	ret


CAVES_SCREEN_CB_BACKDROP_DRAW:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_CAVES_STALACTITE_CAVERN_FLOOR_RIGHT, x=160, y=100
	video offset=CINEMATIC_CAVES_STALACTITE_CAVERN_FLOOR_LEFT, x=160, y=100
	video offset=CINEMATIC_CAVES_SCREEN_CB_BACKDROP_LAYER_2, x=160, y=100
	video offset=CINEMATIC_CAVES_SCREEN_CB_BACKDROP_LAYER_3, x=160, y=100
	ret


CAVES_SCREEN_CC_BACKDROP_DRAW:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_CAVES_STALACTITE_CAVERN_FLOOR_LEFT, x=160, y=100
	video offset=CINEMATIC_CAVES_STALACTITE_CAVERN_FLOOR_RIGHT, x=160, y=100
	video offset=CINEMATIC_CAVES_STALACTITE_CAVERN_CEILING_LEFT, x=160, y=100
	video offset=CINEMATIC_CAVES_STALACTITE_CAVERN_CEILING_RIGHT, x=160, y=100
	jne [0xB0], 0x03, SHARED_RET
	setPalette 0x10
	video offset=CINEMATIC_625, x=49, y=115
	video offset=CINEMATIC_624, x=8, y=96
	video offset=CINEMATIC_708, x=28, y=110
	video offset=CINEMATIC_624, x=68, y=115
	video offset=CINEMATIC_625, x=9, y=80
	video offset=CINEMATIC_625, x=6, y=99
	video offset=CINEMATIC_624, x=15, y=120, zoom=0x2a
	video offset=CINEMATIC_708, x=65526, y=66
	ret


CAVES_SCREEN_CE_BACKDROP_DRAW:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_CAVES_STALACTITE_CAVERN_FLOOR_LEFT, x=160, y=100
	video offset=CINEMATIC_CAVES_STALACTITE_CAVERN_FLOOR_RIGHT, x=160, y=100
	video offset=CINEMATIC_CAVES_STALACTITE_CAVERN_CEILING_LEFT, x=160, y=100
	video offset=CINEMATIC_CAVES_STALACTITE_CAVERN_CEILING_RIGHT, x=160, y=100
	ret


LABEL_D038:
	jne [0xB0], 0x03, SHARED_RET
	video offset=CINEMATIC_436, x=70, y=97
	video offset=CINEMATIC_436, x=260, y=97
	ret


CAVES_SCREEN_AD_BACKDROP_DRAW:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_CAVES_SCREEN_AD_BACKDROP_LAYER_0, x=160, y=100
	video offset=CINEMATIC_596, x=327, y=146
	video offset=CINEMATIC_636, x=239, y=137
	video offset=CINEMATIC_636, x=243, y=180
	jne [0xB0], 0x03, SHARED_RET
	video offset=CINEMATIC_436, x=131, y=217, zoom=0x40
	ret


DRAW_STALACTITE_CAVERN_BG:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_CAVES_STALACTITE_CAVERN_FLOOR_LEFT, x=160, y=100
	video offset=CINEMATIC_CAVES_STALACTITE_CAVERN_FLOOR_RIGHT, x=160, y=100
	video offset=CINEMATIC_CAVES_STALACTITE_CAVERN_CEILING_LEFT, x=160, y=100
	video offset=CINEMATIC_CAVES_STALACTITE_CAVERN_CEILING_RIGHT, x=160, y=100
	video offset=CINEMATIC_CAVES_SCREEN_CD_BACKDROP_LAYER_4, x=160, y=100
	ret


CAVES_SCREEN_ED_BACKDROP_DRAW:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_CAVES_SCREEN_ED_BACKDROP_LAYER_0, x=160, y=100
	video offset=CINEMATIC_CAVES_SCREEN_ED_BACKDROP_LAYER_1, x=160, y=100
	video offset=CINEMATIC_CAVES_SCREEN_ED_BACKDROP_LAYER_2, x=160, y=100
	video offset=CINEMATIC_CAVES_SCREEN_ED_BACKDROP_LAYER_3, x=160, y=100
	video offset=CINEMATIC_CAVES_SCREEN_ED_BACKDROP_LAYER_4, x=160, y=100
	video offset=CINEMATIC_CAVES_SCREEN_ED_BACKDROP_LAYER_5, x=309, y=42
	video offset=CINEMATIC_CAVES_SCREEN_ED_BACKDROP_LAYER_6, x=308, y=57
	video offset=CINEMATIC_CAVES_SCREEN_ED_BACKDROP_LAYER_7, x=303, y=72
	video offset=CINEMATIC_CAVES_SCREEN_ED_BACKDROP_LAYER_8, x=296, y=23
	jne [0xB0], 0x03, SHARED_RET
	video offset=CINEMATIC_436, x=65508, y=90
	video offset=CINEMATIC_436, x=156, y=184
	ret


DRAW_WATERFALL_LEFT_STAIRS_BG:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_CAVES_SCREEN_49_BACKDROP_LAYER_0, x=160, y=100
	video offset=CINEMATIC_275, x=165, y=111
	video offset=CINEMATIC_275, x=220, y=110
	video offset=CINEMATIC_275, x=257, y=111
	video offset=CINEMATIC_275, x=301, y=111
	video offset=CINEMATIC_275, x=33, y=112
	video offset=CINEMATIC_275, x=70, y=110
	ret


LABEL_D0DE:
	db 0x11

CAVES_BUDDY_CRAWLING_SCENE_SETUP:
	fill page=0x00, color=0x00
	fill page=0x03, color=0x00
	load id=0x0043
	copyVideoPage src=0x00, dst=0x03
	mov [SCROLL_Y], 0x0002
	copyVideoPage src=0x83, dst=0x00
	selectVideoPage 0x00
	video offset=CINEMATIC_278, x=163, y=99
	video offset=CINEMATIC_CAVES_WATERFALL, x=162, y=99
	selectVideoPage 0x03
	video offset=CINEMATIC_278, x=160, y=100
	video offset=CINEMATIC_CAVES_WATERFALL, x=160, y=100
	selectVideoPage 0xFF
	ret


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
	video offset=CINEMATIC_CAVES_WATERFALL, x=161, y=61
	video offset=CINEMATIC_CAVES_WATERFALL, x=161, y=62
	selectVideoPage 0x03
	video offset=CINEMATIC_CAVES_WATERFALL, x=161, y=60
	video offset=CINEMATIC_CAVES_WATERFALL, x=160, y=62
	selectVideoPage 0xFF
	ret


DRAW_BUDDY_CRAWLING_BG:
	fill page=0x00, color=0x08
	video offset=CINEMATIC_CAVES_BUDDY_CRAWLING_BG_0, x=160, y=100
	video offset=CINEMATIC_CAVES_BUDDY_CRAWLING_BG_1, x=160, y=100
	video offset=CINEMATIC_CAVES_BUDDY_CRAWLING_BG_2, x=160, y=100
	video offset=CINEMATIC_CAVES_BUDDY_CRAWLING_BG_3, x=160, y=100
	ret


CAVES_SCREEN_4C_BACKDROP_DRAW:
	fill page=0x00, color=0x08
	video offset=CINEMATIC_CAVES_SCREEN_4C_CAVERN_COLUMNS, x=160, y=100
	video offset=CINEMATIC_CAVES_SCREEN_4C_CAVERN_ARCH, x=160, y=100
	video offset=CINEMATIC_334, x=160, y=100
	video offset=CINEMATIC_335, x=31, y=74
	video offset=CINEMATIC_335, x=293, y=150
	video offset=CINEMATIC_336, x=97, y=110
	video offset=CINEMATIC_336, x=29, y=103
	video offset=CINEMATIC_336, x=37, y=15
	video offset=CINEMATIC_336, x=43, y=12
	video offset=CINEMATIC_336, x=86, y=72
	video offset=CINEMATIC_336, x=35, y=103
	video offset=CINEMATIC_336, x=218, y=152
	video offset=CINEMATIC_336, x=93, y=77
	video offset=CINEMATIC_337, x=161, y=96
	video offset=CINEMATIC_275, x=59, y=96
	ret


CAVES_SCREEN_4D_BACKDROP_DRAW:
	fill page=0x00, color=0x08
	video offset=CINEMATIC_CAVES_SCREEN_4D_ARCHES, x=160, y=100
	video offset=CINEMATIC_CAVES_SCREEN_4D_CAVERN_COLUMNS, x=160, y=100
	video offset=CINEMATIC_275, x=214, y=153
	video offset=CINEMATIC_275, x=248, y=153
	video offset=CINEMATIC_275, x=310, y=153
	video offset=CINEMATIC_335, x=24, y=62
	video offset=CINEMATIC_335, x=32, y=71
	video offset=CINEMATIC_335, x=24, y=69
	video offset=CINEMATIC_335, x=38, y=136
	video offset=CINEMATIC_335, x=0, y=64
	video offset=CINEMATIC_335, x=25, y=71
	video offset=CINEMATIC_335, x=4, y=158
	video offset=CINEMATIC_335, x=112, y=82
	video offset=CINEMATIC_335, x=297, y=109
	video offset=CINEMATIC_335, x=317, y=87
	video offset=CINEMATIC_335, x=203, y=157
	video offset=CINEMATIC_336, x=27, y=65
	video offset=CINEMATIC_336, x=34, y=80
	video offset=CINEMATIC_336, x=54, y=140
	video offset=CINEMATIC_336, x=43, y=167
	video offset=CINEMATIC_336, x=4, y=170
	video offset=CINEMATIC_336, x=203, y=163
	video offset=CINEMATIC_336, x=308, y=104
	video offset=CINEMATIC_336, x=309, y=152
	video offset=CINEMATIC_336, x=121, y=84
	video offset=CINEMATIC_336, x=93, y=107
	video offset=CINEMATIC_336, x=2, y=116
	video offset=CINEMATIC_336, x=123, y=173
	video offset=CINEMATIC_336, x=137, y=187
	video offset=CINEMATIC_336, x=124, y=192
	video offset=CINEMATIC_342, x=197, y=154
	video offset=CINEMATIC_337, x=302, y=141
	video offset=CINEMATIC_337, x=209, y=129
	video offset=CINEMATIC_337, x=6, y=57
	ret


CAVES_SCREEN_4E_BACKDROP_DRAW:
	fill page=0x00, color=0x08
	video offset=CINEMATIC_CAVES_SCREEN_4E_BACKDROP_LAYER_0, x=160, y=100
	video offset=CINEMATIC_275, x=47, y=153
	video offset=CINEMATIC_275, x=68, y=153
	video offset=CINEMATIC_275, x=104, y=153
	video offset=CINEMATIC_275, x=141, y=152
	video offset=CINEMATIC_275, x=11, y=153
	video offset=CINEMATIC_275, x=157, y=155
	video offset=CINEMATIC_275, x=188, y=154
	video offset=CINEMATIC_275, x=219, y=154
	video offset=CINEMATIC_275, x=302, y=153
	video offset=CINEMATIC_275, x=177, y=153
	video offset=CINEMATIC_275, x=262, y=153
	ret


CAVES_SCREEN_4F_BACKDROP_DRAW:
	fill page=0x00, color=0x02
	video offset=CINEMATIC_CAVES_SCREEN_4F_BACKDROP_LAYER_0, x=160, y=100
	video offset=CINEMATIC_CAVES_SCREEN_4F_BACKDROP_LAYER_1, x=160, y=100
	video offset=CINEMATIC_346, x=95, y=150
	video offset=CINEMATIC_346, x=191, y=40, zoom=0x3b
	video offset=CINEMATIC_346, x=191, y=40, zoom=0x2f
	video offset=CINEMATIC_346, x=192, y=42, zoom=0x20
	video offset=CINEMATIC_346, x=232, y=41, zoom=0x29
	video offset=CINEMATIC_347, x=196, y=90
	video offset=CINEMATIC_347, x=197, y=96
	video offset=CINEMATIC_347, x=196, y=99
	video offset=CINEMATIC_347, x=196, y=102
	video offset=CINEMATIC_347, x=220, y=94
	video offset=CINEMATIC_347, x=220, y=97
	video offset=CINEMATIC_347, x=219, y=101
	video offset=CINEMATIC_347, x=196, y=94
	video offset=CINEMATIC_347, x=220, y=90
	ret


LABEL_D2A3:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_348, x=160, y=100
	video offset=CINEMATIC_CAVES_SCREEN_50_BACKDROP_LAYER_1, x=160, y=100
	video offset=CINEMATIC_CAVES_SCREEN_50_BACKDROP_LAYER_2, x=160, y=100
	video offset=CINEMATIC_351, x=[0xec], y=130, zoom=0x20
	video offset=CINEMATIC_351, x=[0xed], y=150, zoom=0x30
	video offset=CINEMATIC_352, x=154, y=159
	video offset=CINEMATIC_352, x=145, y=173
	video offset=CINEMATIC_352, x=56, y=108
	video offset=CINEMATIC_335, x=300, y=130
	ret


CAVES_SCREEN_6F_BACKDROP_DRAW:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_CAVES_SCREEN_6F_BACKDROP_LAYER_0, x=160, y=100
	video offset=CINEMATIC_CAVES_SCREEN_6F_BACKDROP_LAYER_1, x=160, y=100
	video offset=CINEMATIC_CAVES_SCREEN_6F_BACKDROP_LAYER_2, x=160, y=100
	jne [0xB0], 0x03, SHARED_RET
	video offset=CINEMATIC_436, x=160, y=230, zoom=0x40
	ret


LABEL_D2EB:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_CAVES_SCREEN_8F_BACKDROP_LAYER_0, x=160, y=100
	video offset=CINEMATIC_CAVES_SCREEN_8F_BACKDROP_LAYER_1, x=160, y=100
	video offset=CINEMATIC_CAVES_SCREEN_8F_BACKDROP_LAYER_2, x=160, y=100
	video offset=CINEMATIC_597, x=160, y=100
	jl [0xB0], 0x02, LABEL_D308
	video offset=CINEMATIC_598, x=160, y=100

LABEL_D308:
	mov [0xF8], [0xB0]
	and [0xF8], 0x0001
	je [0xF8], 0x00, SHARED_RET
	video offset=CINEMATIC_436, x=65466, y=97
	jl [0xB0], 0x02, SHARED_RET
	video offset=CINEMATIC_436, x=160, y=97
	video offset=CINEMATIC_436, x=100, y=97
	setPalette 0x10
	ret


CAVES_SCREEN_8F_BACKDROP_DRAW:
	fill page=0x00, color=0x00
	video offset=CINEMATIC_CAVES_SCREEN_8F_BACKDROP_LAYER_0, x=160, y=100
	video offset=CINEMATIC_CAVES_SCREEN_8F_BACKDROP_LAYER_1, x=160, y=100
	video offset=CINEMATIC_CAVES_SCREEN_8F_BACKDROP_LAYER_2, x=160, y=100
	video offset=CINEMATIC_596, x=65527, y=98
	jne [0xB0], 0x03, SHARED_RET
	video offset=CINEMATIC_436, x=160, y=50
	video offset=CINEMATIC_436, x=160, y=130
	setPalette 0x10
	ret


CAVES_SCREEN_70_BACKDROP_DRAW:
	fill page=0x00, color=0x03
	video offset=CINEMATIC_CAVES_SCREEN_70_BACKDROP_LAYER_0, x=160, y=100
	video offset=CINEMATIC_335, x=180, y=70
	video offset=CINEMATIC_351, x=178, y=73
	ret


CAVES_SCREEN_71_BACKDROP_DRAW:
	fill page=0x00, color=0x03
	video offset=CINEMATIC_540, x=160, y=100
	ret


CAVES_SCREEN_91_BACKDROP_DRAW:
	fill page=0x00, color=0x02
	video offset=CINEMATIC_606, x=161, y=106
	video offset=CINEMATIC_348, x=150, y=65522
	video offset=CINEMATIC_607, x=32, y=102
	video offset=CINEMATIC_607, x=287, y=102
	video offset=CINEMATIC_607, x=125, y=101
	video offset=CINEMATIC_607, x=193, y=101
	video offset=CINEMATIC_346, x=161, y=143
	video offset=CINEMATIC_608, x=394, y=100
	video offset=CINEMATIC_609, x=99, y=100
	video offset=CINEMATIC_609, x=271, y=100
	video offset=CINEMATIC_610, x=10, y=100
	video offset=CINEMATIC_334, x=481, y=65456
	mov [0xF8], [0xB1]
	and [0xF8], 0x0004
	jne [0xF8], 0x00, SHARED_RET
	video offset=CINEMATIC_611, x=3, y=123
	ret


LABEL_D3B8:
	db 0x78, 0x7A, 0x94, 0x4C, 0x7B, 0x11

CAVES_SCREEN_92_BACKDROP_DRAW:
	fill page=0x00, color=0x02
	video offset=CINEMATIC_606, x=160, y=100
	video offset=CINEMATIC_CAVES_SCREEN_92_BACKDROP_LAYER_1, x=160, y=100
	video offset=CINEMATIC_618, x=160, y=100
	ret


CAVES_SCREEN_93_BACKDROP_DRAW:
	fill page=0x00, color=0x02
	video offset=CINEMATIC_606, x=160, y=100
	video offset=CINEMATIC_CAVES_SCREEN_93_BACKDROP_LAYER_1, x=160, y=100
	video offset=CINEMATIC_618, x=160, y=100
	ret


CAVES_SCREEN_94_BACKDROP_DRAW:
	fill page=0x00, color=0x02
	video offset=CINEMATIC_606, x=160, y=100
	video offset=CINEMATIC_618, x=160, y=100
	ret


CAVES_SCREEN_95_BACKDROP_DRAW:
	fill page=0x00, color=0x02
	video offset=CINEMATIC_606, x=160, y=100
	video offset=CINEMATIC_606, x=390, y=100
	video offset=CINEMATIC_CAVES_SCREEN_95_BACKDROP_LAYER_2, x=364, y=107
	video offset=CINEMATIC_CAVES_SCREEN_95_BACKDROP_LAYER_3, x=160, y=100
	video offset=CINEMATIC_CAVES_SCREEN_95_BACKDROP_LAYER_4, x=160, y=100
	video offset=CINEMATIC_CAVES_SCREEN_95_BACKDROP_LAYER_5, x=160, y=100
	ret


LABEL_D408:
	db 0x11

FILL_PAGE_00_COLOR_08:
	fill page=0x00, color=0x08
	video offset=CINEMATIC_CAVES_SCREEN_75_BACKDROP_LAYER_0, x=160, y=100
	video offset=CINEMATIC_CAVES_SCREEN_75_BACKDROP_LAYER_1, x=160, y=100
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
