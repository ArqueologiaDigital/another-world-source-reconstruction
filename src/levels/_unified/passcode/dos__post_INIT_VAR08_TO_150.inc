SCALE_VAR07_TIMES_9_PLUS_4A:
	shl [0x07], 0x0003
	mov [0xF8], [0x07]
	add [0x07], [0xF8]
	add [0x07], 0x004A
	je [0xDB], 0x00, SHARED_RET
	add [0x07], 0x0004
	ret

DRAW_LETTER_2_DISPATCH_BY_X:
	je [0x07], 0xC4, DRAW_LETTER_2_AT_X24
	je [0x07], 0xCC, DRAW_LETTER_2_AT_X25
	je [0x07], 0xD4, DRAW_LETTER_2_AT_X26
	jne [0x07], 0xBC, SHARED_RET
	jne [0x06], 0x0B, DRAW_LETTER_3_AT_X23
	text id=0x012E, x=23, y=80, color=0x04 ; "2"
	ret

DRAW_LETTER_3_AT_X23:
	jne [0x06], 0x0C, DRAW_LETTER_4_AT_X23
	text id=0x012F, x=23, y=80, color=0x04 ; "3"
	ret

DRAW_LETTER_4_AT_X23:
	jne [0x06], 0x0D, DRAW_LETTER_5_AT_X23
	text id=0x0130, x=23, y=80, color=0x04 ; "4"
	ret

DRAW_LETTER_5_AT_X23:
	jne [0x06], 0x0F, DRAW_LETTER_6_AT_X23
	text id=0x0131, x=23, y=80, color=0x04 ; "5"
	ret

DRAW_LETTER_6_AT_X23:
	jne [0x06], 0x10, DRAW_LETTER_7_AT_X23
	text id=0x0132, x=23, y=80, color=0x04 ; "6"
	ret

DRAW_LETTER_7_AT_X23:
	jne [0x06], 0x11, DRAW_LETTER_8_AT_X23
	text id=0x0133, x=23, y=80, color=0x04 ; "7"
	ret

DRAW_LETTER_8_AT_X23:
	jne [0x06], 0x13, DRAW_LETTER_9_AT_X23
	text id=0x0134, x=23, y=80, color=0x04 ; "8"
	ret

DRAW_LETTER_9_AT_X23:
	jne [0x06], 0x14, DRAW_LETTER_A_AT_X23
	text id=0x0135, x=23, y=80, color=0x04 ; "9"
	ret

DRAW_LETTER_A_AT_X23:
	jne [0x06], 0x15, DRAW_LETTER_B_AT_X23
	text id=0x0136, x=23, y=80, color=0x04 ; "A"
	ret

DRAW_LETTER_B_AT_X23:
	jne [0x06], 0x1B, DRAW_LETTER_C_AT_X23__DOS__POST_INIT_VAR08_TO_150
	text id=0x0137, x=23, y=80, color=0x04 ; "B"
	ret

DRAW_LETTER_C_AT_X23__DOS__POST_INIT_VAR08_TO_150:
	jne [0x06], 0x21, DRAW_LETTER_D_AT_X23__DOS__POST_INIT_VAR08_TO_150
	text id=0x0138, x=23, y=80, color=0x04 ; "C"
	ret

DRAW_LETTER_D_AT_X23__DOS__POST_INIT_VAR08_TO_150:
	jne [0x06], 0x1D, SHARED_RET
	text id=0x0139, x=23, y=80, color=0x04 ; "D"
	ret

DRAW_LETTER_2_AT_X24:
	jne [0x06], 0x0B, DRAW_LETTER_3_AT_X24
	text id=0x012E, x=24, y=80, color=0x04 ; "2"
	ret

DRAW_LETTER_3_AT_X24:
	jne [0x06], 0x0C, DRAW_LETTER_4_AT_X24
	text id=0x012F, x=24, y=80, color=0x04 ; "3"
	ret

DRAW_LETTER_4_AT_X24:
	jne [0x06], 0x0D, DRAW_LETTER_5_AT_X24
	text id=0x0130, x=24, y=80, color=0x04 ; "4"
	ret

DRAW_LETTER_5_AT_X24:
	jne [0x06], 0x0F, DRAW_LETTER_6_AT_X24
	text id=0x0131, x=24, y=80, color=0x04 ; "5"
	ret

DRAW_LETTER_6_AT_X24:
	jne [0x06], 0x10, DRAW_LETTER_7_AT_X24
	text id=0x0132, x=24, y=80, color=0x04 ; "6"
	ret

DRAW_LETTER_7_AT_X24:
	jne [0x06], 0x11, DRAW_LETTER_8_AT_X24
	text id=0x0133, x=24, y=80, color=0x04 ; "7"
	ret

DRAW_LETTER_8_AT_X24:
	jne [0x06], 0x13, DRAW_LETTER_9_AT_X24
	text id=0x0134, x=24, y=80, color=0x04 ; "8"
	ret

DRAW_LETTER_9_AT_X24:
	jne [0x06], 0x14, DRAW_LETTER_A_AT_X24
	text id=0x0135, x=24, y=80, color=0x04 ; "9"
	ret

DRAW_LETTER_A_AT_X24:
	jne [0x06], 0x15, DRAW_LETTER_B_AT_X24
	text id=0x0136, x=24, y=80, color=0x04 ; "A"
	ret

DRAW_LETTER_B_AT_X24:
	jne [0x06], 0x1B, DRAW_LETTER_C_AT_X24__DOS__POST_INIT_VAR08_TO_150
	text id=0x0137, x=24, y=80, color=0x04 ; "B"
	ret

DRAW_LETTER_C_AT_X24__DOS__POST_INIT_VAR08_TO_150:
	jne [0x06], 0x21, DRAW_LETTER_D_AT_X24__DOS__POST_INIT_VAR08_TO_150
	text id=0x0138, x=24, y=80, color=0x04 ; "C"
	ret

DRAW_LETTER_D_AT_X24__DOS__POST_INIT_VAR08_TO_150:
	jne [0x06], 0x1D, SHARED_RET
	text id=0x0139, x=24, y=80, color=0x04 ; "D"
	ret

DRAW_LETTER_2_AT_X25:
	jne [0x06], 0x0B, DRAW_LETTER_3_AT_X25
	text id=0x012E, x=25, y=80, color=0x04 ; "2"
	ret

DRAW_LETTER_3_AT_X25:
	jne [0x06], 0x0C, DRAW_LETTER_4_AT_X25
	text id=0x012F, x=25, y=80, color=0x04 ; "3"
	ret

DRAW_LETTER_4_AT_X25:
	jne [0x06], 0x0D, DRAW_LETTER_5_AT_X25
	text id=0x0130, x=25, y=80, color=0x04 ; "4"
	ret

DRAW_LETTER_5_AT_X25:
	jne [0x06], 0x0F, DRAW_LETTER_6_AT_X25
	text id=0x0131, x=25, y=80, color=0x04 ; "5"
	ret

DRAW_LETTER_6_AT_X25:
	jne [0x06], 0x10, DRAW_LETTER_7_AT_X25
	text id=0x0132, x=25, y=80, color=0x04 ; "6"
	ret

DRAW_LETTER_7_AT_X25:
	jne [0x06], 0x11, DRAW_LETTER_8_AT_X25
	text id=0x0133, x=25, y=80, color=0x04 ; "7"
	ret

DRAW_LETTER_8_AT_X25:
	jne [0x06], 0x13, DRAW_LETTER_9_AT_X25
	text id=0x0134, x=25, y=80, color=0x04 ; "8"
	ret

DRAW_LETTER_9_AT_X25:
	jne [0x06], 0x14, DRAW_LETTER_A_AT_X25
	text id=0x0135, x=25, y=80, color=0x04 ; "9"
	ret

DRAW_LETTER_A_AT_X25:
	jne [0x06], 0x15, DRAW_LETTER_B_AT_X25
	text id=0x0136, x=25, y=80, color=0x04 ; "A"
	ret

DRAW_LETTER_B_AT_X25:
	jne [0x06], 0x1B, DRAW_LETTER_C_AT_X25__DOS__POST_INIT_VAR08_TO_150
	text id=0x0137, x=25, y=80, color=0x04 ; "B"
	ret

DRAW_LETTER_C_AT_X25__DOS__POST_INIT_VAR08_TO_150:
	jne [0x06], 0x21, DRAW_LETTER_D_AT_X25__DOS__POST_INIT_VAR08_TO_150
	text id=0x0138, x=25, y=80, color=0x04 ; "C"
	ret

DRAW_LETTER_D_AT_X25__DOS__POST_INIT_VAR08_TO_150:
	jne [0x06], 0x1D, SHARED_RET
	text id=0x0139, x=25, y=80, color=0x04 ; "D"
	ret

DRAW_LETTER_2_AT_X26:
	jne [0x06], 0x0B, DRAW_LETTER_3_AT_X26
	text id=0x012E, x=26, y=80, color=0x04 ; "2"
	ret

DRAW_LETTER_3_AT_X26:
	jne [0x06], 0x0C, DRAW_LETTER_4_AT_X26
	text id=0x012F, x=26, y=80, color=0x04 ; "3"
	ret

DRAW_LETTER_4_AT_X26:
	jne [0x06], 0x0D, DRAW_LETTER_5_AT_X26
	text id=0x0130, x=26, y=80, color=0x04 ; "4"
	ret

DRAW_LETTER_5_AT_X26:
	jne [0x06], 0x0F, DRAW_LETTER_6_AT_X26
	text id=0x0131, x=26, y=80, color=0x04 ; "5"
	ret

DRAW_LETTER_6_AT_X26:
	jne [0x06], 0x10, DRAW_LETTER_7_AT_X26
	text id=0x0132, x=26, y=80, color=0x04 ; "6"
	ret

DRAW_LETTER_7_AT_X26:
	jne [0x06], 0x11, DRAW_LETTER_8_AT_X26
	text id=0x0133, x=26, y=80, color=0x04 ; "7"
	ret

DRAW_LETTER_8_AT_X26:
	jne [0x06], 0x13, DRAW_LETTER_9_AT_X26
	text id=0x0134, x=26, y=80, color=0x04 ; "8"
	ret

DRAW_LETTER_9_AT_X26:
	jne [0x06], 0x14, DRAW_LETTER_A_AT_X26
	text id=0x0135, x=26, y=80, color=0x04 ; "9"
	ret

DRAW_LETTER_A_AT_X26:
	jne [0x06], 0x15, DRAW_LETTER_B_AT_X26
	text id=0x0136, x=26, y=80, color=0x04 ; "A"
	ret

DRAW_LETTER_B_AT_X26:
	jne [0x06], 0x1B, DRAW_LETTER_C_AT_X26__DOS__POST_INIT_VAR08_TO_150
	text id=0x0137, x=26, y=80, color=0x04 ; "B"
	ret

DRAW_LETTER_C_AT_X26__DOS__POST_INIT_VAR08_TO_150:
	jne [0x06], 0x21, DRAW_LETTER_D_AT_X26__DOS__POST_INIT_VAR08_TO_150
	text id=0x0138, x=26, y=80, color=0x04 ; "C"
	ret

DRAW_LETTER_D_AT_X26__DOS__POST_INIT_VAR08_TO_150:
	jne [0x06], 0x1D, SHARED_RET
	text id=0x0139, x=26, y=80, color=0x04 ; "D"
	ret

BLINK_LETTER_DISPATCHER:
	je [0x06], 0x62, DRAW_CIN_053_IF_VAR06_EQ_2__DOS__POST_INIT_VAR08_TO_150
	je [0x06], 0x63, DRAW_CIN_053_IF_VAR06_EQ_2__DOS__POST_INIT_VAR08_TO_150
	jne [0xDB], 0x00, DRAW_LETTER_2_DISPATCH_BY_X
	jne [0x06], 0x01, DRAW_CIN_053_IF_VAR06_EQ_2__DOS__POST_INIT_VAR08_TO_150
	video type=1, offset=CINEMATIC_054, x=[0x07], y=[0x08], zoom=[0x04]
	ret

DRAW_CIN_053_IF_VAR06_EQ_2__DOS__POST_INIT_VAR08_TO_150:
	jne [0x06], 0x02, DRAW_GLYPH_KEY03_CIN_052__DOS__POST_INIT_VAR08_TO_150
	video type=1, offset=CINEMATIC_053, x=[0x07], y=[0x08], zoom=[0x04]
	ret

DRAW_GLYPH_KEY03_CIN_052__DOS__POST_INIT_VAR08_TO_150:
	jne [0x06], 0x03, DRAW_GLYPH_KEY04_CIN_051__DOS__POST_INIT_VAR08_TO_150
	video type=1, offset=CINEMATIC_052, x=[0x07], y=[0x08], zoom=[0x04]
	ret

DRAW_GLYPH_KEY04_CIN_051__DOS__POST_INIT_VAR08_TO_150:
	jne [0x06], 0x04, DRAW_GLYPH_KEY05_CIN_050__DOS__POST_INIT_VAR08_TO_150
	video type=1, offset=CINEMATIC_051, x=[0x07], y=[0x08], zoom=[0x04]
	ret

DRAW_GLYPH_KEY05_CIN_050__DOS__POST_INIT_VAR08_TO_150:
	jne [0x06], 0x05, DRAW_GLYPH_KEY06_CIN_049__DOS__POST_INIT_VAR08_TO_150
	video type=1, offset=CINEMATIC_050, x=[0x07], y=[0x08], zoom=[0x04]
	ret

DRAW_GLYPH_KEY06_CIN_049__DOS__POST_INIT_VAR08_TO_150:
	jne [0x06], 0x06, DRAW_GLYPH_KEY07_CIN_048__DOS__POST_INIT_VAR08_TO_150
	video type=1, offset=CINEMATIC_049, x=[0x07], y=[0x08], zoom=[0x04]
	ret

DRAW_GLYPH_KEY07_CIN_048__DOS__POST_INIT_VAR08_TO_150:
	jne [0x06], 0x07, DRAW_GLYPH_KEY08_CIN_047__DOS__POST_INIT_VAR08_TO_150
	video type=1, offset=CINEMATIC_048, x=[0x07], y=[0x08], zoom=[0x04]
	ret

DRAW_GLYPH_KEY08_CIN_047__DOS__POST_INIT_VAR08_TO_150:
	jne [0x06], 0x08, DRAW_GLYPH_KEY09_CIN_046__DOS__POST_INIT_VAR08_TO_150
	video type=1, offset=CINEMATIC_047, x=[0x07], y=[0x08], zoom=[0x04]
	ret

DRAW_GLYPH_KEY09_CIN_046__DOS__POST_INIT_VAR08_TO_150:
	jne [0x06], 0x09, DRAW_LETTER_A_CIN_045__DOS__POST_INIT_VAR08_TO_150
	video type=1, offset=CINEMATIC_046, x=[0x07], y=[0x08], zoom=[0x04]
	ret

DRAW_LETTER_A_CIN_045__DOS__POST_INIT_VAR08_TO_150:
	jne [0x06], 0x0A, DRAW_LETTER_B_CIN_044__DOS__POST_INIT_VAR08_TO_150
	video type=1, offset=CINEMATIC_045, x=[0x07], y=[0x08], zoom=[0x04]
	ret

DRAW_LETTER_B_CIN_044__DOS__POST_INIT_VAR08_TO_150:
	jne [0x06], 0x0B, DRAW_LETTER_C_CIN_043__DOS__POST_INIT_VAR08_TO_150
	video type=1, offset=CINEMATIC_044, x=[0x07], y=[0x08], zoom=[0x04]
	ret

DRAW_LETTER_C_CIN_043__DOS__POST_INIT_VAR08_TO_150:
	jne [0x06], 0x0C, DRAW_LETTER_D_CIN_042__DOS__POST_INIT_VAR08_TO_150
	video type=1, offset=CINEMATIC_043, x=[0x07], y=[0x08], zoom=[0x04]
	ret

DRAW_LETTER_D_CIN_042__DOS__POST_INIT_VAR08_TO_150:
	jne [0x06], 0x0D, DRAW_LETTER_E_CIN_041__DOS__POST_INIT_VAR08_TO_150
	video type=1, offset=CINEMATIC_042, x=[0x07], y=[0x08], zoom=[0x04]
	ret

DRAW_LETTER_E_CIN_041__DOS__POST_INIT_VAR08_TO_150:
	jne [0x06], 0x0E, DRAW_LETTER_F_CIN_040__DOS__POST_INIT_VAR08_TO_150
	video type=1, offset=CINEMATIC_041, x=[0x07], y=[0x08], zoom=[0x04]
	ret

DRAW_LETTER_F_CIN_040__DOS__POST_INIT_VAR08_TO_150:
	jne [0x06], 0x0F, DRAW_LETTER_G_CIN_039__DOS__POST_INIT_VAR08_TO_150
	video type=1, offset=CINEMATIC_040, x=[0x07], y=[0x08], zoom=[0x04]
	ret

DRAW_LETTER_G_CIN_039__DOS__POST_INIT_VAR08_TO_150:
	jne [0x06], 0x10, DRAW_LETTER_VIA_CIN_DISPATCH__DOS__POST_INIT_VAR08_TO_150
	video type=1, offset=CINEMATIC_039, x=[0x07], y=[0x08], zoom=[0x04]
	ret

DRAW_LETTER_VIA_CIN_DISPATCH__DOS__POST_INIT_VAR08_TO_150:
	jne [0x06], 0x62, DRAW_CIN_000_LETTER_BLANK__DOS__POST_INIT_VAR08_TO_150
	video type=1, offset=CINEMATIC_038, x=[0x07], y=[0x08], zoom=[0x04]
	ret

DRAW_CIN_000_LETTER_BLANK__DOS__POST_INIT_VAR08_TO_150:
	jne [0x06], 0x63, DRAW_GLYPH_KEY00_CIN_036__DOS__POST_INIT_VAR08_TO_150
	video type=1, offset=CINEMATIC_037, x=[0x07], y=[0x08], zoom=[0x04]
	ret

DRAW_GLYPH_KEY00_CIN_036__DOS__POST_INIT_VAR08_TO_150:
	jne [0x06], 0x00, DRAW_LETTER_H_CIN_035__DOS__POST_INIT_VAR08_TO_150
	video type=1, offset=CINEMATIC_036, x=[0x07], y=[0x08], zoom=[0x04]
	ret

DRAW_LETTER_H_CIN_035__DOS__POST_INIT_VAR08_TO_150:
	jne [0x06], 0x11, DRAW_LETTER_I_CIN_034__DOS__POST_INIT_VAR08_TO_150
	video type=1, offset=CINEMATIC_035, x=[0x07], y=[0x08], zoom=[0x04]
	ret

DRAW_LETTER_I_CIN_034__DOS__POST_INIT_VAR08_TO_150:
	jne [0x06], 0x12, DRAW_LETTER_J_CIN_033__DOS__POST_INIT_VAR08_TO_150
	video type=1, offset=CINEMATIC_034, x=[0x07], y=[0x08], zoom=[0x04]
	ret

DRAW_LETTER_J_CIN_033__DOS__POST_INIT_VAR08_TO_150:
	jne [0x06], 0x13, DRAW_LETTER_K_CIN_032__DOS__POST_INIT_VAR08_TO_150
	video type=1, offset=CINEMATIC_033, x=[0x07], y=[0x08], zoom=[0x04]
	ret

DRAW_LETTER_K_CIN_032__DOS__POST_INIT_VAR08_TO_150:
	jne [0x06], 0x14, DRAW_LETTER_L_CIN_031__DOS__POST_INIT_VAR08_TO_150
	video type=1, offset=CINEMATIC_032, x=[0x07], y=[0x08], zoom=[0x04]
	ret

DRAW_LETTER_L_CIN_031__DOS__POST_INIT_VAR08_TO_150:
	jne [0x06], 0x15, DRAW_LETTER_M_CIN_030__DOS__POST_INIT_VAR08_TO_150
	video type=1, offset=CINEMATIC_031, x=[0x07], y=[0x08], zoom=[0x04]
	ret

DRAW_LETTER_M_CIN_030__DOS__POST_INIT_VAR08_TO_150:
	jne [0x06], 0x16, DRAW_LETTER_N_CIN_029
	video type=1, offset=CINEMATIC_030, x=[0x07], y=[0x08], zoom=[0x04]
	ret

DRAW_LETTER_N_CIN_029:
	jne [0x06], 0x17, DRAW_LETTER_O_CIN_028
	video type=1, offset=CINEMATIC_029, x=[0x07], y=[0x08], zoom=[0x04]
	ret

DRAW_LETTER_O_CIN_028:
	jne [0x06], 0x18, DRAW_LETTER_P_CIN_027
	video type=1, offset=CINEMATIC_028, x=[0x07], y=[0x08], zoom=[0x04]
	ret

DRAW_LETTER_P_CIN_027:
	jne [0x06], 0x19, DRAW_LETTER_Q_CIN_026
	video type=1, offset=CINEMATIC_027, x=[0x07], y=[0x08], zoom=[0x04]
	ret

DRAW_LETTER_Q_CIN_026:
	jne [0x06], 0x1A, DRAW_LETTER_R_CIN_025
	video type=1, offset=CINEMATIC_026, x=[0x07], y=[0x08], zoom=[0x04]
	ret

DRAW_LETTER_R_CIN_025:
	jne [0x06], 0x1B, DRAW_LETTER_S_CIN_024
	video type=1, offset=CINEMATIC_025, x=[0x07], y=[0x08], zoom=[0x04]
	ret

DRAW_LETTER_S_CIN_024:
	jne [0x06], 0x1C, DRAW_LETTER_T_CIN_023
	video type=1, offset=CINEMATIC_024, x=[0x07], y=[0x08], zoom=[0x04]
	ret

DRAW_LETTER_T_CIN_023:
	jne [0x06], 0x1D, DRAW_LETTER_U_CIN_022
	video type=1, offset=CINEMATIC_023, x=[0x07], y=[0x08], zoom=[0x04]
	ret

DRAW_LETTER_U_CIN_022:
	jne [0x06], 0x1E, DRAW_LETTER_V_CIN_021
	video type=1, offset=CINEMATIC_022, x=[0x07], y=[0x08], zoom=[0x04]
	ret

DRAW_LETTER_V_CIN_021:
	jne [0x06], 0x1F, DRAW_LETTER_W_CIN_020
	video type=1, offset=CINEMATIC_021, x=[0x07], y=[0x08], zoom=[0x04]
	ret

DRAW_LETTER_W_CIN_020:
	jne [0x06], 0x20, DRAW_LETTER_X_CIN_019
	video type=1, offset=CINEMATIC_020, x=[0x07], y=[0x08], zoom=[0x04]
	ret

DRAW_LETTER_X_CIN_019:
	jne [0x06], 0x21, DRAW_LETTER_Y_CIN_018
	video type=1, offset=CINEMATIC_019, x=[0x07], y=[0x08], zoom=[0x04]
	ret

DRAW_LETTER_Y_CIN_018:
	jne [0x06], 0x22, DRAW_LETTER_Z_CIN_017
	video type=1, offset=CINEMATIC_018, x=[0x07], y=[0x08], zoom=[0x04]
	ret

DRAW_LETTER_Z_CIN_017:
	jne [0x06], 0x23, DRAW_GLYPH_KEY24_CIN_017__DOS__POST_INIT_VAR08_TO_150
	video type=1, offset=CINEMATIC_017, x=[0x07], y=[0x08], zoom=[0x04]
	ret

DRAW_GLYPH_KEY24_CIN_017__DOS__POST_INIT_VAR08_TO_150:
	jne [0x06], 0x24, SHARED_RET
	video type=1, offset=CINEMATIC_017, x=[0x07], y=[0x08], zoom=[0x04]
	ret

SHARED_RET:
	ret
	killChannel
	video type=1, offset=CINEMATIC_057, x=160, y=100

BLITTER_LOOP_COPY_PAGE_00:
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	copyVideoPage src=0x00, dst=0xFF
	break
	jmp BLITTER_LOOP_COPY_PAGE_00

JUNK__1088:
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	break
	jmp JUNK__1088
; (cart has no chunk here — cart_pre above already spans through to CLEAR_PAGES_1_2_AND_BLIT)

CLEAR_PAGES_1_2_AND_BLIT:
	fill page=0x01, color=0x00
	fill page=0x02, color=0x00
	selectVideoPage 0x01
	blitFramebuffer 0x01
	blitFramebuffer 0xFF
	blitFramebuffer 0x02
	ret

	db 0x11, 0x11, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
	FILL(61273, 0xFF)
