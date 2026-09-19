LABEL_3F4D:
	db 0x11

; mirrors CAPSULE_HOLD_PAGE_40
FRAME_PRESENT_RESTORE_PAGE_0_LOOP:
	call INCREMENT_VAR31
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	copyVideoPage src=0x40, dst=0xFF
	break
	jmp FRAME_PRESENT_RESTORE_PAGE_0_LOOP

LABEL_3F5C:
	call INCREMENT_VAR31
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	copyVideoPage src=0x00, dst=0xFF
	break
	call INCREMENT_VAR31
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	copyVideoPage src=0x00, dst=0xFF
	break
	jmp FRAME_PRESENT_RESTORE_PAGE_0_LOOP

JUNK__3F75:
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	break
	jmp JUNK__3F75

FRAME_PRESENT_RESTORE_PAGE_3_LOOP:
	call INCREMENT_VAR31
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	copyVideoPage src=0x03, dst=0xFF
	break
	jmp FRAME_PRESENT_RESTORE_PAGE_3_LOOP

COMMIT_WORK_PAGE_TO_PAGE_3_AND_REFETCH:
	copyVideoPage src=0xFF, dst=0x03
	copyVideoPage src=0x83, dst=0xFF
	jmp FRAME_PRESENT_RESTORE_PAGE_0_LOOP

COMMIT_WORK_PAGE_TO_PAGE_0_AND_REFETCH:
	copyVideoPage src=0xFF, dst=0x00
	copyVideoPage src=0x80, dst=0xFF
	jmp LABEL_DD3E

LABEL_3F9D:
	copyVideoPage src=0x83, dst=0xFF
	jmp FRAME_PRESENT_RESTORE_PAGE_0_LOOP

LABEL_3FA3:
	copyVideoPage src=0x83, dst=0xFF
	mov [SCROLL_Y], 0x0005
	jmp COMMIT_WORK_PAGE_TO_PAGE_3_AND_REFETCH

LABEL_3FAD:
	setPalette 0x1F
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	mov [0xF8], [PAUSE_SLICES]
	mov [PAUSE_SLICES], 0x0001
	setPalette 0x02
	blitFramebuffer 0xFE
	copyVideoPage src=0x00, dst=0xFF
	mov [PAUSE_SLICES], [0xF8]
	break
	jmp FRAME_PRESENT_RESTORE_PAGE_0_LOOP

LABEL_3FCA:
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	jge [SCROLL_Y], 0xFF38, CAVES_SCROLL_Y_WRAP_DOWN_FROM_C8
	add [SCROLL_Y], 0x00C8

CAVES_SCROLL_Y_WRAP_DOWN_FROM_C8:
	jl [SCROLL_Y], 0xC8, LABEL_3FE3
	sub [SCROLL_Y], 0x00C8

LABEL_3FE3:
	copyVideoPage src=0x80, dst=0xFF
	jl [SCROLL_Y], 0x00, SCROLL_BLIT_P83_TO_PFF_OFFSET_00C8
	sub [SCROLL_Y], 0x00C8
	copyVideoPage src=0x83, dst=0xFF
	add [SCROLL_Y], 0x00C8
	jmp LABEL_4005
