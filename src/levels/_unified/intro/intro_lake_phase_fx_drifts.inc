DRAW_CIN_120_LOOP_VAR03:
	video type=1, offset=CINEMATIC_120, x=[0x01], y=[0x02], zoom=0x40
	break
	jne [0x03], 0x00, DRAW_CIN_120_LOOP_VAR03
	mov [0x03], 0x00FF
	video type=1, offset=CINEMATIC_121, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_122, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_123, x=[0x01], y=[0x02], zoom=0x40
	call PLAY_FX_BY_PHASE_VAR1E
	break
	video type=1, offset=CINEMATIC_124, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_125, x=[0x01], y=[0x02], zoom=0x40
	break
	jmp DRAW_CIN_120_LOOP_VAR03
LABEL_1FD1:
	killChannel

PLAY_FX_BY_PHASE_VAR1E:
	jne [0x1E], 0x00, PLAY_FX_PHASE_1_FREQ_22
	play id=0x000B, freq=0x14, vol=0x3F, channel=0x02

PLAY_FX_PHASE_1_FREQ_22:
	jne [0x1E], 0x01, PLAY_FX_PHASE_2_FREQ_18
	play id=0x000B, freq=0x16, vol=0x3F, channel=0x02

PLAY_FX_PHASE_2_FREQ_18:
	jne [0x1E], 0x02, PLAY_FX_PHASE_3_FREQ_18
	play id=0x000B, freq=0x12, vol=0x3F, channel=0x02

PLAY_FX_PHASE_3_FREQ_18:
	jne [0x1E], 0x03, PLAY_FX_PHASE_4_FREQ_20
	play id=0x000B, freq=0x12, vol=0x3F, channel=0x02

PLAY_FX_PHASE_4_FREQ_20:
	jne [0x1E], 0x04, PLAY_FX_PHASE_5_FREQ_20
	play id=0x000B, freq=0x14, vol=0x3F, channel=0x02

PLAY_FX_PHASE_5_FREQ_20:
	jne [0x1E], 0x05, PLAY_FX_DISPATCH_RET
	play id=0x000B, freq=0x14, vol=0x3F, channel=0x02

PLAY_FX_DISPATCH_RET:
	ret

CH_01_INIT_VAR_04_06:
	mov [0x04], 0x0040
	mov [0x06], 0x000F

DRIFT_VAR4_PLUS_3_FOR_15X:
	add [0x04], 0x0003
	break
	djnz [0x06], DRIFT_VAR4_PLUS_3_FOR_15X
	mov [0x06], 0x000A

DRIFT_VAR4_PLUS_5_FOR_10X:
	add [0x04], 0x0005
	break
	djnz [0x06], DRIFT_VAR4_PLUS_5_FOR_10X
	mov [0x06], 0x0014

DRIFT_VAR4_PLUS_9_FOR_20X:
	add [0x04], 0x0009
	break
	djnz [0x06], DRIFT_VAR4_PLUS_9_FOR_20X
	setup channel=0x02, address=KILL_CHANNEL_ROUTINE
	fill page=0xFF, color=0x09
	setup channel=0x3C, address=BLIT_AND_COPY_PAGE_FF_LOOP
	break
	setPalette 0x0E
	copyVideoPage src=0x03, dst=0x00
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_126, x=160, y=100
	video type=1, offset=CINEMATIC_127, x=160, y=100
	selectVideoPage 0xFF
	fill page=0xFF, color=0x09
	break
	setup channel=0x03, address=DRAW_CIN_128_521_ZOOM_VAR04
	play id=0x0036, freq=0x14, vol=0x3F, channel=0x03
	mov [0x04], 0x0153
	mov [0x06], 0x0014

DRIFT_VAR4_MINUS_9_FOR_20X:
	sub [0x04], 0x0009
	break
	djnz [0x06], DRIFT_VAR4_MINUS_9_FOR_20X
	mov [0x06], 0x000A

DRIFT_VAR4_MINUS_5_FOR_10X:
	sub [0x04], 0x0005
	break
	djnz [0x06], DRIFT_VAR4_MINUS_5_FOR_10X
	mov [0x06], 0x0005

DRIFT_VAR4_MINUS_3_FOR_5X:
	sub [0x04], 0x0003
	break
	djnz [0x06], DRIFT_VAR4_MINUS_3_FOR_5X
	setup channel=0x01, address=KILL_CHANNEL_ROUTINE
	setup channel=0x02, address=INTRO_FILL_PAGE0_DRAW_CIN_118
	setup channel=0x03, address=DRAW_CIN_120_LOOP_VAR03
	setup channel=0x3C, address=BLIT_AND_COPY_PAGE_FF_LOOP
	setup channel=0x04, address=KILL_CHANNEL_ROUTINE
	killChannel

