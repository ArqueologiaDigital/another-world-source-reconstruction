LABEL_7C9E:
	db 0x11

LABEL_7C9F:
	call LABEL_7F3C
	call LABEL_7CC5
	mov [0x21], 0x00A0
	mov [0x22], [0x18]
	mov [0x2B], 0x0006

LABEL_7CB0:
	call LABEL_7AB1
	add [0x22], 0x0032
	djnz [0x2B], LABEL_7CB0
	video offset=CINEMATIC_102, x=[0x01], y=[0x02]
	video offset=CINEMATIC_103, x=160, y=129
	ret

LABEL_7CC5:
	mov [0x21], 0x0064
	jg [0x14], 0x22A0, DRAW_CIN_092
	mov [0x21], [0x14]
	sub [0x21], 0x22A0
	add [0x21], 0x0064

DRAW_CIN_092:
	video offset=CINEMATIC_092, x=160, y=[0x21]
	ret

LABEL_7CE1:
	je [HACK_VAR_67], 0x65, LABEL_7CFD
	video offset=CINEMATIC_106, x=160, y=100
	je [HACK_VAR_67], 0x45, LABEL_7CF5
	video offset=CINEMATIC_092, x=160, y=100

LABEL_7CF5:
	call LABEL_7C9F
	video offset=CINEMATIC_105, x=160, y=129
	ret

LABEL_7CFD:
	video offset=CINEMATIC_090, x=160, y=100
	video offset=CINEMATIC_091, x=160, y=100
	call LABEL_7C9F
	video offset=CINEMATIC_104, x=200, y=100
	video offset=CINEMATIC_105, x=160, y=129
	ret
LABEL_7D11:
	db 0x11

LABEL_7D12:
	call COPY_HASH_AND_SPLIT_VAR38_3F_3E
	call INCREMENT_VAR31
	jne [RANDOM_SEED], 0x00, LABEL_7D22
	setup channel=0x38, address=LABEL_0F04

LABEL_7D22:
	jne [RANDOM_SEED], 0x01, LABEL_7D2C
	setup channel=0x39, address=LABEL_0F1C

LABEL_7D2C:
	jne [RANDOM_SEED], 0x02, LABEL_7D36
	setup channel=0x38, address=LABEL_0F34

LABEL_7D36:
	jne [RANDOM_SEED], 0x03, LABEL_7D40
	setup channel=0x39, address=LABEL_0F46

LABEL_7D40:
	jne [RANDOM_SEED], 0x04, LABEL_7D4C
	play id=0x0058, freq=0x0F, vol=0x10, channel=0x03

LABEL_7D4C:
	jne [RANDOM_SEED], 0x05, LABEL_7D58
	play id=0x0058, freq=0x0F, vol=0x10, channel=0x02

LABEL_7D58:
	jne [RANDOM_SEED], 0x06, LABEL_7D64
	play id=0x0058, freq=0x14, vol=0x20, channel=0x03

LABEL_7D64:
	jl [RANDOM_SEED], 0x1E, LABEL_7D70
	play id=0x0058, freq=0x0A, vol=0x18, channel=0x00

LABEL_7D70:
	call LABEL_7F3C
	call LABEL_7C2E
	call LABEL_7C9F
	video offset=CINEMATIC_102, x=[0x01], y=[0x02]
	video offset=CINEMATIC_103, x=160, y=[0x02]
	je [0x11], 0x00, SHARED_RET
	video offset=CINEMATIC_131, x=[0x07], y=[0x08]
	ret

LABEL_7D8F:
	jne [0x63], 0xFFFF, SCROLL_UP_16_VAR14_VAR18_AND_SCROLL_Y
	add [0x14], 0x0010
	add [0x18], 0x0010
	add [SCROLL_Y], 0x0010
	ret
