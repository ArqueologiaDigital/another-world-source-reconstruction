DRAW_BEAST_SUBFRAME_3_VAR09:
	mov [0xF8], [0x09]
	and [0xF8], 0x000F
	je [0xF8], 0x01, DRAW_CIN_054
	je [0xF8], 0x02, DRAW_CIN_055
	je [0xF8], 0x03, DRAW_CIN_056
	ret


DRAW_CIN_054:
	video offset=CINEMATIC_054, x=[0x07], y=[0x08]
	ret


DRAW_CIN_055:
	video offset=CINEMATIC_055, x=[0x07], y=[0x08]
	ret


DRAW_CIN_056:
	video offset=CINEMATIC_056, x=[0x07], y=[0x08]
	ret


DRAW_BEAST_SUBFRAME_2_VAR09_LOW:
	mov [0xF8], [0x09]
	and [0xF8], 0x000F
	je [0xF8], 0x01, DRAW_CIN_057
	je [0xF8], 0x02, DRAW_CIN_058
	ret


DRAW_CIN_057:
	video offset=CINEMATIC_057, x=[0xf5], y=[0x08]
	ret


DRAW_CIN_058:
	video offset=CINEMATIC_058, x=[0xf5], y=[0x08]
	ret


LABEL_835D:
	jg [0x09], 0x03FF, SHARED_RET
	video type=0, offset=CV_FIGURE_WALK_LEFT_UPPER_POSE_08, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jg [0xF6], 0x00, DRAW_BEAST_SUBFRAME_2_VAR09_LOW
	video type=0, offset=CV_5FBC, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_BEAST_SUBFRAME_2_VAR09_LOW

CAVES_DRAW_CV204_AT_X07_Y08_L1:
	jg [0x09], 0x03FF, SHARED_RET
	video type=0, offset=CV_FIGURE_WALK_LEFT_UPPER_POSE_00, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jg [0xF6], 0x00, DRAW_BEAST_SUBFRAME_2_VAR09_LOW
	video type=0, offset=CV_5FC4, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_BEAST_SUBFRAME_2_VAR09_LOW

DRAW_BEAST_HEAD_CV165_166:
	jg [0x09], 0x03FF, SHARED_RET
	video type=0, offset=CV_FIGURE_WALK_LEFT_UPPER_POSE_01, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	sub [0xF5], 0x0001
	jg [0xF6], 0x00, DRAW_BEAST_SUBFRAME_2_VAR09_LOW
	video type=0, offset=CV_5FCC, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_BEAST_SUBFRAME_2_VAR09_LOW

DRAW_BEAST_HEAD_CV211_212:
	jg [0x09], 0x03FF, SHARED_RET
	video type=0, offset=CV_FIGURE_WALK_LEFT_UPPER_POSE_02, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jg [0xF6], 0x00, DRAW_BEAST_SUBFRAME_2_VAR09_LOW
	video type=0, offset=CV_5FD4, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_BEAST_SUBFRAME_2_VAR09_LOW

DRAW_BEAST_HEAD_CV214_215:
	jg [0x09], 0x03FF, SHARED_RET
	video type=0, offset=CV_FIGURE_WALK_LEFT_UPPER_POSE_03, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	add [0xF5], 0x0001
	jg [0xF6], 0x00, DRAW_BEAST_SUBFRAME_2_VAR09_LOW
	video type=0, offset=CV_5FDC, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_BEAST_SUBFRAME_2_VAR09_LOW

LABEL_83F6:
	jg [0x09], 0x03FF, SHARED_RET
	video type=0, offset=CV_FIGURE_WALK_LEFT_UPPER_POSE_04, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	add [0xF5], 0x0001
	jg [0xF6], 0x00, DRAW_BEAST_SUBFRAME_2_VAR09_LOW
	video type=0, offset=CV_5FE4, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_BEAST_SUBFRAME_2_VAR09_LOW

CAVES_INLINE_DRAW_CV_220_016_L1:
	jg [0x09], 0x03FF, SHARED_RET
	video type=0, offset=CV_FIGURE_WALK_LEFT_UPPER_POSE_05, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	add [0xF5], 0x0002
	jg [0xF6], 0x00, DRAW_BEAST_SUBFRAME_2_VAR09_LOW
	video type=0, offset=CV_5FEC, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_BEAST_SUBFRAME_2_VAR09_LOW

CAVES_DRAW_CV224_AT_X07_Y08_L1:
	jg [0x09], 0x03FF, SHARED_RET
	video type=0, offset=CV_FIGURE_WALK_LEFT_UPPER_POSE_06, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	add [0xF5], 0x0002
	jg [0xF6], 0x00, DRAW_BEAST_SUBFRAME_2_VAR09_LOW
	video type=0, offset=CV_5FF4, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_BEAST_SUBFRAME_2_VAR09_LOW

CAVES_INLINE_DRAW_CV_228_018_L0:
	jg [0x09], 0x03FF, SHARED_RET
	video type=0, offset=CV_FIGURE_WALK_LEFT_UPPER_POSE_07, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	add [0xF5], 0x0002
	jg [0xF6], 0x00, DRAW_BEAST_SUBFRAME_2_VAR09_LOW
	video type=0, offset=CV_5FFC, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_BEAST_SUBFRAME_2_VAR09_LOW

CAVES_INLINE_DRAW_CV_266_005_L1:
	video type=0, offset=CV_3116, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jmp DRAW_BEAST_SUBFRAME_2_VAR09_LOW

CAVES_INLINE_DRAW_CV_269_024_L0:
	video type=0, offset=CV_3124, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jmp DRAW_BEAST_SUBFRAME_2_VAR09_LOW

CAVES_INLINE_DRAW_CV_272_013_L0:
	video type=0, offset=CV_316E, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jmp DRAW_BEAST_SUBFRAME_2_VAR09_LOW

LABEL_849B:
	video type=0, offset=CV_3180, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jmp DRAW_BEAST_SUBFRAME_2_VAR09_LOW

CAVES_INLINE_DRAW_CV_269_025_L1:
	video type=0, offset=CV_31A8, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jmp DRAW_BEAST_SUBFRAME_2_VAR09_LOW

CAVES_INLINE_DRAW_CV_269_026_L0:
	video type=0, offset=CV_31CA, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jmp DRAW_BEAST_SUBFRAME_2_VAR09_LOW

LABEL_84BC:
	video type=0, offset=CV_61A2, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jmp DRAW_BEAST_SUBFRAME_2_VAR09_LOW

LABEL_84C7:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	je [0x0D], 0x00, DRAW_CV204_AT_X07_Y08
	call CAVES_DRAW_CV204_AT_X07_Y08_L3
	jmp DRAW_FIGURE_WALK_LEFT_F00
