LABEL_42EF:
	selectVideoPage 0x00	;@raw=0x0D,0x00
	break	;@raw=0x06
	jmp LABEL_42EF	;@raw=0x07,0x42,0xEF
	killChannel	;@raw=0x11

LABEL_42F6:
	selectVideoPage 0xFF	;@raw=0x0D,0xFF
	break	;@raw=0x06
	jmp LABEL_42F6	;@raw=0x07,0x42,0xF6
LABEL_42FC:
	db 0x11
; (cart has no chunk here — cart_pre above already spans through to COPY_HASH)
