LABEL_B33E:
	deleteChannels first=0x34, last=0x37
	setup channel=0x3B, address=KILL_CHANNEL_LANDING
	ret

DELETE_CHANS_0_8_AND_RET:
	deleteChannels first=0x00, last=0x08
	call LABEL_B33E
	ret
	deleteChannels first=0x22, last=0x2E
	deleteChannels first=0x30, last=0x3B
	deleteChannels first=0x00, last=0x08
	ret
	deleteChannels first=0x22, last=0x2E
	call LABEL_B33E
	ret
	deleteChannels first=0x30, last=0x3B
	jmp LABEL_B33E

LABEL_B36B:
	mov [0x23], 0x0001
	jl [HERO_Y], [0x41], LABEL_B379
	mov [0x23], 0x0000

LABEL_B379:
	ret

LABEL_B37A:
	je [HACK_VAR_67], 0x8A, SHARED_RET
	je [HACK_VAR_67], 0x8C, SHARED_RET
	je [HACK_VAR_67], 0xAB, SHARED_RET
	je [HACK_VAR_67], 0xC9, SHARED_RET
	je [HACK_VAR_67], 0x6E, SHARED_RET
	je [HACK_VAR_67], 0x6A, SHARED_RET
	mov [HERO_Y], [0x40]
	je [0x23], 0x00, LABEL_B3AA
	mov [HERO_Y], [0x44]

LABEL_B3AA:
	ret

LABEL_B3AB:
	setup channel=0x10, address=LABEL_43FA
	setup channel=0x18, address=LABEL_67CB
	setup channel=0x2F, address=LABEL_5C5B
	setup channel=0x2E, address=KILL_CHANNEL_LANDING
	setup channel=0x2E, address=LABEL_2A6E
	setup channel=0x3B, address=KILL_CHANNEL_LANDING
	setup channel=0x3C, address=LABEL_2FC0
	deleteChannels first=0x30, last=0x33
	mov [0x32], 0x0000
	call INIT_RANGE_48_TO_4D_TO_MAX
	call INIT_VARS_AA_AD_5B_5E_PLUS1
	selectVideoPage 0x00
	je [HACK_VAR_67], 0x6A, LABEL_A3E7
	je [HACK_VAR_67], 0x6B, LABEL_A465
	je [HACK_VAR_67], 0x4A, LABEL_A588
	je [HACK_VAR_67], 0x4B, LABEL_A5E1
	je [HACK_VAR_67], 0x4C, LABEL_A634
	je [HACK_VAR_67], 0x4D, LABEL_A6B2
	je [HACK_VAR_67], 0x2A, LABEL_A6B2
	je [HACK_VAR_67], 0x6C, LABEL_A7DD
	je [HACK_VAR_67], 0x6D, LABEL_A851
	je [HACK_VAR_67], 0x6E, LABEL_A899
	je [HACK_VAR_67], 0x6F, LABEL_A6EE
	je [HACK_VAR_67], 0x70, LABEL_A6B2
	je [HACK_VAR_67], 0x71, LABEL_A75A
	je [HACK_VAR_67], 0x72, LABEL_A6B2
	je [HACK_VAR_67], 0x73, LABEL_A6EE
	je [HACK_VAR_67], 0x74, LABEL_A6B2
	je [HACK_VAR_67], 0x8A, LABEL_ADD3
	je [HACK_VAR_67], 0x8B, LABEL_AE41
	je [HACK_VAR_67], 0x8C, LABEL_AEB8
	je [HACK_VAR_67], 0x8D, LABEL_A8E8
	je [HACK_VAR_67], 0x8E, LABEL_AEE4
	je [HACK_VAR_67], 0x8F, LABEL_A6EE
	je [HACK_VAR_67], 0x91, LABEL_AA38
	je [HACK_VAR_67], 0x92, LABEL_AA84
	je [HACK_VAR_67], 0xA9, LABEL_AC08
	je [HACK_VAR_67], 0xAA, LABEL_AC4D
	je [HACK_VAR_67], 0xAB, LABEL_AAC5
	je [HACK_VAR_67], 0xAD, LABEL_A98C
	je [HACK_VAR_67], 0x64, LABEL_AA26
	je [HACK_VAR_67], 0xC8, LABEL_AB23
	je [HACK_VAR_67], 0xC9, LABEL_AB78
	je [HACK_VAR_67], 0xCA, LABEL_B042
	je [HACK_VAR_67], 0xCB, LABEL_B08E
	je [HACK_VAR_67], 0xCD, LABEL_A9B9
	je [HACK_VAR_67], 0xCE, LABEL_AFAE
	je [HACK_VAR_67], 0xEA, LABEL_B14D
	je [HACK_VAR_67], 0xEB, LABEL_B0DB
	je [HACK_VAR_67], 0xEC, LABEL_AFEE
	je [HACK_VAR_67], 0xED, LABEL_A9E5
	je [HACK_VAR_67], 0xEE, LABEL_AF4F
	je [HACK_VAR_67], 0xEF, LABEL_A6EE

VAR66_MOD_32_DRAW_DISPATCH:
	selectVideoPage 0xFF
	call LABEL_B36B
	je [0x66], [HACK_VAR_67], COPY_HACK67_TO_VAR66
	mov [0xF8], [0x66]
	and [0xF8], 0x001F
	jne [0xF8], 0x05, COPY_PAGE0_TO_PAGE_FF
