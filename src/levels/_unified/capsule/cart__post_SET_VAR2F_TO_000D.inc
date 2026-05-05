LABEL_537D:
	call LABEL_56A8
	jg [0x1D], 0x1D, LABEL_53BF
	je [0x12], 0x58, SET_VAR2F_TO_000D
	mov [0x21], [BUDDY_X]
	call LABEL_563A
	mov [0x25], [0x26]
	mov [0x21], [HERO_X]
	call LABEL_563A
	mov [0x24], [0x26]
	jle [0x24], [0x25], LABEL_53BF
	mov [0x29], [0x22]
	jl [BUDDY_X], [HERO_X], STEP_VAR29_DOWN10_SET_VAR2F_11
	add [0x29], 0x000A
	mov [0x2F], 0x0011
	ret
