DRAW_CINEMATIC_005_LOOP:
	video type=1, offset=CINEMATIC_005, x=90, y=101
	break
	jmp DRAW_CINEMATIC_005_LOOP
LABEL_22EC:
	killChannel

INTRO_SCENE_INIT_PARTICLES:
	selectVideoPage 0x00
	fill page=0x00, color=0x02
	setPalette 0x01
	video type=1, offset=CINEMATIC_535, x=192, y=59
	video type=1, offset=CINEMATIC_535, x=45, y=50
	video type=1, offset=CINEMATIC_536, x=247, y=108
	video type=1, offset=CINEMATIC_537, x=171, y=100
	video type=1, offset=CINEMATIC_538, x=275, y=44, zoom=0x40
	video type=1, offset=CINEMATIC_539, x=268, y=79, zoom=0x40
	video type=1, offset=CINEMATIC_540, x=297, y=91, zoom=0x40
	video type=1, offset=CINEMATIC_541, x=251, y=98
	video type=1, offset=CINEMATIC_542, x=309, y=96, zoom=0x40
	video type=1, offset=CINEMATIC_543, x=284, y=101, zoom=0x40
	video type=1, offset=CINEMATIC_544, x=357, y=119, zoom=0x40
	video type=1, offset=CINEMATIC_545, x=190, y=143
	video type=1, offset=CINEMATIC_546, x=19, y=78
	video type=1, offset=CINEMATIC_547, x=160, y=78
	video type=1, offset=CINEMATIC_548, x=196, y=94
	video type=1, offset=CINEMATIC_548, x=61, y=94
	video type=1, offset=CINEMATIC_549, x=161, y=96
	video type=1, offset=CINEMATIC_550, x=244, y=78
	video type=1, offset=CINEMATIC_551, x=245, y=78
	video type=1, offset=CINEMATIC_552, x=245, y=78
	video type=1, offset=CINEMATIC_553, x=29, y=32
	video type=1, offset=CINEMATIC_554, x=194, y=43
	video type=1, offset=CINEMATIC_555, x=75, y=120
	video type=1, offset=CINEMATIC_556, x=89, y=123
	video type=1, offset=CINEMATIC_556, x=105, y=123
	video type=1, offset=CINEMATIC_556, x=180, y=123
	video type=1, offset=CINEMATIC_556, x=181, y=123
	video type=1, offset=CINEMATIC_555, x=210, y=120
	video type=1, offset=CINEMATIC_557, x=62, y=114
	video type=1, offset=CINEMATIC_558, x=45, y=121
	video type=1, offset=CINEMATIC_558, x=140, y=116
	video type=1, offset=CINEMATIC_558, x=63, y=126
	video type=1, offset=CINEMATIC_559, x=137, y=59
	video type=1, offset=CINEMATIC_559, x=103, y=121
	video type=1, offset=CINEMATIC_557, x=152, y=117
	video type=1, offset=CINEMATIC_559, x=42, y=117
	video type=1, offset=CINEMATIC_557, x=180, y=55
	video type=1, offset=CINEMATIC_559, x=19, y=113
	video type=1, offset=CINEMATIC_545, x=142, y=125
	video type=1, offset=CINEMATIC_545, x=11, y=126
	video type=1, offset=CINEMATIC_560, x=108, y=138
	video type=1, offset=CINEMATIC_561, x=208, y=114
	video type=1, offset=CINEMATIC_562, x=163, y=111
	video type=1, offset=CINEMATIC_563, x=221, y=91
	video type=1, offset=CINEMATIC_562, x=83, y=109
	video type=1, offset=CINEMATIC_564, x=251, y=116
	video type=1, offset=CINEMATIC_565, x=258, y=131, zoom=0x40
	video type=1, offset=CINEMATIC_566, x=2, y=26
	video type=1, offset=CINEMATIC_567, x=31, y=12
	video type=1, offset=CINEMATIC_568, x=32, y=169
	video type=1, offset=CINEMATIC_569, x=7, y=175
	killChannel

INTRO_PLAY_BG_AUDIO_LOOP:
	break
	play id=0x0008, freq=0x01, vol=0x2D, channel=0x03
	play id=0x0008, freq=0x05, vol=0x2D, channel=0x02
	mov [PAUSE_SLICES], 0x0004
; Frame-delay counter for the djnz loop below. [0x01] is a generic
; temp variable used here (and elsewhere in INTRO) as a "spin N
; frames" counter, combined with PAUSE_SLICES (=4 here) so each
; `break` yields 4 scheduler ticks. Total wait = 4 * counter.
;
; THIS one location alone differs between cart and gba — every
; other `mov [0x01], <N>` in INTRO uses the same N in both ports.
; Cart 0x12 = 18 (4*18 = 72 ticks); gba 0x24 = 36 (4*36 = 144 ticks,
; doubled). The preceding `play id=0x0008` is likely the trigger:
; the GBA port may need longer to sync the sound effect's end with
; the next animation cue (or just a tuning fix specific to this
; one moment in the game).
;@if BRANCH == "cartridge_1992"
	mov [0x01], 0x0012
;@elif BRANCH == "gba_2004"
	mov [0x01], 0x0024
;@endif

DELAY_BEFORE_PLAY_FX_9_DUAL:
	break
	djnz [0x01], DELAY_BEFORE_PLAY_FX_9_DUAL
	play id=0x0009, freq=0x14, vol=0x1E, channel=0x00
	play id=0x0009, freq=0x14, vol=0x3F, channel=0x01
	mov [PAUSE_SLICES], 0x0003
	video type=1, offset=CINEMATIC_006, x=158, y=100
	video type=1, offset=CINEMATIC_007, x=43, y=132, zoom=[0x7c]	;@raw=0x6A,0x04,0x9C,0x2B,0x84,0x7C
	video type=1, offset=CINEMATIC_007, x=392, y=136, zoom=[0x7c]	;@raw=0x7A,0x04,0x9C,0x88,0x88,0x7C
	break
	video type=1, offset=CINEMATIC_008, x=188, y=101
	video type=1, offset=CINEMATIC_007, x=125, y=107
	video type=1, offset=CINEMATIC_007, x=314, y=111, zoom=0x40
	break
	video type=1, offset=CINEMATIC_009, x=133, y=100
	video type=1, offset=CINEMATIC_010, x=189, y=99
	video type=1, offset=CINEMATIC_007, x=210, y=117, zoom=[0x20]	;@raw=0x6A,0x04,0x9C,0xD2,0x75,0x20
	video type=1, offset=CINEMATIC_007, x=339, y=118, zoom=[0x22]	;@raw=0x7A,0x04,0x9C,0x53,0x76,0x22
	break
	video type=1, offset=CINEMATIC_011, x=153, y=102
	video type=1, offset=CINEMATIC_012, x=188, y=100
	video type=1, offset=CINEMATIC_007, x=261, y=120, zoom=[0x1b]	;@raw=0x7A,0x04,0x9C,0x05,0x78,0x1B
	video type=1, offset=CINEMATIC_007, x=337, y=122, zoom=[0x1b]	;@raw=0x7A,0x04,0x9C,0x51,0x7A,0x1B
	break
	video type=1, offset=CINEMATIC_013, x=128, y=107
	video type=1, offset=CINEMATIC_014, x=188, y=100
	video type=1, offset=CINEMATIC_007, x=305, y=119, zoom=[0x17]	;@raw=0x7A,0x04,0x9C,0x31,0x77,0x17
	break
	video type=1, offset=CINEMATIC_015, x=188, y=101
	video type=1, offset=CINEMATIC_016, x=85, y=110
	video type=1, offset=CINEMATIC_007, x=327, y=120, zoom=[0x13]	;@raw=0x7A,0x04,0x9C,0x47,0x78,0x13
	break
	video type=1, offset=CINEMATIC_017, x=187, y=101
	video type=1, offset=CINEMATIC_018, x=64, y=114
	break
	video type=1, offset=CINEMATIC_019, x=212, y=96
	video type=1, offset=CINEMATIC_020, x=42, y=117
	break
	video type=1, offset=CINEMATIC_021, x=212, y=96
	video type=1, offset=CINEMATIC_022, x=49, y=119
	break
	video type=1, offset=CINEMATIC_023, x=211, y=96
	video type=1, offset=CINEMATIC_022, x=44, y=118
	break
	video type=1, offset=CINEMATIC_024, x=212, y=96
	video type=1, offset=CINEMATIC_025, x=45, y=120
	break
	video type=1, offset=CINEMATIC_026, x=212, y=96
	video type=1, offset=CINEMATIC_025, x=39, y=118
	break
	video type=1, offset=CINEMATIC_027, x=213, y=96
	video type=1, offset=CINEMATIC_028, x=40, y=120
	break
	video type=1, offset=CINEMATIC_029, x=216, y=100
	video type=1, offset=CINEMATIC_028, x=36, y=121
	break
	video type=1, offset=CINEMATIC_030, x=216, y=100
	video type=1, offset=CINEMATIC_031, x=42, y=120
	setup channel=0x3C, address=BLIT_AND_COPY_PAGE_FF_LOOP
	break
	setPalette 0x05
	mov [0x01], 0x0014
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_032, x=215, y=100
	copyVideoPage src=0x00, dst=0xFF
	selectVideoPage 0xFF
	mov [PAUSE_SLICES], 0x0002

DRAW_CIN_31_33_LOOP:
	video type=1, offset=CINEMATIC_031, x=42, y=120
	video type=1, offset=CINEMATIC_033, x=160, y=100
	break
	djnz [0x01], DRAW_CIN_31_33_LOOP
	setPalette 0x03
	mov [0x01], 0x001E

DRAW_CIN_034_30X_BEFORE_REPEAT:
	video type=1, offset=CINEMATIC_034, x=160, y=100
	break
	djnz [0x01], DRAW_CIN_034_30X_BEFORE_REPEAT
	jmp DRAW_CIN_035_PAL_3_REPEAT_HEAD
LABEL_24E5:
	killChannel

INTRO_PLAY_FX_AND_PALETTE_4_LOOP:
	break
	setPalette 0x04
	play id=0x000D, freq=0x14, vol=0x19, channel=0x02
	mov [PAUSE_SLICES], 0x0003
	mov [0x01], 0x0032
	break
	play id=0x003C, freq=0x14, vol=0x01, channel=0x01
	video type=1, offset=CINEMATIC_WALKING_FEET_ARRIVING_0, x=229, y=98
	break
	video type=1, offset=CINEMATIC_WALKING_FEET_ARRIVING_1, x=230, y=97
	break
	video type=1, offset=CINEMATIC_WALKING_FEET_ARRIVING_2, x=230, y=97
	break
	video type=1, offset=CINEMATIC_WALKING_FEET_ARRIVING_3, x=230, y=98
	break
	video type=1, offset=CINEMATIC_WALKING_FEET_ARRIVING_4, x=229, y=97
	break
	video type=1, offset=CINEMATIC_WALKING_FEET_ARRIVING_5, x=229, y=97
	play id=0x003C, freq=0x14, vol=0x3F, channel=0x00
	break
	video type=1, offset=CINEMATIC_WALKING_FEET_ARRIVING_6, x=230, y=97
	break
	video type=1, offset=CINEMATIC_WALKING_FEET_ARRIVING_7, x=229, y=98
	break
	video type=1, offset=CINEMATIC_WALKING_FEET_ARRIVING_8, x=230, y=97
	break
	video type=1, offset=CINEMATIC_WALKING_FEET_ARRIVING_9, x=231, y=98
	break
	video type=1, offset=CINEMATIC_WALKING_FEET_ARRIVING_10, x=230, y=97
	break
	video type=1, offset=CINEMATIC_WALKING_FEET_ARRIVING_11, x=231, y=98
	break
	video type=1, offset=CINEMATIC_WALKING_FEET_ARRIVING_12, x=231, y=97
	break
	video type=1, offset=CINEMATIC_WALKING_FEET_ARRIVING_13, x=232, y=97
	break
	video type=1, offset=CINEMATIC_WALKING_FEET_ARRIVING_14, x=232, y=97
	play id=0x003C, freq=0x0A, vol=0x3F, channel=0x00
	break
	video type=1, offset=CINEMATIC_WALKING_FEET_ARRIVING_15, x=231, y=97
	break
	video type=1, offset=CINEMATIC_WALKING_FEET_ARRIVING_16, x=232, y=97
	break
	video type=1, offset=CINEMATIC_WALKING_FEET_ARRIVING_17, x=232, y=97
	break
	video type=1, offset=CINEMATIC_WALKING_FEET_ARRIVING_18, x=231, y=98
	break
	video type=1, offset=CINEMATIC_WALKING_FEET_ARRIVING_19, x=230, y=97
	break
	video type=1, offset=CINEMATIC_WALKING_FEET_ARRIVING_20, x=226, y=96
	break
	video type=1, offset=CINEMATIC_WALKING_FEET_ARRIVING_21, x=230, y=96
	break
	video type=1, offset=CINEMATIC_WALKING_FEET_ARRIVING_22, x=230, y=96
	break
	play id=0x003C, freq=0x0F, vol=0x0F, channel=0x02
	video type=1, offset=CINEMATIC_WALKING_FEET_ARRIVING_23, x=230, y=96
	break
	video type=1, offset=CINEMATIC_WALKING_FEET_ARRIVING_24, x=230, y=96
	break
	video type=1, offset=CINEMATIC_WALKING_FEET_ARRIVING_25, x=230, y=96
	break
	video type=1, offset=CINEMATIC_WALKING_FEET_ARRIVING_26, x=230, y=96
	break
	video type=1, offset=CINEMATIC_WALKING_FEET_ARRIVING_27, x=230, y=96
	break
	video type=1, offset=CINEMATIC_WALKING_FEET_ARRIVING_28, x=230, y=96
	break
	video type=1, offset=CINEMATIC_WALKING_FEET_ARRIVING_29, x=230, y=96
	break
	video type=1, offset=CINEMATIC_WALKING_FEET_ARRIVING_30, x=230, y=96
	break
	video type=1, offset=CINEMATIC_WALKING_FEET_ARRIVING_31, x=230, y=96
	break
	video type=1, offset=CINEMATIC_WALKING_FEET_ARRIVING_32, x=230, y=96
	break
	video type=1, offset=CINEMATIC_WALKING_FEET_ARRIVING_33, x=230, y=96
	break
	video type=1, offset=CINEMATIC_WALKING_FEET_ARRIVING_34, x=230, y=96
	setup channel=0x3C, address=BLIT_AND_COPY_PAGE_FF_LOOP
	break
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_089, x=160, y=100
	video type=1, offset=CINEMATIC_090, x=160, y=100
	selectVideoPage 0xFF
	video type=1, offset=CINEMATIC_WALKING_FEET_ENTERING_0, x=230, y=96
	setup channel=0x3C, address=BLIT_AND_COPY_PAGE_FF_LOOP
	break
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_089, x=160, y=100
	selectVideoPage 0xFF
	video type=1, offset=CINEMATIC_WALKING_FEET_ENTERING_1, x=125, y=98
	break
	video type=1, offset=CINEMATIC_WALKING_FEET_ENTERING_2, x=125, y=98
	break
	video type=1, offset=CINEMATIC_WALKING_FEET_ENTERING_3, x=125, y=98
	break
	video type=1, offset=CINEMATIC_WALKING_FEET_ENTERING_4, x=125, y=98
	break
	mov [PAUSE_SLICES], 0x0002
	video type=1, offset=CINEMATIC_WALKING_FEET_ENTERING_5, x=125, y=98
	break
	video type=1, offset=CINEMATIC_WALKING_FEET_ENTERING_6, x=125, y=98
	break
	video type=1, offset=CINEMATIC_WALKING_FEET_ENTERING_7, x=125, y=98
	break
	video type=1, offset=CINEMATIC_WALKING_FEET_ENTERING_8, x=125, y=98
	break
	video type=1, offset=CINEMATIC_WALKING_FEET_ENTERING_9, x=125, y=98
	play id=0x003C, freq=0x0A, vol=0x14, channel=0x02
	break
	video type=1, offset=CINEMATIC_WALKING_FEET_ENTERING_10, x=125, y=98
	break
	video type=1, offset=CINEMATIC_WALKING_FEET_ENTERING_10, x=94, y=97
	break
	video type=1, offset=CINEMATIC_WALKING_FEET_ENTERING_10, x=71, y=115
	break
	mov [PAUSE_SLICES], 0x0002
	mov [0x01], 0x001C

DELAY_28F_BEFORE_BLITTER_SETUP:
	break
	djnz [0x01], DELAY_28F_BEFORE_BLITTER_SETUP
	break
	setup channel=0x3C, address=BLIT_AND_COPY_PAGE_FF_LOOP
	break
	mov [PAUSE_SLICES], 0x0002
	video type=1, offset=CINEMATIC_090, x=160, y=100
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_102, x=160, y=100
	selectVideoPage 0xFF
	play id=0x000D, freq=0x0C, vol=0x3F, channel=0x03
	mov [0x01], 0x0014

DELAY_20F_BEFORE_PAL_7_INIT:
	break
	djnz [0x01], DELAY_20F_BEFORE_PAL_7_INIT
	setup channel=0x01, address=INTRO_SET_PAL_7_FILL_PAGE0_5
	setup channel=0x02, address=CH_02_INIT_VARS_01_02_03
	setup channel=0x03, address=DRAW_CIN_112_AT_143_94_LOOP
	setup channel=0x3C, address=BLIT_AND_COPY_PAGE_FF_LOOP
	killChannel

INTRO_FILL_AND_DRAW_CIN_103:
	fill page=0x00, color=0x02
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_103, x=192, y=100
	video type=1, offset=CINEMATIC_053, x=14, y=80
	video type=1, offset=CINEMATIC_104, x=189, y=68
	video type=1, offset=CINEMATIC_105, x=64, y=70
	video type=1, offset=CINEMATIC_106, x=244, y=56
	video type=1, offset=CINEMATIC_107, x=246, y=56
	video type=1, offset=CINEMATIC_108, x=247, y=50
	video type=1, offset=CINEMATIC_109, x=117, y=86
	video type=1, offset=CINEMATIC_110, x=61, y=69
	video type=1, offset=CINEMATIC_111, x=160, y=100
	video type=1, offset=CINEMATIC_102, x=160, y=100
	selectVideoPage 0xFF
	killChannel

DRAW_CINEMATIC_053_LOOP:
	video type=1, offset=CINEMATIC_053, x=14, y=80
	break
	jmp DRAW_CINEMATIC_053_LOOP
LABEL_26A6:
	killChannel
;@if BRANCH == "cartridge_1992"
	FILL(55641, 0xFF)
;@elif BRANCH == "gba_2004"
	FILL(55629, 0xFF)
;@endif
