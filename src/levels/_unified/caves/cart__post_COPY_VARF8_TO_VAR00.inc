LABEL_03B9:
	jne [0x00], 0x1E, LABEL_03C6
	text id=0x0160, x=26, y=180, color=0x0F ; "CLLD"
	ret

LABEL_03C6:
	jne [0x00], 0x1F, LABEL_03D3
	text id=0x0164, x=26, y=180, color=0x0F ; "LBKG"
	ret

LABEL_03D3:
	jne [0x00], 0x21, LABEL_03E0
	text id=0x0163, x=26, y=180, color=0x0F ; "XDDJ"
	ret

LABEL_03E0:
	jne [0x00], 0x23, LABEL_03ED
	text id=0x0161, x=26, y=180, color=0x0F ; "FXLC"
	ret

LABEL_03ED:
	jne [0x00], 0x25, LABEL_03FA
	text id=0x0162, x=26, y=180, color=0x0F ; "KRFK"
	ret

LABEL_03FA:
	jne [0x00], 0x27, LABEL_0407
	text id=0x0165, x=26, y=180, color=0x0F ; "KLFB"
	ret

LABEL_0407:
	jne [0x00], 0x29, LABEL_0414
	text id=0x0166, x=26, y=180, color=0x0F ; "TTCT"
	ret

LABEL_0414:
	jne [0x00], 0x2A, LABEL_0421
	text id=0x0167, x=26, y=180, color=0x0F ; "DDRX"
	ret

LABEL_0421:
	jne [0x00], 0x2B, LABEL_042E
	text id=0x0168, x=26, y=180, color=0x0F ; "TBHK"
	ret

LABEL_042E:
	jne [0x00], 0x2C, LABEL_043B
	text id=0x016C, x=26, y=180, color=0x0F ; "BFLX"
	ret

LABEL_043B:
	jne [0x00], 0x2D, LABEL_0448
	text id=0x016D, x=26, y=180, color=0x0F ; "XJRT"
	ret

LABEL_0448:
	jne [0x00], 0x2E, LABEL_0455
	text id=0x016E, x=26, y=180, color=0x0F ; "HRTB"
	ret

LABEL_0455:
	jne [0x00], 0x2F, LABEL_0462
	text id=0x016F, x=26, y=180, color=0x0F ; "HBHK"
	ret

LABEL_0462:
	jne [0x00], 0x30, LABEL_046F
	text id=0x0170, x=26, y=180, color=0x0F ; "JCGB"
	ret

LABEL_046F:
	jne [0x00], 0x31, SHARED_RET
	text id=0x0169, x=26, y=180, color=0x0F ; "BRTD"
	ret
LABEL_047C:
	db 0x11

SETUP_VAR8B_6E_VAR97_B7_VAR96_0:
	mov [0x8B], 0x006E
	or [0x8B], 0x8000
	mov [0x96], 0x0000
	mov [0x97], 0x00B7
	or [0x97], 0x4000
	ret

LABEL_0492:
	break
	mov [0xF8], [0xB1]
	and [0xF8], 0x0001
	je [0xF8], 0x00, KILL_CHAN_AT_01FB
	jl [0x6A], 0x94, LABEL_0492
	jne [0x6A], 0x94, LABEL_04B3
	jl [0x6A], 0x012C, LABEL_0492

LABEL_04B3:
	setup channel=0x23, address=KILL_CHANNEL_LANDING
	selectVideoPage 0x00
	setup channel=0x02, address=LABEL_0633
	video type=1, offset=CINEMATIC_565, x=160, y=100
	selectVideoPage 0xFF
	break
	play id=0x0063, freq=0x1C, vol=0x40, channel=0x02
	video type=1, offset=CINEMATIC_566, x=177, y=115
	video type=1, offset=CINEMATIC_567, x=160, y=107
	break
	video type=1, offset=CINEMATIC_567, x=163, y=120
	video type=1, offset=CINEMATIC_566, x=179, y=126
	break
	video type=1, offset=CINEMATIC_567, x=165, y=154
	video type=1, offset=CINEMATIC_566, x=179, y=128
	break
	video type=1, offset=CINEMATIC_567, x=165, y=165
	video type=1, offset=CINEMATIC_566, x=178, y=121
	break
	play id=0x0063, freq=0x1E, vol=0x20, channel=0x02
	video type=1, offset=CINEMATIC_567, x=166, y=163
	video type=1, offset=CINEMATIC_566, x=178, y=117
	break
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_567, x=165, y=165
	selectVideoPage 0xFF
	video type=1, offset=CINEMATIC_566, x=178, y=110
	mov [0xE6], 0x000A

DELAY_LOOP_VARE6:
	break
	djnz [0xE6], DELAY_LOOP_VARE6
	video type=1, offset=CINEMATIC_568, x=155, y=98
	break
	video type=1, offset=CINEMATIC_568, x=155, y=100
	break
	video type=1, offset=CINEMATIC_568, x=155, y=102
	mov [0xE6], 0x000A

LABEL_0524:
	break
	video type=1, offset=CINEMATIC_568, x=155, y=103
	djnz [0xE6], LABEL_0524
	break
	video type=1, offset=CINEMATIC_568, x=155, y=100
	break
	video type=1, offset=CINEMATIC_568, x=155, y=97
	mov [0xE6], 0x000A

DELAY_LOOP_VARE6_AT_053B:
	break
	djnz [0xE6], DELAY_LOOP_VARE6_AT_053B
	video type=1, offset=CINEMATIC_569, x=159, y=50
	break
	video type=1, offset=CINEMATIC_570, x=159, y=55
	break
	video type=1, offset=CINEMATIC_571, x=159, y=65
	break
	video type=1, offset=CINEMATIC_570, x=159, y=85
	break
	video type=1, offset=CINEMATIC_569, x=159, y=92
	break
	video type=1, offset=CINEMATIC_570, x=159, y=92
	break
	video type=1, offset=CINEMATIC_571, x=159, y=92

LABEL_0562:
	break
	video type=1, offset=CINEMATIC_572, x=159, y=92
	jl [0x01], 0xAA, LABEL_0562
	deleteChannels first=0x14, last=0x16
	setup channel=0x36, address=LABEL_0627
	break
	video type=1, offset=CINEMATIC_572, x=159, y=92
	mov [HERO_ACTION], 0x0000
	jge [0x04], 0x4000, LABEL_0589
	video type=1, offset=CINEMATIC_578, x=180, y=176

LABEL_0589:
	break
	mov [HERO_ACTION], 0x0000
	video type=1, offset=CINEMATIC_572, x=159, y=92
	jge [0x04], 0x4000, LABEL_059D
	video type=1, offset=CINEMATIC_577, x=180, y=176

LABEL_059D:
	break
	video type=1, offset=CINEMATIC_572, x=159, y=92
	jge [0x04], 0x4000, LABEL_05AD
	video type=1, offset=CINEMATIC_576, x=180, y=176

LABEL_05AD:
	break
	video type=1, offset=CINEMATIC_572, x=159, y=92
	jge [0x04], 0x4000, LABEL_05BD
	video type=1, offset=CINEMATIC_575, x=179, y=176

LABEL_05BD:
	break
	video type=1, offset=CINEMATIC_572, x=159, y=90
	jge [0x04], 0x4000, LABEL_05CD
	video type=1, offset=CINEMATIC_574, x=178, y=175

LABEL_05CD:
	break
	video type=1, offset=CINEMATIC_572, x=159, y=80
	jge [0x04], 0x4000, LABEL_05E5
	video type=1, offset=CINEMATIC_573, x=179, y=170
	mov [0x02], 0x0064
	mov [0x32], 0x0009

LABEL_05E5:
	mov [0xE6], 0x0008
	mov [0xE7], 0x0050
	mov [0xE8], 0x00AA
	mov [HERO_ACTION], 0x0000

LABEL_05F5:
	break
	sub [0xE7], 0x0008
	sub [0xE8], 0x0008
	video type=1, offset=CINEMATIC_572, x=159, y=[0xe7], zoom=0x40
	jge [0x04], 0x4000, LABEL_060F
	video type=1, offset=CINEMATIC_573, x=179, y=[0xe8], zoom=0x40

LABEL_060F:
	djnz [0xE6], LABEL_05F5
	jge [0x04], 0x4000, KILL_CHAN_AT_01FB
	mov [0x00], 0x0040
	bankSwitch 6;  Secret Code Entry Screen
	killChannel
	mov [0x02], 0xFFB0
	killChannel

LABEL_0627:
	jge [0x04], 0x4000, KILL_CHAN_AT_01FB
	deleteChannels first=0x14, last=0x16
	killChannel

LABEL_0633:
	video type=1, offset=CINEMATIC_459, x=179, y=31
	video type=1, offset=CINEMATIC_459, x=179, y=62
	video type=1, offset=CINEMATIC_459, x=179, y=93
	break
	jmp LABEL_0633
LABEL_0643:
	db 0x11

LABEL_0644:
	video type=1, offset=CINEMATIC_627, x=2, y=186
	video type=1, offset=CINEMATIC_627, x=2, y=195
	break
	video type=1, offset=CINEMATIC_627, x=2, y=185
	video type=1, offset=CINEMATIC_627, x=2, y=194
	break
	video type=1, offset=CINEMATIC_445, x=3, y=184
	video type=1, offset=CINEMATIC_628, x=3, y=185
	video type=1, offset=CINEMATIC_627, x=2, y=193
	break
	video type=1, offset=CINEMATIC_628, x=3, y=184
	video type=1, offset=CINEMATIC_627, x=2, y=192
	break
	video type=1, offset=CINEMATIC_627, x=2, y=191
	video type=1, offset=CINEMATIC_627, x=2, y=200, zoom=0x40
	break
	video type=1, offset=CINEMATIC_627, x=2, y=190
	video type=1, offset=CINEMATIC_627, x=2, y=199
	break
	video type=1, offset=CINEMATIC_627, x=2, y=189
	video type=1, offset=CINEMATIC_627, x=2, y=198
	break
	video type=1, offset=CINEMATIC_627, x=2, y=188
	video type=1, offset=CINEMATIC_627, x=2, y=197
	break
	video type=1, offset=CINEMATIC_627, x=2, y=187
	video type=1, offset=CINEMATIC_627, x=2, y=196
	break
	jmp LABEL_0644
LABEL_069D:
	db 0x11
