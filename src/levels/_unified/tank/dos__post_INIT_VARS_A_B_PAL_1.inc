LABEL_1C72:
	add [0x0A], 0x0001
	break
	djnz [0x0B], LABEL_1C72
	mov [0x0B], 0x0032

LABEL_1C7F:
	sub [0x0A], 0x0001
	break
	djnz [0x0B], LABEL_1C7F
	jmp INIT_VARS_A_B_PAL_1
LABEL_1C8B:
	db 0x11

LABEL_1C8C:
	je [0x6D], 0x01, SHARED_RET
	selectVideoPage 0x03
	fill page=0x03, color=0x0C
	video offset=CINEMATIC_000, x=160, y=100
	call DRAW_CIN_061_HORIZ_THEN_062
	call DRAW_BG_DOTS_CIN_007_008
	call DRAW_CIN_6_AND_RET
	selectVideoPage 0xFF
	ret

LABEL_1CA7:
	selectVideoPage 0x00
	call DRAW_CIN_6_27_28_AND_RET
	selectVideoPage 0x03
	call DRAW_CIN_6_27_28_AND_RET
	selectVideoPage 0xFF
	ret
