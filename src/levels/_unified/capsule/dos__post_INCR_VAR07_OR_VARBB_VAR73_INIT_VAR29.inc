LABEL_0207:
	jne [0x10], [HACK_VAR_67], LABEL_0222
	video type=1, offset=CINEMATIC_124, x=[0x07], y=[0x08], zoom=0x40
	video type=1, offset=CINEMATIC_344, x=[0x07], y=[0x08], zoom=0x40
	video type=1, offset=CINEMATIC_125, x=[0x07], y=[0x08], zoom=0x40
	play id=0x005E, freq=0x1C, vol=0x40, channel=0x02

LABEL_0222:
	break
	jne [0x10], [HACK_VAR_67], LABEL_0238
	video type=1, offset=CINEMATIC_126, x=[0x07], y=[0x08], zoom=0x40
	video type=1, offset=CINEMATIC_344, x=[0x07], y=[0x08], zoom=0x40
	video type=1, offset=CINEMATIC_125, x=[0x07], y=[0x08], zoom=0x40

LABEL_0238:
	break
	jne [0x10], [HACK_VAR_67], LABEL_0254
	video type=1, offset=CINEMATIC_127, x=[0x07], y=[0x08], zoom=0x40
	video type=1, offset=CINEMATIC_344, x=[0x07], y=[0x08], zoom=0x40
	video type=1, offset=CINEMATIC_128, x=[0x07], y=[0x08], zoom=0x40
	play id=0x005E, freq=0x14, vol=0x40, channel=0x02

LABEL_0254:
	break
	jne [0x10], [HACK_VAR_67], LABEL_026A
	video type=1, offset=CINEMATIC_129, x=[0x07], y=[0x08], zoom=0x40
	video type=1, offset=CINEMATIC_344, x=[0x07], y=[0x08], zoom=0x40
	video type=1, offset=CINEMATIC_128, x=[0x07], y=[0x08], zoom=0x40

LABEL_026A:
	break
	jne [0x10], [HACK_VAR_67], LABEL_0280
	video type=1, offset=CINEMATIC_126, x=[0x07], y=[0x08], zoom=0x40
	video type=1, offset=CINEMATIC_344, x=[0x07], y=[0x08], zoom=0x40
	video type=1, offset=CINEMATIC_125, x=[0x07], y=[0x08], zoom=0x40

LABEL_0280:
	break
	jge [0x7B], 0x4000, LABEL_028C
	djnz [0x29], LABEL_0207

LABEL_028C:
	jne [0x10], [HACK_VAR_67], LABEL_02C1
	video type=1, offset=CINEMATIC_124, x=[0x07], y=[0x08], zoom=0x40
	video type=1, offset=CINEMATIC_344, x=[0x07], y=[0x08], zoom=0x40
	video type=1, offset=CINEMATIC_125, x=[0x07], y=[0x08], zoom=0x40
	play id=0x005E, freq=0x1C, vol=0x40, channel=0x02
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_345, x=[0x07], y=[0x08], zoom=0x40
	add [0x08], 0x0004
	sub [0x07], 0x0004
	video type=1, offset=CINEMATIC_344, x=[0x07], y=[0x08], zoom=0x40
	sub [0x08], 0x0004
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
