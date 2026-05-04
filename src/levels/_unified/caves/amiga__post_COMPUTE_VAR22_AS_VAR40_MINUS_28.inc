LABEL_70AF:
	call COMPUTE_VAR22_AS_VAR40_MINUS_28
	video type=1, offset=CINEMATIC_033, x=5, y=[0x22], zoom=0x40
	break
	call COMPUTE_VAR22_AS_VAR40_MINUS_28
	video type=1, offset=CINEMATIC_034, x=10, y=[0x22], zoom=0x40
	break
	call COMPUTE_VAR22_AS_VAR40_MINUS_28
	video type=1, offset=CINEMATIC_035, x=15, y=[0x22], zoom=0x40
	break
	video type=1, offset=CINEMATIC_036, x=16, y=[0x40], zoom=0x40
	break
	video type=1, offset=CINEMATIC_037, x=17, y=[0x40], zoom=0x40
	mov [0x21], 0x0011
	mov [0x08], [0x40]
	mov [0x10], [HACK_VAR_67]
	call LABEL_6D6D
	killChannel

LABEL_70E3:
	call COMPUTE_VAR22_AS_VAR40_MINUS_28
	video type=1, offset=CINEMATIC_033, x=315, y=[0x22], zoom=0x40
	break
	call COMPUTE_VAR22_AS_VAR40_MINUS_28
	video type=1, offset=CINEMATIC_034, x=307, y=[0x22], zoom=0x40
	break
	call COMPUTE_VAR22_AS_VAR40_MINUS_28
	video type=1, offset=CINEMATIC_035, x=303, y=[0x22], zoom=0x40
	break
	video type=1, offset=CINEMATIC_036, x=300, y=[0x40], zoom=0x40
	break
	video type=1, offset=CINEMATIC_037, x=299, y=[0x40], zoom=0x40
	mov [0x21], 0x012B
	mov [0x08], [0x40]
	mov [0x10], [HACK_VAR_67]
	call LABEL_6D6D
	killChannel

PROJECT_POS_VAR04_OR_CALL_A189:
	mov [0x21], [0x01]
	mov [0x22], [0x02]
	mov [0xF8], [0x04]
	jl [0xF8], 0x4000, LABEL_712A
	call RESET_HERO_ACTION_KEEP_POS_4LSB

LABEL_712A:
	and [0xF8], 0x003F
	sub [0x22], 0x0016
	jl [0xF8], 0x20, LABEL_714F
	sub [0xF8], 0x0020
	sub [0x22], 0x0011
	sub [0x21], 0x0023
	jl [0xF8], 0x10, LABEL_715D
	add [0x21], 0x0042
	ret

LABEL_714F:
	sub [0x21], 0x0021
	jl [0xF8], 0x10, LABEL_715D
	add [0x21], 0x003E

LABEL_715D:
	ret
LABEL_715E:
	db 0x11

PROJECT_POS_VAR04_OR_9EB4:
	mov [0x21], [0x01]
	mov [0x22], [0x02]
	mov [0xF8], [0x04]
	jl [0xF8], 0x4000, LABEL_7172
	call RESET_HERO_ACTION_KEEP_POS_4LSB

LABEL_7172:
	and [0xF8], 0x003F
	sub [0x22], 0x0016
	jl [0xF8], 0x20, LABEL_7197
	sub [0xF8], 0x0020
	sub [0x22], 0x0011
	sub [0x21], 0x0022
	jl [0xF8], 0x10, LABEL_71A5
	add [0x21], 0x0041
	ret

LABEL_7197:
	sub [0x21], 0x0020
	jl [0xF8], 0x10, LABEL_71A5
	add [0x21], 0x003D

LABEL_71A5:
	ret
LABEL_71A6:
	db 0x11

LABEL_71A7:
	mov [0x0F], 0x0000
	jle [0x06], 0x00, DEDUP_CAVES_5B_003	;@raw=0x0A,0x05,0x06,0x00,0x72,0xCC

LABEL_71B1:
	break
	add [0x0F], 0x0001
	jne [HERO_POS_LEFT_RIGHT], 0x00, DEDUP_CAVES_5B_003	;@raw=0x0A,0x01,0xFC,0x00,0x72,0xCC
	je [HERO_ACTION], 0x00, DEDUP_CAVES_5B_003	;@raw=0x0A,0x00,0xFA,0x00,0x72,0xCC
	jl [0x0F], 0x04, LABEL_71B1
	call PROJECT_POS_VAR04_OR_9EB4
	video type=1, offset=CINEMATIC_063, x=[0x21], y=[0x22], zoom=0x40
	break
	call PROJECT_POS_VAR04_OR_9EB4
	video type=1, offset=CINEMATIC_064, x=[0x21], y=[0x22], zoom=0x40
	break
	call PROJECT_POS_VAR04_OR_9EB4
	video type=1, offset=CINEMATIC_065, x=[0x21], y=[0x22], zoom=0x40
	break
	call PROJECT_POS_VAR04_OR_9EB4
	video type=1, offset=CINEMATIC_066, x=[0x21], y=[0x22], zoom=0x40
	play id=0x005B, freq=0x14, vol=0x40, channel=0x01
	je [HERO_ACTION], 0x00, LABEL_72AC
	jmp LABEL_7251
LABEL_71FA:
	db 0x11

LABEL_71FB:
	mov [0x0F], 0x0000
	jle [0x06], 0x00, DEDUP_CAVES_5B_003	;@raw=0x0A,0x05,0x06,0x00,0x72,0xCC

LABEL_7205:
	break
	add [0x0F], 0x0001
	je [HERO_ACTION], 0x00, DEDUP_CAVES_5B_003	;@raw=0x0A,0x00,0xFA,0x00,0x72,0xCC
	jne [HERO_POS_LEFT_RIGHT], 0x00, DEDUP_CAVES_5B_003	;@raw=0x0A,0x01,0xFC,0x00,0x72,0xCC
	jl [0x0F], 0x04, LABEL_7205
	call PROJECT_POS_VAR04_OR_9EB4
	video type=1, offset=CINEMATIC_063, x=[0x21], y=[0x22], zoom=0x40
	break
	call PROJECT_POS_VAR04_OR_9EB4
	video type=1, offset=CINEMATIC_064, x=[0x21], y=[0x22], zoom=0x40
	break
	call PROJECT_POS_VAR04_OR_9EB4
	video type=1, offset=CINEMATIC_065, x=[0x21], y=[0x22], zoom=0x40
	break
	call PROJECT_POS_VAR04_OR_9EB4
	video type=1, offset=CINEMATIC_067, x=[0x21], y=[0x22], zoom=0x40
	play id=0x005B, freq=0x14, vol=0x40, channel=0x01
	jne [HERO_POS_LEFT_RIGHT], 0x00, DEDUP_CAVES_5B_003	;@raw=0x0A,0x01,0xFC,0x00,0x72,0xCC
	je [HERO_ACTION], 0x00, LABEL_72AC

LABEL_7251:
	break
	jne [HERO_POS_LEFT_RIGHT], 0x00, LABEL_72A4
	je [HERO_ACTION], 0x00, LABEL_72A4
	call PROJECT_POS_VAR04_OR_9EB4
	video type=1, offset=CINEMATIC_033, x=[0x21], y=[0x22], zoom=0x40
	break
	je [HERO_ACTION], 0x00, LABEL_72A4
	call PROJECT_POS_VAR04_OR_9EB4
	video type=1, offset=CINEMATIC_034, x=[0x21], y=[0x22], zoom=0x40
	break
	je [HERO_ACTION], 0x00, LABEL_72A4
	call PROJECT_POS_VAR04_OR_9EB4
	video type=1, offset=CINEMATIC_035, x=[0x21], y=[0x22], zoom=0x40
	break
	je [HERO_ACTION], 0x00, LABEL_72A4
	call PROJECT_POS_VAR04_OR_9EB4
	video type=1, offset=CINEMATIC_034, x=[0x21], y=[0x22], zoom=0x40
	add [0x0F], 0x0004
	jl [0x0F], 0x14, LABEL_7251
	break
	je [HERO_ACTION], 0x01, LABEL_7318

LABEL_72A4:
	call PROJECT_POS_VAR04_OR_9EB4
	video type=1, offset=CINEMATIC_036, x=[0x21], y=[0x02], zoom=0x40

LABEL_72AC:
	break
	call PROJECT_POS_VAR04_OR_9EB4
	video type=1, offset=CINEMATIC_037, x=[0x21], y=[0x02], zoom=0x40
	play id=0x0058, freq=0x14, vol=0x40, channel=0x01
	jge [HACK_VAR_67], 0xC8, LABEL_72D1
	sub [0x06], 0x000A
	call LABEL_6DC3
	mov [0x0F], 0x0000
