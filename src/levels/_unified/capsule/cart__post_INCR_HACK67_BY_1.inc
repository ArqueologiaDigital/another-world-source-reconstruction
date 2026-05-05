LABEL_B61C:
	db 0x11

LABEL_B61D:
	call LABEL_7498
	call LABEL_73C9
	call LABEL_00DD
	call LABEL_9BC7
	jl [HERO_X], 0x0146, LABEL_B65D
	je [HACK_VAR_67], 0x91, LABEL_B63C
	je [0x63], 0x02, LABEL_B643

LABEL_B63C:
	jl [HERO_X], 0x0150, LABEL_B65D

LABEL_B643:
	call LABEL_B5DF
	call LABEL_B3AB
	call LABEL_B37A
	mov [0x28], 0x0008
	je [HACK_VAR_67], 0x6B, LABEL_B6D2
	mov [HERO_X], 0x0008
	jmp LABEL_B6D2

LABEL_B65D:
	jg [HERO_X], 0xFFFA, LABEL_B68B
	je [0x63], 0x01, LABEL_B671
	jg [HERO_X], 0xFFF0, LABEL_B68B

LABEL_B671:
	call LABEL_B58F
	call LABEL_B3AB
	call LABEL_B37A
	mov [0x28], 0x0140
	je [HACK_VAR_67], 0x8A, LABEL_B6D2
	mov [HERO_X], 0x0140
	jmp LABEL_B6D2

LABEL_B68B:
	jl [HERO_Y], 0xF9, LABEL_B6B1
	call LABEL_B4ED
	call LABEL_B3AB
	call LABEL_B37A
	mov [0x28], 0x0008
	je [HACK_VAR_67], 0xC9, LABEL_B6D2
	je [HACK_VAR_67], 0x8B, LABEL_B6D2
	mov [HERO_Y], 0xFFFD
	jmp LABEL_B6D2

LABEL_B6B1:
	jg [HERO_Y], 0xFFEC, LABEL_B6D2
	call LABEL_B570
	call LABEL_B3AB
	call LABEL_B37A
	mov [HERO_Y], 0x00C8
	je [HACK_VAR_67], 0xAA, LABEL_B6D2
	mov [0x28], 0x0008
	jmp LABEL_B6D2

LABEL_B6D2:
	break
	jmp LABEL_B61D
	killChannel

LABEL_B6D7:
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	fill page=0xFF, color=0x04
	break
	jmp LABEL_B6D7
LABEL_B6E2:
	db 0x11

LABEL_B6E3:
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	fill page=0xFF, color=0x00
	copyVideoPage src=0x03, dst=0x00
	break
	jmp LABEL_B6E3
	killChannel

LABEL_B6F2:
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	fill page=0xFF, color=0x00
	break
	jmp LABEL_B6F2
LABEL_B6FD:
	db 0x11
