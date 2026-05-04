DELAY_LOOP_VAR14:
	break
	djnz [0x14], DELAY_LOOP_VAR14
	mov [0x14], 0x0005

LABEL_4C75:
	break
	add [0x15], 0x0002
	djnz [0x14], LABEL_4C75
	break
	mov [0x14], 0x000A

LABEL_4C83:
	break
	sub [0x15], 0x0001
	djnz [0x14], LABEL_4C83
	mov [0x14], 0x0008

DELAY_LOOP_VAR14_AT_4C90:
	break
	djnz [0x14], DELAY_LOOP_VAR14_AT_4C90
	mov [0x14], 0x0004

LABEL_4C99:
	break
	add [0x15], 0x0004
	djnz [0x14], LABEL_4C99
	mov [0x14], 0x0004

LABEL_4CA6:
	break
	add [0x15], 0x0002
	djnz [0x14], LABEL_4CA6
	mov [0x14], 0x000E

LABEL_4CB3:
	break
	sub [0x15], 0x0001
	djnz [0x14], LABEL_4CB3
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

LABEL_4CDD:
	break
	add [0x15], 0x0002
	djnz [0x14], LABEL_4CDD
	mov [0x14], 0x0006

DELAY_LOOP_VAR14_AT_4CEA:
	break
	djnz [0x14], DELAY_LOOP_VAR14_AT_4CEA
	deleteChannels first=0x01, last=0x03
	setup channel=0x01, address=SET_PAL_07_FILL_TWO_PAGES_86243111
	setup channel=0x02, address=LABEL_4F23
	killChannel
