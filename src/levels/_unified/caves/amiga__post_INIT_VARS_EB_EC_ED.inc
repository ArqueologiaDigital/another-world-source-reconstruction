LABEL_2753:
	video offset=CINEMATIC_448, x=160, y=[0xec]
	video offset=CINEMATIC_449, x=160, y=[0xed]
	sub [0xEC], 0x0010
	sub [0xED], 0x000C
	break
	djnz [0xEB], LABEL_2753
	killChannel

LABEL_276B:
	break
	jl [HERO_X], 0x7A, LABEL_276B
	jg [HERO_X], 0xA1, LABEL_276B
	jl [HERO_Y], 0x96, LABEL_276B
	jg [HERO_Y], 0xCE, LABEL_276B
	mov [HERO_Y], 0x00B4
	jmp LABEL_27CE
LABEL_278B:
	db 0x11

LABEL_278C:
	break
	jl [HERO_Y], 0x46, LABEL_278C
	mov [HERO_Y], 0x006E
	jmp LABEL_27CE
LABEL_279A:
	db 0x11

LABEL_279B:
	break
	jl [HERO_Y], 0x64, LABEL_279B
	mov [HERO_Y], 0x0094
	jmp LABEL_27CE
LABEL_27A9:
	db 0x11, 0x06, 0x0A, 0x04, 0x02, 0xAA, 0x27, 0xAA
	db 0x00, 0x02, 0x00, 0xBE, 0x07, 0x27, 0xCE, 0x11

LABEL_27B9:
	break
	jg [HERO_X], 0xA7, LABEL_27B9
	jl [HERO_Y], 0xAA, LABEL_27B9
	mov [HERO_Y], 0x00BE
	jmp LABEL_27CE
LABEL_27CD:
	db 0x11

LABEL_27CE:
	deleteChannels first=0x14, last=0x16
	mov [0x04], 0x4000
	mov [0x32], 0x0001
	play id=0x007A, freq=0x14, vol=0x40, channel=0x01
	play id=0x0078, freq=0x14, vol=0x40, channel=0x00
	je [HACK_VAR_67], 0x28, LABEL_27F0
	setup channel=0x3C, address=LABEL_3DE6

LABEL_27F0:
	break
	je [HACK_VAR_67], 0x28, LABEL_2822
	video offset=CINEMATIC_272, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_273, x=[HERO_X], y=[HERO_Y]
	add [HERO_Y], 0x0001
	break
	video offset=CINEMATIC_273, x=[HERO_X], y=[HERO_Y]
	add [HERO_Y], 0x0001
	mov [0x03], 0x000A
	setup channel=0x3F, address=LABEL_016F

LABEL_2818:
	break
	video offset=CINEMATIC_273, x=[HERO_X], y=[HERO_Y]
	jmp LABEL_2818
LABEL_2821:
	db 0x11

LABEL_2822:
	video offset=CINEMATIC_270, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_271, x=[HERO_X], y=[HERO_Y]
	add [HERO_Y], 0x0001
	break
	video offset=CINEMATIC_271, x=[HERO_X], y=[HERO_Y]
	add [HERO_Y], 0x0001
	mov [0x03], 0x000A
	setup channel=0x3F, address=LABEL_016F

LABEL_2843:
	break
	video offset=CINEMATIC_271, x=[HERO_X], y=[HERO_Y]
	jmp LABEL_2843
LABEL_284C:
	db 0x11

LABEL_284D:
	mov [0x07], [0x68]
	mov [0x08], [0x69]
	mov [0x09], 0x0000
	call LABEL_288E
	break
	jmp LABEL_284D
LABEL_285E:
	db 0x11

LABEL_285F:
	je [0x09], 0x01, LABEL_3015
	je [0x09], 0x02, LABEL_2FAB
	je [0x09], 0x00, LABEL_2F9B
	killChannel

LABEL_2872:
	mov [0x07], [0x6A]
	mov [0x08], [0x6B]
	call LABEL_288E
	break
	jmp LABEL_2872
LABEL_287F:
	db 0x11

LABEL_2880:
	mov [0x07], [0x6C]
	mov [0x08], [0x6D]
	call LABEL_288E
	break
	jmp LABEL_2880
LABEL_288D:
	db 0x11

LABEL_288E:
	mov [0x09], 0x0000
	mov [0x21], [0x07]
	mov [0x22], [0x07]
	sub [0x21], 0x000A
	add [0x22], 0x000A
	jl [HERO_X], [0x21], LABEL_28E3
	jg [HERO_X], [0x22], LABEL_28E3
	mov [0x21], [0x08]
	sub [0x21], 0x0002
	mov [0x22], [0x08]
	add [0x22], 0x0002
	jl [HERO_Y], [0x21], SHARED_RET
	jg [HERO_Y], [0x22], SHARED_RET
	jge [0x04], 0x4000, SHARED_RET
	or [0x04], 0x4000
	mov [0xF8], [0x04]
	and [0xF8], 0x0004
	je [0xF8], 0x04, SHARED_RET
	mov [0x09], 0x0001
	ret

LABEL_28E3:
	sub [0x21], 0x0014
	add [0x22], 0x0014
	je [0x09], 0x02, SHARED_RET
	jl [HERO_X], [0x21], SHARED_RET
	jg [HERO_X], [0x22], SHARED_RET
	mov [0x09], 0x0002
	ret
