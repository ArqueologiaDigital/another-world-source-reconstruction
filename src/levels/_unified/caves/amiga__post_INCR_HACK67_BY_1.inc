LABEL_D7A4:
	db 0x11

LABEL_D7A5:
	call LABEL_7B44
	call LABEL_7A75
	call LABEL_9EBD
	jl [HERO_X], 0x0150, LABEL_D7C9
	call LABEL_D761
	call LABEL_D561
	mov [HERO_X], 0x0008
	call LABEL_D53C
	mov [0x28], 0x0008
	jmp LABEL_D819

LABEL_D7C9:
	jg [HERO_X], 0xFFF0, LABEL_D7E4
	call LABEL_D709
	call LABEL_D561
	mov [HERO_X], 0x0140
	call LABEL_D53C
	mov [0x28], 0x0140
	jmp LABEL_D819

LABEL_D7E4:
	jl [HERO_Y], 0xF9, LABEL_D7FE
	call LABEL_D6D2
	call LABEL_D561
	call LABEL_D52F
	mov [0x28], 0x0008
	mov [HERO_Y], 0xFFFD
	jmp LABEL_D819

LABEL_D7FE:
	jg [HERO_Y], 0xFFEC, LABEL_D819
	call LABEL_D6F5
	call LABEL_D561
	call LABEL_D52F
	mov [0x28], 0x0008
	mov [HERO_Y], 0x00C8
	jmp LABEL_D819

LABEL_D819:
	break
	jmp LABEL_D7A5
LABEL_D81D:
	db 0x11, 0x10, 0xFF, 0x0D, 0xFF, 0x0E, 0xFF, 0x04
	db 0x06, 0x07, 0xD8, 0x1E, 0x11

LABEL_D82A:
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	fill page=0xFF, color=0x00
	copyVideoPage src=0x03, dst=0x00
	break
	jmp LABEL_D82A
LABEL_D838:
	db 0x11

LABEL_D839:
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	fill page=0xFF, color=0x00
	break
	jmp LABEL_D839
LABEL_D844:
	db 0x11
