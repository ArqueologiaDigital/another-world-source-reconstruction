ANIM_CIN_438_LOOP_VAR29:
	video offset=CINEMATIC_438, x=[0x07], y=[0x08], zoom=0x40
	break
	djnz [0x29], ANIM_CIN_438_LOOP_VAR29
	add [0x08], 0x0005
	video offset=CINEMATIC_439, x=[0x07], y=[0x08], zoom=0x40
	break
	video offset=CINEMATIC_440, x=[0x07], y=[0x08], zoom=0x40
	mov [0x0E], 0x0001
	mov [0x29], 0x0003

LABEL_1A59:
	break
	call GUARDED_HERO_ANIM_CV_128
	djnz [0x29], LABEL_1A59
	break
	mov [0x0E], 0x0000
	call GUARDED_HERO_ANIM_CV_128
	mov [0x0E], 0x0002
	mov [0x29], 0x0003

LABEL_1A71:
	break
	call GUARDED_HERO_ANIM_CV_128
	djnz [0x29], LABEL_1A71
	mov [0x0E], 0x0002
	mov [0x29], 0x0002

LABEL_1A81:
	break
	call GUARDED_HERO_ANIM_CV_128
	djnz [0x29], LABEL_1A81
	break
	call LABEL_63B1
	add [0x07], 0x0001
	break
	call GUARDED_DRAW_CIN_342
	sub [0x07], 0x0001
	break
	call GUARDED_DRAW_CIN_338_339
	call AND_VAR11_WITH_EFFF
	sub [0x07], 0x0001
	mov [0x29], 0x0008
	mov [0x0E], 0x0004

LABEL_1AAC:
	break
	call GUARDED_DRAW_CIN_242_243
	djnz [0x29], LABEL_1AAC
	break
	call LABEL_5811
	sub [0x07], 0x0001
	break
	call GUARDED_DRAW_CIN_342
	add [0x07], 0x0001
	break
	call LABEL_6390
	call INLINE_OR_VAR11_WITH_1000
	add [0x07], 0x0001
	mov [0x29], 0x0003

LABEL_1AD3:
	break
	call GUARDED_HERO_ANIM_CV_128
	djnz [0x29], LABEL_1AD3
	break
	call LABEL_61B2
	add [0x07], 0x0003
	break
	call LABEL_61D3
	add [0x07], 0x0003
	break
	call LABEL_61F9
	add [0x07], 0x0003
	break
	call GUARDED_HERO_ANIM_CV_291
	video offset=CINEMATIC_441, x=[0x07], y=[0x08], zoom=0x40
	break
	call GUARDED_HERO_ANIM_CV_291
	video offset=CINEMATIC_442, x=[0x07], y=[0x08], zoom=0x40
	break
	call GUARDED_HERO_ANIM_CV_291
	video offset=CINEMATIC_443, x=[0x07], y=[0x08], zoom=0x40
	break
	call GUARDED_HERO_ANIM_CV_291
	play id=0x0060, freq=0x0F, vol=0x40, channel=0x00
	video offset=CINEMATIC_444, x=[0x07], y=[0x08], zoom=0x40
	break
	call GUARDED_HERO_ANIM_CV_291
	video offset=CINEMATIC_443, x=[0x07], y=[0x08], zoom=0x40
	break
	call GUARDED_HERO_ANIM_CV_291
	video offset=CINEMATIC_442, x=[0x07], y=[0x08], zoom=0x40
	break
	call GUARDED_HERO_ANIM_CV_291
	play id=0x0060, freq=0x0F, vol=0x40, channel=0x00
	video offset=CINEMATIC_444, x=[0x07], y=[0x08], zoom=0x40
	break
	call GUARDED_HERO_ANIM_CV_291
	video offset=CINEMATIC_443, x=[0x07], y=[0x08], zoom=0x40
	break
	call GUARDED_HERO_ANIM_CV_291
	video offset=CINEMATIC_442, x=[0x07], y=[0x08], zoom=0x40
	break
	call GUARDED_HERO_ANIM_CV_291
	video offset=CINEMATIC_441, x=[0x07], y=[0x08], zoom=0x40
	mov [0x29], 0x0008

LABEL_1B5D:
	break
	call GUARDED_HERO_ANIM_CV_128
	djnz [0x29], LABEL_1B5D
	break
	call GUARDED_HERO_ANIM_CV_291
	video offset=CINEMATIC_441, x=[0x07], y=[0x08], zoom=0x40
	play id=0x0073, freq=0x14, vol=0x30, channel=0x01
	break
	call GUARDED_HERO_ANIM_CV_291
	video offset=CINEMATIC_445, x=[0x07], y=[0x08], zoom=0x40
	break
	call GUARDED_HERO_ANIM_CV_291
	video offset=CINEMATIC_445, x=[0x07], y=[0x08], zoom=0x40
	break
	call GUARDED_HERO_ANIM_CV_291
	video offset=CINEMATIC_446, x=[0x07], y=[0x08], zoom=0x40
	break
	call GUARDED_HERO_ANIM_CV_291
	video offset=CINEMATIC_447, x=[0x07], y=[0x08], zoom=0x40
	break
	call GUARDED_HERO_ANIM_CV_291
	video offset=CINEMATIC_447, x=[0x07], y=[0x08], zoom=0x40
	break
	call GUARDED_HERO_ANIM_CV_291
	video offset=CINEMATIC_442, x=[0x07], y=[0x08], zoom=0x40
	break
	call GUARDED_HERO_ANIM_CV_291
	video offset=CINEMATIC_441, x=[0x07], y=[0x08], zoom=0x40
	mov [0x29], 0x0003

LABEL_1BB7:
	break
	call GUARDED_HERO_ANIM_CV_128
	djnz [0x29], LABEL_1BB7
	break
	mov [0x0E], 0x0000
	call GUARDED_HERO_ANIM_CV_128
	break
	song id=0x0BC0, delay=0x0000, pos=0x00
	mov [0x29], 0x01A4
	mov [0x2F], 0x0019
	jmp DISPATCH_VAR2F_STATE
LABEL_1BD9:
	db 0x11

LABEL_1BDA:
	jg [0x29], 0x00, DECREMENT_VAR29_BY_1
	je [0x29], 0x00, LABEL_1C15
	jne [0x29], 0xFFFE, LABEL_1BF8
	mov [0x29], 0x0005
	mov [0x0E], 0x0002
	jmp DECREMENT_VAR29_BY_1

LABEL_1BF8:
	jne [0x29], 0xFFFF, LABEL_1C0A
	mov [0x29], 0x0005
	mov [0x0E], 0x0001
	jmp DECREMENT_VAR29_BY_1

LABEL_1C0A:
	mov [0x0E], 0x0000
	mov [0x29], 0x000A
	jmp DECREMENT_VAR29_BY_1

LABEL_1C15:
	call COPY_HASH_AND_SPLIT_VAR38_3F_3E
	jl [0x3A], 0x03, LABEL_1C31
	mov [0x0E], 0x0000
	jne [0x3B], 0x05, SET_VAR29_TO_000A
	mov [0x0D], 0x0001
