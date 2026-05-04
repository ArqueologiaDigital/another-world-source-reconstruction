LABEL_31B0:
	selectVideoPage 0x00
	break
	jmp LABEL_31B0
	killChannel

LABEL_31B7:
	selectVideoPage 0xFF
	break
	jmp LABEL_31B7
LABEL_31BD:
	db 0x11
