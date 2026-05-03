CYCLE_VIDEO_PAGES_3WAY:
	jne [HACK_VAR_67], [0x65], CYCLE_VIDEO_PAGES_2WAY
	copyVideoPage src=0x03, dst=0xFF
	copyVideoPage src=0x00, dst=0x03
	copyVideoPage src=0xFF, dst=0x00
	mov [HACK_VAR_67], [0x65]
	mov [0x65], [0x66]
	mov [0x66], [HACK_VAR_67]
	jmp RET_TARGET_1915

CYCLE_VIDEO_PAGES_2WAY:
	copyVideoPage src=0x00, dst=0x03
	mov [0x65], [0x66]

RET_TARGET_1915:
	ret

