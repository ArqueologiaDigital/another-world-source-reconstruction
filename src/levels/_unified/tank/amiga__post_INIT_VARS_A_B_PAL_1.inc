LABEL_176C:
	add [0x0A], 0x0001
	break
	djnz [0x0B], LABEL_176C
	mov [0x0B], 0x0032

LABEL_1779:
	sub [0x0A], 0x0001
	break
	djnz [0x0B], LABEL_1779
	jmp INIT_VARS_A_B_PAL_1
LABEL_1785:
	db 0x11

LABEL_1786:
	selectVideoPage 0x03
	fill page=0x03, color=0x0C
	video type=1, offset=CINEMATIC_000, x=160, y=100
	call DRAW_CIN_SEQ_001_001_003
	call DRAW_BG_DOTS_CIN_007_008
	call DRAW_CIN_6_AND_RET
	selectVideoPage 0xFF
	ret

LABEL_179B:
	selectVideoPage 0x00
	call DRAW_CIN_6_27_28_AND_RET
	selectVideoPage 0x03
	call DRAW_CIN_6_27_28_AND_RET
	selectVideoPage 0xFF
	ret
