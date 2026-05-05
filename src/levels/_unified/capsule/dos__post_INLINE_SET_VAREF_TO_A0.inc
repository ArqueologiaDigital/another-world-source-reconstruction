LABEL_21DD:
	video offset=CINEMATIC_348, x=[0xef], y=120, zoom=0x40
	sub [0xEF], 0x0014
	break
	video offset=CINEMATIC_348, x=[0xef], y=114, zoom=0x40
	play id=0x0060, freq=0x14, vol=0x20, channel=0x00
	sub [0xEF], 0x0014
	break
	video offset=CINEMATIC_348, x=[0xef], y=110, zoom=0x40
	sub [0xEF], 0x0014
	break
	play id=0x008D, freq=0x22, vol=0x0A, channel=0x02
	video offset=CINEMATIC_348, x=[0xef], y=108, zoom=0x40
	sub [0xEF], 0x0014
	break
	video offset=CINEMATIC_348, x=[0xef], y=110, zoom=0x40
	sub [0xEF], 0x0014
	break
	play id=0x0060, freq=0x16, vol=0x14, channel=0x00
	video offset=CINEMATIC_348, x=[0xef], y=114, zoom=0x40
	sub [0xEF], 0x0014
	break
	video offset=CINEMATIC_348, x=[0xef], y=116, zoom=0x40
	sub [0xEF], 0x0014
	break
	jmp LABEL_21DD

LABEL_2238:
	video offset=CINEMATIC_404, x=[0xe9], y=[0xea], zoom=0x40
	play id=0x008D, freq=0x14, vol=0x40, channel=0x00
	break
	video offset=CINEMATIC_397, x=[0xe9], y=[0xea], zoom=0x40
	break
	video offset=CINEMATIC_398, x=[0xe9], y=[0xea], zoom=0x40
	break
	video offset=CINEMATIC_399, x=[0xe9], y=[0xea], zoom=0x40
	play id=0x0074, freq=0x14, vol=0x40, channel=0x01
	break
	video offset=CINEMATIC_400, x=[0xe9], y=[0xea], zoom=0x40
	break
	video offset=CINEMATIC_401, x=[0xe9], y=[0xea], zoom=0x40
	break
	video offset=CINEMATIC_402, x=[0xe9], y=[0xea], zoom=0x40
	break
	video offset=CINEMATIC_403, x=[0xe9], y=[0xea], zoom=0x40
	killChannel

LABEL_2274:
	video offset=CINEMATIC_397, x=[0xeb], y=[0xec], zoom=0x40
	play id=0x008D, freq=0x14, vol=0x40, channel=0x03
	break
	video offset=CINEMATIC_398, x=[0xeb], y=[0xec], zoom=0x40
	break
	video offset=CINEMATIC_399, x=[0xeb], y=[0xec], zoom=0x40
	break
	video offset=CINEMATIC_400, x=[0xeb], y=[0xec], zoom=0x40
	break
	video offset=CINEMATIC_401, x=[0xeb], y=[0xec], zoom=0x40
	break
	video offset=CINEMATIC_402, x=[0xeb], y=[0xec], zoom=0x40
	break
	video offset=CINEMATIC_403, x=[0xeb], y=[0xec], zoom=0x40
	killChannel

LABEL_22A4:
	video offset=CINEMATIC_397, x=2, y=103
	break
	video offset=CINEMATIC_398, x=2, y=103
	break
	video offset=CINEMATIC_399, x=2, y=103
	break
	video offset=CINEMATIC_400, x=2, y=103
	break
	video offset=CINEMATIC_401, x=2, y=103
	break
	video offset=CINEMATIC_402, x=2, y=103
	break
	video offset=CINEMATIC_403, x=2, y=103
	killChannel

LABEL_22C7:
	video offset=CINEMATIC_361, x=179, y=100
	break
	video offset=CINEMATIC_361, x=179, y=100
	break
	video offset=CINEMATIC_397, x=179, y=100
	break
	video offset=CINEMATIC_398, x=179, y=100
	break
	video offset=CINEMATIC_399, x=179, y=100
	break
	video offset=CINEMATIC_400, x=179, y=100
	break
	video offset=CINEMATIC_401, x=179, y=100
	break
	video offset=CINEMATIC_402, x=179, y=100
	break
	video offset=CINEMATIC_403, x=179, y=100
	killChannel

LABEL_22F4:
	video offset=CINEMATIC_362, x=[0xe6], y=[0xe7], zoom=0x40
	play id=0x006C, freq=0x14, vol=0x18, channel=0x01
	break
	video offset=CINEMATIC_363, x=[0xe6], y=[0xe7], zoom=0x40
	break
	video offset=CINEMATIC_364, x=[0xe6], y=[0xe7], zoom=0x40
	break
	video offset=CINEMATIC_365, x=[0xe6], y=[0xe7], zoom=0x40
	break
	video offset=CINEMATIC_366, x=[0xe6], y=[0xe7], zoom=0x40
	break
	video offset=CINEMATIC_367, x=[0xe6], y=[0xe7], zoom=0x40
	break
	video offset=CINEMATIC_368, x=[0xe6], y=[0xe7], zoom=0x40
	break
	video offset=CINEMATIC_369, x=[0xe6], y=[0xe7], zoom=0x40
	break
	video offset=CINEMATIC_369, x=[0xe6], y=[0xe7], zoom=0x40
	break
	jmp LABEL_22F4
LABEL_2333:
	db 0x11
