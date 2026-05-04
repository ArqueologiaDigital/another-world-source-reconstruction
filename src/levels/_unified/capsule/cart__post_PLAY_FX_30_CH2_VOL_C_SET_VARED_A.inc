DELAY_LOOP_VARED_AT_09DF:
	break
	djnz [0xED], DELAY_LOOP_VARED_AT_09DF
	play id=0x0075, freq=0x0E, vol=0x0C, channel=0x02
	mov [0xED], 0x000A

DELAY_LOOP_VARED_AT_09EE:
	break
	djnz [0xED], DELAY_LOOP_VARED_AT_09EE
	play id=0x0030, freq=0x07, vol=0x0C, channel=0x02
	mov [0xED], 0x000A

DELAY_LOOP_VARED_AT_09FD:
	break
	djnz [0xED], DELAY_LOOP_VARED_AT_09FD
	play id=0x0030, freq=0x02, vol=0x0C, channel=0x02
	mov [0xED], 0x000A

DELAY_LOOP_VARED_AT_0A0C:
	break
	djnz [0xED], DELAY_LOOP_VARED_AT_0A0C
	play id=0x0075, freq=0x0A, vol=0x0C, channel=0x02
	mov [0xED], 0x000A

DELAY_LOOP_VARED_AT_0A1B:
	break
	djnz [0xED], DELAY_LOOP_VARED_AT_0A1B
	jmp PLAY_FX_30_CH2_VOL_C_SET_VARED_A
LABEL_0A23:
	db 0x11
