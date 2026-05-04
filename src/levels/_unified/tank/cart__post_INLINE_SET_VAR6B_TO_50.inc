DELAY_LOOP_VAR6B:
	break
	djnz [0x6B], DELAY_LOOP_VAR6B
	mov [0x6A], 0x0040
	mov [0x6C], 0x008F
	mov [0x6F], 0x00A0
	jne [0x6E], 0x01, LABEL_0569
	mov [0x6F], 0x0078

LABEL_0569:
	setup channel=0x34, address=LABEL_04F8
	mov [0x6B], 0x000A

LABEL_0571:
	break
	jg [0x6B], 0x03, LABEL_057E
	je [0x70], 0x01, INCR_VAR_6C_BY_10_3X

LABEL_057E:
	sub [0x6A], 0x0003
	djnz [0x6B], LABEL_0571
	mov [0x6B], 0x000A

LABEL_058A:
	break
	je [0x70], 0x01, LABEL_05EA
	sub [0x6A], 0x0002
	djnz [0x6B], LABEL_058A
	mov [0x6B], 0x000A

LABEL_059D:
	break
	sub [0x6A], 0x0001
	jne [0x6E], 0x02, LABEL_05AE
	je [0x6B], 0x05, LABEL_05D7

LABEL_05AE:
	djnz [0x6B], LABEL_059D
	setup channel=0x34, address=LABEL_064D
	jne [0x6E], 0x01, LABEL_05C0
	setup channel=0x34, address=LABEL_0638

LABEL_05C0:
	setup channel=0x3C, address=PALETTE_FLASH_1F_TO_01
	mov [0x6B], 0x0002
	add [0x6E], 0x0001
	jl [0x6E], 0x03, DELAY_LOOP_VAR6B
	setup channel=0x34, address=RESET_PAGES_AND_SETUP_CH_0A
	killChannel

LABEL_05D7:
	setup channel=0x34, address=LABEL_05F6
	killChannel
