DRAW_CIN_240_IF_VAR09_EQ_1:
	mov [0xF8], [0x09]
	and [0xF8], 0x000F
	je [0xF8], 0x01, DRAW_CIN_240
	ret


DRAW_CIN_240:
	video offset=CINEMATIC_240, x=[BUDDY_X], y=[BUDDY_Y]
	ret


DRAW_CIN_241_IF_VAR09_EQ_1:
	mov [0xF8], [0x09]
	and [0xF8], 0x000F
	je [0xF8], 0x01, DRAW_CIN_241
	ret


DRAW_CIN_241:
	video offset=CINEMATIC_241, x=[0xf5], y=[BUDDY_Y]
	ret


LABEL_5466:
	video type=0, offset=CV_FIGURE_WALK_LEFT_UPPER_POSE_08, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	mov [0xF5], [BUDDY_X]
	jg [0xF6], 0x00, DRAW_CIN_241_IF_VAR09_EQ_1
	video type=0, offset=CV_5FBC, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	jmp DRAW_CIN_241_IF_VAR09_EQ_1

PRISON_DRAW_CV204_AT_X07_PLUS1_Y08_L1:
	video type=0, offset=CV_FIGURE_WALK_LEFT_UPPER_POSE_00, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	mov [0xF5], [BUDDY_X]
	jg [0xF6], 0x00, DRAW_CIN_241_IF_VAR09_EQ_1
	video type=0, offset=CV_5FC4, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	jmp DRAW_CIN_241_IF_VAR09_EQ_1

PRISON_DRAW_CV204_AT_X07_PLUS1_Y08_L4:
	video type=0, offset=CV_FIGURE_WALK_LEFT_UPPER_POSE_01, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	mov [0xF5], [BUDDY_X]
	sub [0xF5], 0x0001
	jg [0xF6], 0x00, DRAW_CIN_241_IF_VAR09_EQ_1
	video type=0, offset=CV_5FCC, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	jmp DRAW_CIN_241_IF_VAR09_EQ_1

PRISON_DRAW_CV204_AT_X07_PLUS1_Y08_L7:
	video type=0, offset=CV_FIGURE_WALK_LEFT_UPPER_POSE_02, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	mov [0xF5], [BUDDY_X]
	jg [0xF6], 0x00, DRAW_CIN_241_IF_VAR09_EQ_1
	video type=0, offset=CV_5FD4, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	jmp DRAW_CIN_241_IF_VAR09_EQ_1

PRISON_DRAW_CV204_AT_X07_PLUS1_Y08_L10:
	video type=0, offset=CV_FIGURE_WALK_LEFT_UPPER_POSE_03, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	mov [0xF5], [BUDDY_X]
	add [0xF5], 0x0001
	jg [0xF6], 0x00, DRAW_CIN_241_IF_VAR09_EQ_1
	video type=0, offset=CV_5FDC, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	jmp DRAW_CIN_241_IF_VAR09_EQ_1

PRISON_INLINE_DRAW_CV_216_027_L0:
	video type=0, offset=CV_FIGURE_WALK_LEFT_UPPER_POSE_04, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	mov [0xF5], [BUDDY_X]
	add [0xF5], 0x0001
	jg [0xF6], 0x00, DRAW_CIN_241_IF_VAR09_EQ_1
	video type=0, offset=CV_5FE4, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	jmp DRAW_CIN_241_IF_VAR09_EQ_1

PRISON_INLINE_DRAW_CV_220_008_L0:
	video type=0, offset=CV_FIGURE_WALK_LEFT_UPPER_POSE_05, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	mov [0xF5], [BUDDY_X]
	add [0xF5], 0x0002
	jg [0xF6], 0x00, DRAW_CIN_241_IF_VAR09_EQ_1
	video type=0, offset=CV_5FEC, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	jmp DRAW_CIN_241_IF_VAR09_EQ_1

PRISON_DRAW_CV224_AT_X07_Y08_L1:
	video type=0, offset=CV_FIGURE_WALK_LEFT_UPPER_POSE_06, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	mov [0xF5], [BUDDY_X]
	add [0xF5], 0x0002
	jg [0xF6], 0x00, DRAW_CIN_241_IF_VAR09_EQ_1
	video type=0, offset=CV_5FF4, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	jmp DRAW_CIN_241_IF_VAR09_EQ_1

PRISON_INLINE_DRAW_CV_228_020_L0:
	video type=0, offset=CV_FIGURE_WALK_LEFT_UPPER_POSE_07, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	mov [0xF5], [BUDDY_X]
	add [0xF5], 0x0002
	jg [0xF6], 0x00, DRAW_CIN_241_IF_VAR09_EQ_1
	video type=0, offset=CV_5FFC, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	jmp DRAW_CIN_241_IF_VAR09_EQ_1

PRISON_INLINE_DRAW_CV_266_029_L0:
	video type=0, offset=CV_3116, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	mov [0xF5], [BUDDY_X]
	jmp DRAW_CIN_241_IF_VAR09_EQ_1

PRISON_INLINE_DRAW_CV_269_024_L0:
	video type=0, offset=CV_3124, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	mov [0xF5], [BUDDY_X]
	jmp DRAW_CIN_241_IF_VAR09_EQ_1

PRISON_INLINE_DRAW_CV_272_003_L0:
	video type=0, offset=CV_316E, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	mov [0xF5], [BUDDY_X]
	jmp DRAW_CIN_241_IF_VAR09_EQ_1

PRISON_DRAW_CV275_AT_X07_Y08_L1:
	video type=0, offset=CV_3180, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	mov [0xF5], [BUDDY_X]
	jmp DRAW_CIN_241_IF_VAR09_EQ_1

PRISON_INLINE_DRAW_CV_269_025_L1:
	video type=0, offset=CV_31A8, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	mov [0xF5], [BUDDY_X]
	jmp DRAW_CIN_241_IF_VAR09_EQ_1

PRISON_INLINE_DRAW_CV_269_026_L0:
	video type=0, offset=CV_31CA, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	mov [0xF5], [BUDDY_X]
	jmp DRAW_CIN_241_IF_VAR09_EQ_1

PRISON_DRAW_CV263_AT_X07_Y08_L1:
	video type=0, offset=CV_61A2, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	mov [0xF5], [BUDDY_X]
	jmp DRAW_CIN_241_IF_VAR09_EQ_1

LABEL_5591:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	je [0x0D], 0x00, DRAW_CV204_AT_X07_Y08
	call PRISON_DRAW_CV204_AT_X07_Y08_L2
	jmp PRISON_ACTOR_WALK_LEFT_POSE_00_DONE
