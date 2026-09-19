LABEL_814E:
	break
	je [SCREEN_NUM], 0x65, JUMP_TO_LABEL_810F
	mov [0x43], 0x00C1
	mov [0x47], 0x00C1

JUMP_TO_LABEL_810F:
	jmp LABEL_810F
LABEL_8160:
	db 0x11

LABEL_8161:
	freezeChannels first=0x00, last=0x3F
	setup channel=0x3C, address=LABEL_06ED
	setup channel=0x14, address=PRISON_HERO_STAND_LEFT_TICK
	jne [0x11], 0x01, LABEL_8176
	mov [0x6A], [SCREEN_NUM]

LABEL_8176:
	mov [0x63], 0x0001
	call LABEL_884B
	call LABEL_883E
	setup channel=0x01, address=COPY_PAGE0_TO_FF_KILL_CHANNEL
	play id=0x0067, freq=0x14, vol=0x40, channel=0x01
	break
	jmp PRISON_HERO_GATE_X_91_B8_CLOCK_4000_INPUT_CHECK
LABEL_818E:
	db 0x11
