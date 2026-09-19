CYCLE_VIDEO_PAGES_3WAY:
	jne [SCREEN_NUM], [0x65], CYCLE_VIDEO_PAGES_2WAY
	copyVideoPage src=0x03, dst=0xFF
	copyVideoPage src=0x00, dst=0x03
	copyVideoPage src=0xFF, dst=0x00
	mov [SCREEN_NUM], [0x65]
	mov [0x65], [CACHED_SCREEN_NUM]
	mov [CACHED_SCREEN_NUM], [SCREEN_NUM]
	jmp CYCLE_VIDEO_PAGES_RET

CYCLE_VIDEO_PAGES_2WAY:
	copyVideoPage src=0x00, dst=0x03
	mov [0x65], [CACHED_SCREEN_NUM]

CYCLE_VIDEO_PAGES_RET:
	ret

