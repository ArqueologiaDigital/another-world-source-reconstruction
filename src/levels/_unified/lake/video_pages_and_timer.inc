RENDER_FRAME_DISPATCH:
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	je [0x1C], 0x00, BLIT_FROM_PAGE_40_LOOP
;@elif BRANCH == "chahi_amiga_1991"
	je [0x1C], 0x00, BLIT_FROM_PAGE_0_LOOP
;@endif
	je [0x1C], 0x02, CLEAR_FRAMEBUFFER_TO_COLOR_4_LOOP
;@if BRANCH in ("cartridge_1992", "gba_2004")
	jg [0x2A], 0x03, BLIT_FROM_PAGE_40_LOOP
	jne [0xDB], 0x00, BLIT_FROM_PAGE_40_VIA_C0
;@endif
;@if BRANCH == "dos_1992"
	jg [0x2A], 0x03, BLIT_FROM_PAGE_40_LOOP
	jne [0xDB], 0x00, BLIT_FROM_PAGE_40_VIA_C0
;@endif
	copyVideoPage src=0xFF, dst=0x03
	copyVideoPage src=0x83, dst=0xFF
	mov [0x65], 0x0000
;@if BRANCH in ("cartridge_1992", "dos_1992", "gba_2004")
	jmp BLIT_FROM_PAGE_40_LOOP

BLIT_FROM_PAGE_40_VIA_C0:
	copyVideoPage src=0xC0, dst=0x00
	jmp BLIT_FROM_PAGE_40_LOOP
;@elif BRANCH == "chahi_amiga_1991"
	jmp BLIT_FROM_PAGE_0_LOOP
	killChannel
;@endif

INIT_VIDEO_BUFFERS:
	fill page=0x01, color=0x00
	fill page=0x02, color=0x00
	fill page=0x03, color=0x00
	fill page=0x00, color=0x00
	selectVideoPage 0x01
	blitFramebuffer 0x01
	blitFramebuffer 0xFF
	blitFramebuffer 0x02
	ret
	killChannel

SHOW_PAGE_0_LOOP:
	selectVideoPage 0x00
	break
	jmp SHOW_PAGE_0_LOOP
	killChannel

SHOW_PAGE_FF_LOOP:
	selectVideoPage 0xFF
	break
	jmp SHOW_PAGE_FF_LOOP
	killChannel

INC_VAR_6E_PER_TICK_LOOP:
	add [0x6E], 0x0001
	break
	jmp INC_VAR_6E_PER_TICK_LOOP
	killChannel

WAIT_FOR_TIMER_AND_HACK_67_THEN_SETUP_31:
	break
	jl [0x6E], 0x64, WAIT_FOR_TIMER_AND_HACK_67_THEN_SETUP_31
	je [HACK_VAR_67], 0x05, WAIT_FOR_TIMER_AND_HACK_67_THEN_SETUP_31
	je [HACK_VAR_67], 0x02, WAIT_FOR_TIMER_AND_HACK_67_THEN_SETUP_31
	setup channel=0x31, address=PICK_RANDOM_X_FOR_DROPLET_AND_PLAY_DROP_SOUND
	deleteChannels first=0x24, last=0x25
	mov [0x71], 0x0001

