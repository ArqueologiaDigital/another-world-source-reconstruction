DRAW_CV_106:
	video type=0, offset=COMMON_VIDEO_106, x=[HERO_X], y=[HERO_Y], zoom=0x40
	ret
	je [0x1F], 0x00, LABEL_A134
	jl [0x1E], 0x00, INLINE_SET_VAR20_TO_1
	mov [0x20], 0xFFFF

LABEL_A115:
	sub [0x1E], [0x1F]
	add [0x20], 0x0001
	jge [0x1E], 0x00, LABEL_A115
	ret
