BLITTER_LOOP_COPY_PAGE_00:
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	copyVideoPage src=0x00, dst=0xFF
	break
	jmp BLITTER_LOOP_COPY_PAGE_00

JUNK__0AD7:
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	break
	jmp JUNK__0AD7

BLITTER_LOOP_COPY_PAGE_80:
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	fill page=0xFF, color=0x00
	copyVideoPage src=0x80, dst=0xFF
	break
	jmp BLITTER_LOOP_COPY_PAGE_80

SCROLL_Y_BLIT_DISPATCHER:
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	jg [SCROLL_Y], 0xFF38, SCROLL_Y_UP_PAGE_80_THEN_83
	add [SCROLL_Y], 0x00C8
	jmp SCROLL_Y_DOWN_PAGE_83_THEN_80

SCROLL_Y_UP_PAGE_80_THEN_83:
	copyVideoPage src=0x80, dst=0xFF
	add [SCROLL_Y], 0x00C8
	copyVideoPage src=0x83, dst=0xFF
	sub [SCROLL_Y], 0x00C8
	break
	jmp SCROLL_Y_BLIT_DISPATCHER

SCROLL_Y_BLIT_DISPATCHER_VARIANT:
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	jg [SCROLL_Y], 0xFF38, SCROLL_Y_DOWN_PAGE_83_THEN_80
	add [SCROLL_Y], 0x00C8
	jmp SCROLL_Y_UP_PAGE_80_THEN_83

SCROLL_Y_DOWN_PAGE_83_THEN_80:
	copyVideoPage src=0x83, dst=0xFF
	add [SCROLL_Y], 0x00C8
	copyVideoPage src=0x80, dst=0xFF
	sub [SCROLL_Y], 0x00C8
	break
	jmp SCROLL_Y_BLIT_DISPATCHER_VARIANT
