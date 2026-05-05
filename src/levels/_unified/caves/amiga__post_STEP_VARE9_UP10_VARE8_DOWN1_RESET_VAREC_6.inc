DELAY_LOOP_VAREC_AT_32D6:
	break
	djnz [0xEC], DELAY_LOOP_VAREC_AT_32D6
	mov [0xE9], [0xE7]
	mov [0xE8], [0xE6]
	jmp STEP_VARE9_UP10_VARE8_DOWN1_RESET_VAREC_6
LABEL_32E4:
	db 0x11

LABEL_32E5:
	je [0x23], 0x01, DRAW_CIN_254
	je [0x23], 0x02, DRAW_CIN_255
	je [0x23], 0x03, DRAW_CIN_256
	je [0x23], 0x04, DRAW_CIN_257
	je [0x23], 0x05, DRAW_CIN_256
	je [0x23], 0x06, DRAW_CIN_255
	je [0x23], 0x07, DRAW_CIN_254
	je [0x23], 0x08, DRAW_CIN_255
	je [0x23], 0x09, DRAW_CIN_256
	je [0x23], 0x0A, DRAW_CIN_257
	je [0x23], 0x0B, DRAW_CIN_256
	je [0x23], 0x0C, DRAW_CIN_255

DRAW_CIN_254:
	video offset=CINEMATIC_254, x=[0x21], y=[0x22], zoom=0x40
	ret

DRAW_CIN_255:
	video offset=CINEMATIC_255, x=[0x21], y=[0x22], zoom=0x40
	ret

DRAW_CIN_256:
	video offset=CINEMATIC_256, x=[0x21], y=[0x22], zoom=0x40
	ret

DRAW_CIN_257:
	video offset=CINEMATIC_257, x=[0x21], y=[0x22], zoom=0x40
	ret

HANG_DRAW_CIN_253:
	video offset=CINEMATIC_253, x=[0xe6], y=[0xe7], zoom=0x40
	break
	jmp HANG_DRAW_CIN_253
LABEL_334E:
	db 0x11
