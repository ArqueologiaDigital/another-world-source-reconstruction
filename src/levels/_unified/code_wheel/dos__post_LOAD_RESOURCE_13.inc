LABEL_00F9:
	selectVideoPage 0xFF
	setup channel=0x2C, address=PAL_FADE_DOWN_E_TO_8
	mov [0x03], 0x0050

WAIT_FOR_HERO_ACTION_LOOP:
	break
	jne [HERO_ACTION], 0x00, BANK1_INTRO_TRANSITION
	djnz [0x03], WAIT_FOR_HERO_ACTION_LOOP
	setup channel=0x2C, address=PAL_FADE_UP_9_TO_F
	mov [0x03], 0x000A

LABEL_0116:
	break
	jne [HERO_ACTION], 0x00, BANK1_INTRO_TRANSITION
	djnz [0x03], LABEL_0116
	fill page=0x00, color=0x00
	selectVideoPage 0x00
	text id=0x0181, x=18, y=80, color=0x02 ; " BY"
	text id=0x0182, x=15, y=100, color=0x03 ; "ERIC CHAHI"
	selectVideoPage 0xFF
	break
	setPalette 0x1B
	mov [0x03], 0x003C

LABEL_013C:
	break
	jne [HERO_ACTION], 0x00, BANK1_INTRO_TRANSITION
	djnz [0x03], LABEL_013C
	break
	fill page=0x00, color=0x00
	selectVideoPage 0x00
	text id=0x0183, x=1, y=80, color=0x04 ; "         MUSIC AND SOUND EFFECTS"
	text id=0x0184, x=20, y=100, color=0x05 ; " "
	text id=0x0185, x=11, y=120, color=0x06 ; "JEAN-FRANCOIS FREITAS"
	selectVideoPage 0xFF
	mov [0x03], 0x003C
	and [HACK_VAR_54], 0x0001
	je [HACK_VAR_54], 0x00, LABEL_0199

LABEL_016F:
	break
	jne [HERO_ACTION], 0x00, BANK1_INTRO_TRANSITION
	djnz [0x03], LABEL_016F
	break
	fill page=0x00, color=0x00
	selectVideoPage 0x00
	text id=0x0186, x=14, y=80, color=0x04 ; "IBM PC VERSION"
	text id=0x0187, x=14, y=100, color=0x06 ; "      BY"
	text id=0x0188, x=14, y=120, color=0x05 ; " DANIEL MORAIS"
	selectVideoPage 0xFF
	break
	mov [0x03], 0x003C

LABEL_0199:
	break
	jne [HERO_ACTION], 0x00, BANK1_INTRO_TRANSITION
	djnz [0x03], LABEL_0199

BANK1_INTRO_TRANSITION:
	fill page=0x00, color=0x00
	break
	break
	bankSwitch 1;  Intro Sequence
	killChannel
