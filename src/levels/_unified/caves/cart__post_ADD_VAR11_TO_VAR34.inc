LABEL_7980:
	jg [0x34], [0x2B], LABEL_7989
	mov [0x34], [0x2B]

LABEL_7989:
	jle [0x34], [0x2C], LABEL_7992
	mov [0x34], [0x2C]

LABEL_7992:
	mov [0x35], [0x10]
	jmp LABEL_79B0

LABEL_7998:
	add [0x35], 0x0008
	je [0x34], 0x00, LABEL_79B0
	sub [0x34], 0x0002
	jge [0x34], 0x00, LABEL_79B0
	mov [0x34], 0x0000

LABEL_79B0:
	jge [0x0E], 0x00, SHARED_RET
	mov [0x0E], [0x34]
	mov [0x34], 0x0000
	sub [0x34], [0x0E]
	ret
LABEL_79C1:
	db 0x11

LABEL_79C2:
	je [HACK_VAR_67], 0x4A, SHARED_RET
	je [HACK_VAR_67], 0x6A, SHARED_RET
	mov [0x21], [0x01]
	mov [0x22], [0x02]
	mov [0x23], 0x0000
	mov [0xF8], [0x04]
	and [0xF8], 0x0010
	sub [0x21], 0x0014
	je [0xF8], 0x00, LABEL_79ED
	add [0x21], 0x0028

LABEL_79ED:
	call LABEL_7C5F
	sub [0x22], [0x02]
	call LABEL_7E07
	jl [0x22], 0x10, SHARED_RET
	setup channel=0x14, address=LABEL_7B1C
	mov [0x35], 0x0000
	sub [0x34], 0x000D
	add [0x01], 0x0019
	je [0xF8], 0x00, SHARED_RET
	sub [0x01], 0x0032
	add [0x34], 0x001A
	ret

LABEL_7A1B:
	mov [0x63], 0x0064
	call INIT_VAR2B_2C_FROM_VAR01_VAR29_10
	mov [0x34], 0xFFFB
	mov [0x35], 0x0008
	call SET_VAR04_TO_0024
	setup channel=0x14, address=LABEL_7B1C
	jge [0x2B], [0x01], SHARED_RET
	mov [0x34], 0x0005
	call SET_VAR04_TO_0034
	setup channel=0x14, address=LABEL_7B1C
	ret

LABEL_7A43:
	mov [0x2F], [0x35]
	call LABEL_7890
	mov [0x34], 0x0000
	jg [0x02], 0xF0, LABEL_7A59
	jge [0x02], [0x22], LABEL_7A84

LABEL_7A59:
	jl [0x04], 0x00, LABEL_7A80
	jl [0x2F], 0x1E, LABEL_7A6D
	video offset=CINEMATIC_612, x=[0x01], y=[0x02], zoom=0x40
	jmp LABEL_7A80

LABEL_7A6D:
	jl [0x2F], 0x14, LABEL_7A7B
	video offset=CINEMATIC_611, x=[0x01], y=[0x02], zoom=0x40
	jmp LABEL_7A80

LABEL_7A7B:
	video offset=CINEMATIC_610, x=[0x01], y=[0x02], zoom=0x40

LABEL_7A80:
	break
	jmp LABEL_7A43

LABEL_7A84:
	jl [0x2F], 0x1E, LABEL_7ADD
	mov [SCROLL_Y], 0xFFFC
	je [HACK_VAR_67], 0xAF, LABEL_7A98
	setup channel=0x3C, address=LABEL_3F7E

LABEL_7A98:
	video offset=CINEMATIC_614, x=[0x01], y=[0x02], zoom=0x40
	song id=0x0BDD, delay=0x0000, pos=0x00
	call LABEL_7AF8
	break
	video offset=CINEMATIC_615, x=[0x01], y=[0x02], zoom=0x40
	call LABEL_7AF8
	break
	video offset=CINEMATIC_616, x=[0x01], y=[0x02], zoom=0x40
	call LABEL_7AF8
	mov [0x03], 0x0032
	play id=0x007A, freq=0x14, vol=0x40, channel=0x00
	play id=0x005E, freq=0x0A, vol=0x40, channel=0x01
	setup channel=0x3F, address=LABEL_0211

LABEL_7ACC:
	break
	or [0x04], 0x4000
	video offset=CINEMATIC_617, x=[0x01], y=[0x02], zoom=0x40
	call LABEL_7AF8
	jmp LABEL_7ACC
LABEL_7ADC:
	db 0x11

LABEL_7ADD:
	jl [0x04], 0x00, KILL_CHAN_AT_7AF7
	mov [SCROLL_Y], 0x0001
	setup channel=0x3C, address=LABEL_3F7E
	play id=0x005E, freq=0x14, vol=0x30, channel=0x01
	call SET_VAR04_TO_0008
	jmp LABEL_E8D9

KILL_CHAN_AT_7AF7:
	killChannel

LABEL_7AF8:
	call LABEL_2B98
	video offset=CINEMATIC_229, x=320, y=184, zoom=0x40
	je [0xDB], 0x00, DRAW_CIN_229
	video offset=CINEMATIC_229, x=15, y=184
	ret

DRAW_CIN_229:
	video offset=CINEMATIC_229, x=16, y=184
	ret

LABEL_7B10:
	video offset=CINEMATIC_229, x=160, y=19
	break
	jl [0x02], 0x64, LABEL_7B10
	killChannel

LABEL_7B1C:
	mov [0x2D], [0x35]
	mov [0x2E], [0x01]
	mov [0x2F], [0x02]
	call LABEL_7890
	jl [0x2F], [0x22], LABEL_7B4A
	mov [0xF8], [0x2F]
	sub [0xF8], [0x22]
	jl [0xF8], 0x09, LABEL_7B4A
	mov [0x01], [0x2E]
	mov [0x02], [0x2F]
	add [0x02], [0x35]
	mov [0x34], 0x0000
	jmp LABEL_7B50

LABEL_7B4A:
	jge [0x02], [0x22], LABEL_7B8B

LABEL_7B50:
	mov [0xF8], [0x04]
	and [0xF8], 0x0010
	je [0xF8], 0x10, LABEL_7B66
	video offset=CINEMATIC_169, x=[0x01], y=[0x02], zoom=0x40
	break
	jmp LABEL_7B1C

LABEL_7B66:
	jl [0x34], 0x05, LABEL_7B74
	video offset=CINEMATIC_168, x=[0x01], y=[0x02], zoom=0x40
	jmp LABEL_7B87

LABEL_7B74:
	jl [0x34], 0x03, LABEL_7B82
	video offset=CINEMATIC_167, x=[0x01], y=[0x02], zoom=0x40
	jmp LABEL_7B87

LABEL_7B82:
	video offset=CINEMATIC_167, x=[0x01], y=[0x02], zoom=0x40

LABEL_7B87:
	break
	jmp LABEL_7B1C

LABEL_7B8B:
	mov [0xF8], [0x04]
	play id=0x0060, freq=0x14, vol=0x40, channel=0x01
	and [0xF8], 0x0010
	je [0xF8], 0x10, LABEL_7BDA
	je [HACK_VAR_67], 0x88, LABEL_7BC4
	je [HACK_VAR_67], 0x89, LABEL_7BC4
	video offset=CINEMATIC_160, x=[0x01], y=[0x02], zoom=0x40
	break
	mov [0x03], 0x0003
	play id=0x0060, freq=0x14, vol=0x40, channel=0x00

ANIM_CIN_166_LOOP_VAR03:
	video offset=CINEMATIC_166, x=[0x01], y=[0x02], zoom=0x40
	break
	djnz [0x03], ANIM_CIN_166_LOOP_VAR03

LABEL_7BC4:
	mov [0x63], 0x0001
	call SET_VAR04_TO_0020
	video offset=CINEMATIC_160, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_161, x=[0x01], y=[0x02], zoom=0x40
	jmp HERO_WALK_LEFT_LOOP
LABEL_7BD9:
	db 0x11

LABEL_7BDA:
	je [HACK_VAR_67], 0x88, LABEL_7C09
	je [HACK_VAR_67], 0x89, LABEL_7C09
	video offset=CINEMATIC_158, x=[0x01], y=[0x02], zoom=0x40
	break
	mov [0x03], 0x0003
	call DERIVE_HASH_BUCKETS_FROM_VAR38
	jg [0x3A], 0x01, ANIM_CV_335_LOOP_VAR03
	play id=0x0079, freq=0x14, vol=0x40, channel=0x01

ANIM_CV_335_LOOP_VAR03:
	video type=0, offset=COMMON_VIDEO_335, x=[0x01], y=[0x02], zoom=0x40
	break
	djnz [0x03], ANIM_CV_335_LOOP_VAR03

LABEL_7C09:
	mov [0x63], 0x0002
	call SET_VAR04_TO_0020
	video offset=CINEMATIC_158, x=[0x01], y=[0x02], zoom=0x40
	break
	video offset=CINEMATIC_159, x=[0x01], y=[0x02], zoom=0x40
	jmp HERO_WALK_RIGHT_LOOP
LABEL_7C1E:
	db 0x11

LABEL_7C1F:
	call LABEL_7890
	mov [0x63], 0x0064
	call SET_VAR04_TO_0034
	mov [0x2B], [0x23]
	and [0x2B], 0x000F
	je [0x34], 0x00, LABEL_7C44
	jl [0x34], 0x00, LABEL_7C3F
	jmp LABEL_7C3F

LABEL_7C3F:
	break
	jmp LABEL_7C1F
LABEL_7C43:
	db 0x11

LABEL_7C44:
	sub [0x01], 0x0001
	break
	mov [0x63], 0x0001
	jmp LABEL_EB60
LABEL_7C50:
	db 0x11

LABEL_7C51:
	mov [0x21], [0x01]
	mov [0x22], [0x02]
	mov [0x23], 0x0000
	call LABEL_7C5F
	ret

LABEL_7C5F:
	je [HACK_VAR_67], 0x25, LABEL_B526
	je [HACK_VAR_67], 0x28, LABEL_C0EB
	je [HACK_VAR_67], 0x48, LABEL_C07A
	je [HACK_VAR_67], 0x49, LABEL_C095
	je [HACK_VAR_67], 0x4A, LABEL_C0BD
	je [HACK_VAR_67], 0x4C, LABEL_C1D8
	je [HACK_VAR_67], 0x4D, LABEL_C1FA
	je [HACK_VAR_67], 0xC8, LABEL_BB81
	je [HACK_VAR_67], 0xC9, LABEL_BC49
	je [HACK_VAR_67], 0xCA, LABEL_BD6E
	je [HACK_VAR_67], 0xCB, LABEL_BEE7
	je [HACK_VAR_67], 0xCC, LABEL_BEE7
	je [HACK_VAR_67], 0xCD, LABEL_BF44
	je [HACK_VAR_67], 0xED, LABEL_BFEE
	je [HACK_VAR_67], 0xCE, LABEL_BEE7
	je [HACK_VAR_67], 0x67, LABEL_B63D
	je [HACK_VAR_67], 0x68, LABEL_B6F6
	je [HACK_VAR_67], 0x69, LABEL_C222
	je [HACK_VAR_67], 0x6A, LABEL_C0BD
	je [HACK_VAR_67], 0x6B, LABEL_C2F7
	je [HACK_VAR_67], 0x6D, LABEL_C352
	je [HACK_VAR_67], 0x85, LABEL_B5A2
	je [HACK_VAR_67], 0x87, LABEL_B821
	je [HACK_VAR_67], 0x88, LABEL_C110
	je [HACK_VAR_67], 0x89, LABEL_C3A9
	je [HACK_VAR_67], 0x8A, LABEL_C4F9
	je [HACK_VAR_67], 0xAF, LABEL_C04D
	je [HACK_VAR_67], 0xA6, LABEL_B600
	je [HACK_VAR_67], 0xA7, LABEL_B956
	je [HACK_VAR_67], 0xA8, LABEL_BB65
	je [HACK_VAR_67], 0xA9, INIT_VARS_01_22
	je [HACK_VAR_67], 0x6F, LABEL_C036
	je [HACK_VAR_67], 0x71, LABEL_C064
	jg [0x22], [0x41], COPY_VAR40_TO_VAR22
	mov [0x22], [0x44]
	ret
