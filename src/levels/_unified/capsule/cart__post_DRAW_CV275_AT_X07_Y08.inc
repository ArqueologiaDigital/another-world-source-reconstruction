CAPSULE_DRAW_CV263_AT_X07_Y08_L15:
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_2FD6, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	call LABEL_7AA9
	ret


LABEL_8056:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	sub [BUDDY_Y], 0x0001
	je [0x0D], 0x00, CAPSULE_ACTOR_RUN_LEFT_DRAW_8
	call CAPSULE_DRAW_CV204_AT_X07_PLUS1_Y08_L18
	jmp LABEL_8071

CAPSULE_ACTOR_RUN_LEFT_DRAW_8:
	video type=0, offset=CV_31EC, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40

LABEL_8071:
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_304A, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	call LABEL_7AA9
	add [BUDDY_Y], 0x0001
	ret


LABEL_8081:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	je [0x0D], 0x00, LABEL_8093
	call CAPSULE_DRAW_CV204_AT_X07_PLUS1_Y08_L18
	jmp LABEL_8098

LABEL_8093:
	video type=0, offset=CV_31EC, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40

LABEL_8098:
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_3066, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	call CAPSULE_DRAW_CV263_AT_X07_Y08_L13
	ret


LABEL_80A4:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	play id=0x0055, freq=0x0F, vol=0x14, channel=0x00
	add [BUDDY_Y], 0x0001
	je [0x0D], 0x00, LABEL_80C0
	call CAPSULE_DRAW_CV204_AT_X07_PLUS1_Y08_L22
	jmp LABEL_80C5

LABEL_80C0:
	video type=0, offset=CV_31F6, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40

LABEL_80C5:
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_3082, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	call LABEL_7AB4
	sub [BUDDY_Y], 0x0001
	ret


LABEL_80D5:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	add [BUDDY_Y], 0x0001
	je [0x0D], 0x00, LABEL_80EB
	call LABEL_78A0
	jmp LABEL_80F0

LABEL_80EB:
	video type=0, offset=CV_31F6, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40

LABEL_80F0:
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_309E, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	call LABEL_7ABF
	sub [BUDDY_Y], 0x0001
	ret


LABEL_8100:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	je [0x0D], 0x00, LABEL_8112
	call CAPSULE_DRAW_CV204_AT_X07_PLUS1_Y08_L22
	jmp LABEL_8117

LABEL_8112:
	video type=0, offset=CV_3200, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40

LABEL_8117:
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_30BA, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	add [BUDDY_X], 0x0001
	call CAPSULE_DRAW_CV263_AT_X07_Y08_L1
	sub [BUDDY_X], 0x0001
	ret


LABEL_812B:
	call AND_VAR11_WITH_EFFF
	jmp LABEL_813A
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_4AE6

LABEL_813A:
	call LABEL_7F89
	sub [BUDDY_X], 0x0007
	break
	jg [BUDDY_X], [0x29], LABEL_8151
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_4AE6

LABEL_8151:
	call CAPSULE_DRAW_CV263_AT_X07_Y08_L2
	sub [BUDDY_X], 0x0009
	break
	jg [BUDDY_X], [0x29], LABEL_8168
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_4AE6

LABEL_8168:
	call CAPSULE_DRAW_CV263_AT_X07_Y08_L6
	sub [BUDDY_X], 0x0009
	break
	jg [BUDDY_X], [0x29], LABEL_817F
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_4AE6

LABEL_817F:
	call CAPSULE_ACTOR_RUN_LEFT_DRAW_3
	sub [BUDDY_X], 0x0008
	break
	jg [BUDDY_X], [0x29], LABEL_8196
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_4AE6

LABEL_8196:
	call CAPSULE_BUDDY_RUN_LEFT_DRAW_4
	sub [BUDDY_X], 0x000A
	break
	jg [BUDDY_X], [0x29], LABEL_81AD
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_4AE6

LABEL_81AD:
	call LABEL_8056
	sub [BUDDY_X], 0x0007
	break
	jg [BUDDY_X], [0x29], LABEL_81C4
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_4AE6

LABEL_81C4:
	call LABEL_8081
	sub [BUDDY_X], 0x0009
	break
	jg [BUDDY_X], [0x29], LABEL_81DB
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_4AE6

LABEL_81DB:
	call LABEL_80A4
	sub [BUDDY_X], 0x0009
	break
	jg [BUDDY_X], [0x29], LABEL_81F2
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_4AE6

LABEL_81F2:
	call LABEL_80D5
	sub [BUDDY_X], 0x0008
	break
	jg [BUDDY_X], [0x29], LABEL_8209
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_4AE6

LABEL_8209:
	call LABEL_8100
	sub [BUDDY_X], 0x000A
	break
	jmp LABEL_812B
LABEL_8214:
	db 0x11

LABEL_8215:
	video type=0, offset=CV_41A8, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	jg [0x13], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0002
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=CV_5C74, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	ret


LABEL_8233:
	video type=0, offset=CV_41E0, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	jg [0x13], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0002
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=CV_5C7C, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	ret


LABEL_8251:
	video type=0, offset=CV_4218, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	jg [0x13], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=CV_5C84, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	ret


LABEL_826F:
	add [BUDDY_X], 0x0001
	call CAPSULE_DRAW_CV246_AT_X07_Y08_L2
	sub [BUDDY_X], 0x0001
	ret


CAPSULE_DRAW_CV246_AT_X07_Y08_L2:
	video type=0, offset=CV_3B44, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	mov [0xF5], [BUDDY_X]
	jg [0x13], [0x30], DRAW_CIN_112_113_VAR09_LOW
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, DRAW_CIN_112_113_VAR09_LOW
	video type=0, offset=CV_5CA4, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	jmp DRAW_CIN_112_113_VAR09_LOW

LABEL_829E:
	add [BUDDY_X], 0x0001
	call LABEL_82AA
	sub [BUDDY_X], 0x0001
	ret


LABEL_82AA:
	video type=0, offset=CV_3B96, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	mov [0xF5], [BUDDY_X]
	jg [0x13], [0x30], DRAW_CIN_112_113_VAR09_LOW
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, DRAW_CIN_112_113_VAR09_LOW
	video type=0, offset=CV_5CAC, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	jmp DRAW_CIN_112_113_VAR09_LOW

CAPSULE_DRAW_CV261_AT_X07_Y08_L2:
	video type=0, offset=CV_3BE8, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	mov [0xF5], [BUDDY_X]
	jg [0x13], [0x30], DRAW_CIN_112_113_VAR09_LOW
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, DRAW_CIN_112_113_VAR09_LOW
	video type=0, offset=CV_5CB4, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	jmp DRAW_CIN_112_113_VAR09_LOW

CAPSULE_DRAW_CV259_AT_X07_Y08_L2:
	sub [BUDDY_X], 0x0001
	call LABEL_829E
	add [BUDDY_X], 0x0001
	ret


LABEL_82FC:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	sub [BUDDY_Y], 0x0001
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_2566, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	video type=0, offset=CV_FIGURE_RUN_RIGHT_BODY_F00, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	je [0x0D], 0x00, LABEL_831F
	call LABEL_829E
	jmp LABEL_8324

LABEL_831F:
	video type=0, offset=CV_6108, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40

LABEL_8324:
	add [BUDDY_Y], 0x0001
	ret


LABEL_8329:
	jne [SCREEN_NUM], [0x10], SHARED_RET
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=0, offset=CV_255C, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	video type=0, offset=CV_FIGURE_RUN_RIGHT_BODY_F01, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	je [0x0D], 0x00, DRAW_CV246_AT_X07_Y08
	call LABEL_829E
	jmp CAPSULE_DRAW_CV246_AT_X07_Y08_L0
