LABEL_0207:
	jne [0x10], [HACK_VAR_67], LABEL_0222
	video offset=CINEMATIC_124, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_344, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_125, x=[BUDDY_X], y=[BUDDY_Y]
	play id=0x005E, freq=0x1C, vol=0x40, channel=0x02

LABEL_0222:
	break
	jne [0x10], [HACK_VAR_67], LABEL_0238
	video offset=CINEMATIC_126, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_344, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_125, x=[BUDDY_X], y=[BUDDY_Y]

LABEL_0238:
	break
	jne [0x10], [HACK_VAR_67], LABEL_0254
	video offset=CINEMATIC_127, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_344, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_128, x=[BUDDY_X], y=[BUDDY_Y]
	play id=0x005E, freq=0x14, vol=0x40, channel=0x02

LABEL_0254:
	break
	jne [0x10], [HACK_VAR_67], LABEL_026A
	video offset=CINEMATIC_129, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_344, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_128, x=[BUDDY_X], y=[BUDDY_Y]

LABEL_026A:
	break
	jne [0x10], [HACK_VAR_67], LABEL_0280
	video offset=CINEMATIC_126, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_344, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_125, x=[BUDDY_X], y=[BUDDY_Y]

LABEL_0280:
	break
	jge [0x7B], 0x4000, LABEL_028C
	djnz [0x29], LABEL_0207

LABEL_028C:
	jne [0x10], [HACK_VAR_67], LABEL_02C1
	video offset=CINEMATIC_124, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_344, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_125, x=[BUDDY_X], y=[BUDDY_Y]
	play id=0x005E, freq=0x1C, vol=0x40, channel=0x02
	selectVideoPage 0x00
	video offset=CINEMATIC_345, x=[BUDDY_X], y=[BUDDY_Y]
	add [BUDDY_Y], 0x0004
	sub [BUDDY_X], 0x0004
	video offset=CINEMATIC_344, x=[BUDDY_X], y=[BUDDY_Y]
	sub [BUDDY_Y], 0x0004
	selectVideoPage 0xFF

LABEL_02C1:
	mov [0x12], 0x0003
	break
	mov [0x29], 0x032C
	mov [0x2F], 0x0019
	jmp DISPATCH_VAR2F_STATE
LABEL_02D1:
	db 0x11

LABEL_02D2:
	call GUARDED_DRAW_CV_304_305
	break
	jmp LABEL_02D2
LABEL_02D9:
	db 0x11

LABEL_02DA:
	call GUARDED_ALIEN_ANIM_CV_128
	break
	call LABEL_8C2A
	break
	and [0x11], 0xEFFF
	mov [0x29], 0x0000
	jmp LABEL_4D44
LABEL_02ED:
	db 0x11
