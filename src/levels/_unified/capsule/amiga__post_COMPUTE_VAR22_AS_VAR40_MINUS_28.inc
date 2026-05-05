LABEL_5240:
	call COMPUTE_VAR22_AS_VAR40_MINUS_28
	video offset=CINEMATIC_098, x=5, y=[0x22]
	break
	call COMPUTE_VAR22_AS_VAR40_MINUS_28
	video offset=CINEMATIC_099, x=10, y=[0x22]
	break
	call COMPUTE_VAR22_AS_VAR40_MINUS_28
	video offset=CINEMATIC_100, x=15, y=[0x22]
	break
	video offset=CINEMATIC_097, x=16, y=[0x40]
	break
	video offset=CINEMATIC_096, x=17, y=[0x40]
	mov [0x21], 0x0011
	mov [0x08], [0x40]
	mov [0x10], [HACK_VAR_67]
	call LABEL_4EFE
	killChannel

LABEL_5274:
	call COMPUTE_VAR22_AS_VAR40_MINUS_28
	video offset=CINEMATIC_098, x=315, y=[0x22]
	break
	call COMPUTE_VAR22_AS_VAR40_MINUS_28
	video offset=CINEMATIC_099, x=307, y=[0x22]
	break
	call COMPUTE_VAR22_AS_VAR40_MINUS_28
	video offset=CINEMATIC_100, x=303, y=[0x22]
	break
	video offset=CINEMATIC_097, x=300, y=[0x40]
	break
	video offset=CINEMATIC_096, x=299, y=[0x40]
	mov [0x21], 0x0122
	mov [0x08], [0x40]
	mov [0x10], [HACK_VAR_67]
	call LABEL_4EFE
	killChannel

LABEL_52A8:
	mov [0x21], [0x01]
	mov [0x22], [0x02]
	mov [0xF8], [0x04]
	jl [0xF8], 0x4000, LABEL_52BB
	call RESET_HERO_ACTION_KEEP_POS_4LSB

LABEL_52BB:
	and [0xF8], 0x003F
	sub [0x22], 0x0016
	jl [0xF8], 0x20, LABEL_52E0
	sub [0xF8], 0x0020
	sub [0x22], 0x0011
	sub [0x21], 0x0023
	jl [0xF8], 0x10, LABEL_52EE
	add [0x21], 0x0042
	ret

LABEL_52E0:
	sub [0x21], 0x0021
	jl [0xF8], 0x10, LABEL_52EE
	add [0x21], 0x003E

LABEL_52EE:
	ret
LABEL_52EF:
	db 0x11

LABEL_52F0:
	mov [0x21], [0x01]
	mov [0x22], [0x02]
	mov [0xF8], [0x04]
	jl [0xF8], 0x4000, LABEL_5303
	call RESET_HERO_ACTION_KEEP_POS_4LSB

LABEL_5303:
	and [0xF8], 0x003F
	sub [0x22], 0x0016
	jl [0xF8], 0x20, LABEL_5328
	sub [0xF8], 0x0020
	sub [0x22], 0x0011
	sub [0x21], 0x0022
	jl [0xF8], 0x10, LABEL_5336
	add [0x21], 0x0041
	ret

LABEL_5328:
	sub [0x21], 0x0020
	jl [0xF8], 0x10, LABEL_5336
	add [0x21], 0x003D

LABEL_5336:
	ret
LABEL_5337:
	db 0x11

LABEL_5338:
	mov [0x0F], 0x0000
	jle [0x06], 0x00, LABEL_545D

LABEL_5342:
	break
	add [0x0F], 0x0001
	jne [HERO_POS_LEFT_RIGHT], 0x00, LABEL_545D
	je [HERO_ACTION], 0x00, LABEL_545D
	jl [0x0F], 0x04, LABEL_5342
	call LABEL_52F0
	video offset=CINEMATIC_092, x=[0x21], y=[0x22]
	break
	call LABEL_52F0
	video offset=CINEMATIC_093, x=[0x21], y=[0x22]
	break
	call LABEL_52F0
	video offset=CINEMATIC_094, x=[0x21], y=[0x22]
	break
	call LABEL_52F0
	video offset=CINEMATIC_113, x=[0x21], y=[0x22]
	play id=0x005B, freq=0x14, vol=0x40, channel=0x01
	je [HERO_ACTION], 0x00, LABEL_543D
	jmp LABEL_53E2
LABEL_538B:
	db 0x11

LABEL_538C:
	mov [0x0F], 0x0000
	jle [0x06], 0x00, LABEL_545D

LABEL_5396:
	break
	add [0x0F], 0x0001
	je [HERO_ACTION], 0x00, LABEL_545D
	jne [HERO_POS_LEFT_RIGHT], 0x00, LABEL_545D
	jl [0x0F], 0x04, LABEL_5396
	call LABEL_52F0
	video offset=CINEMATIC_092, x=[0x21], y=[0x22]
	break
	call LABEL_52F0
	video offset=CINEMATIC_093, x=[0x21], y=[0x22]
	break
	call LABEL_52F0
	video offset=CINEMATIC_094, x=[0x21], y=[0x22]
	break
	call LABEL_52F0
	video offset=CINEMATIC_095, x=[0x21], y=[0x22]
	play id=0x005B, freq=0x14, vol=0x40, channel=0x01
	jne [HERO_POS_LEFT_RIGHT], 0x00, LABEL_545D
	je [HERO_ACTION], 0x00, LABEL_543D

LABEL_53E2:
	break
	jne [HERO_POS_LEFT_RIGHT], 0x00, LABEL_5435
	je [HERO_ACTION], 0x00, LABEL_5435
	call LABEL_52F0
	video offset=CINEMATIC_098, x=[0x21], y=[0x22]
	break
	je [HERO_ACTION], 0x00, LABEL_5435
	call LABEL_52F0
	video offset=CINEMATIC_099, x=[0x21], y=[0x22]
	break
	je [HERO_ACTION], 0x00, LABEL_5435
	call LABEL_52F0
	video offset=CINEMATIC_100, x=[0x21], y=[0x22]
	break
	je [HERO_ACTION], 0x00, LABEL_5435
	call LABEL_52F0
	video offset=CINEMATIC_099, x=[0x21], y=[0x22]
	add [0x0F], 0x0004
	jl [0x0F], 0x14, LABEL_53E2
	break
	je [HERO_ACTION], 0x01, LABEL_54A9

LABEL_5435:
	call LABEL_52F0
	video offset=CINEMATIC_097, x=[0x21], y=[0x02]

LABEL_543D:
	break
	play id=0x0058, freq=0x14, vol=0x40, channel=0x01
	call LABEL_52F0
	video offset=CINEMATIC_096, x=[0x21], y=[0x02]
	jge [HACK_VAR_67], 0xC8, LABEL_5462
	sub [0x06], 0x000A
	call LABEL_4F54
	mov [0x0F], 0x0000

LABEL_545D:
	mov [0x0F], 0x0000
	killChannel

LABEL_5462:
	break
	call LABEL_52F0
	video offset=CINEMATIC_086, x=[0x21], y=[0x02]
	sub [0x21], 0x0005
	video offset=CINEMATIC_087, x=[0x21], y=[0x02]
	add [0x21], 0x000A
	video offset=CINEMATIC_088, x=[0x21], y=[0x02]
	break
	call LABEL_52F0
	sub [0x21], 0x0007
	video offset=CINEMATIC_089, x=[0x21], y=[0x02]
	sub [0x21], 0x000A
	video offset=CINEMATIC_090, x=[0x21], y=[0x02]
	add [0x21], 0x0018
	video offset=CINEMATIC_087, x=[0x21], y=[0x02]
	add [0x21], 0x000A
	video offset=CINEMATIC_091, x=[0x21], y=[0x02]
	jmp LABEL_545D
LABEL_54A8:
	db 0x11

LABEL_54A9:
	call LABEL_52F0
	video offset=CINEMATIC_101, x=[0x21], y=[0x22]
	play id=0x0059, freq=0x14, vol=0x40, channel=0x01
	break
	call LABEL_52F0
	video offset=CINEMATIC_102, x=[0x21], y=[0x22]

LABEL_54C0:
	break
	call LABEL_52A8
	video offset=CINEMATIC_103, x=[0x21], y=[0x22]
	jne [HERO_POS_LEFT_RIGHT], 0x00, LABEL_5505
	je [HERO_ACTION], 0x00, LABEL_5505
	break
	call LABEL_52A8
	video offset=CINEMATIC_104, x=[0x21], y=[0x22]
	je [HERO_ACTION], 0x00, LABEL_5505
	break
	call LABEL_52A8
	video offset=CINEMATIC_105, x=[0x21], y=[0x22]
	je [HERO_ACTION], 0x00, LABEL_5505
	break
	call LABEL_52A8
	video offset=CINEMATIC_106, x=[0x21], y=[0x22]
	je [HERO_ACTION], 0x00, LABEL_5505
	jmp LABEL_54C0

LABEL_5505:
	break
	sub [0x06], 0x0032
	call LABEL_52A8
	mov [0x90], [0x21]
	mov [0x91], [0x22]
	mov [0x88], 0x0064
	or [0x88], 0x8000
	mov [0xF8], [0x04]
	and [0xF8], 0x0010
	add [0x90], 0x0001
	jne [0xF8], 0x00, LABEL_5534
	sub [0x90], 0x0002
	or [0x91], 0x4000

LABEL_5534:
	mov [0x0F], 0x0000
	killChannel

LABEL_5539:
	call LABEL_55C7
	jg [0x22], [0x21], COMPUTE_VARF8_AS_VAR22_MINUS_VAR09
	mov [0xF8], [0x09]
	sub [0xF8], [0x22]
	jmp LABEL_5551
