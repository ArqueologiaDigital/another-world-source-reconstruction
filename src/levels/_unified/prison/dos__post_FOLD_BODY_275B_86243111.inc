LABEL_50B2:
	break
	sub [0x15], 0x0001
	djnz [0x16], LABEL_50B2
	mov [0x16], 0x0004

LABEL_50BF:
	break
	add [0x15], 0x0001
	djnz [0x16], LABEL_50BF
	mov [0x16], 0x0006
	mov [PAUSE_SLICES], 0x000A

LABEL_50D0:
	break
	sub [0x15], 0x0001
	djnz [0x16], LABEL_50D0
	break
	mov [PAUSE_SLICES], 0x000B
	break
	copyVideoPage src=0xFE, dst=0x00
	setup channel=0x02, address=KILL_CHANNEL_LANDING
	break
	mov [PAUSE_SLICES], 0x0008
	video offset=CINEMATIC_686, x=160, y=100
	break
	video offset=CINEMATIC_687, x=160, y=100
	break
	mov [0x16], 0x0005

DELAY_LOOP_VAR16:
	break
	djnz [0x16], DELAY_LOOP_VAR16
	mov [PAUSE_SLICES], 0x0004
	deleteChannels first=0x01, last=0x03
	setup channel=0x3C, address=BLIT_PAGE_00_TO_FF_AND_BREAK
	setup channel=0x22, address=LABEL_4CB9
	setup channel=0x23, address=LABEL_4B6A
	setup channel=0x14, address=INIT_VARS_15_19_18_14_PLUS4
	setup channel=0x15, address=LABEL_7830
	setup channel=0x00, address=LABEL_1CB0
	call LABEL_1CC1
	killChannel

DRAW_SPRITE_CIN_236_239_BY_VAR09:
	mov [0xF8], [0x09]
	shr [0xF8], 0x0004
	jne [0x0E], 0x00, LABEL_5148
	je [0xF8], 0x00, DRAW_CIN_236
	je [0xF8], 0x01, DRAW_CIN_237
	je [0xF8], 0x02, DRAW_CIN_238
	je [0xF8], 0x03, DRAW_CIN_239
	ret

LABEL_5148:
	jne [0x0E], 0x01, LABEL_5157
	je [0xF8], 0x01, DRAW_CIN_234
	jmp DRAW_CIN_235

LABEL_5157:
	jne [0x0E], 0x02, LABEL_5166
	je [0xF8], 0x01, DRAW_CIN_232
	jmp DRAW_CIN_233

LABEL_5166:
	jne [0x0E], 0x03, LABEL_516F
	jmp DRAW_CIN_231

LABEL_516F:
	jne [0x0E], 0x04, LABEL_517E
	je [0xF8], 0x01, DRAW_CIN_229
	jmp DRAW_CIN_230

LABEL_517E:
	jne [0x0E], 0x05, LABEL_5187
	jmp DRAW_CIN_228

LABEL_5187:
	jne [0x0E], 0x06, LABEL_5193
	video offset=CINEMATIC_227, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_5193:
	jne [0x0E], 0x07, LABEL_51A6
	je [0xF8], 0x00, DRAW_CIN_225
	je [0xF8], 0x01, DRAW_CIN_226
	ret

LABEL_51A6:
	ret
LABEL_51A7:
	db 0x11
