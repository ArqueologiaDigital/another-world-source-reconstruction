LABEL_4565:
	play id=0x0059, freq=0x14, vol=0x40, channel=0x00
	call PROJECT_POS_VAR04_OR_7E81
	video offset=CINEMATIC_190, x=[0x21], y=[0x22]
	break
	call PROJECT_POS_VAR04_OR_7E81
	video offset=CINEMATIC_191, x=[0x21], y=[0x22]

LABEL_457C:
	break
	call PROJECT_POS_BY_VAR04_OR_807B
	video offset=CINEMATIC_192, x=[0x21], y=[0x22]
	jne [HERO_POS_LEFT_RIGHT], 0x00, LABEL_45C1
	je [HERO_ACTION], 0x00, LABEL_45C1
	break
	call PROJECT_POS_BY_VAR04_OR_807B
	video offset=CINEMATIC_193, x=[0x21], y=[0x22]
	je [HERO_ACTION], 0x00, LABEL_45C1
	break
	call PROJECT_POS_BY_VAR04_OR_807B
	video offset=CINEMATIC_194, x=[0x21], y=[0x22]
	je [HERO_ACTION], 0x00, LABEL_45C1
	break
	call PROJECT_POS_BY_VAR04_OR_807B
	video offset=CINEMATIC_195, x=[0x21], y=[0x22]
	je [HERO_ACTION], 0x00, LABEL_45C1
	jmp LABEL_457C

LABEL_45C1:
	break
	sub [0x06], 0x0064
	call PROJECT_POS_BY_VAR04_OR_807B
	mov [0x90], [0x21]
	mov [0x91], [0x22]
	mov [0x88], 0x0064
	or [0x88], 0x8000
	mov [0xF8], [0x04]
	and [0xF8], 0x0010
	jne [0xF8], 0x00, DEDUP_CAVES_5B_003__PRISON_INLINE_SETTERS_AND_INIT
	or [0x91], 0x4000
