DELAY_LOOP_VARE8__DOS__POST_INIT_VARS_E7_E8:
	break
	djnz [0xE8], DELAY_LOOP_VARE8__DOS__POST_INIT_VARS_E7_E8
	play id=0x0030, freq=0x19, vol=0x20, channel=0x02
	video type=1, offset=CINEMATIC_601, x=[0xe7], y=[0x40], zoom=0x40
	break
	add [0xE7], 0x0014
	video type=1, offset=CINEMATIC_602, x=[0xe7], y=[0x40], zoom=0x40
	break
	add [0xE7], 0x000F
	play id=0x0075, freq=0x0A, vol=0x40, channel=0x02
	video type=1, offset=CINEMATIC_603, x=[0xe7], y=[0x40], zoom=0x40
	add [0xE7], 0x0002
	mov [0xE8], 0x0005

LABEL_06D2:
	break
	add [0xE7], 0x0001
	video type=1, offset=CINEMATIC_604, x=[0xe7], y=[0x40], zoom=0x40
	djnz [0xE8], LABEL_06D2
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_604, x=[0xe7], y=[0x40], zoom=0x40
	selectVideoPage 0xFF
	killChannel
