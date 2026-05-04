LABEL_149A:
	break
	call LABEL_14B5
	jne [HERO_ACTION], 0x00, LABEL_14A8
	djnz [0x03], LABEL_149A

LABEL_14A8:
	deleteChannels first=0x00, last=0x3F
	freezeChannels first=0x00, last=0x3F
	setup channel=0x00, address=LABEL_14C7
	killChannel

LABEL_14B5:
	je [0xDB], 0x00, SHARED_RET
	jne [HERO_POS_JUMP_DOWN], 0xFFFF, SHARED_RET
	mov [HERO_ACTION], 0x0001
	ret

LABEL_14C7:
	fill page=0x00, color=0x00
	fill page=0x03, color=0x00
	fill page=0xFF, color=0x00
	setup channel=0x3C, address=COPY_PAGE_40_BREAK_LOOP
	play id=0x005E, freq=0x00, vol=0x00, channel=0x00
	play id=0x005E, freq=0x00, vol=0x00, channel=0x01
	play id=0x005E, freq=0x00, vol=0x00, channel=0x02
	play id=0x005E, freq=0x00, vol=0x00, channel=0x03
	or [0xE3], 0x0001
	mov [PAUSE_SLICES], 0x0005
	break
	setPalette 0x1D

LABEL_14F8:
	break
	text id=0x013D, x=5, y=80, color=0x0C ; "    PRESS BUTTON TO CONTINUE

   PRESS START FOR CODE ENTRY"
	text id=0x013C, x=5, y=180, color=0x0E ; "        ACCESS CODE:"
	call LABEL_1533
	call LABEL_14B5
	jne [HERO_ACTION], 0x00, LABEL_14F8

LABEL_1511:
	break
	text id=0x013D, x=5, y=80, color=0x0C ; "    PRESS BUTTON TO CONTINUE

   PRESS START FOR CODE ENTRY"
	text id=0x013C, x=5, y=180, color=0x0E ; "        ACCESS CODE:"
	call LABEL_1533
	call LABEL_14B5
	je [HERO_ACTION], 0x00, LABEL_1511
	setup channel=0x3B, address=KILL_CHANNEL_LANDING
	setup channel=0x00, address=LABEL_0000
	killChannel

LABEL_1533:
	jne [0x00], 0x3C, LABEL_1540
	text id=0x016B, x=26, y=180, color=0x0D ; "LFCK"
	ret

LABEL_1540:
	jne [0x00], 0x3E, LABEL_154D
	text id=0x0171, x=26, y=180, color=0x0D ; "string_0171"
	ret

LABEL_154D:
	jne [0x00], 0x40, LABEL_155A
	text id=0x0172, x=26, y=180, color=0x0D ; "TFBB"
	ret

LABEL_155A:
	jne [0x00], 0x42, DRAW_TEXT_0174_AT_26_180
	text id=0x0173, x=26, y=180, color=0x0D ; "TXHF"
	ret
