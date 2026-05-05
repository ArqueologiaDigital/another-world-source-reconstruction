LABEL_7D12:
	selectVideoPage 0x00
	video offset=CINEMATIC_106, x=160, y=100
	call LABEL_7C8B
	selectVideoPage 0xFF
	killChannel

LABEL_7D1E:
	copyVideoPage src=0x03, dst=0x00
	break
	jmp LABEL_7D12

LABEL_7D25:
	selectVideoPage 0x00
	video offset=CINEMATIC_106, x=160, y=100
	call LABEL_7C92
	selectVideoPage 0xFF
	killChannel

LABEL_7D31:
	selectVideoPage 0x00
	video offset=CINEMATIC_106, x=160, y=100
	call LABEL_7C99
	selectVideoPage 0xFF
	killChannel
	selectVideoPage 0x00
	selectVideoPage 0xFF
	killChannel

LABEL_7D42:
	jl [0x14], 0x2968, LABEL_7D50
	mov [0x16], 0x0000
	jmp LABEL_7DA8

LABEL_7D50:
	jl [0x14], 0x27D8, LABEL_7D5E
	mov [0x16], 0x0001
	jmp LABEL_7DA8

LABEL_7D5E:
	jl [0x14], 0x2648, LABEL_7D6C
	mov [0x16], 0x0001
	jmp LABEL_7DA8

LABEL_7D6C:
	jl [0x14], 0x24B8, LABEL_7D7A
	mov [0x16], 0x0000
	jmp LABEL_7DA8

LABEL_7D7A:
	jl [0x14], 0x2328, LABEL_7D88
	mov [0x16], 0x0001
	jmp LABEL_7DA8

LABEL_7D88:
	jl [0x14], 0x2198, LABEL_7D96
	mov [0x16], 0x0001
	jmp LABEL_7DA8

LABEL_7D96:
	jl [0x14], 0x2008, INLINE_SET_VAR16_TO_0
	mov [0x16], 0x0000
	jmp LABEL_7DA8
