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
	jg [0x15], 0x01, LABEL_75A9
	mov [0x15], 0x0002

LABEL_75A9:
	jl [0x15], 0x37, LABEL_75B3
	mov [0x15], 0x0037

LABEL_75B3:
	ret


LABEL_75B4:
	jl [HERO_X], 0x1B, LABEL_75D2
	add [0x21], 0x0001
	jl [HERO_X], 0x24, PRISON_CAGE_VIEW_OFFSET_CLAMP_AT_ZERO
	add [0x21], 0x0001

PRISON_CAGE_VIEW_OFFSET_CLAMP_AT_ZERO:
	jl [0x21], 0x00, LABEL_75D2
	mov [0x21], 0x0000

LABEL_75D2:
	ret


LABEL_75D3:
	setup channel=0x14, address=LABEL_75D8
	killChannel

LABEL_75D8:
	mov [0x03], 0x00B5
	mov [0x04], 0x003C
	sub [0x04], 0x0006
	add [0x04], 0x0010
	sub [0x06], 0x0003
	call PRISON_CAGE_SWING_TILT_OFFSET_DISPATCH
	video offset=CINEMATIC_035, x=[0x1a], y=[0x1b]
	call LABEL_73C6
	break
	play id=0x0063, freq=0x14, vol=0x0A, channel=0x01
	setup channel=0x12, address=DRAW_CIN_576_578_BLOCK
	add [0x04], 0x0016
	sub [0x06], 0x0003
	call PRISON_CAGE_SWING_TILT_OFFSET_DISPATCH
	video offset=CINEMATIC_035, x=[0x1a], y=[0x1b]
	call LABEL_73C6
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
	call LABEL_1C96
	setup channel=0x11, address=DRAW_CIN_569_TO_572_6F_AT_F8680E45
	setup channel=0x34, address=HANG_DRAW_CIN_549
	setup channel=0x35, address=DRAW_CIN_540_543_WITH_SFX_57
	setup channel=0x15, address=SETUP_VARS_01_B0_02_B6_06_C7_28_FROM_01
	video offset=CINEMATIC_PRISON_CAGE_LANDING_F3, x=[0x03], y=[0x04]
	mov [0x1A], [0x03]
	mov [0x1B], [0x04]
	break
	video offset=CINEMATIC_PRISON_CAGE_LANDING_F4, x=[0x1a], y=[0x1b]
	setup channel=0x14, address=DRAW_CIN_422_WITH_POS_STEP_AT_C7A1BFCB
	setup channel=0x22, address=PRISON_ACTOR_CONTEXT_LOAD_SLOT0_LOOP
	setup channel=0x23, address=INLINE_SUB_VAR08_INIT_VAR29
	setup channel=0x24, address=PRISON_ACTOR_CONTEXT_ROTATE_INTO_SLOT1_LOOP
	setup channel=0x25, address=LABEL_25A5
	setup channel=0x26, address=PRISON_ACTOR_CONTEXT_ROTATE_INTO_SLOT2_LOOP
	setup channel=0x27, address=KILL_CHANNEL_LANDING
	setup channel=0x28, address=PRISON_ACTOR_CONTEXT_COMMIT_SLOT2_LOOP
	setup channel=0x3A, address=KILL_CHANNEL_LANDING
	setup channel=0x3F, address=LABEL_871B
	call LABEL_07FC
	call PRISON_SCREEN_ENTRY_DISPATCH
	mov [0x42], 0x00A0
	killChannel
