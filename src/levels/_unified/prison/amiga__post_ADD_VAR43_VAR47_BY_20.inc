LABEL_7F4D:
	break
	je [HACK_VAR_67], 0x65, JUMP_TO_LABEL_7F0E
	mov [0x43], 0x00C1
	mov [0x47], 0x00C1

JUMP_TO_LABEL_7F0E:
	jmp LABEL_7F0E
LABEL_7F5F:
	db 0x11

LABEL_7F60:
	freezeChannels first=0x00, last=0x3F
	setup channel=0x3C, address=LABEL_069F
	setup channel=0x14, address=LABEL_8F00
	jne [0x11], 0x01, LABEL_7F75
	mov [0x6A], [HACK_VAR_67]

LABEL_7F75:
	mov [0x63], 0x0001
	call LABEL_85F5
	call LABEL_85E8
	setup channel=0x01, address=COPY_PAGE0_TO_FF_KILL_CHANNEL
	play id=0x0067, freq=0x14, vol=0x40, channel=0x01
	break
	jmp LABEL_7EC8
LABEL_7F8D:
	db 0x11
