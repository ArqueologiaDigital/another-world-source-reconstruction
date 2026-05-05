LABEL_14DD:
	call GUARDED_HERO_ANIM_CV_128
	add [BUDDY_X], 0x0001
	mov [0x29], 0x0005

LABEL_14E8:
	break
	call GUARDED_HERO_ANIM_CV_128
	djnz [0x29], LABEL_14E8
	break
	call GUARDED_DRAW_CIN_342
	selectVideoPage 0x00
	video offset=CINEMATIC_389, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_390, x=[BUDDY_X], y=[BUDDY_Y]
	selectVideoPage 0xFF
	mov [0x29], 0x000F

LABEL_1506:
	break
	video offset=CINEMATIC_391, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_392, x=[BUDDY_X], y=[BUDDY_Y]
	call DRAW_CIN_393_AT_VAR07_08
	djnz [0x29], LABEL_1506
	break
	video offset=CINEMATIC_394, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_392, x=[BUDDY_X], y=[BUDDY_Y]
	call DRAW_CIN_393_AT_VAR07_08
	break
	video offset=CINEMATIC_395, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_392, x=[BUDDY_X], y=[BUDDY_Y]
	call DRAW_CIN_393_AT_VAR07_08
	mov [0x29], 0x0014

LABEL_1538:
	break
	video offset=CINEMATIC_397, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_396, x=[BUDDY_X], y=[BUDDY_Y]
	call DRAW_CIN_393_AT_VAR07_08
	djnz [0x29], LABEL_1538
	break
	video offset=CINEMATIC_395, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_396, x=[BUDDY_X], y=[BUDDY_Y]
	call DRAW_CIN_393_AT_VAR07_08
	break
	video offset=CINEMATIC_400, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_396, x=[BUDDY_X], y=[BUDDY_Y]
	call DRAW_CIN_393_AT_VAR07_08
	break
	video offset=CINEMATIC_401, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_396, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_393, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_402, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_396, x=[BUDDY_X], y=[BUDDY_Y]
	call DRAW_CIN_393_AT_VAR07_08
	mov [0x29], 0x0020

LABEL_1588:
	break
	video offset=CINEMATIC_403, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_392, x=[BUDDY_X], y=[BUDDY_Y]
	call DRAW_CIN_393_AT_VAR07_08
	djnz [0x29], LABEL_1588
	break
	video offset=CINEMATIC_404, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_396, x=[BUDDY_X], y=[BUDDY_Y]
	call DRAW_CIN_393_AT_VAR07_08
	selectVideoPage 0x00
	video offset=CINEMATIC_405, x=160, y=[0x44]
	selectVideoPage 0xFF
	break
	call GUARDED_DRAW_CIN_342
	break
	call GUARDED_HERO_ANIM_CV_128
	or [0x49], 0x0040
	je [0xB6], 0x00, LABEL_15CF
	break
	mov [0x29], 0x0082
	mov [0x12], 0x0028
	jmp LABEL_68DA

LABEL_15CF:
	mov [0x12], 0x1008
	jmp LABEL_25D9
LABEL_15D6:
	db 0x11
