LABEL_1BC4:
	setup channel=0x23, address=LABEL_1FF8
	mov [0x57], 0x0000

LABEL_1BCC:
	break
	jg [0x07], 0xFA, LABEL_1BCC
	mov [0x0E], 0x0000
	mov [0x29], 0x0005

LABEL_1BDB:
	break
	call LABEL_1B40
	jg [0x15], 0x14, LABEL_1C12
	jg [0x07], 0xC8, LABEL_1BDB
	setup channel=0x23, address=LABEL_1FCC

LABEL_1BEF:
	break
	call LABEL_1B40
	jg [0x15], 0x14, LABEL_1C07
	jl [0x07], 0x010E, LABEL_1BEF
	setup channel=0x23, address=LABEL_1FA0
	jmp LABEL_1BDB

LABEL_1C07:
	setup channel=0x23, address=LABEL_21CC
	mov [0x0D], 0x0001
	jmp LABEL_1C1A

LABEL_1C12:
	setup channel=0x23, address=LABEL_220C
	mov [0x0D], 0x0001

LABEL_1C1A:
	break
	jg [0x07], 0xC8, LABEL_1C1A
	setup channel=0x23, address=LABEL_2040

LABEL_1C25:
	break
	jg [0x15], 0x16, LABEL_1C52
	jg [0x15], 0x13, LABEL_1C44
	setup channel=0x23, address=LABEL_21AD
	call COPY_HASH_AND_SPLIT_VAR38_3F_3E
	je [0x38], 0x01, LABEL_1BDB
	break
	break
	jmp LABEL_1BDB

LABEL_1C44:
	jne [0x57], 0x02, LABEL_1C52
	mov [0x57], 0x0000
	setup channel=0x11, address=DRAW_CIN_569_TO_572_6F_AT_F8680E45

LABEL_1C52:
	jl [0x15], 0x28, LABEL_1C25
	jg [0x57], 0x00, LABEL_1C25
	setup channel=0x23, address=LABEL_2158
	mov [0x57], 0x0001
	jmp LABEL_1C25
LABEL_1C69:
	db 0x11

INCREMENT_VAR27_AND_DISPATCH:
	add [0x27], 0x0001
	jne [0x27], 0x01, LABEL_1C77
	mov [0x24], [0x80]

LABEL_1C77:
	jne [0x27], 0x02, LABEL_1C80
	mov [0x24], [0x81]

LABEL_1C80:
	jne [0x27], 0x03, BIT_EXTRACT_FROM_VAR24_TO_VAR25
	mov [0x24], [0x82]
