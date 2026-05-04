LABEL_DC7B:
	jne [HACK_VAR_67], 0xAF, LABEL_DC8A
	mov [HACK_VAR_67], 0x00CE
	mov [0x02], 0x0078
	ret

LABEL_DC8A:
	jne [HACK_VAR_67], 0xC8, LABEL_DCB8
	mov [HACK_VAR_67], 0x00A7
	jg [0x02], 0x50, SHARED_RET
	call LABEL_2782
	call SET_VAR04_TO_0024
	setup channel=0x15, address=KILL_CHANNEL_LANDING
	mov [0x63], 0x0064
	mov [0x34], 0x0000
	mov [0x02], 0x0014
	mov [0x01], 0x0140
	call LABEL_79C2
	ret

LABEL_DCB8:
	jne [HACK_VAR_67], 0x68, DECR_HACK67_BY_1
	jl [0x02], 0x96, DECR_HACK67_BY_1
	mov [HACK_VAR_67], 0x0087
	mov [0x02], 0x0028
	ret
