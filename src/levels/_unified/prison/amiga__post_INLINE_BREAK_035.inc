LABEL_9295:
	call LABEL_6CBB
	je [HERO_ACTION_POS_MASK], 0x80, INLINE_BREAK_035
	jmp PRISON_HERO_FIRE_LEFT_HOLD_LOOP
LABEL_92A1:
	db 0x11

LABEL_92A2:
	call SET_VAR04_TO_0020
	mov [0x2A], 0x0020
	jne [0x0A], 0x00, LABEL_9259
	sub [HERO_X], 0x0004
	call HANDLE_HORIZ_VAR01_VS_VAR28
	video offset=CINEMATIC_560, x=[HERO_X], y=[HERO_Y]
	break
	add [HERO_X], 0x0001
	video offset=CINEMATIC_560, x=[HERO_X], y=[HERO_Y]
	add [HERO_X], 0x0001

LABEL_92C9:
	break
	video offset=CINEMATIC_560, x=[HERO_X], y=[HERO_Y]
	je [HERO_ACTION_POS_MASK], 0x88, LABEL_92C9
	break
	add [HERO_X], 0x0002
	video offset=CINEMATIC_557, x=[HERO_X], y=[HERO_Y]
	mov [0x63], 0x0001
	add [HERO_X], 0x0002
	jmp HERO_WALK_LEFT_LOOP
LABEL_92EA:
	db 0x11

PRISON_HERO_WALK_JUMP_LEFT:
	mov [0x63], 0x0064
	video type=0, offset=CV_52C0, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	video type=0, offset=CV_52E0, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	video type=0, offset=CV_5300, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	video type=0, offset=CV_5320, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0005
	break
	video type=0, offset=CV_5340, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0007
	break
	video type=0, offset=CV_5360, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x000D
	break
	video type=0, offset=CV_5380, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x000C
	break
	video type=0, offset=CV_53C0, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0002
	break
	video type=0, offset=CV_53E0, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0007
	break
	video type=0, offset=CV_5400, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0004
	break
	play id=0x0060, freq=0x14, vol=0x40, channel=0x00
	video type=0, offset=CV_5420, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0007
	break
	video type=0, offset=CV_5444, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	mov [0x63], 0x0001
	jmp PRISON_HERO_STAND_LEFT_TICK
LABEL_9364:
	db 0x11

PRISON_HERO_RUN_JUMP_LEFT:
	sub [HERO_X], 0x0005
	sub [HERO_X], 0x0007
	setup channel=0x15, address=KILL_CHANNEL_LANDING
	mov [0x63], 0x0064
	break
	video type=0, offset=CV_5360, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x000D
	sub [HERO_Y], 0x0002
	break
	video type=0, offset=CV_5380, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x000C
	break
	video type=0, offset=CV_53A0, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x000C
	add [HERO_Y], 0x0001
	break
	video type=0, offset=CV_53A0, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x000C
	add [HERO_Y], 0x0001
	break
	video type=0, offset=CV_53C0, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0002
	break
	video type=0, offset=CV_53E0, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0007
	break
	sub [HERO_X], 0x0005
	je [HERO_ACTION], 0x01, PRISON_HERO_RUN_LEFT_STRIDE_LOOP
	add [HERO_X], 0x0005
	video type=0, offset=CV_5400, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0004
	break
	play id=0x0060, freq=0x14, vol=0x40, channel=0x00
	video type=0, offset=CV_5420, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0007
	break
	video type=0, offset=CV_5444, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	mov [0x63], 0x0002
	jmp PRISON_HERO_STAND_RIGHT_TICK
LABEL_93F3:
	db 0x11

PRISON_HERO_WALK_JUMP_RIGHT:
	mov [0x63], 0x0064
	video type=0, offset=CV_4D98, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	video type=0, offset=CV_4DE4, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	video type=0, offset=CV_4E30, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	video type=0, offset=CV_4E7C, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0005
	break
	video type=0, offset=CV_4EC8, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0007
	break
	video type=0, offset=CV_4F14, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x000D
	break
	video type=0, offset=CV_4F68, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x000C
	break
	video type=0, offset=CV_500C, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0002
	break
	video type=0, offset=CV_5058, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0007
	break
	video type=0, offset=CV_50A8, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0004
	break
	play id=0x0060, freq=0x14, vol=0x40, channel=0x00
	video type=0, offset=CV_50F8, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0007
	break
	video type=0, offset=CV_514C, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	mov [0x63], 0x0002
	jmp PRISON_HERO_STAND_RIGHT_TICK
LABEL_946D:
	db 0x11

PRISON_HERO_RUN_JUMP_RIGHT:
	add [HERO_X], 0x0005
	add [HERO_X], 0x0007
	setup channel=0x15, address=KILL_CHANNEL_LANDING
	mov [0x63], 0x0064
	break
	video type=0, offset=CV_4F14, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x000D
	sub [HERO_Y], 0x0002
	break
	video type=0, offset=CV_4F68, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x000C
	break
	video type=0, offset=CV_4FBC, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x000C
	add [HERO_Y], 0x0001
	break
	video type=0, offset=CV_4FBC, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x000C
	add [HERO_Y], 0x0001
	break
	video type=0, offset=CV_500C, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0002
	break
	video type=0, offset=CV_5058, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0007
	break
	add [HERO_X], 0x0005
	je [HERO_ACTION], 0x01, PRISON_HERO_RUN_RIGHT_STRIDE_LOOP
	sub [HERO_X], 0x0005
	video type=0, offset=CV_50A8, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0004
	break
	play id=0x0060, freq=0x14, vol=0x40, channel=0x00
	video type=0, offset=CV_50F8, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0007
	break
	video type=0, offset=CV_514C, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	mov [0x63], 0x0002
	jmp PRISON_HERO_STAND_RIGHT_TICK
LABEL_94FC:
	db 0x11

LABEL_94FD:
	call SET_VAR04_TO_0030
	je [0x0A], 0x00, PRISON_HERO_ENTER_STAND_RIGHT_TICK
	mov [0x2A], 0x0021
	call HANDLE_HORIZ_VAR01_VS_VAR28
	add [HERO_X], 0x0004
	video offset=CINEMATIC_565, x=[HERO_X], y=[HERO_Y]
	add [HERO_X], 0x0001

PRISON_HERO_FIRE_RIGHT_HOLD_LOOP:
	break
	je [HERO_ACTION_POS_MASK], 0x80, LABEL_9552
	call LABEL_6AAB
	je [HERO_ACTION_POS_MASK], 0x00, PRISON_HERO_FIRE_RIGHT_HOLD_LOOP
	break
	sub [HERO_X], 0x0002
	video offset=CINEMATIC_565, x=[HERO_X], y=[HERO_Y]
	sub [HERO_X], 0x0002
	break
	video offset=CINEMATIC_562, x=[HERO_X], y=[HERO_Y]
	mov [0x63], 0x0002
	mov [0x0A], 0x0004
	jmp HERO_WALK_RIGHT_LOOP
LABEL_9549:
	db 0x11

PRISON_HERO_ENTER_STAND_RIGHT_TICK:
	mov [0x63], 0x0002
	jmp PRISON_HERO_STAND_RIGHT_TICK
LABEL_9551:
	db 0x11

LABEL_9552:
	jne [0x0F], 0x00, LABEL_958B
	add [HERO_X], 0x0002
	video offset=CINEMATIC_566, x=[HERO_X], y=[HERO_Y]
	mov [0x21], [HERO_X]
	mov [0x27], [HERO_Y]
	add [0x21], 0x001E
	sub [0x27], 0x0027
	call PRISON_HERO_FIRE_SHOT_RIGHT
	break
	sub [HERO_X], 0x0001
	video offset=CINEMATIC_565, x=[HERO_X], y=[HERO_Y]
	sub [HERO_X], 0x0001
	jne [HERO_ACTION_POS_MASK], 0x80, PRISON_HERO_FIRE_RIGHT_HOLD_LOOP
	setup channel=0x17, address=PRISON_HERO_GUN_CHARGE_STILL_ENTRY
