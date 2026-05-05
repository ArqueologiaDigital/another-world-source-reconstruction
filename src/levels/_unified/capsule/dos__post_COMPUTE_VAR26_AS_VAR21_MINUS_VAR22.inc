LABEL_565E:
	mov [0x21], [BUDDY_X]
	mov [0x27], [BUDDY_Y]
	sub [0x27], 0x000B
	mov [0x22], [0x21]
	add [0x21], 0x0028
	sub [0x22], 0x0028
	mov [0x1D], 0x0000
	call LABEL_6D7D
	ret

LABEL_567B:
	mov [0x21], [BUDDY_X]
	mov [0x22], [HERO_X]
	mov [0x27], [BUDDY_Y]
	call LABEL_6D64
	ret

JUNK__5688:
	call LABEL_56CE
	mov [0x22], [BUDDY_X]
	mov [0x27], [BUDDY_Y]
	call LABEL_6D64
	ret
	mov [0x21], [BUDDY_X]
	call LABEL_56E2
	mov [0x29], [HERO_X]
	mov [HERO_X], [0x22]
	mov [0x27], [BUDDY_Y]
	call LABEL_6D64
	mov [HERO_X], [0x29]
	ret

LABEL_56AB:
	call LABEL_56CE
	mov [0x22], [HERO_X]
	mov [0x27], [BUDDY_Y]
	call LABEL_6D64
	ret

LABEL_56B8:
	call LABEL_56CE
	call LABEL_56E2
	mov [0x29], [HERO_X]
	mov [HERO_X], [0x22]
	mov [0x27], [BUDDY_Y]
	call LABEL_6D64
	mov [HERO_X], [0x29]
	ret

LABEL_56CE:
	mov [0x21], [BUDDY_X]
	jge [0x2B], 0x1000, INCREMENT_VAR21_BY_F
	sub [0x21], 0x000F
	ret
