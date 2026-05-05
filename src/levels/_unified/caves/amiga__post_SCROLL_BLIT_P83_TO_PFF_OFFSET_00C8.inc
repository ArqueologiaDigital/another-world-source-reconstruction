LABEL_3DC3:
	break
	jmp LABEL_3D88
LABEL_3DC7:
	db 0x11

LABEL_3DC8:
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
	jmp LABEL_3D3B
LABEL_3DE5:
	db 0x11

LABEL_3DE6:
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
	jmp LABEL_3D25
LABEL_3E03:
	db 0x11

LABEL_3E04:
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
	jmp LABEL_3D25

LABEL_3E21:
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
	jmp LABEL_3D25
LABEL_3E3E:
	db 0x11, 0x0B, 0x1F, 0xFF, 0x10, 0xFF, 0x0D, 0xFF
	db 0x01, 0xF8, 0xFF, 0x00, 0xFF, 0x00, 0x01, 0x0B
	db 0x15, 0xFF, 0x10, 0xFE, 0x0F, 0x00, 0xFF, 0x01
	db 0xFF, 0xF8, 0x06, 0x07, 0x3D, 0x25, 0x11

LABEL_3E5D:
	break
	call DERIVE_HASH_BUCKETS_FROM_VAR38
	mov [SCROLL_Y], 0xFFFE
	setup channel=0x3C, address=LABEL_3D49
	break
	call DERIVE_HASH_BUCKETS_FROM_VAR38
	mov [SCROLL_Y], 0x0001
	setup channel=0x3C, address=LABEL_3D49
	jmp LABEL_3E5D
LABEL_3E78:
	db 0x11

LABEL_3E79:
	mov [0x7F], 0x000A
	mov [0xF8], [0xBB]
	and [0xF8], 0x0001
	je [0xF8], 0x00, DELAY_LOOP_VAR7F
	play id=0x006E, freq=0x0A, vol=0x22, channel=0x03
	mov [0x7F], 0x0001
	mov [0x75], 0xFFEC
	mov [0x78], 0xFFE2
	mov [0x7B], 0xFFF6

DELAY_LOOP_VAR7F:
	break
	djnz [0x7F], DELAY_LOOP_VAR7F
	play id=0x006E, freq=0x07, vol=0x22, channel=0x03
	setup channel=0x34, address=LABEL_3E5D
	mov [0x7F], 0x0001

DELAY_LOOP_VAR7F_AT_3EB3:
	break
	djnz [0x7F], DELAY_LOOP_VAR7F_AT_3EB3
	or [0xBB], 0x0001
	setup channel=0x2C, address=INLINE_SET_VAR79_TO_1
	mov [0x7F], 0x0002

DELAY_LOOP_VAR7F_AT_3EC4:
	break
	djnz [0x7F], DELAY_LOOP_VAR7F_AT_3EC4
	setup channel=0x34, address=KILL_CHANNEL_LANDING
	setup channel=0x2D, address=INLINE_SET_VAR7C_TO_0001_039
	mov [0x7F], 0x0002

DELAY_LOOP_VAR7F_AT_3ED5:
	break
	djnz [0x7F], DELAY_LOOP_VAR7F_AT_3ED5
	setup channel=0x34, address=LABEL_3E5D
	setup channel=0x2B, address=INLINE_SET_VAR76_TO_0001_037
	mov [0x7F], 0x0006

DELAY_LOOP_VAR7F_AT_3EE6:
	break
	djnz [0x7F], DELAY_LOOP_VAR7F_AT_3EE6
	mov [0x77], 0x0118
	mov [0x78], 0xFF56
	mov [0x79], 0x0001
	setup channel=0x2C, address=INLINE_SET_VAR79_TO_1
	mov [0x7F], 0x0004
	play id=0x006E, freq=0x08, vol=0x22, channel=0x03

DELAY_LOOP_VAR7F_AT_3F05:
	break
	djnz [0x7F], DELAY_LOOP_VAR7F_AT_3F05
	mov [0x74], [HERO_X]
	mov [0x75], 0xFFE2
	mov [0x76], 0x0001
	setup channel=0x2B, address=INLINE_SET_VAR76_TO_0001_038
	mov [0x7A], 0x00F0
	mov [0x7B], 0xFF9C
	mov [0x7C], 0x0001
	setup channel=0x2D, address=INLINE_SET_VAR7C_TO_0001_039
	play id=0x006E, freq=0x07, vol=0x40, channel=0x03
	killChannel
