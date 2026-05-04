DELAY_LOOP_VAREC_AT_34FF:
	break
	djnz [0xEC], DELAY_LOOP_VAREC_AT_34FF
	mov [0xE9], [0xE7]
	mov [0xE8], [0xE6]
	jmp STEP_VARE9_UP10_VARE8_DOWN1_RESET_VAREC_6
LABEL_350D:
	db 0x11

LABEL_350E:
	je [0x23], 0x01, DRAW_CIN_272
	je [0x23], 0x02, DRAW_CIN_273
	je [0x23], 0x03, DRAW_CIN_274
	je [0x23], 0x04, DRAW_CIN_275
	je [0x23], 0x05, DRAW_CIN_274
	je [0x23], 0x06, DRAW_CIN_273
	je [0x23], 0x07, DRAW_CIN_272
	je [0x23], 0x08, DRAW_CIN_273
	je [0x23], 0x09, DRAW_CIN_274
	je [0x23], 0x0A, DRAW_CIN_275
	je [0x23], 0x0B, DRAW_CIN_274
	je [0x23], 0x0C, DRAW_CIN_273

DRAW_CIN_272:
	video type=1, offset=CINEMATIC_272, x=[0x21], y=[0x22], zoom=0x40
	ret

DRAW_CIN_273:
	video type=1, offset=CINEMATIC_273, x=[0x21], y=[0x22], zoom=0x40
	ret

DRAW_CIN_274:
	video type=1, offset=CINEMATIC_274, x=[0x21], y=[0x22], zoom=0x40
	ret

DRAW_CIN_275:
	video type=1, offset=CINEMATIC_275, x=[0x21], y=[0x22], zoom=0x40
	ret

HANG_DRAW_CIN_271:
	video type=1, offset=CINEMATIC_271, x=[0xe6], y=[0xe7], zoom=0x40
	break
	jmp HANG_DRAW_CIN_271
LABEL_3577:
	db 0x11
