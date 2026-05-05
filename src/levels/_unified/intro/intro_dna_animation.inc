CINEMATIC_035		EQU 0xBC3C
CINEMATIC_036		EQU 0xBC7C
CINEMATIC_037		EQU 0xBCD0
CINEMATIC_038		EQU 0xBD24
CINEMATIC_039		EQU 0xBD68
CINEMATIC_040		EQU 0xBDB8
CINEMATIC_041		EQU 0xBDDA
CINEMATIC_042		EQU 0xBE2C
CINEMATIC_043		EQU 0xBE7E
CINEMATIC_044		EQU 0xBFAC
CINEMATIC_045		EQU 0xC04E
CINEMATIC_046		EQU 0xC08C
CINEMATIC_047		EQU 0xC156
CINEMATIC_048		EQU 0xC236
CINEMATIC_166		EQU 0xF5D8
CINEMATIC_167		EQU 0xF63E
CINEMATIC_168		EQU 0xF688
CINEMATIC_169		EQU 0xF2F6
CINEMATIC_170		EQU 0xF3B0
CINEMATIC_171		EQU 0xF3BC
CINEMATIC_453		EQU 0xF3E0
CINEMATIC_454		EQU 0xF42A
CINEMATIC_455		EQU 0xF472
CINEMATIC_456		EQU 0xF4A2
CINEMATIC_DNA_0		EQU 0xF7D8
CINEMATIC_DNA_1		EQU 0xF7EA
CINEMATIC_DNA_10		EQU 0xF894
CINEMATIC_DNA_11		EQU 0xF8A8
CINEMATIC_DNA_12		EQU 0xF8BC
CINEMATIC_DNA_13		EQU 0xF8D0
CINEMATIC_DNA_14		EQU 0xF8E2
CINEMATIC_DNA_15		EQU 0xF8F4
CINEMATIC_DNA_16		EQU 0xF906
CINEMATIC_DNA_2		EQU 0xF7FC
CINEMATIC_DNA_3		EQU 0xF810
CINEMATIC_DNA_4		EQU 0xF822
CINEMATIC_DNA_5		EQU 0xF834
CINEMATIC_DNA_6		EQU 0xF848
CINEMATIC_DNA_7		EQU 0xF85C
CINEMATIC_DNA_8		EQU 0xF870
CINEMATIC_DNA_9		EQU 0xF880

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
	video offset=CINEMATIC_DNA_0, x=[0x04], y=[0x05], zoom=[0x06]
	break
	video offset=CINEMATIC_DNA_1, x=[0x04], y=[0x05], zoom=[0x06]
	break
	video offset=CINEMATIC_DNA_2, x=[0x04], y=[0x05], zoom=[0x06]
	break
	video offset=CINEMATIC_DNA_3, x=[0x04], y=[0x05], zoom=[0x06]
	break
	video offset=CINEMATIC_DNA_4, x=[0x04], y=[0x05], zoom=[0x06]
	break
	video offset=CINEMATIC_DNA_5, x=[0x04], y=[0x05], zoom=[0x06]
	break
	video offset=CINEMATIC_DNA_6, x=[0x04], y=[0x05], zoom=[0x06]
	break
	video offset=CINEMATIC_DNA_7, x=[0x04], y=[0x05], zoom=[0x06]
	break
	video offset=CINEMATIC_DNA_8, x=[0x04], y=[0x05], zoom=[0x06]
	break
	video offset=CINEMATIC_DNA_9, x=[0x04], y=[0x05], zoom=[0x06]
	break
	video offset=CINEMATIC_DNA_10, x=[0x04], y=[0x05], zoom=[0x06]
	break
	video offset=CINEMATIC_DNA_11, x=[0x04], y=[0x05], zoom=[0x06]
	break
	video offset=CINEMATIC_DNA_12, x=[0x04], y=[0x05], zoom=[0x06]
	break
	video offset=CINEMATIC_DNA_13, x=[0x04], y=[0x05], zoom=[0x06]
	break
	video offset=CINEMATIC_DNA_14, x=[0x04], y=[0x05], zoom=[0x06]
	break
	video offset=CINEMATIC_DNA_15, x=[0x04], y=[0x05], zoom=[0x06]
	break
	video offset=CINEMATIC_DNA_16, x=[0x04], y=[0x05], zoom=[0x06]
	jmp DRAW_DNA_ANIMATION_LOOP
LABEL_0333:
	killChannel

DRAW_CINEMATICS_166_TO_171:
	video offset=CINEMATIC_166, x=160, y=100
	play id=0x002C, freq=0x0F, vol=0x3F, channel=0x02
	break
	video offset=CINEMATIC_167, x=160, y=100
	break
	video offset=CINEMATIC_168, x=160, y=100
	break
	video offset=CINEMATIC_166, x=160, y=100
	killChannel

INIT_VARS_10_11_AND_SELECT_PAGE0:
	mov [0x10], 0x00E4
	mov [0x11], 0x00E4
	selectVideoPage 0x00
	video offset=CINEMATIC_169, x=157, y=100
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
	video offset=CINEMATIC_170, x=[0x10], y=44
	video offset=CINEMATIC_171, x=[0x11], y=44
	break
	jmp DRAW_CIN_170_171_AT_VAR10_VAR11
LABEL_0390:
	killChannel

DRAW_CIN_453_454_SEQ:
	video offset=CINEMATIC_453, x=160, y=100
	break
	video offset=CINEMATIC_454, x=160, y=100
	break
	video offset=CINEMATIC_455, x=160, y=100
	break
	video offset=CINEMATIC_456, x=160, y=100
	killChannel

DRAW_CIN_035_PAL_3_REPEAT_HEAD:
	setPalette 0x03
	mov [PAUSE_SLICES], 0x0003
	video offset=CINEMATIC_035, x=160, y=100
	break
	video offset=CINEMATIC_036, x=160, y=100
	break
	video offset=CINEMATIC_037, x=160, y=100
	break
	video offset=CINEMATIC_038, x=160, y=100
	play id=0x003C, freq=0x16, vol=0x0F, channel=0x00
	break
	video offset=CINEMATIC_039, x=160, y=100
	break
	video offset=CINEMATIC_040, x=160, y=100
	break
	video offset=CINEMATIC_041, x=160, y=100
	break
	video offset=CINEMATIC_042, x=160, y=100
	break
	video offset=CINEMATIC_043, x=160, y=100
	break
	video offset=CINEMATIC_044, x=160, y=100
	break
	video offset=CINEMATIC_045, x=160, y=100
	break
	mov [PAUSE_SLICES], 0x0004
	setPalette 0x1B
	video offset=CINEMATIC_046, x=160, y=100
	break
	video offset=CINEMATIC_047, x=160, y=100
	mov [0x01], 0x000F

DRAW_CIN_048_15_FRAMES_LOOP:
	break
	video offset=CINEMATIC_048, x=160, y=100
	djnz [0x01], DRAW_CIN_048_15_FRAMES_LOOP
	setup channel=0x01, address=INTRO_FILL_AND_DRAW_CIN_103
	setup channel=0x02, address=INTRO_PLAY_FX_AND_PALETTE_4_LOOP
	setup channel=0x03, address=DRAW_CINEMATIC_053_LOOP
	setup channel=0x3C, address=BLIT_AND_COPY_PAGE_FF_LOOP
	killChannel

