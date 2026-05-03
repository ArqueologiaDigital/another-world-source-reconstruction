BEETLE_ANIM_LIFT_AND_FLY:
	video type=1, offset=CINEMATIC_BEETLE_LIFT_FRAME_0, x=[0x0a], y=[0x0b], zoom=0x40
	break
	video type=1, offset=CINEMATIC_BEETLE_LIFT_FRAME_1, x=[0x0a], y=[0x0b], zoom=0x40
	break
	sub [0x0A], 0x000F
	sub [0x0B], 0x0001
	video type=1, offset=CINEMATIC_BEETLE_LIFT_FRAME_3, x=[0x0a], y=[0x0b], zoom=0x40
	break
	video type=1, offset=CINEMATIC_BEETLE_LIFT_FRAME_4, x=[0x0a], y=[0x0b], zoom=0x40
	break
	video type=1, offset=CINEMATIC_BEETLE_LIFT_FRAME_2, x=[0x0a], y=[0x0b], zoom=0x40
	break
	mov [0x09], 0x000A

BEETLE_ANIM_FLYING_LOOP:
	video type=1, offset=CINEMATIC_BEETLE_FLYING_FRAME_0, x=[0x0a], y=[0x0b], zoom=0x40
	break
	video type=1, offset=CINEMATIC_BEETLE_FLYING_FRAME_1, x=[0x0a], y=[0x0b], zoom=0x40
	break
	video type=1, offset=CINEMATIC_BEETLE_FLYING_FRAME_2, x=[0x0a], y=[0x0b], zoom=0x40
	break
	video type=1, offset=CINEMATIC_BEETLE_FLYING_FRAME_3, x=[0x0a], y=[0x0b], zoom=0x40
	break
	video type=1, offset=CINEMATIC_BEETLE_LIFT_FRAME_4, x=[0x0a], y=[0x0b], zoom=0x40
	break
	djnz [0x09], BEETLE_ANIM_FLYING_LOOP
	video type=1, offset=CINEMATIC_BEETLE_FLYING_FRAME_4, x=[0x0a], y=[0x0b], zoom=0x40
	break
	video type=1, offset=CINEMATIC_BEETLE_FLYING_FRAME_5, x=[0x0a], y=[0x0b], zoom=0x40
	break
	video type=1, offset=CINEMATIC_BEETLE_FLYING_FRAME_6, x=[0x0a], y=[0x0b], zoom=0x40
	setup channel=0x2E, address=BEETLE_ANIM_FLY_AWAY_INIT_COUNTER
	break

BEETLE_ANIM_HOVER_INFINITE:
	video type=1, offset=CINEMATIC_BEETLE_HOVER_FRAME_0, x=[0x0a], y=[0x0b], zoom=0x40
	break
	video type=1, offset=CINEMATIC_BEETLE_HOVER_FRAME_1, x=[0x0a], y=[0x0b], zoom=0x40
	break
	jmp BEETLE_ANIM_HOVER_INFINITE

BEETLE_ANIM_HOVER_BOBBING_LOOP:
	video type=1, offset=CINEMATIC_BEETLE_HOVER_FRAME_0, x=[0x0a], y=[0x0b], zoom=0x40
	break
	sub [0x0B], 0x0001
	video type=1, offset=CINEMATIC_BEETLE_HOVER_FRAME_1, x=[0x0a], y=[0x0b], zoom=0x40
	break
	sub [0x0B], 0x0001
	video type=1, offset=CINEMATIC_BEETLE_HOVER_FRAME_0, x=[0x0a], y=[0x0b], zoom=0x40
	break
	video type=1, offset=CINEMATIC_BEETLE_HOVER_FRAME_1, x=[0x0a], y=[0x0b], zoom=0x40
	break
	add [0x0B], 0x0001
	video type=1, offset=CINEMATIC_BEETLE_HOVER_FRAME_0, x=[0x0a], y=[0x0b], zoom=0x40
	break
	add [0x0B], 0x0001
	video type=1, offset=CINEMATIC_BEETLE_HOVER_FRAME_1, x=[0x0a], y=[0x0b], zoom=0x40
	jmp BEETLE_ANIM_HOVER_BOBBING_LOOP
	killChannel

BEETLE_ANIM_DRIFT_RIGHT:
	video type=1, offset=CINEMATIC_BEETLE_DRIFT_RIGHT_FRAME_0, x=[0x0a], y=[0x0b], zoom=0x40
	break
	video type=1, offset=CINEMATIC_BEETLE_DRIFT_RIGHT_FRAME_1, x=[0x0a], y=[0x0b], zoom=0x40
	add [0x0A], 0x000F
	sub [0x0B], 0x0001
	break
	video type=1, offset=CINEMATIC_BEETLE_DRIFT_RIGHT_FRAME_2, x=[0x0a], y=[0x0b], zoom=0x40
	break
	video type=1, offset=CINEMATIC_BEETLE_DRIFT_RIGHT_FRAME_3, x=[0x0a], y=[0x0b], zoom=0x40
	break
	video type=1, offset=CINEMATIC_BEETLE_DRIFT_RIGHT_FRAME_4, x=[0x0a], y=[0x0b], zoom=0x40
	break
	mov [0x09], 0x000A

BEETLE_ANIM_FLY_AWAY_LOOP:
	video type=1, offset=CINEMATIC_BEETLE_FLY_AWAY_FRAME_0, x=[0x0a], y=[0x0b], zoom=0x40
	break
	video type=1, offset=CINEMATIC_BEETLE_FLY_AWAY_FRAME_1, x=[0x0a], y=[0x0b], zoom=0x40
	break
	video type=1, offset=CINEMATIC_BEETLE_FLY_AWAY_FRAME_2, x=[0x0a], y=[0x0b], zoom=0x40
	break
	video type=1, offset=CINEMATIC_BEETLE_FLY_AWAY_FRAME_3, x=[0x0a], y=[0x0b], zoom=0x40
	break
	video type=1, offset=CINEMATIC_BEETLE_DRIFT_RIGHT_FRAME_3, x=[0x0a], y=[0x0b], zoom=0x40
	break
	djnz [0x09], BEETLE_ANIM_FLY_AWAY_LOOP
	video type=1, offset=CINEMATIC_BEETLE_FLY_AWAY_END_FRAME_0, x=[0x0a], y=[0x0b], zoom=0x40
	break
	video type=1, offset=CINEMATIC_BEETLE_FLY_AWAY_END_FRAME_1, x=[0x0a], y=[0x0b], zoom=0x40
	break
	video type=1, offset=CINEMATIC_BEETLE_FLY_AWAY_END_FRAME_2, x=[0x0a], y=[0x0b], zoom=0x40
	setup channel=0x2E, address=BEETLE_ANIM_FLY_AWAY_INIT_COUNTER
	break

BEETLE_ANIM_HOVER_VERT_INFINITE:
	video type=1, offset=CINEMATIC_BEETLE_HOVER_VERT_FRAME_0, x=[0x0a], y=[0x0b], zoom=0x40
	break
	video type=1, offset=CINEMATIC_BEETLE_HOVER_VERT_FRAME_1, x=[0x0a], y=[0x0b], zoom=0x40
	break
	jmp BEETLE_ANIM_HOVER_VERT_INFINITE

BEETLE_ANIM_HOVER_VERTICAL_LOOP:
	video type=1, offset=CINEMATIC_BEETLE_HOVER_VERT_FRAME_0, x=[0x0a], y=[0x0b], zoom=0x40
	break
	sub [0x0B], 0x0001
	video type=1, offset=CINEMATIC_BEETLE_HOVER_VERT_FRAME_1, x=[0x0a], y=[0x0b], zoom=0x40
	break
	sub [0x0B], 0x0001
	video type=1, offset=CINEMATIC_BEETLE_HOVER_VERT_FRAME_0, x=[0x0a], y=[0x0b], zoom=0x40
	break
	video type=1, offset=CINEMATIC_BEETLE_HOVER_VERT_FRAME_1, x=[0x0a], y=[0x0b], zoom=0x40
	break
	add [0x0B], 0x0001
	video type=1, offset=CINEMATIC_BEETLE_HOVER_VERT_FRAME_0, x=[0x0a], y=[0x0b], zoom=0x40
	break
	add [0x0B], 0x0001
	video type=1, offset=CINEMATIC_BEETLE_HOVER_VERT_FRAME_1, x=[0x0a], y=[0x0b], zoom=0x40
	jmp BEETLE_ANIM_HOVER_VERTICAL_LOOP
	killChannel

BEETLE_ANIM_FLY_AWAY_INIT_COUNTER:
	mov [0x09], 0x000A

BEETLE_ANIM_FLY_AWAY_WAIT_LOOP:
	break
	djnz [0x09], BEETLE_ANIM_FLY_AWAY_WAIT_LOOP
	mov [0x09], 0x0008
	setup channel=0x09, address=BEETLE_ANIM_HOVER_VERTICAL_LOOP

BEETLE_ANIM_FLY_DIAGONAL_UP_RIGHT_LOOP:
	sub [0x0B], 0x0002
	add [0x0A], 0x0001
	break
	djnz [0x09], BEETLE_ANIM_FLY_DIAGONAL_UP_RIGHT_LOOP

BEETLE_ANIM_FLY_AWAY_DIAGONAL_FAST_LOOP:
	sub [0x0B], 0x0002
	add [0x0A], 0x000C
	break
	jl [0x0A], 0x0168, BEETLE_ANIM_FLY_AWAY_DIAGONAL_FAST_LOOP
	mov [0x0B], 0x0092
	jmp BEETLE_AI_HOVER_RANDOM_DURATION
	killChannel

BEETLE_AI_DISPATCH_BY_HERO_X:
	jl [0x0A], [0x01], BEETLE_AI_GO_RIGHT_BOUNDED
	setup channel=0x09, address=BEETLE_ANIM_HOVER_BOBBING_LOOP
	jmp BEETLE_AI_GO_LEFT_BOUNDED

BEETLE_AI_GO_RIGHT_BOUNDED:
	mov [0x08], [0x01]
	sub [0x08], 0x0014
	jg [0x0A], [0x08], YIELD_THEN_JUMP_TO_3711
	sub [0x08], 0x000A
	jl [0x0A], [0x08], BEETLE_AI_DEC_LEFT_NEAR
	add [0x0A], 0x0001
	jmp YIELD_THEN_JUMP_TO_3711

BEETLE_AI_DEC_LEFT_NEAR:
	sub [0x08], 0x000F
	jl [0x0A], [0x08], BEETLE_AI_DEC_LEFT_MID
	add [0x0A], 0x0002
	jmp YIELD_THEN_JUMP_TO_3711

BEETLE_AI_DEC_LEFT_MID:
	sub [0x08], 0x001E
	jl [0x0A], [0x08], BEETLE_AI_DEC_LEFT_FAR
	add [0x0A], 0x0007
	jmp YIELD_THEN_JUMP_TO_3711

BEETLE_AI_DEC_LEFT_FAR:
	add [0x0A], 0x000C

YIELD_THEN_JUMP_TO_3711:
	break
	jmp BEETLE_AI_DISPATCH_BY_HERO_X
	killChannel

JMP_TO_BEETLE_GO_RIGHT:
	jg [0x0A], [0x01], BEETLE_AI_GO_LEFT_BOUNDED
	setup channel=0x09, address=BEETLE_ANIM_HOVER_VERTICAL_LOOP
	jmp BEETLE_AI_GO_RIGHT_BOUNDED

BEETLE_AI_GO_LEFT_BOUNDED:
	mov [0x08], [0x01]
	add [0x08], 0x0014
	jl [0x0A], [0x08], YIELD_THEN_JUMP_TO_3767
	add [0x08], 0x000A
	jg [0x0A], [0x08], BEETLE_AI_DEC_RIGHT_NEAR
	sub [0x0A], 0x0001
	jmp YIELD_THEN_JUMP_TO_3767

BEETLE_AI_DEC_RIGHT_NEAR:
	add [0x08], 0x000F
	jg [0x0A], [0x08], BEETLE_AI_DEC_RIGHT_MID
	sub [0x0A], 0x0002
	jmp YIELD_THEN_JUMP_TO_3767

BEETLE_AI_DEC_RIGHT_MID:
	add [0x08], 0x001E
	jg [0x0A], [0x08], BEETLE_AI_DEC_RIGHT_FAR
	sub [0x0A], 0x0007
	jmp YIELD_THEN_JUMP_TO_3767

BEETLE_AI_DEC_RIGHT_FAR:
	sub [0x0A], 0x000C

YIELD_THEN_JUMP_TO_3767:
	break
	jmp JMP_TO_BEETLE_GO_RIGHT
	killChannel

BEETLE_AI_HOVER_RANDOM_DURATION:
	mov [0x0B], 0x0096
	setup channel=0x09, address=BEETLE_ANIM_HOVER_BOBBING_LOOP
	call COMPUTE_RANDOM_BIT_MASKS
	mov [0x09], [0x3F]
	sub [0x09], 0x012C

BEETLE_AI_DESCEND_NEAR_HERO:
	mov [0x08], [0x01]
	add [0x08], 0x000A
	jg [0x0A], [0x08], BEETLE_DECIDE_DESCEND
	sub [0x0B], 0x0002
	je [0x63], 0x64, BEETLE_DECIDE_DESCEND
	sub [0x08], 0x000A
	jl [0x0A], [0x08], BEETLE_DECIDE_DESCEND
	jmp BEAST_SURPRISE_SCENE_INIT

BEETLE_DECIDE_DESCEND:
	jg [0x0A], [0x09], JMP_TO_BEETLE_DESCEND
	jmp BEETLE_AI_HOVER_INIT

JMP_TO_BEETLE_DESCEND:
	sub [0x0A], 0x000C
	break
	jmp BEETLE_AI_DESCEND_NEAR_HERO

BEETLE_AI_HOVER_INIT:
	mov [0x0B], 0x0096
	setup channel=0x09, address=BEETLE_ANIM_HOVER_VERTICAL_LOOP
	call COMPUTE_RANDOM_BIT_MASKS
	mov [0x09], [0x3F]
	add [0x09], 0x015E

BEETLE_AI_HOVER_LOOP_BODY:
	mov [0x08], [0x01]
	sub [0x08], 0x000A
	jl [0x0A], [0x08], JMP_TO_BEETLE_HOVER_RANDOM
	sub [0x0B], 0x0002
	je [0x63], 0x64, JMP_TO_BEETLE_HOVER_RANDOM
	add [0x08], 0x000A
	jg [0x0A], [0x08], JMP_TO_BEETLE_HOVER_RANDOM
	jmp BEAST_SURPRISE_SCENE_INIT

JMP_TO_BEETLE_HOVER_RANDOM:
	jl [0x0A], [0x09], BEETLE_AI_HOVER_RIGHT_DRIFT
	jmp BEETLE_AI_HOVER_RANDOM_DURATION

BEETLE_AI_HOVER_RIGHT_DRIFT:
	add [0x0A], 0x000C
	break
	jmp BEETLE_AI_HOVER_LOOP_BODY
	killChannel
	killChannel

