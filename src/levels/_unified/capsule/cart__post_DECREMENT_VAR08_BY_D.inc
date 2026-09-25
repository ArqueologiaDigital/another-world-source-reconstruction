LABEL_8D64:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	video offset=CINEMATIC_246, x=[ACTOR_X], y=[ACTOR_Y]
	call BUDDY_RIGHT_FIRE_AIM_PHASE_1
	ret


LABEL_8D73:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	sub [ACTOR_X], 0x0001
	call LABEL_8CC2
	video type=0, offset=CV_4324, x=[ACTOR_X], y=[ACTOR_Y], zoom=0x40
	sub [ACTOR_Y], 0x0001
	call LABEL_7898
	add [ACTOR_Y], 0x0001
	add [ACTOR_X], 0x0001
	ret


LABEL_8D95:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	call LABEL_8CC2
	video type=0, offset=CV_FIGURE_CROUCH_FACING_LEFT, x=[ACTOR_X], y=[ACTOR_Y], zoom=0x40
	call LABEL_7898
	ret


LABEL_8DA7:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	add [ACTOR_Y], 0x000D
	sub [ACTOR_X], 0x0004
	video type=0, offset=CV_2570, x=[ACTOR_X], y=[ACTOR_Y], zoom=0x40
	add [ACTOR_X], 0x0004
	sub [ACTOR_Y], 0x000D
	call LABEL_8CC2
	video type=0, offset=CV_FIGURE_CROUCH_FACING_LEFT, x=[ACTOR_X], y=[ACTOR_Y], zoom=0x40
	add [ACTOR_Y], 0x000D
	call LABEL_8602
	sub [ACTOR_Y], 0x000D
	ret


LABEL_8DD6:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	call LABEL_8CC2
	video type=0, offset=CV_FIGURE_CROUCH_FACING_LEFT, x=[ACTOR_X], y=[ACTOR_Y], zoom=0x40
	add [ACTOR_Y], 0x000D
	call LABEL_8602
	sub [ACTOR_Y], 0x000D
	ret


LABEL_8DF0:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	add [ACTOR_Y], 0x000D
	video offset=CINEMATIC_263, x=[ACTOR_X], y=[ACTOR_Y]
	sub [ACTOR_Y], 0x000D
	call LABEL_8CC2
	video type=0, offset=CV_FIGURE_CROUCH_FACING_LEFT, x=[ACTOR_X], y=[ACTOR_Y], zoom=0x40
	add [ACTOR_Y], 0x000D
	call LABEL_8602
	sub [ACTOR_Y], 0x000D
	ret


LABEL_8E17:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	sub [ACTOR_X], 0x0001
	add [ACTOR_Y], 0x000D
	video offset=CINEMATIC_262, x=[ACTOR_X], y=[ACTOR_Y]
	sub [ACTOR_Y], 0x000D
	call LABEL_8CC2
	video type=0, offset=CV_4324, x=[ACTOR_X], y=[ACTOR_Y], zoom=0x40
	add [ACTOR_Y], 0x000D
	call LABEL_85EC
	sub [ACTOR_Y], 0x000D
	add [ACTOR_X], 0x0001
	ret


LABEL_8E46:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_4346, x=[ACTOR_X], y=[ACTOR_Y], zoom=0x40
	sub [ACTOR_Y], 0x000D
	call LABEL_7818
	add [ACTOR_Y], 0x000D
	ret


LABEL_8E60:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	sub [ACTOR_X], 0x0001
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_4368, x=[ACTOR_X], y=[ACTOR_Y], zoom=0x40
	sub [ACTOR_Y], 0x000E
	call LABEL_7846
	add [ACTOR_Y], 0x000E
	add [ACTOR_X], 0x0001
	ret


	jne [SCREEN_NUM], [0x10], SHARED_RET
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_4346, x=[ACTOR_X], y=[ACTOR_Y], zoom=0x40
	sub [ACTOR_Y], 0x000D
	call LABEL_7878
	add [ACTOR_Y], 0x000D
	ret


LABEL_8E9C:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_4346, x=[ACTOR_X], y=[ACTOR_Y], zoom=0x40
	sub [ACTOR_Y], 0x000D
	call LABEL_7846
	add [ACTOR_Y], 0x000D
	ret


	jne [SCREEN_NUM], [0x10], SHARED_RET
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_4346, x=[ACTOR_X], y=[ACTOR_Y], zoom=0x40
	ret


JUNK__8EC5:
	call LABEL_8CE6
	break
	call LABEL_8CE6
	break
	call LABEL_8CE6
	sub [ACTOR_X], 0x0001
	break
	call LABEL_8CF8
	add [ACTOR_X], 0x0001
	break
	jmp JUNK__8EC5
LABEL_8EE0:
	db 0x11

LABEL_8EE1:
	call INLINE_OR_VAR11_WITH_1000
	jmp LABEL_8EF0
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_4B28

LABEL_8EF0:
	call LABEL_82FC
	add [ACTOR_X], 0x0007
	break
	jl [ACTOR_X], [0x29], LABEL_8F07
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_4B28

LABEL_8F07:
	call LABEL_8329
	add [ACTOR_X], 0x0009
	break
	jl [ACTOR_X], [0x29], LABEL_8F1E
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_4B28

LABEL_8F1E:
	call CAPSULE_ACTOR_RUN_RIGHT_DRAW_2
	add [ACTOR_X], 0x0009
	break
	jl [ACTOR_X], [0x29], LABEL_8F35
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_4B28

LABEL_8F35:
	call LABEL_8381
	add [ACTOR_X], 0x0008
	break
	jl [ACTOR_X], [0x29], LABEL_8F4C
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_4B28

LABEL_8F4C:
	call LABEL_83AE
	add [ACTOR_X], 0x000A
	break
	jl [ACTOR_X], [0x29], LABEL_8F63
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_4B28

LABEL_8F63:
	call LABEL_83D3
	add [ACTOR_X], 0x0007
	break
	jl [ACTOR_X], [0x29], LABEL_8F7A
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_4B28

LABEL_8F7A:
	call LABEL_8400
	add [ACTOR_X], 0x0009
	break
	jl [ACTOR_X], [0x29], LABEL_8F91
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_4B28

LABEL_8F91:
	call LABEL_8425
	add [ACTOR_X], 0x0009
	break
	jl [ACTOR_X], [0x29], LABEL_8FA8
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_4B28

LABEL_8FA8:
	call CAPSULE_ACTOR_RUN_RIGHT_DRAW_8
	add [ACTOR_X], 0x0008
	break
	jl [ACTOR_X], [0x29], LABEL_8FBF
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_4B28

LABEL_8FBF:
	call CAPSULE_DRAW_CV261_AT_X07_Y08_L0
	add [ACTOR_X], 0x000A
	break
	jmp LABEL_8EE1
	killChannel

LABEL_8FCB:
	call GUARDED_DRAW_CV_304_305
	break
	jmp LABEL_8FCB
LABEL_8FD2:
	db 0x11

LABEL_8FD3:
	call INLINE_OR_VAR11_WITH_1000
	jmp LABEL_8FE2
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, CAPSULE_BUDDY_SCENE_MAIN_LOOP

LABEL_8FE2:
	call LABEL_86B4
	add [ACTOR_X], 0x0002
	break
	jl [ACTOR_X], [0x29], LABEL_8FF9
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, CAPSULE_BUDDY_SCENE_MAIN_LOOP

LABEL_8FF9:
	call DRAW_FIGURE_WALK_RIGHT_F01
	add [ACTOR_X], 0x0002
	break
	jl [ACTOR_X], [0x29], LABEL_9010
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, CAPSULE_BUDDY_SCENE_MAIN_LOOP

LABEL_9010:
	call LABEL_8708
	add [ACTOR_X], 0x0003
	break
	jl [ACTOR_X], [0x29], LABEL_9027
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, CAPSULE_BUDDY_SCENE_MAIN_LOOP

LABEL_9027:
	call DRAW_FIGURE_WALK_RIGHT_F03
	add [ACTOR_X], 0x0003
	break
	jl [ACTOR_X], [0x29], LABEL_903E
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, CAPSULE_BUDDY_SCENE_MAIN_LOOP

LABEL_903E:
	call LABEL_8756
	add [ACTOR_X], 0x0003
	break
	jl [ACTOR_X], [0x29], LABEL_9055
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, CAPSULE_BUDDY_SCENE_MAIN_LOOP

LABEL_9055:
	call LABEL_8777
	add [ACTOR_X], 0x0003
	break
	jl [ACTOR_X], [0x29], LABEL_906C
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, CAPSULE_BUDDY_SCENE_MAIN_LOOP

LABEL_906C:
	call LABEL_879D
	add [ACTOR_X], 0x0003
	break
	jl [ACTOR_X], [0x29], LABEL_9083
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, CAPSULE_BUDDY_SCENE_MAIN_LOOP

LABEL_9083:
	call LABEL_87C3
	add [ACTOR_X], 0x0002
	break
	jl [ACTOR_X], [0x29], LABEL_909A
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, CAPSULE_BUDDY_SCENE_MAIN_LOOP

LABEL_909A:
	call LABEL_87E9
	add [ACTOR_X], 0x0002
	break
	jl [ACTOR_X], [0x29], LABEL_90B1
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, CAPSULE_BUDDY_SCENE_MAIN_LOOP

LABEL_90B1:
	call LABEL_880F
	add [ACTOR_X], 0x0002
	break
	jl [ACTOR_X], [0x29], LABEL_90C8
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, CAPSULE_BUDDY_SCENE_MAIN_LOOP

LABEL_90C8:
	call LABEL_883D
	add [ACTOR_X], 0x0003
	break
	jl [ACTOR_X], [0x29], LABEL_90DF
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, CAPSULE_BUDDY_SCENE_MAIN_LOOP

LABEL_90DF:
	call DRAW_FIGURE_WALK_RIGHT_F11
	add [ACTOR_X], 0x0003
	break
	jl [ACTOR_X], [0x29], LABEL_90F6
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, CAPSULE_BUDDY_SCENE_MAIN_LOOP

LABEL_90F6:
	call LABEL_8895
	add [ACTOR_X], 0x0003
	break
	jl [ACTOR_X], [0x29], LABEL_910D
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, CAPSULE_BUDDY_SCENE_MAIN_LOOP

LABEL_910D:
	call LABEL_88B6
	add [ACTOR_X], 0x0003
	break
	jl [ACTOR_X], [0x29], LABEL_9124
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, CAPSULE_BUDDY_SCENE_MAIN_LOOP

LABEL_9124:
	call LABEL_88D7
	add [ACTOR_X], 0x0003
	break
	jl [ACTOR_X], [0x29], LABEL_913B
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, CAPSULE_BUDDY_SCENE_MAIN_LOOP

LABEL_913B:
	call LABEL_88F8
	add [ACTOR_X], 0x0002
	break
	jmp LABEL_8FD3
CAPSULE_HERO_AIM_HOLD_RIGHT_DRAW_LOW_CHARGE_BLINK:
	db 0x11

LABEL_9147:
	je [0x0A], [0x0C], KILL_CHAN_AT_9165
	jg [0x0A], [0x0C], LABEL_9166

LABEL_9153:
	add [0x0A], 0x0001
	break
	jne [0x0A], 0x03, LABEL_915F
	break

LABEL_915F:
	jl [0x0A], [0x0C], LABEL_9153

KILL_CHAN_AT_9165:
	killChannel

LABEL_9166:
	sub [0x0A], 0x0001
	break
	jne [0x0A], 0x02, LABEL_9172
	break

LABEL_9172:
	jg [0x0A], [0x0C], LABEL_9166
	killChannel

LABEL_9179:
	sub [0x0B], 0x0001
	jg [0x0B], 0x00, LABEL_91AE
	je [HERO_POS_MASK], 0x00, LABEL_919C
	call LABEL_3240
	mov [0x0B], [RANDOM_SEED]
	add [0x0B], 0x0006
	mov [0x0C], 0x0004
	setup channel=0x15, address=LABEL_9147
	ret


LABEL_919C:
	call LABEL_3240
	mov [0x0B], [0x3A]
	add [0x0B], 0x0006
	mov [0x0C], 0x0001
	setup channel=0x15, address=LABEL_9147

LABEL_91AE:
	ret


LABEL_91AF:
	video type=0, offset=HERO_CROUCH_AIM_RIGHT, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=HERO_CROUCH_AIM_RIGHT_CHARGE_DOT, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_91CD:
	video offset=CINEMATIC_332, x=[HERO_X], y=[HERO_Y]
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=HERO_STAND_AIM_RIGHT_CHARGE_DOT, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


DRAW_HERO_WATER_DEPTH_RIGHT_CASE_00:
	jne [0x05], 0x00, DRAW_HERO_WATER_DEPTH_RIGHT_CASE_01
	video type=0, offset=HERO_WATER_DEPTH_RIGHT_CASE_00, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


DRAW_HERO_WATER_DEPTH_RIGHT_CASE_01:
	jne [0x05], 0x01, DRAW_HERO_WATER_DEPTH_RIGHT_CASE_02
	video type=0, offset=HERO_WATER_DEPTH_RIGHT_CASE_01, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


DRAW_HERO_WATER_DEPTH_RIGHT_CASE_02:
	jne [0x05], 0x02, DRAW_HERO_WATER_DEPTH_RIGHT_CASE_03
	video type=0, offset=HERO_WATER_DEPTH_RIGHT_CASE_02, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


DRAW_HERO_WATER_DEPTH_RIGHT_CASE_03:
	jne [0x05], 0x03, LABEL_921B
	video type=0, offset=HERO_WATER_DEPTH_RIGHT_CASE_03, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_921B:
	ret


LABEL_921C:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F09, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, HERO_GUN_ARM_POSE_CASE_01
	video type=0, offset=HERO_WALK_RIGHT_ARM_F09, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


HERO_GUN_ARM_POSE_CASE_01:
	call LABEL_9179
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
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=HERO_GUN_ARM_RIGHT_CASE_04_CHARGE_BLINK, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_92BA:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F10, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, HERO_GUN_ARM_POSE_CASE_01
	video type=0, offset=HERO_WALK_RIGHT_ARM_F10, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_92CB:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F11, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, HERO_GUN_ARM_POSE_CASE_01
	video type=0, offset=HERO_WALK_RIGHT_ARM_F11, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_92DC:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F12, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, HERO_GUN_ARM_POSE_CASE_01
	video type=0, offset=HERO_WALK_RIGHT_ARM_F12, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_92ED:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F13, x=[HERO_X], y=[HERO_Y], zoom=0x40
	play id=0x0060, freq=0x0B, vol=0x22, channel=0x01
	jne [0x0A], 0x00, HERO_GUN_ARM_POSE_CASE_01
	video type=0, offset=HERO_WALK_RIGHT_ARM_F13, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


CAPSULE_HERO_WALK_RIGHT_DRAW_4:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F14, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, HERO_GUN_ARM_POSE_CASE_01
	video type=0, offset=HERO_WALK_RIGHT_ARM_F14, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


CAPSULE_HERO_WALK_RIGHT_FOOTSTEP_PHASE_1:
	call DRAW_HERO_WATER_DEPTH_RIGHT_CASE_00
	video type=0, offset=HERO_STAND_RIGHT_BODY, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, HERO_GUN_ARM_POSE_CASE_01
	video type=0, offset=HERO_STAND_RIGHT_ARM, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_9329:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F00, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, HERO_GUN_ARM_POSE_CASE_01
	video type=0, offset=HERO_WALK_RIGHT_ARM_F00, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_933A:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F01, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, HERO_GUN_ARM_POSE_CASE_01
	video type=0, offset=HERO_WALK_RIGHT_ARM_F01, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_934B:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F02, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, HERO_GUN_ARM_POSE_CASE_01
	video type=0, offset=HERO_WALK_RIGHT_ARM_F02, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_935C:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F03, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, HERO_GUN_ARM_POSE_CASE_01
	video type=0, offset=HERO_WALK_RIGHT_ARM_F03, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_936D:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F04, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, HERO_GUN_ARM_POSE_CASE_01
	video type=0, offset=HERO_WALK_RIGHT_ARM_F04, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_937E:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F05, x=[HERO_X], y=[HERO_Y], zoom=0x40
	play id=0x0060, freq=0x14, vol=0x20, channel=0x01
	jne [0x0A], 0x00, HERO_GUN_ARM_POSE_CASE_01
	video type=0, offset=HERO_WALK_RIGHT_ARM_F05, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_9395:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F06, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, HERO_GUN_ARM_POSE_CASE_01
	video type=0, offset=HERO_WALK_RIGHT_ARM_F06, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


DRAW_HERO_WALK_RIGHT_F07:
	call DRAW_HERO_WATER_DEPTH_RIGHT_CASE_00
	video type=0, offset=HERO_WALK_RIGHT_BODY_F07, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, HERO_GUN_ARM_POSE_CASE_01
	video type=0, offset=HERO_WALK_RIGHT_ARM_F07, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_93BA:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F08, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, HERO_GUN_ARM_POSE_CASE_01
	video type=0, offset=HERO_WALK_RIGHT_ARM_F08, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_93CB:
	video type=0, offset=HERO_CROUCH_AIM_LEFT, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=HERO_CROUCH_AIM_LEFT_CHARGE_DOT, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_93E9:
	video type=0, offset=HERO_STAND_AIM_LEFT, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=HERO_STAND_AIM_LEFT_CHARGE_DOT, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


HERO_GUN_ARM_POSE_LEFT_CASE_01:
	call LABEL_9179
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
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=HERO_GUN_ARM_LEFT_CASE_04_CHARGE_BLINK, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


DRAW_HERO_WATER_DEPTH_LEFT_CASE_00:
	jne [0x05], 0x00, DRAW_HERO_WATER_DEPTH_LEFT_CASE_01
	video type=0, offset=HERO_WATER_DEPTH_LEFT_CASE_00, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


DRAW_HERO_WATER_DEPTH_LEFT_CASE_01:
	jne [0x05], 0x01, DRAW_HERO_WATER_DEPTH_LEFT_CASE_02
	video type=0, offset=HERO_WATER_DEPTH_LEFT_CASE_01, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


DRAW_HERO_WATER_DEPTH_LEFT_CASE_02:
	jne [0x05], 0x02, DRAW_HERO_WATER_DEPTH_LEFT_CASE_03
	video type=0, offset=HERO_WATER_DEPTH_LEFT_CASE_02, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


DRAW_HERO_WATER_DEPTH_LEFT_CASE_03:
	jne [0x05], 0x03, LABEL_947C
	video type=0, offset=HERO_WATER_DEPTH_LEFT_CASE_03, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_947C:
	ret


CAPSULE_HERO_WALK_LEFT_DRAW_9:
	je [0x0A], 0x00, CAPSULE_DRAW_HERO_WALK_LEFT_BODY_F09
	call HERO_GUN_ARM_POSE_LEFT_CASE_01
