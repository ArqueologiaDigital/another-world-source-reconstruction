LABEL_71EF:
	db 0x11

LABEL_71F0:
	jne [0x27], 0x03, LABEL_7202
	video type=1, offset=CINEMATIC_152, x=[0x21], y=[0x26], zoom=0x40
	sub [0x22], 0x0001
	jmp DECREMENT_VAR22

LABEL_7202:
	jne [0x27], 0x01, LABEL_7210
	video type=1, offset=CINEMATIC_858, x=[0x21], y=[0x26], zoom=0x40
	jmp DECREMENT_VAR22

LABEL_7210:
	video type=1, offset=CINEMATIC_857, x=[0x21], y=[0x26], zoom=0x40
	jmp DECREMENT_VAR22
LABEL_7218:
	db 0x11

LABEL_7219:
	jne [0x27], 0x03, LABEL_722E
	video type=1, offset=CINEMATIC_856, x=[0x21], y=[0x26], zoom=0x40
	call LABEL_724B
	sub [0x22], 0x0001
	jmp DECREMENT_VAR22

LABEL_722E:
	jne [0x27], 0x01, LABEL_723F
	video type=1, offset=CINEMATIC_855, x=[0x21], y=[0x26], zoom=0x40
	call LABEL_724B
	jmp DECREMENT_VAR22

LABEL_723F:
	video type=1, offset=CINEMATIC_854, x=[0x21], y=[0x26], zoom=0x40
	call LABEL_724B
	jmp DECREMENT_VAR22
LABEL_724A:
	db 0x11

LABEL_724B:
	jle [0x22], 0x96, SHARED_RET
	sub [0x21], 0x0002
	video type=1, offset=CINEMATIC_155, x=[0x21], y=[0x26], zoom=0x40
	add [0x21], 0x0002
	jle [0x22], 0x012C, SHARED_RET
	add [0x21], 0x0002
	video type=1, offset=CINEMATIC_154, x=[0x21], y=[0x26], zoom=0x40
	sub [0x21], 0x0002
	ret

LABEL_7273:
	jne [0x27], 0x03, LABEL_7285
	video type=1, offset=CINEMATIC_154, x=[0x21], y=[0x26], zoom=0x40
	sub [0x22], 0x0001
	jmp DECREMENT_VAR22

LABEL_7285:
	jne [0x27], 0x01, LABEL_7293
	video type=1, offset=CINEMATIC_155, x=[0x21], y=[0x26], zoom=0x40
	jmp DECREMENT_VAR22

LABEL_7293:
	video type=1, offset=CINEMATIC_859, x=[0x21], y=[0x26], zoom=0x40
	jmp DECREMENT_VAR22
LABEL_729B:
	db 0x11

LABEL_729C:
	jne [0x27], 0x03, LABEL_72AE
	video type=1, offset=CINEMATIC_157, x=[0x21], y=[0x26], zoom=0x40
	sub [0x22], 0x0001
	jmp DECREMENT_VAR22

LABEL_72AE:
	jne [0x27], 0x01, LABEL_72BC
	video type=1, offset=CINEMATIC_156, x=[0x21], y=[0x26], zoom=0x40
	jmp DECREMENT_VAR22

LABEL_72BC:
	video type=1, offset=CINEMATIC_153, x=[0x21], y=[0x26], zoom=0x40
	jmp DECREMENT_VAR22
LABEL_72C4:
	db 0x11

LABEL_72C5:
	jne [0x27], 0x03, LABEL_72D7
	video type=1, offset=CINEMATIC_862, x=[0x21], y=[0x26], zoom=0x40
	sub [0x22], 0x0001
	jmp DECREMENT_VAR22

LABEL_72D7:
	jne [0x27], 0x01, LABEL_72E5
	video type=1, offset=CINEMATIC_861, x=[0x21], y=[0x26], zoom=0x40
	jmp DECREMENT_VAR22

LABEL_72E5:
	video type=1, offset=CINEMATIC_860, x=[0x21], y=[0x26], zoom=0x40
	jmp DECREMENT_VAR22
LABEL_72ED:
	db 0x11
