LABEL_5139:
	db 0x11

LABEL_513A:
	jne [0x27], 0x03, LABEL_514C
	video offset=CINEMATIC_086, x=[0x21], y=[0x26]
	sub [0x22], 0x0001
	jmp DECREMENT_VAR22

LABEL_514C:
	jne [0x27], 0x01, LABEL_515A
	video offset=CINEMATIC_535, x=[0x21], y=[0x26]
	jmp DECREMENT_VAR22

LABEL_515A:
	video offset=CINEMATIC_534, x=[0x21], y=[0x26]
	jmp DECREMENT_VAR22
LABEL_5162:
	db 0x11

LABEL_5163:
	jne [0x27], 0x03, LABEL_5178
	video offset=CINEMATIC_533, x=[0x21], y=[0x26]
	call LABEL_5195
	sub [0x22], 0x0001
	jmp DECREMENT_VAR22

LABEL_5178:
	jne [0x27], 0x01, LABEL_5189
	video offset=CINEMATIC_532, x=[0x21], y=[0x26]
	call LABEL_5195
	jmp DECREMENT_VAR22

LABEL_5189:
	video offset=CINEMATIC_531, x=[0x21], y=[0x26]
	call LABEL_5195
	jmp DECREMENT_VAR22
LABEL_5194:
	db 0x11

LABEL_5195:
	jle [0x22], 0x96, SHARED_RET
	sub [0x21], 0x0002
	video offset=CINEMATIC_089, x=[0x21], y=[0x26]
	add [0x21], 0x0002
	jle [0x22], 0x012C, SHARED_RET
	add [0x21], 0x0002
	video offset=CINEMATIC_088, x=[0x21], y=[0x26]
	sub [0x21], 0x0002
	ret

LABEL_51BD:
	jne [0x27], 0x03, LABEL_51CF
	video offset=CINEMATIC_088, x=[0x21], y=[0x26]
	sub [0x22], 0x0001
	jmp DECREMENT_VAR22

LABEL_51CF:
	jne [0x27], 0x01, LABEL_51DD
	video offset=CINEMATIC_089, x=[0x21], y=[0x26]
	jmp DECREMENT_VAR22

LABEL_51DD:
	video offset=CINEMATIC_536, x=[0x21], y=[0x26]
	jmp DECREMENT_VAR22
LABEL_51E5:
	db 0x11

LABEL_51E6:
	jne [0x27], 0x03, LABEL_51F8
	video offset=CINEMATIC_091, x=[0x21], y=[0x26]
	sub [0x22], 0x0001
	jmp DECREMENT_VAR22

LABEL_51F8:
	jne [0x27], 0x01, LABEL_5206
	video offset=CINEMATIC_090, x=[0x21], y=[0x26]
	jmp DECREMENT_VAR22

LABEL_5206:
	video offset=CINEMATIC_087, x=[0x21], y=[0x26]
	jmp DECREMENT_VAR22
LABEL_520E:
	db 0x11

LABEL_520F:
	jne [0x27], 0x03, LABEL_5221
	video offset=CINEMATIC_539, x=[0x21], y=[0x26]
	sub [0x22], 0x0001
	jmp DECREMENT_VAR22

LABEL_5221:
	jne [0x27], 0x01, LABEL_522F
	video offset=CINEMATIC_538, x=[0x21], y=[0x26]
	jmp DECREMENT_VAR22

LABEL_522F:
	video offset=CINEMATIC_537, x=[0x21], y=[0x26]
	jmp DECREMENT_VAR22
LABEL_5237:
	db 0x11
