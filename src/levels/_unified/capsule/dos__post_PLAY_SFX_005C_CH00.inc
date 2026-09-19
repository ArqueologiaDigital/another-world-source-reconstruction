LABEL_5F5A:
	or [0x04], 0x4000
	deleteChannels first=0x14, last=0x16
	setup channel=0x3F, address=BREAK_5X_THEN_INIT_VAR03_14
	mov [0x13], 0xFFFF
	mov [0xF8], [0x04]
	and [0xF8], 0x00FF
	play id=0x005D, freq=0x14, vol=0x40, channel=0x01
	jl [0xF8], 0x20, LABEL_5F90
	sub [0xF8], 0x0020
	setup channel=0x14, address=LABEL_40CD
	jl [0xF8], 0x10, SHARED_RET
	setup channel=0x14, address=LABEL_40E8
	ret


LABEL_5F90:
	setup channel=0x14, address=LABEL_4002
	jl [0xF8], 0x10, SHARED_RET
	setup channel=0x14, address=LABEL_4029
	ret


LABEL_5F9F:
	call CAPSULE_ACTOR_SLOT_STATE_LOAD_CASE_28
	mov [0xF8], [0x2B]
	and [0xF8], 0x0800
	play id=0x005D, freq=0x14, vol=0x40, channel=0x00
	jne [0xF8], 0x00, CAPSULE_ACTOR_HIT_REPEAT_MARK_DONE
	call LABEL_2863
	mov [0xF8], [0x2B]
	and [0xF8], 0x1000
	jne [0x1D], 0x28, LABEL_5FD3
	setup channel=0x23, address=LABEL_41EB
	je [0xF8], 0x00, CAPSULE_ACTOR_HIT_FIRST_MARK_DONE
	setup channel=0x23, address=LABEL_4244

LABEL_5FD3:
	jne [0x1D], 0x29, LABEL_5FE7
	setup channel=0x25, address=LABEL_41EB
	je [0xF8], 0x00, CAPSULE_ACTOR_HIT_FIRST_MARK_DONE
	setup channel=0x25, address=LABEL_4244

LABEL_5FE7:
	jne [0x1D], 0x2A, CAPSULE_ACTOR_HIT_FIRST_MARK_DONE
	setup channel=0x27, address=LABEL_41EB
	je [0xF8], 0x00, CAPSULE_ACTOR_HIT_FIRST_MARK_DONE
	setup channel=0x27, address=LABEL_4244

CAPSULE_ACTOR_HIT_FIRST_MARK_DONE:
	or [0x2B], 0x0800
	call CAPSULE_ACTOR_SLOT_STATE_STORE_CASE_28
	mov [0x13], 0xFFFF
	ret


CAPSULE_ACTOR_HIT_REPEAT_MARK_DONE:
	or [0x2B], 0x4000
	call CAPSULE_ACTOR_SLOT_STATE_STORE_CASE_28
	mov [0x13], 0xFFFF
	ret


CAPSULE_ACTOR_SLOT_STATE_LOAD_CASE_28:
	jne [0x1D], 0x28, CAPSULE_ACTOR_SLOT_STATE_LOAD_CASE_29
	mov [0x2B], [0x6B]
	ret


CAPSULE_ACTOR_SLOT_STATE_LOAD_CASE_29:
	jne [0x1D], 0x29, LABEL_6027
	mov [0x2B], [0x73]
	ret


LABEL_6027:
	jne [0x1D], 0x2A, LABEL_6030
	mov [0x2B], [0x7B]

LABEL_6030:
	ret


LABEL_6031:
	db 0x11

CAPSULE_ACTOR_SLOT_STATE_STORE_CASE_28:
	jne [0x1D], 0x28, CAPSULE_ACTOR_SLOT_STATE_STORE_CASE_29
	mov [0x6B], [0x2B]
	ret


CAPSULE_ACTOR_SLOT_STATE_STORE_CASE_29:
	jne [0x1D], 0x29, LABEL_6046
	mov [0x73], [0x2B]
	ret


LABEL_6046:
	jne [0x1D], 0x2A, RET_THEN_KILL_CHANNEL
	mov [0x7B], [0x2B]
