WAIT_RANDOM_DELAY_THEN_LOOP:
	break
	djnz [0x24], WAIT_RANDOM_DELAY_THEN_LOOP
	jmp RANDOM_AMBIENT_SOUND_LOOP
	killChannel

PLAY_RANDOM_AMBIENT_SOUND:
	call COMPUTE_RANDOM_BIT_MASKS
	mov [0xF8], [0x3A]
	jne [0xF8], 0x00, AMBIENT_RND_CASE_1
	ret

AMBIENT_RND_CASE_1:
	jne [0xF8], 0x01, PLAY_AMBIENT_F16
	ret

PLAY_AMBIENT_F16:
	jne [0xF8], 0x02, AMBIENT_RND_CASE_3
	play id=0x0050, freq=0x16, vol=0x20, channel=0x02
	ret

AMBIENT_RND_CASE_3:
	jne [0xF8], 0x03, PLAY_AMBIENT_F05
	ret

PLAY_AMBIENT_F05:
	jne [0xF8], 0x04, AMBIENT_RND_CASE_5
	play id=0x0050, freq=0x05, vol=0x20, channel=0x02
	ret

AMBIENT_RND_CASE_5:
	jne [0xF8], 0x05, PLAY_AMBIENT_F19
	ret

PLAY_AMBIENT_F19:
	jne [0xF8], 0x06, RET_TARGET_1A88
	play id=0x0050, freq=0x19, vol=0x10, channel=0x02
	ret

AMBIENT_LOOP_CH24:
	play id=0x0010, freq=0x01, vol=0x3F, channel=0x03
	mov [0x22], 0x001E

AMBIENT_CH24_DELAY_F0:
	break
	djnz [0x22], AMBIENT_CH24_DELAY_F0
	play id=0x0010, freq=0x01, vol=0x2E, channel=0x03
	break

AMBIENT_CH24_RESTART:
	mov [0x22], 0x003C

AMBIENT_CH24_DELAY_F1:
	break
	djnz [0x22], AMBIENT_CH24_DELAY_F1
	play id=0x0008, freq=0x03, vol=0x1F, channel=0x03
	mov [0x22], 0x001E

AMBIENT_CH24_DELAY_F2:
	break
	djnz [0x22], AMBIENT_CH24_DELAY_F2
	play id=0x0010, freq=0x04, vol=0x14, channel=0x03
	mov [0x22], 0x005A

AMBIENT_CH24_DELAY_F3:
	break
	djnz [0x22], AMBIENT_CH24_DELAY_F3
	play id=0x0010, freq=0x01, vol=0x18, channel=0x03
	jmp AMBIENT_CH24_RESTART
	killChannel

AMBIENT_LOOP_CH25:
	play id=0x0010, freq=0x09, vol=0x20, channel=0x02
	break

AMBIENT_CH25_RESTART:
	mov [0x23], 0x0033

AMBIENT_CH25_DELAY_F0:
	break
	djnz [0x23], AMBIENT_CH25_DELAY_F0
	play id=0x0008, freq=0x03, vol=0x0A, channel=0x02
	mov [0x23], 0x004B

AMBIENT_CH25_DELAY_F1:
	break
	djnz [0x23], AMBIENT_CH25_DELAY_F1
	play id=0x0008, freq=0x00, vol=0x16, channel=0x02
	mov [0x23], 0x001E

AMBIENT_CH25_DELAY_F2:
	break
	djnz [0x23], AMBIENT_CH25_DELAY_F2
	play id=0x0010, freq=0x09, vol=0x0F, channel=0x02
	jmp AMBIENT_CH25_RESTART
	killChannel

