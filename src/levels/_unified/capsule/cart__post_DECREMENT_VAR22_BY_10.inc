LABEL_7498:
	je [0x0F], 0x00, LABEL_74A8
	mov [0x2A], 0x002A
	je [0x28], [HERO_X], LABEL_74A8

LABEL_74A8:
	jl [0x32], 0x08, LABEL_74B2
	mov [0x28], [HERO_X]
	ret

LABEL_74B2:
	call LABEL_B36B
	mov [0x22], [HERO_X]
	jne [HACK_VAR_67], 0xAA, LABEL_74C4
	jl [HERO_Y], 0x96, LABEL_74D0

LABEL_74C4:
	jl [HERO_X], [0x28], LABEL_74FA
	jg [HERO_X], [0x28], LABEL_74DD

LABEL_74D0:
	mov [0x21], [0x04]
	and [0x21], 0x0010
	je [0x21], 0x00, LABEL_74FA

LABEL_74DD:
	mov [0x21], [0x28]
	add [0x22], [0x2A]
	call LABEL_7522
	sub [0x22], [0x2A]
	jge [0x22], [HERO_X], COPY_VAR01_TO_VAR28
	mov [HERO_X], [0x22]
	mov [0x28], [HERO_X]
	ret
