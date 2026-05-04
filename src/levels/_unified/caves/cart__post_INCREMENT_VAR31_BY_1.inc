LABEL_3F37:
	db 0x11

LABEL_3F38:
	call INCREMENT_VAR31
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	copyVideoPage src=0x40, dst=0xFF
	break
	jmp LABEL_3F38

LABEL_3F46:
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
	jmp LABEL_3F38

JUNK__3F5F:
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	break
	jmp JUNK__3F5F

LABEL_3F67:
	call INCREMENT_VAR31
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	copyVideoPage src=0x03, dst=0xFF
	break
	jmp LABEL_3F67

LABEL_3F75:
	copyVideoPage src=0xFF, dst=0x03
	copyVideoPage src=0x83, dst=0xFF
	jmp LABEL_3F38

LABEL_3F7E:
	copyVideoPage src=0xFF, dst=0x00
	copyVideoPage src=0x80, dst=0xFF
	jmp LABEL_DDC7

LABEL_3F87:
	copyVideoPage src=0x83, dst=0xFF
	jmp LABEL_3F38

LABEL_3F8D:
	copyVideoPage src=0x83, dst=0xFF
	mov [SCROLL_Y], 0x0005
	jmp LABEL_3F75

LABEL_3F97:
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
	jmp LABEL_3F38

LABEL_3FB4:
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	jge [SCROLL_Y], 0xFF38, LABEL_3FC3
	add [SCROLL_Y], 0x00C8

LABEL_3FC3:
	jl [SCROLL_Y], 0xC8, LABEL_3FCD
	sub [SCROLL_Y], 0x00C8

LABEL_3FCD:
	copyVideoPage src=0x80, dst=0xFF
	jl [SCROLL_Y], 0x00, SCROLL_BLIT_P83_TO_PFF_OFFSET_00C8
	sub [SCROLL_Y], 0x00C8
	copyVideoPage src=0x83, dst=0xFF
	add [SCROLL_Y], 0x00C8
	jmp LABEL_3FEF
