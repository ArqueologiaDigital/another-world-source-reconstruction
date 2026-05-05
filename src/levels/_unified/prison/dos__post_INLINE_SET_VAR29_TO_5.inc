LABEL_15DB:
	call GUARDED_HERO_ANIM_CV_128
	break
	djnz [0x29], LABEL_15DB
	call LABEL_62AE
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

LABEL_1602:
	call GUARDED_DRAW_CIN_242_243
	break
	djnz [0x29], LABEL_1602
	mov [0x29], 0x0087
	mov [0x12], 0x0028
	jmp LABEL_574E
LABEL_1615:
	db 0x11

LABEL_1616:
	call GUARDED_HERO_ANIM_CV_128
	break
	mov [0x0E], 0x0000
	mov [0x29], 0x0003

LABEL_1622:
	call LABEL_62AE
	break
	djnz [0x29], LABEL_1622
	call GUARDED_HERO_ANIM_CV_128
	mov [0x29], 0x000A

LABEL_1631:
	mov [0x0E], 0x0007
	call COPY_HASH_AND_SPLIT_VAR38_3F_3E
	jg [0x39], 0x01, LABEL_164C
	mov [0x0E], 0x0000
	jne [0x3A], 0x00, LABEL_164C
	mov [0x0E], 0x0004

LABEL_164C:
	break
	call LABEL_628D
	break
	call LABEL_628D
	mov [0x0E], 0x0000
	break
	call LABEL_628D
	djnz [0x29], LABEL_1631
	killChannel

LABEL_1661:
	call LABEL_628D
	mov [0x0D], 0x0001
	mov [0x29], 0x0014
	mov [0x0E], 0x0003

LABEL_1670:
	break
	call GUARDED_HERO_ANIM_CV_128
	djnz [0x29], LABEL_1670
	mov [0x0E], 0x0000
	break
	mov [0x2F], 0x0006
	jmp DISPATCH_VAR2F_STATE
LABEL_1684:
	db 0x11

LABEL_1685:
	mov [BUDDY_X], 0x0104
	mov [0x12], 0x0004
	mov [0xF1], 0x0000
	call LABEL_62AE
	jne [HACK_VAR_67], 0x04, LABEL_1846
	selectVideoPage 0x00
	video offset=CINEMATIC_389, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_390, x=[BUDDY_X], y=[BUDDY_Y]
	selectVideoPage 0xFF
	mov [0x29], 0x000A

LABEL_16AC:
	break
	video offset=CINEMATIC_391, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_392, x=[BUDDY_X], y=[BUDDY_Y]
	call DRAW_CIN_393_AT_VAR07_08
	djnz [0x29], LABEL_16AC
	break
	video offset=CINEMATIC_394, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_392, x=[BUDDY_X], y=[BUDDY_Y]
	call DRAW_CIN_393_AT_VAR07_08
	break
	video offset=CINEMATIC_395, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_396, x=[BUDDY_X], y=[BUDDY_Y]
	call DRAW_CIN_393_AT_VAR07_08
	break
	video offset=CINEMATIC_397, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_398, x=[BUDDY_X], y=[BUDDY_Y]
	call DRAW_CIN_393_AT_VAR07_08
	break
	video offset=CINEMATIC_397, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_399, x=[BUDDY_X], y=[BUDDY_Y]
	call DRAW_CIN_393_AT_VAR07_08
	break
	jmp LABEL_1846
LABEL_16FA:
	db 0x11

LABEL_16FB:
	video offset=CINEMATIC_397, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_399, x=[BUDDY_X], y=[BUDDY_Y]
	call DRAW_CIN_393_AT_VAR07_08
	break
	video offset=CINEMATIC_395, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_398, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_393, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_395, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_399, x=[BUDDY_X], y=[BUDDY_Y]
	call DRAW_CIN_393_AT_VAR07_08
	mov [0x29], 0x0005

LABEL_172A:
	break
	video offset=CINEMATIC_397, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_399, x=[BUDDY_X], y=[BUDDY_Y]
	call DRAW_CIN_393_AT_VAR07_08
	djnz [0x29], LABEL_172A
	break
	jmp LABEL_1846
LABEL_1740:
	db 0x11

LABEL_1741:
	video offset=CINEMATIC_397, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_399, x=[BUDDY_X], y=[BUDDY_Y]
	call DRAW_CIN_393_AT_VAR07_08
	break
	video offset=CINEMATIC_397, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_398, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_393, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_397, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_399, x=[BUDDY_X], y=[BUDDY_Y]
	call DRAW_CIN_393_AT_VAR07_08
	mov [0x29], 0x0005

LABEL_1770:
	break
	video offset=CINEMATIC_395, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_399, x=[BUDDY_X], y=[BUDDY_Y]
	call DRAW_CIN_393_AT_VAR07_08
	djnz [0x29], LABEL_1770
	break
	jmp LABEL_1846
LABEL_1786:
	db 0x11

LABEL_1787:
	video offset=CINEMATIC_400, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_396, x=[BUDDY_X], y=[BUDDY_Y]
	call DRAW_CIN_393_AT_VAR07_08
	break
	video offset=CINEMATIC_401, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_396, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_393, x=[BUDDY_X], y=[BUDDY_Y]
	break
	video offset=CINEMATIC_402, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_396, x=[BUDDY_X], y=[BUDDY_Y]
	call DRAW_CIN_393_AT_VAR07_08
	mov [0x29], 0x0003

LABEL_17B6:
	break
	video offset=CINEMATIC_403, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_392, x=[BUDDY_X], y=[BUDDY_Y]
	call DRAW_CIN_393_AT_VAR07_08
	djnz [0x29], LABEL_17B6
	break
	video offset=CINEMATIC_404, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_396, x=[BUDDY_X], y=[BUDDY_Y]
	call DRAW_CIN_393_AT_VAR07_08
	break
	jmp LABEL_1811
LABEL_17DA:
	db 0x11

LABEL_17DB:
	video offset=CINEMATIC_401, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_396, x=[BUDDY_X], y=[BUDDY_Y]
	call DRAW_CIN_393_AT_VAR07_08
	mov [0x29], 0x0003

LABEL_17EC:
	break
	video offset=CINEMATIC_404, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_396, x=[BUDDY_X], y=[BUDDY_Y]
	call DRAW_CIN_393_AT_VAR07_08
	djnz [0x29], LABEL_17EC
	break
	video offset=CINEMATIC_400, x=[BUDDY_X], y=[BUDDY_Y]
	video offset=CINEMATIC_396, x=[BUDDY_X], y=[BUDDY_Y]
	call DRAW_CIN_393_AT_VAR07_08
	break
	jmp LABEL_1811
LABEL_1810:
	db 0x11

LABEL_1811:
	call COPY_HASH_AND_SPLIT_VAR38_3F_3E
	add [0xF1], 0x0001
	jg [0xF1], 0x28, LABEL_186E
	je [0x3A], 0x00, LABEL_16FB
	je [0x3A], 0x01, LABEL_1741
	jl [0x3A], 0x05, LABEL_1787
	jmp LABEL_17DB
