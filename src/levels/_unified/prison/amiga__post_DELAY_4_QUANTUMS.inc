LABEL_00A2:
	break
	jne [HERO_ACTION], 0x00, LABEL_00A2
	mov [0x03], 0x0014

LABEL_00AD:
	break
	jne [HERO_ACTION], 0x00, LABEL_00B8
	djnz [0x03], LABEL_00AD

LABEL_00B8:
	deleteChannels first=0x00, last=0x3F
	setup channel=0x00, address=LABEL_00C1
	killChannel

LABEL_00C1:
	fill page=0x00, color=0x00
	fill page=0x03, color=0x00
	fill page=0xFF, color=0x00
	setup channel=0x3C, address=LABEL_069F
	mov [PAUSE_SLICES], 0x0005

LABEL_00D2:
	break
	jne [HERO_ACTION], 0x00, LABEL_00D2
	setPalette 0x1D

LABEL_00DC:
	text id=0x013D, x=5, y=80, color=0x0D ; "PRESS BUTTON OR RETURN TO CONTINUE"
	text id=0x013C, x=5, y=180, color=0x0C ; "        ACCESS CODE:"
	text id=0x015F, x=26, y=180, color=0x0E ; "HTDC"
	break
	je [HERO_ACTION], 0x00, LABEL_00DC
	mov [0x00], 0x0015
	setup channel=0x00, address=LABEL_0000
	killChannel
