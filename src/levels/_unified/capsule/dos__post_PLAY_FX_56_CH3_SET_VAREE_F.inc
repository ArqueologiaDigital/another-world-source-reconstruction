DELAY_LOOP_VAREE:
	break
	djnz [0xEE], DELAY_LOOP_VAREE
	play id=0x0030, freq=0x14, vol=0x08, channel=0x03
	mov [0xEE], 0x000B

DELAY_LOOP_VAREE_AT_0987:
	break
	djnz [0xEE], DELAY_LOOP_VAREE_AT_0987
	play id=0x0052, freq=0x14, vol=0x0C, channel=0x03
	mov [0xEE], 0x0007

DELAY_LOOP_VAREE_AT_0996:
	break
	djnz [0xEE], DELAY_LOOP_VAREE_AT_0996
	play id=0x0030, freq=0x0C, vol=0x0C, channel=0x03
	mov [0xEE], 0x000A

DELAY_LOOP_VAREE_AT_09A5:
	break
	djnz [0xEE], DELAY_LOOP_VAREE_AT_09A5
	play id=0x0075, freq=0x02, vol=0x0C, channel=0x03
	mov [0xEE], 0x000A

DELAY_LOOP_VAREE_AT_09B4:
	break
	djnz [0xEE], DELAY_LOOP_VAREE_AT_09B4
	jmp PLAY_FX_56_CH3_SET_VAREE_F

LABEL_09BC:
	mov [0xEB], 0x00A0
	video offset=CINEMATIC_237, x=[0xeb], y=[0x40], zoom=0x40
	video offset=CINEMATIC_593, x=[0xeb], y=[0x40], zoom=0x40
	break
	video offset=CINEMATIC_238, x=[0xeb], y=[0x40], zoom=0x40
	video offset=CINEMATIC_593, x=[0xeb], y=[0x40], zoom=0x40
	break
	video offset=CINEMATIC_239, x=[0xeb], y=[0x40], zoom=0x40
	video offset=CINEMATIC_594, x=[0xeb], y=[0x40], zoom=0x40
	break
	video offset=CINEMATIC_241, x=[0xeb], y=[0x40], zoom=0x40
	video offset=CINEMATIC_594, x=[0xeb], y=[0x40], zoom=0x40
	break
	video offset=CINEMATIC_238, x=[0xeb], y=[0x40], zoom=0x40
	video offset=CINEMATIC_594, x=[0xeb], y=[0x40], zoom=0x40
	break
	jmp LABEL_09BC
LABEL_09FA:
	db 0x11

LABEL_09FB:
	video offset=CINEMATIC_573, x=125, y=65508, zoom=0x40
	play id=0x0052, freq=0x1E, vol=0x40, channel=0x00
	break
	video offset=CINEMATIC_574, x=125, y=65508, zoom=0x40
	break
	break
	break
	video offset=CINEMATIC_231, x=176, y=90
	break
	video offset=CINEMATIC_229, x=211, y=125
	break
	video offset=CINEMATIC_231, x=114, y=28
	break
	break
	jmp LABEL_09FB
LABEL_0A24:
	db 0x11
