LABEL_42BE:
	db 0x11

LABEL_42BF:
	jne [0x27], 0x03, LABEL_42D1
	video offset=CINEMATIC_524, x=[0x21], y=[0x26]
	sub [0x22], 0x0001
	jmp DECREMENT_VAR22

LABEL_42D1:
	jne [0x27], 0x01, LABEL_42DF
	video offset=CINEMATIC_528, x=[0x21], y=[0x26]
	jmp DECREMENT_VAR22

LABEL_42DF:
	video offset=CINEMATIC_527, x=[0x21], y=[0x26]
	jmp DECREMENT_VAR22
LABEL_42E7:
	db 0x11

LABEL_42E8:
	jne [0x27], 0x03, LABEL_42FD
	video offset=CINEMATIC_526, x=[0x21], y=[0x26]
	call LABEL_431A
	sub [0x22], 0x0001
	jmp DECREMENT_VAR22

LABEL_42FD:
	jne [0x27], 0x01, LABEL_430E
	video offset=CINEMATIC_525, x=[0x21], y=[0x26]
	call LABEL_431A
	jmp DECREMENT_VAR22

LABEL_430E:
	video offset=CINEMATIC_522, x=[0x21], y=[0x26]
	call LABEL_431A
	jmp DECREMENT_VAR22
LABEL_4319:
	db 0x11

LABEL_431A:
	jle [0x22], 0x96, SHARED_RET
	sub [0x21], 0x0002
	video offset=CINEMATIC_523, x=[0x21], y=[0x26]
	add [0x21], 0x0002
	jle [0x22], 0x012C, SHARED_RET
	add [0x21], 0x0002
	video offset=CINEMATIC_524, x=[0x21], y=[0x26]
	sub [0x21], 0x0002
	ret

LABEL_4342:
	jne [0x27], 0x03, LABEL_4354
	video offset=CINEMATIC_530, x=[0x21], y=[0x26]
	sub [0x22], 0x0001
	jmp DECREMENT_VAR22

LABEL_4354:
	jne [0x27], 0x01, LABEL_4362
	video offset=CINEMATIC_523, x=[0x21], y=[0x26]
	jmp DECREMENT_VAR22

LABEL_4362:
	video offset=CINEMATIC_529, x=[0x21], y=[0x26]
	jmp DECREMENT_VAR22
LABEL_436A:
	db 0x11

LABEL_436B:
	jne [0x27], 0x03, LABEL_437D
	video offset=CINEMATIC_533, x=[0x21], y=[0x26]
	sub [0x22], 0x0001
	jmp DECREMENT_VAR22

LABEL_437D:
	jne [0x27], 0x01, LABEL_438B
	video offset=CINEMATIC_532, x=[0x21], y=[0x26]
	jmp DECREMENT_VAR22

LABEL_438B:
	video offset=CINEMATIC_531, x=[0x21], y=[0x26]
	jmp DECREMENT_VAR22
LABEL_4393:
	db 0x11

LABEL_4394:
	jne [0x27], 0x03, LABEL_43A6
	video offset=CINEMATIC_536, x=[0x21], y=[0x26]
	sub [0x22], 0x0001
	jmp DECREMENT_VAR22

LABEL_43A6:
	jne [0x27], 0x01, LABEL_43B4
	video offset=CINEMATIC_535, x=[0x21], y=[0x26]
	jmp DECREMENT_VAR22

LABEL_43B4:
	video offset=CINEMATIC_534, x=[0x21], y=[0x26]
	jmp DECREMENT_VAR22
LABEL_43BC:
	db 0x11

PROJECT_POS_BY_VAR04_OR_807B:
	mov [0x21], [HERO_X]
	mov [0x22], [HERO_Y]
	mov [0xF8], [0x04]
	jl [0xF8], 0x4000, LABEL_43D0
	call RESET_HERO_ACTION_KEEP_POS_4LSB

LABEL_43D0:
	and [0xF8], 0x003F
	sub [0x22], 0x0016
	jl [0xF8], 0x20, LABEL_43F5
	sub [0xF8], 0x0020
	sub [0x22], 0x0011
	sub [0x21], 0x0023
	jl [0xF8], 0x10, LABEL_4403
	add [0x21], 0x0042
	ret

LABEL_43F5:
	sub [0x21], 0x0021
	jl [0xF8], 0x10, LABEL_4403
	add [0x21], 0x003E

LABEL_4403:
	ret
LABEL_4404:
	db 0x11

PROJECT_POS_VAR04_OR_7E81:
	mov [0x21], [HERO_X]
	mov [0x22], [HERO_Y]
	mov [0xF8], [0x04]
	jl [0xF8], 0x4000, LABEL_4418
	call RESET_HERO_ACTION_KEEP_POS_4LSB

LABEL_4418:
	and [0xF8], 0x003F
	sub [0x22], 0x0016
	jl [0xF8], 0x20, LABEL_443D
	sub [0xF8], 0x0020
	sub [0x22], 0x0011
	sub [0x21], 0x0022
	jl [0xF8], 0x10, LABEL_444B
	add [0x21], 0x0041
	ret

LABEL_443D:
	sub [0x21], 0x0020
	jl [0xF8], 0x10, LABEL_444B
	add [0x21], 0x003D

LABEL_444B:
	ret
LABEL_444C:
	db 0x11

LABEL_444D:
	mov [0x0F], 0x0000
	jle [0x06], 0x00, DEDUP_CAVES_5B_003

LABEL_4457:
	break
	add [0x0F], 0x0001
	je [HERO_ACTION], 0x00, DEDUP_CAVES_5B_003
	jl [0x0F], 0x04, LABEL_4457
	call PROJECT_POS_VAR04_OR_7E81
	video offset=CINEMATIC_196, x=[0x21], y=[0x22]
	break
	call PROJECT_POS_VAR04_OR_7E81
	video offset=CINEMATIC_197, x=[0x21], y=[0x22]
	break
	call PROJECT_POS_VAR04_OR_7E81
	video offset=CINEMATIC_198, x=[0x21], y=[0x22]
	break
	call PROJECT_POS_VAR04_OR_7E81
	video offset=CINEMATIC_199, x=[0x21], y=[0x22]
	play id=0x005B, freq=0x14, vol=0x40, channel=0x00
	je [HERO_ACTION], 0x00, LABEL_4546
	jmp LABEL_44EB
LABEL_449A:
	db 0x11

LABEL_449B:
	mov [0x0F], 0x0000
	jle [0x06], 0x00, DEDUP_CAVES_5B_003

LABEL_44A5:
	break
	add [0x0F], 0x0001
	jne [HERO_POS_LEFT_RIGHT], 0x00, DEDUP_CAVES_5B_003
	je [HERO_ACTION], 0x00, DEDUP_CAVES_5B_003
	jl [0x0F], 0x04, LABEL_44A5
	call PROJECT_POS_VAR04_OR_7E81
	video offset=CINEMATIC_196, x=[0x21], y=[0x22]
	break
	call PROJECT_POS_VAR04_OR_7E81
	video offset=CINEMATIC_197, x=[0x21], y=[0x22]
	break
	call PROJECT_POS_VAR04_OR_7E81
	video offset=CINEMATIC_198, x=[0x21], y=[0x22]
	break
	call PROJECT_POS_VAR04_OR_7E81
	video offset=CINEMATIC_210, x=[0x21], y=[0x22]
	play id=0x005B, freq=0x14, vol=0x40, channel=0x00
	je [HERO_ACTION], 0x00, LABEL_4546

LABEL_44EB:
	break
	jne [HERO_POS_LEFT_RIGHT], 0x00, LABEL_453E
	je [HERO_ACTION], 0x00, LABEL_453E
	call PROJECT_POS_VAR04_OR_7E81
	video offset=CINEMATIC_202, x=[0x21], y=[0x22]
	break
	je [HERO_ACTION], 0x00, LABEL_453E
	call PROJECT_POS_VAR04_OR_7E81
	video offset=CINEMATIC_203, x=[0x21], y=[0x22]
	break
	je [HERO_ACTION], 0x00, LABEL_453E
	call PROJECT_POS_VAR04_OR_7E81
	video offset=CINEMATIC_204, x=[0x21], y=[0x22]
	break
	je [HERO_ACTION], 0x00, LABEL_453E
	call PROJECT_POS_VAR04_OR_7E81
	video offset=CINEMATIC_203, x=[0x21], y=[0x22]
	add [0x0F], 0x0004
	jl [0x0F], 0x14, LABEL_44EB
	break
	je [HERO_ACTION], 0x01, LABEL_4565

LABEL_453E:
	call PROJECT_POS_VAR04_OR_7E81
	video offset=CINEMATIC_201, x=[0x21], y=[HERO_Y]

LABEL_4546:
	break
	play id=0x0058, freq=0x14, vol=0x40, channel=0x00
	call PROJECT_POS_VAR04_OR_7E81
	video offset=CINEMATIC_200, x=[0x21], y=[HERO_Y]
	sub [0x06], 0x000A
	call LABEL_4123
	mov [0x0F], 0x0000
