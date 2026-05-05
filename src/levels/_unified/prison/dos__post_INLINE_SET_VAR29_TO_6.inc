LABEL_1837:
	break
	je [HACK_VAR_67], 0x04, LABEL_1846
	djnz [0x29], LABEL_1837
	jmp LABEL_1846
LABEL_1845:
	db 0x11

LABEL_1846:
	call COPY_HASH_AND_SPLIT_VAR38_3F_3E
	add [0xF1], 0x0001
	jg [0xF1], 0x20, LABEL_186E
	jne [HACK_VAR_67], 0x04, INLINE_SET_VAR29_TO_6
	je [0x3A], 0x00, LABEL_1787
	je [0x3A], 0x01, LABEL_17DB
	jl [0x3A], 0x05, LABEL_16FB
	jmp LABEL_1741

LABEL_186E:
	jne [HACK_VAR_67], 0x04, LABEL_187C
	selectVideoPage 0x00
	video offset=CINEMATIC_379, x=160, y=100
	selectVideoPage 0xFF

LABEL_187C:
	mov [0x12], 0x0000
	mov [0xB1], 0x0001
	and [0x49], 0x7F9F
	or [0x49], 0x0040
	or [0x49], 0x0380
	mov [0x29], 0x012C
	setup channel=0x08, address=INLINE_SET_VARF1_TO_64
	mov [0xF8], [0x49]
	and [0xF8], 0x0380
	je [0xF8], 0x0380, LABEL_68DA
	mov [0x29], 0x000A
	jmp LABEL_5ADC
