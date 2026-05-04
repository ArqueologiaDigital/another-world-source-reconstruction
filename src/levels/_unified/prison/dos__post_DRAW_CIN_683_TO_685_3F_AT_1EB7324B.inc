DELAY_LOOP_VAR14__DOS__POST_DRAW_CIN_683_TO_685_3F_AT_1EB7324B:
	break
	djnz [0x14], DELAY_LOOP_VAR14__DOS__POST_DRAW_CIN_683_TO_685_3F_AT_1EB7324B
	mov [0x14], 0x0005

LABEL_4D1A:
	break
	add [0x15], 0x0002
	djnz [0x14], LABEL_4D1A
	break
	mov [0x14], 0x000A

LABEL_4D28:
	break
	sub [0x15], 0x0001
	djnz [0x14], LABEL_4D28
	mov [0x14], 0x0008

DELAY_LOOP_VAR14_AT_4D35:
	break
	djnz [0x14], DELAY_LOOP_VAR14_AT_4D35
	mov [0x14], 0x0004

LABEL_4D3E:
	break
	add [0x15], 0x0004
	djnz [0x14], LABEL_4D3E
	mov [0x14], 0x0004

LABEL_4D4B:
	break
	add [0x15], 0x0002
	djnz [0x14], LABEL_4D4B
	mov [0x14], 0x000E

LABEL_4D58:
	break
	sub [0x15], 0x0001
	djnz [0x14], LABEL_4D58
	break
	sub [0x15], 0x0002
	break
	sub [0x15], 0x0008
	break
	add [0x16], 0x0001
	break
	add [0x15], 0x0014
	break
	sub [0x16], 0x0001
	mov [0x14], 0x0004
	add [0x15], 0x0002

LABEL_4D82:
	break
	add [0x15], 0x0002
	djnz [0x14], LABEL_4D82
	mov [0x14], 0x0006

DELAY_LOOP_VAR14_AT_4D8F:
	break
	djnz [0x14], DELAY_LOOP_VAR14_AT_4D8F
	setup channel=0x3C, address=BLIT_PAGE_00_TO_FF_AND_BREAK
	deleteChannels first=0x01, last=0x03
	setup channel=0x01, address=SET_PAL_07_FILL_TWO_PAGES_86243111
	setup channel=0x02, address=LABEL_4FCC
	killChannel
