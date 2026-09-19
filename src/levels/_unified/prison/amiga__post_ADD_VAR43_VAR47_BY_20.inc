LABEL_7F4D:
	break
	je [SCREEN_NUM], 0x65, JUMP_TO_LABEL_7F0E
	mov [0x43], 0x00C1
	mov [0x47], 0x00C1

JUMP_TO_LABEL_7F0E:
	jmp LABEL_7F0E
LABEL_7F5F:
	db 0x11

LABEL_7F60:
	freezeChannels first=0x00, last=0x3F
	setup channel=0x3C, address=LABEL_069F
	setup channel=0x14, address=PRISON_HERO_STAND_LEFT_TICK
	jne [0x11], 0x01, LABEL_7F75
	mov [0x6A], [SCREEN_NUM]

LABEL_7F75:
	mov [0x63], 0x0001
	call LABEL_85F5
	call LABEL_85E8
	setup channel=0x01, address=COPY_PAGE0_TO_FF_KILL_CHANNEL
	play id=0x0067, freq=0x14, vol=0x40, channel=0x01
	break
	jmp PRISON_HERO_GATE_X_91_B8_CLOCK_4000_INPUT_CHECK
LABEL_7F8D:
	db 0x11
