LABEL_585C:
	jg [0x34], [0x2B], LABEL_5865
	mov [0x34], [0x2B]

LABEL_5865:
	jle [0x34], [0x2C], LABEL_586E
	mov [0x34], [0x2C]

LABEL_586E:
	mov [0x35], [0x10]
	jmp LABEL_588C

LABEL_5874:
	add [0x35], 0x0008
	je [0x34], 0x00, LABEL_588C
	sub [0x34], 0x0002
	jge [0x34], 0x00, LABEL_588C
	mov [0x34], 0x0000

LABEL_588C:
	jge [0x0E], 0x00, SHARED_RET
	mov [0x0E], [0x34]
	mov [0x34], 0x0000
	sub [0x34], [0x0E]
	ret
LABEL_589D:
	db 0x11

LABEL_589E:
	mov [0x21], [0x01]
	mov [0x22], [0x02]
	mov [0x23], 0x0000
	mov [0xF8], [0x04]
	and [0xF8], 0x0010
	sub [0x21], 0x0014
	je [0xF8], 0x00, LABEL_58BD
	add [0x21], 0x0028

LABEL_58BD:
	call LABEL_5AE2
	sub [0x22], [0x02]
	call LABEL_5BCA
	jl [0x22], 0x10, SHARED_RET
	setup channel=0x14, address=LABEL_59BA
	mov [0x35], 0x0000
	sub [0x34], 0x000D
	add [0x01], 0x0019
	je [0xF8], 0x00, SHARED_RET
	sub [0x01], 0x0032
	add [0x34], 0x001A
	ret

LABEL_58EB:
	mov [0x63], 0x0064
	call INIT_VAR2B_2C_FROM_VAR01_VAR29_10
	mov [0x34], 0xFFFB
	mov [0x35], 0x0008
	call SET_VAR04_TO_0024
	setup channel=0x14, address=LABEL_59BA
	jge [0x2B], [0x01], SHARED_RET
	mov [0x34], 0x0005
	call SET_VAR04_TO_0034
	setup channel=0x14, address=LABEL_59BA
	ret

LABEL_5913:
	mov [0x2F], [0x35]
	call LABEL_576C
	mov [0x34], 0x0000
	jg [0x02], 0xF0, LABEL_5929
	jge [0x02], [0x22], LABEL_5954

LABEL_5929:
	jl [0x04], 0x00, LABEL_5950
	jl [0x2F], 0x1E, LABEL_593D
	video offset=CINEMATIC_297, x=[0x01], y=[0x02], zoom=0x40
	jmp LABEL_5950

LABEL_593D:
	jl [0x2F], 0x14, LABEL_594B
	video offset=CINEMATIC_296, x=[0x01], y=[0x02], zoom=0x40
	jmp LABEL_5950

LABEL_594B:
	video offset=CINEMATIC_295, x=[0x01], y=[0x02], zoom=0x40

LABEL_5950:
	break
	jmp LABEL_5913

LABEL_5954:
	jl [0x2F], 0x1E, LABEL_598F
	mov [SCROLL_Y], 0xFFFC
	je [HACK_VAR_67], 0xAF, LABEL_5968
	setup channel=0x3C, address=LABEL_21F2

LABEL_5968:
	video offset=CINEMATIC_299, x=[0x01], y=[0x02], zoom=0x40
	call DRAW_CIN_298_THEN_CIN_298
	break
	video offset=CINEMATIC_300, x=[0x01], y=[0x02], zoom=0x40
	call DRAW_CIN_298_THEN_CIN_298
	break
	video offset=CINEMATIC_301, x=[0x01], y=[0x02], zoom=0x40
	call DRAW_CIN_298_THEN_CIN_298

LABEL_5982:
	break
	video offset=CINEMATIC_302, x=[0x01], y=[0x02], zoom=0x40
	call DRAW_CIN_298_THEN_CIN_298
	jmp LABEL_5982
LABEL_598E:
	db 0x11

LABEL_598F:
	jl [0x04], 0x00, KILL_CHAN_AT_59A3
	mov [SCROLL_Y], 0x0001
	setup channel=0x3C, address=LABEL_21F2
	call SET_VAR04_TO_0008
	jmp LABEL_8ED3

KILL_CHAN_AT_59A3:
	killChannel

DRAW_CIN_298_THEN_CIN_298:
	video offset=CINEMATIC_298, x=320, y=184, zoom=0x40
	video offset=CINEMATIC_298, x=16, y=184
	ret
LABEL_59AE:
	db 0xC0, 0xE4, 0xA0, 0x13, 0x06, 0x0A, 0x04, 0x02
	db 0x64, 0x59, 0xAE, 0x11

LABEL_59BA:
	mov [0x2D], [0x35]
	mov [0x2E], [0x01]
	mov [0x2F], [0x02]
	call LABEL_576C
	jl [0x2F], [0x22], LABEL_59E8
	mov [0xF8], [0x2F]
	sub [0xF8], [0x22]
	jl [0xF8], 0x09, LABEL_59E8
	mov [0x01], [0x2E]
	mov [0x02], [0x2F]
	add [0x02], [0x35]
	mov [0x34], 0x0000
	jmp LABEL_59EE

LABEL_59E8:
	jge [0x02], [0x22], LABEL_5A29

LABEL_59EE:
	mov [0xF8], [0x04]
	and [0xF8], 0x0010
	je [0xF8], 0x10, LABEL_5A04
	video offset=CINEMATIC_112, x=[0x01], y=[0x02], zoom=0x40
	break
	jmp LABEL_59BA

LABEL_5A04:
	jl [0x34], 0x05, LABEL_5A12
	video offset=CINEMATIC_111, x=[0x01], y=[0x02], zoom=0x40
	jmp LABEL_5A25

LABEL_5A12:
	jl [0x34], 0x03, LABEL_5A20
	video offset=CINEMATIC_110, x=[0x01], y=[0x02], zoom=0x40
	jmp LABEL_5A25

LABEL_5A20:
	video offset=CINEMATIC_110, x=[0x01], y=[0x02], zoom=0x40

LABEL_5A25:
	break
	jmp LABEL_59BA

LABEL_5A29:
	mov [0xF8], [0x04]
	and [0xF8], 0x0010
	je [0xF8], 0x10, LABEL_5A6C
	je [HACK_VAR_67], 0x88, LABEL_5A56
	je [HACK_VAR_67], 0x89, LABEL_5A56
	video offset=CINEMATIC_107, x=[0x01], y=[0x02], zoom=0x40
	break
	mov [0x03], 0x0003

ANIM_CIN_109_LOOP_VAR03:
	video offset=CINEMATIC_109, x=[0x01], y=[0x02], zoom=0x40
	break
	djnz [0x03], ANIM_CIN_109_LOOP_VAR03

LABEL_5A56:
	mov [0x63], 0x0001
	call SET_VAR04_TO_0020
	video offset=CINEMATIC_107, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_108, x=[0x01], y=[0x02], zoom=0x40
	jmp HERO_WALK_LEFT_LOOP
LABEL_5A6B:
	db 0x11

LABEL_5A6C:
	je [HACK_VAR_67], 0x88, LABEL_5A8C
	je [HACK_VAR_67], 0x89, LABEL_5A8C
	video offset=CINEMATIC_084, x=[0x01], y=[0x02], zoom=0x40
	break
	mov [0x03], 0x0003

ANIM_CV_332_LOOP_VAR03:
	video type=0, offset=COMMON_VIDEO_332, x=[0x01], y=[0x02], zoom=0x40
	break
	djnz [0x03], ANIM_CV_332_LOOP_VAR03

LABEL_5A8C:
	mov [0x63], 0x0002
	call SET_VAR04_TO_0020
	video offset=CINEMATIC_084, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_085, x=[0x01], y=[0x02], zoom=0x40
	jmp HERO_WALK_RIGHT_LOOP
LABEL_5AA1:
	db 0x11

LABEL_5AA2:
	call LABEL_576C
	mov [0x63], 0x0064
	call SET_VAR04_TO_0034
	mov [0x2B], [0x23]
	and [0x2B], 0x000F
	je [0x34], 0x00, LABEL_5AC7
	jl [0x34], 0x00, LABEL_5AC2
	jmp LABEL_5AC2

LABEL_5AC2:
	break
	jmp LABEL_5AA2
LABEL_5AC6:
	db 0x11

LABEL_5AC7:
	sub [0x01], 0x0001
	break
	mov [0x63], 0x0001
	jmp LABEL_90F6
LABEL_5AD3:
	db 0x11

LABEL_5AD4:
	mov [0x21], [0x01]
	mov [0x22], [0x02]
	mov [0x23], 0x0000
	call LABEL_5AE2
	ret

LABEL_5AE2:
	je [HACK_VAR_67], 0x25, LABEL_8133
	jg [0x22], [0x41], COPY_VAR40_TO_VAR22
	mov [0x22], [0x44]
	ret
