LABEL_34CD:
	add [0xE7], 0x0008
	mov [0x21], [0xE7]
	call LABEL_351C
	break
	djnz [0xE6], LABEL_34CD
	mov [0xE6], 0x0032

LABEL_34E0:
	sub [0xE7], 0x0008
	mov [0x21], [0xE7]
	call LABEL_351C
	break
	djnz [0xE6], LABEL_34E0
	jmp INLINE_SET_VARE6_TO_32
