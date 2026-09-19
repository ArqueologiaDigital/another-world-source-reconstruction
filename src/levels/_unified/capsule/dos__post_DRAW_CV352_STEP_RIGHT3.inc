CAPSULE_INLINE_SET_VAR63_TO_1_L2:
	call SET_VAR04_TO_0030
	mov [0x2A], 0x000F
	call LABEL_92C0
	je [HERO_POS_MASK], 0x00, LABEL_BCEB
	add [HERO_X], 0x0002
	mov [0x36], 0xFFFB
	break
	call CAPSULE_HERO_WALK_RIGHT_DRAW_1
	jne [HERO_POS_LEFT_RIGHT], 0x01, LABEL_BD4C
	je [HERO_POS_MASK], 0x00, CAPSULE_HERO_WALK_RIGHT_STOP_STRIDE1_REWIND_1
	add [HERO_X], 0x0001

LABEL_BD4C:
	add [HERO_X], 0x0001
	mov [0x36], 0xFFF9
	break
	call CAPSULE_HERO_WALK_RIGHT_DRAW_2
	jne [HERO_POS_LEFT_RIGHT], 0x01, LABEL_BD68
	je [HERO_POS_MASK], 0x00, CAPSULE_HERO_WALK_RIGHT_STOP_STRIDE1_REWIND_2
	add [HERO_X], 0x0001

LABEL_BD68:
	add [HERO_X], 0x0001
	mov [0x36], 0x0007
	break
	call CAPSULE_HERO_WALK_RIGHT_DRAW_3
	mov [0x36], 0x0005
	add [HERO_X], 0x0001
	jne [HERO_POS_LEFT_RIGHT], 0x01, LABEL_BD86
	add [HERO_X], 0x0002

LABEL_BD86:
	break
	call CAPSULE_HERO_WALK_RIGHT_DRAW_4
	add [HERO_X], 0x0001
	mov [0x36], 0x0003
	jne [HERO_POS_LEFT_RIGHT], 0x01, LABEL_BD9C
	add [HERO_X], 0x0001

LABEL_BD9C:
	break
	call CAPSULE_HERO_WALK_RIGHT_FOOTSTEP_PHASE_1
	mov [0x36], 0x0001
	jne [HERO_POS_LEFT_RIGHT], 0x01, LABEL_BDAE
	add [HERO_X], 0x0002

LABEL_BDAE:
	break
	call CAPSULE_HERO_WALK_RIGHT_DRAW_6
	mov [0x36], 0x0000
	jne [HERO_POS_LEFT_RIGHT], 0x01, LABEL_BDC0
	add [HERO_X], 0x0002

LABEL_BDC0:
	break
	je [HERO_POS_MASK], 0x09, LABEL_C29D
	call SET_VAR04_TO_0030
	call LABEL_933D
	jne [HERO_POS_MASK], 0x01, LABEL_BDC0
	add [HERO_X], 0x0002
	mov [0x36], 0xFFFD
	break
	call HERO_RUN_RIGHT_DECELERATION_LOOP
	je [HERO_POS_MASK], 0x00, LABEL_BD0A
	add [HERO_X], 0x0002
	mov [0x36], 0xFFFB
	break
	call CAPSULE_HERO_WALK_RIGHT_DRAW_9
	jne [HERO_POS_LEFT_RIGHT], 0x01, LABEL_BE01
	je [HERO_POS_MASK], 0x00, CAPSULE_HERO_WALK_RIGHT_STOP_STRIDE2_REWIND_1
	add [HERO_X], 0x0001

LABEL_BE01:
	add [HERO_X], 0x0001
	mov [0x36], 0xFFF9
	break
	call CAPSULE_HERO_WALK_RIGHT_DRAW_10
	jne [HERO_POS_LEFT_RIGHT], 0x01, LABEL_BE1D
	je [HERO_POS_MASK], 0x00, CAPSULE_HERO_WALK_RIGHT_STOP_STRIDE2_REWIND_2
	add [HERO_X], 0x0001

LABEL_BE1D:
	add [HERO_X], 0x0001
	mov [0x36], 0xFFF8
	break
	call CAPSULE_HERO_WALK_RIGHT_DRAW_11
	add [HERO_X], 0x0001
	mov [0x36], 0x0005
	jne [HERO_POS_LEFT_RIGHT], 0x01, LABEL_BE3B
	add [HERO_X], 0x0002

LABEL_BE3B:
	break
	call CAPSULE_HERO_WALK_RIGHT_DRAW_12
	add [HERO_X], 0x0001
	mov [0x36], 0x0003
	jne [HERO_POS_LEFT_RIGHT], 0x01, LABEL_BE51
	add [HERO_X], 0x0001

LABEL_BE51:
	break
	call CAPSULE_HERO_WALK_RIGHT_FOOTSTEP_PHASE_2
	mov [0x36], 0x0001
	jne [HERO_POS_LEFT_RIGHT], 0x01, LABEL_BE63
	add [HERO_X], 0x0002

LABEL_BE63:
	break
	call CAPSULE_HERO_WALK_RIGHT_DRAW_14
	jne [HERO_POS_LEFT_RIGHT], 0x01, HERO_WALK_RIGHT_LOOP
	add [HERO_X], 0x0002

HERO_WALK_RIGHT_LOOP:
	break
	je [HERO_ACTION_POS_MASK], 0x04, HERO_GUN_RAISE_ENTRY_FACING_RIGHT
	je [HERO_POS_MASK], 0x09, LABEL_C29D

LABEL_BE7E:
	call LABEL_92AC
	call SET_VAR04_TO_0030
	jne [HERO_POS_MASK], 0x01, HERO_WALK_RIGHT_LOOP
	add [HERO_X], 0x0002
	mov [0x36], 0xFFFD
	break
	jmp CAPSULE_INLINE_SET_VAR63_TO_1_L2
LABEL_BE96:
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
LABEL_BEC3:
	db 0x11

LABEL_BEC4:
	sub [HERO_X], 0x0004
	video offset=CINEMATIC_327, x=[HERO_X], y=[HERO_Y]
	add [HERO_X], 0x0001
	je [HERO_POS_MASK], 0x00, CAPSULE_HERO_RUN_LEFT_EXIT_TO_WALK_LEFT_LOOP
	break

LABEL_BED8:
	call CAPSULE_DRAW_CV_080_L0
	je [HERO_POS_MASK], 0x00, CAPSULE_HERO_RUN_LEFT_EXIT_TO_WALK_LEFT_LOOP
	break
	je [HERO_POS_MASK], 0x00, LABEL_BED8

LABEL_BEE8:
	setup channel=0x15, address=HERO_RUN_LEFT_DECELERATION_LOOP
	sub [HERO_X], 0x0004

LABEL_BEF0:
	call CAPSULE_HERO_RUN_LEFT_DRAW_0
	call SET_VAR04_TO_0020
	mov [0x2A], 0x000F
	sub [HERO_X], 0x0006
	break
	call CAPSULE_HERO_RUN_LEFT_DRAW_1
	je [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_C1D6
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

LABEL_BF38:
	mov [0x63], 0x0005
	call CAPSULE_HERO_RUN_LEFT_DRAW_5
	sub [HERO_X], 0x0006
	break
	call CAPSULE_HERO_RUN_LEFT_DRAW_6
	je [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_C1D6
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
	jmp LABEL_BEF0
LABEL_BF80:
	db 0x11

LABEL_BF81:
	break
	je [0x63], 0x06, LABEL_BF81
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
LABEL_BFAD:
	db 0x11

CAPSULE_INLINE_SET_VAR63_TO_5_L3:
	video offset=CINEMATIC_327, x=[HERO_X], y=[HERO_Y]
	add [HERO_X], 0x0003
	je [HERO_POS_MASK], 0x00, CAPSULE_HERO_RUN_RIGHT_EXIT_TO_WALK_RIGHT_LOOP
	break

LABEL_BFBE:
	call LABEL_92AC
	je [HERO_POS_MASK], 0x00, CAPSULE_HERO_RUN_RIGHT_EXIT_TO_WALK_RIGHT_LOOP
	break
	je [HERO_POS_MASK], 0x00, LABEL_BFBE

CAPSULE_INLINE_SET_VAR63_TO_5_L2:
	setup channel=0x15, address=LABEL_BF81
	add [HERO_X], 0x0004

LABEL_BFD6:
	call CAPSULE_HERO_RUN_RIGHT_FOOTSTEP_PHASE_1
	call SET_VAR04_TO_0030
	mov [0x2A], 0x000F
	add [HERO_X], 0x0006
	mov [0x36], 0xFFF4
	break
	call CAPSULE_HERO_RUN_RIGHT_DRAW_1
	je [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_C34A
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

LABEL_C026:
	mov [0x63], 0x0006
	call CAPSULE_HERO_RUN_RIGHT_FOOTSTEP_PHASE_2
	add [HERO_X], 0x0006
	mov [0x36], 0xFFF4
	break
	call CAPSULE_HERO_RUN_RIGHT_DRAW_6
	je [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_C34A
	add [HERO_Y], 0x0000
	add [HERO_X], 0x0008
	mov [0x36], 0xFFEF
	break
	call CAPSULE_DRAW_CV_297_L7
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
	jmp LABEL_BFD6
LABEL_C082:
	db 0x11

LABEL_C083:
	call SET_VAR04_TO_0020
	mov [0x2A], 0x0020
	sub [HERO_X], 0x0001
	call LABEL_7449
	sub [HERO_X], 0x0003
	video offset=CINEMATIC_328, x=[HERO_X], y=[HERO_Y]
	sub [HERO_X], 0x0001

LABEL_C09E:
	break
	je [HERO_ACTION_POS_MASK], 0x80, LABEL_C0CE
	call LABEL_9380
	je [HERO_ACTION_POS_MASK], 0x00, LABEL_C09E
	break
	add [HERO_X], 0x0002
	video offset=CINEMATIC_328, x=[HERO_X], y=[HERO_Y]
	add [HERO_X], 0x0002
	break
	video offset=CINEMATIC_330, x=[HERO_X], y=[HERO_Y]
	mov [0x63], 0x0001
	mov [0x0A], 0x0001
	jmp HERO_WALK_LEFT_LOOP
LABEL_C0CD:
	db 0x11

LABEL_C0CE:
	jne [0x0F], 0x00, LABEL_C107
	sub [HERO_X], 0x0002
	video offset=CINEMATIC_329, x=[HERO_X], y=[HERO_Y]
	mov [0x21], [HERO_X]
	mov [0x27], [HERO_Y]
	sub [0x21], 0x001E
	sub [0x27], 0x0027
	call LABEL_5B64
	break
	add [HERO_X], 0x0001
	video offset=CINEMATIC_328, x=[HERO_X], y=[HERO_Y]
	add [HERO_X], 0x0001
	jne [HERO_ACTION_POS_MASK], 0x80, LABEL_C09E
	setup channel=0x17, address=LABEL_6AB2

LABEL_C106:
	break

LABEL_C107:
	call LABEL_9380
	je [HERO_ACTION_POS_MASK], 0x80, LABEL_C106
	jmp LABEL_C09E
	killChannel
	call SET_VAR04_TO_0020
	mov [0x2A], 0x0020
	jne [0x0A], 0x00, LABEL_C0CE
	mov [0x63], 0x0001
	jmp HERO_WALK_LEFT_LOOP
LABEL_C128:
	db 0x11

LABEL_C129:
	je [HERO_POS_MASK], 0x09, LABEL_C29D
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
	call LABEL_706D
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
	jmp LABEL_BCBE
LABEL_C1D5:
	db 0x11

LABEL_C1D6:
	je [HERO_POS_MASK], 0x09, LABEL_C34A
	sub [HERO_X], 0x0005
	sub [HERO_X], 0x0007
	call SET_VAR04_TO_0024
	setup channel=0x15, address=KILL_CHANNEL_LANDING
	mov [0x63], 0x0064
	break

LABEL_C1F0:
	je [HERO_POS_MASK], 0x09, LABEL_C364
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
	call LABEL_706D
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
	je [HERO_ACTION], 0x01, LABEL_BF38
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
	jmp LABEL_BCBE
LABEL_C29C:
	db 0x11

LABEL_C29D:
	je [HERO_POS_MASK], 0x0A, LABEL_C129
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
	call LABEL_706D
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
	jmp LABEL_BE7E
LABEL_C349:
	db 0x11

LABEL_C34A:
	je [HERO_POS_MASK], 0x0A, LABEL_C1D6
	add [HERO_X], 0x0005
	add [HERO_X], 0x0007
	call SET_VAR04_TO_0034
	setup channel=0x15, address=KILL_CHANNEL_LANDING
	mov [0x63], 0x0064
	break

LABEL_C364:
	je [HERO_POS_MASK], 0x0A, LABEL_C1F0
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
	call LABEL_706D
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
	je [HERO_ACTION], 0x01, LABEL_C026
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
	jmp LABEL_BE7E
LABEL_C410:
	db 0x11

LABEL_C411:
	call SET_VAR04_TO_0030
	mov [0x2A], 0x0020
	call LABEL_7449
	add [HERO_X], 0x0004
	video type=0, offset=CV_36D2, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0001

LABEL_C428:
	break
	je [HERO_ACTION_POS_MASK], 0x80, LABEL_C458
	call LABEL_9164
	je [HERO_ACTION_POS_MASK], 0x00, LABEL_C428
	break
	sub [HERO_X], 0x0002
	video type=0, offset=CV_36D2, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0002
	break
	video type=0, offset=CV_15DC, x=[HERO_X], y=[HERO_Y], zoom=0x40
	mov [0x63], 0x0002
	mov [0x0A], 0x0004
	jmp HERO_WALK_RIGHT_LOOP
LABEL_C457:
	db 0x11

LABEL_C458:
	jne [0x0F], 0x00, LABEL_C491
	add [HERO_X], 0x0002
	video type=0, offset=CV_3858, x=[HERO_X], y=[HERO_Y], zoom=0x40
	mov [0x21], [HERO_X]
	mov [0x27], [HERO_Y]
	add [0x21], 0x001E
	sub [0x27], 0x0027
	call LABEL_5BE0
	break
	sub [HERO_X], 0x0001
	video type=0, offset=CV_36D2, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0001
	jne [HERO_ACTION_POS_MASK], 0x80, LABEL_C428
	setup channel=0x17, address=LABEL_6B1B

LABEL_C490:
	break

LABEL_C491:
	call LABEL_9164
	je [HERO_ACTION_POS_MASK], 0x80, LABEL_C490
	jmp LABEL_C428
	killChannel
	call SET_VAR04_TO_0030
	mov [0x2A], 0x0020
	call LABEL_7449
	jne [0x0A], 0x00, LABEL_C458
	mov [0x63], 0x0002
	jmp HERO_WALK_RIGHT_LOOP
LABEL_C4B5:
	db 0x11

HERO_FIRE_SHOT_ENTRY_FACING_LEFT:
	call SET_VAR04_TO_0000
	mov [0x2A], 0x0020
	jne [0x0A], 0x00, HERO_FIRE_SHOT_FACING_LEFT
	mov [0x63], 0x0001
	jmp HERO_WALK_LEFT_LOOP
LABEL_C4CA:
	db 0x11

HERO_FIRE_SHOT_ENTRY_FACING_RIGHT:
	call SET_VAR04_TO_0010
	mov [0x2A], 0x0020
	jne [0x0A], 0x00, HERO_FIRE_SHOT_FACING_RIGHT
	mov [0x63], 0x0002
	jmp HERO_WALK_RIGHT_LOOP
LABEL_C4DF:
	db 0x11

HERO_FIRE_SHOT_FACING_LEFT:
	jne [0x0F], 0x00, LABEL_C51C
	sub [HERO_X], 0x0003
	call LABEL_7449
	video type=0, offset=CV_3ADC, x=[HERO_X], y=[HERO_Y], zoom=0x40
	mov [0x21], [HERO_X]
	mov [0x27], [HERO_Y]
	sub [0x21], 0x001E
	sub [0x27], 0x0016
	call LABEL_5B64
	break
	add [HERO_X], 0x0002
	video type=0, offset=CV_3B10, x=[HERO_X], y=[HERO_Y], zoom=0x40
	add [HERO_X], 0x0001
	jne [HERO_ACTION_POS_MASK], 0x84, HERO_GUN_AIM_HOLD_LEFT_LOOP
	setup channel=0x17, address=LABEL_6AB2

LABEL_C51B:
	break

LABEL_C51C:
	call CAPSULE_HERO_AIM_HOLD_LEFT_DRAW_LOW_CHARGE_BLINK
	je [HERO_ACTION_POS_MASK], 0x84, LABEL_C51B
	jmp HERO_GUN_AIM_HOLD_LEFT_LOOP
LABEL_C528:
	db 0x11

LABEL_C529:
	mov [0x2A], 0x0020
	sub [HERO_X], 0x0001
	call LABEL_7449
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
LABEL_C56E:
	db 0x11

HERO_GUN_RAISE_ENTRY_FACING_LEFT:
	mov [0x63], 0x0064
	call SET_VAR04_TO_0000
	jne [0x0A], 0x00, LABEL_C529
	mov [0x63], 0x0001
	jmp HERO_WALK_LEFT_LOOP
LABEL_C583:
	db 0x11

HERO_FIRE_SHOT_FACING_RIGHT:
	jne [0x0F], 0x00, LABEL_C5C0
	add [HERO_X], 0x0003
	call LABEL_7449
	video type=0, offset=CV_389E, x=[HERO_X], y=[HERO_Y], zoom=0x40
	mov [0x21], [HERO_X]
	mov [0x27], [HERO_Y]
	add [0x21], 0x001E
	sub [0x27], 0x0016
	call LABEL_5BE0
	break
	sub [HERO_X], 0x0002
	video type=0, offset=CV_38D2, x=[HERO_X], y=[HERO_Y], zoom=0x40
	sub [HERO_X], 0x0001
	jne [HERO_ACTION_POS_MASK], 0x84, HERO_GUN_AIM_HOLD_RIGHT_LOOP
	setup channel=0x17, address=LABEL_6B1B

LABEL_C5BF:
	break

LABEL_C5C0:
	call CAPSULE_HERO_AIM_HOLD_RIGHT_DRAW_LOW_CHARGE_BLINK
	je [HERO_ACTION_POS_MASK], 0x84, LABEL_C5BF
	jmp HERO_GUN_AIM_HOLD_RIGHT_LOOP
LABEL_C5CC:
	db 0x11

LABEL_C5CD:
	mov [0x2A], 0x0020
	call LABEL_7449
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
LABEL_C60E:
	db 0x11

HERO_GUN_RAISE_ENTRY_FACING_RIGHT:
	mov [0x63], 0x0064
	call SET_VAR04_TO_0010
	jne [0x0A], 0x00, LABEL_C5CD
	mov [0x63], 0x0002
	jmp HERO_WALK_RIGHT_LOOP
LABEL_C623:
	db 0x11, 0x57, 0x04, 0xFB, 0x01, 0x02, 0x11, 0x57
	db 0x05, 0xEF, 0x01, 0x02, 0x11, 0xFF, 0xFF, 0xFF
