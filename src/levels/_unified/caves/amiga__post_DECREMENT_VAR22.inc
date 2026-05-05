LABEL_6FA8:
	db 0x11

LABEL_6FA9:
	jne [0x27], 0x03, LABEL_6FBB
	video offset=CINEMATIC_152, x=[0x21], y=[0x26]
	sub [0x22], 0x0001
	jmp DECREMENT_VAR22

LABEL_6FBB:
	jne [0x27], 0x01, LABEL_6FC9
	video offset=CINEMATIC_844, x=[0x21], y=[0x26]
	jmp DECREMENT_VAR22

LABEL_6FC9:
	video offset=CINEMATIC_843, x=[0x21], y=[0x26]
	jmp DECREMENT_VAR22
LABEL_6FD1:
	db 0x11

LABEL_6FD2:
	jne [0x27], 0x03, LABEL_6FE7
	video offset=CINEMATIC_842, x=[0x21], y=[0x26]
	call LABEL_7004
	sub [0x22], 0x0001
	jmp DECREMENT_VAR22

LABEL_6FE7:
	jne [0x27], 0x01, LABEL_6FF8
	video offset=CINEMATIC_841, x=[0x21], y=[0x26]
	call LABEL_7004
	jmp DECREMENT_VAR22

LABEL_6FF8:
	video offset=CINEMATIC_840, x=[0x21], y=[0x26]
	call LABEL_7004
	jmp DECREMENT_VAR22
LABEL_7003:
	db 0x11

LABEL_7004:
	jle [0x22], 0x96, SHARED_RET
	sub [0x21], 0x0002
	video offset=CINEMATIC_155, x=[0x21], y=[0x26]
	add [0x21], 0x0002
	jle [0x22], 0x012C, SHARED_RET
	add [0x21], 0x0002
	video offset=CINEMATIC_154, x=[0x21], y=[0x26]
	sub [0x21], 0x0002
	ret

LABEL_702C:
	jne [0x27], 0x03, LABEL_703E
	video offset=CINEMATIC_154, x=[0x21], y=[0x26]
	sub [0x22], 0x0001
	jmp DECREMENT_VAR22

LABEL_703E:
	jne [0x27], 0x01, LABEL_704C
	video offset=CINEMATIC_155, x=[0x21], y=[0x26]
	jmp DECREMENT_VAR22

LABEL_704C:
	video offset=CINEMATIC_845, x=[0x21], y=[0x26]
	jmp DECREMENT_VAR22
LABEL_7054:
	db 0x11

LABEL_7055:
	jne [0x27], 0x03, LABEL_7067
	video offset=CINEMATIC_157, x=[0x21], y=[0x26]
	sub [0x22], 0x0001
	jmp DECREMENT_VAR22

LABEL_7067:
	jne [0x27], 0x01, LABEL_7075
	video offset=CINEMATIC_156, x=[0x21], y=[0x26]
	jmp DECREMENT_VAR22

LABEL_7075:
	video offset=CINEMATIC_153, x=[0x21], y=[0x26]
	jmp DECREMENT_VAR22
LABEL_707D:
	db 0x11

LABEL_707E:
	jne [0x27], 0x03, LABEL_7090
	video offset=CINEMATIC_848, x=[0x21], y=[0x26]
	sub [0x22], 0x0001
	jmp DECREMENT_VAR22

LABEL_7090:
	jne [0x27], 0x01, LABEL_709E
	video offset=CINEMATIC_847, x=[0x21], y=[0x26]
	jmp DECREMENT_VAR22

LABEL_709E:
	video offset=CINEMATIC_846, x=[0x21], y=[0x26]
	jmp DECREMENT_VAR22
LABEL_70A6:
	db 0x11
