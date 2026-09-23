LABEL_5D5C:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	add [BUDDY_Y], 0x0001
	call DRAW_PRISON_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_2552, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	video type=0, offset=CV_FIGURE_RUN_RIGHT_BODY_F08, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	je [0x0D], 0x00, LABEL_5D7F
	call LABEL_5BF4
	jmp DEDUP_CAVES_5B_007_003

LABEL_5D7F:
	video type=0, offset=CV_2276, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
