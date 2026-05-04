LABEL_5BCB:
	call DRAW_SPRITE_CIN_236_239_BY_VAR09
	video type=0, offset=COMMON_VIDEO_284, x=[0x07], y=[0x08], zoom=0x40
	add [0x07], 0x0001
	call LABEL_5586
	sub [0x07], 0x0001
	ret

LABEL_5BDF:
	call AND_VAR11_WITH_EFFF
	jmp LABEL_5BEE
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_265B

LABEL_5BEE:
	call LABEL_5A49
	sub [0x07], 0x0007
	break
	jg [0x07], [0x29], LABEL_5C05
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_265B

LABEL_5C05:
	call LABEL_5A74
	sub [0x07], 0x0009
	break
	jg [0x07], [0x29], LABEL_5C1C
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_265B

LABEL_5C1C:
	call LABEL_5A97
	sub [0x07], 0x0009
	break
	jg [0x07], [0x29], LABEL_5C33
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_265B

LABEL_5C33:
	call LABEL_5AC2
	sub [0x07], 0x0008
	break
	jg [0x07], [0x29], LABEL_5C4A
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_265B

LABEL_5C4A:
	call LABEL_5AED
	sub [0x07], 0x000A
	break
	jg [0x07], [0x29], LABEL_5C61
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_265B

LABEL_5C61:
	call LABEL_5B10
	sub [0x07], 0x0007
	break
	jg [0x07], [0x29], LABEL_5C78
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_265B

LABEL_5C78:
	call LABEL_5B3B
	sub [0x07], 0x0009
	break
	jg [0x07], [0x29], LABEL_5C8F
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_265B

LABEL_5C8F:
	call LABEL_5B5E
	sub [0x07], 0x0009
	break
	jg [0x07], [0x29], LABEL_5CA6
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_265B

LABEL_5CA6:
	call LABEL_5B89
	sub [0x07], 0x0008
	break
	jg [0x07], [0x29], LABEL_5CBD
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_265B

LABEL_5CBD:
	call LABEL_5BB4
	sub [0x07], 0x000A
	break
	jmp LABEL_5BDF
LABEL_5CC8:
	db 0x11

LABEL_5CC9:
	video type=1, offset=CINEMATIC_343, x=[0x07], y=[0x08], zoom=0x40
	jg [0x13], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0002
	je [0xF8], 0x00, SHARED_RET
	video type=1, offset=CINEMATIC_344, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_5CE7:
	video type=1, offset=CINEMATIC_345, x=[0x07], y=[0x08], zoom=0x40
	jg [0x13], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0002
	je [0xF8], 0x00, SHARED_RET
	video type=1, offset=CINEMATIC_346, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_5D05:
	video type=1, offset=CINEMATIC_347, x=[0x07], y=[0x08], zoom=0x40
	jg [0x13], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=1, offset=CINEMATIC_348, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_5D23:
	add [0x07], 0x0001
	call LABEL_5D2F
	sub [0x07], 0x0001
	ret

LABEL_5D2F:
	video type=1, offset=CINEMATIC_170, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jg [0x13], [0x30], DISPATCH_VAR09_LOW_NIBBLE
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, DISPATCH_VAR09_LOW_NIBBLE
	video type=1, offset=CINEMATIC_171, x=[0x07], y=[0x08], zoom=0x40
	jmp DISPATCH_VAR09_LOW_NIBBLE

LABEL_5D52:
	add [0x07], 0x0001
	call LABEL_5D5E
	sub [0x07], 0x0001
	ret

LABEL_5D5E:
	video type=1, offset=CINEMATIC_334, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jg [0x13], [0x30], DISPATCH_VAR09_LOW_NIBBLE
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, DISPATCH_VAR09_LOW_NIBBLE
	video type=1, offset=CINEMATIC_335, x=[0x07], y=[0x08], zoom=0x40
	jmp DISPATCH_VAR09_LOW_NIBBLE

LABEL_5D81:
	video type=1, offset=CINEMATIC_336, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jg [0x13], [0x30], DISPATCH_VAR09_LOW_NIBBLE
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, DISPATCH_VAR09_LOW_NIBBLE
	video type=1, offset=CINEMATIC_337, x=[0x07], y=[0x08], zoom=0x40
	jmp DISPATCH_VAR09_LOW_NIBBLE

LABEL_5DA4:
	sub [0x07], 0x0001
	call LABEL_5D52
	add [0x07], 0x0001
	ret

LABEL_5DB0:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	play id=0x0055, freq=0x19, vol=0x0A, channel=0x01
	sub [0x08], 0x0001
	call DRAW_SPRITE_CIN_164_167_BY_VAR09
	video type=0, offset=COMMON_VIDEO_241, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_242, x=[0x07], y=[0x08], zoom=0x40
	je [0x0D], 0x00, 0x5DD9
	call LABEL_5D52
	jmp 0x5DDE
