LABEL_3033:
	selectVideoPage 0x00
	break
	jmp LABEL_3033
	killChannel

LABEL_303A:
	selectVideoPage 0xFF
	break
	jmp LABEL_303A
LABEL_3040:
	db 0x11
