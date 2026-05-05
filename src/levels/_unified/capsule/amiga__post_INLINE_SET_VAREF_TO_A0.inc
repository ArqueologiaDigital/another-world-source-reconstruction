LABEL_1056:
	video offset=CINEMATIC_002, x=[0xef], y=120, zoom=0x40
	sub [0xEF], 0x0014
	break
	video offset=CINEMATIC_002, x=[0xef], y=114, zoom=0x40
	play id=0x0060, freq=0x14, vol=0x20, channel=0x00
	sub [0xEF], 0x0014
	break
	video offset=CINEMATIC_002, x=[0xef], y=110, zoom=0x40
	sub [0xEF], 0x0014
	break
	play id=0x008D, freq=0x22, vol=0x0A, channel=0x02
	video offset=CINEMATIC_002, x=[0xef], y=108, zoom=0x40
	sub [0xEF], 0x0014
	break
	video offset=CINEMATIC_002, x=[0xef], y=110, zoom=0x40
	sub [0xEF], 0x0014
	break
	play id=0x0060, freq=0x16, vol=0x14, channel=0x00
	video offset=CINEMATIC_002, x=[0xef], y=114, zoom=0x40
	sub [0xEF], 0x0014
	break
	video offset=CINEMATIC_002, x=[0xef], y=116, zoom=0x40
	sub [0xEF], 0x0014
	break
	jmp LABEL_1056

LABEL_10B1:
	video offset=CINEMATIC_058, x=[0xe9], y=[0xea], zoom=0x40
	play id=0x008D, freq=0x14, vol=0x40, channel=0x00
	break
	video offset=CINEMATIC_051, x=[0xe9], y=[0xea], zoom=0x40
	break
	video offset=CINEMATIC_052, x=[0xe9], y=[0xea], zoom=0x40
	break
	video offset=CINEMATIC_053, x=[0xe9], y=[0xea], zoom=0x40
	play id=0x0074, freq=0x14, vol=0x40, channel=0x01
	break
	video offset=CINEMATIC_054, x=[0xe9], y=[0xea], zoom=0x40
	break
	video offset=CINEMATIC_055, x=[0xe9], y=[0xea], zoom=0x40
	break
	video offset=CINEMATIC_056, x=[0xe9], y=[0xea], zoom=0x40
	break
	video offset=CINEMATIC_057, x=[0xe9], y=[0xea], zoom=0x40
	killChannel

LABEL_10ED:
	video offset=CINEMATIC_051, x=[0xeb], y=[0xec], zoom=0x40
	play id=0x008D, freq=0x14, vol=0x40, channel=0x03
	break
	video offset=CINEMATIC_052, x=[0xeb], y=[0xec], zoom=0x40
	break
	video offset=CINEMATIC_053, x=[0xeb], y=[0xec], zoom=0x40
	break
	video offset=CINEMATIC_054, x=[0xeb], y=[0xec], zoom=0x40
	break
	video offset=CINEMATIC_055, x=[0xeb], y=[0xec], zoom=0x40
	break
	video offset=CINEMATIC_056, x=[0xeb], y=[0xec], zoom=0x40
	break
	video offset=CINEMATIC_057, x=[0xeb], y=[0xec], zoom=0x40
	killChannel

LABEL_111D:
	video offset=CINEMATIC_051, x=2, y=103
	break
	video offset=CINEMATIC_052, x=2, y=103
	break
	video offset=CINEMATIC_053, x=2, y=103
	break
	video offset=CINEMATIC_054, x=2, y=103
	break
	video offset=CINEMATIC_055, x=2, y=103
	break
	video offset=CINEMATIC_056, x=2, y=103
	break
	video offset=CINEMATIC_057, x=2, y=103
	killChannel

LABEL_1140:
	video offset=CINEMATIC_015, x=179, y=100
	break
	video offset=CINEMATIC_015, x=179, y=100
	break
	video offset=CINEMATIC_051, x=179, y=100
	break
	video offset=CINEMATIC_052, x=179, y=100
	break
	video offset=CINEMATIC_053, x=179, y=100
	break
	video offset=CINEMATIC_054, x=179, y=100
	break
	video offset=CINEMATIC_055, x=179, y=100
	break
	video offset=CINEMATIC_056, x=179, y=100
	break
	video offset=CINEMATIC_057, x=179, y=100
	killChannel

LABEL_116D:
	video offset=CINEMATIC_016, x=[0xe6], y=[0xe7], zoom=0x40
	play id=0x006C, freq=0x14, vol=0x18, channel=0x01
	break
	video offset=CINEMATIC_017, x=[0xe6], y=[0xe7], zoom=0x40
	break
	video offset=CINEMATIC_018, x=[0xe6], y=[0xe7], zoom=0x40
	break
	video offset=CINEMATIC_019, x=[0xe6], y=[0xe7], zoom=0x40
	break
	video offset=CINEMATIC_020, x=[0xe6], y=[0xe7], zoom=0x40
	break
	video offset=CINEMATIC_021, x=[0xe6], y=[0xe7], zoom=0x40
	break
	video offset=CINEMATIC_022, x=[0xe6], y=[0xe7], zoom=0x40
	break
	video offset=CINEMATIC_023, x=[0xe6], y=[0xe7], zoom=0x40
	break
	video offset=CINEMATIC_023, x=[0xe6], y=[0xe7], zoom=0x40
	break
	jmp LABEL_116D
LABEL_11AC:
	db 0x11
