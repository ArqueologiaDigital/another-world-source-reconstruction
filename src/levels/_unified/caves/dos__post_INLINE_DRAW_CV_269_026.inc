LABEL_8A56:
	call DRAW_BEAST_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_282, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_84B1
	sub [0x08], 0x0001
	ret

LABEL_8A66:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	je [0x0D], 0x00, 0x8A78
	call LABEL_829E
	jmp LABEL_8A7D
