LABEL_31CA:
	add [0xE7], 0x0007
	mov [0x21], [0xE7]
	call DRAW_CIN_295
	break
	djnz [0xE6], LABEL_31CA
	jmp INIT_VARS_E6_E7
LABEL_31DC:
	db 0x11
