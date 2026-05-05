LABEL_485E:
	je [0x0F], 0x00, LABEL_486E
	mov [0x2A], 0x002A
	je [0x28], [HERO_X], LABEL_486E

LABEL_486E:
	je [0x32], 0x00, HANDLE_HORIZ_VAR01_VS_VAR28
	mov [0x28], [HERO_X]
	ret

HANDLE_HORIZ_VAR01_VS_VAR28:
	call LABEL_86DE
	mov [0x22], [HERO_X]
	jl [HERO_X], [0x28], LABEL_48B4
	jl [HERO_X], [0x28], LABEL_4897
	mov [0x21], [0x04]
	and [0x21], 0x0010
	je [0x21], 0x00, LABEL_48B4

LABEL_4897:
	mov [0x21], [0x28]
	add [0x22], [0x2A]
	call LABEL_48DC
	sub [0x22], [0x2A]
	jge [0x22], [HERO_X], COPY_VAR01_TO_VAR28
	mov [HERO_X], [0x22]
	mov [0x28], [HERO_X]
	ret
