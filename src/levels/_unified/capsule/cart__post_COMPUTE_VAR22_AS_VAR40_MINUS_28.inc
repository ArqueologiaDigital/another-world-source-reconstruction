LABEL_69BB:
	call COMPUTE_VAR22_AS_VAR40_MINUS_28
	call LABEL_00F7
	video offset=CINEMATIC_064, x=5, y=[0x22]
	break
	call COMPUTE_VAR22_AS_VAR40_MINUS_28
	video offset=CINEMATIC_065, x=10, y=[0x22]
	break
	call COMPUTE_VAR22_AS_VAR40_MINUS_28
	video offset=CINEMATIC_066, x=15, y=[0x22]
	break
	video offset=CINEMATIC_063, x=16, y=[0x40]
	break
	video offset=CINEMATIC_062, x=17, y=[0x40]
	mov [0x21], 0x0011
	mov [BUDDY_Y], [0x40]
	mov [0x10], [HACK_VAR_67]
	call LABEL_6675
	killChannel

LABEL_69F2:
	call COMPUTE_VAR22_AS_VAR40_MINUS_28
	call LABEL_00F7
	video offset=CINEMATIC_064, x=315, y=[0x22]
	break
	call COMPUTE_VAR22_AS_VAR40_MINUS_28
	video offset=CINEMATIC_065, x=307, y=[0x22]
	break
	call COMPUTE_VAR22_AS_VAR40_MINUS_28
	video offset=CINEMATIC_066, x=303, y=[0x22]
	break
	video offset=CINEMATIC_063, x=300, y=[0x40]
	break
	video offset=CINEMATIC_062, x=299, y=[0x40]
	mov [0x21], 0x0122
	mov [BUDDY_Y], [0x40]
	mov [0x10], [HACK_VAR_67]
	call LABEL_6675
	killChannel

LABEL_6A29:
	mov [0x21], [HERO_X]
	add [0xB8], 0x0007
	mov [0x22], [HERO_Y]
	mov [0xF8], [0x04]
	jl [0xF8], 0x4000, LABEL_6A40
	call RESET_HERO_ACTION_KEEP_POS_4LSB

LABEL_6A40:
	and [0xF8], 0x003F
	sub [0x22], 0x0016
	jl [0xF8], 0x20, LABEL_6A65
	sub [0xF8], 0x0020
	sub [0x22], 0x0011
	sub [0x21], 0x0023
	jl [0xF8], 0x10, LABEL_6A73
	add [0x21], 0x0042
	ret

LABEL_6A65:
	sub [0x21], 0x0021
	jl [0xF8], 0x10, LABEL_6A73
	add [0x21], 0x003E

LABEL_6A73:
	ret
LABEL_6A74:
	db 0x11

PROJECT_POS_VAR_B8_PLUS_7:
	mov [0x21], [HERO_X]
	add [0xB8], 0x0007
	mov [0x22], [HERO_Y]
	mov [0xF8], [0x04]
	jl [0xF8], 0x4000, LABEL_6A8C
	call RESET_HERO_ACTION_KEEP_POS_4LSB

LABEL_6A8C:
	and [0xF8], 0x003F
	sub [0x22], 0x0016
	jl [0xF8], 0x20, LABEL_6AB1
	sub [0xF8], 0x0020
	sub [0x22], 0x0011
	sub [0x21], 0x0022
	jl [0xF8], 0x10, LABEL_6ABF
	add [0x21], 0x0041
	ret

LABEL_6AB1:
	sub [0x21], 0x0020
	jl [0xF8], 0x10, LABEL_6ABF
	add [0x21], 0x003D

LABEL_6ABF:
	ret
LABEL_6AC0:
	db 0x11

LABEL_6AC1:
	mov [0x0F], 0x0000
	jle [0x06], 0x00, DRAW_CIN_052_THEN_053_PAIR

LABEL_6ACB:
	break
	add [0x0F], 0x0001
	jge [0x04], 0x4000, DRAW_CIN_052_THEN_053_PAIR
	jne [HERO_POS_LEFT_RIGHT], 0x00, DRAW_CIN_052_THEN_053_PAIR
	je [HERO_POS_JUMP_DOWN], 0xFFFF, DRAW_CIN_052_THEN_053_PAIR
	je [HERO_ACTION], 0x00, DRAW_CIN_052_THEN_053_PAIR
	jl [0x0F], 0x04, LABEL_6ACB
	call PROJECT_POS_VAR_B8_PLUS_7
	video offset=CINEMATIC_058, x=[0x21], y=[0x22]
	break
	call PROJECT_POS_VAR_B8_PLUS_7
	video offset=CINEMATIC_059, x=[0x21], y=[0x22]
	break
	call PROJECT_POS_VAR_B8_PLUS_7
	video offset=CINEMATIC_060, x=[0x21], y=[0x22]
	break
	jge [0x04], 0x4000, DRAW_CIN_052_THEN_053_PAIR
	call PROJECT_POS_VAR_B8_PLUS_7
	video offset=CINEMATIC_061, x=[0x21], y=[0x22]
	play id=0x005B, freq=0x14, vol=0x40, channel=0x01
	je [HERO_ACTION], 0x00, LABEL_6C22
	jmp LABEL_6B9C
LABEL_6B29:
	db 0x11

LABEL_6B2A:
	mov [0x0F], 0x0000
	jle [0x06], 0x00, DRAW_CIN_052_THEN_053_PAIR

LABEL_6B34:
	break
	add [0x0F], 0x0001
	jge [0x04], 0x4000, DRAW_CIN_052_THEN_053_PAIR
	je [HERO_ACTION], 0x00, DRAW_CIN_052_THEN_053_PAIR
	jne [HERO_POS_LEFT_RIGHT], 0x00, DRAW_CIN_052_THEN_053_PAIR
	je [HERO_POS_JUMP_DOWN], 0xFFFF, DRAW_CIN_052_THEN_053_PAIR
	jl [0x0F], 0x04, LABEL_6B34
	call PROJECT_POS_VAR_B8_PLUS_7
	video offset=CINEMATIC_058, x=[0x21], y=[0x22]
	break
	call PROJECT_POS_VAR_B8_PLUS_7
	video offset=CINEMATIC_059, x=[0x21], y=[0x22]
	break
	call PROJECT_POS_VAR_B8_PLUS_7
	video offset=CINEMATIC_060, x=[0x21], y=[0x22]
	break
	jge [0x04], 0x4000, DRAW_CIN_052_THEN_053_PAIR
	call PROJECT_POS_VAR_B8_PLUS_7
	video offset=CINEMATIC_075, x=[0x21], y=[0x22]
	play id=0x005B, freq=0x14, vol=0x40, channel=0x01
	jne [HERO_POS_LEFT_RIGHT], 0x00, DRAW_CIN_052_THEN_053_PAIR
	je [HERO_POS_JUMP_DOWN], 0xFFFF, DRAW_CIN_052_THEN_053_PAIR
	je [HERO_ACTION], 0x00, LABEL_6C22

LABEL_6B9C:
	break
	jne [HERO_POS_LEFT_RIGHT], 0x00, LABEL_6BF6
	je [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_6BF6
	je [HERO_ACTION], 0x00, LABEL_6BF6
	call PROJECT_POS_VAR_B8_PLUS_7
	video offset=CINEMATIC_064, x=[0x21], y=[0x22]
	break
	je [HERO_ACTION], 0x00, LABEL_6BF6
	call PROJECT_POS_VAR_B8_PLUS_7
	video offset=CINEMATIC_065, x=[0x21], y=[0x22]
	break
	je [HERO_ACTION], 0x00, LABEL_6BF6
	call PROJECT_POS_VAR_B8_PLUS_7
	video offset=CINEMATIC_066, x=[0x21], y=[0x22]
	break
	je [HERO_ACTION], 0x00, LABEL_6BF6
	call PROJECT_POS_VAR_B8_PLUS_7
	video offset=CINEMATIC_065, x=[0x21], y=[0x22]
	add [0x0F], 0x0004
	jl [0x0F], 0x14, LABEL_6B9C
	break
	je [HERO_ACTION], 0x01, LABEL_6CB4

LABEL_6BF6:
	call PROJECT_POS_VAR_B8_PLUS_7
	jne [HACK_VAR_67], 0x6B, LABEL_6C1D
	jg [HERO_Y], 0x96, LABEL_6C1D
	jl [0x21], 0x64, LABEL_6C22
	jl [0x21], 0x8A, LABEL_6C1D
	jl [0x21], 0xC1, LABEL_6C22
	jg [0x21], 0xDE, LABEL_6C22

LABEL_6C1D:
	video offset=CINEMATIC_063, x=[0x21], y=[HERO_Y]

LABEL_6C22:
	break
	play id=0x0058, freq=0x14, vol=0x40, channel=0x01
	call PROJECT_POS_VAR_B8_PLUS_7
	jne [HACK_VAR_67], 0x6B, LABEL_6C58
	jg [HERO_Y], 0x96, LABEL_6C58
	jl [0x21], 0x64, DRAW_CIN_052_THEN_053_PAIR
	jl [0x21], 0x8A, LABEL_6C50
	jl [0x21], 0xC1, DRAW_CIN_052_THEN_053_PAIR
	jg [0x21], 0xDE, DRAW_CIN_052_THEN_053_PAIR

LABEL_6C50:
	video offset=CINEMATIC_062, x=[0x21], y=[HERO_Y]
	jmp DRAW_CIN_052_THEN_053_PAIR

LABEL_6C58:
	video offset=CINEMATIC_062, x=[0x21], y=[HERO_Y]
	sub [0x06], 0x000A
	call LABEL_66CB
	mov [0x0F], 0x0000

DRAW_CIN_052_THEN_053_PAIR:
	mov [0x0F], 0x0000
	killChannel
	break
	call PROJECT_POS_VAR_B8_PLUS_7
	video offset=CINEMATIC_052, x=[0x21], y=[HERO_Y]
	sub [0x21], 0x0005
	video offset=CINEMATIC_053, x=[0x21], y=[HERO_Y]
	add [0x21], 0x000A
	video offset=CINEMATIC_054, x=[0x21], y=[HERO_Y]
	break
	call PROJECT_POS_VAR_B8_PLUS_7
	sub [0x21], 0x0007
	video offset=CINEMATIC_055, x=[0x21], y=[HERO_Y]
	sub [0x21], 0x000A
	video offset=CINEMATIC_056, x=[0x21], y=[HERO_Y]
	add [0x21], 0x0018
	video offset=CINEMATIC_053, x=[0x21], y=[HERO_Y]
	add [0x21], 0x000A
	video offset=CINEMATIC_057, x=[0x21], y=[HERO_Y]
	jmp DRAW_CIN_052_THEN_053_PAIR
LABEL_6CB3:
	db 0x11

LABEL_6CB4:
	call PROJECT_POS_VAR_B8_PLUS_7
	video offset=CINEMATIC_067, x=[0x21], y=[0x22]
	play id=0x0059, freq=0x14, vol=0x40, channel=0x01
	break
	call PROJECT_POS_VAR_B8_PLUS_7
	video offset=CINEMATIC_068, x=[0x21], y=[0x22]

LABEL_6CCB:
	break
	call LABEL_6A29
	video offset=CINEMATIC_069, x=[0x21], y=[0x22]
	jne [HERO_POS_LEFT_RIGHT], 0x00, LABEL_6D2C
	je [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_6D2C
	je [HERO_ACTION], 0x00, LABEL_6D2C
	break
	call LABEL_6A29
	video offset=CINEMATIC_070, x=[0x21], y=[0x22]
	je [HERO_ACTION], 0x00, LABEL_6D2C
	je [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_6D2C
	break
	call LABEL_6A29
	video offset=CINEMATIC_071, x=[0x21], y=[0x22]
	je [HERO_ACTION], 0x00, LABEL_6D2C
	je [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_6D2C
	break
	call LABEL_6A29
	video offset=CINEMATIC_072, x=[0x21], y=[0x22]
	je [HERO_ACTION], 0x00, LABEL_6D2C
	je [HERO_POS_JUMP_DOWN], 0xFFFF, LABEL_6D2C
	jmp LABEL_6CCB

LABEL_6D2C:
	break
	sub [0x06], 0x0032
	call LABEL_6A29
	mov [0x90], [0x21]
	mov [0x91], [0x22]
	mov [0x88], 0x0064
	or [0x88], 0x8000
	mov [0xF8], [0x04]
	and [0xF8], 0x0010
	add [0x90], 0x0001
	jne [0xF8], 0x00, ZERO_VAR0F_AND_KILL
	sub [0x90], 0x0002
	or [0x91], 0x4000

ZERO_VAR0F_AND_KILL:
	mov [0x0F], 0x0000
	killChannel

LABEL_6D60:
	call LABEL_6DEE
	jg [0x22], [0x21], COMPUTE_VARF8_AS_VAR22_MINUS_VAR09
	mov [0xF8], [0x09]
	sub [0xF8], [0x22]
	jmp LABEL_6D78
