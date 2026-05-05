LABEL_7E19:
	je [0x0F], 0x00, LABEL_7E29
	mov [0x2A], 0x002A
	je [0x28], [HERO_X], LABEL_7E29

LABEL_7E29:
	jl [0x32], 0x08, LABEL_7E33
	mov [0x28], [HERO_X]
	ret

LABEL_7E33:
	call LABEL_DA86
	mov [0x22], [HERO_X]
	jl [HERO_X], [0x28], LABEL_7E6F
	jg [HERO_X], [0x28], LABEL_7E52
	mov [0x21], [0x04]
	and [0x21], 0x0010
	je [0x21], 0x00, LABEL_7E6F

LABEL_7E52:
	mov [0x21], [0x28]
	add [0x22], [0x2A]
	call LABEL_7E97
	sub [0x22], [0x2A]
	jge [0x22], [HERO_X], COPY_VAR01_TO_VAR28
	mov [HERO_X], [0x22]
	mov [0x28], [HERO_X]
	ret
