LABEL_36DA:
	add [0xE7], 0x0008
	mov [0x21], [0xE7]
	call LABEL_3729
	break
	djnz [0xE6], LABEL_36DA
	mov [0xE6], 0x0032

LABEL_36ED:
	sub [0xE7], 0x0008
	mov [0x21], [0xE7]
	call LABEL_3729
	break
	djnz [0xE6], LABEL_36ED
	jmp INLINE_SET_VARE6_TO_32
