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
