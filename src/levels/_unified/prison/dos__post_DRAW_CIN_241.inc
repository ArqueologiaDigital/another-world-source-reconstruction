LABEL_5363:
	video type=0, offset=COMMON_VIDEO_239, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jg [0xF6], 0x00, DRAW_CIN_241_IF_VAR09_EQ_1
	video type=0, offset=COMMON_VIDEO_240, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_241_IF_VAR09_EQ_1

LABEL_5379:
	video type=0, offset=COMMON_VIDEO_206, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jg [0xF6], 0x00, DRAW_CIN_241_IF_VAR09_EQ_1
	video type=0, offset=COMMON_VIDEO_207, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_241_IF_VAR09_EQ_1

LABEL_538F:
	video type=0, offset=COMMON_VIDEO_165, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	sub [0xF5], 0x0001
	jg [0xF6], 0x00, DRAW_CIN_241_IF_VAR09_EQ_1
	video type=0, offset=COMMON_VIDEO_166, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_241_IF_VAR09_EQ_1

LABEL_53A9:
	video type=0, offset=COMMON_VIDEO_211, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jg [0xF6], 0x00, DRAW_CIN_241_IF_VAR09_EQ_1
	video type=0, offset=COMMON_VIDEO_212, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_241_IF_VAR09_EQ_1

LABEL_53BF:
	video type=0, offset=COMMON_VIDEO_214, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	add [0xF5], 0x0001
	jg [0xF6], 0x00, DRAW_CIN_241_IF_VAR09_EQ_1
	video type=0, offset=COMMON_VIDEO_215, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_241_IF_VAR09_EQ_1

LABEL_53D9:
	video type=0, offset=COMMON_VIDEO_218, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	add [0xF5], 0x0001
	jg [0xF6], 0x00, DRAW_CIN_241_IF_VAR09_EQ_1
	video type=0, offset=COMMON_VIDEO_219, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_241_IF_VAR09_EQ_1

LABEL_53F3:
	video type=0, offset=COMMON_VIDEO_222, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	add [0xF5], 0x0002
	jg [0xF6], 0x00, DRAW_CIN_241_IF_VAR09_EQ_1
	video type=0, offset=COMMON_VIDEO_223, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_241_IF_VAR09_EQ_1

LABEL_540D:
	video type=0, offset=COMMON_VIDEO_226, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	add [0xF5], 0x0002
	jg [0xF6], 0x00, DRAW_CIN_241_IF_VAR09_EQ_1
	video type=0, offset=COMMON_VIDEO_227, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_241_IF_VAR09_EQ_1

LABEL_5427:
	video type=0, offset=COMMON_VIDEO_230, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	add [0xF5], 0x0002
	jg [0xF6], 0x00, DRAW_CIN_241_IF_VAR09_EQ_1
	video type=0, offset=COMMON_VIDEO_231, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_241_IF_VAR09_EQ_1

LABEL_5441:
	video type=0, offset=COMMON_VIDEO_268, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jmp DRAW_CIN_241_IF_VAR09_EQ_1

LABEL_544C:
	video type=0, offset=COMMON_VIDEO_271, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jmp DRAW_CIN_241_IF_VAR09_EQ_1

LABEL_5457:
	video type=0, offset=COMMON_VIDEO_274, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jmp DRAW_CIN_241_IF_VAR09_EQ_1

LABEL_5462:
	video type=0, offset=COMMON_VIDEO_277, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jmp DRAW_CIN_241_IF_VAR09_EQ_1

LABEL_546D:
	video type=0, offset=COMMON_VIDEO_281, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jmp DRAW_CIN_241_IF_VAR09_EQ_1

LABEL_5478:
	video type=0, offset=COMMON_VIDEO_283, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jmp DRAW_CIN_241_IF_VAR09_EQ_1

LABEL_5483:
	video type=0, offset=COMMON_VIDEO_265, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jmp DRAW_CIN_241_IF_VAR09_EQ_1

LABEL_548E:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, DRAW_CV204_AT_X07_Y08
	call LABEL_532E
	jmp LABEL_54A5
