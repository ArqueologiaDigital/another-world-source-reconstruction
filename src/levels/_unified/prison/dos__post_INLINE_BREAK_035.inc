LABEL_94C3:
	call LABEL_6D68
	je [HERO_ACTION_POS_MASK], 0x80, INLINE_BREAK_035
	jmp PRISON_HERO_FIRE_LEFT_HOLD_LOOP
LABEL_94CF:
	db 0x11

LABEL_94D0:
	call SET_VAR04_TO_0020
	mov [0x2A], 0x0020
	jne [0x0A], 0x00, LABEL_9487
	sub [HERO_X], 0x0004
	call HANDLE_HORIZ_VAR01_VS_VAR28
	video offset=CINEMATIC_PRISON_HERO_ARM_OUT_LEFT, x=[HERO_X], y=[HERO_Y]
	break
	add [HERO_X], 0x0001
	video offset=CINEMATIC_PRISON_HERO_ARM_OUT_LEFT, x=[HERO_X], y=[HERO_Y]
	add [HERO_X], 0x0001

LABEL_94F7:
	break
	video offset=CINEMATIC_PRISON_HERO_ARM_OUT_LEFT, x=[HERO_X], y=[HERO_Y]
	je [HERO_ACTION_POS_MASK], 0x88, LABEL_94F7
	break
	add [HERO_X], 0x0002
	video offset=CINEMATIC_557, x=[HERO_X], y=[HERO_Y]
	mov [0x63], 0x0001
	add [HERO_X], 0x0002
	jmp HERO_WALK_LEFT_LOOP
LABEL_9518:
	db 0x11

PRISON_HERO_WALK_JUMP_LEFT:
	je [HERO_POS_MASK], 0x09, PRISON_HERO_WALK_JUMP_RIGHT
	mov [0x63], 0x0064
	video type=0, offset=HERO_JUMP_LEFT_F00, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	video type=0, offset=HERO_JUMP_LEFT_F01, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	video type=0, offset=HERO_JUMP_LEFT_F02, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	video type=0, offset=HERO_JUMP_LEFT_F03, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0005
	break
	video type=0, offset=HERO_JUMP_LEFT_F04, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0007
	break
	video type=0, offset=HERO_JUMP_LEFT_F05, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x000D
	break
	video type=0, offset=HERO_JUMP_LEFT_F06, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x000C
	break
	video type=0, offset=HERO_JUMP_LEFT_F08, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0002
	break
	video type=0, offset=HERO_JUMP_LEFT_F09, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0007
	break
	video type=0, offset=HERO_JUMP_LEFT_F10, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0004
	break
	play id=0x0060, freq=0x14, vol=0x40, channel=0x00
	video type=0, offset=HERO_JUMP_LEFT_F11, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0007
	break
	video type=0, offset=HERO_JUMP_LEFT_F12, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	mov [0x63], 0x0001
	jmp PRISON_HERO_STAND_LEFT_TICK
LABEL_9598:
	db 0x11

PRISON_HERO_RUN_JUMP_LEFT:
	je [HERO_POS_MASK], 0x09, PRISON_HERO_RUN_JUMP_RIGHT
	sub [HERO_X], 0x0005
	sub [HERO_X], 0x0007
	setup channel=0x15, address=KILL_CHANNEL_LANDING
	mov [0x63], 0x0064
	break

LABEL_95B0:
	je [HERO_POS_MASK], 0x09, LABEL_96CF
	video type=0, offset=HERO_JUMP_LEFT_F05, x=[HERO_X], y=[HERO_Y], zoom=0x40
	setup channel=0x15, address=KILL_CHANNEL_LANDING
	sub [HERO_X], 0x000D
	sub [HERO_Y], 0x0002
	break
	video type=0, offset=HERO_JUMP_LEFT_F06, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x000C
	break
	video type=0, offset=HERO_JUMP_LEFT_F07, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x000C
	add [HERO_Y], 0x0001
	break
	video type=0, offset=HERO_JUMP_LEFT_F07, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x000C
	add [HERO_Y], 0x0001
	break
	video type=0, offset=HERO_JUMP_LEFT_F08, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0002
	break
	video type=0, offset=HERO_JUMP_LEFT_F09, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0007
	break
	sub [HERO_X], 0x0005
	je [HERO_ACTION], 0x01, PRISON_HERO_RUN_LEFT_STRIDE_LOOP
	add [HERO_X], 0x0005
	video type=0, offset=HERO_JUMP_LEFT_F10, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0004
	break
	play id=0x0060, freq=0x14, vol=0x40, channel=0x00
	video type=0, offset=HERO_JUMP_LEFT_F11, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0007
	break
	video type=0, offset=HERO_JUMP_LEFT_F12, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	mov [0x63], 0x0002
	jmp PRISON_HERO_STAND_RIGHT_TICK
LABEL_9637:
	db 0x11

PRISON_HERO_WALK_JUMP_RIGHT:
	je [HERO_POS_MASK], 0x0A, PRISON_HERO_WALK_JUMP_LEFT
	mov [0x63], 0x0064
	video type=0, offset=HERO_JUMP_RIGHT_F00, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	video type=0, offset=HERO_JUMP_RIGHT_F01, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	video type=0, offset=HERO_JUMP_RIGHT_F02, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	video type=0, offset=HERO_JUMP_RIGHT_F03, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0005
	break
	video type=0, offset=HERO_JUMP_RIGHT_F04, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0007
	break
	video type=0, offset=HERO_JUMP_RIGHT_F05, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x000D
	break
	video type=0, offset=HERO_JUMP_RIGHT_F06, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x000C
	break
	video type=0, offset=HERO_JUMP_RIGHT_F08, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0002
	break
	video type=0, offset=HERO_JUMP_RIGHT_F09, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0007
	break
	video type=0, offset=HERO_JUMP_RIGHT_F10, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0004
	break
	play id=0x0060, freq=0x14, vol=0x40, channel=0x00
	video type=0, offset=HERO_JUMP_RIGHT_F11, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0007
	break
	video type=0, offset=HERO_JUMP_RIGHT_F12, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	mov [0x63], 0x0002
	jmp PRISON_HERO_STAND_RIGHT_TICK
LABEL_96B7:
	db 0x11

PRISON_HERO_RUN_JUMP_RIGHT:
	je [HERO_POS_MASK], 0x0A, PRISON_HERO_RUN_JUMP_LEFT
	add [HERO_X], 0x0005
	add [HERO_X], 0x0007
	setup channel=0x15, address=KILL_CHANNEL_LANDING
	mov [0x63], 0x0064
	break

LABEL_96CF:
	je [HERO_POS_MASK], 0x0A, LABEL_95B0
	setup channel=0x15, address=KILL_CHANNEL_LANDING
	video type=0, offset=HERO_JUMP_RIGHT_F05, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x000D
	sub [HERO_Y], 0x0002
	break
	video type=0, offset=HERO_JUMP_RIGHT_F06, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x000C
	break
	video type=0, offset=HERO_JUMP_RIGHT_F07, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x000C
	add [HERO_Y], 0x0001
	break
	video type=0, offset=HERO_JUMP_RIGHT_F07, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x000C
	add [HERO_Y], 0x0001
	break
	video type=0, offset=HERO_JUMP_RIGHT_F08, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0002
	break
	video type=0, offset=HERO_JUMP_RIGHT_F09, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0007
	break
	add [HERO_X], 0x0005
	je [HERO_ACTION], 0x01, PRISON_HERO_RUN_RIGHT_STRIDE_LOOP
	sub [HERO_X], 0x0005
	video type=0, offset=HERO_JUMP_RIGHT_F10, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0004
	break
	play id=0x0060, freq=0x14, vol=0x40, channel=0x00
	video type=0, offset=HERO_JUMP_RIGHT_F11, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0007
	break
	video type=0, offset=HERO_JUMP_RIGHT_F12, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	mov [0x63], 0x0002
	jmp PRISON_HERO_STAND_RIGHT_TICK
LABEL_9756:
	db 0x11

LABEL_9757:
	call SET_VAR04_TO_0030
	je [0x0A], 0x00, PRISON_HERO_ENTER_STAND_RIGHT_TICK
	mov [0x2A], 0x0021
	call HANDLE_HORIZ_VAR01_VS_VAR28
	add [HERO_X], 0x0004
	video offset=CINEMATIC_PRISON_HERO_STAND_SHOOT_RIGHT_F1, x=[HERO_X], y=[HERO_Y]
	add [HERO_X], 0x0001

PRISON_HERO_FIRE_RIGHT_HOLD_LOOP:
	break
	je [HERO_ACTION_POS_MASK], 0x80, LABEL_97AC
	call LABEL_6B58
	je [HERO_ACTION_POS_MASK], 0x00, PRISON_HERO_FIRE_RIGHT_HOLD_LOOP
	break
	sub [HERO_X], 0x0002
	video offset=CINEMATIC_PRISON_HERO_STAND_SHOOT_RIGHT_F1, x=[HERO_X], y=[HERO_Y]
	sub [HERO_X], 0x0002
	break
	video offset=CINEMATIC_562, x=[HERO_X], y=[HERO_Y]
	mov [0x63], 0x0002
	mov [0x0A], 0x0004
	jmp HERO_WALK_RIGHT_LOOP
LABEL_97A3:
	db 0x11

PRISON_HERO_ENTER_STAND_RIGHT_TICK:
	mov [0x63], 0x0002
	jmp PRISON_HERO_STAND_RIGHT_TICK
LABEL_97AB:
	db 0x11

LABEL_97AC:
	jne [0x0F], 0x00, LABEL_97E5
	add [HERO_X], 0x0002
	video offset=CINEMATIC_PRISON_HERO_STAND_SHOOT_RIGHT_F0, x=[HERO_X], y=[HERO_Y]
	mov [0x21], [HERO_X]
	mov [0x27], [HERO_Y]
	add [0x21], 0x001E
	sub [0x27], 0x0027
	call PRISON_HERO_FIRE_SHOT_RIGHT
	break
	sub [HERO_X], 0x0001
	video offset=CINEMATIC_PRISON_HERO_STAND_SHOOT_RIGHT_F1, x=[HERO_X], y=[HERO_Y]
	sub [HERO_X], 0x0001
	jne [HERO_ACTION_POS_MASK], 0x80, PRISON_HERO_FIRE_RIGHT_HOLD_LOOP
	setup channel=0x17, address=PRISON_HERO_GUN_CHARGE_STILL_ENTRY
