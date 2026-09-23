LABEL_226B:
	break
	mov [0x69], 0x00BA
	video offset=CINEMATIC_310, x=[0x68], y=[0x69]
	djnz [0xE6], LABEL_226B
	mov [0xE6], 0x000A
	setup channel=0x03, address=KILL_CHANNEL_LANDING

CAVES_BUDDY_IDLE_HOLD_PHASE_2:
	break
	video offset=CINEMATIC_311, x=[0x68], y=[0x69]
	djnz [0xE6], CAVES_BUDDY_IDLE_HOLD_PHASE_2
	mov [0xE6], 0x0005

CAVES_BUDDY_IDLE_HOLD_PHASE_3:
	break
	video offset=CINEMATIC_312, x=[0x68], y=[0x69]
	djnz [0xE6], CAVES_BUDDY_IDLE_HOLD_PHASE_3
	mov [0xE6], 0x0006

CAVES_BUDDY_IDLE_HOLD_PHASE_4:
	break
	video offset=CINEMATIC_311, x=[0x68], y=[0x69]
	djnz [0xE6], CAVES_BUDDY_IDLE_HOLD_PHASE_4
	mov [0xE6], 0x0005

CAVES_BUDDY_IDLE_HOLD_PHASE_5:
	break
	video offset=CINEMATIC_312, x=[0x68], y=[0x69]
	djnz [0xE6], CAVES_BUDDY_IDLE_HOLD_PHASE_5
	mov [0xE6], 0x0005

CAVES_BUDDY_IDLE_HOLD_PHASE_6:
	break
	video offset=CINEMATIC_311, x=[0x68], y=[0x69]
	djnz [0xE6], CAVES_BUDDY_IDLE_HOLD_PHASE_6
	mov [0xE6], 0x0005

CAVES_BUDDY_IDLE_HOLD_PHASE_7:
	break
	video offset=CINEMATIC_313, x=[0x68], y=[0x69]
	djnz [0xE6], CAVES_BUDDY_IDLE_HOLD_PHASE_7
	mov [0xE6], 0x0005

CAVES_BUDDY_IDLE_HOLD_PHASE_8:
	break
	video offset=CINEMATIC_311, x=[0x68], y=[0x69]
	djnz [0xE6], CAVES_BUDDY_IDLE_HOLD_PHASE_8
	mov [0xE6], 0x0005

CAVES_BUDDY_IDLE_HOLD_PHASE_9:
	break
	video offset=CINEMATIC_313, x=[0x68], y=[0x69]
	djnz [0xE6], CAVES_BUDDY_IDLE_HOLD_PHASE_9
	mov [0xE6], 0x0005

LABEL_22F1:
	break
	video offset=CINEMATIC_311, x=[0x68], y=[0x69]
	djnz [0xE6], LABEL_22F1
	mov [0xE6], 0x0005
	setup channel=0x03, address=HANG_DRAW_CIN_330

CAVES_BUDDY_IDLE_HOLD_PHASE_11:
	break
	video offset=CINEMATIC_310, x=[0x68], y=[0x69]
	djnz [0xE6], CAVES_BUDDY_IDLE_HOLD_PHASE_11
	mov [0xE6], 0x0006

CAVES_BUDDY_IDLE_HOLD_PHASE_12:
	break
	video offset=CINEMATIC_314, x=[0x68], y=[0x69]
	djnz [0xE6], CAVES_BUDDY_IDLE_HOLD_PHASE_12
	mov [0xE6], 0x0005

CAVES_BUDDY_IDLE_HOLD_PHASE_13:
	break
	video offset=CINEMATIC_315, x=[0x68], y=[0x69]
	djnz [0xE6], CAVES_BUDDY_IDLE_HOLD_PHASE_13
	mov [0xE6], 0x0005

CAVES_BUDDY_IDLE_HOLD_PHASE_14:
	break
	video offset=CINEMATIC_316, x=[0x68], y=[0x69]
	djnz [0xE6], CAVES_BUDDY_IDLE_HOLD_PHASE_14
	mov [0xE6], 0x0014

LABEL_233B:
	break
	video offset=CINEMATIC_314, x=[0x68], y=[0x69]
	djnz [0xE6], LABEL_233B
	jmp INIT_VARS_E6_68_69_6B
LABEL_2348:
	db 0x11

LABEL_2349:
	break
	jmp LABEL_2349

LABEL_234D:
	jg [HERO_Y], 0x46, LABEL_237A
	jl [HERO_X], 0xC2, LABEL_237A
	jg [HERO_X], 0xD0, LABEL_2370
	mov [0x46], 0xF060
	setup channel=0x14, address=HERO_DIRECTION_STATE_FROM_INPUT
	setup channel=0x15, address=LABEL_23FC
	setup channel=0x16, address=KILL_CHANNEL_LANDING
	killChannel

LABEL_2370:
	jg [HERO_X], 0xF3, LABEL_237A
	mov [0x46], 0xF060

LABEL_237A:
	break
	jmp LABEL_234D
LABEL_237E:
	db 0x11

HERO_DIRECTION_STATE_FROM_INPUT:
	mov [0x63], 0x0000
	jne [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_238E
	mov [0x63], 0x0003

LABEL_238E:
	jne [HERO_POS_JUMP_DOWN], 0x01, LABEL_2398
	mov [0x63], 0x0004

LABEL_2398:
	jne [HERO_POS_LEFT_RIGHT], 0xFFFF, LABEL_23A3
	mov [0x63], 0x0001

LABEL_23A3:
	jne [HERO_POS_LEFT_RIGHT], 0x01, CAVES_HERO_DIRECTION_YIELD_AND_RESAMPLE
	mov [0x63], 0x0002

CAVES_HERO_DIRECTION_YIELD_AND_RESAMPLE:
	break
	jmp HERO_DIRECTION_STATE_FROM_INPUT
LABEL_23B1:
	db 0x11

LABEL_23B2:
	sub [HERO_Y], 0x0002
	video offset=CINEMATIC_658, x=[HERO_X], y=[HERO_Y]
	break
	sub [HERO_Y], 0x0001
	video offset=CINEMATIC_659, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_658, x=[HERO_X], y=[HERO_Y]
	killChannel

LABEL_23CC:
	add [HERO_Y], 0x0004
	video offset=CINEMATIC_643, x=[HERO_X], y=[HERO_Y]
	call LABEL_25C7
	break
	je [HERO_POS_JUMP_DOWN], 0x01, LABEL_23CC
	add [HERO_Y], 0x0003
	video offset=CINEMATIC_643, x=[HERO_X], y=[HERO_Y]
	call LABEL_25C7
	break
	add [HERO_Y], 0x0002
	jmp LABEL_2416
LABEL_23F3:
	db 0x54, 0x4F, 0xA2, 0x01, 0x02, 0x04, 0x25, 0xC7
	db 0x11

LABEL_23FC:
	video offset=CINEMATIC_643, x=198, y=43
	break
	video offset=CINEMATIC_643, x=198, y=44
	mov [HERO_X], 0x00C6
	mov [HERO_Y], 0x002D
	mov [0x03], 0x0001
	mov [0x19], 0x0037
	break

LABEL_2416:
	video offset=CINEMATIC_643, x=[HERO_X], y=[HERO_Y]
	call LABEL_25C7
	break
	je [0x63], 0x01, CAVES_SHAFT_DESCENT_STAGE_CASE_01
	jne [0x63], 0x02, LABEL_2432
	sub [0x03], 0x0001
	jmp CAVES_SHAFT_DESCENT_STAGE_CASE_01

LABEL_2432:
	jne [0x63], 0x03, LABEL_244A
	jl [HERO_Y], 0x14, LABEL_2416
	video offset=CINEMATIC_643, x=[HERO_X], y=[HERO_Y]
	setup channel=0x16, address=LABEL_23B2
	jmp LABEL_245C

LABEL_244A:
	jne [0x63], 0x04, LABEL_2416
	jmp LABEL_23CC
LABEL_2453:
	db 0x54, 0x51, 0xA7, 0x01, 0x02, 0x08, 0x16, 0x23
	db 0xCC

LABEL_245C:
	break
	break
	break
	break
	jmp LABEL_2416

CAVES_SHAFT_DESCENT_STAGE_CASE_01:
	jne [0x03], 0x01, CAVES_SHAFT_DESCENT_STAGE_CASE_02
	mov [0x34], 0x0000
	mov [0x35], 0x0000
	mov [0x19], 0x0037

CAVES_SHAFT_DESCENT_STAGE_CASE_02:
	jne [0x03], 0x02, CAVES_SHAFT_DESCENT_STAGE_CASE_03
	mov [0x34], 0x0003
	mov [0x35], 0x0002
	mov [0x19], 0x0037

CAVES_SHAFT_DESCENT_STAGE_CASE_03:
	jne [0x03], 0x03, CAVES_SHAFT_DESCENT_STAGE_CASE_04
	mov [0x34], 0x0002
	mov [0x35], 0x0000
	mov [0x19], 0x001E

CAVES_SHAFT_DESCENT_STAGE_CASE_04:
	jne [0x03], 0x04, CAVES_SHAFT_DESCENT_STAGE_CASE_05
	mov [0x34], 0x0002
	mov [0x35], 0xFFFF
	mov [0x19], 0x0028

CAVES_SHAFT_DESCENT_STAGE_CASE_05:
	jne [0x03], 0x05, CAVES_SHAFT_DESCENT_STAGE_CASE_06
	mov [0x34], 0xFFFC
	mov [0x35], 0x0001
	mov [0x19], 0x0030

CAVES_SHAFT_DESCENT_STAGE_CASE_06:
	jne [0x03], 0x06, LABEL_24CF
	mov [0x34], 0xFFF7
	mov [0x35], 0x0000
	mov [0x19], 0x001E

LABEL_24CF:
	video offset=CINEMATIC_643, x=[HERO_X], y=[HERO_Y]
	je [0x63], 0x02, LABEL_2551
	break
	sub [HERO_X], 0x0001
	video offset=CINEMATIC_651, x=[HERO_X], y=[HERO_Y]
	break
	add [HERO_Y], 0x0001
	sub [HERO_X], 0x0009
	video offset=CINEMATIC_652, x=[HERO_X], y=[HERO_Y]
	break
	sub [HERO_X], 0x0005
	add [HERO_X], [0x34]
	video offset=CINEMATIC_653, x=[HERO_X], y=[HERO_Y]
	break
	sub [HERO_X], 0x0008
	add [HERO_X], [0x34]
	video offset=CINEMATIC_654, x=[HERO_X], y=[HERO_Y]
	break
	sub [HERO_Y], 0x0002
	sub [HERO_X], 0x0007
	add [HERO_X], [0x34]
	video offset=CINEMATIC_655, x=[HERO_X], y=[HERO_Y]
	break
	sub [HERO_X], 0x0004
	video offset=CINEMATIC_656, x=[HERO_X], y=[HERO_Y]
	call LABEL_25C7
	break
	add [HERO_Y], 0x0002
	sub [HERO_X], 0x0001
	video offset=CINEMATIC_657, x=[HERO_X], y=[HERO_Y]
	break
	add [HERO_Y], 0x0001
	sub [HERO_X], 0x0002
	add [HERO_X], [0x35]
	video offset=CINEMATIC_643, x=[HERO_X], y=[HERO_Y]
	break
	add [0x03], 0x0001
	jmp LABEL_2416

LABEL_2551:
	break
	add [HERO_X], 0x0001
	video offset=CINEMATIC_644, x=[HERO_X], y=[HERO_Y]
	call LABEL_25C7
	break
	add [HERO_Y], 0x0001
	add [HERO_X], 0x0009
	video offset=CINEMATIC_645, x=[HERO_X], y=[HERO_Y]
	break
	add [HERO_X], 0x0005
	sub [HERO_X], [0x34]
	video offset=CINEMATIC_646, x=[HERO_X], y=[HERO_Y]
	break
	add [HERO_X], 0x0008
	sub [HERO_X], [0x34]
	video offset=CINEMATIC_647, x=[HERO_X], y=[HERO_Y]
	call LABEL_25C7
	break
	sub [HERO_Y], 0x0002
	add [HERO_X], 0x0007
	sub [HERO_X], [0x34]
	video offset=CINEMATIC_648, x=[HERO_X], y=[HERO_Y]
	break
	add [HERO_X], 0x0004
	video offset=CINEMATIC_649, x=[HERO_X], y=[HERO_Y]
	break
	add [HERO_Y], 0x0002
	add [HERO_X], 0x0001
	video offset=CINEMATIC_650, x=[HERO_X], y=[HERO_Y]
	break
	add [HERO_Y], 0x0001
	add [HERO_X], 0x0002
	sub [HERO_X], [0x35]
	video offset=CINEMATIC_643, x=[HERO_X], y=[HERO_Y]
	break
	jmp LABEL_2416

LABEL_25C7:
	je [0x03], 0x00, LABEL_25D4
	jg [HERO_Y], [0x19], CAVES_SCREEN_STEP_UP_ONE_ROW_L3
	ret


LABEL_25D4:
	setup channel=0x14, address=CAVES_INLINE_SET_VAR63_TO_1_L2
	setup channel=0x15, address=KILL_CHANNEL_LANDING
	setup channel=0x16, address=LABEL_DF3B
	call SET_VAR04_TO_0020
	add [HERO_X], 0x0005
	mov [0x03], 0x0000
	mov [0x34], 0x0005
	mov [0x35], 0x0000
	call CAVES_SCREEN_STEP_UP_ONE_ROW_L4
	ret


CAVES_SCREEN_STEP_UP_ONE_ROW_L3:
	setup channel=0x14, address=CAVES_INLINE_SET_VAR63_TO_1_L2
	setup channel=0x15, address=KILL_CHANNEL_LANDING
	setup channel=0x16, address=LABEL_DF3B
	call SET_VAR04_TO_0020
	mov [0x2E], [HERO_X]
	mov [0x03], 0x0000
	mov [0x34], 0x0000
	mov [0x35], 0x0000
	call CAVES_SCREEN_STEP_UP_ONE_ROW_L4
	mov [HERO_X], [0x2E]
	add [HERO_X], 0x0005
	add [HERO_Y], 0x001E
	ret


LABEL_2624:
	db 0x00, 0xEA, 0x00, 0x0A, 0xC9, 0xD3, 0xA0, 0x64
	db 0x06, 0x09, 0xEA, 0x26, 0x28, 0xC9, 0xB1, 0xA0
	db 0x64, 0xC9, 0xD9, 0xA0, 0x64, 0x06, 0xC9, 0xD9
	db 0xA0, 0x64, 0x06, 0x07, 0x26, 0x3A, 0x11

LABEL_2643:
	mov [0xF8], [0x04]
	and [0xF8], 0x0010
	setup channel=0x01, address=LABEL_2F51
	mov [HERO_Y], 0x0056
	jne [SCREEN_NUM], 0x6F, LABEL_266A
	setup channel=0x01, address=LABEL_2F29
	mov [HERO_Y], 0x0086
	jg [HERO_X], 0x50, LABEL_266A
	mov [HERO_X], 0x0050

LABEL_266A:
	jne [0xF8], 0x00, LABEL_268C
	video offset=CINEMATIC_169, x=[HERO_X], y=[HERO_Y]
	break
	add [HERO_Y], 0x000C
	video offset=CINEMATIC_169, x=[HERO_X], y=[HERO_Y]
	break
	add [HERO_Y], 0x000D
	video offset=CINEMATIC_169, x=[HERO_X], y=[HERO_Y]
	jmp CAVES_HERO_FALL_LANDING_AND_SCENE_RESET

LABEL_268C:
	video offset=CINEMATIC_167, x=[HERO_X], y=[HERO_Y]
	break
	add [HERO_Y], 0x000C
	video offset=CINEMATIC_167, x=[HERO_X], y=[HERO_Y]
	break
	add [HERO_Y], 0x000D
	video offset=CINEMATIC_167, x=[HERO_X], y=[HERO_Y]

CAVES_HERO_FALL_LANDING_AND_SCENE_RESET:
	break
	sub [HERO_Y], 0x0018
	video offset=CINEMATIC_CAVES_HERO_IDLE_DOWN_0, x=[HERO_X], y=[HERO_Y]
	break
	sub [HERO_Y], 0x0002
	video offset=CINEMATIC_CAVES_HERO_IDLE_DOWN_0, x=[HERO_X], y=[HERO_Y]
	mov [0x2A], 0x0005
	call LABEL_D95F
	setup channel=0x14, address=LABEL_DBA5
	call SET_VAR18_TO_0122
	mov [0x19], 0x0000
	mov [0x2A], 0x0000
	mov [0x34], 0x0000
	mov [0x35], 0x0000
	mov [0x05], 0x0003
	mov [HERO_Y], 0x0054
	jne [SCREEN_NUM], 0x6F, LABEL_26E9
	mov [HERO_Y], 0x0084

LABEL_26E9:
	break
	jmp HERO_DIRECTION_DOWN_IDLE_LOOP
LABEL_26ED:
	db 0x11

CAVES_HERO_LANDING_SPLASH:
	video offset=CINEMATIC_CAVES_LANDING_SPLASH_F0, x=[HERO_X], y=[0x1a]
	break
	video offset=CINEMATIC_CAVES_LANDING_SPLASH_F1, x=[HERO_X], y=[0x1a]
	play id=0x0074, freq=0x14, vol=0x40, channel=0x00
	break
	video offset=CINEMATIC_CAVES_LANDING_SPLASH_F2, x=[HERO_X], y=[0x1a]
	play id=0x006C, freq=0x14, vol=0x40, channel=0x01
	break
	video offset=CINEMATIC_CAVES_LANDING_SPLASH_F3, x=[HERO_X], y=[0x1a]
	break
	video offset=CINEMATIC_CAVES_LANDING_SPLASH_F4, x=[HERO_X], y=[0x1a]
	break
	play id=0x006C, freq=0x14, vol=0x40, channel=0x02
	video offset=CINEMATIC_CAVES_LANDING_SPLASH_F5, x=[HERO_X], y=[0x1a]
	break
	video offset=CINEMATIC_CAVES_LANDING_SPLASH_F6, x=[HERO_X], y=[0x1a]
	break
	video offset=CINEMATIC_CAVES_LANDING_SPLASH_F7, x=[HERO_X], y=[0x1a]
	break
	video offset=CINEMATIC_CAVES_LANDING_SPLASH_F8, x=[HERO_X], y=[0x1a]
	break
	play id=0x006C, freq=0x14, vol=0x20, channel=0x01
	video offset=CINEMATIC_CAVES_LANDING_SPLASH_F9, x=[HERO_X], y=[0x1a]
	break
	mov [PAUSE_SLICES], 0x0008
	killChannel
