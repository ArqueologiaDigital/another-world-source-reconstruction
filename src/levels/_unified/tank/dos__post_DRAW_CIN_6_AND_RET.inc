TANK_SCENE_INIT_FILL_COLOR_0C_AND_PAGE_3_COPY:
	selectVideoPage 0x00
	fill page=0x00, color=0x0C
	video offset=CINEMATIC_000, x=160, y=100
	copyVideoPage src=0x00, dst=0x03
	call DRAW_CIN_061_HORIZ_THEN_062
	call TANK_HORIZON_DECOR_FULL_WIDTH_PAGE_0
	call DRAW_CIN_6_AND_RET
	selectVideoPage 0x03
	call DRAW_CIN_061_HORIZ_THEN_062
	call TANK_HORIZON_DECOR_FULL_WIDTH_PAGE_3
	call DRAW_CIN_6_AND_RET
	selectVideoPage 0xFF
	ret


DRAW_CIN_113_114_AND_RET:
	video offset=CINEMATIC_162, x=[0x0f], y=[0x10]
	video offset=CINEMATIC_163, x=[0x0f], y=[0x10]
	ret


TANK_TURRET_HIT_STAMP_ON_BACKDROP:
	selectVideoPage 0x00
	video offset=CINEMATIC_173, x=[0x0f], y=[0x10]
	selectVideoPage 0xFF
	ret


TANK_SCENE_DRAW_CIN_169_IF_VAR_67_LE_2:
	selectVideoPage 0x00
	video offset=CINEMATIC_169, x=[0x0f], y=[0x10]
	selectVideoPage 0xFF
	jg [HACK_VAR_67], 0x02, SHARED_RET
	mov [HACK_VAR_67], 0x0002
	ret


TANK_SCENE_DRAW_CIN_168_IF_VAR_67_LT_3:
	jge [HACK_VAR_67], 0x03, SHARED_RET
	selectVideoPage 0x00
	video offset=CINEMATIC_168, x=[0x0f], y=[0x10]
	selectVideoPage 0xFF
	mov [HACK_VAR_67], 0x0003
	ret


DRAW_TANK_FLYBY_CRAFT:
	video offset=CINEMATIC_031, x=[0x01], y=[0x02], zoom=[0x03]
	video offset=CINEMATIC_032, x=[0x01], y=[0x02], zoom=[0x03]
	video offset=CINEMATIC_033, x=[0x01], y=[0x02], zoom=[0x03]
	video offset=CINEMATIC_034, x=[0x01], y=[0x02], zoom=[0x03]
	video offset=CINEMATIC_035, x=[0x01], y=[0x02], zoom=[0x03]
	ret


DRAW_CIN_061_HORIZ_THEN_062:
	video offset=CINEMATIC_001, x=114, y=22
	video offset=CINEMATIC_001, x=86, y=21
	video offset=CINEMATIC_001, x=53, y=21
	video offset=CINEMATIC_001, x=21, y=21
	video offset=CINEMATIC_001, x=1, y=21
	video offset=CINEMATIC_002, x=68, y=21
	video offset=CINEMATIC_002, x=100, y=21
	video offset=CINEMATIC_002, x=47, y=22
	video offset=CINEMATIC_002, x=23, y=20
	video offset=CINEMATIC_002, x=0, y=20
	video offset=CINEMATIC_003, x=87, y=23
	video offset=CINEMATIC_003, x=62, y=20
	video offset=CINEMATIC_003, x=49, y=21
	video offset=CINEMATIC_003, x=24, y=21
	video offset=CINEMATIC_003, x=2, y=23
	video offset=CINEMATIC_003, x=115, y=14
	video offset=CINEMATIC_003, x=75, y=31
	video offset=CINEMATIC_003, x=42, y=31
	video offset=CINEMATIC_003, x=28, y=38
	video offset=CINEMATIC_003, x=96, y=20
	ret


	killChannel
	video offset=CINEMATIC_001, x=114, y=22
	video offset=CINEMATIC_001, x=86, y=21
	video offset=CINEMATIC_001, x=53, y=21
	break
	video offset=CINEMATIC_001, x=21, y=21
	video offset=CINEMATIC_001, x=1, y=21
	video offset=CINEMATIC_002, x=68, y=21
	break
	video offset=CINEMATIC_002, x=100, y=21
	video offset=CINEMATIC_002, x=47, y=22
	video offset=CINEMATIC_002, x=23, y=20
	break
	video offset=CINEMATIC_002, x=0, y=20
	video offset=CINEMATIC_003, x=87, y=23
	video offset=CINEMATIC_003, x=62, y=20
	break
	video offset=CINEMATIC_003, x=49, y=21
	video offset=CINEMATIC_003, x=24, y=21
	video offset=CINEMATIC_003, x=2, y=23
	break
	video offset=CINEMATIC_003, x=115, y=14
	video offset=CINEMATIC_003, x=75, y=31
	break
	video offset=CINEMATIC_003, x=42, y=31
	video offset=CINEMATIC_003, x=28, y=38
	video offset=CINEMATIC_003, x=96, y=20
	killChannel
