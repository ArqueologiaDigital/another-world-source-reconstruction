LABEL_0794:
	selectVideoPage 0x00
	break
	jmp LABEL_0794
	killChannel

LABEL_079B:
	selectVideoPage 0xFF
	break
	jmp LABEL_079B
LABEL_07A1:
	db 0x11
