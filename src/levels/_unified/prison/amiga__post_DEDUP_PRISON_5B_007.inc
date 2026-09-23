LABEL_5D0A:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	call DRAW_PRISON_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_2548, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	video type=0, offset=CV_FIGURE_RUN_RIGHT_BODY_F06, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	je [0x0D], 0x00, LABEL_5D29
	call LABEL_5BA2
	jmp LABEL_5D2E

LABEL_5D29:
	video type=0, offset=CV_FIGURE_RUN_RIGHT_UPPER_POSE_03, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40

LABEL_5D2E:
	ret


LABEL_5D2F:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	add [BUDDY_Y], 0x0001
	call DRAW_PRISON_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_2552, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	video type=0, offset=CV_FIGURE_RUN_RIGHT_BODY_F07, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	je [0x0D], 0x00, LABEL_5D52
	call LABEL_5BD1
	jmp DEDUP_CAVES_5B_007_002

LABEL_5D52:
	video type=0, offset=CV_FIGURE_RUN_RIGHT_UPPER_POSE_05, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
