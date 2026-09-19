LABEL_8CE6:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	call LABEL_8CC2
	video type=0, offset=CV_3E4E, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	call LABEL_7818
	ret


LABEL_8CF8:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	sub [BUDDY_X], 0x0001
	call LABEL_8CC2
	video type=0, offset=CV_4324, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	sub [BUDDY_Y], 0x0001
	call LABEL_7846
	add [BUDDY_Y], 0x0001
	add [BUDDY_X], 0x0001
	ret


LABEL_8D1A:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	call LABEL_8CC2
	video type=0, offset=CV_3E4E, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	call LABEL_7878
	ret


LABEL_8D2C:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	call LABEL_8CC2
	video type=0, offset=CV_3E4E, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	call LABEL_7846
	ret


BUDDY_RIGHT_FIRE_AIM_PHASE_1:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	call LABEL_8CC2
	video type=0, offset=CV_3E4E, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	add [BUDDY_Y], 0x000D
	je [0x0D], 0x00, LABEL_8D5C
	call CAPSULE_DRAW_CV261_AT_X07_Y08_L2
	jmp DECREMENT_VAR08_BY_D

LABEL_8D5C:
	call LABEL_85D6
