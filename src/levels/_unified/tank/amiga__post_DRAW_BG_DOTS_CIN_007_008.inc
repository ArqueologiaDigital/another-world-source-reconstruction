HANG_BLITTING_PAGE_FF:
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	copyVideoPage src=0x00, dst=0xFF
	break
	jmp HANG_BLITTING_PAGE_FF
LABEL_1ABB:
	db 0x10, 0xFF, 0x0D, 0xFF, 0x06, 0x07, 0x1A, 0xBB

BLITTER_LOOP_COPY_PAGE_03:
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	copyVideoPage src=0x03, dst=0xFF
	call SUM_HASH_VARS_TO_VAR_64
	break
	jmp BLITTER_LOOP_COPY_PAGE_03
LABEL_1AD1:
	db 0x11

PALETTE_FLASH_1F_TO_01:
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	mov [PAUSE_SLICES], 0x0002
	setPalette 0x1F
	blitFramebuffer 0xFE
	setPalette 0x01
	blitFramebuffer 0xFE
	mov [PAUSE_SLICES], 0x0006
	copyVideoPage src=0x03, dst=0xFF
	break
	jmp BLITTER_LOOP_COPY_PAGE_03
LABEL_1AEF:
	db 0x11
