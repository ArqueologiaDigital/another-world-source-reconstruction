LABEL_0C16:
	video offset=CINEMATIC_459, x=160, y=[0xe8], zoom=0x40
	sub [0xE8], 0x0002
	break
	djnz [0xE7], LABEL_0C16
	jmp INIT_VARS_E7_E8
LABEL_0C27:
	db 0x11

LABEL_0C28:
	mov [0xB4], 0x0001
	setup channel=0x01, address=KILL_CHANNEL_LANDING
	setup channel=0x3C, address=LABEL_06C3
	killChannel
