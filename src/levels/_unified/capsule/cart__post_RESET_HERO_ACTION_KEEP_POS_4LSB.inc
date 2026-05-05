LABEL_9A8A:
	mov [0x21], [HERO_X]
	mov [0x22], [HERO_Y]
	call LABEL_9F44
	mov [HERO_Y], [0x22]
	sub [HERO_Y], 0x0014
	break
	jmp LABEL_9A8A

LABEL_9A9E:
	mov [HERO_X], 0x003C
	mov [HERO_Y], 0x001D
	mov [0x32], 0x0001
	jmp LABEL_9AAD

LABEL_9AAD:
	sub [HERO_X], 0x0001
	video offset=CINEMATIC_333, x=[HERO_X], y=[HERO_Y]
	break
	add [HERO_X], 0x0001
	video offset=CINEMATIC_333, x=[HERO_X], y=[HERO_Y]
	break
	add [HERO_X], 0x0002
	video offset=CINEMATIC_333, x=[HERO_X], y=[HERO_Y]
	break
	add [HERO_X], 0x0003
	video offset=CINEMATIC_334, x=[HERO_X], y=[HERO_Y]
	break
	add [HERO_X], 0x0004
	video offset=CINEMATIC_334, x=[HERO_X], y=[HERO_Y]
	break
	add [HERO_X], 0x0003
	video offset=CINEMATIC_334, x=[HERO_X], y=[HERO_Y]
	break
	add [HERO_X], 0x0002
	video offset=CINEMATIC_333, x=[HERO_X], y=[HERO_Y]
	break
	add [HERO_X], 0x0001
	video offset=CINEMATIC_334, x=[HERO_X], y=[HERO_Y]
	break
	add [HERO_X], 0x0001
	video offset=CINEMATIC_335, x=[HERO_X], y=[HERO_Y]
	break
	add [HERO_X], 0x0001
	video offset=CINEMATIC_335, x=[HERO_X], y=[HERO_Y]
	break
	sub [HERO_Y], 0x0001
	video offset=CINEMATIC_335, x=[HERO_X], y=[HERO_Y]
	break
	add [HERO_Y], 0x0001
	add [HERO_X], 0x0001

LABEL_9B23:
	video offset=CINEMATIC_335, x=[HERO_X], y=[HERO_Y]
	break
	je [HERO_POS_LEFT_RIGHT], 0x01, LABEL_9AAD
	je [HERO_POS_LEFT_RIGHT], 0xFFFF, LABEL_9B3A
	jmp LABEL_9B23
LABEL_9B39:
	db 0x11

LABEL_9B3A:
	add [HERO_X], 0x0001
	video offset=CINEMATIC_333, x=[HERO_X], y=[HERO_Y]
	break
	sub [HERO_X], 0x0001
	video offset=CINEMATIC_333, x=[HERO_X], y=[HERO_Y]
	break
	sub [HERO_X], 0x0002
	video offset=CINEMATIC_333, x=[HERO_X], y=[HERO_Y]
	break
	sub [HERO_X], 0x0003
	video offset=CINEMATIC_334, x=[HERO_X], y=[HERO_Y]
	break
	sub [HERO_X], 0x0004
	video offset=CINEMATIC_334, x=[HERO_X], y=[HERO_Y]
	break
	sub [HERO_X], 0x0003
	video offset=CINEMATIC_334, x=[HERO_X], y=[HERO_Y]
	break
	sub [HERO_X], 0x0002
	video offset=CINEMATIC_333, x=[HERO_X], y=[HERO_Y]
	break
	sub [HERO_X], 0x0001
	video offset=CINEMATIC_334, x=[HERO_X], y=[HERO_Y]
	break
	sub [HERO_X], 0x0001
	video offset=CINEMATIC_335, x=[HERO_X], y=[HERO_Y]
	break
	sub [HERO_X], 0x0001
	video offset=CINEMATIC_335, x=[HERO_X], y=[HERO_Y]
	break
	sub [HERO_Y], 0x0001
	video offset=CINEMATIC_335, x=[HERO_X], y=[HERO_Y]
	break
	add [HERO_Y], 0x0001
	sub [HERO_X], 0x0001

LABEL_9BB0:
	video offset=CINEMATIC_335, x=[HERO_X], y=[HERO_Y]
	break
	je [HERO_POS_LEFT_RIGHT], 0x01, LABEL_9AAD
	je [HERO_POS_LEFT_RIGHT], 0xFFFF, LABEL_9B3A
	jmp LABEL_9BB0
LABEL_9BC6:
	db 0x11

LABEL_9BC7:
	jge [0x04], 0x4000, LABEL_9C39
	jl [HERO_X], [0x50], LABEL_9C39
	add [0x50], 0x0014
	je [HACK_VAR_67], 0xEE, INLINE_ADD_VAR50_BY_C
	jne [HACK_VAR_67], 0x8E, LABEL_9BE8
