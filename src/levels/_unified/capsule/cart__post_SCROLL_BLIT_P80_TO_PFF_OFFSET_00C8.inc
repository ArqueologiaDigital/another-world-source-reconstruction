LABEL_3107:
	break
	jmp LABEL_30CC
LABEL_310B:
	db 0x11

LABEL_310C:
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
	jmp LABEL_2FD9
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
LABEL_3147:
	db 0x11

LABEL_3148:
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
LABEL_3165:
	db 0x11

LABEL_3166:
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

LABEL_3184:
	break
	call DERIVE_HASH_BUCKETS_FROM_VAR38
	mov [SCROLL_Y], 0xFFFE
	setup channel=0x3C, address=JUNK__2FE7
	break
	call DERIVE_HASH_BUCKETS_FROM_VAR38
	mov [SCROLL_Y], 0x0001
	setup channel=0x3C, address=JUNK__2FE7
	jmp LABEL_3184
LABEL_319F:
	db 0x11
