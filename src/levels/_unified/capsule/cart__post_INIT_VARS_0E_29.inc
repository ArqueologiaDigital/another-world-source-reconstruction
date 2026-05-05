LABEL_0466:
	call LABEL_7D43
	break
	djnz [0x29], LABEL_0466
	mov [0x0E], 0x0003
	call GUARDED_DRAW_CV_304_305
	break
	call LABEL_7D43
	break
	mov [0x0E], 0x0004
	call LABEL_7D61
	break
	mov [0x0E], 0x0000
	call LABEL_7D43
	break
	mov [0x2F], 0x0019
	mov [0x29], 0x016E
	jmp DISPATCH_VAR2F_STATE
LABEL_0495:
	db 0x11

LABEL_0496:
	video offset=CINEMATIC_298, x=111, y=133
	play id=0x0052, freq=0x1E, vol=0x40, channel=0x00
	break
	video offset=CINEMATIC_298, x=111, y=30
	break
	video offset=CINEMATIC_320, x=111, y=65508
	break
	video offset=CINEMATIC_300, x=111, y=3
	break
	break
	video offset=CINEMATIC_298, x=107, y=92
	play id=0x0052, freq=0x20, vol=0x40, channel=0x00
	break
	video offset=CINEMATIC_298, x=107, y=34
	break
	video offset=CINEMATIC_300, x=107, y=7
	video offset=CINEMATIC_298, x=109, y=157
	break
	play id=0x0052, freq=0x1E, vol=0x40, channel=0x00
	video offset=CINEMATIC_298, x=109, y=77
	video offset=CINEMATIC_300, x=107, y=7
	break
	video offset=CINEMATIC_298, x=109, y=32
	break
	video offset=CINEMATIC_320, x=109, y=65511
	selectVideoPage 0x00
	video offset=CINEMATIC_002, x=160, y=100
	selectVideoPage 0xFF
	break
	play id=0x005A, freq=0x05, vol=0x40, channel=0x02
	mov [0xE8], 0x001E
	mov [0xE9], 0x001E
	mov [0xEA], 0x001E
	mov [0xE7], 0x0008

LABEL_0505:
	video offset=CINEMATIC_321, x=110, y=[0xe8]
	video offset=CINEMATIC_321, x=114, y=[0xe9]
	video offset=CINEMATIC_322, x=106, y=[0xea]
	add [0xE8], 0x0028
	add [0xE9], 0x0014
	add [0xEA], 0x001C
	break
	djnz [0xE7], LABEL_0505
	sub [0xE9], 0x0014
	video offset=CINEMATIC_321, x=112, y=[0xe9]
	play id=0x0075, freq=0x0C, vol=0x18, channel=0x02
	play id=0x0075, freq=0x07, vol=0x18, channel=0x03
	play id=0x005E, freq=0x0A, vol=0x20, channel=0x01
	setup channel=0x34, address=KILL_CHANNEL_LANDING
	killChannel

LABEL_0545:
	video offset=CINEMATIC_323, x=[0xe8], y=[0xe9]
	break
	video offset=CINEMATIC_324, x=[0xe8], y=[0xe9]
	break
	video offset=CINEMATIC_325, x=[0xe8], y=[0xe9]
	break
	video offset=CINEMATIC_326, x=[0xe8], y=[0xe9]
	break
	video offset=CINEMATIC_327, x=[0xe8], y=[0xe9]
	jmp LABEL_0545

LABEL_0565:
	video offset=CINEMATIC_326, x=[0xea], y=[0xeb]
	break
	video offset=CINEMATIC_327, x=[0xea], y=[0xeb]
	break
	video offset=CINEMATIC_323, x=[0xea], y=[0xeb]
	break
	video offset=CINEMATIC_324, x=[0xea], y=[0xeb]
	break
	video offset=CINEMATIC_325, x=[0xea], y=[0xeb]
	break
	jmp LABEL_0565

LABEL_0586:
	mov [0xE6], 0x0014
	mov [0xE7], 0x0028
	video offset=CINEMATIC_565, x=160, y=[0xe6]
	selectVideoPage 0x00
	video offset=CINEMATIC_565, x=160, y=[0xe6]

LABEL_059A:
	selectVideoPage 0x00
	add [0xE6], 0x0002
	video offset=CINEMATIC_566, x=160, y=[0xe6]
	selectVideoPage 0xFF
	break
	djnz [0xE7], LABEL_059A
	play id=0x0067, freq=0x14, vol=0x40, channel=0x02
	selectVideoPage 0x00
	video offset=CINEMATIC_565, x=160, y=100
	selectVideoPage 0xFF
	killChannel

LABEL_05BB:
	video offset=CINEMATIC_524, x=160, y=100
	jg [HERO_X], 0x96, LABEL_05D3
	play id=0x005F, freq=0x0A, vol=0x40, channel=0x02
	selectVideoPage 0x00
	video offset=CINEMATIC_524, x=160, y=100
	selectVideoPage 0xFF

LABEL_05D3:
	break
	jg [HERO_X], 0x0139, LABEL_05BB
	video offset=CINEMATIC_525, x=160, y=100
	break

HANG_DRAW_CIN_526:
	video offset=CINEMATIC_526, x=160, y=100
	break
	jmp HANG_DRAW_CIN_526
LABEL_05E8:
	db 0x11

LABEL_05E9:
	break
	jg [HERO_X], 0x012C, LABEL_05E9
	play id=0x0057, freq=0x14, vol=0x40, channel=0x02
	mov [0xE6], 0x0001
	video offset=CINEMATIC_522, x=160, y=100
	mov [0xF8], [0xB9]
	and [0xF8], 0x0800
	jne [0xF8], 0x00, LABEL_0617
	call LABEL_3599
	or [0xB9], 0x0800
	setup channel=0x23, address=LABEL_1199

LABEL_0617:
	break
	play id=0x0067, freq=0x14, vol=0x40, channel=0x02
	video offset=CINEMATIC_522, x=160, y=100
	video offset=CINEMATIC_522, x=120, y=100
	break

LABEL_0627:
	video offset=CINEMATIC_522, x=160, y=100
	video offset=CINEMATIC_522, x=120, y=100
	video offset=CINEMATIC_523, x=160, y=100
	break
	jg [HERO_X], 0x96, LABEL_0627
	jl [0x68], 0x011D, LABEL_0627
	mov [0xE6], 0x0000
	video offset=CINEMATIC_522, x=160, y=100
	video offset=CINEMATIC_522, x=120, y=100
	break
	video offset=CINEMATIC_522, x=160, y=100
	jmp LABEL_05E9

LABEL_0655:
	break
	jl [HERO_X], 0xC3, LABEL_0655
	mov [0x63], 0x0064
	setup channel=0x14, address=INIT_VARS_63_01_02_03
	setup channel=0x15, address=KILL_CHANNEL_LANDING
	mov [0x2A], 0x0005
	killChannel
