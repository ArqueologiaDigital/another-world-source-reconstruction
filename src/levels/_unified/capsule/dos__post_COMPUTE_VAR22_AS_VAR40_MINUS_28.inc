LABEL_69B2:
	call COMPUTE_VAR22_AS_VAR40_MINUS_28
	video offset=CINEMATIC_064, x=5, y=[0x22], zoom=0x40
	break
	call COMPUTE_VAR22_AS_VAR40_MINUS_28
	video offset=CINEMATIC_065, x=10, y=[0x22], zoom=0x40
	break
	call COMPUTE_VAR22_AS_VAR40_MINUS_28
	video offset=CINEMATIC_066, x=15, y=[0x22], zoom=0x40
	break
	video offset=CINEMATIC_063, x=16, y=[0x40], zoom=0x40
	break
	video offset=CINEMATIC_062, x=17, y=[0x40], zoom=0x40
	mov [0x21], 0x0011
	mov [0x08], [0x40]
	mov [0x10], [HACK_VAR_67]
	call LABEL_666C
	killChannel

LABEL_69E6:
	call COMPUTE_VAR22_AS_VAR40_MINUS_28
	video offset=CINEMATIC_064, x=315, y=[0x22], zoom=0x40
	break
	call COMPUTE_VAR22_AS_VAR40_MINUS_28
	video offset=CINEMATIC_065, x=307, y=[0x22], zoom=0x40
	break
	call COMPUTE_VAR22_AS_VAR40_MINUS_28
	video offset=CINEMATIC_066, x=303, y=[0x22], zoom=0x40
	break
	video offset=CINEMATIC_063, x=300, y=[0x40], zoom=0x40
	break
	video offset=CINEMATIC_062, x=299, y=[0x40], zoom=0x40
	mov [0x21], 0x0122
	mov [0x08], [0x40]
	mov [0x10], [HACK_VAR_67]
	call LABEL_666C
	killChannel

LABEL_6A1A:
	mov [0x21], [0x01]
	add [0xB8], 0x0007
	mov [0x22], [0x02]
	mov [0xF8], [0x04]
	jl [0xF8], 0x4000, LABEL_6A31
	call RESET_HERO_ACTION_KEEP_POS_4LSB

LABEL_6A31:
	and [0xF8], 0x003F
	sub [0x22], 0x0016
	jl [0xF8], 0x20, LABEL_6A56
	sub [0xF8], 0x0020
	sub [0x22], 0x0011
	sub [0x21], 0x0023
	jl [0xF8], 0x10, LABEL_6A64
	add [0x21], 0x0042
	ret

LABEL_6A56:
	sub [0x21], 0x0021
	jl [0xF8], 0x10, LABEL_6A64
	add [0x21], 0x003E

LABEL_6A64:
	ret
LABEL_6A65:
	db 0x11

PROJECT_POS_VAR_B8_PLUS_7:
	mov [0x21], [0x01]
	add [0xB8], 0x0007
	mov [0x22], [0x02]
	mov [0xF8], [0x04]
	jl [0xF8], 0x4000, LABEL_6A7D
	call RESET_HERO_ACTION_KEEP_POS_4LSB

LABEL_6A7D:
	and [0xF8], 0x003F
	sub [0x22], 0x0016
	jl [0xF8], 0x20, LABEL_6AA2
	sub [0xF8], 0x0020
	sub [0x22], 0x0011
	sub [0x21], 0x0022
	jl [0xF8], 0x10, LABEL_6AB0
	add [0x21], 0x0041
	ret

LABEL_6AA2:
	sub [0x21], 0x0020
	jl [0xF8], 0x10, LABEL_6AB0
	add [0x21], 0x003D

LABEL_6AB0:
	ret
LABEL_6AB1:
	db 0x11

LABEL_6AB2:
	mov [0x0F], 0x0000
	jle [0x06], 0x00, ZERO_VAR0F_AND_KILL

LABEL_6ABC:
	break
	add [0x0F], 0x0001
	jge [0x04], 0x4000, ZERO_VAR0F_AND_KILL
	jne [HERO_POS_LEFT_RIGHT], 0x00, ZERO_VAR0F_AND_KILL
	je [HERO_POS_JUMP_DOWN], 0xFFFF, ZERO_VAR0F_AND_KILL
	je [HERO_ACTION], 0x00, ZERO_VAR0F_AND_KILL
	jl [0x0F], 0x04, LABEL_6ABC
	call PROJECT_POS_VAR_B8_PLUS_7
	video offset=CINEMATIC_058, x=[0x21], y=[0x22], zoom=0x40
	break
	call PROJECT_POS_VAR_B8_PLUS_7
	video offset=CINEMATIC_059, x=[0x21], y=[0x22], zoom=0x40
	break
	call PROJECT_POS_VAR_B8_PLUS_7
	video offset=CINEMATIC_060, x=[0x21], y=[0x22], zoom=0x40
	break
	jge [0x04], 0x4000, ZERO_VAR0F_AND_KILL
	call PROJECT_POS_VAR_B8_PLUS_7
	video offset=CINEMATIC_061, x=[0x21], y=[0x22], zoom=0x40
	play id=0x005B, freq=0x14, vol=0x40, channel=0x01
	je [HERO_ACTION], 0x00, LABEL_6BEF
	jmp LABEL_6B8D
LABEL_6B1A:
	db 0x11

LABEL_6B1B:
	mov [0x0F], 0x0000
	jle [0x06], 0x00, ZERO_VAR0F_AND_KILL

LABEL_6B25:
	break
	add [0x0F], 0x0001
	jge [0x04], 0x4000, ZERO_VAR0F_AND_KILL
	je [HERO_ACTION], 0x00, ZERO_VAR0F_AND_KILL
	jne [HERO_POS_LEFT_RIGHT], 0x00, ZERO_VAR0F_AND_KILL
	je [HERO_POS_JUMP_DOWN], 0xFFFF, ZERO_VAR0F_AND_KILL
	jl [0x0F], 0x04, LABEL_6B25
	call PROJECT_POS_VAR_B8_PLUS_7
	video offset=CINEMATIC_058, x=[0x21], y=[0x22], zoom=0x40
	break
	call PROJECT_POS_VAR_B8_PLUS_7
	video offset=CINEMATIC_059, x=[0x21], y=[0x22], zoom=0x40
	break
	call PROJECT_POS_VAR_B8_PLUS_7
	video offset=CINEMATIC_060, x=[0x21], y=[0x22], zoom=0x40
	break
	jge [0x04], 0x4000, ZERO_VAR0F_AND_KILL
	call PROJECT_POS_VAR_B8_PLUS_7
	video offset=CINEMATIC_075, x=[0x21], y=[0x22], zoom=0x40
	play id=0x005B, freq=0x14, vol=0x40, channel=0x01
	jne [HERO_POS_LEFT_RIGHT], 0x00, ZERO_VAR0F_AND_KILL
	je [HERO_POS_JUMP_DOWN], 0xFFFF, ZERO_VAR0F_AND_KILL
	je [HERO_ACTION], 0x00, LABEL_6BEF

LABEL_6B8D:
	break
	jne [HERO_POS_LEFT_RIGHT], 0x00, LABEL_6BE7
	je [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_6BE7
	je [HERO_ACTION], 0x00, LABEL_6BE7
	call PROJECT_POS_VAR_B8_PLUS_7
	video offset=CINEMATIC_064, x=[0x21], y=[0x22], zoom=0x40
	break
	je [HERO_ACTION], 0x00, LABEL_6BE7
	call PROJECT_POS_VAR_B8_PLUS_7
	video offset=CINEMATIC_065, x=[0x21], y=[0x22], zoom=0x40
	break
	je [HERO_ACTION], 0x00, LABEL_6BE7
	call PROJECT_POS_VAR_B8_PLUS_7
	video offset=CINEMATIC_066, x=[0x21], y=[0x22], zoom=0x40
	break
	je [HERO_ACTION], 0x00, LABEL_6BE7
	call PROJECT_POS_VAR_B8_PLUS_7
	video offset=CINEMATIC_065, x=[0x21], y=[0x22], zoom=0x40
	add [0x0F], 0x0004
	jl [0x0F], 0x14, LABEL_6B8D
	break
	je [HERO_ACTION], 0x01, LABEL_6C5C

LABEL_6BE7:
	call PROJECT_POS_VAR_B8_PLUS_7
	video offset=CINEMATIC_063, x=[0x21], y=[0x02], zoom=0x40

LABEL_6BEF:
	break
	play id=0x0058, freq=0x14, vol=0x40, channel=0x01
	call PROJECT_POS_VAR_B8_PLUS_7
	video offset=CINEMATIC_062, x=[0x21], y=[0x02], zoom=0x40
	jge [HACK_VAR_67], 0x03E8, LABEL_6C15
	sub [0x06], 0x000A
	call LABEL_66C2
	mov [0x0F], 0x0000

ZERO_VAR0F_AND_KILL:
	mov [0x0F], 0x0000
	killChannel

LABEL_6C15:
	break
	call PROJECT_POS_VAR_B8_PLUS_7
	video offset=CINEMATIC_052, x=[0x21], y=[0x02], zoom=0x40
	sub [0x21], 0x0005
	video offset=CINEMATIC_053, x=[0x21], y=[0x02], zoom=0x40
	add [0x21], 0x000A
	video offset=CINEMATIC_054, x=[0x21], y=[0x02], zoom=0x40
	break
	call PROJECT_POS_VAR_B8_PLUS_7
	sub [0x21], 0x0007
	video offset=CINEMATIC_055, x=[0x21], y=[0x02], zoom=0x40
	sub [0x21], 0x000A
	video offset=CINEMATIC_056, x=[0x21], y=[0x02], zoom=0x40
	add [0x21], 0x0018
	video offset=CINEMATIC_053, x=[0x21], y=[0x02], zoom=0x40
	add [0x21], 0x000A
	video offset=CINEMATIC_057, x=[0x21], y=[0x02], zoom=0x40
	jmp ZERO_VAR0F_AND_KILL
LABEL_6C5B:
	db 0x11

LABEL_6C5C:
	call PROJECT_POS_VAR_B8_PLUS_7
	video offset=CINEMATIC_067, x=[0x21], y=[0x22], zoom=0x40
	play id=0x0059, freq=0x14, vol=0x40, channel=0x01
	break
	call PROJECT_POS_VAR_B8_PLUS_7
	video offset=CINEMATIC_068, x=[0x21], y=[0x22], zoom=0x40

LABEL_6C73:
	break
	call LABEL_6A1A
	video offset=CINEMATIC_069, x=[0x21], y=[0x22], zoom=0x40
	jne [HERO_POS_LEFT_RIGHT], 0x00, LABEL_6CD4
	je [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_6CD4
	je [HERO_ACTION], 0x00, LABEL_6CD4
	break
	call LABEL_6A1A
	video offset=CINEMATIC_070, x=[0x21], y=[0x22], zoom=0x40
	je [HERO_ACTION], 0x00, LABEL_6CD4
	je [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_6CD4
	break
	call LABEL_6A1A
	video offset=CINEMATIC_071, x=[0x21], y=[0x22], zoom=0x40
	je [HERO_ACTION], 0x00, LABEL_6CD4
	je [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_6CD4
	break
	call LABEL_6A1A
	video offset=CINEMATIC_072, x=[0x21], y=[0x22], zoom=0x40
	je [HERO_ACTION], 0x00, LABEL_6CD4
	je [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_6CD4
	jmp LABEL_6C73

LABEL_6CD4:
	break
	sub [0x06], 0x0032
	call LABEL_6A1A
	mov [0x90], [0x21]
	mov [0x91], [0x22]
	mov [0x88], 0x0064
	or [0x88], 0x8000
	mov [0xF8], [0x04]
	and [0xF8], 0x0010
	add [0x90], 0x0001
	jne [0xF8], 0x00, LABEL_6D03
	sub [0x90], 0x0002
	or [0x91], 0x4000

LABEL_6D03:
	mov [0x0F], 0x0000
	killChannel

LABEL_6D08:
	call LABEL_6D96
	jg [0x22], [0x21], COMPUTE_VARF8_AS_VAR22_MINUS_VAR09
	mov [0xF8], [0x09]
	sub [0xF8], [0x22]
	jmp LABEL_6D20
