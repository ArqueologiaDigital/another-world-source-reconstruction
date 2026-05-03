LABEL_0794:
	selectVideoPage 0x00
	break
	jmp LABEL_0794	;@raw=0x07,0x07,0x94
	killChannel

LABEL_079B:
	selectVideoPage 0xFF
	break
	jmp LABEL_079B	;@raw=0x07,0x07,0x9B
LABEL_07A1:
	db 0x11
