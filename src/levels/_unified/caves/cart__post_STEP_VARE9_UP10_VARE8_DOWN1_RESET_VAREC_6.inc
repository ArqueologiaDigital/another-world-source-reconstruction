DELAY_LOOP_VAREC_AT_34E3:
	break
	djnz [0xEC], DELAY_LOOP_VAREC_AT_34E3
	mov [0xE9], [0xE7]
	mov [0xE8], [0xE6]
	jmp STEP_VARE9_UP10_VARE8_DOWN1_RESET_VAREC_6
LABEL_34F1:
	db 0x11

LABEL_34F2:
	je [0x23], 0x01, DRAW_CIN_271
	je [0x23], 0x02, DRAW_CIN_272
	je [0x23], 0x03, DRAW_CIN_273
	je [0x23], 0x04, DRAW_CIN_274
	je [0x23], 0x05, DRAW_CIN_273
	je [0x23], 0x06, DRAW_CIN_272
	je [0x23], 0x07, DRAW_CIN_271
	je [0x23], 0x08, DRAW_CIN_272
	je [0x23], 0x09, DRAW_CIN_273
	je [0x23], 0x0A, DRAW_CIN_274
	je [0x23], 0x0B, DRAW_CIN_273
	je [0x23], 0x0C, DRAW_CIN_272

DRAW_CIN_271:
	video offset=CINEMATIC_271, x=[0x21], y=[0x22]
	ret

DRAW_CIN_272:
	video offset=CINEMATIC_272, x=[0x21], y=[0x22]
	ret

DRAW_CIN_273:
	video offset=CINEMATIC_273, x=[0x21], y=[0x22]
	ret

DRAW_CIN_274:
	video offset=CINEMATIC_274, x=[0x21], y=[0x22]
	ret

HANG_DRAW_CIN_270:
	video offset=CINEMATIC_270, x=[0xe6], y=[0xe7]
	break
	jmp HANG_DRAW_CIN_270
LABEL_355B:
	db 0x11
