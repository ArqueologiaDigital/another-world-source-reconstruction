LABEL_441A:
	db 0x11

LABEL_441B:
	jne [0x27], 0x03, LABEL_442D
	video offset=CINEMATIC_524, x=[0x21], y=[0x26]
	sub [0x22], 0x0001
	jmp DECREMENT_VAR22

LABEL_442D:
	jne [0x27], 0x01, LABEL_443B
	video offset=CINEMATIC_528, x=[0x21], y=[0x26]
	jmp DECREMENT_VAR22

LABEL_443B:
	video offset=CINEMATIC_527, x=[0x21], y=[0x26]
	jmp DECREMENT_VAR22
LABEL_4443:
	db 0x11

LABEL_4444:
	jne [0x27], 0x03, LABEL_4459
	video offset=CINEMATIC_526, x=[0x21], y=[0x26]
	call LABEL_4476
	sub [0x22], 0x0001
	jmp DECREMENT_VAR22

LABEL_4459:
	jne [0x27], 0x01, LABEL_446A
	video offset=CINEMATIC_525, x=[0x21], y=[0x26]
	call LABEL_4476
	jmp DECREMENT_VAR22

LABEL_446A:
	video offset=CINEMATIC_522, x=[0x21], y=[0x26]
	call LABEL_4476
	jmp DECREMENT_VAR22
LABEL_4475:
	db 0x11

LABEL_4476:
	jle [0x22], 0x96, SHARED_RET
	sub [0x21], 0x0002
	video offset=CINEMATIC_523, x=[0x21], y=[0x26]
	add [0x21], 0x0002
	jle [0x22], 0x012C, SHARED_RET
	add [0x21], 0x0002
	video offset=CINEMATIC_524, x=[0x21], y=[0x26]
	sub [0x21], 0x0002
	ret

LABEL_449E:
	jne [0x27], 0x03, LABEL_44B0
	video offset=CINEMATIC_530, x=[0x21], y=[0x26]
	sub [0x22], 0x0001
	jmp DECREMENT_VAR22

LABEL_44B0:
	jne [0x27], 0x01, LABEL_44BE
	video offset=CINEMATIC_523, x=[0x21], y=[0x26]
	jmp DECREMENT_VAR22

LABEL_44BE:
	video offset=CINEMATIC_529, x=[0x21], y=[0x26]
	jmp DECREMENT_VAR22
LABEL_44C6:
	db 0x11

LABEL_44C7:
	jne [0x27], 0x03, LABEL_44D9
	video offset=CINEMATIC_533, x=[0x21], y=[0x26]
	sub [0x22], 0x0001
	jmp DECREMENT_VAR22

LABEL_44D9:
	jne [0x27], 0x01, LABEL_44E7
	video offset=CINEMATIC_532, x=[0x21], y=[0x26]
	jmp DECREMENT_VAR22

LABEL_44E7:
	video offset=CINEMATIC_531, x=[0x21], y=[0x26]
	jmp DECREMENT_VAR22
LABEL_44EF:
	db 0x11

LABEL_44F0:
	jne [0x27], 0x03, LABEL_4502
	video offset=CINEMATIC_536, x=[0x21], y=[0x26]
	sub [0x22], 0x0001
	jmp DECREMENT_VAR22

LABEL_4502:
	jne [0x27], 0x01, LABEL_4510
	video offset=CINEMATIC_535, x=[0x21], y=[0x26]
	jmp DECREMENT_VAR22

LABEL_4510:
	video offset=CINEMATIC_534, x=[0x21], y=[0x26]
	jmp DECREMENT_VAR22
LABEL_4518:
	db 0x11

PROJECT_POS_VAR04_OR_7F4C:
	mov [0x21], [HERO_X]
	mov [0x22], [HERO_Y]
	mov [0xF8], [0x04]
	jl [0xF8], 0x4000, LABEL_452C
	call RESET_HERO_ACTION_KEEP_POS_4LSB

LABEL_452C:
	and [0xF8], 0x003F
	sub [0x22], 0x0016
	jl [0xF8], 0x20, LABEL_4551
	sub [0xF8], 0x0020
	sub [0x22], 0x0011
	sub [0x21], 0x0023
	jl [0xF8], 0x10, LABEL_455F
	add [0x21], 0x0042
	ret

LABEL_4551:
	sub [0x21], 0x0021
	jl [0xF8], 0x10, LABEL_455F
	add [0x21], 0x003E

LABEL_455F:
	ret
LABEL_4560:
	db 0x11

PROJECT_POS_BY_VAR04_OR_807B:
	mov [0x21], [HERO_X]
	mov [0x22], [HERO_Y]
	mov [0xF8], [0x04]
	jl [0xF8], 0x4000, LABEL_4574
	call RESET_HERO_ACTION_KEEP_POS_4LSB

LABEL_4574:
	and [0xF8], 0x003F
	sub [0x22], 0x0016
	jl [0xF8], 0x20, LABEL_4599
	sub [0xF8], 0x0020
	sub [0x22], 0x0011
	sub [0x21], 0x0022
	jl [0xF8], 0x10, LABEL_45A7
	add [0x21], 0x0041
	ret

LABEL_4599:
	sub [0x21], 0x0020
	jl [0xF8], 0x10, LABEL_45A7
	add [0x21], 0x003D

LABEL_45A7:
	ret
LABEL_45A8:
	db 0x11

LABEL_45A9:
	mov [0x0F], 0x0000
	jle [0x06], 0x00, DEDUP_CAVES_5B_003

LABEL_45B3:
	break
	add [0x0F], 0x0001
	je [HERO_ACTION], 0x00, DEDUP_CAVES_5B_003
	je [HERO_POS_JUMP_DOWN], 0xFFFF, DEDUP_CAVES_5B_003
	jl [0x0F], 0x04, LABEL_45B3
	call PROJECT_POS_BY_VAR04_OR_807B
	video offset=CINEMATIC_196, x=[0x21], y=[0x22]
	break
	call PROJECT_POS_BY_VAR04_OR_807B
	video offset=CINEMATIC_197, x=[0x21], y=[0x22]
	break
	call PROJECT_POS_BY_VAR04_OR_807B
	video offset=CINEMATIC_198, x=[0x21], y=[0x22]
	break
	call PROJECT_POS_BY_VAR04_OR_807B
	video offset=CINEMATIC_199, x=[0x21], y=[0x22]
	play id=0x005B, freq=0x14, vol=0x40, channel=0x00
	je [HERO_POS_JUMP_DOWN], 0xFFFF, DEDUP_CAVES_5B_003
	je [HERO_ACTION], 0x00, LABEL_46C5
	jmp LABEL_4663
LABEL_4604:
	db 0x11

LABEL_4605:
	mov [0x0F], 0x0000
	jle [0x06], 0x00, DEDUP_CAVES_5B_003

LABEL_460F:
	break
	add [0x0F], 0x0001
	jne [HERO_POS_LEFT_RIGHT], 0x00, DEDUP_CAVES_5B_003
	je [HERO_ACTION], 0x00, DEDUP_CAVES_5B_003
	je [HERO_POS_JUMP_DOWN], 0xFFFF, DEDUP_CAVES_5B_003
	jl [0x0F], 0x04, LABEL_460F
	call PROJECT_POS_BY_VAR04_OR_807B
	video offset=CINEMATIC_196, x=[0x21], y=[0x22]
	break
	call PROJECT_POS_BY_VAR04_OR_807B
	video offset=CINEMATIC_197, x=[0x21], y=[0x22]
	break
	call PROJECT_POS_BY_VAR04_OR_807B
	video offset=CINEMATIC_198, x=[0x21], y=[0x22]
	break
	call PROJECT_POS_BY_VAR04_OR_807B
	video offset=CINEMATIC_210, x=[0x21], y=[0x22]
	play id=0x005B, freq=0x14, vol=0x40, channel=0x00
	je [HERO_POS_JUMP_DOWN], 0xFFFF, DEDUP_CAVES_5B_003
	je [HERO_ACTION], 0x00, LABEL_46C5

LABEL_4663:
	break
	jne [HERO_POS_LEFT_RIGHT], 0x00, LABEL_46BD
	je [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_46BD
	je [HERO_ACTION], 0x00, LABEL_46BD
	call PROJECT_POS_BY_VAR04_OR_807B
	video offset=CINEMATIC_202, x=[0x21], y=[0x22]
	break
	je [HERO_ACTION], 0x00, LABEL_46BD
	call PROJECT_POS_BY_VAR04_OR_807B
	video offset=CINEMATIC_203, x=[0x21], y=[0x22]
	break
	je [HERO_ACTION], 0x00, LABEL_46BD
	call PROJECT_POS_BY_VAR04_OR_807B
	video offset=CINEMATIC_204, x=[0x21], y=[0x22]
	break
	je [HERO_ACTION], 0x00, LABEL_46BD
	call PROJECT_POS_BY_VAR04_OR_807B
	video offset=CINEMATIC_203, x=[0x21], y=[0x22]
	add [0x0F], 0x0004
	jl [0x0F], 0x14, LABEL_4663
	break
	je [HERO_ACTION], 0x01, LABEL_46E4

LABEL_46BD:
	call PROJECT_POS_BY_VAR04_OR_807B
	video offset=CINEMATIC_201, x=[0x21], y=[HERO_Y]

LABEL_46C5:
	break
	play id=0x0058, freq=0x14, vol=0x40, channel=0x00
	call PROJECT_POS_BY_VAR04_OR_807B
	video offset=CINEMATIC_200, x=[0x21], y=[HERO_Y]
	sub [0x06], 0x000A
	call LABEL_427F
	mov [0x0F], 0x0000
