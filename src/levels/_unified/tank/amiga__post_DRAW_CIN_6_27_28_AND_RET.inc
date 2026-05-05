LABEL_17B5:
	selectVideoPage 0x00
	fill page=0x00, color=0x0C
	video offset=CINEMATIC_000, x=160, y=100
	call DRAW_CIN_SEQ_001_001_003
	call DRAW_BG_DOTS_CIN_001_004
	call DRAW_CIN_6_AND_RET
	selectVideoPage 0xFF
	ret
