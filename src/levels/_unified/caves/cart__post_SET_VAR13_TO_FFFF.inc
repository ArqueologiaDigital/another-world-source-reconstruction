LABEL_6732:
	db 0x11

LABEL_6733:
	jl [0x1D], 0x0A, LABEL_67EA
	jl [0x1D], 0x14, LABEL_6753
	jl [0x1D], 0x1E, LABEL_687E
	je [0x1D], 0x1E, LABEL_689C
	jge [0x1D], 0x28, LABEL_68EB
	ret
LABEL_6752:
	db 0x11

LABEL_6753:
	jne [HACK_VAR_67], 0xCC, LABEL_6792
	jne [0x1D], 0x0A, LABEL_676C
	setup channel=0x28, address=INLINE_SET_VAR74_TO_6
	or [0x49], 0x4000
	and [0x49], 0xFFF8
	ret

LABEL_676C:
	jne [0x1D], 0x0B, LABEL_677F
	setup channel=0x2A, address=INLINE_SET_VAR75_TO_6
	or [0x4B], 0x4000
	and [0x4B], 0xFFF8
	ret

LABEL_677F:
	jne [0x1D], 0x0C, SHARED_RET
	setup channel=0x2C, address=INLINE_SET_VAR76_TO_6
	or [0x4D], 0x4000
	and [0x4D], 0xFFF8
	ret

LABEL_6792:
	jne [HACK_VAR_67], 0xCA, LABEL_67AB
	jne [0x1D], 0x0A, SHARED_RET
	setup channel=0x22, address=INLINE_SET_VAR73_TO_6
	or [0x49], 0x4000
	and [0x49], 0xFFF8
	ret

LABEL_67AB:
	jne [HACK_VAR_67], 0xCB, SHARED_RET
	jne [0x1D], 0x0A, LABEL_67C4
	setup channel=0x28, address=INLINE_SET_VAR74_TO_6
	or [0x49], 0x4000
	and [0x49], 0xFFF8
	ret

LABEL_67C4:
	jne [0x1D], 0x0B, LABEL_67D7
	setup channel=0x2A, address=INLINE_SET_VAR75_TO_6
	or [0x4B], 0x4000
	and [0x4B], 0xFFF8
	ret

LABEL_67D7:
	jne [0x1D], 0x0C, SHARED_RET
	setup channel=0x2C, address=INLINE_SET_VAR76_TO_6
	or [0x4D], 0x4000
	and [0x4D], 0xFFF8
	ret

LABEL_67EA:
	jne [HACK_VAR_67], 0x6B, LABEL_6815
	play id=0x005B, freq=0x14, vol=0x30, channel=0x01
	jne [0x1D], 0x04, SHARED_RET
	or [0xB1], 0x0001
	setup channel=0x35, address=DRAW_CIN_424_426_VERTICAL
	setup channel=0x34, address=LABEL_D026
	selectVideoPage 0x00
	video offset=CINEMATIC_421, x=162, y=70
	selectVideoPage 0xFF
	mov [0x47], 0x0FA0
	ret

LABEL_6815:
	jne [HACK_VAR_67], 0xEE, LABEL_683E
	mov [0xF8], [0xB1]
	and [0xF8], 0x0004
	jne [0xF8], 0x00, SHARED_RET
	mov [0x47], [0x43]
	or [0xB1], 0x0004
	setup channel=0x02, address=KILL_CHANNEL_LANDING
	setup channel=0x3C, address=LABEL_404D
	play id=0x0057, freq=0x1C, vol=0x40, channel=0x00
	ret

LABEL_683E:
	jne [HACK_VAR_67], 0x50, SHARED_RET
	jne [0x1D], 0x04, SHARED_RET
	jl [0x21], 0x64, SHARED_RET
	mov [0xF8], [0xB1]
	and [0xF8], 0x0002
	jne [0xF8], 0x00, SHARED_RET
	setup channel=0x04, address=INIT_VARS_EB_47
	or [0xB1], 0x0002
	jne [0xE6], 0x00, SHARED_RET
	jne [0xE6], 0x00, SHARED_RET
	setup channel=0x07, address=KILL_CHANNEL_LANDING
	setup channel=0x05, address=LABEL_CDA9
	or [0xB2], 0x0002
	ret

LABEL_687E:
	call LABEL_6EE7
	sub [0x11], 0x0004
	call LABEL_6F36
	je [0x29], 0x01, PLAY_SFX_005C_CH00
	play id=0x005C, freq=0x19, vol=0x40, channel=0x01
	ret
