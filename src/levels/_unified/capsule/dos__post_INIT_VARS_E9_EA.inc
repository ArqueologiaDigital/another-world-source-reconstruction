DELAY_LOOP_VAREA__DOS__POST_INIT_VARS_E9_EA:
	break
	djnz [0xEA], DELAY_LOOP_VAREA__DOS__POST_INIT_VARS_E9_EA
	play id=0x0030, freq=0x0A, vol=0x40, channel=0x03
	video type=1, offset=CINEMATIC_595, x=[0xe9], y=[0x40], zoom=0x40
	break
	sub [0xE9], 0x000F
	video type=1, offset=CINEMATIC_596, x=[0xe9], y=[0x40], zoom=0x40
	break
	sub [0xE9], 0x000F
	video type=1, offset=CINEMATIC_597, x=[0xe9], y=[0x40], zoom=0x40
	sub [0xE9], 0x0005
	break
	mov [0xEA], 0x0005

LABEL_071F:
	sub [0xE9], 0x0001
	video type=1, offset=CINEMATIC_598, x=[0xe9], y=[0x40], zoom=0x40
	break
	djnz [0xEA], LABEL_071F
	play id=0x005A, freq=0x14, vol=0x40, channel=0x02
	play id=0x005D, freq=0x14, vol=0x40, channel=0x01
	video type=1, offset=CINEMATIC_599, x=[0xe9], y=[0x40], zoom=0x40
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_600, x=[0xe9], y=98, zoom=0x40
	selectVideoPage 0xFF
	break
	sub [0xE9], 0x000C
	video type=1, offset=CINEMATIC_217, x=[0xe9], y=[0x40], zoom=0x40
	break
	video type=1, offset=CINEMATIC_218, x=[0xe9], y=[0x40], zoom=0x40
	break
	video type=1, offset=CINEMATIC_219, x=[0xe9], y=[0x40], zoom=0x40
	break
	video type=1, offset=CINEMATIC_220, x=[0xe9], y=[0x40], zoom=0x40
	break
	video type=1, offset=CINEMATIC_221, x=[0xe9], y=[0x40], zoom=0x40
	break
	video type=1, offset=CINEMATIC_222, x=[0xe9], y=[0x40], zoom=0x40
	break
	video type=1, offset=CINEMATIC_223, x=[0xe9], y=[0x40], zoom=0x40
	break
	video type=1, offset=CINEMATIC_224, x=[0xe9], y=[0x40], zoom=0x40
	killChannel
