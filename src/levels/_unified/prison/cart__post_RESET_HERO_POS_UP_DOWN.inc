LABEL_7DCE:
	call LABEL_7D8F
	call LABEL_7E97
	jl [0x18], 0x32, LABEL_7DDE
	sub [0x18], 0x0032

LABEL_7DDE:
	jg [0x18], 0xFFCE, LABEL_7DE9
	add [0x18], 0x0032

LABEL_7DE9:
	jne [HERO_POS_UP_DOWN], 0x00, LABEL_7E27
	jne [0x14], 0x28A0, LABEL_7DFD
	mov [HACK_VAR_67], 0x0065
	jmp LABEL_8161

LABEL_7DFD:
	jne [0x14], 0x2710, LABEL_7E0B
	mov [HACK_VAR_67], 0x0005
	jmp LABEL_8161

LABEL_7E0B:
	jne [0x14], 0x23F0, LABEL_7E19
	mov [HACK_VAR_67], 0x0025
	jmp LABEL_8161

LABEL_7E19:
	jne [0x14], 0x2260, LABEL_7E27
	mov [HACK_VAR_67], 0x0045
	jmp LABEL_8161

LABEL_7E27:
	break
	jmp LABEL_7DB0
LABEL_7E2B:
	db 0x11

LABEL_7E2C:
	jge [0x68], 0x91, LABEL_7E55
	jle [0x68], 0x73, LABEL_7E3C
	mov [0x68], 0x0073

LABEL_7E3C:
	mov [BUDDY_X], [0x68]
	mov [BUDDY_Y], [0x69]
	mov [0x0E], 0x0000
	mov [0x0D], 0x0000
	mov [0x10], [HACK_VAR_67]
	mov [0x09], 0x0000
	call GUARDED_HERO_ANIM_CV_128
	ret

LABEL_7E55:
	je [0x11], 0x01, SHARED_RET
	jne [HACK_VAR_67], 0x65, LABEL_7E74
	jl [0x68], 0xB8, LABEL_7E3C
	jg [0x68], 0xD4, LABEL_7E3C
	mov [0x68], 0x00D5
	jmp LABEL_7E3C

LABEL_7E74:
	mov [0x68], 0x0064
	jmp LABEL_7E3C

LABEL_7E7B:
	je [0x6A], 0x05, LABEL_7E2C
	ret

LABEL_7E82:
	je [0x6A], 0x25, LABEL_7E2C
	ret

LABEL_7E89:
	je [0x6A], 0x45, LABEL_7E2C
	ret

LABEL_7E90:
	je [0x6A], 0x65, LABEL_7E2C
	ret

LABEL_7E97:
	jne [0x14], 0x2320, LABEL_7EA2
	setup channel=0x01, address=LABEL_7F1F

LABEL_7EA2:
	jne [0x14], 0x2310, LABEL_7EAD
	setup channel=0x01, address=LABEL_7F2B

LABEL_7EAD:
	jne [0x14], 0x2580, LABEL_7EB8
	setup channel=0x01, address=LABEL_7F0C

LABEL_7EB8:
	jne [0x14], 0x2570, LABEL_7EC3
	setup channel=0x01, address=LABEL_7F1F

LABEL_7EC3:
	jne [0x14], 0x27E0, LABEL_7EDA
	setup channel=0x01, address=LABEL_7EEE
	ret
	je [0x63], 0xFFFF, LABEL_7EDA
	setup channel=0x01, address=LABEL_7F18

LABEL_7EDA:
	jne [0x14], 0x27C0, SHARED_RET
	setup channel=0x01, address=LABEL_7F18
	je [0x63], 0xFFFF, SHARED_RET
	ret
LABEL_7EED:
	db 0x11

LABEL_7EEE:
	break
	copyVideoPage src=0x03, dst=0x00
	break
	selectVideoPage 0x00
	video offset=CINEMATIC_090, x=160, y=100
	video offset=CINEMATIC_091, x=160, y=100
	selectVideoPage 0xFF
	break
	selectVideoPage 0x00
	video offset=CINEMATIC_104, x=200, y=100
	call LABEL_7E90
	selectVideoPage 0xFF
	killChannel

LABEL_7F0C:
	selectVideoPage 0x00
	video offset=CINEMATIC_106, x=160, y=100
	call LABEL_7E7B
	selectVideoPage 0xFF
	killChannel

LABEL_7F18:
	copyVideoPage src=0x03, dst=0x00
	break
	jmp LABEL_7F0C

LABEL_7F1F:
	selectVideoPage 0x00
	video offset=CINEMATIC_106, x=160, y=100
	call LABEL_7E82
	selectVideoPage 0xFF
	killChannel

LABEL_7F2B:
	selectVideoPage 0x00
	video offset=CINEMATIC_106, x=160, y=100
	call LABEL_7E89
	selectVideoPage 0xFF
	killChannel
	selectVideoPage 0x00
	selectVideoPage 0xFF
	killChannel

LABEL_7F3C:
	jl [0x14], 0x2968, LABEL_7F4A
	mov [0x16], 0x0000
	jmp LABEL_7FA2

LABEL_7F4A:
	jl [0x14], 0x27D8, LABEL_7F58
	mov [0x16], 0x0001
	jmp LABEL_7FA2

LABEL_7F58:
	jl [0x14], 0x2648, LABEL_7F66
	mov [0x16], 0x0001
	jmp LABEL_7FA2

LABEL_7F66:
	jl [0x14], 0x24B8, LABEL_7F74
	mov [0x16], 0x0000
	jmp LABEL_7FA2

LABEL_7F74:
	jl [0x14], 0x2328, LABEL_7F82
	mov [0x16], 0x0001
	jmp LABEL_7FA2

LABEL_7F82:
	jl [0x14], 0x2198, LABEL_7F90
	mov [0x16], 0x0001
	jmp LABEL_7FA2

LABEL_7F90:
	jl [0x14], 0x2008, INLINE_SET_VAR16_TO_0
	mov [0x16], 0x0000
	jmp LABEL_7FA2
