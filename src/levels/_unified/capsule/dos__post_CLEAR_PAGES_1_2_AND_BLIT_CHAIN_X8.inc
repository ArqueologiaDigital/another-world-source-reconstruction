LABEL_3033:
	selectVideoPage 0x00
	break
	jmp LABEL_3033	;@raw=0x07,0x30,0x33
	killChannel

LABEL_303A:
	selectVideoPage 0xFF
	break
	jmp LABEL_303A	;@raw=0x07,0x30,0x3A
LABEL_3040:
	db 0x11
