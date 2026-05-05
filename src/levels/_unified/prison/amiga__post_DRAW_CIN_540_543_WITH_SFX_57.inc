HANG_DRAW_CIN_549:
	video offset=CINEMATIC_549, x=181, y=146
	break
	jmp HANG_DRAW_CIN_549
LABEL_76EA:
	db 0x11

HANG_DRAW_CIN_275:
	video offset=CINEMATIC_275, x=181, y=146
	break
	jmp HANG_DRAW_CIN_275

LABEL_76F3:
	mov [0x17], 0x0005
	sub [0x15], 0x0001
	call LABEL_759F
	call LABEL_75B4

LABEL_7701:
	mov [0x16], [0x15]
	add [HERO_X], [0x16]
	break
	jg [HERO_X], 0x28, LABEL_7712
	djnz [0x17], LABEL_7701

LABEL_7712:
	jl [HERO_X], 0x14, LABEL_771E
	play id=0x0062, freq=0x23, vol=0x0F, channel=0x00

LABEL_771E:
	mov [0x16], [0x15]
	sub [0x16], 0x0003
	call LABEL_7589
	add [HERO_X], [0x16]
	call LABEL_75B4
	break
	sub [0x16], 0x0004
	call LABEL_7589
	add [HERO_X], [0x16]
	break
	sub [0x16], 0x0005
	call LABEL_7594
	add [HERO_X], [0x16]
	break
	sub [0x16], 0x0006
	call LABEL_7594
	add [HERO_X], [0x16]
	jl [0x15], 0x28, LABEL_775A
	break
	add [HERO_X], 0x000C

LABEL_775A:
	break
	mov [0x18], 0x0001
	mov [0x19], 0x0000
	sub [HERO_X], 0x0006
	break
	jge [0x15], 0x2C, LABEL_75D3

LABEL_776E:
	mov [0x16], [0x15]
	add [0x16], 0x0001
	sub [HERO_X], [0x16]
	break
	jg [HERO_X], 0x00, LABEL_776E

LABEL_777F:
	mov [0x17], 0x0005
	sub [0x15], 0x0001
	call LABEL_759F
	call LABEL_75B4

LABEL_778D:
	mov [0x16], [0x15]
	sub [HERO_X], [0x16]
	break
	jl [HERO_X], 0xFFD8, LABEL_779F
	djnz [0x17], LABEL_778D

LABEL_779F:
	jg [HERO_X], 0xFFEC, LABEL_77B9
	play id=0x0062, freq=0x14, vol=0x0F, channel=0x00
	jg [HERO_X], 0xFFD3, LABEL_77B9
	play id=0x0063, freq=0x14, vol=0x20, channel=0x03

LABEL_77B9:
	mov [0x16], [0x15]
	sub [0x16], 0x0003
	call LABEL_7589
	sub [HERO_X], [0x16]
	break
	sub [0x16], 0x0004
	call LABEL_7589
	sub [HERO_X], [0x16]
	break
	sub [0x16], 0x0005
	call LABEL_7594
	sub [HERO_X], [0x16]
	break
	sub [0x16], 0x0006
	call LABEL_7594
	sub [HERO_X], [0x16]
	jl [0x15], 0x28, LABEL_77F2
	break
	sub [HERO_X], 0x000C

LABEL_77F2:
	break
	mov [0x18], 0x0000
	mov [0x19], 0x0000
	add [HERO_X], 0x0006
	call LABEL_75B4
	break

LABEL_7803:
	mov [0x16], [0x15]
	add [0x16], 0x0001
	add [HERO_X], [0x16]
	break
	jl [HERO_X], 0x00, LABEL_7803
	jmp LABEL_76F3
LABEL_7817:
	db 0x11, 0x04, 0x70, 0x72, 0x04, 0x72, 0x27, 0x54
	db 0x11, 0xDA, 0x1A, 0x1B, 0x04, 0x72, 0xF2, 0x05
