LABEL_64E8:
	db 0x11

LABEL_64E9:
	jl [0x1D], 0x0A, LABEL_65A0
	jl [0x1D], 0x14, LABEL_6509
	jl [0x1D], 0x1E, LABEL_663D
	je [0x1D], 0x1E, LABEL_665B
	jge [0x1D], 0x28, LABEL_66A4
	ret
LABEL_6508:
	db 0x11

LABEL_6509:
	jne [HACK_VAR_67], 0xCC, LABEL_6548
	jne [0x1D], 0x0A, LABEL_6522
	setup channel=0x28, address=INLINE_SET_VAR74_TO_6
	or [0x49], 0x4000
	and [0x49], 0xFFF8
	ret

LABEL_6522:
	jne [0x1D], 0x0B, LABEL_6535
	setup channel=0x2A, address=INLINE_SET_VAR75_TO_6
	or [0x4B], 0x4000
	and [0x4B], 0xFFF8
	ret

LABEL_6535:
	jne [0x1D], 0x0C, SHARED_RET
	setup channel=0x2C, address=INLINE_SET_VAR76_TO_6
	or [0x4D], 0x4000
	and [0x4D], 0xFFF8
	ret

LABEL_6548:
	jne [HACK_VAR_67], 0xCA, LABEL_6561
	jne [0x1D], 0x0A, SHARED_RET
	setup channel=0x22, address=INLINE_SET_VAR73_TO_6
	or [0x49], 0x4000
	and [0x49], 0xFFF8
	ret

LABEL_6561:
	jne [HACK_VAR_67], 0xCB, SHARED_RET
	jne [0x1D], 0x0A, LABEL_657A
	setup channel=0x28, address=INLINE_SET_VAR74_TO_6
	or [0x49], 0x4000
	and [0x49], 0xFFF8
	ret

LABEL_657A:
	jne [0x1D], 0x0B, LABEL_658D
	setup channel=0x2A, address=INLINE_SET_VAR75_TO_6
	or [0x4B], 0x4000
	and [0x4B], 0xFFF8
	ret

LABEL_658D:
	jne [0x1D], 0x0C, SHARED_RET
	setup channel=0x2C, address=INLINE_SET_VAR76_TO_6
	or [0x4D], 0x4000
	and [0x4D], 0xFFF8
	ret

LABEL_65A0:
	jne [HACK_VAR_67], 0x6B, LABEL_65CB
	play id=0x005B, freq=0x14, vol=0x30, channel=0x01
	jne [0x1D], 0x04, SHARED_RET
	or [0xB1], 0x0001
	setup channel=0x35, address=DRAW_CIN_424_426_VERTICAL
	setup channel=0x34, address=LABEL_CB57
	selectVideoPage 0x00
	video offset=CINEMATIC_400, x=162, y=70
	selectVideoPage 0xFF
	mov [0x47], 0x0FA0
	ret

LABEL_65CB:
	jne [HACK_VAR_67], 0xED, LABEL_65FD
	mov [0xF8], [0xB1]
	and [0xF8], 0x0004
	jne [0xF8], 0x00, SHARED_RET
	mov [0x47], [0x43]
	or [0xB1], 0x0004
	setup channel=0x02, address=KILL_CHANNEL_LANDING
	setup channel=0x3C, address=LABEL_3E21
	selectVideoPage 0x00
	video offset=CINEMATIC_839, x=287, y=50, zoom=0x40
	selectVideoPage 0xFF
	play id=0x0057, freq=0x1C, vol=0x40, channel=0x00
	ret

LABEL_65FD:
	jne [HACK_VAR_67], 0x50, SHARED_RET
	jne [0x1D], 0x04, SHARED_RET
	jl [0x21], 0x64, SHARED_RET
	mov [0xF8], [0xB1]
	and [0xF8], 0x0002
	jne [0xF8], 0x00, LABEL_6624
	setup channel=0x04, address=INIT_VARS_EB_47
	or [0xB1], 0x0002

LABEL_6624:
	jne [0xE6], 0x00, SHARED_RET
	jne [0xE6], 0x00, SHARED_RET
	setup channel=0x07, address=KILL_CHANNEL_LANDING
	setup channel=0x05, address=LABEL_C90A
	or [0xB2], 0x0002
	ret

LABEL_663D:
	call LABEL_6CA0
	sub [0x11], 0x0004
	call LABEL_6CEF
	je [0x29], 0x01, PLAY_SFX_005C_CH00
	play id=0x005C, freq=0x19, vol=0x40, channel=0x01
	ret
