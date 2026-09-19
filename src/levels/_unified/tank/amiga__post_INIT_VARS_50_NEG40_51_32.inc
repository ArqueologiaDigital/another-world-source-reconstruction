TANK_GROUND_DEBRIS_SWEEP_LOOP:
	break
	call TANK_GROUND_DEBRIS_SPAWN
	add [0x50], 0x000A
	djnz [0x51], TANK_GROUND_DEBRIS_SWEEP_LOOP
	jmp TANK_GROUND_DEBRIS_SWEEP_INIT
LABEL_1103:
	db 0x11

TANK_GROUND_DEBRIS_SPAWN:
	jle [0x4F], 0x00, SHARED_RET
	jne [0x4E], 0x00, SHARED_RET
	sub [0x4F], 0x0001
	mov [0x4E], 0x0001
	call TANK_RANDOM_HASH_ADVANCE
	mov [0x4B], [0x64]
	and [0x4B], 0x001F
	add [0x4B], [0x50]
	call TANK_RANDOM_HASH_ADVANCE
	mov [0x4C], [0x64]
	and [0x4C], 0x0007
	add [0x4C], 0x0089
	call TANK_RANDOM_HASH_ADVANCE
	mov [0x4D], [0x64]
	and [0x4D], 0x000F
	add [0x4D], 0x0037
	ret


TANK_GROUND_DEBRIS_BURST_LOOP:
	break
	je [0x4E], 0x00, TANK_GROUND_DEBRIS_BURST_LOOP
	play id=0x008C, freq=0x1E, vol=0x14, channel=0x01
	video offset=CINEMATIC_148, x=[0x4b], y=[0x4c], zoom=[0x4d]
	break
	video offset=CINEMATIC_149, x=[0x4b], y=[0x4c], zoom=[0x4d]
	break
	video offset=CINEMATIC_150, x=[0x4b], y=[0x4c], zoom=[0x4d]
	selectVideoPage 0x03
	video offset=CINEMATIC_151, x=[0x4b], y=[0x4c], zoom=[0x4d]
	selectVideoPage 0xFF
	mov [0x4E], 0x0000
	jmp TANK_GROUND_DEBRIS_BURST_LOOP
LABEL_1174:
	db 0x11

TANK_AMBIENT_RANDOM_DELAY_PLAY_SOUND_8C:
	break
	jle [0x3E], 0x00, TANK_AMBIENT_RANDOM_DELAY_PLAY_SOUND_8C
	sub [0x3E], 0x0001
	call TANK_RANDOM_HASH_ADVANCE
	mov [RANDOM_SEED], [0x65]
	mov [0x3D], [0x64]
	shr [0x3D], 0x0008
	and [0x3D], 0x001F
	add [0x3D], 0x005A
	play id=0x008C, freq=0x19, vol=0x0D, channel=0x00
	video offset=CINEMATIC_152, x=[0x3c], y=[0x3d]
	selectVideoPage 0x03
	call TANK_RANDOM_HASH_ADVANCE
	mov [0xF8], [0x64]
	and [0xF8], 0x0003
	jne [0xF8], 0x00, TANK_AMBIENT_IMPACT_SCAR_CASE_01
	video offset=CINEMATIC_155, x=[0x3c], y=[0x3d]

TANK_AMBIENT_IMPACT_SCAR_CASE_01:
	jne [0xF8], 0x01, TANK_AMBIENT_IMPACT_SCAR_CASE_02
	video offset=CINEMATIC_154, x=[0x3c], y=[0x3d]

TANK_AMBIENT_IMPACT_SCAR_CASE_02:
	jl [0xF8], 0x02, TANK_AMBIENT_IMPACT_SCAR_DONE
	video offset=CINEMATIC_153, x=[0x3c], y=[0x3d]

TANK_AMBIENT_IMPACT_SCAR_DONE:
	selectVideoPage 0xFF
	jmp TANK_AMBIENT_RANDOM_DELAY_PLAY_SOUND_8C
LABEL_11D2:
	db 0x11

TANK_HULL_BODY_REPEAT:
	video offset=CINEMATIC_123, x=[0x0f], y=[0x10]
	break
	jmp TANK_HULL_BODY_REPEAT

TANK_HULL_FRONT_REPEAT:
	video offset=CINEMATIC_115, x=[0x01], y=[0x02]
	break
	jmp TANK_HULL_FRONT_REPEAT

TANK_SHOT_LAUNCH_STREAK_ON_FIRE_TRIGGER:
	break
	je [0x46], 0x00, TANK_SHOT_LAUNCH_STREAK_ON_FIRE_TRIGGER
	play id=0x008E, freq=0x14, vol=0x40, channel=0x01
	video offset=CINEMATIC_059, x=160, y=100
	break
	video offset=CINEMATIC_059, x=160, y=100
	break
	video offset=CINEMATIC_060, x=160, y=100
	break
	video offset=CINEMATIC_061, x=160, y=100
	break
	video offset=CINEMATIC_062, x=160, y=100
	break
	break
	break
	killChannel

TANK_PROJECTILE_ARC_AND_EXPLOSION:
	break
	je [0x56], 0x00, TANK_PROJECTILE_ARC_AND_EXPLOSION
	play id=0x008E, freq=0x14, vol=0x40, channel=0x01
	video offset=CINEMATIC_063, x=195, y=79
	break
	video offset=CINEMATIC_063, x=202, y=75
	break
	video offset=CINEMATIC_064, x=212, y=66
	break
	video offset=CINEMATIC_063, x=220, y=58
	break
	video offset=CINEMATIC_065, x=235, y=55
	break
	video offset=CINEMATIC_066, x=247, y=61
	break
	video offset=CINEMATIC_067, x=258, y=73
	break
	video offset=CINEMATIC_068, x=269, y=80
	break
	video offset=CINEMATIC_068, x=272, y=77, zoom=0x3c
	break
	video offset=CINEMATIC_068, x=275, y=74, zoom=0x32
	break
	video offset=CINEMATIC_068, x=278, y=71, zoom=0x2d
	break
	video offset=CINEMATIC_068, x=278, y=68, zoom=0x22
	break
	video offset=CINEMATIC_068, x=280, y=65, zoom=0x1f
	break
	selectVideoPage 0x00
	play id=0x008C, freq=0x14, vol=0x40, channel=0x01
	video offset=CINEMATIC_069, x=264, y=103
	selectVideoPage 0x03
	video offset=CINEMATIC_069, x=264, y=103
	selectVideoPage 0xFF
	break
	video offset=CINEMATIC_070, x=264, y=105
	break
	video offset=CINEMATIC_071, x=264, y=105
	break
	video offset=CINEMATIC_072, x=264, y=103
	break
	video offset=CINEMATIC_073, x=264, y=103
	break
	video offset=CINEMATIC_074, x=264, y=103
	break
	video offset=CINEMATIC_075, x=264, y=103
	break
	video offset=CINEMATIC_076, x=264, y=103
	killChannel

TANK_BEAM_GUN_WAIT_LOOP:
	jg [0x41], 0x00, TANK_BEAM_GUN_BARREL_EXTEND_INIT
	break
	jmp TANK_BEAM_GUN_WAIT_LOOP

TANK_BEAM_GUN_BARREL_EXTEND_INIT:
	video offset=CINEMATIC_077, x=135, y=100
	video offset=CINEMATIC_078, x=160, y=100
	video offset=CINEMATIC_078, x=145, y=100
	break
	video offset=CINEMATIC_077, x=137, y=100
	video offset=CINEMATIC_078, x=160, y=100
	video offset=CINEMATIC_078, x=145, y=100
	break
	video offset=CINEMATIC_077, x=140, y=100
	video offset=CINEMATIC_078, x=160, y=100
	video offset=CINEMATIC_078, x=145, y=100
	break
	video offset=CINEMATIC_077, x=143, y=100
	video offset=CINEMATIC_078, x=160, y=100
	video offset=CINEMATIC_078, x=145, y=100
	break
	video offset=CINEMATIC_077, x=146, y=100
	video offset=CINEMATIC_078, x=160, y=100
	break
	video offset=CINEMATIC_077, x=149, y=100
	video offset=CINEMATIC_078, x=160, y=100
	break
	video offset=CINEMATIC_077, x=152, y=100
	video offset=CINEMATIC_078, x=160, y=100
	break
	video offset=CINEMATIC_077, x=155, y=100
	video offset=CINEMATIC_078, x=160, y=100
	break
	video offset=CINEMATIC_077, x=157, y=100
	video offset=CINEMATIC_078, x=160, y=100
	selectVideoPage 0x00
	video offset=CINEMATIC_077, x=160, y=100
	selectVideoPage 0xFF

TANK_BEAM_WEAPON_VOLLEY_LOOP:
	break
	jle [0x41], 0x00, TANK_BEAM_WEAPON_VOLLEY_LOOP
	sub [0x41], 0x0001
	selectVideoPage 0x00
	video offset=CINEMATIC_078, x=189, y=100
	video offset=CINEMATIC_078, x=176, y=100
	selectVideoPage 0xFF
	video offset=CINEMATIC_078, x=189, y=100
	video offset=CINEMATIC_078, x=176, y=100
	video offset=CINEMATIC_077, x=155, y=100
	video offset=CINEMATIC_078, x=160, y=100
	play id=0x0052, freq=0x1E, vol=0x40, channel=0x01
	video offset=CINEMATIC_079, x=247, y=91
	break
	video offset=CINEMATIC_077, x=159, y=100
	video offset=CINEMATIC_078, x=160, y=100
	video offset=CINEMATIC_079, x=300, y=91
	selectVideoPage 0x00
	video offset=CINEMATIC_077, x=160, y=100
	selectVideoPage 0xFF
	break
	jmp TANK_BEAM_WEAPON_VOLLEY_LOOP
LABEL_1366:
	db 0x11, 0x93, 0xCE, 0xEF, 0x7B, 0x18, 0x00, 0x52
	db 0x1E, 0x10, 0x01, 0x06, 0x93, 0xD8, 0xF0, 0x7B
	db 0x06, 0x06, 0x07, 0x13, 0x67, 0x11

INIT_VAR1_NEG50_PLAY_8B_TWICE:
	mov [0x01], 0xFFCE
	mov [0x02], 0x0064
	mov [0x03], 0x0040
	mov [0x2B], 0x0023
	play id=0x008B, freq=0x22, vol=0x40, channel=0x01
	play id=0x008B, freq=0x14, vol=0x40, channel=0x00

TANK_ARRIVAL_DRIVE_IN_PRELUDE:
	mov [0xF8], [0x2B]
	and [0xF8], 0x000D
	add [0x01], [0xF8]
	sub [0x2B], 0x0001
	jg [0x2B], 0x20, TANK_ARRIVAL_DRIVE_IN_PRELUDE

TANK_ARRIVAL_DRIVE_IN_LOOP:
	break
	play id=0x008B, freq=0x22, vol=0x40, channel=0x01
	play id=0x008C, freq=0x0A, vol=0x40, channel=0x00
	call DRAW_TANK_FLYBY_CRAFT
	mov [0xF8], [0x2B]
	and [0xF8], 0x000D
	add [0x01], [0xF8]
	djnz [0x2B], TANK_ARRIVAL_DRIVE_IN_LOOP
	play id=0x008B, freq=0x22, vol=0x00, channel=0x01
	play id=0x0084, freq=0x14, vol=0x20, channel=0x02
	play id=0x0084, freq=0x0F, vol=0x10, channel=0x03
	setup channel=0x39, address=TANK_HULL_BODY_REPEAT
	setup channel=0x01, address=TANK_CONSOLE_CURSOR_INPUT_LOOP
	setup channel=0x3B, address=TANK_CONSOLE_HAND_HOVER_LOOP
	selectVideoPage 0x03
	call DRAW_TANK_FLYBY_CRAFT
	selectVideoPage 0x00
	call TANK_HULL_BODY_AND_DETAIL_STAMP
	call DRAW_TANK_FLYBY_CRAFT
	call TANK_HULL_BODY_AND_DETAIL_STAMP
	selectVideoPage 0xFF
	jmp TANK_HULL_FRONT_REPEAT
LABEL_13FD:
	db 0x00, 0x3E, 0x00, 0x14, 0x00, 0x41, 0x00, 0x0A
	db 0x00, 0x37, 0x00, 0x14, 0x00, 0x46, 0x00, 0x01
	db 0x00, 0x47, 0x00, 0x01, 0x00, 0x4F, 0x00, 0x64
	db 0x00, 0x56, 0x00, 0x01, 0x00, 0x57, 0x00, 0x01
	db 0x11

TANK_INIT_PROJECTILE_POOL_CHANNELS_14_TO_25:
	setup channel=0x14, address=TANK_FIRST_GUARD_PAIR_STATE_LOAD_LOOP
	setup channel=0x15, address=TANK_FIREFIGHT_PAIR_FIRE_AND_STEP_PRELUDE
	setup channel=0x16, address=TANK_FIRST_GUARD_PAIR_DRAW_THEN_SECOND_LOAD_LOOP
	setup channel=0x17, address=TANK_FIREFIGHT_SOLDIER_SHOT_AND_FALLS
	setup channel=0x18, address=TANK_SECOND_GUARD_PAIR_DRAW_THEN_THIRD_LOAD_LOOP
	setup channel=0x19, address=TANK_FIREFIGHT_PAIR_POSE_PRELUDE
	setup channel=0x1A, address=TANK_THIRD_GUARD_PAIR_DRAW_LOOP
	mov [0x14], 0x0028
	mov [0x15], 0x0071
	mov [0x16], 0x0040
	mov [0x17], 0x0001
	mov [0x18], 0x0039
	mov [0x19], 0x0001
	mov [0x1A], 0x0104
	mov [0x1B], 0x006C
	mov [0x1C], 0x0055
	mov [0x1D], 0x0001
	mov [0x1E], 0x0118
	mov [0x1F], 0x0001
	mov [0x20], 0x00DC
	mov [0x21], 0x0071
	mov [0x22], 0x0040
	mov [0x23], 0x0001
	mov [0x24], 0x00ED
	mov [0x25], 0x0001
	mov [0x68], 0x0032

TANK_GUARD_CAST_INIT_DELAY:
	break
	djnz [0x68], TANK_GUARD_CAST_INIT_DELAY
	setup channel=0x37, address=TANK_ARENA_CREATURE_CHARGE_PAST
	killChannel

PROJECT_AND_DRAW_TWICE_Y_PLUS_9:
	call TANK_GUARD_FRAME_DISPATCH_CASE_01
	mov [0x07], [0x05]
	mov [0x06], [0x04]
	add [0x06], 0x0009
	call TANK_GUARD_FRAME_DISPATCH_CASE_01
	ret


TANK_FIRST_GUARD_PAIR_STATE_LOAD_LOOP:
	mov [0x07], [0x14]
	mov [0x08], [0x15]
	mov [0x09], [0x16]
	mov [0x06], [0x17]
	mov [0x05], [0x18]
	mov [0x04], [0x19]
	break
	jmp TANK_FIRST_GUARD_PAIR_STATE_LOAD_LOOP
LABEL_14B7:
	db 0x11

TANK_FIRST_GUARD_PAIR_DRAW_THEN_SECOND_LOAD_LOOP:
	mov [0x14], [0x07]
	mov [0x15], [0x08]
	mov [0x16], [0x09]
	mov [0x17], [0x06]
	mov [0x18], [0x05]
	mov [0x19], [0x04]
	call PROJECT_AND_DRAW_TWICE_Y_PLUS_9
	mov [0x07], [0x1A]
	mov [0x08], [0x1B]
	mov [0x09], [0x1C]
	mov [0x06], [0x1D]
	mov [0x05], [0x1E]
	mov [0x04], [0x1F]
	break
	jmp TANK_FIRST_GUARD_PAIR_DRAW_THEN_SECOND_LOAD_LOOP
TANK_DRAW_CIN_154_155_PAIR_IF_GUARDS_PASS:
	db 0x11

TANK_SECOND_GUARD_PAIR_DRAW_THEN_THIRD_LOAD_LOOP:
	mov [0x1A], [0x07]
	mov [0x1B], [0x08]
	mov [0x1C], [0x09]
	mov [0x1D], [0x06]
	mov [0x1E], [0x05]
	mov [0x1F], [0x04]
	call PROJECT_AND_DRAW_TWICE_Y_PLUS_9
	mov [0x07], [0x20]
	mov [0x08], [0x21]
	mov [0x09], [0x22]
	mov [0x06], [0x23]
	mov [0x05], [0x24]
	mov [0x04], [0x25]
	break
	jmp TANK_SECOND_GUARD_PAIR_DRAW_THEN_THIRD_LOAD_LOOP
LABEL_150F:
	db 0x11

TANK_THIRD_GUARD_PAIR_DRAW_LOOP:
	mov [0x20], [0x07]
	mov [0x21], [0x08]
	mov [0x22], [0x09]
	mov [0x23], [0x06]
	mov [0x24], [0x05]
	mov [0x25], [0x04]
	call PROJECT_AND_DRAW_TWICE_Y_PLUS_9
	break
	jmp TANK_THIRD_GUARD_PAIR_DRAW_LOOP
LABEL_1529:
	db 0x11

TANK_GUARD_FRAME_DISPATCH_CASE_01:
	jne [0x06], 0x01, TANK_GUARD_FRAME_DISPATCH_CASE_02
	video offset=CINEMATIC_168, x=[0x07], y=[0x08], zoom=[0x09]
	ret


TANK_GUARD_FRAME_DISPATCH_CASE_02:
	jne [0x06], 0x02, TANK_GUARD_FRAME_DISPATCH_CASE_03
	video offset=CINEMATIC_167, x=[0x07], y=[0x08], zoom=[0x09]
	ret


TANK_GUARD_FRAME_DISPATCH_CASE_03:
	jne [0x06], 0x03, TANK_GUARD_FRAME_DISPATCH_CASE_04
	video offset=CINEMATIC_166, x=[0x07], y=[0x08], zoom=[0x09]
	ret


TANK_GUARD_FRAME_DISPATCH_CASE_04:
	jne [0x06], 0x04, TANK_GUARD_FRAME_DISPATCH_CASE_05
	video offset=CINEMATIC_165, x=[0x07], y=[0x08], zoom=[0x09]
	ret


TANK_GUARD_FRAME_DISPATCH_CASE_05:
	jne [0x06], 0x05, TANK_GUARD_FRAME_DISPATCH_CASE_06
	video offset=CINEMATIC_164, x=[0x07], y=[0x08], zoom=[0x09]
	ret


TANK_GUARD_FRAME_DISPATCH_CASE_06:
	jne [0x06], 0x06, TANK_GUARD_FRAME_DISPATCH_CASE_07
	video offset=CINEMATIC_163, x=[0x07], y=[0x08], zoom=[0x09]
	ret


TANK_GUARD_FRAME_DISPATCH_CASE_07:
	jne [0x06], 0x07, TANK_GUARD_FRAME_DISPATCH_CASE_08
	video offset=CINEMATIC_162, x=[0x07], y=[0x08], zoom=[0x09]
	ret


TANK_GUARD_FRAME_DISPATCH_CASE_08:
	jne [0x06], 0x08, TANK_GUARD_FRAME_DISPATCH_CASE_09
	video offset=CINEMATIC_161, x=[0x07], y=[0x08], zoom=[0x09]
	ret


TANK_GUARD_FRAME_DISPATCH_CASE_09:
	jne [0x06], 0x09, TANK_GUARD_FRAME_DISPATCH_CASE_0A
	video offset=CINEMATIC_160, x=[0x07], y=[0x08], zoom=[0x09]
	ret


TANK_GUARD_FRAME_DISPATCH_CASE_0A:
	jne [0x06], 0x0A, TANK_GUARD_FRAME_DISPATCH_CASE_0B
	video offset=CINEMATIC_159, x=[0x07], y=[0x08], zoom=[0x09]
	ret


TANK_GUARD_FRAME_DISPATCH_CASE_0B:
	jne [0x06], 0x0B, TANK_FIREFIGHT_SOLDIER_POSE_CASE_0C
	video offset=CINEMATIC_158, x=[0x07], y=[0x08], zoom=[0x09]
	ret


TANK_FIREFIGHT_SOLDIER_POSE_CASE_0C:
	jne [0x06], 0x0C, TANK_FIREFIGHT_SOLDIER_POSE_CASE_0D
	video offset=CINEMATIC_157, x=[0x07], y=[0x08], zoom=[0x09]
	ret


TANK_FIREFIGHT_SOLDIER_POSE_CASE_0D:
	jne [0x06], 0x0D, SHARED_RET
	video offset=CINEMATIC_156, x=[0x07], y=[0x08], zoom=[0x09]
	ret