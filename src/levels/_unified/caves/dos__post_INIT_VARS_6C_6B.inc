LABEL_39D4:
	mov [0x09], 0x0087
	call MUL_VAR6B_BY_11_INTO_VAR21
	mov [0x07], 0x00A8
	add [0x07], [0x21]
	mov [0x08], 0x00AA
	call CAVES_SCENE9_HERO_X_SYNC_OR_NOOP
	call GUARDED_DRAW_CIN_600_810
	add [0x08], 0x000A
	call GUARDED_DRAW_CIN_600_810
	break
	djnz [0x6B], LABEL_39D4
	killChannel

HERO_DIRECTION_LEFT_IDLE_ENTRY:
	mov [0x63], 0x0001
	video offset=CINEMATIC_CAVES_LASER_IMPACT_ANIM_LEFT_3, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_820, x=[HERO_X], y=[HERO_Y]
	break
	jne [SCREEN_NUM], 0x6E, LABEL_3A15
	play id=0x006C, freq=0x14, vol=0x20, channel=0x00

LABEL_3A15:
	video offset=CINEMATIC_821, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_CAVES_HERO_IDLE_LEFT_3, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_CAVES_LASER_BOLT_SPAN_RIGHT_0, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_CAVES_HERO_IDLE_LEFT_3, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_821, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_820, x=[HERO_X], y=[HERO_Y]
	break
	jmp HERO_DIRECTION_LEFT_IDLE_ENTRY

LABEL_3A3C:
	video offset=CINEMATIC_CAVES_HERO_SWIM_ARM_LEFT_F0, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_CAVES_HERO_SWIM_ARM_LEFT_F1, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_CAVES_HERO_SWIM_ARM_LEFT_F2, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_CAVES_HERO_SWIM_ARM_LEFT_F3, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_CAVES_HERO_SWIM_ARM_LEFT_F4, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_CAVES_HERO_SWIM_ARM_LEFT_F5, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_CAVES_HERO_SWIM_ARM_LEFT_F6, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_CAVES_HERO_SWIM_ARM_LEFT_F7, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_CAVES_HERO_SWIM_ARM_LEFT_F8, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_CAVES_HERO_SWIM_ARM_LEFT_F9, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_CAVES_HERO_SWIM_ARM_LEFT_F10, x=[HERO_X], y=[HERO_Y]
	break
	jmp LABEL_3A3C
	killChannel

HANG_DRAW_CIN_903:
	video offset=CINEMATIC_903, x=[HERO_X], y=[HERO_Y]
	break
	jmp HANG_DRAW_CIN_903
LABEL_3A8B:
	db 0x11

HERO_DIRECTION_DOWN_TO_LEFT_TURN:
	mov [0x63], 0x0064
	video offset=CINEMATIC_CAVES_HERO_SWIM_HEAD_UP_LEFT_1, x=[HERO_X], y=[HERO_Y]
	mov [0x19], 0x0000
	mov [0x2A], 0x000A
	break
	video offset=CINEMATIC_CAVES_HERO_SWIM_HEAD_UP_LEFT_0, x=[HERO_X], y=[HERO_Y]
	mov [0x2A], 0x000F
	break
	video offset=CINEMATIC_HERO_SWIM_PITCH_LEFT_0, x=[HERO_X], y=[HERO_Y]
	mov [0x2A], 0x0019
	mov [0x63], 0x0001
	setup channel=0x16, address=LABEL_3A3C
	break
	jmp HERO_DIRECTION_LEFT_IDLE_ENTRY

START_HERO_DIRECTION_LEFT_TO_DOWN_TURN:
	setup channel=0x15, address=HERO_DIRECTION_LEFT_TO_DOWN_TURN
	mov [0x63], 0x0064
	setup channel=0x16, address=KILL_CHANNEL_LANDING
	ret


START_HERO_DIRECTION_LEFT_TO_UP_TURN:
	setup channel=0x15, address=HERO_DIRECTION_LEFT_TO_UP_TURN
	mov [0x63], 0x0064
	setup channel=0x16, address=KILL_CHANNEL_LANDING
	ret


START_HERO_DIRECTION_RIGHT_TO_DOWN_TURN:
	setup channel=0x15, address=HERO_DIRECTION_RIGHT_TO_DOWN_TURN
	mov [0x63], 0x0064
	setup channel=0x16, address=KILL_CHANNEL_LANDING
	ret


START_HERO_DIRECTION_RIGHT_TO_UP_TURN:
	setup channel=0x15, address=HERO_DIRECTION_RIGHT_TO_UP_TURN
	mov [0x63], 0x0064
	setup channel=0x16, address=KILL_CHANNEL_LANDING
	ret


START_HERO_DIRECTION_DOWN_TO_RIGHT_TURN:
	setup channel=0x15, address=HERO_DIRECTION_DOWN_TO_RIGHT_TURN
	mov [0x63], 0x0064
	setup channel=0x16, address=KILL_CHANNEL_LANDING
	ret


START_HERO_DIRECTION_UP_TO_RIGHT_TURN:
	setup channel=0x15, address=HERO_DIRECTION_UP_TO_RIGHT_TURN
	mov [0x63], 0x0064
	setup channel=0x16, address=KILL_CHANNEL_LANDING
	ret


START_HERO_DIRECTION_DOWN_TO_LEFT_TURN:
	setup channel=0x15, address=HERO_DIRECTION_DOWN_TO_LEFT_TURN
	mov [0x63], 0x0064
	setup channel=0x16, address=KILL_CHANNEL_LANDING
	ret


START_HERO_DIRECTION_UP_TO_LEFT_TURN:
	setup channel=0x15, address=HERO_DIRECTION_UP_TO_LEFT_TURN
	mov [0x63], 0x0064
	setup channel=0x16, address=KILL_CHANNEL_LANDING
	ret


START_HERO_DIRECTION_LEFT_TO_RIGHT_TURN:
	setup channel=0x15, address=HERO_DIRECTION_LEFT_TO_RIGHT_TURN
	mov [0x63], 0x0064
	setup channel=0x16, address=KILL_CHANNEL_LANDING
	ret


START_HERO_DIRECTION_RIGHT_TO_LEFT_TURN:
	setup channel=0x15, address=HERO_DIRECTION_RIGHT_TO_LEFT_TURN
	mov [0x63], 0x0064
	setup channel=0x16, address=KILL_CHANNEL_LANDING
	ret


HERO_DIRECTION_LEFT_TO_DOWN_TURN:
	mov [0x63], 0x0068
	video offset=CINEMATIC_HERO_SWIM_PITCH_LEFT_0, x=[HERO_X], y=[HERO_Y]
	mov [0x2A], 0x0014
	mov [0x19], 0x000F
	break
	video offset=CINEMATIC_CAVES_HERO_SWIM_HEAD_UP_LEFT_0, x=[HERO_X], y=[HERO_Y]
	mov [0x2A], 0x000A
	mov [0x19], 0x0019
	break
	video offset=CINEMATIC_CAVES_HERO_SWIM_HEAD_UP_LEFT_1, x=[HERO_X], y=[HERO_Y]
	mov [0x2A], 0x0005
	mov [0x19], 0x001E
	mov [0x63], 0x0004
	setup channel=0x16, address=LABEL_3E37
	break
	jmp HERO_DIRECTION_DOWN_IDLE_LOOP

HERO_DIRECTION_UP_TO_LEFT_TURN:
	mov [0x63], 0x0064
	video offset=CINEMATIC_CAVES_HERO_SWIM_HEAD_DOWN_LEFT_2, x=[HERO_X], y=[HERO_Y]
	mov [0x2A], 0x000A
	mov [0x19], 0x0000
	break
	video offset=CINEMATIC_CAVES_HERO_IDLE_RIGHT_2, x=[HERO_X], y=[HERO_Y]
	mov [0x2A], 0x000F
	break
	video offset=CINEMATIC_CAVES_HERO_IDLE_RIGHT_1, x=[HERO_X], y=[HERO_Y]
	mov [0x2A], 0x0019
	mov [0x63], 0x0001
	setup channel=0x16, address=LABEL_3A3C
	break
	jmp HERO_DIRECTION_LEFT_IDLE_ENTRY

HERO_DIRECTION_LEFT_TO_UP_TURN:
	mov [0x63], 0x0067
	video offset=CINEMATIC_CAVES_HERO_IDLE_RIGHT_1, x=[HERO_X], y=[HERO_Y]
	mov [0x2A], 0x0014
	mov [0x19], 0x000A
	break
	video offset=CINEMATIC_CAVES_HERO_IDLE_RIGHT_2, x=[HERO_X], y=[HERO_Y]
	mov [0x2A], 0x000A
	mov [0x19], 0x000F
	break
	video offset=CINEMATIC_CAVES_HERO_SWIM_HEAD_DOWN_LEFT_2, x=[HERO_X], y=[HERO_Y]
	mov [0x2A], 0x0005
	mov [0x19], 0x0014
	mov [0x63], 0x0003
	setup channel=0x16, address=LABEL_3DCC
	break
	jmp HERO_DIRECTION_UP_IDLE_LOOP
LABEL_3BE2:
	db 0x11

HERO_DIRECTION_DOWN_TO_RIGHT_TURN:
	mov [0x63], 0x0064
	video offset=CINEMATIC_CAVES_HERO_SWIM_HEAD_UP_RIGHT_1, x=[HERO_X], y=[HERO_Y]
	mov [0x19], 0x0000
	mov [0x2A], 0x000A
	break
	video offset=CINEMATIC_CAVES_HERO_SWIM_HEAD_UP_RIGHT_0, x=[HERO_X], y=[HERO_Y]
	mov [0x2A], 0x000F
	break
	video offset=CINEMATIC_HERO_SWIM_PITCH_RIGHT_0, x=[HERO_X], y=[HERO_Y]
	mov [0x2A], 0x0019
	mov [0x63], 0x0002
	setup channel=0x16, address=LABEL_3F02
	break
	jmp HERO_DIRECTION_RIGHT_IDLE_ENTRY

HERO_DIRECTION_LEFT_TO_RIGHT_TURN:
	mov [0x63], 0x0064
	video offset=CINEMATIC_554, x=[HERO_X], y=[HERO_Y]
	mov [0x19], 0x0000
	mov [0x2A], 0x0016
	break
	video offset=CINEMATIC_553, x=[HERO_X], y=[HERO_Y]
	mov [0x2A], 0x000F
	break
	video offset=CINEMATIC_552, x=[HERO_X], y=[HERO_Y]
	mov [0x2A], 0x000A
	break
	video offset=CINEMATIC_551, x=[HERO_X], y=[HERO_Y]
	mov [0x2A], 0x0007
	break
	video offset=CINEMATIC_550, x=[HERO_X], y=[HERO_Y]
	mov [0x2A], 0x0009
	break
	video offset=CINEMATIC_549, x=[HERO_X], y=[HERO_Y]
	mov [0x2A], 0x000A
	break
	video offset=CINEMATIC_548, x=[HERO_X], y=[HERO_Y]
	mov [0x2A], 0x000F
	break
	video offset=CINEMATIC_547, x=[HERO_X], y=[HERO_Y]
	mov [0x2A], 0x0016
	break
	video offset=CINEMATIC_546, x=[HERO_X], y=[HERO_Y]
	mov [0x2A], 0x0019
	mov [0x63], 0x0002
	setup channel=0x16, address=LABEL_3F02
	break
	jmp HERO_DIRECTION_RIGHT_IDLE_ENTRY

HERO_DIRECTION_RIGHT_TO_DOWN_TURN:
	mov [0x63], 0x0068
	video offset=CINEMATIC_HERO_SWIM_PITCH_RIGHT_0, x=[HERO_X], y=[HERO_Y]
	mov [0x2A], 0x0019
	mov [0x19], 0x000F
	break
	video offset=CINEMATIC_CAVES_HERO_SWIM_HEAD_UP_RIGHT_0, x=[HERO_X], y=[HERO_Y]
	mov [0x2A], 0x000A
	mov [0x19], 0x0019
	break
	video offset=CINEMATIC_CAVES_HERO_SWIM_HEAD_UP_RIGHT_1, x=[HERO_X], y=[HERO_Y]
	mov [0x2A], 0x0005
	mov [0x19], 0x001E
	mov [0x63], 0x0004
	setup channel=0x16, address=LABEL_3E37
	break
	jmp HERO_DIRECTION_DOWN_IDLE_LOOP

HERO_DIRECTION_RIGHT_TO_LEFT_TURN:
	mov [0x63], 0x0064
	video offset=CINEMATIC_546, x=[HERO_X], y=[HERO_Y]
	mov [0x19], 0x0000
	mov [0x2A], 0x0016
	break
	video offset=CINEMATIC_547, x=[HERO_X], y=[HERO_Y]
	mov [0x2A], 0x000F
	break
	video offset=CINEMATIC_548, x=[HERO_X], y=[HERO_Y]
	mov [0x2A], 0x000A
	break
	video offset=CINEMATIC_549, x=[HERO_X], y=[HERO_Y]
	mov [0x2A], 0x0007
	break
	video offset=CINEMATIC_550, x=[HERO_X], y=[HERO_Y]
	mov [0x2A], 0x0009
	break
	video offset=CINEMATIC_551, x=[HERO_X], y=[HERO_Y]
	mov [0x2A], 0x000A
	break
	video offset=CINEMATIC_552, x=[HERO_X], y=[HERO_Y]
	mov [0x2A], 0x000F
	break
	video offset=CINEMATIC_553, x=[HERO_X], y=[HERO_Y]
	mov [0x2A], 0x0016
	break
	video offset=CINEMATIC_554, x=[HERO_X], y=[HERO_Y]
	mov [0x2A], 0x0019
	mov [0x63], 0x0001
	setup channel=0x16, address=LABEL_3A3C
	break
	jmp HERO_DIRECTION_LEFT_IDLE_ENTRY

HERO_DIRECTION_UP_TO_RIGHT_TURN:
	mov [0x63], 0x0064
	video offset=CINEMATIC_CAVES_HERO_SWIM_HEAD_DOWN_RIGHT_2, x=[HERO_X], y=[HERO_Y]
	mov [0x2A], 0x000A
	mov [0x19], 0x0000
	break
	video offset=CINEMATIC_CAVES_HERO_SWIM_HEAD_DOWN_RIGHT_1, x=[HERO_X], y=[HERO_Y]
	mov [0x2A], 0x0014
	break
	video offset=CINEMATIC_CAVES_HERO_SWIM_HEAD_DOWN_RIGHT_0, x=[HERO_X], y=[HERO_Y]
	mov [0x2A], 0x0019
	mov [0x63], 0x0002
	setup channel=0x16, address=LABEL_3F02
	break
	jmp HERO_DIRECTION_RIGHT_IDLE_ENTRY

HERO_DIRECTION_RIGHT_TO_UP_TURN:
	mov [0x63], 0x0067
	video offset=CINEMATIC_CAVES_HERO_SWIM_HEAD_DOWN_RIGHT_0, x=[HERO_X], y=[HERO_Y]
	mov [0x2A], 0x0014
	mov [0x19], 0x000A
	break
	video offset=CINEMATIC_CAVES_HERO_SWIM_HEAD_DOWN_RIGHT_1, x=[HERO_X], y=[HERO_Y]
	mov [0x2A], 0x000A
	mov [0x19], 0x000F
	break
	video offset=CINEMATIC_CAVES_HERO_SWIM_HEAD_DOWN_RIGHT_2, x=[HERO_X], y=[HERO_Y]
	mov [0x2A], 0x0005
	mov [0x19], 0x0014
	mov [0x63], 0x0003
	setup channel=0x16, address=LABEL_3DCC
	break
	jmp HERO_DIRECTION_UP_IDLE_LOOP

HERO_DIRECTION_DOWN_IDLE_LOOP:
	mov [0x63], 0x0004
	mov [0x19], 0x001E
	video offset=CINEMATIC_471, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_CAVES_HERO_IDLE_UP_0, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_CAVES_HERO_IDLE_UP_1, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_CAVES_HERO_IDLE_UP_2, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_CAVES_HERO_IDLE_UP_3, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_CAVES_HERO_IDLE_UP_2, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_CAVES_HERO_IDLE_UP_1, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_CAVES_HERO_IDLE_UP_0, x=[HERO_X], y=[HERO_Y]
	break
	jmp HERO_DIRECTION_DOWN_IDLE_LOOP

LABEL_3DCC:
	video offset=CINEMATIC_CAVES_HERO_SWIM_LEGS_CYCLE_F0, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_CAVES_HERO_SWIM_LEGS_CYCLE_F1, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_CAVES_HERO_SWIM_LEGS_CYCLE_F2, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_CAVES_HERO_SWIM_LEGS_CYCLE_F3, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_CAVES_HERO_SWIM_LEGS_CYCLE_F4, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_CAVES_HERO_SWIM_LEGS_CYCLE_F5, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_CAVES_HERO_SWIM_LEGS_CYCLE_F6, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_CAVES_HERO_SWIM_LEGS_CYCLE_F7, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_CAVES_HERO_SWIM_LEGS_CYCLE_F8, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_CAVES_HERO_SWIM_LEGS_CYCLE_F9, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_CAVES_HERO_IDLE_RIGHT_0, x=[HERO_X], y=[HERO_Y]
	break
	jmp LABEL_3DCC
LABEL_3E11:
	db 0x11

LABEL_3E12:
	break
	video offset=CINEMATIC_487, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_486, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_486, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_487, x=[HERO_X], y=[HERO_Y]
	call CAVES_NO_FLOOR_ABOVE_WATERLINE_CASE_6F
	je [0x22], 0x03E8, LABEL_3E12
	jmp LABEL_3E60

LABEL_3E37:
	video offset=CINEMATIC_CAVES_HERO_IDLE_UP_4, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_CAVES_HERO_SWIM_LEGS_DOWNSWEEP_F1, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_CAVES_HERO_SWIM_LEGS_DOWNSWEEP_F2, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_CAVES_HERO_SWIM_LEGS_DOWNSWEEP_F3, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_CAVES_HERO_SWIM_LEGS_DOWNSWEEP_F4, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_CAVES_HERO_SWIM_LEGS_DOWNSWEEP_F5, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_CAVES_HERO_SWIM_LEGS_DOWNSWEEP_F6, x=[HERO_X], y=[HERO_Y]

LABEL_3E60:
	break
	video offset=CINEMATIC_486, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_487, x=[HERO_X], y=[HERO_Y]
	call CAVES_NO_FLOOR_ABOVE_WATERLINE_CASE_6F
	je [0x22], 0x03E8, LABEL_3E12
	break
	video offset=CINEMATIC_488, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_489, x=[HERO_X], y=[HERO_Y]
	break
	jmp LABEL_3E37
LABEL_3E86:
	db 0x11

HERO_DIRECTION_UP_IDLE_LOOP:
	mov [0x63], 0x0003
	video offset=CINEMATIC_496, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_497, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_498, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_499, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_500, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_499, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_498, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_497, x=[HERO_X], y=[HERO_Y]
	break
	jmp HERO_DIRECTION_UP_IDLE_LOOP
LABEL_3EBE:
	db 0x11

HERO_DIRECTION_RIGHT_IDLE_ENTRY:
	mov [0x63], 0x0002
	video offset=CINEMATIC_CAVES_HERO_TURN_5, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_CAVES_HERO_TURN_6, x=[HERO_X], y=[HERO_Y]
	break
	jne [SCREEN_NUM], 0x6E, HERO_DIRECTION_RIGHT_IDLE_LOOP
	play id=0x006C, freq=0x14, vol=0x20, channel=0x01

HERO_DIRECTION_RIGHT_IDLE_LOOP:
	video offset=CINEMATIC_CAVES_HERO_TURN_7, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_CAVES_HERO_TURN_8, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_CAVES_HERO_IDLE_RIGHT_4, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_CAVES_HERO_TURN_8, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_CAVES_HERO_TURN_7, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_CAVES_HERO_TURN_6, x=[HERO_X], y=[HERO_Y]
	break
	jmp HERO_DIRECTION_RIGHT_IDLE_ENTRY

LABEL_3F02:
	video offset=CINEMATIC_CAVES_HERO_SWIM_ARM_RIGHT_F0, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_CAVES_HERO_SWIM_ARM_RIGHT_F1, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_CAVES_SCREEN_70_BACKDROP_LAYER_0, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_CAVES_HERO_SWIM_ARM_RIGHT_F3, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_CAVES_HERO_SWIM_ARM_RIGHT_F4, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_CAVES_HERO_SWIM_ARM_RIGHT_F5, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_CAVES_HERO_SWIM_ARM_RIGHT_F6, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_CAVES_SCREEN_75_BACKDROP_LAYER_0, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_CAVES_SCREEN_75_BACKDROP_LAYER_1, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_CAVES_HERO_SWIM_ARM_RIGHT_F9, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_CAVES_HERO_SWIM_ARM_RIGHT_F10, x=[HERO_X], y=[HERO_Y]
	break
	jmp LABEL_3F02
LABEL_3F47:
	db 0x11
