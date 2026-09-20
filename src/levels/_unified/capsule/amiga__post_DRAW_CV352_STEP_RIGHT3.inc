CAPSULE_INLINE_SET_VAR63_TO_1_L2:
	call SET_VAR04_TO_0030
	mov [0x2A], 0x000F
	call CAPSULE_HERO_WALK_RIGHT_DRAW_0
	je [HERO_POS_MASK], 0x00, LABEL_9123
	add [HERO_X], 0x0002
	mov [0x36], 0xFFFB
	break
	call CAPSULE_HERO_WALK_RIGHT_DRAW_1
	je [HERO_POS_MASK], 0x00, CAPSULE_HERO_WALK_RIGHT_STOP_STRIDE1_REWIND_1
	add [HERO_X], 0x0002
	mov [0x36], 0xFFF9
	break
	call CAPSULE_HERO_WALK_RIGHT_DRAW_2
	je [HERO_POS_MASK], 0x00, CAPSULE_HERO_WALK_RIGHT_STOP_STRIDE1_REWIND_2
	add [HERO_X], 0x0002
	mov [0x36], 0x0007
	break
	call CAPSULE_HERO_WALK_RIGHT_DRAW_3
	add [HERO_X], 0x0003
	mov [0x36], 0x0005
	break
	call CAPSULE_HERO_WALK_RIGHT_DRAW_4
	add [HERO_X], 0x0002
	mov [0x36], 0x0003
	break
	call CAPSULE_HERO_WALK_RIGHT_FOOTSTEP_PHASE_1
	add [HERO_X], 0x0002
	mov [0x36], 0x0001
	break
	call CAPSULE_HERO_WALK_RIGHT_DRAW_6
	add [HERO_X], 0x0002
	mov [0x36], 0x0000

; Two-frame aim/gun-pose render tick. Calls LABEL_9110
; (an angle-update helper), then conditionally draws
; CV_5F74 + CV_2D6E at HERO position
; with zoom 0x40 — gated on var06 vs var30 (angle range)
; and var31 bit 1. Mirrors CAVES's LABEL_9B3F.
CAPSULE_AIM_RENDER_TICK_CV159_CV160:
	break
	je [HERO_POS_MASK], 0x09, LABEL_965B
	call SET_VAR04_TO_0030
	call DRAW_HERO_WALK_RIGHT_F07
	jne [HERO_POS_MASK], 0x01, CAPSULE_AIM_RENDER_TICK_CV159_CV160
	add [HERO_X], 0x0002
	mov [0x36], 0xFFFD
	break
	call CAPSULE_HERO_WALK_RIGHT_DRAW_8
	je [HERO_POS_MASK], 0x00, LABEL_9142
	add [HERO_X], 0x0002
	mov [0x36], 0xFFFB
	break
	call CAPSULE_HERO_WALK_RIGHT_DRAW_9
	je [HERO_POS_MASK], 0x00, CAPSULE_HERO_WALK_RIGHT_STOP_STRIDE2_REWIND_1
	add [HERO_X], 0x0002
	mov [0x36], 0xFFF9
	break
	call CAPSULE_HERO_WALK_RIGHT_DRAW_10
	je [HERO_POS_MASK], 0x00, CAPSULE_HERO_WALK_RIGHT_STOP_STRIDE2_REWIND_2
	add [HERO_X], 0x0002
	mov [0x36], 0xFFF8
	break
	call CAPSULE_HERO_WALK_RIGHT_DRAW_11
	add [HERO_X], 0x0003
	mov [0x36], 0x0005
	break
	call CAPSULE_HERO_WALK_RIGHT_DRAW_12
	add [HERO_X], 0x0002
	mov [0x36], 0x0003
	break
	call CAPSULE_HERO_WALK_RIGHT_FOOTSTEP_PHASE_2
	add [HERO_X], 0x0002
	mov [0x36], 0x0001
	break
	call CAPSULE_HERO_WALK_RIGHT_DRAW_14
	add [HERO_X], 0x0002

HERO_WALK_RIGHT_LOOP:
	break
	je [HERO_ACTION_POS_MASK], 0x04, HERO_GUN_RAISE_ENTRY_FACING_RIGHT
	je [HERO_POS_MASK], 0x09, LABEL_965B

LABEL_924E:
	call LABEL_7955
	call SET_VAR04_TO_0030
	jne [HERO_POS_MASK], 0x01, HERO_WALK_RIGHT_LOOP
	add [HERO_X], 0x0002
	mov [0x36], 0xFFFD
	break
	jmp CAPSULE_INLINE_SET_VAR63_TO_1_L2
LABEL_9266:
	db 0x11

HERO_RUN_LEFT_DECELERATION_LOOP:
	break
	je [0x63], 0x05, HERO_RUN_LEFT_DECELERATION_LOOP
	sub [HERO_X], 0x0003
	break
	sub [HERO_X], 0x0002
	break
	sub [HERO_X], 0x0002
	break
	sub [HERO_X], 0x0001
	break
	sub [HERO_X], 0x0001
	break
	sub [HERO_X], 0x0001
	killChannel

CAPSULE_HERO_RUN_LEFT_EXIT_TO_WALK_LEFT_LOOP:
	mov [0x63], 0x0001
	jmp HERO_WALK_LEFT_LOOP
LABEL_9293:
	db 0x11

LABEL_9294:
	sub [HERO_X], 0x0004
	video offset=CINEMATIC_114, x=[HERO_X], y=[HERO_Y]
	add [HERO_X], 0x0001
	je [HERO_POS_MASK], 0x00, CAPSULE_HERO_RUN_LEFT_EXIT_TO_WALK_LEFT_LOOP
	break

LABEL_92A8:
	call LABEL_7B25
	je [HERO_POS_MASK], 0x00, CAPSULE_HERO_RUN_LEFT_EXIT_TO_WALK_LEFT_LOOP
	break
	je [HERO_POS_MASK], 0x00, LABEL_92A8

LABEL_92B8:
	setup channel=0x15, address=HERO_RUN_LEFT_DECELERATION_LOOP
	sub [HERO_X], 0x0004

LABEL_92C0:
	call CAPSULE_HERO_RUN_LEFT_DRAW_0
	call SET_VAR04_TO_0020
	mov [0x2A], 0x000F
	sub [HERO_X], 0x0006
	break
	call CAPSULE_HERO_RUN_LEFT_DRAW_1
	je [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_95A0
	sub [HERO_X], 0x0008
	add [HERO_Y], 0x0000
	break
	call CAPSULE_HERO_RUN_LEFT_DRAW_2
	sub [HERO_X], 0x0008
	break
	call CAPSULE_HERO_RUN_LEFT_DRAW_3
	sub [HERO_X], 0x0008
	add [HERO_Y], 0x0000
	break
	call CAPSULE_HERO_RUN_LEFT_DRAW_4
	add [HERO_Y], 0x0000
	je [HERO_POS_MASK], 0x00, CAPSULE_HERO_RUN_LEFT_EXIT_TO_WALK_LEFT_LOOP
	sub [HERO_X], 0x000A
	break

LABEL_9308:
	mov [0x63], 0x0005
	call CAPSULE_HERO_RUN_LEFT_DRAW_5
	sub [HERO_X], 0x0006
	break
	call CAPSULE_HERO_RUN_LEFT_DRAW_6
	je [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_95A0
	sub [HERO_X], 0x0008
	add [HERO_Y], 0x0000
	break
	call CAPSULE_HERO_RUN_LEFT_DRAW_7
	sub [HERO_X], 0x0008
	break
	call CAPSULE_HERO_RUN_LEFT_DRAW_8
	sub [HERO_X], 0x0008
	add [HERO_Y], 0x0000
	break
	call CAPSULE_HERO_RUN_LEFT_DRAW_9
	add [HERO_Y], 0x0000
	je [HERO_POS_MASK], 0x00, CAPSULE_HERO_RUN_LEFT_EXIT_TO_WALK_LEFT_LOOP
	sub [HERO_X], 0x000A
	break
	jmp LABEL_92C0
LABEL_9350:
	db 0x11

HERO_RUN_RIGHT_DECELERATION_LOOP:
	break
	je [0x63], 0x06, HERO_RUN_RIGHT_DECELERATION_LOOP
	add [HERO_X], 0x0003
	break
	add [HERO_X], 0x0002
	break
	add [HERO_X], 0x0002
	break
	add [HERO_X], 0x0001
	break
	add [HERO_X], 0x0001
	break
	add [HERO_X], 0x0001
	killChannel

CAPSULE_HERO_RUN_RIGHT_EXIT_TO_WALK_RIGHT_LOOP:
	mov [0x63], 0x0002
	jmp HERO_WALK_RIGHT_LOOP
LABEL_937D:
	db 0x11

CAPSULE_INLINE_SET_VAR63_TO_5_L3:
	video offset=CINEMATIC_114, x=[HERO_X], y=[HERO_Y]
	add [HERO_X], 0x0003
	je [HERO_POS_MASK], 0x00, CAPSULE_HERO_RUN_RIGHT_EXIT_TO_WALK_RIGHT_LOOP
	break

LABEL_938E:
	call LABEL_7955
	je [HERO_POS_MASK], 0x00, CAPSULE_HERO_RUN_RIGHT_EXIT_TO_WALK_RIGHT_LOOP
	break
	je [HERO_POS_MASK], 0x00, LABEL_938E

CAPSULE_INLINE_SET_VAR63_TO_5_L2:
	setup channel=0x15, address=HERO_RUN_RIGHT_DECELERATION_LOOP
	add [HERO_X], 0x0004

LABEL_93A6:
	call CAPSULE_HERO_RUN_RIGHT_FOOTSTEP_PHASE_1
	call SET_VAR04_TO_0030
	mov [0x2A], 0x000F
	add [HERO_X], 0x0006
	mov [0x36], 0xFFF4
	break
	call CAPSULE_HERO_RUN_RIGHT_DRAW_1
	je [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_9702
	add [HERO_X], 0x0008
	mov [0x36], 0xFFEF
	break
	call CAPSULE_HERO_RUN_RIGHT_DRAW_2
	add [HERO_X], 0x0008
	mov [0x36], 0xFFFE
	break
	call CAPSULE_HERO_RUN_RIGHT_DRAW_3
	add [HERO_X], 0x0008
	mov [0x36], 0x0005
	break
	call CAPSULE_HERO_RUN_RIGHT_DRAW_4
	je [HERO_POS_MASK], 0x00, CAPSULE_HERO_RUN_RIGHT_EXIT_TO_WALK_RIGHT_LOOP
	add [HERO_X], 0x000A
	mov [0x36], 0xFFF9
	break

LABEL_93F6:
	mov [0x63], 0x0006
	call CAPSULE_HERO_RUN_RIGHT_FOOTSTEP_PHASE_2
	add [HERO_X], 0x0006
	mov [0x36], 0xFFF4
	break
	call CAPSULE_HERO_RUN_RIGHT_DRAW_6
	je [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_9702
	add [HERO_Y], 0x0000
	add [HERO_X], 0x0008
	mov [0x36], 0xFFEF
	break
	call CAPSULE_HERO_RUN_RIGHT_DRAW_7
	add [HERO_X], 0x0008
	mov [0x36], 0xFFFE
	break
	call CAPSULE_HERO_RUN_RIGHT_DRAW_8
	add [HERO_Y], 0x0000
	add [HERO_X], 0x0008
	mov [0x36], 0x0005
	break
	call CAPSULE_HERO_RUN_RIGHT_DRAW_9
	add [HERO_Y], 0x0000
	je [HERO_POS_MASK], 0x00, CAPSULE_HERO_RUN_RIGHT_EXIT_TO_WALK_RIGHT_LOOP
	add [HERO_X], 0x000A
	mov [0x36], 0xFFF9
	break
	jmp LABEL_93A6
LABEL_9452:
	db 0x11

LABEL_9453:
	call SET_VAR04_TO_0020
	mov [0x2A], 0x0020
	sub [HERO_X], 0x0001
	call LABEL_5BF6
	sub [HERO_X], 0x0003
	video offset=CINEMATIC_115, x=[HERO_X], y=[HERO_Y]
	sub [HERO_X], 0x0001

LABEL_946E:
	break
	je [HERO_ACTION_POS_MASK], 0x80, LABEL_949E
	call LABEL_7A29
	je [HERO_ACTION_POS_MASK], 0x00, LABEL_946E
	break
	add [HERO_X], 0x0002
	video offset=CINEMATIC_115, x=[HERO_X], y=[HERO_Y]
	add [HERO_X], 0x0002
	break
	video offset=CINEMATIC_117, x=[HERO_X], y=[HERO_Y]
	mov [0x63], 0x0001
	mov [0x0A], 0x0001
	jmp HERO_WALK_LEFT_LOOP
LABEL_949D:
	db 0x11

LABEL_949E:
	jne [0x0F], 0x00, LABEL_94D7
	sub [HERO_X], 0x0002
	video offset=CINEMATIC_116, x=[HERO_X], y=[HERO_Y]
	mov [0x21], [HERO_X]
	mov [0x27], [HERO_Y]
	sub [0x21], 0x001E
	sub [0x27], 0x0027
	call LABEL_440F
	break
	add [HERO_X], 0x0001
	video offset=CINEMATIC_115, x=[HERO_X], y=[HERO_Y]
	add [HERO_X], 0x0001
	jne [HERO_ACTION_POS_MASK], 0x80, LABEL_946E
	setup channel=0x17, address=LABEL_5338

LABEL_94D6:
	break

LABEL_94D7:
	call LABEL_7A29
	je [HERO_ACTION_POS_MASK], 0x80, LABEL_94D6
	jmp LABEL_946E
LABEL_94E3:
	db 0x11, 0x04, 0x87, 0x37, 0x00, 0x2A, 0x00, 0x20
	db 0x0A, 0x01, 0x0A, 0x00, 0x94, 0x9E, 0x00, 0x63
	db 0x00, 0x01, 0x07, 0x90, 0xE9, 0x11

LABEL_94F9:
	mov [0x63], 0x0064
	video type=0, offset=CV_52C0, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	video type=0, offset=CV_52E0, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	video type=0, offset=CV_5300, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	call SET_VAR04_TO_0024
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
	mov [0x34], 0xFFFE
	sub [HERO_X], 0x000F
	call LABEL_589E
	break
	add [HERO_X], 0x000F
	video type=0, offset=CV_53C0, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0002
	sub [HERO_X], 0x000F
	break
	add [HERO_X], 0x000F
	video type=0, offset=CV_53E0, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0007
	call SET_VAR04_TO_0020
	sub [HERO_X], 0x000C
	break
	add [HERO_X], 0x000C
	video type=0, offset=CV_5400, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0004
	sub [HERO_X], 0x0007
	break
	add [HERO_X], 0x0007
	video type=0, offset=CV_5420, x=[HERO_X], y=[HERO_Y], zoom=0x40
	play id=0x0060, freq=0x14, vol=0x40, channel=0x01
	sub [HERO_X], 0x0007
	break
	video type=0, offset=CV_5444, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	mov [0x63], 0x0001
	jmp LABEL_90F6
LABEL_959F:
	db 0x11

LABEL_95A0:
	sub [HERO_X], 0x0005
	sub [HERO_X], 0x0007
	call SET_VAR04_TO_0024
	setup channel=0x15, address=KILL_CHANNEL_LANDING
	mov [0x63], 0x0064
	break

LABEL_95B4:
	call SET_VAR04_TO_0024
	setup channel=0x15, address=KILL_CHANNEL_LANDING
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
	mov [0x34], 0xFFFB
	sub [HERO_X], 0x000F
	call LABEL_589E
	sub [HERO_X], 0x0002
	break
	add [HERO_X], 0x000F
	video type=0, offset=CV_53E0, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0007
	call SET_VAR04_TO_0020
	sub [HERO_X], 0x000C
	break
	add [HERO_X], 0x000C
	sub [HERO_X], 0x0005
	play id=0x0060, freq=0x14, vol=0x40, channel=0x01
	je [HERO_ACTION], 0x01, LABEL_9308
	add [HERO_X], 0x0005
	video type=0, offset=CV_5400, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0004
	sub [HERO_X], 0x0007
	break
	add [HERO_X], 0x0007
	video type=0, offset=CV_5420, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0007
	break
	video type=0, offset=CV_5444, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	mov [0x63], 0x0001
	jmp LABEL_90F6
LABEL_965A:
	db 0x11

LABEL_965B:
	mov [0x63], 0x0064
	video type=0, offset=CV_4D98, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	video type=0, offset=CV_4DE4, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	video type=0, offset=CV_4E30, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	call SET_VAR04_TO_0034
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
	mov [0x34], 0x0002
	add [HERO_X], 0x000F
	call LABEL_589E
	break
	sub [HERO_X], 0x000F
	video type=0, offset=CV_500C, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0002
	add [HERO_X], 0x000F
	break
	sub [HERO_X], 0x000F
	video type=0, offset=CV_5058, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0007
	call SET_VAR04_TO_0030
	add [HERO_X], 0x000C
	break
	sub [HERO_X], 0x000C
	video type=0, offset=CV_50A8, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0004
	add [HERO_X], 0x0007
	break
	sub [HERO_X], 0x0007
	play id=0x0060, freq=0x14, vol=0x40, channel=0x01
	video type=0, offset=CV_50F8, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0007
	break
	video type=0, offset=CV_514C, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	mov [0x63], 0x0002
	jmp LABEL_924E
LABEL_9701:
	db 0x11

LABEL_9702:
	add [HERO_X], 0x0005
	add [HERO_X], 0x0007
	call SET_VAR04_TO_0034
	setup channel=0x15, address=KILL_CHANNEL_LANDING
	mov [0x63], 0x0064
	break

LABEL_9716:
	call SET_VAR04_TO_0034
	setup channel=0x15, address=KILL_CHANNEL_LANDING
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
	mov [0x34], 0x0005
	add [HERO_X], 0x000F
	call LABEL_589E
	add [HERO_X], 0x0002
	break
	sub [HERO_X], 0x000F
	video type=0, offset=CV_5058, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0007
	call SET_VAR04_TO_0030
	add [HERO_X], 0x000C
	break
	sub [HERO_X], 0x000C
	add [HERO_X], 0x0005
	play id=0x0060, freq=0x14, vol=0x40, channel=0x01
	je [HERO_ACTION], 0x01, LABEL_93F6
	sub [HERO_X], 0x0005
	video type=0, offset=CV_50A8, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0004
	add [HERO_X], 0x0007
	break
	sub [HERO_X], 0x0007
	video type=0, offset=CV_50F8, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0007
	break
	video type=0, offset=CV_514C, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	mov [0x63], 0x0002
	jmp LABEL_924E
LABEL_97BC:
	db 0x11

LABEL_97BD:
	call SET_VAR04_TO_0030
	mov [0x2A], 0x0020
	call LABEL_5BF6
	add [HERO_X], 0x0004
	video type=0, offset=CV_36D2, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0001

LABEL_97D4:
	break
	je [HERO_ACTION_POS_MASK], 0x80, LABEL_9804
	call LABEL_780D
	je [HERO_ACTION_POS_MASK], 0x00, LABEL_97D4
	break
	sub [HERO_X], 0x0002
	video type=0, offset=CV_36D2, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0002
	break
	video type=0, offset=CV_15DC, x=[HERO_X], y=[HERO_Y], zoom=0x40
	mov [0x63], 0x0002
	mov [0x0A], 0x0004
	jmp HERO_WALK_RIGHT_LOOP
LABEL_9803:
	db 0x11

LABEL_9804:
	jne [0x0F], 0x00, LABEL_983D
	add [HERO_X], 0x0002
	video type=0, offset=CV_3858, x=[HERO_X], y=[HERO_Y], zoom=0x40
	mov [0x21], [HERO_X]
	mov [0x27], [HERO_Y]
	add [0x21], 0x001E
	sub [0x27], 0x0027
	call LABEL_4487
	break
	sub [HERO_X], 0x0001
	video type=0, offset=CV_36D2, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0001
	jne [HERO_ACTION_POS_MASK], 0x80, LABEL_97D4
	setup channel=0x17, address=LABEL_538C

LABEL_983C:
	break

LABEL_983D:
	call LABEL_780D
	je [HERO_ACTION_POS_MASK], 0x80, LABEL_983C
	jmp LABEL_97D4
LABEL_9849:
	db 0x11, 0x04, 0x87, 0x3C, 0x00, 0x2A, 0x00, 0x20
	db 0x04, 0x5B, 0xF6, 0x0A, 0x01, 0x0A, 0x00, 0x98
	db 0x04, 0x00, 0x63, 0x00, 0x02, 0x07, 0x92, 0x41
	db 0x11

HERO_FIRE_SHOT_ENTRY_FACING_LEFT:
	call SET_VAR04_TO_0000
	mov [0x2A], 0x0020
	jne [0x0A], 0x00, HERO_FIRE_SHOT_FACING_LEFT
	mov [0x63], 0x0001
	jmp HERO_WALK_LEFT_LOOP
LABEL_9876:
	db 0x11

HERO_FIRE_SHOT_ENTRY_FACING_RIGHT:
	call SET_VAR04_TO_0010
	mov [0x2A], 0x0020
	jne [0x0A], 0x00, HERO_FIRE_SHOT_FACING_RIGHT
	mov [0x63], 0x0002
	jmp HERO_WALK_RIGHT_LOOP
LABEL_988B:
	db 0x11

HERO_FIRE_SHOT_FACING_LEFT:
	jne [0x0F], 0x00, LABEL_98C8
	sub [HERO_X], 0x0003
	call LABEL_5BF6
	video type=0, offset=CV_3ADC, x=[HERO_X], y=[HERO_Y], zoom=0x40
	mov [0x21], [HERO_X]
	mov [0x27], [HERO_Y]
	sub [0x21], 0x001E
	sub [0x27], 0x0016
	call LABEL_440F
	break
	add [HERO_X], 0x0002
	video type=0, offset=CV_3B10, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0001
	jne [HERO_ACTION_POS_MASK], 0x84, HERO_GUN_AIM_HOLD_LEFT_LOOP
	setup channel=0x17, address=LABEL_5338

LABEL_98C7:
	break

LABEL_98C8:
	call CAPSULE_HERO_AIM_HOLD_LEFT_DRAW_LOW_CHARGE_BLINK
	je [HERO_ACTION_POS_MASK], 0x84, LABEL_98C7
	jmp HERO_GUN_AIM_HOLD_LEFT_LOOP
LABEL_98D4:
	db 0x11

LABEL_98D5:
	mov [0x2A], 0x0020
	sub [HERO_X], 0x0001
	call LABEL_5BF6
	add [HERO_X], 0x0003
	video type=0, offset=CV_17A8, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	video type=0, offset=CV_3B10, x=[HERO_X], y=[HERO_Y], zoom=0x40

HERO_GUN_AIM_HOLD_LEFT_LOOP:
	break
	je [HERO_ACTION_POS_MASK], 0x84, HERO_FIRE_SHOT_FACING_LEFT
	je [HERO_ACTION_POS_MASK], 0x86, HERO_FIRE_SHOT_FACING_LEFT
	call CAPSULE_HERO_AIM_HOLD_LEFT_DRAW_LOW_CHARGE_BLINK
	je [HERO_ACTION_POS_MASK], 0x04, HERO_GUN_AIM_HOLD_LEFT_LOOP
	break
	sub [HERO_X], 0x0002
	video type=0, offset=CV_17CC, x=[HERO_X], y=[HERO_Y], zoom=0x40
	mov [0x63], 0x0001
	mov [0x0A], 0x0003
	jmp HERO_WALK_LEFT_LOOP
LABEL_991A:
	db 0x11

HERO_GUN_RAISE_ENTRY_FACING_LEFT:
	mov [0x63], 0x0064
	call SET_VAR04_TO_0000
	jne [0x0A], 0x00, LABEL_98D5
	mov [0x63], 0x0001
	jmp HERO_WALK_LEFT_LOOP
LABEL_992F:
	db 0x11

HERO_FIRE_SHOT_FACING_RIGHT:
	jne [0x0F], 0x00, LABEL_996C
	add [HERO_X], 0x0003
	call LABEL_5BF6
	video type=0, offset=CV_389E, x=[HERO_X], y=[HERO_Y], zoom=0x40
	mov [0x21], [HERO_X]
	mov [0x27], [HERO_Y]
	add [0x21], 0x001E
	sub [0x27], 0x0016
	call LABEL_4487
	break
	sub [HERO_X], 0x0002
	video type=0, offset=CV_38D2, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0001
	jne [HERO_ACTION_POS_MASK], 0x84, HERO_GUN_AIM_HOLD_RIGHT_LOOP
	setup channel=0x17, address=LABEL_538C

LABEL_996B:
	break

LABEL_996C:
	call CAPSULE_HERO_AIM_HOLD_RIGHT_DRAW_LOW_CHARGE_BLINK
	je [HERO_ACTION_POS_MASK], 0x84, LABEL_996B
	jmp HERO_GUN_AIM_HOLD_RIGHT_LOOP
LABEL_9978:
	db 0x11

LABEL_9979:
	mov [0x2A], 0x0020
	call LABEL_5BF6
	sub [HERO_X], 0x0002
	video type=0, offset=CV_1600, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	video type=0, offset=CV_38D2, x=[HERO_X], y=[HERO_Y], zoom=0x40

HERO_GUN_AIM_HOLD_RIGHT_LOOP:
	break
	je [HERO_ACTION_POS_MASK], 0x84, HERO_FIRE_SHOT_FACING_RIGHT
	je [HERO_ACTION_POS_MASK], 0x85, HERO_FIRE_SHOT_FACING_RIGHT
	call CAPSULE_HERO_AIM_HOLD_RIGHT_DRAW_LOW_CHARGE_BLINK
	je [HERO_POS_MASK], 0x04, HERO_GUN_AIM_HOLD_RIGHT_LOOP
	break
	add [HERO_X], 0x0002
	video type=0, offset=CV_1664, x=[HERO_X], y=[HERO_Y], zoom=0x40
	mov [0x63], 0x0002
	mov [0x0A], 0x0003
	jmp HERO_WALK_RIGHT_LOOP
LABEL_99BA:
	db 0x11

HERO_GUN_RAISE_ENTRY_FACING_RIGHT:
	mov [0x63], 0x0064
	call SET_VAR04_TO_0010
	jne [0x0A], 0x00, LABEL_9979
	mov [0x63], 0x0002
	jmp HERO_WALK_RIGHT_LOOP
LABEL_99CF:
	db 0x11, 0x57, 0x04, 0xFB, 0x01, 0x02, 0x11, 0x57
	db 0x05, 0xEF, 0x01, 0x02, 0x11, 0xFF, 0xFF, 0xFF
