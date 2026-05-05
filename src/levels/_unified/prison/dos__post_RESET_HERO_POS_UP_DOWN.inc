LABEL_7CA9:
	call LABEL_7C6A
	call LABEL_7D6B
	jl [0x18], 0x32, LABEL_7CB9
	sub [0x18], 0x0032

LABEL_7CB9:
	jg [0x18], 0xFFCE, LABEL_7CC4
	add [0x18], 0x0032

LABEL_7CC4:
	jne [HERO_POS_UP_DOWN], 0x00, LABEL_7D02
	jne [0x14], 0x28A0, LABEL_7CD8
	mov [HACK_VAR_67], 0x0065
	jmp LABEL_8032

LABEL_7CD8:
	jne [0x14], 0x2710, LABEL_7CE6
	mov [HACK_VAR_67], 0x0005
	jmp LABEL_8032

LABEL_7CE6:
	jne [0x14], 0x23F0, LABEL_7CF4
	mov [HACK_VAR_67], 0x0025
	jmp LABEL_8032

LABEL_7CF4:
	jne [0x14], 0x2260, LABEL_7D02
	mov [HACK_VAR_67], 0x0045
	jmp LABEL_8032

LABEL_7D02:
	break
	jmp LABEL_7C8B
LABEL_7D06:
	db 0x11

LABEL_7D07:
	jge [0x68], 0x91, LABEL_7D30
	jle [0x68], 0x73, LABEL_7D17
	mov [0x68], 0x0073

LABEL_7D17:
	mov [BUDDY_X], [0x68]
	mov [BUDDY_Y], [0x69]
	mov [0x0E], 0x0000
	mov [0x0D], 0x0000
	mov [0x10], [HACK_VAR_67]
	mov [0x09], 0x0000
	call GUARDED_HERO_ANIM_CV_128
	ret

LABEL_7D30:
	je [0x11], 0x01, SHARED_RET
	jne [HACK_VAR_67], 0x65, LABEL_7D4F
	jl [0x68], 0xB8, LABEL_7D17
	jg [0x68], 0xD4, LABEL_7D17
	mov [0x68], 0x00D5
	jmp LABEL_7D17

LABEL_7D4F:
	mov [0x68], 0x0064
	jmp LABEL_7D17

LABEL_7D56:
	je [0x6A], 0x05, LABEL_7D07
	ret

LABEL_7D5D:
	je [0x6A], 0x25, LABEL_7D07
	ret

LABEL_7D64:
	je [0x6A], 0x45, LABEL_7D07
	ret

LABEL_7D6B:
	jne [0x14], 0x2320, LABEL_7D81
	setup channel=0x01, address=LABEL_7DF0
	je [0x63], 0xFFFF, LABEL_7D81
	setup channel=0x01, address=LABEL_7DFC

LABEL_7D81:
	jne [0x14], 0x2580, LABEL_7D97
	setup channel=0x01, address=LABEL_7DDD
	je [0x63], 0xFFFF, LABEL_7D97
	setup channel=0x01, address=LABEL_7DF0

LABEL_7D97:
	jne [0x14], 0x27D0, LABEL_7DAE
	setup channel=0x01, address=DRAW_CIN_090_TO_104_3F_AT_8C208B32
	je [0x63], 0xFFFF, LABEL_7DAE
	setup channel=0x01, address=LABEL_7DE9
	ret

LABEL_7DAE:
	jne [0x14], 0x27C0, SHARED_RET
	je [0x63], 0xFFFF, SHARED_RET
	setup channel=0x01, address=LABEL_7DE9
	ret
LABEL_7DC1:
	db 0x11
