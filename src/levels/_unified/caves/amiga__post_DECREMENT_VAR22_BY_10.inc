LABEL_7B44:
	je [0x0F], 0x00, LABEL_7B54
	mov [0x2A], 0x002A
	je [0x28], [HERO_X], LABEL_7B54

LABEL_7B54:
	jl [0x32], 0x08, LABEL_7B5E
	mov [0x28], [HERO_X]
	ret

LABEL_7B5E:
	call LABEL_D520
	mov [0x22], [HERO_X]
	jl [HERO_X], [0x28], LABEL_7B9A
	jg [HERO_X], [0x28], LABEL_7B7D
	mov [0x21], [0x04]
	and [0x21], 0x0010
	je [0x21], 0x00, LABEL_7B9A

LABEL_7B7D:
	mov [0x21], [0x28]
	add [0x22], [0x2A]
	call LABEL_7BC2
	sub [0x22], [0x2A]
	jge [0x22], [HERO_X], COPY_VAR01_TO_VAR28
	mov [HERO_X], [0x22]
	mov [0x28], [HERO_X]
	ret
