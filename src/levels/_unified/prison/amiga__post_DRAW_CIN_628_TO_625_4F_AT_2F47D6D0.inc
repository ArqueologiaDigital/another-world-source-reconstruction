HANG_DRAW_CIN_624:
	video offset=CINEMATIC_624, x=160, y=100
	break
	jmp HANG_DRAW_CIN_624
LABEL_4C17:
	db 0x11

LABEL_4C18:
	mov [0x07], 0x0118
	mov [0x08], 0x00B6
	video offset=CINEMATIC_633, x=[0x07], y=[0x08], zoom=0x40
	break
	jmp LABEL_4C18
LABEL_4C29:
	db 0x11
