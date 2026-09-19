TANK_SCENE_INIT_FILL_COLOR_0C_DRAW_BG:
	jne [0x6D], 0x00, TANK_SCROLL_Y_INIT_AND_PAGE_83_TO_00
	selectVideoPage 0x00
	fill page=0x00, color=0x0C
	video offset=CINEMATIC_000, x=160, y=100
	call TANK_HORIZON_DECOR_LEFT_THIRD
	call TANK_HORIZON_DECOR_FULL_WIDTH_PAGE_0
	call DRAW_CIN_6_AND_RET
	selectVideoPage 0xFF
	ret


TANK_SCENE_INIT_CALL_DRAW_BG_THEN_PAL_1:
	call TANK_SCENE_INIT_FILL_COLOR_0C_DRAW_BG
	copyVideoPage src=0x03, dst=0xFF
	jmp TANK_BACKDROP_SWAY_CYCLE_INIT

TANK_SCROLL_Y_INIT_AND_PAGE_83_TO_00:
	mov [SCROLL_Y], 0xFF9C
	copyVideoPage src=0x83, dst=0x00
	copyVideoPage src=0x00, dst=0xFF
	selectVideoPage 0x03
	call DRAW_TANK_HORIZON_DECOR_CLUSTER
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