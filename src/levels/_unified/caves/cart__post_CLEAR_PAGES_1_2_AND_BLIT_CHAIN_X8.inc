LABEL_42D9:
	selectVideoPage 0x00
	break
	jmp LABEL_42D9
	killChannel

LABEL_42E0:
	selectVideoPage 0xFF
	break
	jmp LABEL_42E0
LABEL_42E6:
	db 0x11


; (cart has no chunk here — cart_pre above already spans through to COPY_HASH)
