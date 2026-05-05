LABEL_7DDD:
	selectVideoPage 0x00
	video offset=CINEMATIC_106, x=160, y=100
	call LABEL_7D56
	selectVideoPage 0xFF
	killChannel

LABEL_7DE9:
	copyVideoPage src=0x03, dst=0x00
	break
	jmp LABEL_7DDD

LABEL_7DF0:
	selectVideoPage 0x00
	video offset=CINEMATIC_106, x=160, y=100
	call LABEL_7D5D
	selectVideoPage 0xFF
	killChannel

LABEL_7DFC:
	selectVideoPage 0x00
	video offset=CINEMATIC_106, x=160, y=100
	call LABEL_7D64
	selectVideoPage 0xFF
	killChannel
	selectVideoPage 0x00
	selectVideoPage 0xFF
	killChannel

LABEL_7E0D:
	jl [0x14], 0x2968, LABEL_7E1B
	mov [0x16], 0x0000
	jmp LABEL_7E73

LABEL_7E1B:
	jl [0x14], 0x27D8, LABEL_7E29
	mov [0x16], 0x0001
	jmp LABEL_7E73

LABEL_7E29:
	jl [0x14], 0x2648, LABEL_7E37
	mov [0x16], 0x0001
	jmp LABEL_7E73

LABEL_7E37:
	jl [0x14], 0x24B8, LABEL_7E45
	mov [0x16], 0x0000
	jmp LABEL_7E73

LABEL_7E45:
	jl [0x14], 0x2328, LABEL_7E53
	mov [0x16], 0x0001
	jmp LABEL_7E73

LABEL_7E53:
	jl [0x14], 0x2198, LABEL_7E61
	mov [0x16], 0x0001
	jmp LABEL_7E73

LABEL_7E61:
	jl [0x14], 0x2008, INLINE_SET_VAR16_TO_0
	mov [0x16], 0x0000
	jmp LABEL_7E73
