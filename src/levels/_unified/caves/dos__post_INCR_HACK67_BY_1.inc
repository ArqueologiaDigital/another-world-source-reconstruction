LABEL_DC98:
	db 0x11

LABEL_DC99:
	call LABEL_7EA2
	call LABEL_7DD3
	call LABEL_A21B
	jl [HERO_X], 0x0146, LABEL_DCD0
	je [HACK_VAR_67], 0x6D, LABEL_DCB5
	je [0x63], 0x02, LABEL_DCBC

LABEL_DCB5:
	jl [HERO_X], 0x0150, LABEL_DCD0

LABEL_DCBC:
	call LABEL_DC4D
	call LABEL_DA47
	mov [HERO_X], 0x0008
	call LABEL_DA1C
	mov [0x28], 0x0008
	jmp LABEL_DD2D

LABEL_DCD0:
	jg [HERO_X], 0xFFFA, LABEL_DCF8
	je [0x63], 0x01, LABEL_DCE4
	jg [HERO_X], 0xFFF0, LABEL_DCF8

LABEL_DCE4:
	call LABEL_DBF5
	call LABEL_DA47
	mov [HERO_X], 0x0140
	call LABEL_DA1C
	mov [0x28], 0x0140
	jmp LABEL_DD2D

LABEL_DCF8:
	jl [HERO_Y], 0xF9, LABEL_DD12
	call LABEL_DBBE
	call LABEL_DA47
	call LABEL_DA0F
	mov [0x28], 0x0008
	mov [HERO_Y], 0xFFFD
	jmp LABEL_DD2D

LABEL_DD12:
	jg [HERO_Y], 0xFFEC, LABEL_DD2D
	call LABEL_DBE1
	call LABEL_DA47
	call LABEL_DA0F
	mov [0x28], 0x0008
	mov [HERO_Y], 0x00C8
	jmp LABEL_DD2D

LABEL_DD2D:
	break
	jmp LABEL_DC99
	killChannel

LABEL_DD32:
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	fill page=0xFF, color=0x04
	break
	jmp LABEL_DD32
LABEL_DD3D:
	db 0x11

LABEL_DD3E:
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	fill page=0xFF, color=0x00
	copyVideoPage src=0x03, dst=0x00
	break
	jmp LABEL_DD3E
LABEL_DD4C:
	db 0x11

LABEL_DD4D:
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	fill page=0xFF, color=0x00
	break
	jmp LABEL_DD4D
LABEL_DD58:
	db 0x11
