LABEL_3FEF:
	break
	jmp LABEL_3FB4
LABEL_3FF3:
	db 0x11

LABEL_3FF4:
	setPalette 0x1F
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	mov [0xF8], [PAUSE_SLICES]
	mov [PAUSE_SLICES], 0x0001
	setPalette 0x0E
	blitFramebuffer 0xFE
	copyVideoPage src=0x03, dst=0xFF
	mov [PAUSE_SLICES], [0xF8]
	break
	jmp LABEL_3F67
LABEL_4011:
	db 0x11

LABEL_4012:
	setPalette 0x1E
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	mov [0xF8], [PAUSE_SLICES]
	mov [PAUSE_SLICES], 0x0001
	setPalette 0x0E
	blitFramebuffer 0xFE
	copyVideoPage src=0x00, dst=0xFF
	mov [PAUSE_SLICES], [0xF8]
	break
	jmp LABEL_3F38
LABEL_402F:
	db 0x11

LABEL_4030:
	setPalette 0x1F
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	mov [0xF8], [PAUSE_SLICES]
	mov [PAUSE_SLICES], 0x0001
	setPalette 0x19
	blitFramebuffer 0xFE
	copyVideoPage src=0x00, dst=0xFF
	mov [PAUSE_SLICES], [0xF8]
	break
	jmp LABEL_3F38

LABEL_404D:
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
	jmp LABEL_3F38
	killChannel
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
	jmp LABEL_3F38
LABEL_4088:
	db 0x11

LABEL_4089:
	break
	call DERIVE_HASH_BUCKETS_FROM_VAR38
	mov [SCROLL_Y], 0xFFFE
	setup channel=0x3C, address=LABEL_3F75
	break
	call DERIVE_HASH_BUCKETS_FROM_VAR38
	mov [SCROLL_Y], 0x0001
	setup channel=0x3C, address=LABEL_3F75
	jmp LABEL_4089
	killChannel
