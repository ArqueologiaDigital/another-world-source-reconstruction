DELAY_LOOP_VARED_AT_0929:
	break
	djnz [0xED], DELAY_LOOP_VARED_AT_0929
	play id=0x0075, freq=0x0E, vol=0x0C, channel=0x02
	mov [0xED], 0x000A

DELAY_LOOP_VARED_AT_0938:
	break
	djnz [0xED], DELAY_LOOP_VARED_AT_0938
	play id=0x0030, freq=0x07, vol=0x0C, channel=0x02
	mov [0xED], 0x000A

DELAY_LOOP_VARED_AT_0947:
	break
	djnz [0xED], DELAY_LOOP_VARED_AT_0947
	play id=0x0030, freq=0x02, vol=0x0C, channel=0x02
	mov [0xED], 0x000A

DELAY_LOOP_VARED_AT_0956:
	break
	djnz [0xED], DELAY_LOOP_VARED_AT_0956
	play id=0x0075, freq=0x0A, vol=0x0C, channel=0x02
	mov [0xED], 0x000A

DELAY_LOOP_VARED_AT_0965:
	break
	djnz [0xED], DELAY_LOOP_VARED_AT_0965
	jmp PLAY_FX_30_CH2_VOL_C_SET_VARED_A
LABEL_096D:
	db 0x11
