HANG_DRAW_CIN_624:
	video offset=CINEMATIC_624, x=160, y=100
	break
	jmp HANG_DRAW_CIN_624
LABEL_4CB8:
	db 0x11

LABEL_4CB9:
	mov [0x07], 0x0118
	mov [0x08], 0x00B6
	mov [PAUSE_SLICES], 0x0007
	video offset=CINEMATIC_633, x=[0x07], y=[0x08]
	break
	jmp LABEL_4CB9
LABEL_4CCE:
	db 0x11
