CINEMATIC_005		EQU 0x0CB8
CINEMATIC_032		EQU 0x05B8

CINEMATIC_193		EQU 0x972C
CINEMATIC_194		EQU 0x97C8
CINEMATIC_195		EQU 0x985C
CINEMATIC_196		EQU 0x98F4
CINEMATIC_197		EQU 0x9562
CINEMATIC_198		EQU 0x95F2
CINEMATIC_199		EQU 0x968E
CINEMATIC_200		EQU 0x9990
CINEMATIC_201		EQU 0x99D0
CINEMATIC_202		EQU 0x9A10
CINEMATIC_203		EQU 0x9A50
CINEMATIC_204		EQU 0x9A90
CINEMATIC_205		EQU 0x9B3C
CINEMATIC_206		EQU 0x9C24
CINEMATIC_207		EQU 0x9D48
CINEMATIC_208		EQU 0x9E90
CINEMATIC_209		EQU 0xA002
CINEMATIC_210		EQU 0xA16A
CINEMATIC_211		EQU 0xA29C
CINEMATIC_212		EQU 0xA3C2
CINEMATIC_213		EQU 0xA4F0
CINEMATIC_214		EQU 0xA61E
CINEMATIC_215		EQU 0xA72C
CINEMATIC_216		EQU 0xA82A
CINEMATIC_217		EQU 0xA928
CINEMATIC_218		EQU 0xA9CA
CINEMATIC_219		EQU 0xAA50
CINEMATIC_220		EQU 0xAAC2
CINEMATIC_221		EQU 0xAB10
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

SETUP_INTRO_PARTICLE_CHANNELS:
	setup channel=0x03, address=INTRO_TRANSITION_TO_LAKE_SETUP
	setup channel=0x01, address=INTRO_SCENE_INIT_PARTICLES
	setup channel=0x3C, address=BLIT_AND_COPY_PAGE_FF_LOOP
;@if BRANCH == "gba_2004"
	song id=0x0FBA, delay=0x0000, pos=0x01
;@endif
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
	video offset=CINEMATIC_032, x=215, y=100
	video offset=CINEMATIC_005, x=90, y=101
	mov [0x01], 0x015E

PARTICLE_PHASE_350_FRAME_TIMER:
	break
	djnz [0x01], PARTICLE_PHASE_350_FRAME_TIMER
	setup channel=0x3C, address=BLIT_DISPATCH_HERO_ACTION_ALT
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
	setup channel=0x01, address=FILL_FF_PAGE_LOOP
	break
	video offset=CINEMATIC_193, x=160, y=100
	break
	mov [PAUSE_SLICES], 0x0003
	video offset=CINEMATIC_194, x=160, y=100
	break
	video offset=CINEMATIC_195, x=160, y=100
	break
	play id=0x000A, freq=0x05, vol=0x3F, channel=0x02
	video offset=CINEMATIC_196, x=160, y=100
	break
	video offset=CINEMATIC_197, x=160, y=100
	break
	video offset=CINEMATIC_198, x=160, y=100
	break
	video offset=CINEMATIC_199, x=160, y=100
	play id=0x000A, freq=0x19, vol=0x3F, channel=0x03
	break
	fill page=0xFF, color=0x08
	break
	fill page=0xFF, color=0x08
	break
	fill page=0xFF, color=0x08
	setup channel=0x01, address=FILL_FF_PAGE_LOOP
	break
	break
	break
	break
	setup channel=0x3C, address=BLIT_AND_COPY_PAGE_FF_LOOP
	break
	setup channel=0x01, address=KILL_CHANNEL_ROUTINE
	jmp SETUP_PAL19_AND_PAGE_FLIP
LABEL_06D7:
	killChannel

FILL_FF_PAGE_LOOP:
	fill page=0xFF, color=0x02
	break
	jmp FILL_FF_PAGE_LOOP
LABEL_06DF:
	killChannel

SETUP_PAL19_AND_PAGE_FLIP:
	selectVideoPage 0x00
	selectVideoPage 0xFF
	mov [PAUSE_SLICES], 0x0002
	setPalette 0x19
	break
	play id=0x000A, freq=0x1E, vol=0x3F, channel=0x02
	video offset=CINEMATIC_200, x=183, y=100
	break
	video offset=CINEMATIC_201, x=183, y=100
	break
	video offset=CINEMATIC_202, x=183, y=100
	break
	video offset=CINEMATIC_203, x=183, y=100
	break
	play id=0x000A, freq=0x02, vol=0x3F, channel=0x03
	video offset=CINEMATIC_204, x=183, y=100
	break
	video offset=CINEMATIC_205, x=183, y=100
	break
	mov [PAUSE_SLICES], 0x0003
	video offset=CINEMATIC_206, x=183, y=100
	break
	video offset=CINEMATIC_207, x=183, y=100
	break
	video offset=CINEMATIC_208, x=183, y=100
	break
	video offset=CINEMATIC_209, x=183, y=100
	break
	video offset=CINEMATIC_210, x=183, y=100
	break
	video offset=CINEMATIC_211, x=183, y=100
	break
	video offset=CINEMATIC_212, x=183, y=100
	break
	video offset=CINEMATIC_213, x=183, y=100
	break
	mov [PAUSE_SLICES], 0x0002
	video offset=CINEMATIC_214, x=183, y=100
	break
	video offset=CINEMATIC_215, x=183, y=100
	break
	video offset=CINEMATIC_216, x=183, y=100
	break
	video offset=CINEMATIC_217, x=183, y=100
	break
	video offset=CINEMATIC_218, x=183, y=100
	break
	video offset=CINEMATIC_219, x=183, y=100
	break
	video offset=CINEMATIC_220, x=183, y=100
	break
	video offset=CINEMATIC_221, x=183, y=100
	setup channel=0x3C, address=BLIT_AND_COPY_PAGE_FF_LOOP
	break
	jmp PHASE_PAGE3_TO_0_PAL_16
LABEL_0775:
	killChannel

TRANSITION_TO_BLITTER_LOOP:
	setup channel=0x3C, address=BLIT_AND_COPY_PAGE_FF_LOOP
	break
	play id=0x000A, freq=0x07, vol=0x3F, channel=0x03
	play id=0x000A, freq=0x14, vol=0x3F, channel=0x02
	copyVideoPage src=0x03, dst=0x00
	break
	setPalette 0x17
	play id=0x000A, freq=0x0F, vol=0x3F, channel=0x01
	setPalette 0x18
	mov [0x01], 0x0001

FILL_PAGE_FF_COLOR_8_ONCE:
	break
	fill page=0xFF, color=0x08
	break
	djnz [0x01], FILL_PAGE_FF_COLOR_8_ONCE
	setup channel=0x04, address=SET_PALETTE_18
	video offset=CINEMATIC_274, x=160, y=100
	play id=0x002C, freq=0x14, vol=0x3F, channel=0x03
	break
	video offset=CINEMATIC_275, x=160, y=100
	play id=0x000A, freq=0x14, vol=0x3F, channel=0x03
	break
	video offset=CINEMATIC_276, x=160, y=100
	play id=0x002C, freq=0x14, vol=0x3F, channel=0x03
	break
	video offset=CINEMATIC_277, x=160, y=100
	play id=0x000A, freq=0x14, vol=0x3F, channel=0x03
	break
	video offset=CINEMATIC_278, x=160, y=100
	play id=0x000E, freq=0x14, vol=0x3F, channel=0x02
	break
	video offset=CINEMATIC_279, x=160, y=100
	play id=0x000A, freq=0x05, vol=0x3F, channel=0x00
	break
	video offset=CINEMATIC_280, x=160, y=100
	play id=0x000A, freq=0x14, vol=0x3F, channel=0x01
	break
	video offset=CINEMATIC_281, x=160, y=100
	break
	video offset=CINEMATIC_282, x=160, y=100
	break
	video offset=CINEMATIC_283, x=160, y=100
	break
	video offset=CINEMATIC_284, x=160, y=100
	break
	video offset=CINEMATIC_285, x=160, y=100
	break
	video offset=CINEMATIC_286, x=160, y=100
	play id=0x000A, freq=0x0C, vol=0x3F, channel=0x03
	break
	video offset=CINEMATIC_287, x=160, y=100
	break
	video offset=CINEMATIC_288, x=160, y=100
	break
	video offset=CINEMATIC_289, x=160, y=100
	break
	video offset=CINEMATIC_290, x=160, y=100
	break
	video offset=CINEMATIC_291, x=160, y=100
	break
	video offset=CINEMATIC_292, x=160, y=100
	break
	video offset=CINEMATIC_293, x=160, y=100
	break
	video offset=CINEMATIC_294, x=160, y=100
	play id=0x000A, freq=0x02, vol=0x3F, channel=0x01
	break
	video offset=CINEMATIC_295, x=160, y=100
	break
	video offset=CINEMATIC_296, x=160, y=100
	break
	video offset=CINEMATIC_297, x=160, y=100
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
	video offset=CINEMATIC_298, x=160, y=100
	selectVideoPage 0xFF
	break
	fill page=0xFF, color=0x00
	selectVideoPage 0x00
	video offset=CINEMATIC_299, x=160, y=100
	play id=0x000E, freq=0x02, vol=0x3F, channel=0x03
	selectVideoPage 0xFF
	break
	fill page=0xFF, color=0x08
	selectVideoPage 0x00
	video offset=CINEMATIC_300, x=160, y=100
	play id=0x000F, freq=0x02, vol=0x3F, channel=0x03
	selectVideoPage 0xFF
	break
	fill page=0xFF, color=0x00
	setup channel=0x3C, address=BLIT_AND_COPY_PAGE_FF_LOOP
	break
	setPalette 0x17
	play id=0x0003, freq=0x14, vol=0x0A, channel=0x03
	setup channel=0x04, address=SET_PALETTE_17_INIT_VAR_14
	setup channel=0x0B, address=PLAY_FX_2C_AND_DRAW_CIN_000
	setup channel=0x0C, address=DRAW_INTRO_DECOR_340
	setup channel=0x0D, address=DRAW_INTRO_DECOR_337
	setup channel=0x0E, address=DRAW_INTRO_DECOR_333
	setup channel=0x0F, address=DRAW_INTRO_DECOR_331
	setup channel=0x10, address=DRAW_INTRO_DECOR_329
	setup channel=0x11, address=DRAW_INTRO_DECOR_318
	setup channel=0x12, address=INIT_VAR_0D_THEN_LOOP
	setup channel=0x14, address=DRAW_INTRO_DECOR_305
	setup channel=0x15, address=DRAW_INTRO_DECOR_301
	mov [0x01], 0x0064

WAIT_100_THEN_CIN_274:
	break
	djnz [0x01], WAIT_100_THEN_CIN_274
	play id=0x0003, freq=0x14, vol=0x12, channel=0x03
	video offset=CINEMATIC_274, x=160, y=100
	break
	play id=0x0003, freq=0x14, vol=0x10, channel=0x03
	video offset=CINEMATIC_275, x=160, y=100
	break
	play id=0x0003, freq=0x14, vol=0x0E, channel=0x03
	video offset=CINEMATIC_276, x=160, y=100
	play id=0x000E, freq=0x02, vol=0x32, channel=0x03
	break
	play id=0x0003, freq=0x14, vol=0x0C, channel=0x03
	video offset=CINEMATIC_277, x=160, y=100
	play id=0x000E, freq=0x05, vol=0x32, channel=0x02
	break
	play id=0x0003, freq=0x14, vol=0x0A, channel=0x03
	video offset=CINEMATIC_278, x=160, y=100
	play id=0x000E, freq=0x01, vol=0x3F, channel=0x00
	break
	play id=0x0003, freq=0x14, vol=0x08, channel=0x03
	video offset=CINEMATIC_279, x=160, y=100
	break
	play id=0x0003, freq=0x14, vol=0x06, channel=0x03
	video offset=CINEMATIC_280, x=160, y=100
	setup channel=0x04, address=KILL_CHANNEL_ROUTINE
	play id=0x000E, freq=0x06, vol=0x3F, channel=0x01
	break
	play id=0x0003, freq=0x14, vol=0x04, channel=0x03
	video offset=CINEMATIC_281, x=160, y=100
	break
	setPalette 0x18
	play id=0x0003, freq=0x14, vol=0x02, channel=0x03
	video offset=CINEMATIC_282, x=160, y=100
	break
	setPalette 0x1A
	play id=0x000E, freq=0x00, vol=0x3F, channel=0x03
	video offset=CINEMATIC_282, x=160, y=100
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
	setup channel=0x12, address=INIT_VAR_0D_THEN_LOOP
	setup channel=0x0E, address=KILL_CHANNEL_ROUTINE
	setup channel=0x11, address=KILL_CHANNEL_ROUTINE
	setup channel=0x0F, address=KILL_CHANNEL_ROUTINE
	mov [0x01], 0x0014

WAIT_20_THEN_LOAD_3E82:
	break
	djnz [0x01], WAIT_20_THEN_LOAD_3E82
	load id=0x3E82
	killChannel

