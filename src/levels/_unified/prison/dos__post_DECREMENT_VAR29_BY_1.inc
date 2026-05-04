LABEL_1BBC:
	setup channel=0x23, address=LABEL_1FF0
	mov [0x57], 0x0000

LABEL_1BC4:
	break
	jg [0x07], 0xFA, LABEL_1BC4
	mov [0x0E], 0x0000
	mov [0x29], 0x0005

LABEL_1BD3:
	break
	call LABEL_1B38
	jg [0x15], 0x14, LABEL_1C0A
	jg [0x07], 0xC8, LABEL_1BD3
	setup channel=0x23, address=LABEL_1FC4

LABEL_1BE7:
	break
	call LABEL_1B38
	jg [0x15], 0x14, LABEL_1BFF
	jl [0x07], 0x010E, LABEL_1BE7
	setup channel=0x23, address=LABEL_1F98
	jmp LABEL_1BD3

LABEL_1BFF:
	setup channel=0x23, address=LABEL_21C4
	mov [0x0D], 0x0001
	jmp LABEL_1C12

LABEL_1C0A:
	setup channel=0x23, address=LABEL_2204
	mov [0x0D], 0x0001

LABEL_1C12:
	break
	jg [0x07], 0xC8, LABEL_1C12
	setup channel=0x23, address=LABEL_2038

LABEL_1C1D:
	break
	jg [0x15], 0x16, LABEL_1C4A
	jg [0x15], 0x13, LABEL_1C3C
	setup channel=0x23, address=LABEL_21A5
	call COPY_HASH_AND_SPLIT_VAR38_3F_3E
	je [0x38], 0x01, LABEL_1BD3
	break
	break
	jmp LABEL_1BD3

LABEL_1C3C:
	jne [0x57], 0x02, LABEL_1C4A
	mov [0x57], 0x0000
	setup channel=0x11, address=DRAW_CIN_569_TO_572_6F_AT_F8680E45

LABEL_1C4A:
	jl [0x15], 0x28, LABEL_1C1D
	jg [0x57], 0x00, LABEL_1C1D
	setup channel=0x23, address=LABEL_2150
	mov [0x57], 0x0001
	jmp LABEL_1C1D
LABEL_1C61:
	db 0x11

INCREMENT_VAR27_AND_DISPATCH:
	add [0x27], 0x0001
	jne [0x27], 0x01, LABEL_1C6F
	mov [0x24], [0x80]

LABEL_1C6F:
	jne [0x27], 0x02, LABEL_1C78
	mov [0x24], [0x81]

LABEL_1C78:
	jne [0x27], 0x03, BIT_EXTRACT_FROM_VAR24_TO_VAR25
	mov [0x24], [0x82]
