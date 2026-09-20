HERO_FLOOR_STEP_DOWN_ENTRY:
	mov [0x63], 0x0064
	mov [HERO_Y], [0x52]
	sub [HERO_Y], 0x001E
	call HERO_FLOOR_STEP_DOWN_DRAW_BY_FACING
	break
	mov [HERO_Y], [0x52]
	call HERO_FLOOR_STEP_DOWN_DRAW_BY_FACING
	setup channel=0x1A, address=LABEL_7E20
	jmp LABEL_7E9F
LABEL_7E4E:
	db 0x11

HERO_FLOOR_STEP_UP_ENTRY:
	mov [0x63], 0x0064
	mov [HERO_Y], [0x51]
	add [HERO_Y], 0x001E
	call HERO_FLOOR_STEP_UP_DRAW_BY_FACING
	break
	mov [HERO_Y], [0x51]
	call HERO_FLOOR_STEP_UP_DRAW_BY_FACING
	setup channel=0x1A, address=LABEL_7E0E
	jmp LABEL_7E9F
LABEL_7E6B:
	db 0x11

HERO_FLOOR_STEP_UP_DRAW_BY_FACING:
	mov [0xF8], [0x04]
	and [0xF8], 0x0010
	jne [0xF8], 0x00, DRAW_CIN_305
	video offset=CINEMATIC_TELEPORT_UP_BEAM, x=[HERO_X], y=[HERO_Y]
	ret


DRAW_CIN_305:
	video offset=CINEMATIC_305, x=[HERO_X], y=[HERO_Y]
	ret


LABEL_7E85:
	db 0x11

HERO_FLOOR_STEP_DOWN_DRAW_BY_FACING:
	mov [0xF8], [0x04]
	and [0xF8], 0x0010
	jne [0xF8], 0x00, DRAW_CIN_303
	video offset=CINEMATIC_304, x=[HERO_X], y=[HERO_Y]
	ret


DRAW_CIN_303:
	video offset=CINEMATIC_303, x=[HERO_X], y=[HERO_Y]
	ret


LABEL_7E9F:
	mov [0xF8], [0x04]
	and [0xF8], 0x0010
	mov [0x32], 0x0000
	mov [0x63], 0x0002
	jne [0xF8], 0x00, HERO_WALK_RIGHT_LOOP
	mov [0x63], 0x0001
	jmp HERO_WALK_LEFT_LOOP
LABEL_7EBB:
	db 0x11
