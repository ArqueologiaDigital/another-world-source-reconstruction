LABEL_DD1E:
	db 0x11

LABEL_DD1F:
	call LABEL_7E19
	call LABEL_7D4A
	call LABEL_0094
	call LABEL_A192
	jl [HERO_X], 0x0146, LABEL_DD59
	je [HACK_VAR_67], 0x6D, LABEL_DD3E
	je [0x63], 0x02, LABEL_DD45

LABEL_DD3E:
	jl [HERO_X], 0x0150, LABEL_DD59

LABEL_DD45:
	call LABEL_DCD3
	call LABEL_DACD
	mov [HERO_X], 0x0008
	call LABEL_DAA2
	mov [0x28], 0x0008
	jmp LABEL_DDB6

LABEL_DD59:
	jg [HERO_X], 0xFFFA, LABEL_DD81
	je [0x63], 0x01, LABEL_DD6D
	jg [HERO_X], 0xFFF0, LABEL_DD81

LABEL_DD6D:
	call LABEL_DC7B
	call LABEL_DACD
	mov [HERO_X], 0x0140
	call LABEL_DAA2
	mov [0x28], 0x0140
	jmp LABEL_DDB6

LABEL_DD81:
	jl [HERO_Y], 0xF9, LABEL_DD9B
	call LABEL_DC44
	call LABEL_DACD
	call LABEL_DA95
	mov [0x28], 0x0008
	mov [HERO_Y], 0xFFFD
	jmp LABEL_DDB6

LABEL_DD9B:
	jg [HERO_Y], 0xFFEC, LABEL_DDB6
	call LABEL_DC67
	call LABEL_DACD
	call LABEL_DA95
	mov [0x28], 0x0008
	mov [HERO_Y], 0x00C8
	jmp LABEL_DDB6

LABEL_DDB6:
	break
	jmp LABEL_DD1F
	killChannel

LABEL_DDBB:
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	fill page=0xFF, color=0x04
	break
	jmp LABEL_DDBB
LABEL_DDC6:
	db 0x11

LABEL_DDC7:
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	fill page=0xFF, color=0x00
	copyVideoPage src=0x03, dst=0x00
	break
	jmp LABEL_DDC7
LABEL_DDD5:
	db 0x11

LABEL_DDD6:
	blitFramebuffer 0xFF
	selectVideoPage 0xFF
	fill page=0xFF, color=0x00
	break
	jmp LABEL_DDD6
LABEL_DDE1:
	db 0x11
