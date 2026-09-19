LABEL_4005:
	break
	jmp LABEL_3FCA
LABEL_4009:
	db 0x11

CAVES_BARRIER_BREACH_PALETTE_FLASH_FRAME:
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
	jmp FRAME_PRESENT_RESTORE_PAGE_3_LOOP
LABEL_4027:
	db 0x11

CAVES_HERO_FALL_DEATH_PALETTE_FLASH_FRAME:
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
	jmp FRAME_PRESENT_RESTORE_PAGE_0_LOOP
LABEL_4045:
	db 0x11

CAVES_ROCK_CRUSH_PALETTE_FLASH_FRAME:
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
	jmp FRAME_PRESENT_RESTORE_PAGE_0_LOOP

CAVES_SCREEN_ED_EVENT_PALETTE_FLASH_FRAME:
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
	jmp FRAME_PRESENT_RESTORE_PAGE_0_LOOP
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
	jmp FRAME_PRESENT_RESTORE_PAGE_0_LOOP
LABEL_409E:
	db 0x11

LABEL_409F:
	break
	call DERIVE_HASH_BUCKETS_FROM_VAR38
	mov [SCROLL_Y], 0xFFFE
	setup channel=0x3C, address=COMMIT_WORK_PAGE_TO_PAGE_3_AND_REFETCH
	break
	call DERIVE_HASH_BUCKETS_FROM_VAR38
	mov [SCROLL_Y], 0x0001
	setup channel=0x3C, address=COMMIT_WORK_PAGE_TO_PAGE_3_AND_REFETCH
	jmp LABEL_409F
	killChannel
