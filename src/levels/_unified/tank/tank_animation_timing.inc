ALTERNATE_VAR06_VAR04_TIMING:
	mov [0x06], 0x0002
	mov [0x04], 0x0001
	break
	break
	mov [0x06], 0x0001
	mov [0x04], 0x0002
	break
	break
	mov [0x06], 0x0001
	mov [0x04], 0x0003
	break
	break
	mov [0x06], 0x0005
	mov [0x04], 0x0004
	sub [0x05], 0x0004
	break
	mov [0x06], 0x0006
	break
	mov [0x06], 0x0007
	mov [0x06], 0x0008
	break
	sub [0x07], 0x0001
	break
	mov [0x04], 0x0000
	killChannel

;@if BRANCH == "chahi_amiga_1991"
;@include "amiga__post_ALTERNATE_VAR06_VAR04_TIMING.inc"
;@elif BRANCH == "cartridge_1992"
;@include "cart__post_ALTERNATE_VAR06_VAR04_TIMING.inc"
;@elif BRANCH == "dos_1992"
;@include "dos__post_ALTERNATE_VAR06_VAR04_TIMING.inc"
;@endif

