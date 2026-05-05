LABEL_004A:
	mov [0x31], 0x0000
	mov [0x1B], 0x0000
	mov [0x64], 0x0001
	mov [0x6E], 0x007D
	mov [0x33], 0x2202
	mov [0x34], 0x002D
	mov [0x4E], 0x002E
	mov [0xB4], 0x001A
	mov [0xC5], 0x0236
	mov [0xBE], 0x1ED1
	mov [0x53], 0x004E
	ret
LABEL_0077:
	db 0x00, 0x54, 0x00, 0x01

GAME_INTRO_PHASE_DRAW_CIN_076:
	jl [HACK_VAR_54], 0x80, LABEL_00AF
	fill page=0xFF, color=0x00
	setPalette 0x00
	load id=0x0012
	selectVideoPage 0x00
	video offset=CINEMATIC_050, x=160, y=100
	selectVideoPage 0xFF
	setup channel=0x2C, address=PAL_FADE_DOWN_1A_TO_4
	mov [0x03], 0x0028

DELAY_LOOP_VAR03:
	break
	djnz [0x03], DELAY_LOOP_VAR03
	setup channel=0x2C, address=PAL_FADE_4_TO_18_AND_BACK
	mov [0x03], 0x000A

DELAY_LOOP_VAR03_AT_00A7:
	break
	djnz [0x03], DELAY_LOOP_VAR03_AT_00A7
	jmp LABEL_00AF

LABEL_00AF:
	setPalette 0x17
	fill page=0xFF, color=0x00
	fill page=0x00, color=0x00
	setup channel=0x2C, address=PAL_FADE_DOWN_17_TO_11
	mov [0x03], 0x0014

DELAY_LOOP_VAR03_AT_00C0:
	break
	djnz [0x03], DELAY_LOOP_VAR03_AT_00C0
	jmp LABEL_00C8

LABEL_00C8:
	fill page=0xFF, color=0x00
	setPalette 0x0E
	jge [HACK_VAR_54], 0x80, LOAD_RESOURCE_13
	load id=0x0053
	selectVideoPage 0x00
	video offset=CINEMATIC_049, x=160, y=100
	jmp LABEL_00E3
