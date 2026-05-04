LABEL_33F3:
	add [0xE7], 0x0007
	mov [0x21], [0xE7]
	call DRAW_CIN_316
	break
	djnz [0xE6], LABEL_33F3
	jmp INIT_VARS_E6_E7
LABEL_3405:
	db 0x11
