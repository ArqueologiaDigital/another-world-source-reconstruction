LABEL_804A:
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_276, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	call LABEL_7AA9
	ret

LABEL_8056:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	sub [BUDDY_Y], 0x0001
	je [0x0D], 0x00, LABEL_806C
	call LABEL_78CA
	jmp LABEL_8071

LABEL_806C:
	video type=0, offset=COMMON_VIDEO_272, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40

LABEL_8071:
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_278, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	call LABEL_7AA9
	add [BUDDY_Y], 0x0001
	ret

LABEL_8081:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, LABEL_8093
	call LABEL_78CA
	jmp LABEL_8098

LABEL_8093:
	video type=0, offset=COMMON_VIDEO_272, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40

LABEL_8098:
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_279, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	call LABEL_7A9E
	ret

LABEL_80A4:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	play id=0x0055, freq=0x0F, vol=0x14, channel=0x00
	add [BUDDY_Y], 0x0001
	je [0x0D], 0x00, LABEL_80C0
	call LABEL_78AC
	jmp LABEL_80C5

LABEL_80C0:
	video type=0, offset=COMMON_VIDEO_269, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40

LABEL_80C5:
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_280, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	call LABEL_7AB4
	sub [BUDDY_Y], 0x0001
	ret

LABEL_80D5:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [BUDDY_Y], 0x0001
	je [0x0D], 0x00, LABEL_80EB
	call LABEL_78A0
	jmp LABEL_80F0

LABEL_80EB:
	video type=0, offset=COMMON_VIDEO_269, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40

LABEL_80F0:
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_282, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	call LABEL_7ABF
	sub [BUDDY_Y], 0x0001
	ret

LABEL_8100:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, LABEL_8112
	call LABEL_78AC
	jmp LABEL_8117

LABEL_8112:
	video type=0, offset=COMMON_VIDEO_266, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40

LABEL_8117:
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_284, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	add [BUDDY_X], 0x0001
	call LABEL_7ACA
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
	call LABEL_7FB4
	sub [BUDDY_X], 0x0009
	break
	jg [BUDDY_X], [0x29], LABEL_8168
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_4AE6

LABEL_8168:
	call LABEL_7FD7
	sub [BUDDY_X], 0x0009
	break
	jg [BUDDY_X], [0x29], LABEL_817F
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_4AE6

LABEL_817F:
	call LABEL_8002
	sub [BUDDY_X], 0x0008
	break
	jg [BUDDY_X], [0x29], LABEL_8196
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_4AE6

LABEL_8196:
	call LABEL_8033
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
	video type=0, offset=COMMON_VIDEO_314, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	jg [0x13], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0002
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_315, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	ret

LABEL_8233:
	video type=0, offset=COMMON_VIDEO_316, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	jg [0x13], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0002
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_317, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	ret

LABEL_8251:
	video type=0, offset=COMMON_VIDEO_318, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	jg [0x13], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_319, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	ret

LABEL_826F:
	add [BUDDY_X], 0x0001
	call LABEL_827B
	sub [BUDDY_X], 0x0001
	ret

LABEL_827B:
	video type=0, offset=COMMON_VIDEO_302, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	mov [0xF5], [BUDDY_X]
	jg [0x13], [0x30], DRAW_CIN_112_113_VAR09_LOW
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, DRAW_CIN_112_113_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_303, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	jmp DRAW_CIN_112_113_VAR09_LOW

LABEL_829E:
	add [BUDDY_X], 0x0001
	call LABEL_82AA
	sub [BUDDY_X], 0x0001
	ret

LABEL_82AA:
	video type=0, offset=COMMON_VIDEO_310, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	mov [0xF5], [BUDDY_X]
	jg [0x13], [0x30], DRAW_CIN_112_113_VAR09_LOW
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, DRAW_CIN_112_113_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_311, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	jmp DRAW_CIN_112_113_VAR09_LOW

LABEL_82CD:
	video type=0, offset=COMMON_VIDEO_312, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	mov [0xF5], [BUDDY_X]
	jg [0x13], [0x30], DRAW_CIN_112_113_VAR09_LOW
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, DRAW_CIN_112_113_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_313, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	jmp DRAW_CIN_112_113_VAR09_LOW

LABEL_82F0:
	sub [BUDDY_X], 0x0001
	call LABEL_829E
	add [BUDDY_X], 0x0001
	ret

LABEL_82FC:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	sub [BUDDY_Y], 0x0001
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_241, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	video type=0, offset=COMMON_VIDEO_242, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	je [0x0D], 0x00, LABEL_831F
	call LABEL_829E
	jmp LABEL_8324

LABEL_831F:
	video type=0, offset=COMMON_VIDEO_243, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40

LABEL_8324:
	add [BUDDY_Y], 0x0001
	ret

LABEL_8329:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	call DRAW_ALIEN_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_244, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	video type=0, offset=COMMON_VIDEO_245, x=[BUDDY_X], y=[BUDDY_Y], zoom=0x40
	je [0x0D], 0x00, DRAW_CV246_AT_X07_Y08
	call LABEL_829E
	jmp LABEL_834D
