LABEL_469E:
	db 0x11

LABEL_469F:
	jl [0x1D], 0x0A, LABEL_4756
	jl [0x1D], 0x14, LABEL_46BF
	jl [0x1D], 0x1E, LABEL_47D2
	je [0x1D], 0x1E, LABEL_47F0
	jge [0x1D], 0x28, LABEL_4835
	ret
LABEL_46BE:
	db 0x11

LABEL_46BF:
	jne [HACK_VAR_67], 0xCC, LABEL_46FE
	jne [0x1D], 0x0A, LABEL_46D8
	setup channel=0x28, address=LABEL_1FD3
	or [0x49], 0x4000
	and [0x49], 0xFFF8
	ret

LABEL_46D8:
	jne [0x1D], 0x0B, LABEL_46EB
	setup channel=0x2A, address=LABEL_1FD3
	or [0x4B], 0x4000
	and [0x4B], 0xFFF8
	ret

LABEL_46EB:
	jne [0x1D], 0x0C, SHARED_RET
	setup channel=0x2C, address=LABEL_1FD3
	or [0x4D], 0x4000
	and [0x4D], 0xFFF8
	ret

LABEL_46FE:
	jne [HACK_VAR_67], 0xCA, LABEL_4717
	jne [0x1D], 0x0A, SHARED_RET
	setup channel=0x22, address=LABEL_1FD3
	or [0x49], 0x4000
	and [0x49], 0xFFF8
	ret

LABEL_4717:
	jne [HACK_VAR_67], 0xCB, SHARED_RET
	jne [0x1D], 0x0A, LABEL_4730
	setup channel=0x28, address=LABEL_1FD3
	or [0x49], 0x4000
	and [0x49], 0xFFF8
	ret

LABEL_4730:
	jne [0x1D], 0x0B, LABEL_4743
	setup channel=0x2A, address=LABEL_1FD3
	or [0x4B], 0x4000
	and [0x4B], 0xFFF8
	ret

LABEL_4743:
	jne [0x1D], 0x0C, SHARED_RET
	setup channel=0x2C, address=LABEL_1FD3
	or [0x4D], 0x4000
	and [0x4D], 0xFFF8
	ret

LABEL_4756:
	jne [HACK_VAR_67], 0x6B, LABEL_477B
	jne [0x1D], 0x04, SHARED_RET
	or [0xB1], 0x0001
	setup channel=0x35, address=LABEL_83FA
	setup channel=0x34, address=LABEL_83FA
	selectVideoPage 0x00
	video offset=CINEMATIC_530, x=162, y=70
	selectVideoPage 0xFF
	mov [0x47], 0x0FA0
	ret

LABEL_477B:
	jne [HACK_VAR_67], 0xED, LABEL_4792
	mov [0x47], 0x0FA0
	or [0xB1], 0x0004
	setup channel=0x02, address=KILL_CHANNEL_LANDING
	setup channel=0x3C, address=LABEL_22A4
	ret

LABEL_4792:
	jne [HACK_VAR_67], 0x50, SHARED_RET
	jne [0x1D], 0x04, SHARED_RET
	jl [0x21], 0x64, SHARED_RET
	mov [0xF8], [0xB1]
	and [0xF8], 0x0002
	jne [0xF8], 0x00, LABEL_47B9
	setup channel=0x04, address=LABEL_81EF
	or [0xB1], 0x0002

LABEL_47B9:
	jne [0xE6], 0x00, SHARED_RET
	jne [0xE6], 0x00, SHARED_RET
	setup channel=0x07, address=KILL_CHANNEL_LANDING
	setup channel=0x05, address=LABEL_8353
	or [0xB2], 0x0002
	ret

LABEL_47D2:
	call LABEL_4E31
	sub [0x11], 0x0004
	call LABEL_4E80
	je [0x29], 0x01, PLAY_SFX_005C_CH00
	play id=0x005C, freq=0x19, vol=0x40, channel=0x01
	ret
