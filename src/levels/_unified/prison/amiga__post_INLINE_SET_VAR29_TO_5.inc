LABEL_15E3:
	call GUARDED_HERO_ANIM_CV_009
	break
	djnz [0x29], LABEL_15E3
	call LABEL_6201
	add [BUDDY_X], 0x0001
	break
	call GUARDED_DRAW_CIN_342
	sub [BUDDY_X], 0x0001
	break
	call GUARDED_DRAW_CIN_338_339
	call AND_VAR11_WITH_EFFF
	sub [BUDDY_X], 0x0001
	break
	mov [0x29], 0x0007

LABEL_160A:
	call GUARDED_DRAW_CIN_242_243
	break
	djnz [0x29], LABEL_160A
	mov [0x29], 0x0087
	mov [0x12], 0x0028
	jmp LABEL_56A1
LABEL_161D:
	db 0x11

LABEL_161E:
	call GUARDED_HERO_ANIM_CV_009
	break
	mov [0x0E], 0x0000
	mov [0x29], 0x0003

LABEL_162A:
	call LABEL_6201
	break
	djnz [0x29], LABEL_162A
	call GUARDED_HERO_ANIM_CV_009
	mov [0x29], 0x000A

LABEL_1639:
	mov [0x0E], 0x0007
	call COPY_HASH_AND_SPLIT_VAR38_3F_3E
	jg [0x39], 0x01, LABEL_1654
	mov [0x0E], 0x0000
	jne [0x3A], 0x00, LABEL_1654
	mov [0x0E], 0x0004

LABEL_1654:
	break
	call LABEL_61E0
	break
	call LABEL_61E0
	mov [0x0E], 0x0000
	break
	call LABEL_61E0
	djnz [0x29], LABEL_1639
	killChannel

LABEL_1669:
	call LABEL_61E0
	mov [0x0D], 0x0001
	mov [0x29], 0x0014
	mov [0x0E], 0x0003

LABEL_1678:
	break
	call GUARDED_HERO_ANIM_CV_009
	djnz [0x29], LABEL_1678
	mov [0x0E], 0x0000
	break
	mov [0x2F], 0x0006
	jmp DISPATCH_VAR2F_STATE
LABEL_168C:
	db 0x11

BUDDY_HACK_SECOND_INIT:
	mov [BUDDY_X], 0x0104
	mov [0x12], 0x0004
	mov [0xF1], 0x0000
	call LABEL_6201
	jne [HACK_VAR_67], 0x04, PRISON_INLINE_SET_VAR29_TO_6_L1
	selectVideoPage 0x00
	video offset=CINEMATIC_BUDDY_HACKING_SECURITY_DOOR, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_390, x=[BUDDY_X], y=[BUDDY_Y]
	selectVideoPage 0xFF
	mov [0x29], 0x000A

BUDDY_HACK_SECOND_TYPING_LOOP:
	break
	video offset=CINEMATIC_391, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_392, x=[BUDDY_X], y=[BUDDY_Y]
	call DRAW_BUDDY_FIGURE_BASE
	djnz [0x29], BUDDY_HACK_SECOND_TYPING_LOOP
	break
	video offset=CINEMATIC_394, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_392, x=[BUDDY_X], y=[BUDDY_Y]
	call DRAW_BUDDY_FIGURE_BASE
	break
	video offset=CINEMATIC_395, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_396, x=[BUDDY_X], y=[BUDDY_Y]
	call DRAW_BUDDY_FIGURE_BASE
	break
	video offset=CINEMATIC_397, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_398, x=[BUDDY_X], y=[BUDDY_Y]
	call DRAW_BUDDY_FIGURE_BASE
	break
	video offset=CINEMATIC_397, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_399, x=[BUDDY_X], y=[BUDDY_Y]
	call DRAW_BUDDY_FIGURE_BASE
	break
	jmp PRISON_INLINE_SET_VAR29_TO_6_L1
LABEL_1702:
	db 0x11

PRISON_INLINE_SET_VAR29_TO_6_L6:
	video offset=CINEMATIC_397, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_399, x=[BUDDY_X], y=[BUDDY_Y]
	call DRAW_BUDDY_FIGURE_BASE
	break
	video offset=CINEMATIC_395, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_398, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_393, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_395, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_399, x=[BUDDY_X], y=[BUDDY_Y]
	call DRAW_BUDDY_FIGURE_BASE
	mov [0x29], 0x0005

LABEL_1732:
	break
	video offset=CINEMATIC_397, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_399, x=[BUDDY_X], y=[BUDDY_Y]
	call DRAW_BUDDY_FIGURE_BASE
	djnz [0x29], LABEL_1732
	break
	jmp PRISON_INLINE_SET_VAR29_TO_6_L1
LABEL_1748:
	db 0x11

PRISON_INLINE_SET_VAR29_TO_6_L7:
	video offset=CINEMATIC_397, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_399, x=[BUDDY_X], y=[BUDDY_Y]
	call DRAW_BUDDY_FIGURE_BASE
	break
	video offset=CINEMATIC_397, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_398, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_393, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_397, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_399, x=[BUDDY_X], y=[BUDDY_Y]
	call DRAW_BUDDY_FIGURE_BASE
	mov [0x29], 0x0005

LABEL_1778:
	break
	video offset=CINEMATIC_395, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_399, x=[BUDDY_X], y=[BUDDY_Y]
	call DRAW_BUDDY_FIGURE_BASE
	djnz [0x29], LABEL_1778
	break
	jmp PRISON_INLINE_SET_VAR29_TO_6_L1
LABEL_178E:
	db 0x11

PRISON_INLINE_SET_VAR29_TO_6_L4:
	video offset=CINEMATIC_400, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_396, x=[BUDDY_X], y=[BUDDY_Y]
	call DRAW_BUDDY_FIGURE_BASE
	break
	video offset=CINEMATIC_401, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_396, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_393, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_402, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_396, x=[BUDDY_X], y=[BUDDY_Y]
	call DRAW_BUDDY_FIGURE_BASE
	mov [0x29], 0x0003

LABEL_17BE:
	break
	video offset=CINEMATIC_403, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_392, x=[BUDDY_X], y=[BUDDY_Y]
	call DRAW_BUDDY_FIGURE_BASE
	djnz [0x29], LABEL_17BE
	break
	video offset=CINEMATIC_404, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_396, x=[BUDDY_X], y=[BUDDY_Y]
	call DRAW_BUDDY_FIGURE_BASE
	break
	jmp LABEL_1819
LABEL_17E2:
	db 0x11

PRISON_INLINE_SET_VAR29_TO_6_L5:
	video offset=CINEMATIC_401, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_396, x=[BUDDY_X], y=[BUDDY_Y]
	call DRAW_BUDDY_FIGURE_BASE
	mov [0x29], 0x0003

LABEL_17F4:
	break
	video offset=CINEMATIC_404, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_396, x=[BUDDY_X], y=[BUDDY_Y]
	call DRAW_BUDDY_FIGURE_BASE
	djnz [0x29], LABEL_17F4
	break
	video offset=CINEMATIC_400, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_396, x=[BUDDY_X], y=[BUDDY_Y]
	call DRAW_BUDDY_FIGURE_BASE
	break
	jmp LABEL_1819
LABEL_1818:
	db 0x11

LABEL_1819:
	call COPY_HASH_AND_SPLIT_VAR38_3F_3E
	add [0xF1], 0x0001
	jg [0xF1], 0x28, PRISON_INLINE_SET_VAR29_TO_6_L3
	je [0x3A], 0x00, PRISON_INLINE_SET_VAR29_TO_6_L6
	je [0x3A], 0x01, PRISON_INLINE_SET_VAR29_TO_6_L7
	jl [0x3A], 0x05, PRISON_INLINE_SET_VAR29_TO_6_L4
	jmp PRISON_INLINE_SET_VAR29_TO_6_L5
