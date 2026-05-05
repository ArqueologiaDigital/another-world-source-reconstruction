LABEL_742F:
	je [0x0F], 0x00, LABEL_743F
	mov [0x2A], 0x002A
	je [0x28], [HERO_X], LABEL_743F

LABEL_743F:
	jl [0x32], 0x08, LABEL_7449
	mov [0x28], [HERO_X]
	ret

LABEL_7449:
	call LABEL_B28A
	mov [0x22], [HERO_X]
	jne [HACK_VAR_67], 0xAA, LABEL_745B
	jl [HERO_Y], 0x96, LABEL_7467

LABEL_745B:
	jl [HERO_X], [0x28], LABEL_7491
	jg [HERO_X], [0x28], LABEL_7474

LABEL_7467:
	mov [0x21], [0x04]
	and [0x21], 0x0010
	je [0x21], 0x00, LABEL_7491

LABEL_7474:
	mov [0x21], [0x28]
	add [0x22], [0x2A]
	call LABEL_74B9
	sub [0x22], [0x2A]
	jge [0x22], [HERO_X], COPY_VAR01_TO_VAR28
	mov [HERO_X], [0x22]
	mov [0x28], [HERO_X]
	ret
