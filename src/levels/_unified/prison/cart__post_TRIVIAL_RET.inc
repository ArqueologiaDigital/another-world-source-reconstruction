LABEL_4958:
	je [0x0F], 0x00, LABEL_4968
	mov [0x2A], 0x002A
	je [0x28], [HERO_X], LABEL_4968

LABEL_4968:
	je [0x32], 0x00, HANDLE_HORIZ_VAR01_VS_VAR28
	mov [0x28], [HERO_X]
	ret

HANDLE_HORIZ_VAR01_VS_VAR28:
	call LABEL_882F
	mov [0x22], [HERO_X]
	jl [HERO_X], [0x28], LABEL_49AE
	jl [HERO_X], [0x28], LABEL_4991
	mov [0x21], [0x04]
	and [0x21], 0x0010
	je [0x21], 0x00, LABEL_49AE

LABEL_4991:
	mov [0x21], [0x28]
	add [0x22], [0x2A]
	call LABEL_49D6
	sub [0x22], [0x2A]
	jge [0x22], [HERO_X], COPY_VAR01_TO_VAR28
	mov [HERO_X], [0x22]
	mov [0x28], [HERO_X]
	ret
