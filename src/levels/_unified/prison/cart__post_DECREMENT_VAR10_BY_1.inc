LABEL_897B:
	call LABEL_4958
	call LABEL_0068
	mov [0x32], 0x0000
	call LABEL_8084
	jl [HERO_X], 0x0146, LABEL_89B4
	je [0x63], 0x02, LABEL_899C
	jl [HERO_X], 0x0150, LABEL_89B4

LABEL_899C:
	add [HACK_VAR_67], 0x0001
	call LABEL_884B
	call LABEL_883E
	mov [0x28], 0x0008
	mov [HERO_X], 0x0008
	call LABEL_8903
	jmp LABEL_89ED

LABEL_89B4:
	jg [HERO_X], 0xFFFA, LABEL_89E0
	je [0x63], 0x01, LABEL_89C8
	jg [HERO_X], 0xFFF0, LABEL_89E0

LABEL_89C8:
	sub [HACK_VAR_67], 0x0001
	call LABEL_884B
	call LABEL_883E
	mov [0x28], 0x0140
	mov [HERO_X], 0x0140
	call LABEL_8903
	jmp LABEL_89ED

LABEL_89E0:
	jl [HERO_Y], 0xDC, LABEL_89E6

LABEL_89E6:
	jg [HERO_Y], 0xFFEC, LABEL_89ED

LABEL_89ED:
	break
	jmp LABEL_897B
	killChannel

LABEL_89F2:
	mov [HACK_VAR_67], 0x0001
	call JUNK__7FA3
	setPalette 0x09
	je [0x66], 0x01, JUMP_TO_LABEL_8AAB
	mov [0x66], 0x0001
	fill page=0x00, color=0x02
	selectVideoPage 0x00
	call SETUP_VARS_01_B0_02_B6_06_C7_28_FROM_01
	selectVideoPage 0xFF
	copyVideoPage src=0x00, dst=0xFF

JUMP_TO_LABEL_8AAB:
	jmp LABEL_8AAB
LABEL_8A16:
	db 0x11

LABEL_8A17:
	mov [HACK_VAR_67], 0x0002
	call JUNK__7FA3
	setPalette 0x07
	je [0x66], 0x02, JUMP_TO_LABEL_8AC4
	mov [0x66], 0x0002
	fill page=0x00, color=0x0E
	selectVideoPage 0x00
	call SETUP_VARS_01_B0_02_B6_06_C7_28_FROM_01
	selectVideoPage 0xFF
	copyVideoPage src=0x00, dst=0xFF

JUMP_TO_LABEL_8AC4:
	jmp LABEL_8AC4
	killChannel

LABEL_8A3C:
	mov [HACK_VAR_67], 0x0003
	call JUNK__7FA3
	setPalette 0x05
	je [0x66], 0x03, JUMP_TO_LABEL_8AD6
	mov [0x66], 0x0003
	fill page=0x00, color=0x0E
	selectVideoPage 0x00
	call SETUP_VARS_01_B0_02_B6_06_C7_28_FROM_01
	selectVideoPage 0xFF
	copyVideoPage src=0x00, dst=0xFF

JUMP_TO_LABEL_8AD6:
	jmp LABEL_8AD6
LABEL_8A60:
	db 0x11

LABEL_8A61:
	mov [HACK_VAR_67], 0x0004
	call JUNK__7FA3
	setPalette 0x05
	je [0x66], 0x04, JUMP_TO_LABEL_8B03
	mov [0x66], 0x0004
	fill page=0x00, color=0x0E
	selectVideoPage 0x00
	call SETUP_VARS_01_B0_02_B6_06_C7_28_FROM_01
	selectVideoPage 0xFF
	copyVideoPage src=0x00, dst=0xFF

JUMP_TO_LABEL_8B03:
	jmp LABEL_8B03
LABEL_8A85:
	db 0x11

LABEL_8A86:
	mov [HACK_VAR_67], 0x0005
	call JUNK__7FA3
	setPalette 0x07
	je [0x66], 0x05, JUMP_TO_LABEL_8B30
	mov [0x66], 0x0005
	fill page=0x00, color=0x0E
	selectVideoPage 0x00
	call SETUP_VARS_01_B0_02_B6_06_C7_28_FROM_01
	selectVideoPage 0xFF
	copyVideoPage src=0x00, dst=0xFF

JUMP_TO_LABEL_8B30:
	jmp LABEL_8B30
LABEL_8AAA:
	db 0x11

LABEL_8AAB:
	jl [HERO_X], 0x0159, LABEL_8ABF
	mov [HERO_X], 0x0000
	call LABEL_8B5F
	call LABEL_8B5A
	jmp LABEL_8A17

LABEL_8ABF:
	break
	jmp LABEL_8AAB
LABEL_8AC3:
	db 0x11

LABEL_8AC4:
	mov [HERO_X], 0x0140
	call LABEL_8B5F
	call LABEL_8B5B
	jmp LABEL_89F2
	break
	jmp LABEL_8AC4
LABEL_8AD5:
	db 0x11

LABEL_8AD6:
	jl [HERO_X], 0x0159, LABEL_8AEA
	mov [HERO_X], 0x0000
	call LABEL_8B5F
	call JUNK__8B5C
	jmp LABEL_8A61

LABEL_8AEA:
	jg [HERO_X], 0xFFE7, LABEL_8AFE
	mov [HERO_X], 0x0140
	call LABEL_8B5F
	call JUNK__8B5C
	jmp LABEL_8A17

LABEL_8AFE:
	break
	jmp LABEL_8AD6
LABEL_8B02:
	db 0x11

LABEL_8B03:
	jl [HERO_X], 0x0159, LABEL_8B17
	mov [HERO_X], 0x0000
	call LABEL_8B5F
	call LABEL_8B5D
	jmp LABEL_8A86

LABEL_8B17:
	jg [HERO_X], 0xFFE7, LABEL_8B2B
	mov [HERO_X], 0x0140
	call LABEL_8B5F
	call LABEL_8B5D
	jmp LABEL_8A3C

LABEL_8B2B:
	break
	jmp LABEL_8B03
LABEL_8B2F:
	db 0x11

LABEL_8B30:
	jg [HERO_X], 0xFFE7, LABEL_8B44
	mov [HERO_X], 0x0140
	call LABEL_8B5F
	call LABEL_8B5E
	jmp LABEL_8A61

LABEL_8B44:
	jne [0x2A], 0x05, LABEL_8B55
	jl [HERO_X], 0x013D, LABEL_8B55
	setup channel=0x0A, address=JUNK__7FA3

LABEL_8B55:
	break
	jmp LABEL_8B30
LABEL_8B59:
	db 0x11

LABEL_8B5A:
	ret

LABEL_8B5B:
	ret

JUNK__8B5C:
	ret

LABEL_8B5D:
	ret

LABEL_8B5E:
	ret

LABEL_8B5F:
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	fill page=0xFF, color=0x04
	break
	jmp LABEL_8B5F
	killChannel

LABEL_8B6B:
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	fill page=0xFF, color=0x00
	break
	jmp LABEL_8B6B
LABEL_8B76:
	db 0x11

LABEL_8B77:
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	fill page=0xFF, color=0x00
	break
	jmp LABEL_8B77
LABEL_8B82:
	db 0x11
