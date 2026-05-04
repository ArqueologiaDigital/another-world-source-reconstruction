SET_VAR5A_5B_INIT_OR_CONTINUE:
	jne [0x59], 0x00, LABEL_06B4
	mov [0x5A], 0x0022
	mov [0x5B], 0x0019
	ret

LABEL_06B4:
	jne [0x59], 0x01, LABEL_06C3
	mov [0x5A], 0x0026
	mov [0x5B], 0x001B
	ret

LABEL_06C3:
	jne [0x59], 0x02, LABEL_06D2
	mov [0x5A], 0x002A
	mov [0x5B], 0x001E
	ret

LABEL_06D2:
	jne [0x59], 0x0E, LABEL_06E1
	mov [0x5A], 0x004A
	mov [0x5B], 0x002B
	ret

LABEL_06E1:
	jne [0x59], 0x08, LABEL_06F0
	mov [0x5A], 0x0022
	mov [0x5B], 0x001F
	ret

LABEL_06F0:
	jne [0x59], 0x09, LABEL_06FF
	mov [0x5A], 0x0026
	mov [0x5B], 0x0021
	ret

LABEL_06FF:
	jne [0x59], 0x0B, LABEL_070E
	mov [0x5A], 0x0031
	mov [0x5B], 0x0027
	ret

LABEL_070E:
	jne [0x59], 0x0C, LABEL_071D
	mov [0x5A], 0x0035
	mov [0x5B], 0x002A
	ret

LABEL_071D:
	jne [0x59], 0x10, LABEL_072C
	mov [0x5A], 0x0022
	mov [0x5B], 0x0025
	ret

LABEL_072C:
	jne [0x59], 0x11, LABEL_073B
	mov [0x5A], 0x0026
	mov [0x5B], 0x0027
	ret

LABEL_073B:
	jne [0x59], 0x13, LABEL_074A
	mov [0x5A], 0x0031
	mov [0x5B], 0x0030
	ret

LABEL_074A:
	jne [0x59], 0x14, LABEL_0759
	mov [0x5A], 0x0035
	mov [0x5B], 0x0032
	ret

LABEL_0759:
	jne [0x59], 0x15, LABEL_0768
	mov [0x5A], 0x0040
	mov [0x5B], 0x0035
	ret

LABEL_0768:
	jne [0x59], 0x16, LABEL_0777
	mov [0x5A], 0x004A
	mov [0x5B], 0x0036
	ret

LABEL_0777:
	jne [0x59], 0x18, LABEL_0786
	mov [0x5A], 0x0022
	mov [0x5B], 0x002C
	ret

LABEL_0786:
	jne [0x59], 0x19, LABEL_0795
	mov [0x5A], 0x0026
	mov [0x5B], 0x002D
	ret

LABEL_0795:
	jne [0x59], 0x1A, LABEL_07A4
	mov [0x5A], 0x002A
	mov [0x5B], 0x0033
	ret

LABEL_07A4:
	jne [0x59], 0x1B, LABEL_07B3
	mov [0x5A], 0x0031
	mov [0x5B], 0x0038
	ret

LABEL_07B3:
	jne [0x59], 0x1C, LABEL_07C2
	mov [0x5A], 0x0035
	mov [0x5B], 0x003A
	ret

LABEL_07C2:
	jne [0x59], 0x1D, LABEL_07D1
	mov [0x5A], 0x0040
	mov [0x5B], 0x003B
	ret

LABEL_07D1:
	jne [0x59], 0x21, LABEL_07E0
	mov [0x5A], 0x0026
	mov [0x5B], 0x0035
	ret

LABEL_07E0:
	jne [0x59], 0x22, SHARED_RET
	mov [0x5A], 0x002B
	mov [0x5B], 0x003B
	ret

DRAW_CIN_SEQ_117_118_119:
	video type=1, offset=CINEMATIC_117, x=[0x60], y=[0x61], zoom=0x40
	video type=1, offset=CINEMATIC_118, x=[0x5d], y=[0x5e], zoom=0x40
	video type=1, offset=CINEMATIC_119, x=160, y=100
	ret

WAIT_LOOP_VAR_5C:
	jne [0x5C], 0xFFFF, LABEL_0812
	mov [0x5D], [0x60]
	mov [0x5E], [0x61]
	call DRAW_CIN_SEQ_117_118_119
	break
	jmp WAIT_LOOP_VAR_5C

LABEL_0812:
	mov [0x59], [0x5C]
	call SET_VAR5A_5B_INIT_OR_CONTINUE
	mov [0x5D], [0x5A]
	mov [0x5E], [0x5B]
	add [0x5D], 0x000A
	add [0x5D], 0x000A
	mov [0x59], [0x5C]
	call SET_VAR5A_5B_INIT_OR_CONTINUE
	video type=1, offset=CINEMATIC_116, x=[0x5a], y=[0x5b], zoom=0x40
	call DRAW_CIN_SEQ_117_118_119
	break
	mov [0x5C], 0xFFFF
	jmp WAIT_LOOP_VAR_5C
LABEL_083C:
	db 0x11

LABEL_083D:
	mov [0x62], [0x5F]
	add [0x5F], [HERO_POS_LEFT_RIGHT]
	mov [0xF8], [HERO_POS_JUMP_DOWN]
	shl [0xF8], 0x0003
	add [0x5F], [0xF8]
	call LABEL_05C3
	mov [0x59], [0x5F]
	call SET_VAR5A_5B_INIT_OR_CONTINUE
	mov [0x60], [0x5A]
	mov [0x61], [0x5B]
	video type=1, offset=CINEMATIC_117, x=[0x60], y=[0x61], zoom=0x40
	je [HERO_ACTION], 0x00, LABEL_086D
	call LABEL_0872
	mov [0x5C], [0x5F]

LABEL_086D:
	break
	jmp LABEL_083D
LABEL_0871:
	db 0x11

LABEL_0872:
	jne [0x59], 0x00, LABEL_087D
	mov [0x63], 0x0001
	ret

LABEL_087D:
	jne [0x59], 0x01, LABEL_0888
	mov [0x57], 0x0001
	ret

LABEL_0888:
	jne [0x59], 0x02, LABEL_0893
	mov [0x47], 0x0001
	ret

LABEL_0893:
	jne [0x59], 0x0E, LABEL_089E
	add [0x3E], 0x0005
	ret

LABEL_089E:
	jne [0x59], 0x08, LABEL_08A5
	ret

LABEL_08A5:
	jne [0x59], 0x09, LABEL_08AC
	ret

LABEL_08AC:
	jne [0x59], 0x0B, LABEL_08B6
	call DRAW_CIN_122_ON_PAGE_0
	ret

LABEL_08B6:
	jne [0x59], 0x0C, LABEL_08C1
	add [0x4F], 0x000A
	ret

LABEL_08C1:
	jne [0x59], 0x10, LABEL_08C8
	ret

LABEL_08C8:
	jne [0x59], 0x11, LABEL_08D3
	mov [0x46], 0x0001
	ret

LABEL_08D3:
	jne [0x59], 0x13, LABEL_08DD
	call LABEL_1807
	ret

LABEL_08DD:
	jne [0x59], 0x14, LABEL_08E8
	add [0x37], 0x0001
	ret

LABEL_08E8:
	jne [0x59], 0x15, LABEL_08F3
	mov [0x3E], 0x000A
	ret

LABEL_08F3:
	jne [0x59], 0x16, LABEL_08FE
	mov [0x56], 0x0001
	ret

LABEL_08FE:
	jne [0x59], 0x18, LABEL_0908
	call LABEL_181B
	ret

LABEL_0908:
	jne [0x59], 0x19, LABEL_0913
	mov [0x47], 0x0001
	ret

LABEL_0913:
	jne [0x59], 0x1A, LABEL_091A
	ret

LABEL_091A:
	jne [0x59], 0x1B, LABEL_0925
	add [0x41], 0x000A
	ret

LABEL_0925:
	jne [0x59], 0x1C, LABEL_0930
	add [0x37], 0x000A
	ret

LABEL_0930:
	jne [0x59], 0x1D, LABEL_093B
	mov [0x47], 0x0001
	ret

LABEL_093B:
	jne [0x59], 0x21, LABEL_0942
	ret

LABEL_0942:
	jne [0x59], 0x22, SHARED_RET
	mov [0x46], 0x0001
	ret

HANG_DRAW_CIN_173:
	video type=1, offset=CINEMATIC_173, x=160, y=100
	break
	jmp HANG_DRAW_CIN_173

LABEL_0955:
	call LABEL_17CF
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_012, x=160, y=100
	video type=1, offset=CINEMATIC_013, x=160, y=100
	selectVideoPage 0xFF
	setup channel=0x0A, address=HANG_DRAW_CIN_173
	break
	break
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_014, x=160, y=100
	selectVideoPage 0xFF
	break
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_015, x=160, y=100
	selectVideoPage 0xFF
	break
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_016, x=160, y=100
	selectVideoPage 0xFF
	break
	mov [0x11], 0x0001

DELAY_LOOP_VAR11:
	break
	djnz [0x11], DELAY_LOOP_VAR11
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_017, x=160, y=100
	selectVideoPage 0xFF
	mov [0x11], 0x000A
	break
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_018, x=160, y=100
	selectVideoPage 0xFF
	break
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_019, x=160, y=100
	selectVideoPage 0xFF
	break
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_020, x=160, y=100
	selectVideoPage 0xFF
	break
	break
	video type=1, offset=CINEMATIC_021, x=160, y=100
	video type=1, offset=CINEMATIC_022, x=160, y=100
	break
	video type=1, offset=CINEMATIC_021, x=160, y=100, zoom=[0x46]	;@raw=0x6A,0x1B,0x33,0xA0,0x64,0x46
	video type=1, offset=CINEMATIC_023, x=160, y=100, zoom=[0x46]	;@raw=0x6A,0x1D,0xE1,0xA0,0x64,0x46
	break
	video type=1, offset=CINEMATIC_024, x=160, y=100, zoom=[0x50]	;@raw=0x6A,0x1E,0x47,0xA0,0x64,0x50
	video type=1, offset=CINEMATIC_021, x=160, y=100, zoom=[0x50]	;@raw=0x6A,0x1B,0x33,0xA0,0x64,0x50
	break
	video type=1, offset=CINEMATIC_025, x=160, y=100, zoom=[0x50]	;@raw=0x6A,0x1F,0x39,0xA0,0x64,0x50
	video type=1, offset=CINEMATIC_021, x=160, y=100, zoom=[0x5a]	;@raw=0x6A,0x1B,0x33,0xA0,0x64,0x5A
	setup channel=0x37, address=LABEL_0E34
	break
	video type=1, offset=CINEMATIC_026, x=160, y=100, zoom=[0x50]	;@raw=0x6A,0x1F,0x9D,0xA0,0x64,0x50
	video type=1, offset=CINEMATIC_021, x=160, y=100, zoom=[0x64]	;@raw=0x6A,0x1B,0x33,0xA0,0x64,0x64
	break
	video type=1, offset=CINEMATIC_026, x=160, y=100, zoom=[0x50]	;@raw=0x6A,0x1F,0x9D,0xA0,0x64,0x50
	video type=1, offset=CINEMATIC_021, x=160, y=100, zoom=[0x6e]	;@raw=0x6A,0x1B,0x33,0xA0,0x64,0x6E
	break
	video type=1, offset=CINEMATIC_026, x=160, y=100, zoom=[0x50]	;@raw=0x6A,0x1F,0x9D,0xA0,0x64,0x50
	video type=1, offset=CINEMATIC_021, x=160, y=100, zoom=[0x78]	;@raw=0x6A,0x1B,0x33,0xA0,0x64,0x78
	killChannel
	video type=1, offset=CINEMATIC_026, x=160, y=100, zoom=[0x50]	;@raw=0x6A,0x1F,0x9D,0xA0,0x64,0x50
	video type=1, offset=CINEMATIC_021, x=160, y=100, zoom=[0x82]	;@raw=0x6A,0x1B,0x33,0xA0,0x64,0x82
	break
	video type=1, offset=CINEMATIC_026, x=160, y=100, zoom=[0x50]	;@raw=0x6A,0x1F,0x9D,0xA0,0x64,0x50
	video type=1, offset=CINEMATIC_021, x=160, y=100, zoom=[0x87]	;@raw=0x6A,0x1B,0x33,0xA0,0x64,0x87
	break
	video type=1, offset=CINEMATIC_021, x=160, y=100, zoom=[0x8e]	;@raw=0x6A,0x1B,0x33,0xA0,0x64,0x8E
	break
	video type=1, offset=CINEMATIC_021, x=160, y=100, zoom=[0x96]	;@raw=0x6A,0x1B,0x33,0xA0,0x64,0x96
	break
	video type=1, offset=CINEMATIC_021, x=160, y=100, zoom=[0xa0]	;@raw=0x6A,0x1B,0x33,0xA0,0x64,0xA0
	jmp LABEL_001B
LABEL_0A43:
	db 0x11

LABEL_0A44:
	break
	video type=1, offset=CINEMATIC_135, x=152, y=5
	video type=1, offset=CINEMATIC_066, x=242, y=65535, zoom=0x40
	break
	video type=1, offset=CINEMATIC_067, x=257, y=23, zoom=0x40
	video type=1, offset=CINEMATIC_136, x=147, y=33
	break
	video type=1, offset=CINEMATIC_135, x=144, y=53
	video type=1, offset=CINEMATIC_066, x=269, y=41, zoom=0x40
	break
	video type=1, offset=CINEMATIC_137, x=127, y=72
	video type=1, offset=CINEMATIC_136, x=269, y=67, zoom=0x40
	break
	video type=1, offset=CINEMATIC_135, x=111, y=86
	video type=1, offset=CINEMATIC_066, x=273, y=90, zoom=0x40
	break
	video type=1, offset=CINEMATIC_131, x=90, y=98
	video type=1, offset=CINEMATIC_067, x=273, y=110, zoom=0x40
	break
	video type=1, offset=CINEMATIC_137, x=64, y=107
	video type=1, offset=CINEMATIC_067, x=268, y=118, zoom=0x40
	video type=1, offset=CINEMATIC_138, x=178, y=3
	break
	video type=1, offset=CINEMATIC_137, x=42, y=122
	video type=1, offset=CINEMATIC_066, x=259, y=129, zoom=0x40
	video type=1, offset=CINEMATIC_138, x=172, y=70, zoom=[0x64]	;@raw=0x6A,0x1A,0x4B,0xAC,0x46,0x64
	break
	video type=1, offset=CINEMATIC_137, x=21, y=134
	video type=1, offset=CINEMATIC_066, x=278, y=141, zoom=0x40
	video type=1, offset=CINEMATIC_138, x=172, y=143, zoom=[0x8e]	;@raw=0x6A,0x1A,0x4B,0xAC,0x8F,0x8E
	break
	video type=1, offset=CINEMATIC_135, x=4, y=149
	video type=1, offset=CINEMATIC_136, x=287, y=148, zoom=0x40
	video type=1, offset=CINEMATIC_138, x=172, y=250, zoom=[0xdc]	;@raw=0x6A,0x1A,0x4B,0xAC,0xFA,0xDC
	selectVideoPage 0x03
	play id=0x008C, freq=0x1E, vol=0x40, channel=0x01
	play id=0x008C, freq=0x0A, vol=0x40, channel=0x00
	video type=1, offset=CINEMATIC_139, x=160, y=100
	video type=1, offset=CINEMATIC_140, x=160, y=100
	video type=1, offset=CINEMATIC_141, x=160, y=100
	selectVideoPage 0xFF
	setup channel=0x3C, address=PALETTE_FLASH_1F_TO_01
	unfreezeChannels first=0x27, last=0x38
	unfreezeChannels first=0x02, last=0x02
	break
	play id=0x008C, freq=0x1E, vol=0x40, channel=0x01
	fill page=0xFF, color=0x02
	break
	mov [PAUSE_SLICES], 0x0005
	setPalette 0x06
	video type=1, offset=CINEMATIC_142, x=160, y=100
	break
	setPalette 0x05
	play id=0x008C, freq=0x05, vol=0x40, channel=0x00
	video type=1, offset=CINEMATIC_080, x=198, y=49
	video type=1, offset=CINEMATIC_080, x=87, y=66
	video type=1, offset=CINEMATIC_143, x=160, y=100
	break
	setPalette 0x04
	video type=1, offset=CINEMATIC_144, x=315, y=58, zoom=0x40
	video type=1, offset=CINEMATIC_144, x=86, y=57
	video type=1, offset=CINEMATIC_080, x=198, y=91
	video type=1, offset=CINEMATIC_145, x=160, y=100
	break
	setPalette 0x03
	video type=1, offset=CINEMATIC_082, x=91, y=58
	video type=1, offset=CINEMATIC_083, x=306, y=56, zoom=0x40
	video type=1, offset=CINEMATIC_144, x=199, y=98
	video type=1, offset=CINEMATIC_146, x=160, y=100
	freezeChannels first=0x27, last=0x38
	break
	play id=0x008C, freq=0x14, vol=0x40, channel=0x01
	setPalette 0x02
	video type=1, offset=CINEMATIC_083, x=195, y=110
	video type=1, offset=CINEMATIC_147, x=160, y=100
	break
	setPalette 0x01
	video type=1, offset=CINEMATIC_082, x=50, y=111
	video type=1, offset=CINEMATIC_082, x=140, y=114
	video type=1, offset=CINEMATIC_082, x=207, y=104
	video type=1, offset=CINEMATIC_082, x=261, y=108, zoom=0x40
	break
	video type=1, offset=CINEMATIC_083, x=50, y=111
	video type=1, offset=CINEMATIC_083, x=140, y=114
	video type=1, offset=CINEMATIC_083, x=209, y=114
	video type=1, offset=CINEMATIC_083, x=261, y=110, zoom=0x40
	freezeChannels first=0x02, last=0x02
	killChannel

LABEL_0B7F:
	break
	je [0x57], 0x00, LABEL_0B7F
	setup channel=0x31, address=WAIT_VAR46_PLAY_8E_DRAW_CIN_056
	setup channel=0x22, address=WAIT_VAR56_PLAY_8E_DRAW_CIN_020
	mov [0x46], 0x0000
	mov [0x56], 0x0000
	break
	mov [0x46], 0x0001
	break
	mov [0x56], 0x0001
	play id=0x008E, freq=0x0F, vol=0x40, channel=0x01
	video type=1, offset=CINEMATIC_065, x=199, y=128
	break
	video type=1, offset=CINEMATIC_067, x=203, y=129
	break
	video type=1, offset=CINEMATIC_067, x=208, y=137
	break
	video type=1, offset=CINEMATIC_065, x=219, y=142
	break
	video type=1, offset=CINEMATIC_063, x=231, y=136
	break
	video type=1, offset=CINEMATIC_064, x=242, y=125
	break
	video type=1, offset=CINEMATIC_064, x=252, y=103
	break
	video type=1, offset=CINEMATIC_064, x=262, y=76, zoom=0x40
	break
	video type=1, offset=CINEMATIC_063, x=267, y=57, zoom=0x40
	break
	video type=1, offset=CINEMATIC_063, x=274, y=41, zoom=0x40
	break
	video type=1, offset=CINEMATIC_064, x=279, y=21, zoom=0x40
	break
	video type=1, offset=CINEMATIC_064, x=281, y=65535, zoom=0x40
	killChannel
	break

LABEL_0BE9:
	break
	je [0x57], 0x00, LABEL_0BE9
	play id=0x008E, freq=0x16, vol=0x40, channel=0x00
	video type=1, offset=CINEMATIC_067, x=205, y=118
	break
	video type=1, offset=CINEMATIC_067, x=222, y=121
	break
	video type=1, offset=CINEMATIC_066, x=241, y=126
	break
	video type=1, offset=CINEMATIC_067, x=253, y=129
	break
	video type=1, offset=CINEMATIC_068, x=262, y=130, zoom=0x40
	break
	video type=1, offset=CINEMATIC_129, x=260, y=128, zoom=0x40
	break
	video type=1, offset=CINEMATIC_130, x=258, y=127, zoom=0x40
	break
	video type=1, offset=CINEMATIC_131, x=253, y=127
	break
	video type=1, offset=CINEMATIC_132, x=241, y=116
	break
	video type=1, offset=CINEMATIC_133, x=232, y=102
	break
	video type=1, offset=CINEMATIC_134, x=228, y=93
	break
	video type=1, offset=CINEMATIC_134, x=231, y=75
	break
	video type=1, offset=CINEMATIC_064, x=234, y=64
	break
	video type=1, offset=CINEMATIC_064, x=239, y=42
	break
	video type=1, offset=CINEMATIC_134, x=235, y=21
	break
	video type=1, offset=CINEMATIC_133, x=227, y=8
	break
	video type=1, offset=CINEMATIC_132, x=196, y=2
	break
	setup channel=0x26, address=LABEL_0A44
	killChannel

LABEL_0C53:
	video type=1, offset=CINEMATIC_125, x=391, y=103, zoom=0x40
	play id=0x008E, freq=0x19, vol=0x40, channel=0x00
	break
	video type=1, offset=CINEMATIC_125, x=28, y=103
	break
	mov [0x4A], 0x0014

DELAY_LOOP_VAR4A:
	break
	djnz [0x4A], DELAY_LOOP_VAR4A
	setup channel=0x0F, address=INIT_VARS_48_49_4A
	killChannel
