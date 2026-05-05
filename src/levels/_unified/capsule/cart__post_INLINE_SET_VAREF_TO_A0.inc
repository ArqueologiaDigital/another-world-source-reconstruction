LABEL_22F1:
	video offset=CINEMATIC_349, x=[0xef], y=120
	sub [0xEF], 0x0014
	break
	video offset=CINEMATIC_349, x=[0xef], y=114
	play id=0x0060, freq=0x14, vol=0x20, channel=0x00
	sub [0xEF], 0x0014
	break
	video offset=CINEMATIC_349, x=[0xef], y=110
	sub [0xEF], 0x0014
	break
	play id=0x008D, freq=0x22, vol=0x0A, channel=0x02
	video offset=CINEMATIC_349, x=[0xef], y=108
	sub [0xEF], 0x0014
	break
	video offset=CINEMATIC_349, x=[0xef], y=110
	sub [0xEF], 0x0014
	break
	play id=0x0060, freq=0x16, vol=0x14, channel=0x00
	video offset=CINEMATIC_349, x=[0xef], y=114
	sub [0xEF], 0x0014
	break
	video offset=CINEMATIC_349, x=[0xef], y=116
	sub [0xEF], 0x0014
	break
	jmp LABEL_22F1

LABEL_234C:
	video offset=CINEMATIC_408, x=[0xe9], y=[0xea]
	play id=0x008D, freq=0x14, vol=0x40, channel=0x00
	break
	video offset=CINEMATIC_400, x=[0xe9], y=[0xea]
	je [0xDB], 0x01, LABEL_2368
	video offset=CINEMATIC_407, x=[0xe9], y=[0xea]

LABEL_2368:
	break
	video offset=CINEMATIC_401, x=[0xe9], y=[0xea]
	break
	video offset=CINEMATIC_402, x=[0xe9], y=[0xea]
	play id=0x0074, freq=0x14, vol=0x40, channel=0x01
	break
	video offset=CINEMATIC_403, x=[0xe9], y=[0xea]
	break
	video offset=CINEMATIC_404, x=[0xe9], y=[0xea]
	break
	video offset=CINEMATIC_405, x=[0xe9], y=[0xea]
	break
	video offset=CINEMATIC_406, x=[0xe9], y=[0xea]
	killChannel

LABEL_2393:
	video offset=CINEMATIC_400, x=[0xeb], y=[0xec]
	play id=0x008D, freq=0x14, vol=0x40, channel=0x03
	je [0xDB], 0x01, LABEL_23A9
	video offset=CINEMATIC_407, x=[0xeb], y=[0xec]

LABEL_23A9:
	break
	video offset=CINEMATIC_401, x=[0xeb], y=[0xec]
	break
	video offset=CINEMATIC_402, x=[0xeb], y=[0xec]
	break
	video offset=CINEMATIC_403, x=[0xeb], y=[0xec]
	break
	video offset=CINEMATIC_404, x=[0xeb], y=[0xec]
	break
	video offset=CINEMATIC_405, x=[0xeb], y=[0xec]
	break
	video offset=CINEMATIC_406, x=[0xeb], y=[0xec]
	killChannel

LABEL_23CE:
	video offset=CINEMATIC_400, x=2, y=103
	je [0xDB], 0x01, LABEL_23DC
	video offset=CINEMATIC_407, x=2, y=103

LABEL_23DC:
	break
	video offset=CINEMATIC_401, x=2, y=103
	break
	video offset=CINEMATIC_402, x=2, y=103
	break
	video offset=CINEMATIC_403, x=2, y=103
	break
	video offset=CINEMATIC_404, x=2, y=103
	break
	video offset=CINEMATIC_405, x=2, y=103
	break
	video offset=CINEMATIC_406, x=2, y=103
	killChannel

LABEL_23FB:
	video offset=CINEMATIC_362, x=179, y=100
	break
	video offset=CINEMATIC_362, x=179, y=100
	break
	video offset=CINEMATIC_400, x=179, y=100
	je [0xDB], 0x01, LABEL_2413
	video offset=CINEMATIC_407, x=179, y=100

LABEL_2413:
	break
	video offset=CINEMATIC_401, x=179, y=100
	break
	video offset=CINEMATIC_402, x=179, y=100
	break
	video offset=CINEMATIC_403, x=179, y=100
	break
	video offset=CINEMATIC_404, x=179, y=100
	break
	video offset=CINEMATIC_405, x=179, y=100
	break
	video offset=CINEMATIC_406, x=179, y=100
	killChannel

LABEL_2432:
	video offset=CINEMATIC_365, x=[0xe6], y=[0xe7]
	play id=0x006C, freq=0x14, vol=0x18, channel=0x01
	break
	video offset=CINEMATIC_366, x=[0xe6], y=[0xe7]
	break
	video offset=CINEMATIC_367, x=[0xe6], y=[0xe7]
	break
	video offset=CINEMATIC_368, x=[0xe6], y=[0xe7]
	break
	video offset=CINEMATIC_369, x=[0xe6], y=[0xe7]
	break
	video offset=CINEMATIC_370, x=[0xe6], y=[0xe7]
	break
	video offset=CINEMATIC_371, x=[0xe6], y=[0xe7]
	break
	video offset=CINEMATIC_372, x=[0xe6], y=[0xe7]
	break
	video offset=CINEMATIC_372, x=[0xe6], y=[0xe7]
	break
	jmp LABEL_2432
LABEL_2471:
	db 0x11
