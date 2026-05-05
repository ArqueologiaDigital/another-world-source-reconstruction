LABEL_8788:
	db 0x11

LABEL_8789:
	jne [0x6A], 0x25, LABEL_8793
	mov [0x69], 0x0081

LABEL_8793:
	jne [0x6A], 0x45, LABEL_879D
	mov [0x69], 0x0081

LABEL_879D:
	jne [0x6A], 0x44, LABEL_87A7
	mov [0x69], 0x008B

LABEL_87A7:
	jne [0x6A], 0x05, SHARED_RET
	mov [0x69], 0x0081
	ret

LABEL_87B2:
	mov [BUDDY_X], [0x68]
	mov [BUDDY_Y], [0x69]
	mov [0x10], [0x6A]
	call LABEL_87F2
	mov [0x68], [BUDDY_X]
	mov [0x69], [BUDDY_Y]
	mov [0x6A], [0x10]
	mov [BUDDY_X], [0x70]
	mov [BUDDY_Y], [0x71]
	mov [0x10], [0x72]
	call LABEL_87F2
	mov [0x70], [BUDDY_X]
	mov [0x71], [BUDDY_Y]
	mov [0x72], [0x10]
	mov [BUDDY_X], [0x78]
	mov [BUDDY_Y], [0x79]
	mov [0x10], [0x7A]
	call LABEL_87F2
	mov [0x78], [BUDDY_X]
	mov [0x79], [BUDDY_Y]
	mov [0x7A], [0x10]
	ret

LABEL_87F2:
	jg [HERO_X], 0x0A, SHARED_RET
	jg [BUDDY_X], 0x28, LABEL_8809
	jne [0x10], [HACK_VAR_67], LABEL_8809
	mov [BUDDY_X], 0x002A
	ret

LABEL_8809:
	jl [BUDDY_X], 0x0140, SHARED_RET
	add [0x10], 0x0001
	jne [0x10], [HACK_VAR_67], DECREMENT_VAR10_BY_1
	mov [BUDDY_X], 0x002A
	ret
