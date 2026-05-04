DELAY_LOOP_VARF1__CART__POST_INLINE_SET_VARF1_TO_64:
	break
	djnz [0xF1], DELAY_LOOP_VARF1__CART__POST_INLINE_SET_VARF1_TO_64
	and [0x49], 0x7F9F
	killChannel

DRAW_CIN_406_408_BLOCK:
	video type=1, offset=CINEMATIC_406, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=1, offset=CINEMATIC_407, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=1, offset=CINEMATIC_408, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=1, offset=CINEMATIC_409, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=1, offset=CINEMATIC_409, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=1, offset=CINEMATIC_408, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=1, offset=CINEMATIC_409, x=[0x07], y=[0x08], zoom=0x40
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_410, x=160, y=100
	selectVideoPage 0xFF
	break
	video type=1, offset=CINEMATIC_411, x=[0x07], y=[0x08], zoom=0x40

LABEL_198A:
	break
	video type=1, offset=CINEMATIC_412, x=[0x07], y=[0x08], zoom=0x40
	jg [0x01], 0xA0, LABEL_198A
	jl [0x01], 0x91, LABEL_198A
	mov [0xB6], 0x0001
	mov [0x2A], 0x0005
	mov [0x42], 0x0037
	mov [0x43], 0x0098
	setup channel=0x15, address=KILL_CHANNEL_LANDING
	setup channel=0x14, address=LABEL_0501
	setup channel=0x16, address=LABEL_0DB0
	break
	video type=1, offset=CINEMATIC_411, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=1, offset=CINEMATIC_409, x=[0x07], y=[0x08], zoom=0x40
	break
	video type=1, offset=CINEMATIC_408, x=[0x07], y=[0x08], zoom=0x40
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_413, x=160, y=36
	selectVideoPage 0xFF
	break
	video type=1, offset=CINEMATIC_407, x=[0x07], y=[0x08], zoom=0x40
	break
	call LABEL_64ED
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
	break

LABEL_19F8:
	call GUARDED_HERO_ANIM_CV_128
	break
	jmp LABEL_19F8
	add [0x07], 0x0001
	break
	call GUARDED_DRAW_CIN_342
	sub [0x07], 0x0001
	break
	call GUARDED_DRAW_CIN_338_339
	call AND_VAR11_WITH_EFFF
	sub [0x07], 0x0001
	break
	mov [0x2F], 0x0018
	mov [0x29], 0xFFF0
	jmp DISPATCH_VAR2F_STATE
LABEL_1A22:
	db 0x11
