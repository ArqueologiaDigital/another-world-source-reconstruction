LABEL_36F6:
	add [0xE7], 0x0008
	mov [0x21], [0xE7]
	call LABEL_3745
	break
	djnz [0xE6], LABEL_36F6
	mov [0xE6], 0x0032

LABEL_3709:
	sub [0xE7], 0x0008
	mov [0x21], [0xE7]
	call LABEL_3745
	break
	djnz [0xE6], LABEL_3709
	jmp INLINE_SET_VARE6_TO_32
