LABEL_8824:
	call LABEL_485E
	call LABEL_7F55
	jl [HERO_X], 0x0146, LABEL_8856
	je [0x63], 0x02, LABEL_883E
	jl [HERO_X], 0x0150, LABEL_8856

LABEL_883E:
	add [HACK_VAR_67], 0x0001
	call LABEL_86FA
	call LABEL_86ED
	mov [0x28], 0x0008
	mov [HERO_X], 0x0008
	call LABEL_87B2
	jmp LABEL_888F

LABEL_8856:
	jg [HERO_X], 0xFFFA, LABEL_8882
	je [0x63], 0x01, LABEL_886A
	jg [HERO_X], 0xFFF0, LABEL_8882

LABEL_886A:
	sub [HACK_VAR_67], 0x0001
	call LABEL_86FA
	call LABEL_86ED
	mov [0x28], 0x0140
	mov [HERO_X], 0x0140
	call LABEL_87B2
	jmp LABEL_888F

LABEL_8882:
	jl [HERO_Y], 0xDC, LABEL_8888

LABEL_8888:
	jg [HERO_Y], 0xFFEC, LABEL_888F

LABEL_888F:
	break
	jmp LABEL_8824
	killChannel

LABEL_8894:
	mov [HACK_VAR_67], 0x0001
	call JUNK__7E74
	setPalette 0x09
	je [0x66], 0x01, JUMP_TO_LABEL_894D
	mov [0x66], 0x0001
	fill page=0x00, color=0x02
	selectVideoPage 0x00
	call SETUP_VARS_01_B0_02_B6_06_C7_28_FROM_01
	selectVideoPage 0xFF
	copyVideoPage src=0x00, dst=0xFF

JUMP_TO_LABEL_894D:
	jmp LABEL_894D
LABEL_88B8:
	db 0x11

LABEL_88B9:
	mov [HACK_VAR_67], 0x0002
	call JUNK__7E74
	setPalette 0x07
	je [0x66], 0x02, JUMP_TO_LABEL_8966
	mov [0x66], 0x0002
	fill page=0x00, color=0x0E
	selectVideoPage 0x00
	call SETUP_VARS_01_B0_02_B6_06_C7_28_FROM_01
	selectVideoPage 0xFF
	copyVideoPage src=0x00, dst=0xFF

JUMP_TO_LABEL_8966:
	jmp LABEL_8966
	killChannel

LABEL_88DE:
	mov [HACK_VAR_67], 0x0003
	call JUNK__7E74
	setPalette 0x05
	je [0x66], 0x03, JUMP_TO_LABEL_8978
	mov [0x66], 0x0003
	fill page=0x00, color=0x0E
	selectVideoPage 0x00
	call SETUP_VARS_01_B0_02_B6_06_C7_28_FROM_01
	selectVideoPage 0xFF
	copyVideoPage src=0x00, dst=0xFF

JUMP_TO_LABEL_8978:
	jmp LABEL_8978
LABEL_8902:
	db 0x11

LABEL_8903:
	mov [HACK_VAR_67], 0x0004
	call JUNK__7E74
	setPalette 0x05
	je [0x66], 0x04, JUMP_TO_LABEL_89A5
	mov [0x66], 0x0004
	fill page=0x00, color=0x0E
	selectVideoPage 0x00
	call SETUP_VARS_01_B0_02_B6_06_C7_28_FROM_01
	selectVideoPage 0xFF
	copyVideoPage src=0x00, dst=0xFF

JUMP_TO_LABEL_89A5:
	jmp LABEL_89A5
LABEL_8927:
	db 0x11

LABEL_8928:
	mov [HACK_VAR_67], 0x0005
	call JUNK__7E74
	setPalette 0x07
	je [0x66], 0x05, JUMP_TO_LABEL_89D2
	mov [0x66], 0x0005
	fill page=0x00, color=0x0E
	selectVideoPage 0x00
	call SETUP_VARS_01_B0_02_B6_06_C7_28_FROM_01
	selectVideoPage 0xFF
	copyVideoPage src=0x00, dst=0xFF

JUMP_TO_LABEL_89D2:
	jmp LABEL_89D2
LABEL_894C:
	db 0x11

LABEL_894D:
	jl [HERO_X], 0x0159, LABEL_8961
	mov [HERO_X], 0x0000
	call LABEL_8A01
	call LABEL_89FC
	jmp LABEL_88B9

LABEL_8961:
	break
	jmp LABEL_894D
LABEL_8965:
	db 0x11

LABEL_8966:
	mov [HERO_X], 0x0140
	call LABEL_8A01
	call LABEL_89FD
	jmp LABEL_8894
	break
	jmp LABEL_8966
LABEL_8977:
	db 0x11

LABEL_8978:
	jl [HERO_X], 0x0159, LABEL_898C
	mov [HERO_X], 0x0000
	call LABEL_8A01
	call JUNK__89FE
	jmp LABEL_8903

LABEL_898C:
	jg [HERO_X], 0xFFE7, LABEL_89A0
	mov [HERO_X], 0x0140
	call LABEL_8A01
	call JUNK__89FE
	jmp LABEL_88B9

LABEL_89A0:
	break
	jmp LABEL_8978
LABEL_89A4:
	db 0x11

LABEL_89A5:
	jl [HERO_X], 0x0159, LABEL_89B9
	mov [HERO_X], 0x0000
	call LABEL_8A01
	call LABEL_89FF
	jmp LABEL_8928

LABEL_89B9:
	jg [HERO_X], 0xFFE7, LABEL_89CD
	mov [HERO_X], 0x0140
	call LABEL_8A01
	call LABEL_89FF
	jmp LABEL_88DE

LABEL_89CD:
	break
	jmp LABEL_89A5
LABEL_89D1:
	db 0x11

LABEL_89D2:
	jg [HERO_X], 0xFFE7, LABEL_89E6
	mov [HERO_X], 0x0140
	call LABEL_8A01
	call LABEL_8A00
	jmp LABEL_8903

LABEL_89E6:
	jne [0x2A], 0x05, LABEL_89F7
	jl [HERO_X], 0x013D, LABEL_89F7
	setup channel=0x0A, address=JUNK__7E74

LABEL_89F7:
	break
	jmp LABEL_89D2
LABEL_89FB:
	db 0x11

LABEL_89FC:
	ret

LABEL_89FD:
	ret

JUNK__89FE:
	ret

LABEL_89FF:
	ret

LABEL_8A00:
	ret

LABEL_8A01:
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	fill page=0xFF, color=0x04
	break
	jmp LABEL_8A01
	killChannel

LABEL_8A0D:
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	fill page=0xFF, color=0x00
	break
	jmp LABEL_8A0D
LABEL_8A18:
	db 0x11

LABEL_8A19:
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	fill page=0xFF, color=0x00
	break
	jmp LABEL_8A19
LABEL_8A24:
	db 0x11
