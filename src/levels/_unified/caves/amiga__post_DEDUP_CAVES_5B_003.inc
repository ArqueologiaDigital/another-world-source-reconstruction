LABEL_72D1:
	break
	call PROJECT_POS_VAR04_OR_9EB4
	video type=1, offset=CINEMATIC_152, x=[0x21], y=[0x02], zoom=0x40
	sub [0x21], 0x0005
	video type=1, offset=CINEMATIC_153, x=[0x21], y=[0x02], zoom=0x40
	add [0x21], 0x000A
	video type=1, offset=CINEMATIC_154, x=[0x21], y=[0x02], zoom=0x40
	break
	call PROJECT_POS_VAR04_OR_9EB4
	sub [0x21], 0x0007
	video type=1, offset=CINEMATIC_155, x=[0x21], y=[0x02], zoom=0x40
	sub [0x21], 0x000A
	video type=1, offset=CINEMATIC_156, x=[0x21], y=[0x02], zoom=0x40
	add [0x21], 0x0018
	video type=1, offset=CINEMATIC_153, x=[0x21], y=[0x02], zoom=0x40
	add [0x21], 0x000A
	video type=1, offset=CINEMATIC_157, x=[0x21], y=[0x02], zoom=0x40
	jmp DEDUP_CAVES_5B_003
LABEL_7317:
	db 0x11

LABEL_7318:
	call PROJECT_POS_VAR04_OR_9EB4
	video type=1, offset=CINEMATIC_068, x=[0x21], y=[0x22], zoom=0x40
	play id=0x0059, freq=0x14, vol=0x40, channel=0x01
	break
	call PROJECT_POS_VAR04_OR_9EB4
	video type=1, offset=CINEMATIC_069, x=[0x21], y=[0x22], zoom=0x40

LABEL_732F:
	break
	call PROJECT_POS_VAR04_OR_CALL_A189
	video type=1, offset=CINEMATIC_070, x=[0x21], y=[0x22], zoom=0x40
	jne [HERO_POS_LEFT_RIGHT], 0x00, LABEL_7374
	je [HERO_ACTION], 0x00, LABEL_7374
	break
	call PROJECT_POS_VAR04_OR_CALL_A189
	video type=1, offset=CINEMATIC_071, x=[0x21], y=[0x22], zoom=0x40
	je [HERO_ACTION], 0x00, LABEL_7374
	break
	call PROJECT_POS_VAR04_OR_CALL_A189
	video type=1, offset=CINEMATIC_072, x=[0x21], y=[0x22], zoom=0x40
	je [HERO_ACTION], 0x00, LABEL_7374
	break
	call PROJECT_POS_VAR04_OR_CALL_A189
	video type=1, offset=CINEMATIC_073, x=[0x21], y=[0x22], zoom=0x40
	je [HERO_ACTION], 0x00, LABEL_7374
	jmp LABEL_732F

LABEL_7374:
	break
	sub [0x06], 0x0032
	call PROJECT_POS_VAR04_OR_CALL_A189
	mov [0x90], [0x21]
	mov [0x91], [0x22]
	mov [0x88], 0x0064
	or [0x88], 0x8000
	mov [0xF8], [0x04]
	and [0xF8], 0x0010
	add [0x90], 0x0001
	jne [0xF8], 0x00, DEDUP_CAVES_5B_003__CAVES_INLINE_SETTERS_AND_INIT
	sub [0x90], 0x0002
	or [0x91], 0x4000
