LABEL_0664:
	db 0x11

LABEL_0665:
	call INCREMENT_VAR31
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	copyVideoPage src=0x40, dst=0xFF
	break
	jmp LABEL_0665

BLIT_PAGE_00_TO_FF_AND_BREAK:
	call INCREMENT_VAR31
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	copyVideoPage src=0x00, dst=0xFF
	break
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	copyVideoPage src=0x00, dst=0xFF
	break
	jmp LABEL_0665

LABEL_0689:
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	break
	jmp LABEL_0689

JUNK__0691:
	call INCREMENT_VAR31
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	copyVideoPage src=0x03, dst=0xFF
	break
	jmp JUNK__0691

LABEL_069F:
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
	jmp LABEL_0665

JUNK__06BC:
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	jg [SCROLL_Y], 0xFF38, LABEL_06CB
	add [SCROLL_Y], 0x00C8

LABEL_06CB:
	jl [SCROLL_Y], 0xC8, LABEL_06D5
	sub [SCROLL_Y], 0x00C8

LABEL_06D5:
	copyVideoPage src=0x80, dst=0xFF
	jl [SCROLL_Y], 0x00, SCROLL_BLIT_P80_TO_PFF_OFFSET_00C8
	sub [SCROLL_Y], 0x00C8
	copyVideoPage src=0x80, dst=0xFF
	add [SCROLL_Y], 0x00C8
	jmp LABEL_06F7
