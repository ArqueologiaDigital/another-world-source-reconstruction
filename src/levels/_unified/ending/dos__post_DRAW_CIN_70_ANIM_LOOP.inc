LABEL_022A:
	db 0x11

LABEL_022B:
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
	fill page=0x03, color=0x00
	break
	jne [0xDB], 0x00, LABEL_034A
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

DELAY_LOOP_VAR01__DOS__POST_DRAW_CIN_70_ANIM_LOOP:
	break
	djnz [0x01], DELAY_LOOP_VAR01__DOS__POST_DRAW_CIN_70_ANIM_LOOP
	setup channel=0x14, address=PAL_FADE_18_TO_1D
	mov [0x01], 0x00AF

LABEL_02A0:
	break
	sub [SCROLL_Y], 0x0001
	djnz [0x01], LABEL_02A0
	mov [0x01], 0x00C8

DELAY_LOOP_VAR01_AT_02AD:
	break
	djnz [0x01], DELAY_LOOP_VAR01_AT_02AD
	mov [0x01], 0x00B4

LABEL_02B6:
	break
	sub [SCROLL_Y], 0x0001
	djnz [0x01], LABEL_02B6
	selectVideoPage 0x00
	fill page=0x00, color=0x00
	text id=0x0263, x=6, y=0, color=0x0C ; "              Thanks To"
	text id=0x0264, x=6, y=30, color=0x0C ; "           Jesus Martinez\n\n          Daniel Morais\n\n        Frederic Savoir\n\n      Cecile Chahi\n\n    Philippe Delamarre\n\n  Philippe Ulrich\n\nSebastien Berthet\n\nPierre Gousseau"
	selectVideoPage 0xFF
	mov [SCROLL_Y], 0x00C8
	mov [0x01], 0x0096

LABEL_02DA:
	break
	sub [SCROLL_Y], 0x0001
	djnz [0x01], LABEL_02DA
	mov [0x01], 0x00C8

DELAY_LOOP_VAR01_AT_02E7:
	break
	djnz [0x01], DELAY_LOOP_VAR01_AT_02E7
	mov [0x01], 0x00C8

LABEL_02F0:
	break
	sub [SCROLL_Y], 0x0001
	djnz [0x01], LABEL_02F0
	selectVideoPage 0x00
	fill page=0x00, color=0x00
	text id=0x0265, x=6, y=0, color=0x0C ; "Now Go Out Of This World"
	selectVideoPage 0xFF
	mov [SCROLL_Y], 0x00C8
	mov [0x01], 0x0064

LABEL_030E:
	break
	sub [SCROLL_Y], 0x0001
	djnz [0x01], LABEL_030E
	mov [0x01], 0x00AA

DELAY_LOOP_VAR01_AT_031B:
	break
	djnz [0x01], DELAY_LOOP_VAR01_AT_031B
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

LABEL_034A:
	selectVideoPage 0x03
	text id=0x0258, x=2, y=20, color=0x0C ; "      Designed by ..... Eric Chahi"
	text id=0x0259, x=2, y=50, color=0x0C ; "    Programmed by...... Eric Chahi"
	text id=0x025A, x=2, y=80, color=0x0C ; "      Artwork ......... Eric Chahi"
	text id=0x025B, x=2, y=130, color=0x0C ; "Music by ........ Jean-francois Freitas"
	selectVideoPage 0xFF
	mov [SCROLL_Y], 0x0000
	setup channel=0x3C, address=SCROLL_Y_BLIT_DISPATCHER
	mov [PAUSE_SLICES], 0x0002
	mov [0x01], 0x000A

DELAY_LOOP_VAR01_AT_0376:
	break
	djnz [0x01], DELAY_LOOP_VAR01_AT_0376
	setup channel=0x14, address=PAL_FADE_18_TO_1D
	mov [0x01], 0x00C8

LABEL_0383:
	break
	sub [SCROLL_Y], 0x0001
	djnz [0x01], LABEL_0383
	selectVideoPage 0x00
	text id=0x025C, x=2, y=2, color=0x0C ; "            Sound effects"
	text id=0x025E, x=2, y=82, color=0x0C ; "string_025E"
	text id=0x025F, x=2, y=162, color=0x0C ; "string_025F"
	selectVideoPage 0xFF
	mov [0x01], 0x00C8

LABEL_03A6:
	break
	sub [SCROLL_Y], 0x0001
	djnz [0x01], LABEL_03A6
	fill page=0x03, color=0x00
	selectVideoPage 0x03
	text id=0x0260, x=2, y=45, color=0x0C ; "string_0260"
	text id=0x0261, x=2, y=172, color=0x0C ; "string_0261"
	selectVideoPage 0xFF
	mov [0x01], 0x00C8

LABEL_03C6:
	break
	sub [SCROLL_Y], 0x0001
	djnz [0x01], LABEL_03C6
	fill page=0x00, color=0x00
	mov [0x01], 0x00C8

LABEL_03D6:
	break
	sub [SCROLL_Y], 0x0001
	djnz [0x01], LABEL_03D6
	fill page=0x03, color=0x00
	selectVideoPage 0x03
	text id=0x0263, x=5, y=50, color=0x0C ; "              Thanks To"
	text id=0x0264, x=2, y=90, color=0x0C ; "           Jesus Martinez\n\n          Daniel Morais\n\n        Frederic Savoir\n\n      Cecile Chahi\n\n    Philippe Delamarre\n\n  Philippe Ulrich\n\nSebastien Berthet\n\nPierre Gousseau"
	selectVideoPage 0xFF
	sub [SCROLL_Y], 0x0032
	mov [0x01], 0x0096

LABEL_03FA:
	break
	sub [SCROLL_Y], 0x0001
	djnz [0x01], LABEL_03FA
	mov [0x01], 0x0028

DELAY_LOOP_VAR01_AT_0407:
	break
	djnz [0x01], DELAY_LOOP_VAR01_AT_0407
	fill page=0x00, color=0x00
	mov [0x01], 0x00BE

LABEL_0413:
	break
	sub [SCROLL_Y], 0x0001
	djnz [0x01], LABEL_0413
	sub [SCROLL_Y], 0x000A
	selectVideoPage 0x03
	fill page=0x03, color=0x00
	text id=0x0265, x=6, y=0, color=0x0C ; "Now Go Out Of This World"
	selectVideoPage 0xFF
	mov [0x01], 0x0064

LABEL_0431:
	break
	sub [SCROLL_Y], 0x0001
	djnz [0x01], LABEL_0431
	mov [0x01], 0x0096

DELAY_LOOP_VAR01_AT_043E:
	break
	djnz [0x01], DELAY_LOOP_VAR01_AT_043E
	song id=0x0000, delay=0x0000, pos=0x00
	killChannel
	killChannel
