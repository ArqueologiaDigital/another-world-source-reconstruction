LABEL_7EC5:
	jl [0x01], [0x50], LABEL_7F02
	add [0x50], 0x0014
	jg [0x01], [0x50], LABEL_7EFE
	jne [0x02], [0x52], LABEL_7EEA
	jne [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_7EFE
	mov [0x32], 0x0001
	setup channel=0x14, address=LABEL_7E4F

LABEL_7EEA:
	jne [0x02], [0x51], LABEL_7EFE
	jne [HERO_POS_JUMP_DOWN], 0x01, LABEL_7EFE
	mov [0x32], 0x0001
	setup channel=0x14, address=LABEL_7E32

LABEL_7EFE:
	sub [0x50], 0x0014

LABEL_7F02:
	ret
LABEL_7F03:
	db 0x11
