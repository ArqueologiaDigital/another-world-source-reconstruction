LABEL_74A2:
	jne [0x06], 0x00, LABEL_74AE
	video offset=CINEMATIC_595, x=[0x03], y=[0x04], zoom=0x40
	ret

LABEL_74AE:
	jne [0x06], 0x01, LABEL_74BA
	video offset=CINEMATIC_594, x=[0x03], y=[0x04], zoom=0x40
	ret

LABEL_74BA:
	jne [0x06], 0x02, LABEL_74C6
	video offset=CINEMATIC_593, x=[0x03], y=[0x04], zoom=0x40
	ret

LABEL_74C6:
	jne [0x06], 0x03, LABEL_74D2
	video offset=CINEMATIC_592, x=[0x03], y=[0x04], zoom=0x40
	ret

LABEL_74D2:
	jne [0x06], 0x04, LABEL_74DE
	video offset=CINEMATIC_591, x=[0x03], y=[0x04], zoom=0x40
	ret

LABEL_74DE:
	jne [0x06], 0x05, LABEL_74EA
	video offset=CINEMATIC_590, x=[0x03], y=[0x04], zoom=0x40
	ret

LABEL_74EA:
	jne [0x06], 0x06, LABEL_74F6
	video offset=CINEMATIC_589, x=[0x03], y=[0x04], zoom=0x40
	ret

LABEL_74F6:
	jl [0x06], 0x07, LABEL_7502
	video offset=CINEMATIC_588, x=[0x03], y=[0x04], zoom=0x40
	ret

LABEL_7502:
	jne [0x06], 0xFFFF, LABEL_750F
	video offset=CINEMATIC_587, x=[0x03], y=[0x04], zoom=0x40
	ret

LABEL_750F:
	jne [0x06], 0xFFFE, LABEL_751C
	video offset=CINEMATIC_586, x=[0x03], y=[0x04], zoom=0x40
	ret

LABEL_751C:
	jne [0x06], 0xFFFD, LABEL_7529
	video offset=CINEMATIC_585, x=[0x03], y=[0x04], zoom=0x40
	ret

LABEL_7529:
	jne [0x06], 0xFFFC, LABEL_7536
	video offset=CINEMATIC_584, x=[0x03], y=[0x04], zoom=0x40
	ret

LABEL_7536:
	jne [0x06], 0xFFFB, LABEL_7543
	video offset=CINEMATIC_583, x=[0x03], y=[0x04], zoom=0x40
	ret

LABEL_7543:
	jne [0x06], 0xFFFA, DRAW_CIN_581
	video offset=CINEMATIC_582, x=[0x03], y=[0x04], zoom=0x40
	ret

DRAW_CIN_581:
	video offset=CINEMATIC_581, x=[0x03], y=[0x04], zoom=0x40
	ret
	killChannel
	jne [0x06], 0x00, LABEL_7563
	video offset=CINEMATIC_079, x=[0x03], y=[0x04], zoom=0x40
	ret

LABEL_7563:
	jne [0x06], 0x01, DRAW_CIN_055_AT_756F
	video offset=CINEMATIC_076, x=[0x03], y=[0x04], zoom=0x40
	ret

DRAW_CIN_055_AT_756F:
	video offset=CINEMATIC_055, x=[0x03], y=[0x04], zoom=0x40
	ret
LABEL_7575:
	db 0x11

LABEL_7576:
	jne [0x06], 0x00, LABEL_7587
	video offset=CINEMATIC_078, x=[0x03], y=[0x04], zoom=0x40
	video offset=CINEMATIC_079, x=[0x03], y=[0x04], zoom=0x40
	ret

LABEL_7587:
	jne [0x06], 0x01, LABEL_75A6
	jg [0x14], 0x00, LABEL_759B
	video offset=CINEMATIC_077, x=[0x03], y=[0x04], zoom=0x40
	jmp DRAW_CIN_076

LABEL_759B:
	video offset=CINEMATIC_075, x=[0x03], y=[0x04], zoom=0x40

DRAW_CIN_076:
	video offset=CINEMATIC_076, x=[0x03], y=[0x04], zoom=0x40
	ret

LABEL_75A6:
	jne [0x06], 0x02, LABEL_75C5
	jg [0x14], 0x00, LABEL_75BA
	video offset=CINEMATIC_074, x=[0x03], y=[0x04], zoom=0x40
	jmp DRAW_CIN_073

LABEL_75BA:
	video offset=CINEMATIC_072, x=[0x03], y=[0x04], zoom=0x40

DRAW_CIN_073:
	video offset=CINEMATIC_073, x=[0x03], y=[0x04], zoom=0x40
	ret

LABEL_75C5:
	jne [0x06], 0x03, LABEL_75E4
	jg [0x14], 0x00, LABEL_75D9
	video offset=CINEMATIC_071, x=[0x03], y=[0x04], zoom=0x40
	jmp DRAW_CIN_070

LABEL_75D9:
	video offset=CINEMATIC_069, x=[0x03], y=[0x04], zoom=0x40

DRAW_CIN_070:
	video offset=CINEMATIC_070, x=[0x03], y=[0x04], zoom=0x40
	ret

LABEL_75E4:
	jne [0x06], 0x04, LABEL_7603
	jg [0x14], 0x00, LABEL_75F8
	video offset=CINEMATIC_068, x=[0x03], y=[0x04], zoom=0x40
	jmp DRAW_CIN_067

LABEL_75F8:
	video offset=CINEMATIC_066, x=[0x03], y=[0x04], zoom=0x40

DRAW_CIN_067:
	video offset=CINEMATIC_067, x=[0x03], y=[0x04], zoom=0x40
	ret

LABEL_7603:
	jne [0x06], 0x05, LABEL_7622
	jg [0x14], 0x00, LABEL_7617
	video offset=CINEMATIC_065, x=[0x03], y=[0x04], zoom=0x40
	jmp DRAW_CIN_064

LABEL_7617:
	video offset=CINEMATIC_063, x=[0x03], y=[0x04], zoom=0x40

DRAW_CIN_064:
	video offset=CINEMATIC_064, x=[0x03], y=[0x04], zoom=0x40
	ret

LABEL_7622:
	jne [0x06], 0x06, LABEL_7641
	jg [0x14], 0x00, LABEL_7636
	video offset=CINEMATIC_062, x=[0x03], y=[0x04], zoom=0x40
	jmp DRAW_CIN_061

LABEL_7636:
	video offset=CINEMATIC_060, x=[0x03], y=[0x04], zoom=0x40

DRAW_CIN_061:
	video offset=CINEMATIC_061, x=[0x03], y=[0x04], zoom=0x40
	ret

LABEL_7641:
	jl [0x06], 0x07, LABEL_7660
	jg [0x14], 0x00, LABEL_7655
	video offset=CINEMATIC_059, x=[0x03], y=[0x04], zoom=0x40
	jmp DRAW_CIN_058

LABEL_7655:
	video offset=CINEMATIC_057, x=[0x03], y=[0x04], zoom=0x40

DRAW_CIN_058:
	video offset=CINEMATIC_058, x=[0x03], y=[0x04], zoom=0x40
	ret

LABEL_7660:
	jne [0x06], 0xFFFF, LABEL_7680
	jl [0x14], 0x00, LABEL_7675
	video offset=CINEMATIC_056, x=[0x03], y=[0x04], zoom=0x40
	jmp DRAW_CIN_055_AT_767A

LABEL_7675:
	video offset=CINEMATIC_054, x=[0x03], y=[0x04], zoom=0x40

DRAW_CIN_055_AT_767A:
	video offset=CINEMATIC_055, x=[0x03], y=[0x04], zoom=0x40
	ret

LABEL_7680:
	jne [0x06], 0xFFFE, LABEL_76A0
	jl [0x14], 0x00, LABEL_7695
	video offset=CINEMATIC_053, x=[0x03], y=[0x04], zoom=0x40
	jmp DRAW_CIN_052

LABEL_7695:
	video offset=CINEMATIC_051, x=[0x03], y=[0x04], zoom=0x40

DRAW_CIN_052:
	video offset=CINEMATIC_052, x=[0x03], y=[0x04], zoom=0x40
	ret

LABEL_76A0:
	jne [0x06], 0xFFFD, LABEL_76C0
	jl [0x14], 0x00, LABEL_76B5
	video offset=CINEMATIC_050, x=[0x03], y=[0x04], zoom=0x40
	jmp DRAW_CIN_049

LABEL_76B5:
	video offset=CINEMATIC_048, x=[0x03], y=[0x04], zoom=0x40

DRAW_CIN_049:
	video offset=CINEMATIC_049, x=[0x03], y=[0x04], zoom=0x40
	ret

LABEL_76C0:
	jne [0x06], 0xFFFC, LABEL_76E0
	jl [0x14], 0x00, LABEL_76D5
	video offset=CINEMATIC_047, x=[0x03], y=[0x04], zoom=0x40
	jmp DRAW_CIN_046

LABEL_76D5:
	video offset=CINEMATIC_045, x=[0x03], y=[0x04], zoom=0x40

DRAW_CIN_046:
	video offset=CINEMATIC_046, x=[0x03], y=[0x04], zoom=0x40
	ret

LABEL_76E0:
	jne [0x06], 0xFFFB, LABEL_7700
	jl [0x14], 0x00, LABEL_76F5
	video offset=CINEMATIC_044, x=[0x03], y=[0x04], zoom=0x40
	jmp DRAW_CIN_043

LABEL_76F5:
	video offset=CINEMATIC_042, x=[0x03], y=[0x04], zoom=0x40

DRAW_CIN_043:
	video offset=CINEMATIC_043, x=[0x03], y=[0x04], zoom=0x40
	ret

LABEL_7700:
	jne [0x06], 0xFFFA, LABEL_7720
	jl [0x14], 0x00, LABEL_7715
	video offset=CINEMATIC_041, x=[0x03], y=[0x04], zoom=0x40
	jmp DRAW_CIN_040

LABEL_7715:
	video offset=CINEMATIC_039, x=[0x03], y=[0x04], zoom=0x40

DRAW_CIN_040:
	video offset=CINEMATIC_040, x=[0x03], y=[0x04], zoom=0x40
	ret

LABEL_7720:
	jl [0x14], 0x00, LABEL_772E
	video offset=CINEMATIC_038, x=[0x03], y=[0x04], zoom=0x40
	jmp DRAW_CIN_037

LABEL_772E:
	video offset=CINEMATIC_036, x=[0x03], y=[0x04], zoom=0x40

DRAW_CIN_037:
	video offset=CINEMATIC_037, x=[0x03], y=[0x04], zoom=0x40
	ret

LABEL_7739:
	jg [0x16], 0x01, LABEL_7743
	mov [0x16], 0x0002

LABEL_7743:
	ret

LABEL_7744:
	jg [0x16], 0x00, LABEL_774E
	mov [0x16], 0x0000

LABEL_774E:
	ret

LABEL_774F:
	jg [0x15], 0x01, LABEL_7759
	mov [0x15], 0x0002

LABEL_7759:
	jl [0x15], 0x37, LABEL_7763
	mov [0x15], 0x0037

LABEL_7763:
	ret

LABEL_7764:
	jl [0x01], 0x1B, LABEL_7782
	add [0x21], 0x0001
	jl [0x01], 0x24, LABEL_7778
	add [0x21], 0x0001

LABEL_7778:
	jl [0x21], 0x00, LABEL_7782
	mov [0x21], 0x0000

LABEL_7782:
	ret

LABEL_7783:
	setup channel=0x14, address=LABEL_7788
	killChannel

LABEL_7788:
	mov [0x03], 0x00B5
	mov [0x04], 0x003C
	sub [0x04], 0x0006
	add [0x04], 0x0010
	sub [0x06], 0x0003
	song id=0x0BBE, delay=0x0000, pos=0x00
	call LABEL_73D7
	video offset=CINEMATIC_035, x=[0x1a], y=[0x1b], zoom=0x40
	call LABEL_7576
	break
	play id=0x0063, freq=0x14, vol=0x0A, channel=0x01
	setup channel=0x12, address=DRAW_CIN_576_578_BLOCK
	add [0x04], 0x0016
	sub [0x06], 0x0003
	call LABEL_73D7
	video offset=CINEMATIC_035, x=[0x1a], y=[0x1b], zoom=0x40
	call LABEL_7576
	deleteChannels first=0x21, last=0x24
	break
	add [0x04], 0x0020
	play id=0x0063, freq=0x14, vol=0x40, channel=0x01
	video offset=CINEMATIC_080, x=[0x03], y=[0x04], zoom=0x40
	break
	add [0x04], 0x0016
	setPalette 0x02
	video offset=CINEMATIC_081, x=[0x03], y=[0x04], zoom=0x40
	break
	play id=0x0064, freq=0x14, vol=0x40, channel=0x02
	selectVideoPage 0x00
	video offset=CINEMATIC_082, x=[0x03], y=[0x04], zoom=0x40
	selectVideoPage 0xFF
	call LABEL_1D30
	setup channel=0x11, address=LABEL_1FA0
	setup channel=0x34, address=HANG_DRAW_CIN_549
	setup channel=0x35, address=DRAW_CIN_540_543_WITH_SFX_57
	setup channel=0x15, address=SETUP_VARS_01_B0_02_B6_06_C7_28_FROM_01
	mov [PAUSE_SLICES], 0x0004
	video offset=CINEMATIC_083, x=[0x03], y=[0x04], zoom=0x40
	mov [0x1A], [0x03]
	mov [0x1B], [0x04]
	break
	video offset=CINEMATIC_084, x=[0x1a], y=[0x1b], zoom=0x40
	setup channel=0x14, address=LABEL_0607
	setup channel=0x22, address=LABEL_14B0
	setup channel=0x23, address=INLINE_SUB_VAR08_INIT_VAR29
	setup channel=0x24, address=LABEL_14D3
	setup channel=0x25, address=LABEL_267B
	setup channel=0x26, address=LABEL_150E
	setup channel=0x27, address=KILL_CHANNEL_LANDING
	setup channel=0x28, address=LABEL_1549
	setup channel=0x3A, address=KILL_CHANNEL_LANDING
	setup channel=0x3F, address=LABEL_897B
	call LABEL_0860
	call LABEL_884B
	mov [0x42], 0x00A0
	killChannel

DRAW_CIN_540_543_WITH_SFX_57:
	video offset=CINEMATIC_540, x=[0x1a], y=[0x1b], zoom=0x40
	video offset=CINEMATIC_541, x=[0x1a], y=[0x1b], zoom=0x40
	break
	play id=0x0057, freq=0x1C, vol=0x40, channel=0x02
	video offset=CINEMATIC_542, x=[0x1a], y=[0x1b], zoom=0x40
	video offset=CINEMATIC_543, x=[0x1a], y=[0x1b], zoom=0x40
	break
	video offset=CINEMATIC_544, x=[0x1a], y=[0x1b], zoom=0x40
	video offset=CINEMATIC_545, x=[0x1a], y=[0x1b], zoom=0x40
	break
	video offset=CINEMATIC_546, x=[0x1a], y=[0x1b], zoom=0x40
	break
	video offset=CINEMATIC_547, x=[0x1a], y=[0x1b], zoom=0x40
	break
	video offset=CINEMATIC_548, x=[0x1a], y=[0x1b], zoom=0x40
	break
	video offset=CINEMATIC_547, x=[0x1a], y=[0x1b], zoom=0x40
	break
	video offset=CINEMATIC_548, x=[0x1a], y=[0x1b], zoom=0x40
	killChannel

HANG_DRAW_CIN_549:
	video offset=CINEMATIC_549, x=181, y=146
	break
	jmp HANG_DRAW_CIN_549
LABEL_78A4:
	db 0x11

HANG_DRAW_CIN_275:
	video offset=CINEMATIC_275, x=181, y=146
	break
	jmp HANG_DRAW_CIN_275

LABEL_78AD:
	mov [0x17], 0x0005
	sub [0x15], 0x0001
	call LABEL_774F
	call LABEL_7764

LABEL_78BB:
	mov [0x16], [0x15]
	add [0x01], [0x16]
	break
	jg [0x01], 0x28, LABEL_78CC
	djnz [0x17], LABEL_78BB

LABEL_78CC:
	jl [0x01], 0x14, LABEL_78D8
	play id=0x0062, freq=0x23, vol=0x0F, channel=0x00

LABEL_78D8:
	mov [0x16], [0x15]
	sub [0x16], 0x0003
	call LABEL_7739
	add [0x01], [0x16]
	call LABEL_7764
	break
	sub [0x16], 0x0004
	call LABEL_7739
	add [0x01], [0x16]
	break
	sub [0x16], 0x0005
	call LABEL_7744
	add [0x01], [0x16]
	break
	sub [0x16], 0x0006
	call LABEL_7744
	add [0x01], [0x16]
	jl [0x15], 0x28, LABEL_7914
	break
	add [0x01], 0x000C

LABEL_7914:
	break
	mov [0x18], 0x0001
	mov [0x18], 0x0001
	sub [0x01], 0x0006
	break
	jge [0x15], 0x2C, LABEL_7783

LABEL_7928:
	mov [0x16], [0x15]
	add [0x16], 0x0001
	sub [0x01], [0x16]
	break
	jg [0x01], 0x00, LABEL_7928

LABEL_7939:
	mov [0x17], 0x0005
	sub [0x15], 0x0001
	call LABEL_774F
	call LABEL_7764

LABEL_7947:
	mov [0x16], [0x15]
	sub [0x01], [0x16]
	break
	jl [0x01], 0xFFD8, LABEL_7959
	djnz [0x17], LABEL_7947

LABEL_7959:
	jg [0x01], 0xFFEC, LABEL_7973
	play id=0x0062, freq=0x14, vol=0x0F, channel=0x00
	jg [0x01], 0xFFD3, LABEL_7973
	play id=0x0063, freq=0x14, vol=0x20, channel=0x03

LABEL_7973:
	mov [0x16], [0x15]
	sub [0x16], 0x0003
	call LABEL_7739
	sub [0x01], [0x16]
	break
	sub [0x16], 0x0004
	call LABEL_7739
	sub [0x01], [0x16]
	break
	sub [0x16], 0x0005
	call LABEL_7744
	sub [0x01], [0x16]
	break
	sub [0x16], 0x0006
	call LABEL_7744
	sub [0x01], [0x16]
	jl [0x15], 0x28, LABEL_79AC
	break
	sub [0x01], 0x000C

LABEL_79AC:
	break
	mov [0x18], 0x0000
	mov [0x18], 0x0000
	add [0x01], 0x0006
	call LABEL_7764
	break

LABEL_79BD:
	mov [0x16], [0x15]
	add [0x16], 0x0001
	add [0x01], [0x16]
	break
	jl [0x01], 0x00, LABEL_79BD
	jmp LABEL_78AD
	killChannel
	call LABEL_7222
	call LABEL_73D7
	video offset=CINEMATIC_035, x=[0x1a], y=[0x1b], zoom=0x40
	call LABEL_74A2
	ret
