LABEL_42EF:
	selectVideoPage 0x00
	break
	jmp LABEL_42EF
	killChannel

LABEL_42F6:
	selectVideoPage 0xFF
	break
	jmp LABEL_42F6
LABEL_42FC:
	db 0x11
; (cart has no chunk here — cart_pre above already spans through to COPY_HASH)
