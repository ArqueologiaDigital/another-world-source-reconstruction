LABEL_89B6:
	call DRAW_BEAST_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_276, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_849B
	ret

LABEL_89C2:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	sub [0x08], 0x0001
	je [0x0D], 0x00, 0x89D8
	call LABEL_82BC
	jmp LABEL_89DD
