LABEL_19FD:
	add [0x69], 0x0008
	mov [0x21], [0x69]
	call LABEL_1A4C
	break
	djnz [0x68], LABEL_19FD
	mov [0x68], 0x0032

LABEL_1A10:
	sub [0x69], 0x0008
	mov [0x21], [0x69]
	call LABEL_1A4C
	break
	djnz [0x68], LABEL_1A10
	jmp INLINE_SET_VAR68_TO_32
