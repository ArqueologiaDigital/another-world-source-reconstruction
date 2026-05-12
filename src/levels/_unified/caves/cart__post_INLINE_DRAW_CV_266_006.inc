CAVES_INLINE_DRAW_CV_269_026_L2:
	call DRAW_BEAST_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_284, x=[0x07], y=[0x08], zoom=0x40
	add [0x07], 0x0001
	call LABEL_8433
	sub [0x07], 0x0001
	ret


LABEL_8A08:
	call AND_VAR11_WITH_EFFF
	jmp LABEL_8A17
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_5595

LABEL_8A17:
	call LABEL_8872
	sub [0x07], 0x0007
	break
	jg [0x07], [0x29], LABEL_8A2E
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_5595

LABEL_8A2E:
	call LABEL_889D
	sub [0x07], 0x0009
	break
	jg [0x07], [0x29], LABEL_8A45
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_5595

LABEL_8A45:
	call CAVES_INLINE_DRAW_CV_266_005_L2
	sub [0x07], 0x0009
	break
	jg [0x07], [0x29], LABEL_8A5C
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_5595

LABEL_8A5C:
	call CAVES_INLINE_DRAW_CV_269_024_L1
	sub [0x07], 0x0008
	break
	jg [0x07], [0x29], LABEL_8A73
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_5595

LABEL_8A73:
	call CAVES_INLINE_DRAW_CV_272_013_L1
	sub [0x07], 0x000A
	break
	jg [0x07], [0x29], LABEL_8A8A
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_5595

LABEL_8A8A:
	call LABEL_8939
	sub [0x07], 0x0007
	break
	jg [0x07], [0x29], LABEL_8AA1
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_5595

LABEL_8AA1:
	call LABEL_8964
	sub [0x07], 0x0009
	break
	jg [0x07], [0x29], LABEL_8AB8
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_5595

LABEL_8AB8:
	call CAVES_INLINE_DRAW_CV_272_015_L1
	sub [0x07], 0x0009
	break
	jg [0x07], [0x29], LABEL_8ACF
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_5595

LABEL_8ACF:
	call CAVES_INLINE_DRAW_CV_269_025_L2
	sub [0x07], 0x0008
	break
	jg [0x07], [0x29], LABEL_8AE6
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_5595

LABEL_8AE6:
	call CAVES_INLINE_DRAW_CV_269_026_L1
	sub [0x07], 0x000A
	break
	jmp LABEL_8A08
LABEL_8AF1:
	db 0x11

LABEL_8AF2:
	video type=0, offset=COMMON_VIDEO_314, x=[0x07], y=[0x08], zoom=0x40
	jg [0x13], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0002
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_315, x=[0x07], y=[0x08], zoom=0x40
	ret


LABEL_8B10:
	video type=0, offset=COMMON_VIDEO_316, x=[0x07], y=[0x08], zoom=0x40
	jg [0x13], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0002
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_317, x=[0x07], y=[0x08], zoom=0x40
	ret


LABEL_8B2E:
	video type=0, offset=COMMON_VIDEO_318, x=[0x07], y=[0x08], zoom=0x40
	jg [0x13], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_319, x=[0x07], y=[0x08], zoom=0x40
	ret


LABEL_8B4C:
	add [0x07], 0x0001
	call CAVES_DRAW_CV246_AT_X07_Y08_L2
	sub [0x07], 0x0001
	ret


CAVES_DRAW_CV246_AT_X07_Y08_L2:
	video type=0, offset=COMMON_VIDEO_302, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jg [0x13], [0x30], DRAW_HERO_SUBFRAME_2_VAR09_LOW
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, DRAW_HERO_SUBFRAME_2_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_303, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_HERO_SUBFRAME_2_VAR09_LOW

CAVES_INLINE_DRAW_CV_255_031_L2:
	add [0x07], 0x0001
	call LABEL_8B87
	sub [0x07], 0x0001
	ret


LABEL_8B87:
	video type=0, offset=COMMON_VIDEO_310, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jg [0x13], [0x30], DRAW_HERO_SUBFRAME_2_VAR09_LOW
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, DRAW_HERO_SUBFRAME_2_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_311, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_HERO_SUBFRAME_2_VAR09_LOW

CAVES_DRAW_CV_355_L9:
	video type=0, offset=COMMON_VIDEO_312, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jg [0x13], [0x30], DRAW_HERO_SUBFRAME_2_VAR09_LOW
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, DRAW_HERO_SUBFRAME_2_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_313, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_HERO_SUBFRAME_2_VAR09_LOW

LABEL_8BCD:
	sub [0x07], 0x0001
	call CAVES_INLINE_DRAW_CV_255_031_L2
	add [0x07], 0x0001
	ret


LABEL_8BD9:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	sub [0x08], 0x0001
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_241, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_242, x=[0x07], y=[0x08], zoom=0x40
	je [0x0D], 0x00, INLINE_DRAW_CV_243_012__HELPER
	call CAVES_INLINE_DRAW_CV_255_031_L2
	jmp DEDUP_CAVES_5B_020__HELPER
