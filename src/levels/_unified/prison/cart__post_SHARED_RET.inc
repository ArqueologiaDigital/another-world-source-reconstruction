DRAW_CIN_240_IF_VAR09_EQ_1:
	mov [0xF8], [0x09]
	and [0xF8], 0x000F
	je [0xF8], 0x01, DRAW_CIN_240__CART__POST_SHARED_RET
	ret

DRAW_CIN_240__CART__POST_SHARED_RET:
	video type=1, offset=CINEMATIC_240, x=[0x07], y=[0x08], zoom=0x40
	ret

DRAW_CIN_241_IF_VAR09_EQ_1:
	mov [0xF8], [0x09]
	and [0xF8], 0x000F
	je [0xF8], 0x01, DRAW_CIN_241__CART__POST_SHARED_RET
	ret

DRAW_CIN_241__CART__POST_SHARED_RET:
	video type=1, offset=CINEMATIC_241, x=[0xf5], y=[0x08], zoom=0x40
	ret

LABEL_5466:
	video type=0, offset=COMMON_VIDEO_239, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jg [0xF6], 0x00, DRAW_CIN_241_IF_VAR09_EQ_1
	video type=0, offset=COMMON_VIDEO_240, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_241_IF_VAR09_EQ_1

LABEL_547C:
	video type=0, offset=COMMON_VIDEO_206, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jg [0xF6], 0x00, DRAW_CIN_241_IF_VAR09_EQ_1
	video type=0, offset=COMMON_VIDEO_207, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_241_IF_VAR09_EQ_1

LABEL_5492:
	video type=0, offset=COMMON_VIDEO_165, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	sub [0xF5], 0x0001
	jg [0xF6], 0x00, DRAW_CIN_241_IF_VAR09_EQ_1
	video type=0, offset=COMMON_VIDEO_166, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_241_IF_VAR09_EQ_1

LABEL_54AC:
	video type=0, offset=COMMON_VIDEO_211, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jg [0xF6], 0x00, DRAW_CIN_241_IF_VAR09_EQ_1
	video type=0, offset=COMMON_VIDEO_212, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_241_IF_VAR09_EQ_1

LABEL_54C2:
	video type=0, offset=COMMON_VIDEO_214, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	add [0xF5], 0x0001
	jg [0xF6], 0x00, DRAW_CIN_241_IF_VAR09_EQ_1
	video type=0, offset=COMMON_VIDEO_215, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_241_IF_VAR09_EQ_1

LABEL_54DC:
	video type=0, offset=COMMON_VIDEO_218, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	add [0xF5], 0x0001
	jg [0xF6], 0x00, DRAW_CIN_241_IF_VAR09_EQ_1
	video type=0, offset=COMMON_VIDEO_219, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_241_IF_VAR09_EQ_1

LABEL_54F6:
	video type=0, offset=COMMON_VIDEO_222, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	add [0xF5], 0x0002
	jg [0xF6], 0x00, DRAW_CIN_241_IF_VAR09_EQ_1
	video type=0, offset=COMMON_VIDEO_223, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_241_IF_VAR09_EQ_1

LABEL_5510:
	video type=0, offset=COMMON_VIDEO_226, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	add [0xF5], 0x0002
	jg [0xF6], 0x00, DRAW_CIN_241_IF_VAR09_EQ_1
	video type=0, offset=COMMON_VIDEO_227, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_241_IF_VAR09_EQ_1

LABEL_552A:
	video type=0, offset=COMMON_VIDEO_230, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	add [0xF5], 0x0002
	jg [0xF6], 0x00, DRAW_CIN_241_IF_VAR09_EQ_1
	video type=0, offset=COMMON_VIDEO_231, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_241_IF_VAR09_EQ_1

LABEL_5544:
	video type=0, offset=COMMON_VIDEO_268, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jmp DRAW_CIN_241_IF_VAR09_EQ_1

LABEL_554F:
	video type=0, offset=COMMON_VIDEO_271, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jmp DRAW_CIN_241_IF_VAR09_EQ_1

LABEL_555A:
	video type=0, offset=COMMON_VIDEO_274, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jmp DRAW_CIN_241_IF_VAR09_EQ_1

LABEL_5565:
	video type=0, offset=COMMON_VIDEO_277, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jmp DRAW_CIN_241_IF_VAR09_EQ_1

LABEL_5570:
	video type=0, offset=COMMON_VIDEO_281, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jmp DRAW_CIN_241_IF_VAR09_EQ_1

LABEL_557B:
	video type=0, offset=COMMON_VIDEO_283, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jmp DRAW_CIN_241_IF_VAR09_EQ_1

LABEL_5586:
	video type=0, offset=COMMON_VIDEO_265, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jmp DRAW_CIN_241_IF_VAR09_EQ_1

LABEL_5591:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, DRAW_CV204_AT_X07_Y08
	call LABEL_5431
	jmp LABEL_55A8
