LABEL_4005:
	break
	jmp LABEL_3FCA
LABEL_4009:
	db 0x11

LABEL_400A:
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
	jmp LABEL_3F7D
LABEL_4027:
	db 0x11

LABEL_4028:
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
	jmp LABEL_3F4E
LABEL_4045:
	db 0x11

LABEL_4046:
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
	jmp LABEL_3F4E

LABEL_4063:
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
	jmp LABEL_3F4E
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
	jmp LABEL_3F4E
LABEL_409E:
	db 0x11

LABEL_409F:
	break
	call DERIVE_HASH_BUCKETS_FROM_VAR38
	mov [SCROLL_Y], 0xFFFE
	setup channel=0x3C, address=LABEL_3F8B
	break
	call DERIVE_HASH_BUCKETS_FROM_VAR38
	mov [SCROLL_Y], 0x0001
	setup channel=0x3C, address=LABEL_3F8B
	jmp LABEL_409F
	killChannel
