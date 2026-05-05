LABEL_1C5E:
	setup channel=0x23, address=LABEL_2092
	mov [0x57], 0x0000

LABEL_1C66:
	break
	jg [BUDDY_X], 0xFA, LABEL_1C66
	mov [0x0E], 0x0000
	mov [0x29], 0x0005

LABEL_1C75:
	break
	call LABEL_1BDA
	jg [0x15], 0x14, LABEL_1CAC
	jg [BUDDY_X], 0xC8, LABEL_1C75
	setup channel=0x23, address=LABEL_2066

LABEL_1C89:
	break
	call LABEL_1BDA
	jg [0x15], 0x14, LABEL_1CA1
	jl [BUDDY_X], 0x010E, LABEL_1C89
	setup channel=0x23, address=LABEL_203A
	jmp LABEL_1C75

LABEL_1CA1:
	setup channel=0x23, address=LABEL_2266
	mov [0x0D], 0x0001
	jmp LABEL_1CB4

LABEL_1CAC:
	setup channel=0x23, address=LABEL_22A6
	mov [0x0D], 0x0001

LABEL_1CB4:
	break
	jg [BUDDY_X], 0xC8, LABEL_1CB4
	setup channel=0x23, address=LABEL_20DA

LABEL_1CBF:
	break
	jg [0x15], 0x16, LABEL_1CEC
	jg [0x15], 0x13, LABEL_1CDE
	setup channel=0x23, address=LABEL_2247
	call COPY_HASH_AND_SPLIT_VAR38_3F_3E
	je [0x38], 0x01, LABEL_1C75
	break
	break
	jmp LABEL_1C75

LABEL_1CDE:
	jne [0x57], 0x02, LABEL_1CEC
	mov [0x57], 0x0000
	setup channel=0x11, address=LABEL_1FA0

LABEL_1CEC:
	jl [0x15], 0x28, LABEL_1CBF
	jg [0x57], 0x00, LABEL_1CBF
	setup channel=0x23, address=LABEL_21F2
	mov [0x57], 0x0001
	jmp LABEL_1CBF
LABEL_1D03:
	db 0x11

INCREMENT_VAR27_AND_DISPATCH:
	add [0x27], 0x0001
	jne [0x27], 0x01, LABEL_1D11
	mov [0x24], [0x80]

LABEL_1D11:
	jne [0x27], 0x02, LABEL_1D1A
	mov [0x24], [0x81]

LABEL_1D1A:
	jne [0x27], 0x03, BIT_EXTRACT_FROM_VAR24_TO_VAR25
	mov [0x24], [0x82]
