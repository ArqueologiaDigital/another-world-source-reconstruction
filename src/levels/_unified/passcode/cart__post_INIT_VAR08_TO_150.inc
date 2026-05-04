SCALE_VAR07_TIMES_9_PLUS_4A:
	shl [0x07], 0x0003
	mov [0xF8], [0x07]
	add [0x07], [0xF8]
	add [0x07], 0x004A
	je [0xDB], 0x00, SHARED_RET
	add [0x07], 0x0004
	ret

DRAW_LETTER_DISPATCH_BY_X:
	je [0x07], 0xC4, DRAW_LETTER_AT_X24
	je [0x07], 0xCC, DRAW_LETTER_AT_X25
	je [0x07], 0xD4, DRAW_LETTER_AT_X26
	jne [0x07], 0xBC, SHARED_RET
	jne [0x06], 0x0B, DRAW_LETTER_C_AT_X23__CART__POST_INIT_VAR08_TO_150
	text id=0x012E, x=23, y=80, color=0x04 ; "B"
	ret

DRAW_LETTER_C_AT_X23__CART__POST_INIT_VAR08_TO_150:
	jne [0x06], 0x0C, DRAW_LETTER_D_AT_X23__CART__POST_INIT_VAR08_TO_150
	text id=0x012F, x=23, y=80, color=0x04 ; "C"
	ret

DRAW_LETTER_D_AT_X23__CART__POST_INIT_VAR08_TO_150:
	jne [0x06], 0x0D, DRAW_LETTER_F_AT_X23
	text id=0x0130, x=23, y=80, color=0x04 ; "D"
	ret

DRAW_LETTER_F_AT_X23:
	jne [0x06], 0x0F, DRAW_LETTER_G_AT_X23
	text id=0x0131, x=23, y=80, color=0x04 ; "F"
	ret

DRAW_LETTER_G_AT_X23:
	jne [0x06], 0x10, DRAW_LETTER_H_AT_X23
	text id=0x0132, x=23, y=80, color=0x04 ; "G"
	ret

DRAW_LETTER_H_AT_X23:
	jne [0x06], 0x11, DRAW_LETTER_J_AT_X23
	text id=0x0133, x=23, y=80, color=0x04 ; "H"
	ret

DRAW_LETTER_J_AT_X23:
	jne [0x06], 0x13, DRAW_LETTER_K_AT_X23
	text id=0x0134, x=23, y=80, color=0x04 ; "J"
	ret

DRAW_LETTER_K_AT_X23:
	jne [0x06], 0x14, DRAW_LETTER_L_AT_X23
	text id=0x0135, x=23, y=80, color=0x04 ; "K"
	ret

DRAW_LETTER_L_AT_X23:
	jne [0x06], 0x15, DRAW_LETTER_R_AT_X23
	text id=0x0136, x=23, y=80, color=0x04 ; "L"
	ret

DRAW_LETTER_R_AT_X23:
	jne [0x06], 0x1B, DRAW_LETTER_X_AT_X23
	text id=0x0137, x=23, y=80, color=0x04 ; "R"
	ret

DRAW_LETTER_X_AT_X23:
	jne [0x06], 0x21, DRAW_LETTER_T_AT_X23
	text id=0x0138, x=23, y=80, color=0x04 ; "X"
	ret

DRAW_LETTER_T_AT_X23:
	jne [0x06], 0x1D, SHARED_RET
	text id=0x0139, x=23, y=80, color=0x04 ; "T"
	ret

DRAW_LETTER_AT_X24:
	jne [0x06], 0x0B, DRAW_LETTER_C_AT_X24__CART__POST_INIT_VAR08_TO_150
	text id=0x012E, x=24, y=80, color=0x04 ; "B"
	ret

DRAW_LETTER_C_AT_X24__CART__POST_INIT_VAR08_TO_150:
	jne [0x06], 0x0C, DRAW_LETTER_D_AT_X24__CART__POST_INIT_VAR08_TO_150
	text id=0x012F, x=24, y=80, color=0x04 ; "C"
	ret

DRAW_LETTER_D_AT_X24__CART__POST_INIT_VAR08_TO_150:
	jne [0x06], 0x0D, DRAW_LETTER_F_AT_X24
	text id=0x0130, x=24, y=80, color=0x04 ; "D"
	ret

DRAW_LETTER_F_AT_X24:
	jne [0x06], 0x0F, DRAW_LETTER_G_AT_X24
	text id=0x0131, x=24, y=80, color=0x04 ; "F"
	ret

DRAW_LETTER_G_AT_X24:
	jne [0x06], 0x10, DRAW_LETTER_H_AT_X24
	text id=0x0132, x=24, y=80, color=0x04 ; "G"
	ret

DRAW_LETTER_H_AT_X24:
	jne [0x06], 0x11, DRAW_LETTER_J_AT_X24
	text id=0x0133, x=24, y=80, color=0x04 ; "H"
	ret

DRAW_LETTER_J_AT_X24:
	jne [0x06], 0x13, DRAW_LETTER_K_AT_X24
	text id=0x0134, x=24, y=80, color=0x04 ; "J"
	ret

DRAW_LETTER_K_AT_X24:
	jne [0x06], 0x14, DRAW_LETTER_L_AT_X24
	text id=0x0135, x=24, y=80, color=0x04 ; "K"
	ret

DRAW_LETTER_L_AT_X24:
	jne [0x06], 0x15, DRAW_LETTER_R_AT_X24
	text id=0x0136, x=24, y=80, color=0x04 ; "L"
	ret

DRAW_LETTER_R_AT_X24:
	jne [0x06], 0x1B, DRAW_LETTER_X_AT_X24
	text id=0x0137, x=24, y=80, color=0x04 ; "R"
	ret

DRAW_LETTER_X_AT_X24:
	jne [0x06], 0x21, DRAW_LETTER_T_AT_X24
	text id=0x0138, x=24, y=80, color=0x04 ; "X"
	ret

DRAW_LETTER_T_AT_X24:
	jne [0x06], 0x1D, SHARED_RET
	text id=0x0139, x=24, y=80, color=0x04 ; "T"
	ret

DRAW_LETTER_AT_X25:
	jne [0x06], 0x0B, DRAW_LETTER_C_AT_X25__CART__POST_INIT_VAR08_TO_150
	text id=0x012E, x=25, y=80, color=0x04 ; "B"
	ret

DRAW_LETTER_C_AT_X25__CART__POST_INIT_VAR08_TO_150:
	jne [0x06], 0x0C, DRAW_LETTER_D_AT_X25__CART__POST_INIT_VAR08_TO_150
	text id=0x012F, x=25, y=80, color=0x04 ; "C"
	ret

DRAW_LETTER_D_AT_X25__CART__POST_INIT_VAR08_TO_150:
	jne [0x06], 0x0D, DRAW_LETTER_F_AT_X25
	text id=0x0130, x=25, y=80, color=0x04 ; "D"
	ret

DRAW_LETTER_F_AT_X25:
	jne [0x06], 0x0F, DRAW_LETTER_G_AT_X25
	text id=0x0131, x=25, y=80, color=0x04 ; "F"
	ret

DRAW_LETTER_G_AT_X25:
	jne [0x06], 0x10, DRAW_LETTER_H_AT_X25
	text id=0x0132, x=25, y=80, color=0x04 ; "G"
	ret

DRAW_LETTER_H_AT_X25:
	jne [0x06], 0x11, DRAW_LETTER_J_AT_X25
	text id=0x0133, x=25, y=80, color=0x04 ; "H"
	ret

DRAW_LETTER_J_AT_X25:
	jne [0x06], 0x13, DRAW_LETTER_K_AT_X25
	text id=0x0134, x=25, y=80, color=0x04 ; "J"
	ret

DRAW_LETTER_K_AT_X25:
	jne [0x06], 0x14, DRAW_LETTER_L_AT_X25
	text id=0x0135, x=25, y=80, color=0x04 ; "K"
	ret

DRAW_LETTER_L_AT_X25:
	jne [0x06], 0x15, DRAW_LETTER_R_AT_X25
	text id=0x0136, x=25, y=80, color=0x04 ; "L"
	ret

DRAW_LETTER_R_AT_X25:
	jne [0x06], 0x1B, DRAW_LETTER_X_AT_X25
	text id=0x0137, x=25, y=80, color=0x04 ; "R"
	ret

DRAW_LETTER_X_AT_X25:
	jne [0x06], 0x21, DRAW_LETTER_T_AT_X25
	text id=0x0138, x=25, y=80, color=0x04 ; "X"
	ret

DRAW_LETTER_T_AT_X25:
	jne [0x06], 0x1D, SHARED_RET
	text id=0x0139, x=25, y=80, color=0x04 ; "T"
	ret

DRAW_LETTER_AT_X26:
	jne [0x06], 0x0B, DRAW_LETTER_C_AT_X26__CART__POST_INIT_VAR08_TO_150
	text id=0x012E, x=26, y=80, color=0x04 ; "B"
	ret

DRAW_LETTER_C_AT_X26__CART__POST_INIT_VAR08_TO_150:
	jne [0x06], 0x0C, DRAW_LETTER_D_AT_X26__CART__POST_INIT_VAR08_TO_150
	text id=0x012F, x=26, y=80, color=0x04 ; "C"
	ret

DRAW_LETTER_D_AT_X26__CART__POST_INIT_VAR08_TO_150:
	jne [0x06], 0x0D, DRAW_LETTER_F_AT_X26
	text id=0x0130, x=26, y=80, color=0x04 ; "D"
	ret

DRAW_LETTER_F_AT_X26:
	jne [0x06], 0x0F, DRAW_LETTER_G_AT_X26
	text id=0x0131, x=26, y=80, color=0x04 ; "F"
	ret

DRAW_LETTER_G_AT_X26:
	jne [0x06], 0x10, DRAW_LETTER_H_AT_X26
	text id=0x0132, x=26, y=80, color=0x04 ; "G"
	ret

DRAW_LETTER_H_AT_X26:
	jne [0x06], 0x11, DRAW_LETTER_J_AT_X26
	text id=0x0133, x=26, y=80, color=0x04 ; "H"
	ret

DRAW_LETTER_J_AT_X26:
	jne [0x06], 0x13, DRAW_LETTER_K_AT_X26
	text id=0x0134, x=26, y=80, color=0x04 ; "J"
	ret

DRAW_LETTER_K_AT_X26:
	jne [0x06], 0x14, DRAW_LETTER_L_AT_X26
	text id=0x0135, x=26, y=80, color=0x04 ; "K"
	ret

DRAW_LETTER_L_AT_X26:
	jne [0x06], 0x15, DRAW_LETTER_R_AT_X26
	text id=0x0136, x=26, y=80, color=0x04 ; "L"
	ret

DRAW_LETTER_R_AT_X26:
	jne [0x06], 0x1B, DRAW_LETTER_X_AT_X26
	text id=0x0137, x=26, y=80, color=0x04 ; "R"
	ret

DRAW_LETTER_X_AT_X26:
	jne [0x06], 0x21, DRAW_LETTER_T_AT_X26
	text id=0x0138, x=26, y=80, color=0x04 ; "X"
	ret

DRAW_LETTER_T_AT_X26:
	jne [0x06], 0x1D, SHARED_RET
	text id=0x0139, x=26, y=80, color=0x04 ; "T"
	ret

DRAW_OR_BLINK_LETTER:
	je [0x06], 0x62, DRAW_LETTER_VIA_CIN_DISPATCH__CART__POST_INIT_VAR08_TO_150
	je [0x06], 0x63, DRAW_LETTER_VIA_CIN_DISPATCH__CART__POST_INIT_VAR08_TO_150
	jne [0xDB], 0x00, DRAW_LETTER_DISPATCH_BY_X

DRAW_LETTER_VIA_CIN_DISPATCH__CART__POST_INIT_VAR08_TO_150:
	jne [0x06], 0x62, DRAW_CIN_000_LETTER_BLANK__CART__POST_INIT_VAR08_TO_150
	video type=1, offset=CINEMATIC_001, x=[0x07], y=[0x08], zoom=[0x04]
	ret

DRAW_CIN_000_LETTER_BLANK__CART__POST_INIT_VAR08_TO_150:
	jne [0x06], 0x63, SHARED_RET
	video type=1, offset=CINEMATIC_000, x=[0x07], y=[0x08], zoom=[0x04]
	ret

SHARED_RET:
	ret
	killChannel
	video type=1, offset=CINEMATIC_004, x=160, y=100

BLITTER_LOOP_COPY_PAGE_00:
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	copyVideoPage src=0x00, dst=0xFF
	break
	jmp BLITTER_LOOP_COPY_PAGE_00

JUNK__0BCA:
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	break
	jmp JUNK__0BCA


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
	FILL(62487, 0xFF)
