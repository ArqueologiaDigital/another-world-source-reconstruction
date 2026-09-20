CAPSULE_DRAW_CV246_AT_X07_Y08_L3:
	sub [BUDDY_Y], 0x0001
	ret


LABEL_8381:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	add [BUDDY_Y], 0x0001
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_2548, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	video type=0, offset=CV_FIGURE_RUN_RIGHT_BODY_F03, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	je [0x0D], 0x00, LABEL_83A4
	call LABEL_826F
	jmp LABEL_83A9

LABEL_83A4:
	video type=0, offset=CV_2200, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40

LABEL_83A9:
	sub [BUDDY_Y], 0x0001
	ret


LABEL_83AE:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_2570, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	video type=0, offset=CV_FIGURE_RUN_RIGHT_BODY_F04, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	je [0x0D], 0x00, LABEL_83CD
	call CAPSULE_DRAW_CV246_AT_X07_Y08_L2
	jmp LABEL_83D2

LABEL_83CD:
	video type=0, offset=CV_2212, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40

LABEL_83D2:
	ret


LABEL_83D3:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	sub [BUDDY_Y], 0x0001
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_2548, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	video type=0, offset=CV_FIGURE_RUN_RIGHT_BODY_F05, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	je [0x0D], 0x00, LABEL_83F6
	call LABEL_829E
	jmp LABEL_83FB

LABEL_83F6:
	video type=0, offset=CV_2212, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40

LABEL_83FB:
	add [BUDDY_Y], 0x0001
	ret


LABEL_8400:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_2548, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	video type=0, offset=CV_FIGURE_RUN_RIGHT_BODY_F06, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	je [0x0D], 0x00, LABEL_841F
	call LABEL_829E
	jmp LABEL_8424

LABEL_841F:
	video type=0, offset=CV_2200, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40

LABEL_8424:
	ret


LABEL_8425:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	play id=0x0055, freq=0x14, vol=0x14, channel=0x00
	add [BUDDY_Y], 0x0001
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_2552, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	video type=0, offset=CV_FIGURE_RUN_RIGHT_BODY_F07, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	je [0x0D], 0x00, DRAW_CV259_AT_X07_Y08
	call CAPSULE_DRAW_CV261_AT_X07_Y08_L2
	jmp CAPSULE_DRAW_CV259_AT_X07_Y08_L0
