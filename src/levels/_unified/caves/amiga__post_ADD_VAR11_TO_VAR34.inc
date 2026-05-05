LABEL_76CB:
	jg [0x34], [0x2B], LABEL_76D4
	mov [0x34], [0x2B]

LABEL_76D4:
	jle [0x34], [0x2C], LABEL_76DD
	mov [0x34], [0x2C]

LABEL_76DD:
	mov [0x35], [0x10]
	jmp LABEL_76FB

LABEL_76E3:
	add [0x35], 0x0008
	je [0x34], 0x00, LABEL_76FB
	sub [0x34], 0x0002
	jge [0x34], 0x00, LABEL_76FB
	mov [0x34], 0x0000

LABEL_76FB:
	jge [0x0E], 0x00, SHARED_RET
	mov [0x0E], [0x34]
	mov [0x34], 0x0000
	sub [0x34], [0x0E]
	ret
LABEL_770C:
	db 0x11

LABEL_770D:
	mov [0x21], [HERO_X]
	mov [0x22], [HERO_Y]
	mov [0x23], 0x0000
	mov [0xF8], [0x04]
	and [0xF8], 0x0010
	sub [0x21], 0x0014
	je [0xF8], 0x00, LABEL_772C
	add [0x21], 0x0028

LABEL_772C:
	call LABEL_798A
	sub [0x22], [HERO_Y]
	call LABEL_7B32
	jl [0x22], 0x10, SHARED_RET
	setup channel=0x14, address=LABEL_7847
	mov [0x35], 0x0000
	sub [0x34], 0x000D
	add [HERO_X], 0x0019
	je [0xF8], 0x00, SHARED_RET
	sub [HERO_X], 0x0032
	add [0x34], 0x001A
	ret

LABEL_775A:
	mov [0x63], 0x0064
	call INIT_VAR2B_2C_FROM_VAR01_VAR29_10
	mov [0x34], 0xFFFB
	mov [0x35], 0x0008
	call SET_VAR04_TO_0024
	setup channel=0x14, address=LABEL_7847
	jge [0x2B], [HERO_X], SHARED_RET
	mov [0x34], 0x0005
	call SET_VAR04_TO_0034
	setup channel=0x14, address=LABEL_7847
	ret

LABEL_7782:
	mov [0x2F], [0x35]
	call LABEL_75DB
	mov [0x34], 0x0000
	jg [HERO_Y], 0xF0, LABEL_7798
	jge [HERO_Y], [0x22], LABEL_77C3

LABEL_7798:
	jl [0x04], 0x00, LABEL_77BF
	jl [0x2F], 0x1E, LABEL_77AC
	video offset=CINEMATIC_601, x=[HERO_X], y=[HERO_Y]
	jmp LABEL_77BF

LABEL_77AC:
	jl [0x2F], 0x14, LABEL_77BA
	video offset=CINEMATIC_600, x=[HERO_X], y=[HERO_Y]
	jmp LABEL_77BF

LABEL_77BA:
	video offset=CINEMATIC_599, x=[HERO_X], y=[HERO_Y]

LABEL_77BF:
	break
	jmp LABEL_7782

LABEL_77C3:
	jl [0x2F], 0x1E, LABEL_7816
	mov [SCROLL_Y], 0xFFFC
	je [HACK_VAR_67], 0xAF, LABEL_77D7
	setup channel=0x3C, address=LABEL_3D52

LABEL_77D7:
	video offset=CINEMATIC_602, x=[HERO_X], y=[HERO_Y]
	call DRAW_CIN_212_THEN_CIN_212
	break
	video offset=CINEMATIC_603, x=[HERO_X], y=[HERO_Y]
	call DRAW_CIN_212_THEN_CIN_212
	break
	video offset=CINEMATIC_604, x=[HERO_X], y=[HERO_Y]
	call DRAW_CIN_212_THEN_CIN_212
	mov [0x03], 0x0032
	play id=0x007A, freq=0x14, vol=0x40, channel=0x00
	play id=0x005E, freq=0x0A, vol=0x40, channel=0x01
	setup channel=0x3F, address=LABEL_016F

LABEL_7805:
	break
	or [0x04], 0x4000
	video offset=CINEMATIC_605, x=[HERO_X], y=[HERO_Y]
	call DRAW_CIN_212_THEN_CIN_212
	jmp LABEL_7805
LABEL_7815:
	db 0x11

LABEL_7816:
	jl [0x04], 0x00, KILL_CHAN_AT_7830
	mov [SCROLL_Y], 0x0001
	setup channel=0x3C, address=LABEL_3D52
	play id=0x005E, freq=0x14, vol=0x30, channel=0x01
	call SET_VAR04_TO_0008
	jmp LABEL_E2C9

KILL_CHAN_AT_7830:
	killChannel

DRAW_CIN_212_THEN_CIN_212:
	video offset=CINEMATIC_212, x=320, y=184
	video offset=CINEMATIC_212, x=16, y=184
	ret

LABEL_783B:
	video offset=CINEMATIC_212, x=160, y=19
	break
	jl [HERO_Y], 0x64, LABEL_783B
	killChannel

LABEL_7847:
	mov [0x2D], [0x35]
	mov [0x2E], [HERO_X]
	mov [0x2F], [HERO_Y]
	call LABEL_75DB
	jl [0x2F], [0x22], LABEL_7875
	mov [0xF8], [0x2F]
	sub [0xF8], [0x22]
	jl [0xF8], 0x09, LABEL_7875
	mov [HERO_X], [0x2E]
	mov [HERO_Y], [0x2F]
	add [HERO_Y], [0x35]
	mov [0x34], 0x0000
	jmp LABEL_787B

LABEL_7875:
	jge [HERO_Y], [0x22], LABEL_78B6

LABEL_787B:
	mov [0xF8], [0x04]
	and [0xF8], 0x0010
	je [0xF8], 0x10, LABEL_7891
	video offset=CINEMATIC_169, x=[HERO_X], y=[HERO_Y]
	break
	jmp LABEL_7847

LABEL_7891:
	jl [0x34], 0x05, LABEL_789F
	video offset=CINEMATIC_168, x=[HERO_X], y=[HERO_Y]
	jmp LABEL_78B2

LABEL_789F:
	jl [0x34], 0x03, LABEL_78AD
	video offset=CINEMATIC_167, x=[HERO_X], y=[HERO_Y]
	jmp LABEL_78B2

LABEL_78AD:
	video offset=CINEMATIC_167, x=[HERO_X], y=[HERO_Y]

LABEL_78B2:
	break
	jmp LABEL_7847

LABEL_78B6:
	mov [0xF8], [0x04]
	play id=0x0060, freq=0x14, vol=0x40, channel=0x01
	and [0xF8], 0x0010
	je [0xF8], 0x10, LABEL_7905
	je [HACK_VAR_67], 0x88, LABEL_78EF
	je [HACK_VAR_67], 0x89, LABEL_78EF
	video offset=CINEMATIC_160, x=[HERO_X], y=[HERO_Y]
	break
	mov [0x03], 0x0003
	play id=0x0060, freq=0x14, vol=0x40, channel=0x00

ANIM_CIN_166_LOOP_VAR03:
	video offset=CINEMATIC_166, x=[HERO_X], y=[HERO_Y]
	break
	djnz [0x03], ANIM_CIN_166_LOOP_VAR03

LABEL_78EF:
	mov [0x63], 0x0001
	call SET_VAR04_TO_0020
	video offset=CINEMATIC_160, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_161, x=[HERO_X], y=[HERO_Y]
	jmp HERO_WALK_LEFT_LOOP
LABEL_7904:
	db 0x11

LABEL_7905:
	je [HACK_VAR_67], 0x88, LABEL_7934
	je [HACK_VAR_67], 0x89, LABEL_7934
	video offset=CINEMATIC_158, x=[HERO_X], y=[HERO_Y]
	break
	mov [0x03], 0x0003
	call DERIVE_HASH_BUCKETS_FROM_VAR38
	jg [0x3A], 0x01, ANIM_CV_332_LOOP_VAR03
	play id=0x0079, freq=0x14, vol=0x40, channel=0x01

ANIM_CV_332_LOOP_VAR03:
	video type=0, offset=COMMON_VIDEO_332, x=[HERO_X], y=[HERO_Y], zoom=0x40
	break
	djnz [0x03], ANIM_CV_332_LOOP_VAR03

LABEL_7934:
	mov [0x63], 0x0002
	call SET_VAR04_TO_0020
	video offset=CINEMATIC_158, x=[HERO_X], y=[HERO_Y]
	break
	video offset=CINEMATIC_159, x=[HERO_X], y=[HERO_Y]
	jmp HERO_WALK_RIGHT_LOOP
LABEL_7949:
	db 0x11

LABEL_794A:
	call LABEL_75DB
	mov [0x63], 0x0064
	call SET_VAR04_TO_0034
	mov [0x2B], [0x23]
	and [0x2B], 0x000F
	je [0x34], 0x00, LABEL_796F
	jl [0x34], 0x00, LABEL_796A
	jmp LABEL_796A

LABEL_796A:
	break
	jmp LABEL_794A
LABEL_796E:
	db 0x11

LABEL_796F:
	sub [HERO_X], 0x0001
	break
	mov [0x63], 0x0001
	jmp LABEL_E4EC
LABEL_797B:
	db 0x11

LABEL_797C:
	mov [0x21], [HERO_X]
	mov [0x22], [HERO_Y]
	mov [0x23], 0x0000
	call LABEL_798A
	ret

LABEL_798A:
	je [HACK_VAR_67], 0x25, LABEL_B112
	je [HACK_VAR_67], 0x28, LABEL_BC9B
	je [HACK_VAR_67], 0x48, LABEL_BC2E
	je [HACK_VAR_67], 0x49, LABEL_BC49
	je [HACK_VAR_67], 0x4A, LABEL_BC71
	je [HACK_VAR_67], 0x4C, LABEL_BD60
	je [HACK_VAR_67], 0x4D, LABEL_BD82
	je [HACK_VAR_67], 0xC8, LABEL_B76D
	je [HACK_VAR_67], 0xC9, LABEL_B835
	je [HACK_VAR_67], 0xCA, LABEL_B95A
	je [HACK_VAR_67], 0xCB, LABEL_BAD3
	je [HACK_VAR_67], 0xCC, LABEL_BAD3
	je [HACK_VAR_67], 0xCD, LABEL_BB30
	je [HACK_VAR_67], 0xED, LABEL_BBDA
	je [HACK_VAR_67], 0xCE, LABEL_BAD3
	je [HACK_VAR_67], 0x67, LABEL_B229
	je [HACK_VAR_67], 0x68, LABEL_B2E2
	je [HACK_VAR_67], 0x69, LABEL_BDAA
	je [HACK_VAR_67], 0x6A, LABEL_BC71
	je [HACK_VAR_67], 0x6B, LABEL_BE7F
	je [HACK_VAR_67], 0x6D, LABEL_BEDA
	je [HACK_VAR_67], 0x85, LABEL_B18E
	je [HACK_VAR_67], 0x87, LABEL_B40D
	je [HACK_VAR_67], 0x88, LABEL_BCC0
	je [HACK_VAR_67], 0x89, LABEL_BF79
	je [HACK_VAR_67], 0x8A, LABEL_C0C9
	je [HACK_VAR_67], 0xAF, LABEL_BC01
	je [HACK_VAR_67], 0xA6, LABEL_B1EC
	je [HACK_VAR_67], 0xA7, LABEL_B542
	je [HACK_VAR_67], 0xA8, LABEL_B751
	je [HACK_VAR_67], 0xA9, INIT_VARS_01_22
	je [HACK_VAR_67], 0x6F, LABEL_BBEA
	je [HACK_VAR_67], 0x71, LABEL_BC18
	jg [0x22], [0x41], COPY_VAR40_TO_VAR22
	mov [0x22], [0x44]
	ret
