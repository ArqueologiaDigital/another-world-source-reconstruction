LABEL_5FB9:
	mov [0x21], [HERO_X]
	mov [0x22], [0x07]
	jmp CAVES_COPY_VAR40_TO_VAR22_L8

LABEL_5FC2:
	mov [0x21], [0x07]
	mov [0x27], [0x08]
	sub [0x27], 0x000B
	mov [0x22], [0x21]
	add [0x21], 0x0028
	sub [0x22], 0x0028
	mov [0x1D], 0x0000
	call LABEL_76D2
	ret


LABEL_5FDF:
	mov [0x21], [0x07]
	mov [0x22], [HERO_X]
	mov [0x27], [0x08]
	call LABEL_76B9
	ret


JUNK__5FEC:
	call LABEL_6032
	mov [0x22], [0x07]
	mov [0x27], [0x08]
	call LABEL_76B9
	ret


	mov [0x21], [0x07]
	call CAVES_INCREMENT_VAR21_BY_F_L0
	mov [0x29], [HERO_X]
	mov [HERO_X], [0x22]
	mov [0x27], [0x08]
	call LABEL_76B9
	mov [HERO_X], [0x29]
	ret


LABEL_600F:
	call LABEL_6032
	mov [0x22], [HERO_X]
	mov [0x27], [0x08]
	call LABEL_76B9
	ret


CAVES_SET_VAR2F_TO_000D_L1:
	call LABEL_6032
	call CAVES_INCREMENT_VAR21_BY_F_L0
	mov [0x29], [HERO_X]
	mov [HERO_X], [0x22]
	mov [0x27], [0x08]
	call LABEL_76B9
	mov [HERO_X], [0x29]
	ret


LABEL_6032:
	mov [0x21], [0x07]
	jge [0x2B], 0x1000, INCREMENT_VAR21_BY_F
	sub [0x21], 0x000F
	ret
