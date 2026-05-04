LABEL_04A1:
	break
	video type=1, offset=CINEMATIC_074, x=160, y=100
	jmp LABEL_04A1
LABEL_04A9:
	db 0x06

HANG_DRAWING_CIN_071:
	video type=1, offset=CINEMATIC_071, x=160, y=100
	break
	jmp HANG_DRAWING_CIN_071
