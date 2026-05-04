LABEL_1B86:
	add [0x69], 0x0008
	mov [0x21], [0x69]
	call LABEL_1BD5
	break
	djnz [0x68], LABEL_1B86
	mov [0x68], 0x0032

LABEL_1B99:
	sub [0x69], 0x0008
	mov [0x21], [0x69]
	call LABEL_1BD5
	break
	djnz [0x68], LABEL_1B99
	jmp INLINE_SET_VAR68_TO_32
