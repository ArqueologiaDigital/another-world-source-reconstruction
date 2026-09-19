LABEL_022A:
	db 0x11

ENDING_CREDITS_ROLL_ENTRY:
	setPalette 0x10
	break
	setPalette 0x11
	break
	setPalette 0x12
	break
	setPalette 0x13
	break
	setPalette 0x14
	break
	setPalette 0x15
	break
	setPalette 0x16
	break
	setPalette 0x17
	deleteChannels first=0x0A, last=0x11
	fill page=0x00, color=0x00
	break
	selectVideoPage 0x00
	text id=0x0258, x=2, y=10, color=0x0C ; "      Designed by ..... Eric Chahi"
	text id=0x0259, x=2, y=40, color=0x0C ; "    Programmed by...... Eric Chahi"
	text id=0x025A, x=2, y=70, color=0x0C ; "      Artwork ......... Eric Chahi"
	text id=0x025B, x=1, y=100, color=0x0C ; "Music by ........ Jean-francois Freitas"
	text id=0x025C, x=2, y=130, color=0x0C ; "            Sound effects"
	text id=0x025D, x=2, y=140, color=0x0C ; "        Jean-Francois Freitas\n             Eric Chahi"
	selectVideoPage 0xFF
	mov [SCROLL_Y], 0x00C8
	setup channel=0x3C, address=BLITTER_LOOP_COPY_PAGE_80
	mov [PAUSE_SLICES], 0x0002
	mov [0x01], 0x000A

ENDING_CREDITS_ROLL_START_DELAY:
	break
	djnz [0x01], ENDING_CREDITS_ROLL_START_DELAY
	setup channel=0x14, address=PAL_ENDING_CREDITS_FADE_18_TO_1D
	mov [0x01], 0x00AF

ENDING_CREDITS_CREW_PAGE_SCROLL_IN_LOOP:
	break
	sub [SCROLL_Y], 0x0001
	djnz [0x01], ENDING_CREDITS_CREW_PAGE_SCROLL_IN_LOOP
	mov [0x01], 0x00C8

ENDING_CREDITS_STAFF_HOLD:
	break
	djnz [0x01], ENDING_CREDITS_STAFF_HOLD
	mov [0x01], 0x00B4

ENDING_CREDITS_CREW_PAGE_SCROLL_OUT_THEN_THANKS:
	break
	sub [SCROLL_Y], 0x0001
	djnz [0x01], ENDING_CREDITS_CREW_PAGE_SCROLL_OUT_THEN_THANKS
	selectVideoPage 0x00
	fill page=0x00, color=0x00
	text id=0x0263, x=6, y=0, color=0x0C ; "              Thanks To"
	text id=0x0264, x=6, y=30, color=0x0C ; "           Jesus Martinez\n\n          Daniel Morais\n\n        Frederic Savoir\n\n      Cecile Chahi\n\n    Philippe Delamarre\n\n  Philippe Ulrich\n\nSebastien Berthet\n\nPierre Gousseau"
	selectVideoPage 0xFF
	mov [SCROLL_Y], 0x00C8
	mov [0x01], 0x0096

ENDING_CREDITS_THANKS_SCROLL_IN_LOOP:
	break
	sub [SCROLL_Y], 0x0001
	djnz [0x01], ENDING_CREDITS_THANKS_SCROLL_IN_LOOP
	mov [0x01], 0x00C8

ENDING_CREDITS_THANKS_HOLD:
	break
	djnz [0x01], ENDING_CREDITS_THANKS_HOLD
	mov [0x01], 0x00C8

ENDING_CREDITS_THANKS_SCROLL_OUT_THEN_SIGNOFF:
	break
	sub [SCROLL_Y], 0x0001
	djnz [0x01], ENDING_CREDITS_THANKS_SCROLL_OUT_THEN_SIGNOFF
	selectVideoPage 0x00
	fill page=0x00, color=0x00
	text id=0x0265, x=6, y=0, color=0x0C ; "Now Go Out Of This World"
	selectVideoPage 0xFF
	mov [SCROLL_Y], 0x00C8
	mov [0x01], 0x0064

ENDING_CREDITS_SIGNOFF_SCROLL_IN_LOOP:
	break
	sub [SCROLL_Y], 0x0001
	djnz [0x01], ENDING_CREDITS_SIGNOFF_SCROLL_IN_LOOP
	mov [0x01], 0x0096

ENDING_CREDITS_SIGNOFF_HOLD_THEN_MUSIC_STOP:
	break
	djnz [0x01], ENDING_CREDITS_SIGNOFF_HOLD_THEN_MUSIC_STOP
	song id=0x0000, delay=0x0000, pos=0x00
	killChannel
	selectVideoPage 0x00
	text id=0x017C, x=9, y=10, color=0x0C ; "string_017C"
	text id=0x017D, x=19, y=40, color=0x05 ; "string_017D"
	text id=0x017E, x=13, y=90, color=0x0B ; "string_017E"
	text id=0x0180, x=12, y=120, color=0x0D ; "string_0180"
	text id=0x017F, x=12, y=150, color=0x0E ; "string_017F"
	selectVideoPage 0xFF
	killChannel
