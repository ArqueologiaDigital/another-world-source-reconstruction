ANIM_CIN_438_LOOP_VAR29__DOS__POST_FOLD_BODY_89B_179104BB:
	video type=1, offset=CINEMATIC_438, x=[0x07], y=[0x08], zoom=0x40
	break
	djnz [0x29], ANIM_CIN_438_LOOP_VAR29__DOS__POST_FOLD_BODY_89B_179104BB
	add [0x08], 0x0005
	video type=1, offset=CINEMATIC_439, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=1, offset=CINEMATIC_440, x=[0x07], y=[0x08], zoom=0x40
	mov [0x0E], 0x0001
	mov [0x29], 0x0003

LABEL_19BD:
	break
	call GUARDED_HERO_ANIM_CV_128
	djnz [0x29], LABEL_19BD
	break
	mov [0x0E], 0x0000
	call GUARDED_HERO_ANIM_CV_128
	mov [0x0E], 0x0002
	mov [0x29], 0x0003

LABEL_19D5:
	break
	call GUARDED_HERO_ANIM_CV_128
	djnz [0x29], LABEL_19D5
	mov [0x0E], 0x0002
	mov [0x29], 0x0002

LABEL_19E5:
	break
	call GUARDED_HERO_ANIM_CV_128
	djnz [0x29], LABEL_19E5
	break
	call LABEL_62AE
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

LABEL_1A10:
	break
	call GUARDED_DRAW_CIN_242_243
	djnz [0x29], LABEL_1A10
	break
	call LABEL_570E
	sub [0x07], 0x0001
	break
	call GUARDED_DRAW_CIN_342
	add [0x07], 0x0001
	break
	call LABEL_628D
	call INLINE_OR_VAR11_WITH_1000
	add [0x07], 0x0001
	mov [0x29], 0x0003

LABEL_1A37:
	break
	call GUARDED_HERO_ANIM_CV_128
	djnz [0x29], LABEL_1A37
	break
	call LABEL_60AF
	add [0x07], 0x0003
	break
	call LABEL_60D0
	add [0x07], 0x0003
	break
	call LABEL_60F6
	add [0x07], 0x0003
	break
	call GUARDED_HERO_ANIM_CV_291
	video type=1, offset=CINEMATIC_441, x=[0x07], y=[0x08], zoom=0x40
	break
	call GUARDED_HERO_ANIM_CV_291
	video type=1, offset=CINEMATIC_442, x=[0x07], y=[0x08], zoom=0x40
	break
	call GUARDED_HERO_ANIM_CV_291
	video type=1, offset=CINEMATIC_443, x=[0x07], y=[0x08], zoom=0x40
	break
	call GUARDED_HERO_ANIM_CV_291
	play id=0x0060, freq=0x0F, vol=0x40, channel=0x00
	video type=1, offset=CINEMATIC_444, x=[0x07], y=[0x08], zoom=0x40
	break
	call GUARDED_HERO_ANIM_CV_291
	video type=1, offset=CINEMATIC_443, x=[0x07], y=[0x08], zoom=0x40
	break
	call GUARDED_HERO_ANIM_CV_291
	video type=1, offset=CINEMATIC_442, x=[0x07], y=[0x08], zoom=0x40
	break
	call GUARDED_HERO_ANIM_CV_291
	play id=0x0060, freq=0x0F, vol=0x40, channel=0x00
	video type=1, offset=CINEMATIC_444, x=[0x07], y=[0x08], zoom=0x40
	break
	call GUARDED_HERO_ANIM_CV_291
	video type=1, offset=CINEMATIC_443, x=[0x07], y=[0x08], zoom=0x40
	break
	call GUARDED_HERO_ANIM_CV_291
	video type=1, offset=CINEMATIC_442, x=[0x07], y=[0x08], zoom=0x40
	break
	call GUARDED_HERO_ANIM_CV_291
	video type=1, offset=CINEMATIC_441, x=[0x07], y=[0x08], zoom=0x40
	mov [0x29], 0x0008

LABEL_1AC1:
	break
	call GUARDED_HERO_ANIM_CV_128
	djnz [0x29], LABEL_1AC1
	break
	call GUARDED_HERO_ANIM_CV_291
	video type=1, offset=CINEMATIC_441, x=[0x07], y=[0x08], zoom=0x40
	play id=0x0073, freq=0x14, vol=0x30, channel=0x01
	break
	call GUARDED_HERO_ANIM_CV_291
	video type=1, offset=CINEMATIC_445, x=[0x07], y=[0x08], zoom=0x40
	break
	call GUARDED_HERO_ANIM_CV_291
	video type=1, offset=CINEMATIC_445, x=[0x07], y=[0x08], zoom=0x40
	break
	call GUARDED_HERO_ANIM_CV_291
	video type=1, offset=CINEMATIC_446, x=[0x07], y=[0x08], zoom=0x40
	break
	call GUARDED_HERO_ANIM_CV_291
	video type=1, offset=CINEMATIC_447, x=[0x07], y=[0x08], zoom=0x40
	break
	call GUARDED_HERO_ANIM_CV_291
	video type=1, offset=CINEMATIC_447, x=[0x07], y=[0x08], zoom=0x40
	break
	call GUARDED_HERO_ANIM_CV_291
	video type=1, offset=CINEMATIC_442, x=[0x07], y=[0x08], zoom=0x40
	break
	call GUARDED_HERO_ANIM_CV_291
	video type=1, offset=CINEMATIC_441, x=[0x07], y=[0x08], zoom=0x40
	mov [0x29], 0x0003

LABEL_1B1B:
	break
	call GUARDED_HERO_ANIM_CV_128
	djnz [0x29], LABEL_1B1B
	break
	mov [0x0E], 0x0000
	call GUARDED_HERO_ANIM_CV_128
	break
	mov [0x29], 0x01A4
	mov [0x2F], 0x0019
	jmp DISPATCH_VAR2F_STATE
LABEL_1B37:
	db 0x11

LABEL_1B38:
	jg [0x29], 0x00, DECREMENT_VAR29_BY_1
	je [0x29], 0x00, LABEL_1B73
	jne [0x29], 0xFFFE, LABEL_1B56
	mov [0x29], 0x0005
	mov [0x0E], 0x0002
	jmp DECREMENT_VAR29_BY_1

LABEL_1B56:
	jne [0x29], 0xFFFF, LABEL_1B68
	mov [0x29], 0x0005
	mov [0x0E], 0x0001
	jmp DECREMENT_VAR29_BY_1

LABEL_1B68:
	mov [0x0E], 0x0000
	mov [0x29], 0x000A
	jmp DECREMENT_VAR29_BY_1

LABEL_1B73:
	call COPY_HASH_AND_SPLIT_VAR38_3F_3E
	jl [0x3A], 0x03, LABEL_1B8F
	mov [0x0E], 0x0000
	jne [0x3B], 0x05, SET_VAR29_TO_000A
	mov [0x0D], 0x0001
