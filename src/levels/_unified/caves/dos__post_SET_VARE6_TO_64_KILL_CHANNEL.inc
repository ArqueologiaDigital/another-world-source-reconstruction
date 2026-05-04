DELAY_LOOP_VARE6_AT_42B4:
	break
	djnz [0xE6], DELAY_LOOP_VARE6_AT_42B4
	mov [SCROLL_Y], 0xFF6A
	setup channel=0x3C, address=LABEL_3F9D
	break
	add [SCROLL_Y], 0x000E
	setup channel=0x3C, address=LABEL_3F9D
	break
	setup channel=0x3C, address=LABEL_3FA3
	add [SCROLL_Y], 0x0012
	selectVideoPage 0x03
	video type=1, offset=CINEMATIC_395, x=160, y=100
	copyVideoPage src=0x83, dst=0x00
	selectVideoPage 0xFF
	killChannel
