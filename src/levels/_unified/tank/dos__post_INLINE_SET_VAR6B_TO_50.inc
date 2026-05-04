DELAY_LOOP_VAR6B:
	break
	djnz [0x6B], DELAY_LOOP_VAR6B
	mov [0x6A], 0x0040
	mov [0x6C], 0x008F
	mov [0x6F], 0x00A0
	jne [0x6E], 0x01, LABEL_0591
	mov [0x6F], 0x0078

LABEL_0591:
	setup channel=0x34, address=LABEL_0520
	mov [0x6B], 0x000A

LABEL_0599:
	break
	jg [0x6B], 0x03, LABEL_05A6
	je [0x70], 0x01, INCR_VAR_6C_BY_10_3X

LABEL_05A6:
	sub [0x6A], 0x0003
	djnz [0x6B], LABEL_0599
	mov [0x6B], 0x000A

LABEL_05B2:
	break
	je [0x70], 0x01, LABEL_0612
	sub [0x6A], 0x0002
	djnz [0x6B], LABEL_05B2
	mov [0x6B], 0x000A

LABEL_05C5:
	break
	sub [0x6A], 0x0001
	jne [0x6E], 0x02, LABEL_05D6
	je [0x6B], 0x05, LABEL_05FF

LABEL_05D6:
	djnz [0x6B], LABEL_05C5
	setup channel=0x34, address=LABEL_0675
	jne [0x6E], 0x01, LABEL_05E8
	setup channel=0x34, address=LABEL_0660

LABEL_05E8:
	setup channel=0x3C, address=PALETTE_FLASH_1F_TO_01
	mov [0x6B], 0x0002
	add [0x6E], 0x0001
	jl [0x6E], 0x03, DELAY_LOOP_VAR6B
	setup channel=0x34, address=RESET_PAGES_AND_SETUP_CH_0A
	killChannel

LABEL_05FF:
	setup channel=0x34, address=LABEL_061E
	killChannel
