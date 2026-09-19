HANDLE_HERO_LR_INPUT:
	je [0x62], 0x16, TANK_PANEL_CURSOR_RIGHT_EDGE_CLAMP
	je [0x62], 0x0E, TANK_PANEL_CURSOR_RIGHT_EDGE_CLAMP
	je [HERO_POS_LEFT_RIGHT], 0x00, TANK_PANEL_CURSOR_RESTORE_PREV_CELL
	sub [0x5F], [HERO_POS_LEFT_RIGHT]
	mov [HERO_POS_LEFT_RIGHT], 0x0000
	jmp TANK_HERO_67_5F_DISPATCH
LABEL_0A86:
	db 0x05

HANDLE_HERO_UD_INPUT:
	je [HERO_POS_UP_DOWN], 0x00, TANK_PANEL_CURSOR_RESTORE_PREV_CELL
	shl [HERO_POS_UP_DOWN], 0x0003
	sub [0x5F], [HERO_POS_UP_DOWN]
	mov [HERO_POS_UP_DOWN], 0x0000
	jmp TANK_HERO_67_5F_DISPATCH
LABEL_0A9B:
	db 0x05

TANK_PANEL_CELL_SCREEN_POSITION_LOOKUP:
	jne [0x59], 0x00, LABEL_0AAB
	mov [0x5A], 0x0022
	mov [0x5B], 0x0019
	ret


LABEL_0AAB:
	jne [0x59], 0x01, LABEL_0ABA
	mov [0x5A], 0x0026
	mov [0x5B], 0x001B
	ret


LABEL_0ABA:
	jne [0x59], 0x02, LABEL_0AC9
	mov [0x5A], 0x002A
	mov [0x5B], 0x001E
	ret


LABEL_0AC9:
	jne [0x59], 0x0E, LABEL_0AD8
	mov [0x5A], 0x004A
	mov [0x5B], 0x002B
	ret


LABEL_0AD8:
	jne [0x59], 0x08, LABEL_0AE7
	mov [0x5A], 0x0022
	mov [0x5B], 0x001F
	ret


LABEL_0AE7:
	jne [0x59], 0x09, LABEL_0AF6
	mov [0x5A], 0x0026
	mov [0x5B], 0x0021
	ret


LABEL_0AF6:
	jne [0x59], 0x0B, LABEL_0B05
	mov [0x5A], 0x0031
	mov [0x5B], 0x0027
	ret


LABEL_0B05:
	jne [0x59], 0x0C, LABEL_0B14
	mov [0x5A], 0x0035
	mov [0x5B], 0x002A
	ret


LABEL_0B14:
	jne [0x59], 0x10, LABEL_0B23
	mov [0x5A], 0x0022
	mov [0x5B], 0x0025
	ret


LABEL_0B23:
	jne [0x59], 0x11, LABEL_0B32
	mov [0x5A], 0x0026
	mov [0x5B], 0x0027
	ret


LABEL_0B32:
	jne [0x59], 0x12, LABEL_0B41
	mov [0x5A], 0x002B
	mov [0x5B], 0x002A
	ret


LABEL_0B41:
	jne [0x59], 0x13, LABEL_0B50
	mov [0x5A], 0x0031
	mov [0x5B], 0x0030
	ret


LABEL_0B50:
	jne [0x59], 0x14, LABEL_0B5F
	mov [0x5A], 0x0035
	mov [0x5B], 0x0032
	ret


LABEL_0B5F:
	jne [0x59], 0x15, LABEL_0B6E
	mov [0x5A], 0x0040
	mov [0x5B], 0x0035
	ret


LABEL_0B6E:
	jne [0x59], 0x16, LABEL_0B7D
	mov [0x5A], 0x004A
	mov [0x5B], 0x0036
	ret


LABEL_0B7D:
	jne [0x59], 0x18, LABEL_0B8C
	mov [0x5A], 0x0022
	mov [0x5B], 0x002C
	ret


LABEL_0B8C:
	jne [0x59], 0x19, LABEL_0B9B
	mov [0x5A], 0x0026
	mov [0x5B], 0x002D
	ret


LABEL_0B9B:
	jne [0x59], 0x1A, LABEL_0BAA
	mov [0x5A], 0x002A
	mov [0x5B], 0x0033
	ret


LABEL_0BAA:
	jne [0x59], 0x1B, LABEL_0BB9
	mov [0x5A], 0x0031
	mov [0x5B], 0x0038
	ret


LABEL_0BB9:
	jne [0x59], 0x1C, LABEL_0BC8
	mov [0x5A], 0x0035
	mov [0x5B], 0x003A
	ret


LABEL_0BC8:
	jne [0x59], 0x1D, LABEL_0BD7
	mov [0x5A], 0x0040
	mov [0x5B], 0x003B
	ret


LABEL_0BD7:
	jne [0x59], 0x21, LABEL_0BE6
	mov [0x5A], 0x0026
	mov [0x5B], 0x0035
	ret


LABEL_0BE6:
	jne [0x59], 0x22, SHARED_RET
	mov [0x5A], 0x002B
	mov [0x5B], 0x003B
	ret


DRAW_CIN_SEQ_189_190_191:
	video offset=CINEMATIC_189, x=[0x60], y=[0x61]
	video offset=CINEMATIC_190, x=[0x5d], y=[0x5e]
	video offset=CINEMATIC_191, x=160, y=100
	ret


TANK_CONSOLE_HAND_HOVER_LOOP:
	jne [0x5C], 0xFFFF, LABEL_0C18
	mov [0x5D], [0x60]
	mov [0x5E], [0x61]
	call DRAW_CIN_SEQ_189_190_191
	break
	jmp TANK_CONSOLE_HAND_HOVER_LOOP

LABEL_0C18:
	mov [0x59], [0x5C]
	call TANK_PANEL_CELL_SCREEN_POSITION_LOOKUP
	mov [0x5D], [0x5A]
	mov [0x5E], [0x5B]
	add [0x5D], 0x000A
	add [0x5D], 0x000A
	mov [0x59], [0x5C]
	call TANK_PANEL_CELL_SCREEN_POSITION_LOOKUP
	video offset=CINEMATIC_188, x=[0x5a], y=[0x5b]
	call DRAW_CIN_SEQ_189_190_191
	break
	mov [0x5C], 0xFFFF
	jmp TANK_CONSOLE_HAND_HOVER_LOOP
LABEL_0C42:
	db 0x11

LABEL_0C43:
	mov [0x62], [0x5F]
	add [0x5F], [HERO_POS_LEFT_RIGHT]
	mov [0xF8], [HERO_POS_UP_DOWN]
	shl [0xF8], 0x0003
	add [0x5F], [0xF8]
	call TANK_HERO_67_5F_DISPATCH
	mov [0x59], [0x5F]
	call TANK_PANEL_CELL_SCREEN_POSITION_LOOKUP
	mov [0x60], [0x5A]
	mov [0x61], [0x5B]
	video offset=CINEMATIC_189, x=[0x60], y=[0x61]
	je [HERO_ACTION], 0x00, LABEL_0C76
	call LABEL_0CC0
	call LABEL_0C93
	mov [0x5C], [0x5F]

LABEL_0C76:
	break
	jmp LABEL_0C43
LABEL_0C7A:
	db 0x11

LABEL_0C7B:
	selectVideoPage 0x00
	video offset=CINEMATIC_188, x=43, y=40
	selectVideoPage 0xFF
	break
	break
	selectVideoPage 0x00
	video offset=CINEMATIC_199, x=43, y=40
	selectVideoPage 0xFF
	break
	break
	jmp LABEL_0C7B
LABEL_0C92:
	db 0x11

LABEL_0C93:
	je [SCREEN_NUM], 0x06, SHARED_RET
	je [0x71], 0x00, SHARED_RET
	je [0x72], 0x00, SHARED_RET
	je [0x74], 0x00, SHARED_RET
	je [0x75], 0x00, SHARED_RET
	jg [SCREEN_NUM], 0x06, SHARED_RET
	mov [SCREEN_NUM], 0x0006
	setup channel=0x06, address=LABEL_0C7B
	ret


LABEL_0CC0:
	jne [0x59], 0x00, LABEL_0CCB
	mov [0x63], 0x0001
	ret


LABEL_0CCB:
	jne [0x59], 0x01, LABEL_0CD6
	mov [0x57], 0x0001
	ret


LABEL_0CD6:
	jne [0x59], 0x02, LABEL_0CE1
	mov [0x47], 0x0001
	ret


LABEL_0CE1:
	jne [0x59], 0x0E, LABEL_0CEC
	mov [0x57], 0x0001
	ret


LABEL_0CEC:
	jne [0x59], 0x08, LABEL_0D1B
	video offset=CINEMATIC_197, x=35, y=43
	video offset=CINEMATIC_198, x=39, y=45
	selectVideoPage 0x00
	je [0x71], 0x00, LABEL_0D10
	jmp LABEL_0D10
	video offset=CINEMATIC_197, x=35, y=31
	selectVideoPage 0xFF
	mov [0x71], 0x0000
	ret


LABEL_0D10:
	video offset=CINEMATIC_195, x=35, y=31
	selectVideoPage 0xFF
	mov [0x71], 0x0001
	ret


LABEL_0D1B:
	jne [0x59], 0x09, LABEL_0D42
	selectVideoPage 0x00
	je [0x74], 0x00, LABEL_0D37
	jmp LABEL_0D37
	video offset=CINEMATIC_197, x=39, y=33
	mov [0x74], 0x0000
	selectVideoPage 0xFF
	ret


LABEL_0D37:
	video offset=CINEMATIC_194, x=39, y=33
	mov [0x74], 0x0001
	selectVideoPage 0xFF
	ret


LABEL_0D42:
	jne [0x59], 0x0B, LABEL_0D4C
	call LABEL_1C6E
	ret


LABEL_0D4C:
	jne [0x59], 0x0C, LABEL_0D57
	add [0x4F], 0x000A
	ret


LABEL_0D57:
	jne [0x59], 0x10, LABEL_0D7E
	selectVideoPage 0x00
	je [0x72], 0x00, LABEL_0D73
	jmp LABEL_0D73
	video offset=CINEMATIC_197, x=35, y=37
	selectVideoPage 0xFF
	mov [0x72], 0x0000
	ret


LABEL_0D73:
	video offset=CINEMATIC_195, x=35, y=37
	selectVideoPage 0xFF
	mov [0x72], 0x0001
	ret


LABEL_0D7E:
	jne [0x59], 0x11, LABEL_0DA5
	selectVideoPage 0x00
	je [0x75], 0x00, TANK_CONSOLE_BUTTON_ACTION_CASE_13
	jmp TANK_CONSOLE_BUTTON_ACTION_CASE_13
	video offset=CINEMATIC_197, x=39, y=39
	selectVideoPage 0xFF
	mov [0x75], 0x0000
	ret


TANK_CONSOLE_BUTTON_ACTION_CASE_13:
	video offset=CINEMATIC_194, x=39, y=39
	selectVideoPage 0xFF
	mov [0x75], 0x0001
	ret


LABEL_0DA5:
	jne [0x59], 0x13, TANK_CONSOLE_BUTTON_ACTION_CASE_15
	call LABEL_1C78
	ret


TANK_CONSOLE_BUTTON_ACTION_CASE_15:
	jne [0x59], 0x14, TANK_CONSOLE_BUTTON_ACTION_CASE_16
	add [0x37], 0x0001
	ret


TANK_CONSOLE_BUTTON_ACTION_CASE_16:
	jne [0x59], 0x15, TANK_CONSOLE_BUTTON_ACTION_CASE_18
	mov [0x3E], 0x000A
	ret


TANK_CONSOLE_BUTTON_ACTION_CASE_18:
	jne [0x59], 0x16, LABEL_0DD0
	mov [0x56], 0x0001
	ret


LABEL_0DD0:
	jne [0x59], 0x18, TANK_CONSOLE_BUTTON_ACTION_CASE_1A
	ret


	selectVideoPage 0x00
	video offset=CINEMATIC_195, x=39, y=29
	selectVideoPage 0xFF
	jg [SCREEN_NUM], 0x05, SHARED_RET
	mov [SCREEN_NUM], 0x0005
	ret


TANK_CONSOLE_BUTTON_ACTION_CASE_1A:
	jne [0x59], 0x19, LABEL_0DF5
	mov [0x47], 0x0001
	ret


LABEL_0DF5:
	jne [0x59], 0x1A, TANK_CONSOLE_BUTTON_ACTION_CASE_1C
	call TANK_SCENE_INIT_FILL_PAGE_3_COLOR_0C
	ret


TANK_CONSOLE_BUTTON_ACTION_CASE_1C:
	jne [0x59], 0x1B, TANK_CONSOLE_BUTTON_ACTION_CASE_1D
	add [0x41], 0x000A
	ret


TANK_CONSOLE_BUTTON_ACTION_CASE_1D:
	jne [0x59], 0x1C, TANK_CONSOLE_BUTTON_ACTION_CASE_21
	add [0x37], 0x000A
	ret


TANK_CONSOLE_BUTTON_ACTION_CASE_21:
	jne [0x59], 0x1D, LABEL_0E20
	mov [0x47], 0x0001
	ret


LABEL_0E20:
	jne [0x59], 0x21, TANK_DRAW_CIN_225_AT_160_100_FOREVER
	ret


TANK_DRAW_CIN_225_AT_160_100_FOREVER:
	jne [0x59], 0x12, SHARED_RET
	mov [0x63], 0x0001
	ret


LABEL_0E32:
	break
	video offset=CINEMATIC_000, x=152, y=5
	video offset=CINEMATIC_TANK_HORIZON_DECOR_1, x=242, y=65535
	break
	video offset=CINEMATIC_TANK_HORIZON_DECOR_2, x=257, y=23
	video offset=CINEMATIC_TANK_HORIZON_DECOR_3, x=147, y=33
	break
	video offset=CINEMATIC_000, x=144, y=53
	video offset=CINEMATIC_TANK_HORIZON_DECOR_1, x=269, y=41
	break
	video offset=CINEMATIC_TANK_HORIZON_DECOR_0, x=127, y=72
	video offset=CINEMATIC_TANK_HORIZON_DECOR_3, x=269, y=67
	break
	video offset=CINEMATIC_000, x=111, y=86
	video offset=CINEMATIC_TANK_HORIZON_DECOR_1, x=273, y=90
	break
	video offset=CINEMATIC_TANK_HORIZON_DECOR_4, x=90, y=98
	video offset=CINEMATIC_TANK_HORIZON_DECOR_2, x=273, y=110
	break
	video offset=CINEMATIC_TANK_HORIZON_DECOR_0, x=64, y=107
	video offset=CINEMATIC_TANK_HORIZON_DECOR_2, x=268, y=118
	video offset=CINEMATIC_006, x=178, y=3
	break
	video offset=CINEMATIC_TANK_HORIZON_DECOR_0, x=42, y=122
	video offset=CINEMATIC_TANK_HORIZON_DECOR_1, x=259, y=129
	video offset=CINEMATIC_006, x=172, y=70, zoom=0x64
	break
	video offset=CINEMATIC_TANK_HORIZON_DECOR_0, x=21, y=134
	video offset=CINEMATIC_TANK_HORIZON_DECOR_1, x=278, y=141
	video offset=CINEMATIC_006, x=172, y=143, zoom=0x8e
	break
	video offset=CINEMATIC_000, x=4, y=149
	video offset=CINEMATIC_TANK_HORIZON_DECOR_3, x=287, y=148
	video offset=CINEMATIC_006, x=172, y=250, zoom=0xdc
	selectVideoPage 0x03
	play id=0x008C, freq=0x1E, vol=0x40, channel=0x01
	play id=0x008C, freq=0x0A, vol=0x40, channel=0x00
	mov [0x70], 0x0001
	video offset=CINEMATIC_TANK_HORIZON_DECOR_PAGE3_0, x=160, y=100
	video offset=CINEMATIC_TANK_HORIZON_DECOR_PAGE3_1, x=160, y=100
	video offset=CINEMATIC_TANK_HORIZON_DECOR_PAGE3_2, x=160, y=100
	selectVideoPage 0xFF
	setup channel=0x3C, address=PALETTE_FLASH_1F_TO_01
	unfreezeChannels first=0x27, last=0x38
	unfreezeChannels first=0x02, last=0x02
	break
	play id=0x008C, freq=0x1E, vol=0x40, channel=0x01
	fill page=0xFF, color=0x02
	break
	mov [PAUSE_SLICES], 0x0005
	setPalette 0x06
	video offset=CINEMATIC_TANK_HORIZON_DECOR_PAGE3_3, x=160, y=100
	break
	setPalette 0x05
	play id=0x008C, freq=0x05, vol=0x40, channel=0x00
	video offset=CINEMATIC_TANK_HORIZON_DECOR_PAGE3_4, x=198, y=49
	video offset=CINEMATIC_TANK_HORIZON_DECOR_PAGE3_4, x=87, y=66
	video offset=CINEMATIC_012, x=160, y=100
	break
	setPalette 0x04
	video offset=CINEMATIC_013, x=315, y=58
	video offset=CINEMATIC_013, x=86, y=57
	video offset=CINEMATIC_TANK_HORIZON_DECOR_PAGE3_4, x=198, y=91
	video offset=CINEMATIC_014, x=160, y=100
	break
	setPalette 0x03
	video offset=CINEMATIC_015, x=91, y=58
	video offset=CINEMATIC_016, x=306, y=56
	video offset=CINEMATIC_013, x=199, y=98
	video offset=CINEMATIC_017, x=160, y=100
	freezeChannels first=0x27, last=0x38
	break
	play id=0x008C, freq=0x14, vol=0x40, channel=0x01
	setPalette 0x02
	video offset=CINEMATIC_016, x=195, y=110
	video offset=CINEMATIC_018, x=160, y=100
	break
	setPalette 0x01
	video offset=CINEMATIC_015, x=50, y=111
	video offset=CINEMATIC_015, x=140, y=114
	video offset=CINEMATIC_015, x=207, y=104
	video offset=CINEMATIC_015, x=261, y=108
	break
	video offset=CINEMATIC_016, x=50, y=111
	video offset=CINEMATIC_016, x=140, y=114
	video offset=CINEMATIC_016, x=209, y=114
	video offset=CINEMATIC_016, x=261, y=110
	freezeChannels first=0x02, last=0x02
	killChannel

LABEL_0F71:
	break
	je [0x57], 0x00, LABEL_0F71
	setup channel=0x31, address=TANK_SHOT_LAUNCH_STREAK_ON_FIRE_TRIGGER
	setup channel=0x22, address=TANK_PROJECTILE_ARC_AND_EXPLOSION
	mov [0x46], 0x0000
	mov [0x56], 0x0000
	break
	mov [0x46], 0x0001
	break
	mov [0x56], 0x0001
	play id=0x008E, freq=0x0F, vol=0x40, channel=0x01
	video offset=CINEMATIC_019, x=199, y=128
	break
	video offset=CINEMATIC_TANK_HORIZON_DECOR_2, x=203, y=129
	break
	video offset=CINEMATIC_TANK_HORIZON_DECOR_2, x=208, y=137
	break
	video offset=CINEMATIC_019, x=219, y=142
	break
	video offset=CINEMATIC_020, x=231, y=136
	break
	video offset=CINEMATIC_021, x=242, y=125
	break
	video offset=CINEMATIC_021, x=252, y=103
	break
	video offset=CINEMATIC_021, x=262, y=76
	break
	video offset=CINEMATIC_020, x=267, y=57
	break
	video offset=CINEMATIC_020, x=274, y=41
	break
	video offset=CINEMATIC_021, x=279, y=21
	break
	video offset=CINEMATIC_021, x=281, y=65535
	killChannel
	break

LABEL_0FDB:
	break
	je [0x57], 0x00, LABEL_0FDB
	play id=0x008E, freq=0x16, vol=0x40, channel=0x00
	video offset=CINEMATIC_TANK_HORIZON_DECOR_2, x=205, y=118
	break
	video offset=CINEMATIC_TANK_HORIZON_DECOR_2, x=222, y=121
	break
	video offset=CINEMATIC_TANK_HORIZON_DECOR_1, x=241, y=126
	break
	video offset=CINEMATIC_TANK_HORIZON_DECOR_2, x=253, y=129
	break
	video offset=CINEMATIC_022, x=262, y=130
	break
	video offset=CINEMATIC_023, x=260, y=128
	break
	video offset=CINEMATIC_024, x=258, y=127
	break
	video offset=CINEMATIC_TANK_HORIZON_DECOR_4, x=253, y=127
	break
	video offset=CINEMATIC_025, x=241, y=116
	break
	video offset=CINEMATIC_026, x=232, y=102
	break
	video offset=CINEMATIC_027, x=228, y=93
	break
	video offset=CINEMATIC_027, x=231, y=75
	break
	video offset=CINEMATIC_021, x=234, y=64
	break
	video offset=CINEMATIC_021, x=239, y=42
	break
	video offset=CINEMATIC_027, x=235, y=21
	break
	video offset=CINEMATIC_026, x=227, y=8
	break
	video offset=CINEMATIC_025, x=196, y=2
	break
	setup channel=0x26, address=LABEL_0E32
	killChannel

LABEL_1045:
	video offset=CINEMATIC_028, x=391, y=103
	play id=0x008E, freq=0x19, vol=0x40, channel=0x00
	break
	video offset=CINEMATIC_028, x=28, y=103
	break
	mov [0x4A], 0x0014

TANK_MISSILE_PASS_GAP_DELAY:
	break
	djnz [0x4A], TANK_MISSILE_PASS_GAP_DELAY
	setup channel=0x0F, address=TANK_MISSILE_FAR_PASS_INIT
	killChannel
