LABEL_7177:
	break
	jmp LABEL_713A

LABEL_717B:
	jl [0x2F], 0x1E, LABEL_71BA
	mov [SCROLL_Y], 0xFFFC
	video offset=CINEMATIC_086, x=[HERO_X], y=[HERO_Y]
	song id=0x0BDD, delay=0x0000, pos=0x00
	call LABEL_71CF
	break
	video offset=CINEMATIC_087, x=[HERO_X], y=[HERO_Y]
	call LABEL_71CF
	break
	video offset=CINEMATIC_088, x=[HERO_X], y=[HERO_Y]
	call LABEL_71CF
	or [0x04], 0x4000
	setup channel=0x3F, address=BREAK_5X_THEN_INIT_VAR03_14

LABEL_71AD:
	break
	video offset=CINEMATIC_089, x=[HERO_X], y=[HERO_Y]
	call LABEL_71CF
	jmp LABEL_71AD
LABEL_71B9:
	db 0x11

LABEL_71BA:
	jl [0x04], 0x00, KILL_CHAN_AT_71CE
	mov [SCROLL_Y], 0x0001
	setup channel=0x3C, address=LABEL_2FF0
	call SET_VAR04_TO_0008
	jmp LABEL_BB1B

KILL_CHAN_AT_71CE:
	killChannel

LABEL_71CF:
	video offset=CINEMATIC_084, x=320, y=184
	video offset=CINEMATIC_084, x=16, y=184
	je [0xDB], 0x00, SHARED_RET
	video offset=CINEMATIC_085, x=[HERO_X], y=[HERO_Y]
	ret

JUNK__71E4:
	video offset=CINEMATIC_084, x=160, y=19
	break
	jl [HERO_Y], 0x64, JUNK__71E4
	killChannel

LABEL_71F0:
	mov [0x2D], [0x35]
	mov [0x2E], [HERO_X]
	mov [0x2F], [HERO_Y]
	call LABEL_6F93
	jl [0x2F], [0x22], LABEL_721E
	mov [0xF8], [0x2F]
	sub [0xF8], [0x22]
	jl [0xF8], 0x09, LABEL_721E
	mov [HERO_X], [0x2E]
	mov [HERO_Y], [0x2F]
	add [HERO_Y], [0x35]
	mov [0x34], 0x0000
	jmp LABEL_7224

LABEL_721E:
	jge [HERO_Y], [0x22], LABEL_725F

LABEL_7224:
	mov [0xF8], [0x04]
	and [0xF8], 0x0010
	je [0xF8], 0x10, LABEL_723A
	video offset=CINEMATIC_081, x=[HERO_X], y=[HERO_Y]
	break
	jmp LABEL_71F0

LABEL_723A:
	jl [0x34], 0x05, LABEL_7248
	video offset=CINEMATIC_080, x=[HERO_X], y=[HERO_Y]
	jmp LABEL_725B

LABEL_7248:
	jl [0x34], 0x03, LABEL_7256
	video offset=CINEMATIC_079, x=[HERO_X], y=[HERO_Y]
	jmp LABEL_725B

LABEL_7256:
	video offset=CINEMATIC_079, x=[HERO_X], y=[HERO_Y]

LABEL_725B:
	break
	jmp LABEL_71F0

LABEL_725F:
	mov [0xF8], [0x04]
	and [0xF8], 0x0010
	play id=0x0060, freq=0x14, vol=0x40, channel=0x01
	je [0xF8], 0x10, LABEL_72AE
	je [HACK_VAR_67], 0x88, LABEL_7298
	je [HACK_VAR_67], 0x89, LABEL_7298
	video offset=CINEMATIC_076, x=[HERO_X], y=[HERO_Y]
	break
	mov [0x03], 0x0003
	play id=0x0060, freq=0x14, vol=0x40, channel=0x00

ANIM_CIN_078_LOOP_VAR03_AT_728E:
	video offset=CINEMATIC_078, x=[HERO_X], y=[HERO_Y]
	break
	djnz [0x03], ANIM_CIN_078_LOOP_VAR03_AT_728E

LABEL_7298:
	mov [0x63], 0x0001
	call SET_VAR04_TO_0020
	video offset=CINEMATIC_076, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_077, x=[HERO_X], y=[HERO_Y]
	jmp HERO_WALK_LEFT_LOOP
LABEL_72AD:
	db 0x11

LABEL_72AE:
	je [HACK_VAR_67], 0x88, LABEL_72DD
	je [HACK_VAR_67], 0x89, LABEL_72DD
	video offset=CINEMATIC_073, x=[HERO_X], y=[HERO_Y]
	break
	mov [0x03], 0x0003
	call DERIVE_HASH_BUCKETS_FROM_VAR38
	jg [0x3A], 0x01, ANIM_CV_335_LOOP_VAR03
	play id=0x0079, freq=0x14, vol=0x40, channel=0x01

ANIM_CV_335_LOOP_VAR03:
	video type=0, offset=COMMON_VIDEO_335, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	djnz [0x03], ANIM_CV_335_LOOP_VAR03

LABEL_72DD:
	mov [0x63], 0x0002
	call SET_VAR04_TO_0030
	video offset=CINEMATIC_073, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_074, x=[HERO_X], y=[HERO_Y]
	jmp HERO_WALK_RIGHT_LOOP
LABEL_72F2:
	db 0x11

LABEL_72F3:
	call LABEL_6F93
	mov [0x63], 0x0064
	call SET_VAR04_TO_0034
	mov [0x2B], [0x23]
	and [0x2B], 0x000F
	je [0x34], 0x00, LABEL_7318
	jl [0x34], 0x00, LABEL_7313
	jmp LABEL_7313

LABEL_7313:
	break
	jmp LABEL_72F3
LABEL_7317:
	db 0x11

LABEL_7318:
	sub [HERO_X], 0x0001
	break
	mov [0x63], 0x0001
	jmp LABEL_BDA2
LABEL_7324:
	db 0x11

LABEL_7325:
	mov [0x21], [HERO_X]
	mov [0x22], [HERO_Y]
	mov [0x23], 0x0000
	call LABEL_7333
	ret

LABEL_7333:
	je [HACK_VAR_67], 0x4D, SHARED_RET
	je [HACK_VAR_67], 0x2A, LABEL_A11C
	je [HACK_VAR_67], 0x6A, LABEL_A05D
	je [HACK_VAR_67], 0x6C, LABEL_A0F0
	je [HACK_VAR_67], 0x6D, LABEL_A106
	je [HACK_VAR_67], 0x6E, LABEL_9FF0
	je [HACK_VAR_67], 0x8A, LABEL_A154
	je [HACK_VAR_67], 0x8B, LABEL_A199
	je [HACK_VAR_67], 0x8D, LABEL_A12B
	je [HACK_VAR_67], 0xAB, LABEL_A32E
	je [HACK_VAR_67], 0xCB, LABEL_9F14
	jg [0x22], [0x41], COPY_VAR40_TO_VAR22
	mov [0x22], [0x44]
	ret
