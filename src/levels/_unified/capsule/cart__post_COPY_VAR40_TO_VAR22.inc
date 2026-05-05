LABEL_7383:
	mov [0x21], [BUDDY_X]
	mov [0x22], [BUDDY_Y]
	mov [0x23], 0x0000
	mov [0x24], [HACK_VAR_67]
	mov [0x25], [0x35]
	mov [HACK_VAR_67], [0x10]
	mov [0x35], 0x0000
	call LABEL_7333
	mov [HACK_VAR_67], [0x24]
	mov [0x35], [0x25]
	jne [0x10], 0x6B, SHARED_RET
	mov [0x22], 0x0099
	ret

LABEL_73AE:
	mov [0x21], [BUDDY_X]
	mov [0x22], [BUDDY_Y]
	mov [0x23], 0x0000
	jl [BUDDY_X], 0xC3, LABEL_73C2
	mov [0x22], 0x00D2

LABEL_73C2:
	call LABEL_7333
	mov [BUDDY_Y], [0x22]
	ret

LABEL_73C9:
	mov [0xF8], [0x32]
	and [0xF8], 0x0001
	jne [0xF8], 0x00, SHARED_RET
	call LABEL_7325
	mov [0xF8], [0x04]
	and [0xF8], 0x0004
	je [0xF8], 0x00, LABEL_73EF
	jl [HERO_Y], [0x22], SHARED_RET
	jmp LABEL_7433

LABEL_73EF:
	mov [0xF8], [0x22]
	sub [0xF8], [HERO_Y]
	call LABEL_7474
	jl [0xF8], 0x10, LABEL_7433
	jg [0x63], 0x02, LABEL_7425
	jne [HERO_POS_LEFT_RIGHT], 0x00, LABEL_7425
	call INIT_VAR2B_2C_FROM_VAR01_VAR29_10
	mov [0x21], [HERO_X]
	mov [0x22], [0x2B]
	call LABEL_563A
	jg [0x26], 0x0A, LABEL_7425
	mov [HERO_X], [0x2B]
	call LABEL_7325
	jmp LABEL_7433

LABEL_7425:
	call LABEL_7112
	jne [HACK_VAR_67], 0x25, SHARED_RET
	setup channel=0x14, address=LABEL_713A
	ret

LABEL_7433:
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
	je [0xF8], 0x00, LABEL_746A
	mov [0x34], 0x0004

LABEL_746A:
	mov [0x35], 0x0006
	setup channel=0x14, address=LABEL_72F3
	ret
LABEL_7473:
	db 0x11

LABEL_7474:
	je [HACK_VAR_67], 0x88, DECREMENT_VARF8_BY_10
	je [HACK_VAR_67], 0x89, DECREMENT_VARF8_BY_10
	ret
