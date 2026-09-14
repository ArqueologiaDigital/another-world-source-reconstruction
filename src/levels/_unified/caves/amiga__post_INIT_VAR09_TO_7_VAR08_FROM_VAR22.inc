LABEL_2A46:
	add [0x09], 0x0001
	jne [0x09], 0x08, CAVES_FALLING_ROCK_BOUNCE_CASE_09
	sub [0x08], 0x0008

CAVES_FALLING_ROCK_BOUNCE_CASE_09:
	jne [0x09], 0x09, CAVES_FALLING_ROCK_BOUNCE_CASE_0A
	sub [0x08], 0x0002

CAVES_FALLING_ROCK_BOUNCE_CASE_0A:
	jne [0x09], 0x0A, CAVES_FALLING_ROCK_BOUNCE_CASE_0B
	add [0x08], 0x0004

CAVES_FALLING_ROCK_BOUNCE_CASE_0B:
	jne [0x09], 0x0B, CAVES_FALLING_ROCK_BOUNCE_CASE_0C
	add [0x08], 0x0008

CAVES_FALLING_ROCK_BOUNCE_CASE_0C:
	jne [0x09], 0x0C, LABEL_2A7C
	add [0x08], 0x0010

LABEL_2A7C:
	jl [0x09], 0x0D, SHARED_RET
	add [0x08], 0x0014
	jl [0x08], 0xF0, SHARED_RET
	mov [0x08], 0xFFF6
	mov [0x09], 0x0001
	ret


HANG_DRAW_CIN_625:
	video offset=CINEMATIC_625, x=[0x74], y=[0x75]
	break
	jmp HANG_DRAW_CIN_625

HANG_DRAW_CIN_624:
	video offset=CINEMATIC_624, x=[0x77], y=[0x78]
	break
	jmp HANG_DRAW_CIN_624

HANG_DRAW_CIN_708:
	video offset=CINEMATIC_708, x=[0x7a], y=[0x7b]
	break
	jmp HANG_DRAW_CIN_708
LABEL_2AB0:
	db 0x11

CAVES_FALLING_ROCK_SMALL_DRAW:
	jg [0x09], 0x07, LABEL_2AC9
	video offset=CINEMATIC_625, x=[0x07], y=[0x08]
	ret


CAVES_FALLING_ROCK_MEDIUM_DRAW:
	jg [0x09], 0x07, LABEL_2AC9
	video offset=CINEMATIC_624, x=[0x07], y=[0x08]
	ret


LABEL_2AC9:
	jne [0x09], 0x08, LABEL_2AF3
	play id=0x0077, freq=0x0A, vol=0x40, channel=0x02
	jmp LABEL_2AF3

CAVES_FALLING_ROCK_LARGE_DRAW:
	jg [0x09], 0x07, LABEL_2AE4
	video offset=CINEMATIC_708, x=[0x07], y=[0x08]
	ret


LABEL_2AE4:
	jne [0x09], 0x08, LABEL_2AF3
	play id=0x0077, freq=0x14, vol=0x40, channel=0x00
	jmp LABEL_2AF3

LABEL_2AF3:
	jne [0x09], 0x08, LABEL_2B20
	sub [0x08], 0x0008
	video offset=CINEMATIC_624, x=[0x07], y=[0x08], zoom=0x20
	sub [0x07], 0x000A
	video offset=CINEMATIC_708, x=[0x07], y=[0x08], zoom=0x20
	add [0x08], 0x0008
	add [0x07], 0x0014
	video offset=CINEMATIC_625, x=[0x07], y=[0x08], zoom=0x20
	sub [0x07], 0x000A
	ret


LABEL_2B20:
	jne [0x09], 0x09, LABEL_2B4D
	sub [0x08], 0x000A
	video offset=CINEMATIC_624, x=[0x07], y=[0x08], zoom=0x20
	add [0x08], 0x000A
	sub [0x07], 0x0011
	video offset=CINEMATIC_708, x=[0x07], y=[0x08], zoom=0x20
	add [0x07], 0x0022
	video offset=CINEMATIC_625, x=[0x07], y=[0x08], zoom=0x20
	sub [0x07], 0x0011
	ret


LABEL_2B4D:
	jne [0x09], 0x0A, LABEL_2B7A
	video offset=CINEMATIC_624, x=[0x07], y=[0x08], zoom=0x20
	sub [0x07], 0x0014
	add [0x08], 0x0001
	video offset=CINEMATIC_708, x=[0x07], y=[0x08], zoom=0x20
	sub [0x08], 0x0001
	add [0x07], 0x0028
	video offset=CINEMATIC_625, x=[0x07], y=[0x08], zoom=0x20
	sub [0x07], 0x0014
	ret


LABEL_2B7A:
	jl [0x09], 0x0B, SHARED_RET
	video offset=CINEMATIC_624, x=[0x07], y=[0x08], zoom=0x20
	sub [0x07], 0x001E
	add [0x08], 0x0007
	video offset=CINEMATIC_708, x=[0x07], y=[0x08], zoom=0x20
	sub [0x08], 0x0007
	add [0x07], 0x0032
	video offset=CINEMATIC_625, x=[0x07], y=[0x08], zoom=0x20
	sub [0x07], 0x0014
	ret


CAVES_TRAP_COLUMN_WATCH_SLOT_0_LOOP:
	mov [0x07], [0x68]
	mov [0x08], [0x69]
	call LABEL_2D3D
	break
	jmp CAVES_TRAP_COLUMN_WATCH_SLOT_0_LOOP
LABEL_2BB4:
	db 0x11

CAVES_TRAP_COLUMN_WATCH_SLOT_1_LOOP:
	mov [0x07], [0x6A]
	mov [0x08], [0x6B]
	call LABEL_2D3D
	break
	jmp CAVES_TRAP_COLUMN_WATCH_SLOT_1_LOOP
LABEL_2BC2:
	db 0x11

CAVES_INIT_VARS_6D_71_70_L16:
	mov [0x07], [0x6A]
	mov [0x08], [0x6B]
	mov [0x09], 0x0000
	break
	jmp CAVES_INIT_VARS_6D_71_70_L16
LABEL_2BD1:
	db 0x11, 0x01, 0x07, 0x6C, 0x01, 0x08, 0x6D, 0x04
	db 0x2D, 0x3D, 0x06, 0x07, 0x2B, 0xD2, 0x11

CAVES_TRAP_COLUMN_WATCH_SLOT_3_LOOP:
	mov [0x07], [0x6E]
	mov [0x08], [0x6F]
	call LABEL_2D3D
	break
	jmp CAVES_TRAP_COLUMN_WATCH_SLOT_3_LOOP
LABEL_2BED:
	db 0x11

CAVES_TRAP_COLUMN_WATCH_SLOT_4_LOOP:
	mov [0x07], [0x70]
	mov [0x08], [0x71]
	call LABEL_2D3D
	break
	jmp CAVES_TRAP_COLUMN_WATCH_SLOT_4_LOOP
LABEL_2BFB:
	db 0x11

CAVES_TRAP_COLUMN_WATCH_SLOT_5_LOOP:
	mov [0x07], [0x72]
	mov [0x08], [0x73]
	call LABEL_2D3D
	break
	jmp CAVES_TRAP_COLUMN_WATCH_SLOT_5_LOOP
LABEL_2C09:
	db 0x11
