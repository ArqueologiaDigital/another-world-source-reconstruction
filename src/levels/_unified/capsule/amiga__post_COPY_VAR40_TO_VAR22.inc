LABEL_5AF6:
	mov [0x21], [0x07]
	mov [0x22], [0x08]
	mov [0x23], 0x0000
	mov [0x24], [HACK_VAR_67]
	mov [HACK_VAR_67], [0x10]
	call LABEL_5AE2
	mov [HACK_VAR_67], [0x24]
	ret

LABEL_5B0D:
	mov [0xF8], [0x32]
	and [0xF8], 0x0001
	jne [0xF8], 0x00, SHARED_RET
	call LABEL_5AD4
	mov [0xF8], [0x04]
	and [0xF8], 0x0004
	je [0xF8], 0x00, LABEL_5B33
	jl [HERO_Y], [0x22], SHARED_RET
	jmp LABEL_5B77

LABEL_5B33:
	mov [0xF8], [0x22]
	sub [0xF8], [HERO_Y]
	call LABEL_5BB8
	jl [0xF8], 0x10, LABEL_5B77
	jg [0x63], 0x02, LABEL_5B69
	jne [HERO_POS_LEFT_RIGHT], 0x00, LABEL_5B69
	call INIT_VAR2B_2C_FROM_VAR01_VAR29_10
	mov [0x21], [HERO_X]
	mov [0x22], [0x2B]
	call LABEL_3F38
	jg [0x26], 0x0A, LABEL_5B69
	mov [HERO_X], [0x2B]
	call LABEL_5AD4
	jmp LABEL_5B77

LABEL_5B69:
	call LABEL_58EB
	jne [HACK_VAR_67], 0x25, SHARED_RET
	setup channel=0x14, address=LABEL_5913
	ret

LABEL_5B77:
	mov [HERO_Y], [0x22]
	mov [0xF8], [0x23]
	and [0xF8], 0x0010
	je [0xF8], 0x00, SHARED_RET
	je [0x63], 0x05, SHARED_RET
	je [0x63], 0x06, SHARED_RET
	je [0x63], 0x64, SHARED_RET
	mov [0x34], 0xFFF6
	mov [0xF8], [0x23]
	and [0xF8], 0x0008
	je [0xF8], 0x00, LABEL_5BAE
	mov [0x34], 0x0004

LABEL_5BAE:
	mov [0x35], 0x0006
	setup channel=0x14, address=LABEL_5AA2
	ret
LABEL_5BB7:
	db 0x11

LABEL_5BB8:
	je [HACK_VAR_67], 0x88, DECREMENT_VARF8_BY_10
	je [HACK_VAR_67], 0x89, DECREMENT_VARF8_BY_10
	ret
