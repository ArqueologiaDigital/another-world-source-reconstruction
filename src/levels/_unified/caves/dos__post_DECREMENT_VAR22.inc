LABEL_72C2:
	db 0x11

LABEL_72C3:
	jne [0x27], 0x03, LABEL_72D5
	video type=1, offset=CINEMATIC_152, x=[0x21], y=[0x26], zoom=0x40
	sub [0x22], 0x0001
	jmp DECREMENT_VAR22

LABEL_72D5:
	jne [0x27], 0x01, LABEL_72E3
	video type=1, offset=CINEMATIC_867, x=[0x21], y=[0x26], zoom=0x40
	jmp DECREMENT_VAR22

LABEL_72E3:
	video type=1, offset=CINEMATIC_866, x=[0x21], y=[0x26], zoom=0x40
	jmp DECREMENT_VAR22
LABEL_72EB:
	db 0x11

LABEL_72EC:
	jne [0x27], 0x03, LABEL_7301
	video type=1, offset=CINEMATIC_865, x=[0x21], y=[0x26], zoom=0x40
	call LABEL_731E
	sub [0x22], 0x0001
	jmp DECREMENT_VAR22

LABEL_7301:
	jne [0x27], 0x01, LABEL_7312
	video type=1, offset=CINEMATIC_864, x=[0x21], y=[0x26], zoom=0x40
	call LABEL_731E
	jmp DECREMENT_VAR22

LABEL_7312:
	video type=1, offset=CINEMATIC_863, x=[0x21], y=[0x26], zoom=0x40
	call LABEL_731E
	jmp DECREMENT_VAR22
LABEL_731D:
	db 0x11

LABEL_731E:
	jle [0x22], 0x96, SHARED_RET
	sub [0x21], 0x0002
	video type=1, offset=CINEMATIC_155, x=[0x21], y=[0x26], zoom=0x40
	add [0x21], 0x0002
	jle [0x22], 0x012C, SHARED_RET
	add [0x21], 0x0002
	video type=1, offset=CINEMATIC_154, x=[0x21], y=[0x26], zoom=0x40
	sub [0x21], 0x0002
	ret

LABEL_7346:
	jne [0x27], 0x03, LABEL_7358
	video type=1, offset=CINEMATIC_154, x=[0x21], y=[0x26], zoom=0x40
	sub [0x22], 0x0001
	jmp DECREMENT_VAR22

LABEL_7358:
	jne [0x27], 0x01, LABEL_7366
	video type=1, offset=CINEMATIC_155, x=[0x21], y=[0x26], zoom=0x40
	jmp DECREMENT_VAR22

LABEL_7366:
	video type=1, offset=CINEMATIC_868, x=[0x21], y=[0x26], zoom=0x40
	jmp DECREMENT_VAR22
LABEL_736E:
	db 0x11

LABEL_736F:
	jne [0x27], 0x03, LABEL_7381
	video type=1, offset=CINEMATIC_157, x=[0x21], y=[0x26], zoom=0x40
	sub [0x22], 0x0001
	jmp DECREMENT_VAR22

LABEL_7381:
	jne [0x27], 0x01, LABEL_738F
	video type=1, offset=CINEMATIC_156, x=[0x21], y=[0x26], zoom=0x40
	jmp DECREMENT_VAR22

LABEL_738F:
	video type=1, offset=CINEMATIC_153, x=[0x21], y=[0x26], zoom=0x40
	jmp DECREMENT_VAR22
LABEL_7397:
	db 0x11

LABEL_7398:
	jne [0x27], 0x03, LABEL_73AA
	video type=1, offset=CINEMATIC_871, x=[0x21], y=[0x26], zoom=0x40
	sub [0x22], 0x0001
	jmp DECREMENT_VAR22

LABEL_73AA:
	jne [0x27], 0x01, LABEL_73B8
	video type=1, offset=CINEMATIC_870, x=[0x21], y=[0x26], zoom=0x40
	jmp DECREMENT_VAR22

LABEL_73B8:
	video type=1, offset=CINEMATIC_869, x=[0x21], y=[0x26], zoom=0x40
	jmp DECREMENT_VAR22
LABEL_73C0:
	db 0x11
