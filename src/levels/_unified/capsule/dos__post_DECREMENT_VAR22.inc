LABEL_68AB:
	db 0x11

LABEL_68AC:
	jne [0x27], 0x03, LABEL_68BE
	video offset=CINEMATIC_052, x=[0x21], y=[0x26], zoom=0x40
	sub [0x22], 0x0001
	jmp DECREMENT_VAR22

LABEL_68BE:
	jne [0x27], 0x01, LABEL_68CC
	video offset=CINEMATIC_681, x=[0x21], y=[0x26], zoom=0x40
	jmp DECREMENT_VAR22

LABEL_68CC:
	video offset=CINEMATIC_680, x=[0x21], y=[0x26], zoom=0x40
	jmp DECREMENT_VAR22
LABEL_68D4:
	db 0x11

LABEL_68D5:
	jne [0x27], 0x03, LABEL_68EA
	video offset=CINEMATIC_679, x=[0x21], y=[0x26], zoom=0x40
	call LABEL_6907
	sub [0x22], 0x0001
	jmp DECREMENT_VAR22

LABEL_68EA:
	jne [0x27], 0x01, LABEL_68FB
	video offset=CINEMATIC_678, x=[0x21], y=[0x26], zoom=0x40
	call LABEL_6907
	jmp DECREMENT_VAR22

LABEL_68FB:
	video offset=CINEMATIC_677, x=[0x21], y=[0x26], zoom=0x40
	call LABEL_6907
	jmp DECREMENT_VAR22
LABEL_6906:
	db 0x11

LABEL_6907:
	jle [0x22], 0x96, SHARED_RET
	sub [0x21], 0x0002
	video offset=CINEMATIC_055, x=[0x21], y=[0x26], zoom=0x40
	add [0x21], 0x0002
	jle [0x22], 0x012C, SHARED_RET
	add [0x21], 0x0002
	video offset=CINEMATIC_054, x=[0x21], y=[0x26], zoom=0x40
	sub [0x21], 0x0002
	ret

LABEL_692F:
	jne [0x27], 0x03, LABEL_6941
	video offset=CINEMATIC_054, x=[0x21], y=[0x26], zoom=0x40
	sub [0x22], 0x0001
	jmp DECREMENT_VAR22

LABEL_6941:
	jne [0x27], 0x01, LABEL_694F
	video offset=CINEMATIC_055, x=[0x21], y=[0x26], zoom=0x40
	jmp DECREMENT_VAR22

LABEL_694F:
	video offset=CINEMATIC_682, x=[0x21], y=[0x26], zoom=0x40
	jmp DECREMENT_VAR22
LABEL_6957:
	db 0x11

LABEL_6958:
	jne [0x27], 0x03, LABEL_696A
	video offset=CINEMATIC_057, x=[0x21], y=[0x26], zoom=0x40
	sub [0x22], 0x0001
	jmp DECREMENT_VAR22

LABEL_696A:
	jne [0x27], 0x01, LABEL_6978
	video offset=CINEMATIC_056, x=[0x21], y=[0x26], zoom=0x40
	jmp DECREMENT_VAR22

LABEL_6978:
	video offset=CINEMATIC_053, x=[0x21], y=[0x26], zoom=0x40
	jmp DECREMENT_VAR22
LABEL_6980:
	db 0x11

LABEL_6981:
	jne [0x27], 0x03, LABEL_6993
	video offset=CINEMATIC_685, x=[0x21], y=[0x26], zoom=0x40
	sub [0x22], 0x0001
	jmp DECREMENT_VAR22

LABEL_6993:
	jne [0x27], 0x01, LABEL_69A1
	video offset=CINEMATIC_684, x=[0x21], y=[0x26], zoom=0x40
	jmp DECREMENT_VAR22

LABEL_69A1:
	video offset=CINEMATIC_683, x=[0x21], y=[0x26], zoom=0x40
	jmp DECREMENT_VAR22
LABEL_69A9:
	db 0x11
