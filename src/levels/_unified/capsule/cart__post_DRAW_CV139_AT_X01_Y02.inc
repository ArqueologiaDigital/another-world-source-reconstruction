LABEL_7177:
	break
	jmp LABEL_713A

LABEL_717B:
	jl [0x2F], 0x1E, LABEL_71BA
	mov [SCROLL_Y], 0xFFFC
	video type=1, offset=CINEMATIC_086, x=[0x01], y=[0x02], zoom=0x40
	song id=0x0BDD, delay=0x0000, pos=0x00
	call LABEL_71CF
	break
	video type=1, offset=CINEMATIC_087, x=[0x01], y=[0x02], zoom=0x40
	call LABEL_71CF
	break
	video type=1, offset=CINEMATIC_088, x=[0x01], y=[0x02], zoom=0x40
	call LABEL_71CF
	or [0x04], 0x4000
	setup channel=0x3F, address=BREAK_5X_THEN_INIT_VAR03_14

LABEL_71AD:
	break
	video type=1, offset=CINEMATIC_089, x=[0x01], y=[0x02], zoom=0x40
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
	video type=1, offset=CINEMATIC_084, x=320, y=184, zoom=0x40
	video type=1, offset=CINEMATIC_084, x=16, y=184
	je [0xDB], 0x00, SHARED_RET
	video type=1, offset=CINEMATIC_085, x=[0x01], y=[0x02], zoom=0x40
	ret

JUNK__71E4:
	video type=1, offset=CINEMATIC_084, x=160, y=19
	break
	jl [0x02], 0x64, JUNK__71E4
	killChannel

LABEL_71F0:
	mov [0x2D], [0x35]
	mov [0x2E], [0x01]
	mov [0x2F], [0x02]
	call LABEL_6F93
	jl [0x2F], [0x22], LABEL_721E
	mov [0xF8], [0x2F]
	sub [0xF8], [0x22]
	jl [0xF8], 0x09, LABEL_721E
	mov [0x01], [0x2E]
	mov [0x02], [0x2F]
	add [0x02], [0x35]
	mov [0x34], 0x0000
	jmp LABEL_7224

LABEL_721E:
	jge [0x02], [0x22], LABEL_725F

LABEL_7224:
	mov [0xF8], [0x04]
	and [0xF8], 0x0010
	je [0xF8], 0x10, LABEL_723A
	video type=1, offset=CINEMATIC_081, x=[0x01], y=[0x02], zoom=0x40
	break
	jmp LABEL_71F0

LABEL_723A:
	jl [0x34], 0x05, LABEL_7248
	video type=1, offset=CINEMATIC_080, x=[0x01], y=[0x02], zoom=0x40
	jmp LABEL_725B

LABEL_7248:
	jl [0x34], 0x03, LABEL_7256
	video type=1, offset=CINEMATIC_079, x=[0x01], y=[0x02], zoom=0x40
	jmp LABEL_725B

LABEL_7256:
	video type=1, offset=CINEMATIC_079, x=[0x01], y=[0x02], zoom=0x40

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
	video type=1, offset=CINEMATIC_076, x=[0x01], y=[0x02], zoom=0x40
	break
	mov [0x03], 0x0003
	play id=0x0060, freq=0x14, vol=0x40, channel=0x00

ANIM_CIN_078_LOOP_VAR03_AT_728E:
	video type=1, offset=CINEMATIC_078, x=[0x01], y=[0x02], zoom=0x40
	break
	djnz [0x03], ANIM_CIN_078_LOOP_VAR03_AT_728E

LABEL_7298:
	mov [0x63], 0x0001
	call SET_VAR04_TO_0020
	video type=1, offset=CINEMATIC_076, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_077, x=[0x01], y=[0x02], zoom=0x40
	jmp HERO_WALK_LEFT_LOOP
LABEL_72AD:
	db 0x11

LABEL_72AE:
	je [HACK_VAR_67], 0x88, LABEL_72DD
	je [HACK_VAR_67], 0x89, LABEL_72DD
	video type=1, offset=CINEMATIC_073, x=[0x01], y=[0x02], zoom=0x40
	break
	mov [0x03], 0x0003
	call DERIVE_HASH_BUCKETS_FROM_VAR38
	jg [0x3A], 0x01, ANIM_CV_335_LOOP_VAR03__CART__POST_DRAW_CV139_AT_X01_Y02
	play id=0x0079, freq=0x14, vol=0x40, channel=0x01

ANIM_CV_335_LOOP_VAR03__CART__POST_DRAW_CV139_AT_X01_Y02:
	video type=0, offset=COMMON_VIDEO_335, x=[0x01], y=[0x02], zoom=0x40
	break
	djnz [0x03], ANIM_CV_335_LOOP_VAR03__CART__POST_DRAW_CV139_AT_X01_Y02

LABEL_72DD:
	mov [0x63], 0x0002
	call SET_VAR04_TO_0030
	video type=1, offset=CINEMATIC_073, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_074, x=[0x01], y=[0x02], zoom=0x40
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
	sub [0x01], 0x0001
	break
	mov [0x63], 0x0001
	jmp LABEL_BDA2
LABEL_7324:
	db 0x11

LABEL_7325:
	mov [0x21], [0x01]
	mov [0x22], [0x02]
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
