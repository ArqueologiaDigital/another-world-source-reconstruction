LABEL_3432:
	add [0xEB], 0x000A
	mov [0x21], [0xEB]
	call LABEL_3458
	break
	djnz [0xEA], LABEL_3432
	mov [0xEA], 0x000E

LABEL_3445:
	sub [0xEB], 0x000A
	mov [0x21], [0xEB]
	call LABEL_3458
	break
	djnz [0xEA], LABEL_3445
	jmp INIT_VARS_EA_EB
LABEL_3457:
	db 0x11

LABEL_3458:
	mov [0xEE], [0x21]
	je [HACK_VAR_67], 0x6A, DRAW_CIN_315
	video offset=CINEMATIC_315, x=[0x21], y=98
	ret

DRAW_CIN_315:
	video offset=CINEMATIC_315, x=[0x21], y=85
	ret

DRAW_CIN_316:
	video offset=CINEMATIC_316, x=160, y=[0x21]
	ret

LABEL_3473:
	break
	jg [0x06], 0x03DE, LABEL_3473
	jne [0x04], 0x20, LABEL_3473
	je [HACK_VAR_67], 0x4F, LABEL_3490
	jg [HERO_X], 0x67, LABEL_3473
	jmp LABEL_349C

LABEL_3490:
	jg [HERO_X], 0x6E, LABEL_3473
	jg [HERO_Y], 0x64, LABEL_3473

LABEL_349C:
	mov [HERO_X], 0x0069
	mov [0x06], 0x03E8
	setPalette 0x05
	deleteChannels first=0x14, last=0x16
	setup channel=0x14, address=LABEL_079A
	setup channel=0x19, address=LABEL_08A6
	mov [0xED], 0x00A0
	mov [0xEE], 0x0064
	jne [HACK_VAR_67], 0x4F, LABEL_3473
	mov [0xED], 0x00A7
	mov [0xEE], 0x000A
	mov [HERO_X], 0x0070
	jmp LABEL_3473
LABEL_34D0:
	db 0x11

LABEL_34D1:
	mov [0xE6], 0x0026
	mov [0xE7], 0x005A
	jne [HACK_VAR_67], 0x4F, COPY_VARE6E7_TO_VARE8_E9_EA_EB
	mov [0xE6], 0x002D
	mov [0xE7], 0x0002
