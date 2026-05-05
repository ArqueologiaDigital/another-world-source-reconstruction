LABEL_B25D:
	deleteChannels first=0x34, last=0x37
	setup channel=0x3B, address=KILL_CHANNEL_LANDING
	ret

DELETE_CHANS_0_8_AND_RET:
	deleteChannels first=0x00, last=0x08
	call LABEL_B25D
	ret
	deleteChannels first=0x22, last=0x2E
	deleteChannels first=0x30, last=0x3B
	deleteChannels first=0x00, last=0x08
	ret
	deleteChannels first=0x22, last=0x2E
	call LABEL_B25D
	ret
	deleteChannels first=0x30, last=0x3B
	jmp LABEL_B25D

LABEL_B28A:
	mov [0x23], 0x0001
	jl [HERO_Y], [0x41], LABEL_B298
	mov [0x23], 0x0000

LABEL_B298:
	ret

LABEL_B299:
	je [HACK_VAR_67], 0x8A, SHARED_RET
	je [HACK_VAR_67], 0x8C, SHARED_RET
	je [HACK_VAR_67], 0xAB, SHARED_RET
	je [HACK_VAR_67], 0xC9, SHARED_RET
	je [HACK_VAR_67], 0x6E, SHARED_RET
	je [HACK_VAR_67], 0x6A, SHARED_RET
	mov [HERO_Y], [0x40]
	je [0x23], 0x00, LABEL_B2C9
	mov [HERO_Y], [0x44]

LABEL_B2C9:
	ret

LABEL_B2CA:
	setup channel=0x10, address=LABEL_441E
	setup channel=0x18, address=LABEL_67C2
	setup channel=0x2F, address=LABEL_5C58
	setup channel=0x2E, address=KILL_CHANNEL_LANDING
	setup channel=0x2E, address=LABEL_28F7
	setup channel=0x3B, address=KILL_CHANNEL_LANDING
	setup channel=0x3C, address=LABEL_2E43
	deleteChannels first=0x30, last=0x33
	mov [0x32], 0x0000
	call INIT_RANGE_48_TO_4D_TO_MAX
	call INIT_VARS_AA_AD_5B_5E_PLUS1
	selectVideoPage 0x00
	je [HACK_VAR_67], 0x6A, LABEL_A3A3
	je [HACK_VAR_67], 0x6B, LABEL_A41B
	je [HACK_VAR_67], 0x4A, LABEL_A524
	je [HACK_VAR_67], 0x4B, LABEL_A57D
	je [HACK_VAR_67], 0x4C, LABEL_A5D0
	je [HACK_VAR_67], 0x4D, LABEL_A662
	je [HACK_VAR_67], 0x2A, LABEL_A632
	je [HACK_VAR_67], 0x6C, LABEL_A789
	je [HACK_VAR_67], 0x6D, LABEL_A7EF
	je [HACK_VAR_67], 0x6E, LABEL_A837
	je [HACK_VAR_67], 0x6F, LABEL_A69A
	je [HACK_VAR_67], 0x70, LABEL_A662
	je [HACK_VAR_67], 0x71, LABEL_A706
	je [HACK_VAR_67], 0x72, LABEL_A662
	je [HACK_VAR_67], 0x73, LABEL_A69A
	je [HACK_VAR_67], 0x74, LABEL_A662
	je [HACK_VAR_67], 0x8A, LABEL_AD53
	je [HACK_VAR_67], 0x8B, LABEL_ADB5
	je [HACK_VAR_67], 0x8C, LABEL_AE2C
	je [HACK_VAR_67], 0x8D, LABEL_A886
	je [HACK_VAR_67], 0x8E, LABEL_AE58
	je [HACK_VAR_67], 0x8F, LABEL_A69A
	je [HACK_VAR_67], 0x91, LABEL_A9D6
	je [HACK_VAR_67], 0x92, LABEL_AA22
	je [HACK_VAR_67], 0xA9, LABEL_ABA0
	je [HACK_VAR_67], 0xAA, LABEL_ABE5
	je [HACK_VAR_67], 0xAB, LABEL_AA63
	je [HACK_VAR_67], 0xAD, LABEL_A92A
	je [HACK_VAR_67], 0x64, LABEL_A9C4
	je [HACK_VAR_67], 0xC8, LABEL_AAC1
	je [HACK_VAR_67], 0xC9, LABEL_AB16
	je [HACK_VAR_67], 0xCA, LABEL_AF64
	je [HACK_VAR_67], 0xCB, LABEL_AFB0
	je [HACK_VAR_67], 0xCD, LABEL_A957
	je [HACK_VAR_67], 0xCE, LABEL_AED0
	je [HACK_VAR_67], 0xEA, LABEL_B06C
	je [HACK_VAR_67], 0xEB, LABEL_AFFD
	je [HACK_VAR_67], 0xEC, LABEL_AF10
	je [HACK_VAR_67], 0xED, LABEL_A983
	je [HACK_VAR_67], 0xEE, LABEL_AE90
	je [HACK_VAR_67], 0xEF, LABEL_A69A

VAR66_MOD_32_DRAW_DISPATCH:
	selectVideoPage 0xFF
	call LABEL_B28A
	je [0x66], [HACK_VAR_67], COPY_HACK67_TO_VAR66
	mov [0xF8], [0x66]
	and [0xF8], 0x001F
	jne [0xF8], 0x05, COPY_PAGE0_TO_PAGE_FF
