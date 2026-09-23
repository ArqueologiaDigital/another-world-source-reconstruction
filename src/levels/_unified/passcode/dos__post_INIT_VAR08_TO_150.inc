PASSCODE_GRID_COLUMN_SCREEN_X:
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
	jne [0x06], 0x1B, DRAW_LETTER_C_AT_X23
	text id=0x0137, x=23, y=80, color=0x04 ; "B"
	ret


DRAW_LETTER_C_AT_X23:
	jne [0x06], 0x21, DRAW_LETTER_D_AT_X23
	text id=0x0138, x=23, y=80, color=0x04 ; "C"
	ret


DRAW_LETTER_D_AT_X23:
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
	jne [0x06], 0x1B, DRAW_LETTER_C_AT_X24
	text id=0x0137, x=24, y=80, color=0x04 ; "B"
	ret


DRAW_LETTER_C_AT_X24:
	jne [0x06], 0x21, DRAW_LETTER_D_AT_X24
	text id=0x0138, x=24, y=80, color=0x04 ; "C"
	ret


DRAW_LETTER_D_AT_X24:
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
	jne [0x06], 0x1B, DRAW_LETTER_C_AT_X25
	text id=0x0137, x=25, y=80, color=0x04 ; "B"
	ret


DRAW_LETTER_C_AT_X25:
	jne [0x06], 0x21, DRAW_LETTER_D_AT_X25
	text id=0x0138, x=25, y=80, color=0x04 ; "C"
	ret


DRAW_LETTER_D_AT_X25:
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
	jne [0x06], 0x1B, DRAW_LETTER_C_AT_X26
	text id=0x0137, x=26, y=80, color=0x04 ; "B"
	ret


DRAW_LETTER_C_AT_X26:
	jne [0x06], 0x21, DRAW_LETTER_D_AT_X26
	text id=0x0138, x=26, y=80, color=0x04 ; "C"
	ret


DRAW_LETTER_D_AT_X26:
	jne [0x06], 0x1D, SHARED_RET
	text id=0x0139, x=26, y=80, color=0x04 ; "D"
	ret


BLINK_LETTER_DISPATCHER:
	je [0x06], 0x62, PASSCODE_GLYPH_DIGIT_2
	je [0x06], 0x63, PASSCODE_GLYPH_DIGIT_2
	jne [0xDB], 0x00, DRAW_LETTER_2_DISPATCH_BY_X
	jne [0x06], 0x01, PASSCODE_GLYPH_DIGIT_2
	video offset=CINEMATIC_PASSCODE_FONT_DIGIT_1, x=[0x07], y=[0x08], zoom=[0x04]
	ret


PASSCODE_GLYPH_DIGIT_2:
	jne [0x06], 0x02, PASSCODE_GLYPH_DIGIT_3
	video offset=CINEMATIC_PASSCODE_FONT_DIGIT_2, x=[0x07], y=[0x08], zoom=[0x04]
	ret


PASSCODE_GLYPH_DIGIT_3:
	jne [0x06], 0x03, PASSCODE_GLYPH_DIGIT_4
	video offset=CINEMATIC_PASSCODE_FONT_DIGIT_3, x=[0x07], y=[0x08], zoom=[0x04]
	ret


PASSCODE_GLYPH_DIGIT_4:
	jne [0x06], 0x04, PASSCODE_GLYPH_DIGIT_5
	video offset=CINEMATIC_PASSCODE_FONT_DIGIT_4, x=[0x07], y=[0x08], zoom=[0x04]
	ret


PASSCODE_GLYPH_DIGIT_5:
	jne [0x06], 0x05, PASSCODE_GLYPH_DIGIT_6
	video offset=CINEMATIC_PASSCODE_FONT_DIGIT_5, x=[0x07], y=[0x08], zoom=[0x04]
	ret


PASSCODE_GLYPH_DIGIT_6:
	jne [0x06], 0x06, PASSCODE_GLYPH_DIGIT_7
	video offset=CINEMATIC_PASSCODE_FONT_DIGIT_6, x=[0x07], y=[0x08], zoom=[0x04]
	ret


PASSCODE_GLYPH_DIGIT_7:
	jne [0x06], 0x07, PASSCODE_GLYPH_DIGIT_8
	video offset=CINEMATIC_PASSCODE_FONT_DIGIT_7, x=[0x07], y=[0x08], zoom=[0x04]
	ret


PASSCODE_GLYPH_DIGIT_8:
	jne [0x06], 0x08, PASSCODE_GLYPH_DIGIT_9
	video offset=CINEMATIC_PASSCODE_FONT_DIGIT_8, x=[0x07], y=[0x08], zoom=[0x04]
	ret


PASSCODE_GLYPH_DIGIT_9:
	jne [0x06], 0x09, PASSCODE_GLYPH_LETTER_A
	video offset=CINEMATIC_PASSCODE_FONT_DIGIT_9, x=[0x07], y=[0x08], zoom=[0x04]
	ret


PASSCODE_GLYPH_LETTER_A:
	jne [0x06], 0x0A, PASSCODE_LETTER_B_CASE_0B
	video offset=CINEMATIC_PASSCODE_FONT_LETTER_A, x=[0x07], y=[0x08], zoom=[0x04]
	ret


PASSCODE_LETTER_B_CASE_0B:
	jne [0x06], 0x0B, PASSCODE_LETTER_C_CASE_0C
	video offset=CINEMATIC_PASSCODE_FONT_LETTER_B, x=[0x07], y=[0x08], zoom=[0x04]
	ret


PASSCODE_LETTER_C_CASE_0C:
	jne [0x06], 0x0C, PASSCODE_LETTER_D_CASE_0D
	video offset=CINEMATIC_PASSCODE_FONT_LETTER_C, x=[0x07], y=[0x08], zoom=[0x04]
	ret


PASSCODE_LETTER_D_CASE_0D:
	jne [0x06], 0x0D, PASSCODE_LETTER_E_CASE_0E
	video offset=CINEMATIC_PASSCODE_FONT_LETTER_D, x=[0x07], y=[0x08], zoom=[0x04]
	ret


PASSCODE_LETTER_E_CASE_0E:
	jne [0x06], 0x0E, DRAW_LETTER_F_AT_X23
	video offset=CINEMATIC_PASSCODE_FONT_LETTER_E, x=[0x07], y=[0x08], zoom=[0x04]
	ret


DRAW_LETTER_F_AT_X23:
	jne [0x06], 0x0F, DRAW_LETTER_G_AT_X23
	video offset=CINEMATIC_PASSCODE_FONT_LETTER_F, x=[0x07], y=[0x08], zoom=[0x04]
	ret


DRAW_LETTER_G_AT_X23:
	jne [0x06], 0x10, DRAW_LETTER_VIA_CIN_DISPATCH
	video offset=CINEMATIC_PASSCODE_FONT_LETTER_G, x=[0x07], y=[0x08], zoom=[0x04]
	ret


DRAW_LETTER_VIA_CIN_DISPATCH:
	jne [0x06], 0x62, PASSCODE_VALIDATE_KEY_GLYPH_CASE_63
	video offset=CINEMATIC_DEL_BUTTON, x=[0x07], y=[0x08], zoom=[0x04]
	ret


PASSCODE_VALIDATE_KEY_GLYPH_CASE_63:
	jne [0x06], 0x63, PASSCODE_GLYPH_CASE_00
	video offset=CINEMATIC_OK_BUTTON, x=[0x07], y=[0x08], zoom=[0x04]
	ret


PASSCODE_GLYPH_CASE_00:
	jne [0x06], 0x00, PASSCODE_LETTER_H_CASE_11
	video offset=CINEMATIC_PASSCODE_FONT_DIGIT_0, x=[0x07], y=[0x08], zoom=[0x04]
	ret


PASSCODE_LETTER_H_CASE_11:
	jne [0x06], 0x11, PASSCODE_LETTER_I_CASE_12
	video offset=CINEMATIC_PASSCODE_FONT_LETTER_H, x=[0x07], y=[0x08], zoom=[0x04]
	ret


PASSCODE_LETTER_I_CASE_12:
	jne [0x06], 0x12, PASSCODE_LETTER_J_CASE_13
	video offset=CINEMATIC_PASSCODE_FONT_LETTER_I, x=[0x07], y=[0x08], zoom=[0x04]
	ret


PASSCODE_LETTER_J_CASE_13:
	jne [0x06], 0x13, PASSCODE_LETTER_K_CASE_14
	video offset=CINEMATIC_PASSCODE_FONT_LETTER_J, x=[0x07], y=[0x08], zoom=[0x04]
	ret


PASSCODE_LETTER_K_CASE_14:
	jne [0x06], 0x14, PASSCODE_LETTER_L_CASE_15
	video offset=CINEMATIC_PASSCODE_FONT_LETTER_K, x=[0x07], y=[0x08], zoom=[0x04]
	ret


PASSCODE_LETTER_L_CASE_15:
	jne [0x06], 0x15, PASSCODE_LETTER_M_CASE_16
	video offset=CINEMATIC_PASSCODE_FONT_LETTER_L, x=[0x07], y=[0x08], zoom=[0x04]
	ret


PASSCODE_LETTER_M_CASE_16:
	jne [0x06], 0x16, PASSCODE_LETTER_N_CASE_17
	video offset=CINEMATIC_PASSCODE_FONT_LETTER_M, x=[0x07], y=[0x08], zoom=[0x04]
	ret


PASSCODE_LETTER_N_CASE_17:
	jne [0x06], 0x17, PASSCODE_LETTER_O_CASE_18
	video offset=CINEMATIC_PASSCODE_FONT_LETTER_N, x=[0x07], y=[0x08], zoom=[0x04]
	ret


PASSCODE_LETTER_O_CASE_18:
	jne [0x06], 0x18, PASSCODE_LETTER_P_CASE_19
	video offset=CINEMATIC_PASSCODE_FONT_LETTER_O, x=[0x07], y=[0x08], zoom=[0x04]
	ret


PASSCODE_LETTER_P_CASE_19:
	jne [0x06], 0x19, PASSCODE_LETTER_Q_CASE_1A
	video offset=CINEMATIC_PASSCODE_FONT_LETTER_P, x=[0x07], y=[0x08], zoom=[0x04]
	ret


PASSCODE_LETTER_Q_CASE_1A:
	jne [0x06], 0x1A, PASSCODE_LETTER_R_CASE_1B
	video offset=CINEMATIC_PASSCODE_FONT_LETTER_Q, x=[0x07], y=[0x08], zoom=[0x04]
	ret


PASSCODE_LETTER_R_CASE_1B:
	jne [0x06], 0x1B, PASSCODE_LETTER_S_CASE_1C
	video offset=CINEMATIC_PASSCODE_FONT_LETTER_R, x=[0x07], y=[0x08], zoom=[0x04]
	ret


PASSCODE_LETTER_S_CASE_1C:
	jne [0x06], 0x1C, PASSCODE_LETTER_T_CASE_1D
	video offset=CINEMATIC_PASSCODE_FONT_LETTER_S, x=[0x07], y=[0x08], zoom=[0x04]
	ret


PASSCODE_LETTER_T_CASE_1D:
	jne [0x06], 0x1D, PASSCODE_LETTER_U_CASE_1E
	video offset=CINEMATIC_PASSCODE_FONT_LETTER_T, x=[0x07], y=[0x08], zoom=[0x04]
	ret


PASSCODE_LETTER_U_CASE_1E:
	jne [0x06], 0x1E, PASSCODE_LETTER_V_CASE_1F
	video offset=CINEMATIC_PASSCODE_FONT_LETTER_U, x=[0x07], y=[0x08], zoom=[0x04]
	ret


PASSCODE_LETTER_V_CASE_1F:
	jne [0x06], 0x1F, PASSCODE_LETTER_W_CASE_20
	video offset=CINEMATIC_PASSCODE_FONT_LETTER_V, x=[0x07], y=[0x08], zoom=[0x04]
	ret


PASSCODE_LETTER_W_CASE_20:
	jne [0x06], 0x20, PASSCODE_LETTER_X_CASE_21
	video offset=CINEMATIC_PASSCODE_FONT_LETTER_W, x=[0x07], y=[0x08], zoom=[0x04]
	ret


PASSCODE_LETTER_X_CASE_21:
	jne [0x06], 0x21, PASSCODE_LETTER_Y_CASE_22
	video offset=CINEMATIC_PASSCODE_FONT_LETTER_X, x=[0x07], y=[0x08], zoom=[0x04]
	ret


PASSCODE_LETTER_Y_CASE_22:
	jne [0x06], 0x22, PASSCODE_LETTER_Z_CASE_23
	video offset=CINEMATIC_PASSCODE_FONT_LETTER_Y, x=[0x07], y=[0x08], zoom=[0x04]
	ret


PASSCODE_LETTER_Z_CASE_23:
	jne [0x06], 0x23, PASSCODE_GLYPH_PAST_Z_CASE_24
	video offset=CINEMATIC_PASSCODE_FONT_LETTER_Z, x=[0x07], y=[0x08], zoom=[0x04]
	ret


PASSCODE_GLYPH_PAST_Z_CASE_24:
	jne [0x06], 0x24, SHARED_RET
	video offset=CINEMATIC_PASSCODE_FONT_LETTER_Z, x=[0x07], y=[0x08], zoom=[0x04]
	ret


SHARED_RET:
	ret


	killChannel
	video offset=CINEMATIC_057, x=160, y=100

BLITTER_LOOP_COPY_PAGE_00:
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	copyVideoPage src=0x00, dst=0xFF
	break
	jmp BLITTER_LOOP_COPY_PAGE_00

LABEL_1088:
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	break
	jmp LABEL_1088
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
