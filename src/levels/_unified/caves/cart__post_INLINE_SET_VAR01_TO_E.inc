LABEL_1D9C:
	add [0xE8], 0x0005
	sub [0xE9], 0x001E
	add [0xEA], 0x000C
	sub [0xEB], 0x000F
	add [0xEC], 0x0009
	sub [0xED], 0x0014
	add [0xEE], 0x000F
	sub [0xEF], 0x000C
	break
	djnz [HERO_X], LABEL_1D9C
	setup channel=0x13, address=KILL_CHANNEL_LANDING
	mov [0x03], 0x0005
	setup channel=0x3F, address=LABEL_0211
	fill page=0x00, color=0x00
	fill page=0x03, color=0x00
	killChannel

LABEL_1DD4:
	video offset=CINEMATIC_008, x=160, y=[0xe7]
	break
	setPalette 0x0D
	play id=0x0052, freq=0x0A, vol=0x40, channel=0x02
	video offset=CINEMATIC_009, x=160, y=[0xe7]
	break
	setPalette 0x08
	video offset=CINEMATIC_010, x=160, y=[0xe7]
	break
	video offset=CINEMATIC_011, x=160, y=[0xe7]
	killChannel

LABEL_1DF8:
	video offset=CINEMATIC_008, x=160, y=[0xe8]
	break
	play id=0x0052, freq=0x14, vol=0x40, channel=0x02
	video offset=CINEMATIC_009, x=160, y=[0xe8]
	break
	video offset=CINEMATIC_010, x=160, y=[0xe8]
	break
	video offset=CINEMATIC_011, x=160, y=[0xe8]
	killChannel

HANG_DRAW_CIN_012:
	video offset=CINEMATIC_012, x=160, y=100
	break
	jmp HANG_DRAW_CIN_012
LABEL_1E1E:
	db 0x11
