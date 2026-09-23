LABEL_EFC1:
	call LABEL_9CC0
	je [HERO_ACTION_POS_MASK], 0x80, INLINE_BREAK_035
	jmp LABEL_EF5E
	killChannel
	call SET_VAR04_TO_0020
	mov [0x2A], 0x0020
	jne [0x0A], 0x00, LABEL_EF8C
	mov [0x63], 0x0001
	jmp HERO_WALK_LEFT_LOOP
LABEL_EFE2:
	db 0x11

LABEL_EFE3:
	mov [0x63], 0x0064
	je [HERO_POS_MASK], 0x09, LABEL_F157
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
	jmp LABEL_EB60
LABEL_F08F:
	db 0x11

LABEL_F090:
	je [HERO_POS_MASK], 0x09, LABEL_F204
	sub [HERO_X], 0x0005
	sub [HERO_X], 0x0007
	call SET_VAR04_TO_0024
	setup channel=0x15, address=KILL_CHANNEL_LANDING
	mov [0x63], 0x0064
	break

LABEL_F0AA:
	je [HERO_POS_MASK], 0x09, LABEL_F21E
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
	je [HERO_ACTION], 0x01, LABEL_EDE0
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
	jmp LABEL_EB60
LABEL_F156:
	db 0x11

LABEL_F157:
	mov [0x63], 0x0064
	je [HERO_POS_MASK], 0x0A, LABEL_EFE3
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
	jmp LABEL_ED20
LABEL_F203:
	db 0x11

LABEL_F204:
	je [HERO_POS_MASK], 0x0A, LABEL_F090
	add [HERO_X], 0x0005
	add [HERO_X], 0x0007
	call SET_VAR04_TO_0034
	setup channel=0x15, address=KILL_CHANNEL_LANDING
	mov [0x63], 0x0064
	break

LABEL_F21E:
	je [HERO_POS_MASK], 0x0A, LABEL_F0AA
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
	je [HERO_ACTION], 0x01, LABEL_EECE
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
	jmp LABEL_ED20
LABEL_F2CA:
	db 0x11

LABEL_F2CB:
	call LABEL_9BAA
	break
	je [HERO_ACTION_POS_MASK], 0x80, LABEL_F2CB
	call LABEL_9BAA
	mov [0x63], 0x0002
	jmp HERO_WALK_RIGHT_LOOP

LABEL_F2DF:
	call SET_VAR04_TO_0030
	je [0x0A], 0x00, LABEL_F2CB
	mov [0x2A], 0x0020
	call CAVES_STEP_DRAW_CV336_THEN_CV340_L4
	add [HERO_X], 0x0004
	call LABEL_9A26
	add [HERO_X], 0x0001

LABEL_F2FA:
	break
	je [HERO_ACTION_POS_MASK], 0x80, LABEL_F328
	call LABEL_9A38
	je [HERO_ACTION_POS_MASK], 0x00, LABEL_F2FA
	break
	sub [HERO_X], 0x0002
	call LABEL_9A26
	sub [HERO_X], 0x0002
	break
	video type=0, offset=HERO_STAND_GUN_LOWER_RIGHT, x=[HERO_X], y=[HERO_Y], zoom=0x40
	mov [0x63], 0x0002
	mov [0x0A], 0x0004
	jmp HERO_WALK_RIGHT_LOOP
LABEL_F327:
	db 0x11

LABEL_F328:
	jne [0x0F], 0x00, LABEL_F35D
	add [HERO_X], 0x0002
	call LABEL_9A62
	mov [0x21], [HERO_X]
	mov [0x27], [HERO_Y]
	add [0x21], 0x001E
	sub [0x27], 0x0027
	call CAVES_STEP_DRAW_CV336_THEN_CV340_L6
	break
	sub [HERO_X], 0x0001
	call LABEL_9A26
	sub [HERO_X], 0x0001
	jne [HERO_ACTION_POS_MASK], 0x80, LABEL_F2FA
	setup channel=0x17, address=CAVES_STEP_DRAW_CV336_THEN_CV340_L9
