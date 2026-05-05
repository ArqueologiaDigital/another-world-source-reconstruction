DRAW_CIN_054_055_056_VAR09:
	mov [0xF8], [0x09]
	and [0xF8], 0x000F
	je [0xF8], 0x01, DRAW_CIN_054
	je [0xF8], 0x02, DRAW_CIN_055
	je [0xF8], 0x03, DRAW_CIN_056
	ret

DRAW_CIN_054:
	video offset=CINEMATIC_054, x=[0x07], y=[0x08]
	ret

DRAW_CIN_055:
	video offset=CINEMATIC_055, x=[0x07], y=[0x08]
	ret

DRAW_CIN_056:
	video offset=CINEMATIC_056, x=[0x07], y=[0x08]
	ret

DRAW_CIN_057_058_VAR09_LOW:
	mov [0xF8], [0x09]
	and [0xF8], 0x000F
	je [0xF8], 0x01, DRAW_CIN_057
	je [0xF8], 0x02, DRAW_CIN_058
	ret

DRAW_CIN_057:
	video offset=CINEMATIC_057, x=[0xf5], y=[0x08]
	ret

DRAW_CIN_058:
	video offset=CINEMATIC_058, x=[0xf5], y=[0x08]
	ret

LABEL_82D4:
	jg [0x09], 0x03FF, SHARED_RET
	video type=0, offset=COMMON_VIDEO_239, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jg [0xF6], 0x00, DRAW_CIN_057_058_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_240, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_057_058_VAR09_LOW

LABEL_82F1:
	jg [0x09], 0x03FF, SHARED_RET
	video type=0, offset=COMMON_VIDEO_206, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jg [0xF6], 0x00, DRAW_CIN_057_058_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_207, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_057_058_VAR09_LOW

DRAW_BEAST_HEAD_CV165_166:
	jg [0x09], 0x03FF, SHARED_RET
	video type=0, offset=COMMON_VIDEO_165, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	sub [0xF5], 0x0001
	jg [0xF6], 0x00, DRAW_CIN_057_058_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_166, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_057_058_VAR09_LOW

DRAW_BEAST_HEAD_CV211_212:
	jg [0x09], 0x03FF, SHARED_RET
	video type=0, offset=COMMON_VIDEO_211, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jg [0xF6], 0x00, DRAW_CIN_057_058_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_212, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_057_058_VAR09_LOW

DRAW_BEAST_HEAD_CV214_215:
	jg [0x09], 0x03FF, SHARED_RET
	video type=0, offset=COMMON_VIDEO_214, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	add [0xF5], 0x0001
	jg [0xF6], 0x00, DRAW_CIN_057_058_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_215, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_057_058_VAR09_LOW

LABEL_836D:
	jg [0x09], 0x03FF, SHARED_RET
	video type=0, offset=COMMON_VIDEO_218, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	add [0xF5], 0x0001
	jg [0xF6], 0x00, DRAW_CIN_057_058_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_219, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_057_058_VAR09_LOW

LABEL_838E:
	jg [0x09], 0x03FF, SHARED_RET
	video type=0, offset=COMMON_VIDEO_222, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	add [0xF5], 0x0002
	jg [0xF6], 0x00, DRAW_CIN_057_058_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_223, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_057_058_VAR09_LOW

LABEL_83AF:
	jg [0x09], 0x03FF, SHARED_RET
	video type=0, offset=COMMON_VIDEO_226, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	add [0xF5], 0x0002
	jg [0xF6], 0x00, DRAW_CIN_057_058_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_227, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_057_058_VAR09_LOW

LABEL_83D0:
	jg [0x09], 0x03FF, SHARED_RET
	video type=0, offset=COMMON_VIDEO_230, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	add [0xF5], 0x0002
	jg [0xF6], 0x00, DRAW_CIN_057_058_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_231, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_057_058_VAR09_LOW

LABEL_83F1:
	video type=0, offset=COMMON_VIDEO_268, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jmp DRAW_CIN_057_058_VAR09_LOW

LABEL_83FC:
	video type=0, offset=COMMON_VIDEO_271, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jmp DRAW_CIN_057_058_VAR09_LOW

LABEL_8407:
	video type=0, offset=COMMON_VIDEO_274, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jmp DRAW_CIN_057_058_VAR09_LOW

LABEL_8412:
	video type=0, offset=COMMON_VIDEO_277, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jmp DRAW_CIN_057_058_VAR09_LOW

LABEL_841D:
	video type=0, offset=COMMON_VIDEO_281, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jmp DRAW_CIN_057_058_VAR09_LOW

LABEL_8428:
	video type=0, offset=COMMON_VIDEO_283, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jmp DRAW_CIN_057_058_VAR09_LOW

LABEL_8433:
	video type=0, offset=COMMON_VIDEO_265, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jmp DRAW_CIN_057_058_VAR09_LOW

LABEL_843E:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, DRAW_CV204_AT_X07_Y08
	call LABEL_827B
	jmp LABEL_8455
