LABEL_C533:
	db 0x11

LABEL_C534:
	jne [HACK_VAR_67], 0x8A, LABEL_C565
	deleteChannels first=0x01, last=0x02
	setup channel=0x08, address=INLINE_SET_VAR6B_TO_1
	setup channel=0x3C, address=LABEL_400A
	selectVideoPage 0x03
	video offset=CINEMATIC_804, x=160, y=100
	selectVideoPage 0xFF
	or [0xB0], 0x0001
	play id=0x006A, freq=0x0F, vol=0x40, channel=0x03
	play id=0x005A, freq=0x0A, vol=0x40, channel=0x00
	play id=0x0074, freq=0x0A, vol=0x40, channel=0x02
	ret

LABEL_C565:
	jne [HACK_VAR_67], 0xA7, LABEL_C589
	copyVideoPage src=0x03, dst=0x00
	selectVideoPage 0x00
	video offset=CINEMATIC_648, x=160, y=100
	selectVideoPage 0xFF
	or [0xB1], 0x0008
	mov [SCROLL_Y], 0xFFFE
	play id=0x005A, freq=0x0A, vol=0x40, channel=0x00
	setup channel=0x3C, address=LABEL_3F8B
	ret

LABEL_C589:
	jne [HACK_VAR_67], 0xAF, LABEL_C5A2
	selectVideoPage 0x00
	video offset=CINEMATIC_619, x=160, y=100
	selectVideoPage 0xFF
	or [0xB0], 0x0002
	play id=0x005A, freq=0x0A, vol=0x40, channel=0x00
	ret

LABEL_C5A2:
	jne [HACK_VAR_67], 0x68, LABEL_C5BB
	or [0xB1], 0x0010
	selectVideoPage 0x00
	video offset=CINEMATIC_407, x=160, y=100
	selectVideoPage 0xFF
	play id=0x005A, freq=0x0A, vol=0x40, channel=0x00
	ret

LABEL_C5BB:
	jne [HACK_VAR_67], 0x28, LABEL_C5D4
	selectVideoPage 0x00
	video offset=CINEMATIC_287, x=160, y=100
	selectVideoPage 0xFF
	play id=0x005A, freq=0x0A, vol=0x40, channel=0x00
	or [0xB1], 0x8000
	ret

LABEL_C5D4:
	jne [HACK_VAR_67], 0xCA, LABEL_C5F9
	deleteChannels first=0x22, last=0x23
	or [0xBD], 0x0020
	mov [0x13], 0x0070
	add [0x21], 0x0010
	add [0x27], 0x0028
	mov [0x49], 0x7FFF
	video offset=CINEMATIC_134, x=[0x68], y=73, zoom=[0x5a]	;@enc=alt
	ret

LABEL_C5F9:
	jne [HACK_VAR_67], 0xCB, LABEL_C620
	jne [0x1D], 0x0C, SHARED_RET
	deleteChannels first=0x2C, last=0x2D
	mov [0x13], 0x0070
	add [0x21], 0x0010
	add [0x27], 0x0014
	mov [0x4D], 0x7FFF
	video offset=CINEMATIC_134, x=[0x72], y=93, zoom=[0x5a]	;@enc=alt
	ret

LABEL_C620:
	jne [HACK_VAR_67], 0xCC, SHARED_RET
	jne [0x1D], 0x0B, LABEL_C64B
	deleteChannels first=0x2A, last=0x2B
	or [0xBD], 0x0002
	mov [0x13], 0x0070
	add [0x21], 0x0010
	add [0x27], 0x0028
	mov [0x4B], 0x7FFF
	video offset=CINEMATIC_134, x=[0x70], y=93, zoom=[0x5a]	;@enc=alt
	ret

LABEL_C64B:
	jne [0x1D], 0x0A, LABEL_C670
	deleteChannels first=0x28, last=0x29
	or [0xBD], 0x0004
	mov [0x13], 0x0070
	add [0x21], 0x0010
	add [0x27], 0x0028
	mov [0x49], 0x7FFF
	video offset=CINEMATIC_134, x=[0x6e], y=93, zoom=[0x5a]	;@enc=alt
	ret

LABEL_C670:
	jne [0x1D], 0x0C, SHARED_RET
	deleteChannels first=0x2C, last=0x2D
	or [0xBD], 0x0001
	mov [0x13], 0x0070
	add [0x21], 0x0010
	add [0x27], 0x0028
	mov [0x4D], 0x7FFF
	video offset=CINEMATIC_134, x=[0x72], y=93, zoom=[0x5a]	;@enc=alt
	ret
LABEL_C695:
	db 0x11

LABEL_C696:
	jne [HACK_VAR_67], 0x4E, LABEL_C6BD
	mov [0xF8], [0x49]
	and [0xF8], 0x0380
	shl [0xF8], 0x0002
	and [0xB1], 0xF0FF
	add [0xB1], [0xF8]
	mov [0xF8], [0x4B]
	and [0xF8], 0x0200
	shr [0xF8], 0x0001
	add [0xB1], [0xF8]
	ret

LABEL_C6BD:
	jne [HACK_VAR_67], 0x92, LABEL_C6F2
	mov [0xB8], 0x0000
	mov [0xF8], [0x49]
	and [0xF8], 0x0380
	shr [0xF8], 0x0007
	add [0xB8], [0xF8]
	mov [0xF8], [0x4B]
	and [0xF8], 0x0380
	shr [0xF8], 0x0004
	add [0xB8], [0xF8]
	mov [0xF8], [0x4D]
	and [0xF8], 0x0380
	shr [0xF8], 0x0001
	add [0xB8], [0xF8]
	ret

LABEL_C6F2:
	jne [HACK_VAR_67], 0x93, LABEL_C727
	and [0xB9], 0xFE00
	mov [0xF8], [0x49]
	and [0xF8], 0x0380
	shr [0xF8], 0x0007
	add [0xB9], [0xF8]
	mov [0xF8], [0x4B]
	and [0xF8], 0x0380
	shr [0xF8], 0x0004
	add [0xB9], [0xF8]
	mov [0xF8], [0x4D]
	and [0xF8], 0x0380
	shr [0xF8], 0x0001
	add [0xB9], [0xF8]
	ret

LABEL_C727:
	jne [HACK_VAR_67], 0x94, LABEL_C74E
	and [0xB9], 0x01FF
	mov [0xF8], [0x49]
	and [0xF8], 0x0380
	shr [0xF8], 0x0002
	add [0xB9], [0xF8]
	mov [0xF8], [0x4B]
	and [0xF8], 0x0380
	shr [0xF8], 0x0005
	add [0xB9], [0xF8]
	ret

LABEL_C74E:
	jne [HACK_VAR_67], 0x45, SHARED_RET
	mov [0xBA], 0x0000
	ret
LABEL_C759:
	db 0x11

LABEL_C75A:
	selectVideoPage 0x03
	fill page=0x03, color=0x00
	call LABEL_D213
	copyVideoPage src=0x03, dst=0x00
	selectVideoPage 0xFF

HANG_DRAW_CIN_222:
	video offset=CINEMATIC_222, x=[HERO_X], y=[HERO_Y]
	break
	jmp HANG_DRAW_CIN_222

LABEL_C770:
	jg [0x49], 0x0100, LABEL_C77F
	video offset=CINEMATIC_613, x=160, y=100
	break
	jmp LABEL_C770

LABEL_C77F:
	video offset=CINEMATIC_612, x=160, y=100
	break
	jmp LABEL_C770
LABEL_C787:
	db 0x11

LABEL_C788:
	jg [0x49], 0x0100, LABEL_C7DB
	video offset=CINEMATIC_650, x=160, y=100
	break
	video offset=CINEMATIC_651, x=160, y=100
	play id=0x005A, freq=0x0A, vol=0x40, channel=0x00
	play id=0x005A, freq=0x07, vol=0x40, channel=0x02
	play id=0x005A, freq=0x0F, vol=0x40, channel=0x03
	break
	mov [SCROLL_Y], 0x0004
	setup channel=0x3C, address=LABEL_3F8B

LABEL_C7B3:
	video offset=CINEMATIC_652, x=160, y=100
	jl [HERO_Y], 0x96, LABEL_C7C7
	jl [HERO_X], 0x9B, LABEL_C7C7
	mov [0x42], 0x009B

LABEL_C7C7:
	jg [HERO_Y], 0x24, LABEL_C7D7
	jg [HERO_X], 0xF8, LABEL_C7D7
	mov [0x43], 0x00F6

LABEL_C7D7:
	break
	jmp LABEL_C7B3

LABEL_C7DB:
	video offset=CINEMATIC_649, x=160, y=100
	break
	jmp LABEL_C788
LABEL_C7E3:
	db 0x11

LABEL_C7E4:
	jg [HERO_Y], 0x78, LABEL_C80B
	jg [HERO_X], 0x82, LABEL_C800
	video offset=CINEMATIC_401, x=97, y=32
	video offset=CINEMATIC_401, x=108, y=21
	video offset=CINEMATIC_601, x=74, y=27
	video offset=CINEMATIC_401, x=29, y=21

LABEL_C800:
	video offset=CINEMATIC_401, x=161, y=23
	video offset=CINEMATIC_405, x=206, y=7
	jmp LABEL_C80F

LABEL_C80B:
	video offset=CINEMATIC_405, x=211, y=135

LABEL_C80F:
	break
	jmp LABEL_C7E4
LABEL_C813:
	db 0x11

LABEL_C814:
	video offset=CINEMATIC_399, x=153, y=108
	video offset=CINEMATIC_400, x=192, y=140
	jg [HERO_Y], 0x96, LABEL_C832
	video offset=CINEMATIC_405, x=258, y=31
	video offset=CINEMATIC_403, x=127, y=39
	video offset=CINEMATIC_406, x=144, y=74
	jmp LABEL_C842

LABEL_C832:
	video offset=CINEMATIC_401, x=78, y=144
	video offset=CINEMATIC_402, x=104, y=171
	video offset=CINEMATIC_403, x=110, y=140
	video offset=CINEMATIC_404, x=111, y=162

LABEL_C842:
	break
	jmp LABEL_C814
LABEL_C846:
	db 0x11

LABEL_C847:
	jg [HERO_X], 0x46, LABEL_C858
	video offset=CINEMATIC_401, x=29, y=142
	video offset=CINEMATIC_401, x=39, y=123
	jmp LABEL_C881

LABEL_C858:
	jg [HERO_X], 0x0100, LABEL_C87C
	video offset=CINEMATIC_405, x=100, y=121
	video offset=CINEMATIC_605, x=162, y=131
	jl [HERO_X], 0xC0, LABEL_C881
	video offset=CINEMATIC_401, x=208, y=128
	video offset=CINEMATIC_601, x=222, y=119
	video offset=CINEMATIC_401, x=231, y=118
	jmp LABEL_C881

LABEL_C87C:
	video offset=CINEMATIC_405, x=292, y=115

LABEL_C881:
	break
	jmp LABEL_C847
LABEL_C885:
	db 0x11

LABEL_C886:
	video offset=CINEMATIC_601, x=85, y=105
	jl [HERO_X], 0xD7, LABEL_C896
	jl [HERO_Y], 0x55, LABEL_C8FA

LABEL_C896:
	video offset=CINEMATIC_406, x=53, y=131
	jne [0xB0], 0x03, LABEL_C8F0
	video offset=CINEMATIC_403, x=102, y=99
	video offset=CINEMATIC_403, x=94, y=88
	video offset=CINEMATIC_403, x=107, y=102
	video offset=CINEMATIC_403, x=116, y=95
	video offset=CINEMATIC_403, x=151, y=86
	video offset=CINEMATIC_403, x=178, y=115
	video offset=CINEMATIC_403, x=272, y=39
	video offset=CINEMATIC_406, x=137, y=135
	video offset=CINEMATIC_406, x=141, y=135
	video offset=CINEMATIC_406, x=135, y=133
	video offset=CINEMATIC_406, x=195, y=143
	video offset=CINEMATIC_404, x=104, y=138
	video offset=CINEMATIC_404, x=206, y=145
	video offset=CINEMATIC_404, x=213, y=144
	jl [HERO_X], 0xC8, LABEL_C8F0
	video offset=CINEMATIC_401, x=261, y=41
	video offset=CINEMATIC_403, x=246, y=27
	video offset=CINEMATIC_403, x=239, y=24
	video offset=CINEMATIC_403, x=233, y=27

LABEL_C8F0:
	jg [HERO_X], 0x64, LABEL_C8FA
	video offset=CINEMATIC_767, x=160, y=100

LABEL_C8FA:
	break
	jmp LABEL_C886
LABEL_C8FE:
	db 0x11

HANG_DRAW_CIN_658:
	video offset=CINEMATIC_658, x=160, y=100
	break
	jmp HANG_DRAW_CIN_658
LABEL_C907:
	db 0x11

LABEL_C908:
	je [0xB0], 0x03, LABEL_C914
	jg [HERO_X], 0x6A, LABEL_C920

LABEL_C914:
	video offset=CINEMATIC_402, x=22, y=124
	video offset=CINEMATIC_401, x=29, y=85
	video offset=CINEMATIC_758, x=160, y=100

LABEL_C920:
	jl [HERO_X], 0x32, LABEL_C952
	jg [HERO_X], 0xD8, LABEL_C952
	video offset=CINEMATIC_404, x=98, y=107
	video offset=CINEMATIC_601, x=117, y=74
	video offset=CINEMATIC_403, x=130, y=69
	video offset=CINEMATIC_403, x=137, y=67
	jl [HERO_X], 0x6A, LABEL_C952
	video offset=CINEMATIC_406, x=146, y=103
	video offset=CINEMATIC_402, x=152, y=116
	video offset=CINEMATIC_403, x=155, y=63
	video offset=CINEMATIC_406, x=173, y=104

LABEL_C952:
	jl [HERO_X], 0xC8, LABEL_C960
	video offset=CINEMATIC_404, x=253, y=103
	video offset=CINEMATIC_403, x=235, y=61

LABEL_C960:
	break
	jmp LABEL_C908
LABEL_C964:
	db 0x11

LABEL_C965:
	video offset=CINEMATIC_458, x=286, y=27
	video offset=CINEMATIC_730, x=66, y=143
	jg [HERO_Y], 0x78, LABEL_C9AA
	jg [HERO_X], 0x64, LABEL_C987
	jl [HERO_X], 0x3C, LABEL_C9AA
	video offset=CINEMATIC_401, x=71, y=54
	jmp LABEL_C9AA

LABEL_C987:
	jg [HERO_X], 0xAC, LABEL_C99C
	video offset=CINEMATIC_738, x=130, y=53
	video offset=CINEMATIC_403, x=144, y=54
	video offset=CINEMATIC_731, x=160, y=43
	jmp LABEL_C9AA

LABEL_C99C:
	jg [HERO_X], 0xF1, LABEL_C9AA
	video offset=CINEMATIC_403, x=187, y=60
	video offset=CINEMATIC_404, x=226, y=102

LABEL_C9AA:
	break
	jmp LABEL_C965
LABEL_C9AE:
	db 0x11

LABEL_C9AF:
	jl [HERO_Y], 0x64, LABEL_C9E7
	jg [HERO_X], 0x5F, LABEL_C9C2
	video offset=CINEMATIC_399, x=65, y=107
	jmp LABEL_C9EB

LABEL_C9C2:
	jg [HERO_X], 0xAC, LABEL_C9D3
	video offset=CINEMATIC_402, x=114, y=130
	video offset=CINEMATIC_404, x=165, y=169
	jmp LABEL_C9EB

LABEL_C9D3:
	jg [HERO_X], 0xE1, LABEL_C9E0
	video offset=CINEMATIC_663, x=160, y=126
	jmp LABEL_C9EB

LABEL_C9E0:
	video offset=CINEMATIC_406, x=245, y=159
	jmp LABEL_C9EB

LABEL_C9E7:
	video offset=CINEMATIC_403, x=253, y=15

LABEL_C9EB:
	break
	jmp LABEL_C9AF
LABEL_C9EF:
	db 0x11

LABEL_C9F0:
	jg [HERO_Y], 0x78, LABEL_CA30
	jg [HERO_X], 0xD1, LABEL_CA11
	jl [HERO_X], 0x69, LABEL_CA45
	video offset=CINEMATIC_732, x=131, y=58
	video offset=CINEMATIC_404, x=167, y=62
	video offset=CINEMATIC_601, x=197, y=31
	jmp LABEL_CA45

LABEL_CA11:
	jg [HERO_X], 0x0118, LABEL_CA45
	video offset=CINEMATIC_731, x=228, y=51
	video offset=CINEMATIC_402, x=235, y=76
	video offset=CINEMATIC_404, x=243, y=67
	video offset=CINEMATIC_406, x=255, y=62
	video offset=CINEMATIC_403, x=271, y=25
	jmp LABEL_CA45

LABEL_CA30:
	jg [HERO_X], 0xA0, LABEL_CA41
	video offset=CINEMATIC_404, x=77, y=165
	video offset=CINEMATIC_730, x=128, y=193
	jmp LABEL_CA45

LABEL_CA41:
	video offset=CINEMATIC_402, x=226, y=159

LABEL_CA45:
	break
	jmp LABEL_C9F0
LABEL_CA49:
	db 0x11

LABEL_CA4A:
	video offset=CINEMATIC_608, x=223, y=114
	video offset=CINEMATIC_405, x=160, y=110
	video offset=CINEMATIC_405, x=62, y=123
	video offset=CINEMATIC_609, x=9, y=126
	break
	jmp LABEL_CA4A
LABEL_CA5E:
	db 0x11

LABEL_CA5F:
	video offset=CINEMATIC_401, x=46, y=65
	video offset=CINEMATIC_653, x=268, y=18
	video offset=CINEMATIC_654, x=177, y=18
	video offset=CINEMATIC_601, x=69, y=67
	break
	jmp LABEL_CA5F
LABEL_CA74:
	db 0x11

HANG_DRAW_CIN_395:
	video offset=CINEMATIC_395, x=160, y=100
	break
	jmp HANG_DRAW_CIN_395

LABEL_CA7D:
	video offset=CINEMATIC_593, x=160, y=100
	break
	jne [0x6C], 0x03E8, LABEL_CA7D
	jg [HERO_X], 0x8C, LABEL_CB3E
	deleteChannels first=0x14, last=0x16
	video offset=CINEMATIC_593, x=160, y=100
	break
	play id=0x006A, freq=0x0A, vol=0x40, channel=0x00
	play id=0x006A, freq=0x0A, vol=0x40, channel=0x01
	play id=0x0074, freq=0x0A, vol=0x40, channel=0x02
	play id=0x0074, freq=0x0A, vol=0x40, channel=0x03
	video offset=CINEMATIC_160, x=125, y=153
	video offset=CINEMATIC_594, x=160, y=100
	break
	video offset=CINEMATIC_595, x=160, y=100
	video offset=CINEMATIC_169, x=126, y=115
	break
	video offset=CINEMATIC_596, x=160, y=100
	video offset=CINEMATIC_169, x=124, y=79
	break
	video offset=CINEMATIC_597, x=160, y=100
	video offset=CINEMATIC_169, x=126, y=70
	break
	video offset=CINEMATIC_598, x=160, y=100
	video offset=CINEMATIC_169, x=126, y=63
	setup channel=0x02, address=LABEL_CB75
	break
	video offset=CINEMATIC_599, x=160, y=100
	video offset=CINEMATIC_169, x=125, y=72
	break
	play id=0x0074, freq=0x0F, vol=0x40, channel=0x00
	play id=0x0074, freq=0x0A, vol=0x40, channel=0x01
	play id=0x0074, freq=0x0C, vol=0x40, channel=0x02
	play id=0x0074, freq=0x0E, vol=0x40, channel=0x03
	video offset=CINEMATIC_592, x=160, y=100
	video offset=CINEMATIC_160, x=124, y=88
	break
	video offset=CINEMATIC_592, x=160, y=100
	video offset=CINEMATIC_166, x=124, y=88
	selectVideoPage 0x00
	video offset=CINEMATIC_592, x=160, y=100
	selectVideoPage 0xFF
	break
	video offset=CINEMATIC_166, x=124, y=88
	break
	video offset=CINEMATIC_160, x=124, y=88
	mov [0xAF], 0x0058
	mov [HERO_X], 0x007C
	mov [HERO_Y], 0x0058
	mov [0x63], 0x0001
	setup channel=0x14, address=LABEL_E9A5
	setup channel=0x16, address=SETUP_CHAN_14_BY_VAR63
	killChannel

LABEL_CB3E:
	video offset=CINEMATIC_593, x=160, y=100
	break
	video offset=CINEMATIC_594, x=160, y=100
	break
	video offset=CINEMATIC_595, x=160, y=100
	break
	video offset=CINEMATIC_596, x=160, y=100
	break
	video offset=CINEMATIC_597, x=160, y=100
	break
	video offset=CINEMATIC_598, x=160, y=100
	setup channel=0x02, address=LABEL_CB75
	break
	video offset=CINEMATIC_599, x=160, y=100
	break
	video offset=CINEMATIC_592, x=160, y=100
	selectVideoPage 0x00
	video offset=CINEMATIC_592, x=160, y=100
	selectVideoPage 0xFF
	jmp LABEL_1C56
LABEL_CB74:
	db 0x11

LABEL_CB75:
	mov [0xE8], 0x00A0
	mov [0xE7], 0x0009
	mov [0xE6], 0x0061
	setup channel=0x01, address=LABEL_3152

LABEL_CB85:
	selectVideoPage 0x00
	video offset=CINEMATIC_600, x=125, y=[0xe8]
	video offset=CINEMATIC_600, x=160, y=[0xe8]
	selectVideoPage 0xFF
	sub [0xE8], 0x0003
	sub [0xE6], 0x0003
	break
	djnz [0xE7], LABEL_CB85
	killChannel

LABEL_CBA1:
	break
	jl [HERO_X], 0x42, LABEL_CBA1
	jg [HERO_X], 0x010A, LABEL_CBA1
	jl [HERO_Y], 0x7E, LABEL_CBA1
	deleteChannels first=0x14, last=0x16
	mov [0x1A], 0x0086
	setup channel=0x15, address=LABEL_2807
	setup channel=0x38, address=LABEL_28B2
	killChannel

LABEL_CBC6:
	video offset=CINEMATIC_458, x=104, y=43
	video offset=CINEMATIC_458, x=201, y=45
	break
	jmp LABEL_CBC6

LABEL_CBD2:
	video offset=CINEMATIC_458, x=104, y=40
	video offset=CINEMATIC_458, x=149, y=32
	video offset=CINEMATIC_458, x=194, y=41
	break
	jmp LABEL_CBD2

LABEL_CBE2:
	break
	jg [HERO_X], 0xDF, LABEL_CBE2
	jl [HERO_Y], 0x55, LABEL_CBE2
	deleteChannels first=0x14, last=0x16
	mov [0x1A], 0x0056
	setup channel=0x15, address=LABEL_2807
	setup channel=0x38, address=LABEL_28B2
	killChannel
