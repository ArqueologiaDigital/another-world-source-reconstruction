LABEL_5234:
	video offset=CINEMATIC_351, x=[BUDDY_X], y=[BUDDY_Y]
	mov [0xF5], [BUDDY_X]
	jg [0xF6], 0x00, LABEL_5247
	video offset=CINEMATIC_354, x=[BUDDY_X], y=[BUDDY_Y]

LABEL_5247:
	jg [0x13], [0x30], LABEL_51FC
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, LABEL_51FC
	video offset=CINEMATIC_353, x=[BUDDY_X], y=[BUDDY_Y]
	jmp LABEL_51FC

LABEL_5262:
	video offset=CINEMATIC_355, x=[BUDDY_X], y=[BUDDY_Y]
	mov [0xF5], [BUDDY_X]
	sub [0xF5], 0x0001
	jg [0xF6], 0x00, LABEL_5279
	video offset=CINEMATIC_357, x=[BUDDY_X], y=[BUDDY_Y]

LABEL_5279:
	jg [0x13], [0x30], LABEL_51FC
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, LABEL_51FC
	video offset=CINEMATIC_356, x=[BUDDY_X], y=[BUDDY_Y]
	jmp LABEL_51FC

LABEL_5294:
	video offset=CINEMATIC_358, x=[BUDDY_X], y=[BUDDY_Y]
	jg [0x13], [0x30], LABEL_5210
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, LABEL_5210
	video offset=CINEMATIC_359, x=[BUDDY_X], y=[BUDDY_Y]
	jmp LABEL_5210

LABEL_52B4:
	video offset=CINEMATIC_360, x=[BUDDY_X], y=[BUDDY_Y]
	jmp LABEL_5210

LABEL_52BC:
	sub [BUDDY_X], 0x0001
	call LABEL_52C8
	add [BUDDY_X], 0x0001
	ret

LABEL_52C8:
	video offset=CINEMATIC_340, x=[BUDDY_X], y=[BUDDY_Y]
	jg [0x13], [0x30], SHARED_RET_AT_533A
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET_AT_533A
	video offset=CINEMATIC_341, x=[BUDDY_X], y=[BUDDY_Y]
	ret

LABEL_52E6:
	sub [BUDDY_X], 0x0001
	call DRAW_CIN_338_THEN_339
	add [BUDDY_X], 0x0001
	ret

DRAW_CIN_338_THEN_339:
	video offset=CINEMATIC_338, x=[BUDDY_X], y=[BUDDY_Y]
	jg [0x13], [0x30], SHARED_RET_AT_533A
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET_AT_533A
	video offset=CINEMATIC_339, x=[BUDDY_X], y=[BUDDY_Y]
	ret

DRAW_CIN_242_THEN_243:
	video offset=CINEMATIC_242, x=[BUDDY_X], y=[BUDDY_Y]
	jg [0x13], [0x30], SHARED_RET_AT_533A
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET_AT_533A
	video offset=CINEMATIC_243, x=[BUDDY_X], y=[BUDDY_Y]
	ret

LABEL_532E:
	add [BUDDY_X], 0x0001
	call DRAW_CIN_242_THEN_243
	sub [BUDDY_X], 0x0001
	ret
