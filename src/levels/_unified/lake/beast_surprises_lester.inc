THE_BEAST_SURPRISES_LESTER:
	break
	djnz [0x10], THE_BEAST_SURPRISES_LESTER
	video type=1, offset=CINEMATIC_BEAST_SURPRISE_BODY_0, x=160, y=65506, zoom=0x40
	break
	video type=1, offset=CINEMATIC_BEAST_SURPRISE_BODY_0, x=160, y=50
	break
	video type=1, offset=CINEMATIC_BEAST_SURPRISE_BODY_1, x=160, y=100
	break
	video type=1, offset=CINEMATIC_BEAST_SURPRISE_BODY_2, x=160, y=100
	play id=0x003D, freq=0x14, vol=0x3F, channel=0x00
	break
	video type=1, offset=CINEMATIC_BEAST_SURPRISE_BODY_3, x=160, y=100
	play id=0x003D, freq=0x12, vol=0x3F, channel=0x01
	break
	video type=1, offset=CINEMATIC_BEAST_SURPRISE_BODY_4, x=160, y=100
	break
	video type=1, offset=CINEMATIC_BEAST_SURPRISE_BODY_5, x=160, y=100
	video type=1, offset=CINEMATIC_BEAST_SURPRISE_EYES_AND_TEETH_0, x=160, y=100
	break
	video type=1, offset=CINEMATIC_BEAST_SURPRISE_BODY_5, x=160, y=100
	video type=1, offset=CINEMATIC_BEAST_SURPRISE_EYES_AND_TEETH_1, x=160, y=100
	break
	video type=1, offset=CINEMATIC_BEAST_SURPRISE_BODY_6, x=160, y=100
	video type=1, offset=CINEMATIC_BEAST_SURPRISE_EYES_AND_TEETH_2, x=160, y=100
	play id=0x0030, freq=0x14, vol=0x3F, channel=0x00
	play id=0x0030, freq=0x14, vol=0x3F, channel=0x01
	play id=0x0030, freq=0x14, vol=0x3F, channel=0x02
	play id=0x0030, freq=0x14, vol=0x3F, channel=0x03
	break
	video type=1, offset=CINEMATIC_BEAST_SURPRISE_BODY_6, x=160, y=100
	video type=1, offset=CINEMATIC_BEAST_SURPRISE_EYES_AND_TEETH_3, x=160, y=100
	break
	video type=1, offset=CINEMATIC_BEAST_SURPRISE_BODY_7, x=160, y=100
	video type=1, offset=CINEMATIC_BEAST_SURPRISE_EYES_AND_TEETH_4, x=160, y=100
	mov [0x10], 0x0001

BEAST_SURPRISE_PHASE7_HOLD:
	break
	video type=1, offset=CINEMATIC_BEAST_SURPRISE_BODY_7, x=160, y=100
	video type=1, offset=CINEMATIC_BEAST_SURPRISE_EYES_AND_TEETH_5, x=160, y=100
	djnz [0x10], BEAST_SURPRISE_PHASE7_HOLD
	break
	video type=1, offset=CINEMATIC_BEAST_SURPRISE_BODY_7, x=160, y=100
	video type=1, offset=CINEMATIC_BEAST_SURPRISE_EYES_AND_TEETH_6, x=158, y=100
	break
	video type=1, offset=CINEMATIC_BEAST_SURPRISE_BODY_6, x=160, y=100
	video type=1, offset=CINEMATIC_BEAST_SURPRISE_EYES_AND_TEETH_7, x=155, y=100
	break
	video type=1, offset=CINEMATIC_BEAST_SURPRISE_BODY_5, x=160, y=100
	video type=1, offset=CINEMATIC_BEAST_SURPRISE_EYES_AND_TEETH_8, x=152, y=100
	break
	video type=1, offset=CINEMATIC_BEAST_SURPRISE_BODY_8, x=160, y=100
	video type=1, offset=CINEMATIC_BEAST_SURPRISE_EYES_AND_TEETH_8, x=149, y=98
	break
	video type=1, offset=CINEMATIC_BEAST_SURPRISE_BODY_9, x=160, y=100
	video type=1, offset=CINEMATIC_BEAST_SURPRISE_EYES_AND_TEETH_9, x=147, y=97
	break
	video type=1, offset=CINEMATIC_BEAST_SURPRISE_BODY_9, x=160, y=100
	video type=1, offset=CINEMATIC_BEAST_SURPRISE_EYES_AND_TEETH_9, x=145, y=94
	break
	video type=1, offset=CINEMATIC_BEAST_SURPRISE_BODY_9, x=160, y=100
	video type=1, offset=CINEMATIC_BEAST_SURPRISE_EYES_AND_TEETH_9, x=144, y=92
	break
	video type=1, offset=CINEMATIC_BEAST_SURPRISE_BODY_8, x=160, y=100
	video type=1, offset=CINEMATIC_BEAST_SURPRISE_EYES_AND_TEETH_7, x=144, y=92
	break
	video type=1, offset=CINEMATIC_BEAST_SURPRISE_BODY_8, x=160, y=100
	video type=1, offset=CINEMATIC_BEAST_SURPRISE_EYES_AND_TEETH_7, x=146, y=93
	break
	video type=1, offset=CINEMATIC_BEAST_SURPRISE_BODY_5, x=160, y=100
	video type=1, offset=CINEMATIC_BEAST_SURPRISE_EYES_AND_TEETH_10, x=150, y=94
	break
	video type=1, offset=CINEMATIC_BEAST_SURPRISE_BODY_6, x=160, y=100
	video type=1, offset=CINEMATIC_BEAST_SURPRISE_EYES_AND_TEETH_6, x=154, y=96
	break
	video type=1, offset=CINEMATIC_BEAST_SURPRISE_BODY_7, x=160, y=100
	video type=1, offset=CINEMATIC_BEAST_SURPRISE_EYES_AND_TEETH_5, x=158, y=98
	break
	video type=1, offset=CINEMATIC_BEAST_SURPRISE_BODY_7, x=160, y=100
	video type=1, offset=CINEMATIC_BEAST_SURPRISE_EYES_AND_TEETH_4, x=161, y=100
	break
	video type=1, offset=CINEMATIC_BEAST_SURPRISE_BODY_7, x=160, y=100
	video type=1, offset=CINEMATIC_BEAST_SURPRISE_EYES_AND_TEETH_4, x=163, y=101
	break
	video type=1, offset=CINEMATIC_BEAST_SURPRISE_BODY_7, x=160, y=100
	video type=1, offset=CINEMATIC_BEAST_SURPRISE_EYES_AND_TEETH_4, x=164, y=101
	break
	video type=1, offset=CINEMATIC_BEAST_SURPRISE_BODY_6, x=160, y=100
	video type=1, offset=CINEMATIC_BEAST_SURPRISE_EYES_AND_TEETH_4, x=163, y=100
	break
	video type=1, offset=CINEMATIC_BEAST_SURPRISE_BODY_6, x=160, y=100
	video type=1, offset=CINEMATIC_BEAST_SURPRISE_EYES_AND_TEETH_4, x=161, y=99
;@if BRANCH in ("cartridge_1992", "gba_2004")
	setup channel=0x3C, address=BLIT_FROM_PAGE_0_LOOP
;@endif
;@if BRANCH == "dos_1992"
	setup channel=0x3C, address=BLIT_FROM_PAGE_0_LOOP
;@endif
	break
	video type=1, offset=CINEMATIC_BEAST_SURPRISE_BODY_6, x=160, y=100
	video type=1, offset=CINEMATIC_BEAST_SURPRISE_EYES_AND_TEETH_4, x=161, y=99
	freezeChannels first=0x00, last=0x3F
	setup channel=0x29, address=CHECK_IF_THE_BEAST_HAS_ALREADY_REACHED_LESTER
	copyVideoPage src=0x03, dst=0x00
	selectVideoPage 0x03
	fill page=0x03, color=0x0E
	call DRAW_SCENARIO_OF_SECOND_SCREEN_TO_THE_RIGHT
	mov [0x65], 0x0004
	selectVideoPage 0xFF
	freezeChannels first=0x0B, last=0x13
	break
	setPalette 0x06
	mov [PAUSE_SLICES], 0x0003
	setup channel=0x24, address=AMBIENT_LOOP_CH24
	setup channel=0x25, address=AMBIENT_LOOP_CH25
;@if BRANCH in ("cartridge_1992", "gba_2004")
	song id=0x0BBA, delay=0x0000, pos=0x00
;@endif
;@if BRANCH == "gba_2004"
	song id=0x0FA3, delay=0x0000, pos=0x00
;@endif
	jmp BEAST_AI_SPAWN_MID_RIGHT
	killChannel

