DRAW_HERO_POSE_0_1:
	video offset=CINEMATIC_022, x=[0x07], y=[0x08]
	ret


DRAW_HERO_POSE_0_2:
	video offset=CINEMATIC_023, x=[0x07], y=[0x08]
	ret


DRAW_HERO_POSE_0_3:
	video offset=CINEMATIC_024, x=[0x07], y=[0x08]
	ret


DRAW_HERO_POSE_0_4:
	video offset=CINEMATIC_025, x=[0x07], y=[0x08]
	ret


DRAW_HERO_POSE_0_6:
	video offset=CINEMATIC_027, x=[0x07], y=[0x08]
	ret


DRAW_HERO_POSE_1:
	video offset=CINEMATIC_021, x=[0x07], y=[0x08]
	ret


DRAW_HERO_POSE_2:
	video offset=CINEMATIC_020, x=[0x07], y=[0x08]
	ret


DRAW_HERO_POSE_3:
	video offset=CINEMATIC_019, x=[0x07], y=[0x08]
	ret


DRAW_CIN_018:
	video offset=CINEMATIC_018, x=[0x07], y=[0x08]
	ret


DRAW_CIN_017:
	video offset=CINEMATIC_017, x=[0x07], y=[0x08]
	ret


DRAW_HERO_POSE_5:
	video offset=CINEMATIC_016, x=[0x07], y=[0x08]
	ret


DRAW_CIN_015:
	video offset=CINEMATIC_015, x=[0x07], y=[0x08]
	ret


LABEL_8ED7:
	db 0x11

DRAW_HERO_SUBFRAME_3_VAR09:
	mov [0xF8], [0x09]
	and [0xF8], 0x000F
	je [0xF8], 0x01, DRAW_CIN_028
	je [0xF8], 0x02, DRAW_CIN_029
	je [0xF8], 0x03, DRAW_CIN_030
	ret


DRAW_CIN_028:
	video offset=CINEMATIC_028, x=[0x07], y=[0x08]
	ret


DRAW_CIN_029:
	video offset=CINEMATIC_029, x=[0x07], y=[0x08]
	ret


DRAW_CIN_030:
	video offset=CINEMATIC_030, x=[0x07], y=[0x08]
	ret


DRAW_HERO_SUBFRAME_2_VAR09_LOW:
	mov [0xF8], [0x09]
	and [0xF8], 0x000F
	je [0xF8], 0x01, DRAW_CIN_031
	je [0xF8], 0x02, DRAW_CIN_032
	ret


DRAW_CIN_031:
	video offset=CINEMATIC_031, x=[0xf5], y=[0x08]
	ret


DRAW_CIN_032:
	video offset=CINEMATIC_032, x=[0xf5], y=[0x08]
	ret


CAVES_DRAW_CV_355_L10:
	video type=0, offset=CV_1A54, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jg [0xF6], 0x00, DRAW_HERO_SUBFRAME_2_VAR09_LOW
	video type=0, offset=CV_5F74, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_HERO_SUBFRAME_2_VAR09_LOW

LABEL_8F3A:
	video type=0, offset=CV_1A84, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jg [0xF6], 0x00, DRAW_HERO_SUBFRAME_2_VAR09_LOW
	video type=0, offset=CV_5F7C, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_HERO_SUBFRAME_2_VAR09_LOW

LABEL_8F50:
	video type=0, offset=CV_1AB4, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	add [0xF5], 0x0001
	jg [0xF6], 0x00, DRAW_HERO_SUBFRAME_2_VAR09_LOW
	video type=0, offset=CV_5F84, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_HERO_SUBFRAME_2_VAR09_LOW

LABEL_8F6A:
	video type=0, offset=CV_1AE4, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jg [0xF6], 0x00, DRAW_HERO_SUBFRAME_2_VAR09_LOW
	video type=0, offset=CV_5F8C, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_HERO_SUBFRAME_2_VAR09_LOW

LABEL_8F80:
	video type=0, offset=CV_1B14, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	sub [0xF5], 0x0001
	jg [0xF6], 0x00, DRAW_HERO_SUBFRAME_2_VAR09_LOW
	video type=0, offset=CV_5F94, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_HERO_SUBFRAME_2_VAR09_LOW

LABEL_8F9A:
	video type=0, offset=CV_1B44, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	sub [0xF5], 0x0001
	jg [0xF6], 0x00, DRAW_HERO_SUBFRAME_2_VAR09_LOW
	video type=0, offset=CV_5F9C, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_HERO_SUBFRAME_2_VAR09_LOW

LABEL_8FB4:
	video type=0, offset=CV_1B74, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	sub [0xF5], 0x0002
	jg [0xF6], 0x00, DRAW_HERO_SUBFRAME_2_VAR09_LOW
	video type=0, offset=CV_5FA4, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_HERO_SUBFRAME_2_VAR09_LOW

LABEL_8FCE:
	video type=0, offset=CV_1BA4, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	sub [0xF5], 0x0002
	jg [0xF6], 0x00, DRAW_HERO_SUBFRAME_2_VAR09_LOW
	video type=0, offset=CV_5FAC, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_HERO_SUBFRAME_2_VAR09_LOW

LABEL_8FE8:
	video type=0, offset=CV_1BD4, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	sub [0xF5], 0x0002
	jg [0xF6], 0x00, DRAW_HERO_SUBFRAME_2_VAR09_LOW
	video type=0, offset=CV_5FB4, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_HERO_SUBFRAME_2_VAR09_LOW

CAVES_ACTOR_WALK_RIGHT_DRAW_PHASE_1:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_247C, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=CV_FIGURE_WALK_RIGHT_BODY_F00, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_HERO_SUBFRAME_3_VAR09
	je [0x0D], 0x00, LABEL_9024
	call LABEL_8BD5
	jmp LABEL_9027

LABEL_9024:
	call LABEL_8F3A

LABEL_9027:
	ret


LABEL_9028:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	sub [0x07], 0x0001
	video type=0, offset=CV_247C, x=[0x07], y=[0x08], zoom=0x40
	add [0x07], 0x0001
	video type=0, offset=CV_FIGURE_WALK_RIGHT_BODY_F01, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_HERO_SUBFRAME_3_VAR09
	je [0x0D], 0x00, LABEL_9052
	call LABEL_8BD5
	jmp LABEL_9055

LABEL_9052:
	call LABEL_8F3A

LABEL_9055:
	ret


LABEL_9056:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_FIGURE_WALK_RIGHT_BODY_F02, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_HERO_SUBFRAME_3_VAR09
	je [0x0D], 0x00, LABEL_9073
	call CAVES_DRAW_CV246_AT_X07_Y08_L2
	jmp CAVES_ACTOR_WALK_RIGHT_DRAW_PHASE_3_RET

LABEL_9073:
	call LABEL_8F50

CAVES_ACTOR_WALK_RIGHT_DRAW_PHASE_3_RET:
	ret


LABEL_9077:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	play id=0x0055, freq=0x0F, vol=0x14, channel=0x00
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_FIGURE_WALK_RIGHT_BODY_F03, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_HERO_SUBFRAME_3_VAR09
	je [0x0D], 0x00, LABEL_909A
	call CAVES_DRAW_CV246_AT_X07_Y08_L2
	jmp LABEL_909D

LABEL_909A:
	call LABEL_8F6A

LABEL_909D:
	ret


CAVES_ACTOR_WALK_RIGHT_DRAW_PHASE_5:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_FIGURE_WALK_RIGHT_BODY_F04, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_HERO_SUBFRAME_3_VAR09
	je [0x0D], 0x00, LABEL_90BB
	call CAVES_DRAW_CV246_AT_X07_Y08_L2
	jmp LABEL_90BE

LABEL_90BB:
	call LABEL_8F80

LABEL_90BE:
	ret


CAVES_ACTOR_WALK_RIGHT_DRAW_PHASE_6:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_2474, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=CV_FIGURE_WALK_RIGHT_BODY_F05, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_HERO_SUBFRAME_3_VAR09
	je [0x0D], 0x00, LABEL_90E1
	call CAVES_INLINE_DRAW_CV_255_031_L2
	jmp CAVES_ACTOR_WALK_RIGHT_DRAW_PHASE_6_RET

LABEL_90E1:
	call LABEL_8F9A

CAVES_ACTOR_WALK_RIGHT_DRAW_PHASE_6_RET:
	ret


CAVES_ACTOR_WALK_RIGHT_DRAW_PHASE_7:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_246C, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=CV_FIGURE_WALK_RIGHT_BODY_F06, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_HERO_SUBFRAME_3_VAR09
	je [0x0D], 0x00, LABEL_9107
	call LABEL_8C10
	jmp CAVES_ACTOR_WALK_RIGHT_DRAW_PHASE_7_RET

LABEL_9107:
	call LABEL_8FB4

CAVES_ACTOR_WALK_RIGHT_DRAW_PHASE_7_RET:
	ret


CAVES_ACTOR_WALK_RIGHT_DRAW_PHASE_8:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_245C, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=CV_FIGURE_WALK_RIGHT_BODY_F07, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_HERO_SUBFRAME_3_VAR09
	je [0x0D], 0x00, LABEL_912D
	call CAVES_DRAW_CV_355_L9
	jmp CAVES_ACTOR_WALK_RIGHT_DRAW_PHASE_8_RET

LABEL_912D:
	call LABEL_8FCE

CAVES_ACTOR_WALK_RIGHT_DRAW_PHASE_8_RET:
	ret


CAVES_ACTOR_WALK_RIGHT_DRAW_PHASE_9:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_2464, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=CV_FIGURE_WALK_RIGHT_BODY_F08, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_HERO_SUBFRAME_3_VAR09
	je [0x0D], 0x00, LABEL_9153
	call LABEL_8C56
	jmp CAVES_ACTOR_WALK_RIGHT_DRAW_PHASE_9_RET

LABEL_9153:
	call LABEL_8FE8

CAVES_ACTOR_WALK_RIGHT_DRAW_PHASE_9_RET:
	ret


CAVES_ACTOR_WALK_RIGHT_DRAW_PHASE_10:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_2464, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=CV_FIGURE_WALK_RIGHT_BODY_F09, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_HERO_SUBFRAME_3_VAR09
	je [0x0D], 0x00, LABEL_9179
	call LABEL_8C56
	jmp CAVES_ACTOR_WALK_RIGHT_DRAW_PHASE_10_RET

LABEL_9179:
	sub [0x07], 0x0001
	call LABEL_8FE8
	add [0x07], 0x0001

CAVES_ACTOR_WALK_RIGHT_DRAW_PHASE_10_RET:
	ret


CAVES_ACTOR_WALK_RIGHT_DRAW_PHASE_11:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_246C, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=CV_FIGURE_WALK_RIGHT_BODY_F10, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_HERO_SUBFRAME_3_VAR09
	je [0x0D], 0x00, LABEL_91A7
	call CAVES_DRAW_CV_355_L9
	jmp CAVES_ACTOR_WALK_RIGHT_DRAW_PHASE_11_RET

LABEL_91A7:
	call LABEL_8FB4

CAVES_ACTOR_WALK_RIGHT_DRAW_PHASE_11_RET:
	ret


LABEL_91AB:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	play id=0x0055, freq=0x14, vol=0x14, channel=0x00
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_2474, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=CV_FIGURE_WALK_RIGHT_BODY_F11, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_HERO_SUBFRAME_3_VAR09
	je [0x0D], 0x00, LABEL_91D3
	call CAVES_DRAW_CV_355_L9
	jmp LABEL_91D6

LABEL_91D3:
	call LABEL_8F9A

LABEL_91D6:
	ret


CAVES_ACTOR_WALK_RIGHT_DRAW_PHASE_13:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_FIGURE_WALK_RIGHT_BODY_F12, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_HERO_SUBFRAME_3_VAR09
	je [0x0D], 0x00, LABEL_91F4
	call CAVES_DRAW_CV_355_L9
	jmp CAVES_ACTOR_WALK_RIGHT_DRAW_PHASE_13_RET

LABEL_91F4:
	call LABEL_8F80

CAVES_ACTOR_WALK_RIGHT_DRAW_PHASE_13_RET:
	ret


CAVES_ACTOR_WALK_RIGHT_DRAW_PHASE_14:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_FIGURE_WALK_RIGHT_BODY_F13, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_HERO_SUBFRAME_3_VAR09
	je [0x0D], 0x00, LABEL_9215
	call LABEL_8C10
	jmp CAVES_ACTOR_WALK_RIGHT_DRAW_PHASE_14_RET

LABEL_9215:
	call LABEL_8F6A

CAVES_ACTOR_WALK_RIGHT_DRAW_PHASE_14_RET:
	ret


CAVES_ACTOR_WALK_RIGHT_DRAW_PHASE_15:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_FIGURE_WALK_RIGHT_BODY_F14, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_HERO_SUBFRAME_3_VAR09
	je [0x0D], 0x00, LABEL_9236
	call CAVES_INLINE_DRAW_CV_255_031_L2
	jmp CAVES_ACTOR_WALK_RIGHT_DRAW_PHASE_15_RET

LABEL_9236:
	call LABEL_8F50

CAVES_ACTOR_WALK_RIGHT_DRAW_PHASE_15_RET:
	ret


LABEL_923A:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_FIGURE_WALK_RIGHT_BODY_F15, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_HERO_SUBFRAME_3_VAR09
	je [0x0D], 0x00, LABEL_9257
	call CAVES_DRAW_CV246_AT_X07_Y08_L2
	jmp CAVES_ACTOR_WALK_RIGHT_DRAW_PHASE_16_RET

LABEL_9257:
	call CAVES_DRAW_CV_355_L10

CAVES_ACTOR_WALK_RIGHT_DRAW_PHASE_16_RET:
	ret


CAVES_ACTOR_WALK_RIGHT_DRAW_PHASE_3:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_FIGURE_PROFILE_STANCE, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_HERO_SUBFRAME_3_VAR09
	je [0x0D], 0x00, LABEL_9278
	call CAVES_DRAW_CV246_AT_X07_Y08_L2
	jmp CAVES_HERO_PER_FRAME_TICK_RET

LABEL_9278:
	call LABEL_8F80

CAVES_HERO_PER_FRAME_TICK_RET:
	ret


CAVES_ACTOR_TURN_TO_FACE_RIGHT_DRAW_PHASE_3:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_FIGURE_PROFILE_STANCE, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_HERO_SUBFRAME_3_VAR09
	je [0x0D], 0x00, LABEL_9299
	call CAVES_INLINE_DRAW_CV_255_031_L2
	jmp CAVES_ACTOR_TURN_TO_FACE_RIGHT_DRAW_PHASE_3_RET

LABEL_9299:
	call LABEL_8F9A

CAVES_ACTOR_TURN_TO_FACE_RIGHT_DRAW_PHASE_3_RET:
	ret


CAVES_ACTOR_TURN_TO_FACE_LEFT_DRAW_PHASE_1:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_FIGURE_PROFILE_STANCE, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_HERO_SUBFRAME_3_VAR09
	je [0x0D], 0x00, LABEL_92BA
	call LABEL_8C10
	jmp CAVES_ACTOR_TURN_TO_FACE_LEFT_DRAW_PHASE_1_RET

LABEL_92BA:
	call LABEL_8FB4

CAVES_ACTOR_TURN_TO_FACE_LEFT_DRAW_PHASE_1_RET:
	ret


LABEL_92BE:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	video offset=CINEMATIC_139, x=[0x07], y=[0x08]
	ret


LABEL_92CA:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	video offset=CINEMATIC_140, x=[0x07], y=[0x08]
	ret


LABEL_92D6:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	call LABEL_8B7B
	call DRAW_BEAST_Y_PLUS_D
	video type=0, offset=CV_FIGURE_CROUCH_FACING_RIGHT, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_835D
	sub [0x08], 0x000D
	ret


LABEL_92F3:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	add [0x07], 0x0001
	sub [0x08], 0x0001
	call LABEL_8B99
	add [0x08], 0x0001
	call DRAW_BEAST_Y_PLUS_D
	video type=0, offset=CV_42BA, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call CAVES_DRAW_CV204_AT_X07_Y08_L1
	sub [0x08], 0x000D
	sub [0x07], 0x0001
	ret


LABEL_9320:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	call LABEL_8BB7
	call DRAW_BEAST_Y_PLUS_D
	video type=0, offset=CV_FIGURE_CROUCH_FACING_RIGHT, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_835D
	sub [0x08], 0x000D
	ret


LABEL_933D:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	call LABEL_8B99
	call DRAW_BEAST_Y_PLUS_D
	video type=0, offset=CV_FIGURE_CROUCH_FACING_RIGHT, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_835D
	sub [0x08], 0x000D
	ret


LABEL_935A:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	je [0x0D], 0x00, LABEL_9371
	add [0x08], 0x000D
	call DRAW_CV_304_THEN_305
	sub [0x08], 0x000D

LABEL_9371:
	call DRAW_BEAST_Y_PLUS_D
	video type=0, offset=CV_FIGURE_CROUCH_FACING_RIGHT, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call CAVES_DRAW_CV204_AT_X07_Y08_L1
	sub [0x08], 0x000D
	ret


LABEL_9385:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	video offset=CINEMATIC_060, x=[0x07], y=[0x08]
	call LABEL_935A
	ret


LABEL_9394:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	add [0x07], 0x0001
	sub [0x08], 0x0001
	video type=0, offset=CV_4314, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x0001
	call DRAW_BEAST_Y_PLUS_D
	video type=0, offset=CV_42BA, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call CAVES_DRAW_CV204_AT_X07_Y08_L1
	sub [0x08], 0x000D
	sub [0x07], 0x0001
	ret


LABEL_93C3:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	video type=0, offset=CV_4314, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_BEAST_Y_PLUS_D
	video type=0, offset=CV_FIGURE_CROUCH_FACING_RIGHT, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call LABEL_835D
	sub [0x08], 0x000D
	ret


LABEL_93E2:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	add [0x08], 0x000D
	add [0x07], 0x0004
	video type=0, offset=CV_3212, x=[0x07], y=[0x08], zoom=0x40
	sub [0x07], 0x0004
	sub [0x08], 0x000D
	call DRAW_BEAST_Y_PLUS_D
	video type=0, offset=CV_FIGURE_CROUCH_FACING_RIGHT, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call DRAW_BEAST_HEAD_CV165_166
	sub [0x08], 0x000D
	ret


LABEL_9411:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	call DRAW_BEAST_Y_PLUS_D
	video type=0, offset=CV_FIGURE_CROUCH_FACING_RIGHT, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call DRAW_BEAST_HEAD_CV165_166
	sub [0x08], 0x000D
	ret


LABEL_942B:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	add [0x08], 0x000D
	video offset=CINEMATIC_075, x=[0x07], y=[0x08]
	sub [0x08], 0x000D
	call DRAW_BEAST_Y_PLUS_D
	video type=0, offset=CV_FIGURE_CROUCH_FACING_RIGHT, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call DRAW_BEAST_HEAD_CV165_166
	sub [0x08], 0x000D
	ret


LABEL_9452:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	add [0x07], 0x0001
	add [0x08], 0x000D
	video offset=CINEMATIC_074, x=[0x07], y=[0x08]
	sub [0x08], 0x000D
	call DRAW_BEAST_Y_PLUS_D
	video type=0, offset=CV_42BA, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x000D
	call CAVES_DRAW_CV204_AT_X07_Y08_L1
	sub [0x08], 0x000D
	sub [0x07], 0x0001
	ret


LABEL_9481:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	sub [0x78], 0x000A
	add [0x79], 0x0005
	video type=0, offset=CV_4314, x=[0x78], y=[0x79], zoom=0x40
	sub [0x79], 0x0005
	add [0x78], 0x000A
	video offset=CINEMATIC_184, x=[0x78], y=[0x79]
	ret


LABEL_94A2:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	sub [0x08], 0x000D
	call LABEL_8B7B
	add [0x08], 0x000D
	call DRAW_BEAST_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_FIGURE_PROFILE_STRIDE, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_BEAST_HEAD_CV214_215
	ret


LABEL_94BF:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	add [0x07], 0x0001
	sub [0x08], 0x000E
	call LABEL_8B99
	add [0x08], 0x000E
	call DRAW_BEAST_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_426C, x=[0x07], y=[0x08], zoom=0x40
	add [0x07], 0x0001
	call DRAW_BEAST_HEAD_CV214_215
	sub [0x07], 0x0002
	ret


	jne [SCREEN_NUM], [0x10], SHARED_RET
	sub [0x08], 0x000D
	call LABEL_8BB7
	add [0x08], 0x000D
	call DRAW_BEAST_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_FIGURE_PROFILE_STRIDE, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_BEAST_HEAD_CV214_215
	ret


LABEL_9505:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	sub [0x08], 0x000D
	call LABEL_8B99
	add [0x08], 0x000D
	call DRAW_BEAST_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_FIGURE_PROFILE_STRIDE, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_BEAST_HEAD_CV214_215
	ret


	jne [SCREEN_NUM], [0x10], SHARED_RET
	call DRAW_BEAST_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_FIGURE_PROFILE_STRIDE, x=[0x07], y=[0x08], zoom=0x40
	ret


JUNK__9531:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	call DRAW_CV_355
	video type=0, offset=CV_40BE, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=CV_FIGURE_FRONT_STANCE_NARROW, x=[0x07], y=[0x08], zoom=0x40
	ret


LABEL_9545:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	video offset=CINEMATIC_059, x=[0x07], y=[0x08]
	ret


	jne [SCREEN_NUM], [0x10], SHARED_RET
	call DRAW_CV_355
	video type=0, offset=CV_FIGURE_FRONT_STANCE_NARROW, x=[0x07], y=[0x08], zoom=0x40
	ret


	jne [SCREEN_NUM], [0x10], SHARED_RET
	video type=0, offset=CV_3FA8, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=CV_FIGURE_FRONT_STANCE_WIDE, x=[0x07], y=[0x08], zoom=0x40
	call JUNK__958C
	ret


DRAW_HERO_Y_PLUS_E:
	add [0x08], 0x000E
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	sub [0x08], 0x000E
	ret


DRAW_BEAST_Y_PLUS_D:
	add [0x08], 0x000D
	call DRAW_BEAST_SPRITE_BY_VAR09_0E
	sub [0x08], 0x000D
	ret


JUNK__958C:
	video offset=CINEMATIC_891, x=[0x07], y=[0x08]
	ret
