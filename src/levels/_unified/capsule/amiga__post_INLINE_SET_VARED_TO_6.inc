DELAY_LOOP_VARED:
	break
	djnz [0xED], DELAY_LOOP_VARED
	setup channel=0x38, address=LABEL_11FD
	mov [0xED], 0x000A

DELAY_LOOP_VARED_AT_0D3B:
	break
	djnz [0xED], DELAY_LOOP_VARED_AT_0D3B
	setup channel=0x35, address=LABEL_126C
	setup channel=0x36, address=LABEL_1233
	mov [0xED], 0x000A

DELAY_LOOP_VARED_AT_0D4C:
	break
	djnz [0xED], DELAY_LOOP_VARED_AT_0D4C
	setup channel=0x38, address=LABEL_1242
	setup channel=0x39, address=KILL_CHANNEL_LANDING
	mov [0xED], 0x0001

DELAY_LOOP_VARED_AT_0D5D:
	break
	djnz [0xED], DELAY_LOOP_VARED_AT_0D5D
	setup channel=0x14, address=LABEL_13B1
	setup channel=0x36, address=LABEL_120C
	break
	break
	deleteChannels first=0x34, last=0x3B
	setup channel=0x34, address=LABEL_1140
	setup channel=0x35, address=LABEL_10B1
	setup channel=0x36, address=LABEL_111D
	setup channel=0x37, address=LABEL_10ED
	deleteChannels first=0x03, last=0x04
	setup channel=0x2D, address=HANG_DRAW_CIN_047
	mov [0xED], 0x000F

DELAY_LOOP_VARED_AT_0D8C:
	break
	djnz [0xED], DELAY_LOOP_VARED_AT_0D8C
	mov [0xE8], 0x0022
	setup channel=0x02, address=LABEL_0E13
	mov [0xED], 0x000A

DELAY_LOOP_VARED_AT_0D9D:
	break
	djnz [0xED], DELAY_LOOP_VARED_AT_0D9D
	setup channel=0x03, address=LABEL_0E3D
	setup channel=0x36, address=LABEL_0E76
