LABEL_42EF:
	selectVideoPage 0x00
	break
	jmp LABEL_42EF	;@raw=0x07,0x42,0xEF
	killChannel

LABEL_42F6:
	selectVideoPage 0xFF
	break
	jmp LABEL_42F6	;@raw=0x07,0x42,0xF6
LABEL_42FC:
	db 0x11
; (cart has no chunk here — cart_pre above already spans through to COPY_HASH)
