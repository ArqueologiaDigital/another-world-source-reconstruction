LABEL_33D7:
	add [0xE7], 0x0007
	mov [0x21], [0xE7]
	call DRAW_CIN_315
	break
	djnz [0xE6], LABEL_33D7
	jmp INIT_VARS_E6_E7
LABEL_33E9:
	db 0x11
