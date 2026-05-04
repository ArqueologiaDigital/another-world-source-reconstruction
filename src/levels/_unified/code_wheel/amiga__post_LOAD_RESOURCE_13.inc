LABEL_00E3:
	selectVideoPage 0xFF
	setup channel=0x2C, address=PAL_FADE_DOWN_E_TO_8
	mov [0x03], 0x0028

DELAY_LOOP_VAR03_AT_00ED:
	break
	djnz [0x03], DELAY_LOOP_VAR03_AT_00ED
	setup channel=0x2C, address=PAL_FADE_UP_9_TO_F
	mov [0x03], 0x000A

DELAY_LOOP_VAR03_AT_00FA:
	break
	djnz [0x03], DELAY_LOOP_VAR03_AT_00FA
	fill page=0x00, color=0x00
	selectVideoPage 0x00
	text id=0x0181, x=18, y=80, color=0x02 ; " BY"
	text id=0x0182, x=15, y=100, color=0x03 ; "ERIC CHAHI"
	selectVideoPage 0xFF
	break
	setPalette 0x1B
	mov [0x03], 0x003C

DELAY_LOOP_VAR03_AT_011A:
	break
	djnz [0x03], DELAY_LOOP_VAR03_AT_011A
	break
	fill page=0x00, color=0x00
	selectVideoPage 0x00
	text id=0x0183, x=1, y=80, color=0x04 ; "         MUSIC AND SOUND EFFECTS"
	text id=0x0184, x=20, y=100, color=0x05 ; " "
	text id=0x0185, x=11, y=120, color=0x06 ; "JEAN-FRANCOIS FREITAS"
	selectVideoPage 0xFF
	mov [0x03], 0x003C
	and [HACK_VAR_54], 0x0001
	je [HACK_VAR_54], 0x00, DELAY_LOOP_VAR03_AT_016B

DELAY_LOOP_VAR03_AT_0147:
	break
	djnz [0x03], DELAY_LOOP_VAR03_AT_0147
	break
	fill page=0x00, color=0x00
	selectVideoPage 0x00
	text id=0x0186, x=14, y=80, color=0x04 ; "IBM PC VERSION"
	text id=0x0187, x=14, y=100, color=0x06 ; "      BY"
	text id=0x0188, x=14, y=120, color=0x05 ; " DANIEL MORAIS"
	selectVideoPage 0xFF
	break
	mov [0x03], 0x003C

DELAY_LOOP_VAR03_AT_016B:
	break
	djnz [0x03], DELAY_LOOP_VAR03_AT_016B
	fill page=0x00, color=0x00
	break
	break
	bankSwitch 1;  Intro Sequence
	killChannel
