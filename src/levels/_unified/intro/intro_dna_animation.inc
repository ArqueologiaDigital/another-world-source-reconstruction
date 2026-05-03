SETUP_INTRO_DNA_CHANNELS:
	setup channel=0x0A, address=DNA_VAR_05_HOLD_LOOP
	setup channel=0x0B, address=DRAW_DNA_ANIMATION_LOOP
	break
	break
	break
	setup channel=0x0C, address=DNA_VAR_05_DRIFT_LOOP
	setup channel=0x0D, address=DRAW_DNA_ANIMATION_LOOP
	break
	break
	break
	setup channel=0x0E, address=DNA_VAR_05_DRIFT_LOOP
	setup channel=0x0F, address=DRAW_DNA_ANIMATION_LOOP
	break
	break
	break
	setup channel=0x10, address=DNA_VAR_05_DRIFT_LOOP
	setup channel=0x11, address=DRAW_DNA_ANIMATION_LOOP
	break
	break
	break
	setup channel=0x12, address=DNA_VAR_05_DRIFT_LOOP
	setup channel=0x13, address=DRAW_DNA_ANIMATION_LOOP
	break
	break
	break
	setup channel=0x14, address=DNA_VAR_05_DRIFT_LOOP
	setup channel=0x15, address=DRAW_DNA_ANIMATION_LOOP
	break
	break
	break
	setup channel=0x16, address=DNA_VAR_05_DRIFT_LOOP
	setup channel=0x17, address=DRAW_DNA_ANIMATION_LOOP
	break
	break
	break
	setup channel=0x18, address=DNA_VAR_05_DRIFT_LOOP
	setup channel=0x19, address=DRAW_DNA_ANIMATION_LOOP
	break
	break
	break
	setup channel=0x1A, address=DNA_VAR_05_DRIFT_LOOP
	setup channel=0x1B, address=DRAW_DNA_ANIMATION_LOOP
	break
	break
	break
	setup channel=0x1C, address=DNA_VAR_05_DRIFT_LOOP
	setup channel=0x1D, address=DRAW_DNA_ANIMATION_LOOP
	break
	break
	break
	setup channel=0x1E, address=DNA_VAR_05_DRIFT_LOOP
	setup channel=0x1F, address=DRAW_DNA_ANIMATION_LOOP
	killChannel

DELETE_CHANNELS_0A_TO_1F:
	deleteChannels first=0x0A, last=0x1F
	killChannel

DNA_VAR_05_HOLD_LOOP:
	mov [0x05], 0x002A
	break
	jmp DNA_VAR_05_HOLD_LOOP
LABEL_02AF:
	killChannel

DNA_VAR_05_DRIFT_LOOP:
	add [0x05], 0x000A
	break
	jmp DNA_VAR_05_DRIFT_LOOP
LABEL_02B8:
	killChannel

DRAW_DNA_ANIMATION_LOOP:
	break
	video type=1, offset=CINEMATIC_DNA_0, x=[0x04], y=[0x05], zoom=[0x06]
	break
	video type=1, offset=CINEMATIC_DNA_1, x=[0x04], y=[0x05], zoom=[0x06]
	break
	video type=1, offset=CINEMATIC_DNA_2, x=[0x04], y=[0x05], zoom=[0x06]
	break
	video type=1, offset=CINEMATIC_DNA_3, x=[0x04], y=[0x05], zoom=[0x06]
	break
	video type=1, offset=CINEMATIC_DNA_4, x=[0x04], y=[0x05], zoom=[0x06]
	break
	video type=1, offset=CINEMATIC_DNA_5, x=[0x04], y=[0x05], zoom=[0x06]
	break
	video type=1, offset=CINEMATIC_DNA_6, x=[0x04], y=[0x05], zoom=[0x06]
	break
	video type=1, offset=CINEMATIC_DNA_7, x=[0x04], y=[0x05], zoom=[0x06]
	break
	video type=1, offset=CINEMATIC_DNA_8, x=[0x04], y=[0x05], zoom=[0x06]
	break
	video type=1, offset=CINEMATIC_DNA_9, x=[0x04], y=[0x05], zoom=[0x06]
	break
	video type=1, offset=CINEMATIC_DNA_10, x=[0x04], y=[0x05], zoom=[0x06]
	break
	video type=1, offset=CINEMATIC_DNA_11, x=[0x04], y=[0x05], zoom=[0x06]
	break
	video type=1, offset=CINEMATIC_DNA_12, x=[0x04], y=[0x05], zoom=[0x06]
	break
	video type=1, offset=CINEMATIC_DNA_13, x=[0x04], y=[0x05], zoom=[0x06]
	break
	video type=1, offset=CINEMATIC_DNA_14, x=[0x04], y=[0x05], zoom=[0x06]
	break
	video type=1, offset=CINEMATIC_DNA_15, x=[0x04], y=[0x05], zoom=[0x06]
	break
	video type=1, offset=CINEMATIC_DNA_16, x=[0x04], y=[0x05], zoom=[0x06]
	jmp DRAW_DNA_ANIMATION_LOOP
LABEL_0333:
	killChannel

DRAW_CINEMATICS_166_TO_171:
	video type=1, offset=CINEMATIC_166, x=160, y=100
	play id=0x002C, freq=0x0F, vol=0x3F, channel=0x02
	break
	video type=1, offset=CINEMATIC_167, x=160, y=100
	break
	video type=1, offset=CINEMATIC_168, x=160, y=100
	break
	video type=1, offset=CINEMATIC_166, x=160, y=100
	killChannel

INIT_VARS_10_11_AND_SELECT_PAGE0:
	mov [0x10], 0x00E4
	mov [0x11], 0x00E4
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_169, x=157, y=100
	selectVideoPage 0xFF
	mov [0x0F], 0x001E

WAIT_VAR_0F_30_TICKS:
	break
	djnz [0x0F], WAIT_VAR_0F_30_TICKS
	setup channel=0x3C, address=BLIT_AND_DISPATCH_VAR3
	mov [0x0F], 0x000A

DRIFT_VAR_10_INC_BY_1_LOOP:
	add [0x10], 0x0001
	break
	sub [0x11], 0x0001
	break
	djnz [0x0F], DRIFT_VAR_10_INC_BY_1_LOOP
	setup channel=0x3C, address=BLIT_AND_COPY_PAGE_FF_LOOP
	killChannel

DRAW_CIN_170_171_AT_VAR10_VAR11:
	video type=1, offset=CINEMATIC_170, x=[0x10], y=44, zoom=0x40
	video type=1, offset=CINEMATIC_171, x=[0x11], y=44, zoom=0x40
	break
	jmp DRAW_CIN_170_171_AT_VAR10_VAR11
LABEL_0390:
	killChannel

DRAW_CIN_453_454_SEQ:
	video type=1, offset=CINEMATIC_453, x=160, y=100
	break
	video type=1, offset=CINEMATIC_454, x=160, y=100
	break
	video type=1, offset=CINEMATIC_455, x=160, y=100
	break
	video type=1, offset=CINEMATIC_456, x=160, y=100
	killChannel

LABEL_03A5:
	setPalette 0x03
	mov [PAUSE_SLICES], 0x0003
	video type=1, offset=CINEMATIC_035, x=160, y=100
	break
	video type=1, offset=CINEMATIC_036, x=160, y=100
	break
	video type=1, offset=CINEMATIC_037, x=160, y=100
	break
	video type=1, offset=CINEMATIC_038, x=160, y=100
	play id=0x003C, freq=0x16, vol=0x0F, channel=0x00
	break
	video type=1, offset=CINEMATIC_039, x=160, y=100
	break
	video type=1, offset=CINEMATIC_040, x=160, y=100
	break
	video type=1, offset=CINEMATIC_041, x=160, y=100
	break
	video type=1, offset=CINEMATIC_042, x=160, y=100
	break
	video type=1, offset=CINEMATIC_043, x=160, y=100
	break
	video type=1, offset=CINEMATIC_044, x=160, y=100
	break
	video type=1, offset=CINEMATIC_045, x=160, y=100
	break
	mov [PAUSE_SLICES], 0x0004
	setPalette 0x1B
	video type=1, offset=CINEMATIC_046, x=160, y=100
	break
	video type=1, offset=CINEMATIC_047, x=160, y=100
	mov [0x01], 0x000F

LABEL_03FD:
	break
	video type=1, offset=CINEMATIC_048, x=160, y=100
	djnz [0x01], LABEL_03FD
	setup channel=0x01, address=INTRO_FILL_AND_DRAW_CIN_103
	setup channel=0x02, address=INTRO_PLAY_FX_AND_PALETTE_4_LOOP
	setup channel=0x03, address=DRAW_CINEMATIC_053_LOOP
	setup channel=0x3C, address=BLIT_AND_COPY_PAGE_FF_LOOP
	killChannel

