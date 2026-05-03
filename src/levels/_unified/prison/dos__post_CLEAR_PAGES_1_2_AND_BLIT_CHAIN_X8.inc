LABEL_070C:
	selectVideoPage 0x00
	break
	jmp LABEL_070C	;@raw=0x07,0x07,0x0C
	killChannel

LABEL_0713:
	selectVideoPage 0xFF
	break
	jmp LABEL_0713	;@raw=0x07,0x07,0x13
LABEL_0719:
	db 0x11
