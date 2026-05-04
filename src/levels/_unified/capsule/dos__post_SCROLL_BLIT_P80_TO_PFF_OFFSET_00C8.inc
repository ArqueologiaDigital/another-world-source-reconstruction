LABEL_2F8A:
	break
	jmp LABEL_2F4F
LABEL_2F8E:
	db 0x11

LABEL_2F8F:
	setPalette 0x06
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	mov [0xF8], [PAUSE_SLICES]
	mov [PAUSE_SLICES], 0x0001
	setPalette 0x01
	blitFramebuffer 0xFE
	copyVideoPage src=0x00, dst=0xFF
	mov [PAUSE_SLICES], [0xF8]
	break
	jmp LABEL_2E5C
	killChannel
	setPalette 0x1F
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	mov [0xF8], [PAUSE_SLICES]
	mov [PAUSE_SLICES], 0x0001
	setPalette 0x01
	blitFramebuffer 0xFE
	copyVideoPage src=0x00, dst=0xFF
	mov [PAUSE_SLICES], [0xF8]
	break
	jmp COPY_PAGE_40_BREAK_LOOP
LABEL_2FCA:
	db 0x11

LABEL_2FCB:
	setPalette 0x1F
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	mov [0xF8], [PAUSE_SLICES]
	mov [PAUSE_SLICES], 0x0001
	setPalette 0x0E
	blitFramebuffer 0xFE
	copyVideoPage src=0x00, dst=0xFF
	mov [PAUSE_SLICES], [0xF8]
	break
	jmp COPY_PAGE_40_BREAK_LOOP
LABEL_2FE8:
	db 0x11

LABEL_2FE9:
	setPalette 0x1F
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	mov [0xF8], [PAUSE_SLICES]
	mov [PAUSE_SLICES], 0x0001
	setPalette 0x15
	blitFramebuffer 0xFE
	copyVideoPage src=0x00, dst=0xFF
	mov [PAUSE_SLICES], [0xF8]
	break
	jmp COPY_PAGE_40_BREAK_LOOP
	killChannel

LABEL_3007:
	break
	call DERIVE_HASH_BUCKETS_FROM_VAR38
	mov [SCROLL_Y], 0xFFFE
	setup channel=0x3C, address=JUNK__2E6A
	break
	call DERIVE_HASH_BUCKETS_FROM_VAR38
	mov [SCROLL_Y], 0x0001
	setup channel=0x3C, address=JUNK__2E6A
	jmp LABEL_3007
LABEL_3022:
	db 0x11
