LABEL_893D:
	call DRAW_BEAST_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_267, x=[0x07], y=[0x08], zoom=0x40
	call LABEL_847A
	ret

LABEL_8949:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	add [0x08], 0x0001
	je [0x0D], 0x00, 0x895F
	call DRAW_CV_304_THEN_305
	jmp LABEL_8964
