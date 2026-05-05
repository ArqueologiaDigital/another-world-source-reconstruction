DELAY_LOOP_VAREE:
	break
	djnz [0xEE], DELAY_LOOP_VAREE
	play id=0x0030, freq=0x14, vol=0x08, channel=0x03
	mov [0xEE], 0x000B

DELAY_LOOP_VAREE_AT_0A3D:
	break
	djnz [0xEE], DELAY_LOOP_VAREE_AT_0A3D
	play id=0x0052, freq=0x14, vol=0x0C, channel=0x03
	mov [0xEE], 0x0007

DELAY_LOOP_VAREE_AT_0A4C:
	break
	djnz [0xEE], DELAY_LOOP_VAREE_AT_0A4C
	play id=0x0030, freq=0x0C, vol=0x0C, channel=0x03
	mov [0xEE], 0x000A

DELAY_LOOP_VAREE_AT_0A5B:
	break
	djnz [0xEE], DELAY_LOOP_VAREE_AT_0A5B
	play id=0x0075, freq=0x02, vol=0x0C, channel=0x03
	mov [0xEE], 0x000A

DELAY_LOOP_VAREE_AT_0A6A:
	break
	djnz [0xEE], DELAY_LOOP_VAREE_AT_0A6A
	jmp PLAY_FX_56_CH3_SET_VAREE_F

LABEL_0A72:
	mov [0xEB], 0x00A0
	video offset=CINEMATIC_238, x=[0xeb], y=[0x40], zoom=0x40
	video offset=CINEMATIC_602, x=[0xeb], y=[0x40], zoom=0x40
	break
	video offset=CINEMATIC_239, x=[0xeb], y=[0x40], zoom=0x40
	video offset=CINEMATIC_602, x=[0xeb], y=[0x40], zoom=0x40
	break
	video offset=CINEMATIC_240, x=[0xeb], y=[0x40], zoom=0x40
	video offset=CINEMATIC_603, x=[0xeb], y=[0x40], zoom=0x40
	break
	video offset=CINEMATIC_242, x=[0xeb], y=[0x40], zoom=0x40
	video offset=CINEMATIC_603, x=[0xeb], y=[0x40], zoom=0x40
	break
	video offset=CINEMATIC_239, x=[0xeb], y=[0x40], zoom=0x40
	video offset=CINEMATIC_603, x=[0xeb], y=[0x40], zoom=0x40
	break
	jmp LABEL_0A72
LABEL_0AB0:
	db 0x11

LABEL_0AB1:
	video offset=CINEMATIC_582, x=125, y=65508, zoom=0x40
	play id=0x0052, freq=0x1E, vol=0x40, channel=0x00
	break
	video offset=CINEMATIC_583, x=125, y=65508, zoom=0x40
	break
	break
	break
	video offset=CINEMATIC_232, x=176, y=90
	break
	video offset=CINEMATIC_230, x=211, y=125
	break
	video offset=CINEMATIC_232, x=114, y=28
	break
	break
	jmp LABEL_0AB1
LABEL_0ADA:
	db 0x11
