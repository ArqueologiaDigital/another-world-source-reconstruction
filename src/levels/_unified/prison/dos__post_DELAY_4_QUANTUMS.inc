LABEL_00A2:
	break
	call LABEL_00CB
	jne [HERO_ACTION], 0x00, LABEL_00A2
	mov [0x03], 0x0014

LABEL_00B0:
	break
	call LABEL_00CB
	jne [HERO_ACTION], 0x00, LABEL_00BE
	djnz [0x03], LABEL_00B0

LABEL_00BE:
	deleteChannels first=0x00, last=0x3F
	setup channel=0x3C, address=BLIT_PAGE_00_TO_FF_AND_BREAK
	setup channel=0x00, address=LABEL_00DD
	killChannel

LABEL_00CB:
	je [0xDB], 0x00, SHARED_RET
	jne [HERO_POS_JUMP_DOWN], 0xFFFF, SHARED_RET
	mov [HERO_ACTION], 0x0001
	ret

LABEL_00DD:
	fill page=0x00, color=0x00
	fill page=0x03, color=0x00
	fill page=0xFF, color=0x00
	setup channel=0x3C, address=BLIT_PAGE_00_TO_FF_AND_BREAK
	mov [PAUSE_SLICES], 0x0005

LABEL_00EE:
	break
	call LABEL_00CB
	jne [HERO_ACTION], 0x00, LABEL_00EE
	setPalette 0x1D

LABEL_00FB:
	text id=0x013D, x=5, y=80, color=0x0D ; "PRESS BUTTON OR RETURN TO CONTINUE"
	text id=0x013C, x=5, y=180, color=0x0C ; "        ACCESS CODE:"
	text id=0x015F, x=26, y=180, color=0x0E ; "HTDC"
	break
	call LABEL_00CB
	je [HERO_ACTION], 0x00, LABEL_00FB
	mov [0x00], 0x0015
	setup channel=0x00, address=LABEL_0000
	killChannel
