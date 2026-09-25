LABEL_8788:
	db 0x11

PRISON_ACTOR_SLOT0_FLOOR_Y_CASE_25:
	jne [0x6A], 0x25, PRISON_ACTOR_SLOT0_FLOOR_Y_CASE_45
	mov [0x69], 0x0081

PRISON_ACTOR_SLOT0_FLOOR_Y_CASE_45:
	jne [0x6A], 0x45, PRISON_ACTOR_SLOT0_FLOOR_Y_CASE_44
	mov [0x69], 0x0081

PRISON_ACTOR_SLOT0_FLOOR_Y_CASE_44:
	jne [0x6A], 0x44, LABEL_87A7
	mov [0x69], 0x008B

LABEL_87A7:
	jne [0x6A], 0x05, SHARED_RET
	mov [0x69], 0x0081
	ret


LABEL_87B2:
	mov [ACTOR_X], [0x68]
	mov [ACTOR_Y], [0x69]
	mov [0x10], [0x6A]
	call LABEL_87F2
	mov [0x68], [ACTOR_X]
	mov [0x69], [ACTOR_Y]
	mov [0x6A], [0x10]
	mov [ACTOR_X], [0x70]
	mov [ACTOR_Y], [0x71]
	mov [0x10], [0x72]
	call LABEL_87F2
	mov [0x70], [ACTOR_X]
	mov [0x71], [ACTOR_Y]
	mov [0x72], [0x10]
	mov [ACTOR_X], [0x78]
	mov [ACTOR_Y], [0x79]
	mov [0x10], [0x7A]
	call LABEL_87F2
	mov [0x78], [ACTOR_X]
	mov [0x79], [ACTOR_Y]
	mov [0x7A], [0x10]
	ret


LABEL_87F2:
	jg [HERO_X], 0x0A, SHARED_RET
	jg [ACTOR_X], 0x28, LABEL_8809
	jne [0x10], [SCREEN_NUM], LABEL_8809
	mov [ACTOR_X], 0x002A
	ret


LABEL_8809:
	jl [ACTOR_X], 0x0140, SHARED_RET
	add [0x10], 0x0001
	jne [0x10], [SCREEN_NUM], DECREMENT_VAR10_BY_1
	mov [ACTOR_X], 0x002A
	ret
