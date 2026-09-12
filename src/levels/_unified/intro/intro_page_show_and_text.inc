.if BRANCH == "chahi_amiga_1991"
CINEMATIC_382		EQU 0xE7FE
CINEMATIC_383		EQU 0xE92E
CINEMATIC_384		EQU 0xEA92
CINEMATIC_419		EQU 0xE950
CINEMATIC_420		EQU 0xE692
CINEMATIC_421		EQU 0xE6FA
CINEMATIC_422		EQU 0xE752
CINEMATIC_423		EQU 0xE7AE
CINEMATIC_424		EQU 0xE772
CINEMATIC_425		EQU 0xE448
CINEMATIC_426		EQU 0xE4D6
CINEMATIC_427		EQU 0xE546
CINEMATIC_428		EQU 0xE3E4
CINEMATIC_517		EQU 0x4306
CINEMATIC_518		EQU 0x431E
CINEMATIC_LESTER_IN_BIOMETRIC_SCANNER		EQU 0x4982
CINEMATIC_LAB_AUTH_CRT_SHOWING_BIOMETRICS		EQU 0x4ABA
.else
CINEMATIC_382		EQU 0xE75C
CINEMATIC_383		EQU 0xE770
CINEMATIC_384		EQU 0xE8A0
CINEMATIC_419		EQU 0xE8E6
CINEMATIC_420		EQU 0xE8C2
CINEMATIC_421		EQU 0xE604
CINEMATIC_422		EQU 0xE66C
CINEMATIC_423		EQU 0xE6C4
CINEMATIC_424		EQU 0xE720
CINEMATIC_425		EQU 0xE6E4
CINEMATIC_426		EQU 0xE3BA
CINEMATIC_427		EQU 0xE448
CINEMATIC_428		EQU 0xE4B8
CINEMATIC_517		EQU 0xAF34
CINEMATIC_518		EQU 0xB000
CINEMATIC_LESTER_IN_BIOMETRIC_SCANNER		EQU 0x48F4
CINEMATIC_LAB_AUTH_CRT_SHOWING_BIOMETRICS		EQU 0x4A2C
.endif

SHOW_PAGE_0_LOOP_INTRO:
	selectVideoPage 0x00
	break
	jmp SHOW_PAGE_0_LOOP_INTRO
LABEL_158C:
.if BRANCH == "dos_1992"
	db 0x11
.else
.if BRANCH == "chahi_amiga_1991"
	db 0x11
.else
	killChannel
.endif
.endif

SHOW_PAGE_FF_LOOP_INTRO:
	selectVideoPage 0xFF
	break
	jmp SHOW_PAGE_FF_LOOP_INTRO
LABEL_1593:
.if BRANCH == "dos_1992"
	db 0x11
.else
.if BRANCH == "chahi_amiga_1991"
	db 0x11
.else
	killChannel
.endif
.endif

INIT_VAR_03_AND_LOOP:
	mov [0x03], 0x000A

SHOW_TEXT_39_AT_5_170_10X:
	break
	text id=0x0039, x=5, y=170, color=0x06
	djnz [0x03], SHOW_TEXT_39_AT_5_170_10X
	mov [0x03], 0x0008

INTRO_TEXT_39_REST_8X:
	break
	djnz [0x03], INTRO_TEXT_39_REST_8X
	jmp INIT_VAR_03_AND_LOOP
LABEL_15AF:
.if BRANCH == "dos_1992"
	db 0x11
.else
.if BRANCH == "chahi_amiga_1991"
	db 0x11
.else
	killChannel
.endif
.endif

DISPLAY_TEXT_21:
	break
	text id=0x0021, x=5, y=150, color=0x06
	break
	text id=0x0021, x=6, y=150, color=0x06
	break
	text id=0x0021, x=7, y=150, color=0x06
	break
	text id=0x0021, x=7, y=150, color=0x06
	break
	text id=0x0021, x=9, y=150, color=0x06
	break
	text id=0x0021, x=10, y=150, color=0x06
	break
	text id=0x0021, x=10, y=150, color=0x06
	break
	text id=0x0021, x=11, y=150, color=0x06
	break
	text id=0x0021, x=12, y=150, color=0x06
	break
	text id=0x0021, x=12, y=150, color=0x06
	break
	text id=0x0021, x=13, y=150, color=0x06
	break
	text id=0x0021, x=14, y=150, color=0x06
	break
	text id=0x0021, x=15, y=150, color=0x06
	break
	mov [0x02], 0x000A

SHOW_TEXT_21_AT_17_150_10X:
	text id=0x0021, x=17, y=150, color=0x06
	break
	djnz [0x02], SHOW_TEXT_21_AT_17_150_10X
	selectVideoPage 0x00
	text id=0x0021, x=3, y=158, color=0x06
	selectVideoPage 0xFF
	killChannel

DISPLAY_TEXT_0A_0B_PLAY_FX:
	text id=0x000A, x=3, y=150, color=0x06
	text id=0x000B, x=4, y=150, color=0x06
	play id=0x0033, freq=0x14, vol=0x3F, channel=0x02
	break
	text id=0x000C, x=5, y=150, color=0x06
	play id=0x0033, freq=0x11, vol=0x3F, channel=0x02
	break
	break
	break
	text id=0x000D, x=7, y=150, color=0x06
	text id=0x000E, x=8, y=150, color=0x06
	play id=0x0033, freq=0x14, vol=0x3F, channel=0x02
	break
	text id=0x000F, x=9, y=150, color=0x06
	play id=0x0033, freq=0x14, vol=0x3F, channel=0x02
	break
	break
	text id=0x0010, x=10, y=150, color=0x06
	play id=0x0033, freq=0x16, vol=0x3F, channel=0x02
	break
	text id=0x0011, x=11, y=150, color=0x06
	play id=0x0033, freq=0x15, vol=0x3F, channel=0x02
	break
	break
	text id=0x0012, x=12, y=150, color=0x06
	play id=0x0033, freq=0x14, vol=0x3F, channel=0x02
	break
	text id=0x0013, x=13, y=150, color=0x06
	play id=0x0033, freq=0x15, vol=0x3F, channel=0x02
	break
	break
	text id=0x0003, x=15, y=150, color=0x06
	text id=0x0004, x=16, y=150, color=0x06
	play id=0x0033, freq=0x14, vol=0x3F, channel=0x02
	killChannel

DRAW_CITY_SEQ_419_420:
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_LESTER_HEAD_SIDEWAYS_AMIGA_EXTRA, x=160, y=100
.else
	video offset=CINEMATIC_419, x=160, y=100
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_419, x=160, y=100
.else
	video offset=CINEMATIC_420, x=160, y=100
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_420, x=160, y=100
	video offset=CINEMATIC_421, x=19, y=8
	video offset=CINEMATIC_422, x=21, y=8
	video offset=CINEMATIC_423, x=104, y=92
.else
	video offset=CINEMATIC_421, x=160, y=100
	video offset=CINEMATIC_422, x=19, y=8
	video offset=CINEMATIC_423, x=21, y=8
	video offset=CINEMATIC_424, x=104, y=92
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_421, x=19, y=93
	video offset=CINEMATIC_424, x=18, y=93
	video offset=CINEMATIC_423, x=104, y=7
.else
	video offset=CINEMATIC_422, x=19, y=93
	video offset=CINEMATIC_425, x=18, y=93
	video offset=CINEMATIC_424, x=104, y=7
.endif
	killChannel
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_185, x=162, y=100
.else
	video offset=CINEMATIC_HOLO_ACCELERATOR_LOOP_DIAGRAM, x=162, y=100
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_186, x=234, y=163
.else
	video offset=CINEMATIC_192, x=234, y=163
.endif
	killChannel

CIN_382_PUFFS_PHASE_INIT:
	mov [0x02], 0x0002

DRAW_CIN_382_PUFFS_2X:
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_381, x=165, y=74
.else
	video offset=CINEMATIC_382, x=165, y=74
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_381, x=178, y=43
.else
	video offset=CINEMATIC_382, x=178, y=43
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_381, x=202, y=22
.else
	video offset=CINEMATIC_382, x=202, y=22
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_381, x=235, y=16
.else
	video offset=CINEMATIC_382, x=235, y=16
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_381, x=267, y=27
.else
	video offset=CINEMATIC_382, x=267, y=27
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_381, x=289, y=52
.else
	video offset=CINEMATIC_382, x=289, y=52
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_381, x=296, y=83
.else
	video offset=CINEMATIC_382, x=296, y=83
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_381, x=287, y=113
.else
	video offset=CINEMATIC_382, x=287, y=113
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_381, x=264, y=136
.else
	video offset=CINEMATIC_382, x=264, y=136
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_381, x=225, y=145
.else
	video offset=CINEMATIC_382, x=225, y=145
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_381, x=189, y=130
.else
	video offset=CINEMATIC_382, x=189, y=130
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_381, x=170, y=104
.else
	video offset=CINEMATIC_382, x=170, y=104
.endif
	djnz [0x02], DRAW_CIN_382_PUFFS_2X
	mov [0x02], 0x0003

DRAW_CIN_382_PUFFS_3X:
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_381, x=165, y=74
.else
	video offset=CINEMATIC_382, x=165, y=74
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_381, x=193, y=28
.else
	video offset=CINEMATIC_382, x=193, y=28
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_381, x=255, y=20
.else
	video offset=CINEMATIC_382, x=255, y=20
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_381, x=293, y=61
.else
	video offset=CINEMATIC_382, x=293, y=61
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_381, x=287, y=114
.else
	video offset=CINEMATIC_382, x=287, y=114
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_381, x=236, y=145
.else
	video offset=CINEMATIC_382, x=236, y=145
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_381, x=185, y=127
.else
	video offset=CINEMATIC_382, x=185, y=127
.endif
	djnz [0x02], DRAW_CIN_382_PUFFS_3X
.if BRANCH != "chahi_amiga_1991"
	setup channel=0x3C, address=BLIT_AND_COPY_PAGE_FF_LOOP
.endif
	selectVideoPage 0x00
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_382, x=237, y=156
.else
	video offset=CINEMATIC_383, x=237, y=156
.endif
	selectVideoPage 0xFF
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_381, x=165, y=74
.else
	video offset=CINEMATIC_382, x=165, y=74
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_381, x=233, y=15
.else
	video offset=CINEMATIC_382, x=233, y=15
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_381, x=296, y=84
.else
	video offset=CINEMATIC_382, x=296, y=84
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_381, x=249, y=148
.else
	video offset=CINEMATIC_382, x=249, y=148
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_383, x=237, y=156
	video offset=CINEMATIC_383, x=287, y=150, zoom=[0x14]	;@enc=alt
.else
	video offset=CINEMATIC_384, x=237, y=156
	video offset=CINEMATIC_384, x=287, y=150, zoom=[0x14]	;@enc=alt
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_383, x=287, y=150
.else
	video offset=CINEMATIC_384, x=287, y=150
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_383, x=287, y=150, zoom=[0x78]	;@enc=alt
.else
	video offset=CINEMATIC_384, x=287, y=150, zoom=[0x78]	;@enc=alt
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_383, x=287, y=150, zoom=[0xbe]	;@enc=alt
.else
	video offset=CINEMATIC_384, x=287, y=150, zoom=[0xbe]	;@enc=alt
.endif
	killChannel

INIT_VAR_02_AND_BREAK_LOOP:
	break
	mov [0x02], 0x0012

BLINK_TEXTS_14_15_AT_10_150_18X:
	text id=0x0014, x=10, y=150, color=0x05
	break
	text id=0x0015, x=10, y=150, color=0x05
	break
	text id=0x0016, x=9, y=150, color=0x05
	break
	text id=0x0017, x=11, y=150, color=0x05
	break
	text id=0x0018, x=10, y=150, color=0x05
	break
	djnz [0x02], BLINK_TEXTS_14_15_AT_10_150_18X
	killChannel

DRAW_CIN_382_TWICE_AT_DIFF_Y:
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_381, x=164, y=123
.else
	video offset=CINEMATIC_382, x=164, y=123
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_381, x=164, y=118
.else
	video offset=CINEMATIC_382, x=164, y=118
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_381, x=164, y=110
.else
	video offset=CINEMATIC_382, x=164, y=110
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_381, x=164, y=99
.else
	video offset=CINEMATIC_382, x=164, y=99
.endif
	mov [0x02], 0x0001

DRAW_CIN_382_PUFFS_1X:
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_381, x=165, y=74
.else
	video offset=CINEMATIC_382, x=165, y=74
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_381, x=170, y=55
.else
	video offset=CINEMATIC_382, x=170, y=55
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_381, x=180, y=41
.else
	video offset=CINEMATIC_382, x=180, y=41
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_381, x=191, y=29
.else
	video offset=CINEMATIC_382, x=191, y=29
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_381, x=206, y=20
.else
	video offset=CINEMATIC_382, x=206, y=20
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_381, x=224, y=15
.else
	video offset=CINEMATIC_382, x=224, y=15
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_381, x=246, y=16
.else
	video offset=CINEMATIC_382, x=246, y=16
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_381, x=263, y=24
.else
	video offset=CINEMATIC_382, x=263, y=24
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_381, x=278, y=36
.else
	video offset=CINEMATIC_382, x=278, y=36
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_381, x=288, y=49
.else
	video offset=CINEMATIC_382, x=288, y=49
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_381, x=294, y=66
.else
	video offset=CINEMATIC_382, x=294, y=66
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_381, x=297, y=82
.else
	video offset=CINEMATIC_382, x=297, y=82
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_381, x=293, y=101
.else
	video offset=CINEMATIC_382, x=293, y=101
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_381, x=284, y=117
.else
	video offset=CINEMATIC_382, x=284, y=117
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_381, x=271, y=131
.else
	video offset=CINEMATIC_382, x=271, y=131
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_381, x=256, y=141
.else
	video offset=CINEMATIC_382, x=256, y=141
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_381, x=237, y=145
.else
	video offset=CINEMATIC_382, x=237, y=145
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_381, x=217, y=144
.else
	video offset=CINEMATIC_382, x=217, y=144
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_381, x=200, y=138
.else
	video offset=CINEMATIC_382, x=200, y=138
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_381, x=184, y=127
.else
	video offset=CINEMATIC_382, x=184, y=127
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_381, x=173, y=112
.else
	video offset=CINEMATIC_382, x=173, y=112
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_381, x=167, y=94
.else
	video offset=CINEMATIC_382, x=167, y=94
.endif
	djnz [0x02], DRAW_CIN_382_PUFFS_1X
	jmp CIN_382_PUFFS_PHASE_INIT
LABEL_185D:
.if BRANCH == "dos_1992"
	db 0x11
.else
.if BRANCH == "chahi_amiga_1991"
	db 0x11
.else
	killChannel
.endif
.endif

DRAW_CIN_426_427_TWICE:
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_425, x=58, y=100
	video offset=CINEMATIC_426, x=292, y=100
.else
	video offset=CINEMATIC_426, x=58, y=100
	video offset=CINEMATIC_427, x=292, y=100
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_426, x=58, y=100
	video offset=CINEMATIC_427, x=292, y=100
.else
	video offset=CINEMATIC_427, x=58, y=100
	video offset=CINEMATIC_428, x=292, y=100
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_427, x=58, y=100
	video offset=CINEMATIC_425, x=292, y=100
.else
	video offset=CINEMATIC_428, x=58, y=100
	video offset=CINEMATIC_426, x=292, y=100
.endif
	break
	jmp DRAW_CIN_426_427_TWICE
LABEL_187F:
.if BRANCH == "dos_1992"
	db 0x11
.else
.if BRANCH == "chahi_amiga_1991"
	db 0x11
.else
	killChannel
.endif
.endif

FILL_FF_8_AND_DRAW_CIN_517_518:
	fill page=0xFF, color=0x08
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_LESTER_WALKING_AWAY_FROM_CAMERA_F2, x=160, y=100
	video offset=CINEMATIC_LESTER_WALKING_AWAY_FROM_CAMERA_F3_AMIGA_EXTRA, x=160, y=100
.else
	video offset=CINEMATIC_517, x=160, y=100
	video offset=CINEMATIC_518, x=160, y=100
.endif
	video offset=CINEMATIC_LESTER_IN_BIOMETRIC_SCANNER, x=110, y=101
	video offset=CINEMATIC_LAB_AUTH_CRT_SHOWING_BIOMETRICS, x=228, y=85
.if BRANCH != "chahi_amiga_1991"
	je [0xDB], 0x00, IF_DB_ZERO_SWAP_PAGE_PAL_11
	video offset=CINEMATIC_352, x=128, y=30

IF_DB_ZERO_SWAP_PAGE_PAL_11:
.endif
	copyVideoPage src=0xFF, dst=0x00
	setPalette 0x11
	killChannel

