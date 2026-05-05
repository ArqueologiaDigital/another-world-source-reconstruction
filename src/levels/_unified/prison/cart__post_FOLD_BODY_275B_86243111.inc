LABEL_51B2:
	break
	sub [0x15], 0x0001
	djnz [0x16], LABEL_51B2
	mov [0x16], 0x0004

LABEL_51BF:
	break
	add [0x15], 0x0001
	djnz [0x16], LABEL_51BF
	mov [0x16], 0x0006
	mov [PAUSE_SLICES], 0x000A

LABEL_51D0:
	break
	sub [0x15], 0x0001
	djnz [0x16], LABEL_51D0
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
	setup channel=0x22, address=LABEL_4DB9
	setup channel=0x23, address=LABEL_4C64
	setup channel=0x14, address=INIT_VARS_15_19_18_14_PLUS4
	setup channel=0x15, address=LABEL_7939
	setup channel=0x00, address=LABEL_1D52
	call LABEL_1D63
	call LABEL_0054
	killChannel

DRAW_SPRITE_CIN_236_239_BY_VAR09:
	mov [0xF8], [0x09]
	shr [0xF8], 0x0004
	jne [0x0E], 0x00, LABEL_524B
	je [0xF8], 0x00, DRAW_CIN_236
	je [0xF8], 0x01, DRAW_CIN_237
	je [0xF8], 0x02, DRAW_CIN_238
	je [0xF8], 0x03, DRAW_CIN_239
	ret

LABEL_524B:
	jne [0x0E], 0x01, LABEL_525A
	je [0xF8], 0x01, DRAW_CIN_234
	jmp DRAW_CIN_235

LABEL_525A:
	jne [0x0E], 0x02, LABEL_5269
	je [0xF8], 0x01, DRAW_CIN_232
	jmp DRAW_CIN_233

LABEL_5269:
	jne [0x0E], 0x03, LABEL_5272
	jmp DRAW_CIN_231

LABEL_5272:
	jne [0x0E], 0x04, LABEL_5281
	je [0xF8], 0x01, DRAW_CIN_229
	jmp DRAW_CIN_230

LABEL_5281:
	jne [0x0E], 0x05, LABEL_528A
	jmp DRAW_CIN_228

LABEL_528A:
	jne [0x0E], 0x06, LABEL_5296
	video offset=CINEMATIC_227, x=[BUDDY_X], y=[BUDDY_Y]
	ret

LABEL_5296:
	jne [0x0E], 0x07, LABEL_52A9
	je [0xF8], 0x00, DRAW_CIN_225
	je [0xF8], 0x01, DRAW_CIN_226
	ret

LABEL_52A9:
	ret
LABEL_52AA:
	db 0x11

DRAW_CIN_236:
	video offset=CINEMATIC_236, x=[BUDDY_X], y=[BUDDY_Y]
	ret

DRAW_CIN_237:
	video offset=CINEMATIC_237, x=[BUDDY_X], y=[BUDDY_Y]
	ret

DRAW_CIN_238:
	video offset=CINEMATIC_238, x=[BUDDY_X], y=[BUDDY_Y]
	ret

DRAW_CIN_239:
	video offset=CINEMATIC_239, x=[BUDDY_X], y=[BUDDY_Y]
	ret

DRAW_CIN_235:
	video offset=CINEMATIC_235, x=[BUDDY_X], y=[BUDDY_Y]
	ret

DRAW_CIN_234:
	video offset=CINEMATIC_234, x=[BUDDY_X], y=[BUDDY_Y]
	ret

DRAW_CIN_233:
	video offset=CINEMATIC_233, x=[BUDDY_X], y=[BUDDY_Y]
	ret

DRAW_CIN_232:
	video offset=CINEMATIC_232, x=[BUDDY_X], y=[BUDDY_Y]
	ret

DRAW_CIN_231:
	video offset=CINEMATIC_231, x=[BUDDY_X], y=[BUDDY_Y]
	ret

DRAW_CIN_230:
	video offset=CINEMATIC_230, x=[BUDDY_X], y=[BUDDY_Y]
	ret

DRAW_CIN_229:
	video offset=CINEMATIC_229, x=[BUDDY_X], y=[BUDDY_Y]
	ret

DRAW_CIN_228:
	video offset=CINEMATIC_228, x=[BUDDY_X], y=[BUDDY_Y]
	ret

DRAW_CIN_225:
	video offset=CINEMATIC_225, x=[BUDDY_X], y=[BUDDY_Y]
	ret

DRAW_CIN_226:
	video offset=CINEMATIC_226, x=[BUDDY_X], y=[BUDDY_Y]
	ret

LABEL_52FF:
	mov [0xF8], [0x09]
	and [0xF8], 0x000F
	je [0xF8], 0x01, DRAW_CIN_352
	ret

DRAW_CIN_352:
	video offset=CINEMATIC_352, x=[0xf5], y=[BUDDY_Y]
	ret

LABEL_5313:
	mov [0xF8], [0x09]
	and [0xF8], 0x000F
	je [0xF8], 0x01, LABEL_5321
	ret

LABEL_5321:
	add [BUDDY_Y], 0x000D
	sub [BUDDY_X], 0x0002
	video offset=CINEMATIC_169, x=[BUDDY_X], y=[BUDDY_Y]
	add [BUDDY_X], 0x0002
	sub [BUDDY_Y], 0x000D
	ret

LABEL_5337:
	video offset=CINEMATIC_351, x=[BUDDY_X], y=[BUDDY_Y]
	mov [0xF5], [BUDDY_X]
	jg [0xF6], 0x00, LABEL_534A
	video offset=CINEMATIC_354, x=[BUDDY_X], y=[BUDDY_Y]

LABEL_534A:
	jg [0x13], [0x30], LABEL_52FF
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, LABEL_52FF
	video offset=CINEMATIC_353, x=[BUDDY_X], y=[BUDDY_Y]
	jmp LABEL_52FF

LABEL_5365:
	video offset=CINEMATIC_355, x=[BUDDY_X], y=[BUDDY_Y]
	mov [0xF5], [BUDDY_X]
	sub [0xF5], 0x0001
	jg [0xF6], 0x00, LABEL_537C
	video offset=CINEMATIC_357, x=[BUDDY_X], y=[BUDDY_Y]

LABEL_537C:
	jg [0x13], [0x30], LABEL_52FF
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, LABEL_52FF
	video offset=CINEMATIC_356, x=[BUDDY_X], y=[BUDDY_Y]
	jmp LABEL_52FF

LABEL_5397:
	video offset=CINEMATIC_358, x=[BUDDY_X], y=[BUDDY_Y]
	jg [0x13], [0x30], LABEL_5313
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, LABEL_5313
	video offset=CINEMATIC_359, x=[BUDDY_X], y=[BUDDY_Y]
	jmp LABEL_5313

LABEL_53B7:
	video offset=CINEMATIC_360, x=[BUDDY_X], y=[BUDDY_Y]
	jmp LABEL_5313

LABEL_53BF:
	sub [BUDDY_X], 0x0001
	call LABEL_53CB
	add [BUDDY_X], 0x0001
	ret

LABEL_53CB:
	video offset=CINEMATIC_340, x=[BUDDY_X], y=[BUDDY_Y]
	jg [0x13], [0x30], SHARED_RET_AT_543D
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET_AT_543D
	video offset=CINEMATIC_341, x=[BUDDY_X], y=[BUDDY_Y]
	ret

LABEL_53E9:
	sub [BUDDY_X], 0x0001
	call DRAW_CIN_338_THEN_339
	add [BUDDY_X], 0x0001
	ret

DRAW_CIN_338_THEN_339:
	video offset=CINEMATIC_338, x=[BUDDY_X], y=[BUDDY_Y]
	jg [0x13], [0x30], SHARED_RET_AT_543D
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET_AT_543D
	video offset=CINEMATIC_339, x=[BUDDY_X], y=[BUDDY_Y]
	ret

DRAW_CIN_242_THEN_243:
	video offset=CINEMATIC_242, x=[BUDDY_X], y=[BUDDY_Y]
	jg [0x13], [0x30], SHARED_RET_AT_543D
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET_AT_543D
	video offset=CINEMATIC_243, x=[BUDDY_X], y=[BUDDY_Y]
	ret

LABEL_5431:
	add [BUDDY_X], 0x0001
	call DRAW_CIN_242_THEN_243
	sub [BUDDY_X], 0x0001
	ret
