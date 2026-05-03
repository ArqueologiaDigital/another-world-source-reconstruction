BEETLE_WALKING_RIGHT:
	video type=1, offset=CINEMATIC_BEETLE_WALKING_RIGHT_0, x=[0x0a], y=[0x0b], zoom=0x40
	break
	video type=1, offset=CINEMATIC_BEETLE_WALKING_RIGHT_0, x=[0x0a], y=[0x0b], zoom=0x40
	add [0x0A], 0x0001
	break
	video type=1, offset=CINEMATIC_BEETLE_WALKING_RIGHT_1, x=[0x0a], y=[0x0b], zoom=0x40
	break
	video type=1, offset=CINEMATIC_BEETLE_WALKING_RIGHT_1, x=[0x0a], y=[0x0b], zoom=0x40
	add [0x0A], 0x0001
	break
	video type=1, offset=CINEMATIC_BEETLE_WALKING_RIGHT_2, x=[0x0a], y=[0x0b], zoom=0x40
	break
	video type=1, offset=CINEMATIC_BEETLE_WALKING_RIGHT_2, x=[0x0a], y=[0x0b], zoom=0x40
	add [0x0A], 0x0001
	break
	video type=1, offset=CINEMATIC_BEETLE_WALKING_RIGHT_3, x=[0x0a], y=[0x0b], zoom=0x40
	break
	video type=1, offset=CINEMATIC_BEETLE_WALKING_RIGHT_3, x=[0x0a], y=[0x0b], zoom=0x40
	add [0x0A], 0x0001
	break
	video type=1, offset=CINEMATIC_BEETLE_WALKING_RIGHT_4, x=[0x0a], y=[0x0b], zoom=0x40
	break
	video type=1, offset=CINEMATIC_BEETLE_WALKING_RIGHT_4, x=[0x0a], y=[0x0b], zoom=0x40
	add [0x0A], 0x0001
	break
	video type=1, offset=CINEMATIC_BEETLE_WALKING_RIGHT_5, x=[0x0a], y=[0x0b], zoom=0x40
	break
	video type=1, offset=CINEMATIC_BEETLE_WALKING_RIGHT_5, x=[0x0a], y=[0x0b], zoom=0x40
	add [0x0A], 0x0001
	break
	video type=1, offset=CINEMATIC_BEETLE_WALKING_RIGHT_6, x=[0x0a], y=[0x0b], zoom=0x40
	break
	video type=1, offset=CINEMATIC_BEETLE_WALKING_RIGHT_6, x=[0x0a], y=[0x0b], zoom=0x40
	add [0x0A], 0x0001
	break
	jmp BEETLE_WALKING_RIGHT
	killChannel

WAIT_FOR_BEETLE_OFFSCREEN_THEN_KILL:
	break
	jne [HACK_VAR_67], 0x01, WAIT_FOR_BEETLE_OFFSCREEN_THEN_KILL
	jg [0x0A], 0x014A, WAIT_FOR_BEETLE_OFFSCREEN_THEN_KILL
	setup channel=0x09, address=KILL_CHANNEL_ROUTINE
	killChannel

BEETLE_KICK_DETECTOR:
	break
	je [0x06], 0x00, MAYBE_RESTART_BEETLE_WALKING_RIGHT
	jg [0x06], 0x02, MAYBE_RESTART_BEETLE_WALKING_RIGHT
	jl [0x01], [0x04], BEETLE_KICK_DETECTOR_FROM_LEFT
	mov [0x08], [0x04]
	sub [0x08], 0x0004
	jl [0x0A], [0x08], MAYBE_RESTART_BEETLE_WALKING_RIGHT
	add [0x08], 0x0008
	jg [0x0A], [0x08], MAYBE_RESTART_BEETLE_WALKING_RIGHT
	setup channel=0x09, address=BEETLE_ANIM_LIFT_AND_FLY
	killChannel

BEETLE_KICK_DETECTOR_FROM_LEFT:
	mov [0x08], [0x04]
	add [0x08], 0x0004
	jg [0x0A], [0x08], MAYBE_RESTART_BEETLE_WALKING_RIGHT
	sub [0x08], 0x0008
	jl [0x0A], [0x08], MAYBE_RESTART_BEETLE_WALKING_RIGHT
	setup channel=0x09, address=BEETLE_ANIM_DRIFT_RIGHT
	killChannel

MAYBE_RESTART_BEETLE_WALKING_RIGHT:
	break
	jg [0x0A], 0xFFF6, MAYBE_RESTART_BEETLE_WALKING_LEFT
	setup channel=0x09, address=BEETLE_WALKING_RIGHT

MAYBE_RESTART_BEETLE_WALKING_LEFT:
	jl [0x0A], 0x014A, RESTART_BEETLE_KICK_DETECTOR
	setup channel=0x09, address=BEETLE_WALKING_LEFT

RESTART_BEETLE_KICK_DETECTOR:
	jmp BEETLE_KICK_DETECTOR
	killChannel

BEETLE_INIT_POS_THEN_WALK_LEFT:
	mov [0x0A], 0x0258
	mov [0x0B], 0x00B6

BEETLE_WALKING_LEFT:
	video type=1, offset=CINEMATIC_BEETLE_WALKING_LEFT_0, x=[0x0a], y=[0x0b], zoom=0x40
	break
	video type=1, offset=CINEMATIC_BEETLE_WALKING_LEFT_0, x=[0x0a], y=[0x0b], zoom=0x40
	sub [0x0A], 0x0001
	break
	video type=1, offset=CINEMATIC_BEETLE_WALKING_LEFT_1, x=[0x0a], y=[0x0b], zoom=0x40
	break
	video type=1, offset=CINEMATIC_BEETLE_WALKING_LEFT_1, x=[0x0a], y=[0x0b], zoom=0x40
	sub [0x0A], 0x0001
	break
	video type=1, offset=CINEMATIC_BEETLE_WALKING_LEFT_2, x=[0x0a], y=[0x0b], zoom=0x40
	break
	video type=1, offset=CINEMATIC_BEETLE_WALKING_LEFT_2, x=[0x0a], y=[0x0b], zoom=0x40
	sub [0x0A], 0x0001
	break
	video type=1, offset=CINEMATIC_BEETLE_WALKING_LEFT_3, x=[0x0a], y=[0x0b], zoom=0x40
	break
	video type=1, offset=CINEMATIC_BEETLE_WALKING_LEFT_3, x=[0x0a], y=[0x0b], zoom=0x40
	sub [0x0A], 0x0001
	break
	video type=1, offset=CINEMATIC_BEETLE_WALKING_LEFT_4, x=[0x0a], y=[0x0b], zoom=0x40
	break
	video type=1, offset=CINEMATIC_BEETLE_WALKING_LEFT_4, x=[0x0a], y=[0x0b], zoom=0x40
	sub [0x0A], 0x0001
	break
	video type=1, offset=CINEMATIC_BEETLE_WALKING_LEFT_5, x=[0x0a], y=[0x0b], zoom=0x40
	break
	video type=1, offset=CINEMATIC_BEETLE_WALKING_LEFT_5, x=[0x0a], y=[0x0b], zoom=0x40
	sub [0x0A], 0x0001
	break
	video type=1, offset=CINEMATIC_BEETLE_WALKING_LEFT_6, x=[0x0a], y=[0x0b], zoom=0x40
	break
	video type=1, offset=CINEMATIC_BEETLE_WALKING_LEFT_6, x=[0x0a], y=[0x0b], zoom=0x40
	sub [0x0A], 0x0001
	break
	jmp BEETLE_WALKING_LEFT

