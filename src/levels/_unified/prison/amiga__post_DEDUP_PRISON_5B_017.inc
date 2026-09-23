LABEL_5D89:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	call DRAW_PRISON_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_255C, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	video type=0, offset=CV_FIGURE_RUN_RIGHT_BODY_F09, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	sub [BUDDY_X], 0x0001
	je [0x0D], 0x00, LABEL_5DAC
	call LABEL_5BD1
	jmp INCREMENT_VAR07_BY_1

LABEL_5DAC:
	video type=0, offset=CV_FIGURE_RUN_RIGHT_UPPER_POSE_00, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
