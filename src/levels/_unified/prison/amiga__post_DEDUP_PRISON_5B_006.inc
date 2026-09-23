LABEL_5C33:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	call DRAW_PRISON_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_255C, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	video type=0, offset=CV_FIGURE_RUN_RIGHT_BODY_F01, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	je [0x0D], 0x00, LABEL_5C52
	call LABEL_5BA2
	jmp LABEL_5C57

LABEL_5C52:
	video type=0, offset=CV_FIGURE_RUN_RIGHT_UPPER_POSE_01, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40

LABEL_5C57:
	ret


LABEL_5C58:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	add [BUDDY_Y], 0x0001
	call DRAW_PRISON_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_2552, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	video type=0, offset=CV_FIGURE_RUN_RIGHT_BODY_F02, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	je [0x0D], 0x00, LABEL_5C7B
	call LABEL_5B7F
	jmp DEDUP_CAVES_5B_007__HELPER

LABEL_5C7B:
	video type=0, offset=CV_FIGURE_RUN_RIGHT_UPPER_POSE_02, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
