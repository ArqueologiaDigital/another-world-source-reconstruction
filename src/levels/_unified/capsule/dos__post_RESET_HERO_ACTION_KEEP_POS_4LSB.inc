LABEL_9A21:
	mov [0x21], [HERO_X]
	mov [0x22], [HERO_Y]
	call LABEL_9F00
	mov [HERO_Y], [0x22]
	sub [HERO_Y], 0x0014
	break
	jmp LABEL_9A21

LABEL_9A35:
	mov [HERO_X], 0x003C
	mov [HERO_Y], 0x001D
	mov [0x32], 0x0001
	jmp LABEL_9A44

LABEL_9A44:
	sub [HERO_X], 0x0001
	video offset=CINEMATIC_332, x=[HERO_X], y=[HERO_Y]
	break
	add [HERO_X], 0x0001
	video offset=CINEMATIC_332, x=[HERO_X], y=[HERO_Y]
	break
	add [HERO_X], 0x0002
	video offset=CINEMATIC_332, x=[HERO_X], y=[HERO_Y]
	break
	add [HERO_X], 0x0003
	video offset=CINEMATIC_333, x=[HERO_X], y=[HERO_Y]
	break
	add [HERO_X], 0x0004
	video offset=CINEMATIC_333, x=[HERO_X], y=[HERO_Y]
	break
	add [HERO_X], 0x0003
	video offset=CINEMATIC_333, x=[HERO_X], y=[HERO_Y]
	break
	add [HERO_X], 0x0002
	video offset=CINEMATIC_332, x=[HERO_X], y=[HERO_Y]
	break
	add [HERO_X], 0x0001
	video offset=CINEMATIC_333, x=[HERO_X], y=[HERO_Y]
	break
	add [HERO_X], 0x0001
	video offset=CINEMATIC_334, x=[HERO_X], y=[HERO_Y]
	break
	add [HERO_X], 0x0001
	video offset=CINEMATIC_334, x=[HERO_X], y=[HERO_Y]
	break
	sub [HERO_Y], 0x0001
	video offset=CINEMATIC_334, x=[HERO_X], y=[HERO_Y]
	break
	add [HERO_Y], 0x0001
	add [HERO_X], 0x0001

LABEL_9ABA:
	video offset=CINEMATIC_334, x=[HERO_X], y=[HERO_Y]
	break
	je [HERO_POS_LEFT_RIGHT], 0x01, LABEL_9A44
	je [HERO_POS_LEFT_RIGHT], 0xFFFF, LABEL_9AD1
	jmp LABEL_9ABA
LABEL_9AD0:
	db 0x11

LABEL_9AD1:
	add [HERO_X], 0x0001
	video offset=CINEMATIC_332, x=[HERO_X], y=[HERO_Y]
	break
	sub [HERO_X], 0x0001
	video offset=CINEMATIC_332, x=[HERO_X], y=[HERO_Y]
	break
	sub [HERO_X], 0x0002
	video offset=CINEMATIC_332, x=[HERO_X], y=[HERO_Y]
	break
	sub [HERO_X], 0x0003
	video offset=CINEMATIC_333, x=[HERO_X], y=[HERO_Y]
	break
	sub [HERO_X], 0x0004
	video offset=CINEMATIC_333, x=[HERO_X], y=[HERO_Y]
	break
	sub [HERO_X], 0x0003
	video offset=CINEMATIC_333, x=[HERO_X], y=[HERO_Y]
	break
	sub [HERO_X], 0x0002
	video offset=CINEMATIC_332, x=[HERO_X], y=[HERO_Y]
	break
	sub [HERO_X], 0x0001
	video offset=CINEMATIC_333, x=[HERO_X], y=[HERO_Y]
	break
	sub [HERO_X], 0x0001
	video offset=CINEMATIC_334, x=[HERO_X], y=[HERO_Y]
	break
	sub [HERO_X], 0x0001
	video offset=CINEMATIC_334, x=[HERO_X], y=[HERO_Y]
	break
	sub [HERO_Y], 0x0001
	video offset=CINEMATIC_334, x=[HERO_X], y=[HERO_Y]
	break
	add [HERO_Y], 0x0001
	sub [HERO_X], 0x0001

LABEL_9B47:
	video offset=CINEMATIC_334, x=[HERO_X], y=[HERO_Y]
	break
	je [HERO_POS_LEFT_RIGHT], 0x01, LABEL_9A44
	je [HERO_POS_LEFT_RIGHT], 0xFFFF, LABEL_9AD1
	jmp LABEL_9B47
LABEL_9B5D:
	db 0x11

LABEL_9B5E:
	jge [0x04], 0x4000, LABEL_9BC8
	jl [HERO_X], [0x50], LABEL_9BC8
	add [0x50], 0x0014
	je [HACK_VAR_67], 0xEE, INLINE_ADD_VAR50_BY_C
	jne [HACK_VAR_67], 0x8E, LABEL_9B7F
