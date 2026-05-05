DELAY_LOOP_VARE6_AT_3FAF:
	break
	djnz [0xE6], DELAY_LOOP_VARE6_AT_3FAF
	mov [SCROLL_Y], 0xFF6A
	setup channel=0x3C, address=LABEL_3D5B
	break
	add [SCROLL_Y], 0x000E
	setup channel=0x3C, address=LABEL_3D5B
	break
	setup channel=0x3C, address=LABEL_3D61
	add [SCROLL_Y], 0x0012
	selectVideoPage 0x03
	video offset=CINEMATIC_374, x=160, y=100
	copyVideoPage src=0x83, dst=0x00
	selectVideoPage 0xFF
	killChannel

LABEL_3FDA:
	fill page=0x01, color=0x00
	fill page=0x02, color=0x00
	selectVideoPage 0x01
	blitFramebuffer 0x01
	blitFramebuffer 0xFF
	blitFramebuffer 0x02
	ret
LABEL_3FE9:
	db 0x11, 0x0D, 0x00, 0x06, 0x07, 0x3F, 0xEA, 0x11
	db 0x0D, 0xFF, 0x06, 0x07, 0x3F, 0xF1, 0x11
; (cart has no chunk here — cart_pre above already spans through to COPY_HASH)
