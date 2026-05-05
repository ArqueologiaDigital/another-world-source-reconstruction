HANG_DRAW_CIN_624:
	video offset=CINEMATIC_624, x=160, y=100
	break
	jmp HANG_DRAW_CIN_624
LABEL_4C17:
	db 0x11

LABEL_4C18:
	mov [BUDDY_X], 0x0118
	mov [BUDDY_Y], 0x00B6
	video offset=CINEMATIC_633, x=[BUDDY_X], y=[BUDDY_Y]
	break
	jmp LABEL_4C18
LABEL_4C29:
	db 0x11
