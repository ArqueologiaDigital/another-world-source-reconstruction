LABEL_03A4:
	video offset=CINEMATIC_044, x=113, y=194
	video offset=CINEMATIC_545, x=123, y=172
	video offset=CINEMATIC_546, x=97, y=138
	break
	djnz [0xE6], LABEL_03A4
	video offset=CINEMATIC_547, x=123, y=172
	break
	video offset=CINEMATIC_548, x=123, y=172
	break
	video offset=CINEMATIC_549, x=123, y=172
	mov [0xE6], 0x0002

LABEL_03C7:
	break
	video offset=CINEMATIC_550, x=123, y=172
	djnz [0xE6], LABEL_03C7
	break
	video offset=CINEMATIC_551, x=123, y=172
	break
	video offset=CINEMATIC_552, x=123, y=172
	mov [HERO_X], 0x005C
	mov [HERO_Y], 0x00AC
	mov [0x63], 0x0002
	setup channel=0x14, address=LABEL_E54E
	setup channel=0x16, address=LABEL_DF3B
	setup channel=0x38, address=LABEL_0507
	mov [0x32], 0x0000
	break
	video offset=CINEMATIC_553, x=123, y=172
	break
	video offset=CINEMATIC_553, x=123, y=172
	break
	video offset=CINEMATIC_553, x=123, y=172
	break
	video offset=CINEMATIC_553, x=123, y=172
	call LABEL_12DE
	call LABEL_4407
	killChannel

LABEL_0411:
	break
	break
	play id=0x0052, freq=0x19, vol=0x20, channel=0x02
	video offset=CINEMATIC_554, x=105, y=215, zoom=0x40
	break
	video offset=CINEMATIC_554, x=105, y=152
	video offset=CINEMATIC_554, x=105, y=192
	break
	video offset=CINEMATIC_554, x=105, y=152
	mov [0xE7], 0x0005

DELAY_LOOP_VARE7:
	break
	djnz [0xE7], DELAY_LOOP_VARE7
	mov [0xE7], 0x0002

LABEL_0439:
	video offset=CINEMATIC_554, x=112, y=215, zoom=0x40
	play id=0x0052, freq=0x22, vol=0x20, channel=0x02
	break
	video offset=CINEMATIC_554, x=112, y=152
	video offset=CINEMATIC_554, x=112, y=192
	break
	video offset=CINEMATIC_554, x=112, y=152
	break
	djnz [0xE7], LABEL_0439
	mov [0xE8], 0x0036
	mov [0xE9], 0x0035
	mov [0xEA], 0x003E
	mov [0xE7], 0x000A
	play id=0x005A, freq=0x05, vol=0x40, channel=0x03

LABEL_046D:
	video offset=CINEMATIC_555, x=110, y=[0xe8], zoom=[0x30]	;@enc=alt
	video offset=CINEMATIC_555, x=114, y=[0xe9], zoom=[0x28]	;@enc=alt
	video offset=CINEMATIC_555, x=106, y=[0xea], zoom=[0x20]	;@enc=alt
	add [0xE8], 0x0028
	add [0xE9], 0x0014
	add [0xEA], 0x001C
	break
	djnz [0xE7], LABEL_046D
	play id=0x0075, freq=0x0C, vol=0x40, channel=0x03
	play id=0x0075, freq=0x07, vol=0x20, channel=0x02
	play id=0x005E, freq=0x14, vol=0x20, channel=0x00
	killChannel

LABEL_04A3:
	mov [0x0E], 0x0000
	mov [0x29], 0x0005

LABEL_04AB:
	call LABEL_83CB
	break
	djnz [0x29], LABEL_04AB
	mov [0x0E], 0x0003
	call GUARDED_DRAW_CV_304_305
	break
	call LABEL_83CB
	break
	mov [0x0E], 0x0004
	call LABEL_83E9
	break
	mov [0x0E], 0x0000
	call LABEL_83CB
	break
	setup channel=0x01, address=LABEL_0411
	mov [0x2F], 0x0019
	mov [0x29], 0x0116
	jmp DISPATCH_VAR2F_STATE
LABEL_04DE:
	db 0x11

LABEL_04DF:
	video offset=CINEMATIC_437, x=109, y=188
	video offset=CINEMATIC_338, x=32, y=141
	video offset=CINEMATIC_412, x=78, y=110
	video offset=CINEMATIC_338, x=134, y=142
	video offset=CINEMATIC_338, x=38, y=141
	video offset=CINEMATIC_338, x=77, y=141
	video offset=CINEMATIC_412, x=135, y=123
	video offset=CINEMATIC_437, x=111, y=63
	video offset=CINEMATIC_544, x=160, y=100
	break
	jmp LABEL_04DF

LABEL_0507:
	break
	jl [HERO_X], 0xE4, LABEL_0507
	bankSwitch 5;  Tank in the Battle Arena
	killChannel

LABEL_0512:
	break
	jl [0x6A], 0x94, LABEL_0512
	jne [0x6A], 0x94, LABEL_0526
	jl [0x6A], 0x012C, LABEL_0512

LABEL_0526:
	setup channel=0x23, address=KILL_CHANNEL_LANDING
	selectVideoPage 0x00
	setup channel=0x02, address=LABEL_0692
	video offset=CINEMATIC_556, x=160, y=100
	selectVideoPage 0xFF
	break
	play id=0x0063, freq=0x1C, vol=0x40, channel=0x02
	video offset=CINEMATIC_557, x=177, y=115
	video offset=CINEMATIC_558, x=160, y=107
	break
	video offset=CINEMATIC_558, x=163, y=120
	video offset=CINEMATIC_557, x=179, y=126
	break
	video offset=CINEMATIC_558, x=165, y=154
	video offset=CINEMATIC_557, x=179, y=128
	break
	video offset=CINEMATIC_558, x=165, y=165
	video offset=CINEMATIC_557, x=178, y=121
	break
	play id=0x0063, freq=0x1E, vol=0x20, channel=0x02
	video offset=CINEMATIC_558, x=166, y=163
	video offset=CINEMATIC_557, x=178, y=117
	break
	selectVideoPage 0x00
	video offset=CINEMATIC_558, x=165, y=165
	selectVideoPage 0xFF
	video offset=CINEMATIC_557, x=178, y=110
	mov [0xE6], 0x000A

DELAY_LOOP_VARE6:
	break
	djnz [0xE6], DELAY_LOOP_VARE6
	video offset=CINEMATIC_559, x=155, y=98
	break
	video offset=CINEMATIC_559, x=155, y=100
	break
	video offset=CINEMATIC_559, x=155, y=102
	mov [0xE6], 0x000A

LABEL_0597:
	break
	video offset=CINEMATIC_559, x=155, y=103
	djnz [0xE6], LABEL_0597
	break
	video offset=CINEMATIC_559, x=155, y=100
	break
	video offset=CINEMATIC_559, x=155, y=97
	mov [0xE6], 0x000A

DELAY_LOOP_VARE6_AT_05AE:
	break
	djnz [0xE6], DELAY_LOOP_VARE6_AT_05AE
	video offset=CINEMATIC_560, x=159, y=50
	break
	video offset=CINEMATIC_561, x=159, y=55
	break
	video offset=CINEMATIC_546, x=159, y=65
	break
	video offset=CINEMATIC_561, x=159, y=85
	break
	video offset=CINEMATIC_560, x=159, y=92
	break
	video offset=CINEMATIC_561, x=159, y=92
	break
	video offset=CINEMATIC_546, x=159, y=92

LABEL_05D5:
	break
	video offset=CINEMATIC_562, x=159, y=92
	jl [HERO_X], 0xAA, LABEL_05D5
	deleteChannels first=0x14, last=0x16
	setup channel=0x36, address=LABEL_0686
	break
	video offset=CINEMATIC_562, x=159, y=92
	jge [0x04], 0x4000, LABEL_05F8
	video offset=CINEMATIC_568, x=180, y=176

LABEL_05F8:
	break
	video offset=CINEMATIC_562, x=159, y=92
	jge [0x04], 0x4000, LABEL_0608
	video offset=CINEMATIC_567, x=180, y=176

LABEL_0608:
	break
	video offset=CINEMATIC_562, x=159, y=92
	jge [0x04], 0x4000, LABEL_0618
	video offset=CINEMATIC_566, x=180, y=176

LABEL_0618:
	break
	video offset=CINEMATIC_562, x=159, y=92
	jge [0x04], 0x4000, LABEL_0628
	video offset=CINEMATIC_565, x=179, y=176

LABEL_0628:
	break
	video offset=CINEMATIC_562, x=159, y=90
	jge [0x04], 0x4000, LABEL_0638
	video offset=CINEMATIC_564, x=178, y=175

LABEL_0638:
	break
	video offset=CINEMATIC_562, x=159, y=80
	jge [0x04], 0x4000, INIT_VARS_E6_E7_E8
	video offset=CINEMATIC_563, x=179, y=170
	mov [HERO_Y], 0x0064
	mov [0x32], 0x0009
