LABEL_18CF:
	break
	je [HACK_VAR_67], 0x04, LABEL_18DE
	djnz [0x29], LABEL_18CF
	jmp LABEL_18DE
LABEL_18DD:
	db 0x11

LABEL_18DE:
	call COPY_HASH_AND_SPLIT_VAR38_3F_3E
	add [0xF1], 0x0001
	jg [0xF1], 0x20, LABEL_1906
	jne [HACK_VAR_67], 0x04, INLINE_SET_VAR29_TO_6
	je [0x3A], 0x00, LABEL_1821
	je [0x3A], 0x01, LABEL_1873
	jl [0x3A], 0x05, LABEL_1799
	jmp LABEL_17DD

LABEL_1906:
	jne [HACK_VAR_67], 0x04, LABEL_1914
	selectVideoPage 0x00
	video offset=CINEMATIC_379, x=160, y=100
	selectVideoPage 0xFF

LABEL_1914:
	mov [0x12], 0x0000
	mov [0xB1], 0x0001
	and [0x49], 0x7F9F
	or [0x49], 0x0040
	or [0x49], 0x0380
	mov [0x29], 0x012C
	setup channel=0x08, address=INLINE_SET_VARF1_TO_64
	mov [0xF8], [0x49]
	and [0xF8], 0x0380
	je [0xF8], 0x0380, LABEL_69DD
	mov [0x29], 0x000A
	jmp LABEL_5BDF
