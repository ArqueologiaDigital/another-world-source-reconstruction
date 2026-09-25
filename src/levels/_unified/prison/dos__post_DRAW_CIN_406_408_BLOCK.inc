LABEL_18F2:
	break
	video offset=CINEMATIC_PRISON_FIGURE_LIFTING_BAR_F5, x=[ACTOR_X], y=[ACTOR_Y]
	jl [HERO_X], 0x8C, LABEL_18F2
	jl [HERO_X], 0x91, LABEL_18F2
	mov [0xB6], 0x0001
	mov [0x2A], 0x0005
	mov [0x42], 0x0037
	mov [0x43], 0x0098
	setup channel=0x14, address=LABEL_0481
	setup channel=0x16, address=LABEL_0D28
	break
	video offset=CINEMATIC_PRISON_FIGURE_LIFTING_BAR_F4, x=[ACTOR_X], y=[ACTOR_Y]
	break
	video offset=CINEMATIC_PRISON_FIGURE_LIFTING_BAR_F3, x=[ACTOR_X], y=[ACTOR_Y]
	break
	video offset=CINEMATIC_PRISON_FIGURE_LIFTING_BAR_F2, x=[ACTOR_X], y=[ACTOR_Y]
	selectVideoPage 0x00
	video offset=CINEMATIC_413, x=160, y=36
	selectVideoPage 0xFF
	break
	video offset=CINEMATIC_PRISON_FIGURE_LIFTING_BAR_F1, x=[ACTOR_X], y=[ACTOR_Y]
	break
	call LABEL_63EA
	break
	call LABEL_570E
	sub [ACTOR_X], 0x0001
	break
	call GUARDED_DRAW_CIN_342
	add [ACTOR_X], 0x0001
	break
	call PRISON_HERO_PER_FRAME_TICK_CIN164_168_VARIANT
	call INLINE_OR_VAR11_WITH_1000
	add [ACTOR_X], 0x0001
	break

LABEL_195C:
	call PRISON_ACTOR_WALK_RIGHT_DRAW_PHASE_02
	break
	jmp LABEL_195C
	add [ACTOR_X], 0x0001
	break
	call GUARDED_DRAW_CIN_342
	sub [ACTOR_X], 0x0001
	break
	call GUARDED_DRAW_CIN_338_339
	call AND_VAR11_WITH_EFFF
	sub [ACTOR_X], 0x0001
	break
	mov [0x2F], 0x0018
	mov [0x29], 0xFFF0
	jmp DISPATCH_VAR2F_STATE
LABEL_1986:
	db 0x11
