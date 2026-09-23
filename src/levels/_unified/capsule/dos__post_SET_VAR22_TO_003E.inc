CAPSULE_SCREEN_6A_ENTRY:
	mov [0x46], 0x0007
	mov [0x47], 0x0FA0
	mov [0x42], 0x000A
	mov [0x43], 0x0FA0
	mov [0x45], 0x0000
	mov [0x44], 0x001E
	mov [0x41], 0x0028
	mov [0x40], 0x00AC
	setPalette 0x01
	call CAPSULE_SCREEN_6A_BACKDROP_DRAW
	call DELETE_CHANS_0_8_AND_RET
	setup channel=0x1B, address=KILL_CHANNEL_LANDING
	setup channel=0x19, address=KILL_CHANNEL_LANDING
	setup channel=0x37, address=LABEL_1F89
	play id=0x0066, freq=0x07, vol=0x10, channel=0x03
	jl [HERO_Y], 0x64, INLINE_SET_VAR02_TO_97
	mov [HERO_Y], 0x00AC
	jmp LABEL_A3EF
