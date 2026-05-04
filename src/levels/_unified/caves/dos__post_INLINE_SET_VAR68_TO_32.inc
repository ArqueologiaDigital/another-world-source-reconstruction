LABEL_1BC7:
	add [0x69], 0x0008
	mov [0x21], [0x69]
	call LABEL_1C16
	break
	djnz [0x68], LABEL_1BC7
	mov [0x68], 0x0032

LABEL_1BDA:
	sub [0x69], 0x0008
	mov [0x21], [0x69]
	call LABEL_1C16
	break
	djnz [0x68], LABEL_1BDA
	jmp INLINE_SET_VAR68_TO_32
