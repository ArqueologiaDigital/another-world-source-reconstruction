LABEL_3209:
	add [0xEB], 0x000A
	mov [0x21], [0xEB]
	call LABEL_322F
	break
	djnz [0xEA], LABEL_3209
	mov [0xEA], 0x000E

LABEL_321C:
	sub [0xEB], 0x000A
	mov [0x21], [0xEB]
	call LABEL_322F
	break
	djnz [0xEA], LABEL_321C
	jmp INIT_VARS_EA_EB
LABEL_322E:
	db 0x11

LABEL_322F:
	mov [0xEE], [0x21]
	je [HACK_VAR_67], 0x6A, DRAW_CIN_294
	video offset=CINEMATIC_294, x=[0x21], y=98
	ret

DRAW_CIN_294:
	video offset=CINEMATIC_294, x=[0x21], y=85
	ret

DRAW_CIN_295:
	video offset=CINEMATIC_295, x=160, y=[0x21]
	ret

LABEL_324A:
	break
	jg [0x06], 0x03DE, LABEL_324A
	jne [0x04], 0x20, LABEL_324A
	je [HACK_VAR_67], 0x4F, LABEL_3267
	jg [0x01], 0x67, LABEL_324A
	jmp LABEL_3273

LABEL_3267:
	jg [0x01], 0x6E, LABEL_324A
	jg [0x02], 0x64, LABEL_324A

LABEL_3273:
	mov [0x01], 0x0069
	mov [0x06], 0x03E8
	setPalette 0x05
	deleteChannels first=0x14, last=0x16
	setup channel=0x14, address=LABEL_0779
	setup channel=0x19, address=LABEL_0885
	mov [0xED], 0x00A0
	mov [0xEE], 0x0064
	jne [HACK_VAR_67], 0x4F, LABEL_324A
	mov [0xED], 0x00A7
	mov [0xEE], 0x000A
	mov [0x01], 0x0070
	jmp LABEL_324A
LABEL_32A7:
	db 0x11

LABEL_32A8:
	mov [0xE6], 0x0026
	mov [0xE7], 0x005A
	jne [HACK_VAR_67], 0x4F, COPY_VARE6E7_TO_VARE8_E9_EA_EB
	mov [0xE6], 0x002D
	mov [0xE7], 0x0002
