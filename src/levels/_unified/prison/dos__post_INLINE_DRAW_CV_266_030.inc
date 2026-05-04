LABEL_5AC8:
	call DRAW_SPRITE_CIN_236_239_BY_VAR09
	video type=0, offset=COMMON_VIDEO_284, x=[0x07], y=[0x08], zoom=0x40
	add [0x07], 0x0001
	call LABEL_5483
	sub [0x07], 0x0001
	ret

LABEL_5ADC:
	call AND_VAR11_WITH_EFFF
	jmp LABEL_5AEB
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_25B9

LABEL_5AEB:
	call LABEL_5946
	sub [0x07], 0x0007
	break
	jg [0x07], [0x29], LABEL_5B02
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_25B9

LABEL_5B02:
	call LABEL_5971
	sub [0x07], 0x0009
	break
	jg [0x07], [0x29], LABEL_5B19
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_25B9

LABEL_5B19:
	call LABEL_5994
	sub [0x07], 0x0009
	break
	jg [0x07], [0x29], LABEL_5B30
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_25B9

LABEL_5B30:
	call LABEL_59BF
	sub [0x07], 0x0008
	break
	jg [0x07], [0x29], LABEL_5B47
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_25B9

LABEL_5B47:
	call LABEL_59EA
	sub [0x07], 0x000A
	break
	jg [0x07], [0x29], LABEL_5B5E
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_25B9

LABEL_5B5E:
	call LABEL_5A0D
	sub [0x07], 0x0007
	break
	jg [0x07], [0x29], LABEL_5B75
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_25B9

LABEL_5B75:
	call LABEL_5A38
	sub [0x07], 0x0009
	break
	jg [0x07], [0x29], LABEL_5B8C
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_25B9

LABEL_5B8C:
	call LABEL_5A5B
	sub [0x07], 0x0009
	break
	jg [0x07], [0x29], LABEL_5BA3
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_25B9

LABEL_5BA3:
	call LABEL_5A86
	sub [0x07], 0x0008
	break
	jg [0x07], [0x29], LABEL_5BBA
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_25B9

LABEL_5BBA:
	call LABEL_5AB1
	sub [0x07], 0x000A
	break
	jmp LABEL_5ADC
LABEL_5BC5:
	db 0x11

LABEL_5BC6:
	video type=1, offset=CINEMATIC_343, x=[0x07], y=[0x08], zoom=0x40
	jg [0x13], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0002
	je [0xF8], 0x00, SHARED_RET
	video type=1, offset=CINEMATIC_344, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_5BE4:
	video type=1, offset=CINEMATIC_345, x=[0x07], y=[0x08], zoom=0x40
	jg [0x13], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0002
	je [0xF8], 0x00, SHARED_RET
	video type=1, offset=CINEMATIC_346, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_5C02:
	video type=1, offset=CINEMATIC_347, x=[0x07], y=[0x08], zoom=0x40
	jg [0x13], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=1, offset=CINEMATIC_348, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_5C20:
	add [0x07], 0x0001
	call LABEL_5C2C
	sub [0x07], 0x0001
	ret

LABEL_5C2C:
	video type=1, offset=CINEMATIC_170, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jg [0x13], [0x30], DRAW_CIN_169_IF_VAR09_EQ_1
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, DRAW_CIN_169_IF_VAR09_EQ_1
	video type=1, offset=CINEMATIC_171, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_169_IF_VAR09_EQ_1

LABEL_5C4F:
	add [0x07], 0x0001
	call LABEL_5C5B
	sub [0x07], 0x0001
	ret

LABEL_5C5B:
	video type=1, offset=CINEMATIC_334, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jg [0x13], [0x30], DRAW_CIN_169_IF_VAR09_EQ_1
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, DRAW_CIN_169_IF_VAR09_EQ_1
	video type=1, offset=CINEMATIC_335, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_169_IF_VAR09_EQ_1

LABEL_5C7E:
	video type=1, offset=CINEMATIC_336, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jg [0x13], [0x30], DRAW_CIN_169_IF_VAR09_EQ_1
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, DRAW_CIN_169_IF_VAR09_EQ_1
	video type=1, offset=CINEMATIC_337, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_169_IF_VAR09_EQ_1

LABEL_5CA1:
	sub [0x07], 0x0001
	call LABEL_5C4F
	add [0x07], 0x0001
	ret

LABEL_5CAD:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	play id=0x0055, freq=0x19, vol=0x0A, channel=0x01
	sub [0x08], 0x0001
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video type=0, offset=COMMON_VIDEO_241, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_242, x=[0x07], y=[0x08], zoom=0x40
	je [0x0D], 0x00, 0x5CD6
	call LABEL_5C4F
	jmp 0x5CDB
