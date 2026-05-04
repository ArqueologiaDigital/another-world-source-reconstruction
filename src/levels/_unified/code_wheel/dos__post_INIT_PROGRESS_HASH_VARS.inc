INIT_GAME_STATE_VARS:
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
	mov [0x32], 0x0000
	ret
	mov [HACK_VAR_54], 0x0080

GAME_INTRO_PHASE_DRAW_CIN_076:
	jl [HACK_VAR_54], 0x80, LABEL_00BF
	fill page=0xFF, color=0x00
	setPalette 0x00
	load id=0x0012
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_076, x=160, y=100
	selectVideoPage 0xFF
	setup channel=0x2C, address=PAL_FADE_DOWN_1A_TO_4
	mov [0x03], 0x0028

LABEL_009E:
	break
	jne [HERO_ACTION], 0x00, BANK1_INTRO_TRANSITION
	djnz [0x03], LABEL_009E
	setup channel=0x2C, address=PAL_FADE_4_TO_18_AND_BACK
	mov [0x03], 0x000A

LABEL_00B1:
	break
	jne [HERO_ACTION], 0x00, BANK1_INTRO_TRANSITION
	djnz [0x03], LABEL_00B1
	jmp LABEL_00BF

LABEL_00BF:
	setPalette 0x17
	fill page=0xFF, color=0x00
	load id=0x0047
	setup channel=0x2C, address=PAL_FADE_DOWN_17_TO_11
	mov [0x03], 0x0014

LABEL_00D0:
	break
	jne [HERO_ACTION], 0x00, BANK1_INTRO_TRANSITION
	djnz [0x03], LABEL_00D0
	jmp LABEL_00DE

LABEL_00DE:
	fill page=0xFF, color=0x00
	setPalette 0x0E
	jge [HACK_VAR_54], 0x80, LOAD_RESOURCE_13
	load id=0x0053
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_075, x=160, y=100
	jmp LABEL_00F9
