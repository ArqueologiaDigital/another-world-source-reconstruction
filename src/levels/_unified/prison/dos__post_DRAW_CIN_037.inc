LABEL_7636:
	jg [0x16], 0x01, LABEL_7640
	mov [0x16], 0x0002

LABEL_7640:
	ret

LABEL_7641:
	jg [0x16], 0x00, LABEL_764B
	mov [0x16], 0x0000

LABEL_764B:
	ret

LABEL_764C:
	jg [0x15], 0x01, LABEL_7656
	mov [0x15], 0x0002

LABEL_7656:
	jl [0x15], 0x37, LABEL_7660
	mov [0x15], 0x0037

LABEL_7660:
	ret

LABEL_7661:
	jl [0x01], 0x1B, LABEL_767F
	add [0x21], 0x0001
	jl [0x01], 0x24, LABEL_7675
	add [0x21], 0x0001

LABEL_7675:
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
	call LABEL_72D4
	video offset=CINEMATIC_035, x=[0x1a], y=[0x1b], zoom=0x40
	call LABEL_7473
	break
	play id=0x0063, freq=0x14, vol=0x0A, channel=0x01
	setup channel=0x12, address=DRAW_CIN_576_578_BLOCK
	add [0x04], 0x0016
	sub [0x06], 0x0003
	call LABEL_72D4
	video offset=CINEMATIC_035, x=[0x1a], y=[0x1b], zoom=0x40
	call LABEL_7473
	deleteChannels first=0x21, last=0x24
	break
	add [0x04], 0x0020
	play id=0x0063, freq=0x14, vol=0x40, channel=0x01
	video offset=CINEMATIC_080, x=[0x03], y=[0x04], zoom=0x40
	break
	add [0x04], 0x0016
	setPalette 0x02
	video offset=CINEMATIC_081, x=[0x03], y=[0x04], zoom=0x40
	break
	play id=0x0064, freq=0x14, vol=0x40, channel=0x02
	selectVideoPage 0x00
	video offset=CINEMATIC_082, x=[0x03], y=[0x04], zoom=0x40
	selectVideoPage 0xFF
	call LABEL_1C8E
	setup channel=0x11, address=DRAW_CIN_569_TO_572_6F_AT_F8680E45
	setup channel=0x34, address=HANG_DRAW_CIN_549
	setup channel=0x35, address=DRAW_CIN_540_543_WITH_SFX_57
	setup channel=0x15, address=SETUP_VARS_01_B0_02_B6_06_C7_28_FROM_01
	mov [PAUSE_SLICES], 0x0004
	video offset=CINEMATIC_083, x=[0x03], y=[0x04], zoom=0x40
	mov [0x1A], [0x03]
	mov [0x1B], [0x04]
	break
	video offset=CINEMATIC_084, x=[0x1a], y=[0x1b], zoom=0x40
	setup channel=0x14, address=DRAW_CIN_422_WITH_POS_STEP_AT_C7A1BFCB
	setup channel=0x22, address=LABEL_141E
	setup channel=0x23, address=INLINE_SUB_VAR08_INIT_VAR29
	setup channel=0x24, address=LABEL_1441
	setup channel=0x25, address=LABEL_25D9
	setup channel=0x26, address=LABEL_147C
	setup channel=0x27, address=KILL_CHANNEL_LANDING
	setup channel=0x28, address=LABEL_14B7
	setup channel=0x3A, address=KILL_CHANNEL_LANDING
	setup channel=0x3F, address=LABEL_8824
	call LABEL_07D8
	call LABEL_86FA
	mov [0x42], 0x00A0
	killChannel
