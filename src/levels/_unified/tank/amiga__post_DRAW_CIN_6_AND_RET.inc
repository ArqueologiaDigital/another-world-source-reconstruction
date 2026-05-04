LABEL_17CF:
	selectVideoPage 0x00
	fill page=0x00, color=0x0C
	video type=1, offset=CINEMATIC_000, x=160, y=100
	copyVideoPage src=0x00, dst=0x03
	call DRAW_CIN_SEQ_001_001_003
	call DRAW_BG_DOTS_CIN_001_004
	call DRAW_CIN_6_AND_RET
	selectVideoPage 0x03
	call DRAW_CIN_SEQ_001_001_003
	call DRAW_BG_DOTS_CIN_007_008
	call DRAW_CIN_6_AND_RET
	selectVideoPage 0xFF
	ret

DRAW_CIN_113_114_AND_RET:
	video type=1, offset=CINEMATIC_113, x=[0x0f], y=[0x10], zoom=0x40
	video type=1, offset=CINEMATIC_114, x=[0x0f], y=[0x10], zoom=0x40
	ret

DRAW_CIN_122_ON_PAGE_0:
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_122, x=[0x0f], y=[0x10], zoom=0x40
	selectVideoPage 0xFF
	ret

LABEL_1807:
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_121, x=[0x0f], y=[0x10], zoom=0x40
	selectVideoPage 0xFF
	jg [HACK_VAR_67], 0x02, SHARED_RET
	mov [HACK_VAR_67], 0x0002
	ret

LABEL_181B:
	selectVideoPage 0x00
	video type=1, offset=CINEMATIC_120, x=[0x0f], y=[0x10], zoom=0x40
	mov [HACK_VAR_67], 0x0003
	selectVideoPage 0xFF
	ret

DRAW_CIN_093_TO_097_VAR:
	video type=1, offset=CINEMATIC_029, x=[0x01], y=[0x02], zoom=[0x03]
	video type=1, offset=CINEMATIC_030, x=[0x01], y=[0x02], zoom=[0x03]
	video type=1, offset=CINEMATIC_031, x=[0x01], y=[0x02], zoom=[0x03]
	video type=1, offset=CINEMATIC_032, x=[0x01], y=[0x02], zoom=[0x03]
	video type=1, offset=CINEMATIC_033, x=[0x01], y=[0x02], zoom=[0x03]
	ret

DRAW_CIN_SEQ_001_001_003:
	video type=1, offset=CINEMATIC_001, x=114, y=22
	video type=1, offset=CINEMATIC_001, x=86, y=21
	video type=1, offset=CINEMATIC_001, x=53, y=21
	video type=1, offset=CINEMATIC_001, x=21, y=21
	video type=1, offset=CINEMATIC_001, x=1, y=21
	video type=1, offset=CINEMATIC_002, x=68, y=21
	video type=1, offset=CINEMATIC_002, x=100, y=21
	video type=1, offset=CINEMATIC_002, x=47, y=22
	video type=1, offset=CINEMATIC_002, x=23, y=20
	video type=1, offset=CINEMATIC_002, x=0, y=20
	video type=1, offset=CINEMATIC_003, x=87, y=23
	video type=1, offset=CINEMATIC_003, x=62, y=20
	video type=1, offset=CINEMATIC_003, x=49, y=21
	video type=1, offset=CINEMATIC_003, x=24, y=21
	video type=1, offset=CINEMATIC_003, x=2, y=23
	video type=1, offset=CINEMATIC_003, x=115, y=14
	video type=1, offset=CINEMATIC_003, x=75, y=31
	video type=1, offset=CINEMATIC_003, x=42, y=31
	video type=1, offset=CINEMATIC_003, x=28, y=38
	video type=1, offset=CINEMATIC_003, x=96, y=20
	ret
LABEL_1899:
	db 0x11, 0x87, 0xBA, 0x72, 0x16, 0x87, 0xBA, 0x56
	db 0x15, 0x87, 0xBA, 0x35, 0x15, 0x06, 0x87, 0xBA
	db 0x15, 0x15, 0x87, 0xBA, 0x01, 0x15, 0x87, 0xDE
	db 0x44, 0x15, 0x06, 0x87, 0xDE, 0x64, 0x15, 0x87
	db 0xDE, 0x2F, 0x16, 0x87, 0xDE, 0x17, 0x14, 0x06
	db 0x87, 0xDE, 0x00, 0x14, 0x88, 0x14, 0x57, 0x17
	db 0x88, 0x14, 0x3E, 0x14, 0x06, 0x88, 0x14, 0x31
	db 0x15, 0x88, 0x14, 0x18, 0x15, 0x88, 0x14, 0x02
	db 0x17, 0x06, 0x88, 0x14, 0x73, 0x0E, 0x88, 0x14
	db 0x4B, 0x1F, 0x06, 0x88, 0x14, 0x2A, 0x1F, 0x88
	db 0x14, 0x1C, 0x26, 0x88, 0x14, 0x60, 0x14, 0x11
