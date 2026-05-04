DELAY_LOOP_VARED_AT_1DF0:
	break
	djnz [0xED], DELAY_LOOP_VARED_AT_1DF0
	setup channel=0x38, address=LABEL_24D8
	mov [0xED], 0x000A

DELAY_LOOP_VARED_AT_1DFD:
	break
	djnz [0xED], DELAY_LOOP_VARED_AT_1DFD
	setup channel=0x35, address=LABEL_2547
	setup channel=0x36, address=LABEL_250E
	mov [0xED], 0x000A

DELAY_LOOP_VARED_AT_1E0E:
	break
	djnz [0xED], DELAY_LOOP_VARED_AT_1E0E
	setup channel=0x38, address=LABEL_251D
	setup channel=0x39, address=KILL_CHANNEL_LANDING
	mov [0xED], 0x0001

DELAY_LOOP_VARED_AT_1E1F:
	break
	djnz [0xED], DELAY_LOOP_VARED_AT_1E1F
	setup channel=0x14, address=LABEL_2718
	setup channel=0x36, address=LABEL_24E7
	break
	break
	deleteChannels first=0x34, last=0x3B
	setup channel=0x34, address=LABEL_23FB
	setup channel=0x35, address=LABEL_234C
	setup channel=0x36, address=LABEL_23CE
	setup channel=0x37, address=LABEL_2393
	deleteChannels first=0x03, last=0x04
	setup channel=0x2D, address=HANG_DRAW_CIN_396
	mov [0xED], 0x000F

DELAY_LOOP_VARED_AT_1E4E:
	break
	djnz [0xED], DELAY_LOOP_VARED_AT_1E4E
	mov [0xE8], 0x0022
	setup channel=0x02, address=LABEL_1ED5
	mov [0xED], 0x000A

DELAY_LOOP_VARED_AT_1E5F:
	break
	djnz [0xED], DELAY_LOOP_VARED_AT_1E5F
	setup channel=0x03, address=LABEL_1EFF
	setup channel=0x36, address=LABEL_1F38
