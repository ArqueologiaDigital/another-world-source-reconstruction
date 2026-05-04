LABEL_C514:
	db 0x11

LABEL_C515:
	jne [HACK_VAR_67], 0x8A, LABEL_C546
	deleteChannels first=0x01, last=0x02
	setup channel=0x08, address=LABEL_3778
	setup channel=0x3C, address=LABEL_3FF4
	selectVideoPage 0x03
	video type=1, offset=CINEMATIC_795, x=160, y=100
	selectVideoPage 0xFF
	or [0xB0], 0x0001
	play id=0x006A, freq=0x0F, vol=0x40, channel=0x03
	play id=0x005A, freq=0x0A, vol=0x40, channel=0x00
	play id=0x0074, freq=0x0A, vol=0x40, channel=0x02
	ret

LABEL_C546:
	jne [HACK_VAR_67], 0xA7, LABEL_C56A
	copyVideoPage src=0x03, dst=0x00
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_639, x=160, y=100
	selectVideoPage 0xFF
	or [0xB1], 0x0008
	mov [SCROLL_Y], 0xFFFE
	play id=0x005A, freq=0x0A, vol=0x40, channel=0x00
	setup channel=0x3C, address=LABEL_3F75
	ret

LABEL_C56A:
	jne [HACK_VAR_67], 0xAF, LABEL_C583
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_609, x=160, y=100
	selectVideoPage 0xFF
	or [0xB0], 0x0002
	play id=0x005A, freq=0x0A, vol=0x40, channel=0x00
	ret

LABEL_C583:
	jne [HACK_VAR_67], 0x68, LABEL_C59C
	or [0xB1], 0x0010
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_407, x=160, y=100
	selectVideoPage 0xFF
	play id=0x005A, freq=0x0A, vol=0x40, channel=0x00
	ret

LABEL_C59C:
	jne [HACK_VAR_67], 0x28, LABEL_C5B5
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_286, x=160, y=100
	selectVideoPage 0xFF
	play id=0x005A, freq=0x0A, vol=0x40, channel=0x00
	or [0xB1], 0x8000
	ret

LABEL_C5B5:
	jne [HACK_VAR_67], 0xCA, LABEL_C5DA
	deleteChannels first=0x22, last=0x23
	or [0xBD], 0x0020
	mov [0x13], 0x0070
	add [0x21], 0x0010
	add [0x27], 0x0028
	mov [0x49], 0x7FFF
	video type=1, offset=CINEMATIC_134, x=[0x68], y=73, zoom=[0x5a]	;@raw=0x5A,0x1A,0xC0,0x68,0x49,0x5A
	ret

LABEL_C5DA:
	jne [HACK_VAR_67], 0xCB, LABEL_C601
	jne [0x1D], 0x0C, SHARED_RET
	deleteChannels first=0x2C, last=0x2D
	mov [0x13], 0x0070
	add [0x21], 0x0010
	add [0x27], 0x0014
	mov [0x4D], 0x7FFF
	video type=1, offset=CINEMATIC_134, x=[0x72], y=93, zoom=[0x5a]	;@raw=0x5A,0x1A,0xC0,0x72,0x5D,0x5A
	ret

LABEL_C601:
	jne [HACK_VAR_67], 0xCC, SHARED_RET
	jne [0x1D], 0x0B, LABEL_C62C
	deleteChannels first=0x2A, last=0x2B
	or [0xBD], 0x0002
	mov [0x13], 0x0070
	add [0x21], 0x0010
	add [0x27], 0x0028
	mov [0x4B], 0x7FFF
	video type=1, offset=CINEMATIC_134, x=[0x70], y=93, zoom=[0x5a]	;@raw=0x5A,0x1A,0xC0,0x70,0x5D,0x5A
	ret

LABEL_C62C:
	jne [0x1D], 0x0A, LABEL_C651
	deleteChannels first=0x28, last=0x29
	or [0xBD], 0x0004
	mov [0x13], 0x0070
	add [0x21], 0x0010
	add [0x27], 0x0028
	mov [0x49], 0x7FFF
	video type=1, offset=CINEMATIC_134, x=[0x6e], y=93, zoom=[0x5a]	;@raw=0x5A,0x1A,0xC0,0x6E,0x5D,0x5A
	ret

LABEL_C651:
	jne [0x1D], 0x0C, SHARED_RET
	deleteChannels first=0x2C, last=0x2D
	or [0xBD], 0x0001
	mov [0x13], 0x0070
	add [0x21], 0x0010
	add [0x27], 0x0028
	mov [0x4D], 0x7FFF
	video type=1, offset=CINEMATIC_134, x=[0x72], y=93, zoom=[0x5a]	;@raw=0x5A,0x1A,0xC0,0x72,0x5D,0x5A
	ret
LABEL_C676:
	db 0x11

LABEL_C677:
	jne [HACK_VAR_67], 0x4E, LABEL_C69E
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

LABEL_C69E:
	jne [HACK_VAR_67], 0x92, LABEL_C6D3
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

LABEL_C6D3:
	jne [HACK_VAR_67], 0x93, LABEL_C708
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

LABEL_C708:
	jne [HACK_VAR_67], 0x94, LABEL_C72F
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

LABEL_C72F:
	jne [HACK_VAR_67], 0x45, SHARED_RET
	mov [0xBA], 0x0000
	ret
LABEL_C73A:
	db 0x11

LABEL_C73B:
	selectVideoPage 0x03
	fill page=0x03, color=0x00
	call LABEL_D298
	copyVideoPage src=0x03, dst=0x00
	selectVideoPage 0xFF

HANG_DRAW_CIN_222:
	video type=1, offset=CINEMATIC_222, x=[0x01], y=[0x02], zoom=0x40
	break
	jmp HANG_DRAW_CIN_222

LABEL_C751:
	jg [0x49], 0x0100, LABEL_C760
	video type=1, offset=CINEMATIC_603, x=160, y=100
	break
	jmp LABEL_C751

LABEL_C760:
	video type=1, offset=CINEMATIC_602, x=160, y=100
	break
	jmp LABEL_C751
LABEL_C768:
	db 0x11

LABEL_C769:
	jg [0x49], 0x0100, LABEL_C7BC
	video type=1, offset=CINEMATIC_641, x=160, y=100
	break
	video type=1, offset=CINEMATIC_642, x=160, y=100
	play id=0x005A, freq=0x0A, vol=0x40, channel=0x00
	play id=0x005A, freq=0x07, vol=0x40, channel=0x02
	play id=0x005A, freq=0x0F, vol=0x40, channel=0x03
	break
	mov [SCROLL_Y], 0x0004
	setup channel=0x3C, address=LABEL_3F75

LABEL_C794:
	video type=1, offset=CINEMATIC_643, x=160, y=100
	jl [0x02], 0x96, LABEL_C7A8
	jl [0x01], 0x9B, LABEL_C7A8
	mov [0x42], 0x009B

LABEL_C7A8:
	jg [0x02], 0x24, LABEL_C7B8
	jg [0x01], 0xF8, LABEL_C7B8
	mov [0x43], 0x00F6

LABEL_C7B8:
	break
	jmp LABEL_C794

LABEL_C7BC:
	video type=1, offset=CINEMATIC_640, x=160, y=100
	break
	jmp LABEL_C769
LABEL_C7C4:
	db 0x11

LABEL_C7C5:
	jg [0x02], 0x78, LABEL_C7EC
	jg [0x01], 0x82, LABEL_C7E1
	video type=1, offset=CINEMATIC_400, x=97, y=32
	video type=1, offset=CINEMATIC_400, x=108, y=21
	video type=1, offset=CINEMATIC_590, x=74, y=27
	video type=1, offset=CINEMATIC_400, x=29, y=21

LABEL_C7E1:
	video type=1, offset=CINEMATIC_400, x=161, y=23
	video type=1, offset=CINEMATIC_405, x=206, y=7
	jmp LABEL_C7F0

LABEL_C7EC:
	video type=1, offset=CINEMATIC_405, x=211, y=135

LABEL_C7F0:
	break
	jmp LABEL_C7C5
LABEL_C7F4:
	db 0x11

LABEL_C7F5:
	video type=1, offset=CINEMATIC_398, x=153, y=108
	video type=1, offset=CINEMATIC_399, x=192, y=140
	jg [0x02], 0x96, LABEL_C817
	video type=1, offset=CINEMATIC_404, x=248, y=112
	video type=1, offset=CINEMATIC_405, x=258, y=31, zoom=0x40
	video type=1, offset=CINEMATIC_402, x=127, y=39
	video type=1, offset=CINEMATIC_406, x=144, y=74
	jmp LABEL_C827

LABEL_C817:
	video type=1, offset=CINEMATIC_400, x=78, y=144
	video type=1, offset=CINEMATIC_401, x=104, y=171
	video type=1, offset=CINEMATIC_402, x=110, y=140
	video type=1, offset=CINEMATIC_403, x=111, y=162

LABEL_C827:
	break
	jmp LABEL_C7F5
LABEL_C82B:
	db 0x11

LABEL_C82C:
	jg [0x01], 0x46, LABEL_C83D
	video type=1, offset=CINEMATIC_400, x=29, y=142
	video type=1, offset=CINEMATIC_400, x=39, y=123
	jmp LABEL_C866

LABEL_C83D:
	jg [0x01], 0x0100, LABEL_C861
	video type=1, offset=CINEMATIC_405, x=100, y=121
	video type=1, offset=CINEMATIC_594, x=162, y=131
	jl [0x01], 0xC0, LABEL_C866
	video type=1, offset=CINEMATIC_400, x=208, y=128
	video type=1, offset=CINEMATIC_590, x=222, y=119
	video type=1, offset=CINEMATIC_400, x=231, y=118
	jmp LABEL_C866

LABEL_C861:
	video type=1, offset=CINEMATIC_405, x=292, y=115, zoom=0x40

LABEL_C866:
	break
	jmp LABEL_C82C
LABEL_C86A:
	db 0x11

LABEL_C86B:
	video type=1, offset=CINEMATIC_590, x=85, y=105
	jl [0x01], 0xD7, LABEL_C87B
	jl [0x02], 0x55, LABEL_C8DF

LABEL_C87B:
	video type=1, offset=CINEMATIC_406, x=53, y=131
	jne [0xB0], 0x03, LABEL_C8D5
	video type=1, offset=CINEMATIC_402, x=102, y=99
	video type=1, offset=CINEMATIC_402, x=94, y=88
	video type=1, offset=CINEMATIC_402, x=107, y=102
	video type=1, offset=CINEMATIC_402, x=116, y=95
	video type=1, offset=CINEMATIC_402, x=151, y=86
	video type=1, offset=CINEMATIC_402, x=178, y=115
	video type=1, offset=CINEMATIC_402, x=272, y=39, zoom=0x40
	video type=1, offset=CINEMATIC_406, x=137, y=135
	video type=1, offset=CINEMATIC_406, x=141, y=135
	video type=1, offset=CINEMATIC_406, x=135, y=133
	video type=1, offset=CINEMATIC_406, x=195, y=143
	video type=1, offset=CINEMATIC_403, x=104, y=138
	video type=1, offset=CINEMATIC_403, x=206, y=145
	video type=1, offset=CINEMATIC_403, x=213, y=144
	jl [0x01], 0xC8, LABEL_C8D5
	video type=1, offset=CINEMATIC_400, x=261, y=41, zoom=0x40
	video type=1, offset=CINEMATIC_402, x=246, y=27
	video type=1, offset=CINEMATIC_402, x=239, y=24
	video type=1, offset=CINEMATIC_402, x=233, y=27

LABEL_C8D5:
	jg [0x01], 0x64, LABEL_C8DF
	video type=1, offset=CINEMATIC_758, x=160, y=100

LABEL_C8DF:
	break
	jmp LABEL_C86B
LABEL_C8E3:
	db 0x11

HANG_DRAW_CIN_648:
	video type=1, offset=CINEMATIC_648, x=160, y=100
	break
	jmp HANG_DRAW_CIN_648
LABEL_C8EC:
	db 0x11

LABEL_C8ED:
	je [0xB0], 0x03, LABEL_C8F9
	jg [0x01], 0x6A, LABEL_C905

LABEL_C8F9:
	video type=1, offset=CINEMATIC_401, x=22, y=124
	video type=1, offset=CINEMATIC_400, x=29, y=85
	video type=1, offset=CINEMATIC_749, x=160, y=100

LABEL_C905:
	jl [0x01], 0x32, LABEL_C937
	jg [0x01], 0xD8, LABEL_C937
	video type=1, offset=CINEMATIC_403, x=98, y=107
	video type=1, offset=CINEMATIC_590, x=117, y=74
	video type=1, offset=CINEMATIC_402, x=130, y=69
	video type=1, offset=CINEMATIC_402, x=137, y=67
	jl [0x01], 0x6A, LABEL_C937
	video type=1, offset=CINEMATIC_406, x=146, y=103
	video type=1, offset=CINEMATIC_401, x=152, y=116
	video type=1, offset=CINEMATIC_402, x=155, y=63
	video type=1, offset=CINEMATIC_406, x=173, y=104

LABEL_C937:
	jl [0x01], 0xC8, LABEL_C945
	video type=1, offset=CINEMATIC_403, x=253, y=103
	video type=1, offset=CINEMATIC_402, x=235, y=61

LABEL_C945:
	break
	jmp LABEL_C8ED
LABEL_C949:
	db 0x11

LABEL_C94A:
	video type=1, offset=CINEMATIC_459, x=286, y=27, zoom=0x40
	video type=1, offset=CINEMATIC_721, x=66, y=143
	jg [0x02], 0x78, LABEL_C98F
	jg [0x01], 0x64, LABEL_C96C
	jl [0x01], 0x3C, LABEL_C98F
	video type=1, offset=CINEMATIC_400, x=71, y=54
	jmp LABEL_C98F

LABEL_C96C:
	jg [0x01], 0xAC, LABEL_C981
	video type=1, offset=CINEMATIC_729, x=130, y=53
	video type=1, offset=CINEMATIC_402, x=144, y=54
	video type=1, offset=CINEMATIC_722, x=160, y=43
	jmp LABEL_C98F

LABEL_C981:
	jg [0x01], 0xF1, LABEL_C98F
	video type=1, offset=CINEMATIC_402, x=187, y=60
	video type=1, offset=CINEMATIC_403, x=226, y=102

LABEL_C98F:
	break
	jmp LABEL_C94A
LABEL_C993:
	db 0x11

LABEL_C994:
	jl [0x02], 0x64, LABEL_C9CC
	jg [0x01], 0x5F, LABEL_C9A7
	video type=1, offset=CINEMATIC_398, x=65, y=107
	jmp LABEL_C9D0

LABEL_C9A7:
	jg [0x01], 0xAC, LABEL_C9B8
	video type=1, offset=CINEMATIC_401, x=114, y=130
	video type=1, offset=CINEMATIC_403, x=165, y=169
	jmp LABEL_C9D0

LABEL_C9B8:
	jg [0x01], 0xE1, LABEL_C9C5
	video type=1, offset=CINEMATIC_653, x=160, y=126
	jmp LABEL_C9D0

LABEL_C9C5:
	video type=1, offset=CINEMATIC_406, x=245, y=159
	jmp LABEL_C9D0

LABEL_C9CC:
	video type=1, offset=CINEMATIC_402, x=253, y=15

LABEL_C9D0:
	break
	jmp LABEL_C994
LABEL_C9D4:
	db 0x11

LABEL_C9D5:
	jg [0x02], 0x78, LABEL_CA15
	jg [0x01], 0xD1, LABEL_C9F6
	jl [0x01], 0x69, LABEL_CA2A
	video type=1, offset=CINEMATIC_723, x=131, y=58
	video type=1, offset=CINEMATIC_403, x=167, y=62
	video type=1, offset=CINEMATIC_590, x=197, y=31
	jmp LABEL_CA2A

LABEL_C9F6:
	jg [0x01], 0x0118, LABEL_CA2A
	video type=1, offset=CINEMATIC_722, x=228, y=51
	video type=1, offset=CINEMATIC_401, x=235, y=76
	video type=1, offset=CINEMATIC_403, x=243, y=67
	video type=1, offset=CINEMATIC_406, x=255, y=62
	video type=1, offset=CINEMATIC_402, x=271, y=25, zoom=0x40
	jmp LABEL_CA2A

LABEL_CA15:
	jg [0x01], 0xA0, LABEL_CA26
	video type=1, offset=CINEMATIC_403, x=77, y=165
	video type=1, offset=CINEMATIC_721, x=128, y=193
	jmp LABEL_CA2A

LABEL_CA26:
	video type=1, offset=CINEMATIC_401, x=226, y=159

LABEL_CA2A:
	break
	jmp LABEL_C9D5
LABEL_CA2E:
	db 0x11

LABEL_CA2F:
	video type=1, offset=CINEMATIC_598, x=223, y=114
	video type=1, offset=CINEMATIC_405, x=160, y=110
	video type=1, offset=CINEMATIC_405, x=62, y=123
	video type=1, offset=CINEMATIC_599, x=9, y=126
	break
	jmp LABEL_CA2F
LABEL_CA43:
	db 0x11

LABEL_CA44:
	video type=1, offset=CINEMATIC_400, x=46, y=65
	video type=1, offset=CINEMATIC_644, x=268, y=18, zoom=0x40
	video type=1, offset=CINEMATIC_404, x=177, y=18
	video type=1, offset=CINEMATIC_590, x=69, y=67
	break
	jmp LABEL_CA44
LABEL_CA59:
	db 0x11

HANG_DRAW_CIN_394:
	video type=1, offset=CINEMATIC_394, x=160, y=100
	break
	jmp HANG_DRAW_CIN_394

LABEL_CA62:
	video type=1, offset=CINEMATIC_582, x=160, y=100
	break
	jne [0x6C], 0x03E8, LABEL_CA62
	jg [0x01], 0x8C, LABEL_CB29
	deleteChannels first=0x14, last=0x16
	video type=1, offset=CINEMATIC_582, x=160, y=100
	break
	play id=0x006A, freq=0x0A, vol=0x40, channel=0x00
	play id=0x006A, freq=0x0A, vol=0x40, channel=0x01
	play id=0x0074, freq=0x0A, vol=0x40, channel=0x02
	play id=0x0074, freq=0x0A, vol=0x40, channel=0x03
	video type=1, offset=CINEMATIC_160, x=125, y=153
	video type=1, offset=CINEMATIC_583, x=160, y=100
	break
	video type=1, offset=CINEMATIC_584, x=160, y=100
	video type=1, offset=CINEMATIC_169, x=126, y=115
	break
	video type=1, offset=CINEMATIC_585, x=160, y=100
	video type=1, offset=CINEMATIC_169, x=124, y=79
	break
	video type=1, offset=CINEMATIC_586, x=160, y=100
	video type=1, offset=CINEMATIC_169, x=126, y=70
	break
	video type=1, offset=CINEMATIC_587, x=160, y=100
	video type=1, offset=CINEMATIC_169, x=126, y=63
	setup channel=0x02, address=LABEL_CB60
	break
	video type=1, offset=CINEMATIC_588, x=160, y=100
	video type=1, offset=CINEMATIC_169, x=125, y=72
	break
	play id=0x0074, freq=0x0F, vol=0x40, channel=0x00
	play id=0x0074, freq=0x0A, vol=0x40, channel=0x01
	play id=0x0074, freq=0x0C, vol=0x40, channel=0x02
	play id=0x0074, freq=0x0E, vol=0x40, channel=0x03
	video type=1, offset=CINEMATIC_581, x=160, y=100
	video type=1, offset=CINEMATIC_160, x=124, y=88
	break
	video type=1, offset=CINEMATIC_581, x=160, y=100
	video type=1, offset=CINEMATIC_166, x=124, y=88
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_581, x=160, y=100
	selectVideoPage 0xFF
	break
	video type=1, offset=CINEMATIC_166, x=124, y=88
	break
	video type=1, offset=CINEMATIC_160, x=124, y=88
	mov [0xAF], 0x0058
	mov [0x01], 0x007C
	mov [0x02], 0x0058
	mov [0x63], 0x0001
	setup channel=0x14, address=LABEL_EA2E
	setup channel=0x16, address=SETUP_CHAN_14_BY_VAR63
	song id=0x0BC8, delay=0x0000, pos=0x00
	killChannel

LABEL_CB29:
	video type=1, offset=CINEMATIC_582, x=160, y=100
	break
	video type=1, offset=CINEMATIC_583, x=160, y=100
	break
	video type=1, offset=CINEMATIC_584, x=160, y=100
	break
	video type=1, offset=CINEMATIC_585, x=160, y=100
	break
	video type=1, offset=CINEMATIC_586, x=160, y=100
	break
	video type=1, offset=CINEMATIC_587, x=160, y=100
	setup channel=0x02, address=LABEL_CB60
	break
	video type=1, offset=CINEMATIC_588, x=160, y=100
	break
	video type=1, offset=CINEMATIC_581, x=160, y=100
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_581, x=160, y=100
	selectVideoPage 0xFF
	jmp LABEL_1C15
LABEL_CB5F:
	db 0x11

LABEL_CB60:
	mov [0xE8], 0x00A0
	mov [0xE7], 0x0009
	mov [0xE6], 0x0061
	setup channel=0x01, address=LABEL_3136

LABEL_CB70:
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_589, x=125, y=[0xe8], zoom=0x40
	video type=1, offset=CINEMATIC_589, x=160, y=[0xe8], zoom=0x40
	selectVideoPage 0xFF
	sub [0xE8], 0x0003
	sub [0xE6], 0x0003
	break
	djnz [0xE7], LABEL_CB70
	killChannel

LABEL_CB8C:
	break
	jl [0x01], 0x42, LABEL_CB8C
	jg [0x01], 0x010A, LABEL_CB8C
	jl [0x02], 0x7E, LABEL_CB8C
	deleteChannels first=0x14, last=0x16
	mov [0x1A], 0x0086
	setup channel=0x15, address=LABEL_27CE
	setup channel=0x38, address=LABEL_2879
	killChannel

LABEL_CBB1:
	video type=1, offset=CINEMATIC_459, x=104, y=43
	video type=1, offset=CINEMATIC_459, x=201, y=45
	break
	jmp LABEL_CBB1

LABEL_CBBD:
	video type=1, offset=CINEMATIC_459, x=104, y=40
	video type=1, offset=CINEMATIC_459, x=149, y=32
	video type=1, offset=CINEMATIC_459, x=194, y=41
	break
	jmp LABEL_CBBD

LABEL_CBCD:
	break
	jg [0x01], 0xDF, LABEL_CBCD
	jl [0x02], 0x55, LABEL_CBCD
	deleteChannels first=0x14, last=0x16
	mov [0x1A], 0x0056
	setup channel=0x15, address=LABEL_27CE
	setup channel=0x38, address=LABEL_2879
	killChannel
