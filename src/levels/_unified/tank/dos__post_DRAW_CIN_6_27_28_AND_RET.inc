LABEL_1CC1:
	jne [0x6D], 0x00, LABEL_1CE5
	selectVideoPage 0x00
	fill page=0x00, color=0x0C
	video offset=CINEMATIC_000, x=160, y=100
	call DRAW_CIN_061_HORIZ_THEN_062
	call DRAW_BG_DOTS_CIN_001_004
	call DRAW_CIN_6_AND_RET
	selectVideoPage 0xFF
	ret

LABEL_1CDC:
	call LABEL_1CC1
	copyVideoPage src=0x03, dst=0xFF
	jmp INIT_VARS_A_B_PAL_1

LABEL_1CE5:
	mov [SCROLL_Y], 0xFF9C
	copyVideoPage src=0x83, dst=0x00
	copyVideoPage src=0x00, dst=0xFF
	selectVideoPage 0x03
	call DRAW_CIN_SEQ_011_011_011
	copyVideoPage src=0x03, dst=0x00
	selectVideoPage 0xFF
	video offset=CINEMATIC_029, x=[0x0f], y=[0x10]
	video offset=CINEMATIC_030, x=160, y=90
	copyVideoPage src=0xFF, dst=0x00
	selectVideoPage 0x00
	call DRAW_CIN_6_AND_RET
	selectVideoPage 0x03
	call DRAW_CIN_6_AND_RET
	selectVideoPage 0xFF
	ret
