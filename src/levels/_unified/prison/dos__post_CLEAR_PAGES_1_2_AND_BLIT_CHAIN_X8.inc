LABEL_070C:
	selectVideoPage 0x00
	break
	jmp LABEL_070C
	killChannel

LABEL_0713:
	selectVideoPage 0xFF
	break
	jmp LABEL_0713
LABEL_0719:
	db 0x11
