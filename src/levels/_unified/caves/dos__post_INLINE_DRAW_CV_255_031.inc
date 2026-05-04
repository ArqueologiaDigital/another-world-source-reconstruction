LABEL_8D32:
	ret

LABEL_8D33:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	sub [0x08], 0x0001
	call DRAW_HERO_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_250, x=[0x07], y=[0x08], zoom=0x40
	video type=0, offset=COMMON_VIDEO_256, x=[0x07], y=[0x08], zoom=0x40
	je [0x0D], 0x00, INLINE_DRAW_CV_255_010	;@raw=0x0A,0x00,0x0D,0x00,0x8D,0x56
	call LABEL_8C04
	jmp DEDUP_CAVES_5B_020	;@raw=0x07,0x8D,0x5B
