LABEL_4320:
	db 0x11

LABEL_4321:
	jne [0x27], 0x03, LABEL_4333
	video offset=CINEMATIC_524, x=[0x21], y=[0x26]
	sub [0x22], 0x0001
	jmp DECREMENT_VAR22

LABEL_4333:
	jne [0x27], 0x01, LABEL_4341
	video offset=CINEMATIC_528, x=[0x21], y=[0x26]
	jmp DECREMENT_VAR22

LABEL_4341:
	video offset=CINEMATIC_527, x=[0x21], y=[0x26]
	jmp DECREMENT_VAR22
LABEL_4349:
	db 0x11

LABEL_434A:
	jne [0x27], 0x03, LABEL_435F
	video offset=CINEMATIC_526, x=[0x21], y=[0x26]
	call LABEL_437C
	sub [0x22], 0x0001
	jmp DECREMENT_VAR22

LABEL_435F:
	jne [0x27], 0x01, LABEL_4370
	video offset=CINEMATIC_525, x=[0x21], y=[0x26]
	call LABEL_437C
	jmp DECREMENT_VAR22

LABEL_4370:
	video offset=CINEMATIC_522, x=[0x21], y=[0x26]
	call LABEL_437C
	jmp DECREMENT_VAR22
LABEL_437B:
	db 0x11

LABEL_437C:
	jle [0x22], 0x96, SHARED_RET
	sub [0x21], 0x0002
	video offset=CINEMATIC_523, x=[0x21], y=[0x26]
	add [0x21], 0x0002
	jle [0x22], 0x012C, SHARED_RET
	add [0x21], 0x0002
	video offset=CINEMATIC_524, x=[0x21], y=[0x26]
	sub [0x21], 0x0002
	ret

LABEL_43A4:
	jne [0x27], 0x03, LABEL_43B6
	video offset=CINEMATIC_530, x=[0x21], y=[0x26]
	sub [0x22], 0x0001
	jmp DECREMENT_VAR22

LABEL_43B6:
	jne [0x27], 0x01, LABEL_43C4
	video offset=CINEMATIC_523, x=[0x21], y=[0x26]
	jmp DECREMENT_VAR22

LABEL_43C4:
	video offset=CINEMATIC_529, x=[0x21], y=[0x26]
	jmp DECREMENT_VAR22
LABEL_43CC:
	db 0x11

LABEL_43CD:
	jne [0x27], 0x03, LABEL_43DF
	video offset=CINEMATIC_533, x=[0x21], y=[0x26]
	sub [0x22], 0x0001
	jmp DECREMENT_VAR22

LABEL_43DF:
	jne [0x27], 0x01, LABEL_43ED
	video offset=CINEMATIC_532, x=[0x21], y=[0x26]
	jmp DECREMENT_VAR22

LABEL_43ED:
	video offset=CINEMATIC_531, x=[0x21], y=[0x26]
	jmp DECREMENT_VAR22
LABEL_43F5:
	db 0x11

LABEL_43F6:
	jne [0x27], 0x03, LABEL_4408
	video offset=CINEMATIC_536, x=[0x21], y=[0x26]
	sub [0x22], 0x0001
	jmp DECREMENT_VAR22

LABEL_4408:
	jne [0x27], 0x01, LABEL_4416
	video offset=CINEMATIC_535, x=[0x21], y=[0x26]
	jmp DECREMENT_VAR22

LABEL_4416:
	video offset=CINEMATIC_534, x=[0x21], y=[0x26]
	jmp DECREMENT_VAR22
LABEL_441E:
	db 0x11

PROJECT_POS_BY_VAR04_OR_807B:
	mov [0x21], [0x01]
	mov [0x22], [0x02]
	mov [0xF8], [0x04]
	jl [0xF8], 0x4000, LABEL_4432
	call RESET_HERO_ACTION_KEEP_POS_4LSB

LABEL_4432:
	and [0xF8], 0x003F
	sub [0x22], 0x0016
	jl [0xF8], 0x20, LABEL_4457
	sub [0xF8], 0x0020
	sub [0x22], 0x0011
	sub [0x21], 0x0023
	jl [0xF8], 0x10, LABEL_4465
	add [0x21], 0x0042
	ret

LABEL_4457:
	sub [0x21], 0x0021
	jl [0xF8], 0x10, LABEL_4465
	add [0x21], 0x003E

LABEL_4465:
	ret
LABEL_4466:
	db 0x11

PROJECT_POS_VAR04_OR_7F4C:
	mov [0x21], [0x01]
	mov [0x22], [0x02]
	mov [0xF8], [0x04]
	jl [0xF8], 0x4000, LABEL_447A
	call RESET_HERO_ACTION_KEEP_POS_4LSB

LABEL_447A:
	and [0xF8], 0x003F
	sub [0x22], 0x0016
	jl [0xF8], 0x20, LABEL_449F
	sub [0xF8], 0x0020
	sub [0x22], 0x0011
	sub [0x21], 0x0022
	jl [0xF8], 0x10, LABEL_44AD
	add [0x21], 0x0041
	ret

LABEL_449F:
	sub [0x21], 0x0020
	jl [0xF8], 0x10, LABEL_44AD
	add [0x21], 0x003D

LABEL_44AD:
	ret
LABEL_44AE:
	db 0x11

LABEL_44AF:
	mov [0x0F], 0x0000
	jle [0x06], 0x00, DEDUP_CAVES_5B_003

LABEL_44B9:
	break
	add [0x0F], 0x0001
	je [HERO_ACTION], 0x00, DEDUP_CAVES_5B_003
	je [HERO_POS_JUMP_DOWN], 0xFFFF, DEDUP_CAVES_5B_003
	jl [0x0F], 0x04, LABEL_44B9
	call PROJECT_POS_VAR04_OR_7F4C
	video offset=CINEMATIC_196, x=[0x21], y=[0x22]
	break
	call PROJECT_POS_VAR04_OR_7F4C
	video offset=CINEMATIC_197, x=[0x21], y=[0x22]
	break
	call PROJECT_POS_VAR04_OR_7F4C
	video offset=CINEMATIC_198, x=[0x21], y=[0x22]
	break
	call PROJECT_POS_VAR04_OR_7F4C
	video offset=CINEMATIC_199, x=[0x21], y=[0x22]
	play id=0x005B, freq=0x14, vol=0x40, channel=0x00
	je [HERO_POS_JUMP_DOWN], 0xFFFF, DEDUP_CAVES_5B_003
	je [HERO_ACTION], 0x00, LABEL_45CB
	jmp LABEL_4569
LABEL_450A:
	db 0x11

LABEL_450B:
	mov [0x0F], 0x0000
	jle [0x06], 0x00, DEDUP_CAVES_5B_003

LABEL_4515:
	break
	add [0x0F], 0x0001
	jne [HERO_POS_LEFT_RIGHT], 0x00, DEDUP_CAVES_5B_003
	je [HERO_ACTION], 0x00, DEDUP_CAVES_5B_003
	je [HERO_POS_JUMP_DOWN], 0xFFFF, DEDUP_CAVES_5B_003
	jl [0x0F], 0x04, LABEL_4515
	call PROJECT_POS_VAR04_OR_7F4C
	video offset=CINEMATIC_196, x=[0x21], y=[0x22]
	break
	call PROJECT_POS_VAR04_OR_7F4C
	video offset=CINEMATIC_197, x=[0x21], y=[0x22]
	break
	call PROJECT_POS_VAR04_OR_7F4C
	video offset=CINEMATIC_198, x=[0x21], y=[0x22]
	break
	call PROJECT_POS_VAR04_OR_7F4C
	video offset=CINEMATIC_210, x=[0x21], y=[0x22]
	play id=0x005B, freq=0x14, vol=0x40, channel=0x00
	je [HERO_POS_JUMP_DOWN], 0xFFFF, DEDUP_CAVES_5B_003
	je [HERO_ACTION], 0x00, LABEL_45CB

LABEL_4569:
	break
	jne [HERO_POS_LEFT_RIGHT], 0x00, LABEL_45C3
	je [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_45C3
	je [HERO_ACTION], 0x00, LABEL_45C3
	call PROJECT_POS_VAR04_OR_7F4C
	video offset=CINEMATIC_202, x=[0x21], y=[0x22]
	break
	je [HERO_ACTION], 0x00, LABEL_45C3
	call PROJECT_POS_VAR04_OR_7F4C
	video offset=CINEMATIC_203, x=[0x21], y=[0x22]
	break
	je [HERO_ACTION], 0x00, LABEL_45C3
	call PROJECT_POS_VAR04_OR_7F4C
	video offset=CINEMATIC_204, x=[0x21], y=[0x22]
	break
	je [HERO_ACTION], 0x00, LABEL_45C3
	call PROJECT_POS_VAR04_OR_7F4C
	video offset=CINEMATIC_203, x=[0x21], y=[0x22]
	add [0x0F], 0x0004
	jl [0x0F], 0x14, LABEL_4569
	break
	je [HERO_ACTION], 0x01, LABEL_45EA

LABEL_45C3:
	call PROJECT_POS_VAR04_OR_7F4C
	video offset=CINEMATIC_201, x=[0x21], y=[0x02]

LABEL_45CB:
	break
	play id=0x0058, freq=0x14, vol=0x40, channel=0x00
	call PROJECT_POS_VAR04_OR_7F4C
	video offset=CINEMATIC_200, x=[0x21], y=[0x02]
	sub [0x06], 0x000A
	call LABEL_4185
	mov [0x0F], 0x0000
