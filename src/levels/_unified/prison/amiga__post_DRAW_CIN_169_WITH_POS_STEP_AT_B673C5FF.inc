LABEL_5187:
	video offset=CINEMATIC_351, x=[BUDDY_X], y=[BUDDY_Y]
	mov [0xF5], [BUDDY_X]
	jg [0xF6], 0x00, LABEL_519A
	video offset=CINEMATIC_354, x=[BUDDY_X], y=[BUDDY_Y]

LABEL_519A:
	jg [0x13], [0x30], LABEL_514F
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, LABEL_514F
	video offset=CINEMATIC_353, x=[BUDDY_X], y=[BUDDY_Y]
	jmp LABEL_514F

LABEL_51B5:
	video offset=CINEMATIC_355, x=[BUDDY_X], y=[BUDDY_Y]
	mov [0xF5], [BUDDY_X]
	sub [0xF5], 0x0001
	jg [0xF6], 0x00, LABEL_51CC
	video offset=CINEMATIC_357, x=[BUDDY_X], y=[BUDDY_Y]

LABEL_51CC:
	jg [0x13], [0x30], LABEL_514F
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, LABEL_514F
	video offset=CINEMATIC_356, x=[BUDDY_X], y=[BUDDY_Y]
	jmp LABEL_514F

LABEL_51E7:
	video offset=CINEMATIC_358, x=[BUDDY_X], y=[BUDDY_Y]
	jg [0x13], [0x30], LABEL_5163
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, LABEL_5163
	video offset=CINEMATIC_359, x=[BUDDY_X], y=[BUDDY_Y]
	jmp LABEL_5163

LABEL_5207:
	video offset=CINEMATIC_360, x=[BUDDY_X], y=[BUDDY_Y]
	jmp LABEL_5163

LABEL_520F:
	sub [BUDDY_X], 0x0001
	call LABEL_521B
	add [BUDDY_X], 0x0001
	ret

LABEL_521B:
	video offset=CINEMATIC_340, x=[BUDDY_X], y=[BUDDY_Y]
	jg [0x13], [0x30], SHARED_RET_AT_528D
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET_AT_528D
	video offset=CINEMATIC_341, x=[BUDDY_X], y=[BUDDY_Y]
	ret

LABEL_5239:
	sub [BUDDY_X], 0x0001
	call DRAW_CIN_338_THEN_339
	add [BUDDY_X], 0x0001
	ret

DRAW_CIN_338_THEN_339:
	video offset=CINEMATIC_338, x=[BUDDY_X], y=[BUDDY_Y]
	jg [0x13], [0x30], SHARED_RET_AT_528D
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET_AT_528D
	video offset=CINEMATIC_339, x=[BUDDY_X], y=[BUDDY_Y]
	ret

DRAW_CIN_242_THEN_243:
	video offset=CINEMATIC_242, x=[BUDDY_X], y=[BUDDY_Y]
	jg [0x13], [0x30], SHARED_RET_AT_528D
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET_AT_528D
	video offset=CINEMATIC_243, x=[BUDDY_X], y=[BUDDY_Y]
	ret

LABEL_5281:
	add [BUDDY_X], 0x0001
	call DRAW_CIN_242_THEN_243
	sub [BUDDY_X], 0x0001
	ret
