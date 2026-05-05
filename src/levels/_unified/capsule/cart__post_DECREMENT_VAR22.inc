LABEL_68B4:
	db 0x11

LABEL_68B5:
	jne [0x27], 0x03, LABEL_68C7
	video offset=CINEMATIC_052, x=[0x21], y=[0x26], zoom=0x40
	sub [0x22], 0x0001
	jmp DECREMENT_VAR22

LABEL_68C7:
	jne [0x27], 0x01, LABEL_68D5
	video offset=CINEMATIC_690, x=[0x21], y=[0x26], zoom=0x40
	jmp DECREMENT_VAR22

LABEL_68D5:
	video offset=CINEMATIC_689, x=[0x21], y=[0x26], zoom=0x40
	jmp DECREMENT_VAR22
LABEL_68DD:
	db 0x11

LABEL_68DE:
	jne [0x27], 0x03, LABEL_68F3
	video offset=CINEMATIC_688, x=[0x21], y=[0x26], zoom=0x40
	call LABEL_6910
	sub [0x22], 0x0001
	jmp DECREMENT_VAR22

LABEL_68F3:
	jne [0x27], 0x01, LABEL_6904
	video offset=CINEMATIC_687, x=[0x21], y=[0x26], zoom=0x40
	call LABEL_6910
	jmp DECREMENT_VAR22

LABEL_6904:
	video offset=CINEMATIC_686, x=[0x21], y=[0x26], zoom=0x40
	call LABEL_6910
	jmp DECREMENT_VAR22
LABEL_690F:
	db 0x11

LABEL_6910:
	jle [0x22], 0x96, SHARED_RET
	sub [0x21], 0x0002
	video offset=CINEMATIC_055, x=[0x21], y=[0x26], zoom=0x40
	add [0x21], 0x0002
	jle [0x22], 0x012C, SHARED_RET
	add [0x21], 0x0002
	video offset=CINEMATIC_054, x=[0x21], y=[0x26], zoom=0x40
	sub [0x21], 0x0002
	ret

LABEL_6938:
	jne [0x27], 0x03, LABEL_694A
	video offset=CINEMATIC_054, x=[0x21], y=[0x26], zoom=0x40
	sub [0x22], 0x0001
	jmp DECREMENT_VAR22

LABEL_694A:
	jne [0x27], 0x01, LABEL_6958
	video offset=CINEMATIC_055, x=[0x21], y=[0x26], zoom=0x40
	jmp DECREMENT_VAR22

LABEL_6958:
	video offset=CINEMATIC_691, x=[0x21], y=[0x26], zoom=0x40
	jmp DECREMENT_VAR22
LABEL_6960:
	db 0x11

LABEL_6961:
	jne [0x27], 0x03, LABEL_6973
	video offset=CINEMATIC_057, x=[0x21], y=[0x26], zoom=0x40
	sub [0x22], 0x0001
	jmp DECREMENT_VAR22

LABEL_6973:
	jne [0x27], 0x01, LABEL_6981
	video offset=CINEMATIC_056, x=[0x21], y=[0x26], zoom=0x40
	jmp DECREMENT_VAR22

LABEL_6981:
	video offset=CINEMATIC_053, x=[0x21], y=[0x26], zoom=0x40
	jmp DECREMENT_VAR22
LABEL_6989:
	db 0x11

LABEL_698A:
	jne [0x27], 0x03, LABEL_699C
	video offset=CINEMATIC_694, x=[0x21], y=[0x26], zoom=0x40
	sub [0x22], 0x0001
	jmp DECREMENT_VAR22

LABEL_699C:
	jne [0x27], 0x01, LABEL_69AA
	video offset=CINEMATIC_693, x=[0x21], y=[0x26], zoom=0x40
	jmp DECREMENT_VAR22

LABEL_69AA:
	video offset=CINEMATIC_692, x=[0x21], y=[0x26], zoom=0x40
	jmp DECREMENT_VAR22
LABEL_69B2:
	db 0x11
