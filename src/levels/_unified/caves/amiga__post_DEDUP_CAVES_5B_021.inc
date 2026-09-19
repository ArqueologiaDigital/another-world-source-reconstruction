LABEL_8A02:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_2548, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=CV_232C, x=[0x07], y=[0x08], zoom=0x40
	je [0x0D], 0x00, LABEL_8A21
	call LABEL_88A6
	jmp LABEL_8A26

LABEL_8A21:
	video type=0, offset=CV_2200, x=[0x07], y=[0x08], zoom=0x40

LABEL_8A26:
	ret


CAVES_ACTOR_RUN_RIGHT_PHASE_8_FRAME:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	add [0x08], 0x0001
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_2552, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=CV_2348, x=[0x07], y=[0x08], zoom=0x40
	je [0x0D], 0x00, LABEL_8A4A
	call LABEL_88D5
	jmp DEDUP_CAVES_5B_007_002

LABEL_8A4A:
	video type=0, offset=CV_224C, x=[0x07], y=[0x08], zoom=0x40
