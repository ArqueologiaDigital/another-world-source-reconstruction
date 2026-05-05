LABEL_18F2:
	break
	video offset=CINEMATIC_412, x=[BUDDY_X], y=[BUDDY_Y]
	jl [HERO_X], 0x8C, LABEL_18F2
	jl [HERO_X], 0x91, LABEL_18F2
	mov [0xB6], 0x0001
	mov [0x2A], 0x0005
	mov [0x42], 0x0037
	mov [0x43], 0x0098
	setup channel=0x14, address=LABEL_0481
	setup channel=0x16, address=LABEL_0D28
	break
	video offset=CINEMATIC_411, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_409, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_408, x=[BUDDY_X], y=[BUDDY_Y]
	selectVideoPage 0x00
	video offset=CINEMATIC_413, x=160, y=36
	selectVideoPage 0xFF
	break
	video offset=CINEMATIC_407, x=[BUDDY_X], y=[BUDDY_Y]
	break
	call LABEL_63EA
	break
	call LABEL_570E
	sub [BUDDY_X], 0x0001
	break
	call GUARDED_DRAW_CIN_342
	add [BUDDY_X], 0x0001
	break
	call LABEL_628D
	call INLINE_OR_VAR11_WITH_1000
	add [BUDDY_X], 0x0001
	break

LABEL_195C:
	call GUARDED_HERO_ANIM_CV_128
	break
	jmp LABEL_195C
	add [BUDDY_X], 0x0001
	break
	call GUARDED_DRAW_CIN_342
	sub [BUDDY_X], 0x0001
	break
	call GUARDED_DRAW_CIN_338_339
	call AND_VAR11_WITH_EFFF
	sub [BUDDY_X], 0x0001
	break
	mov [0x2F], 0x0018
	mov [0x29], 0xFFF0
	jmp DISPATCH_VAR2F_STATE
LABEL_1986:
	db 0x11
