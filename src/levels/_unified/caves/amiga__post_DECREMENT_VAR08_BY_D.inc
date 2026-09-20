LABEL_92B8:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	video offset=CINEMATIC_060, x=[0x07], y=[0x08]
	call LABEL_9292
	ret


LABEL_92C7:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	sub [0x07], 0x0001
	call DRAW_HERO_Y_PLUS_E
	video type=0, offset=CV_4324, x=[0x07], y=[0x08], zoom=0x40
	sub [0x08], 0x0001
	call LABEL_7F2C
	add [0x08], 0x0001
	add [0x07], 0x0001
	ret


LABEL_92E9:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	call DRAW_HERO_Y_PLUS_E
	video type=0, offset=CV_FIGURE_CROUCH_FACING_LEFT, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_7F2C
	ret


LABEL_92FB:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	add [0x08], 0x000D
	sub [0x07], 0x0004
	video type=0, offset=CV_2570, x=[0x07], y=[0x08], zoom=0x40
	add [0x07], 0x0004
	sub [0x08], 0x000D
	call DRAW_HERO_Y_PLUS_E
	video type=0, offset=CV_FIGURE_CROUCH_FACING_LEFT, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_8BF2
	sub [0x08], 0x000D
	ret


LABEL_932A:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	call DRAW_HERO_Y_PLUS_E
	video type=0, offset=CV_FIGURE_CROUCH_FACING_LEFT, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_8BF2
	sub [0x08], 0x000D
	ret


LABEL_9344:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	add [0x08], 0x000D
	video offset=CINEMATIC_138, x=[0x07], y=[0x08]
	sub [0x08], 0x000D
	call DRAW_HERO_Y_PLUS_E
	video type=0, offset=CV_FIGURE_CROUCH_FACING_LEFT, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_8BF2
	sub [0x08], 0x000D
	ret


LABEL_936B:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	sub [0x07], 0x0001
	add [0x08], 0x000D
	video offset=CINEMATIC_137, x=[0x07], y=[0x08]
	sub [0x08], 0x000D
	call DRAW_HERO_Y_PLUS_E
	video type=0, offset=CV_4324, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_8BDC
	sub [0x08], 0x000D
	add [0x07], 0x0001
	ret


LABEL_939A:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_4346, x=[0x07], y=[0x08], zoom=0x40
	sub [0x08], 0x000D
	call LABEL_7EAC
	add [0x08], 0x000D
	ret


LABEL_93B4:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	sub [0x07], 0x0001
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_4368, x=[0x07], y=[0x08], zoom=0x40
	sub [0x08], 0x000E
	call LABEL_7EDA
	add [0x08], 0x000E
	add [0x07], 0x0001
	ret


LABEL_93D6:
	db 0x0A, 0x81, 0x67, 0x10, 0x7F, 0xB2, 0x04, 0x8A
	db 0xAE, 0x57, 0x21, 0xA3, 0x07, 0x08, 0x03, 0x08
	db 0xFF, 0xF3, 0x04, 0x7F, 0x0C, 0x03, 0x08, 0x00
	db 0x0D, 0x05

LABEL_93F0:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_4346, x=[0x07], y=[0x08], zoom=0x40
	sub [0x08], 0x000D
	call LABEL_7EDA
	add [0x08], 0x000D
	ret


LABEL_940A:
	db 0x0A, 0x81, 0x67, 0x10, 0x7F, 0xB2, 0x04, 0x8A
	db 0xAE, 0x57, 0x21, 0xA3, 0x07, 0x08, 0x05, 0x04
	db 0x92, 0x3A, 0x06, 0x04, 0x92, 0x3A, 0x06, 0x04
	db 0x92, 0x3A, 0x03, 0x07, 0xFF, 0xFF, 0x06, 0x04
	db 0x92, 0x4C, 0x03, 0x07, 0x00, 0x01, 0x06, 0x07
	db 0x94, 0x19, 0x11

CAVES_ACTOR_FACE_RIGHT_THEN_RUN_RIGHT:
	call INLINE_OR_VAR11_WITH_1000
	jmp CAVES_HERO_RUN_RIGHT_PHASE_1
LABEL_943B:
	db 0x04, 0x59, 0xB4, 0x0A, 0x01, 0x2F, 0x03, 0x53
	db 0xB1

CAVES_HERO_RUN_RIGHT_PHASE_1:
	call CAVES_ACTOR_RUN_RIGHT_PHASE_1_FRAME
	add [0x07], 0x0007
	break
	jl [0x07], [0x29], CAVES_HERO_RUN_RIGHT_PHASE_2
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, CAVES_HERO_SCENE_LOOP_STATE3_PATH

CAVES_HERO_RUN_RIGHT_PHASE_2:
	call LABEL_8931
	add [0x07], 0x0009
	break
	jl [0x07], [0x29], CAVES_HERO_RUN_RIGHT_PHASE_3
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, CAVES_HERO_SCENE_LOOP_STATE3_PATH

CAVES_HERO_RUN_RIGHT_PHASE_3:
	call CAVES_ACTOR_RUN_RIGHT_PHASE_3_FRAME
	add [0x07], 0x0009
	break
	jl [0x07], [0x29], CAVES_HERO_RUN_RIGHT_PHASE_4
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, CAVES_HERO_SCENE_LOOP_STATE3_PATH

CAVES_HERO_RUN_RIGHT_PHASE_4:
	call CAVES_ACTOR_RUN_RIGHT_PHASE_4_FRAME
	add [0x07], 0x0008
	break
	jl [0x07], [0x29], CAVES_HERO_RUN_RIGHT_PHASE_5
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, CAVES_HERO_SCENE_LOOP_STATE3_PATH

CAVES_HERO_RUN_RIGHT_PHASE_5:
	call LABEL_89B0
	add [0x07], 0x000A
	break
	jl [0x07], [0x29], CAVES_HERO_RUN_RIGHT_PHASE_6
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, CAVES_HERO_SCENE_LOOP_STATE3_PATH

CAVES_HERO_RUN_RIGHT_PHASE_6:
	call CAVES_ACTOR_RUN_RIGHT_PHASE_6_FRAME
	add [0x07], 0x0007
	break
	jl [0x07], [0x29], CAVES_HERO_RUN_RIGHT_PHASE_7
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, CAVES_HERO_SCENE_LOOP_STATE3_PATH

CAVES_HERO_RUN_RIGHT_PHASE_7:
	call LABEL_8A02
	add [0x07], 0x0009
	break
	jl [0x07], [0x29], CAVES_HERO_RUN_RIGHT_PHASE_8
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, CAVES_HERO_SCENE_LOOP_STATE3_PATH

CAVES_HERO_RUN_RIGHT_PHASE_8:
	call CAVES_ACTOR_RUN_RIGHT_PHASE_8_FRAME
	add [0x07], 0x0009
	break
	jl [0x07], [0x29], CAVES_HERO_RUN_RIGHT_PHASE_9
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, CAVES_HERO_SCENE_LOOP_STATE3_PATH

CAVES_HERO_RUN_RIGHT_PHASE_9:
	call CAVES_ACTOR_RUN_RIGHT_PHASE_9_FRAME
	add [0x07], 0x0008
	break
	jl [0x07], [0x29], LABEL_9513
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, CAVES_HERO_SCENE_LOOP_STATE3_PATH

LABEL_9513:
	call LABEL_8A81
	add [0x07], 0x000A
	break
	jmp CAVES_ACTOR_FACE_RIGHT_THEN_RUN_RIGHT
LABEL_951E:
	db 0x11, 0x04, 0x83, 0xAD, 0x06, 0x07, 0x95, 0x1F
	db 0x11

CAVES_ACTOR_FACE_RIGHT_THEN_WALK_RIGHT:
	call INLINE_OR_VAR11_WITH_1000
	jmp CAVES_HERO_WALK_RIGHT_PHASE_1
LABEL_952D:
	db 0x04, 0x59, 0xB4, 0x0A, 0x01, 0x2F, 0x01, 0x53
	db 0xA0

CAVES_HERO_WALK_RIGHT_PHASE_1:
	call CAVES_ACTOR_WALK_RIGHT_DRAW_PHASE_1
	add [0x07], 0x0002
	break
	jl [0x07], [0x29], CAVES_HERO_WALK_RIGHT_PHASE_2
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_HERO_DISPATCH_FIRST

CAVES_HERO_WALK_RIGHT_PHASE_2:
	call LABEL_8CCA
	add [0x07], 0x0002
	break
	jl [0x07], [0x29], CAVES_HERO_WALK_RIGHT_PHASE_3
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_HERO_DISPATCH_FIRST

CAVES_HERO_WALK_RIGHT_PHASE_3:
	call CAVES_ACTOR_WALK_RIGHT_DRAW_PHASE_3
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], CAVES_HERO_WALK_RIGHT_PHASE_4
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_HERO_DISPATCH_FIRST

CAVES_HERO_WALK_RIGHT_PHASE_4:
	call DRAW_FIGURE_WALK_RIGHT_F03
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], CAVES_HERO_WALK_RIGHT_PHASE_5
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_HERO_DISPATCH_FIRST

CAVES_HERO_WALK_RIGHT_PHASE_5:
	call CAVES_ACTOR_WALK_RIGHT_DRAW_PHASE_5
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], CAVES_HERO_WALK_RIGHT_PHASE_6
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_HERO_DISPATCH_FIRST

CAVES_HERO_WALK_RIGHT_PHASE_6:
	call CAVES_ACTOR_WALK_RIGHT_DRAW_PHASE_6
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], CAVES_HERO_WALK_RIGHT_PHASE_7
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_HERO_DISPATCH_FIRST

CAVES_HERO_WALK_RIGHT_PHASE_7:
	call CAVES_ACTOR_WALK_RIGHT_DRAW_PHASE_7
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], CAVES_HERO_WALK_RIGHT_PHASE_8
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_HERO_DISPATCH_FIRST

CAVES_HERO_WALK_RIGHT_PHASE_8:
	call CAVES_ACTOR_WALK_RIGHT_DRAW_PHASE_8
	add [0x07], 0x0002
	break
	jl [0x07], [0x29], CAVES_HERO_WALK_RIGHT_PHASE_9
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_HERO_DISPATCH_FIRST

CAVES_HERO_WALK_RIGHT_PHASE_9:
	call CAVES_ACTOR_WALK_RIGHT_DRAW_PHASE_9
	add [0x07], 0x0002
	break
	jl [0x07], [0x29], CAVES_HERO_WALK_RIGHT_PHASE_10
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_HERO_DISPATCH_FIRST

CAVES_HERO_WALK_RIGHT_PHASE_10:
	call CAVES_ACTOR_WALK_RIGHT_DRAW_PHASE_10
	add [0x07], 0x0002
	break
	jl [0x07], [0x29], CAVES_HERO_WALK_RIGHT_PHASE_11
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_HERO_DISPATCH_FIRST

CAVES_HERO_WALK_RIGHT_PHASE_11:
	call CAVES_ACTOR_WALK_RIGHT_DRAW_PHASE_11
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], CAVES_HERO_WALK_RIGHT_PHASE_12
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_HERO_DISPATCH_FIRST

CAVES_HERO_WALK_RIGHT_PHASE_12:
	call LABEL_8E4D
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], CAVES_HERO_WALK_RIGHT_PHASE_13
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_HERO_DISPATCH_FIRST

CAVES_HERO_WALK_RIGHT_PHASE_13:
	call CAVES_ACTOR_WALK_RIGHT_DRAW_PHASE_13
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], CAVES_HERO_WALK_RIGHT_PHASE_14
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_HERO_DISPATCH_FIRST

CAVES_HERO_WALK_RIGHT_PHASE_14:
	call CAVES_ACTOR_WALK_RIGHT_DRAW_PHASE_14
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], CAVES_HERO_WALK_RIGHT_PHASE_15
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_HERO_DISPATCH_FIRST

CAVES_HERO_WALK_RIGHT_PHASE_15:
	call CAVES_ACTOR_WALK_RIGHT_DRAW_PHASE_15
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], LABEL_968F
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_HERO_DISPATCH_FIRST

LABEL_968F:
	call CAVES_ACTOR_WALK_RIGHT_DRAW_PHASE_16
	add [0x07], 0x0002
	break
	jmp CAVES_ACTOR_FACE_RIGHT_THEN_WALK_RIGHT
LABEL_969A:
	db 0x11

LABEL_969B:
	je [0x0A], [0x0C], KILL_CHAN_AT_96B9
	jg [0x0A], [0x0C], HERO_GUN_ARM_POSE_RAMP_DOWN_LOOP

HERO_GUN_ARM_POSE_RAMP_UP_LOOP:
	add [0x0A], 0x0001
	break
	jne [0x0A], 0x03, LABEL_96B3
	break

LABEL_96B3:
	jl [0x0A], [0x0C], HERO_GUN_ARM_POSE_RAMP_UP_LOOP

KILL_CHAN_AT_96B9:
	killChannel

HERO_GUN_ARM_POSE_RAMP_DOWN_LOOP:
	sub [0x0A], 0x0001
	break
	jne [0x0A], 0x02, LABEL_96C6
	break

LABEL_96C6:
	jg [0x0A], [0x0C], HERO_GUN_ARM_POSE_RAMP_DOWN_LOOP
	killChannel

LABEL_96CD:
	sub [0x0B], 0x0001
	jg [0x0B], 0x00, LABEL_9702
	je [HERO_POS_MASK], 0x00, LABEL_96F0
	call SETUP_HASH_AND_DERIVE_BUCKETS
	mov [0x0B], [RANDOM_SEED]
	add [0x0B], 0x0006
	mov [0x0C], 0x0004
	setup channel=0x15, address=LABEL_969B
	ret


LABEL_96F0:
	call SETUP_HASH_AND_DERIVE_BUCKETS
	mov [0x0B], [0x3A]
	add [0x0B], 0x0006
	mov [0x0C], 0x0001
	setup channel=0x15, address=LABEL_969B

LABEL_9702:
	ret


LABEL_9703:
	video type=0, offset=CV_38D2, x=[HERO_X], y=[HERO_Y], zoom=0x40
	je [0xBE], 0x03, DRAW_CIN_149
	ret


DRAW_CIN_149:
	video offset=CINEMATIC_149, x=[HERO_X], y=[HERO_Y]
	ret


HERO_CROUCH_ARMED_RIGHT_FRAME_CHARGE_BLINK:
	video type=0, offset=CV_3764, x=[HERO_X], y=[HERO_Y], zoom=0x40
	je [0xBE], 0x03, DRAW_CIN_150
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=CV_5C4C, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


DRAW_CIN_150:
	video offset=CINEMATIC_150, x=[HERO_X], y=[HERO_Y]
	ret


LABEL_973F:
	video type=0, offset=CV_389E, x=[HERO_X], y=[HERO_Y], zoom=0x40
	je [0xBE], 0x03, DRAW_CIN_151
	ret


DRAW_CIN_151:
	video offset=CINEMATIC_151, x=[HERO_X], y=[HERO_Y]
	ret


LABEL_9751:
	video type=0, offset=CV_36D2, x=[HERO_X], y=[HERO_Y], zoom=0x40
	je [0xBE], 0x03, DRAW_CIN_175
	ret


DRAW_CIN_175:
	video offset=CINEMATIC_175, x=[HERO_X], y=[HERO_Y]
	ret


LABEL_9763:
	video offset=CINEMATIC_176, x=[HERO_X], y=[HERO_Y]
	je [0xBE], 0x03, DRAW_CIN_177
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=CV_5C54, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


DRAW_CIN_177:
	video offset=CINEMATIC_177, x=[HERO_X], y=[HERO_Y]
	ret


LABEL_978D:
	video type=0, offset=CV_3858, x=[HERO_X], y=[HERO_Y], zoom=0x40
	je [0xBE], 0x03, DRAW_CIN_178
	ret


DRAW_CIN_178:
	video offset=CINEMATIC_178, x=[HERO_X], y=[HERO_Y]
	ret


CAVES_HERO_WATER_DEPTH_SPRITE_RIGHT_CASE_00:
	jne [0x05], 0x00, CAVES_HERO_WATER_DEPTH_SPRITE_RIGHT_CASE_01
	video type=0, offset=HERO_WATER_DEPTH_RIGHT_CASE_00, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


CAVES_HERO_WATER_DEPTH_SPRITE_RIGHT_CASE_01:
	jne [0x05], 0x01, CAVES_HERO_WATER_DEPTH_SPRITE_RIGHT_CASE_02
	video type=0, offset=HERO_WATER_DEPTH_RIGHT_CASE_01, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


CAVES_HERO_WATER_DEPTH_SPRITE_RIGHT_CASE_02:
	jne [0x05], 0x02, CAVES_HERO_WATER_DEPTH_SPRITE_RIGHT_CASE_03
	video type=0, offset=HERO_WATER_DEPTH_RIGHT_CASE_02, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


CAVES_HERO_WATER_DEPTH_SPRITE_RIGHT_CASE_03:
	jne [0x05], 0x03, CAVES_HERO_WATER_DEPTH_SPRITE_RIGHT_CASE_03_RET
	video type=0, offset=HERO_WATER_DEPTH_RIGHT_CASE_03, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


CAVES_HERO_WATER_DEPTH_SPRITE_RIGHT_CASE_03_RET:
	ret


DRAW_HERO_WALK_RIGHT_F09:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F09, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, HERO_GUN_ARM_POSE_CASE_01
	video type=0, offset=HERO_WALK_RIGHT_ARM_F09, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


HERO_GUN_ARM_POSE_CASE_01:
	call LABEL_96CD
	jne [0x0A], 0x01, HERO_GUN_ARM_POSE_CASE_02
	video type=0, offset=HERO_GUN_ARM_RIGHT_CASE_01, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0002
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=HERO_GUN_ARM_RIGHT_CASE_01_CHARGE_BLINK, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


HERO_GUN_ARM_POSE_CASE_02:
	jne [0x0A], 0x02, HERO_GUN_ARM_POSE_CASE_03
	video type=0, offset=HERO_GUN_ARM_RIGHT_CASE_02, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=HERO_GUN_ARM_RIGHT_CASE_02_CHARGE_BLINK, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


HERO_GUN_ARM_POSE_CASE_03:
	jne [0x0A], 0x03, HERO_GUN_ARM_POSE_CASE_04
	video type=0, offset=HERO_GUN_ARM_RIGHT_CASE_03, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=HERO_GUN_ARM_RIGHT_CASE_03_CHARGE_BLINK, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


HERO_GUN_ARM_POSE_CASE_04:
	video type=0, offset=HERO_GUN_ARM_RIGHT_CASE_04, x=[HERO_X], y=[HERO_Y], zoom=0x40
	je [0xBE], 0x03, DRAW_CIN_148
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=HERO_GUN_ARM_RIGHT_CASE_04_CHARGE_BLINK, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


DRAW_CIN_148:
	video offset=CINEMATIC_148, x=[HERO_X], y=[HERO_Y]
	ret


DRAW_HERO_WALK_RIGHT_F10:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F10, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, HERO_GUN_ARM_POSE_CASE_01
	video type=0, offset=HERO_WALK_RIGHT_ARM_F10, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


DRAW_HERO_WALK_RIGHT_F11:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F11, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, HERO_GUN_ARM_POSE_CASE_01
	video type=0, offset=HERO_WALK_RIGHT_ARM_F11, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


DRAW_HERO_WALK_RIGHT_F12:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F12, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, HERO_GUN_ARM_POSE_CASE_01
	video type=0, offset=HERO_WALK_RIGHT_ARM_F12, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


DRAW_HERO_WALK_RIGHT_F13:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F13, x=[HERO_X], y=[HERO_Y], zoom=0x40
	play id=0x0060, freq=0x0B, vol=0x22, channel=0x01
	jne [0x0A], 0x00, HERO_GUN_ARM_POSE_CASE_01
	video type=0, offset=HERO_WALK_RIGHT_ARM_F13, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


DRAW_HERO_WALK_RIGHT_F14:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F14, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, HERO_GUN_ARM_POSE_CASE_01
	video type=0, offset=HERO_WALK_RIGHT_ARM_F14, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_98D5:
	call CAVES_HERO_WATER_DEPTH_SPRITE_RIGHT_CASE_00
	video type=0, offset=CV_0F90, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, HERO_GUN_ARM_POSE_CASE_01
	video type=0, offset=CV_338E, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


DRAW_HERO_WALK_RIGHT_F00:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F00, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, HERO_GUN_ARM_POSE_CASE_01
	video type=0, offset=HERO_WALK_RIGHT_ARM_F00, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


DRAW_HERO_WALK_RIGHT_F01:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F01, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, HERO_GUN_ARM_POSE_CASE_01
	video type=0, offset=HERO_WALK_RIGHT_ARM_F01, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


DRAW_HERO_WALK_RIGHT_F02:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F02, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, HERO_GUN_ARM_POSE_CASE_01
	video type=0, offset=HERO_WALK_RIGHT_ARM_F02, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


DRAW_HERO_WALK_RIGHT_F03:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F03, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, HERO_GUN_ARM_POSE_CASE_01
	video type=0, offset=HERO_WALK_RIGHT_ARM_F03, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


DRAW_HERO_WALK_RIGHT_F04:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F04, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, HERO_GUN_ARM_POSE_CASE_01
	video type=0, offset=HERO_WALK_RIGHT_ARM_F04, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


DRAW_HERO_WALK_RIGHT_F05:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F05, x=[HERO_X], y=[HERO_Y], zoom=0x40
	play id=0x0060, freq=0x14, vol=0x22, channel=0x01
	jne [0x0A], 0x00, HERO_GUN_ARM_POSE_CASE_01
	video type=0, offset=HERO_WALK_RIGHT_ARM_F05, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


DRAW_HERO_WALK_RIGHT_F06:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F06, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, HERO_GUN_ARM_POSE_CASE_01
	video type=0, offset=HERO_WALK_RIGHT_ARM_F06, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


DRAW_HERO_WALK_RIGHT_F07:
	call CAVES_HERO_WATER_DEPTH_SPRITE_RIGHT_CASE_00
	video type=0, offset=HERO_WALK_RIGHT_BODY_F07, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, HERO_GUN_ARM_POSE_CASE_01
	video type=0, offset=HERO_WALK_RIGHT_ARM_F07, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


DRAW_HERO_WALK_RIGHT_F08:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F08, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, HERO_GUN_ARM_POSE_CASE_01
	video type=0, offset=HERO_WALK_RIGHT_ARM_F08, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_998B:
	video type=0, offset=CV_3B10, x=[HERO_X], y=[HERO_Y], zoom=0x40
	je [0xBE], 0x03, DRAW_CIN_162
	ret


DRAW_CIN_162:
	video offset=CINEMATIC_162, x=[HERO_X], y=[HERO_Y]
	ret


HERO_CROUCH_ARMED_LEFT_FRAME_CHARGE_BLINK:
	video type=0, offset=CV_39A2, x=[HERO_X], y=[HERO_Y], zoom=0x40
	je [0xBE], 0x03, DRAW_CIN_163
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=CV_5C94, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


DRAW_CIN_163:
	video offset=CINEMATIC_163, x=[HERO_X], y=[HERO_Y]
	ret


LABEL_99C7:
	video type=0, offset=CV_3ADC, x=[HERO_X], y=[HERO_Y], zoom=0x40
	je [0xBE], 0x03, DRAW_CIN_164
	ret


DRAW_CIN_164:
	video offset=CINEMATIC_164, x=[HERO_X], y=[HERO_Y]
	ret


LABEL_99D9:
	video type=0, offset=CV_391A, x=[HERO_X], y=[HERO_Y], zoom=0x40
	je [0xBE], 0x03, DRAW_CIN_171
	ret


DRAW_CIN_171:
	video offset=CINEMATIC_171, x=[HERO_X], y=[HERO_Y]
	ret


LABEL_99EB:
	video type=0, offset=CV_3A64, x=[HERO_X], y=[HERO_Y], zoom=0x40
	je [0xBE], 0x03, DRAW_CIN_172
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=CV_5C9C, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


DRAW_CIN_172:
	video offset=CINEMATIC_172, x=[HERO_X], y=[HERO_Y]
	ret


LABEL_9A15:
	video type=0, offset=CV_3A96, x=[HERO_X], y=[HERO_Y], zoom=0x40
	je [0xBE], 0x03, DRAW_CIN_173
	ret


DRAW_CIN_173:
	video offset=CINEMATIC_173, x=[HERO_X], y=[HERO_Y]
	ret


GUARDED_DRAW_CV_126:
	call LABEL_96CD
	jne [0x0A], 0x01, HERO_GUN_ARM_POSE_LEFT_CASE_02
	video type=0, offset=HERO_GUN_ARM_LEFT_CASE_01, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


HERO_GUN_ARM_POSE_LEFT_CASE_02:
	jne [0x0A], 0x02, HERO_GUN_ARM_POSE_LEFT_CASE_03
	video type=0, offset=HERO_GUN_ARM_LEFT_CASE_02, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


HERO_GUN_ARM_POSE_LEFT_CASE_03:
	jne [0x0A], 0x03, HERO_GUN_ARM_POSE_LEFT_CASE_04
	video type=0, offset=HERO_GUN_ARM_LEFT_CASE_03, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


HERO_GUN_ARM_POSE_LEFT_CASE_04:
	video type=0, offset=HERO_GUN_ARM_LEFT_CASE_04, x=[HERO_X], y=[HERO_Y], zoom=0x40
	je [0xBE], 0x03, DRAW_CIN_165
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=HERO_GUN_ARM_LEFT_CASE_04_CHARGE_BLINK, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


DRAW_CIN_165:
	video offset=CINEMATIC_165, x=[HERO_X], y=[HERO_Y]
	ret


CAVES_HERO_WATER_DEPTH_SPRITE_LEFT_CASE_00:
	jne [0x05], 0x00, CAVES_HERO_WATER_DEPTH_SPRITE_LEFT_CASE_01
	video type=0, offset=HERO_WATER_DEPTH_LEFT_CASE_00, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


CAVES_HERO_WATER_DEPTH_SPRITE_LEFT_CASE_01:
	jne [0x05], 0x01, CAVES_HERO_WATER_DEPTH_SPRITE_LEFT_CASE_02
	video type=0, offset=HERO_WATER_DEPTH_LEFT_CASE_01, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


CAVES_HERO_WATER_DEPTH_SPRITE_LEFT_CASE_02:
	jne [0x05], 0x02, CAVES_HERO_WATER_DEPTH_SPRITE_LEFT_CASE_03
	video type=0, offset=HERO_WATER_DEPTH_LEFT_CASE_02, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


CAVES_HERO_WATER_DEPTH_SPRITE_LEFT_CASE_03:
	jne [0x05], 0x03, CAVES_HERO_WATER_DEPTH_SPRITE_LEFT_CASE_03_RET
	video type=0, offset=HERO_WATER_DEPTH_LEFT_CASE_03, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


CAVES_HERO_WATER_DEPTH_SPRITE_LEFT_CASE_03_RET:
	ret


LABEL_9AA9:
	je [0x0A], 0x00, DRAW_CV_113
	call GUARDED_DRAW_CV_126

.include "../_helpers/DRAW_CV_113.inc"

LABEL_9AB8:
	je [0x0A], 0x00, DRAW_CV_114
	call GUARDED_DRAW_CV_126

DRAW_CV_114:
	video type=0, offset=CV_00B4, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_9AC7:
	je [0x0A], 0x00, DRAW_CV_115
	call GUARDED_DRAW_CV_126

DRAW_CV_115:
	video type=0, offset=CV_0128, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_9AD6:
	je [0x0A], 0x00, DRAW_CV_116
	call GUARDED_DRAW_CV_126

.include "../_helpers/DRAW_CV_116.inc"

LABEL_9AE5:
	je [0x0A], 0x00, LABEL_9AEE
	call GUARDED_DRAW_CV_126

LABEL_9AEE:
	video type=0, offset=CV_0234, x=[HERO_X], y=[HERO_Y], zoom=0x40
	play id=0x0060, freq=0x0B, vol=0x22, channel=0x01
	ret


CAVES_HERO_WALK_LEFT_STRIDE_PHASE_15:
	jne [0x0A], 0x00, LABEL_9B08
	video type=0, offset=CV_331A, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jmp DRAW_CV_118

LABEL_9B08:
	call GUARDED_DRAW_CV_126

.include "../_helpers/DRAW_CV_118.inc"

LABEL_9B11:
	jne [0x0A], 0x00, LABEL_9B1F
	video type=0, offset=HERO_STAND_LEFT_ARM, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jmp LABEL_9B22

LABEL_9B1F:
	call GUARDED_DRAW_CV_126

LABEL_9B22:
	call CAVES_HERO_WATER_DEPTH_SPRITE_LEFT_CASE_00
	video type=0, offset=HERO_STAND_LEFT_BODY, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


CAVES_HERO_WALK_LEFT_STRIDE_PHASE_1:
	jne [0x0A], 0x00, LABEL_9B39
	video type=0, offset=CV_332A, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jmp DRAW_CV_099

LABEL_9B39:
	call GUARDED_DRAW_CV_126

.include "../_helpers/DRAW_CV_099.inc"

CAVES_HERO_WALK_LEFT_STRIDE_PHASE_2:
	jne [0x0A], 0x00, LABEL_9B50
	video type=0, offset=CV_3332, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jmp DRAW_CV_101

LABEL_9B50:
	call GUARDED_DRAW_CV_126

.include "../_helpers/DRAW_CV_101.inc"

CAVES_HERO_WALK_LEFT_STRIDE_PHASE_3:
	jne [0x0A], 0x00, LABEL_9B67
	video type=0, offset=CV_333A, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jmp DRAW_CV_103

LABEL_9B67:
	call GUARDED_DRAW_CV_126

.include "../_helpers/DRAW_CV_103.inc"

CAVES_HERO_WALK_LEFT_STRIDE_PHASE_4:
	jne [0x0A], 0x00, LABEL_9B7E
	video type=0, offset=CV_3342, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jmp DRAW_CV_105

LABEL_9B7E:
	call GUARDED_DRAW_CV_126

.include "../_helpers/DRAW_CV_105.inc"

CAVES_HERO_WALK_LEFT_STRIDE_PHASE_5:
	jne [0x0A], 0x00, LABEL_9B95
	video type=0, offset=CV_334A, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jmp DRAW_CV_107

LABEL_9B95:
	call GUARDED_DRAW_CV_126

.include "../_helpers/DRAW_CV_107.inc"

LABEL_9B9E:
	je [0x0A], 0x00, LABEL_9BA7
	call GUARDED_DRAW_CV_126

LABEL_9BA7:
	video type=0, offset=CV_0814, x=[HERO_X], y=[HERO_Y], zoom=0x40
	play id=0x0060, freq=0x14, vol=0x20, channel=0x01
	ret


LABEL_9BB3:
	je [0x0A], 0x00, DRAW_CV_110
	call GUARDED_DRAW_CV_126

DRAW_CV_110:
	video type=0, offset=CV_0844, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_9BC2:
	call CAVES_HERO_WATER_DEPTH_SPRITE_LEFT_CASE_00
	je [0x0A], 0x00, DRAW_CV_111
	call GUARDED_DRAW_CV_126

.include "../_helpers/DRAW_CV_111.inc"

LABEL_9BD4:
	je [0x0A], 0x00, DRAW_CV_112
	call GUARDED_DRAW_CV_126

DRAW_CV_112:
	video type=0, offset=CV_08A0, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


.include "../_helpers/DRAW_CV_273.inc"

.include "../_helpers/DRAW_CV_270.inc"

.include "../_helpers/DRAW_CV_252.inc"

.include "../_helpers/DRAW_CV_255.inc"

.include "../_helpers/DRAW_CV_265.inc"

DRAW_HERO_RUN_RIGHT_F00:
	video type=0, offset=HERO_RUN_RIGHT_BODY_F00, x=[HERO_X], y=[HERO_Y], zoom=0x40
	play id=0x0060, freq=0x0F, vol=0x2A, channel=0x01
	jne [0x0A], 0x00, DRAW_CV_252
	video type=0, offset=HERO_RUN_RIGHT_ARM_F00, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


DRAW_HERO_RUN_RIGHT_F01:
	video type=0, offset=HERO_RUN_RIGHT_BODY_F01, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, DRAW_CV_255
	video type=0, offset=HERO_RUN_RIGHT_ARM_F01, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


DRAW_HERO_RUN_RIGHT_F02:
	video type=0, offset=HERO_RUN_RIGHT_BODY_F02, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, DRAW_CV_270
	video type=0, offset=HERO_RUN_RIGHT_ARM_F02, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


DRAW_HERO_RUN_RIGHT_F03:
	video type=0, offset=HERO_RUN_RIGHT_BODY_F03, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, DRAW_CV_273
	video type=0, offset=HERO_RUN_RIGHT_ARM_F03, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


DRAW_HERO_RUN_RIGHT_F04:
	video type=0, offset=HERO_RUN_RIGHT_BODY_F04, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, DRAW_CV_273
	video type=0, offset=HERO_RUN_RIGHT_ARM_F04, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


DRAW_HERO_RUN_RIGHT_F05:
	video type=0, offset=HERO_RUN_RIGHT_BODY_F05, x=[HERO_X], y=[HERO_Y], zoom=0x40
	play id=0x0060, freq=0x0A, vol=0x2A, channel=0x01
	jne [0x0A], 0x00, DRAW_CV_252
	video type=0, offset=HERO_RUN_RIGHT_ARM_F05, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


DRAW_HERO_RUN_RIGHT_F06:
	video type=0, offset=HERO_RUN_RIGHT_BODY_F06, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, DRAW_CV_252
	video type=0, offset=HERO_RUN_RIGHT_ARM_F06, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


DRAW_HERO_RUN_RIGHT_F07:
	video type=0, offset=HERO_RUN_RIGHT_BODY_F07, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, DRAW_CV_255
	video type=0, offset=HERO_RUN_RIGHT_ARM_F07, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


DRAW_HERO_RUN_RIGHT_F08:
	video type=0, offset=HERO_RUN_RIGHT_BODY_F08, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, DRAW_CV_265
	video type=0, offset=HERO_RUN_RIGHT_ARM_F08, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


DRAW_HERO_RUN_RIGHT_F09:
	video type=0, offset=HERO_RUN_RIGHT_BODY_F09, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, DRAW_CV_265
	video type=0, offset=HERO_RUN_RIGHT_ARM_F09, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


.include "../_helpers/DRAW_CV_279.inc"

CAVES_HERO_RUN_LEFT_DRAW_PHASE_1:
	je [0x0A], 0x00, CAVES_HERO_RUN_LEFT_NO_GUN_ARM_PHASE_1
	call DRAW_CV_279
	jmp LABEL_9CCE

CAVES_HERO_RUN_LEFT_NO_GUN_ARM_PHASE_1:
	video type=0, offset=CV_3630, x=[HERO_X], y=[HERO_Y], zoom=0x40

LABEL_9CCE:
	video type=0, offset=CV_11B8, x=[HERO_X], y=[HERO_Y], zoom=0x40
	play id=0x0060, freq=0x0F, vol=0x2A, channel=0x01
	ret


CAVES_HERO_RUN_LEFT_DRAW_PHASE_2:
	je [0x0A], 0x00, CAVES_HERO_RUN_LEFT_NO_GUN_ARM_PHASE_2
	call DRAW_CV_279
	jmp DRAW_CV_281

CAVES_HERO_RUN_LEFT_NO_GUN_ARM_PHASE_2:
	video type=0, offset=CV_3638, x=[HERO_X], y=[HERO_Y], zoom=0x40

.include "../_helpers/DRAW_CV_281.inc"

CAVES_HERO_RUN_LEFT_DRAW_PHASE_3:
	je [0x0A], 0x00, CAVES_HERO_RUN_LEFT_NO_GUN_ARM_PHASE_3
	call DRAW_CV_279
	jmp DRAW_CV_294

CAVES_HERO_RUN_LEFT_NO_GUN_ARM_PHASE_3:
	video type=0, offset=CV_3640, x=[HERO_X], y=[HERO_Y], zoom=0x40

.include "../_helpers/DRAW_CV_294.inc"

CAVES_HERO_RUN_LEFT_DRAW_PHASE_4:
	je [0x0A], 0x00, CAVES_HERO_RUN_LEFT_NO_GUN_ARM_PHASE_4
	call DRAW_CV_279
	jmp DRAW_CV_296

CAVES_HERO_RUN_LEFT_NO_GUN_ARM_PHASE_4:
	video type=0, offset=CV_3648, x=[HERO_X], y=[HERO_Y], zoom=0x40

DRAW_CV_296:
	video type=0, offset=CV_13B2, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_9D1F:
	je [0x0A], 0x00, DRAW_CV_297
	call DRAW_CV_279

DRAW_CV_297:
	video type=0, offset=CV_1474, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


CAVES_HERO_RUN_LEFT_DRAW_PHASE_6:
	je [0x0A], 0x00, CAVES_HERO_RUN_LEFT_NO_GUN_ARM_PHASE_6
	call DRAW_CV_279
	jmp LABEL_9D3F

CAVES_HERO_RUN_LEFT_NO_GUN_ARM_PHASE_6:
	video type=0, offset=CV_3650, x=[HERO_X], y=[HERO_Y], zoom=0x40

LABEL_9D3F:
	video type=0, offset=CV_150A, x=[HERO_X], y=[HERO_Y], zoom=0x40
	play id=0x0060, freq=0x0A, vol=0x2A, channel=0x01
	ret


CAVES_HERO_RUN_LEFT_DRAW_PHASE_7:
	je [0x0A], 0x00, CAVES_HERO_RUN_LEFT_NO_GUN_ARM_PHASE_7
	call DRAW_CV_279
	jmp DRAW_CV_286

CAVES_HERO_RUN_LEFT_NO_GUN_ARM_PHASE_7:
	video type=0, offset=CV_3674, x=[HERO_X], y=[HERO_Y], zoom=0x40

.include "../_helpers/DRAW_CV_286.inc"

CAVES_HERO_RUN_LEFT_DRAW_PHASE_8:
	je [0x0A], 0x00, CAVES_HERO_RUN_LEFT_NO_GUN_ARM_PHASE_8
	call DRAW_CV_279
	jmp DRAW_CV_288

CAVES_HERO_RUN_LEFT_NO_GUN_ARM_PHASE_8:
	video type=0, offset=CV_3658, x=[HERO_X], y=[HERO_Y], zoom=0x40

.include "../_helpers/DRAW_CV_288.inc"

CAVES_HERO_RUN_LEFT_DRAW_PHASE_9:
	je [0x0A], 0x00, CAVES_HERO_RUN_LEFT_NO_GUN_ARM_PHASE_9
	call DRAW_CV_279
	jmp DRAW_CV_290

CAVES_HERO_RUN_LEFT_NO_GUN_ARM_PHASE_9:
	video type=0, offset=CV_3660, x=[HERO_X], y=[HERO_Y], zoom=0x40

.include "../_helpers/DRAW_CV_290.inc"

CAVES_HERO_RUN_LEFT_DRAW_PHASE_10:
	je [0x0A], 0x00, CAVES_HERO_RUN_LEFT_NO_GUN_ARM_PHASE_10
	call DRAW_CV_279
	jmp DRAW_CV_292

CAVES_HERO_RUN_LEFT_NO_GUN_ARM_PHASE_10:
	video type=0, offset=CV_366C, x=[HERO_X], y=[HERO_Y], zoom=0x40

.include "../_helpers/DRAW_CV_292.inc"
LABEL_9DA7:
	db 0x0A, 0x00, 0x1F, 0x00, 0x9D, 0xD6, 0x0A, 0x04
	db 0x1E, 0x00, 0x9D, 0xC5, 0x00, 0x20, 0xFF, 0xFF
	db 0x13, 0x1E, 0x1F, 0x03, 0x20, 0x00, 0x01, 0x0A
	db 0x03, 0x1E, 0x00, 0x9D, 0xB7, 0x05, 0x00, 0x20
	db 0x00, 0x01, 0x02, 0x1E, 0x1F, 0x03, 0x20, 0xFF
	db 0xFF, 0x0A, 0x05, 0x1E, 0x00, 0x9D, 0xC9, 0x05
	db 0x11, 0x0A, 0x81, 0x67, 0x65, 0x9D, 0xF3, 0x0F
	db 0x03, 0xFF, 0x0F, 0x00, 0x03, 0x0F, 0xFF, 0x00
	db 0x01, 0x67, 0x65, 0x01, 0x65, 0x66, 0x01, 0x66
	db 0x67, 0x07, 0x9D, 0xF9, 0x0F, 0x00, 0x03, 0x01
	db 0x65, 0x66, 0x05

CAVES_TELEPORT_UP_SETTLE_LOOP:
	jg [HERO_Y], [0x51], COPY_VAR51_TO_VAR02_KILL_CHANNEL
	add [HERO_Y], 0x0001
	break
	jmp CAVES_TELEPORT_UP_SETTLE_LOOP
