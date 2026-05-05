LABEL_0590:
	break
	video offset=CINEMATIC_422, x=[HERO_X], y=[HERO_Y]
	djnz [0x03], LABEL_0590
	break
	video offset=CINEMATIC_421, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_420, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_419, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_418, x=[HERO_X], y=[HERO_Y]
	mov [0x03], 0x0009

LABEL_05B6:
	break
	video offset=CINEMATIC_215, x=[HERO_X], y=[HERO_Y]
	djnz [0x03], LABEL_05B6
	break
	video offset=CINEMATIC_212, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_211, x=[HERO_X], y=[HERO_Y]
	mov [0x63], 0x0002
	break
	play id=0x0060, freq=0x14, vol=0x1E, channel=0x00
	call LABEL_6C9A
	setup channel=0x15, address=INLINE_SET_VAR03_TO_7
	break
	jmp LABEL_9638
LABEL_05E2:
	db 0x11
