LABEL_8931:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_255C, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=CV_FIGURE_RUN_RIGHT_BODY_F01, x=[0x07], y=[0x08], zoom=0x40
	je [0x0D], 0x00, LABEL_8950
	call LABEL_88A6
	jmp LABEL_8955

LABEL_8950:
	video type=0, offset=CV_FIGURE_RUN_RIGHT_UPPER_POSE_01, x=[0x07], y=[0x08], zoom=0x40

LABEL_8955:
	ret


CAVES_ACTOR_RUN_RIGHT_PHASE_3_FRAME:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	add [0x08], 0x0001
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_2552, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=CV_FIGURE_RUN_RIGHT_BODY_F02, x=[0x07], y=[0x08], zoom=0x40
	je [0x0D], 0x00, LABEL_8979
	call LABEL_8883
	jmp DEDUP_CAVES_5B_007__HELPER

LABEL_8979:
	video type=0, offset=CV_FIGURE_RUN_RIGHT_UPPER_POSE_02, x=[0x07], y=[0x08], zoom=0x40
