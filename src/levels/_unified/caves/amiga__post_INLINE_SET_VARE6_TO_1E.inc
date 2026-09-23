DELAY_LOOP_VARE6_AT_1C9A:
	break
	djnz [0xE6], DELAY_LOOP_VARE6_AT_1C9A
	mov [0xE7], 0x00AA
	setup channel=0x36, address=CAVES_INLINE_SET_VAR01_TO_E_L2
	mov [0xE6], 0x000A

DELAY_LOOP_VARE6_AT_1CAB:
	break
	djnz [0xE6], DELAY_LOOP_VARE6_AT_1CAB
	mov [0xE7], 0x0064
	setup channel=0x36, address=CAVES_INLINE_SET_VAR01_TO_E_L2
	mov [0xE6], 0x0002
	or [0xB1], 0x0020

DELAY_LOOP_VARE6_AT_1CC0:
	break
	djnz [0xE6], DELAY_LOOP_VARE6_AT_1CC0
	mov [0xE8], 0x0082
	setup channel=0x39, address=CAVES_INLINE_SET_VAR01_TO_E_L3
	mov [0xE6], 0x0003

DELAY_LOOP_VARE6_AT_1CD1:
	break
	djnz [0xE6], DELAY_LOOP_VARE6_AT_1CD1
	setup channel=0x38, address=LABEL_1D69
	break
	break
	mov [0xE7], 0x0078
	setup channel=0x36, address=CAVES_INLINE_SET_VAR01_TO_E_L2
	break
	break
	break
	mov [0xE8], 0x008C
	setup channel=0x36, address=CAVES_INLINE_SET_VAR01_TO_E_L3
	break
	break
	mov [0xE7], 0x0096
	setup channel=0x39, address=CAVES_INLINE_SET_VAR01_TO_E_L2
	break
	break
	mov [0xE6], 0x0007

DELAY_LOOP_VARE6_AT_1CFF:
	break
	djnz [0xE6], DELAY_LOOP_VARE6_AT_1CFF
	mov [0xE7], 0x0078
	setup channel=0x36, address=CAVES_INLINE_SET_VAR01_TO_E_L2
	mov [0xE6], 0x000A

DELAY_LOOP_VARE6_AT_1D10:
	break
	djnz [0xE6], DELAY_LOOP_VARE6_AT_1D10
	mov [0xE8], 0x0064
	setup channel=0x39, address=CAVES_INLINE_SET_VAR01_TO_E_L3
	break
	break
	mov [0xE7], 0x0078
	setup channel=0x36, address=CAVES_INLINE_SET_VAR01_TO_E_L2
	break
	break
	break
	mov [0xE8], 0x008C
	setup channel=0x36, address=CAVES_INLINE_SET_VAR01_TO_E_L3
	break
	break
	mov [0xE7], 0x0064
	setup channel=0x39, address=CAVES_INLINE_SET_VAR01_TO_E_L2
	break
	break
	break
	setup channel=0x36, address=LABEL_1E39
	mov [0xE6], 0x0003

DELAY_LOOP_VARE6_AT_1D47:
	break
	djnz [0xE6], DELAY_LOOP_VARE6_AT_1D47
	setup channel=0x38, address=LABEL_1F82
	break
	setup channel=0x39, address=KILL_CHANNEL_LANDING
	break
	break
	break
	break
	setup channel=0x3A, address=LABEL_1EDE
	break
	play id=0x0066, freq=0x04, vol=0x10, channel=0x02
	mov [0x74], 0x4018
	killChannel

LABEL_1D69:
	video offset=CINEMATIC_261, x=65506, y=114
	video offset=CINEMATIC_262, x=65506, y=114
	break
	play id=0x0060, freq=0x14, vol=0x28, channel=0x00
	video offset=CINEMATIC_261, x=7, y=116
	video offset=CINEMATIC_263, x=7, y=116
	break
	video offset=CINEMATIC_261, x=43, y=120
	video offset=CINEMATIC_264, x=43, y=120
	break
	video offset=CINEMATIC_261, x=75, y=121
	video offset=CINEMATIC_265, x=75, y=121
	break
	video offset=CINEMATIC_261, x=119, y=116
	video offset=CINEMATIC_265, x=124, y=116
	break
	video offset=CINEMATIC_261, x=153, y=118
	video offset=CINEMATIC_264, x=153, y=118
	break
	video offset=CINEMATIC_261, x=190, y=120
	video offset=CINEMATIC_264, x=190, y=120
	break
	video offset=CINEMATIC_261, x=223, y=117
	video offset=CINEMATIC_263, x=223, y=117
	break
	video offset=CINEMATIC_261, x=266, y=112
	video offset=CINEMATIC_262, x=266, y=112
	break
	video offset=CINEMATIC_261, x=301, y=114
	video offset=CINEMATIC_263, x=301, y=114
	break
	video offset=CINEMATIC_261, x=331, y=114
	video offset=CINEMATIC_264, x=331, y=114
	break
	killChannel
	video offset=CINEMATIC_261, x=65506, y=114
	break
	video type=0, offset=CV_FIGURE_RUN_RIGHT_UPPER_POSE_01, x=160, y=100, zoom=0x40
	video type=0, offset=CV_FIGURE_RUN_RIGHT_UPPER_POSE_02, x=180, y=100, zoom=0x40
	video type=0, offset=CV_FIGURE_RUN_RIGHT_UPPER_POSE_03, x=200, y=100, zoom=0x40
	video type=0, offset=CV_FIGURE_RUN_RIGHT_UPPER_POSE_04, x=220, y=100, zoom=0x40
	video type=0, offset=CV_FIGURE_RUN_RIGHT_UPPER_POSE_05, x=240, y=100, zoom=0x40
	video type=0, offset=CV_2276, x=260, y=100, zoom=0x40
	video type=0, offset=CV_FIGURE_RUN_RIGHT_UPPER_POSE_00, x=280, y=100, zoom=0x40
	break
	video offset=CINEMATIC_261, x=121, y=118
	break
	video offset=CINEMATIC_261, x=154, y=120
	break
	video offset=CINEMATIC_261, x=186, y=116
	break
	video offset=CINEMATIC_261, x=219, y=112
	break
	video offset=CINEMATIC_261, x=251, y=114
	break
	video offset=CINEMATIC_261, x=281, y=116
	break
	video offset=CINEMATIC_261, x=310, y=117
	break
	video offset=CINEMATIC_261, x=329, y=118
	break
	video offset=CINEMATIC_261, x=352, y=114
	killChannel

LABEL_1E39:
	video offset=CINEMATIC_261, x=65506, y=114
	video offset=CINEMATIC_262, x=65506, y=114
	video offset=CINEMATIC_266, x=65506, y=114
	break
	play id=0x0055, freq=0x14, vol=0x32, channel=0x02
	video offset=CINEMATIC_261, x=7, y=116
	video offset=CINEMATIC_263, x=7, y=116
	video offset=CINEMATIC_266, x=7, y=116
	break
	video offset=CINEMATIC_261, x=43, y=120
	video offset=CINEMATIC_264, x=43, y=120
	video offset=CINEMATIC_266, x=43, y=120
	break
	video offset=CINEMATIC_261, x=75, y=121
	video offset=CINEMATIC_265, x=75, y=121
	video offset=CINEMATIC_266, x=75, y=121
	break
	video offset=CINEMATIC_261, x=119, y=116
	video offset=CINEMATIC_265, x=124, y=116
	video offset=CINEMATIC_266, x=119, y=116
	break
	video offset=CINEMATIC_261, x=153, y=118
	video offset=CINEMATIC_264, x=153, y=118
	video offset=CINEMATIC_266, x=153, y=118
	break
	video offset=CINEMATIC_261, x=190, y=120
	video offset=CINEMATIC_264, x=190, y=120
	video offset=CINEMATIC_266, x=190, y=120
	break
	video offset=CINEMATIC_261, x=223, y=117
	video offset=CINEMATIC_263, x=223, y=117
	video offset=CINEMATIC_266, x=223, y=117
	break
	video offset=CINEMATIC_261, x=266, y=112
	video offset=CINEMATIC_262, x=266, y=112
	video offset=CINEMATIC_266, x=266, y=112
	break
	video offset=CINEMATIC_261, x=301, y=114
	video offset=CINEMATIC_263, x=301, y=114
	video offset=CINEMATIC_266, x=301, y=114
	break
	video offset=CINEMATIC_261, x=331, y=114
	video offset=CINEMATIC_264, x=331, y=114
	video offset=CINEMATIC_266, x=331, y=114
	break
	killChannel

LABEL_1EDE:
	video offset=CINEMATIC_261, x=65506, y=114
	video offset=CINEMATIC_262, x=65506, y=114
	video offset=CINEMATIC_267, x=65506, y=114
	break
	play id=0x0055, freq=0x12, vol=0x32, channel=0x01
	video offset=CINEMATIC_261, x=7, y=116
	video offset=CINEMATIC_263, x=7, y=116
	video offset=CINEMATIC_267, x=7, y=116
	break
	video offset=CINEMATIC_261, x=43, y=120
	video offset=CINEMATIC_264, x=43, y=120
	video offset=CINEMATIC_267, x=43, y=120
	break
	video offset=CINEMATIC_261, x=75, y=121
	video offset=CINEMATIC_265, x=75, y=121
	video offset=CINEMATIC_267, x=75, y=121
	break
	video offset=CINEMATIC_261, x=119, y=116
	video offset=CINEMATIC_265, x=124, y=116
	video offset=CINEMATIC_267, x=119, y=116
	break
	video offset=CINEMATIC_261, x=153, y=118
	video offset=CINEMATIC_264, x=153, y=118
	video offset=CINEMATIC_267, x=153, y=118
	break
	video offset=CINEMATIC_261, x=190, y=120
	video offset=CINEMATIC_264, x=190, y=120
	video offset=CINEMATIC_267, x=190, y=120
	break
	video offset=CINEMATIC_261, x=223, y=117
	video offset=CINEMATIC_263, x=223, y=117
	video offset=CINEMATIC_267, x=223, y=117
	break
	video offset=CINEMATIC_261, x=266, y=112
	video offset=CINEMATIC_262, x=266, y=112
	video offset=CINEMATIC_267, x=266, y=112
	break
	video offset=CINEMATIC_261, x=301, y=114
	video offset=CINEMATIC_263, x=301, y=114
	video offset=CINEMATIC_267, x=301, y=114
	break
	video offset=CINEMATIC_261, x=331, y=114
	video offset=CINEMATIC_264, x=331, y=114
	video offset=CINEMATIC_267, x=331, y=114
	killChannel

LABEL_1F82:
	video offset=CINEMATIC_261, x=65506, y=114
	video offset=CINEMATIC_262, x=65506, y=114
	video offset=CINEMATIC_268, x=65506, y=114
	break
	play id=0x0055, freq=0x17, vol=0x28, channel=0x00
	video offset=CINEMATIC_261, x=7, y=116
	video offset=CINEMATIC_263, x=7, y=116
	video offset=CINEMATIC_268, x=7, y=116
	break
	video offset=CINEMATIC_261, x=43, y=120
	video offset=CINEMATIC_264, x=43, y=120
	video offset=CINEMATIC_268, x=43, y=120
	break
	video offset=CINEMATIC_261, x=75, y=121
	video offset=CINEMATIC_265, x=75, y=121
	video offset=CINEMATIC_268, x=75, y=121
	break
	video offset=CINEMATIC_261, x=119, y=116
	video offset=CINEMATIC_265, x=124, y=116
	video offset=CINEMATIC_268, x=119, y=116
	break
	video offset=CINEMATIC_261, x=153, y=118
	video offset=CINEMATIC_264, x=153, y=118
	video offset=CINEMATIC_268, x=153, y=118
	break
	video offset=CINEMATIC_261, x=190, y=120
	video offset=CINEMATIC_264, x=190, y=120
	video offset=CINEMATIC_268, x=190, y=120
	break
	video offset=CINEMATIC_261, x=223, y=117
	video offset=CINEMATIC_263, x=223, y=117
	video offset=CINEMATIC_268, x=223, y=117
	break
	video offset=CINEMATIC_261, x=266, y=112
	video offset=CINEMATIC_262, x=266, y=112
	video offset=CINEMATIC_268, x=266, y=112
	break
	video offset=CINEMATIC_261, x=301, y=114
	video offset=CINEMATIC_263, x=301, y=114
	video offset=CINEMATIC_268, x=301, y=114
	break
	video offset=CINEMATIC_261, x=331, y=114
	video offset=CINEMATIC_264, x=331, y=114
	video offset=CINEMATIC_268, x=331, y=114
	killChannel

LABEL_2026:
	setPalette 0x11
	jl [HERO_X], 0xAE, LABEL_2038
	jg [HERO_X], 0xE1, LABEL_2038
	setPalette 0x09

LABEL_2038:
	break
	jmp LABEL_2026
LABEL_203C:
	db 0x11

CAVES_WATERFALL_DRIP_LOOP:
	call SETUP_HASH_AND_DERIVE_BUCKETS
	mov [0xE8], [0x3D]
	add [0xE8], 0x008E
	mov [0xE7], 0x00A6
	video offset=CINEMATIC_CAVES_WATERFALL_DRIP_F0, x=[0xe8], y=[0xe7]
	break
	video offset=CINEMATIC_CAVES_WATERFALL_DRIP_F1, x=[0xe8], y=[0xe7]
	break
	video offset=CINEMATIC_CAVES_WATERFALL_DRIP_F2, x=[0xe8], y=[0xe7]
	break
	video offset=CINEMATIC_CAVES_WATERFALL_DRIP_F3, x=[0xe8], y=[0xe7]
	break
	video offset=CINEMATIC_CAVES_WATERFALL_DRIP_F4, x=[0xe8], y=[0xe7]
	break
	video offset=CINEMATIC_CAVES_WATERFALL_DRIP_F5, x=[0xe8], y=[0xe7]
	break
	video offset=CINEMATIC_CAVES_WATERFALL_DRIP_F6, x=[0xe8], y=[0xe7]
	break
	video offset=CINEMATIC_CAVES_WATERFALL_DRIP_F7, x=[0xe8], y=[0xe7]
	break
	video offset=CINEMATIC_CAVES_WATERFALL_DRIP_F8, x=[0xe8], y=[0xe7]
	mov [0xE8], 0x000A

DELAY_LOOP_VARE8_AT_2084:
	break
	djnz [0xE8], DELAY_LOOP_VARE8_AT_2084
	jmp CAVES_WATERFALL_DRIP_LOOP
LABEL_208C:
	db 0x11, 0x00, 0xE6, 0x00, 0x00, 0x00, 0xE7, 0x00
	db 0x00, 0x00, 0xE9, 0x00, 0x32, 0x00, 0xE8, 0x00
	db 0x50, 0x00, 0xE6, 0x00, 0x00, 0x03, 0xE6, 0x00
	db 0x04, 0x01, 0xF8, 0xE6, 0x17, 0xF8, 0x00, 0x04
	db 0x02, 0xF8, 0xE7, 0x54, 0x57, 0x3A, 0xE6, 0xF8
	db 0x09, 0xE8, 0x20, 0xA1, 0x03, 0xE7, 0x00, 0x04
	db 0x09, 0xE9, 0x20, 0x99, 0x05, 0x11

HANG_DRAW_CIN_330:
	video offset=CINEMATIC_330, x=160, y=100
	break
	jmp HANG_DRAW_CIN_330
LABEL_20CA:
	db 0x11

HANG_DRAW_CIN_331:
	video offset=CINEMATIC_331, x=160, y=100
	break
	jmp HANG_DRAW_CIN_331
LABEL_20D3:
	db 0x11

LABEL_20D4:
	break
	break
	break
	break
	video offset=CINEMATIC_339, x=65522, y=182
	break
	video offset=CINEMATIC_339, x=65530, y=188
	break
	video offset=CINEMATIC_339, x=2, y=194
	break
	video offset=CINEMATIC_339, x=6, y=198
	break
	video offset=CINEMATIC_339, x=13, y=203, zoom=0x40
	break
	video offset=CINEMATIC_339, x=18, y=206, zoom=0x40
	killChannel

LABEL_20FC:
	mov [0xE6], 0x000A
	mov [0xF8], [0xB2]
	and [0xF8], 0x0040
	jne [0xF8], 0x00, INIT_VARS_E6_68_69_6B
	or [0xB2], 0x0040

DELAY_LOOP_VARE6_AT_2111:
	break
	djnz [0xE6], DELAY_LOOP_VARE6_AT_2111
	video offset=CINEMATIC_BUDDY_CRAWLING_STUCK_AT_RING, x=15, y=178
	break
	video offset=CINEMATIC_BUDDY_CRAWLING_STUCK_AT_RING, x=30, y=185
	break
	play id=0x0060, freq=0x05, vol=0x40, channel=0x03
	mov [0x6B], 0x0200
	mov [0x68], 0x002A
	video offset=CINEMATIC_318, x=[0x68], y=184
	break
	add [0x68], 0x000B
	video offset=CINEMATIC_318, x=[0x68], y=184
	break
	add [0x68], 0x0008
	video offset=CINEMATIC_318, x=[0x68], y=184
	break
	add [0x68], 0x0006
	video offset=CINEMATIC_318, x=[0x68], y=184
	break
	add [0x68], 0x0004
	video offset=CINEMATIC_319, x=[0x68], y=184
	break
	add [0x68], 0x0003
	video offset=CINEMATIC_319, x=[0x68], y=184
	break
	add [0x68], 0x0003
	video offset=CINEMATIC_319, x=[0x68], y=184
	break
	add [0x68], 0x0002
	video offset=CINEMATIC_320, x=[0x68], y=184
	break
	add [0x68], 0x0002
	video offset=CINEMATIC_320, x=[0x68], y=184
	break
	video offset=CINEMATIC_320, x=[0x68], y=184
	add [0x68], 0x0001
	mov [0xE6], 0x0014

LABEL_2191:
	break
	video offset=CINEMATIC_320, x=[0x68], y=184
	djnz [0xE6], LABEL_2191
	break
	video offset=CINEMATIC_321, x=[0x68], y=184
	break
	video offset=CINEMATIC_321, x=[0x68], y=184
	break
	video offset=CINEMATIC_322, x=[0x68], y=184
	break
	video offset=CINEMATIC_322, x=[0x68], y=184
	mov [0x69], 0x00BA
	mov [0xE6], 0x0001

LABEL_21BB:
	break
	video offset=CINEMATIC_323, x=[0x68], y=[0x69]
	djnz [0xE6], LABEL_21BB
	break
	video offset=CINEMATIC_324, x=[0x68], y=[0x69]
	break
	video offset=CINEMATIC_324, x=[0x68], y=[0x69]
	break
	video offset=CINEMATIC_310, x=[0x68], y=[0x69]
	mov [0xE6], 0x0005

CAVES_BUDDY_ARRIVAL_HOLD_PHASE_3:
	break
	video offset=CINEMATIC_314, x=[0x68], y=[0x69]
	djnz [0xE6], CAVES_BUDDY_ARRIVAL_HOLD_PHASE_3
	mov [0xE6], 0x0005

CAVES_BUDDY_ARRIVAL_HOLD_PHASE_4:
	break
	video offset=CINEMATIC_323, x=[0x68], y=[0x69]
	djnz [0xE6], CAVES_BUDDY_ARRIVAL_HOLD_PHASE_4
	mov [0xE6], 0x0008

LABEL_21F7:
	break
	video offset=CINEMATIC_323, x=[0x68], y=[0x69]
	break
	video offset=CINEMATIC_323, x=[0x68], y=[0x69]
	add [0x68], 0x0003
	break
	video offset=CINEMATIC_325, x=[0x68], y=[0x69]
	break
	video offset=CINEMATIC_325, x=[0x68], y=[0x69]
	add [0x68], 0x0003
	break
	video offset=CINEMATIC_326, x=[0x68], y=[0x69]
	break
	video offset=CINEMATIC_326, x=[0x68], y=[0x69]
	add [0x68], 0x0002
	break
	video offset=CINEMATIC_327, x=[0x68], y=[0x69]
	break
	video offset=CINEMATIC_327, x=[0x68], y=[0x69]
	add [0x68], 0x0003
	break
	video offset=CINEMATIC_328, x=[0x68], y=[0x69]
	break
	video offset=CINEMATIC_328, x=[0x68], y=[0x69]
	add [0x68], 0x0003
	break
	video offset=CINEMATIC_329, x=[0x68], y=[0x69]
	break
	video offset=CINEMATIC_329, x=[0x68], y=[0x69]
	add [0x68], 0x0003
	djnz [0xE6], LABEL_21F7
