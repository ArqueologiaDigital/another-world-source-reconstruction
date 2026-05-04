LABEL_85CF:
	call DRAW_BEAST_SPRITE_BY_VAR09_0E
	video type=0, offset=COMMON_VIDEO_233, x=[0x07], y=[0x08], zoom=0x40
	call DRAW_CIN_054_055_056_VAR09
	call LABEL_838E
	ret

LABEL_85DE:
	jne [HACK_VAR_67], [0x10], SHARED_RET
	play id=0x0055, freq=0x14, vol=0x14, channel=0x00
	je [0x0D], 0x00, INLINE_DRAW_CV_216_027	;@raw=0x0A,0x00,0x0D,0x00,0x85,0xF6
	call LABEL_8215
	jmp LABEL_85FB
