LABEL_73C9:
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
	call LABEL_7087
	killChannel

LABEL_73FD:
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
	call LABEL_7087
	killChannel

PROJECT_POS_VAR04_OR_CALL_A189:
	mov [0x21], [0x01]
	mov [0x22], [0x02]
	mov [0xF8], [0x04]
	jl [0xF8], 0x4000, LABEL_7444
	call RESET_HERO_ACTION_KEEP_POS_4LSB

LABEL_7444:
	and [0xF8], 0x003F
	sub [0x22], 0x0016
	jl [0xF8], 0x20, LABEL_7469
	sub [0xF8], 0x0020
	sub [0x22], 0x0011
	sub [0x21], 0x0023
	jl [0xF8], 0x10, LABEL_7477
	add [0x21], 0x0042
	ret

LABEL_7469:
	sub [0x21], 0x0021
	jl [0xF8], 0x10, LABEL_7477
	add [0x21], 0x003E

LABEL_7477:
	ret
LABEL_7478:
	db 0x11

PROJECT_POS_VAR04_OR_A212:
	mov [0x21], [0x01]
	mov [0x22], [0x02]
	mov [0xF8], [0x04]
	jl [0xF8], 0x4000, LABEL_748C
	call RESET_HERO_ACTION_KEEP_POS_4LSB

LABEL_748C:
	and [0xF8], 0x003F
	sub [0x22], 0x0016
	jl [0xF8], 0x20, LABEL_74B1
	sub [0xF8], 0x0020
	sub [0x22], 0x0011
	sub [0x21], 0x0022
	jl [0xF8], 0x10, LABEL_74BF
	add [0x21], 0x0041
	ret

LABEL_74B1:
	sub [0x21], 0x0020
	jl [0xF8], 0x10, LABEL_74BF
	add [0x21], 0x003D

LABEL_74BF:
	ret
LABEL_74C0:
	db 0x11

LABEL_74C1:
	mov [0x0F], 0x0000
	jle [0x06], 0x00, DEDUP_CAVES_5B_003	;@raw=0x0A,0x05,0x06,0x00,0x76,0x09

LABEL_74CB:
	break
	add [0x0F], 0x0001
	jne [HERO_POS_LEFT_RIGHT], 0x00, DEDUP_CAVES_5B_003	;@raw=0x0A,0x01,0xFC,0x00,0x76,0x09
	je [HERO_POS_JUMP_DOWN], 0xFFFF, DEDUP_CAVES_5B_003	;@raw=0x0A,0x40,0xFB,0xFF,0xFF,0x76,0x09
	je [HERO_ACTION], 0x00, DEDUP_CAVES_5B_003	;@raw=0x0A,0x00,0xFA,0x00,0x76,0x09
	jl [0x0F], 0x04, LABEL_74CB
	call PROJECT_POS_VAR04_OR_A212
	video type=1, offset=CINEMATIC_063, x=[0x21], y=[0x22], zoom=0x40
	break
	call PROJECT_POS_VAR04_OR_A212
	video type=1, offset=CINEMATIC_064, x=[0x21], y=[0x22], zoom=0x40
	break
	call PROJECT_POS_VAR04_OR_A212
	video type=1, offset=CINEMATIC_065, x=[0x21], y=[0x22], zoom=0x40
	break
	call PROJECT_POS_VAR04_OR_A212
	video type=1, offset=CINEMATIC_066, x=[0x21], y=[0x22], zoom=0x40
	play id=0x005B, freq=0x14, vol=0x40, channel=0x01
	je [HERO_POS_JUMP_DOWN], 0xFFFF, DEDUP_CAVES_5B_003	;@raw=0x0A,0x40,0xFB,0xFF,0xFF,0x76,0x09
	je [HERO_ACTION], 0x00, LABEL_75E9
	jmp LABEL_7587
LABEL_7522:
	db 0x11

LABEL_7523:
	mov [0x0F], 0x0000
	jle [0x06], 0x00, DEDUP_CAVES_5B_003	;@raw=0x0A,0x05,0x06,0x00,0x76,0x09

LABEL_752D:
	break
	add [0x0F], 0x0001
	je [HERO_ACTION], 0x00, DEDUP_CAVES_5B_003	;@raw=0x0A,0x00,0xFA,0x00,0x76,0x09
	je [HERO_POS_JUMP_DOWN], 0xFFFF, DEDUP_CAVES_5B_003	;@raw=0x0A,0x40,0xFB,0xFF,0xFF,0x76,0x09
	jne [HERO_POS_LEFT_RIGHT], 0x00, DEDUP_CAVES_5B_003	;@raw=0x0A,0x01,0xFC,0x00,0x76,0x09
	jl [0x0F], 0x04, LABEL_752D
	call PROJECT_POS_VAR04_OR_A212
	video type=1, offset=CINEMATIC_063, x=[0x21], y=[0x22], zoom=0x40
	break
	call PROJECT_POS_VAR04_OR_A212
	video type=1, offset=CINEMATIC_064, x=[0x21], y=[0x22], zoom=0x40
	break
	call PROJECT_POS_VAR04_OR_A212
	video type=1, offset=CINEMATIC_065, x=[0x21], y=[0x22], zoom=0x40
	break
	call PROJECT_POS_VAR04_OR_A212
	video type=1, offset=CINEMATIC_067, x=[0x21], y=[0x22], zoom=0x40
	play id=0x005B, freq=0x14, vol=0x40, channel=0x01
	jne [HERO_POS_LEFT_RIGHT], 0x00, DEDUP_CAVES_5B_003	;@raw=0x0A,0x01,0xFC,0x00,0x76,0x09
	je [HERO_POS_JUMP_DOWN], 0xFFFF, DEDUP_CAVES_5B_003	;@raw=0x0A,0x40,0xFB,0xFF,0xFF,0x76,0x09
	je [HERO_ACTION], 0x00, LABEL_75E9

LABEL_7587:
	break
	jne [HERO_POS_LEFT_RIGHT], 0x00, LABEL_75E1
	je [HERO_ACTION], 0x00, LABEL_75E1
	je [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_75E1
	call PROJECT_POS_VAR04_OR_A212
	video type=1, offset=CINEMATIC_033, x=[0x21], y=[0x22], zoom=0x40
	break
	je [HERO_ACTION], 0x00, LABEL_75E1
	call PROJECT_POS_VAR04_OR_A212
	video type=1, offset=CINEMATIC_034, x=[0x21], y=[0x22], zoom=0x40
	break
	je [HERO_ACTION], 0x00, LABEL_75E1
	call PROJECT_POS_VAR04_OR_A212
	video type=1, offset=CINEMATIC_035, x=[0x21], y=[0x22], zoom=0x40
	break
	je [HERO_ACTION], 0x00, LABEL_75E1
	call PROJECT_POS_VAR04_OR_A212
	video type=1, offset=CINEMATIC_034, x=[0x21], y=[0x22], zoom=0x40
	add [0x0F], 0x0004
	jl [0x0F], 0x14, LABEL_7587
	break
	je [HERO_ACTION], 0x01, LABEL_7655

LABEL_75E1:
	call PROJECT_POS_VAR04_OR_A212
	video type=1, offset=CINEMATIC_036, x=[0x21], y=[0x02], zoom=0x40

LABEL_75E9:
	break
	call PROJECT_POS_VAR04_OR_A212
	video type=1, offset=CINEMATIC_037, x=[0x21], y=[0x02], zoom=0x40
	play id=0x0058, freq=0x14, vol=0x40, channel=0x01
	jge [HACK_VAR_67], 0xC8, LABEL_760E
	sub [0x06], 0x000A
	call LABEL_70DD
	mov [0x0F], 0x0000
