LABEL_8A04:
	call DRAW_BEAST_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_279, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_8490
	ret

LABEL_8A10:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x08], 0x0001
	je [0x0D], 0x00, 0x8A26
	call LABEL_829E
	jmp LABEL_8A2B
