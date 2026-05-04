LABEL_7FE1:
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_276, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_7A40
	ret

LABEL_7FED:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	sub [0x08], 0x0001
	je [0x0D], 0x00, LABEL_8003
	call LABEL_7861
	jmp LABEL_8008

LABEL_8003:
	video type=0, offset=COMMON_VIDEO_272, x=[0x07], y=[0x08], zoom=0x40

LABEL_8008:
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_278, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_7A40
	add [0x08], 0x0001
	ret

LABEL_8018:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, LABEL_802A
	call LABEL_7861
	jmp LABEL_802F

LABEL_802A:
	video type=0, offset=COMMON_VIDEO_272, x=[0x07], y=[0x08], zoom=0x40

LABEL_802F:
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_279, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_7A35
	ret

LABEL_803B:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	play id=0x0055, freq=0x0F, vol=0x14, channel=0x00
	add [0x08], 0x0001
	je [0x0D], 0x00, LABEL_8057
	call LABEL_7843
	jmp LABEL_805C

LABEL_8057:
	video type=0, offset=COMMON_VIDEO_269, x=[0x07], y=[0x08], zoom=0x40

LABEL_805C:
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_280, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_7A4B
	sub [0x08], 0x0001
	ret

LABEL_806C:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x08], 0x0001
	je [0x0D], 0x00, LABEL_8082
	call LABEL_7837
	jmp LABEL_8087

LABEL_8082:
	video type=0, offset=COMMON_VIDEO_269, x=[0x07], y=[0x08], zoom=0x40

LABEL_8087:
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_282, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_7A56
	sub [0x08], 0x0001
	ret

LABEL_8097:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, LABEL_80A9
	call LABEL_7843
	jmp LABEL_80AE

LABEL_80A9:
	video type=0, offset=COMMON_VIDEO_266, x=[0x07], y=[0x08], zoom=0x40

LABEL_80AE:
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_284, x=[0x07], y=[0x08], zoom=0x40
	add [0x07], 0x0001
	call LABEL_7A61
	sub [0x07], 0x0001
	ret

LABEL_80C2:
	call AND_VAR11_WITH_EFFF
	jmp LABEL_80D1
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_4B0A

LABEL_80D1:
	call LABEL_7F20
	sub [0x07], 0x0007
	break
	jg [0x07], [0x29], LABEL_80E8
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_4B0A

LABEL_80E8:
	call LABEL_7F4B
	sub [0x07], 0x0009
	break
	jg [0x07], [0x29], LABEL_80FF
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_4B0A

LABEL_80FF:
	call LABEL_7F6E
	sub [0x07], 0x0009
	break
	jg [0x07], [0x29], LABEL_8116
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_4B0A

LABEL_8116:
	call LABEL_7F99
	sub [0x07], 0x0008
	break
	jg [0x07], [0x29], LABEL_812D
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_4B0A

LABEL_812D:
	call LABEL_7FCA
	sub [0x07], 0x000A
	break
	jg [0x07], [0x29], LABEL_8144
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_4B0A

LABEL_8144:
	call LABEL_7FED
	sub [0x07], 0x0007
	break
	jg [0x07], [0x29], LABEL_815B
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_4B0A

LABEL_815B:
	call LABEL_8018
	sub [0x07], 0x0009
	break
	jg [0x07], [0x29], LABEL_8172
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_4B0A

LABEL_8172:
	call LABEL_803B
	sub [0x07], 0x0009
	break
	jg [0x07], [0x29], LABEL_8189
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_4B0A

LABEL_8189:
	call LABEL_806C
	sub [0x07], 0x0008
	break
	jg [0x07], [0x29], LABEL_81A0
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_4B0A

LABEL_81A0:
	call LABEL_8097
	sub [0x07], 0x000A
	break
	jmp LABEL_80C2
LABEL_81AB:
	db 0x11

LABEL_81AC:
	video type=0, offset=COMMON_VIDEO_314, x=[0x07], y=[0x08], zoom=0x40
	jg [0x13], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0002
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_315, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_81CA:
	video type=0, offset=COMMON_VIDEO_316, x=[0x07], y=[0x08], zoom=0x40
	jg [0x13], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0002
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_317, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_81E8:
	video type=0, offset=COMMON_VIDEO_318, x=[0x07], y=[0x08], zoom=0x40
	jg [0x13], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_319, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_8206:
	add [0x07], 0x0001
	call LABEL_8212
	sub [0x07], 0x0001
	ret

LABEL_8212:
	video type=0, offset=COMMON_VIDEO_302, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jg [0x13], [0x30], DRAW_CIN_111_112_VAR09_LOW
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, DRAW_CIN_111_112_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_303, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_111_112_VAR09_LOW

LABEL_8235:
	add [0x07], 0x0001
	call LABEL_8241
	sub [0x07], 0x0001
	ret

LABEL_8241:
	video type=0, offset=COMMON_VIDEO_310, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jg [0x13], [0x30], DRAW_CIN_111_112_VAR09_LOW
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, DRAW_CIN_111_112_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_311, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_111_112_VAR09_LOW

LABEL_8264:
	video type=0, offset=COMMON_VIDEO_312, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jg [0x13], [0x30], DRAW_CIN_111_112_VAR09_LOW
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, DRAW_CIN_111_112_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_313, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_111_112_VAR09_LOW

LABEL_8287:
	sub [0x07], 0x0001
	call LABEL_8235
	add [0x07], 0x0001
	ret

LABEL_8293:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	sub [0x08], 0x0001
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_241, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_242, x=[0x07], y=[0x08], zoom=0x40
	je [0x0D], 0x00, LABEL_82B6
	call LABEL_8235
	jmp LABEL_82BB

LABEL_82B6:
	video type=0, offset=COMMON_VIDEO_243, x=[0x07], y=[0x08], zoom=0x40

LABEL_82BB:
	add [0x08], 0x0001
	ret

LABEL_82C0:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_244, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_245, x=[0x07], y=[0x08], zoom=0x40
	je [0x0D], 0x00, DRAW_CV246_AT_X07_Y08
	call LABEL_8235
	jmp LABEL_82E4
