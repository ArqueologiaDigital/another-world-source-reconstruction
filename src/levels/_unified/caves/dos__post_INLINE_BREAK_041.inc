LABEL_EF38:
	call LABEL_9D49
	je [HERO_ACTION_POS_MASK], 0x80, INLINE_BREAK_035
	jmp LABEL_EED5
	killChannel
	call SET_VAR04_TO_0020
	mov [0x2A], 0x0020
	jne [0x0A], 0x00, LABEL_EF03
	mov [0x63], 0x0001
	jmp HERO_WALK_LEFT_LOOP
LABEL_EF59:
	db 0x11

HERO_JUMP_LEFT_FROM_STAND:
	mov [0x63], 0x0064
	je [HERO_POS_MASK], 0x09, HERO_JUMP_RIGHT_FROM_STAND
	video type=0, offset=HERO_JUMP_LEFT_F00, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	video type=0, offset=HERO_JUMP_LEFT_F01, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	video type=0, offset=HERO_JUMP_LEFT_F02, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	call SET_VAR04_TO_0024
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
	mov [0x34], 0xFFFE
	sub [HERO_X], 0x000F
	call CAVES_SCREEN_STEP_UP_ONE_ROW_L4
	break
	add [HERO_X], 0x000F
	video type=0, offset=HERO_JUMP_LEFT_F08, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0002
	sub [HERO_X], 0x000F
	break
	add [HERO_X], 0x000F
	video type=0, offset=HERO_JUMP_LEFT_F09, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0007
	call SET_VAR04_TO_0020
	sub [HERO_X], 0x000C
	break
	add [HERO_X], 0x000C
	video type=0, offset=HERO_JUMP_LEFT_F10, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0004
	sub [HERO_X], 0x0007
	play id=0x0060, freq=0x14, vol=0x40, channel=0x01
	break
	add [HERO_X], 0x0007
	video type=0, offset=HERO_JUMP_LEFT_F11, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0007
	break
	video type=0, offset=HERO_JUMP_LEFT_F12, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	mov [0x63], 0x0001
	jmp LABEL_EAD7
LABEL_F006:
	db 0x11

HERO_JUMP_LEFT_RUN_PRELUDE:
	je [HERO_POS_MASK], 0x09, HERO_JUMP_RIGHT_RUN_PRELUDE
	sub [HERO_X], 0x0005
	sub [HERO_X], 0x0007
	call SET_VAR04_TO_0024
	setup channel=0x15, address=KILL_CHANNEL_LANDING
	mov [0x63], 0x0064
	break

HERO_JUMP_LEFT_FROM_RUN:
	je [HERO_POS_MASK], 0x09, HERO_JUMP_RIGHT_FROM_RUN
	setup channel=0x15, address=KILL_CHANNEL_LANDING
	call SET_VAR04_TO_0024
	video type=0, offset=HERO_JUMP_LEFT_F05, x=[HERO_X], y=[HERO_Y], zoom=0x40
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
	mov [0x34], 0xFFFB
	sub [HERO_X], 0x000F
	call CAVES_SCREEN_STEP_UP_ONE_ROW_L4
	sub [HERO_X], 0x0002
	break
	add [HERO_X], 0x000F
	video type=0, offset=HERO_JUMP_LEFT_F09, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0007
	call SET_VAR04_TO_0020
	sub [HERO_X], 0x000C
	break
	play id=0x0060, freq=0x14, vol=0x40, channel=0x01
	add [HERO_X], 0x000C
	sub [HERO_X], 0x0005
	je [HERO_ACTION], 0x01, LABEL_ED57
	add [HERO_X], 0x0005
	video type=0, offset=HERO_JUMP_LEFT_F10, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0004
	sub [HERO_X], 0x0007
	break
	add [HERO_X], 0x0007
	video type=0, offset=HERO_JUMP_LEFT_F11, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0007
	break
	video type=0, offset=HERO_JUMP_LEFT_F12, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	mov [0x63], 0x0001
	jmp LABEL_EAD7
LABEL_F0CD:
	db 0x11

HERO_JUMP_RIGHT_FROM_STAND:
	mov [0x63], 0x0064
	je [HERO_POS_MASK], 0x0A, HERO_JUMP_LEFT_FROM_STAND
	video type=0, offset=HERO_JUMP_RIGHT_F00, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	video type=0, offset=HERO_JUMP_RIGHT_F01, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	video type=0, offset=HERO_JUMP_RIGHT_F02, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	call SET_VAR04_TO_0034
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
	mov [0x34], 0x0002
	add [HERO_X], 0x000F
	call CAVES_SCREEN_STEP_UP_ONE_ROW_L4
	break
	sub [HERO_X], 0x000F
	video type=0, offset=HERO_JUMP_RIGHT_F08, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0002
	add [HERO_X], 0x000F
	break
	sub [HERO_X], 0x000F
	video type=0, offset=HERO_JUMP_RIGHT_F09, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0007
	call SET_VAR04_TO_0030
	add [HERO_X], 0x000C
	break
	sub [HERO_X], 0x000C
	video type=0, offset=HERO_JUMP_RIGHT_F10, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0004
	add [HERO_X], 0x0007
	play id=0x0060, freq=0x14, vol=0x40, channel=0x01
	break
	sub [HERO_X], 0x0007
	video type=0, offset=HERO_JUMP_RIGHT_F11, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0007
	break
	video type=0, offset=HERO_JUMP_RIGHT_F12, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	mov [0x63], 0x0002
	jmp LABEL_EC97
LABEL_F17A:
	db 0x11

HERO_JUMP_RIGHT_RUN_PRELUDE:
	je [HERO_POS_MASK], 0x0A, HERO_JUMP_LEFT_RUN_PRELUDE
	add [HERO_X], 0x0005
	add [HERO_X], 0x0007
	call SET_VAR04_TO_0034
	setup channel=0x15, address=KILL_CHANNEL_LANDING
	mov [0x63], 0x0064
	break

HERO_JUMP_RIGHT_FROM_RUN:
	je [HERO_POS_MASK], 0x0A, HERO_JUMP_LEFT_FROM_RUN
	call SET_VAR04_TO_0034
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
	mov [0x34], 0x0005
	add [HERO_X], 0x000F
	call CAVES_SCREEN_STEP_UP_ONE_ROW_L4
	add [HERO_X], 0x0002
	break
	sub [HERO_X], 0x000F
	video type=0, offset=HERO_JUMP_RIGHT_F09, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0007
	call SET_VAR04_TO_0030
	add [HERO_X], 0x000C
	break
	play id=0x0060, freq=0x14, vol=0x40, channel=0x01
	sub [HERO_X], 0x000C
	add [HERO_X], 0x0005
	je [HERO_ACTION], 0x01, LABEL_EE45
	sub [HERO_X], 0x0005
	video type=0, offset=HERO_JUMP_RIGHT_F10, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0004
	add [HERO_X], 0x0007
	break
	sub [HERO_X], 0x0007
	video type=0, offset=HERO_JUMP_RIGHT_F11, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0007
	break
	video type=0, offset=HERO_JUMP_RIGHT_F12, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	mov [0x63], 0x0002
	jmp LABEL_EC97
LABEL_F241:
	db 0x11

LABEL_F242:
	call LABEL_9C33
	break
	je [HERO_ACTION_POS_MASK], 0x80, LABEL_F242
	call LABEL_9C33
	mov [0x63], 0x0002
	jmp HERO_WALK_RIGHT_LOOP

LABEL_F256:
	call SET_VAR04_TO_0030
	je [0x0A], 0x00, LABEL_F242
	mov [0x2A], 0x0020
	call CAVES_STEP_DRAW_CV336_THEN_CV340_L4
	add [HERO_X], 0x0004
	call LABEL_9AAF
	add [HERO_X], 0x0001

LABEL_F271:
	break
	je [HERO_ACTION_POS_MASK], 0x80, LABEL_F29F
	call LABEL_9AC1
	je [HERO_ACTION_POS_MASK], 0x00, LABEL_F271
	break
	sub [HERO_X], 0x0002
	call LABEL_9AAF
	sub [HERO_X], 0x0002
	break
	video type=0, offset=CV_15DC, x=[HERO_X], y=[HERO_Y], zoom=0x40
	mov [0x63], 0x0002
	mov [0x0A], 0x0004
	jmp HERO_WALK_RIGHT_LOOP
LABEL_F29E:
	db 0x11

LABEL_F29F:
	jne [0x0F], 0x00, LABEL_F2D4
	add [HERO_X], 0x0002
	call LABEL_9AEB
	mov [0x21], [HERO_X]
	mov [0x27], [HERO_Y]
	add [0x21], 0x001E
	sub [0x27], 0x0027
	call CAVES_STEP_DRAW_CV336_THEN_CV340_L6
	break
	sub [HERO_X], 0x0001
	call LABEL_9AAF
	sub [HERO_X], 0x0001
	jne [HERO_ACTION_POS_MASK], 0x80, LABEL_F271
	setup channel=0x17, address=CAVES_STEP_DRAW_CV336_THEN_CV340_L9
