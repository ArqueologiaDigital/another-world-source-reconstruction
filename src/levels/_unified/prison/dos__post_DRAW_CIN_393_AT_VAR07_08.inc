LABEL_14DD:
	call GUARDED_HERO_ANIM_CV_128
	add [0x07], 0x0001
	mov [0x29], 0x0005

LABEL_14E8:
	break
	call GUARDED_HERO_ANIM_CV_128
	djnz [0x29], LABEL_14E8
	break
	call GUARDED_DRAW_CIN_342
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_389, x=[0x07], y=[0x08], zoom=0x40
	video type=1, offset=CINEMATIC_390, x=[0x07], y=[0x08], zoom=0x40
	selectVideoPage 0xFF
	mov [0x29], 0x000F

LABEL_1506:
	break
	video type=1, offset=CINEMATIC_391, x=[0x07], y=[0x08], zoom=0x40
	video type=1, offset=CINEMATIC_392, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_393_AT_VAR07_08
	djnz [0x29], LABEL_1506
	break
	video type=1, offset=CINEMATIC_394, x=[0x07], y=[0x08], zoom=0x40
	video type=1, offset=CINEMATIC_392, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_393_AT_VAR07_08
	break
	video type=1, offset=CINEMATIC_395, x=[0x07], y=[0x08], zoom=0x40
	video type=1, offset=CINEMATIC_392, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_393_AT_VAR07_08
	mov [0x29], 0x0014

LABEL_1538:
	break
	video type=1, offset=CINEMATIC_397, x=[0x07], y=[0x08], zoom=0x40
	video type=1, offset=CINEMATIC_396, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_393_AT_VAR07_08
	djnz [0x29], LABEL_1538
	break
	video type=1, offset=CINEMATIC_395, x=[0x07], y=[0x08], zoom=0x40
	video type=1, offset=CINEMATIC_396, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_393_AT_VAR07_08
	break
	video type=1, offset=CINEMATIC_400, x=[0x07], y=[0x08], zoom=0x40
	video type=1, offset=CINEMATIC_396, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_393_AT_VAR07_08
	break
	video type=1, offset=CINEMATIC_401, x=[0x07], y=[0x08], zoom=0x40
	video type=1, offset=CINEMATIC_396, x=[0x07], y=[0x08], zoom=0x40
	video type=1, offset=CINEMATIC_393, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=1, offset=CINEMATIC_402, x=[0x07], y=[0x08], zoom=0x40
	video type=1, offset=CINEMATIC_396, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_393_AT_VAR07_08
	mov [0x29], 0x0020

LABEL_1588:
	break
	video type=1, offset=CINEMATIC_403, x=[0x07], y=[0x08], zoom=0x40
	video type=1, offset=CINEMATIC_392, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_393_AT_VAR07_08
	djnz [0x29], LABEL_1588
	break
	video type=1, offset=CINEMATIC_404, x=[0x07], y=[0x08], zoom=0x40
	video type=1, offset=CINEMATIC_396, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_393_AT_VAR07_08
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_405, x=160, y=[0x44], zoom=0x40
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
