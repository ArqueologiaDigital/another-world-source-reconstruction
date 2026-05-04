DELAY_LOOP_VARED_AT_1CDC:
	break
	djnz [0xED], DELAY_LOOP_VARED_AT_1CDC
	setup channel=0x38, address=LABEL_2384
	mov [0xED], 0x000A

DELAY_LOOP_VARED_AT_1CE9:
	break
	djnz [0xED], DELAY_LOOP_VARED_AT_1CE9
	setup channel=0x35, address=LABEL_23F3
	setup channel=0x36, address=LABEL_23BA
	mov [0xED], 0x000A

DELAY_LOOP_VARED_AT_1CFA:
	break
	djnz [0xED], DELAY_LOOP_VARED_AT_1CFA
	setup channel=0x38, address=LABEL_23C9
	setup channel=0x39, address=KILL_CHANNEL_LANDING
	mov [0xED], 0x0001

DELAY_LOOP_VARED_AT_1D0B:
	break
	djnz [0xED], DELAY_LOOP_VARED_AT_1D0B
	setup channel=0x14, address=LABEL_25A7
	setup channel=0x36, address=LABEL_2393
	break
	break
	deleteChannels first=0x34, last=0x3B
	setup channel=0x34, address=LABEL_22C7
	setup channel=0x35, address=LABEL_2238
	setup channel=0x36, address=LABEL_22A4
	setup channel=0x37, address=LABEL_2274
	deleteChannels first=0x03, last=0x04
	setup channel=0x2D, address=HANG_DRAW_CIN_393
	mov [0xED], 0x000F

DELAY_LOOP_VARED_AT_1D3A:
	break
	djnz [0xED], DELAY_LOOP_VARED_AT_1D3A
	mov [0xE8], 0x0022
	setup channel=0x02, address=LABEL_1DC1
	mov [0xED], 0x000A

DELAY_LOOP_VARED_AT_1D4B:
	break
	djnz [0xED], DELAY_LOOP_VARED_AT_1D4B
	setup channel=0x03, address=LABEL_1DEB
	setup channel=0x36, address=LABEL_1E24
