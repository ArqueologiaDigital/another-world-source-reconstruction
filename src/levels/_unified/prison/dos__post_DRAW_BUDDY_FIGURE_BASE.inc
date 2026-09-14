BUDDY_HACK_FIRST_INIT_AND_STEP_RIGHT:
	call PRISON_ACTOR_WALK_RIGHT_DRAW_PHASE_02
	add [BUDDY_X], 0x0001
	mov [0x29], 0x0005

BUDDY_HACK_FIRST_PREPARE_LOOP:
	break
	call PRISON_ACTOR_WALK_RIGHT_DRAW_PHASE_02
	djnz [0x29], BUDDY_HACK_FIRST_PREPARE_LOOP
	break
	call GUARDED_DRAW_CIN_342
	selectVideoPage 0x00
	video offset=CINEMATIC_BUDDY_HACKING_SECURITY_DOOR, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_390, x=[BUDDY_X], y=[BUDDY_Y]
	selectVideoPage 0xFF
	mov [0x29], 0x000F

BUDDY_HACK_FIRST_TYPING_LOOP:
	break
	video offset=CINEMATIC_391, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_392, x=[BUDDY_X], y=[BUDDY_Y]
	call DRAW_BUDDY_FIGURE_BASE
	djnz [0x29], BUDDY_HACK_FIRST_TYPING_LOOP
	break
	video offset=CINEMATIC_394, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_392, x=[BUDDY_X], y=[BUDDY_Y]
	call DRAW_BUDDY_FIGURE_BASE
	break
	video offset=CINEMATIC_395, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_392, x=[BUDDY_X], y=[BUDDY_Y]
	call DRAW_BUDDY_FIGURE_BASE
	mov [0x29], 0x0014

LABEL_1538:
	break
	video offset=CINEMATIC_397, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_396, x=[BUDDY_X], y=[BUDDY_Y]
	call DRAW_BUDDY_FIGURE_BASE
	djnz [0x29], LABEL_1538
	break
	video offset=CINEMATIC_395, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_396, x=[BUDDY_X], y=[BUDDY_Y]
	call DRAW_BUDDY_FIGURE_BASE
	break
	video offset=CINEMATIC_400, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_396, x=[BUDDY_X], y=[BUDDY_Y]
	call DRAW_BUDDY_FIGURE_BASE
	break
	video offset=CINEMATIC_401, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_396, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_393, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_402, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_396, x=[BUDDY_X], y=[BUDDY_Y]
	call DRAW_BUDDY_FIGURE_BASE
	mov [0x29], 0x0020

LABEL_1588:
	break
	video offset=CINEMATIC_403, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_392, x=[BUDDY_X], y=[BUDDY_Y]
	call DRAW_BUDDY_FIGURE_BASE
	djnz [0x29], LABEL_1588
	break
	video offset=CINEMATIC_404, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_396, x=[BUDDY_X], y=[BUDDY_Y]
	call DRAW_BUDDY_FIGURE_BASE
	selectVideoPage 0x00
	video offset=CINEMATIC_405, x=160, y=[0x44]
	selectVideoPage 0xFF
	break
	call GUARDED_DRAW_CIN_342
	break
	call PRISON_ACTOR_WALK_RIGHT_DRAW_PHASE_02
	or [0x49], 0x0040
	je [0xB6], 0x00, LABEL_15CF
	break
	mov [0x29], 0x0082
	mov [0x12], 0x0028
	jmp PRISON_ACTOR_FACE_RIGHT_THEN_WALK_RIGHT

LABEL_15CF:
	mov [0x12], 0x1008
	jmp LABEL_25D9
LABEL_15D6:
	db 0x11
