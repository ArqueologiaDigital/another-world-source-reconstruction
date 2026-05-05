LABEL_7EA2:
	je [0x0F], 0x00, LABEL_7EB2
	mov [0x2A], 0x002A
	je [0x28], [HERO_X], LABEL_7EB2

LABEL_7EB2:
	jl [0x32], 0x08, LABEL_7EBC
	mov [0x28], [HERO_X]
	ret

LABEL_7EBC:
	call LABEL_DA00
	mov [0x22], [HERO_X]
	jl [HERO_X], [0x28], LABEL_7EF8
	jg [HERO_X], [0x28], LABEL_7EDB
	mov [0x21], [0x04]
	and [0x21], 0x0010
	je [0x21], 0x00, LABEL_7EF8

LABEL_7EDB:
	mov [0x21], [0x28]
	add [0x22], [0x2A]
	call LABEL_7F20
	sub [0x22], [0x2A]
	jge [0x22], [HERO_X], COPY_VAR01_TO_VAR28
	mov [HERO_X], [0x22]
	mov [0x28], [HERO_X]
	ret
