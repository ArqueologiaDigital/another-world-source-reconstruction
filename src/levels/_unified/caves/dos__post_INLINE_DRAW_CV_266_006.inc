LABEL_8A7D:
	call DRAW_BEAST_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_284, x=[0x07], y=[0x08], zoom=0x40
	add [0x07], 0x0001
	call LABEL_84BC
	sub [0x07], 0x0001
	ret

LABEL_8A91:
	call AND_VAR11_WITH_EFFF
	jmp LABEL_8AA0
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_5692

LABEL_8AA0:
	call LABEL_88FB
	sub [0x07], 0x0007
	break
	jg [0x07], [0x29], LABEL_8AB7
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_5692

LABEL_8AB7:
	call LABEL_8926
	sub [0x07], 0x0009
	break
	jg [0x07], [0x29], LABEL_8ACE
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_5692

LABEL_8ACE:
	call LABEL_8949
	sub [0x07], 0x0009
	break
	jg [0x07], [0x29], LABEL_8AE5
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_5692

LABEL_8AE5:
	call LABEL_8974
	sub [0x07], 0x0008
	break
	jg [0x07], [0x29], LABEL_8AFC
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_5692

LABEL_8AFC:
	call LABEL_899F
	sub [0x07], 0x000A
	break
	jg [0x07], [0x29], LABEL_8B13
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_5692

LABEL_8B13:
	call LABEL_89C2
	sub [0x07], 0x0007
	break
	jg [0x07], [0x29], LABEL_8B2A
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_5692

LABEL_8B2A:
	call LABEL_89ED
	sub [0x07], 0x0009
	break
	jg [0x07], [0x29], LABEL_8B41
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_5692

LABEL_8B41:
	call LABEL_8A10
	sub [0x07], 0x0009
	break
	jg [0x07], [0x29], LABEL_8B58
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_5692

LABEL_8B58:
	call LABEL_8A3B
	sub [0x07], 0x0008
	break
	jg [0x07], [0x29], LABEL_8B6F
	call STATE_VAR12_BIG_DISPATCH
	jne [0x2F], 0x04, LABEL_5692

LABEL_8B6F:
	call LABEL_8A66
	sub [0x07], 0x000A
	break
	jmp LABEL_8A91
LABEL_8B7A:
	db 0x11

LABEL_8B7B:
	video type=0, offset=COMMON_VIDEO_314, x=[0x07], y=[0x08], zoom=0x40
	jg [0x13], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0002
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_315, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_8B99:
	video type=0, offset=COMMON_VIDEO_316, x=[0x07], y=[0x08], zoom=0x40
	jg [0x13], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0002
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_317, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_8BB7:
	video type=0, offset=COMMON_VIDEO_318, x=[0x07], y=[0x08], zoom=0x40
	jg [0x13], [0x30], SHARED_RET
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, SHARED_RET
	video type=0, offset=COMMON_VIDEO_319, x=[0x07], y=[0x08], zoom=0x40
	ret

LABEL_8BD5:
	add [0x07], 0x0001
	call LABEL_8BE1
	sub [0x07], 0x0001
	ret

LABEL_8BE1:
	video type=0, offset=COMMON_VIDEO_302, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jg [0x13], [0x30], DRAW_CIN_031_032_VAR09_LOW
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, DRAW_CIN_031_032_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_303, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_031_032_VAR09_LOW

LABEL_8C04:
	add [0x07], 0x0001
	call LABEL_8C10
	sub [0x07], 0x0001
	ret

LABEL_8C10:
	video type=0, offset=COMMON_VIDEO_310, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jg [0x13], [0x30], DRAW_CIN_031_032_VAR09_LOW
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, DRAW_CIN_031_032_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_311, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_031_032_VAR09_LOW

LABEL_8C33:
	video type=0, offset=COMMON_VIDEO_312, x=[0x07], y=[0x08], zoom=0x40
	mov [0xF5], [0x07]
	jg [0x13], [0x30], DRAW_CIN_031_032_VAR09_LOW
	mov [0xF8], [0x31]
	and [0xF8], 0x0004
	je [0xF8], 0x00, DRAW_CIN_031_032_VAR09_LOW
	video type=0, offset=COMMON_VIDEO_313, x=[0x07], y=[0x08], zoom=0x40
	jmp DRAW_CIN_031_032_VAR09_LOW

LABEL_8C56:
	sub [0x07], 0x0001
	call LABEL_8C04
	add [0x07], 0x0001
	ret

LABEL_8C62:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	sub [0x08], 0x0001
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_241, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_242, x=[0x07], y=[0x08], zoom=0x40
	je [0x0D], 0x00, INLINE_DRAW_CV_243_012__HELPER_INLINE_DRAW_CV_243_012
	call LABEL_8C04
	jmp DEDUP_CAVES_5B_020__HELPER_DEDUP_CAVES_5B_020
