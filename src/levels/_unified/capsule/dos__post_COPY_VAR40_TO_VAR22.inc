LABEL_731A:
	mov [0x21], [BUDDY_X]
	mov [0x22], [BUDDY_Y]
	mov [0x23], 0x0000
	mov [0x24], [HACK_VAR_67]
	mov [0x25], [0x35]
	mov [HACK_VAR_67], [0x10]
	mov [0x35], 0x0000
	call LABEL_72CA
	mov [HACK_VAR_67], [0x24]
	mov [0x35], [0x25]
	jne [0x10], 0x6B, SHARED_RET
	mov [0x22], 0x0099
	ret

LABEL_7345:
	mov [0x21], [BUDDY_X]
	mov [0x22], [BUDDY_Y]
	mov [0x23], 0x0000
	jl [BUDDY_X], 0xC3, LABEL_7359
	mov [0x22], 0x00D2

LABEL_7359:
	call LABEL_72CA
	mov [BUDDY_Y], [0x22]
	ret

LABEL_7360:
	mov [0xF8], [0x32]
	and [0xF8], 0x0001
	jne [0xF8], 0x00, SHARED_RET
	call LABEL_72BC
	mov [0xF8], [0x04]
	and [0xF8], 0x0004
	je [0xF8], 0x00, LABEL_7386
	jl [HERO_Y], [0x22], SHARED_RET
	jmp LABEL_73CA

LABEL_7386:
	mov [0xF8], [0x22]
	sub [0xF8], [HERO_Y]
	call LABEL_740B
	jl [0xF8], 0x10, LABEL_73CA
	jg [0x63], 0x02, LABEL_73BC
	jne [HERO_POS_LEFT_RIGHT], 0x00, LABEL_73BC
	call INIT_VAR2B_2C_FROM_VAR01_VAR29_10
	mov [0x21], [HERO_X]
	mov [0x22], [0x2B]
	call LABEL_564A
	jg [0x26], 0x0A, LABEL_73BC
	mov [HERO_X], [0x2B]
	call LABEL_72BC
	jmp LABEL_73CA

LABEL_73BC:
	call LABEL_70BA
	jne [HACK_VAR_67], 0x25, SHARED_RET
	setup channel=0x14, address=LABEL_70E2
	ret

LABEL_73CA:
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
	je [0xF8], 0x00, LABEL_7401
	mov [0x34], 0x0004

LABEL_7401:
	mov [0x35], 0x0006
	setup channel=0x14, address=LABEL_728A
	ret
LABEL_740A:
	db 0x11

LABEL_740B:
	je [HACK_VAR_67], 0x88, DECREMENT_VARF8_BY_10
	je [HACK_VAR_67], 0x89, DECREMENT_VARF8_BY_10
	ret
