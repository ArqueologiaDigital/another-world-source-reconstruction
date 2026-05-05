LABEL_84DF:
	deleteChannels first=0x34, last=0x37
	setup channel=0x3B, address=KILL_CHANNEL_LANDING
	ret

LABEL_84E8:
	deleteChannels first=0x00, last=0x08
	call LABEL_84DF
	ret
LABEL_84F0:
	db 0x0C, 0x22, 0x2E, 0x02, 0x0C, 0x30, 0x3B, 0x02
	db 0x0C, 0x00, 0x08, 0x02, 0x05, 0x0C, 0x22, 0x2E
	db 0x02, 0x04, 0x84, 0xDF, 0x05

LABEL_8505:
	mov [0x23], 0x0001
	jl [HERO_Y], [0x41], LABEL_8513
	mov [0x23], 0x0000

LABEL_8513:
	ret

LABEL_8514:
	mov [HERO_Y], [0x40]
	je [0x23], 0x00, LABEL_8520
	mov [HERO_Y], [0x44]

LABEL_8520:
	ret

LABEL_8521:
	setup channel=0x10, address=LABEL_2E58
	setup channel=0x18, address=LABEL_5054
	setup channel=0x2F, address=LABEL_44FB
	setup channel=0x2E, address=KILL_CHANNEL_LANDING
	setup channel=0x2E, address=LABEL_17D8
	setup channel=0x3B, address=KILL_CHANNEL_LANDING
	setup channel=0x3C, address=LABEL_21C5
	deleteChannels first=0x30, last=0x33
	mov [0x32], 0x0000
	call INIT_RANGE_48_TO_4D_TO_MAX
	call INIT_VARS_AA_AD_5B_5E_PLUS1
	selectVideoPage 0x00
	je [HACK_VAR_67], 0x4A, LABEL_7F7E
	je [HACK_VAR_67], 0x4B, LABEL_7FD7
	je [HACK_VAR_67], 0x4C, LABEL_802A
	je [HACK_VAR_67], 0x4D, LABEL_805B
	je [HACK_VAR_67], 0x91, LABEL_80A6
	je [HACK_VAR_67], 0x92, LABEL_80F2
	je [HACK_VAR_67], 0x64, LABEL_8094

VAR66_MOD_32_DRAW_DISPATCH:
	selectVideoPage 0xFF
	call LABEL_8505
	je [0x66], [HACK_VAR_67], COPY_HACK67_TO_VAR66
	mov [0xF8], [0x66]
	and [0xF8], 0x001F
	jne [0xF8], 0x05, COPY_PAGE0_TO_PAGE_FF
