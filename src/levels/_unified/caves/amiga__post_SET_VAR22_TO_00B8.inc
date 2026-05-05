LABEL_C0E4:
	db 0x11

LABEL_C0E5:
	jne [HACK_VAR_67], 0x8A, LABEL_C116
	deleteChannels first=0x01, last=0x02
	setup channel=0x08, address=INLINE_SET_VAR6B_TO_1
	setup channel=0x3C, address=LABEL_3DC8
	selectVideoPage 0x03
	video offset=CINEMATIC_780, x=160, y=100
	selectVideoPage 0xFF
	or [0xB0], 0x0001
	play id=0x006A, freq=0x0F, vol=0x40, channel=0x03
	play id=0x005A, freq=0x0A, vol=0x40, channel=0x00
	play id=0x0074, freq=0x0A, vol=0x40, channel=0x02
	ret

LABEL_C116:
	jne [HACK_VAR_67], 0xA7, LABEL_C13A
	copyVideoPage src=0x03, dst=0x00
	selectVideoPage 0x00
	video offset=CINEMATIC_626, x=160, y=100
	selectVideoPage 0xFF
	or [0xB1], 0x0008
	mov [SCROLL_Y], 0xFFFE
	play id=0x005A, freq=0x0A, vol=0x40, channel=0x00
	setup channel=0x3C, address=LABEL_3D49
	ret

LABEL_C13A:
	jne [HACK_VAR_67], 0xAF, LABEL_C153
	selectVideoPage 0x00
	video offset=CINEMATIC_598, x=160, y=100
	selectVideoPage 0xFF
	or [0xB0], 0x0002
	play id=0x005A, freq=0x0A, vol=0x40, channel=0x00
	ret

LABEL_C153:
	jne [HACK_VAR_67], 0x68, LABEL_C16C
	or [0xB1], 0x0010
	selectVideoPage 0x00
	video offset=CINEMATIC_386, x=160, y=100
	selectVideoPage 0xFF
	play id=0x005A, freq=0x0A, vol=0x40, channel=0x00
	ret

LABEL_C16C:
	jne [HACK_VAR_67], 0x28, LABEL_C181
	selectVideoPage 0x00
	video offset=CINEMATIC_779, x=160, y=100
	selectVideoPage 0xFF
	play id=0x005A, freq=0x0A, vol=0x40, channel=0x00
	ret

LABEL_C181:
	jne [HACK_VAR_67], 0xCA, LABEL_C1A6
	deleteChannels first=0x22, last=0x23
	or [0xBD], 0x0020
	mov [0x13], 0x0070
	add [0x21], 0x0010
	add [0x27], 0x0028
	mov [0x49], 0x7FFF
	video offset=CINEMATIC_134, x=[0x68], y=73, zoom=[0x5a]	;@enc=alt
	ret

LABEL_C1A6:
	jne [HACK_VAR_67], 0xCB, LABEL_C1CD
	jne [0x1D], 0x0C, SHARED_RET
	deleteChannels first=0x2C, last=0x2D
	mov [0x13], 0x0070
	add [0x21], 0x0010
	add [0x27], 0x0014
	mov [0x4D], 0x7FFF
	video offset=CINEMATIC_134, x=[0x72], y=93, zoom=[0x5a]	;@enc=alt
	ret

LABEL_C1CD:
	jne [HACK_VAR_67], 0xCC, SHARED_RET
	jne [0x1D], 0x0B, LABEL_C1F8
	deleteChannels first=0x2A, last=0x2B
	or [0xBD], 0x0002
	mov [0x13], 0x0070
	add [0x21], 0x0010
	add [0x27], 0x0028
	mov [0x4B], 0x7FFF
	video offset=CINEMATIC_134, x=[0x70], y=93, zoom=[0x5a]	;@enc=alt
	ret

LABEL_C1F8:
	jne [0x1D], 0x0A, LABEL_C21D
	deleteChannels first=0x28, last=0x29
	or [0xBD], 0x0004
	mov [0x13], 0x0070
	add [0x21], 0x0010
	add [0x27], 0x0028
	mov [0x49], 0x7FFF
	video offset=CINEMATIC_134, x=[0x6e], y=93, zoom=[0x5a]	;@enc=alt
	ret

LABEL_C21D:
	jne [0x1D], 0x0C, SHARED_RET
	deleteChannels first=0x2C, last=0x2D
	or [0xBD], 0x0001
	mov [0x13], 0x0070
	add [0x21], 0x0010
	add [0x27], 0x0028
	mov [0x4D], 0x7FFF
	video offset=CINEMATIC_134, x=[0x72], y=93, zoom=[0x5a]	;@enc=alt
	ret
LABEL_C242:
	db 0x11

LABEL_C243:
	jne [HACK_VAR_67], 0x4E, LABEL_C26A
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

LABEL_C26A:
	jne [HACK_VAR_67], 0x92, LABEL_C29F
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

LABEL_C29F:
	jne [HACK_VAR_67], 0x93, LABEL_C2D4
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

LABEL_C2D4:
	jne [HACK_VAR_67], 0x94, LABEL_C2FB
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

LABEL_C2FB:
	jne [HACK_VAR_67], 0x45, SHARED_RET
	mov [0xBA], 0x0000
	ret
LABEL_C306:
	db 0x11

LABEL_C307:
	selectVideoPage 0x03
	fill page=0x03, color=0x00
	call LABEL_CD67
	copyVideoPage src=0x03, dst=0x00
	selectVideoPage 0xFF

HANG_DRAW_CIN_205:
	video offset=CINEMATIC_205, x=[0x01], y=[0x02]
	break
	jmp HANG_DRAW_CIN_205

LABEL_C31D:
	jg [0x49], 0x0100, LABEL_C32C
	video offset=CINEMATIC_592, x=160, y=100
	break
	jmp LABEL_C31D

LABEL_C32C:
	video offset=CINEMATIC_591, x=160, y=100
	break
	jmp LABEL_C31D
LABEL_C334:
	db 0x11

LABEL_C335:
	jg [0x49], 0x0100, LABEL_C388
	video offset=CINEMATIC_628, x=160, y=100
	break
	video offset=CINEMATIC_629, x=160, y=100
	play id=0x005A, freq=0x0A, vol=0x40, channel=0x00
	play id=0x005A, freq=0x07, vol=0x40, channel=0x02
	play id=0x005A, freq=0x0F, vol=0x40, channel=0x03
	break
	mov [SCROLL_Y], 0x0004
	setup channel=0x3C, address=LABEL_3D49

LABEL_C360:
	video offset=CINEMATIC_630, x=160, y=100
	jl [0x02], 0x96, LABEL_C374
	jl [0x01], 0x9B, LABEL_C374
	mov [0x42], 0x009B

LABEL_C374:
	jg [0x02], 0x24, LABEL_C384
	jg [0x01], 0xF8, LABEL_C384
	mov [0x43], 0x00F6

LABEL_C384:
	break
	jmp LABEL_C360

LABEL_C388:
	video offset=CINEMATIC_627, x=160, y=100
	break
	jmp LABEL_C335
LABEL_C390:
	db 0x11

LABEL_C391:
	jg [0x02], 0x78, LABEL_C3B8
	jg [0x01], 0x82, LABEL_C3AD
	video offset=CINEMATIC_380, x=97, y=32
	video offset=CINEMATIC_380, x=108, y=21
	video offset=CINEMATIC_580, x=74, y=27
	video offset=CINEMATIC_380, x=29, y=21

LABEL_C3AD:
	video offset=CINEMATIC_380, x=161, y=23
	video offset=CINEMATIC_384, x=206, y=7
	jmp LABEL_C3BC

LABEL_C3B8:
	video offset=CINEMATIC_384, x=211, y=135

LABEL_C3BC:
	break
	jmp LABEL_C391
LABEL_C3C0:
	db 0x11

LABEL_C3C1:
	video offset=CINEMATIC_378, x=153, y=108
	video offset=CINEMATIC_379, x=192, y=140
	jg [0x02], 0x96, LABEL_C3DF
	video offset=CINEMATIC_384, x=258, y=31
	video offset=CINEMATIC_382, x=127, y=39
	video offset=CINEMATIC_385, x=144, y=74
	jmp LABEL_C3EF

LABEL_C3DF:
	video offset=CINEMATIC_380, x=78, y=144
	video offset=CINEMATIC_381, x=104, y=171
	video offset=CINEMATIC_382, x=110, y=140
	video offset=CINEMATIC_383, x=111, y=162

LABEL_C3EF:
	break
	jmp LABEL_C3C1
LABEL_C3F3:
	db 0x11

LABEL_C3F4:
	jg [0x01], 0x46, LABEL_C405
	video offset=CINEMATIC_380, x=29, y=142
	video offset=CINEMATIC_380, x=39, y=123
	jmp LABEL_C42E

LABEL_C405:
	jg [0x01], 0x0100, LABEL_C429
	video offset=CINEMATIC_384, x=100, y=121
	video offset=CINEMATIC_584, x=162, y=131
	jl [0x01], 0xC0, LABEL_C42E
	video offset=CINEMATIC_380, x=208, y=128
	video offset=CINEMATIC_580, x=222, y=119
	video offset=CINEMATIC_380, x=231, y=118
	jmp LABEL_C42E

LABEL_C429:
	video offset=CINEMATIC_384, x=292, y=115

LABEL_C42E:
	break
	jmp LABEL_C3F4
LABEL_C432:
	db 0x11

LABEL_C433:
	video offset=CINEMATIC_580, x=85, y=105
	video offset=CINEMATIC_382, x=102, y=99
	video offset=CINEMATIC_382, x=94, y=88
	video offset=CINEMATIC_382, x=107, y=102
	video offset=CINEMATIC_382, x=116, y=95
	video offset=CINEMATIC_382, x=151, y=86
	video offset=CINEMATIC_382, x=178, y=115
	video offset=CINEMATIC_382, x=272, y=39
	video offset=CINEMATIC_385, x=53, y=131
	video offset=CINEMATIC_385, x=137, y=135
	video offset=CINEMATIC_385, x=141, y=135
	video offset=CINEMATIC_385, x=135, y=133
	video offset=CINEMATIC_385, x=195, y=143
	video offset=CINEMATIC_383, x=104, y=138
	video offset=CINEMATIC_383, x=206, y=145
	video offset=CINEMATIC_383, x=213, y=144
	video offset=CINEMATIC_380, x=261, y=41
	video offset=CINEMATIC_382, x=246, y=27
	video offset=CINEMATIC_382, x=239, y=24
	video offset=CINEMATIC_382, x=233, y=27
	video offset=CINEMATIC_747, x=160, y=100
	break
	jmp LABEL_C433
LABEL_C48D:
	db 0x11

HANG_DRAW_CIN_637:
	video offset=CINEMATIC_637, x=160, y=100
	break
	jmp HANG_DRAW_CIN_637
LABEL_C496:
	db 0x11

LABEL_C497:
	video offset=CINEMATIC_381, x=22, y=124
	video offset=CINEMATIC_383, x=98, y=107
	video offset=CINEMATIC_580, x=117, y=74
	video offset=CINEMATIC_380, x=29, y=85
	video offset=CINEMATIC_385, x=146, y=103
	video offset=CINEMATIC_381, x=152, y=116
	video offset=CINEMATIC_385, x=173, y=104
	video offset=CINEMATIC_383, x=253, y=103
	video offset=CINEMATIC_382, x=155, y=63
	video offset=CINEMATIC_382, x=270, y=69
	video offset=CINEMATIC_382, x=235, y=61
	video offset=CINEMATIC_382, x=130, y=69
	video offset=CINEMATIC_382, x=137, y=67
	video offset=CINEMATIC_737, x=160, y=100
	break
	jmp LABEL_C497
LABEL_C4D4:
	db 0x11

LABEL_C4D5:
	video offset=CINEMATIC_437, x=286, y=27
	video offset=CINEMATIC_709, x=66, y=143
	jg [0x02], 0x78, LABEL_C51A
	jg [0x01], 0x64, LABEL_C4F7
	jl [0x01], 0x3C, LABEL_C51A
	video offset=CINEMATIC_380, x=71, y=54
	jmp LABEL_C51A

LABEL_C4F7:
	jg [0x01], 0xAC, LABEL_C50C
	video offset=CINEMATIC_717, x=130, y=53
	video offset=CINEMATIC_382, x=144, y=54
	video offset=CINEMATIC_710, x=160, y=43
	jmp LABEL_C51A

LABEL_C50C:
	jg [0x01], 0xF1, LABEL_C51A
	video offset=CINEMATIC_382, x=187, y=60
	video offset=CINEMATIC_383, x=226, y=102

LABEL_C51A:
	break
	jmp LABEL_C4D5
LABEL_C51E:
	db 0x11

LABEL_C51F:
	jl [0x02], 0x64, LABEL_C557
	jg [0x01], 0x5F, LABEL_C532
	video offset=CINEMATIC_378, x=65, y=107
	jmp LABEL_C55B

LABEL_C532:
	jg [0x01], 0xAC, LABEL_C543
	video offset=CINEMATIC_381, x=114, y=130
	video offset=CINEMATIC_383, x=165, y=169
	jmp LABEL_C55B

LABEL_C543:
	jg [0x01], 0xE1, LABEL_C550
	video offset=CINEMATIC_642, x=160, y=126
	jmp LABEL_C55B

LABEL_C550:
	video offset=CINEMATIC_385, x=245, y=159
	jmp LABEL_C55B

LABEL_C557:
	video offset=CINEMATIC_382, x=253, y=15

LABEL_C55B:
	break
	jmp LABEL_C51F
LABEL_C55F:
	db 0x11

LABEL_C560:
	jg [0x02], 0x78, LABEL_C5A0
	jg [0x01], 0xD1, LABEL_C581
	jl [0x01], 0x69, LABEL_C5B5
	video offset=CINEMATIC_711, x=131, y=58
	video offset=CINEMATIC_383, x=167, y=62
	video offset=CINEMATIC_580, x=197, y=31
	jmp LABEL_C5B5

LABEL_C581:
	jg [0x01], 0x0118, LABEL_C5B5
	video offset=CINEMATIC_710, x=228, y=51
	video offset=CINEMATIC_381, x=235, y=76
	video offset=CINEMATIC_383, x=243, y=67
	video offset=CINEMATIC_385, x=255, y=62
	video offset=CINEMATIC_382, x=271, y=25
	jmp LABEL_C5B5

LABEL_C5A0:
	jg [0x01], 0xA0, LABEL_C5B1
	video offset=CINEMATIC_383, x=77, y=165
	video offset=CINEMATIC_709, x=128, y=193
	jmp LABEL_C5B5

LABEL_C5B1:
	video offset=CINEMATIC_381, x=226, y=159

LABEL_C5B5:
	break
	jmp LABEL_C560
LABEL_C5B9:
	db 0x11

LABEL_C5BA:
	video offset=CINEMATIC_587, x=223, y=114
	video offset=CINEMATIC_384, x=160, y=110
	video offset=CINEMATIC_384, x=62, y=123
	video offset=CINEMATIC_588, x=9, y=126
	break
	jmp LABEL_C5BA
LABEL_C5CE:
	db 0x11

LABEL_C5CF:
	video offset=CINEMATIC_380, x=46, y=65
	video offset=CINEMATIC_631, x=268, y=18
	video offset=CINEMATIC_632, x=177, y=18
	video offset=CINEMATIC_580, x=69, y=67
	break
	jmp LABEL_C5CF
LABEL_C5E4:
	db 0x11

HANG_DRAW_CIN_374:
	video offset=CINEMATIC_374, x=160, y=100
	break
	jmp HANG_DRAW_CIN_374

LABEL_C5ED:
	video offset=CINEMATIC_572, x=160, y=100
	break
	jne [0x6C], 0x03E8, LABEL_C5ED
	jg [0x01], 0x8C, LABEL_C6AE
	deleteChannels first=0x14, last=0x16
	video offset=CINEMATIC_572, x=160, y=100
	break
	play id=0x006A, freq=0x0A, vol=0x40, channel=0x00
	play id=0x006A, freq=0x0A, vol=0x40, channel=0x01
	play id=0x0074, freq=0x0A, vol=0x40, channel=0x02
	play id=0x0074, freq=0x0A, vol=0x40, channel=0x03
	video offset=CINEMATIC_160, x=125, y=153
	video offset=CINEMATIC_573, x=160, y=100
	break
	video offset=CINEMATIC_574, x=160, y=100
	video offset=CINEMATIC_169, x=126, y=115
	break
	video offset=CINEMATIC_575, x=160, y=100
	video offset=CINEMATIC_169, x=124, y=79
	break
	video offset=CINEMATIC_576, x=160, y=100
	video offset=CINEMATIC_169, x=126, y=70
	break
	video offset=CINEMATIC_577, x=160, y=100
	video offset=CINEMATIC_169, x=126, y=63
	setup channel=0x02, address=LABEL_C6E2
	break
	video offset=CINEMATIC_578, x=160, y=100
	video offset=CINEMATIC_169, x=125, y=72
	break
	play id=0x0074, freq=0x0F, vol=0x40, channel=0x00
	play id=0x0074, freq=0x0A, vol=0x40, channel=0x01
	play id=0x0074, freq=0x0C, vol=0x40, channel=0x02
	play id=0x0074, freq=0x0E, vol=0x40, channel=0x03
	video offset=CINEMATIC_571, x=160, y=100
	video offset=CINEMATIC_160, x=124, y=88
	break
	video offset=CINEMATIC_571, x=160, y=100
	video offset=CINEMATIC_166, x=124, y=88
	selectVideoPage 0x00
	video offset=CINEMATIC_571, x=160, y=100
	selectVideoPage 0xFF
	break
	video offset=CINEMATIC_166, x=124, y=88
	break
	video offset=CINEMATIC_160, x=124, y=88
	mov [0xAF], 0x0058
	mov [0x01], 0x007C
	mov [0x02], 0x0058
	mov [0x63], 0x0001
	setup channel=0x14, address=LABEL_E41E
	setup channel=0x16, address=LABEL_DF3B
	killChannel

LABEL_C6AE:
	video offset=CINEMATIC_572, x=160, y=100
	break
	video offset=CINEMATIC_573, x=160, y=100
	break
	video offset=CINEMATIC_574, x=160, y=100
	break
	video offset=CINEMATIC_575, x=160, y=100
	break
	video offset=CINEMATIC_576, x=160, y=100
	break
	video offset=CINEMATIC_577, x=160, y=100
	setup channel=0x02, address=LABEL_C6E2
	break
	video offset=CINEMATIC_578, x=160, y=100
	break
	video offset=CINEMATIC_571, x=160, y=100
	selectVideoPage 0x00
	video offset=CINEMATIC_571, x=160, y=100
	selectVideoPage 0xFF
	killChannel

LABEL_C6E2:
	mov [0xE8], 0x00A0
	mov [0xE7], 0x0009
	mov [0xE6], 0x0061
	setup channel=0x01, address=LABEL_2F29

LABEL_C6F2:
	selectVideoPage 0x00
	video offset=CINEMATIC_579, x=125, y=[0xe8]
	video offset=CINEMATIC_579, x=160, y=[0xe8]
	selectVideoPage 0xFF
	sub [0xE8], 0x0003
	sub [0xE6], 0x0003
	break
	djnz [0xE7], LABEL_C6F2
	killChannel

LABEL_C70E:
	break
	jl [0x02], 0x7E, LABEL_C70E
	deleteChannels first=0x14, last=0x16
	mov [0x1A], 0x0086
	setup channel=0x15, address=LABEL_2643
	setup channel=0x38, address=LABEL_26EE
	killChannel

LABEL_C726:
	video offset=CINEMATIC_437, x=104, y=43
	video offset=CINEMATIC_437, x=201, y=45
	break
	jmp LABEL_C726

LABEL_C732:
	video offset=CINEMATIC_437, x=104, y=40
	video offset=CINEMATIC_437, x=149, y=32
	video offset=CINEMATIC_437, x=194, y=41
	break
	jmp LABEL_C732

LABEL_C742:
	break
	jl [0x02], 0x55, LABEL_C742
	deleteChannels first=0x14, last=0x16
	mov [0x1A], 0x0056
	setup channel=0x15, address=LABEL_2643
	setup channel=0x38, address=LABEL_26EE
	killChannel
