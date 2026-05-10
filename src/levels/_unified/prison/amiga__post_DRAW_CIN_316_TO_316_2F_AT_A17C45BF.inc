LABEL_0A9A:
	db 0x11

LABEL_0A9B:
	video offset=CINEMATIC_317, x=160, y=100
	play id=0x0058, freq=0x14, vol=0x20, channel=0x02
	setPalette 0x05
	break
	setPalette 0x02
	jmp LABEL_0A04
