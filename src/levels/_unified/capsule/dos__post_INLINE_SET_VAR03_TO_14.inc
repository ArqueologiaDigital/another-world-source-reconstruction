LABEL_13AD:
	break
	call LABEL_13C4
	jne [HERO_ACTION], 0x00, LABEL_13BB
	djnz [0x03], LABEL_13AD

LABEL_13BB:
	deleteChannels first=0x00, last=0x3F
	setup channel=0x00, address=LABEL_13D6
	killChannel

LABEL_13C4:
	je [0xDB], 0x00, SHARED_RET
	jne [HERO_POS_JUMP_DOWN], 0xFFFF, SHARED_RET
	mov [HERO_ACTION], 0x0001
	ret

LABEL_13D6:
	fill page=0x00, color=0x00
	fill page=0x03, color=0x00
	fill page=0xFF, color=0x00
	setup channel=0x3C, address=COPY_PAGE_40_BREAK_LOOP
	play id=0x005E, freq=0x00, vol=0x00, channel=0x00
	play id=0x005E, freq=0x00, vol=0x00, channel=0x01
	play id=0x005E, freq=0x00, vol=0x00, channel=0x02
	play id=0x005E, freq=0x00, vol=0x00, channel=0x03
	mov [PAUSE_SLICES], 0x0005
	break
	setPalette 0x1D

LABEL_1403:
	text id=0x013D, x=5, y=80, color=0x0C ; "PRESS BUTTON OR RETURN TO CONTINUE"
	text id=0x013C, x=5, y=180, color=0x0E ; "        ACCESS CODE:"
	call LABEL_1425
	break
	call LABEL_13C4
	je [HERO_ACTION], 0x00, LABEL_1403
	setup channel=0x3B, address=KILL_CHANNEL_LANDING
	setup channel=0x00, address=LABEL_0000
	killChannel

LABEL_1425:
	jne [0x00], 0x3C, LABEL_1432
	text id=0x016B, x=26, y=180, color=0x0D ; "LFCK"
	ret

LABEL_1432:
	jne [0x00], 0x3E, LABEL_143F
	text id=0x0171, x=26, y=180, color=0x0D ; "HHFL"
	ret

LABEL_143F:
	jne [0x00], 0x40, LABEL_144C
	text id=0x0172, x=26, y=180, color=0x0D ; "TFBB"
	ret

LABEL_144C:
	jne [0x00], 0x42, DRAW_TEXT_0174_AT_26_180
	text id=0x0173, x=26, y=180, color=0x0D ; "TXHF"
	ret
