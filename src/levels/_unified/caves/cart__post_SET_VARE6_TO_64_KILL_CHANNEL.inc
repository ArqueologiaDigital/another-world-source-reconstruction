DELAY_LOOP_VARE6_AT_429E:
	break
	djnz [0xE6], DELAY_LOOP_VARE6_AT_429E
	mov [SCROLL_Y], 0xFF6A
	setup channel=0x3C, address=LABEL_3F87
	break
	add [SCROLL_Y], 0x000E
	setup channel=0x3C, address=LABEL_3F87
	break
	setup channel=0x3C, address=LABEL_3F8D
	add [SCROLL_Y], 0x0012
	selectVideoPage 0x03
	video offset=CINEMATIC_394, x=160, y=100
	copyVideoPage src=0x83, dst=0x00
	selectVideoPage 0xFF
	killChannel
