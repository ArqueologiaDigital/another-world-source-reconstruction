TANK_PANEL_CELL_SCREEN_POSITION_LOOKUP:
	jne [0x59], 0x00, TANK_PANEL_CELL_SCREEN_POSITION_LOOKUP_CASE_01
	mov [0x5A], 0x0022
	mov [0x5B], 0x0019
	ret


TANK_PANEL_CELL_SCREEN_POSITION_LOOKUP_CASE_01:
	jne [0x59], 0x01, TANK_CONSOLE_BUTTON_POSITION_CASE_02
	mov [0x5A], 0x0026
	mov [0x5B], 0x001B
	ret


TANK_CONSOLE_BUTTON_POSITION_CASE_02:
	jne [0x59], 0x02, TANK_CONSOLE_BUTTON_POSITION_CASE_0E
	mov [0x5A], 0x002A
	mov [0x5B], 0x001E
	ret


TANK_CONSOLE_BUTTON_POSITION_CASE_0E:
	jne [0x59], 0x0E, TANK_CONSOLE_BUTTON_POSITION_CASE_08
	mov [0x5A], 0x004A
	mov [0x5B], 0x002B
	ret


TANK_CONSOLE_BUTTON_POSITION_CASE_08:
	jne [0x59], 0x08, TANK_CONSOLE_BUTTON_POSITION_CASE_09
	mov [0x5A], 0x0022
	mov [0x5B], 0x001F
	ret


TANK_CONSOLE_BUTTON_POSITION_CASE_09:
	jne [0x59], 0x09, TANK_CONSOLE_BUTTON_POSITION_CASE_0B
	mov [0x5A], 0x0026
	mov [0x5B], 0x0021
	ret


TANK_CONSOLE_BUTTON_POSITION_CASE_0B:
	jne [0x59], 0x0B, TANK_CONSOLE_BUTTON_POSITION_CASE_0C
	mov [0x5A], 0x0031
	mov [0x5B], 0x0027
	ret


TANK_CONSOLE_BUTTON_POSITION_CASE_0C:
	jne [0x59], 0x0C, TANK_CONSOLE_BUTTON_POSITION_CASE_10
	mov [0x5A], 0x0035
	mov [0x5B], 0x002A
	ret


TANK_CONSOLE_BUTTON_POSITION_CASE_10:
	jne [0x59], 0x10, TANK_CONSOLE_BUTTON_POSITION_CASE_11
	mov [0x5A], 0x0022
	mov [0x5B], 0x0025
	ret


TANK_CONSOLE_BUTTON_POSITION_CASE_11:
	jne [0x59], 0x11, TANK_CONSOLE_BUTTON_POSITION_CASE_13
	mov [0x5A], 0x0026
	mov [0x5B], 0x0027
	ret


TANK_CONSOLE_BUTTON_POSITION_CASE_13:
	jne [0x59], 0x13, TANK_CONSOLE_BUTTON_POSITION_CASE_14
	mov [0x5A], 0x0031
	mov [0x5B], 0x0030
	ret


TANK_CONSOLE_BUTTON_POSITION_CASE_14:
	jne [0x59], 0x14, TANK_CONSOLE_BUTTON_POSITION_CASE_15
	mov [0x5A], 0x0035
	mov [0x5B], 0x0032
	ret


TANK_CONSOLE_BUTTON_POSITION_CASE_15:
	jne [0x59], 0x15, TANK_CONSOLE_BUTTON_POSITION_CASE_16
	mov [0x5A], 0x0040
	mov [0x5B], 0x0035
	ret


TANK_CONSOLE_BUTTON_POSITION_CASE_16:
	jne [0x59], 0x16, TANK_CONSOLE_BUTTON_POSITION_CASE_18
	mov [0x5A], 0x004A
	mov [0x5B], 0x0036
	ret


TANK_CONSOLE_BUTTON_POSITION_CASE_18:
	jne [0x59], 0x18, TANK_CONSOLE_BUTTON_POSITION_CASE_19
	mov [0x5A], 0x0022
	mov [0x5B], 0x002C
	ret


TANK_CONSOLE_BUTTON_POSITION_CASE_19:
	jne [0x59], 0x19, TANK_CONSOLE_BUTTON_POSITION_CASE_1A
	mov [0x5A], 0x0026
	mov [0x5B], 0x002D
	ret


TANK_CONSOLE_BUTTON_POSITION_CASE_1A:
	jne [0x59], 0x1A, TANK_CONSOLE_BUTTON_POSITION_CASE_1B
	mov [0x5A], 0x002A
	mov [0x5B], 0x0033
	ret


TANK_CONSOLE_BUTTON_POSITION_CASE_1B:
	jne [0x59], 0x1B, TANK_CONSOLE_BUTTON_POSITION_CASE_1C
	mov [0x5A], 0x0031
	mov [0x5B], 0x0038
	ret


TANK_CONSOLE_BUTTON_POSITION_CASE_1C:
	jne [0x59], 0x1C, TANK_CONSOLE_BUTTON_POSITION_CASE_1D
	mov [0x5A], 0x0035
	mov [0x5B], 0x003A
	ret


TANK_CONSOLE_BUTTON_POSITION_CASE_1D:
	jne [0x59], 0x1D, TANK_CONSOLE_BUTTON_POSITION_CASE_21
	mov [0x5A], 0x0040
	mov [0x5B], 0x003B
	ret


TANK_CONSOLE_BUTTON_POSITION_CASE_21:
	jne [0x59], 0x21, TANK_CONSOLE_BUTTON_POSITION_CASE_22
	mov [0x5A], 0x0026
	mov [0x5B], 0x0035
	ret


TANK_CONSOLE_BUTTON_POSITION_CASE_22:
	jne [0x59], 0x22, SHARED_RET
	mov [0x5A], 0x002B
	mov [0x5B], 0x003B
	ret


TANK_CONSOLE_DRAW_CURSOR_HAND_AND_EDGE:
	video offset=CINEMATIC_117, x=[0x60], y=[0x61]
	video offset=CINEMATIC_118, x=[0x5d], y=[0x5e]
	video offset=CINEMATIC_119, x=160, y=100
	ret


TANK_CONSOLE_HAND_HOVER_LOOP:
	jne [0x5C], 0xFFFF, TANK_CONSOLE_HAND_PRESS_BUTTON_FLASH
	mov [0x5D], [0x60]
	mov [0x5E], [0x61]
	call TANK_CONSOLE_DRAW_CURSOR_HAND_AND_EDGE
	break
	jmp TANK_CONSOLE_HAND_HOVER_LOOP

TANK_CONSOLE_HAND_PRESS_BUTTON_FLASH:
	mov [0x59], [0x5C]
	call TANK_PANEL_CELL_SCREEN_POSITION_LOOKUP
	mov [0x5D], [0x5A]
	mov [0x5E], [0x5B]
	add [0x5D], 0x000A
	add [0x5D], 0x000A
	mov [0x59], [0x5C]
	call TANK_PANEL_CELL_SCREEN_POSITION_LOOKUP
	video offset=CINEMATIC_116, x=[0x5a], y=[0x5b]
	call TANK_CONSOLE_DRAW_CURSOR_HAND_AND_EDGE
	break
	mov [0x5C], 0xFFFF
	jmp TANK_CONSOLE_HAND_HOVER_LOOP
LABEL_083C:
	db 0x11

TANK_CONSOLE_CURSOR_INPUT_LOOP:
	mov [0x62], [0x5F]
	add [0x5F], [HERO_POS_LEFT_RIGHT]
	mov [0xF8], [HERO_POS_JUMP_DOWN]
	shl [0xF8], 0x0003
	add [0x5F], [0xF8]
	call TANK_TURRET_ANGLE_STATE_DISPATCH
	mov [0x59], [0x5F]
	call TANK_PANEL_CELL_SCREEN_POSITION_LOOKUP
	mov [0x60], [0x5A]
	mov [0x61], [0x5B]
	video offset=CINEMATIC_117, x=[0x60], y=[0x61]
	je [HERO_ACTION], 0x00, TANK_CONSOLE_CURSOR_INPUT_DONE
	call TANK_CONSOLE_BUTTON_ACTION_DISPATCH
	mov [0x5C], [0x5F]

TANK_CONSOLE_CURSOR_INPUT_DONE:
	break
	jmp TANK_CONSOLE_CURSOR_INPUT_LOOP
LABEL_0871:
	db 0x11

TANK_CONSOLE_BUTTON_ACTION_DISPATCH:
	jne [0x59], 0x00, TANK_CONSOLE_BUTTON_ACTION_CASE_01
	mov [0x63], 0x0001
	ret


TANK_CONSOLE_BUTTON_ACTION_CASE_01:
	jne [0x59], 0x01, TANK_CONSOLE_BUTTON_ACTION_CASE_02
	mov [0x57], 0x0001
	ret


TANK_CONSOLE_BUTTON_ACTION_CASE_02:
	jne [0x59], 0x02, TANK_CONSOLE_BUTTON_ACTION_CASE_0E
	mov [0x47], 0x0001
	ret


TANK_CONSOLE_BUTTON_ACTION_CASE_0E:
	jne [0x59], 0x0E, TANK_CONSOLE_BUTTON_ACTION_CASE_08
	add [0x3E], 0x0005
	ret


TANK_CONSOLE_BUTTON_ACTION_CASE_08:
	jne [0x59], 0x08, TANK_CONSOLE_BUTTON_ACTION_CASE_09
	ret


TANK_CONSOLE_BUTTON_ACTION_CASE_09:
	jne [0x59], 0x09, TANK_CONSOLE_BUTTON_ACTION_CASE_0B
	ret


TANK_CONSOLE_BUTTON_ACTION_CASE_0B:
	jne [0x59], 0x0B, TANK_CONSOLE_BUTTON_ACTION_CASE_0C
	call TANK_TURRET_HIT_STAMP_ON_BACKDROP
	ret


TANK_CONSOLE_BUTTON_ACTION_CASE_0C:
	jne [0x59], 0x0C, TANK_CONSOLE_BUTTON_ACTION_CASE_10
	add [0x4F], 0x000A
	ret


TANK_CONSOLE_BUTTON_ACTION_CASE_10:
	jne [0x59], 0x10, TANK_CONSOLE_BUTTON_ACTION_CASE_11
	ret


TANK_CONSOLE_BUTTON_ACTION_CASE_11:
	jne [0x59], 0x11, TANK_CONSOLE_BUTTON_ACTION_CASE_13
	mov [0x46], 0x0001
	ret


TANK_CONSOLE_BUTTON_ACTION_CASE_13:
	jne [0x59], 0x13, TANK_CONSOLE_BUTTON_ACTION_CASE_14
	call TANK_TURRET_HIT_STAMP_ADVANCE_SCREEN_STATE
	ret


TANK_CONSOLE_BUTTON_ACTION_CASE_14:
	jne [0x59], 0x14, TANK_CONSOLE_BUTTON_ACTION_CASE_15
	add [0x37], 0x0001
	ret


TANK_CONSOLE_BUTTON_ACTION_CASE_15:
	jne [0x59], 0x15, LABEL_08F3
	mov [0x3E], 0x000A
	ret


LABEL_08F3:
	jne [0x59], 0x16, LABEL_08FE
	mov [0x56], 0x0001
	ret


LABEL_08FE:
	jne [0x59], 0x18, LABEL_0908
	call TANK_SCENE_INIT_FILL_PAGE_3_COLOR_0C
	ret


LABEL_0908:
	jne [0x59], 0x19, LABEL_0913
	mov [0x47], 0x0001
	ret


LABEL_0913:
	jne [0x59], 0x1A, LABEL_091A
	ret


LABEL_091A:
	jne [0x59], 0x1B, LABEL_0925
	add [0x41], 0x000A
	ret


LABEL_0925:
	jne [0x59], 0x1C, LABEL_0930
	add [0x37], 0x000A
	ret


LABEL_0930:
	jne [0x59], 0x1D, LABEL_093B
	mov [0x47], 0x0001
	ret


LABEL_093B:
	jne [0x59], 0x21, LABEL_0942
	ret


LABEL_0942:
	jne [0x59], 0x22, SHARED_RET
	mov [0x46], 0x0001
	ret


TANK_ARRIVAL_SIDE_MASK_REDRAW_LOOP:
	video offset=CINEMATIC_173, x=160, y=100
	break
	jmp TANK_ARRIVAL_SIDE_MASK_REDRAW_LOOP

TANK_ARRIVAL_CUTSCENE_ENTRY:
	call TANK_BACKDROP_BUILD_BOTH_PAGES
	selectVideoPage 0x00
	video offset=CINEMATIC_012, x=160, y=100
	video offset=CINEMATIC_013, x=160, y=100
	selectVideoPage 0xFF
	setup channel=0x0A, address=TANK_ARRIVAL_SIDE_MASK_REDRAW_LOOP
	break
	break
	selectVideoPage 0x00
	video offset=CINEMATIC_014, x=160, y=100
	selectVideoPage 0xFF
	break
	selectVideoPage 0x00
	video offset=CINEMATIC_015, x=160, y=100
	selectVideoPage 0xFF
	break
	selectVideoPage 0x00
	video offset=CINEMATIC_016, x=160, y=100
	selectVideoPage 0xFF
	break
	mov [0x11], 0x0001

TANK_ARRIVAL_CUTSCENE_BURST_AND_ZOOM_IN:
	break
	djnz [0x11], TANK_ARRIVAL_CUTSCENE_BURST_AND_ZOOM_IN
	selectVideoPage 0x00
	video offset=CINEMATIC_017, x=160, y=100
	selectVideoPage 0xFF
	mov [0x11], 0x000A
	break
	selectVideoPage 0x00
	video offset=CINEMATIC_018, x=160, y=100
	selectVideoPage 0xFF
	break
	selectVideoPage 0x00
	video offset=CINEMATIC_019, x=160, y=100
	selectVideoPage 0xFF
	break
	selectVideoPage 0x00
	video offset=CINEMATIC_020, x=160, y=100
	selectVideoPage 0xFF
	break
	break
	video offset=CINEMATIC_021, x=160, y=100
	video offset=CINEMATIC_022, x=160, y=100
	break
	video offset=CINEMATIC_021, x=160, y=100, zoom=0x46
	video offset=CINEMATIC_023, x=160, y=100, zoom=0x46
	break
	video offset=CINEMATIC_024, x=160, y=100, zoom=0x50
	video offset=CINEMATIC_021, x=160, y=100, zoom=0x50
	break
	video offset=CINEMATIC_025, x=160, y=100, zoom=0x50
	video offset=CINEMATIC_021, x=160, y=100, zoom=0x5a
	setup channel=0x37, address=TANK_ARENA_CREATURE_CHARGE_AND_SCENE_REARM
	break
	video offset=CINEMATIC_026, x=160, y=100, zoom=0x50
	video offset=CINEMATIC_021, x=160, y=100, zoom=0x64
	break
	video offset=CINEMATIC_026, x=160, y=100, zoom=0x50
	video offset=CINEMATIC_021, x=160, y=100, zoom=0x6e
	break
	video offset=CINEMATIC_026, x=160, y=100, zoom=0x50
	video offset=CINEMATIC_021, x=160, y=100, zoom=0x78
	killChannel
	video offset=CINEMATIC_026, x=160, y=100, zoom=0x50
	video offset=CINEMATIC_021, x=160, y=100, zoom=0x82
	break
	video offset=CINEMATIC_026, x=160, y=100, zoom=0x50
	video offset=CINEMATIC_021, x=160, y=100, zoom=0x87
	break
	video offset=CINEMATIC_021, x=160, y=100, zoom=0x8e
	break
	video offset=CINEMATIC_021, x=160, y=100, zoom=0x96
	break
	video offset=CINEMATIC_021, x=160, y=100, zoom=0xa0
	jmp TANK_STAGE_BOOT_SETUP_CHANNELS
LABEL_0A43:
	db 0x11

TANK_SALVO_IMPACT_FIREBALL_AND_NEW_BACKDROP:
	break
	video offset=CINEMATIC_135, x=152, y=5
	video offset=CINEMATIC_066, x=242, y=65535
	break
	video offset=CINEMATIC_067, x=257, y=23
	video offset=CINEMATIC_136, x=147, y=33
	break
	video offset=CINEMATIC_135, x=144, y=53
	video offset=CINEMATIC_066, x=269, y=41
	break
	video offset=CINEMATIC_137, x=127, y=72
	video offset=CINEMATIC_136, x=269, y=67
	break
	video offset=CINEMATIC_135, x=111, y=86
	video offset=CINEMATIC_066, x=273, y=90
	break
	video offset=CINEMATIC_131, x=90, y=98
	video offset=CINEMATIC_067, x=273, y=110
	break
	video offset=CINEMATIC_137, x=64, y=107
	video offset=CINEMATIC_067, x=268, y=118
	video offset=CINEMATIC_138, x=178, y=3
	break
	video offset=CINEMATIC_137, x=42, y=122
	video offset=CINEMATIC_066, x=259, y=129
	video offset=CINEMATIC_138, x=172, y=70, zoom=0x64
	break
	video offset=CINEMATIC_137, x=21, y=134
	video offset=CINEMATIC_066, x=278, y=141
	video offset=CINEMATIC_138, x=172, y=143, zoom=0x8e
	break
	video offset=CINEMATIC_135, x=4, y=149
	video offset=CINEMATIC_136, x=287, y=148
	video offset=CINEMATIC_138, x=172, y=250, zoom=0xdc
	selectVideoPage 0x03
	play id=0x008C, freq=0x1E, vol=0x40, channel=0x01
	play id=0x008C, freq=0x0A, vol=0x40, channel=0x00
	video offset=CINEMATIC_139, x=160, y=100
	video offset=CINEMATIC_140, x=160, y=100
	video offset=CINEMATIC_141, x=160, y=100
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
	video offset=CINEMATIC_142, x=160, y=100
	break
	setPalette 0x05
	play id=0x008C, freq=0x05, vol=0x40, channel=0x00
	video offset=CINEMATIC_080, x=198, y=49
	video offset=CINEMATIC_080, x=87, y=66
	video offset=CINEMATIC_143, x=160, y=100
	break
	setPalette 0x04
	video offset=CINEMATIC_144, x=315, y=58
	video offset=CINEMATIC_144, x=86, y=57
	video offset=CINEMATIC_080, x=198, y=91
	video offset=CINEMATIC_145, x=160, y=100
	break
	setPalette 0x03
	video offset=CINEMATIC_082, x=91, y=58
	video offset=CINEMATIC_083, x=306, y=56
	video offset=CINEMATIC_144, x=199, y=98
	video offset=CINEMATIC_146, x=160, y=100
	freezeChannels first=0x27, last=0x38
	break
	play id=0x008C, freq=0x14, vol=0x40, channel=0x01
	setPalette 0x02
	video offset=CINEMATIC_083, x=195, y=110
	video offset=CINEMATIC_147, x=160, y=100
	break
	setPalette 0x01
	video offset=CINEMATIC_082, x=50, y=111
	video offset=CINEMATIC_082, x=140, y=114
	video offset=CINEMATIC_082, x=207, y=104
	video offset=CINEMATIC_082, x=261, y=108
	break
	video offset=CINEMATIC_083, x=50, y=111
	video offset=CINEMATIC_083, x=140, y=114
	video offset=CINEMATIC_083, x=209, y=114
	video offset=CINEMATIC_083, x=261, y=110
	freezeChannels first=0x02, last=0x02
	killChannel

TANK_SALVO_TRAIL_CLIMB_AND_SPAWN_BURSTS:
	break
	je [0x57], 0x00, TANK_SALVO_TRAIL_CLIMB_AND_SPAWN_BURSTS
	setup channel=0x31, address=WAIT_VAR46_PLAY_8E_DRAW_CIN_056
	setup channel=0x22, address=TANK_PROJECTILE_ARC_AND_EXPLOSION
	mov [0x46], 0x0000
	mov [0x56], 0x0000
	break
	mov [0x46], 0x0001
	break
	mov [0x56], 0x0001
	play id=0x008E, freq=0x0F, vol=0x40, channel=0x01
	video offset=CINEMATIC_065, x=199, y=128
	break
	video offset=CINEMATIC_067, x=203, y=129
	break
	video offset=CINEMATIC_067, x=208, y=137
	break
	video offset=CINEMATIC_065, x=219, y=142
	break
	video offset=CINEMATIC_063, x=231, y=136
	break
	video offset=CINEMATIC_064, x=242, y=125
	break
	video offset=CINEMATIC_064, x=252, y=103
	break
	video offset=CINEMATIC_064, x=262, y=76
	break
	video offset=CINEMATIC_063, x=267, y=57
	break
	video offset=CINEMATIC_063, x=274, y=41
	break
	video offset=CINEMATIC_064, x=279, y=21
	break
	video offset=CINEMATIC_064, x=281, y=65535
	killChannel
	break

TANK_SALVO_TRAIL_CLIMB_THEN_STRIKE:
	break
	je [0x57], 0x00, TANK_SALVO_TRAIL_CLIMB_THEN_STRIKE
	play id=0x008E, freq=0x16, vol=0x40, channel=0x00
	video offset=CINEMATIC_067, x=205, y=118
	break
	video offset=CINEMATIC_067, x=222, y=121
	break
	video offset=CINEMATIC_066, x=241, y=126
	break
	video offset=CINEMATIC_067, x=253, y=129
	break
	video offset=CINEMATIC_068, x=262, y=130
	break
	video offset=CINEMATIC_129, x=260, y=128
	break
	video offset=CINEMATIC_130, x=258, y=127
	break
	video offset=CINEMATIC_131, x=253, y=127
	break
	video offset=CINEMATIC_132, x=241, y=116
	break
	video offset=CINEMATIC_133, x=232, y=102
	break
	video offset=CINEMATIC_134, x=228, y=93
	break
	video offset=CINEMATIC_134, x=231, y=75
	break
	video offset=CINEMATIC_064, x=234, y=64
	break
	video offset=CINEMATIC_064, x=239, y=42
	break
	video offset=CINEMATIC_134, x=235, y=21
	break
	video offset=CINEMATIC_133, x=227, y=8
	break
	video offset=CINEMATIC_132, x=196, y=2
	break
	setup channel=0x26, address=TANK_SALVO_IMPACT_FIREBALL_AND_NEW_BACKDROP
	killChannel

TANK_MISSILE_NEAR_PASS_ENTRY:
	video offset=CINEMATIC_125, x=391, y=103
	play id=0x008E, freq=0x19, vol=0x40, channel=0x00
	break
	video offset=CINEMATIC_125, x=28, y=103
	break
	mov [0x4A], 0x0014

TANK_MISSILE_PASS_GAP_DELAY:
	break
	djnz [0x4A], TANK_MISSILE_PASS_GAP_DELAY
	setup channel=0x0F, address=TANK_MISSILE_FAR_PASS_INIT
	killChannel
