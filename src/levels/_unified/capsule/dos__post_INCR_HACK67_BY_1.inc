LABEL_B53B:
	db 0x11

LABEL_B53C:
	call LABEL_742F
	call LABEL_7360
	call LABEL_9B5E
	jl [0x01], 0x0146, LABEL_B579
	je [HACK_VAR_67], 0x91, LABEL_B558
	je [0x63], 0x02, LABEL_B55F

LABEL_B558:
	jl [0x01], 0x0150, LABEL_B579

LABEL_B55F:
	call LABEL_B4FE
	call LABEL_B2CA
	call LABEL_B299
	mov [0x28], 0x0008
	je [HACK_VAR_67], 0x6B, LABEL_B5EE
	mov [0x01], 0x0008
	jmp LABEL_B5EE

LABEL_B579:
	jg [0x01], 0xFFFA, LABEL_B5A7
	je [0x63], 0x01, LABEL_B58D
	jg [0x01], 0xFFF0, LABEL_B5A7

LABEL_B58D:
	call LABEL_B4AE
	call LABEL_B2CA
	call LABEL_B299
	mov [0x28], 0x0140
	je [HACK_VAR_67], 0x8A, LABEL_B5EE
	mov [0x01], 0x0140
	jmp LABEL_B5EE

LABEL_B5A7:
	jl [0x02], 0xF9, LABEL_B5CD
	call LABEL_B40C
	call LABEL_B2CA
	call LABEL_B299
	mov [0x28], 0x0008
	je [HACK_VAR_67], 0xC9, LABEL_B5EE
	je [HACK_VAR_67], 0x8B, LABEL_B5EE
	mov [0x02], 0xFFFD
	jmp LABEL_B5EE

LABEL_B5CD:
	jg [0x02], 0xFFEC, LABEL_B5EE
	call LABEL_B48F
	call LABEL_B2CA
	call LABEL_B299
	mov [0x02], 0x00C8
	je [HACK_VAR_67], 0xAA, LABEL_B5EE
	mov [0x28], 0x0008
	jmp LABEL_B5EE

LABEL_B5EE:
	break
	jmp LABEL_B53C
	killChannel

LABEL_B5F3:
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	fill page=0xFF, color=0x04
	break
	jmp LABEL_B5F3
LABEL_B5FE:
	db 0x11

LABEL_B5FF:
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	fill page=0xFF, color=0x00
	copyVideoPage src=0x03, dst=0x00
	break
	jmp LABEL_B5FF
	killChannel

LABEL_B60E:
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	fill page=0xFF, color=0x00
	break
	jmp LABEL_B60E
LABEL_B619:
	db 0x11
