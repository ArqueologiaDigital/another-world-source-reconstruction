LABEL_958D:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	video offset=CINEMATIC_060, x=[0x07], y=[0x08]
	call CAVES_DRAW_CV_355_L7
	ret


LABEL_959C:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	sub [0x07], 0x0001
	call DRAW_HERO_Y_PLUS_E
	video type=0, offset=CV_4324, x=[0x07], y=[0x08], zoom=0x40
	sub [0x08], 0x0001
	call LABEL_8201
	add [0x08], 0x0001
	add [0x07], 0x0001
	ret


LABEL_95BE:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	call DRAW_HERO_Y_PLUS_E
	video type=0, offset=CV_FIGURE_CROUCH_FACING_LEFT, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_8201
	ret


LABEL_95D0:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	add [0x08], 0x000D
	sub [0x07], 0x0004
	video type=0, offset=CV_2570, x=[0x07], y=[0x08], zoom=0x40
	add [0x07], 0x0004
	sub [0x08], 0x000D
	call DRAW_HERO_Y_PLUS_E
	video type=0, offset=CV_FIGURE_CROUCH_FACING_LEFT, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_8EC7
	sub [0x08], 0x000D
	ret


LABEL_95FF:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	call DRAW_HERO_Y_PLUS_E
	video type=0, offset=CV_FIGURE_CROUCH_FACING_LEFT, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_8EC7
	sub [0x08], 0x000D
	ret


LABEL_9619:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	add [0x08], 0x000D
	video offset=CINEMATIC_138, x=[0x07], y=[0x08]
	sub [0x08], 0x000D
	call DRAW_HERO_Y_PLUS_E
	video type=0, offset=CV_FIGURE_CROUCH_FACING_LEFT, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_8EC7
	sub [0x08], 0x000D
	ret


LABEL_9640:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	sub [0x07], 0x0001
	add [0x08], 0x000D
	video offset=CINEMATIC_137, x=[0x07], y=[0x08]
	sub [0x08], 0x000D
	call DRAW_HERO_Y_PLUS_E
	video type=0, offset=CV_4324, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_8EB1
	sub [0x08], 0x000D
	add [0x07], 0x0001
	ret


LABEL_966F:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_4346, x=[0x07], y=[0x08], zoom=0x40
	sub [0x08], 0x000D
	call CAVES_DRAW_CV_355_L1
	add [0x08], 0x000D
	ret


LABEL_9689:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	sub [0x07], 0x0001
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_4368, x=[0x07], y=[0x08], zoom=0x40
	sub [0x08], 0x000E
	call CAVES_DRAW_CV_355_L3
	add [0x08], 0x000E
	add [0x07], 0x0001
	ret


	jne [SCREEN_NUM], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_4346, x=[0x07], y=[0x08], zoom=0x40
	sub [0x08], 0x000D
	call CAVES_DRAW_CV_355_L5
	add [0x08], 0x000D
	ret


LABEL_96C5:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_4346, x=[0x07], y=[0x08], zoom=0x40
	sub [0x08], 0x000D
	call CAVES_DRAW_CV_355_L3
	add [0x08], 0x000D
	ret


	jne [SCREEN_NUM], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_4346, x=[0x07], y=[0x08], zoom=0x40
	ret


JUNK__96EE:
	call CAVES_DRAW_CV_355_L0
	break
	call CAVES_DRAW_CV_355_L0
	break
	call CAVES_DRAW_CV_355_L0
	sub [0x07], 0x0001
	break
	call CAVES_DRAW_CV_355_L2
	add [0x07], 0x0001
	break
	jmp JUNK__96EE
LABEL_9709:
	db 0x11

LABEL_970A:
	call INLINE_OR_VAR11_WITH_1000
	jmp LABEL_9719
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_55D7

LABEL_9719:
	call LABEL_8BD9
	add [0x07], 0x0007
	break
	jl [0x07], [0x29], LABEL_9730
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_55D7

LABEL_9730:
	call LABEL_8C06
	add [0x07], 0x0009
	break
	jl [0x07], [0x29], LABEL_9747
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_55D7

LABEL_9747:
	call CAVES_ACTOR_RUN_RIGHT_PHASE_3_FRAME
	add [0x07], 0x0009
	break
	jl [0x07], [0x29], LABEL_975E
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_55D7

LABEL_975E:
	call LABEL_8C58
	add [0x07], 0x0008
	break
	jl [0x07], [0x29], LABEL_9775
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_55D7

LABEL_9775:
	call LABEL_8C85
	add [0x07], 0x000A
	break
	jl [0x07], [0x29], LABEL_978C
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_55D7

LABEL_978C:
	call CAVES_ACTOR_RUN_RIGHT_PHASE_6_FRAME
	add [0x07], 0x0007
	break
	jl [0x07], [0x29], LABEL_97A3
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_55D7

LABEL_97A3:
	call LABEL_8CD7
	add [0x07], 0x0009
	break
	jl [0x07], [0x29], LABEL_97BA
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_55D7

LABEL_97BA:
	call CAVES_ACTOR_RUN_RIGHT_PHASE_8_FRAME
	add [0x07], 0x0009
	break
	jl [0x07], [0x29], LABEL_97D1
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_55D7

LABEL_97D1:
	call LABEL_8D29
	add [0x07], 0x0008
	break
	jl [0x07], [0x29], LABEL_97E8
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x03, LABEL_55D7

LABEL_97E8:
	call LABEL_8D56
	add [0x07], 0x000A
	break
	jmp LABEL_970A
	killChannel

LABEL_97F4:
	call GUARDED_BEAST_OR_CV_304_305
	break
	jmp LABEL_97F4
LABEL_97FB:
	db 0x11

LABEL_97FC:
	call INLINE_OR_VAR11_WITH_1000
	jmp LABEL_980B
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_HERO_CV128

LABEL_980B:
	call LABEL_8F79
	add [0x07], 0x0002
	break
	jl [0x07], [0x29], LABEL_9822
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_HERO_CV128

LABEL_9822:
	call LABEL_8F9F
	add [0x07], 0x0002
	break
	jl [0x07], [0x29], LABEL_9839
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_HERO_CV128

LABEL_9839:
	call LABEL_8FCD
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], LABEL_9850
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_HERO_CV128

LABEL_9850:
	call LABEL_8FEE
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], LABEL_9867
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_HERO_CV128

LABEL_9867:
	call LABEL_9015
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], LABEL_987E
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_HERO_CV128

LABEL_987E:
	call LABEL_9036
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], LABEL_9895
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_HERO_CV128

LABEL_9895:
	call LABEL_905C
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], LABEL_98AC
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_HERO_CV128

LABEL_98AC:
	call LABEL_9082
	add [0x07], 0x0002
	break
	jl [0x07], [0x29], LABEL_98C3
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_HERO_CV128

LABEL_98C3:
	call LABEL_90A8
	add [0x07], 0x0002
	break
	jl [0x07], [0x29], LABEL_98DA
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_HERO_CV128

LABEL_98DA:
	call LABEL_90CE
	add [0x07], 0x0002
	break
	jl [0x07], [0x29], LABEL_98F1
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_HERO_CV128

LABEL_98F1:
	call LABEL_90FC
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], LABEL_9908
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_HERO_CV128

LABEL_9908:
	call LABEL_9122
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], LABEL_991F
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_HERO_CV128

LABEL_991F:
	call LABEL_914E
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], LABEL_9936
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_HERO_CV128

LABEL_9936:
	call LABEL_916F
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], LABEL_994D
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_HERO_CV128

LABEL_994D:
	call LABEL_9190
	add [0x07], 0x0003
	break
	jl [0x07], [0x29], LABEL_9964
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x01, GAME_LOOP_HERO_CV128

LABEL_9964:
	call LABEL_91B1
	add [0x07], 0x0002
	break
	jmp LABEL_97FC
LABEL_996F:
	db 0x11

LABEL_9970:
	je [0x0A], [0x0C], KILL_CHAN_AT_998E
	jg [0x0A], [0x0C], LABEL_998F

LABEL_997C:
	add [0x0A], 0x0001
	break
	jne [0x0A], 0x03, LABEL_9988
	break

LABEL_9988:
	jl [0x0A], [0x0C], LABEL_997C

KILL_CHAN_AT_998E:
	killChannel

LABEL_998F:
	sub [0x0A], 0x0001
	break
	jne [0x0A], 0x02, LABEL_999B
	break

LABEL_999B:
	jg [0x0A], [0x0C], LABEL_998F
	killChannel

LABEL_99A2:
	sub [0x0B], 0x0001
	jg [0x0B], 0x00, LABEL_99D7
	je [HERO_POS_MASK], 0x00, LABEL_99C5
	call SETUP_HASH_AND_DERIVE_BUCKETS
	mov [0x0B], [RANDOM_SEED]
	add [0x0B], 0x0006
	mov [0x0C], 0x0004
	setup channel=0x15, address=LABEL_9970
	ret


LABEL_99C5:
	call SETUP_HASH_AND_DERIVE_BUCKETS
	mov [0x0B], [0x3A]
	add [0x0B], 0x0006
	mov [0x0C], 0x0001
	setup channel=0x15, address=LABEL_9970

LABEL_99D7:
	ret


CAVES_STEP_DRAW_CV336_THEN_CV340_L7:
	video type=0, offset=CV_38D2, x=[HERO_X], y=[HERO_Y], zoom=0x40
	je [0xBE], 0x03, DRAW_CIN_149
	ret


DRAW_CIN_149:
	video offset=CINEMATIC_149, x=[HERO_X], y=[HERO_Y]
	ret


LABEL_99EA:
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


CAVES_STEP_DRAW_CV336_THEN_CV340_L5:
	video type=0, offset=CV_389E, x=[HERO_X], y=[HERO_Y], zoom=0x40
	je [0xBE], 0x03, DRAW_CIN_151
	ret


DRAW_CIN_151:
	video offset=CINEMATIC_151, x=[HERO_X], y=[HERO_Y]
	ret


LABEL_9A26:
	video type=0, offset=CV_36D2, x=[HERO_X], y=[HERO_Y], zoom=0x40
	je [0xBE], 0x03, DRAW_CIN_175
	ret


DRAW_CIN_175:
	video offset=CINEMATIC_175, x=[HERO_X], y=[HERO_Y]
	ret


LABEL_9A38:
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


LABEL_9A62:
	video type=0, offset=CV_3858, x=[HERO_X], y=[HERO_Y], zoom=0x40
	je [0xBE], 0x03, DRAW_CIN_178
	ret


DRAW_CIN_178:
	video offset=CINEMATIC_178, x=[HERO_X], y=[HERO_Y]
	ret


LABEL_9A74:
	jne [0x05], 0x00, LABEL_9A80
	video type=0, offset=HERO_WATER_DEPTH_RIGHT_CASE_00, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_9A80:
	jne [0x05], 0x01, LABEL_9A8C
	video type=0, offset=HERO_WATER_DEPTH_RIGHT_CASE_01, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_9A8C:
	jne [0x05], 0x02, LABEL_9A98
	video type=0, offset=HERO_WATER_DEPTH_RIGHT_CASE_02, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_9A98:
	jne [0x05], 0x03, LABEL_9AA4
	video type=0, offset=HERO_WATER_DEPTH_RIGHT_CASE_03, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_9AA4:
	ret


LABEL_9AA5:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F09, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=HERO_WALK_RIGHT_ARM_F09, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


GUARDED_DRAW_CV_159:
	call LABEL_99A2
	jne [0x0A], 0x01, LABEL_9ADD
	video type=0, offset=HERO_GUN_ARM_RIGHT_CASE_01, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0002
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=HERO_GUN_ARM_RIGHT_CASE_01_CHARGE_BLINK, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_9ADD:
	jne [0x0A], 0x02, LABEL_9B01
	video type=0, offset=HERO_GUN_ARM_RIGHT_CASE_02, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=HERO_GUN_ARM_RIGHT_CASE_02_CHARGE_BLINK, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_9B01:
	jne [0x0A], 0x03, LABEL_9B25
	video type=0, offset=HERO_GUN_ARM_RIGHT_CASE_03, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jg [0x06], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=HERO_GUN_ARM_RIGHT_CASE_03_CHARGE_BLINK, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_9B25:
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


LABEL_9B4F:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F10, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=HERO_WALK_RIGHT_ARM_F10, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_9B60:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F11, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=HERO_WALK_RIGHT_ARM_F11, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_9B71:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F12, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=HERO_WALK_RIGHT_ARM_F12, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_9B82:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F13, x=[HERO_X], y=[HERO_Y], zoom=0x40
	play id=0x0060, freq=0x0B, vol=0x22, channel=0x01
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=HERO_WALK_RIGHT_ARM_F13, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_9B99:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F14, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=HERO_WALK_RIGHT_ARM_F14, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_9BAA:
	call LABEL_9A74
	video type=0, offset=CV_0F90, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=CV_338E, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_9BBE:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F00, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=HERO_WALK_RIGHT_ARM_F00, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_9BCF:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F01, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=HERO_WALK_RIGHT_ARM_F01, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_9BE0:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F02, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=HERO_WALK_RIGHT_ARM_F02, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_9BF1:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F03, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=HERO_WALK_RIGHT_ARM_F03, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_9C02:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F04, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=HERO_WALK_RIGHT_ARM_F04, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_9C13:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F05, x=[HERO_X], y=[HERO_Y], zoom=0x40
	play id=0x0060, freq=0x14, vol=0x22, channel=0x01
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=HERO_WALK_RIGHT_ARM_F05, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_9C2A:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F06, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=HERO_WALK_RIGHT_ARM_F06, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_9C3B:
	call LABEL_9A74
	video type=0, offset=HERO_WALK_RIGHT_BODY_F07, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=HERO_WALK_RIGHT_ARM_F07, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_9C4F:
	video type=0, offset=HERO_WALK_RIGHT_BODY_F08, x=[HERO_X], y=[HERO_Y], zoom=0x40
	jne [0x0A], 0x00, GUARDED_DRAW_CV_159
	video type=0, offset=HERO_WALK_RIGHT_ARM_F08, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_9C60:
	video type=0, offset=CV_3B10, x=[HERO_X], y=[HERO_Y], zoom=0x40
	je [0xBE], 0x03, DRAW_CIN_162
	ret


DRAW_CIN_162:
	video offset=CINEMATIC_162, x=[HERO_X], y=[HERO_Y]
	ret


LABEL_9C72:
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


LABEL_9C9C:
	video type=0, offset=CV_3ADC, x=[HERO_X], y=[HERO_Y], zoom=0x40
	je [0xBE], 0x03, DRAW_CIN_164
	ret


DRAW_CIN_164:
	video offset=CINEMATIC_164, x=[HERO_X], y=[HERO_Y]
	ret


LABEL_9CAE:
	video type=0, offset=CV_391A, x=[HERO_X], y=[HERO_Y], zoom=0x40
	je [0xBE], 0x03, DRAW_CIN_171
	ret


DRAW_CIN_171:
	video offset=CINEMATIC_171, x=[HERO_X], y=[HERO_Y]
	ret


LABEL_9CC0:
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


LABEL_9CEA:
	video type=0, offset=CV_3A96, x=[HERO_X], y=[HERO_Y], zoom=0x40
	je [0xBE], 0x03, DRAW_CIN_173
	ret


DRAW_CIN_173:
	video offset=CINEMATIC_173, x=[HERO_X], y=[HERO_Y]
	ret


GUARDED_DRAW_CV_126:
	call LABEL_99A2
	jne [0x0A], 0x01, LABEL_9D0B
	video type=0, offset=HERO_GUN_ARM_LEFT_CASE_01, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_9D0B:
	jne [0x0A], 0x02, LABEL_9D17
	video type=0, offset=HERO_GUN_ARM_LEFT_CASE_02, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_9D17:
	jne [0x0A], 0x03, LABEL_9D23
	video type=0, offset=HERO_GUN_ARM_LEFT_CASE_03, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_9D23:
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
	jne [0x05], 0x00, LABEL_9D59
	video type=0, offset=HERO_WATER_DEPTH_LEFT_CASE_00, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_9D59:
	jne [0x05], 0x01, LABEL_9D65
	video type=0, offset=HERO_WATER_DEPTH_LEFT_CASE_01, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_9D65:
	jne [0x05], 0x02, LABEL_9D71
	video type=0, offset=HERO_WATER_DEPTH_LEFT_CASE_02, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_9D71:
	jne [0x05], 0x03, LABEL_9D7D
	video type=0, offset=HERO_WATER_DEPTH_LEFT_CASE_03, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret


LABEL_9D7D:
	ret


CAVES_STEP_LEFT4_DRAW_CV140_LEFT4_L32:
	je [0x0A], 0x00, DRAW_CV_074
	call GUARDED_DRAW_CV_126
