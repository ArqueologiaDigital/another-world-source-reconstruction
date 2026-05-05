LABEL_711F:
	break
	jmp LABEL_70E2

LABEL_7123:
	jl [0x2F], 0x1E, LABEL_715C
	mov [SCROLL_Y], 0xFFFC
	video offset=CINEMATIC_085, x=[HERO_X], y=[HERO_Y]
	call DRAW_CIN_084_THEN_CIN_084
	break
	video offset=CINEMATIC_086, x=[HERO_X], y=[HERO_Y]
	call DRAW_CIN_084_THEN_CIN_084
	break
	video offset=CINEMATIC_087, x=[HERO_X], y=[HERO_Y]
	call DRAW_CIN_084_THEN_CIN_084
	or [0x04], 0x4000
	setup channel=0x3F, address=BREAK_5X_THEN_INIT_VAR03_14

LABEL_714F:
	break
	video offset=CINEMATIC_088, x=[HERO_X], y=[HERO_Y]
	call DRAW_CIN_084_THEN_CIN_084
	jmp LABEL_714F
LABEL_715B:
	db 0x11

LABEL_715C:
	jl [0x04], 0x00, KILL_CHAN_AT_7170
	mov [SCROLL_Y], 0x0001
	setup channel=0x3C, address=LABEL_2E73
	call SET_VAR04_TO_0008
	jmp LABEL_BA37

KILL_CHAN_AT_7170:
	killChannel

DRAW_CIN_084_THEN_CIN_084:
	video offset=CINEMATIC_084, x=320, y=184
	video offset=CINEMATIC_084, x=16, y=184
	ret

JUNK__717B:
	video offset=CINEMATIC_084, x=160, y=19
	break
	jl [HERO_Y], 0x64, JUNK__717B
	killChannel

LABEL_7187:
	mov [0x2D], [0x35]
	mov [0x2E], [HERO_X]
	mov [0x2F], [HERO_Y]
	call LABEL_6F3B
	jl [0x2F], [0x22], LABEL_71B5
	mov [0xF8], [0x2F]
	sub [0xF8], [0x22]
	jl [0xF8], 0x09, LABEL_71B5
	mov [HERO_X], [0x2E]
	mov [HERO_Y], [0x2F]
	add [HERO_Y], [0x35]
	mov [0x34], 0x0000
	jmp LABEL_71BB

LABEL_71B5:
	jge [HERO_Y], [0x22], LABEL_71F6

LABEL_71BB:
	mov [0xF8], [0x04]
	and [0xF8], 0x0010
	je [0xF8], 0x10, LABEL_71D1
	video offset=CINEMATIC_081, x=[HERO_X], y=[HERO_Y]
	break
	jmp LABEL_7187

LABEL_71D1:
	jl [0x34], 0x05, LABEL_71DF
	video offset=CINEMATIC_080, x=[HERO_X], y=[HERO_Y]
	jmp LABEL_71F2

LABEL_71DF:
	jl [0x34], 0x03, LABEL_71ED
	video offset=CINEMATIC_079, x=[HERO_X], y=[HERO_Y]
	jmp LABEL_71F2

LABEL_71ED:
	video offset=CINEMATIC_079, x=[HERO_X], y=[HERO_Y]

LABEL_71F2:
	break
	jmp LABEL_7187

LABEL_71F6:
	mov [0xF8], [0x04]
	and [0xF8], 0x0010
	play id=0x0060, freq=0x14, vol=0x40, channel=0x01
	je [0xF8], 0x10, LABEL_7245
	je [HACK_VAR_67], 0x88, LABEL_722F
	je [HACK_VAR_67], 0x89, LABEL_722F
	video offset=CINEMATIC_076, x=[HERO_X], y=[HERO_Y]
	break
	mov [0x03], 0x0003
	play id=0x0060, freq=0x14, vol=0x40, channel=0x00

ANIM_CIN_078_LOOP_VAR03_AT_7225:
	video offset=CINEMATIC_078, x=[HERO_X], y=[HERO_Y]
	break
	djnz [0x03], ANIM_CIN_078_LOOP_VAR03_AT_7225

LABEL_722F:
	mov [0x63], 0x0001
	call SET_VAR04_TO_0020
	video offset=CINEMATIC_076, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_077, x=[HERO_X], y=[HERO_Y]
	jmp HERO_WALK_LEFT_LOOP
LABEL_7244:
	db 0x11

LABEL_7245:
	je [HACK_VAR_67], 0x88, LABEL_7274
	je [HACK_VAR_67], 0x89, LABEL_7274
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

LABEL_7274:
	mov [0x63], 0x0002
	call SET_VAR04_TO_0030
	video offset=CINEMATIC_073, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_074, x=[HERO_X], y=[HERO_Y]
	jmp HERO_WALK_RIGHT_LOOP
LABEL_7289:
	db 0x11

LABEL_728A:
	call LABEL_6F3B
	mov [0x63], 0x0064
	call SET_VAR04_TO_0034
	mov [0x2B], [0x23]
	and [0x2B], 0x000F
	je [0x34], 0x00, LABEL_72AF
	jl [0x34], 0x00, LABEL_72AA
	jmp LABEL_72AA

LABEL_72AA:
	break
	jmp LABEL_728A
LABEL_72AE:
	db 0x11

LABEL_72AF:
	sub [HERO_X], 0x0001
	break
	mov [0x63], 0x0001
	jmp LABEL_BCBE
LABEL_72BB:
	db 0x11

LABEL_72BC:
	mov [0x21], [HERO_X]
	mov [0x22], [HERO_Y]
	mov [0x23], 0x0000
	call LABEL_72CA
	ret

LABEL_72CA:
	je [HACK_VAR_67], 0x4D, SHARED_RET
	je [HACK_VAR_67], 0x2A, LABEL_A0D8
	je [HACK_VAR_67], 0x6A, LABEL_A019
	je [HACK_VAR_67], 0x6C, LABEL_A0AC
	je [HACK_VAR_67], 0x6D, LABEL_A0C2
	je [HACK_VAR_67], 0x6E, LABEL_9FAC
	je [HACK_VAR_67], 0x8A, LABEL_A110
	je [HACK_VAR_67], 0x8B, LABEL_A155
	je [HACK_VAR_67], 0x8D, LABEL_A0E7
	je [HACK_VAR_67], 0xAB, LABEL_A2EA
	je [HACK_VAR_67], 0xCB, LABEL_9ED6
	jg [0x22], [0x41], COPY_VAR40_TO_VAR22
	mov [0x22], [0x44]
	ret
