BLIT_FROM_PAGE_0_LOOP:
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	copyVideoPage src=0x00, dst=0xFF
	break
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	copyVideoPage src=0x00, dst=0xFF
	break
	jmp BLIT_FROM_PAGE_40_LOOP
;@elif BRANCH == "chahi_amiga_1991"
	jmp BLIT_FROM_PAGE_0_LOOP
;@endif

BLIT_AND_SHOW_PAGE_FF_LOOP:
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	break
	jmp BLIT_AND_SHOW_PAGE_FF_LOOP

BLIT_FROM_PAGE_3_LOOP:
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	copyVideoPage src=0x03, dst=0xFF
	break
	jmp BLIT_FROM_PAGE_3_LOOP

