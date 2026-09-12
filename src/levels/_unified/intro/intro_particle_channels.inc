.if BRANCH == "chahi_amiga_1991"
CINEMATIC_CAR_DRIVING_AWAY_FROM_CAMERA_F2		EQU 0x041C
CINEMATIC_LESTER_EXITING_CAR_F4		EQU 0xBD5E
.else
CINEMATIC_005		EQU 0x0CB8
CINEMATIC_032		EQU 0x05B8
.endif

CINEMATIC_EXPERIMENT_LIGHTNING_F0		EQU 0x972C
CINEMATIC_EXPERIMENT_LIGHTNING_F1		EQU 0x97C8
CINEMATIC_EXPERIMENT_LIGHTNING_F2		EQU 0x985C
CINEMATIC_EXPERIMENT_LIGHTNING_F3		EQU 0x98F4
.if BRANCH == "chahi_amiga_1991"
CINEMATIC_EXPERIMENT_LIGHTNING_F4		EQU 0x95F0
.else
CINEMATIC_EXPERIMENT_LIGHTNING_F4		EQU 0x9562
.endif
CINEMATIC_EXPERIMENT_LIGHTNING_F5		EQU 0x95F2
.if BRANCH == "chahi_amiga_1991"
CINEMATIC_EXPERIMENT_LIGHTNING_F6		EQU 0x971C
CINEMATIC_EXPERIMENT_LIGHTNING_F7		EQU 0x9A1E
CINEMATIC_EXPERIMENT_LIGHTNING_F8		EQU 0x9A5E
CINEMATIC_EXPERIMENT_LIGHTNING_F9		EQU 0x9A9E
CINEMATIC_EXPERIMENT_LIGHTNING_F10		EQU 0x9ADE
CINEMATIC_EXPERIMENT_LIGHTNING_F11		EQU 0x9B1E
CINEMATIC_EXPERIMENT_LIGHTNING_F12		EQU 0x9BCA
CINEMATIC_EXPERIMENT_LIGHTNING_F13		EQU 0x9CB2
CINEMATIC_EXPERIMENT_LIGHTNING_F14		EQU 0x9DD6
CINEMATIC_EXPERIMENT_LIGHTNING_F15		EQU 0x9F1E
CINEMATIC_EXPERIMENT_LIGHTNING_F16		EQU 0xA090
CINEMATIC_EXPERIMENT_LIGHTNING_F17		EQU 0xA1F8
CINEMATIC_EXPERIMENT_LIGHTNING_F18		EQU 0xA32A
CINEMATIC_EXPERIMENT_LIGHTNING_F19		EQU 0xA450
CINEMATIC_EXPERIMENT_LIGHTNING_F20		EQU 0xA57E
CINEMATIC_EXPERIMENT_LIGHTNING_F21		EQU 0xA6AC
CINEMATIC_EXPERIMENT_LIGHTNING_F22		EQU 0xA7BA
CINEMATIC_EXPERIMENT_LIGHTNING_F23		EQU 0xA8B8
CINEMATIC_EXPERIMENT_LIGHTNING_F24		EQU 0xA9B6
CINEMATIC_EXPERIMENT_LIGHTNING_F25		EQU 0xAA58
CINEMATIC_EXPERIMENT_LIGHTNING_F26		EQU 0xAADE
CINEMATIC_EXPERIMENT_LIGHTNING_F27		EQU 0xAB50
CINEMATIC_EXPERIMENT_LIGHTNING_F28		EQU 0xAB9E
CINEMATIC_274		EQU 0xD280
CINEMATIC_275		EQU 0xD2FC
CINEMATIC_276		EQU 0xD374
CINEMATIC_LESTER_TUMBLING_TOWARDS_CAMERA_F0		EQU 0xD3A4
CINEMATIC_LESTER_TUMBLING_TOWARDS_CAMERA_F1		EQU 0xD3C4
CINEMATIC_LESTER_TUMBLING_TOWARDS_CAMERA_F2		EQU 0xD400
CINEMATIC_LESTER_TUMBLING_TOWARDS_CAMERA_F3		EQU 0xD440
CINEMATIC_LESTER_TUMBLING_TOWARDS_CAMERA_F4		EQU 0xD48C
CINEMATIC_LESTER_TUMBLING_TOWARDS_CAMERA_F5		EQU 0xD4EC
CINEMATIC_LESTER_TUMBLING_TOWARDS_CAMERA_F6		EQU 0xD550
CINEMATIC_LESTER_TUMBLING_TOWARDS_CAMERA_F7		EQU 0xD5B4
CINEMATIC_LESTER_TUMBLING_TOWARDS_CAMERA_F8		EQU 0xD620
CINEMATIC_LESTER_TUMBLING_TOWARDS_CAMERA_F9		EQU 0xD66C
CINEMATIC_LESTER_TUMBLING_TOWARDS_CAMERA_F10		EQU 0xD6E8
CINEMATIC_LESTER_TUMBLING_TOWARDS_CAMERA_F11		EQU 0xD780
CINEMATIC_LESTER_TUMBLING_TOWARDS_CAMERA_F12		EQU 0xD822
CINEMATIC_LESTER_TUMBLING_TOWARDS_CAMERA_F13		EQU 0xD892
CINEMATIC_LESTER_TUMBLING_TOWARDS_CAMERA_F14		EQU 0xD902
CINEMATIC_292		EQU 0xD9EE
CINEMATIC_293		EQU 0xDA7E
CINEMATIC_294		EQU 0xDC20
CINEMATIC_EXPERIMENT_DISCHARGE_STREAK_F0		EQU 0xEBAA
CINEMATIC_EXPERIMENT_DISCHARGE_STREAK_F1		EQU 0xEBC2
CINEMATIC_EXPERIMENT_DISCHARGE_STREAK_F2		EQU 0xEBDA
CINEMATIC_EXPERIMENT_DISCHARGE_STREAK_F3		EQU 0xEBF2
CINEMATIC_EXPERIMENT_DISCHARGE_STREAK_F4		EQU 0xEC0E
CINEMATIC_EXPERIMENT_LIGHTNING_FLICKER_CENTER_F0		EQU 0xF02A
.else
CINEMATIC_EXPERIMENT_LIGHTNING_F6		EQU 0x968E
CINEMATIC_EXPERIMENT_LIGHTNING_F7		EQU 0x9990
CINEMATIC_EXPERIMENT_LIGHTNING_F8		EQU 0x99D0
CINEMATIC_EXPERIMENT_LIGHTNING_F9		EQU 0x9A10
CINEMATIC_EXPERIMENT_LIGHTNING_F10		EQU 0x9A50
CINEMATIC_EXPERIMENT_LIGHTNING_F11		EQU 0x9A90
CINEMATIC_EXPERIMENT_LIGHTNING_F12		EQU 0x9B3C
CINEMATIC_EXPERIMENT_LIGHTNING_F13		EQU 0x9C24
CINEMATIC_EXPERIMENT_LIGHTNING_F14		EQU 0x9D48
CINEMATIC_EXPERIMENT_LIGHTNING_F15		EQU 0x9E90
CINEMATIC_EXPERIMENT_LIGHTNING_F16		EQU 0xA002
CINEMATIC_EXPERIMENT_LIGHTNING_F17		EQU 0xA16A
CINEMATIC_EXPERIMENT_LIGHTNING_F18		EQU 0xA29C
CINEMATIC_EXPERIMENT_LIGHTNING_F19		EQU 0xA3C2
CINEMATIC_EXPERIMENT_LIGHTNING_F20		EQU 0xA4F0
CINEMATIC_EXPERIMENT_LIGHTNING_F21		EQU 0xA61E
CINEMATIC_EXPERIMENT_LIGHTNING_F22		EQU 0xA72C
CINEMATIC_EXPERIMENT_LIGHTNING_F23		EQU 0xA82A
CINEMATIC_EXPERIMENT_LIGHTNING_F24		EQU 0xA928
CINEMATIC_EXPERIMENT_LIGHTNING_F25		EQU 0xA9CA
CINEMATIC_EXPERIMENT_LIGHTNING_F26		EQU 0xAA50
CINEMATIC_EXPERIMENT_LIGHTNING_F27		EQU 0xAAC2
CINEMATIC_EXPERIMENT_LIGHTNING_F28		EQU 0xAB10
CINEMATIC_274		EQU 0xCF1A
CINEMATIC_275		EQU 0xCFC2
CINEMATIC_276		EQU 0xD032
CINEMATIC_277		EQU 0xD0A2
CINEMATIC_278		EQU 0xD112
CINEMATIC_279		EQU 0xD182
CINEMATIC_280		EQU 0xD1F2
CINEMATIC_281		EQU 0xD26E
CINEMATIC_282		EQU 0xD2E6
CINEMATIC_283		EQU 0xD316
CINEMATIC_284		EQU 0xD336
CINEMATIC_285		EQU 0xD372
CINEMATIC_286		EQU 0xD3B2
CINEMATIC_287		EQU 0xD3FE
CINEMATIC_288		EQU 0xD45E
CINEMATIC_289		EQU 0xD4C2
CINEMATIC_290		EQU 0xD526
CINEMATIC_291		EQU 0xD592
CINEMATIC_292		EQU 0xD5DE
CINEMATIC_293		EQU 0xD65A
CINEMATIC_294		EQU 0xD6F2
CINEMATIC_295		EQU 0xD794
CINEMATIC_296		EQU 0xD804
CINEMATIC_297		EQU 0xD874
CINEMATIC_298		EQU 0xD960
CINEMATIC_299		EQU 0xD9F0
CINEMATIC_300		EQU 0xDB92
.endif

SETUP_INTRO_PARTICLE_CHANNELS:
	setup channel=0x03, address=INTRO_TRANSITION_TO_LAKE_SETUP
	setup channel=0x01, address=INTRO_SCENE_INIT_PARTICLES
.if BRANCH != "chahi_amiga_1991"
	setup channel=0x3C, address=BLIT_AND_COPY_PAGE_FF_LOOP
.endif
.if BRANCH == "gba_2004"
	song id=0x0FBA, delay=0x0000, pos=0x01
.endif
	break
	song id=0x0000, delay=0x0000, pos=0x00
	play id=0x000A, freq=0x02, vol=0x14, channel=0x00
	play id=0x0008, freq=0x05, vol=0x3F, channel=0x03
	play id=0x0008, freq=0x00, vol=0x3F, channel=0x02
	setPalette 0x19
	setup channel=0x0A, address=CH_0A_INIT_VAR_02
	setup channel=0x0B, address=CH_0B_INIT_VAR_03
	setup channel=0x0C, address=CH_0C_INIT_VAR_04
	setup channel=0x0D, address=CH_0D_INIT_VAR_05
	setup channel=0x0E, address=CH_0E_INIT_VAR_06
	setup channel=0x0F, address=CH_0F_INIT_PARTICLE_POS
	setup channel=0x10, address=CH_10_DRAW_CIN_353_PARTICLE
	setup channel=0x11, address=CH_11_INIT_PARTICLE_POS_2
	setup channel=0x12, address=CH_12_INIT_PARTICLE_POS_3
	mov [PAUSE_SLICES], 0x0003
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_CAR_DRIVING_AWAY_FROM_CAMERA_F15, x=215, y=100
	video offset=CINEMATIC_CITY_FOREGROUND_GIRDER_MID_ARM, x=90, y=101
.else
	video offset=CINEMATIC_032, x=215, y=100
	video offset=CINEMATIC_005, x=90, y=101
.endif
	mov [0x01], 0x015E

PARTICLE_PHASE_350_FRAME_TIMER:
	break
	djnz [0x01], PARTICLE_PHASE_350_FRAME_TIMER
.if BRANCH == "chahi_amiga_1991"
	setup channel=0x3C, address=LABEL_008A
.else
	setup channel=0x3C, address=BLIT_DISPATCH_HERO_ACTION_ALT
.endif
.if BRANCH == "chahi_amiga_1991"
	setup channel=0x01, address=FILL_FF_PAGE_LOOP
.endif
	deleteChannels first=0x0A, last=0x12
	break
	play id=0x000A, freq=0x14, vol=0x3F, channel=0x00
	setPalette 0x17
	fill page=0xFF, color=0x08
	break
	fill page=0xFF, color=0x08
	break
	fill page=0xFF, color=0x08
	play id=0x000A, freq=0x0A, vol=0x3F, channel=0x01
.if BRANCH != "chahi_amiga_1991"
	setup channel=0x01, address=FILL_FF_PAGE_LOOP
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_187, x=160, y=100
.else
	video offset=CINEMATIC_EXPERIMENT_LIGHTNING_F0, x=160, y=100
.endif
	break
	mov [PAUSE_SLICES], 0x0003
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_188, x=160, y=100
.else
	video offset=CINEMATIC_EXPERIMENT_LIGHTNING_F1, x=160, y=100
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_189, x=160, y=100
.else
	video offset=CINEMATIC_EXPERIMENT_LIGHTNING_F2, x=160, y=100
.endif
	break
	play id=0x000A, freq=0x05, vol=0x3F, channel=0x02
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_190, x=160, y=100
.else
	video offset=CINEMATIC_EXPERIMENT_LIGHTNING_F3, x=160, y=100
.endif
	break
	video offset=CINEMATIC_EXPERIMENT_LIGHTNING_F4, x=160, y=100
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_192, x=160, y=100
.else
	video offset=CINEMATIC_EXPERIMENT_LIGHTNING_F5, x=160, y=100
.endif
	break
	video offset=CINEMATIC_EXPERIMENT_LIGHTNING_F6, x=160, y=100
	play id=0x000A, freq=0x19, vol=0x3F, channel=0x03
	break
	fill page=0xFF, color=0x08
	break
	fill page=0xFF, color=0x08
	break
	fill page=0xFF, color=0x08
.if BRANCH == "chahi_amiga_1991"
	break
.else
	setup channel=0x01, address=FILL_FF_PAGE_LOOP
.endif
	break
	break
	break
	break
.if BRANCH == "chahi_amiga_1991"
	setup channel=0x3C, address=BLIT_AND_DISPATCH_HERO_ACTION
.else
	setup channel=0x3C, address=BLIT_AND_COPY_PAGE_FF_LOOP
.endif
.if BRANCH != "chahi_amiga_1991"
	break
.endif
	setup channel=0x01, address=KILL_CHANNEL_ROUTINE
	jmp SETUP_PAL19_AND_PAGE_FLIP
LABEL_06D7:
.if BRANCH == "dos_1992"
	db 0x11
.else
.if BRANCH == "chahi_amiga_1991"
	db 0x11
.else
	killChannel
.endif
.endif

FILL_FF_PAGE_LOOP:
	fill page=0xFF, color=0x02
	break
	jmp FILL_FF_PAGE_LOOP
LABEL_06DF:
.if BRANCH == "dos_1992"
	db 0x11
.else
.if BRANCH == "chahi_amiga_1991"
	db 0x11
.else
	killChannel
.endif
.endif

SETUP_PAL19_AND_PAGE_FLIP:
	selectVideoPage 0x00
.if BRANCH != "chahi_amiga_1991"
	selectVideoPage 0xFF
.endif
	mov [PAUSE_SLICES], 0x0002
	setPalette 0x19
	break
	play id=0x000A, freq=0x1E, vol=0x3F, channel=0x02
	video offset=CINEMATIC_EXPERIMENT_LIGHTNING_F7, x=183, y=100
	break
	video offset=CINEMATIC_EXPERIMENT_LIGHTNING_F8, x=183, y=100
	break
	video offset=CINEMATIC_EXPERIMENT_LIGHTNING_F9, x=183, y=100
	break
	video offset=CINEMATIC_EXPERIMENT_LIGHTNING_F10, x=183, y=100
	break
	play id=0x000A, freq=0x02, vol=0x3F, channel=0x03
	video offset=CINEMATIC_EXPERIMENT_LIGHTNING_F11, x=183, y=100
	break
	video offset=CINEMATIC_EXPERIMENT_LIGHTNING_F12, x=183, y=100
	break
	mov [PAUSE_SLICES], 0x0003
	video offset=CINEMATIC_EXPERIMENT_LIGHTNING_F13, x=183, y=100
	break
	video offset=CINEMATIC_EXPERIMENT_LIGHTNING_F14, x=183, y=100
	break
	video offset=CINEMATIC_EXPERIMENT_LIGHTNING_F15, x=183, y=100
	break
	video offset=CINEMATIC_EXPERIMENT_LIGHTNING_F16, x=183, y=100
	break
	video offset=CINEMATIC_EXPERIMENT_LIGHTNING_F17, x=183, y=100
	break
	video offset=CINEMATIC_EXPERIMENT_LIGHTNING_F18, x=183, y=100
	break
	video offset=CINEMATIC_EXPERIMENT_LIGHTNING_F19, x=183, y=100
	break
	video offset=CINEMATIC_EXPERIMENT_LIGHTNING_F20, x=183, y=100
	break
	mov [PAUSE_SLICES], 0x0002
	video offset=CINEMATIC_EXPERIMENT_LIGHTNING_F21, x=183, y=100
	break
	video offset=CINEMATIC_EXPERIMENT_LIGHTNING_F22, x=183, y=100
	break
	video offset=CINEMATIC_EXPERIMENT_LIGHTNING_F23, x=183, y=100
	break
	video offset=CINEMATIC_EXPERIMENT_LIGHTNING_F24, x=183, y=100
	break
	video offset=CINEMATIC_EXPERIMENT_LIGHTNING_F25, x=183, y=100
	break
	video offset=CINEMATIC_EXPERIMENT_LIGHTNING_F26, x=183, y=100
	break
	video offset=CINEMATIC_EXPERIMENT_LIGHTNING_F27, x=183, y=100
	break
	video offset=CINEMATIC_EXPERIMENT_LIGHTNING_F28, x=183, y=100
.if BRANCH != "chahi_amiga_1991"
	setup channel=0x3C, address=BLIT_AND_COPY_PAGE_FF_LOOP
.endif
	break
	jmp PHASE_PAGE3_TO_0_PAL_16
LABEL_0775:
.if BRANCH == "dos_1992"
	db 0x11
.else
.if BRANCH == "chahi_amiga_1991"
	db 0x11
.else
	killChannel
.endif
.endif

TRANSITION_TO_BLITTER_LOOP:
.if BRANCH != "chahi_amiga_1991"
	setup channel=0x3C, address=BLIT_AND_COPY_PAGE_FF_LOOP
.endif
	break
	play id=0x000A, freq=0x07, vol=0x3F, channel=0x03
	play id=0x000A, freq=0x14, vol=0x3F, channel=0x02
	copyVideoPage src=0x03, dst=0x00
.if BRANCH == "chahi_amiga_1991"
	setPalette 0x17
	mov [0x01], 0x0001

LABEL_06ED:
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	djnz [0x01], LABEL_06ED
.else
	setPalette 0x17
.endif
	play id=0x000A, freq=0x0F, vol=0x3F, channel=0x01
	setPalette 0x18
	mov [0x01], 0x0001

FILL_PAGE_FF_COLOR_8_ONCE:
	break
	fill page=0xFF, color=0x08
	break
	djnz [0x01], FILL_PAGE_FF_COLOR_8_ONCE
	setup channel=0x04, address=SET_PALETTE_18
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_268, x=160, y=100
.else
	video offset=CINEMATIC_274, x=160, y=100
.endif
	play id=0x002C, freq=0x14, vol=0x3F, channel=0x03
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_269, x=160, y=100
.else
	video offset=CINEMATIC_275, x=160, y=100
.endif
	play id=0x000A, freq=0x14, vol=0x3F, channel=0x03
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_270, x=160, y=100
.else
	video offset=CINEMATIC_276, x=160, y=100
.endif
	play id=0x002C, freq=0x14, vol=0x3F, channel=0x03
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_271, x=160, y=100
.else
	video offset=CINEMATIC_277, x=160, y=100
.endif
	play id=0x000A, freq=0x14, vol=0x3F, channel=0x03
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_272, x=160, y=100
.else
	video offset=CINEMATIC_278, x=160, y=100
.endif
	play id=0x000E, freq=0x14, vol=0x3F, channel=0x02
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_273, x=160, y=100
.else
	video offset=CINEMATIC_279, x=160, y=100
.endif
	play id=0x000A, freq=0x05, vol=0x3F, channel=0x00
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_274, x=160, y=100
.else
	video offset=CINEMATIC_280, x=160, y=100
.endif
	play id=0x000A, freq=0x14, vol=0x3F, channel=0x01
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_275, x=160, y=100
.else
	video offset=CINEMATIC_281, x=160, y=100
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_276, x=160, y=100
.else
	video offset=CINEMATIC_282, x=160, y=100
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_LESTER_TUMBLING_TOWARDS_CAMERA_F0, x=160, y=100
.else
	video offset=CINEMATIC_283, x=160, y=100
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_LESTER_TUMBLING_TOWARDS_CAMERA_F1, x=160, y=100
.else
	video offset=CINEMATIC_284, x=160, y=100
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_LESTER_TUMBLING_TOWARDS_CAMERA_F2, x=160, y=100
.else
	video offset=CINEMATIC_285, x=160, y=100
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_LESTER_TUMBLING_TOWARDS_CAMERA_F3, x=160, y=100
.else
	video offset=CINEMATIC_286, x=160, y=100
.endif
	play id=0x000A, freq=0x0C, vol=0x3F, channel=0x03
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_LESTER_TUMBLING_TOWARDS_CAMERA_F4, x=160, y=100
.else
	video offset=CINEMATIC_287, x=160, y=100
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_LESTER_TUMBLING_TOWARDS_CAMERA_F5, x=160, y=100
.else
	video offset=CINEMATIC_288, x=160, y=100
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_LESTER_TUMBLING_TOWARDS_CAMERA_F6, x=160, y=100
.else
	video offset=CINEMATIC_289, x=160, y=100
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_LESTER_TUMBLING_TOWARDS_CAMERA_F7, x=160, y=100
.else
	video offset=CINEMATIC_290, x=160, y=100
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_LESTER_TUMBLING_TOWARDS_CAMERA_F8, x=160, y=100
.else
	video offset=CINEMATIC_291, x=160, y=100
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_LESTER_TUMBLING_TOWARDS_CAMERA_F9, x=160, y=100
.else
	video offset=CINEMATIC_292, x=160, y=100
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_LESTER_TUMBLING_TOWARDS_CAMERA_F10, x=160, y=100
.else
	video offset=CINEMATIC_293, x=160, y=100
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_LESTER_TUMBLING_TOWARDS_CAMERA_F11, x=160, y=100
.else
	video offset=CINEMATIC_294, x=160, y=100
.endif
	play id=0x000A, freq=0x02, vol=0x3F, channel=0x01
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_LESTER_TUMBLING_TOWARDS_CAMERA_F12, x=160, y=100
.else
	video offset=CINEMATIC_295, x=160, y=100
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_LESTER_TUMBLING_TOWARDS_CAMERA_F13, x=160, y=100
.else
	video offset=CINEMATIC_296, x=160, y=100
.endif
	break
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_LESTER_TUMBLING_TOWARDS_CAMERA_F14, x=160, y=100
.else
	video offset=CINEMATIC_297, x=160, y=100
.endif
	play id=0x000A, freq=0x14, vol=0x3F, channel=0x00
	play id=0x000A, freq=0x01, vol=0x3F, channel=0x02
	break
	setup channel=0x04, address=KILL_CHANNEL_ROUTINE
	mov [PAUSE_SLICES], 0x0002
	mov [0x01], 0x0003

BLINK_PAGE_FF_3X_LOOP:
	fill page=0xFF, color=0x08
	break
	fill page=0xFF, color=0x00
	break
	djnz [0x01], BLINK_PAGE_FF_3X_LOOP
	fill page=0xFF, color=0x08
	selectVideoPage 0x00
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_292, x=160, y=100
.else
	video offset=CINEMATIC_298, x=160, y=100
.endif
	selectVideoPage 0xFF
	break
	fill page=0xFF, color=0x00
	selectVideoPage 0x00
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_293, x=160, y=100
.else
	video offset=CINEMATIC_299, x=160, y=100
.endif
	play id=0x000E, freq=0x02, vol=0x3F, channel=0x03
	selectVideoPage 0xFF
	break
	fill page=0xFF, color=0x08
	selectVideoPage 0x00
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_294, x=160, y=100
.else
	video offset=CINEMATIC_300, x=160, y=100
.endif
	play id=0x000F, freq=0x02, vol=0x3F, channel=0x03
	selectVideoPage 0xFF
	break
	fill page=0xFF, color=0x00
.if BRANCH != "chahi_amiga_1991"
	setup channel=0x3C, address=BLIT_AND_COPY_PAGE_FF_LOOP
.endif
	break
	setPalette 0x17
	play id=0x0003, freq=0x14, vol=0x0A, channel=0x03
	setup channel=0x04, address=INTRO_PALETTE_FLICKER_LOOP
	setup channel=0x0B, address=PLAY_FX_2C_AND_DRAW_CIN_000
	setup channel=0x0C, address=DRAW_INTRO_LIGHTNING_FLICKER_LONG
	setup channel=0x0D, address=DRAW_INTRO_DECOR_337
	setup channel=0x0E, address=DRAW_INTRO_LIGHTNING_FLICKER_SHORT
	setup channel=0x0F, address=DRAW_INTRO_DECOR_331
	setup channel=0x10, address=DRAW_INTRO_DECOR_329
	setup channel=0x11, address=DRAW_INTRO_DECOR_318
	setup channel=0x12, address=DRAW_INTRO_LIGHTNING_BOLT_STRIKE
	setup channel=0x14, address=DRAW_INTRO_LIGHTNING_FLICKER_RIGHT
	setup channel=0x15, address=DRAW_INTRO_LIGHTNING_FLICKER_CENTER
	mov [0x01], 0x0064

WAIT_100_THEN_CIN_274:
	break
	djnz [0x01], WAIT_100_THEN_CIN_274
	play id=0x0003, freq=0x14, vol=0x12, channel=0x03
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_268, x=160, y=100
.else
	video offset=CINEMATIC_274, x=160, y=100
.endif
	break
	play id=0x0003, freq=0x14, vol=0x10, channel=0x03
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_269, x=160, y=100
.else
	video offset=CINEMATIC_275, x=160, y=100
.endif
	break
	play id=0x0003, freq=0x14, vol=0x0E, channel=0x03
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_270, x=160, y=100
.else
	video offset=CINEMATIC_276, x=160, y=100
.endif
	play id=0x000E, freq=0x02, vol=0x32, channel=0x03
	break
	play id=0x0003, freq=0x14, vol=0x0C, channel=0x03
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_271, x=160, y=100
.else
	video offset=CINEMATIC_277, x=160, y=100
.endif
	play id=0x000E, freq=0x05, vol=0x32, channel=0x02
	break
	play id=0x0003, freq=0x14, vol=0x0A, channel=0x03
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_272, x=160, y=100
.else
	video offset=CINEMATIC_278, x=160, y=100
.endif
	play id=0x000E, freq=0x01, vol=0x3F, channel=0x00
	break
	play id=0x0003, freq=0x14, vol=0x08, channel=0x03
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_273, x=160, y=100
.else
	video offset=CINEMATIC_279, x=160, y=100
.endif
	break
	play id=0x0003, freq=0x14, vol=0x06, channel=0x03
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_274, x=160, y=100
.else
	video offset=CINEMATIC_280, x=160, y=100
.endif
	setup channel=0x04, address=KILL_CHANNEL_ROUTINE
	play id=0x000E, freq=0x06, vol=0x3F, channel=0x01
	break
	play id=0x0003, freq=0x14, vol=0x04, channel=0x03
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_275, x=160, y=100
.else
	video offset=CINEMATIC_281, x=160, y=100
.endif
	break
	setPalette 0x18
	play id=0x0003, freq=0x14, vol=0x02, channel=0x03
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_276, x=160, y=100
.else
	video offset=CINEMATIC_282, x=160, y=100
.endif
	break
	setPalette 0x1A
	play id=0x000E, freq=0x00, vol=0x3F, channel=0x03
.if BRANCH == "chahi_amiga_1991"
	video offset=CINEMATIC_276, x=160, y=100
.else
	video offset=CINEMATIC_282, x=160, y=100
.endif
	break
	setup channel=0x14, address=KILL_CHANNEL_ROUTINE
	setup channel=0x15, address=KILL_CHANNEL_ROUTINE
	setup channel=0x0A, address=KILL_CHANNEL_ROUTINE
	setup channel=0x0B, address=KILL_CHANNEL_ROUTINE
	setup channel=0x0C, address=KILL_CHANNEL_ROUTINE
	setup channel=0x0D, address=KILL_CHANNEL_ROUTINE
	setup channel=0x10, address=KILL_CHANNEL_ROUTINE
	break
	setPalette 0x18
	break
	setPalette 0x17
	mov [0x01], 0x001E

WAIT_30_THEN_SETUP_CH12:
	break
	djnz [0x01], WAIT_30_THEN_SETUP_CH12
	setup channel=0x12, address=DRAW_INTRO_LIGHTNING_BOLT_STRIKE
	setup channel=0x0E, address=KILL_CHANNEL_ROUTINE
	setup channel=0x11, address=KILL_CHANNEL_ROUTINE
	setup channel=0x0F, address=KILL_CHANNEL_ROUTINE
	mov [0x01], 0x0014

WAIT_20_THEN_LOAD_3E82:
	break
	djnz [0x01], WAIT_20_THEN_LOAD_3E82
.if BRANCH == "dos_1992"
	bankSwitch 2;  Arrival at the Lake & Beast Chase
.else
.if BRANCH == "chahi_amiga_1991"
	bankSwitch 2;  Arrival at the Lake & Beast Chase
.else
	load id=0x3E82
.endif
.endif
	killChannel

