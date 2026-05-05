LABEL_0274:
	jne [0x10], [HACK_VAR_67], LABEL_028F
	video offset=CINEMATIC_125, x=[0x07], y=[0x08]
	video offset=CINEMATIC_345, x=[0x07], y=[0x08]
	video offset=CINEMATIC_126, x=[0x07], y=[0x08]
	play id=0x005E, freq=0x1C, vol=0x40, channel=0x02

LABEL_028F:
	break
	jne [0x10], [HACK_VAR_67], LABEL_02A5
	video offset=CINEMATIC_127, x=[0x07], y=[0x08]
	video offset=CINEMATIC_345, x=[0x07], y=[0x08]
	video offset=CINEMATIC_126, x=[0x07], y=[0x08]

LABEL_02A5:
	break
	jne [0x10], [HACK_VAR_67], LABEL_02C1
	video offset=CINEMATIC_128, x=[0x07], y=[0x08]
	video offset=CINEMATIC_345, x=[0x07], y=[0x08]
	video offset=CINEMATIC_129, x=[0x07], y=[0x08]
	play id=0x005E, freq=0x14, vol=0x40, channel=0x02

LABEL_02C1:
	break
	jne [0x10], [HACK_VAR_67], LABEL_02D7
	video offset=CINEMATIC_130, x=[0x07], y=[0x08]
	video offset=CINEMATIC_345, x=[0x07], y=[0x08]
	video offset=CINEMATIC_129, x=[0x07], y=[0x08]

LABEL_02D7:
	break
	jne [0x10], [HACK_VAR_67], LABEL_02ED
	video offset=CINEMATIC_127, x=[0x07], y=[0x08]
	video offset=CINEMATIC_345, x=[0x07], y=[0x08]
	video offset=CINEMATIC_126, x=[0x07], y=[0x08]

LABEL_02ED:
	break
	jge [0x7B], 0x4000, LABEL_02F9
	djnz [0x29], LABEL_0274

LABEL_02F9:
	jne [0x10], [HACK_VAR_67], LABEL_032E
	video offset=CINEMATIC_125, x=[0x07], y=[0x08]
	video offset=CINEMATIC_345, x=[0x07], y=[0x08]
	video offset=CINEMATIC_126, x=[0x07], y=[0x08]
	play id=0x005E, freq=0x1C, vol=0x40, channel=0x02
	selectVideoPage 0x00
	video offset=CINEMATIC_346, x=[0x07], y=[0x08]
	add [0x08], 0x0004
	sub [0x07], 0x0004
	video offset=CINEMATIC_345, x=[0x07], y=[0x08]
	sub [0x08], 0x0004
	selectVideoPage 0xFF

LABEL_032E:
	mov [0x12], 0x0003
	break
	mov [0x29], 0x032C
	mov [0x2F], 0x0019
	jmp DISPATCH_VAR2F_STATE
LABEL_033E:
	db 0x11

LABEL_033F:
	call GUARDED_DRAW_CV_304_305
	break
	jmp LABEL_033F
LABEL_0346:
	db 0x11

LABEL_0347:
	call GUARDED_ALIEN_ANIM_CV_128
	break
	call LABEL_8C93
	break
	and [0x11], 0xEFFF
	mov [0x29], 0x0000
	jmp LABEL_4D20
LABEL_035A:
	db 0x11
