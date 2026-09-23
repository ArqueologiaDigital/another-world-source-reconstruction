LABEL_5CB2:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	call DRAW_PRISON_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_2570, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	video type=0, offset=CV_FIGURE_RUN_RIGHT_BODY_F04, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	je [0x0D], 0x00, LABEL_5CD1
	call LABEL_5B7F
	jmp LABEL_5CD6

LABEL_5CD1:
	video type=0, offset=CV_FIGURE_RUN_RIGHT_UPPER_POSE_04, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40

LABEL_5CD6:
	ret


LABEL_5CD7:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	play id=0x0055, freq=0x1C, vol=0x0A, channel=0x01
	sub [BUDDY_Y], 0x0001
	call DRAW_PRISON_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_2548, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	video type=0, offset=CV_FIGURE_RUN_RIGHT_BODY_F05, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	je [0x0D], 0x00, LABEL_5D00
	call LABEL_5BA2
	jmp DEDUP_CAVES_5B_020

LABEL_5D00:
	video type=0, offset=CV_FIGURE_RUN_RIGHT_UPPER_POSE_04, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
