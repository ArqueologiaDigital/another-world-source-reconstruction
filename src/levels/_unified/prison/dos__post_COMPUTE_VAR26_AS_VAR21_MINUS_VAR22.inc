LABEL_32D8:
	mov [0x21], [ACTOR_X]
	mov [0x27], [ACTOR_Y]
	sub [0x27], 0x000B
	mov [0x22], [0x21]
	add [0x21], 0x0028
	sub [0x22], 0x0028
	mov [0x1D], 0x0000
	call LABEL_46FE
	ret


LABEL_32F5:
	mov [0x21], [ACTOR_X]
	mov [0x22], [HERO_X]
	mov [0x27], [ACTOR_Y]
	call LABEL_46E5
	ret


LABEL_3302:
	call LABEL_3348
	mov [0x22], [ACTOR_X]
	mov [0x27], [ACTOR_Y]
	call LABEL_46E5
	ret


	mov [0x21], [ACTOR_X]
	call PRISON_HERO_FRONT_X_BY_FACING
	mov [0x29], [HERO_X]
	mov [HERO_X], [0x22]
	mov [0x27], [ACTOR_Y]
	call LABEL_46E5
	mov [HERO_X], [0x29]
	ret


	call LABEL_3348
	mov [0x22], [HERO_X]
	mov [0x27], [ACTOR_Y]
	call LABEL_46E5
	ret


PRISON_DEDUP_PRISON_5B_023_L1:
	call LABEL_3348
	call PRISON_HERO_FRONT_X_BY_FACING
	mov [0x29], [HERO_X]
	mov [HERO_X], [0x22]
	mov [0x27], [ACTOR_Y]
	call LABEL_46E5
	mov [HERO_X], [0x29]
	ret


LABEL_3348:
	mov [0x21], [ACTOR_X]
	jge [0x2B], 0x1000, INCREMENT_VAR21_BY_F
	sub [0x21], 0x000F
	ret
