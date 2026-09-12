LABEL_17B5:
	selectVideoPage 0x00
	fill page=0x00, color=0x0C
	video offset=CINEMATIC_000, x=160, y=100
	call TANK_HORIZON_DECOR_LEFT_THIRD
	call TANK_HORIZON_DECOR_FULL_WIDTH_PAGE_0
	call DRAW_CIN_6_AND_RET
	selectVideoPage 0xFF
	ret
