LABEL_7A23:
	jg [0x34], [0x2B], LABEL_7A2C
	mov [0x34], [0x2B]

LABEL_7A2C:
	jle [0x34], [0x2C], LABEL_7A35
	mov [0x34], [0x2C]

LABEL_7A35:
	mov [0x35], [0x10]
	jmp LABEL_7A53

LABEL_7A3B:
	add [0x35], 0x0008
	je [0x34], 0x00, LABEL_7A53
	sub [0x34], 0x0002
	jge [0x34], 0x00, LABEL_7A53
	mov [0x34], 0x0000

LABEL_7A53:
	jge [0x0E], 0x00, SHARED_RET
	mov [0x0E], [0x34]
	mov [0x34], 0x0000
	sub [0x34], [0x0E]
	ret
LABEL_7A64:
	db 0x11

LABEL_7A65:
	mov [0x21], [0x01]
	mov [0x22], [0x02]
	mov [0x23], 0x0000
	mov [0xF8], [0x04]
	and [0xF8], 0x0010
	sub [0x21], 0x0014
	je [0xF8], 0x00, LABEL_7A84
	add [0x21], 0x0028

LABEL_7A84:
	call LABEL_7CE8
	sub [0x22], [0x02]
	call LABEL_7E90
	jl [0x22], 0x10, SHARED_RET
	setup channel=0x14, address=LABEL_7BA5
	mov [0x35], 0x0000
	sub [0x34], 0x000D
	add [0x01], 0x0019
	je [0xF8], 0x00, SHARED_RET
	sub [0x01], 0x0032
	add [0x34], 0x001A
	ret

LABEL_7AB2:
	mov [0x63], 0x0064
	call INIT_VAR2B_2C_FROM_VAR01_VAR29_10
	mov [0x34], 0xFFFB
	mov [0x35], 0x0008
	call SET_VAR04_TO_0024
	setup channel=0x14, address=LABEL_7BA5
	jge [0x2B], [0x01], SHARED_RET
	mov [0x34], 0x0005
	call SET_VAR04_TO_0034
	setup channel=0x14, address=LABEL_7BA5
	ret

LABEL_7ADA:
	mov [0x2F], [0x35]
	call LABEL_7933
	mov [0x34], 0x0000
	jg [0x02], 0xF0, LABEL_7AF0
	jge [0x02], [0x22], LABEL_7B1B

LABEL_7AF0:
	jl [0x04], 0x00, LABEL_7B17
	jl [0x2F], 0x1E, LABEL_7B04
	video type=1, offset=CINEMATIC_622, x=[0x01], y=[0x02], zoom=0x40
	jmp LABEL_7B17

LABEL_7B04:
	jl [0x2F], 0x14, LABEL_7B12
	video type=1, offset=CINEMATIC_621, x=[0x01], y=[0x02], zoom=0x40
	jmp LABEL_7B17

LABEL_7B12:
	video type=1, offset=CINEMATIC_620, x=[0x01], y=[0x02], zoom=0x40

LABEL_7B17:
	break
	jmp LABEL_7ADA

LABEL_7B1B:
	jl [0x2F], 0x1E, LABEL_7B6E
	mov [SCROLL_Y], 0xFFFC
	je [HACK_VAR_67], 0xAF, LABEL_7B2F
	setup channel=0x3C, address=LABEL_3F94

LABEL_7B2F:
	video type=1, offset=CINEMATIC_623, x=[0x01], y=[0x02], zoom=0x40
	call LABEL_7B89
	break
	video type=1, offset=CINEMATIC_624, x=[0x01], y=[0x02], zoom=0x40
	call LABEL_7B89
	break
	video type=1, offset=CINEMATIC_625, x=[0x01], y=[0x02], zoom=0x40
	call LABEL_7B89
	mov [0x03], 0x0032
	play id=0x007A, freq=0x14, vol=0x40, channel=0x00
	play id=0x005E, freq=0x0A, vol=0x40, channel=0x01
	setup channel=0x3F, address=LABEL_0184

LABEL_7B5D:
	break
	or [0x04], 0x4000
	video type=1, offset=CINEMATIC_626, x=[0x01], y=[0x02], zoom=0x40
	call LABEL_7B89
	jmp LABEL_7B5D
LABEL_7B6D:
	db 0x11

LABEL_7B6E:
	jl [0x04], 0x00, KILL_CHAN_AT_7B88
	mov [SCROLL_Y], 0x0001
	setup channel=0x3C, address=LABEL_3F94
	play id=0x005E, freq=0x14, vol=0x30, channel=0x01
	call SET_VAR04_TO_0008
	jmp LABEL_E850

KILL_CHAN_AT_7B88:
	killChannel

LABEL_7B89:
	video type=1, offset=CINEMATIC_229, x=320, y=184, zoom=0x40
	video type=1, offset=CINEMATIC_229, x=16, y=184
	call LABEL_2BCB
	ret

LABEL_7B96:
	video type=1, offset=CINEMATIC_229, x=160, y=19
	call LABEL_2BCB
	break
	jl [0x02], 0x64, LABEL_7B96
	killChannel

LABEL_7BA5:
	mov [0x2D], [0x35]
	mov [0x2E], [0x01]
	mov [0x2F], [0x02]
	call LABEL_7933
	jl [0x2F], [0x22], LABEL_7BD3
	mov [0xF8], [0x2F]
	sub [0xF8], [0x22]
	jl [0xF8], 0x09, LABEL_7BD3
	mov [0x01], [0x2E]
	mov [0x02], [0x2F]
	add [0x02], [0x35]
	mov [0x34], 0x0000
	jmp LABEL_7BD9

LABEL_7BD3:
	jge [0x02], [0x22], LABEL_7C14

LABEL_7BD9:
	mov [0xF8], [0x04]
	and [0xF8], 0x0010
	je [0xF8], 0x10, LABEL_7BEF
	video type=1, offset=CINEMATIC_169, x=[0x01], y=[0x02], zoom=0x40
	break
	jmp LABEL_7BA5

LABEL_7BEF:
	jl [0x34], 0x05, LABEL_7BFD
	video type=1, offset=CINEMATIC_168, x=[0x01], y=[0x02], zoom=0x40
	jmp LABEL_7C10

LABEL_7BFD:
	jl [0x34], 0x03, LABEL_7C0B
	video type=1, offset=CINEMATIC_167, x=[0x01], y=[0x02], zoom=0x40
	jmp LABEL_7C10

LABEL_7C0B:
	video type=1, offset=CINEMATIC_167, x=[0x01], y=[0x02], zoom=0x40

LABEL_7C10:
	break
	jmp LABEL_7BA5

LABEL_7C14:
	mov [0xF8], [0x04]
	play id=0x0060, freq=0x14, vol=0x40, channel=0x01
	and [0xF8], 0x0010
	je [0xF8], 0x10, LABEL_7C63
	je [HACK_VAR_67], 0x88, LABEL_7C4D
	je [HACK_VAR_67], 0x89, LABEL_7C4D
	video type=1, offset=CINEMATIC_160, x=[0x01], y=[0x02], zoom=0x40
	break
	mov [0x03], 0x0003
	play id=0x0060, freq=0x14, vol=0x40, channel=0x00

ANIM_CIN_166_LOOP_VAR03:
	video type=1, offset=CINEMATIC_166, x=[0x01], y=[0x02], zoom=0x40
	break
	djnz [0x03], ANIM_CIN_166_LOOP_VAR03

LABEL_7C4D:
	mov [0x63], 0x0001
	call SET_VAR04_TO_0020
	video type=1, offset=CINEMATIC_160, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_161, x=[0x01], y=[0x02], zoom=0x40
	jmp HERO_WALK_LEFT_LOOP
LABEL_7C62:
	db 0x11

LABEL_7C63:
	je [HACK_VAR_67], 0x88, LABEL_7C92
	je [HACK_VAR_67], 0x89, LABEL_7C92
	video type=1, offset=CINEMATIC_158, x=[0x01], y=[0x02], zoom=0x40
	break
	mov [0x03], 0x0003
	call DERIVE_HASH_BUCKETS_FROM_VAR38
	jg [0x3A], 0x01, ANIM_CV_335_LOOP_VAR03
	play id=0x0079, freq=0x14, vol=0x40, channel=0x01

ANIM_CV_335_LOOP_VAR03:
	video type=0, offset=COMMON_VIDEO_335, x=[0x01], y=[0x02], zoom=0x40
	break
	djnz [0x03], ANIM_CV_335_LOOP_VAR03

LABEL_7C92:
	mov [0x63], 0x0002
	call SET_VAR04_TO_0020
	video type=1, offset=CINEMATIC_158, x=[0x01], y=[0x02], zoom=0x40
	break
	video type=1, offset=CINEMATIC_159, x=[0x01], y=[0x02], zoom=0x40
	jmp HERO_WALK_RIGHT_LOOP
LABEL_7CA7:
	db 0x11

LABEL_7CA8:
	call LABEL_7933
	mov [0x63], 0x0064
	call SET_VAR04_TO_0034
	mov [0x2B], [0x23]
	and [0x2B], 0x000F
	je [0x34], 0x00, LABEL_7CCD
	jl [0x34], 0x00, LABEL_7CC8
	jmp LABEL_7CC8

LABEL_7CC8:
	break
	jmp LABEL_7CA8
LABEL_7CCC:
	db 0x11

LABEL_7CCD:
	sub [0x01], 0x0001
	break
	mov [0x63], 0x0001
	jmp LABEL_EAD7
LABEL_7CD9:
	db 0x11

LABEL_7CDA:
	mov [0x21], [0x01]
	mov [0x22], [0x02]
	mov [0x23], 0x0000
	call LABEL_7CE8
	ret

LABEL_7CE8:
	je [HACK_VAR_67], 0x25, LABEL_B525
	je [HACK_VAR_67], 0x28, LABEL_C0EA
	je [HACK_VAR_67], 0x48, LABEL_C079
	je [HACK_VAR_67], 0x49, LABEL_C094
	je [HACK_VAR_67], 0x4A, LABEL_C0BC
	je [HACK_VAR_67], 0x4C, LABEL_C1AF
	je [HACK_VAR_67], 0x4D, LABEL_C1D1
	je [HACK_VAR_67], 0xC8, LABEL_BB80
	je [HACK_VAR_67], 0xC9, LABEL_BC48
	je [HACK_VAR_67], 0xCA, LABEL_BD6D
	je [HACK_VAR_67], 0xCB, LABEL_BEE6
	je [HACK_VAR_67], 0xCC, LABEL_BEE6
	je [HACK_VAR_67], 0xCD, LABEL_BF43
	je [HACK_VAR_67], 0xED, LABEL_BFED
	je [HACK_VAR_67], 0xCE, LABEL_BEE6
	je [HACK_VAR_67], 0x67, LABEL_B63C
	je [HACK_VAR_67], 0x68, LABEL_B6F5
	je [HACK_VAR_67], 0x69, LABEL_C1F9
	je [HACK_VAR_67], 0x6A, LABEL_C0BC
	je [HACK_VAR_67], 0x6B, LABEL_C2CE
	je [HACK_VAR_67], 0x6D, LABEL_C329
	je [HACK_VAR_67], 0x85, LABEL_B5A1
	je [HACK_VAR_67], 0x87, LABEL_B820
	je [HACK_VAR_67], 0x88, LABEL_C10F
	je [HACK_VAR_67], 0x89, LABEL_C3C8
	je [HACK_VAR_67], 0x8A, LABEL_C518
	je [HACK_VAR_67], 0xAF, LABEL_C04C
	je [HACK_VAR_67], 0xA6, LABEL_B5FF
	je [HACK_VAR_67], 0xA7, LABEL_B955
	je [HACK_VAR_67], 0xA8, LABEL_BB64
	je [HACK_VAR_67], 0xA9, INIT_VARS_01_22
	je [HACK_VAR_67], 0x6F, LABEL_C035
	je [HACK_VAR_67], 0x71, LABEL_C063
	jg [0x22], [0x41], COPY_VAR40_TO_VAR22
	mov [0x22], [0x44]
	ret
