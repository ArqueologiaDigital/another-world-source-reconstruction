LABEL_801F:
	break
	je [HACK_VAR_67], 0x65, JUMP_TO_LABEL_7FE0
	mov [0x43], 0x00C1
	mov [0x47], 0x00C1

JUMP_TO_LABEL_7FE0:
	jmp LABEL_7FE0
LABEL_8031:
	db 0x11

LABEL_8032:
	freezeChannels first=0x00, last=0x3F
	setup channel=0x3C, address=LABEL_0665
	setup channel=0x14, address=LABEL_90C6
	jne [0x11], 0x01, LABEL_8047
	mov [0x6A], [HACK_VAR_67]

LABEL_8047:
	mov [0x63], 0x0001
	call LABEL_86FA
	call LABEL_86ED
	setup channel=0x01, address=COPY_PAGE0_TO_FF_KILL_CHANNEL
	play id=0x0067, freq=0x14, vol=0x40, channel=0x01
	break
	jmp LABEL_7F9A
LABEL_805F:
	db 0x11
