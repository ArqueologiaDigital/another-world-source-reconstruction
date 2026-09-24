PRISON_CAGE_SWING_STEP_MIN_TWO:
	jg [0x16], 0x01, PRISON_CAGE_SWING_STEP_MIN_TWO_RET
	mov [0x16], 0x0002

PRISON_CAGE_SWING_STEP_MIN_TWO_RET:
	ret


PRISON_CAGE_SWING_STEP_NO_REVERSE:
	jg [0x16], 0x00, PRISON_CAGE_SWING_STEP_NO_REVERSE_RET
	mov [0x16], 0x0000

PRISON_CAGE_SWING_STEP_NO_REVERSE_RET:
	ret


PRISON_CAGE_SWING_AMPLITUDE_MIN_TWO:
	jg [0x15], 0x01, LABEL_7656
	mov [0x15], 0x0002

LABEL_7656:
	jl [0x15], 0x37, LABEL_7660
	mov [0x15], 0x0037

LABEL_7660:
	ret


LABEL_7661:
	jl [HERO_X], 0x1B, LABEL_767F
	add [0x21], 0x0001
	jl [HERO_X], 0x24, PRISON_CAGE_VIEW_OFFSET_CLAMP_AT_ZERO
	add [0x21], 0x0001

PRISON_CAGE_VIEW_OFFSET_CLAMP_AT_ZERO:
	jl [0x21], 0x00, LABEL_767F
	mov [0x21], 0x0000

LABEL_767F:
	ret


LABEL_7680:
	setup channel=0x14, address=LABEL_7685
	killChannel

LABEL_7685:
	mov [0x03], 0x00B5
	mov [0x04], 0x003C
	sub [0x04], 0x0006
	add [0x04], 0x0010
	sub [0x06], 0x0003
	call PRISON_CAGE_SWING_TILT_OFFSET_DISPATCH
	video offset=CINEMATIC_PRISON_CAGE_BUDDY_SEATED, x=[0x1a], y=[0x1b]
	call LABEL_7473
	break
	play id=0x0063, freq=0x14, vol=0x0A, channel=0x01
	setup channel=0x12, address=DRAW_CIN_576_578_BLOCK
	add [0x04], 0x0016
	sub [0x06], 0x0003
	call PRISON_CAGE_SWING_TILT_OFFSET_DISPATCH
	video offset=CINEMATIC_PRISON_CAGE_BUDDY_SEATED, x=[0x1a], y=[0x1b]
	call LABEL_7473
	deleteChannels first=0x21, last=0x24
	break
	add [0x04], 0x0020
	play id=0x0063, freq=0x14, vol=0x40, channel=0x01
	video offset=CINEMATIC_PRISON_CAGE_LANDING_F0, x=[0x03], y=[0x04]
	break
	add [0x04], 0x0016
	setPalette 0x02
	video offset=CINEMATIC_PRISON_CAGE_LANDING_F1, x=[0x03], y=[0x04]
	break
	play id=0x0064, freq=0x14, vol=0x40, channel=0x02
	selectVideoPage 0x00
	video offset=CINEMATIC_PRISON_CAGE_LANDING_F2, x=[0x03], y=[0x04]
	selectVideoPage 0xFF
	call LABEL_1C8E
	setup channel=0x11, address=DRAW_CIN_569_TO_572_6F_AT_F8680E45
	setup channel=0x34, address=HANG_DRAW_CIN_549
	setup channel=0x35, address=DRAW_CIN_540_543_WITH_SFX_57
	setup channel=0x15, address=SETUP_VARS_01_B0_02_B6_06_C7_28_FROM_01
	mov [PAUSE_SLICES], 0x0004
	video offset=CINEMATIC_PRISON_CAGE_LANDING_F3, x=[0x03], y=[0x04]
	mov [0x1A], [0x03]
	mov [0x1B], [0x04]
	break
	video offset=CINEMATIC_PRISON_CAGE_LANDING_F4, x=[0x1a], y=[0x1b]
	setup channel=0x14, address=DRAW_CIN_422_WITH_POS_STEP_AT_C7A1BFCB
	setup channel=0x22, address=PRISON_ACTOR_CONTEXT_LOAD_SLOT0_LOOP
	setup channel=0x23, address=INLINE_SUB_VAR08_INIT_VAR29
	setup channel=0x24, address=PRISON_ACTOR_CONTEXT_ROTATE_INTO_SLOT1_LOOP
	setup channel=0x25, address=LABEL_25D9
	setup channel=0x26, address=PRISON_ACTOR_CONTEXT_ROTATE_INTO_SLOT2_LOOP
	setup channel=0x27, address=KILL_CHANNEL_LANDING
	setup channel=0x28, address=PRISON_ACTOR_CONTEXT_COMMIT_SLOT2_LOOP
	setup channel=0x3A, address=KILL_CHANNEL_LANDING
	setup channel=0x3F, address=LABEL_8824
	call LABEL_07D8
	call PRISON_SCREEN_ENTRY_DISPATCH
	mov [0x42], 0x00A0
	killChannel
